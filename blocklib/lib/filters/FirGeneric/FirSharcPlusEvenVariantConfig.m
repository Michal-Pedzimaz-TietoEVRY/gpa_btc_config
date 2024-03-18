classdef FirSharcPlusEvenVariantConfig < BtcVariant
% FirSharcPlusEven---------------------------------------------------------
% This block is the SharcPlus Variant for Fir that takes advantage
% of SharcPlus SIMD optimizations. There are additional requirements for 
% parameters and inputs to this variant.
% THIS BLOCK IS NOT READY FOR USE
%   Requirements:
%       -All coefficients should be of equal length and of length equal to
%           the property <Parent.MaxCoeffsLength>
%       -All coefficients should be of even length
%       -The number of input channels should equal the number of output
%           channels       
%--------------------------------------------------------------------------
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % PropertyName size class {validation functions} = DefaultValue

  end
  methods
    %----------------------------------------------------------------------
    function this = FirSharcPlusEvenVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        error("FirSharcPlusEvenVariant is not ready for use");
    end
    %----------------------------------------------------------------------
    function VariantValidate(this)
        % VariantValidate validates cross-property interactions. Our parent
        % object calls us during block mask initialization.

        if (mod(this.Parent.NumChannels,2) ~= 0)
            error("SharcPlusFirEven Variant Requires an even number of channels");
        end
        if (this.Parent.NumInputs ~= this.Parent.NumOutputs)
            error("SharcPlusFirEven Variant Requires an even number of channels");
        end

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
