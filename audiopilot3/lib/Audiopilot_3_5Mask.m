classdef Audiopilot_3_5Mask
    % Audiopilot_3_5Mask:
    % Mask logic for the Audioopilot_3_5 block
    
    methods (Static)
        %%%%%%%%%%%%%%%%%%%%
        function NoiseEstimationModeCallBack(H)
            % This callback function makes sure that the correct  
            % view of configuration parameter options are presented 
            % to the user based on the top-level configuration
            thisMask = Simulink.Mask.get(H);
            flag = get_param(H,'NoiseEstimationMode');
            IncTails = thisMask.getParameter('IncludeSpumTails');
            IncIgnMic = thisMask.getParameter('IncludeIgnoreMicFlag');
            if (strcmp(flag,'Regular'))
                IncTails.Visible = 'on';
                IncIgnMic.Visible = 'on';
            else
                IncTails.Visible = 'off';
                IncIgnMic.Visible = 'off';
            end
        end         
        %%%%%%%%%%%%%%%%%%%%
        function [NumMicChannels,NumMusicChannels,...
                    NumHFRefLPF,NumHFRefBPF,NumLFRef] = ...
                    ChannelSetUp(~,InputAudioMode,NoiseEstimationMode,...
                            IncludeSpumTails)
            % This function sets up the number of channels for each 
            % of the inputs to AudioPilot.
            if (strcmp(NoiseEstimationMode,'Speed Only'))
                NumMicChannels = 0;
                NumHFRefLPF = 0;
                NumHFRefBPF = 0;
                NumLFRef = 0;
                if (strcmp(InputAudioMode,'Stereo - 2 Channels'))
                    NumMusicChannels = 2;
                else
                    NumMusicChannels = 6;
                end
            else
                NumLFRef = 1;
                NumMicChannels = 1;
                if (IncludeSpumTails)
                    NumHFRefLPF = 6;
                else
                    NumHFRefLPF = 4;
                end
                if (strcmp(InputAudioMode,'Stereo - 2 Channels'))
                    NumMusicChannels = 2;
                    NumHFRefBPF = 0;
                else
                    NumMusicChannels = 6;
                    NumHFRefBPF = 3;    
                 end
            end
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureRtcResponses(H,enableResponse)
            % Find all the blocks
            SpeedRtc = locate_block_all(H,'SetSpeedIn');
            HvacRtc = locate_block_all(H,'SetHvacSetting');
            if (enableResponse)
                doResponse = 'on';
            else
                doResponse = 'off';
            end
            set_response(SpeedRtc,doResponse);            
            set_response(HvacRtc,doResponse);
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureVariant(H,NoiseEstimationMode)
            
            blkOptions = Simulink.FindOptions("FollowLinks", true, ...
                                              "LookUnderMasks", "ALL",...
                                              "SearchDepth", 1);
            Variant = Simulink.findBlocks(H, ...
                'Name', 'NoiseEstimationVariant', blkOptions);
            
