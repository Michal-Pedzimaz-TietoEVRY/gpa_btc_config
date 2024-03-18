classdef HighFrequencyNoiseEstimatorCohConfig < BtcBaseClass
    % HighFrequencyNoiseEstimatorCohConfig
    % Configuration Parameters for the High Frequency Noise Estimator

    properties(Constant = true)
        % These are the properties that are not allowed to be changed.

        % This determines the rate at which the estimator operates
        DecimationFactor                        = 16;
 
        % Coherence Calculations (Power Spectral Density)
        CoherenceFftSize                        = 256;
        CoherenceWelchSize                      = 16;
        
        % Impulse & Speech Rejection
        ImpRejNumSubWindow                      = 3;
    end
    
    properties(Constant = true, GetAccess = protected)
        % These are the properties that are not allowed to be changed, snd
        % also not gettable externally.
 
        % Bandpass Filter (BPF) Parameters
        BandPassFilterOrder                     = 12;
        BandPassFilterCutoffFrequencyLowHz      = 4562;
        BandPassFilterCutoffFrequencyHighHz     = 5562;

        % Lowpass Filter (LPF) Parameters
        LowPassFilterOrder                      = 6;

        % Anti-aliasing Filter (AA) Parameters
        AntiAliasFilterOrder                    = 4;
        AntiAliasFilterRippleDb                 = 0.5;
        AntiAliasFilterStopBandAttenuationDb    = 50;
        AntiAliasFilterCutoffFrequencyHz        = 1200;
    end
    
    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the HighFrequencyNoiseEstimatorCoh block.
 
        SampleRateHz                        {mustBePositive}        = 44100;
        FrameSize                           {mustBePositive,mustBeInteger} ...
                                                                    = 32;
        
        % Reference
        RefLatencyMsec              single  {mustBeNonnegative}     = 25;
        RefMaxLatencySamples        int32   {mustBeInteger}         = 256;
        RefPowerMinDb              single  {mustBeNonpositive}     = -160;        

        % Impulse and Speech Rejection
        ImpRejSubWindowTimeSec      single  {mustBePositive}        = 1; 
                                                % = 22 samples @ DecRate;
        ImpRejMinSearchMinGain      single  {mustBePositive, ...
            mustBeGreaterThan(ImpRejMinSearchMinGain,1)}            = 2.12; 
        ImpRejMinStatAlphaFactor    single  {mustBePositive, ...
            mustBeLessThan(ImpRejMinStatAlphaFactor,1)}             = 0.96;
        ImpRejMinStatAlphaMin        single  {mustBeNonnegative}    = 0.2;
        ImpRejMinStatMin            single  {mustBeNonnegative}     = 0.7;
        ImpRejMinStatBeta           single  {mustBeNonnegative}     = 0.7;
        ImpRejMinSearchCoef         single  {mustBePositive, ...
            mustBeLessThan(ImpRejMinSearchCoef,1)}                  = 0.7;
        
        ImpRejFlatnessThreshold     single  {mustBePositive, ...
            mustBeLessThan(ImpRejFlatnessThreshold,1)}              = 0.9;
        ImpRejFlatnessLowIndex      single  {mustBePositive,mustBeInteger} ...
                                                                    = 10;
        ImpRejFlatnessHighIndex     single  {mustBePositive,mustBeInteger} ...
                                                                    = 40;
        ImpRejLevelUpdateCoef       single  {mustBePositive, ...
             mustBeLessThan(ImpRejLevelUpdateCoef,1)}               = 0.07;
        
        NoiseLevelBias              single  {mustBePositive}        = 72;

        % Slewing for the Noise Estimate
        SlewAttackDbpersec          single  {mustBePositive}        = 3.0;
        SlewDecayDbpersec           single  {mustBeNegative}        = -12.0;
        SlewThresholdDb             single  {mustBeNonnegative}     = 2;
        SlewInitDb                  single  {mustBeNonnegative}     = 20;
        
        % Rfft Config
        RfftWindowingStft           RfftWindowingConfig;  
        RfftWindowAlias                                             = "RfftRef";

        % Implementation
        STFTImplementation          CodeImplementationVariant ...
                                          = CodeImplementationVariant.Generic;
        BpLpFiltVariant                                             = 'Generic';
        AaFiltVariant                                               = 'Generic';
        Variant                                                     = 'Generic';
    end
    
    
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        
        DecRateHz                   single {mustBePositive};
                
        % Coherence Calculations
        CoherenceOverlap            single  {mustBePositive,mustBeInteger};
        CoherenceHopSize            single  {mustBePositive,mustBeInteger};
        CoherenceDecRateHz          single  {mustBePositive};
        CoherenceDecRate2Hz         single  {mustBePositive};       

    end 
  
    properties(Dependent = true, GetAccess = protected)
        % These are the properties that are derived, but not gettable
        % externally.
        LPFCutoffFrequencyHz        single  {mustBeNonnegative};
    end
    
    properties(SetAccess = protected)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        ModulateFrequencyHz;
        BandPassFilterSos;
        BandPassFilterNumStages;
        LowPassFilterSos;
        LowPassFilterNumStages;
        AntiAliasFilterSos;
        AntiAliasFilterNumStages;       
    end
    
    methods
        function obj = HighFrequencyNoiseEstimatorCohConfig()
            % Constructor that creates an instance of the
            % HighFrequencyNoiseEstimatorCohConfig class.

            % Rfft Config
            obj.RfftWindowingStft = RfftWindowingConfig();
            obj.RfftWindowingStft.SelectVariant(obj.STFTImplementation);
            obj.LockPropertyAsAlias('RfftWindowingStft.FftSize',...
                                    'CoherenceFftSize')
            obj.LockPropertyAsAlias('RfftWindowingStft.Alias',...
                                    'RfftWindowAlias')

        end
                                    
        % The get functions for the non-settable properties.                 
                
        function value = get.DecRateHz(obj)
            value = obj.SampleRateHz/obj.DecimationFactor;              
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
         
         function value = get.BandPassFilterSos(obj)
            obj = formBandPassFilter(obj);
            value = obj.BandPassFilterSos;
        end
        
        function value = get.BandPassFilterNumStages(obj)
            obj = formBandPassFilter(obj);
            value = obj.BandPassFilterNumStages;
        end       
        
        function value = get.LPFCutoffFrequencyHz(obj)
            value = obj.BandPassFilterCutoffFrequencyHighHz;
        end
        
        function value = get.LowPassFilterSos(obj)
            obj = formLowPassFilter(obj);
            value = obj.LowPassFilterSos;
        end
        
        function value = get.LowPassFilterNumStages(obj)
            obj = formLowPassFilter(obj);
            value = obj.LowPassFilterNumStages;
        end
        
        function value = get.AntiAliasFilterSos(obj)
            obj = formAntiAliasingFilter(obj);
            value = obj.AntiAliasFilterSos;
        end
        
        function value = get.AntiAliasFilterNumStages(obj)
            obj = formAntiAliasingFilter(obj);
            value = obj.AntiAliasFilterNumStages;
        end
        
        function value = get.ModulateFrequencyHz(obj)
            value = obj.SampleRateHz / ...
                ceil(obj.SampleRateHz / obj.BandPassFilterCutoffFrequencyLowHz);
        end
        %%%%
                 
        function Validate(obj)
            % This function performs a self consistency check on the
            % property data in the object.  It should be invoked
            % only after the object is fully populated.
            
            if (obj.ImpRejFlatnessLowIndex > obj.ImpRejFlatnessHighIndex)
                error(['The higher index for flatness calculations ' ...
                    'should be larger than the lower index.']);
            end
            obj.Validate@BtcBaseClass();
        end
    end
    
    %%%%%%%%%%%%%%%%
    
    methods (Access = protected)
        
        function obj = formBandPassFilter(obj)
            % This function forms the band-pass filter and returns  
            % the object with second-order stages and the number.
            H = fdesign.bandpass('N,F3dB1,F3dB2', ...
                obj.BandPassFilterOrder, obj.BandPassFilterCutoffFrequencyLowHz, ...
                obj.BandPassFilterCutoffFrequencyHighHz, obj.SampleRateHz);
            Hdesign = design(H, 'butter');
            SOStemp = Hdesign.sosMatrix;
            G = Hdesign.ScaleValues;
            [Z, P, K] = sos2zp(SOStemp, G);
        	obj.BandPassFilterSos = zp2sos(Z, P, prod(K));
            obj.BandPassFilterNumStages = ceil(obj.BandPassFilterOrder/2);
        end
        
        function obj = formLowPassFilter(obj)
            % This function forms the low-pass filter and returns  
            % the object with second-order stages and the number.
            H = fdesign.lowpass('N,F3dB', ...
                obj.LowPassFilterOrder, obj.LPFCutoffFrequencyHz, obj.SampleRateHz);
            Hdesign = design(H, 'butter');
            SOStemp = Hdesign.sosMatrix;
            G = Hdesign.ScaleValues;
            [Z, P, K] = sos2zp(SOStemp, G);
        	obj.LowPassFilterSos = zp2sos(Z, P, prod(K));
            obj.LowPassFilterNumStages = ceil(obj.LowPassFilterOrder/2);
        end
        
        function obj = formAntiAliasingFilter(obj)
            % This function forms the anti-aliasing filter and returns  
            % the object with second-order stages and the number.
            [Z, P, K] = ...
                ellip(obj.AntiAliasFilterOrder, obj.AntiAliasFilterRippleDb, ...
                    obj.AntiAliasFilterStopBandAttenuationDb, ...
                    obj.AntiAliasFilterCutoffFrequencyHz/(obj.SampleRateHz/2));
            obj.AntiAliasFilterSos = zp2sos(Z, P, K);
            obj.AntiAliasFilterNumStages = ceil(obj.AntiAliasFilterOrder/2);
        end        
    end
end

