classdef NearConfig < BtcBaseClass
% ModelConfig Build-time configuration class for the Model block
% Usage:
%    aConfig = ModelConfig
%

%   Copyright 2023 Bose Corporation

  properties
    %.Properties use this syntax:
    %.   PropertyName size class {validation functions} = DefaultValue
    %.About Build-Time Configuration: https://wiki.bose.com/x/dqPoB
    SampleRate = 44100
    FullRateFrameSize = 32
    DeciRateFrameSize = 8
    FrameSize = 24
    NumOutputAudioChannels = 24
    NumEntInputChannels = 2
    AnnChannelCount = 2
    
    NearEnabled = 1;
    NearPreAmpConfig PreAmpConfig
    Near Near1p1Config
    NearWiggleFilter WiggleFilterConfig
    SrcDn SampleRateConverterConfig

  end

  properties (Dependent)
      NumChannels
      NumNonHeadrestChannels
      NumPeripheralChannels
  end

  methods
    %----------------------------------------------------------------------
    function this = NearConfig()
        % ModelConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
    
        % Give each feature their own function to initialize their
        % BTC configurations.
        this.InitNear();
        this.SrcDn = SampleRateConverterConfig;
        this.SrcDn.Upfactor = 12;
        this.SrcDn.Downfactor = 13;

    end



    function InitNear(this)
        % Initialize NEAR settings
        this.NearPreAmpConfig = PreAmpConfig();
        %this.Lock(@this.NearPreAmpConfig.FrameSize,@()this.FullRateFrameSize);

        this.Near = Near1p1Config();
        this.Lock(@this.Near.AnnChannelCount,@()this.AnnChannelCount);

        this.NearWiggleFilter = WiggleFilterConfig();
        this.Lock(@this.NearWiggleFilter.ChannelCount,@()this.NumEntInputChannels);
    end





    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok

        %.If there are no cross-property interactions, then this entire
        %.method can be deleted!

        %.End with a call to our base class to continue validation checks
        %.including any violations of property locking.
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
  end
end
