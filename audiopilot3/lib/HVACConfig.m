classdef HVACConfig < BtcBaseClass
    % HVACConfig
    % Configuration Parameters for the HVAC module
    
    properties(Constant = true)
        % These are the properties that are not allowed to be changed.
        % NOTE: symfun will read this parameter.
        HVACTableSize = 16;
    end
    
    properties (GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the block.
        HVACTabledBSPL {mustBeNonnegative};
    end
    
    methods
        function obj = HVACConfig()
            % Constructor that creates an instance of the HVACConfig class.
            HVACAxis = (0:(obj.HVACTableSize-1)) / (obj.HVACTableSize-1);
            HVACNoise = 60 * ones(obj.HVACTableSize,1);
            obj.HVACTabledBSPL = single([HVACAxis' , HVACNoise]);
        end
        
        function obj = set.HVACTabledBSPL(obj,value)
            % Check that the table entered is of the correct size
            if any(size(value) > [obj.HVACTableSize,2])
                error('The table has to be of size (%d,2).',...
                    obj.HVACTableSize);
            else
                obj.HVACTabledBSPL = value;
            end
        end
    end
end

