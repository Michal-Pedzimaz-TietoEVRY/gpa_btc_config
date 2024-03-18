classdef MedusaFdpDeciRateVariantConfig < BtcVariant
% MedusaFdpDeciRateVariantConfig Build-time configuration class for the MedusaFdpDeciRate variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % PropertyName size class {validation functions} = DefaultValue
    NumComponents 
  end
  methods
    %----------------------------------------------------------------------
    function this = MedusaFdpDeciRateVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        this.Lock(@this.NumComponents, @() 8);
        this.SetDefaults();

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
    %----------------------------------------------------------------------
    function SetDefaults(this)
        % Set Defaults
        this.Parent.FrameSize = 8;
        this.Parent.DecimationFactor = 4;
        this.Parent.SetDefaultSmoothingFilters;

        % SPUM
        this.Parent.DetectImpulseThreshold = 6;
        this.Parent.MaxValueOfCounterForDetectingImpulse = 4;
        this.Parent.MaxDirectPathSamples = (this.Parent.MaxSpumFrameDelay + 1)*this.Parent.FrameSizeInFrequency;
    end
  end
end
