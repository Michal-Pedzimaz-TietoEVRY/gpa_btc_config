function [PremixConfig, PremixTune] = MedusaPremixInit(tuneFileName,...
    headrestTuneFileName, overheadTuneFileName, MedusaParams)
%#codegen
    %% Init script for MedusaPremix block
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.sampleRate                 : Sample rate (at full rate, in Hz)
    %   MedusaParams.decimation                 : Decimation factor
    %   MedusaParams.frameSize                  : Frame Size (for full rate, in samples)
    %   MedusaParams.numCenterChannels          : Number of Center Output Channels
    %   MedusaParams.numSurroundChannels        : Number of Surround Output Channels
    %   MedusaParams.holigramEQLinkPerSpeaker   : Number of Left and Right Output Channels
    %   MedusaParams.includePremixCAE           : Indicates CAE support for Premix
	%   MedusaParams.splitPremixBassComp        : Indicates split for premix bass component
    %   MedusaParams.include_surround_input     : Indicates 5.1 input support
    %   MedusaParams.numHeadrestVLS             : Number of Headrest Left and Right Output Channels
    %   MedusaParams.numOverheadSpeakerPairs    : Number of Overhead Left and Right Output Channels
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   PremixConfig : config struct to interface with library block 
    %   PremixTune   : tune struct to interface with library block
    %% 
    
    % Load default tune values into PremixTune struct
    PremixTune = MedusaPremixTuneInit(tuneFileName, headrestTuneFileName, overheadTuneFileName, MedusaParams);

    % Extracting necessary parameters from MedusaParams
    sampleRate = MedusaParams.sampleRate;
    decimationFactor = MedusaParams.decimation;
    frameSize = MedusaParams.frameSize;
    numCenterOut = MedusaParams.numCenterChannels;
    numSurroundOut = MedusaParams.numSurroundChannels;
    numEQLinks = MedusaParams.holigramEQLinkPerSpeaker;
    includesSurroundInput = MedusaParams.include_surround_input;
    includeCAE = MedusaParams.includePremixCAE;
    splitBassComp = MedusaParams.splitPremixBassComp;
    numHeadrestVLS = MedusaParams.numHeadrestVLS;
    numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;
    
    % Computing necessary premix algorithmic parameters
    sample_rate_in_hertz = sampleRate/decimationFactor;
    frame_size = frameSize/decimationFactor;
	if(splitBassComp ~=0)
        splitBassComp = 1;
    end
    
    % Other model parameters
    rgain_SILENT_GAIN = eps('single');                      % Minimum gain when ramping from zero (could be changed to its sqrt)
    internal_granularity = [0 128 255];                     % Surround index values at anchor points
    
    % Number of I/O left and right channels
    LR_in = 7;
    if (numEQLinks == 6)
            LR_out = 6;                                     % Without Bass Output (H6 configuration)
            numOverheadComps = 6;
    else
            LR_out = (1-splitBassComp)*7 + splitBassComp*8;         % With Bass Output (H8 configuration)
            numOverheadComps = (1-splitBassComp)*7 + splitBassComp*8;
    end
    if (numHeadrestVLS ~= 0)
        LR_out = LR_out + 3;                                        % Add 3 more headrest component LR pairs
    end
    if (numOverheadSpkrs ~= 0)
        LR_out = LR_out + numOverheadComps;                         % Add overhead component LR pairs
    end                                                     

    % Number of Center-Surround channels
    CS_out = numCenterOut + numSurroundOut;                 % Number of center and surround output channels
    CS_in = 10;                                             % Number of inputs for CS processing
    
    % Number of total outputs
    NumPremixOut = LR_out*2 + CS_out;
    
    % Include discrete input components for 5.1 processing
    if(includesSurroundInput)
        LR_in = LR_in + 2;                                          % Two additional discrete inputs (Lsi/Rsi and Csi)
        CS_in = CS_in + 3;                                          % Three additional discrete inputs (Lsi, Rsi and Csi)
    end
    
    % Number of tail components
    numTailComp = struct();
    numTailComp.LR = 3;    numTailComp.CS = 2;

    % Initial mixing gains
    initLeftGain = PremixTune.detentGain_Left(:, 1:LR_in);
    initCsGain = PremixTune.detentGain_CS(:, 1:CS_in);
    initRightGain = PremixTune.detentGain_Right(:, 1:LR_in);
    
    % Constructing the PremixConfig struct
    PremixConfig = struct('sample_rate_in_hertz', sample_rate_in_hertz, ...
                          'frame_size', frame_size, ...
                          'rgain_SILENT_GAIN', rgain_SILENT_GAIN, ...
                          'granularity', internal_granularity, ...
                          'LR_in', LR_in, 'LR_out', LR_out, ...
                          'CS_in', CS_in, 'CS_out', CS_out, ...
                          'NumCenterOut', numCenterOut, ...
                          'NumSurroundOut', numSurroundOut, ...
                          'NumTailComp', numTailComp, ...
                          'NumPremixOut', NumPremixOut, ...
                          'numOverheadComps', numOverheadComps, ...
                          'includesSurroundInput', includesSurroundInput, ...
                          'includeCAE', includeCAE, ...
                          'initLeftGain', initLeftGain, ...
                          'initCsGain', initCsGain, ...
                          'initRightGain', initRightGain);
                      
end