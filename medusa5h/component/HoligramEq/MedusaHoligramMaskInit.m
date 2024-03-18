function MedusaHoligramMaskInit(gcbh, bufferAlias, headerFileName)
%#codegen
% Get block handle
bufferBlockPath = MaskUtil.SubBlockName(gcbh, 'Data Store Memory');
bufferBlockHandle = getSimulinkBlockHandle(bufferBlockPath);

if -1 ~= bufferBlockHandle
    
    % If the block is in *OUR* home library just return
    if (MaskUtil.IsInBlockDiagram(bufferBlockHandle,'MedusaDrHoligramEq'))
        return;
    end
    
    % Get Coder Info of the signal object used in delay buffer DSM
    theStateSignalObject = get(bufferBlockHandle, 'StateSignalObject');
    theCoderInfo = get(theStateSignalObject,'CoderInfo');
    
    MaskUtil.safe_setparam(bufferBlockHandle, 'StateStorageClass', 'ExportToFile (Bose)');
    theCoderInfo.Identifier = bufferAlias;
    
    fullHeaderFilename = append(getfullname(bdroot(bufferBlockHandle)),'_',headerFileName,'.h');
    theCoderInfo.CustomAttributes.HeaderFile = fullHeaderFilename;
    
end

end