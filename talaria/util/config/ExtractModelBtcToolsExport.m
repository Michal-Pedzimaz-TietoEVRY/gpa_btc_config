function ExtractModelBtcToolsExport(modelName, filename)
% ExtractModelBtcToolsExport creates a JSON file of specially identified
% build-time-configuration properties. Model-level BTC is required for this routine to work. Given
% a model name, acquires model-level BTC and then scans through to find
% non-object properties that use the {ExportToTools} validation function and
% serializes only those properties to a JSON file with structural hierarchy
% that matches the BTC classes.
% Usage:
%   ExtractModelBtcToolsExport(modelName,[filename])
%
% filename is optional - when not provided default file path is codegen
% folder with name <modelName>_ToolApi.json
%
% See also: ExportToTools

% As this is pre-release, prevent errors from stopping process
try

% Acquire the model's BTC
theBtc = BTConfig.GetModelSettings(modelName);

% Scan depth-first through the object, adding properties as we find them.
theStruct = DumpObjectToStruct(struct,theBtc,{});

if (false == exist('filename','var'))
    % Construct a worthy JSON output path
    codeGenDir = Simulink.fileGenControl('get','CodeGenFolder');
    defaultName = sprintf('%s_%s.json',modelName,'ToolApi');
    filename = fullfile(codeGenDir,defaultName);
end

fprintf(' Writing to file "%s"\n', MaskUtil.GetFileEditLink(filename));

theJson = jsonencode(theStruct);
fid = CreateTextFile(filename);
fprintf(fid,theJson);
fclose(fid);

catch ME
    warning("Talaria:ExtractToolApiBtc", ...
        "**********************************\n" + ...
        "ExtractToolApiBtc failed with %s",ME.message);
end
end

function theStruct = DumpObjectToStruct(theStruct,theObject,componentNames)
% Given object, grab metadata object, check for export, recurse

    % This is the validator function that will trigger export
    funcToFind = @ExportToTools;

    mco = meta.class.fromName(class(theObject));
    propList = mco.PropertyList;
    % Loop through properties of this class
    for p = 1:numel(propList)
        aProp = propList(p);
        aPropName = aProp.Name;
        [canGet,~,isUserBtcClass] = BtcBaseClass.GetPropertyStats(aProp);

        % If we cannot even get the value, going to be hard to export
        if (false == canGet)
            continue;
        end

        % If this property is a user class, recurse into it
        if (isUserBtcClass)
            newComponentNames = vertcat(componentNames,aPropName);
            theStruct = DumpObjectToStruct( ...
                theStruct, theObject.(aPropName),newComponentNames);
            continue;
        end

        % Check if this property is annointed for export:
        theVal = aProp.Validation;
        if (isempty(theVal))
            % No Validation at all... so not this one.
            continue;
        end
        valFuncs = theVal.ValidatorFunctions;
        for v=1:numel(valFuncs)
            if (isequal(valFuncs{v},funcToFind))
                currentValue = theObject.(aPropName);
                newComponentNames = vertcat(componentNames,aPropName);
                theStruct = setfield(theStruct,newComponentNames{:},currentValue);

                currentValueStr = MaskUtil.ValueToStr(currentValue);
                componentPath = strjoin(newComponentNames,'.');
                fprintf('Found: %s = %s\n',componentPath,currentValueStr);
            end
        end
        
    end

end