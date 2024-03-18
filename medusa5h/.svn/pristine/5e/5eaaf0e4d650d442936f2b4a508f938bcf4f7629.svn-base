classdef MedusaFdpTuneConfig < TuneConfigClass
% MedusaFdpTuneConfig Default TuneVar values for MedusaDeciRateFdp block
% Note that this class does *NOT* have the ablity to Validate, but it can
% lock and default property values. Do not create a Validate method here!

%   Copyright 2023 Bose Corporation
  properties (Description='TuneDefault',GetObservable,SetObservable)
    FdpCoeffsESDUpperbounddB = double(-2)
    FdpCoeffsXpMin = double(0.2)
    FdpSlowPsdSmoothCutoff = double(3.03388081591392)
    FdpFastPsdSmoothCutoff = double(21.533203125)
    FdpDirectPathSec = double(0.0232199546485261)
    FdpLsSmoothCutoff = double(1.44166589555648)

    FdpDeciRateXpMax = double(0.9)
    FdpFullRateXpMax = double(0.7)

    FdpCoeffsDeciRateESDLowerbounddB = double(-10)
    FdpCoeffsFullRateESDLowerbounddB = double(-4.8571)

    FdpSpumOverwrite = double(0)

  end
  methods
    function EasyConstructor(this)
        % Called from MedusaFdpTuneConfig Constructor.
        % Lock and Default properties here, using Parent if desired...
    end
  end
end
