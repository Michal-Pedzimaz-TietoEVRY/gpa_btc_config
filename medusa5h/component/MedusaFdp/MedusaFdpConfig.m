classdef MedusaFdpConfig < BtcBaseClassWithVariants
% MedusaFdpConfig -------------------------------------------------------
% This is the Medusa Frequency Domain Processing block that operates at a
% decimated rate. The block takes in a bandpassed audio signal in the time
% domain and converts it into the frequency domain using a Short Time
% Fourier Transform. In the frequency domain, upmixing is done using
% magnitude selectivity, phase selectivity, and spatial un-masking (SPUM)
% to generate a set of Medusa Components. Compressed Audio Expansion (CAE) 
% can be turned on to 'stretch' the Medusa Components. Additionally, 
% smoothing is applied between frames in order to minimize artifacts.
% After the Frequency Domain Processing, the components are then converted
% back into the time domain using a Inverse Short-Time Fourier Transform.
% 
% Inputs:
%   -AudioIn [FrameSize x 2] Left and Right Channels of a bandpassed audio
%       signal.
%   -CaeEnable [Integer] 1 or 0, indicating whether CAE is turned on.
%   -DecayRate [single] A constant used in SPUM.
% Outputs:
%   -AudioOut [FrameSize x 8] AudioIn signal is upmixed into 8 outputs,
%       [L, R] -- upmixed --> [Lo, Ro, Ls, Rs, Limp, Ltail, Rimp, Rtail]
%--------------------------------------------------------------------------
%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)

    % System Level Properties
    SampleRate                          = 44100 
    IncludeCae {mustBeMember(IncludeCae,[0,1])} = 1 % 1 for on, 0 for off                   
    FrameSize {mustBeInteger}           = 8           
    DecimationFactor {mustBeInteger}    = 4

    % Rfft and Windowing
    Rfft    RfftConfig
    Rifft   RifftWolaConfig
    Window  single 
    Overlap {mustBeInteger} = 128
    FftSize {mustBeInteger} = 256

    % Spum: Detect Impulse Threshold
    % When energy difference between successive frames exceeds this
    % threshold, we consider the event as impulse detection.
    % Threshold is defined for fullrate.
    % Old values were 6/8 for fullrate, 6 for decimated rate.
    DetectImpulseThreshold 

    % Spum: Max Value of Counter For Detecting Impulse
    % Maximum ineration (steps) up to which we hold the current state
    % of impulse detection when energy difference does not exceed the
    % threshold. For FullRate, use 16. For DeciRate use 4.
    MaxValueOfCounterForDetectingImpulse

    % Spum: Max Spum Frame Delay
    % Maximum decimated frames that separates dry and reverb parts. In 
    % Medusa 5 this value was hardcoded to N=2 (~20ms). The upperbound now
    % is 8 decimated frames or ~90 ms.
    MaxSpumFrameDelay = 4

    TuneDefaults MedusaFdpTuneConfig
    MaxDirectPathSamples 

  end
  properties (GetObservable, SetObservable, Dependent)
    FrameSizeInFrequency 
    FrameRate          
  end
  properties (GetObservable, SetObservable, SetAccess = private)
    % Smoothing Filter Properties For Medusa Components
    LsPole1 
    LsPole2 
    LsGain1 
    LsGain2 
  end
  methods
    %----------------------------------------------------------------------
    function this = MedusaFdpConfig()
        % MedusaFdpConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        
        % Tune Defaults
        this@BtcBaseClassWithVariants('MedusaFdpVariantEnum');
        this.TuneDefaults =  MedusaFdpTuneConfig(this);

        % Rfft
        this.Rfft = RfftConfig();
        this.Lock(@this.Rfft.FftSize, @() this.FftSize);
        this.Default(@this.Rfft.Alias, @() ['MedusaFdp' char(this.Variant) 'Rfft']);
        this.Rifft = RifftWolaConfig();
        this.Lock(@this.Rifft.FftSize, @() this.FftSize);
        this.Lock(@this.Rifft.NumOverlap, @() this.Overlap);
        this.Default(@this.Rifft.Alias, @() ['MedusaFdp' char(this.Variant) 'Rifft']);

        % Rfft Window
        this.Default(@this.Window, @() sqrt(hanning(this.FftSize,'periodic')));

        % Smoothing Filters
        this.SetDefaultSmoothingFilters();
        
        % Set Defaults For Variant
        this.VariantObj.SetDefaults();
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClassWithVariants(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.

        this.UpdateFeaturePath(blockHandle);

        DoMaskInit@BtcBaseClassWithVariants(this,blockHandle);

    end
    %----------------------------------------------------------------------
    function SetDefaultSmoothingFilters(this)
        % Fixed smoothing filter frequencies in Hz 
        lpf1Hz = 0.03/2 * this.FrameRate; % 1.292 at 44100/512
        lpf2Hz = 0.3/2 * this.FrameRate;  % 12.92 at 44100/512

        % Smoothing coefficients
        [lsPole1, lsGain1] = this.CutoffToCoeff(lpf1Hz, this.FrameRate);
        [lsPole2, lsGain2] = this.CutoffToCoeff(lpf2Hz, this.FrameRate);
        this.LsPole1 = lsPole1;
        this.LsPole2 = lsPole2;
        this.LsGain1 = lsGain1;
        this.LsGain2 = lsGain2;
    end
    %----------------------------------------------------------------------
    function [LsPole, LsGain] = CutoffToCoeff(this, CutoffHz, SampleRateHz)
    % Convert cutoff (reciprocal of time constant) to first order iir
    % filter coefficient (pole). 
        maxCutoff = (1-eps) * SampleRateHz;
        boundedLPF1 = min(CutoffHz, maxCutoff);
        w1 = 2 * pi * boundedLPF1 / SampleRateHz;
        LsPole = -(sin(w1) - 1) / cos(w1);
        LsGain = (1 - LsPole) / 2;
    end
    %----------------------------------------------------------------------
    function UpdateFeaturePath(this, blockHandle)
        % FeaturePath set to DeciRate or FullRate
        BlockName = 'FeaturePath';
        BlockPath = MaskUtil.SubBlockName(blockHandle,BlockName);
        FeaturePathBlockHandle = getSimulinkBlockHandle(BlockPath);
        MaskObj = Simulink.Mask.get(FeaturePathBlockHandle);
        MaskObj.Parameters(1).Value = string(this.Variant);
    end
    % Get Methods for Dependent Properties --------------------------------
    function val = get.FrameSizeInFrequency(this)
        val = this.FftSize/2 + 1;
    end
    function val = get.FrameRate(this)
        val = this.SampleRate/this.DecimationFactor/(this.FftSize - this.Overlap);
    end
    %----------------------------------------------------------------------
  end
end
