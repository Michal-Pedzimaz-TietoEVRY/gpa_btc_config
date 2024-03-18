classdef CrossFaderConfig < BtcBaseClass
    % CrossFaderConfig Build-time configuration class for the CrossFader block
    % Usage:
    %   aConfig = CrossFaderConfig
    %   Copyright 2023 Bose Corporation

    properties
        FadeTime = 0.25
    end
    methods
        %----------------------------------------------------------------------
        function this = CrossFaderConfig()
            % CrossFaderConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
