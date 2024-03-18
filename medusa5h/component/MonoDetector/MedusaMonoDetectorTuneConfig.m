classdef MedusaMonoDetectorTuneConfig < handle
    % MedusaMonoDetectorTuneConfig Default TuneVar values for MedusaMonoDetector block
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

    %   Copyright 2023 Bose Corporation
    properties (Description='TuneDefault')

        LevelCutoff = double(40)
        LSSmoothCutoff = double(0.25)
        LSSmoothResetCutoff = double(40)
        NoiseFloordB = double(-100)
        LRMatchTolerancedB = double(0.5)
        ThresholdMonoInput = double(0.995)
        ThresholdStereoInput = double(0.99)
        HPFCutoff = double(1000)
        Enable = int32(1)
        
    end
end
