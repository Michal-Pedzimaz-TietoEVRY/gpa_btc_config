classdef TestRouterConfig < BtcBaseClass
    %TestRouterConfig Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (GetObservable,SetObservable)
        FrameSize
        NumOutChannels
        MainChannelSelectVector
        NumMainChannels  
        MainGains
        EnableAuxSrcs
        NumAuxChannels
        AuxGains
        TestRouterEnableAuxSrcs = 0
    end
    
    methods
        %----------------------------------------------------------------------
    function this = TestRouterConfig()
        % InputSelectConfig constructor: assign component property objects
        % and adjust component property defaults and/or lock values    

    end
    function Validate(this)
        % Validate called from mask initialization to check settings ok

        %.If there are no cross-property interactions, then this entire
        %.method can be deleted!

        %.End with a call to our base class to continue validation checks
        %.including any violations of property locking.
        Validate@BtcBaseClass(this);
    end
        
        function DoMaskInit(this,blockHandle)
        % DoMaskInit called from mask initialization to perform automation
        % of code generation settings and other canvas interactions.
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end
    end
end

