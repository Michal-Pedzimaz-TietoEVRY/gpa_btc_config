classdef PoolIirWithResetSharcPlusCoreVariantConfig < BtcVariant
    % PoolIirWithResetSharcPlusCoreVariantConfig Build-time configuration class for the PooliirSharcPlusCore variant
    % Usage:
    %    <automatically allocated by setting the "Variant" property of the
    %    containing object derived from BtcBaseClassWithVariants
    %

    %   Copyright 2023 Bose Corporation

    properties(SetObservable, GetObservable)
        CodeWorkMemorySize              % State memory used for core implementation
    end

    properties(SetAccess = private)
        PostOverlayRequired     = 0
        CodeWorkMemoryInitVal
    end

    methods
        %----------------------------------------------------------------------
        function this = PoolIirWithResetSharcPlusCoreVariantConfig(parentObj)
            %.PoolIirWithResetSharcPlusCoreVariantConfig constructor
            this@BtcVariant(parentObj);
            this.Lock(@this.CodeWorkMemorySize,@()2*this.Parent.MaxNumStages);
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
            this.CodeWorkMemoryInitVal = zeros(1, this.CodeWorkMemorySize);

            % Be friendly about the CRL this variant expects
            this.EnsureCodeReplacementLibrary(blockHandle,'SHARC+');

            VariantDoMaskInit@BtcVariant(this,blockHandle);
        end
        %----------------------------------------------------------------------
    end
end
