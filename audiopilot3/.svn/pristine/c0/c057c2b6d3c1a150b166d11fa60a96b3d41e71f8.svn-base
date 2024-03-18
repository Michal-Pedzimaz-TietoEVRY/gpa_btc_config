classdef EntertainmentLevelDetectionMask
    % EntertainmentLevelDetectionMask:
    % Mask logic for the Entertainment Level Detection block
    
    methods (Static)
      %%%%%%%%%%%%%%%%%%%%
        function ConfigureAdditionalLevelDetectors(H,FANEnable,BODEnable)
            % This function configures the FAN and BOD variants according
            % to the mask parameters, FANEnable and BODEnable.
            
            % Also get block path
            BlockPath = getfullname(H);
            
            % Locate blocks
            FANVariant = locate_block(H,'FanLevelDetect');
            BODVariant = locate_block(H,'BodLevelDetect');
            FANOutport = locate_block(H,'FanLevel');
            BODOutport = locate_block(H,'BodLevel');
            DYNEQOutport = locate_block(H,'DyneqLevel');
            
            % CONFIGURATION
            
            % First, set all the variants
            
            if FANEnable
                set_param(FANVariant,'LabelModeActiveChoice','FanEnable');
            else
                set_param(FANVariant,'LabelModeActiveChoice','FanDisable');
            end
            if BODEnable
                set_param(BODVariant,'LabelModeActiveChoice','BodEnable');
            else
                set_param(BODVariant,'LabelModeActiveChoice','BodDisable');
            end
            
            % Then, set the ports
            % However, this exercise is not valid when the translation
            % engine is engaged, and all the ports are removed/disabled.
            % So check if the "permanant" inport "DYNEQOutport" is present
            % before proceeding.
            
            if (~isempty(DYNEQOutport))
                
                PortNum = str2double(get_param(DYNEQOutport,'Port'));
                
                if FANEnable
                    PortNum = PortNum + 1;
                    if ~(strcmp(get_param(FANOutport,'BlockType'),'Outport'))
                        ReplacedBlocks = replace_block(BlockPath, ...
                            'FollowLinks','on', 'SearchDepth','1', ...
                            'Name','FanLevel','Outport','noprompt');
                        set_param(ReplacedBlocks{1},'Port',num2str(PortNum));
                    end
                else
                    if strcmp(get_param(FANOutport,'BlockType'),'Outport')
                        replace_block(BlockPath, ...
                            'FollowLinks','on','SearchDepth','1', ...
                            'Name','FanLevel','terminator','noprompt');
                    end
                end
                if BODEnable
                    PortNum = PortNum + 1;
                    if ~(strcmp(get_param(BODOutport,'BlockType'),'Outport'))
                        ReplacedBlocks = replace_block(BlockPath, ...
                            'FollowLinks','on','SearchDepth','1', ...
                            'Name','BodLevel','Outport','noprompt');
                        set_param(ReplacedBlocks{1},'Port',num2str(PortNum));
                    end
                else
                    if strcmp(get_param(BODOutport,'BlockType'),'Outport')
                        replace_block(BlockPath, ...
                            'FollowLinks','on','SearchDepth','1', ...
                            'Name','BodLevel','terminator','noprompt');
                    end
                end
            end
        end
    end
end

%%%%%%%%%%%%%%%%%%%%
function handle = locate_block(H, Name)
% This helper function locates a block by the string, Name,
% in the system H, and returns the handle.
handle = find_system(H,...
    'LookUnderMasks','on',...
    'FollowLinks','on',...
    'SearchDepth','1',...
    'Name',Name);
end
