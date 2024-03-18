classdef PreAmpConfig < BtcBaseClass
    % PreAmpConfig Build-time configuration class for the PreAmp block
    % Usage:
    %   aConfig = PreAmpConfig
    %   Copyright 2023 Bose Corporation

    properties
        FixedAttenuator FixedAttenuatorConfig
        MusicLimiter MusicLimiterConfig
        Monoizer MonoizerConfig
        CrossFader CrossFaderConfig
    end
    methods
        %----------------------------------------------------------------------
        function this = PreAmpConfig()
            % PreAmpConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.CrossFader =  CrossFaderConfig;
            this.Monoizer =  MonoizerConfig;
            this.MusicLimiter =  MusicLimiterConfig;
            this.FixedAttenuator =  FixedAttenuatorConfig;
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
