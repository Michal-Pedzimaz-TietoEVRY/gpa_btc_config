classdef InputSelectConfig < BtcBaseClass
% InputSelectConfig Build-time configuration class for the InputSelect block
% Usage:
%    aConfig = InputSelectConfig
%

%   Copyright 2024 Bose Corporation

  properties (GetObservable,SetObservable)
    RouterCfg RouterConfig
    annMap = [1 2]
    entMap = [3 4]
    vncMic = [5]
    NumInputChannels = 5
    InputSelectOutputMap  = [1 2 3]
  end
  methods
    %----------------------------------------------------------------------
    function this = InputSelectConfig()
        % InputSelectConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.RouterCfg = RouterConfig;  
        this.RouterCfg.NumIn = this.NumInputChannels;
        this.RouterCfg.NumOut = this.NumInputChannels;
        this.RouterCfg.DefaultOutputMap = this.InputSelectOutputMap;
        this.Lock(@this.RouterCfg.NumIn, @() this.NumInputChannels);
        this.Lock(@this.RouterCfg.NumOut, @() this.NumInputChannels);
        this.Lock(@this.RouterCfg.DefaultOutputMap, @() this.InputSelectOutputMap);       

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
