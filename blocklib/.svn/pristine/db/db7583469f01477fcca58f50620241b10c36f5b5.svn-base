classdef PoolIirWithResetArmNeonV7V8VariantConfig < BtcVariant
% PoolIirWithResetArmNeonV7V8VariantConfig Build-time configuration class for the PoolIirArmNeonV7V8 variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties(GetObservable, SetObservable, SetAccess = private)
      PostOverlayRequired     = 1
  end
  properties(GetObservable, SetObservable)
      DsmStatesInitVal  (:,1)
  end
  properties(GetObservable, SetObservable, Hidden)
      % Ignore this property. Only exists to allow ARM and Hexagon variant
      % to share the same canvas space.
      MaxNumOfThreads = 0
  end
  methods
    %----------------------------------------------------------------------
    function this = PoolIirWithResetArmNeonV7V8VariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        this.Lock(@this.DsmStatesInitVal, ...
            @() zeros(2*constructingParentObj.MaxNumStages*constructingParentObj.NumChannels + 16, 1));
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
        this.EnsureCodeReplacementLibrary(blockHandle,'ARM');
        
        this.ConfigureDataStoreMemory('states', blockHandle);

        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, DataStoreMemoryName, blkh)
        % Get DSM block Path
        theDsm = ['PoolIir/TargetSpecific/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        Identifier = [char(this.Parent.Alias) num2str(randi([0 2^16])) char(DataStoreMemoryName)];

        % Configure DSM Storage Class
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'PooliirAccelStorage', ...
                                'MemorySection','AttributeAligned8',...
                                'Identifier', Identifier);
    end
    %----------------------------------------------------------------------

  end
end
