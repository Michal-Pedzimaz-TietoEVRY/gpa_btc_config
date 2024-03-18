classdef InputRouterEqConfig < BtcBaseClass
% InputRouterEqConfig Build-time configuration class for the InputRouterEq block
% Usage:
%    aConfig = InputRouterEqConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    InputSelect RouterConfig
    MultiSourceEq MultiSourceEqConfig

    NumChannels = 3
    EntMap = [1 2]
    AnnMap = [3 4]
    
  end 
  methods
    %----------------------------------------------------------------------
    function this = InputRouterEqConfig()
        % InputRouterEqConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.MultiSourceEq =  MultiSourceEqConfig;
        this.Default(@this.MultiSourceEq.NumEntChannel, ...
            @() this.NumChannels);

        this.InputSelect =  RouterConfig;
        SelectMap = [this.EntMap this.AnnMap];
        this.Default(@this.InputSelect.NumIn, @() this.NumChannels);
        this.Default(@this.InputSelect.NumOut, @() this.NumChannels);
        this.Default(@this.InputSelect.DefaultOutputMap, ...
            @() SelectMap);

    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

  end
end
