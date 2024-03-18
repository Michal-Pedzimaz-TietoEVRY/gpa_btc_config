function FRMTune  = MedusaFullRateMixerTuneInit(tuneFileName, ...
    headrestTuneFileName, overheadTuneFileName, MedusaParams)
%#codegen
    %% Initialization for Medusa Full-Rate Mixer Tune Values
    %
    % Input arguments: 
    % Config struct with the following fields:
    %   MedusaParams.numCenterChannels : Number of Center Output Channels
    %   MedusaParams.numSurroundChannels : Number of Surround Output Channels
    %   MedusaParams.numLeftRightPairs  : Number of Left and Right Output Channels
    %   MedusaParams.includePremixCAE           : Indicates CAE support for Full Rate Mixer
    %   MedusaParams.include_surround_input     : Indicates 5.1 input support
    %   MedusaParams.numHeadrestVLS             : Number of Headrest Left and Right Output Channels
    %   MedusaParams.numOverheadSpeakerPairs    : Number of Overhead Left and Right Output Channels
    %
    % Returns:
    % Structs that can be passed to the Simulink block  
    %   FRMTune   : tune struct to interface with library block
    %%

% Extracting necessary parameters from MedusaParams
NumCenterOut = MedusaParams.numCenterChannels;
NumSurroundOut = MedusaParams.numSurroundChannels;
NumLeftRightOut = MedusaParams.numLeftRightPairs;
includeCAE = MedusaParams.includePremixCAE;
includesSurroundInput = MedusaParams.include_surround_input;
numHeadrestVLS = MedusaParams.numHeadrestVLS;
numOverheadSpkrs = MedusaParams.numOverheadSpeakerPairs;

% Number of I/O left and right channels
LR_out = NumLeftRightOut;                       % Number of left and right output channels
LR_in = 3;

% Number of Center-Surround channels
CS_out = NumCenterOut + NumSurroundOut;         % Number of center and surround output channels
CS_in = 6;

% Include discrete input components for 5.1 processing
if(includesSurroundInput)
	LR_in = LR_in + 2;
	CS_in = CS_in + 3;
end

% Accounting for additional weights included as part of CAE
if(includeCAE)
    LR_in = LR_in + 1;
    CS_in = CS_in + 2;
end

% Accounting for additional channels introduced by headrest processing
if(numHeadrestVLS ~= 0)
	HR_out = numHeadrestVLS;    % The number of headrest speaker pairs
	HR_in = LR_in;              % The number of input components remain same for headrest channel
end

% Accounting for additional (overhead) channels introduced by 3D surround processing
if(numOverheadSpkrs ~= 0)
	OH_out = numOverheadSpkrs;	% Number of overhead speaker channel pairs
	OH_in = LR_in;              % The number of input components remain same for overhead speaker channels
end

% Load the Tune File and validate the dimensions of Premix matrices
FRMTune = load(tuneFileName);

FRMTune.minGain_CS = ValidateCSTune(FRMTune.minGain_CS, CS_in, CS_out, NumSurroundOut);
FRMTune.detentGain_CS = ValidateCSTune(FRMTune.detentGain_CS, CS_in, CS_out,NumSurroundOut);
FRMTune.maxGain_CS = ValidateCSTune(FRMTune.maxGain_CS, CS_in, CS_out, NumSurroundOut);
FRMTune.downmix_wts_CS = ValidateCSTune(FRMTune.downmix_wts_CS, CS_in, CS_out, NumSurroundOut);

FRMTune.minGain_Left = ValidateLRTune(FRMTune.minGain_Left, LR_in, LR_out);
FRMTune.detentGain_Left = ValidateLRTune(FRMTune.detentGain_Left, LR_in, LR_out);
FRMTune.maxGain_Left = ValidateLRTune(FRMTune.maxGain_Left, LR_in, LR_out);
FRMTune.downmix_wts_Left = ValidateLRTune(FRMTune.downmix_wts_Left, LR_in, LR_out);

FRMTune.minGain_Right = ValidateLRTune(FRMTune.minGain_Right, LR_in, LR_out);
FRMTune.detentGain_Right = ValidateLRTune(FRMTune.detentGain_Right, LR_in, LR_out);
FRMTune.maxGain_Right = ValidateLRTune(FRMTune.maxGain_Right, LR_in, LR_out);
FRMTune.downmix_wts_Right = ValidateLRTune(FRMTune.downmix_wts_Right, LR_in, LR_out);

