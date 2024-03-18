classdef MonoizerConfig < BtcBaseClass
    % MonoizerConfig Build-time configuration class for the Monoizer block
    % Usage:
    %   aConfig = MonoizerConfig
    %   Copyright 2023 Bose Corporation

    properties(Description='TuneDefault',GetObservable,SetObservable)
        G single = 1
        NumChannels int32 = 2
    end
    methods
        %----------------------------------------------------------------------
        function this = MonoizerConfig()
            % MonoizerConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
