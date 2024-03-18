function PremixTune  = MedusaPremixTuneInit(tuneFileName, ...
    headrestTuneFileName, overheadTuneFileName, MedusaParams)
%#codegen
%% Initialization for Medusa Premix Tune Values
%
% Input arguments:
% Config struct with the following fields:
%   MedusaParams.numCenterChannels          : Number of Center Output Channels
%   MedusaParams.numSurroundChannels        : Number of Surround Output Channels
%   MedusaParams.holigramEQLinkPerSpeaker   : Number of Left and Right Output Channels
%   MedusaParams.includePremixCAE           : Indicates CAE support for Premix
%   MedusaParams.splitPremixBassComp        : Indicates split for premix bass component
%   MedusaParams.include_surround_input     : Indicates 5.1 input support for Premix
%   MedusaParams.numHeadrestVLS             : Number of Headrest Left and Right Output Channels
%   MedusaParams.numOverheadSpeakerPairs    : Number of Overhead Left and Right Output Channels
%
% Returns:
% Structs that can be passed to the Simulink block
%   PremixTune   : tune struct to interface with library block
%%

% Extracting necessary parameters from MedusaParams
NumCenterOut = MedusaParams.numCenterChannels;
NumSurroundOut = MedusaParams.numSurroundChannels;
NumEQLinks = MedusaParams.holigramEQLinkPerSpeaker;
includeCAE = MedusaParams.includePremixCAE;
splitBassComp = MedusaParams.splitPremixBassComp;
includesSurroundInput = MedusaParams.include_surround_input;
numHeadrestVLS = MedusaParams.numHeadrestVLS;
numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;

% Error check for bass component split flag
if(splitBassComp ~=0)
    splitBassComp = 1;
end

% Number of I/O left and right channels
LR_in = 7;
if (NumEQLinks == 6)                            % Without Bass Output (H6 configuration)
    LR_out = 6;
    numOverheadComps = 6;
else                                            % With Bass Output (H8 configuration)
    LR_out = (1-splitBassComp)*7 + splitBassComp*8;
    numOverheadComps = (1-splitBassComp)*7 + splitBassComp*8;
end

% Number of Center-Surround channels
CS_out = NumCenterOut + NumSurroundOut;         % Number of center and surround output channels
CS_in = 10;

% Include discrete input components for 5.1 processing
if(includesSurroundInput)
    LR_in = LR_in + 2;
    CS_in = CS_in + 3;
end

% Accounting for additional weights included as part of CAE
if(includeCAE)
    LR_in = LR_in + 3;
    CS_in = CS_in + 2;
end

% Accounting for additional channels introduced by headrest processing
if(numHeadrestVLS ~= 0)
    HR_out = 3;                 % 3 dedicated output channels for headrest
    HR_in = LR_in;              % The number of input components remain same for headrest channel
end

% Accounting for additional (overhead) channels introduced by 3D surround processing
if(numOverheadSpkrs ~= 0)
    OH_out = numOverheadComps;	% 6 dedicated output components for overhead speaker channels
    OH_in = LR_in;              % The number of input components remain same for overhead speaker channels
end

% Load the Tune File and validate the dimensions of Premix matrices
PremixTune = load(tuneFileName);

PremixTune.minGain_CS = ValidateCSTune(PremixTune.minGain_CS, CS_in, CS_out, NumSurroundOut);
PremixTune.detentGain_CS = ValidateCSTune(PremixTune.detentGain_CS, CS_in, CS_out, NumSurroundOut);
PremixTune.maxGain_CS = ValidateCSTune(PremixTune.maxGain_CS, CS_in, CS_out, NumSurroundOut);
PremixTune.downmix_wts_CS = ValidateCSTune(PremixTune.downmix_wts_CS, CS_in, CS_out, NumSurroundOut);

