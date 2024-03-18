classdef FirUpTunableConfig < FirUpConfig
% Block Documentation for FirUpTunable-------------------------------------
% Upsampling followed by an Fir filter. The block is implemented using a 
% polyphase Fir. Fir filter length must be a multiple of the upsampling 
% factor. This block is a wrapper around the FirUp (DSP only) block. The
% wrapper handes translations of the coefficients to each specific hardware
% target depending on the selected variant. The wrapper also contains
% contains insfrastructure for tuning during the overlay process.
% Inputs:
%   AudioIn: [FrameSize x NumChannels] Input signal 
% Outputs:
%   AudioOut: [FrameSize*UpFactor x NumChannels] Upsampled and filtered
%       output signal
%
% Properties:
%   TuneVarCoeffsRaw: [NumCoeffs x 1] Coefficients in standard format [h[0], h[1] ...]
%   DownFactor: Down-Sampling Factor
%--------------------------------------------------------------------------


%   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        TuneVarCoeffsRaw (:,1) single
    end
    properties(GetObservable, SetObservable, Hidden)
        WithFirVariant FirGenericVariantEnum
    end
    methods
    %----------------------------------------------------------------------
    function this = FirUpTunableConfig()
        % FirUpTunableConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this.Default(@this.TuneVarCoeffsRaw, @() designMultirateFIR(this.UpFactor,1,0.1));
        this.Lock(@this.NumCoeffs, @() this.GetNumCoeffs);
    
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@FirUpConfig(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        % MaskInit Depending on which blockType uses this Config
        blockType = get_param(blockHandle, 'MaskType');
        if (blockType == "Blocklib FirUp")
            DoMaskInit@FirUpConfig(this,blockHandle);
        elseif (blockType == "Blocklib FirUpTunable")
            DoMaskInit@BtcBaseClass(this,blockHandle);
        else
            error("Unsupported Block %s" , blockType);
        end
    end
    %----------------------------------------------------------------------
    function val = get.WithFirVariant(this)
        if this.Variant == "WithFir"
            val = this.VariantObj.Fir.Variant;
        else
            val = FirVariantEnum.Generic;
        end
    end
    %----------------------------------------------------------------------
    function NumCoeffs = GetNumCoeffs(this)
        if (this.Variant == FirUpVariantEnum.WithFir)
            CoeffsTarget = FirUpTranslation(this.TuneVarCoeffsRaw, this.UpFactor, this.Variant, this.VariantObj.Fir.Variant);
        else
            CoeffsTarget = FirUpTranslation(this.TuneVarCoeffsRaw, this.UpFactor, this.Variant);
        end
        NumCoeffs = numel(CoeffsTarget);
    end
    end
    %----------------------------------------------------------------------
    % [Rename-Compatibility:1]
    properties (GetObservable, SetObservable, Dependent, Hidden) % [Rename-Compatibility:1]
       CoeffsRaw
    end
    methods
       function set.CoeffsRaw(obj,val)
          obj.TuneVarCoeffsRaw = val;
          warning('Deprecated FirUpTunableConfig property [CoeffsRaw] used. Update to use [TuneVarCoeffsRaw]')
       end
       function val = get.CoeffsRaw(obj)
          val = obj.TuneVarCoeffsRaw;
          warning('Deprecated FirUpTunableConfig property [CoeffsRaw] used. Update to use [TuneVarCoeffsRaw]')
       end
    end % [Rename-Compatibility:1]
    %----------------------------------------------------------------------
end
