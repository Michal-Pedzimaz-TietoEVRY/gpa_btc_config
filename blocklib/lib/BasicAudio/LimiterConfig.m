classdef LimiterConfig < BtcBaseClass
% LimiterConfig Build-time configuration class for the Limiter block
% Usage:
%    aConfig = LimiterConfig
%

%   Copyright 2021 Bose Corporation

  properties (GetObservable,SetObservable)
    DefaultAttackDb  = [10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000 10000]
    DefaultAttackLowDb  = [10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000  10000]
    DefaultDecayDB  = [100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100]
    DefaultDecayLowDb  = [100  100  100  100  100  100  100  100  100  100  100  100  100  100  100  100]
    DefaultMaxAttackDb  = [10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10]
    DefaultMaxAttackLowDb  = [10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10]
    DefaultThreshold  = [0.1        0.015         0.2        0.25         0.3        0.35         0.4        0.45         0.5         0.6        0.65         0.7        0.75         0.8         0.85 0.9]
    DefaultThresholdLow  = [0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5         0.5]
    % Properties use this syntax:
    %    PropertyName size class {validation functions} = DefaultValue
    % About Build-Time Configuration: https://wiki.bose.com/x/dqPoB

  end
  methods
    %----------------------------------------------------------------------
    function this = LimiterConfig()
        % LimiterConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values

    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        % Call base class and check for any cross-property interactions
        Validate@BtcBaseClass(this);

        % If there are no cross-property interactions, then this entire
        % method can be deleted!
    end

  end
end
