% Init script for VLS feature block
% This script generates VLSConfig struct for VLS block

% Specify files for default tune data, if not present already
if(~exist('VLSGainsTuneFile', 'var'))
    VLSGainsTuneFile = 'VLSGainsTuneVal.mat';
end

generateVLSConfig(sys_defs, VLSGainsTuneFile);

function generateVLSConfig(varargin)
% Generate VLSConfig struct, which contains config structs for all sub-
% components inside Medusa
    
    % Extract build time parameters from sys_defs. A default struct is
    % returned if sys_defs is empty
    if nargin > 0
        sys_defs = varargin{1};
        if nargin > 1
            VLSGainsTuneFile = varargin{2};
        end
    else
        sys_defs = [];
    end

    MedusaParams = getMedusaParams(sys_defs);

    [VLSGainsTune, VLSGainsConfig] = VLSGainsInit(MedusaParams, VLSGainsTuneFile);
    HeadrestCompEQConfig = HeadrestCompEQInit(MedusaParams);
    HeadrestDelayConfig = HeadrestDelayInit(MedusaParams);
    VLSGenDConfig = VLSGenInit(MedusaParams, 'FirD');
    VLSGenPConfig = VLSGenInit(MedusaParams, 'FirP');
    XtalkCancellationConfig = XtalkCancellationInit(MedusaParams);
    numHeadrestPairs = MedusaParams.numHeadrestVLS;
    
    %% Save to workspace
    VLSConfig = struct('numHeadrestPairs', numHeadrestPairs,...
                       'VLSGainsConfig', VLSGainsConfig,...
                       'VLSGainsTune', VLSGainsTune,...
                       'HeadrestCompEQConfig', HeadrestCompEQConfig,...
                       'HeadrestDelayConfig', HeadrestDelayConfig,...
                       'VLSGenDConfig', VLSGenDConfig,...
                       'VLSGenPConfig', VLSGenPConfig,...
                       'XtalkCancellationConfig', XtalkCancellationConfig);
                      
    assignin('base', 'VLSConfig', VLSConfig);        
end