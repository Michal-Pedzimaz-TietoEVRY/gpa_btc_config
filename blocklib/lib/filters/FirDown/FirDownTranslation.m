function [CoeffsTarget] = FirDownTranslation(CoeffsRaw, Variant)
% Translates Raw FirDown Filter Coefficients into Target Compatible formats
% Inputs:
%   CoeffsRaw: [1D array] Raw Coefficients, also the Fir Coeffs for
%       Simulation
%   DownFactor: [int] Downsampling Factor
%   Variant: [FirDownVariantEnum Type] (Optional) Variant Type associated
%       with target.
% Outputs:
%   CoeffsTarget: [1D array] Coefficients in Target Specific Format
%--------------------------------------------------------------------------

switch(Variant)
    case{"Simulink"}
        CoeffsTarget = CoeffsRaw;
    otherwise
        error("FirDown Translation for Variant %s is not yet supported", Variant);
end
end