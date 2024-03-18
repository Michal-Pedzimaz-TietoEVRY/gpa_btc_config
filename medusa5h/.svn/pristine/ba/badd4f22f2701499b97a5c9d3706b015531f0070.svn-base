classdef HeadrestOutputDelayTranslationConfig < MedusaDelayConfig
    % HeadrestOutputDelayTranslationConfig Build-time configuration class for the HeadrestOutputDelayTranslation block
    % Usage:
    %    aConfig = HeadrestOutputDelayTranslationConfig
    %

    %   Copyright 2022 Bose Corporation

    properties
        DefaultTuning MedusaDelayTuneConfig
    end

    methods
        %----------------------------------------------------------------------
        function this = HeadrestOutputDelayTranslationConfig()
            % HeadrestOutputDelayTranslationConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.DefaultTuning = MedusaDelayTuneConfig(this);
            this.Default(@this.DefaultTuning.DeciRateNonHeadrestDelay,  @()zeros(1, this.NumNonHeadrestChannels));
            this.Default(@this.DefaultTuning.FullRateHoligramDelay,  @()zeros(1, this.NumFullRateChannels, 'int32'));
        end

        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@MedusaDelayConfig(this);
        end

    end
end
