classdef PostProcessConfig < BtcBaseClass
% PostProcessConfig Build-time configuration class for the PostProcess block
% Usage:
%    aConfig = PostProcessConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
    Mute MuteConfig
    Limiter LimiterConfig
    EnergyLimiter EnergyLimiterConfig
    SoftClipper SoftClipperConfig
    PostLimiterEq PostLimiterEqConfig


    FrameSize = 32
    EnableAux = [1] 
    AuxGain = [1]
    NumAux = [2]     
    MainGain = 1
    NumChanOut = 24 
    DspTarget = 'Generic'
  end
  methods
    %----------------------------------------------------------------------
    function this = PostProcessConfig()
        % PostProcessConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        
        % Mute
        this.Mute =  MuteConfig();
        this.Default(@this.Mute.InitialMuteState, 0);

        % Limiter
        this.Limiter =  LimiterConfig();
        this.Default(@this.Limiter.DefaultThreshold, ...
            @() 0.9 * ones(1, this.NumChanOut));
        this.Default(@this.Limiter.DefaultThresholdLow, ...
            @() 0.5 * ones(1, this.NumChanOut));
        this.Default(@this.Limiter.DefaultMaxAttackDb, ...
            @() 10 * ones(1, this.NumChanOut));
        this.Default(@this.Limiter.DefaultMaxAttackLowDb, ...
            @() 10 * ones(1, this.NumChanOut));
        this.Default(@this.Limiter.DefaultDecayDB, ...
            @() 100 * ones(1, this.NumChanOut));        
        this.Default(@this.Limiter.DefaultDecayLowDb, ...
            @() 100 * ones(1, this.NumChanOut));  
        this.Default(@this.Limiter.DefaultAttackDb, ...
            @() 10000 * ones(1, this.NumChanOut));          
        this.Default(@this.Limiter.DefaultAttackLowDb, ...
            @() 10000 * ones(1, this.NumChanOut)); 
            
        % EnergyLimiter
        this.EnergyLimiter = EnergyLimiterConfig();

        % SoftClipper
        this.SoftClipper =  SoftClipperConfig();

        % PostLimiter EQ
        this.PostLimiterEq =  PostLimiterEqConfig();
        this.Default(@this.PostLimiterEq.NumChannels, @() this.NumChanOut);   
        sos = [1 0 0 1 0 0];
        this.PostLimiterEq.MaxNumStages = 128;
        this.PostLimiterEq.DefaultNumStages = size(sos, 1) * ones(1, this.NumChanOut);
        this.PostLimiterEq.DefaultSosCoefficients = repmat(sos, this.NumChanOut, 1);
        this.PostLimiterEq.SelectVariant(this.DspTarget);
        this.PostLimiterEq.Alias = 'PostProcPostLimiterEq';

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
