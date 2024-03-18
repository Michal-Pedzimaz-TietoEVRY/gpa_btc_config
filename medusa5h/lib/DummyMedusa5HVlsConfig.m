classdef DummyMedusa5HVlsConfig < BtcBaseClass
    % This is a dummy file that will be used for the discussion of sharing
    % BTC between Algorithm and Tools teams. This file shall be
    % deleted or merged with other Medusa system level configs
    % Est. timeline of discussion: Jun '23 - Dec '23

    % DummyMedusa5HVlsConfig Build-time configuration class for the Medusa5H1Stereo block
    % This is a work in progress during the BTC upgrade process.
    % Usage:
    %    aConfig = DummyMedusa5HVlsConfig
    %

    %   Copyright 2022 Bose Corporation

    
    properties (GetObservable,SetObservable)
        % Basic parameters
        SampleRate                   {ExportToApi}              = 44100     % Sample rate for full-rate processing
        FullRateFrameSize            {ExportToApi}              = 32        % Frame size for full-rate processing
        DecimationFactor                                        = 4

        % System I/O Channel Configuration
        NumInputs           {mustBeMember(NumInputs, [2,6,10])} = 2         % Stereo Input
        NumCenterChannels                                       = 2         % Number of center channels
        NumSurroundChannels                                     = 0         % Number of surround channels
        NumLeftRightSpeakerPairs                                = 4         % Number of left or right channels (Value of '6' means that there are 6 left and 6 right speakers)
        NumOverheadSpeakerPairs                                 = 2         % Number of overhead speakers (Value of '2' means that there are 2 left and 2 right speakers)
        NumVlsHeadrestSpeakerPairs                              = 2         % Number of headrest speakers (Value of '2' means that there are 2 left and 2 right speakers)

        % Supported Add-ons
        IncludeCaeSupport   {ExportToApi, mustBeMember(IncludeCaeSupport, [0,1])}  = 0
        IncludeNearSupport  {ExportToApi, mustBeMember(IncludeNearSupport, [0,1])} = 0

        % Bass Manager configuration
        BassXofOrder                {ExportToApi}               = 5
        BassLpfFc                   {ExportToApi}               = 90

        % Max delay values
        DeciRateMaxWiggleDelay          int32   {ExportToApi}   = 166
        DeciRateMaxNearWiggleDelay      int32   {ExportToApi}   = 166
        MaxHoligramDelay                int32   {ExportToApi}   = 1764
        MaxFullRateHoligramDelay        int32   {ExportToApi, mustBeNonnegative} = 45
        MaxSpeakerDelay                 int32   {ExportToApi, mustBeNonnegative} = 1323
        
        % Holigram Configuration
        MaximumHoligramFirLength                    = 650
        AverageHoligramFirLength                    = 530
        MaximumDeciRateHoligramEqStagesPerLink      = 20
        MaximumFullRateHoligramEqStagesPerSpeaker   = 8
        NumHoligramEqPerSpeaker         {mustBeMember(NumHoligramEqPerSpeaker, [2,4,6,8,10,12])}    = 8

        % Component Configuration
        CaeEnable MedusaCaeEnableConfig
        TrebleBoost TrebleBoostStereoConfig
        BassManager MedusaBassManagerStereoConfig
        MonoDetector MedusaMonoDetectorConfig
        PremixCaeEnable MedusaCaeEnableConfig
    end

    properties(SetAccess = private)
        DeciRateFrameSize                           = 8

        NumPeripheralChannels       {ExportToApi}   = 15
        NumSystemChannels           {ExportToApi}   = 15
        NumDeciRateChannels         {ExportToApi}   = 15
        NumHeadrestComps            {ExportToApi}   = 6                     % Design-time parameter
    end
    
    methods
        function this = DummyMedusa5HVlsConfig()
            this.CaeEnable = MedusaCaeEnableConfig();
            this.TrebleBoost = TrebleBoostStereoConfig();
            this.BassManager = MedusaBassManagerStereoConfig();
            this.MonoDetector = MedusaMonoDetectorConfig();
            this.PremixCaeEnable = MedusaCaeEnableConfig();
            
            % Lock medusa component properties
            this.LockCompSampleRate();
            this.LockCompFrameSize();
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            this.DeciRateFrameSize = this.FullRateFrameSize/this.DecimationFactor;

            this.NumPeripheralChannels = this.NumCenterChannels + this.NumSurroundChannels + 2*this.NumLeftRightSpeakerPairs;
            this.NumSystemChannels = this.NumPeripheralChannels + 2*this.NumOverheadSpeakerPairs + 2*this.NumVlsHeadrestSpeakerPairs;
            this.NumDeciRateChannels = this.NumPeripheralChannels + 2*this.NumOverheadSpeakerPairs + this.NumHeadrestComps*this.NumVlsHeadrestSpeakerPairs;

            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);
        end

        %----------------------------------------------------------------------
        function LockCompSampleRate(this)
            this.LockPropertyAsAlias('BassManager.SampleRate', 'SampleRate');
            this.LockPropertyAsAlias('TrebleBoost.SampleRate', 'SampleRate');
            this.LockPropertyAsAlias('MonoDetector.SampleRate', 'SampleRate');
        end

        function LockCompFrameSize(this)
            this.LockPropertyAsAlias('TrebleBoost.FrameSize', 'FullRateFrameSize');
        end

    end
end

