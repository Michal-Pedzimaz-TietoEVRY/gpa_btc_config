classdef Upmixer1p1Config < BtcBaseClass
    % Upmixer1p1Config Build-time configuration class for the Upmixer1p1 block
    % Usage:
    %   aConfig = Upmixer1p1Config
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
		% System-Level Build Time Parameters
        AnnChannelCount 
        FrontPeripheralChannelCount
        HeadrestCount
        ChannelsPerHeadrest 
		
		% Build-Time Parameters
		Interp = 1
		LocationInit = [0, 0]
		
		% Tune Parameters
        TuneDefaults Upmixer1p1TuneConfig
    end
    methods
        %----------------------------------------------------------------------
        function this = Upmixer1p1Config()
            % Upmixer1p1Config constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.TuneDefaults =  Upmixer1p1TuneConfig(this);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
