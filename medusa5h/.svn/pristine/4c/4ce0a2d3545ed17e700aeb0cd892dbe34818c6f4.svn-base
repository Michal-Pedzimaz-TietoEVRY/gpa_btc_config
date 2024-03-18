classdef DummyModelConfig < BtcBaseClass
    % This is a dummy file that will be used for the discussion of sharing
    % BTC between Algorithm and Tools teams. This file shall be deleted at
    % the end of the discussion
    % Est. timeline of discussion: Jun '23 - Dec '23

    % DummyModelConfig Build-time configuration class for the Medusa5H1Stereo block
    % This is a work in progress during the BTC upgrade process.
    % Usage:
    %    aConfig = DummyModelConfig
    %

    %   Copyright 2022 Bose Corporation

    
    properties (GetObservable,SetObservable)
        % Basic parameters
        SampleRate                   {ExportToApi}              = 44100      % Sample rate for full-rate processing
        FrameSize                    {ExportToApi}              = 32         % Frame size for full-rate processing
        
        % System I/O Channel Configuration
        NumInputs           {ExportToApi, mustBeMember(NumInputs, [2,6,10])} = 2         % Stereo Input
        NumCenterChannels            {ExportToApi}               = 2         % Number of center channels
        NumSurroundChannels          {ExportToApi}               = 0         % Number of surround channels
        NumLeftRightSpeakerPairs     {ExportToApi}               = 4         % Number of left or right channels (Value of '6' means that there are 6 left and 6 right speakers)
        NumOverheadSpeakerPairs      {ExportToApi}               = 2         % Number of overhead speakers (Value of '2' means that there are 2 left and 2 right speakers)
        NumVlsHeadrestSpeakerPairs   {ExportToApi}               = 2         % Number of headrest speakers (Value of '2' means that there are 2 left and 2 right speakers)

        % NEAR Config
        IncludeNearSupport  {ExportToApi, mustBeMember(IncludeNearSupport, [0,1])} = 0

        % Medusa Config
        IncludeCaeSupport   {ExportToApi, mustBeMember(IncludeCaeSupport, [0,1])}  = 0       
        
        MaximumHoligramFirLength     {ExportToApi}              = 650
        AverageHoligramFirLength     {ExportToApi}              = 530
        MaximumDeciRateHoligramEqStagesPerLink      {ExportToApi}    = 20
        MaximumFullRateHoligramEqStagesPerSpeaker   {ExportToApi}    = 8
        NumHoligramEqPerSpeaker         {ExportToApi, mustBeMember(NumHoligramEqPerSpeaker, [2,4,6,8,10,12])}    = 8
        
        % Block Configuration
        MedusaConfig DummyMedusa5HVlsConfig
    end
    
    methods
        function this = DummyModelConfig()
            this.MedusaConfig = DummyMedusa5HVlsConfig();
            
            % Lock block properties
            this.LockCompSampleRate();
            this.LockCompFrameSize();

            this.LockMedusaProperties();
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);
        end

        %----------------------------------------------------------------------
        function LockCompSampleRate(this)
            this.LockPropertyAsAlias('MedusaConfig.SampleRate', 'SampleRate');
        end

        function LockCompFrameSize(this)
            this.LockPropertyAsAlias('MedusaConfig.FullRateFrameSize', 'FrameSize');
        end

        function LockMedusaProperties(this)
            this.LockPropertyAsAlias('MedusaConfig.IncludeCaeSupport', 'IncludeCaeSupport');
            this.LockPropertyAsAlias('MedusaConfig.IncludeNearSupport', 'IncludeNearSupport');

            % Channel Configuration
            this.LockPropertyAsAlias('MedusaConfig.NumInputs', 'NumInputs');
            this.LockPropertyAsAlias('MedusaConfig.NumCenterChannels', 'NumCenterChannels');
            this.LockPropertyAsAlias('MedusaConfig.NumSurroundChannels', 'NumSurroundChannels');
            this.LockPropertyAsAlias('MedusaConfig.NumLeftRightSpeakerPairs', 'NumLeftRightSpeakerPairs');
            this.LockPropertyAsAlias('MedusaConfig.NumOverheadSpeakerPairs', 'NumOverheadSpeakerPairs');
            this.LockPropertyAsAlias('MedusaConfig.NumVlsHeadrestSpeakerPairs', 'NumVlsHeadrestSpeakerPairs');

            % Holigram Properties
            this.MedusaConfig.MaximumHoligramFirLength = this.MaximumHoligramFirLength;
            this.MedusaConfig.AverageHoligramFirLength = this.AverageHoligramFirLength;
            this.MedusaConfig.MaximumDeciRateHoligramEqStagesPerLink = this.MaximumDeciRateHoligramEqStagesPerLink;
            this.MedusaConfig.MaximumFullRateHoligramEqStagesPerSpeaker = this.MaximumFullRateHoligramEqStagesPerSpeaker;
            this.MedusaConfig.NumHoligramEqPerSpeaker = this.NumHoligramEqPerSpeaker;
        end
    end
end

