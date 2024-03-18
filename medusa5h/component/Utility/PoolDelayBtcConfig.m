classdef PoolDelayBtcConfig < BtcBaseClass
    % PoolDelayBtcConfig Build-time configuration class for the PoolDelayBtc block
    % Usage:
    %    aConfig = PoolDelayBtcConfig
    %

    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        MaxDelay = 512;
        BufferAlias = '';
        HeaderFilename = '';
    end
    methods
        %----------------------------------------------------------------------
        function this = PoolDelayBtcConfig()
            % PoolDelayBtcConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock valu
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            % Call base class and check for any cross-property interactions
            Validate@BtcBaseClass(this);
        end
        %----------------------------------------------------------------------
        function DoMaskInit(this,blockHandle)
            % DoMaskInit called from mask initialization to perform automation
            % of code generation settings and other canvas interactions.

            % Set code gen options for delay buffer
            MedusaDelayMaskInit(blockHandle, this.BufferAlias, this.HeaderFilename);

            %.Call base class in case it has any work to perform:
            DoMaskInit@BtcBaseClass(this,blockHandle);
        end
    end
end
