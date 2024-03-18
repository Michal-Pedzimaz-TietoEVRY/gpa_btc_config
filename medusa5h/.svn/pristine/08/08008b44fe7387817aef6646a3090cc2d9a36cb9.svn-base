function [FRMIdx] = FRMOutputReorder(MedusaParams, FRMConfig)
% This function reorders the indices of Full-rate Mixer output so that the
% headrest speakers are the last 4 outputs: h0l, h0r, h1l, h1r.

numCS = FRMConfig.CS_out;
numLR = FRMConfig.LR_out;
numOut = numCS + numLR*2; % Number of total speaker outputs     
numHeadrestVLS = MedusaParams.numHeadrestVLS;
numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;

if ((numHeadrestVLS ~= 0) && (numOverheadSpkrs ~= 0))
    % Headrest speaker indices
    leftIdxStartHR = numCS + numLR - numHeadrestVLS + 1;
    leftIdxEndHR = leftIdxStartHR + numHeadrestVLS - 1;
    rightIdxStartHR = numOut - numHeadrestVLS + 1;
    rightIdxEndHR = rightIdxStartHR + numHeadrestVLS - 1;
    % Interleave left and right headrest speaker outputs: h0l, h0r, h1l, h1r
    HeadrestIdx = reshape([leftIdxStartHR:leftIdxEndHR; rightIdxStartHR:rightIdxEndHR], 1, []);
    
    % Overhead component indices
    leftIdxStartOH = leftIdxStartHR - numOverheadSpkrs;
    leftIdxEndOH = leftIdxStartOH + numOverheadSpkrs - 1;
    rightIdxStartOH = leftIdxStartOH + numLR;
    rightIdxEndOH = rightIdxStartOH + numOverheadSpkrs - 1;
    OverheadIdx = [leftIdxStartOH:leftIdxEndOH rightIdxStartOH:rightIdxEndOH];
    
    % Peripheral speaker indices
    leftIdxEnd = leftIdxStartOH - 1;
    rightIdxStart = leftIdxEndHR + 1;
    rightIdxEnd = rightIdxStartOH - 1;
    
    % Reorder FRM outputs as followed: all CS, all peripheral left, 
    % all peripheral right, loh0, loh1, roh0, roh1, h01, h0r, h1l, h1r
    % Update FRM Tune Init to match the order presented here
    FRMIdx = [1:leftIdxEnd, rightIdxStart:rightIdxEnd, OverheadIdx, HeadrestIdx];
    
elseif ((numHeadrestVLS == 0) && (numOverheadSpkrs ~= 0))
    % Overhead component indices
    leftIdxStartOH = numCS + numLR - numOverheadSpkrs + 1;
    leftIdxEndOH = leftIdxStartOH + numOverheadSpkrs - 1;
    rightIdxStartOH = leftIdxStartOH + numLR;
    rightIdxEndOH = rightIdxStartOH + numOverheadSpkrs - 1;
    OverheadIdx = [leftIdxStartOH:leftIdxEndOH rightIdxStartOH:rightIdxEndOH];
    
    % Peripheral speaker indices
    leftIdxEnd = leftIdxStartOH - 1;
    rightIdxStart = leftIdxEndOH + 1;
    rightIdxEnd = rightIdxStartOH - 1;
    
    % Reorder FRM outputs as followed: all CS, all peripheral left, 
    % all peripheral right, loh0, loh1, roh0, roh1
    FRMIdx = [1:leftIdxEnd, rightIdxStart:rightIdxEnd, OverheadIdx];
    
elseif ((numHeadrestVLS ~= 0) && (numOverheadSpkrs == 0))
    % Headrest speaker indices
    leftIdxStartHR = numCS + numLR - numHeadrestVLS + 1;
    leftIdxEndHR = leftIdxStartHR + numHeadrestVLS - 1;
    rightIdxStartHR = numOut - numHeadrestVLS + 1;
    rightIdxEndHR = rightIdxStartHR + numHeadrestVLS - 1;
    % Interleave left and right headrest speaker outputs: h0l, h0r, h1l, h1r
    HeadrestIdx = reshape([leftIdxStartHR:leftIdxEndHR; rightIdxStartHR:rightIdxEndHR], 1, []);
    
    % Peripheral speaker indices
    leftIdxEnd = leftIdxStartHR - 1;
    rightIdxStart = leftIdxEndHR + 1;
    rightIdxEnd = rightIdxStartHR - 1;
    
    % Reorder FRM outputs as followed: all CS, all peripheral left, 
    % all peripheral right, h01, h0r, h1l, h1r
    FRMIdx = [1:leftIdxEnd, rightIdxStart:rightIdxEnd, HeadrestIdx];

else
    FRMIdx = 1:numOut;
end

end