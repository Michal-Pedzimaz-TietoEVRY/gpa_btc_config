function MSConfig = MedusaMSInit(MedusaParams)
    %% Init script for MedusaMonoSurround block
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.sampleRate : Sample rate (at full rate, in Hz)
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   MSConfig : config struct to interface with library block 
    %% 
  
    % Extracting necessary parameters from MedusaParams
    sampleRate = MedusaParams.sampleRate;
    DEC = MedusaParams.decimation;
    %poolIirVariant = MedusaParams.variant;
    poolIirVariant = MedusaParams.DspTarget;
    
    % Defining parameters for Hilbert Pair generation
    fL = 100;               % Lowest frequecy of interest
    fH = 5000;              % Highest frequency of interest
    ripple_deg = 0.3;       % Maximum allowable phase difference deviation
    Fs = sampleRate/DEC;    % Decimated sampling rate in Hz
    
    % Generate Hilbert Pair SOS
    [sos0, sos90] = hilbpair(fL*2*pi/Fs,fH* 2*pi/Fs,ripple_deg*pi/180);
    
    % Parameters for Hilbert Filtering
    numChannels = 1;        % Only the 'Surround' channel is processed always
    maxNumStages = 5;       % One SOS stage for one channel
    
    % Generate Hilbert Pair Coefficients
    numStages = size(sos0, 1) * ones(1, numChannels);
    rawSOSA = repmat(sos0, numChannels, 1);     % Fix it to one audio channel
    [hilbPairNumStagesA, hilbPairCoeffsA] = pooliirTranslation(rawSOSA, numStages, maxNumStages);
    
    numStages = size(sos90, 1) * ones(1, numChannels);
    rawSOSB = repmat(sos90, numChannels, 1);     % Fix it to one audio channel
    [hilbPairNumStagesB, hilbPairCoeffsB] = pooliirTranslation(rawSOSB, numStages, maxNumStages);
    
    
    % Default Value for Tunable Parameter in Mono-Surround
    DefaultPhaseAngle = 180;   % Angle 'phi' for controlling amount of right mixing
    
    % Constructing the MSConfig struct                  
    MSConfig = struct('hilbPairNumStagesA', hilbPairNumStagesA, ...
                      'hilbPairCoeffsA', hilbPairCoeffsA, ...
                      'hilbPairNumStagesB', hilbPairNumStagesB, ...
                      'hilbPairCoeffsB', hilbPairCoeffsB, ...
                      'maxNumStages', maxNumStages, ...
                      'DefaultPhaseAngle', DefaultPhaseAngle, ...
                      'variant', poolIirVariant);
                     
end

function [PoolNumStages, PoolCoeffs] = pooliirTranslation(rawSOS, numStages, maxNumStages)

RawSOS = rawSOS;
NumStages = int32(numStages);
NumChannels = length(NumStages);

MaxNumStages = maxNumStages; 
PoolNumStages = int32(zeros(NumChannels,1));
PoolCoeffs = single(zeros(MaxNumStages * 4 + NumChannels,1));
ChannelCoeffs = zeros(MaxNumStages * 4 + 1,1);
ChannelSOS = single(zeros(MaxNumStages, 6));
SOSIndex = int32(0);

for i = 1:NumChannels
    
    ChannelNumStages = NumStages(i);   % Size of current SOS
    assert(ChannelNumStages <= MaxNumStages);
    
    if (ChannelNumStages == 0)
        continue;
    end
    
    ChannelSOS(1:ChannelNumStages,:) = RawSOS(SOSIndex+(1:ChannelNumStages),:);
    SOSIndex = SOSIndex + ChannelNumStages;

    if size(ChannelSOS,2) ~= 6
        TranslateError('SOS matrix must have 6 columns');
    end
    % decompose SOS
   
    ts = 1:4:4*ChannelNumStages;
    ChannelCoeffs(1,1) = prod(ChannelSOS(1:ChannelNumStages,1));        % b0
    
    % the remaining coeffs are compacted forms of the biquads
    ChannelCoeffs(1+ts,1) = ChannelSOS(1:ChannelNumStages,6);           % a2
    ChannelCoeffs(2+ts,1) = ChannelSOS(1:ChannelNumStages,5);           % a1
    if( ChannelSOS(:,1) == 0 )
    ChannelCoeffs(3+ts,1) = 0;                 % b2/b0
    ChannelCoeffs(4+ts,1) = 0;                 % b1/b0
    else
    ChannelCoeffs(3+ts,1) = ...
        ChannelSOS(1:ChannelNumStages,3)./ ...
        ChannelSOS(1:ChannelNumStages,1);  % b2/b0
    ChannelCoeffs(4+ts,1) = ...
        ChannelSOS(1:ChannelNumStages,2)./ ...
        ChannelSOS(1:ChannelNumStages,1);  % b1/b0
    end
    
    % length of Cuurent Channel Coeffs   
    ChannelCoeffsLength = 1+4*ChannelNumStages;
    
    % Offset into coefficient array for the current channel
    offset = (i-1)+4*sum(PoolNumStages(1:i-1));
    
    % Verify that the SOS does not violate the maximum number of stages
    % allocated for the pool
    PoolNumStages(i) = int32(ChannelNumStages);
    if (sum(PoolNumStages) > MaxNumStages)
        TranslateError('Too many second order sections');
    end

    % Store the coefficients
    PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength));   
end

end