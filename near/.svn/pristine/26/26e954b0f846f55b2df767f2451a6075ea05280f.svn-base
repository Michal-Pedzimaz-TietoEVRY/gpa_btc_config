classdef FsEqConfig < BtcBaseClass
    % FsEqConfig Build-time configuration class for the FsEq block
    % Usage:
    %   aConfig = FsEqConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        MaxAverageStagesPerChannel = 10
        MinNumChannels = 2
        MaxNumChannels = 7

        % external pooliir parameters
        maxNumStages = 100
        numStagesPerChannel = 10
        sosCoefficients = [1, 0, 0, 1, 0, 0]

        FrameSize
        FrontPeripheralChannelCount

        f1_del single = 0
        f2_del single = 0
        f3_del single = 0
        f4_del single = 0
        f5_del single = 0
        f6_del single = 0
        f7_del single = 0
        
        DelayPerChannel DelayPerChannelConfig
        Pooliir PoolIirTunableConfig
    end
    
    properties(Dependent)
        NumChannels
    end
    methods
        %----------------------------------------------------------------------
        function this = FsEqConfig()
            % FsEqConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.Pooliir =  PoolIirTunableConfig;
            this.Pooliir.Alias = 'NearFsEq';
            this.DelayPerChannel =  DelayPerChannelConfig;
            this.Lock(@this.DelayPerChannel.NumChannels, @()this.NumChannels);
            this.Lock(@this.Pooliir.MaxNumStages, @()this.maxNumStages);
            this.Lock(@this.Pooliir.NumChannels, @()this.FrontPeripheralChannelCount);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
        %----------------------------------------------------------------------
        function value = get.NumChannels(this)
            value = this.FrontPeripheralChannelCount;
        end
    end
end
