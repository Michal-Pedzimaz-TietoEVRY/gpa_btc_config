classdef FirDownConfig < BtcBaseClassWithVariants
% FirDownConfig Build-time configuration class for the FirDown block
% Block Documentation For FirDown -------------------------------------------
% Downsampling followed by an Fir filter. The block is implemented using a 
% polyphase Fir. This block expects input "CoeffsTarget" to be translated 
% to the correct format for each hardware target. The same 
% Fir filter is applied to each channel.
% 
% Inputs:
% -AudioIn: [FrameSize x  NumChannels] The input audio signal
% -CoeffsTarget: [NumCoeffs x 1] 1-D array of the Fir filter coefficients. 
%   These must be translated into the format expected by the hardware 
%   target. The Simulink Variant uses the standard coefficient format.
% Outputs:
% -AudioOut: [FrameSize*FactorDown x NumChannels] The output audio after 
%   upsampling and filtering.
%--------------------------------------------------------------------------
  properties (GetObservable,SetObservable)
      DownFactor  (1,1) {mustBePositive, mustBeInteger} = 4    % Downsampling Factor
  end
  methods
    %----------------------------------------------------------------------
    function this = FirDownConfig()
        % FirDownConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this@BtcBaseClassWithVariants('FirDownVariantEnum');
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate called from mask initialization to check settings ok
        Validate@BtcBaseClassWithVariants(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        DoMaskInit@BtcBaseClassWithVariants(this,blockHandle);
    end
    %----------------------------------------------------------------------
  end
end