%             Variant = find_system(H,...
%                 'LookUnderMasks','on',...
%                 'FollowLinks','on',...
%                 'SearchDepth','1',...
%                 'Name','NoiseEstimationVariant');
            if (strcmp(NoiseEstimationMode,'Speed Only'))
                set_param(Variant,'LabelModeActiveChoice','Speed Only')
            else
                set_param(Variant,'LabelModeActiveChoice','Regular')
            end
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureModel(H,InputAudioMode,...
                NoiseEstimationMode,IncludeIgMicFlag)
            % This function configures the model according to the Mask
            % Parameters, InputAudioMode (stereo or surround),
            % NoiseEstimationMode (regular or speed only), and
            % IncludeIgnoreMicFlag.
                        
            % Also get block path            
            BlockPath = getfullname(H);

            % Locate all the blocks            
            MusicInput = locate_block(H,'MusicIn');  
            MicInput = locate_block(H,'Mic');           
            LFRefInput = locate_block(H,'LFRef');           
            HFRefLPFInput = locate_block(H,'HFRefLPF'); 
            HFRefBPFInput = locate_block(H,'HFRefBPF');             
            SpeedTag = locate_block(H,'SpeedFrom');            
            MuteTag = locate_block(H,'MuteFrom');
            HVACTag = locate_block(H,'HVACFrom');
            IgMicFlagInput = locate_block(H,'IgnoreMicFlag');
            IgMicFlagTag = locate_block(H,'IgnoreMicFlagFrom1');

            NoiseEstBlock = locate_block(H,'NoiseEstimationVariant');

            % Configure Ports
            % However, this exercise is not valid when the translation
            % engine is engaged, and all the inports are removed/disabled. 
            % So check if the "permanant" inport "Music" is present
            % before proceeding.
            if (~isempty(MusicInput))
                
                % Configure noise estimation variant
               Audiopilot_3_5Mask.ConfigureNoiseEstVarBlock ...
                    (NoiseEstBlock,InputAudioMode,NoiseEstimationMode)
                
                % Position of noise estimator block
                NoiseEstPos = get_param(NoiseEstBlock,'position');
                NoiseEstHeight = NoiseEstPos(4) - NoiseEstPos(2);
                
                % Position of "reference" inport - Music
                MusicInPos = get_param(MusicInput,'position');
                
                % Position of "reference" tag - Speed
                SpeedPos = get_param(SpeedTag,'position');
                
                % Size of tags and inports
                InportSize = [MusicInPos(3)-MusicInPos(1) ...
                                MusicInPos(4)-MusicInPos(2)];
                TagSize = [SpeedPos(3)-SpeedPos(1) ...
                                SpeedPos(4)-SpeedPos(2)];
                            
                % Number of inputs into noise estimator block
                % -- Should be 8 for regular stereo mode,
                % -- 9 for surround mode, & 4 for speed only mode
                
                NoiseEstPorts = get_param(NoiseEstBlock,'ports');
                NoiseEstNumPorts = NoiseEstPorts(1);
                
                % Calculate the separation between inputs of the noise
                % estimation block, as well as the offset of the 1st input
                % from the top of the block
                Sep = ceil(NoiseEstHeight/NoiseEstNumPorts);
                Offset = (NoiseEstHeight-((NoiseEstNumPorts-1)*Sep))/2;
                                                            
                % Set up ports based on whether it is speed-only
                if(strcmp(NoiseEstimationMode,'Speed Only'))
                    % Remove unnecessary ports
                    if ~isempty(MicInput)
                        delete_block_line(MicInput);
                    end
                    if ~isempty(LFRefInput)
                        delete_block_line(LFRefInput);
                    end
                    if ~isempty(HFRefLPFInput)
                        delete_block_line(HFRefLPFInput);
                    end
                    if ~isempty(HFRefBPFInput)
                        delete_block_line(HFRefBPFInput);
                    end
                    replace_block(BlockPath,...
                            'FollowLinks','on','LookUnderMasks','on',...
                            'SearchDepth','1','Name','IgnoreMicFlag',...
                            'constant','noprompt');
                    set_param([BlockPath '/IgnoreMicFlag'],...
                                'Value','1','OutDataTypeStr','boolean');
                    if ~isempty(MuteTag)
                        delete_block_line(MuteTag);
                        replace_block(BlockPath,...
                            'FollowLinks','on','LookUnderMasks','on',...
                            'Name','MuteGoto','terminator','noprompt');
                        set_param([BlockPath,'/MuteGoto'],'ShowName','off');
                    end
                    % Re-arrange the tags and the inports
                    % Speed Tag
                    currPos(1) = SpeedPos(1);
                    currPos(2) = NoiseEstPos(2) + Offset - TagSize(2)/2;
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2)+TagSize(2);
                    set_param(SpeedTag,'position',currPos);
                    % HVAC_dBSPL Tag
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(HVACTag,'position',currPos);
                    % SpeedOnlyFlag Tag
                    currPos(1) = SpeedPos(1);
                    currPos(2) = currPos(2) + Sep;
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(IgMicFlagTag,'position',currPos);
                        
                 else 
                    % Set up tags and inports
                    if isempty(MicInput)
                        MicInput = add_block('built-in/Inport',[BlockPath,'/Mic']);
                        add_line(BlockPath,'Mic/1','NoiseEstimationVariant/1');
                    end
                    if isempty(LFRefInput)
                        LFRefInput = add_block('built-in/Inport',[BlockPath,'/LFRef']);
                        add_line(BlockPath,'LFRef/1','NoiseEstimationVariant/2');
                    end
                    if isempty(HFRefLPFInput)
                        HFRefLPFInput = add_block('built-in/Inport',[BlockPath,'/HFRefLPF']);
                        add_line(BlockPath,'HFRefLPF/1','NoiseEstimationVariant/3');
                    end
                    if strcmp(InputAudioMode,'Surround - 6 Channels')
                        if isempty(HFRefBPFInput)
                            HFRefBPFInput = add_block('built-in/Inport',[BlockPath,'/HFRefBPF']);
                            add_line(BlockPath,'HFRefBPF/1','NoiseEstimationVariant/4');
                        end
                        if isempty(MuteTag)
                            MuteTag = add_block('built-in/From',[BlockPath,'/MuteFrom']);
                            add_line(BlockPath,'MuteFrom/1','NoiseEstimationVariant/6');
                            replace_block(BlockPath,'FollowLinks','on', ...
                                'Name','MuteGoto','Goto','noprompt');
                        end
                    else
                        if ~isempty(HFRefBPFInput)
                            delete_block_line(HFRefBPFInput);
                        end
                        if isempty(MuteTag)
                            MuteTag = add_block('built-in/From',[BlockPath,'/MuteFrom']);
                            add_line(BlockPath,'MuteFrom/1','NoiseEstimationVariant/5');
                            replace_block(BlockPath,...
                                'FollowLinks','on','LookUnderMasks','on',...
                                'Name','MuteGoto','Goto','noprompt');
                        end
                    end
                    if (IncludeIgMicFlag)
                        if ~(strcmp(get_param(IgMicFlagInput,'blockType'),'Inport'))
                            replace_block(BlockPath,...
                                'FollowLinks','on','LookUnderMasks','on',...
                                'SearchDepth','1','Name','IgnoreMicFlag',...
                                'Inport','noprompt');
                        end
                        % Allow Inport to take the last (or next) port number
                    else
                        if ~(strcmp(get_param(IgMicFlagInput,'blockType'),'Constant'))
                            replace_block(BlockPath,...
                                'FollowLinks','on','LookUnderMasks','on',...
                                'SearchDepth','1','Name','IgnoreMicFlag',...
                                'Constant','noprompt');
                            set_param([BlockPath '/IgnoreMicFlag'],...
                                'Value','0','OutDataTypeStr','boolean');
                        end
                    end   
                    % Configure tags and inports
                    % Mic Inport                
                    currPos(1) = MusicInPos(1);
                    currPos(2) = NoiseEstPos(2) + Offset - InportSize(2)/2; 
                    currPos(3) = MusicInPos(3);
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = 2;
                    set_port_position(MicInput,portNum,currPos);
                    % LFRef Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(LFRefInput,portNum,currPos);
                    % HFRefLPF Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(HFRefLPFInput,portNum,currPos);
                    % HFRefBPF Inport
                    if strcmp(InputAudioMode,'Surround - 6 Channels')
                        currPos(2) = currPos(2) + Sep;
                        currPos(4) = currPos(2) + InportSize(2);
                        portNum = portNum + 1;
                        set_port_position(HFRefBPFInput,portNum,currPos);
                    end
                    % Speed Tag
                    currPos(1) = SpeedPos(1);
                    currPos(2) = currPos(2) + Sep ...
                        + InportSize(2)/2 - TagSize(2)/2;
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(SpeedTag,'Position',currPos);
                    % Mute Tag
                    set_param([BlockPath,'/MuteGoto'],'GotoTag','Mute',...
                                                      'ShowName','off');
                    currPos(2) = currPos(2) + Sep; 
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(MuteTag,'GotoTag','Mute',...
                        'ShowName','off','Position',currPos);
                    % HVAC_dBSPL Tag
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(HVACTag,'Position',currPos);
                    % IgnoreMicFlag Tag
                    currPos(1) = SpeedPos(1);
                    currPos(2) = currPos(2) + Sep;
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2) + TagSize(2);
                    set_param(IgMicFlagTag,'Position',currPos);
                end
            end
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureNoiseEstVarBlock(H,InputAudioMode,...
                NoiseEstimationMode)
            % This function sets up the Noise Estimation Variant Block.
             
            % Also get block path
            BlockPath = getfullname(H);
            
            % Locate all the blocks
            MicInput = locate_block(H,'Mic');
            LFRefInput = locate_block(H,'LFRef');
            HFRefLPFInput = locate_block(H,'HFRefLPF');
            HFRefBPFInput = locate_block(H,'HFRefBPF');
            SpeedInput = locate_block(H,'Speed');
            MuteInput = locate_block(H,'Mute');
            HVACInput = locate_block(H,'HVACdBSPL');
            IgMicFlagInput = locate_block(H,'IgnoreMicFlag');
            
            % Configure Regular Noise Estimation within the Variant if used
            if(strcmp(NoiseEstimationMode,'Regular'))
                RegEstBlock = locate_block(H,'RegularNoiseEstimation');
                Audiopilot_3_5Mask.ConfigureRegEstBlock ...
                    (RegEstBlock,InputAudioMode);
            end
            
            % Configure Ports
            % However, this exercise is not valid when the translation
            % engine is engaged, and all the inports are removed/disabled. 
            % So check if the "permanant" inport "Speed" is present
            % before proceeding.
            if (~isempty(SpeedInput))
                
                % Position of regular noise estimation block
                % We can't use the handle because the block might not be active
                RegularPos = get_param ...
                    ([BlockPath '/RegularNoiseEstimation'],'position');
                RegularHeight = RegularPos(4) - RegularPos(2);
                
                % Position of speed inport
                SpeedPos = get_param(SpeedInput,'position');
                
                % Size of inports
                InportSize = [SpeedPos(3)-SpeedPos(1) ...
                                SpeedPos(4)-SpeedPos(2)];
                            
                % Number of inputs into regular noise estimator block
                % -- Should be 8 for regular stereo mode,
                % -- & 9 for surround mode
                
                RegularPorts = get_param ...
                    ([BlockPath '/RegularNoiseEstimation'],'ports');
                RegularNumPorts = RegularPorts(1);

                % Calculate the separation between inputs of the regular 
                % noise estimation block, as well as the offset of the 1st 
                %inpu from the top of the block
                Sep = ceil(RegularHeight/RegularNumPorts);
                Offset = (RegularHeight-((RegularNumPorts-1)*Sep))/2;

                % There are 4 inputs in speed only mode
                Sep_SpeedOnly = round(RegularHeight/4);
                Offset_SpeedOnly = round(RegularHeight/8);
                
                % Set up inports based on whether it is speed-only                
                if(strcmp(NoiseEstimationMode,'Speed Only'))
                    % Remove unnecessary ports
                    if ~isempty(MicInput)
                        delete_block(MicInput);
                    end
                    if ~isempty(LFRefInput)
                        delete_block(LFRefInput);
                    end
                    if ~isempty(HFRefLPFInput)
                        delete_block(HFRefLPFInput);
                    end
                    if ~isempty(HFRefBPFInput)
                        delete_block(HFRefBPFInput);
                    end
                    if ~isempty(MuteInput)
                        delete_block(MuteInput);
                    end

                    % Configure block parameters (port number, position, etc.)
                    % Speed Inport
                    currPos(1) = SpeedPos(1);
                    currPos(2) = RegularPos(2) + Offset_SpeedOnly - InportSize(2)/2;
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = 1;
                    set_port_position(SpeedInput,portNum,currPos);
                    % HVACdBSPL Inport
                    currPos(2) = currPos(2) + Sep_SpeedOnly;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(HVACInput,portNum,currPos);
                     % IgnoreMicFlag Inport
                    currPos(2) = currPos(2) + Sep_SpeedOnly;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(IgMicFlagInput,portNum,currPos);
                else
                    % Set up inports
                    if isempty(MicInput)
                        MicInput = add_block('built-in/Inport',...
                            [BlockPath,'/Mic']);
                    end
                    if isempty(LFRefInput)
                        LFRefInput = add_block('built-in/Inport',...
                            [BlockPath,'/LFRef']);
                    end
                    if isempty(HFRefLPFInput)
                        HFRefLPFInput = add_block('built-in/Inport',...
                            [BlockPath,'/HFRefLPF']);
                    end
                    if ((isempty(HFRefBPFInput)) && ...
                            (strcmp(InputAudioMode,'Surround - 6 Channels')))
                        HFRefBPFInput = add_block('built-in/Inport',...
                            [BlockPath,'/HFRefBPF']);
                    elseif ((~isempty(HFRefBPFInput)) && ...
                            (strcmp(InputAudioMode,'Stereo - 2 Channels')))
                        delete_block(HFRefBPFInput);
                    end                                       
                    if isempty(MuteInput)
                        MuteInput = add_block('built-in/Inport',...
                            [BlockPath,'/Mute']);
                    end
                    % Set up block parameters (positions, port number, etc.)
                     % Mic Inport
                    currPos(1) = SpeedPos(1);
                    currPos(2) = RegularPos(2) + Offset - InportSize(2)/2; 
                    currPos(3) = SpeedPos(3);
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = 1;
                    set_port_position(MicInput,portNum,currPos);
                    % LFRef Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(LFRefInput,portNum,currPos);
                    % HFRefLPF Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(HFRefLPFInput,portNum,currPos);
                    % HFRefBPF Inport (only in Surround Mode)
                    if strcmp(InputAudioMode,'Surround - 6 Channels')
                        currPos(2) = currPos(2) + Sep;
                        currPos(4) = currPos(2) + InportSize(2);
                        portNum = portNum + 1;
                        set_port_position(HFRefBPFInput,portNum,currPos);
                    end
                    % Speed Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(SpeedInput,portNum,currPos);
                    % Mute Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(MuteInput,portNum,currPos);
                    % HVACdBSPL Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(HVACInput,portNum,currPos);
                    % IgnoreMicFlag Inport
                    currPos(2) = currPos(2) + Sep;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = portNum + 1;
                    set_port_position(IgMicFlagInput,portNum,currPos);
                end
            end
        end
        %%%%%%%%%%%%%%%%%%%%
        function ConfigureRegEstBlock(H,InputAudioMode)
            % This function sets up the Regular Noise Estimation Block.
            
            % Also get block path
            BlockPath = getfullname(H);
            
            % Locate all the blocks
            MicInput = locate_block(H,'Mic');
            HFRefLPFInput = locate_block(H,'HFRefLPF');
            HFRefBPFInput = locate_block(H,'HFRefBPF');
            MuteLPFTag = locate_block(H,'FromMuteLPF');
            MuteBPFTag = locate_block(H,'FromMuteBPF');
            MuteLPFBlock = locate_block(H,'MuteLPF');
            MuteBPFBlock = locate_block(H,'MuteBPF');
            HFEstBlock = locate_block(H,'HFNoiseEstimatorCoh');
            LFEstBlock = locate_block(H,'LFNoiseEstimatorCoh');
            
            % Set up Implementation Variants and transform specific blocks  
            % by forcing the mask initializations in the noise estimators.                           
            MaskUtil.safe_setparam(LFEstBlock,'TriggerInit','1');
            MaskUtil.safe_setparam(HFEstBlock,'TriggerInit','1');
            
            % Configure Ports
            % However, this exercise is not valid when the translation
            % engine is engaged, and all the inports are removed/disabled. 
            % So check if the "permanant" inport "Mic" is present
            % before proceeding.
            if (~isempty(MicInput))
                
                % Position of HF Noise Estimator block
                HFPos = get_param(HFEstBlock,'position');
                HFHeight = HFPos(4) - HFPos(2);
               % Set up based on input audio mode                
                 if strcmp(InputAudioMode,'Stereo - 2 Channels')
                     % Remove unnecessary ports and blocks
                     if ~isempty(HFRefBPFInput)
                        delete_block_line(HFRefBPFInput);
                    end
                    if ~isempty(MuteBPFTag)
                        delete_block_line(MuteBPFTag);
                    end
                    if ~isempty(MuteBPFBlock)
                        delete_block_line(MuteBPFBlock);
                    end
                else
                    % Set up blocks
                    if isempty(MuteBPFBlock)
                        MuteBPFBlock = ...
                            add_block('simulink/Math Operations/Product',...
                                [BlockPath,'/MuteBPF']);
                        add_line(BlockPath,'MuteBPF/1','HFNoiseEstimatorCoh/3');
                    end
                    if isempty(MuteBPFTag)
                        MuteBPFTag = add_block('built-in/From',...
                            [BlockPath,'/FromMuteBPF']);
                        add_line(BlockPath,'FromMuteBPF/1','MuteBPF/2');
                    end
                     if isempty(HFRefBPFInput)
                        HFRefBPFInput = add_block('built-in/Inport',...
                            [BlockPath,'/HFRefBPF']);
                        add_line(BlockPath,'HFRefBPF/1','MuteBPF/1');
                    end
      
                    % Set up block parameters (positions, port number, etc.)
                    HFSep = HFHeight/3;                   
                    % HFRefBPF Inport
                    currPos = get_param(HFRefLPFInput,'position');
                    currPos(2) = currPos(2) + HFSep;
                    currPos(4) = currPos(4) + HFSep;
                    set_port_position(HFRefBPFInput,4,currPos);
                    set_param(HFRefBPFInput,'PortDimensions',...
                                    '[FrameSize NumHFRefBPF]');
                    % FromMuteBPF Tag
                    currPos = get_param(MuteLPFTag,'position');
                    currPos(2) = currPos(2) + HFSep;
                    currPos(4) = currPos(4) + HFSep;
                    set_param(MuteBPFTag,'GotoTag','Mute','position',currPos);
                    % MuteBPF Product Block
                    currPos = get_param(MuteLPFBlock,'position');
                    currPos(2) = currPos(2) + HFSep;
                    currPos(4) = currPos(4) + HFSep;
                    set_param(MuteBPFBlock,'position',currPos);
                 end
            end
        end
   end
