function VLSGainsMaskInit(gcbh, featurePathName)   

% Find all DSMs in library block
blockHandles = Simulink.findBlocksOfType(gcbh,'DataStoreMemory');

% If the block is in *OUR* home library just return
% if MaskUtil.IsInBlockDiagram(blockHandles(1),'VLSGains')
%     return;
% end

structName = string(['VLS_' featurePathName '_Ramper']);
for i = 1:1:numel(blockHandles)
    blockHandle = blockHandles(i);
    if -1 ~= blockHandle
        % Get Coder Info of the signal object used in delay buffer DSM
        theStateSignalObject = get(blockHandle, 'StateSignalObject');
        theCoderInfo = get(theStateSignalObject,'CoderInfo');
        theCoderInfo.CustomAttributes.StructName = structName;
    end

end 

end
