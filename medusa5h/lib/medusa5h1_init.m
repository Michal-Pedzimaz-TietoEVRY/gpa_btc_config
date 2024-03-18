% Init script for medusa5h1 feature block
% This script generates MedusaConfig struct for Medusa5H1 block

% Specify files for default tune data, if not present already
if(~exist('MedusaTuneFiles', 'var'))
    MedusaTuneFiles = getMedusaTuneDefaults(sys_defs);
end

% Send an empty struct for sys_defs, if it is not present already
if(~exist('sys_defs', 'var'))
    sys_defs = [];
end

generateMedusaConfig(sys_defs, MedusaTuneFiles);

function generateMedusaConfig(sys_defs, MedusaTuneFiles)
% Generate MedusaConfig struct, which contains config structs for all sub-
% components inside Medusa

    % Extract build time parameters from sys_defs. A default struct is
    % returned if sys_defs is empty
    MedusaParams = getMedusaParams(sys_defs);

    BandSplitConfig = MedusaBandSplitInit(MedusaParams);                    % Band Split
    [DRFDPConfig, FRFDPConfig] = MedusaFDPInit(MedusaParams);               % Upmixers
%    MonoDetectorConfig = MonoDetectorInit(MedusaParams);                    % Mono Detector
%    DelayConfig = MedusaDelayInit(MedusaParams);                            % Delays
    SurroundConfig = MedusaSurroundLevelControlInit;                        % Surround Level Control
    MSConfig = MedusaMSInit(MedusaParams);                                  % Mono Surround
    HoligramEQConfig = MedusaHoligramEQInit(MedusaParams);                  % Holigram EQ
%     OverheadHoligramEQConfig = MedusaOverheadHoligramEQInit(MedusaParams);   % Overhead Holigram EQ
    
    % Store the value of 'include_surround_input' from sys_defs before modification
    IncludeSurroundInput = MedusaParams.include_surround_input;
    
    % Modifying the value of 'include_surround_input' to generate Stereo
    % configs for Premix and Full-rate Mixer
    MedusaParams.include_surround_input = 0;
    [PremixConfig.Stereo, PremixTune.Stereo] = MedusaPremixInit(MedusaTuneFiles.PremixStereo, ...
        MedusaTuneFiles.HeadrestPremix, MedusaTuneFiles.OverheadPremix, MedusaParams);   % Deci-rate Premix Stereo
    [FRMConfig.Stereo, FRMTune.Stereo] = MedusaFullRateMixerInit(MedusaTuneFiles.FRMStereo, ...
        MedusaTuneFiles.HeadrestFRM, MedusaTuneFiles.OverheadFRM, MedusaParams);      % Full-rate Premix Stereo
    [HeadrestIdx, OverheadIdx, PeripheralIdx] = PremixOutputSelect(MedusaParams, PremixConfig.Stereo); 
    FRMOutputIdx = FRMOutputReorder(MedusaParams, FRMConfig.Stereo);
    
    % Modifying the value of 'include_surround_input' to generate 5.1
    % configs for Premix and Full-rate Mixer
    MedusaParams.include_surround_input = 1;
    [PremixConfig.v5h1, PremixTune.v5h1] = MedusaPremixInit(MedusaTuneFiles.Premix5h1, [], [], MedusaParams);  % Deci-rate Premix 5.1
    [FRMConfig.v5h1, FRMTune.v5h1] = MedusaFullRateMixerInit(MedusaTuneFiles.FRM5h1, [], [], MedusaParams);    % Full-rate Premix 5.1
	 
    % Reverting the value 'include_surround_input' to the one in sys_defs
    MedusaParams.include_surround_input = IncludeSurroundInput;
    
    % Number of supported output channels for an application
    % Note: This is not necessarily Medusa speaker outputs, since some
    % outputs can be specified as 'unused' in config.tune
