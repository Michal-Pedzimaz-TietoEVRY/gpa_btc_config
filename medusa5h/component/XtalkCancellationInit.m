function [XtalkCancellationConfig] = XtalkCancellationInit(MedusaParams)   
    %% Init script for XtalkCancellation block
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.sampleRate : Sample rate (at full rate, in Hz)
    %   MedusaParams.decimation : Decimation factor
    %   MedusaParams.frameSize  : Frame Size (for full rate, in samples)
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   XtalkCancellationConfig : config struct to interface with library block 
    %%     
    % Get build params
    decimationFactor = MedusaParams.decimation;
    frameSize = MedusaParams.frameSize/decimationFactor;
    numHeadrests = MedusaParams.numHeadrestVLS * 2;
    numFilterPerSpkr = numHeadrests; % by design of MxM cross array
    numFilters = numHeadrests * numFilterPerSpkr;
    % Max num stages = 4 speakers x (18 for straight path + 16 for cross seat + 13 cross-car x 2)
    maxNumStages = MedusaParams.xtalkMaxNumStagesPool;    
    % Max delay pool = 4 speakers x (0 for straight path + 20 for cross seat 
    % + 50 for cross-car near side + 80 for cross-car far side)
    maxDelayPool = MedusaParams.xtalkMaxDelayPool; 
    
    % Init for DR pooliir
    if numFilters == 16 %4x4 cross array
        gains = [1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1]'; % only enable straight path
    else
        gains = ones(numFilters,1);
    end
    IIR.sos = [1 0 0 1 0 0];
    %IIR.sos = repmat([0.25 0 0 1 0 0], 15, 1); % for profiling
    IIR.numStages = size(IIR.sos, 1) * ones(1,numFilters);
    IIR.coeffs = repmat(IIR.sos, numFilters, 1);
    IIR.coeffs(:,1) = IIR.coeffs(:,1) .* gains;
    IIR.maxNumStages = maxNumStages;
    
    % Define delay default values
    delayDefault = zeros(numFilters,1);
    
    % Constructing the PremixConfig struct
    XtalkCancellationConfig = struct('IIR', IIR, ...
                                     'numFilters', numFilters, ...
                                     'numHeadrests', numHeadrests,...
                                     'numFilterPerSpkr', numFilterPerSpkr,...
                                     'frameSize', frameSize, ...
                                     'maxDelayPool', maxDelayPool,...
                                     'delayDefault', delayDefault);
                               
end
