classdef FirEvenConfig < BtcBaseClassWithVariants
% FirEvenConfig Build-time configuration class for the FirEven block
% Usage:
%    aConfig = FirEvenConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
      Alias = "Default";
      MaxNumOfThreads = 1;
      NumOutputs = 2
      NumInputs = 2
      FrameSize = 32
      NumChannels = 2
      MaxAvgCoeffLength = 8       % MaxCoeffLength needs to be a multiple of 4 for hexagon Variant
  end
  methods
    %----------------------------------------------------------------------
    function this = FirEvenConfig(optionalVariant)
        % FirEvenConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this@BtcBaseClassWithVariants('FirEvenVariantEnum');

        if (exist('optionalVariant','var'))
            % Perform direct assignment so provided string must make sense
            this.Variant = optionalVariant;
        end
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClassWithVariants(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        DoMaskInit@BtcBaseClassWithVariants(this,blockHandle);
    end

  end
end
