classdef PoolIirWithResetConfig < BtcBaseClassWithVariants
    % Blocklib PoolIir-----------------------------------------------------
    %   Inputs:
    %       AudioIn         [FrameSize x NumChannels] Input Signal
    %       NumStages       [NumChannels x 1] Number of Sos Stages per channel
    %       CoeffsTarget    [CoeffLength(Target) x 1] Total set of 
    %                           coefficients translated to target specific 
    %                           format from RawSos    
    %----------------------------------------------------------------------
    %   Copyright 2023 Bose Corporation

    properties(GetObservable, SetObservable)
        FrameSize       = 32
        MaxNumStages    = 80
        NumChannels     = 4
        Alias           = 'Default'
    end
    methods
        %----------------------------------------------------------------------
        function this = PoolIirWithResetConfig()
            % PoolIirWithResetConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this@BtcBaseClassWithVariants('PoolIirWithResetVariantEnum');
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            %.End with a call to our base class to continue validation checks
            %.including any violations of property locking.
            Validate@BtcBaseClassWithVariants(this);
        end
        %----------------------------------------------------------------------
        function DoMaskInit(this,blockHandle)
            % DoMaskInit called from mask initialization to perform automation
            % of code generation settings and other canvas interactions.

            %.Call base class in case it has any work to perform:
            DoMaskInit@BtcBaseClassWithVariants(this,blockHandle);
        end

    end
end
