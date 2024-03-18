classdef MedusaSurroundLevelControlGenericConfig < MedusaSurroundLevelControlConfig
% MedusaSurroundLevelControlGenericConfig Build-time configuration class for the MedusaSurroundLevelControlGeneric block
% Usage:
%    aConfig = MedusaSurroundLevelControlGenericConfig
%

%   Copyright 2023 Bose Corporation

  properties

  end

  methods
    %----------------------------------------------------------------------
    function this = MedusaSurroundLevelControlGenericConfig()
        % MedusaSurroundLevelControlGenericConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values

    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        % Call base class and check for any cross-property interactions
        Validate@MedusaSurroundLevelControlConfig(this);
    end

  end
end
