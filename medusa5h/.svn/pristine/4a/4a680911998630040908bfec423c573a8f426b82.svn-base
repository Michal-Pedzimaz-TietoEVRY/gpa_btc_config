function VLSGenConfig = VLSGenInit(MedusaParams, firalias)
    % Get build params
    decimationFactor = MedusaParams.decimation;
    firLengthTail = MedusaParams.vlsTailFilterLength;  
    firLengthImpulse = MedusaParams.vlsImpulseFilterLength;
    frameSize = MedusaParams.frameSize/decimationFactor;  % 8 for DR
    useAccel = MedusaParams.useAcceleratorForVLSGen;  % 0 - Core, 1 - Accel, 2 - Generic
    dspTarget = MedusaParams.DspTarget;
    numFilters = 20;
    maxTotalFirLength = firLengthTail*10 + firLengthImpulse*10;
   
    % Total memory allocated for FIR states
    % Because of state sharing between filters, the total number of buffers
    % is (4 Le/Re pairs + 2 center) x impulse/tail. 
    if useAccel == 0
        totalBufferSize = (firLengthTail + frameSize)*6 + (firLengthImpulse + frameSize)*6; 
    else
        totalBufferSize = (firLengthTail + frameSize - 1)*6 + ...
            (firLengthImpulse + frameSize - 1)*6;  
    end
    
    % Configure variant select for FIR and IIR
    variantFIR = useAccel;
    
    % Configure Le/Re selector for Binaural Sum
    % This needs to match the FIR channel order in Symfun
    LeIdx = [1:2:16 17 18]; % Lo imp/tail, Ro imp/tail, Ls imp/tail, Rs imp/tail, Lsr imp/tail
    ReIdx = [2:2:16 19 20]; % Lo imp/tail, Ro imp/tail, Ls imp/tail, Rs imp/tail, Rsr imp/tail
    
    % Define hybrid EQ default values
    firLengthAvg = floor((firLengthTail + firLengthImpulse)/2);
    firLengthsDefault = firLengthAvg * ones(numFilters, 1);
    firCoeffsGainsDefault = ones(numFilters,1);
    firCoeffsDefault = flip(upsample(firCoeffsGainsDefault,firLengthAvg));

    Fir = FirConfig;
    Fir.NumOutputs = numFilters;
    Fir.NumInputs = 6 + 6;
    Fir.FrameSize = frameSize;
    %Fir.NumTaps = firLengthAvg;
    Fir.MaxAvgCoeffLength = firLengthAvg;
    Fir.Alias = firalias;
	Fir.SelectVariant(dspTarget);

    VLSGenConfig = struct('frameSize', frameSize,...
                          'numFilters', numFilters,...
                          'maxTotalFirLength', maxTotalFirLength,...
                          'totalBufferSize',  totalBufferSize,...
                          'variantFIR', variantFIR,...
                          'LeIdx', LeIdx, ...
                          'ReIdx', ReIdx, ...
                          'firCoeffsDefault', firCoeffsDefault,...
                          'firLengthsDefault', firLengthsDefault,...
                          'Fir', Fir);

end