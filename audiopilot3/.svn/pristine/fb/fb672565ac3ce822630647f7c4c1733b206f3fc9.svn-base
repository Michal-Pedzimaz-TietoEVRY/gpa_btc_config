classdef SpeedOnlyConfig < BtcBaseClass
    % SpeedOnlyConfig
    % Configuration Parameters for the Speed Only Noise Estimator

    properties(Constant = true)
        % These are the properties that are not allowed to be changed.

        % This determines the rate at which the estimator operates
        DecimationFactor            {mustBePositive,mustBeInteger}  = 64;
     end
    
     properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the Speed Only block.

        SampleRateHz                {mustBePositive}                = 44100;

        % Slewing for the Noise Estimate
        SlewAttackdDbpsec           single  {mustBePositive}        = 3;
        SlewDecayDbpsec             single  {mustBeNegative}        = -12;
        SlewSlowSlewDbpsec          single  {mustBeNonnegative}     = 0.5;
        SlewThresholdDb             single  {mustBeNonnegative}     = 3;
        
        % Speed Bounds Block
        SpeedBounds                 SpeedBoundsConfig;
     end
        
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        DecRateHz                   single  {mustBePositive}
    end 
          
    methods
        function obj = SpeedOnlyConfig()
            % Constructor that creates an instance of the
            % SpeedOnlyConfig class.
            % Default values are used, unless otherwise provided
            % (see introduction)
            
            % Speed Bounds Block
            obj.SpeedBounds  = SpeedBoundsConfig();
        end
                                    
        % The get functions for the non-settable properties.                 
                
        function value = get.DecRateHz(obj)
            value = obj.SampleRateHz/obj.DecimationFactor;
        end                          
        %%%%
        
      end
end

