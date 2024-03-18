function [HeadrestIdx, OverheadIdx, PeripheralIdx] = PremixOutputSelect(MedusaParams, PremixConfig)
%#codegen
% This function calculates the indices of Headrest and Non-headrest
% components from Premix output

numCS = PremixConfig.CS_out;
numLR = PremixConfig.LR_out;
numHeadrestCompPairs = 3; % fixed by design
numHeadrestVLS = MedusaParams.numHeadrestVLS; 
numOverheadCompPairs = PremixConfig.numOverheadComps;
numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;

if ((numHeadrestVLS ~= 0) && (numOverheadSpkrs ~= 0))
    % Headrest component indices
    leftIdxStartHR = numCS + numLR - numHeadrestCompPairs + 1;
    leftIdxEndHR = leftIdxStartHR + numHeadrestCompPairs - 1;
    rightIdxStartHR = leftIdxStartHR + numLR;
    rightIdxEndHR = rightIdxStartHR + numHeadrestCompPairs - 1;
    % Interleave left and right components to match headrest component EQ 
    % input order: Lo, Ro, Ls, Rs, Lsr, Rsr
    HeadrestIdx = reshape([leftIdxStartHR:leftIdxEndHR; rightIdxStartHR:rightIdxEndHR], 1, []);
    
    % Overhead component indices
    leftIdxStartOH = numCS + numLR - numOverheadCompPairs - numHeadrestCompPairs + 1;
    leftIdxEndOH = leftIdxStartOH + numOverheadCompPairs - 1;
    rightIdxStartOH = leftIdxStartOH + numLR;
    rightIdxEndOH = rightIdxStartOH + numOverheadCompPairs - 1;
    OverheadIdx = [leftIdxStartOH:leftIdxEndOH, rightIdxStartOH:rightIdxEndOH];
    
    % Peripheral component indices
    leftIdxEndPeripheral = leftIdxStartOH - 1;
    rightIdxStartPeripheral = leftIdxEndHR + 1;
    rightIdxEndPeripheral = rightIdxStartOH - 1;    
    PeripheralIdx = [1:leftIdxEndPeripheral, rightIdxStartPeripheral:rightIdxEndPeripheral];
    
elseif ((numHeadrestVLS == 0) && (numOverheadSpkrs ~= 0))
    % Headrest component indices
    HeadrestIdx = ones(numHeadrestCompPairs*2,1); % dummy indices
    
    % Overhead component indices
    leftIdxStartOH = numCS + numLR - numOverheadCompPairs + 1;
    leftIdxEndOH = leftIdxStartOH + numOverheadCompPairs - 1;
    rightIdxStartOH = leftIdxStartOH + numLR;
    rightIdxEndOH = rightIdxStartOH + numOverheadCompPairs - 1;
    OverheadIdx = [leftIdxStartOH:leftIdxEndOH, rightIdxStartOH:rightIdxEndOH];
    
    % Peripheral component indices
    leftIdxEndPeripheral = leftIdxStartOH - 1;
    rightIdxStartPeripheral = leftIdxEndOH + 1;
    rightIdxEndPeripheral = rightIdxStartOH - 1;
    PeripheralIdx = [1:leftIdxEndPeripheral, rightIdxStartPeripheral:rightIdxEndPeripheral];
    
elseif ((numHeadrestVLS ~= 0) && (numOverheadSpkrs == 0))
    % Headrest component indices
    leftIdxStartHR = numCS + numLR - numHeadrestCompPairs + 1;
    leftIdxEndHR = leftIdxStartHR + numHeadrestCompPairs - 1;
    rightIdxStartHR = leftIdxStartHR + numLR;
    rightIdxEndHR = rightIdxStartHR + numHeadrestCompPairs - 1;
    % Interleave left and right components to match headrest component EQ 
    % input order: Lo, Ro, Ls, Rs, Lsr, Rsr
    HeadrestIdx = reshape([leftIdxStartHR:leftIdxEndHR; rightIdxStartHR:rightIdxEndHR], 1, []);
    
    % Overhead component indices
    OverheadIdx = ones(numOverheadCompPairs*2,1); % dummy indices

    % Peripheral component indices
    leftIdxEndPeripheral = leftIdxStartHR - 1;
    rightIdxStartPeripheral = leftIdxEndHR + 1;
    rightIdxEndPeripheral = rightIdxStartHR - 1;
    PeripheralIdx = [1:leftIdxEndPeripheral, rightIdxStartPeripheral:rightIdxEndPeripheral];

else   
    HeadrestIdx = ones(numHeadrestCompPairs*2,1); % dummy indices
    OverheadIdx = ones(numOverheadCompPairs*2,1); % dummy indices
    
    leftIdxEnd = numCS + numLR;
    rightIdxStart = leftIdxEnd + 1;
    rightIdxEnd = rightIdxStart + numLR - 1;
    PeripheralIdx = [1:leftIdxEnd, rightIdxStart:rightIdxEnd];
end

end