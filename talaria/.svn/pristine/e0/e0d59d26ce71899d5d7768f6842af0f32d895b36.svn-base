classdef DataMapUtil
%DATAMAPUTIL Utility class for storing values in a base workspace data map
%   Using the block's full name as a key (with adjustments to support
%   using ModelRootName, saves a single value into a base workspace
%   containers.Map variable. 

%   Copyright 2018-2019 Bose Corporation
    properties
        MapNameRoot
        UseModelRootName
    end

    methods (Static)
    end
    methods
        %--------------------------------------------------
        function this = DataMapUtil(mapNameRoot,useModelRootName)
            this.MapNameRoot = mapNameRoot;
            if (nargin >= 2)
                this.UseModelRootName = useModelRootName;
            else
                % By default, we share among partiitoned models via use of
                % the model root name
                this.UseModelRootName = true;
            end
        end
        %--------------------------------------------------
        function blockKey = GetKey(this,H)
            fullName = getfullname(H);
            if (this.UseModelRootName)
                % This map is shared among partitions (i.e. uses a model's
                % "root" name instead of the full model name). Do it:
                modelName = bdroot(fullName);
                rootModelName = ModelRootName(H);
                blockKey = strrep(fullName,modelName,rootModelName);
            else
                % This map is specific to the specific model file. Do not
                % share the map among paritioned models.
                blockKey = fullName;
            end
        end
        %--------------------------------------------------
        function [mapName] = GetDataMapName(this,H)
            if (this.UseModelRootName)
                % This map is shared among partitions
                mapName = [this.MapNameRoot, ModelRootName(H)];
            else
                % This map is specific to the specific model file
                modelName = bdroot(getfullname(H));
                mapName = [this.MapNameRoot, modelName];
            end
        end
        %--------------------------------------------------
        function [theMap] = GetDataMap(this,H)
            wsName = 'base';
            mapName = this.GetDataMapName(H);
            try
                theMap = evalin(wsName,mapName);
            catch
                assignin(wsName,mapName,containers.Map);
                theMap = evalin(wsName,mapName);
            end
        end
        %--------------------------------------------------
        function SaveDataMap(this,H,directory)

            % If directory wasn't provided, use the model location
            if nargin < 3
                % Saves datamap to file in same directory as model
                modelRoot = bdroot(H);
                modelFilePath = get_param(modelRoot,'FileName');
                directory = fileparts(modelFilePath);
            end
            % Ensure that the map exists (even if just empty)
            this.GetDataMap(H);
            mapName = this.GetDataMapName(H);
            newFilePath = fullfile(directory,mapName);
            saveCmd = sprintf('save(''%s'',''%s'');',newFilePath,mapName);
            evalin('base',saveCmd);
        end
        %--------------------------------------------------
        function LoadDataMap(this,H,directory)
            % If directory wasn't provided, use the model location
            if nargin < 3
                % Loads datamap from file in same directory as model
                modelRoot = bdroot(H);
                modelFilePath = get_param(modelRoot,'FileName');
                directory = fileparts(modelFilePath);
            end
            mapName = this.GetDataMapName(H);
            theFilePath = fullfile(directory,mapName);
            loadCmd = sprintf('load(''%s'');',theFilePath);
            evalin('base',loadCmd);
        end
        %--------------------------------------------------
        function [theValue,wasFound] = GetStoredValue(this,H)
            % Do not load values for libraries - just models
            diagramType = get_param(bdroot(H),'BlockDiagramType');
            if (strcmp(diagramType,'library'))
                theValue=[];
                wasFound=false;
                return;
            end

            % Retrieve the numeric version of the value from storage. This
            % is the original inport value with no alteration.
            theMap = this.GetDataMap(H);
            blockKey = this.GetKey(H);
            if (theMap.isKey(blockKey))
                theValue = theMap(blockKey);
                wasFound = true;
            else
                theValue = [];
                wasFound = false;
            end
        end
        %--------------------------------------------------
        function SetStoredValue(this,H,theValue)
            % SetStoredValue Set the value stored in the data map for the
            % specified block.
            % Usage:
            %       map.SetStoredValue(blockH,value);
            
            % Do not save values for libraries - just models
            diagramType = get_param(bdroot(H),'BlockDiagramType');
            if (strcmp(diagramType,'library'))
                return;
            end

            % Save the numeric version of the value (received via inport)
            % into storage. Save the original inport value with no alteration.
            theMap = this.GetDataMap(H);
            blockKey = this.GetKey(H);
            theMap(blockKey) = theValue;
        end
        %--------------------------------------------------
        function ClearMap(this,H)
            wsName = 'base';
            mapName = this.GetDataMapName(H);
            cmmdExpr = sprintf('clear %s', mapName);
            evalin(wsName,cmmdExpr);
        end
    end
end

