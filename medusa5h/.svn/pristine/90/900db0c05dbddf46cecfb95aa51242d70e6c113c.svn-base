classdef MedusaAlignmentDelayTranslationConfig < MedusaDelayConfig
    % MedusaAlignmentDelayTranslationConfig Build-time configuration class for the MedusaAlignmentDelayTranslation block
    % Usage:
    %    aConfig = MedusaAlignmentDelayTranslationConfig
    %

    %   Copyright 2022 Bose Corporation

    properties
        DefaultTuning MedusaDelayTuneConfig
    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaAlignmentDelayTranslationConfig()
            % MedusaAlignmentDelayTranslationConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.DefaultTuning = MedusaDelayTuneConfig(this);
        end

        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@MedusaDelayConfig(this);
        end

    end
end
