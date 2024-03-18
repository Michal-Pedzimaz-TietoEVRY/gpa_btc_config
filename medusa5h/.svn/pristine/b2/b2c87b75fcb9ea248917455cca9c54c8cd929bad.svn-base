classdef MedusaForwardBackwardSmoothConfig < BtcBaseClass
% MedusaForwardBackwardSmoothConfig Build-time configuration class for the MedusaForwardBackwardSmoothConfig block
% Usage:
%    aConfig = MedusaForwardBackwardSmoothConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    % Properties use this syntax:
    %    PropertyName size class {validation functions} = DefaultValue
    % About Build-Time Configuration: https://wiki.bose.com/x/dqPoB
    DelayLength {mustBePositive} = 1
    InitialCondition = 0
  end
  methods
    %----------------------------------------------------------------------
    function this = MedusaForwardBackwardSmoothConfig()
        % ForwardBackwardSmoothConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
    end

    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        % Call base class and check for any cross-property interactions
        Validate@BtcBaseClass(this);
    end

  end
end
