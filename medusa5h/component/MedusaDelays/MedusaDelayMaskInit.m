function MedusaDelayMaskInit(blkh, bufferAlias, headerFilename)
% Get block handle
bufferBlockPath = MaskUtil.SubBlockName(blkh, 'Data Store Memory');
bufferBlockHandle = getSimulinkBlockHandle(bufferBlockPath);

% If the block is in *OUR* home library just return
if (MaskUtil.IsInBlockDiagram(bufferBlockHandle,'MedusaDelays'))
    return;
end

if -1 ~= bufferBlockHandle

    % Set alias and header file name
    if ~isempty(bufferAlias)
        fullHeaderFilename = '';
        if ~isempty(headerFilename)
            fullHeaderFilename = ...
                [getfullname(bdroot(bufferBlockHandle)) '_' headerFilename '.h'];
        end
        CscUtil.SetDatastoreCsc(bufferBlockHandle, 'Bose', 'ExportToFile (Bose)', 'Identifier', bufferAlias, 'HeaderFile', fullHeaderFilename);
        
        % Get code mapping object of delay buffer DSM
        CodeMappingObj = CscUtil.GetMappingObj(bufferBlockHandle);

        if ~isempty(headerFilename)
            fullHeaderFilename = ...
                [getfullname(bdroot(bufferBlockHandle)) '_' headerFilename '.h'];
            CodeMappingObj.setDataStore(bufferBlockHandle, 'HeaderFile', fullHeaderFilename);
        else
            CodeMappingObj.setDataStore(bufferBlockHandle, 'HeaderFile', '');
        end

    else
        CscUtil.SetDatastoreCsc(bufferBlockHandle, 'Simulink', 'Auto');
    end

end