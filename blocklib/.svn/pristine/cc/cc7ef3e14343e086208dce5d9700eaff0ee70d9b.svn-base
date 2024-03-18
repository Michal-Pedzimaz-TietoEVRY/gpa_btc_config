function Output = FirUpProcessSim(Input, Coeffs, UpFactor, Variant)
% Upsample Input signal followed by Fir Filter. Implemented using
% Polyphase Fir Filter
% Inputs:
%   Input:      [FrameSize x NumChannels] Lower Rate Input Signal
%   Coeffs:     [1d array of size CoeffLength] Fir Filter Coefficients
%   UpFactor:   [int] Upsampling Factor
%--------------------------------------------------------------------------

if nargin < 4
    Variant = "Simulation";
end

[FrameSize, NumChannels] = size(Input);
Output = single(zeros(FrameSize*UpFactor, NumChannels));
CoeffLength = numel(Coeffs);
MaxSubFilterLength = ceil(CoeffLength/UpFactor);

% Padding to ensure that all Subfilters are the same length
PaddedCoeffLength = MaxSubFilterLength*UpFactor;
PaddedCoeffs = [Coeffs(:); zeros(PaddedCoeffLength - CoeffLength,1)];

% Untranslate Coeffs
PaddedCoeffs = TranslateCoeffsTargetToSim(PaddedCoeffs, UpFactor, Variant);

persistent States 
if isempty(States)
    States = single(zeros(PaddedCoeffLength, NumChannels));
end
for ch = 1 : NumChannels
    for k = 0: UpFactor - 1
        % Get indices for kth Subfilter
        SubFilterIndices = 1 + (0:MaxSubFilterLength-1)*UpFactor + k;
        % Get Coeffs of k-th Subfilter
        SubFilterCoeffs = PaddedCoeffs(SubFilterIndices);
        % Compute Fir
        [SubFilterOutput, SubFiltersStates] = FirFilter(flipud(SubFilterCoeffs), Input(:,ch), States(SubFilterIndices, ch), false);
        % Save States
        States(SubFilterIndices,ch) = SubFiltersStates(:);
        % Upsample, Delay and Accumulate
        OutputIndices = ((1 + k):UpFactor:(FrameSize*UpFactor)); 
        Output(OutputIndices , ch) = Output(OutputIndices , ch) + SubFilterOutput(:);
    end
end
end

function CoeffsSim = TranslateCoeffsTargetToSim(Coeffs, UpFactor, Variant)
% Undoes Coefficient Translation. Returns coefficients in a simulation
% ready format.

CoeffsSim = zeros(size(Coeffs),'single');
switch(Variant)
    case{"SharcPlus", "Hexagon"}
        MaxSubFilterLength = numel(Coeffs)/UpFactor;
        for k = 0: UpFactor - 1
            SubFilterIndices = 1 + (0:MaxSubFilterLength-1)*UpFactor + k;
            if Variant == "SharcPlus"
                SubFilterIndices = flip(SubFilterIndices);
            end
            CoeffsSim(SubFilterIndices) = Coeffs(k*MaxSubFilterLength + (1:MaxSubFilterLength));
        end
    otherwise
        CoeffsSim = single(Coeffs);
end
end