% Concat with Headrest FRM tune values if include headrest processing
if (numOverheadSpkrs ~= 0 && ~isempty(overheadTuneFileName))
    OverheadFRMTune = load(overheadTuneFileName);
    
    % Validate the dimensions of Headrest tune matrices
    % Reusing the logic for CSTune with numSurroundOut = 0
	OverheadFRMTune.minGain_Left = ValidateLRTune(OverheadFRMTune.minGain_Left, OH_in, OH_out);
	OverheadFRMTune.detentGain_Left = ValidateLRTune(OverheadFRMTune.detentGain_Left, OH_in, OH_out);
	OverheadFRMTune.maxGain_Left = ValidateLRTune(OverheadFRMTune.maxGain_Left, OH_in, OH_out);
	OverheadFRMTune.downmix_wts_Left = ValidateLRTune(OverheadFRMTune.downmix_wts_Left, OH_in, OH_out);
	
	OverheadFRMTune.minGain_Right = ValidateLRTune(OverheadFRMTune.minGain_Right, OH_in, OH_out);
	OverheadFRMTune.detentGain_Right = ValidateLRTune(OverheadFRMTune.detentGain_Right, OH_in, OH_out);
	OverheadFRMTune.maxGain_Right = ValidateLRTune(OverheadFRMTune.maxGain_Right, OH_in, OH_out);
	OverheadFRMTune.downmix_wts_Right = ValidateLRTune(OverheadFRMTune.downmix_wts_Right, OH_in, OH_out);
    
    FRMTune.minGain_Left = vertcat(FRMTune.minGain_Left, OverheadFRMTune.minGain_Left);
    FRMTune.detentGain_Left = vertcat(FRMTune.detentGain_Left, OverheadFRMTune.detentGain_Left);
    FRMTune.maxGain_Left = vertcat(FRMTune.maxGain_Left, OverheadFRMTune.maxGain_Left);
    FRMTune.downmix_wts_Left = vertcat(FRMTune.downmix_wts_Left, OverheadFRMTune.downmix_wts_Left);
    
    FRMTune.minGain_Right = vertcat(FRMTune.minGain_Right, OverheadFRMTune.minGain_Right);
    FRMTune.detentGain_Right = vertcat(FRMTune.detentGain_Right, OverheadFRMTune.detentGain_Right);
    FRMTune.maxGain_Right = vertcat(FRMTune.maxGain_Right, OverheadFRMTune.maxGain_Right);
    FRMTune.downmix_wts_Right = vertcat(FRMTune.downmix_wts_Right, OverheadFRMTune.downmix_wts_Right);
end

% Concat with Headrest FRM tune values if include headrest processing
if (numHeadrestVLS ~= 0 && ~isempty(headrestTuneFileName))
    HeadrestFRMTune = load(headrestTuneFileName);
    
    % Validate the dimensions of Headrest tune matrices
    % Reusing the logic for CSTune with numSurroundOut = 0
	HeadrestFRMTune.minGain_Left = ValidateCSTune(HeadrestFRMTune.minGain_Left, HR_in, HR_out, 0);
	HeadrestFRMTune.detentGain_Left = ValidateCSTune(HeadrestFRMTune.detentGain_Left, HR_in, HR_out, 0);
	HeadrestFRMTune.maxGain_Left = ValidateCSTune(HeadrestFRMTune.maxGain_Left, HR_in, HR_out, 0);
	HeadrestFRMTune.downmix_wts_Left = ValidateCSTune(HeadrestFRMTune.downmix_wts_Left, HR_in, HR_out, 0);
	
	HeadrestFRMTune.minGain_Right = ValidateCSTune(HeadrestFRMTune.minGain_Right, HR_in, HR_out, 0);
	HeadrestFRMTune.detentGain_Right = ValidateCSTune(HeadrestFRMTune.detentGain_Right, HR_in, HR_out, 0);
	HeadrestFRMTune.maxGain_Right = ValidateCSTune(HeadrestFRMTune.maxGain_Right, HR_in, HR_out, 0);
	HeadrestFRMTune.downmix_wts_Right = ValidateCSTune(HeadrestFRMTune.downmix_wts_Right, HR_in, HR_out, 0);
    
    FRMTune.minGain_Left = vertcat(FRMTune.minGain_Left, HeadrestFRMTune.minGain_Left);
    FRMTune.detentGain_Left = vertcat(FRMTune.detentGain_Left, HeadrestFRMTune.detentGain_Left);
    FRMTune.maxGain_Left = vertcat(FRMTune.maxGain_Left, HeadrestFRMTune.maxGain_Left);
    FRMTune.downmix_wts_Left = vertcat(FRMTune.downmix_wts_Left, HeadrestFRMTune.downmix_wts_Left);
    
    FRMTune.minGain_Right = vertcat(FRMTune.minGain_Right, HeadrestFRMTune.minGain_Right);
    FRMTune.detentGain_Right = vertcat(FRMTune.detentGain_Right, HeadrestFRMTune.detentGain_Right);
    FRMTune.maxGain_Right = vertcat(FRMTune.maxGain_Right, HeadrestFRMTune.maxGain_Right);
    FRMTune.downmix_wts_Right = vertcat(FRMTune.downmix_wts_Right, HeadrestFRMTune.downmix_wts_Right);
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
            gain = gain(1:NumCenter, :);                % Selecting C1 and C2
        end
    else                                        % NumRows < CS_out
        diffNumRows = dimOut-NumRows;
        gain = [gain; zeros(diffNumRows, dimIn)];  % Zero Padding the differential rows
    end
end

if(NumColumns ~= dimIn)
    if(NumColumns < dimIn)
        diffNumColumns = dimIn-NumColumns;
        gain = [gain zeros(dimOut, diffNumColumns)];    % Zero Padding the differential columns
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
        gain = gain(1:dimOut, :);               % Removing/Retaining Bass Output based on build-time setting
    else                                        % NumRows < CS_out
        diffNumRows = dimOut-NumRows;
        gain = [gain; zeros(diffNumRows, NumColumns)];  % Zero Padding the differential rows
    end
end

if(NumColumns ~= dimIn)
    if(NumColumns < dimIn)
        diffNumColumns = dimIn-NumColumns;
        gain = [gain zeros(dimOut, diffNumColumns)];    % Zero Padding the differential columns
    else
        gain = gain(:, 1:dimIn);
    end
end

end