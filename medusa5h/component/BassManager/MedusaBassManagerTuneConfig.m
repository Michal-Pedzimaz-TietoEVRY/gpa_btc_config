classdef MedusaBassManagerTuneConfig < TuneConfigClass
% MedusaBassManagerTuneConfig Default TuneVar values for MedusaBassManager block
% Note that this class does *NOT* have the ablity to Validate, but it can
% lock and default property values. Do not create a Validate method here!
%.This is because TuneVar values must be validated by their translations
%.instead of by build-time logic. During tunings or data builds, only the
%.translation code (in a DLL) is available to ensure the TuneVars are good.
%.TuneVars are inherently variable size, but their maximum dimensions are
%.set by either their build-time default value, or explicitly set in the
%.TuneVar block (TuneTOPs only support automatic size from default value).
% This class simply holds startup values for TuneVars that are used during 
% simulation or translated into TOPs and built into the generated code.
%.To calculate default values using multiple properties, use anonymous
%.functions in a call to Default in this constructor.
%.e.g. the provided default value will start with @().
%.Usage:
%. The BTConfig.AddAllTuneVars method automates the addition of properties 
%.for this class by parsing the Simulink canvas content.

%   Copyright 2023 Bose Corporation
  properties (Description='TuneDefault',GetObservable,SetObservable)
    LeftMixWeights
    RightMixWeights
    GainLfe2C = single(1)
  end

  methods
    function EasyConstructor(this)
        % Called from MedusaBassManagerTuneConfig Constructor.
        % Lock and Default properties here, using Parent if desired...
        %.Parent property available for use, but only calculated @() values
        %.are recommended because the parent object might not be fully
        %.constructed yet.
        this.Default(@this.LeftMixWeights, @() this.GetDefaultMixWeights());
        this.Default(@this.RightMixWeights, @() this.GetDefaultMixWeights());
    end

    function mixWeights = GetDefaultMixWeights(this)
        if(this.Parent.NumInputs == 2)
            % Stereo input case
            mixWeights = 1;
        else
            % Discrete input (5.1/5.1.4) case
            numMixWeights = single((2 + this.Parent.NumInputs) / 2);
            mixWeights = repmat( (1 / numMixWeights), 1, numMixWeights );
        end
    end
  end
end
