classdef TrebleBoostTuneConfig < handle
% TrebleBoostTuneConfig Default TuneVar values for TrebleBoostStereo block
% Note that this class does *NOT* have the ablity to Validate or lock 
% property values. TuneVars must be validated by translations instead of by
% build-time logic as new tuning data arrives after build-time has already
% completed. The Talaria Translation Engine validates tunings via TuneVar
% translation code during the build of a datastore or use of a tuning tool.
% This class simply holds startup values for TuneVars that are used during 
% simulation or translated into TOPs and built into the generated code.
% Usage:
%  The BTConfig.AddAllTuneVars method automates the addition of properties 
% for this class by parsing the Simulink canvas content. Once the 
% properties are present, set their default values below.

    properties
        EnableFlag = 1
        LossyPeakTau = 0.3
        MinSteepnessThresholddB = 20
        MaxSteepnessThresholddB = 50
        MinSteepnessValue = 0.1
        HighFrequency = 17000
        EnergyConfidenceInflectionPoint = 0.00001
        HighFrequencyMinEnergyThresholddB = -70
        HighFrequencyMaxEnergyThresholddB = -60
        FullBandFrequencyHz = 20000
        CutoffFrequencyTau = 0.02    % DEBUG: Changed from 5, 0.1 (11k), 0.1 (15k), 0.02 (input_CAE)
        ConfidenceTau = 0.5          % DEBUG: Changed from 15, 0.5 (Scenario 6 & 7)
        ConfidenceThreshold = 0.7
        HysteresisBand = 0.4         % DEBU: Changed from 0.2 (Scenario 7)
        Freq1InHz = 9000
        Freq2InHz = 13000
        Freq3InHz = 17000
        Gain1IndB = 5
        Gain2IndB = 3
        RamperTau = 0.05             % DEBUG: Changed from 2, 0.05 (11k), 0.03 (15k), 0.05 (input_CAE)
        CrossOverFrequency = 10000
    end
end

