function CoeffsTarget = FirTranslation(CoeffsRaw, CoeffsLengths, Variant)
% Translates Raw Filter Coefficients into target specific format
% Inputs:
%   CoeffsRaw: [1d array] All filter coefficients stored consecutively in a
%       1d array. Filter lengths may vary between filters. IE: For N number 
%       of filter, CoeffsRaw stores the i-th filter hi(n) as
%       CoeffsRaw = [h1(1:end); h2(1:end); ... hN(1:end)]
%       filter_i[0] = CoeffsRaw(CoeffsMapping(i))
%   CoeffsLengths: [1d array] Array of lengths for each filter. The length
%       of filter i is given by CoeffsLengths(i)
%   Variant: [FirVariantEnum] Specifies the target type for
%       translation
% Output:
%   CoeffsTarget: [1d array] All translated filter coefficients after
%       translation into target specific format.
%--------------------------------------------------------------------------
NumFilters = numel(CoeffsLengths);

% Convert empty EnumTypes into empty array
if isempty(Variant)
    Variant = "Sim";
end

switch(string(Variant))
    case{"SharcPlusAccel", "SharcPlusCore", "ArmNeonV7V8"}
        CoeffsTarget = zeros(size(CoeffsRaw),class(CoeffsRaw));
        StartingIdx = 1;
        for FilterIdx = 1:NumFilters
            Coeff = CoeffsRaw(StartingIdx: StartingIdx + CoeffsLengths(FilterIdx) - 1);
            CoeffsTarget(StartingIdx: StartingIdx + CoeffsLengths(FilterIdx) - 1) = flip(Coeff);
            StartingIdx = StartingIdx + CoeffsLengths(FilterIdx);
        end
        
    otherwise
        CoeffsTarget = CoeffsRaw;
end
end
