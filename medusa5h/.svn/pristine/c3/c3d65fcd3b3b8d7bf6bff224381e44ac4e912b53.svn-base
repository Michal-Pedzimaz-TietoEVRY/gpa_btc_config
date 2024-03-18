function HoligramEQConfig = MedusaHoligramEQInit(MedusaParams)
    % Get build params
    decimationFactor = MedusaParams.decimation;
    firLength = MedusaParams.holigramDecFIRLengthAvg;           % max average fir length => determine size of hybrid EQ FIR states
    firLengthMax = MedusaParams.holigramDecFIRLengthMax;        % max absolute fir length => determine size of hybrid EQ delay line
    sosStagesDR = MedusaParams.holigramDecMaxNumStages;         % max IIR sos stages for decimated-rate
    sosStagesFR =  MedusaParams.holigramFullMaxNumStages;       % max IIR sos stages for full-rate
    frameSize = MedusaParams.frameSize/decimationFactor;        % 8 for DR
    frameSizeFR = MedusaParams.frameSize;                       % 32 for FR
    numLRpair = MedusaParams.numLeftRightPairs;                 % number of LR pairs
    numCenter = MedusaParams.numCenterChannels;                 % number of Center channels
    numSurround = MedusaParams.numSurroundChannels;             % number of Surround channels
    linksPerSpkrPair = MedusaParams.holigramEQLinkPerSpeaker;   % number of EQ links per speaker
    splitBassComp = MedusaParams.splitPremixBassComp;           % Indicates split for premix bass component
    useAccel = MedusaParams.useAcceleratorForHoligramEQ;        % 0 - Core, 1 - Accel, 2 - Generic
    numHeadrestVLS = MedusaParams.numHeadrestVLS;               % number of supported headrest pairs
    numOverheadSpkrPairs = MedusaParams.numOverheadSpeakerPairs;% number of supported overhead speaker pairs
    
    % Error check for bass component split flag
    if(splitBassComp ~=0)
        splitBassComp = 1;
    end
    
    % Config parameters
    % L/R Premix output components: Lofront, Lorear, Lsfront, Lsrear, Lsrfront, 
    % Lsrrear, Lbass (front & rear), Rofront, Rorear, Rsfront, Rsrear, Rsrfront,
    % Rsrrear, Rbass (front & rear)
    if(linksPerSpkrPair == 8)
        numPremixLRComp = (1-splitBassComp)*14 + splitBassComp*16;
    elseif(linksPerSpkrPair == 6)
        numPremixLRComp = 12;                       % Minus Lbass/Rbass components
    else
        error('Current Medusa only supports 6 or 8 EQ links per speaker');
    end
    
    numInput = numCenter + numSurround + numPremixLRComp;
    
    % Derive other block params
    numCS = numCenter + numSurround;
    numEQlink = numLRpair * linksPerSpkrPair + numCS; 
    
    % TODO: Figure out how to error out at build time.
    % numOutput determines the number of outputs for peripheral DR Hybrid Holigram EQ block
    numOutput = numLRpair * 2 + numCS;
    % numSpkrOutput is used by the PoolIIR mask to determine the size of the
    % codeWorkSize buffer during code generation, so it must include all 
    % speaker pairs.
    numSpkrOutput = numOutput + 2*(numOverheadSpkrPairs + numHeadrestVLS);

    if useAccel == 0
        totalBufferSize = (firLength + frameSize) * numInput; % total memory allocated for FIR states
    else
        totalBufferSize = (firLength + frameSize - 1) * numInput; % total memory allocated for FIR states
    end
    
    % Configure variant select for FIR and IIR
    variantFIR = useAccel;
    variantIIR = useAccel;
    
    % Init for DR pooliir
    DRIIR.sos = [1 0 0 1 0 0];
    DRIIR.numStages = size(DRIIR.sos, 1) * ones(1,numEQlink);
    DRIIR.coeffs = repmat(DRIIR.sos, numEQlink, 1);
    DRIIR.maxNumStages = sosStagesDR * numEQlink;
    
    % Init for FR pooliir
    FRIIR.sos = [1 0 0 1 0 0];
    FRIIR.numStages = size(FRIIR.sos, 1) * ones(1,numSpkrOutput);
    FRIIR.coeffs = repmat(FRIIR.sos, numSpkrOutput, 1);
    FRIIR.maxNumStages = sosStagesFR * numSpkrOutput;
    
    % Delay line length depends  on the max absolute FIR length, as we
    % always delay by the max samples per input and tape out at different
    % points based on the actual delay amount per EQ link in order to share
    % delay states for EQ links sharing the same input.
    fixedDelayLength = int32(firLengthMax + frameSize);  
    
    % Define hybrid EQ default values
    inputMappingDefault = [(0:1:numInput-1)'; zeros(numEQlink-numInput, 1)];
    outputMappingDefault = (0:1:numOutput-1)';
    flippedPassThruCoeffs = repmat([zeros(firLength-1,1); 1], numOutput, 1);
    zeroCoeffs = repmat(zeros(firLength,1), numEQlink - numOutput, 1);
    firCoeffsDefault = vertcat(flippedPassThruCoeffs, zeroCoeffs);
    
    % Define code gen attributes for Hybrid EQ "states"
    bufferAlias = "DelayBuffer";
    headerFilename = "MedusaHoligramEQ";
    
    HoligramEQConfig = struct('frameSize', frameSize,...
                              'frameSizeFR', frameSizeFR, ...
                              'numEQlink', numEQlink,...
                              'numInput', numInput,...
                              'numOutput', numOutput,...
                              'numSpkrOutput', numSpkrOutput,...
                              'firLength', firLength,...
                              'fixedDelayLength', fixedDelayLength,...
                              'totalBufferSize',  totalBufferSize,...
                              'DRIIR', DRIIR,...
                              'FRIIR', FRIIR,...
                              'variantFIR', variantFIR,...
                              'variantIIR', variantIIR,...
                              'inputMappingDefault', inputMappingDefault,...
                              'outputMappingDefault', outputMappingDefault,...
                              'firCoeffsDefault', firCoeffsDefault,...
                              'bufferAlias', bufferAlias,...
                              'headerFilename', headerFilename);  
end