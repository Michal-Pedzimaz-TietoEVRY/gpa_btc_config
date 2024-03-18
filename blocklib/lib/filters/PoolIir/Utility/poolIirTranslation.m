function [PoolNumStages, PoolCoeffs] = poolIirTranslation(rawSOS, numStages, maxNumStages, variantUint8)
% Perform platform-based translation for poolIir block
%
% This functions offers the following outputs:
%   PoolNumStages: Number of active stages for each channel
%   PoolCoeffs   : SOS coefficients in a format accepted by CRL (can be
%                  different for different platform CRLs)
%                  Hexagon (qhdsp_iir_af_bose.S) and ARM format - [b0, b1, a1, b2, a2]        [NumStages x 5, 1]
%                  Hexagon (flt_iir_cas_bq.S) DF-II format [-a1/a0 b1/b0 -a2/a0 b2/b0] plus gain per channel.
%                                             where a0 is assumed to be 1.0. [TotNumStages x 4 + NumChannel, 1]
%                  SHARC plus processors - [k, b1, b2, a1, a2]          [NumStages x 4, 1]                  
%
% This function expects the following inputs:
%   rawSOS      : Unprocessed SOS coefficients in the order - [b0, b1, b2, a0, a1, a2]
%                 Dimensions - [NumStages x NumChannels, 6]
%   numStages   : Number of active stages for each channel
%                 Dimensions - [1 x NumChannels]
%   maxNumStages: Maximum permissible number of stages for each channel
%                 Dimensions - [1 x NumChannels]
%   variantUint8: Platform Variant - accepts only uint8 data type
%                 Generally, the 'variant' is a character array or a
%                 string. In that case, it could be changed to uint8 data
%                 type as follows: uint8(char(Config.Variant))
% 
% If rawSOS and numStages are not being supplied from a TuneVar directly,
% please change it to TuneVar output type as shown below:
% rawSOS = struct('Value', rawSosCoeffs);

variantStr = char(variantUint8); 

switch (variantStr)
    case {"Generic","SharcPlusCore"}
        % These variants order biquad coefficients in a compacted form
        [PoolNumStages, PoolCoeffs] = pooliirTranslationFcn(rawSOS, numStages, maxNumStages);
    case {"SharcPlusAccelGul","SharcPlusAccelGxp"}
        % These variants order biquad coefficients for the ADI accelerator
        [PoolNumStages, PoolCoeffs] = pooliirAccelTranslationFcn(rawSOS, numStages, maxNumStages);
    case{"Hexagon"}
        % Hexagon specific order for biquad coefficients 
        [PoolNumStages, PoolCoeffs] = PoolIirHexagonTranslationFcn(rawSOS, numStages, maxNumStages);
    case{"ArmNeonV7V8"}
        [PoolNumStages, PoolCoeffs] = PoolIirArmNeonV7V8TranslationFcn(rawSOS, numStages, maxNumStages);
    otherwise
        % This is a build-time error, not a translation error. The
        % selected build-time variant is not supported for translation
        error('Invalid implementation type for pool IIR: [%s]', variantStr);
end

end

