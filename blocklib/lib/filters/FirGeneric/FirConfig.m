classdef FirConfig < BtcBaseClassWithVariants
% Blocklib Fir-------------------------------------------------------------
% Generic multi-channel FIR block supports multiple inputs, outputs and 
% coefficient sets. Some inputs may drive multiple outputs, and this input 
% sharing is specified by an input mapping per output. Some filters may be 
% shared among multiple outputs, and this filter sharing is specified by a 
% filter mapping per output. Input sharing assumes all filters sharing the 
% same input have the same length to support state buffer sharing. 
% 
% Input signals:
%   AudioIn: [frame size x number of inputs] Input signal to be filtered
%   CoeffsRaw: [sum(CoeffsLengths) x 1] Raw coefficient sets. coefficients 
%       are in standard format stored consecutively in a 1d array 
%       Example: [h0[0], h0[1], ... h0[N0-1], h1[0], h1[1], ... h1[N1-1] ......]
%   CoeffsTarget: Coefficient sets after translation [sum(CoeffsLengths) x 1]
%       To get CoeffsTarget from CoeffsRaw, use FirTranslation function
%       Example: CoeffsTarget = FirTranslation(CoeffsRaw, CoeffsMapping, CoeffsLengths, Variant)
%   CoeffsLengths: [number of filters x 1] Array of filter lengths. Filters
%       should be of even length.
%       Example: [N0, N1, N2 ....] where Ni is the length of the ith filter 
%   InputMapping: [number of outputs x 1] Zero-based input mapping for each
%       output. Output[i] = Fir(Input[InputMapping[i]], ...)
%   CoeffsMapping: [number of outputs x 1] Zero-based filter mapping for each
%       output. Output[i] = Fir(Filter[CoeffsMapping[i]], ...)
%  
% Output signals: 
%   y: output channels [frame size x number of outputs] 
%
% Properties:
%   NumInputs
%   NumOutputs
%   FrameSize
%   MaxAvgCoeffLength: This is the maximum total coefficient length divided
%       by the number of coefficient sets. Sum(CoeffLengths) must be <=
%       MaxAvgCoeffLength*NumberOfFilters
%   BufferAlias: A unique name must be provided for each instance of
%       Blocklib Fir.
%
% For Sharc: The Fir CodeWorkMemory buffer should always be mapped 
% to L1 memory or core MIPS usage will increase.
% For Hexagon: The filter lengths for each channel must be a multiple of 4.
%
% For Hexagon: 
%   -Filter lengths must all be equal.
%   -Filter length must be multiple of 4. (Use zero-padding)
%   -Filter lengths must be greater than the FrameSize. (Use zero-padding)
%   -Filter length requirements can be met by zero-padding filters to ensure
%       complaince
%--------------------------------------------------------------------------
%   Copyright 2023 Bose Corporation

  properties(GetObservable, SetObservable)
      NumOutputs = 2
      NumInputs = 2
      FrameSize = 32
      MaxAvgCoeffLength = 8       % MaxCoeffLength needs to be a multiple of 4 for hexagon Variant
      Alias = 'Default'
  end
  properties(GetObservable, SetObservable, Dependent, SetAccess=private)
    StateBufferSizeSimulation
  end

  methods
    %----------------------------------------------------------------------
    function this = FirConfig()
        % FirConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values

        % Specify the variant enumeration

        this@BtcBaseClassWithVariants('FirVariantEnum');
    end
    %----------------------------------------------------------------------
    function val = get.StateBufferSizeSimulation(this)
        val = (this.MaxAvgCoeffLength + this.FrameSize)*this.NumOutputs;
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClassWithVariants(this);
    end
    %----------------------------------------------------------------------.
    function DoMaskInit(this, blockHandle)
        DoMaskInit@BtcBaseClassWithVariants(this, blockHandle);
    end
  end
end
