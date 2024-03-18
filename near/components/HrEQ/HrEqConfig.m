classdef HrEqConfig < BtcBaseClass
    % HrEqConfig Build-time configuration class for the HrEq block
    % Usage:
    %   aConfig = HrEqConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        MaxAverageStagesPerChannel = 10    % Average SOS stage per channel (from requirements)
        MinNumHeadrestChannels = 1
        MaxNumHeadrestChannels = 2
        MinNumAnnChannels = 1
        MaxNumAnnChannels = 4

        FrameSize
        NumHeadrestSpeakers
        AnnChannelCount

        % external pooliir parameters
        maxNumStages = 100
        numStagesPerChannel = 10
        sosCoefficients = [1, 0, 0, 1, 0, 0]

        driver_src1 single = 0
        driver_src2 single = 0
        driver_src3 single = 0
        driver_src4 single = 0
        passenger_src1 single = 0
        passenger_src2 single = 0
        passenger_src3 single = 0
        passenger_src4 single = 0

        DelayPerChannel DelayPerChannelConfig
        PoolIirTunable PoolIirTunableConfig
    end

    properties (Dependent)
        NumChannels
    end
    methods
        %----------------------------------------------------------------------
        function this = HrEqConfig()
            % HrEqConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.PoolIirTunable =  PoolIirTunableConfig;
            this.PoolIirTunable.Alias = 'NearHrEq';
            this.DelayPerChannel =  DelayPerChannelConfig;
            this.Lock(@this.DelayPerChannel.NumChannels,@()this.NumChannels);
            this.Lock(@this.PoolIirTunable.MaxNumStages,@()this.maxNumStages);
            this.Lock(@this.PoolIirTunable.NumChannels,@()this.NumChannels);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
        %----------------------------------------------------------------------
        function value = get.NumChannels(this)
            value = this.AnnChannelCount*this.NumHeadrestSpeakers;
        end
    end
end
