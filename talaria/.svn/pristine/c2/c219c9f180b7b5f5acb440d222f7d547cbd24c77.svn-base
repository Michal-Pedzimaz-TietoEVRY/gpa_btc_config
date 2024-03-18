classdef ProcessUnitMap
    % ProcessUnitMap is a class of static methods to manage shared storage
    % that tracks assigned use of processing units (e.g. HW accelerators)
    % across different DSP cores.
    
    % Challenge is that the built-up map does not know when to "reset"
    % itself between differing model updates. When the build-time settings
    % change, the "old" map must be either cleared - or re-validated to
    % ensure that it still represents what the blocks want. Passing in the
    % workspace variable as part of the assignment allows the assignment to
    % be re-validated by methods of this class by asking the block's
    % workspace what the *current* unit id assignment is. It's a sneaky way
    % to cause the blocks to ask each other what they want when conflicts
    % are detected.
    
    % Copyright 2021 Bose Corporation
    
    methods (Static)
        function [chipIndex,coreIndex] = AssignBlockToUnit(H,workspaceVariable,unitType,estimatedWorkload)
            % AssignBlockToUnit Assigns a unit to be used by the specified 
            % block with the estimated additional workload. Note that the
            % actual assignment is discovered in the block's mask workspace
            % via the provided workspaceVariable.
            % Usage:
            %   [chipIndex,coreIndex] = ProcessUnitMap.AssignBlockToUnit(H,workspaceVariable,unitType,estimatedWorkload)
            %
            % H : Handle or Simulink-URL of the block to be assigned to the
            %   processing unit
            % workspaceVariable : parameter or workspace variable name that
            %   the block uses to configure its designed unitId e.g.
            %   AccelDeviceId. Note that this variable cannot be a property
            %   of an object like Config.AccelDeviceId. It follows the same
            %   rules as passing Parameter-scope values to a MATLAB
            %   Function Block - just simple variable names only.
            % unitType : description of unit type to differentiate units. A
            %   single block might have more than one type, or different
            %   collections of blocks might coordinate their own types
            %   (e.g. "iir" or "fir"). The shared data storage uses this
            %   name.
            % estimatedWorkload : OPTIONAL numeric quantity estimating how
            %   much work the block will ask of the processing unit
            % chipIndex : returned numeric index indicating block H's
            %   currently assigned processor chip
            % coreIndex : returned numeric index indicating block H's
            %   currently assigned processor core
            %
            % Example:
            % [chip,core]=ProcessUnitMap.AssignBlockToUnit(blkh,'AccelId','iir');
            
            if (nargin < 4)
                estimatedWorkload = 0;
            end
            
            % Retrieve the data - MATLAB table objects are not handles...
            % so any changes made here must be written back to global data.
            theT = ProcessUnitMap.GetSharedData(H,unitType);

            % Gather the variables of the table: {'BlockName','Unit','CoreTag','Workload'}
            theBlockName = getfullname(H);
            theUnit = MaskUtil.GetEvaluatedParameter(H,workspaceVariable);
            theCoreTag = ProcessUnitMap.GetCoreTag(H);
            theWorkload = estimatedWorkload;
            
            % Extract/determine chip and core numbers
            chipIndex = 1;
            coreIndex = 1;
            foundTokensCell = regexp(theCoreTag,'(\d*)_(\d*)','tokens');
            if (false == isempty(foundTokensCell))
                chipIndex = str2double(foundTokensCell{1}{1});
                coreIndex = str2double(foundTokensCell{1}{2});
            end
            
            % Build a table row with the gathered data
            tableRow = {theBlockName,theUnit,theCoreTag,theWorkload};
            
            % Update the table with this row
            rowMatch = ismember(theT.BlockName,theBlockName);
            switch (sum(rowMatch))
                case 0
                    % Not present yet, add it to the end
                    rowMatch(end+1) = true;                    
                case 1
                    % Found existing entry, it will be replaced
                otherwise
                    % Unexpected error! The row is found more than once!
                    warning('Block [%s] has more than one entry!', theBlockName);
                    % ... leave the rows in place - they will ALL be
                    % updated below
            end
            if (isempty(theT))
                theT = [theT; tableRow];
            else
                theT(rowMatch,:) = deal(tableRow);
            end
            
            % Retrieve the current table size
            numRows = size(theT,1);
            
            % Find rows that are assigned to the same unit
            unitMatch = ismember(theT.Unit,theUnit);

            % ... and investigate any that do not match
            coreMatch = ismember(theT.CoreTag,theCoreTag);
            troubleRows = find((unitMatch) & (false == coreMatch));
            invalidRows = false(numRows,1);
            if (false == isempty(troubleRows))
                for i = troubleRows
                    % Check if this troubling row is still entirely valid
                    % (assume it is guilty until proven innocent)
                    invalidRows(i) = true;
                    peerBlock = theT.BlockName{i};
                    peerExists = ishandle(getSimulinkBlockHandle(peerBlock));
                    if (peerExists)
                        % Peer block still exists
                        % ... check if the unit still matches
                        peerUnit = MaskUtil.GetEvaluatedParameter( ...
                            peerBlock,workspaceVariable);                
                        if (isequal(peerUnit,theUnit))
                            % Peer unit is still the same
                            % ... check if the coreTag matches
                            peerTag = ProcessUnitMap.GetCoreTag(peerBlock);
                            if (false == isequal(peerTag,theCoreTag))
                                invalidRows(i) = false;
                                error('ProcessUnitMap:Mismatch', ...
                                'Encountered differing core assignments for %s [%s][%s].\n [%s]:[''%s''] vs.\n [%s]:[''%s'']', ...
                                    workspaceVariable, ...
                                    unitType,string(theUnit), ...
                                    theCoreTag,MaskUtil.GetBlockLinkString(GetSourceModelUrls(theBlockName)), ...
                                    peerTag,MaskUtil.GetBlockLinkString(GetSourceModelUrls(peerBlock)));
                            end
                        end                    
                    end
                end

                % Delete the invalid rows
                theT(invalidRows,:) = [];
            end
            
            % All done. Write this updated table back out to global storage
            ProcessUnitMap.SetSharedData(H,unitType,theT);
        end
        
        function ClearSharedData(H,unitType)
            % ClearSharedData wipes out any shared data for this map
            [variableName,theModel,itExists] = ProcessUnitMap.GetVariableName(H,unitType);
            if (itExists)
                % Got it! Remove it!
                Simulink.data.evalinGlobal(theModel,['clear ' variableName]);
            end
        end
        
        function SetSharedData(H,unitType,theData)
            % SetSharedData replaces any shared data with the provided data
            [variableName,theModel] = ProcessUnitMap.GetVariableName(H,unitType);
            Simulink.data.assigninGlobal(theModel,variableName,theData);
        end

        function theData = GetSharedData(H,unitType)
            % GetSharedData retrieves shared data, or creates if not there
            [variableName,theModel,itExists] = ProcessUnitMap.GetVariableName(H,unitType);
            if (itExists)
                % Got it! Pass it along!
                theData = Simulink.data.evalinGlobal(theModel,variableName);
            else
                % Aint nobody got it. Create it now!
                theData = table([],[],[],[], ...
                    'VariableNames',{'BlockName','Unit','CoreTag','Workload'});
                Simulink.data.assigninGlobal(theModel,variableName,theData);
            end
        end

    end
    methods (Static, Access=private)
        function [variableName,theModel,itExists] = GetVariableName(H,unitType)
            % GetVariableName returns shared-data-related values
            theModel = getfullname(bdroot(H));
            variableName = sprintf('%s_%sUnitMap',theModel,unitType);
            itExists = Simulink.data.existsInGlobal(theModel,variableName);
        end
        function coreTag = GetCoreTag(H)
            % GetCoreTag returns the assigned core tag for the given block
            % Note that it could be empty or whatever other weird value is
            % found in the tag.
            topAtomic = GetTopAtomic(H,true);
            coreTag = get_param(topAtomic,'Tag');
        end
    end
    
end