classdef VolumeMuteConfig < BtcBaseClass
    % VolumeMuteConfig Build-time configuration class for the VolumeMute block
    % Usage:
    %   aConfig = VolumeMuteConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        % System Level Build Time Parameters
        FsFast = 44100
        FrameSize = 32
        AnnChannelCount = 4
        DecimationFactor = 4

        % Child Blocks
        Ann1NonEntGainCalc NonEntGainCalcConfig
        Ann1Volume AnnVolumeConfig
        Ann1NonEntVncApplied NonEntVncAppliedConfig
        Ann1Mute MuteConfig

        Ann2Volume AnnVolumeConfig
        Ann2NonEntGainCalc NonEntGainCalcConfig
        Ann2NonEntVncApplied NonEntVncAppliedConfig
        Ann2Mute MuteConfig

        Ann3Volume AnnVolumeConfig
        Ann3NonEntGainCalc NonEntGainCalcConfig
        Ann3NonEntVncApplied NonEntVncAppliedConfig
        Ann3Mute MuteConfig

        Ann4Volume AnnVolumeConfig
        Ann4NonEntGainCalc NonEntGainCalcConfig
        Ann4NonEntVncApplied NonEntVncAppliedConfig
        Ann4Mute MuteConfig

        AnnouncementLevelDetector AnnouncementLevelDetectorConfig
    end
    methods
        %----------------------------------------------------------------------
        function this = VolumeMuteConfig()
            % VolumeMuteConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.AnnouncementLevelDetector =  AnnouncementLevelDetectorConfig;
            
            this.Lock(@this.AnnouncementLevelDetector.FsFast,@()this.FsFast);
            this.Lock(@this.AnnouncementLevelDetector.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.AnnouncementLevelDetector.FrameSize,@()this.FrameSize);
            this.Lock(@this.AnnouncementLevelDetector.FrameRate,@()this.FsFast/this.FrameSize);

            this.Ann1Volume =  AnnVolumeConfig;
            this.Ann1Mute =  MuteConfig;
            this.Ann1NonEntVncApplied =  NonEntVncAppliedConfig;
            this.Ann1NonEntGainCalc =  NonEntGainCalcConfig;

            %Tune Parameters for NonEntGainCalc
            this.Ann1NonEntGainCalc.DefaultVncEnable = 1;
            this.Ann1NonEntGainCalc.DefaultVncThresh = zeros(1,1);
            this.Ann1NonEntGainCalc.DefaultVncSlope = 0.4*ones(1,1);
            this.Ann1NonEntGainCalc.DefaultMaxBoost = 18*ones(1,1);
            this.Ann1NonEntGainCalc.DefaultMaxSpl=120*ones(1,1);
            this.Ann1NonEntGainCalc.DefaultMinVncSignal = 40;
            this.Ann1NonEntGainCalc.DefaultTau = 0.1;
            this.Ann1NonEntGainCalc.DefaultNoiseOverrideFlag = zeros(1,1);
            this.Ann1NonEntGainCalc.DefaultNoiseOverride = 0;
            this.Ann1NonEntGainCalc.DefaultBoostOverride = zeros(1,1);
            this.Ann1NonEntGainCalc.DefaultBoostOverrideFlag = zeros(1,1);
            this.Lock(@this.Ann1NonEntGainCalc.Fd,@()this.FsFast/this.DecimationFactor);

            %Tune Parameters for NonEntVncApplied
            this.Lock(@this.Ann1NonEntVncApplied.FrameSize,@()this.FrameSize);

            this.Ann2Volume =  AnnVolumeConfig;
            this.Ann2Mute =  MuteConfig;
            this.Ann2NonEntVncApplied =  NonEntVncAppliedConfig;
            this.Ann2NonEntGainCalc =  NonEntGainCalcConfig;

            %Tune Parameters for NonEntGainCalc
            this.Ann2NonEntGainCalc.DefaultVncEnable = 1;
            this.Ann2NonEntGainCalc.DefaultVncThresh = zeros(1,1);
            this.Ann2NonEntGainCalc.DefaultVncSlope = 0.4*ones(1,1);
            this.Ann2NonEntGainCalc.DefaultMaxBoost = 18*ones(1,1);
            this.Ann2NonEntGainCalc.DefaultMaxSpl=120*ones(1,1);
            this.Ann2NonEntGainCalc.DefaultMinVncSignal = 40;
            this.Ann2NonEntGainCalc.DefaultTau = 0.1;
            this.Ann2NonEntGainCalc.DefaultNoiseOverrideFlag = zeros(1,1);
            this.Ann2NonEntGainCalc.DefaultNoiseOverride = 0;
            this.Ann2NonEntGainCalc.DefaultBoostOverride = zeros(1,1);
            this.Ann2NonEntGainCalc.DefaultBoostOverrideFlag = zeros(1,1);
            this.Lock(@this.Ann2NonEntGainCalc.Fd,@()this.FsFast/this.DecimationFactor);

            %Tune Parameters for NonEntVncApplied
            this.Lock(@this.Ann2NonEntVncApplied.FrameSize,@()this.FrameSize);

            this.Ann3Volume =  AnnVolumeConfig;
            this.Ann3Mute =  MuteConfig;
            this.Ann3NonEntVncApplied =  NonEntVncAppliedConfig;
            this.Ann3NonEntGainCalc =  NonEntGainCalcConfig;

            %Tune Parameters for NonEntGainCalc
            this.Ann3NonEntGainCalc.DefaultVncEnable = 1;
            this.Ann3NonEntGainCalc.DefaultVncThresh = zeros(1,1);
            this.Ann3NonEntGainCalc.DefaultVncSlope = 0.4*ones(1,1);
            this.Ann3NonEntGainCalc.DefaultMaxBoost = 18*ones(1,1);
            this.Ann3NonEntGainCalc.DefaultMaxSpl=120*ones(1,1);
            this.Ann3NonEntGainCalc.DefaultMinVncSignal = 40;
            this.Ann3NonEntGainCalc.DefaultTau = 0.1;
            this.Ann3NonEntGainCalc.DefaultNoiseOverrideFlag = zeros(1,1);
            this.Ann3NonEntGainCalc.DefaultNoiseOverride = 0;
            this.Ann3NonEntGainCalc.DefaultBoostOverride = zeros(1,1);
            this.Ann3NonEntGainCalc.DefaultBoostOverrideFlag = zeros(1,1);
            this.Lock(@this.Ann3NonEntGainCalc.Fd,@()this.FsFast/this.DecimationFactor);

            %Tune Parameters for NonEntVncApplied
            this.Lock(@this.Ann3NonEntVncApplied.FrameSize,@()this.FrameSize);

            this.Ann4Volume =  AnnVolumeConfig;
            this.Ann4Mute =  MuteConfig;
            this.Ann4NonEntVncApplied =  NonEntVncAppliedConfig;
            this.Ann4NonEntGainCalc =  NonEntGainCalcConfig;

            %Tune Parameters for NonEntGainCalc
            this.Ann4NonEntGainCalc.DefaultVncEnable = 1;
            this.Ann4NonEntGainCalc.DefaultVncThresh = zeros(1,1);
            this.Ann4NonEntGainCalc.DefaultVncSlope = 0.4*ones(1,1);
            this.Ann4NonEntGainCalc.DefaultMaxBoost = 18*ones(1,1);
            this.Ann4NonEntGainCalc.DefaultMaxSpl=120*ones(1,1);
            this.Ann4NonEntGainCalc.DefaultMinVncSignal = 40;
            this.Ann4NonEntGainCalc.DefaultTau = 0.1;
            this.Ann4NonEntGainCalc.DefaultNoiseOverrideFlag = zeros(1,1);
            this.Ann4NonEntGainCalc.DefaultNoiseOverride = 0;
            this.Ann4NonEntGainCalc.DefaultBoostOverride = zeros(1,1);
            this.Ann4NonEntGainCalc.DefaultBoostOverrideFlag = zeros(1,1);
            this.Lock(@this.Ann4NonEntGainCalc.Fd,@()this.FsFast/this.DecimationFactor);

            %Tune Parameters for NonEntVncApplied
            this.Lock(@this.Ann4NonEntVncApplied.FrameSize,@()this.FrameSize);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
