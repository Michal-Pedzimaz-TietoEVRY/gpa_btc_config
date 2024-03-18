classdef FirUpGenericVariantConfig < BtcVariant
% FirUpGenericVariantConfig Build-time configuration class for the
% FirUpGeneric variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%
% CoeffsTarget should be ordered by polyphase sub-filter. For an
% interpolation factor of L, there will be L number of polyphase sub-filters
% where the nth value of the kth is given by 
% SubFilter[k, n] = Filter[n*L + k]
% 
% The Target Coefficients should be in the following format
% CoeffsTarget = [SubFilter[0, :]; SubFilter[1,:]; ... SubFilter[L-1,:]]
% SubFilter[k,:] = [SubFilter[k,0]; SubFilter[k,1]; SubFilter[k,2]; ...]
%--------------------------------------------------------------------------
%   Copyright 2023 Bose Corporation

  properties (SetAccess = private, Hidden)
      CodeWorkMemorySize uint32   = 7
  end
  properties (Dependent, Hidden)
      CodeWorkMemoryInitValue
      DelayLineMemoryInitValue
  end
  properties(GetObservable, Hidden, Dependent)
      DelayLineMemorySize   uint32
  end
  properties(GetObservable, SetObservable)
    NumChannels {mustBeInteger} = 2
  end
  methods
    %----------------------------------------------------------------------
    function this = FirUpGenericVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
    end
    %----------------------------------------------------------------------
    function VariantValidate(this)
        % VariantValidate validates cross-property interactions. Our parent
        % object calls us during block mask initialization.
        VariantValidate@BtcVariant(this);
    end
    %----------------------------------------------------------------------
    function val = get.DelayLineMemorySize(this)
        val = this.Parent.NumCoeffs/this.Parent.UpFactor*this.NumChannels;
    end
    %----------------------------------------------------------------------
    function val = get.CodeWorkMemoryInitValue(this)
        val = zeros(1,this.CodeWorkMemorySize,'uint32');
    end
    %----------------------------------------------------------------------
    function val = get.DelayLineMemoryInitValue(this)
        val = zeros(1,this.DelayLineMemorySize,'single');
    end
    %----------------------------------------------------------------------
    function VariantDoMaskInit(this,blockHandle)
        % VariantDoMaskInit performs automation of code generation settings
        % and other canvas interactions for a variant subsystem. Our parent
        % object calls us during block mask initialization.
        VariantDoMaskInit@BtcVariant(this,blockHandle);
        this.ConfigureDataStoreMemory('DelayLineMemory', blockHandle);
        this.ConfigureDataStoreMemory('CodeWorkMemory', blockHandle);

    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, DataStoreMemoryName, blkh)
        % Get DSM block Path
        theDsm = ['FirUp/TargetSpecific/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        Identifier = [char(this.Parent.Alias) char(DataStoreMemoryName)];
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'FirStorage', ...
                                'MemorySection', 'AttributeAligned8',...
                                'Identifier', Identifier);
    end
    %----------------------------------------------------------------------
  end
end
