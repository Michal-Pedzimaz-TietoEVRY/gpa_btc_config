classdef PoolIirTunableWithResetTuneConfig < TuneConfigClass
    % PoolIirTunableWithResetTuneConfig Default TuneVar values for PoolIirWithVariants block
    %   Copyright 2023 Bose Corporation

    properties (Description='TuneDefault', GetObservable, SetObservable)
        NumStages
        SosCoefficients
    end

    methods
        function EasyConstructor(this)
            % Called from PoolIirWithResetTuneConfig Constructor.
            % Lock and Default properties here, using Parent if desired...
            %.Parent property available for use, but only calculated @() values
            %.are recommended because the parent object might not be fully
            %.constructed yet. If there are no property Lock/Default actions
            %.this entire method could be removed. <<Insert code below>>
            this.Default(@this.NumStages,@()this.GetDefaultNumStages);
            this.Default(@this.SosCoefficients,@()this.GetDefaultSosCoeffs);
        end

        function value = GetDefaultNumStages(this)
            numStagesPerChannel = floor(this.Parent.MaxNumStages/this.Parent.NumChannels);
            value = repmat(numStagesPerChannel, 1, this.Parent.NumChannels);
        end

        function value = GetDefaultSosCoeffs(this)
            sos = [1 0 0 1 0 0];
            value = repmat(sos, this.Parent.MaxNumStages, 1);
        end
    end
end
