function y = FirGenericProcessSim(u, coeffs, stateSize, filterLengths, ...
                inputMapping, filterMapping, frameSize, numOutputs, Variant)
if nargin < 9
    Variant = "Generic";
end

% Apply Flipping of Coefficients for Simulation if not already flipped
switch(Variant)
    case{'Generic','Hexagon'}
        coeffs = FlipCoefficients(coeffs, filterLengths);
end

y = zeros(frameSize,numOutputs,class(u));
numCoeffSets = numel(filterLengths);

% Matlab value objects are passes by value, so 'states' is only used to
% trigger CRL. Another buffer is created here with the same size to
% actually save the states between function calls.
persistent states2;
if isempty(states2)
    states2 = single(zeros(stateSize,1));
end

% Calculate filter offsets from filter lengths
persistent filterOffsets;
if isempty(filterOffsets)
    filterOffsets = uint32(ones(numCoeffSets,1));
    currIndex = uint32(1);
    for OutputIndex = 2:numCoeffSets
        currIndex = filterLengths(OutputIndex-1) + currIndex;
        filterOffsets(OutputIndex,1) = currIndex;
    end
end

% Calculate state offsets from filter lengths and filter mapping. In Matlab
% state has size [fitler length - 1], not [filter length + frame size - 1],
% so the stateOffsets here is different than the one derived in CRL.
persistent stateOffsets;
if isempty(stateOffsets)
    % Initiate State Buffer Offset Array
    stateOffsets = uint32(ones(numOutputs,1));
    % Get the index of the filter for all but the last output
    FilterIndices = filterMapping(1:numOutputs-1);
    % Get the filter length for each filter
    FilterLengths = filterLengths(FilterIndices + 1);
    % Get state size from filter length
    StateSizes = FilterLengths-1;
    % stateOffset(filter[i+1]) = stateOffset(filter[i]) + Len(filter[i])-1
    stateOffsets(2:numOutputs,1) = uint32(cumsum(StateSizes) + 1);
end

statesTemp = states2; % temp state buffer
for OutputIndex = 1:numOutputs
    % Get input 
    inputIdx = inputMapping(OutputIndex)+1;  % add 1 for Matlab indexing
    input = u(:, inputIdx);      

    % Get filter coefficients
    coeffIdx = filterMapping(OutputIndex)+1; % add 1 for Matlab indexing
    coeffOffset = filterOffsets(coeffIdx); % offsets already defined in Matlab as one-based
    coeffLength = filterLengths(coeffIdx);
    coeff = coeffs(coeffOffset: (coeffOffset + coeffLength - 1));

    % Get state pointer
    stateOffset = stateOffsets(OutputIndex);
    state = states2(stateOffset : stateOffset+coeffLength-2);

    [y0, state] = FirFilter(coeff, input, state);
    y(:, OutputIndex) = y0;
    
    % Update Temp state vector
    statesTemp(stateOffset:stateOffset+coeffLength-2) = state;

end

% Update state buffer 
states2 = statesTemp;
end

function FlippedCoeffs = FlipCoefficients(Coeffs, CoeffsLengths)
FlippedCoeffs = zeros(size(Coeffs),class(Coeffs));
CoeffsOffset = 1;
for idx = 1:numel(CoeffsLengths)
    Length = double(CoeffsLengths(idx));
    FlippedCoeffs(CoeffsOffset: CoeffsOffset + Length - 1) = flip(Coeffs(CoeffsOffset : CoeffsOffset + Length - 1));
    CoeffsOffset = CoeffsOffset + Length;

    if(CoeffsOffset >= numel(Coeffs))
         CoeffsOffset = 1;  
    end
end
end