classdef ModelSimpleSrcConfig < BtcBaseClass
% NullFramePlayConfig Build-time configuration class for the NullFramePlay block
% Usage:
%    aConfig = ModelSimpleSrcConfig
%

%   Copyright 2023 Bose Corporation

  properties
    To44 SampleRateConverterConfig
    To48 SampleRateConverterConfig

    SampleRate = 48000
    CoreIndex CoreIndexConfig

    InAt48 ModelRootInportConfig
    InAt44 ModelRootInportConfig
    BackInAt44 ModelRootInportConfig

    OutAt44 ModelRootOutportConfig
    BackOutAt44 ModelRootOutportConfig
    OutAt48 ModelRootOutportConfig
  end
  methods
    %----------------------------------------------------------------------
    function this = ModelSimpleSrcConfig()
        
        this.InAt48 = ModelRootInportConfig;
        this.InAt48.BufferName = 'UnitTest_Target_AudioIn';
        this.InAt48.FrameSamples = 32;
        this.InAt48.ChannelCount = 5;

        this.InAt44 =  ModelRootInportConfig;
        this.InAt44.BufferName = 'UnitTest_Target_AudioIn_2_1';
        this.InAt44.FrameSamples = 32;
        this.InAt44.ChannelCount = 5;

        this.BackInAt44 =  ModelRootInportConfig;
        this.BackInAt44.BufferName = 'UnitTest_Target_AudioIn_3_1'; 
        this.BackInAt44.FrameSamples = 32;
        this.BackInAt44.ChannelCount = 5;
                
        this.OutAt44 = ModelRootOutportConfig;
        this.OutAt44.BufferName = 'UnitTest_Target_AudioOut_1_1';
        this.BackOutAt44 = ModelRootOutportConfig;
        this.BackOutAt44.BufferName = 'UnitTest_Target_AudioOut_2_1';
        this.OutAt48 = ModelRootOutportConfig;
        this.OutAt48.BufferName = 'UnitTest_Target_AudioOut';


        this.CoreIndex =  CoreIndexConfig;
        this.To48 =  SampleRateConverterConfig;
        this.To44 =  SampleRateConverterConfig;

        this.To48.Upfactor = 13;
        this.To48.Downfactor = 12;        
        
        % System audio input (e.g. at 48k)
        this.Lock(@this.InAt48.SampleRateInHertz,@this.SampleRate);

        % 44        
        this.Lock(@this.InAt44.SampleRateInHertz,@()this.SampleRate/13*12);
        this.Lock(@this.BackInAt44.SampleRateInHertz,@()this.SampleRate/13*12);
   
        this.CoreIndex.CrossCore.Api = "FourList";
        this.CoreIndex.CrossCore.Allocation = "AllLocalChip";
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
