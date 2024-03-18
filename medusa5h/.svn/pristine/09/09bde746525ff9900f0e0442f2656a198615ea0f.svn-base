classdef MedusaSpeakerDelayTranslationConfig < MedusaDelayConfig
    % MedusaSpeakerDelayTranslationConfig Build-time configuration class for the MedusaSpeakerDelayTranslation block
    % Usage:
    %    aConfig = MedusaSpeakerDelayTranslationConfig
    %

    %   Copyright 2022 Bose Corporation

    properties
        DefaultTuning MedusaDelayTuneConfig
    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaSpeakerDelayTranslationConfig()
            % MedusaSpeakerDelayTranslationConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.DefaultTuning = MedusaDelayTuneConfig(this);
            this.Default(@this.DefaultTuning.SpeakerDelay,  @()zeros(1, this.NumFullRateChannels, 'int32'));
        end

        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@MedusaDelayConfig(this);
        end

    end
end
