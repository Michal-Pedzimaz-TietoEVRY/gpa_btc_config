classdef FirUpSharcPlusVariantConfig < BtcVariant
% FirUpSharcPlusVariantConfig Build-time configuration class for the FirUpSharcPlus variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % PropertyName size class {validation functions} = DefaultValue
      NumChannels (1,1) {mustBePositive, mustBeInteger} = 2

  end
  properties (GetObservable,SetObservable,Hidden)
    % PropertyName size class {validation functions} = DefaultValue
    DsmStatesInitValue (:,:) single
    DsmStateIndexInitValue (1,1) int32 = 0
  end
  methods
    %----------------------------------------------------------------------
    function this = FirUpSharcPlusVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        this.Lock(@this.DsmStatesInitValue, ...
            @() zeros(constructingParentObj.NumCoeffs/constructingParentObj.UpFactor + 2, this.NumChannels ));
        disp("SharcPlus Variant for FirUp has been selected. The Code Replacement Library for this block's variant has not yet been validated on hardware. Remove this after validation");
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

        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end

  end
end
