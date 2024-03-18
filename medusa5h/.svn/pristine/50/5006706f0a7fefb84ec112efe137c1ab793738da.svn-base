classdef MedusaOverheadHoligramEqConfig < BtcBaseClass
% MedusaOverheadHoligramEqConfig Build-time configuration class for the MedusaOverheadsHoligramEq block
% Usage:
%    aConfig = MedusaOverheadHoligramEqConfig
%

%   Copyright 2023 Bose Corporation

  properties (GetObservable,SetObservable)
      FullRateFrameSize           uint32          = 32
      DecimationFactor            uint32          = 4

      % Platform Variant Configuration
      Variant                                     = 'Generic'

      % System Channel Configuration
      NumOverheadSpeakerPairs     uint32          = 2                     % Number of overhead speakers (Value of '2' means that there are 2 left and 2 right speakers)
      
      % Number of Holigram EQ links per speaker - N2/N4/N6/N8/N10/N12
      NumHoligramEqLinks          uint32      {mustBeMember(NumHoligramEqLinks,[2, 4, 6, 8, 10, 12])} = 8

      % Filter parameters
      AvgFirLength                uint32          = 532
      MaxFirLength                uint32          = 652
      MaxNumStages                uint32          = 20

      % Holigram EQ object
      HoligramEq                  MedusaDrHoligramEqConfig
  end

  properties(Dependent = true)
      NumInputs                   uint32
      NumOutputs                  uint32
      TotalNumEqLinks             uint32
  end

  properties(SetAccess = private)
      BufferAlias       = "OverheadDelayBuffer"
      HeaderFileName    = "MedusaHoligramEq"
  end

  methods
    %----------------------------------------------------------------------
    function this = MedusaOverheadHoligramEqConfig()
        % MedusaOverheadHoligramEqConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.Lock(@this.HoligramEq, @() this.ConstructHoligramEq());
      
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok

        %.End with a call to our base class to continue validation checks
        %.including any violations of property locking.
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.

        %.Call base class in case it has any work to perform:
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end
   
    function value = get.NumInputs(this)
        % Number of inputs to Overhead Holigram EQ must be equal to number
        % of overhead premix outputs
        value = 2*this.NumHoligramEqLinks;
    end

    function value = get.NumOutputs(this)
        % Number of outputs from Overhead Holigram EQ must be equal to
        % number of overhead speaker outputs
        value = 2*this.NumOverheadSpeakerPairs;
    end

    function value = get.TotalNumEqLinks(this)
        % Computes the total number of Hybrid Holigram EQ links between all
        % inputs and outputs
        value = this.NumOverheadSpeakerPairs * this.NumHoligramEqLinks;
    end

    function config = ConstructHoligramEq(this)
        config = MedusaDrHoligramEqConfig;
        config.FullRateFrameSize = this.FullRateFrameSize;
        config.DecimationFactor = this.DecimationFactor;
        config.NumInputs = this.NumInputs;
        config.NumOutputs = this.NumOutputs;
        config.TotalNumEqLinks = this.TotalNumEqLinks;
        config.AvgFirLength = this.AvgFirLength;
        config.MaxFirLength = this.MaxFirLength;
        config.MaxNumStages = this.MaxNumStages;
        config.Variant = this.Variant;
        config.BufferAlias = this.BufferAlias;
        config.HeaderFileName = this.HeaderFileName;
    end

  end
end
