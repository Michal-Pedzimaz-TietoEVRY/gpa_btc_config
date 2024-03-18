function HeadrestCompEQConfig = HeadrestCompEQInit(MedusaParams)
    % Get build params
    decimationFactor = MedusaParams.decimation;
    firLength = MedusaParams.headrestCompEQFIRLengthMax;   % max fir length => determine size of hybrid EQ FIR states
    sosStagesDR = MedusaParams.headrestCompEQMaxNumStages; % max IIR sos stages for decimated-rate
    frameSize = MedusaParams.frameSize/decimationFactor;   % 8 for DR
    useAccel = MedusaParams.useAcceleratorForHeadrestCompEQ; % 0 - Core, 1 - Accel, 2 - Generic   
    numInput = MedusaParams.numHeadrestComps;              % number of headrest components
    numHeadrestVLS = MedusaParams.numHeadrestVLS;          % number of supported headrest pairs
    numEQlink = numInput * numHeadrestVLS;
    dspTarget = MedusaParams.DspTarget;

    if useAccel == 0
        totalBufferSize = (firLength + frameSize) * numInput; % total memory allocated for FIR states
    else
        totalBufferSize = (firLength + frameSize - 1) * numInput; % total memory allocated for FIR states
    end
    
    % Configure variant select for FIR and IIR
    variantFIR = useAccel;
    variantIIR = useAccel;
    
    % Init for DR pooliir
    %DRIIR.sos = repmat([1 0 0 1 0 0], 20, 1); % for profiling
    DRIIR.sos = [1 0 0 1 0 0];
    DRIIR.numStages = size(DRIIR.sos, 1) * ones(1,numEQlink);
    DRIIR.coeffs = repmat(DRIIR.sos, numEQlink, 1);
    DRIIR.maxNumStages = sosStagesDR * numEQlink;
    
    % Delay line length depends  on the max absolute FIR length, as we
    % always delay by the max samples per input and tape out at different
    % points based on the actual delay amount per EQ link in order to share
    % delay states for EQ links sharing the same input.
    fixedDelayLength = int32(firLength + frameSize);  
    
    % Define hybrid EQ default values
    firCoeffsDefault = repmat([zeros(firLength-1,1); 1], numEQlink, 1);
    
    % Input mapping 
    % This is the hardcoded zero-based input order for BOTH Simulink and 
    % Symfun headrest EQ routing 
    inputMapping = repmat(0:numInput-1,1,numHeadrestVLS);

    FirHr = FirConfig;
    FirHr.NumOutputs = numEQlink;
    FirHr.NumInputs = numInput;
    FirHr.FrameSize = frameSize;
    FirHr.MaxAvgCoeffLength = firLength;
    FirHr.Alias = 'DrHeadrestFirEq';
	
	%@SSC-TODO
	FirHr.SelectVariant(dspTarget);
    %FirHr.SelectVariant('Hexagon');
    
    HeadrestCompEQConfig = struct('frameSize', frameSize,...
                                  'numEQlink', numEQlink,...
                                  'numInput', numInput,...
                                  'firLength', firLength,...
                                  'fixedDelayLength', fixedDelayLength,...
                                  'totalBufferSize',  totalBufferSize,...
                                  'DRIIR', DRIIR,...
                                  'variantFIR', variantFIR,...
                                  'variantIIR', variantIIR,...
                                  'firCoeffsDefault', firCoeffsDefault,...
                                  'inputMapping', inputMapping,...
                                  'Fir', FirHr);  
end