PremixTune.minGain_Left = ValidateLRTune(PremixTune.minGain_Left, LR_in, LR_out);
PremixTune.detentGain_Left = ValidateLRTune(PremixTune.detentGain_Left, LR_in, LR_out);
PremixTune.maxGain_Left = ValidateLRTune(PremixTune.maxGain_Left, LR_in, LR_out);
PremixTune.downmix_wts_Left = ValidateLRTune(PremixTune.downmix_wts_Left, LR_in, LR_out);

PremixTune.minGain_Right = ValidateLRTune(PremixTune.minGain_Right, LR_in, LR_out);
PremixTune.detentGain_Right = ValidateLRTune(PremixTune.detentGain_Right, LR_in, LR_out);
PremixTune.maxGain_Right = ValidateLRTune(PremixTune.maxGain_Right, LR_in, LR_out);
PremixTune.downmix_wts_Right = ValidateLRTune(PremixTune.downmix_wts_Right, LR_in, LR_out);

% Concat with Overhead Premix tune values if include 3D Surround processing
if (numOverheadSpkrs ~= 0 && ~isempty(overheadTuneFileName))
    OverheadPremixTune = load(overheadTuneFileName);
    
    % Validate the dimensions of Headrest tune matrices
    % Reusing the logic for CSTune with numSurroundOut = 0
    OverheadPremixTune.minGain_Left = ValidateLRTune(OverheadPremixTune.minGain_Left, OH_in, OH_out);
    OverheadPremixTune.detentGain_Left = ValidateLRTune(OverheadPremixTune.detentGain_Left, OH_in, OH_out);
    OverheadPremixTune.maxGain_Left = ValidateLRTune(OverheadPremixTune.maxGain_Left, OH_in, OH_out);
    OverheadPremixTune.downmix_wts_Left = ValidateLRTune(OverheadPremixTune.downmix_wts_Left, OH_in, OH_out);
    
    OverheadPremixTune.minGain_Right = ValidateLRTune(OverheadPremixTune.minGain_Right, OH_in, OH_out);
    OverheadPremixTune.detentGain_Right = ValidateLRTune(OverheadPremixTune.detentGain_Right, OH_in, OH_out);
    OverheadPremixTune.maxGain_Right = ValidateLRTune(OverheadPremixTune.maxGain_Right, OH_in, OH_out);
    OverheadPremixTune.downmix_wts_Right = ValidateLRTune(OverheadPremixTune.downmix_wts_Right, OH_in, OH_out);
    
    
    PremixTune.minGain_Left = vertcat(PremixTune.minGain_Left, OverheadPremixTune.minGain_Left);
    PremixTune.detentGain_Left = vertcat(PremixTune.detentGain_Left, OverheadPremixTune.detentGain_Left);
    PremixTune.maxGain_Left = vertcat(PremixTune.maxGain_Left, OverheadPremixTune.maxGain_Left);
    PremixTune.downmix_wts_Left = vertcat(PremixTune.downmix_wts_Left, OverheadPremixTune.downmix_wts_Left);
    
    PremixTune.minGain_Right = vertcat(PremixTune.minGain_Right, OverheadPremixTune.minGain_Right);
    PremixTune.detentGain_Right = vertcat(PremixTune.detentGain_Right, OverheadPremixTune.detentGain_Right);
    PremixTune.maxGain_Right = vertcat(PremixTune.maxGain_Right, OverheadPremixTune.maxGain_Right);
    PremixTune.downmix_wts_Right = vertcat(PremixTune.downmix_wts_Right, OverheadPremixTune.downmix_wts_Right);
end

