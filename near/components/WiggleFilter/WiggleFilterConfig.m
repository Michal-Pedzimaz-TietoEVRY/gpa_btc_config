classdef WiggleFilterConfig < BtcBaseClass
    %  WiggleFilterConfig Build-time configuration class for the WiggleFilter block
    %  Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        % Build Time Parameters
        ChannelCount
        FilterLength = 1024
        FrameSize = 32

        % Child blocks
        CrossFader CrossFaderConfig
        FirEven FirEvenConfig
    end
    properties(Description='TuneDefault',GetObservable,SetObservable)
        DefaultNearWiggleCoeffs
        DefaultNearDelay
    end
    methods
        %----------------------------------------------------------------------
        function this = WiggleFilterConfig()
            % WiggleFilterConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.FirEven = FirEvenConfig;
            this.FirEven.Alias = 'NearWiggle';
            this.FirEven.MaxAvgCoeffLength = this.FilterLength; 
            this.FirEven.NumOutputs = this.ChannelCount;
            this.FirEven.FrameSize = this.FrameSize;


            this.CrossFader =  CrossFaderConfig;

            %FIR_pass_thru = zeros(this.FilterLength, this.ChannelCount); 
            %FIR_pass_thru(1) = 1.0;
            this.Default(@this.DefaultNearWiggleCoeffs,@()[1.*ones(1, this.ChannelCount); zeros(this.FilterLength-1, this.ChannelCount)]);
            %this.Default(@this.DefaultNearWiggleCoeffs,@()FIR_pass_thru);
            this.Default(@this.DefaultNearDelay,@()size(this.DefaultNearWiggleCoeffs, 1));
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
