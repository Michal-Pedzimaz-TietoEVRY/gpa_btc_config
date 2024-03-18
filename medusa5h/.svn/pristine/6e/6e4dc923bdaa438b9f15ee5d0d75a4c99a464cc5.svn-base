classdef MedusaDelayConfig < BtcBaseClass
    % MedusaDelayConfig Build-time configuration class for the MedusaAlignmentDelay block
    % Usage:
    %    aConfig = MedusaDelayConfig
    %

    %   Copyright 2022 Bose Corporation

    properties (GetObservable,SetObservable)
        % Basic parameters
        FullRateFrameSize                           = 32
        DecimationFactor                            = 4

        % Max delay values
        DeciRateMaxWiggleDelay          int32       = 166
        DeciRateMaxNearWiggleDelay      int32       = 166
        MaxHoligramDelay                int32       = 1764
        MaxFullRateHoligramDelay        int32   {mustBeNonnegative} = 45
        MaxSpeakerDelay                 int32   {mustBeNonnegative} = 1323

        % System Channel Configuration
        NumCenterChannels                       {mustBePositive}    = 2
        NumSurroundChannels                     {mustBeNonnegative} = 1
        NumLeftRightSpeakerPairs                {mustBePositive}    = 6
        NumOverheadSpeakerPairs                 {mustBeNonnegative} = 0
        NumVlsHeadrestSpeakerPairs              {mustBeNonnegative} = 0
    end

    properties (Dependent = true)
        DeciRateFrameSize
        DeciRateFdpDelay                                                    % Full Rate + Decimated Rate FDP Latency

        % Max delay values
        DeciRateMaxBassDelay            int32
        FullRateMaxBassDelay            int32
        MaxMidRangeDelay                int32
        MaxTrebleDelay                  int32
        MaxMidrangeSurroundDelay        int32
        MaxTrebleSurroundDelay          int32
        MaxFullRateSpeakerDelay         int32

        % Num of channels
        NumPeripheralChannels
        NumNonHeadrestChannels
        NumDeciRateChannels
        NumFullRateChannels

    end

    properties (SetAccess = private)
        % Delays inherent to medusa design
        BandSplitDelay                              = 134                   % Latency introduced by Band Split
        FullRateFdpDelay                            = 384                   % Latency introduced by Upmixer

        % Max delay values
        FullRateMaxWiggleDelay          int32       = 664
        FullRateMaxNearWiggleDelay      int32       = 664

        % Number of channels
        NumHeadrestComps                              = 6                   % Design-time parameter

    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaDelayConfig()
            % MedusaDelayConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values

        end

        function value = get.DeciRateFrameSize(this)
            value = this.FullRateFrameSize/this.DecimationFactor;
        end

        function value = get.DeciRateFdpDelay(this)
            value = this.FullRateFdpDelay*this.DecimationFactor;
        end

        function value = get.DeciRateMaxBassDelay(this)
            BassDelay = this.DeciRateFdpDelay + this.BandSplitDelay/2 + this.FullRateMaxWiggleDelay + this.FullRateMaxNearWiggleDelay;
            value = floor(BassDelay/this.DecimationFactor);
        end

        function value = get.FullRateMaxBassDelay(this)
            value = this.DecimationFactor - 1;
        end

        function value = get.MaxMidRangeDelay(this)
            value = this.DeciRateMaxWiggleDelay;
        end

        function value = get.MaxTrebleDelay(this)
            value = this.DeciRateFdpDelay - this.FullRateFdpDelay + this.FullRateMaxWiggleDelay + this.FullRateMaxNearWiggleDelay + this.MaxHoligramDelay;
        end

        function value = get.MaxMidrangeSurroundDelay(this)
            value = floor(this.DeciRateFdpDelay/this.DecimationFactor) + this.DeciRateMaxWiggleDelay + this.DeciRateMaxNearWiggleDelay;
        end

        function value = get.MaxTrebleSurroundDelay(this)
            value = this.DeciRateFdpDelay + this.FullRateMaxWiggleDelay + this.FullRateMaxNearWiggleDelay + this.MaxHoligramDelay;
        end

        function value = get.MaxFullRateSpeakerDelay(this)
            value = ceil(this.MaxSpeakerDelay/this.DecimationFactor)*this.DecimationFactor;
        end

        function value = get.NumPeripheralChannels(this)
            value = this.NumCenterChannels + this.NumSurroundChannels + 2*this.NumLeftRightSpeakerPairs;
        end

        function value = get.NumNonHeadrestChannels(this)
            value = this.NumPeripheralChannels + 2*this.NumOverheadSpeakerPairs;
        end

        function value = get.NumDeciRateChannels(this)
            value = this.NumNonHeadrestChannels + this.NumHeadrestComps*this.NumVlsHeadrestSpeakerPairs;
        end

        function value = get.NumFullRateChannels(this)
            value = this.NumNonHeadrestChannels + 2*this.NumVlsHeadrestSpeakerPairs;
        end

        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            % Latency introduced by Wiggle Filter and NEAR Wiggle Filter for a full-rate path
            this.FullRateMaxWiggleDelay = this.DeciRateMaxWiggleDelay*this.DecimationFactor;
            this.FullRateMaxNearWiggleDelay = this.DeciRateMaxNearWiggleDelay*this.DecimationFactor;

            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);
        end

        %----------------------------------------------------------------------
        function DoMaskInit(this,blockHandle)
            % DoMaskInit called from mask initialization to perform automation
            % of code generation settings and other canvas interactions.

            %.Call base class in case it has any work to perform:
            DoMaskInit@BtcBaseClass(this,blockHandle);
        end
    end
end