%     numSystemOut = MedusaParams.numSystemOut;
    
    % Number of Medusa output channels
    numLR = 2 * MedusaParams.numLeftRightPairs;
    numCS = MedusaParams.numCenterChannels + MedusaParams.numSurroundChannels;
    numPeripheral = numLR + numCS;                      % number of peripheral speakers
    
    % VLS settings
    numHeadrestComps = MedusaParams.numHeadrestComps;   % number of components per headrest pair
    numHeadrestVLS = MedusaParams.numHeadrestVLS;       % number of supported headrest pairs
    numVLSGains = numHeadrestComps * numHeadrestVLS;    % number of headrest components/ENT gains
    numOverhead = MedusaParams.numOverheadSpeakerPairs; % number of supported overhead pairs
    numNonHeadrest = numPeripheral + numOverhead*2;     % number of non-headrest speakers
    numDRChan = numNonHeadrest + numVLSGains;           % number of DR channels going through Fade/Balance/Mute
    
    numMedusaOut = numPeripheral + numOverhead*2 + numHeadrestVLS*2;   % number of total output speaker
    
    holigramOutputSelect = [1:numDRChan];               % components to be selected from holigram output for further processing
    if(numOverhead == 0)
        headrestStartIdx = numPeripheral + 2;           % skip the dummy overhead output and jump to next output
        headrestEndIdx = headrestStartIdx + numVLSGains - 1;
        holigramOutputSelect = [1:numPeripheral headrestStartIdx:headrestEndIdx];
    end

    % Routing map default
    routingMapDefault = MedusaParams.defaultRoutingMap;
    
    % Wiggle Filters
    numTailComps = 4; % Lftail, Rftail, Lrtail, Rrtail
    wiggleFilterLength = MedusaParams.wiggleFilterLength;
    wiggleFilterDefault = [ones(1,numTailComps); zeros(wiggleFilterLength-1,numTailComps)];
    
    % XXX: FirEven was updated to it's BTC compliant implementation as 
    % the old implementation was removed during the upgrade. While not
    % ideal in the general case, this construction for how medusa was 
    % historically used will suffice for now, but should be removed as
    % Medusa continues to work towards BTC compliance.
    TailCompFirEvenSettings = FirEvenConfig();    
    variant = MedusaParams.DspTarget;
    if(startsWith(variant, {'SharcPlusCore', 'SharcPlusAccelGul'}))
        variant = 'SharcPlus';
    end

    %@SSC-TODO
    TailCompFirEvenSettings.SelectVariant(variant);
    TailCompFirEvenSettings.Alias = 'MedusaExpandTailWiggle';
    TailCompFirEvenSettings.MaxAvgCoeffLength = wiggleFilterLength; 
    TailCompFirEvenSettings.NumOutputs = numTailComps;
    TailCompFirEvenSettings.FrameSize = MedusaParams.frameSize / MedusaParams.decimation;

    % Tail Component EQs
    maxStagesTailCompEQ = 10;
    tailCompEQ.sos = [1 0 0 1 0 0];
    tailCompEQ.numStages = size(tailCompEQ.sos, 1) * ones(1,numTailComps);
    tailCompEQ.coeffs = repmat(tailCompEQ.sos, numTailComps, 1);
    tailCompEQ.maxNumStages = maxStagesTailCompEQ * numTailComps;
    tailCompEQ.variant = MedusaParams.variant;
    
    % Default 'OFF' output
    outputDefault = zeros(MedusaParams.frameSize, MedusaParams.numSystemOut);


    %% Save to workspace
    MedusaConfig = struct('BandSplitConfig', BandSplitConfig, ...
                          'DRFDPConfig', DRFDPConfig, ...
                          'FRFDPConfig', FRFDPConfig, ...
                          'SurroundConfig', SurroundConfig, ...
                          'MSConfig', MSConfig, ...
                          'PremixConfig', PremixConfig.Stereo, ...
                          'PremixTune', PremixTune.Stereo, ...
                          'FRMConfig', FRMConfig.Stereo, ...
                          'FRMTune', FRMTune.Stereo, ...
                          'Premix5H1Config', PremixConfig.v5h1, ...
                          'Premix5H1Tune', PremixTune.v5h1, ...
                          'FRM5H1Config', FRMConfig.v5h1, ...
                          'FRM5H1Tune', FRMTune.v5h1, ...
                          'HoligramEQConfig', HoligramEQConfig,...
                          'wiggleFilterDefault', wiggleFilterDefault,...
                          'TailCompFirEvenSettings', TailCompFirEvenSettings, ...
                          'tailCompEQ', tailCompEQ,...
                          'routingMapDefault', routingMapDefault,...
                          'outputDefault', outputDefault,...
                          'numMedusaOut', numMedusaOut,...
                          'numVLSGains', numVLSGains,...
                          'numPeripheral', numPeripheral,...
                          'numNonHeadrest', numNonHeadrest,...
                          'numDRChan', numDRChan,...
                          'HeadrestIdx', HeadrestIdx,...
                          'OverheadIdx', OverheadIdx, ...
                          'PeripheralIdx', PeripheralIdx, ...
                          'FRMOutputIdx', FRMOutputIdx, ...
                          'holigramOutputSelect', holigramOutputSelect);
                      
    assignin('base', 'MedusaConfig', MedusaConfig);        
end

function MedusaTuneFiles = getMedusaTuneDefaults(sys_defs, MedusaTuneFiles)
% Generate MedusaConfig struct, which contains config structs for all sub-
% components inside Medusa

    % Specify tune data files for exposing upmixer components (default)
    MedusaTuneFiles.PremixStereo = 'PremixTuneFiles\MedusaPremixCAETuneVal_bypass.mat';
    MedusaTuneFiles.FRMStereo = 'PremixTuneFiles\MedusaFullRateMixerCAETuneVal_bypass.mat';
    MedusaTuneFiles.Premix5h1 = 'PremixTuneFiles\MedusaPremix5_1TuneVal_bypass.mat';
    MedusaTuneFiles.FRM5h1 = 'PremixTuneFiles\MedusaFullRateMixer5_1TuneVal_bypass.mat';
    MedusaTuneFiles.HeadrestPremix = 'PremixTuneFiles\HeadrestPremixCAETuneVal_bypass.mat';
    MedusaTuneFiles.HeadrestFRM = 'PremixTuneFiles\HeadrestFullRateMixerCAETuneVal_bypass.mat';
    MedusaTuneFiles.OverheadPremix = 'PremixTuneFiles\OverheadPremixCAETuneVal_bypass.mat';
    MedusaTuneFiles.OverheadFRM = 'PremixTuneFiles\OverheadFullRateMixerCAETuneVal_bypass.mat';
    
    % If the routing plan is not set to expose 'upmixer' components,
    % specify new files
    if(sys_defs.medusa_routing_plan)    % Flat routing
        MedusaTuneFiles.PremixStereo = 'PremixTuneFiles\MedusaPremixCAETuneVal_flat.mat';
        MedusaTuneFiles.FRMStereo = 'PremixTuneFiles\MedusaFullRateMixerCAETuneVal_flat.mat';
        MedusaTuneFiles.Premix5h1 = 'PremixTuneFiles\MedusaPremix5_1TuneVal_flat.mat';
        MedusaTuneFiles.FRM5h1 = 'PremixTuneFiles\MedusaFullRateMixer5_1TuneVal_flat.mat';
        MedusaTuneFiles.OverheadPremix = 'PremixTuneFiles\OverheadPremixCAETuneVal_flat.mat';
        MedusaTuneFiles.OverheadFRM = 'PremixTuneFiles\OverheadFullRateMixerCAETuneVal_flat.mat';
    end
end