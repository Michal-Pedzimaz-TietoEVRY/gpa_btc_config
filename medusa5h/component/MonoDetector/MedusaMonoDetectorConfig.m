classdef MedusaMonoDetectorConfig < BtcBaseClass
    % MedusaMonoDetectorConfig Build-time configuration class for the MedusaMonoDetector block
    % Usage:
    %    aConfig = MedusaMonoDetectorConfig
    %

    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        SampleRate                                  = 44100
        Variant                                     = 'Generic'
        Hpf             PoolIirConfig
        TuneDefaults    MedusaMonoDetectorTuneConfig
    end

    properties(SetAccess = private)
        DownSamplingFactor                          = 32
        NumInputChannels                            = 2

        % If the signal level does not go above predefined threshold for
        % this duration, we reset mono detector states.
        DurationUntilReset                          = 0.5
        MaxZeroLevelCount

        % High pass filter parameters
        HpfOrder                                    = 2
        MaxNumStages

        % Output when mono detector is bypassed
        BypassValue                     uint32      = 1
    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaMonoDetectorConfig()
            % MedusaMonoDetectorConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.Hpf = PoolIirConfig;
            this.Hpf.Alias = 'MedusaMonoDetectorHpf';
            this.TuneDefaults =  MedusaMonoDetectorTuneConfig;

            this.MaxNumStages = ceil(this.HpfOrder/2) * this.NumInputChannels;
            this.LockPropertyAsAlias('Hpf.MaxNumStages', 'MaxNumStages');
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);

            this.Hpf.SelectVariant(this.Variant);

            this.MaxZeroLevelCount = ceil(this.DurationUntilReset * (this.SampleRate/this.DownSamplingFactor));

            % Bus object initialization
            monoDetectorTunable;
        end

    end
end
