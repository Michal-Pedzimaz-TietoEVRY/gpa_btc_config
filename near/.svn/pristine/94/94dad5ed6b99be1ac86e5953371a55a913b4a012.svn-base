classdef NearBandSplitConfig < BtcBaseClass
    % NearBandSplitConfig Build-time configuration class for the NearBandSplit block
    % Usage:
    %    aConfig = NearBandSplitConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        maxNumStages = 60
        FsFast = 44100
        FrameSize = 32
        ChannelCount = 4

        PoolIir PoolIirConfig
        BandSplit BandSplitConfig

    end
    properties(Description='TuneDefault',GetObservable,SetObservable)
        DefaultHpfCutoffFrequency double = 90
        DefaultHpfFilterOrder double = 5
    end
    methods
        %----------------------------------------------------------------------
        function this = NearBandSplitConfig()
            % NearBandSplitConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.PoolIir =  PoolIirConfig;
            this.PoolIir.Alias = 'NearBandSplitIir';
            this.BandSplit =  BandSplitConfig;
            this.BandSplit.FirEven.Alias = 'NearBandSplitFir';
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
