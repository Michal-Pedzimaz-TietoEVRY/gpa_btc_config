classdef LowFrequencyNoiseEstimatorCohMask
    % LowFrequencyNoiseEstimatorCohMask:
    % Mask logic for the low frequency noise estimator (multiCoherence) block
    
    methods (Static)
        %%%%%%%%%%%%%%%%%%%%
        function TriggerInitCallBack(H)
            % Force the block to run its mask init by changing this dummy 
            % parameter. The callback returns it to the original value.
            MaskUtil.safe_setparam(H,'TriggerInit','0');
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureModel(H,Config)
            % This function configures the model according to the Config
                    
        end
    end
end

