function PoolDelayMask(gcbh, implementation)

% Data stores in the PoolDelay block and their Custom Storage Class 
% memory sections
blockDataStores = {'codeWorkMemory', 'delayBuffer', 'fastDelayBuffer'};
blockMemorySections = {'MemL1', 'MemL2Uncached', 'MemPm'};

for i = 1:1:length(blockDataStores)
    
    % Get the data store buffer name
    dataStoreName = blockDataStores{i};

    % Get block handle of the data store
    bufferBlockPath = MaskUtil.SubBlockName(gcbh, dataStoreName);
    bufferBlockHandle = getSimulinkBlockHandle(bufferBlockPath);

    % Create unique alias for data store name from buffer block
    % path, removing spaces and replacing all non-alphanumeric
    % characters with underscores
    bufferAlias = replace(bufferBlockPath, ' ', '');
    bufferAlias = regexprep(bufferAlias, '\W', '_');
    
    if -1 ~= bufferBlockHandle

        % Get Coder Info of the data store signal object used in the 
        % Pool Delay block
        theStateSignalObject = get(bufferBlockHandle, 'StateSignalObject');
        theCoderInfo = get(theStateSignalObject, 'CoderInfo');

        % Set the Custom Storage Class memory section
        if 3 == implementation
            % Generic implementation:  Set to default to eliminate memory 
            % section pragma mapping and alignment
            theCoderInfo.CustomAttributes.MemorySection = 'Default';
        else
            % L1 and L2 Memory implementations:  Set to designated section 
            theCoderInfo.CustomAttributes.MemorySection = blockMemorySections{i};
        end
        
        % Set the alias for this instance of the data store
        theCoderInfo.Alias = bufferAlias;

        % Set the header name for this top level model
        fullHeaderFilename = ...
                [getfullname(bdroot(bufferBlockHandle)) '_PoolDelayStorage.h'];
        theCoderInfo.CustomAttributes.HeaderFile = fullHeaderFilename;

        % Set definition file name for this top level model
        fullDefinitionFilename = ...
                [getfullname(bdroot(bufferBlockHandle)) '_PoolDelayStorage.c'];
        theCoderInfo.CustomAttributes.DefinitionFile = fullDefinitionFilename;

    end

end
