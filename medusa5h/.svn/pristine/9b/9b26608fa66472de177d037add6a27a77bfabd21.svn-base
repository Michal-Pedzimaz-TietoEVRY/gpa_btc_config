classdef MedusaDrHoligramEqConfig < BtcBaseClass
% MedusaDrHoligramEqConfig Build-time configuration class for the MedusaDrHoligramEq block
% Usage:
%    aConfig = MedusaDrHoligramEqConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
      FullRateFrameSize           uint32          = 32
      DecimationFactor            uint32          = 4

      % Platform Variant Configuration
      Variant                                     = 'Generic'

      % Holigram EQ configuration
      NumInputs                   uint32
      NumOutputs                  uint32
      TotalNumEqLinks             uint32

      % Filter objects
      Fir           FirConfig
      Iir           PoolIirTunableConfig

      % Filter parameters      
      AvgFirLength                uint32          = 532
      MaxFirLength                uint32          = 652
      MaxNumStages                uint32          = 20

      % Buffer Alias and Header file name
      BufferAlias
      HeaderFileName

      % Default tune values
      TuneDefaults  MedusaDrHoligramEqTuneConfig
  end

  properties(Dependent = true)
      DeciRateFrameSize           uint32
      FilterMapping               uint32
      FixedDelayLength            int32
      DelayStateInitVal           single
  end

  methods
    %----------------------------------------------------------------------
    function this = MedusaDrHoligramEqConfig()
        % MedusaDrHoligramEqConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.TuneDefaults =  MedusaDrHoligramEqTuneConfig(this);

        
        this.Default(@this.Fir, @() this.ConstructFir());
        this.Default(@this.Iir, @() this.ConstructIir());
     
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

        % Set code gen attributes for Hybrid Holigram EQ "states"
        MedusaHoligramMaskInit(blockHandle, this.BufferAlias, this.HeaderFileName);

        %.Call base class in case it has any work to perform:
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

    function value = get.DeciRateFrameSize(this)
        value = this.FullRateFrameSize/this.DecimationFactor;
    end

    function value = get.FilterMapping(this)
        value = (0:1:this.TotalNumEqLinks-1)';
    end

    function value = get.FixedDelayLength(this)
        % Delay line length depends  on the max absolute FIR length, as we
        % always delay by the max samples per input and tape out at different
        % points based on the actual delay amount per EQ link in order to 
        % share delay states for EQ links sharing the same input.
        value = int32(this.MaxFirLength + this.DeciRateFrameSize);
    end

    function value = get.DelayStateInitVal(this)
        value = zeros(this.FixedDelayLength, this.NumInputs);
    end
   
    function config = ConstructFir(this)
        config = FirConfig;
        config.NumOutputs = this.TotalNumEqLinks;
        config.NumInputs = this.NumInputs;
        config.FrameSize = this.FullRateFrameSize/this.DecimationFactor;
        config.MaxAvgCoeffLength = this.MaxFirLength;
        config.Alias = 'MedusaDrHoligramFirEq';

		%@SSC-TODO
		config.SelectVariant(this.Variant);
		%config.Variant = 'Hexagon';        
    end

    function config = ConstructIir(this)
        config = PoolIirTunableConfig;
        %sos = [1 0 0 1 0 0];
        [b, a] = butter(2,0.99);
        sos = [b a];
        sos = repmat(sos, 12, 1);
        config.TuneDefaults.NumStages = size(sos, 1) * ones(1,this.TotalNumEqLinks);
        config.TuneDefaults.SosCoefficients = repmat(sos, this.TotalNumEqLinks, 1);

        config.FrameSize = this.DeciRateFrameSize;
        config.MaxNumStages = this.MaxNumStages * this.TotalNumEqLinks;
        config.NumChannels = this.TotalNumEqLinks;
        config.SelectVariant(this.Variant);
        config.Alias = 'MedusaDrHoligramIirEq';
    end

  end
end
