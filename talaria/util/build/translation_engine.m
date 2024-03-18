classdef translation_engine < handle
%TRANSLATION_ENGINE Loads a translation engine into MATLAB.
%   Given the name of the original model, this routine seaches the code
%   generation folder for the "<modelName>_TranslationEngine64" dll. If
%   found, the resulting object can be used to access the translation
%   engine.
% Note: The translation engine must be built with the same
% machine architecture as the host (i.e. 64 vs. 32 bit)
    
%   Copyright 2018-2019 Bose Corporation
    properties
        ModelName
        DllName
    end
    
    properties (Constant)
        SubDir32 = 'engines32';
        SubDir64 = 'engines64';
    end
    
    methods (Static)
        function dllName = GetDllName(modelName)
            codeGenPath = Simulink.fileGenControl('get','CodeGenFolder');
            searchBase = fullfile(codeGenPath,[modelName '_TranslationEngine64']);
            searchString = [searchBase '*.dll'];
            namesStruct = dir(searchString);
            dllCandidates = string({namesStruct(:).name});
            [~,winnerIdx] = min(dllCandidates.strlength);
            [~,dllName] = fileparts(dllCandidates(winnerIdx).char);
        end
        function UnloadDll(modelName)
            dllName = translation_engine.GetDllName(modelName);
            if (false == isempty(dllName) && libisloaded(dllName))
                fprintf('%s unloaded\n',dllName);
                unloadlibrary(dllName);
            end
        end
    end
    
    methods
        function this = translation_engine(modelName)
            this.ModelName = modelName;
            
            this.DllName = translation_engine.GetDllName(modelName);
            if (isempty(this.DllName))
                error('Could not find DLL for %s',modelName);
            end
            
            % Now find the folder where this DLL's code headers are found
            codeGenPath = Simulink.fileGenControl('get','CodeGenFolder');
            folderName = [modelName '_TranslationEngine64_ert_shrlib_rtw'];
            folderPath = fullfile(codeGenPath,translation_engine.SubDir64, ...
                folderName);
            dllHeader = fullfile(folderPath,'translate_dll.h');
            
            % Try to load the library
            [notfound,warnings] = loadlibrary(this.DllName,dllHeader);
            
            % Cold start of the code:
            calllib(this.DllName,'InitializeTranslationEngine');
        end
        
        function [tuneVars] = ListTuneVars(this)
            % ListTuneVars Returns a string array of recognized TuneVars
            tuneVars = string( calllib(this.DllName,'FirstTuneVar') );
            aName = calllib(this.DllName,'NextTuneVar');
            while (false == isempty(aName))
                tuneVars(end+1) = string(aName);
                aName = calllib(this.DllName,'NextTuneVar');
            end
        end
        
        function [tuneVars] = GetTuneVarsForTop(this,topName)
            % ListTuneVars Returns a string array of recognized TuneVars
            tuneVars = string( calllib(this.DllName,'GetTuneVarsForTop',topName) );
        end
        
        function SetTuneVar(this,tuneVarName,tuneVarValues)
            % SetTuneVar Sets a TuneVar with provided space-delimited values
            % Returns 0 for OK, 1 for error
            retVal = calllib(this.DllName,'SetTuneVar',tuneVarName,tuneVarValues);
            strings = string(calllib(this.DllName,'GetTuneVarErrorStrings'));
            switch(retVal)
                case 0 
                case 1
                    error('TTE:SetTuneVar:error', strings);
            end
        end
        
        function SetReturnBufferSize(this,numBytes)
            retVal = calllib(this.DllName,'SetReturnBufferSize',numBytes);
            if (retVal)
                error('Unable to allocate %d bytes', numBytes);
            end
        end
        
        function values = GetTuneVar(this,tuneVarName)
            values = calllib(this.DllName,'GetTuneVar',tuneVarName);
            strings = calllib(this.DllName,'GetTuneVarErrorStrings');
            if (false == isempty(strings))
                error('TTE:GetTuneVar:error',strings);
            end
        end
        
        function [TOPs] = RunTranslations(this)
            % RunTranslations Returns a string array of up-to-date TOPs
            % generated by running any translation routines flagged as
            % out-of-date (i.e. because one or more of their TuneVars have
            % been set). Once translations are successful, they are no
            % longer out-of-date and will not run again unless new TuneVar
            % values are set (or there are errors)
            this.ClearTranslationErrorState;
            TOPs = string(calllib(this.DllName,'GetFirstTranslatedTOP'));
            aTOP = calllib(this.DllName,'GetNextTranslatedTOP');
            this.EmitErrors('RunTranslations');
            while (false == isempty(aTOP))
                TOPs(end+1) = string(aTOP);
                aTOP = calllib(this.DllName,'GetNextTranslatedTOP');
                this.EmitErrors('RunTranslations');
            end
        end

        function TOP = GetFirstTranslatedTOP(this)
            % GetFirstTransledTOP Runs translations "on demand"
            % individually to extract TOPs one at a time.
            this.ClearTranslationErrorState;
            TOP = string(calllib(this.DllName,'GetFirstTranslatedTOP'));
            this.EmitErrors('GetFirstTranslatedTOP');
        end
        
        function TOP = GetNextTranslatedTOP(this)
            % GetNextTranslatedTOP Runs translations "on demand"
            % individually to extract TOPs one at a time.
            this.ClearTranslationErrorState;
            TOP = string(calllib(this.DllName,'GetNextTranslatedTOP'));
            this.EmitErrors('GetNextTranslatedTOP');
        end

        function LoadAllTuneVarDefaults(this)
            calllib(this.DllName,'LoadAllTuneVarDefaults');
        end

        function ClearAllTuneSightings(this)
            calllib(this.DllName,'ClearAllTuneSightings');
        end
        
        function ClearAllTranslationRequiredFlags(this)
            calllib(this.DllName,'ClearAllTranslationRequiredFlags');
        end
        
        function [errorState] = GetTranslationErrorState(this)
            % GetTranslationErrorState Returns the current error state
            % for the engine. A value of "0" implies no errors.
            errorState = calllib(this.DllName,'GetTranslationErrorState');
        end
        
        function [errors] = GetErrorStrings(this)
            % GetErrorStrings Returns the current error strings
            % for the engine.
            errors = string(calllib(this.DllName,'GetTranslationErrorStrings'));
        end            

        function ClearTranslationErrorState(this)
            % ClearTranslationErrorState Resets the engine's error state
            % back to "0" (no errors).
            calllib(this.DllName,'ClearTranslationErrorState');
        end            

        function [compatibilityHash] = GetTopCompat(this,overlayGroupNameHash)
            % GetTopCompat Returns the compatibility hash code for the TOPs
            % represented within this translation engine. Provide
            % the crc32 hash of the overlay group name.
            compatibilityHash = calllib(this.DllName,'GetTopCompat',overlayGroupNameHash);            
            compatibilityHash = sprintf('%08x',uint32(compatibilityHash));
        end

        function [compatibilityHash] = GetTopCompatByName(this,overlayGroupName)
            % GetTopCompatByName Returns the compatibility hash code for the TOPs
            % represented within this translation engine. Provide
            % the exact name of the overlay group.
            compatibilityHash = calllib(this.DllName,'GetTopCompatByName',overlayGroupName);            
            compatibilityHash = sprintf('%08x',uint32(compatibilityHash));
        end
        
        function Reset(this)
            % Reset Clears the engine's error state and all other states
            % such as the tracking of which TuneVars have been seen, and
            % the flags which indicate that a translation is out-of-date
            % and needs to be run.
            calllib(this.DllName,'LoadAllTuneVarDefaults');
            calllib(this.DllName,'ClearAllTuneSightings');
            calllib(this.DllName,'ClearAllTranslationRequiredFlags');
            this.ClearTranslationErrorState;
        end


        % Make sure to unload the library when object dies
        function delete(this)
            if (false == isempty(this.DllName) && libisloaded(this.DllName))
                unloadlibrary(this.DllName);
            end
        end
        
    end
    methods (Access = protected)
        function EmitErrors(this, functionName)
            msgStrings = this.GetErrorStrings();
            if (this.GetTranslationErrorState)
                messageId = sprintf('TTE:%s:error',functionName);
                error(messageId, msgStrings);
            elseif "" ~= msgStrings
                messageId = sprintf('TTE:%s:warning',functionName);
                warning(messageId, msgStrings);
            end
        end
    end
end
