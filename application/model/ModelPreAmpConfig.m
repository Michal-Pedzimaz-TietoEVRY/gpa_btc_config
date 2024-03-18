classdef ModelPreAmpConfig < BtcBaseClass
% ModelPreAmpConfig Build-time configuration class for the ModelPreAmp block
% Usage:
%    aConfig = ModelPreAmpConfig
%

%   Copyright 2024 Bose Corporation
    properties (GetObservable,SetObservable)
        DspTarget = 'Generic'
        SampleRate = 48000*12/13;
        FrameSize = 32
        AudiopilotNumMicIn = 0
        AudiopilotNumMusicIn = 2
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
        NearEnable = 0
        SleepingBeautyEnabled = 1
        SrcDn SampleRateConverterConfig
        SrcUp SampleRateConverterConfig
        NearPreAmpConfig PreAmpConfig
        NearWiggleFilter WiggleFilterConfig
        Bass ToneConfig
        Treble ToneConfig
        Midrange MidrangeConfig
        VolumeCfg VolumeConfig 
        Audiopilot Audiopilot_3_5Config
        LDCfg EntertainmentLevelDetectionConfig
        Balance_Cfg BalanceConfig
        MedusaBTC Medusa5HVlsConfig
        MedusaConfig struct
        VLSConfig struct
    end
    
    methods
        function this = ModelPreAmpConfig()
            this.SrcDn = SampleRateConverterConfig;
            this.SrcDn.Upfactor = 12;
            this.SrcDn.Downfactor = 13;    

            this.SrcUp = SampleRateConverterConfig;
            this.SrcUp.Upfactor = 13;
            this.SrcUp.Downfactor = 12;

            this.Bass = ToneConfig();
            this.Bass.DefaultBoostDb = 20;
            this.Bass.DefaultBoostHz = 120;
            this.Bass.DefaultCutDb = 20;
            this.Bass.DefaultCutHz = 120;
            this.Bass.DefaultOffset = 128;
            this.Bass.DefaultScale = 127;
            this.Bass.BankNumber = 0;
            this.Bass.FilterType = "lowpass";

            this.Treble = ToneConfig();
            this.Treble.DefaultBoostDb = 20;
            this.Treble.DefaultBoostHz = 4000;
            this.Treble.DefaultCutDb = 20;
            this.Treble.DefaultCutHz = 4000;
            this.Treble.DefaultOffset = 128;
            this.Treble.DefaultScale = 127;
            this.Treble.BankNumber = 0;
            this.Treble.FilterType = "highpass";

            this.Midrange = MidrangeConfig();   

            this.VolumeCfg = VolumeConfig();           
            this.VolumeCfg.InitialLinearGain = 1.0;
            this.VolumeCfg.DefaultTable = [0 -100; 0.5 -30; 1 0];
            this.VolumeCfg.MaximumTablePoints = 8;
            this.VolumeCfg.BankNumber = 0;

            this.Audiopilot = Audiopilot_3_5Config();
            this.Audiopilot.HfNoise.BpLpFiltVariant = this.DspTarget;
            this.Audiopilot.HfNoise.AaFiltVariant   = this.DspTarget;
            this.Audiopilot.LfNoise.MicFiltVariant  = this.DspTarget;
            this.Audiopilot.LfNoise.RefFiltVariant  = this.DspTarget;
            this.Audiopilot.HfNoise.RfftWindowingStft.Variant = this.DspTarget;
            this.Audiopilot.LfNoise.RfftWindowingStft.Variant = this.DspTarget;
        
            this.LDCfg = EntertainmentLevelDetectionConfig();                    
            this.LDCfg.LevDetPreEmpPooliirVariant = this.DspTarget;

            this.Balance_Cfg = BalanceConfig;
            this.Balance_Cfg.DefaultMaskChanRampMap = [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1];

            this.MedusaBTC = Medusa5HVlsConfig();
            this.MedusaBTC.Variant = this.DspTarget;
            this.MedusaBTC.BassManager.Lpf.Variant = this.DspTarget;
            this.MedusaBTC.BassManager.Hpf.Variant = this.DspTarget;
            this.MedusaBTC.SampleRate = this.SampleRate;
            this.MedusaBTC.BassManager.XofOrder = this.MedusaBassManagerXofOrder;
            this.MedusaBTC.BassManager.LpfFc = this.MedusaBassManagerLpfFc;
            this.MedusaBTC.NumCenterChannels = this.MedusaNumCenterChannels;
            this.MedusaBTC.NumSurroundChannels = this.MedusaNumSurroundChannels;
            this.MedusaBTC.NumLeftRightSpeakerPairs = this.MedusaNumLeftRightSpeakerPairs;
            this.MedusaBTC.NumOverheadSpeakerPairs = this.MedusaNumOverheadSpeakerPairs;
            this.MedusaBTC.NumVlsHeadrestSpeakerPairs = this.MedusaNumVlsHeadrestSpeakerPairs;
            this.MedusaBTC.AvgPeripheralFirLength = this.MedusaAvgPeripheralFirLength;
            this.MedusaBTC.MaxPeripheralFirLength = this.MedusaMaxPeripheralFirLength;
            this.MedusaBTC.MaxPeripheralNumStages = this.MedusaMaxPeripheralNumStages;
            this.MedusaBTC.AvgOverheadFirLength = this.MedusaAvgOverheadFirLength;
            this.MedusaBTC.MaxOverheadFirLength = this.MedusaMaxOverheadFirLength;
            this.MedusaBTC.MaxOverheadNumStages = this.MedusaMaxOverheadNumStages;
            this.MedusaBTC.DeciRateFdp.Rfft.SelectVariant(this.DspTarget);
            this.MedusaBTC.DeciRateFdp.Rifft.SelectVariant(this.DspTarget);
            this.MedusaBTC.FullRateFdp.Rfft.SelectVariant(this.DspTarget);
            this.MedusaBTC.FullRateFdp.Rifft.SelectVariant(this.DspTarget);
            this.MedusaBTC.PeripheralHoligramEq.HoligramEq.Iir.SelectVariant(this.DspTarget);
            this.MedusaBTC.OverheadHoligramEq.HoligramEq.Iir.SelectVariant(this.DspTarget);
            this.MedusaBTC.Validate();
       
            
        end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

  end
end

