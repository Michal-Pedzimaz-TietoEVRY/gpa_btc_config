classdef TrebleBoostStereoConfig < BtcBaseClass
    % TrebleBoostStereoConfig Build-time configuration class for the TrebleBoostStereo block
    % Usage:
    %    aConfig = TrebleBoostStereoConfig
    %

    %   Copyright 2022 Bose Corporation

    properties (GetObservable,SetObservable)
        % Properties use this syntax:
        %    PropertyName size class {validation functions} = DefaultValue
        % About Build-Time Configuration: https://wiki.bose.com/x/dqPoB
        SampleRate = 44100
        FrameSize = 32
        Variant = 'Generic'
        DefaultTuning TrebleBoostTuneConfig
    end

    properties (SetAccess=private)
        FftFrameSize = 256     % Size of FFT frame in samples
        MinDetectionFrequencyHz = 6000
        MaxDetectionFrequencyHz = 18500
        SteepnessIndexRange = 5

        % Defining parameters for Linkwitz-Riley filter
        FilterOrder = 4
        MaxFilterOrder int32 = 4
        MaxNumStages = 4       % One SOS stage for one channel
        NumChannels = 2        % Left and Right have one channel each

        % The following properties are computed based on other properties
        % in this class. See the Validate function for their assignments.
        HannWindow
        Frequencies
        MinDetectionFrequencyIndex
        MaxDetectionFrequencyIndex
        SpectrumSize
    end

    methods
        %----------------------------------------------------------------------
        function this = TrebleBoostStereoConfig()
            % TrebleBoostStereoConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values

            this.DefaultTuning = TrebleBoostTuneConfig();
        end
        %----------------------------------------------------------------------
        function Validate(this)
            this.SpectrumSize = this.FftFrameSize/2 + 1;
            this.HannWindow = hann(this.FftFrameSize, 'periodic');

            % Defining parameters for cut-off frequency calculation
            this.Frequencies = single(((1:this.SpectrumSize)'-1)/(this.SpectrumSize-1)*this.SampleRate/2);
            this.MinDetectionFrequencyIndex = int32(floor((this.MinDetectionFrequencyHz/(this.SampleRate/2)) * (this.FftFrameSize/2))) + 1;
            this.MaxDetectionFrequencyIndex = int32(ceil((this.MaxDetectionFrequencyHz/(this.SampleRate/2)) * (this.FftFrameSize/2))) + 1;

            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);
        end

    end
end