end

%%%%%%%%%%%%%%%%%%%%
function set_port_position(block,num,pos)
    % This helper function sets the position of a port
    % AND also sets the port number. If the latter is not
    % necessary, then use set_param directly.
    set_param(block,'Port',num2str(num),'Position',pos);
end
%%%%%%%%%%%%%%%%%%%%
function delete_block_line(block)
    % This helper function deletes a block with a single 
    % output signal line, such as a tag or an inport, 
    % including the line.  
    handle = get_param(block,'LineHandles');
    if (handle.Outport ~= -1)
        delete_line(handle.Outport(1));
    end
    delete_block(block);
end
%%%%%%%%%%%%%%%%%%%%
function handle = locate_block(H, Name)
    % This helper function locates a block by the string, Name, 
    % in the system H, and returns the handle.  Search depth is set to 1.
    
    blkOptions = Simulink.FindOptions("FollowLinks",true, ...
                                      "SearchDepth", 1, ...
                                      "LookUnderMasks","All");
    handle = Simulink.findBlocks(H, 'Name', Name, blkOptions);    
    
%     handle = find_system(H,...
%         'LookUnderMasks','on',...
%         'FollowLinks','on',...
%         'SearchDepth','1',...
%         'Name',Name);
end
%%%%%%%%%%%%%%%%%%%%
function handle = locate_block_all(H, Name)
    % This helper function locates a block by the string, Name, 
    % in the system H, and returns the handle.
    
    blkOptions = Simulink.FindOptions("FollowLinks",true,...
                                      "LookUnderMasks","All");
    handle = Simulink.findBlocks(H, 'Name', Name, blkOptions);
     
%     handle = find_system(H,...
%         'LookUnderMasks','on',...
%         'FollowLinks','on',...
%         'Name',Name);
end
%%%%%%%%%%%%%%%%%%%%
function set_response(H, response)
    if (~isempty(H))
        MaskUtil.safe_setparam(H,'EnableResponse',response);
    end
end