classdef LowFrequencyNoiseEstimatorCohConfig < BtcBaseClass
    % LowFrequencyNoiseEstimatorCohConfig
    % Configuration Parameters for the Low Frequency Noise Estimator
   
    properties(Constant = true)
        % These are the properties that are not allowed to be changed.

        % This determines the rate at which the estimator operates
        DecimationFactor            = 64;
 
        % Coherence Calculations (Power Spectral Density)
        CoherenceFftSize           = 256;
        CoherenceWelchSize         = 3;
    end
    
    properties(Constant = true, GetAccess = protected)
        % These are the properties that are not allowed to be changed, and
        % also not gettable externally.

        % Anti-aliasing Filter (AA) Parameters
        AntiAliasFilterOrder                     = 6;
        AntiAliasFilterRippleDb                  = 1;
        AntiAliasFilterStopBandAttenuationDb     = 76;
        AntiAliasFilterCutoffFrequencyHz         = 100;
    end
    
    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the LowFrequencyNoiseEstimatorCoh block.

        SampleRateHz                   {mustBePositive}            = 44100;

        % Reference
        RefLatencyMsec              single  {mustBeNonnegative}     = 70;
        RefMaxLatencyMsec           single  {mustBeNonnegative}     = 100;
        
        % Calibration
        SysMaxDbspl                 single  {mustBeNonnegative}     = 120;
        NoiseOffsetDbspl            single  {mustBeNonnegative}     = 0;
      
        % Impulse and Speech Rejection
        ImpRejMusicScale            single  {mustBeNumeric}         = -0.05;
        ImpRejNoiseScale            single  {mustBeNonnegative}     = 0.1;
        ImpRejImpulseScale          single  {mustBeNonnegative}     = 10.0;
        ImpRejOutputMin             single  {mustBeNonnegative}     = 0.0001;
        ImpRejEnergyFilterTauSec    single  {mustBeNonnegative}     = 0.5;
        ImpRejGamma0TauSec          single  {mustBeNonnegative}     = 0.75;
        ImpRejImpulseVarianceFilterTauSec ...
                                    single  {mustBeNonnegative}     = 1.5;

        % Slewing for the Noise Estimate
        SlewAttackDbpersec          single  {mustBePositive}        = 3;
        SlewDecayDbpersec           single  {mustBeNegative}        = -12;
        SlewSlowSlewDbpersec        single  {mustBeNonnegative}     = 0.5;
        SlewThresholdDb             single  {mustBeNonnegative}     = 3;
        
        % Rfft Config
        RfftWindowingStft           RfftWindowingConfig;  
        RfftWindowAlias                                             = "LfRfftWindow";

        % Implementation
        STFTImplementation          CodeImplementationVariant ...
                                          = CodeImplementationVariant.Generic;
       
        % Speed Bounds Block
        SpeedBounds SpeedBoundsConfig;

        % Mic/Ref mic filter
        MicFiltVariant = 'Generic';
        RefFiltVariant = 'Generic';
     end
    
    properties(GetAccess = {?ExtractModelBTC})
        % These are the settable properties that are used to derive 
        % other properties (See the protected properties below).  
        % They themselves are not used directly.
        CoherenceLowFrequencyHz        {mustBePositive}            = 20;
        CoherenceHighFrequencyHz       {mustBePositive}            = 100;
    end
    
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        DecRateHz                      single  {mustBePositive}
        
        % Coherence Calculations
        CoherenceOverlap               single  {mustBePositive,mustBeInteger};
        CoherenceHopSize               single  {mustBePositive,mustBeInteger};
        CoherenceDecRateHz             single  {mustBePositive};
        CoherenceDecRate2Hz            single  {mustBePositive};
        CoherenceLowFrequencyIndex     single  {mustBePositive,mustBeInteger};
        CoherenceHighFrequencyIndex    single  {mustBePositive,mustBeInteger};
   
        % Anti-aliasing Filter
        AntiAliasFilterSos;
        AntiAliasFilterNumStages;       
    end
    
    methods
        function obj = LowFrequencyNoiseEstimatorCohConfig()
            % Constructor that creates an instance of the
            % LowFrequencyNoiseEstimatorCohConfig class.
 
            % Speed Bounds Block
            obj.SpeedBounds  = SpeedBoundsConfig();

            % Rfft Config
            obj.RfftWindowingStft = RfftWindowingConfig();
            obj.RfftWindowingStft.SelectVariant(obj.STFTImplementation);
            obj.LockPropertyAsAlias('RfftWindowingStft.FftSize','CoherenceFftSize')
            obj.LockPropertyAsAlias('RfftWindowingStft.Alias','RfftWindowAlias')
         end
                                    
        % The get functions for the non-settable properties.                 
                
        function value = get.DecRateHz(obj)
            value = obj.SampleRateHz/obj.DecimationFactor;
        end
        
        function value = get.CoherenceLowFrequencyIndex(obj)
            value = max(floor(obj.CoherenceLowFrequencyHz / ...
                obj.DecRateHz * obj.CoherenceFftSize),1);
        end
         
        function value = get.CoherenceHighFrequencyIndex(obj)
            value = max(ceil(obj.CoherenceHighFrequencyHz / ...
                obj.DecRateHz * obj.CoherenceFftSize),1);
        end
        
        function value = get.CoherenceOverlap(obj)
            value = obj.CoherenceFftSize/2;              % 50% overlap
        end
        
        function value = get.CoherenceHopSize(obj)
            value = obj.CoherenceFftSize - obj.CoherenceOverlap;
        end
          
        function value = get.CoherenceDecRateHz(obj)
            value = obj.SampleRateHz/obj.DecimationFactor ...
                /obj.CoherenceHopSize;
        end
                       
        function value = get.CoherenceDecRate2Hz(obj)
            value = obj.CoherenceDecRateHz / obj.CoherenceWelchSize;
        end
        
        function value = get.AntiAliasFilterSos(obj)
            [Sos, ~] = formAntiAliasingFilter(obj);
            value = Sos;
        end
        
        function value = get.AntiAliasFilterNumStages(obj)
            [~, NumStages] = formAntiAliasingFilter(obj);
            value = NumStages;
        end
        
        %%%%
        
        function S = GetPrivateProperties(obj)
            % This function allows the user to read, albeit indirectly, the
            % private but settable properties of the object.
            S = struct;
            S.SampleRateHz = obj.SampleRateHz;
            S.CoherenceLowFrequencyHz = obj.CoherenceLowFrequencyHz;
            S.CoherenceHighFrequencyHz = obj.CoherenceHighFrequencyHz;
        end
        
        function Validate(obj)
            % This function performs a self consistency check on the
            % property data in the object.  It should be invoked
            % only after the object is fully populated.
            
            if (obj.CoherenceLowFrequencyHz > obj.CoherenceHighFrequencyHz)
                error(['The high frequency bound of the coherence observation ' ...
                    'band should be larger than the low bound.']);
            end
            
            checkBelowNyquist(obj,'CoherenceLowFrequencyHz');
            checkBelowNyquist(obj,'CoherenceHighFrequencyHz');  
            obj.Validate@BtcBaseClass();
        end
    end
    
    %%%%%%%%%%%%%%%%
    
    methods (Access = protected)        
        function [AntiAliasFilterSos, AntiAliasFilterNumStages] ...
                = formAntiAliasingFilter(obj)
            % This function forms the anti-aliasing filter and returns
            % the second-order stages and the number of stages.
            [Z, P, K] = ...
                ellip(obj.AntiAliasFilterOrder, obj.AntiAliasFilterRippleDb, ...
                obj.AntiAliasFilterStopBandAttenuationDb, ...
                obj.AntiAliasFilterCutoffFrequencyHz/(obj.SampleRateHz/2));
            AntiAliasFilterSos = zp2sos(Z, P, K);
            AntiAliasFilterNumStages = ceil(obj.AntiAliasFilterOrder/2);
        end
        
        function checkBelowNyquist(obj,freqName)
            if (obj.(freqName) > (obj.SampleRateHz / 2))
                error([freqName ' must be within Nyquist']);
            end
        end

    end
end

