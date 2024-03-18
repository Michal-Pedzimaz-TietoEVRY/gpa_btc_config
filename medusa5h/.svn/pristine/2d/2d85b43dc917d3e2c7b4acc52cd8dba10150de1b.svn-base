classdef MedusaSurroundLevelControlConfig < BtcBaseClass
% MedusaSurroundLevelControlConfig Build-time configuration class for the MedusaSurroundLevelControl block
% Usage:
%    aConfig = MedusaSurroundLevelControlConfig
%

%   Copyright 2023 Bose Corporation

  properties(SetAccess=private)
    % Default values for Surround Level Control parameters
    defaultSurroundIndex = 128;                         % Default Surround Index
    defaultRampRate = 100;                              % Default Ramp Rate in dB per second
    defaultRampTime = 0;                                % Default Ramp Time in milliseconds

  end

  methods
    %----------------------------------------------------------------------
    function this = MedusaSurroundLevelControlConfig()
        % MedusaSurroundLevelControlConfig constructor: assign component property objects
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
