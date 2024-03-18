classdef ModelConfig < BtcBaseClass
% ModelConfig Build-time configuration class for the Model block
% Usage:
%    aConfig = ModelConfig
%

%   Copyright 2024 Bose Corporation 

  properties
    %.Properties use this syntax:
    %.   PropertyName size class {validation functions} = DefaultValue
    %.About Build-Time Configuration: https://wiki.bose.com/x/dqPoB
    SampleRate = 48000
    ModelFrameSize = 32
    NumInputAudioChannels = 4 % 2 ANN, 2 ENT
    NumOutputAudioChannels = 24
    NumInputMicChannels = 1 % For Module 5 In-Line RMS
    annMap = [1 2]
    entMap = [3 4]
    vncMic = [5]
    BypassMap = 1:32;
    DspTarget = 'Hexagon'
    
    % TestRouter
    TestRouterEnableAuxSrcs = 0;
    TestRouterAuxGains = zeros(1, 24);
    
    % Near
    NearEnable = 0;
    NearRouterNumOut = 18;

    % PreAmp
    DefaultMaskChanRampMap = [1 2]
    SleepingBeautyEnabled = 1

    % Medusa
    MedusaBassManagerXofOrder = 3
    MedusaBassManagerLpfFc = 90
    MedusaNumCenterChannels = 2
    MedusaNumSurroundChannels = 0
    MedusaNumLeftRightSpeakerPairs = 8
    MedusaNumOverheadSpeakerPairs = 0
    MedusaNumVlsHeadrestSpeakerPairs = 2
    MedusaAvgPeripheralFirLength = 532
    MedusaMaxPeripheralFirLength = 652
    MedusaMaxPeripheralNumStages = 20
    MedusaAvgOverheadFirLength = 532
    MedusaMaxOverheadFirLength = 652
    MedusaMaxOverheadNumStages = 20

    % Simulation input signal
    InputAudioChannelFreqs = [50 1000 50 1000]
    InputMicChannelFreqs = [500]
    InputAudioChannelAmps = [0.5 0.5 0.5 0.5]
    InputMicChannelAmps = [0]

    Inport ModelRootInportConfig
    InputSelect InputSelectConfig
    NearConfig NearConfig
    ModelPreAmp ModelPreAmpConfig
    TestRouter AsdRouterConfig
    PostProcess PostProcessConfig  
    Outport ModelRootOutportConfig  
    

  end

  methods
    %----------------------------------------------------------------------
    function this = ModelConfig()
        % ModelConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        
        % Inport Config
        this.Inport =  ModelRootInportConfig();
        this.Lock(@this.Inport.SampleRateInHertz, ...
            @() this.SampleRate);
        this.Lock(@this.Inport.ChannelCount, ...
            @() (this.NumInputAudioChannels + this.NumInputMicChannels));
        this.Default(@this.Inport.BufferName, 'UnitTest_Target_AudioIn');
        this.Default(@this.Inport.AccessType, 'ImportedPointer');

        % InputSelect Config
        this.InputSelect =  InputSelectConfig();
        this.Lock(@this.InputSelect.annMap, @() (this.annMap));
        this.Lock(@this.InputSelect.entMap, @() (this.entMap));
        this.Lock(@this.InputSelect.vncMic, @() (this.vncMic));
        this.Lock(@this.InputSelect.NumInputChannels, ...
            @() (this.NumInputAudioChannels + this.NumInputMicChannels));
        ChannelMap = [this.annMap this.entMap this.vncMic];
        this.Lock(@this.InputSelect.InputSelectOutputMap, ...
            @() (ChannelMap));
     

        % TestRouter Config
        this.TestRouter = AsdRouterConfig();
        this.Lock(@this.TestRouter.FrameSize, @() this.ModelFrameSize);
        this.Lock(@this.TestRouter.NumChanOut, @() this.NumOutputAudioChannels);  
        this.Lock(@this.TestRouter.MainSelect, @() 1:this.NumOutputAudioChannels);
        this.Lock(@this.TestRouter.NumMainCh, @() this.NumOutputAudioChannels);  
        this.Lock(@this.TestRouter.MainGain, @() ones(1, this.NumOutputAudioChannels));
        this.Lock(@this.TestRouter.EnableAux, @() this.TestRouterEnableAuxSrcs);
        this.Lock(@this.TestRouter.NumAux, @() numel(this.BypassMap));
        this.Lock(@this.TestRouter.AuxGain, @() this.TestRouterAuxGains);

        % Near Config
        this.NearConfig = NearConfig();
        this.NearConfig.NumEntInputChannels = numel(this.entMap);
        this.NearConfig.AnnChannelCount = numel(this.annMap);
        this.NearConfig.NumOutputAudioChannels = this.NumOutputAudioChannels;
        this.NearConfig.Validate();
        this.NearConfig.Near.NearBandSplit.BandSplit.FirEven.Alias = 'NearBandSplit';
        this.NearConfig.Near.NearRouterNumOut = this.NearRouterNumOut;   
        this.NearConfig.Near.NearRouterMap = ones(1, this.NearRouterNumOut);
        this.NearConfig.NearWiggleFilter.FirEven.SelectVariant(this.DspTarget);
        this.NearConfig.Near.NearBandSplit.BandSplit.FirEven.SelectVariant(this.DspTarget);
        this.NearConfig.Near.FsEqDr.Pooliir.SelectVariant(this.DspTarget);
        this.NearConfig.Near.HrEqDr.PoolIirTunable.SelectVariant(this.DspTarget);
        this.NearConfig.Near.FsEqFr.Pooliir.SelectVariant(this.DspTarget);
        this.NearConfig.Near.HrEqFr.PoolIirTunable.SelectVariant(this.DspTarget);
        this.NearConfig.Near.VolumeMute.AnnouncementLevelDetector.PreEmphasisShelfFilter.Variant = this.DspTarget;
        this.NearConfig.Near.NearBandSplit.PoolIir.Variant = 'Generic';

        % PreAmp Config  
        this.ModelPreAmp = ModelPreAmpConfig();  
        this.ModelPreAmp.NearPreAmpConfig = this.NearConfig.NearPreAmpConfig; %copy parameters from NEAR above   
        this.ModelPreAmp.NearWiggleFilter = this.NearConfig.NearWiggleFilter; %copy parameters from NEAR above  
        this.ModelPreAmp.SleepingBeautyEnabled = this.SleepingBeautyEnabled;
        this.ModelPreAmp.NearEnable = this.NearConfig.NearEnabled; %copy parameters from NEAR above   
        this.ModelPreAmp.Audiopilot = Audiopilot_3_5Config();
        this.ModelPreAmp.Audiopilot.HfNoise.BpLpFiltVariant = this.DspTarget;
        this.ModelPreAmp.Audiopilot.HfNoise.AaFiltVariant   = this.DspTarget;
        this.ModelPreAmp.Audiopilot.LfNoise.MicFiltVariant  = this.DspTarget;
        this.ModelPreAmp.Audiopilot.LfNoise.RefFiltVariant  = this.DspTarget;
        this.ModelPreAmp.Audiopilot.HfNoise.RfftWindowingStft.Variant = this.DspTarget;
        this.ModelPreAmp.Audiopilot.LfNoise.RfftWindowingStft.Variant = this.DspTarget;
        this.ModelPreAmp.AudiopilotNumMicIn = this.NumInputMicChannels;
        this.ModelPreAmp.AudiopilotNumMusicIn = length(this.entMap);
        this.ModelPreAmp.LDCfg.LevDetPreEmpPooliirVariant = this.DspTarget; 
        this.ModelPreAmp.Balance_Cfg.DefaultMaskChanRampMap = this.DefaultMaskChanRampMap;
        this.ModelPreAmp.MedusaBTC.Variant = this.DspTarget;
        this.ModelPreAmp.MedusaBTC.BassManager.Hpf.Variant = this.DspTarget;
        this.ModelPreAmp.MedusaBTC.BassManager.Lpf.Variant = this.DspTarget;
        this.ModelPreAmp.MedusaBTC.SampleRate = this.SampleRate*12/13; %Decimated sample rate
        this.ModelPreAmp.MedusaBTC.BassManager.XofOrder = this.MedusaBassManagerXofOrder;
        this.ModelPreAmp.MedusaBTC.BassManager.LpfFc = this.MedusaBassManagerLpfFc;
        this.ModelPreAmp.MedusaBTC.NumCenterChannels = this.MedusaNumCenterChannels;
        this.ModelPreAmp.MedusaBTC.NumSurroundChannels = this.MedusaNumSurroundChannels;
        this.ModelPreAmp.MedusaBTC.NumLeftRightSpeakerPairs = this.MedusaNumLeftRightSpeakerPairs;
        this.ModelPreAmp.MedusaBTC.NumOverheadSpeakerPairs = this.MedusaNumOverheadSpeakerPairs;
        this.ModelPreAmp.MedusaBTC.NumVlsHeadrestSpeakerPairs = this.MedusaNumVlsHeadrestSpeakerPairs;
        this.ModelPreAmp.MedusaBTC.AvgPeripheralFirLength = this.MedusaAvgPeripheralFirLength;
        this.ModelPreAmp.MedusaBTC.MaxPeripheralFirLength = this.MedusaMaxPeripheralFirLength;
        this.ModelPreAmp.MedusaBTC.MaxPeripheralNumStages = this.MedusaMaxPeripheralNumStages;
        this.ModelPreAmp.MedusaBTC.AvgOverheadFirLength = this.MedusaAvgOverheadFirLength;
        this.ModelPreAmp.MedusaBTC.MaxOverheadFirLength = this.MedusaMaxOverheadFirLength;
        this.ModelPreAmp.MedusaBTC.MaxOverheadNumStages = this.MedusaMaxOverheadNumStages;
        this.ModelPreAmp.MedusaBTC.DeciRateFdp.Rfft.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.DeciRateFdp.Rifft.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.FullRateFdp.Rfft.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.FullRateFdp.Rifft.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.PeripheralHoligramEq.HoligramEq.Iir.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.OverheadHoligramEq.HoligramEq.Iir.SelectVariant(this.DspTarget);
        this.ModelPreAmp.MedusaBTC.Validate();
                
        % Post Process Config
        this.PostProcess = PostProcessConfig();      

        % Outport Config
        this.Outport =  ModelRootOutportConfig();
        this.Default(@this.Outport.BufferName, 'UnitTest_Target_AudioOut');
        this.Default(@this.Outport.AccessType, 'ImportedPointer');  

    end

    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok

        %.If there are no cross-property interactions, then this entire
        %.method can be deleted!

        %.End with a call to our base class to continue validation checks
        %.including any violations of property locking.
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.

        %.If there are no CscUtil code generation settings or other canvas
        %.interactions, this entire method can be deleted!
        %.Avoid making design-time changes - find another way if possible.
        %.(e.g. avoid calling: set_param, add_block, replace_block).
        %.If there's an error, just call the error function!

        %.Call base class in case it has any work to perform:
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

  end
end
