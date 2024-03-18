classdef MedusaMidrangeSurroundAlignmentDelayTranslationConfig < MedusaDelayConfig
    % MedusaMidrangeSurroundAlignmentDelayTranslationConfig Build-time configuration class for the MedusaMidrangeSurroundAlignmentDelayTranslation block
    % Usage:
    %    aConfig = MedusaMidrangeSurroundAlignmentDelayTranslationConfig
    %

    %   Copyright 2022 Bose Corporation

    properties
        DefaultTuning MedusaDelayTuneConfig
    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaMidrangeSurroundAlignmentDelayTranslationConfig()
            % MedusaMidrangeSurroundAlignmentDelayTranslationConfig constructor: assign component property objects
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