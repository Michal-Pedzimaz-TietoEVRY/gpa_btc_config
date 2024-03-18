function HeadrestDelayConfig = HeadrestDelayInit(MedusaParams)
    
    % Extracting necessary parameters from Medusa Config file
    sampleRate = MedusaParams.sampleRate;
    decimationFactor = MedusaParams.decimation;
    frameSizeFR = MedusaParams.frameSize;
    maxFullRateEQDelay = MedusaParams.maximumFullrateEQDelayInSamples;
    maxSpkrDelay = MedusaParams.maximumOutputDelayInSamples;
    numCenterChannels = MedusaParams.numCenterChannels;
    numSurroundChannels = MedusaParams.numSurroundChannels;
    numLeftRightChannels = MedusaParams.numLeftRightPairs;
    numHeadrestVLS = MedusaParams.numHeadrestVLS;
    numHeadrestComps = MedusaParams.numHeadrestComps; % number of headrest components
    numOverheadSpkrPairs = MedusaParams.numOverheadSpeakerPairs; % number of overhead speaker pairs
    
    frameSizeDR = frameSizeFR/decimationFactor;
    
    % Number of Channels
    numHRCompsChannels = MedusaParams.numHeadrestComps;
    numNonHRChannels = numCenterChannels + numSurroundChannels + 2*numLeftRightChannels + 2*numOverheadSpkrPairs;
    % DR delay channels = non-headrest speakers + headrest components
    numDRChannels = numNonHRChannels + numHRCompsChannels*numHeadrestVLS; 
    % FR delay channels = non-headrest speakers + headrest speakers
    numFRSpkrChannels = numNonHRChannels + 2*numHeadrestVLS;
    
    % Compute max delays  
    maxFREQDelay = int32(round(maxFullRateEQDelay));
    maxFRSpkrDelay = int32(ceil(maxSpkrDelay/decimationFactor)*decimationFactor); 
    maxDRSpkrDelay = maxFRSpkrDelay/decimationFactor;
    
    % Default Values for Tune TOPs
    DRNonHRDelay = zeros(1,numNonHRChannels); 
    FRSpkrDelay = zeros(1,numFRSpkrChannels);
    
    % Header file name and delay buffer alias
    delayHeaderFile = 'MedusaDelays';
    FRSpkrDelayAlias = 'FRSpeakerDelay';
    DRSpkrDelayAlias = 'DRSpeakerDelay';
    
    % Generating the struct for Delay Configuration
    HeadrestDelayConfig = struct('sampleRate', sampleRate, ...
                                 'frameSizeFR', frameSizeFR, ...
                                 'frameSizeDR', frameSizeDR, ...
                                 'DEC', decimationFactor, ...
                                 'maxFREQDelay', maxFREQDelay, ...
                                 'maxDRSpkrDelay', maxDRSpkrDelay, ...
                                 'maxFRSpkrDelay', maxFRSpkrDelay, ...
                                 'DRNonHRDelay', DRNonHRDelay, ...
                                 'FRSpkrDelay', FRSpkrDelay, ...
                                 'numHeadrestComps', numHeadrestComps,...
                                 'numDRChannels', numDRChannels, ...
                                 'numFRSpkrChannels', numFRSpkrChannels, ...
                                 'delayHeaderFile', delayHeaderFile, ...
                                 'FRSpkrDelayAlias', FRSpkrDelayAlias, ...
                                 'DRSpkrDelayAlias', DRSpkrDelayAlias); 

end