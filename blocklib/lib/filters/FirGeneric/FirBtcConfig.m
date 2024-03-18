classdef FirBtcConfig < FirConfig
% Blocklib FirBtc----------------------------------------------------------
% Wrapper around the Blocklib FirGeneric block. Setting coefficients, 
% coefficient mapping and input mapping is handled in the Build Time 
% Configuration. 
% Generic multi-channel FIR block supports multiple inputs, outputs and 
% coefficient sets. Some inputs may drive multiple outputs, and this input 
% sharing is specified by an input mapping per output. Some filters may be 
% shared among multiple outputs, and this filter sharing is specified by a 
% filter mapping per output. Input sharing assumes all filters sharing the 
% same input have the same length to support state buffer sharing. 
% 
% Input signals:
%   AudioIn: input channels [frame size x number of inputs] 
% 
% Output signals: 
%   y: output channels [frame size x number of outputs]
%
% Btc Paramaters
%   CoeffsRaw: [sum(TuneVarCoeffsLengths) x 1] Raw coefficient sets. coefficients 
%       are in standard format stored consecutively in a 1d array 
%       Example: [h0[0], h0[1], ... h0[N0-1], h1[0], h1[1], ... h1[N1-1] ......]
%   TuneVarCoeffsLengths: [number of filters x 1] Array of filter lengths
%       Example: [N0, N1, N2 ....] where Ni is the length of the ith filter 
%   TuneVarInputMapping: [number of outputs x 1] Zero-based input mapping for each
%       output. Output[i] = Fir(Input[TuneVarInputMapping[i]], ...)
%   TuneVarCoeffsMapping: [number of outputs x 1] Zero-based filter mapping for each
%       output. Output[i] = Fir(Filter[TuneVarCoeffsMapping[i]], ...)
%
% For Hexagon: 
%   -Filter lengths must all be equal. (Done using )
%   -Filter length must be multiple of 4. (Use zero-padding)
%   -Filter lengths must be greater than the FrameSize. (Use zero-padding)
%   -Filter length requirements can be met by zero-padding filters to ensure
%       complaince
%--------------------------------------------------------------------------

  properties (GetObservable,SetObservable)
    % column vector of all filter coefficients. These coefficients may be of
    % different length. 
    CoeffsRaw       (:,1) single

    % row vector, where the i-th value specifies the length of the i-th
    % filter
    TuneVarCoeffsLengths   (1,:) {mustBeNonnegative, mustBeInteger}

    % row vector, maps each output of the block to an input. The i-th value
    % of the TuneVarInputMapping vector returns the index (zero-indexed) of the 
    % input that maps to the i-th output 
    TuneVarInputMapping    (1,:) {mustBeNonnegative, mustBeInteger} 

    % row vector, maps each output of the block to a filter. The i-th value
    % of the TuneVarCoeffsMapping vector returns the index (zero-indexed) of the 
    % filter that maps to the i-th output 
    TuneVarCoeffsMapping   (1,:) {mustBeNonnegative, mustBeInteger}
  end
  properties(GetObservable, SetObservable, Dependent)
    % Coefficients after translation to target specific format
    TuneVarCoeffsTarget    (:,1) single
  end

  methods
    %----------------------------------------------------------------------
    function this = FirBtcConfig()
        % FirBtcConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        DefaultNumCoeffSets = 2;
        this.Default(@this.CoeffsRaw,@() repmat([1,zeros(1,this.MaxAvgCoeffLength-1)],1,DefaultNumCoeffSets));
        this.Default(@this.TuneVarCoeffsLengths, @() repmat(this.MaxAvgCoeffLength,1,DefaultNumCoeffSets));
        this.Default(@this.TuneVarInputMapping, @() mod(0:(this.NumOutputs-1), this.NumInputs));
        this.Default(@this.TuneVarCoeffsMapping, @() mod(0:(this.NumOutputs-1), numel(this.TuneVarCoeffsLengths)));
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@FirConfig(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        blockType = get_param(blockHandle, 'MaskType');
        if (blockType == "Blocklib Fir")
            DoMaskInit@FirConfig(this, blockHandle);
        elseif (blockType == "Blocklib FirBtc")
            DoMaskInit@BtcBaseClass(this, blockHandle);
        else
            error("Unsupported Block %s", blockType);
        end
    end
    %----------------------------------------------------------------------
    function val = get.TuneVarCoeffsTarget(this)
        % Catch error before translation
        if (this.Variant == "Hexagon") || (this.Variant == "ArmNeonV7V8")
            if (~all(this.TuneVarCoeffsLengths) == this.TuneVarCoeffsLengths(1))
                error("Property [TuneVarCoeffsLengths] for Blocklib Fir block must all be equal for selected Variant [%s]",string(this.Variant));
            end
            if (mod(this.TuneVarCoeffsLengths(1), 4) ~= 0)
                error("Property [TuneVarCoeffsLengths] for Blocklib Fir block must be a multiple of 4 for selected Variant [%s]",string(this.Variant));
            end
        end
        if numel(this.CoeffsRaw) ~= sum(this.TuneVarCoeffsLengths)
            error("For Blocklib Fir Block, total number of coefficients of property [CoeffsRaw] is %d which is not equal to %d, " + ...
                "the total number of coefficients specified by property [TuneVarCoeffslengths]. Number of coefficients need to be consistent.", ...
                numel(this.CoeffsRaw), sum(this.TuneVarCoeffsLengths))
        end
        val = FirTranslation(   this.CoeffsRaw, ...
                                this.TuneVarCoeffsLengths,...
                                this.Variant);
    end
    %----------------------------------------------------------------------
  end

properties (GetObservable, SetObservable, Dependent, Hidden) % [Rename-Compatibility:1]
   CoeffsLengths
   InputMapping
   CoeffsMapping
   CoeffsTarget
end
methods
   function set.CoeffsLengths(obj,val)
      obj.TuneVarCoeffsLengths = val;
      warning('Deprecated FirBtcConfig property [CoeffsLengths] used. Update to use [TuneVarCoeffsLengths]')
   end
   function val = get.CoeffsLengths(obj)
      val = obj.TuneVarCoeffsLengths;
      warning('Deprecated FirBtcConfig property [CoeffsLengths] used. Update to use [TuneVarCoeffsLengths]')
   end
   function set.InputMapping(obj,val)
      obj.TuneVarInputMapping = val;
      warning('Deprecated FirBtcConfig property [InputMapping] used. Update to use [TuneVarInputMapping]')
   end
   function val = get.InputMapping(obj)
      val = obj.TuneVarInputMapping;
      warning('Deprecated FirBtcConfig property [InputMapping] used. Update to use [TuneVarInputMapping]')
   end
   function set.CoeffsMapping(obj,val)
      obj.TuneVarCoeffsMapping = val;
      warning('Deprecated FirBtcConfig property [CoeffsMapping] used. Update to use [TuneVarCoeffsMapping]')
   end
   function val = get.CoeffsMapping(obj)
      val = obj.TuneVarCoeffsMapping;
      warning('Deprecated FirBtcConfig property [CoeffsMapping] used. Update to use [TuneVarCoeffsMapping]')
   end
   function set.CoeffsTarget(obj,val)
      obj.TuneVarCoeffsTarget = val;
      warning('Deprecated FirBtcConfig property [CoeffsTarget] used. Update to use [TuneVarCoeffsTarget]')
   end
   function val = get.CoeffsTarget(obj)
      val = obj.TuneVarCoeffsTarget;
      warning('Deprecated FirBtcConfig property [CoeffsTarget] used. Update to use [TuneVarCoeffsTarget]')
   end
end % [Rename-Compatibility:1]

end
