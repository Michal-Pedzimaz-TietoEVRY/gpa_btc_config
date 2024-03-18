classdef MusicLimiterConfig < BtcBaseClass
    % MusicLimiterConfig Build-time configuration class for the MusicLimiter block
    % Usage:
    %   aConfig = MusicLimiterConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        FrameSize = 32
        FsFast = 44100
        Attack single = 10000
        Decay single = 100
        MaxGainDb single = 0
        MinGainDb single = -80

        TuneDefaults MusicLimiterTuneConfig
    end

    properties (Dependent,GetObservable,SetObservable)
        MaxGain     % = 1, This is Linear MaxGain
        MinGain     % = 0.0001, This is Linear MinGain
    end

    methods
        %----------------------------------------------------------------------
        function this = MusicLimiterConfig()
            % MusicLimiterConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.TuneDefaults =  MusicLimiterTuneConfig;
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
        %----------------------------------------------------------------------
        function value = get.MinGain(obj)
            value = undb20(obj.MinGainDb);
        end

        function set.MinGain(obj,MinGain)
            if MinGain < 0
                MinGain = RgainBusUtil.GetSilentGainLinear();
            end
            obj.MinGainDb = db20(MinGain);
        end

        function value = get.MaxGain(obj)
            value = undb20(obj.MaxGainDb);
        end

        function set.MaxGain(obj,MaxGain)
            if MaxGain > 0
                MaxGain = RgainBusUtil.GetSilentGainLinear();
            end
            obj.MaxGainDb = db20(MaxGain);
        end
    end
end
