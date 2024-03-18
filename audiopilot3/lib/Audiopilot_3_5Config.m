classdef Audiopilot_3_5Config < BtcBaseClass
    % Audiopilot_3_5Config
    % Configuration Parameters for Top-Level AudioPilot

    properties (GetObservable,SetObservable)
        SampleRateHz                    {mustBePositive}        = 48000*(12/13);
        FrameSize                       {mustBePositive,mustBeInteger}...
                                                                = 32;
        GainApp             GainApplicationConfig  
        GainCalc            GainCalculationConfig
        LfNoise             LowFrequencyNoiseEstimatorCohConfig
        HfNoise             HighFrequencyNoiseEstimatorCohConfig
        Ratio               RatioCalculationConfig
        HVAC                HVACConfig
        SpeedOnly           SpeedOnlyConfig
        
        EnableRtcResponse   logical                             = 0;
        
        Implementation      CodeImplementationVariant ...
                                          = CodeImplementationVariant.Generic;

    end
    methods
    %----------------------------------------------------------------------
    function obj = Audiopilot_3_5Config()
        % Audiopilot_3_5Config constructor: assign component property objects
        % and adjust component property defaults and/or lock values

        obj.GainApp = GainApplicationConfig(); 
        obj.LockPropertyAsAlias('GainApp.FrameSize', 'FrameSize');
        obj.LockPropertyAsAlias('GainApp.SampleRateHz', 'SampleRateHz');

        obj.GainCalc = GainCalculationConfig();
        obj.LockPropertyAsAlias('GainCalc.FrameSize', 'FrameSize');
        obj.LockPropertyAsAlias('GainCalc.SampleRateHz', 'SampleRateHz'); 
        obj.LockPropertyAsAlias('GainCalc.EnableRtcResponse', ...
                                                    'EnableRtcResponse'); 
        
        obj.LfNoise = LowFrequencyNoiseEstimatorCohConfig();
        obj.LockPropertyAsAlias('LfNoise.SampleRateHz', 'SampleRateHz');
        obj.LockPropertyAsAlias('LfNoise.STFTImplementation', ...
                                                        'Implementation');
         
        obj.HfNoise = HighFrequencyNoiseEstimatorCohConfig();
        obj.LockPropertyAsAlias('HfNoise.FrameSize', 'FrameSize');
        obj.LockPropertyAsAlias('HfNoise.SampleRateHz', 'SampleRateHz')        
        obj.LockPropertyAsAlias('HfNoise.STFTImplementation', ...
                                                        'Implementation');

        obj.Ratio = RatioCalculationConfig();
        obj.LockPropertyAsAlias('Ratio.SampleRateHz', 'SampleRateHz')        

        obj.HVAC = HVACConfig();
        
        obj.SpeedOnly = SpeedOnlyConfig();
        obj.LockPropertyAsAlias('SpeedOnly.SampleRateHz', 'SampleRateHz')        
        
    end
    %----------------------------------------------------------------------
  end
end
