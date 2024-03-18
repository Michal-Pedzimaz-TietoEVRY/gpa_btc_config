classdef BandLimitConfig < BtcBaseClass
    % BandLimitConfig Build-time configuration class for the BandLimit block
    % Usage:
    %    aConfig = BandLimitConfig
    %   Copyright 2023 Bose Corporation

    properties
        FsFast = 44100
        FrameSize = 32
        ChannelCount = 4

        % HPF pooliir parameters
        maxNumStages = 60
        numStagesPerChannel
        sosCoefficients

        % LPF parameters
        InterpolatedFilter
        DecimationFactor = 4
        BandSeparationDelay = 100
        
        PoolIir PoolIirConfig
    end

    properties(Description='TuneDefault')
        DefaultHpfCutoffFrequency = 90
        DefaultHpfFilterOrder = 5
    end
    methods
        %----------------------------------------------------------------------
        function this = BandLimitConfig()
            % BandsplitConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.PoolIir =  PoolIirConfig;
            this.PoolIir.Alias = 'NearBandLimitLpf';
            this = this.CalcLpfCoefficients();
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            %.If there are no cross-property interactions, then this entire
            %.method can be deleted!

            %.End with a call to our base class to continue validation checks
            %.including any violations of property locking.
            Validate@BtcBaseClass(this);
        end
        %----------------------------------------------------------------------
        function obj = CalcLpfCoefficients(obj)
            % Calculate anti-aliasing filter coefficients (same as Medusa band splitter)
            %% Interpolated Filter
            F = obj.FsFast;
            Fs = (F/2)/obj.DecimationFactor;    % Stop Band Cutoff
            Fp = Fs * .54422;                   % Pass Band Cutoff (.54422 will cause Fp=1500 for DECIMATE = 8, which was the static constant originally)
            down = obj.DecimationFactor/2;      % Interpolation Factor (originally 4)... change to reflect DECIMATE value

            ripple_dB = 100;        % Ripple for stop and pass band in dB
            ripple = 10^(-ripple_dB/20);

            [n,Wn,bta,filtype] = kaiserord([Fp Fs],[1 0],[ripple ripple],F);
            b = fir1(n,Wn,filtype,kaiser(n+1,bta),'noscale');

            basemask = down*[1 zeros(1,(down-1))];
            mask = [];

            for i = 1:ceil(length(b)/down)
                mask = [mask basemask];
            end

            obj.InterpolatedFilter = b .* mask(1:length(b));

        end
    end
end
