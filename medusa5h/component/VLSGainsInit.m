function [VLSGainsTune, VLSGainsConfig] = VLSGainsInit(MedusaParams, ...
    VLSGainsTuneFileName)   
    %% Init script for VLSGains block
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.sampleRate : Sample rate (at full rate, in Hz)
    %   MedusaParams.decimation : Decimation factor
    %   MedusaParams.frameSize  : Frame Size (for full rate, in samples)
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   VLSGainsConfig : config struct to interface with library block 
    %   VLSGainsTune   : tune struct to interface with library block
    %% 
    
    % Load default tune values into VLSGainsTune struct
    VLSGainsTune = load(VLSGainsTuneFileName);
    
    % Extracting necessary parameters from MedusaParams
    sampleRate = MedusaParams.sampleRate;
    decimationFactor = MedusaParams.decimation;
    frameSize = MedusaParams.frameSize;
    
    % Computing the decimated sample rate and frame size
    sample_rate_in_hertz = sampleRate/decimationFactor;
    frame_size = frameSize/decimationFactor;
    
    % Other model parameters
    rgain_SILENT_GAIN = eps('single');                  % Minimum gain when ramping from zero (could be changed to its sqrt)
    internal_granularity = [0 128 255];                 % Surround index values at anchor points
    
    % Number of gain elements
    numHeadrestComps = MedusaParams.numHeadrestComps;   % number of components per headrest pair
    numHeadrestVLS = MedusaParams.numHeadrestVLS;       % number of supported headrest pairs
    numGains = uint32(numHeadrestComps * numHeadrestVLS);
    
    % Constructing the PremixConfig struct
    VLSGainsConfig = struct('sample_rate_in_hertz', sample_rate_in_hertz, ...
                            'frame_size', frame_size, ...
                            'rgain_SILENT_GAIN', rgain_SILENT_GAIN, ...
                            'granularity', internal_granularity, ...
                            'numGains', numGains);
                               
end
