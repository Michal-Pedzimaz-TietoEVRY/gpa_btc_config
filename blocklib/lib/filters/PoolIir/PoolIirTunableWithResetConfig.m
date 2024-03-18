classdef PoolIirTunableWithResetConfig < PoolIirWithResetConfig
    % PoolIirTunableWithResetConfig Build-time configuration class for the PoolIirWithVariants block
    % Usage:
    %    aConfig = PoolIirTunableWithResetConfig
    %

    %   Copyright 2023 Bose Corporation

    properties
        TuneDefaults    PoolIirTunableWithResetTuneConfig
    end

    properties(GetObservable, SetObservable, Dependent = true, Hidden = true)
        % Delete the following properties when all features have upgraded
        % to the latest PoolIirTunable (with variants)
        DefaultNumStages        single
        DefaultSosCoefficients  single
    end

    methods
        %----------------------------------------------------------------------
        function this = PoolIirTunableWithResetConfig()
            % PoolIirTunableWithResetConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.TuneDefaults =  PoolIirTunableWithResetTuneConfig(this);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            %.End with a call to our base class to continue validation checks
            %.including any violations of property locking.
            Validate@PoolIirWithResetConfig(this);
        end
        %----------------------------------------------------------------------
        function DoMaskInit(this,blockHandle)
            % DoMaskInit called from mask initialization to perform automation
            % of code generation settings and other canvas interactions.

            % The same object is being used for both container block and inner block.
            % So, the class hierarchy is being flattened. Hence, the function is
            % called by both container and the inner block.
            blockType = get_param(blockHandle, 'MaskType');
            if (blockType == "Bose Pool IIR With Reset")
                DoMaskInit@PoolIirWithResetConfig(this,blockHandle);
            elseif (blockType == "Bose Pool IIR Tunable")
                DoMaskInit@BtcBaseClass(this,blockHandle);
            else
                error("Unsupported Block %s" , blockType);
            end
        end
    end

    % Remove this method when all features have upgraded to the latest
    % PoolIirTunable (with variants)
    methods
        function set.DefaultNumStages(obj,val)
            obj.TuneDefaults.NumStages = val;
            warning('Deprecated PoolIirTunableWithResetConfig property [DefaultNumStages] used. Update to use [TuneDefaults.NumStages]')
        end
        function val = get.DefaultNumStages(obj)
            val = obj.TuneDefaults.NumStages;
            warning('Deprecated PoolIirTunableWithResetConfig property [DefaultNumStages] used. Update to use [TuneDefaults.NumStages]')
        end

        function set.DefaultSosCoefficients(obj,val)
            obj.TuneDefaults.SosCoefficients = val;
            warning('Deprecated PoolIirTunableWithResetConfig property [DefaultSosCoefficients] used. Update to use [TuneDefaults.SosCoefficients]')
        end
        function val = get.DefaultSosCoefficients(obj)
            val = obj.TuneDefaults.SosCoefficients;
            warning('Deprecated PoolIirTunableWithResetConfig property [DefaultSosCoefficients] used. Update to use [TuneDefaults.SosCoefficients]')
        end
    end
end
