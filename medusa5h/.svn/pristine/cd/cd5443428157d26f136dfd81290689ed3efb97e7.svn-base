function [FRMConfig, FRMTune] = MedusaFullRateMixerInit(tuneFileName, ...
    headrestTuneFileName, overheadTuneFileName, MedusaParams)
%#codegen
    %% Init script for MedusaFullRateMixer block
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.sampleRate                 : Sample rate (at full rate, in Hz)
    %   MedusaParams.frameSize                  : Frame Size (for full rate, in samples)
    %   MedusaParams.numCenterChannels          : Number of Center Output Channels
    %   MedusaParams.numSurroundChannels        : Number of Surround Output Channels
    %   MedusaParams.numLeftRightPairs          : Number of Left and Right Output Channels
    %   MedusaParams.includePremixCAE           : Indicates CAE support for Full Rate Mixer
    %   MedusaParams.include_surround_input     : Indicates 5.1 input support
    %   MedusaParams.numHeadrestVLS             : Number of Headrest Left and Right Output Channels
    %   MedusaParams.numOverheadSpeakerPairs    : Number of Overhead Left and Right Output Channels
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   FRMConfig : config struct to interface with library block 
    %   FRMTune   : tune struct to interface with library block
    %%
    
    % Load default tune values into FRMTune struct
    FRMTune = MedusaFullRateMixerTuneInit(tuneFileName, headrestTuneFileName, overheadTuneFileName, MedusaParams);
    
    % Extracting necessary parameters from MedusaParams
    sample_rate_in_hertz = MedusaParams.sampleRate;
    frame_size = MedusaParams.frameSize;
    numCenterOut = MedusaParams.numCenterChannels;
    numSurroundOut = MedusaParams.numSurroundChannels;
    numLeftRightOut = MedusaParams.numLeftRightPairs;
    includesSurroundInput = MedusaParams.include_surround_input;
    includeCAE = MedusaParams.includePremixCAE;
    numHeadrestVLS = MedusaParams.numHeadrestVLS;
    numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;

    % Other model parameters
    rgain_SILENT_GAIN = eps('single');              % Minimum gain when ramping from zero (could be changed to its sqrt)
    internal_granularity = [0 128 255];             % Surround index values at anchor points
    LR_out = numLeftRightOut;                       % Number of left and right output channels
    LR_in = 3;                                      % Number of inputs for left and right channels
    CS_out = numCenterOut + numSurroundOut;         % Number of center and surround output channels
    CS_in = 6;                                      % Number of inputs for CS processing
    
    if (numHeadrestVLS ~= 0)
        LR_out = LR_out + numHeadrestVLS;           % Add supported headrest
    end
    if (numOverheadSpkrs ~= 0)
        LR_out = LR_out + numOverheadSpkrs;         % Add overhead LR pairs
    end
    
	if(includesSurroundInput)						% Include discrete input components for 5.1 processing
		LR_in = 5;
		CS_in = 9;
	end
		
    numTailComp = struct();							% Number of tail components
    numTailComp.LR = 1;    numTailComp.CS = 2;
    
    % Constructing the FRMConfig struct
    FRMConfig = struct('sample_rate_in_hertz', sample_rate_in_hertz, ...
                       'frame_size', frame_size, ...
                       'rgain_SILENT_GAIN', rgain_SILENT_GAIN, ...
                       'granularity', internal_granularity, ...
                       'LR_in', LR_in, 'LR_out', LR_out, ...
                       'CS_in', CS_in, 'CS_out', CS_out, ...
                       'NumTailComp', numTailComp, ...
                       'includesSurroundInput', includesSurroundInput, ...
                       'includeCAE', includeCAE);
end