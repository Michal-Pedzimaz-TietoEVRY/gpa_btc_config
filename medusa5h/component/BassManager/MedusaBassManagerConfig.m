classdef MedusaBassManagerConfig < BtcBaseClass
% MedusaBassManagerConfig Build-time configuration class for the MedusaBassManager block
% Usage:
%    aConfig = MedusaBassManagerConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable, SetObservable)
    SampleRate      = 44100
    FrameSize       {mustBeInteger} = 32

    % Number of input channels
    NumInputs       uint32  {mustBeMember(NumInputs,[2, 6, 10])}    = 2  

    % Input Select Indices
    LeftIndices
    RightIndices
    CenterIndex
    LfeIndex
    LeftRightIndices

    % Filter parameters
    XofOrder        = 5
    LpfFc           = 90
    NumLpfCh        = 2         % Lbass, Rbass
    NumHpfCh        = 2         % HF components
    Lpf             PoolIirTunableConfig
    Hpf             PoolIirTunableConfig

    % Default tune values
    TuneDefaults    MedusaBassManagerTuneConfig

  end

  properties(Constant)
    % Order of inputs to Medusa and hence, Bass Manager
    % This order should always be in sync with the output order of Input 
    % Mixer
    InputOrder = dictionary(...
                ["L", "R", "C", "LFE", "Ls", "Rs", "LTF", "LTB", "RTF", "RTB"], ...
                [ 1,   2,   3,    4,    5,   6,     7,     8,     9,     10  ] ...
            );
    
  end
  properties (Hidden, Dependent)
    SosLpf % Default Sos Values
    SosHpf % Default Sos Values
  end
  methods
    %----------------------------------------------------------------------
    function this = MedusaBassManagerConfig()
        % MedusaBassManagerConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.TuneDefaults =  MedusaBassManagerTuneConfig(this);

        this.Lock(@this.LeftIndices, @() this.SelectLpfCh(this.InputOrder, "left"));
        this.Lock(@this.RightIndices, @() this.SelectLpfCh(this.InputOrder, "right"));
        this.Lock(@this.CenterIndex, @() this.SelectHpfCh(this.InputOrder, "C"));
        this.Lock(@this.LfeIndex, @() this.SelectHpfCh(this.InputOrder, "LFE"));
        this.Lock(@this.LeftRightIndices, @() this.SelectHpfCh(this.InputOrder, "leftright"));

        this.Lock(@this.NumHpfCh, @() this.CalcNumHpfCh());
        
        this.Lpf = PoolIirTunableConfig();
        this.Default(@this.Lpf.TuneDefaults.NumStages, @() size(this.SosLpf,1)*ones(1,this.NumLpfCh));
        this.Default(@this.Lpf.TuneDefaults.SosCoefficients, @() repmat(this.SosLpf,this.NumLpfCh,1));
        this.Lock(@this.Lpf.NumChannels, @() this.NumLpfCh);
        this.Lock(@this.Lpf.FrameSize, @() this.FrameSize);
        this.Lock(@this.Lpf.MaxNumStages, @() this.XofOrder*this.NumLpfCh);
        this.Default(@this.Lpf.Alias, @() 'MedusaBassMgrLpf');

        this.Hpf = PoolIirTunableConfig();
        this.Default(@this.Hpf.TuneDefaults.NumStages, @() size(this.SosHpf,1)*ones(1,this.NumHpfCh));
        this.Default(@this.Hpf.TuneDefaults.SosCoefficients, @() repmat(this.SosHpf,this.NumHpfCh,1));
        this.Lock(@this.Hpf.NumChannels, @() this.NumHpfCh);
        this.Lock(@this.Hpf.FrameSize, @() this.FrameSize);
        this.Lock(@this.Hpf.MaxNumStages, @() this.XofOrder*this.NumHpfCh);
        this.Default(@this.Hpf.Alias, @() 'MedusaBassMgrHpf');
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok

        %.End with a call to our base class to continue validation checks
        %.including any violations of property locking.
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.

        %.Call base class in case it has any work to perform:
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

    function Indices = SelectLpfCh(this, Order, ChannelType)
        switch(this.NumInputs)
            case 6
                % 5.1 inputs
                leftIndices = Order(["L", "Ls", "C", "LFE"]);
                rightIndices = Order(["R", "Rs", "C", "LFE"]);

            case 10
                % 5.1.4 inputs
                leftIndices = Order(["L", "Ls", "LTF", "LTB", "C", "LFE"]);
                rightIndices = Order(["R", "Rs", "RTF", "RTB", "C", "LFE"]);

            otherwise
                % Default to stereo input case
                leftIndices = 1;
                rightIndices = 2;
        end

        if(strcmp(ChannelType, "left"))
            Indices = leftIndices;
        else
            Indices = rightIndices;
        end
    end

    function Indices = SelectHpfCh(this, Order, ChannelType)
        leftRightIndices = 1:this.NumInputs;
        centerIndex = 0;
        lfeIndex = 0;

        if(this.NumInputs > 2)
            % For 5.1, 5.1.4 inputs, separate C and LFE channels from rest
            % of the inputs to generate the modified C
            centerIndex = Order("C");
            lfeIndex = Order("LFE");
            leftRightIndices([centerIndex lfeIndex]) = [];
        end
        
        if(strcmp(ChannelType, "C"))
            Indices = centerIndex;
        elseif(strcmp(ChannelType, "LFE"))
            Indices = lfeIndex;
        else
            Indices = leftRightIndices;
        end
    end

    function NumHpfCh = CalcNumHpfCh(this)
        NumHpfCh = this.NumInputs;

        if(this.NumInputs > 2)
            % For 5.1/5.1.4 inputs, HpfInput = All inputs except LFE
            % LFE is mixed with C before HPF
            NumHpfCh = this.NumInputs - 1;      
        end
    end


    function sos = GetSos(this, filterType)
        [fullZ, fullP, fullK] = butter(this.XofOrder, this.LpfFc / (this.SampleRate / 2), filterType);
        sos = zp2sos(fullZ, fullP, fullK);
    end
    function val = get.SosLpf(this)
        val = this.GetSos("low");
    end
    function val = get.SosHpf(this)
        val = this.GetSos("high");
    end
  end
end
