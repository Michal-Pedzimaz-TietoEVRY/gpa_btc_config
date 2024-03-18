classdef FirUpHexagonVariantConfig < FirUpGenericVariantConfig
% FirUpHexagonVariantConfig Build-time configuration class for the FirUpHexagon variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
% For Documentation see FirUpGenericVariantConfig

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % PropertyName size class {validation functions} = DefaultValue

  end
  methods
    %----------------------------------------------------------------------
    function this = FirUpHexagonVariantConfig(constructingParentObj)
        this@FirUpGenericVariantConfig(constructingParentObj);
    end
    %----------------------------------------------------------------------
    function VariantValidate(this)
        % VariantValidate validates cross-property interactions. Our parent
        % object calls us during block mask initialization.

        VariantValidate@FirUpGenericVariantConfig(this);
    end
    %----------------------------------------------------------------------
    function VariantDoMaskInit(this,blockHandle)
        % VariantDoMaskInit performs automation of code generation settings
        % and other canvas interactions for a variant subsystem. Our parent
        % object calls us during block mask initialization.

        VariantDoMaskInit@FirUpGenericVariantConfig(this,blockHandle);
    end

  end
end
