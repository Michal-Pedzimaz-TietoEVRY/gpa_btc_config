classdef MedusaFdpFullRateVariantConfig < BtcVariant
% MedusaFdpFullRateVariantConfig Build-time configuration class for the MedusaFdpFullRate variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % PropertyName size class {validation functions} = DefaultValue
    NumComponents % Number of Components
  end
  methods
    %----------------------------------------------------------------------
    function this = MedusaFdpFullRateVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        this.SetDefaults();
        this.Lock(@this.NumComponents, @() 6);
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
        this.Parent.FrameSize = 32;
        this.Parent.DecimationFactor = 1;
        this.Parent.SetDefaultSmoothingFilters;

        % SPUM
        this.Parent.DetectImpulseThreshold = 6/8;
        this.Parent.MaxValueOfCounterForDetectingImpulse = 16;
        this.Parent.MaxDirectPathSamples = this.Parent.MaxSpumFrameDelay*4/...
            this.Parent.DecimationFactor * this.Parent.FrameSizeInFrequency; 
    end
  end
end
