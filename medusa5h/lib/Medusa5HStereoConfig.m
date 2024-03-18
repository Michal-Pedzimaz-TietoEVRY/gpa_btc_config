classdef Medusa5HStereoConfig < BtcBaseClass
    % Medusa5HStereoConfig Build-time configuration class for the Medusa5H1Stereo block
    % This is a work in progress during the BTC upgrade process.
    % Usage:
    %    aConfig = Medusa5HStereoConfig
    %

    %   Copyright 2022 Bose Corporation

    
    properties (GetObservable,SetObservable)
        % Basic parameters
        SampleRate                                  = 44100                 % Sample rate for full-rate processing
        FullRateFrameSize                           = 32                    % Frame size for full-rate processing
        DecimationFactor                            = 4

        % System Channel Configuration
        NumCenterChannels                           = 2                     % Number of center channels
        NumSurroundChannels                         = 1                     % Number of surround channels
        NumLeftRightSpeakerPairs                    = 6                     % Number of left or right channels (Value of '6' means that there are 6 left and 6 right speakers)
        NumOverheadSpeakerPairs                     = 0                     % Number of overhead speakers (Value of '2' means that there are 2 left and 2 right speakers)
        NumVlsHeadrestSpeakerPairs                  = 0                     % Number of headrest speakers (Value of '2' means that there are 2 left and 2 right speakers)

        % Holigram EQ Configuration
        NumHoligramEqLinks          uint32      {mustBeMember(NumHoligramEqLinks,[2, 4, 6, 8, 10, 12])} = 8
        
        AvgPeripheralFirLength      uint32          = 530
        MaxPeripheralFirLength      uint32          = 650
        MaxPeripheralNumStages      uint32          = 20

        AvgOverheadFirLength        uint32          = 530
        MaxOverheadFirLength        uint32          = 650
        MaxOverheadNumStages        uint32          = 20

        % Component Configuration
        CaeEnable MedusaCaeEnableConfig
        TrebleBoost TrebleBoostStereoConfig
        BassManager MedusaBassManagerStereoConfig
        MonoDetector MedusaMonoDetectorConfig
        DeciRateBassDelay MedusaAlignmentDelayConfig
        FullRateBassDelay MedusaAlignmentDelayConfig
        MidrangeDelay MedusaAlignmentDelayConfig
        TrebleDelay MedusaAlignmentDelayConfig
        FullRateHoligramDelay MedusaTunableDelayConfig
        SpeakerDelay MedusaTunableDelayConfig
        AlignmentDelayTranslation MedusaAlignmentDelayTranslationConfig
        TrebleDelayTranslation MedusaFullRateAlignmentDelayTranslationConfig
        FullRateHoligramDelayTranslation MedusaFullRateHoligramDelayTranslationConfig
        SpeakerDelayTranslation MedusaSpeakerDelayTranslationConfig
        PremixCaeEnable MedusaCaeEnableConfig
        PeripheralHoligramEq MedusaPeripheralHoligramEqConfig
        OverheadHoligramEq MedusaOverheadHoligramEqConfig
    end

    properties(Dependent = true)
        % Platform Configuration
        % This parameter, which indicates the target DSP, eventually influences the CRL
        % selection during code gen. For Generic, Hexagon, ARM and SharcPlusCore, the
        % parameter propagates the same value to all the applicable components. However,
        % for SharcPlusAccel variants (applicable for GUL and GXP processors), only
        % Holigram EQ is switched to use accelerators. Rest of the filter instances will
        % default to SharcPlusCore even though those instances support accelerator variants.        % Add comment to describe the variant usage between Medusa and
        % Holigram
        Variant     char    {isaValidPlatformVariant(Variant)}
    end

    properties(SetAccess = private)
        DeciRateFrameSize                           = 8

        NumPeripheralChannels                       = 15
        NumSystemChannels                           = 15
        NumDeciRateChannels                         = 15
        NumHeadrestComps                            = 6                     % Design-time parameter

        DefaultFullRateMixerOutput
        DefaultOverheadHoligramEqOutput

        DefaultMedusaVariant                        = 'Generic'
        DefaultHoligramVariant                      = 'Generic'
    end

    methods
        function this = Medusa5HStereoConfig()
            this.CaeEnable = MedusaCaeEnableConfig();
            this.TrebleBoost = TrebleBoostStereoConfig();
            this.BassManager = MedusaBassManagerStereoConfig();
            this.MonoDetector = MedusaMonoDetectorConfig();
            this.DeciRateBassDelay = MedusaAlignmentDelayConfig('DeciRateBassDelay');
            this.FullRateBassDelay = MedusaAlignmentDelayConfig('FullRateBassDelay');
            this.MidrangeDelay = MedusaAlignmentDelayConfig('MidrangeDelay');
            this.AlignmentDelayTranslation = MedusaAlignmentDelayTranslationConfig;
            this.TrebleDelay = MedusaAlignmentDelayConfig('TrebleDelay');
            this.TrebleDelayTranslation = MedusaFullRateAlignmentDelayTranslationConfig;
            this.FullRateHoligramDelay = MedusaTunableDelayConfig('FullRateHoligramDelay');
            this.FullRateHoligramDelayTranslation = MedusaFullRateHoligramDelayTranslationConfig;
            this.SpeakerDelay = MedusaTunableDelayConfig('SpeakerDelay');
            this.SpeakerDelayTranslation = MedusaSpeakerDelayTranslationConfig;
            this.PremixCaeEnable = MedusaCaeEnableConfig();
            this.PeripheralHoligramEq = MedusaPeripheralHoligramEqConfig;
            this.OverheadHoligramEq = MedusaOverheadHoligramEqConfig;
            
            % Lock medusa component properties
            this.LockCompSampleRate();
            this.LockCompFrameSize();
            this.LockCompChannelCount();
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);

            this.DeciRateFrameSize = this.FullRateFrameSize/this.DecimationFactor;

            this.NumPeripheralChannels = this.NumCenterChannels + this.NumSurroundChannels + 2*this.NumLeftRightSpeakerPairs;
            this.NumSystemChannels = this.NumPeripheralChannels + 2*this.NumOverheadSpeakerPairs + 2*this.NumVlsHeadrestSpeakerPairs;
            this.NumDeciRateChannels = this.NumPeripheralChannels + this.NumHeadrestComps*this.NumVlsHeadrestSpeakerPairs;

            this.DefaultFullRateMixerOutput = zeros(this.FullRateFrameSize, this.NumSystemChannels);
            this.DefaultOverheadHoligramEqOutput = zeros(this.DeciRateFrameSize, max(2*this.NumOverheadSpeakerPairs,1));
        end

        function value = get.Variant(this)
            value = this.DefaultHoligramVariant;
        end

        function set.Variant(this, value)
            this.DefaultMedusaVariant = value;
            this.DefaultHoligramVariant = value;
            if(startsWith(this.DefaultMedusaVariant, 'SharcPlus'))
                this.DefaultMedusaVariant = 'SharcPlusCore';
            end
            this.UpdatePlatformVariant();
        end

        function UpdatePlatformVariant(this)
            sprintf("Updating all Medusa components to use - %s and all Holigram filters to use - %s", this.DefaultMedusaVariant, this.DefaultHoligramVariant)
            this.TrebleBoost.Variant = this.DefaultMedusaVariant;
            this.BassManager.Variant = this.DefaultMedusaVariant;
            this.MonoDetector.Variant = this.DefaultMedusaVariant;
            this.PeripheralHoligramEq.Variant = this.DefaultHoligramVariant;
            this.OverheadHoligramEq.Variant = this.DefaultHoligramVariant;
        end
        %----------------------------------------------------------------------
        function LockCompSampleRate(this)
            this.LockPropertyAsAlias('BassManager.SampleRate', 'SampleRate');
            this.LockPropertyAsAlias('TrebleBoost.SampleRate', 'SampleRate');
            this.LockPropertyAsAlias('MonoDetector.SampleRate', 'SampleRate');
        end
        function LockCompFrameSize(this)
            this.LockPropertyAsAlias('TrebleBoost.FrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('DeciRateBassDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('FullRateBassDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('MidrangeDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('TrebleDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('FullRateHoligramDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('SpeakerDelay.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('AlignmentDelayTranslation.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('TrebleDelayTranslation.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('SpeakerDelayTranslation.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('PeripheralHoligramEq.FullRateFrameSize', 'FullRateFrameSize');
            this.LockPropertyAsAlias('OverheadHoligramEq.FullRateFrameSize', 'FullRateFrameSize');
        end
        function LockCompChannelCount(this)
            this.LockPropertyAsAlias('SpeakerDelay.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('SpeakerDelay.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('SpeakerDelay.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');
            this.LockPropertyAsAlias('SpeakerDelay.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
            this.LockPropertyAsAlias('SpeakerDelay.NumVlsHeadrestSpeakerPairs', 'NumVlsHeadrestSpeakerPairs');

            this.LockPropertyAsAlias('FullRateHoligramDelay.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('FullRateHoligramDelay.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('FullRateHoligramDelay.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');
            this.LockPropertyAsAlias('FullRateHoligramDelay.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
            this.LockPropertyAsAlias('FullRateHoligramDelay.NumVlsHeadrestSpeakerPairs', 'NumVlsHeadrestSpeakerPairs');

            this.LockPropertyAsAlias('SpeakerDelayTranslation.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('SpeakerDelayTranslation.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('SpeakerDelayTranslation.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');
            this.LockPropertyAsAlias('SpeakerDelayTranslation.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
            this.LockPropertyAsAlias('SpeakerDelayTranslation.NumVlsHeadrestSpeakerPairs', 'NumVlsHeadrestSpeakerPairs');
            
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
            this.LockPropertyAsAlias('FullRateHoligramDelayTranslation.NumVlsHeadrestSpeakerPairs', 'NumVlsHeadrestSpeakerPairs');

            this.LockPropertyAsAlias('PeripheralHoligramEq.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('PeripheralHoligramEq.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('PeripheralHoligramEq.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');

            this.LockPropertyAsAlias('OverheadHoligramEq.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
        end
    end
end

