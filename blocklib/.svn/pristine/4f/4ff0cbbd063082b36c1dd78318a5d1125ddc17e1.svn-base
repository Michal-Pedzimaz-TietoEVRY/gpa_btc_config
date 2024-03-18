classdef PoolIirWithResetSharcPlusAccelGxpVariantConfig < BtcVariant
% This is a just a placeholder of SharcPlusAccelGxpVariantConfig. This file
% needs to be updated whenever the block is merged to blocklib by Zeus team.

    % PoolIirWithResetSharcPlusAccelGxpVariantConfig Build-time configuration class for the PooliirGulAccel variant
    % Usage:
    %    <automatically allocated by setting the "Variant" property of the
    %    containing object derived from BtcBaseClassWithVariants
    %

    %   Copyright 2023 Bose Corporation

    properties(GetObservable, SetObservable)
        CodeWorkMemorySize              % Size of code work memory required for variant
        WorkloadEstimate                % Estimate of HW workload for the accelerator task
        DspCoreId                       % DSP Core ID
    end

    properties(SetAccess = private)
        PostOverlayRequired     = 1
        CacheLineLen            = 64    % ADI GUL size in bytes
        AccelDeviceId           = 0     % IIR Accel device ID: 0, 1, 2, 3, 4, 5, 6, or 7
        CoreId                  = []
        CodeWorkMemoryInitVal
    end

    methods
        %----------------------------------------------------------------------
        function this = PoolIirWithResetSharcPlusAccelGxpVariantConfig(parentObj)
            %.PoolIirWithResetSharcPlusAccelGxpVariantConfig constructor
            this@BtcVariant(parentObj);
            this.Lock(@this.CodeWorkMemorySize,@()this.GetCodeWorkMemorySize);
            this.Lock(@this.WorkloadEstimate,@()this.GetWorkloadEstimate);
        end
        %----------------------------------------------------------------------
        function VariantValidate(this)
            % VariantValidate validates cross-property interactions. Our parent
            % object calls us during block mask initialization.
            VariantValidate@BtcVariant(this);
        end
        %----------------------------------------------------------------------
        function VariantDoMaskInit(this,blockHandle)
            % VariantDoMaskInit performs automation of code generation settings
            % and other canvas interactions for a variant subsystem. Our parent
            % object calls us during block mask initialization.

            % Create alias for code work memory buffer for each instance of model
            blockDataStore = {'Pooliir/SharcPlusAccelGxp/codeWorkMemory'};
            PooliirAccelMask(blockHandle, blockDataStore);

            this.CodeWorkMemoryInitVal = zeros(1, this.CodeWorkMemorySize);

            % Discover and create accelerator device mapping to DSP core
            [~, this.CoreId] = ProcessUnitMap.AssignBlockToUnit(blockHandle, ...
                'accelDeviceId', 'iir', workloadEstimate);

            % Be friendly about the CRL this variant expects
            containingModel = getfullname(bdroot(blockHandle));
            selectedCRL = get_param(containingModel,'CodeReplacementLibrary');
            expectedCRL = 'SHARC+ code replacement library';
            if (false == contains(selectedCRL, expectedCRL))
                warning('Expected CRL [%s], but instead found [%s]', ...
                    expectedCRL,selectedCRL);
            end

            VariantDoMaskInit@BtcVariant(this,blockHandle);
        end
        %----------------------------------------------------------------------
    end

    methods

        function value = GetCodeWorkMemorySize(this)
            % Accelerator CRL code work memory size is equal to:
            %             sizeof(iirAccelWorkMemory_t) + variableDataSize;
            % with variable data size dependent on number channels and
            % frame size.  NOTE: this must be updated to match the CRL code
            % if any changes are made to the accelWorkMemory_t structure.
            bufferSize = 68 + this.NumChannels * (64 + this.FrameSize * 4);
            variableDataSize = TargetCacheRoundUpSize(bufferSize, ...
                1, ...
                this.CacheLineLen); % bytes
            memSize = 64 + variableDataSize; % bytes
            value = memSize / 4; % words (single)
        end

        function value = GetWorkloadEstimate(this)
            % Estimate of HW accelerator MIPS equivalent usage for this
            % accelerator task

            % SJD: Add calculation.  This could also include a core MIPS
            %      estimate.  Will need sample rate property.
            value = 0;  % HW MIPS equivalent
        end
    end
end
