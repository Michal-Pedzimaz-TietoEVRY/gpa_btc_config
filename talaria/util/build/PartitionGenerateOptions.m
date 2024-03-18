classdef PartitionGenerateOptions < handle
% PartitionGenerateOptions Options for the partition and generate script
%   Contains behavior details for the partitioning tool scripts. Specifies
%   which actions to take and how to take them.
    
%   Copyright 2021 Bose Corporation
    
    properties
        % Optional map from coreTag to the model ConfigSet to use during
        % code generation. The key of the map is the coreTag e.g. "1_2", or
        % "default" as a key represents the ConfigSet behavior to use when
        % a model's coreTag is not found in the map. The value assigned can
        % be one of three options:
        % 1) Empty: No action, just use active set already in the model
        % 2) String: Config set is already in the model, select it by name
        % 3) Object: A ConfigSet object (e.g. from exported script)
        CoreTagToConfigSetMap

        % For single-core direct-addressing builds only, controls core
        % index value in all generated tokens.
        SingleCoreIndex

        % Function name for file generated by getAtomicList and then
        % manually edited to assign processor units to each atomic
        % subsystem. Leave this as "default" to automatically search for
        % $(MODEL)_atomicList and switch to single-core mode if this
        % file is not found. Otherwise set to a specific function name
        % found via the MATLAB path, or set value to empty [] to configure
        % the partitioning tool to perform single-core operation
        % (regardless of the existence of any atomicList files).
        % Note that specified function names can include keyword
        % substitution string $(MODEL).
        AtomicListFunctionName string
        
        % Action to take for each partition or engine model:
        TranslateEngine32Bit ModelAction % ModelAction to take for 32-bit translation engine
        InterpretEngine32Bit ModelAction % ModelAction to take for 32-bit interpretation engine
        TranslateEngine64Bit ModelAction % ModelAction to take for 64-bit translation engine
        InterpretEngine64Bit ModelAction % ModelAction to take for 64-bit interpretation engine
        CoreTagToActionMap % Optional map of ModelAction to take for each core tag (or 'default')

        % How to perform work:
        Parallel logical = false % Boolean flag of whether to use the Parallel Computing Toolbox where possible
        CleanBuild logical = false % Boolean flag of whether to ignore previous results, re-generating everything
        CrossChipFrameDelay % Frame delay for a cross chip transfer
        CrossCoreFrameDelay % Frame delay for a cross core transfer
    end
    
    methods

        function this = PartitionGenerateOptions(optionsString)
            % PartitionGenerateSettings(shortcutNames) creates settings
            % according to the values associated with the provided
            % optionsString (space delimited codes)

            % Reset to default behaviors
            this.Reset();
            
            % Decode any shortcut expressions provided for settings
            if (nargin >= 1)
                this.Decode(optionsString);
            end
        end
        
        function this = Reset(this)
            % Resets an PartitionGenerateSettings to default settings
            this.CoreTagToActionMap = containers.Map;
            this.CoreTagToConfigSetMap = containers.Map;
            this.AtomicListFunctionName = "default";
            
            % By default, all partitioned core models take full action
            this.CoreTagToActionMap('default') = ModelAction.BothModelAndCode;
            
            % By default, the single-core direct-addressing core index is 1
            this.SingleCoreIndex = 1;
            
            % By default, the 64-bit engines are created
            this.Decode('64');            
            
            % By default, no clean builds or parallel builds
            this.Parallel = false;
            this.CleanBuild = false;

            % By default, frame delay = 2
            this.CrossChipFrameDelay = 2;
            this.CrossCoreFrameDelay = 2;
        end
        
        function Print(this)
            % Prints out (via fprintf) the current options
            fprintf('Parallel = %d\n',this.Parallel);
            fprintf('CleanBuild = %d\n',this.CleanBuild);
            fprintf('CrossChipFrameDelay = %d\n',this.CrossChipFrameDelay);
            fprintf('CrossCoreFrameDelay = %d\n',this.CrossCoreFrameDelay);
            fprintf('TranslateEngine32Bit = %s\n',this.TranslateEngine32Bit);
            fprintf('InterpretEngine32Bit = %s\n',this.InterpretEngine32Bit);
            fprintf('TranslateEngine64Bit = %s\n',this.TranslateEngine64Bit);
            fprintf('InterpretEngine64Bit = %s\n',this.InterpretEngine64Bit);
            fprintf('SingleCoreIndex = %d\n', this.SingleCoreIndex);
            
            keys = this.CoreTagToActionMap.keys;
            for i=1:numel(keys)
                key = keys{i};
                value = this.CoreTagToActionMap(key);
                fprintf('ModelAction[%s] = %s\n',key,value);
            end
                
            keys = this.CoreTagToConfigSetMap.keys;
            for i=1:numel(keys)
                key = keys{i};
                value = this.CoreTagToConfigSetMap(key);
                if (isa(value,'Simulink.ConfigSet'))
                    value = sprintf('ConfigSet[%s]',value.Name);
                else
                    value = sprintf('"%s"',value);
                end
                fprintf('ConfigSet[%s] = %s\n',key,value);
            end
        end        
        function this = Decode(this,optionsString)
            optionCell = split(optionsString);
            for i=1:numel(optionCell)
                aName = lower(optionCell{i});
                switch(aName)
                    case '0'
                        this.SingleCoreIndex = 0;
                    case '1'
                        this.SingleCoreIndex = 1;
                    case '2'
                        this.SingleCoreIndex = 2;
                    case '3'
                        this.SingleCoreIndex = 3;
                    case '4'
                        this.SingleCoreIndex = 4;
                    case '5'
                        this.SingleCoreIndex = 5;
                    case '6'
                        this.SingleCoreIndex = 6;
                    case '7'
                        this.SingleCoreIndex = 7;
                    case '64'
                        this.Create32Bit(ModelAction.Nothing);
                        this.Create64Bit(ModelAction.BothModelAndCode);
                    case '32'
                        this.Create32Bit(ModelAction.BothModelAndCode);
                        this.Create64Bit(ModelAction.Nothing);
                    case '-t32'
                        this.TranslateEngine32Bit = ModelAction.Nothing;
                    case '-i32'
                        this.InterpretEngine32Bit = ModelAction.Nothing;
                    case '-t64'
                        this.TranslateEngine64Bit = ModelAction.Nothing;
                    case '-i64'
                        this.InterpretEngine64Bit = ModelAction.Nothing;
                    case '+t32'
                        this.TranslateEngine32Bit = ModelAction.BothModelAndCode;
                    case '+i32'
                        this.InterpretEngine32Bit = ModelAction.BothModelAndCode;
                    case '+t64'
                        this.TranslateEngine64Bit = ModelAction.BothModelAndCode;
                    case '+i64'
                        this.InterpretEngine64Bit = ModelAction.BothModelAndCode;
                    case '-ball'
                        this.CoreTagToActionMap('default') = ModelAction.OnlyCreateModel;
                        this.Create32Bit(ModelAction.Nothing);
                        this.Create64Bit(ModelAction.Nothing);
                    case {'+parallel','+p'}
                        this.Parallel = true;
                    case {'+cleanbuild','+c'}
                        this.CleanBuild = true;
                    case {'-parallel','-p'}
                        this.Parallel = false;
                    case {'-cleanbuild','-c'}
                        this.CleanBuild = false;
                    case {'-engines', '-e'}
                        this.TranslateEngine32Bit = ModelAction.Nothing;
                        this.InterpretEngine32Bit = ModelAction.Nothing;
                        this.TranslateEngine64Bit = ModelAction.Nothing;
                        this.InterpretEngine64Bit = ModelAction.Nothing;
                    case {'+singlecore','+single','+s'}
                        this.AtomicListFunctionName = [];
                    case {'crosschipframedelay','chipdelay'}
                        this.CrossChipFrameDelay = str2double(optionCell{i+1});
                        optionCell{i+1} = '';
                    case {'crosscoreframedelay','coredelay'}
                        this.CrossCoreFrameDelay = str2double(optionCell{i+1});
                        optionCell{i+1} = '';
                    case ''
                        % Empty- do nothing
                    otherwise
                        error('Unrecognized PartitionGenerateSettings option [%s]', ...
                            aName);
                end
            end
        end
        
        function this = Create32Bit(this,value)
            % Create32Bit(value) sets flags for all 32-bit engines as
            % specified. If not specified, assumes BothModelAndCode
            if nargin < 2
                value = ModelAction.BothModelAndCode;
            end
            this.TranslateEngine32Bit = value;
            this.InterpretEngine32Bit = value;
        end
        function this = Create64Bit(this,value)
            % Create64Bit(value) sets flags for all 64-bit engines as
            % specified. If not specified, assumes BothModelAndCode
            if nargin < 2
                value = ModelAction.BothModelAndCode;
            end
            this.TranslateEngine64Bit = value;
            this.InterpretEngine64Bit = value;
        end
        
        function modelAction = GetCoreTagModelAction(this,coreTag)
            if (this.CoreTagToActionMap.isKey(coreTag))
                % Core-specific action
                modelAction = this.CoreTagToActionMap(coreTag);
            elseif (this.CoreTagToActionMap.isKey('default'))
                % specified default action
                modelAction = this.CoreTagToActionMap('default');
            else
                % default action to take if no other guidance given
                modelAction = ModelAction.BothModelAndCode;
            end
            modelAction = ModelAction(modelAction);
        end

        function configSet = GetCoreTagConfigSet(this,coreTag)
            % Determine model config set for this core - could be a string,
            % an object, or nothing at all (empty)
            if (this.CoreTagToConfigSetMap.isKey(coreTag))
                % Core-specific config set
                configSet = this.CoreTagToConfigSetMap(coreTag);
            elseif (this.CoreTagToConfigSetMap.isKey('default'))
                % specified default config set
                configSet = this.CoreTagToConfigSetMap('default');
            else
                % no special config set is given - just use the active one
                configSet = [];
            end  
        end

    end
end
