classdef EntertainmentLevelDetectionConfig < BtcBaseClass
    % EntertainmentLevelDetectionConfig
    % Configuration Parameters for Entertainment Level Detection
       
    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the EntertainmentLevelDetection block.
        SampleRateHz                        {mustBePositive}        = 44100;
        FrameSize                           {mustBePositive,mustBeInteger}...
                                                                    = 32;
        FastDecayDbpersec           single  {mustBePositive}        = 5.0;
        SlowDecayDbpersec           single  {mustBePositive}        = 0.1;
        HoldTimeSec                 single  {mustBeNonnegative}     = 3.0;
        HoldMarginDb                single  {mustBeNumeric}         = 6.0;
        MinVolumeDb                 single  {mustBeNumeric}         = -80.0;
        MaxVolumeDb                 single  {mustBeNumeric}         = 0.0;
        MaxDbspl                    single  {mustBePositive}        = 123;
        AnnTriggerThreshold         single  {mustBeNonnegative}     = 0.5;
        SuperFastDecayMultiplier    single  {mustBePositive}        = 3.0;
        LatencyMsec                 single  {mustBeNonnegative}     = 1.5;
        
        MaxMusicDelay               {mustBeNonnegative,mustBeInteger}...
                                                                    = 512;
        LevDetPreEmpPooliirVariant                                  = 'Generic';
    end
    
    properties(GetAccess = {?ExtractModelBTC})
        % These are the settable properties that are used to derive 
        % other properties (See the protected properties below).  
        % They themselves are not used directly.
       
        PreemphasisWeightDb             {mustBeNumeric}         = 4.0;
        PreemphasisSlope                {mustBePositive}        = 1.0;
        PreemphasisCutoffFrequencyHz    {mustBePositive}        = 100;
    end
    
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
        FrameRateHz                 single      {mustBePositive};                   
        % Shelf Filter
        ShelfSos               ;
        ShelfNumStages         ;
    end
    
    methods
        function obj = EntertainmentLevelDetectionConfig()
            % Constructor that creates an instance of the
            % EntertainmentLevelDetectionConfig class.
         end
                                    
        % The get functions for the non-settable properties.                 
                
        function value = get.ShelfSos(obj)
            [Sos, ~] = formShelfFilter(obj);
            value = Sos;
        end
        
        function value = get.ShelfNumStages(obj)
            [~, NumStages] = formShelfFilter(obj);
            value = NumStages;
        end
        
        function value = get.FrameRateHz(obj)
            value = obj.SampleRateHz / obj.FrameSize;
        end
        
        %%%%
        
        function S = GetPrivateProperties(obj)
            % This function allows the user to read, albeit indirectly, the
            % private but settable properties of the object.
            S = struct;
            S.PreemphasisWeightDb = obj.PreemphasisWeightDb;
            S.PreemphasisSlope = obj.PreemphasisSlope;
            S.PreemphasisCutoffFrequencyHz ...
                = obj.PreemphasisCutoffFrequencyHz;
        end
     
        %%%%
                
        function Validate(obj)
            % This function performs a self consistency check on the
            % property data in the object.  It should be invoked
            % only after the object is fully populated.
            
            if (obj.MinVolumeDb > obj.MaxVolumeDb)
                error('MaxVolumeDb should be larger than MinVolumeDb');
            end
            
            if (obj.PreemphasisCutoffFrequencyHz > (obj.SampleRateHz / 2))
                error('cutoff frequency must be within Nyquist');
            end
            Validate@BtcBaseClass(obj);
        end
    end
    
    %%%%%%%%%%%%%%%%
    
    methods (Access = protected)
                 
        function [Sos, NumStages] = formShelfFilter(obj)
            % This function forms the shelf filter and returns 
            % the second-order stages and the number.
            
            Gain = obj.PreemphasisWeightDb;
            Slope = obj.PreemphasisSlope;
            fc = obj.PreemphasisCutoffFrequencyHz;
            wc = fc / (obj.SampleRateHz / 2);
            
            [numShelf, denomShelf] ...
                = designShelvingEQ(Gain, Slope, wc, 'hi');
            
            % Division by undb20(Gain) ensures a maximum gain of unity in 
            % the passband of the shelf filter.
            Sos = tf2sos(numShelf/(undb20(Gain)),[1;denomShelf]);
            NumStages = length(denomShelf)/2;
        end
    end
end

