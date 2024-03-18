classdef FirUpConfig < BtcBaseClassWithVariants
% Block Documentation For FirUp -------------------------------------------
% Upsampling followed by an Fir filter. The block is implemented using a 
% polyphase Fir. Fir filter length must be a multiple of the upsampling 
% factor. This block expects the the input "CoeffsTarget" to be translated 
% to the correct format for each hardware target. A seperate input 
% "CoeffsRaw" is the coefficients used in the simulation format. The same 
% Fir filter is applied to each channel.
% 
% Inputs:
% -AudioIn: [FrameSize x  NumChannels] The input audio signal
% -CoeffsTarget: [NumCoeffs x 1] 1-D array of the Fir filter coefficients. 
%   These must be translated into the format expected by the hardware 
%   target. For Simulink and Simuation Variants, the CoeffsTarget should be
%   equal to the CoeffsRaw.
% -CoeffsRaw: [NumCoeffs x 1] 1-D array of the Fir filter coefficients used
%   for simulation. For filter h[n] of length N, 
%   CoeffsRaw = [ h[0]; h[1]; ...... h[N-1] ]
% 
% Outputs:
% -AudioOut: [FrameSize*FactorUp x NumChannels] The output audio after 
%   upsampling and filtering.
%--------------------------------------------------------------------------
  properties (GetObservable,SetObservable)
      NumCoeffs (1,1) {mustBePositive, mustBeInteger} = 96     % Length of Fir Filter
      UpFactor  (1,1) {mustBePositive, mustBeInteger} = 4      % Upsampling Factor
      Alias    = 'Default' % Unique Alias for each instance of the block
  end

  properties (GetObservable, SetObservable, Dependent, Hidden) % [Rename-Compatibility:1]
       NumChannels
  end
  methods
    %----------------------------------------------------------------------
    function this = FirUpConfig()
        % FirUpConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values
        this@BtcBaseClassWithVariants('FirUpVariantEnum');
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
  end
end