% Concat with Headrest Premix tune values if include headrest processing
if (numHeadrestVLS ~= 0 && ~isempty(headrestTuneFileName))
    HeadrestPremixTune = load(headrestTuneFileName);
    
    % Validate the dimensions of Headrest tune matrices
    % Reusing the logic for CSTune with numSurroundOut = 0
    HeadrestPremixTune.minGain_Left = ValidateCSTune(HeadrestPremixTune.minGain_Left, HR_in, HR_out, 0);
    HeadrestPremixTune.detentGain_Left = ValidateCSTune(HeadrestPremixTune.detentGain_Left, HR_in, HR_out, 0);
    HeadrestPremixTune.maxGain_Left = ValidateCSTune(HeadrestPremixTune.maxGain_Left, HR_in, HR_out, 0);
    HeadrestPremixTune.downmix_wts_Left = ValidateCSTune(HeadrestPremixTune.downmix_wts_Left, HR_in, HR_out, 0);
    
    HeadrestPremixTune.minGain_Right = ValidateCSTune(HeadrestPremixTune.minGain_Right, HR_in, HR_out, 0);
    HeadrestPremixTune.detentGain_Right = ValidateCSTune(HeadrestPremixTune.detentGain_Right, HR_in, HR_out, 0);
    HeadrestPremixTune.maxGain_Right = ValidateCSTune(HeadrestPremixTune.maxGain_Right, HR_in, HR_out, 0);
    HeadrestPremixTune.downmix_wts_Right = ValidateCSTune(HeadrestPremixTune.downmix_wts_Right, HR_in, HR_out, 0);
    
    
    PremixTune.minGain_Left = vertcat(PremixTune.minGain_Left, HeadrestPremixTune.minGain_Left);
    PremixTune.detentGain_Left = vertcat(PremixTune.detentGain_Left, HeadrestPremixTune.detentGain_Left);
    PremixTune.maxGain_Left = vertcat(PremixTune.maxGain_Left, HeadrestPremixTune.maxGain_Left);
    PremixTune.downmix_wts_Left = vertcat(PremixTune.downmix_wts_Left, HeadrestPremixTune.downmix_wts_Left);
    
    PremixTune.minGain_Right = vertcat(PremixTune.minGain_Right, HeadrestPremixTune.minGain_Right);
    PremixTune.detentGain_Right = vertcat(PremixTune.detentGain_Right, HeadrestPremixTune.detentGain_Right);
    PremixTune.maxGain_Right = vertcat(PremixTune.maxGain_Right, HeadrestPremixTune.maxGain_Right);
    PremixTune.downmix_wts_Right = vertcat(PremixTune.downmix_wts_Right, HeadrestPremixTune.downmix_wts_Right);
end

end

function gain = ValidateCSTune(gain, dimIn, dimOut, NumSurroundOut)

NumRows = size(gain,1);
NumColumns = size(gain,2);

NumCenter = dimOut - NumSurroundOut;

% Checks and corrects the dimensions of premix sub-matrix
if(NumRows ~= dimOut)
    if(NumRows > dimOut)
        if(NumSurroundOut)
            gain = gain([1:NumCenter end], :);              % Selecting C1 and S
        else
            gain = gain(1:NumCenter, 1:NumColumns);           % Selecting C1 and C2
        end
    else                                                    % NumRows < CS_out
        diffNumRows = dimOut-NumRows;
        gain = [gain; zeros(diffNumRows, NumColumns)];      % Zero Padding the differential rows
    end
end

if(NumColumns ~= dimIn)
    if(NumColumns < dimIn)
        diffNumColumns = dimIn-NumColumns;
        gain = [gain zeros(dimOut, diffNumColumns)];        % Zero Padding the differential columns
    else
        gain = gain(:, 1:dimIn);
    end
end

end

function gain = ValidateLRTune(gain, dimIn, dimOut)

NumRows = size(gain,1);
NumColumns = size(gain,2);

% Checks and corrects the dimensions of premix sub-matrix
if(NumRows ~= dimOut)
    if(NumRows > dimOut)
        gain = gain(1:dimOut, 1:NumColumns);                  % Removing/Retaining Bass Output based on build-time setting
    else                                                    % NumRows < CS_out
        diffNumRows = dimOut-NumRows;
        gain = [gain; zeros(diffNumRows, NumColumns)];      % Zero Padding the differential rows
    end
end

if(NumColumns ~= dimIn)
    if(NumColumns < dimIn)
        diffNumColumns = dimIn-NumColumns;
        gain = [gain zeros(dimOut, diffNumColumns)];        % Zero Padding the differential columns
    else
        gain = gain(:, 1:dimIn);
    end
end

end