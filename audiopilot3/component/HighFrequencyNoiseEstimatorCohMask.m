classdef HighFrequencyNoiseEstimatorCohMask
    % HighFrequencyNoiseEstimatorCohMask:
    % Mask logic for the high frequency noise estimator (multiCoherence) block    

    methods (Static)
        %%%%%%%%%%%%%%%%%%%%
        function TriggerInitCallBack(H)
            % Force the block to run its mask init by changing this dummy 
            % parameter. The callback returns it to the original value.
            MaskUtil.safe_setparam(H,'TriggerInit','0');
        end
        %%%%%%%%%%%%%%%%%%%%
        function [AA,BPLP,NumAAChannels,NumHFRefChannels] ...
                = FormFilterCoef(~,Config,NumHFRefLPF,NumHFRefBPF)
            % This function forms the coefficient pool for the pooliir 
            % modules used for Band-Pass/Low-Pass & Anti-Aliasing
            
            %%% Channel Count
            NumHFRefChannels = NumHFRefLPF + NumHFRefBPF;
            
            %%% Anti-Aliasing           
            AA = struct();
            NumAAChannels = NumHFRefChannels + 1;
            AA.NumStages = repmat(Config.AntiAliasFilterNumStages,NumAAChannels,1);
            AA.SOS = repmat(Config.AntiAliasFilterSos,NumAAChannels,1);
            AA.MaxNumStages = sum(AA.NumStages);
            
            %%% Band-Pass & Low-Pass
            BPLP = struct();
            if (NumHFRefLPF == 0 && NumHFRefBPF == 0)
                error('There has to be a non-zero number of reference channels.');
            else
                BPLP.NumStages = ...
                    [Config.BandPassFilterNumStages; ...                       % Mic
                    repmat(Config.LowPassFilterNumStages,NumHFRefLPF,1); ...  % steering components
                    repmat(Config.BandPassFilterNumStages,NumHFRefBPF,1)];     % treble channels
                BPLP.SOS = ...
                    [Config.BandPassFilterSos; ...                             % Mic
                    repmat(Config.LowPassFilterSos,NumHFRefLPF,1); ...        % steering components
                    repmat(Config.BandPassFilterSos,NumHFRefBPF,1)];           % treble channels
                BPLP.MaxNumStages = sum(BPLP.NumStages);
            end
        end
        %%%%%%%%%%%%%%%%%%%%%
        function ConfigureModel(H,NumHFRefLPF,NumHFRefBPF,Config)
            % This function configures the model according to the Mask
            % Parameters, NumHFRefLPF,NumHFRefBPF and STFTImplementation.
            
            % Also get block path            
            BlockPath = getfullname(H);

            % Locate all the blocks            
            MicInput = locate_block(H,'Mic');           
            RefLPFInput = locate_block(H,'RefLPF');            
            RefBPFInput = locate_block(H,'RefBPF');
            RefConcatBlock = locate_block(H,'RefConcat');
            PreProcBlock = locate_block(H,'PreProcessing');
            STFTVariant = locate_block(H,'HfNoiseStft');

            % Decide which STFT Variant to use
            if mod((NumHFRefLPF + NumHFRefBPF),2)==0
                MaskUtil.safe_setparam(STFTVariant,...
                    'LabelModeActiveChoice','OddNumChannels');
            else
                MaskUtil.safe_setparam(STFTVariant,...
                    'LabelModeActiveChoice','EvenNumChannels');
            end
            
            % Configure Ports
            % However, this exercise is not valid when the translation
            % engine is engaged, and all the inports are removed/disabled.
            % So check if the "permanant" inport "Mic" is present
            % before proceeding.
            if (~isempty(MicInput))
                
                % Position of Pre_Processing block
                PreProcPos = get_param(PreProcBlock,'position');
                PreProcHeight = PreProcPos(4) - PreProcPos(2);
                
                % Position of "reference" inport - Mic
                MicInPos = get_param(MicInput,'position');
                              
                % Size of inports
                InportSize = [MicInPos(3)-MicInPos(1) ...
                                MicInPos(4)-MicInPos(2)];
               
                % There are 2 inputs to the Pre_Processing Block
                PreSep = round(PreProcHeight/2);
                PreOffset = round(PreProcHeight/4); 
                
                % Check to see if we need the concatenation block
                ConcatPresent = false;
                if (NumHFRefBPF > 0 && NumHFRefLPF > 0)
                    ConcatPresent = true;
                end
                
                % Handle each block one by one

                % Reference Concatenation
                if ConcatPresent
                    % Size of Block
                    ConcatSize = [45 60];
                    % There are 2 inputs to the Concatenation Block
                    ConSep = round(ConcatSize(2)/2);
                    ConOffset = round(ConcatSize(2)/4);
                    % Position
                    ConcatPos(1) = (PreProcPos(1) + MicInPos(3))/2 ...
                        - ConcatSize(1)/2;
                    ConcatPos(2) = PreProcPos(4) - PreOffset ...
                        - ConcatSize(2)/2;
                    ConcatPos(3) = ConcatPos(1) + ConcatSize(1);
                    ConcatPos(4) = ConcatPos(2) + ConcatSize(2);
                    if isempty(RefConcatBlock)
                        RefConcatBlock = add_block(...
                            'simulink/Math Operations/Matrix Concatenate', ...
                            [BlockPath '/RefConcat'],'position',ConcatPos);
                    end
                    delete_output_line(RefConcatBlock);
                 else
                    if ~isempty(RefConcatBlock)
                        delete_block_line(RefConcatBlock);
                    end
                end
                
                % RefLPF Inport
                if (NumHFRefLPF > 0)
                    if isempty(RefLPFInput)
                        RefLPFInput = ...
                            add_block('built-in/Inport',[BlockPath '/RefLPF']);
                    end
                    delete_output_line(RefLPFInput);
                    set_param(RefLPFInput,'PortDimensions',...
                                         '[FrameSize NumHFRefLPF]');
                else
                    if ~isempty(RefLPFInput)
                        delete_block_line(RefLPFInput);
                    end
                end
                
                % RefBPF Inport
                if (NumHFRefBPF > 0)
                    if isempty(RefBPFInput)
                        RefBPFInput = ...
                            add_block('built-in/Inport',[BlockPath '/RefBPF']);
                    end
                    delete_output_line(RefBPFInput);                    
                    set_param(RefBPFInput,'PortDimensions',...
                                        '[FrameSize NumHFRefBPF]');
                 else
                    if ~isempty(RefBPFInput)
                        delete_block_line(RefBPFInput);
                    end
                end
                
                % Position and Wire the Inports
                currPos(1) = MicInPos(1);
                currPos(3) = currPos(1) + InportSize(1);

                if ConcatPresent
                    add_line(BlockPath,'RefConcat/1','PreProcessing/2');
                    add_line(BlockPath,'RefLPF/1','RefConcat/1');
                    add_line(BlockPath,'RefBPF/1','RefConcat/2');
                    % RefLPF Inport
                    portNum = 2;
                    currPos(2) = ConcatPos(2) + ConOffset - InportSize(2)/2;
                    currPos(4) = currPos(2) + InportSize(2);
                    set_port_position(RefLPFInput,portNum,currPos);
                    % RefBPF Inport
                    portNum = portNum + 1;
                    currPos(2) = currPos(2) + ConSep;
                    currPos(4) = currPos(2) + InportSize(2);
                    set_port_position(RefBPFInput,portNum,currPos);
                else
                    currPos(2) = PreProcPos(4) - PreOffset - InportSize(2)/2;
                    currPos(4) = currPos(2) + InportSize(2);
                    portNum = 2;
                    if (NumHFRefBPF > 0)
                        add_line(BlockPath,'RefBPF/1','PreProcessing/2');
                        set_port_position(RefBPFInput,portNum,currPos);
                    else
                        add_line(BlockPath,'RefLPF/1','PreProcessing/2');
                        set_port_position(RefLPFInput,portNum,currPos);
                    end
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
function delete_output_line(block)
    % This helper function deletes the output line of 
    % a block with a single output signal line
    % such as a tag or an inport. 
    handle = get_param(block,'LineHandles');
    if (handle.Outport ~= -1)
        delete_line(handle.Outport(1));
    end
end%%%%%%%%%%%%%%%%%%%%
function delete_block_line(block)
    % This helper function deletes a block with a single 
    % output signal line, such as a tag or an inport, 
    % including the line.  
    delete_output_line(block);
    delete_block(block);
end
%%%%%%%%%%%%%%%%%%%%
function handle = locate_block(H, Name)
    % This helper function locates a block by the string, Name, 
    % in the system H, and returns the handle.
    blkOptions = Simulink.FindOptions("LookUnderMasks", "All", ...
        "FollowLinks", true, "SearchDepth", 1);
    handle = Simulink.findBlocks(H, "Name", Name, blkOptions);
    
%     handle = find_system(H,...
%         'LookUnderMasks','on',...
%         'FollowLinks','on',...
%         'SearchDepth','1',...
%         'Name',Name);
end