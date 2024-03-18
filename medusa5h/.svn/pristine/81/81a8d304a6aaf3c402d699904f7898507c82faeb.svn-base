function gainStruct = MedusaPremixAddCAEGain(gainStruct, isCS, Config)
% #codegen
% Check whether the input struct contains downmmix weights or mix matrix
numGains = numel(fieldnames(gainStruct));
isDownmixWeight = (numGains==2);        

if(isCS)
    % Determine the indices of weights to be replaced
    ltailIndex = floor(Config.CS_in/2);
    rtailIndex = Config.CS_in;
    
    if(Config.includesSurroundInput)
        ltailIndex = ltailIndex - 1;
        rtailIndex = rtailIndex - 2;
    end
    
    % Replace the corresponding weights
    if(isDownmixWeight)
        gainStruct.downmixWeight(:,[ltailIndex,rtailIndex]) = gainStruct.downmixWeight_CAE;
        
    else
        gainStruct.minGain(:,[ltailIndex,rtailIndex]) = gainStruct.minGain_CAE;
        gainStruct.detentGain(:,[ltailIndex,rtailIndex]) = gainStruct.detentGain_CAE;
        gainStruct.maxGain(:,[ltailIndex,rtailIndex]) = gainStruct.maxGain_CAE;
    end
    
else
    % Determine the indices of weights to be replaced depending
    tailStartIndex = Config.LR_in - Config.NumTailComp.LR + 1;
    tailEndIndex = Config.LR_in;
        
    if(Config.includesSurroundInput)
        tailStartIndex = tailStartIndex - 2;
        tailEndIndex = tailEndIndex - 2;
    end
    
    % Replace the corresponding weights
    if(isDownmixWeight)
        gainStruct.downmixWeight(:,[tailStartIndex:tailEndIndex]) = gainStruct.downmixWeight_CAE;
        
    else
        gainStruct.minGain(:,[tailStartIndex:tailEndIndex]) = gainStruct.minGain_CAE;
        gainStruct.detentGain(:,[tailStartIndex:tailEndIndex]) = gainStruct.detentGain_CAE;
        gainStruct.maxGain(:,[tailStartIndex:tailEndIndex]) = gainStruct.maxGain_CAE;
    end
    
end

end