function delayBufferInitVal = CalcDelayBufferInitVal(maxDelay, frameSize, numChannels)
%#codegen
% Computes the initial value of the alignment delay buffer
delayBufferSize = (maxDelay + frameSize)*numChannels;
delayBufferInitVal = zeros(delayBufferSize, 1, 'single');
end