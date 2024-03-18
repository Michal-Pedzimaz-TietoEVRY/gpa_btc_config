classdef GainCalculationMask
    % GainCalculationMask:
    % Mask logic for the loudness gain calculation block    

    methods (Static)
        function ConfigureRtcResponses(H,enableResponse)
            % Find all the blocks
            LfNoiseRtc = locate_block_all(H,'LfNoiseOverRide');
            WbNoiseRtc = locate_block_all(H,'WbNoiseOverRide');
            HfNoiseRtc = locate_block_all(H,'HfNoiseOverRide');
            NoiseRatioRtc = locate_block_all(H,'NoiseRatioOverRide');
            LoudSignalRtc = locate_block_all(H,'LoudSignalOverRide');
            VNCSignalRtc = locate_block_all(H,'VNCSignalOverRide');
            DyneqBoostRtc = locate_block_all(H,'DyneqBoostOverRide');
            BassBoostRtc = locate_block_all(H,'VNCBassBoostOverRide');
            MidBoostRtc = locate_block_all(H,'VNCMidBoostOverRide');
            TrebleBoostRtc = locate_block_all(H,'VNCTrebleBoostOverRide');

            if (enableResponse)
                doResponse = 'on';
            else
                doResponse = 'off';
            end
            
            set_response(LfNoiseRtc,doResponse);  
            set_response(WbNoiseRtc,doResponse);
            set_response(HfNoiseRtc,doResponse);            
            set_response(NoiseRatioRtc,doResponse);
            set_response(LoudSignalRtc,doResponse);
            set_response(VNCSignalRtc,doResponse);
            set_response(DyneqBoostRtc,doResponse);            
            set_response(BassBoostRtc,doResponse);
            set_response(MidBoostRtc,doResponse);            
            set_response(TrebleBoostRtc,doResponse);
        end        
    end
end

function handle = locate_block_all(H, Name)
    % This helper function locates a block by the string, Name, 
    % in the system H, and returns the handle.
    handle = find_system(H,...
        'LookUnderMasks','on',...
        'FollowLinks','on',...
        'Name',Name);
end

function set_response(H, response)
    if (~isempty(H))
        MaskUtil.safe_setparam(H,'EnableResponse',response);
    end
end
        
