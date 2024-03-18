classdef RatioCalculationConfig < BtcBaseClass
    % RatioCalculationConfig
    % Configuration Parameters for Ratio Calculation

    properties(Constant = true)
        % These are the properties that are not allowed to be changed.

        % This determines the rate at which the estimator operates
        DecimationFactor            = 16;
        
        % This should match the FFTSize used by the HF Noise Estimator
        FftSize                     = 256;
    end
        
    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the RatioCalculation block.

        SampleRateHz                            {mustBePositive}    = 44100;
        
       % Ratio Bounds
        LowBoundDb                      single  {mustBeNonnegative} = 50;
        HighBoundDb                     single  {mustBeNonnegative} = 60;

        % LFUP Checking
        UpdateLfNoiseUpdateThreshDb     single  {mustBePositive}    = 2;
        UpdateFlagHoldTimeSec           single  {mustBeNonnegative} = 6.0; 
                                                        % 130*DecSampleTimeSec
        UpdateLfNoiseUpdatePeriodSec    single  {mustBeNonnegative} = 1.5; 
                                                        % 33*DecSampleTimeSec
        UpdateSpeedUpdateThreshMph      single  {mustBeNonnegative} = 40;   
                                                        % Miles per Hour
        UpdateLfNoiseThreshDbspl        single  {mustBeNonnegative} = 60;
        UpdateHfNoiseThreshDbspl        single  {mustBeNonnegative} = 30;

        % Impulse Rejection & Smoothing
        ImpRejNoiseScale                single  {mustBeNonnegative} = 0.1;
        ImpRejImpulseScale              single  {mustBeNonnegative} = 100;

        ImpRejGamma0TauSec              single  {mustBePositive}    = 1.5;
        ImpRejImpulseVarianceLpfTauSec  single  {mustBePositive}    = 0.2;
        ImpRejEnergyLpfTauSec           single  {mustBePositive}    = 0.2;

        ImpRejFilterOutInit             single  {mustBeNonnegative} = 1000;
        ImpRejOutputLowBound            single  {mustBeNonnegative} = 100;

        % Slewing for the Ratio
        SlewAttackDbpersec              single  {mustBePositive}    = 3.0;
        SlewDecayDbpersec               single  {mustBeNegative}    = -12.0;
        SlewThresholdDb                 single  {mustBeNonnegative} = 1;
    end
        
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        DecRateHz;
        DecSampleTimeSec;
    end 
  
    properties(Dependent = true, GetAccess = protected)
        % These are the properties that are derived, but not gettable
        % externally.
        Overlap;
        HopSize;
    end
        
    methods
        function obj = RatioCalculationConfig()
        end
                                    
        % The get functions for the non-settable properties.                 
                
        function value = get.Overlap(obj)
            value = obj.FftSize/2;              % 50% Overlap
        end
        
        function value = get.HopSize(obj)
            value = obj.FftSize - obj.Overlap;
        end
          
        function value = get.DecRateHz(obj)
            value = obj.SampleRateHz/obj.DecimationFactor ...
                /obj.HopSize;
        end
        
        function value = get.DecSampleTimeSec(obj)
            value = 1/obj.DecRateHz;
        end
        
        %%%%
                
        function Validate(obj)
             if (obj.LowBoundDb > obj.HighBoundDb)
                error(['The high bound for the ratio ' ...
                    'should be larger than the low bound.']);
            end
            obj.Validate@BtcBaseClass();
        end
     end
end

