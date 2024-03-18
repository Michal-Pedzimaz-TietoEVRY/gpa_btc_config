function [DRFDPConfig, FRFDPConfig] = MedusaFDPInit(MedusaParams)
% Init script for MedusaFDP and MedusaFullRateFDP blocks
%
% Input arguments: 
% Config struct with the following fields:
%   MedusaParams.sampleRate     : Sample rate (at full rate, in Hz)
%   MedusaParams.fftSize        : FFT block size
%   MedusaParams.include_cae    : Include Compressed Audio Enhancement (CAE)   
%   MedusaParams.frameSize      : Frame size 
%   MedusaParams.useGenericCode : Switch for Optimized/Generic implementation
%
% Returns:
% Base workspace variables that can be passed to or used in Simulink block 
%   MedusaFDPConfig        : config struct to interface with MedusaFDP
%   MedusaFullRateFDPConfig: config struct to interface with MedusaFullRateFDP
%   include_CAE            : Simulink parameter to control CAE variant systems  
%   decayEstTunable        : Bus object for SPUM estimate decay in MedusaFullRateFDP
%   decaySlewTunable       : Bus object for SPUM slew decay in MedusaFullRateFDP

    %% Common for decimated and full-rate
    sampleRate = MedusaParams.sampleRate;
    fftSize = MedusaParams.fftSize; % fft size L
    overlapFactor = 0.5;
    win = single(sqrt(hanning(fftSize, 'periodic'))); % Hanning window
    overlap = fftSize * overlapFactor; 
    hopsize = fftSize - overlap;
    frameSizeInFrequency = fftSize/2+1;
    include_CAE = Simulink.Parameter(MedusaParams.include_cae);
    useGenericCode = MedusaParams.useGenericCode;
    dspTarget = MedusaParams.DspTarget;

    % Shared SPUM constants
    
    % When energy difference between successive frames exceeds this
    % threshold, we consider the event as impulse detection.
    % Threshold is defined for fullrate.
    % Old values were 6/8 for fullrate, 6 for decimated rate
    detectImpulseThresholdFullRate = 6/4; 
    
    % Maximum ineration (steps) up to which we hold the current state
    % of impulse detection when energy difference does not exceed the
    % threshold. This is the value for full rate. Value for decimated
    % rate is derived from this.
    detectImpulseCounterLimitFullRate = 16;

    % Maximum decimated frames that separates dry and reverb parts. In 
    % Medusa 5 this value was hardcoded to N=2 (~20ms). The upperbound now
    % is 8 decimated frames or ~90 ms.
    maxDirectPathFramesFullRate = MedusaParams.maximumSPUMFrameDelay*4;
    
    %% Decimated rate configurations
    decimationFactor = 4; % decimation factor
    frameSize = MedusaParams.frameSize/decimationFactor;
    frameRate = sampleRate/decimationFactor/hopsize; % frame rate
    
    % Fixed smoothing filter frequencies in Hz 
    lpf1Hz = 0.03/2 * frameRate; % 1.292 at 44100/512
    lpf2Hz = 0.3/2 * frameRate;  % 12.92 at 44100/512
    
    % Smoothing coefficients
    [lsPole1, lsGain1] = cutoffToCoeff(lpf1Hz, frameRate);
    [lsPole2, lsGain2] = cutoffToCoeff(lpf2Hz, frameRate);
    
    % SPUM constants for impulse detection
    detectImpulseThreshold = detectImpulseThresholdFullRate * decimationFactor;
    maxValueOfCounterForDetectingImpulse = detectImpulseCounterLimitFullRate/decimationFactor;
    maxDirectPathSamples = (maxDirectPathFramesFullRate / decimationFactor + 1) * frameSizeInFrequency;

    %@SSC-TODO
    fftVariant = dspTarget;
    DRFrfftConfig1 = RfftConfig();
    DRFrfftConfig1.FftSize = fftSize;
    DRFrfftConfig1.Alias = 'DRFrfft1';
    DRFrfftConfig1.SelectVariant(fftVariant);
    DRFrfftConfig2 = RfftConfig();
    DRFrfftConfig2.FftSize = fftSize;
    DRFrfftConfig2.Alias = 'DRFrfft2';
    DRFrfftConfig2.SelectVariant(fftVariant);

    DRFrifftConfig = RifftWolaConfig();
    DRFrifftConfig.FftSize = fftSize;
    DRFrifftConfig.NumOverlap = overlap;
    DRFrifftConfig.Alias = 'DRFrifft';
    DRFrifftConfig.SelectVariant(fftVariant);
    
    DRFDPConfig = struct('frameRate', frameRate,...
                         'frameSize', frameSize,...
                         'fftSize', fftSize,...
                         'win', win,...
                         'overlap', overlap,...
                         'include_CAE', include_CAE,...
                         'lsPole1', lsPole1, ...
                         'lsGain1', lsGain1, ...
                         'lsPole2', lsPole2, ...
                         'lsGain2', lsGain2, ...
                         'detectImpulseThreshold', detectImpulseThreshold,...
                         'maxValueOfCounterForDetectingImpulse', maxValueOfCounterForDetectingImpulse,...
                         'maxDirectPathSamples', maxDirectPathSamples,...
                         'useGenericCode', useGenericCode,...
                         'rfftConfig1', DRFrfftConfig1,...
                         'rfftConfig2', DRFrfftConfig2,...
                         'DRFrifftConfig', DRFrifftConfig);        

    %% Full rate configurations

    decimationFactor = 1; % decimation factor
    frameSize = MedusaParams.frameSize/decimationFactor;
    frameRate = sampleRate/decimationFactor/hopsize; % frame rate
    
    % Smoothing coefficients
    [lsPole1, lsGain1] = cutoffToCoeff(lpf1Hz, frameRate);
    
    % SPUM constants for impulse detection
    detectImpulseThreshold = detectImpulseThresholdFullRate * decimationFactor;
    maxValueOfCounterForDetectingImpulse = detectImpulseCounterLimitFullRate/decimationFactor;
    maxDirectPathSamples = maxDirectPathFramesFullRate / decimationFactor * frameSizeInFrequency;

    % SPUM constants used only for decay estimation
    
    % High-pass filter 
    % Note: the old constants for decay estimation in frequency domain are
    % commented out. The new decay estimation operates in time domain so a
    % 6th order Butterworth is needed to highpass filter above 6 Khz
    hpfOrder = 6;
    hpfCutoff = 6000;
    numChannels = 2; % L and R treble
    [Z, P, K] = butter(hpfOrder, hpfCutoff / (sampleRate/2), 'high');
    decayConst.sos = zp2sos(Z, P, K);
    decayConst.numStages = size(decayConst.sos, 1) * ones(1, numChannels);
    decayConst.coeffs = repmat(decayConst.sos, numChannels, 1);
    decayConst.maxNumStages = hpfOrder * numChannels;
    decayConst.variant = MedusaParams.variant;
    %decayConst.decayPSDIndexStart = round(6000 / sampleRate * fftSize) + 1; 
    %decayConst.decayPSDIndexStop = fftSize / 2 + 1;
    
    % Decay estimate
    % Note: no need to precalculate sumOfTimeIndices and sumOfSquaresTimeIndices 
    % manually anymore as Simulink Coder will optimize automatically
    decayConst.minGateFrameEnergydB = single(-25);
    decayConst.onsetCounterLimit = 700;
    decayConst.decayDefaultCounterLimit = round(30*frameRate); % 10336 at 44100/128
    decayConst.numPointsForSlopeComputation = 5;
    decayConst.lengthFrameEnergiesBuffer = 8;
    decayConst.decaySlowest = single((-60/2.5)/frameRate); % -6.96598639455782292496e-2) at 44100/128
    decayConst.decayFastest = single((-60/0.5)/frameRate); % -3.48299319727891132370e-1) at 44100/128
    decayConst.alias = 'SPUMDecayIir';

    % Smooth and slew decay
    % As direct_path_sec is now tunable, the decay default is now specified
    % as the decay slope per frame for RT60 = 1s, i.e. decayDefaultSlope = (-60/1.0)/FRAME_RATE_FS 
    % Originally this is the linear decay default over DIRECTPATH_FS = 8 frames, 
    % i.e. decayDefault = undb10(DecayDefaultSlope * DIRECTPATH_FS) = single(7.25571594461775770668e-1)
    decayConst.decayDefaultSlope = single((-60/1.0)/frameRate); % -1.74149659863945566185e-1) at 44100/128

    FRFrfftConfig1 = RfftConfig();
    FRFrfftConfig1.FftSize = fftSize;
    FRFrfftConfig1.Alias = 'FRFrfft1';
    FRFrfftConfig1.SelectVariant(fftVariant);
    FRFrfftConfig2 = RfftConfig();
    FRFrfftConfig2.FftSize = fftSize;
    FRFrfftConfig2.Alias = 'FRFrfft2';
    FRFrfftConfig2.SelectVariant(fftVariant);

    FRFrifftConfig = RifftWolaConfig();
    FRFrifftConfig.FftSize = fftSize;
    FRFrifftConfig.NumOverlap = overlap;
    FRFrifftConfig.Alias = 'FRFrifft';
    FRFrifftConfig.SelectVariant(fftVariant);
    
    FRFDPConfig = struct('frameRate',frameRate,...
                         'frameSize', frameSize,...
                         'fftSize', fftSize,...
                         'win', win,...
                         'overlap', overlap,...
                         'include_CAE', include_CAE,...
                         'lsPole1', lsPole1, ...
                         'lsGain1', lsGain1, ...
                         'detectImpulseThreshold', detectImpulseThreshold,...
                         'maxValueOfCounterForDetectingImpulse', maxValueOfCounterForDetectingImpulse,...
                         'maxDirectPathSamples', maxDirectPathSamples, ...
                         'decayEstimateConst', decayConst,...
                         'useGenericCode', useGenericCode,...
                         'rfftConfig1', FRFrfftConfig1,...
                         'rfftConfig2', FRFrfftConfig2,...
                         'FRFrifftConfig', FRFrifftConfig);
    assignin('base', 'include_CAE', include_CAE); 
    
    % Bus object initialization
    decayEstTunable;
    decaySlewTunable;
end

function [lsPole, lsGain] = cutoffToCoeff(cutoffHz, sampleRateHz)
% Convert cutoff (reciprocal of time constant) to first order iir
% filter coefficient (pole). 

    maxCutoff = (1-eps) * sampleRateHz;
    boundedLPF1 = min(cutoffHz, maxCutoff);
    w1 = 2 * pi * boundedLPF1 / sampleRateHz;
    lsPole = -(sin(w1) - 1) / cos(w1);
    lsGain = (1 - lsPole) / 2;
    
end