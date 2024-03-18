classdef FirSharcPlusAccelVariantConfig < BtcVariant
% FirSharcPlusAccelVariantConfig Build-time configuration class for the FirSharcPlusAccel variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties
    % PropertyName size class {validation functions} = DefaultValue

  end

  properties (Dependent, SetAccess = private)
    CodeWorkMemorySize
    StateBufferSize
  end

  methods
    %----------------------------------------------------------------------
    function this = FirSharcPlusAccelVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
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
        
        % Be friendly about the CRL this variant expects
        this.EnsureCodeReplacementLibrary(blockHandle,'SHARC+');

        % Assign Unique Identifier to StateBuffer
        this.ConfigureDataStoreMemory(blockHandle, 'StateBuffer');

        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end
    %----------------------------------------------------------------------
    function val = get.CodeWorkMemorySize(this)
        % Accelerator CRL code work memory size is equal to:
        %             sizeof(accelWorkMemory_t) + variableDataSize;
        % with variable data size dependent on number inputs, number outputs
        % and frame size.  NOTE: this must be updated to match the CRL code
        % if any changes are made to the accelWorkMemory_t structure.
        val = 156 + (24 + this.Parent.NumInputs*48 + this.Parent.NumOutputs*(80 + 4*this.Parent.FrameSize));
        val = val / 4;
    end
    %----------------------------------------------------------------------
    function val = get.StateBufferSize(this)
        val = (this.Parent.MaxAvgCoeffLength + this.Parent.FrameSize - 1)*this.Parent.NumInputs;
    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, blkh, DataStoreMemoryName)
        % Get DSM block Path
        theDsm = ['Fir/TargetSpecific/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        Identifier = [char(this.Parent.Alias) char(DataStoreMemoryName)];
        % Configure DSM Storage Class
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'FirGenericStorage', ...
                                'Identifier', Identifier);
    end
    %----------------------------------------------------------------------
  end
end
