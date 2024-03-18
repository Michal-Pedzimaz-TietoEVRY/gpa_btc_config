classdef GainCalculationConfig < BtcBaseClass
    % GainCalculationConfig
    % Configuration Parameters for Gain Calculation Block

    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the Gain Calculation block.
        
        SampleRateHz                {mustBePositive}                = 44100;
        FrameSize                   {mustBePositive,mustBeInteger}  = 32;

        % Configuration
        AudiopilotOn                single      {mustBe0or1}        = 1;
        DyneqOn                     single      {mustBe0or1}        = 1;
        DownwardExpansionOn         single      {mustBe0or1}        = 0;
        
        % Alpha Calculation
        LfNoiseLowBoundDbspl        single      {mustBeNonnegative} = 83;
        LfNoiseHighBoundDbspl       single      {mustBeNonnegative} = 88;
        
        HfNoiseLowBoundDbspl        single      {mustBeNonnegative} = 20;
        HfNoiseHighBoundDbspl       single      {mustBeNonnegative} = 30;
        
        % Signal Minimum
        MinSignalLevelDbspl         single      {mustBeNonnegative} = 40;
        
        % Dynamic Equalization
        DyneqBassThreshDbspl        single      {mustBeNonnegative} = 95;
        DyneqBassSlopeDbPerDb       single      {mustBeNonnegative} = 0.35;
        DyneqBassMaxBoostDb         single      {mustBeNonnegative} = 20;
        
        % Bass
        BassThresh0Db               single      {mustBeNumeric}     = -3;
        BassThresh1Db               single      {mustBeNumeric}     = -4;
        BassSlope0DbPerDb           single      {mustBeNonnegative} = 0.65;
        BassSlope1DbPerDb           single      {mustBeNonnegative} = 0.75;
        BassDownwardThreshDbspl     single      {mustBeNonnegative} = 40; 
        BassDownwardSlopeDbPerDb    single      {mustBeNonnegative} = 1.25;
        BassMaxAudiopilotBoostDb    single      {mustBeNonnegative} = 20;

        BassMaxTotalBoostDb         single      {mustBeNonnegative} = 40;
        
        % Mid Band
        MidrangeThresh0Db           single      {mustBeNumeric}     = -4.5;
        MidrangeThresh1Db           single      {mustBeNumeric}     = -5.5;
        MidrangeSlope0DbPerDb       single      {mustBeNonnegative} = 0.52;
        MidrangeSlope1DbPerDb       single      {mustBeNonnegative} = 0.80;
        MidrangeDownwardThreshDbspl     single  {mustBeNonnegative} = 40;
        MidrangeDownwardSlopeDbPerDb    single  {mustBeNonnegative} = 1;
        MidrangeMaxTotalBoostDb     single      {mustBeNonnegative} = 20; 
        
        % Treble band (wide band)
        TrebleThresh0Db             single      {mustBeNumeric}     = -7;
        TrebleThresh1Db             single      {mustBeNumeric}     = -7.5;
        TrebleSlope0DbPerDb         single      {mustBeNonnegative} = 0.35;
        TrebleSlope1DbPerDb         single      {mustBeNonnegative} = 0.50;
        TrebleDownwardThreshDbspl   single      {mustBeNonnegative} = 43;
        TrebleDownwardSlopeDbPerDb  single      {mustBeNonnegative} = 1;
        TrebleMaxTotalBoostDb       single      {mustBeNonnegative} = 14;
        
        % Enable Switch Ramper
        EnableRampTauSec            single      {mustBePositive}    = 0.1; 
        
        % Enable RTC Responses
        EnableRtcResponse           logical     = 0;
    end
    
    properties(Dependent = true)
        % These are the properties that are not settable, but are, instead,
        % computed from other settable properties.
                
        FrameRateHz                 single      {mustBePositive};       
    end
    
    methods
        function obj = GainCalculationConfig()
        end
        
        % The get functions for the non-settable properties.                 
                
        function value = get.FrameRateHz(obj)
            value = obj.SampleRateHz / obj.FrameSize;
        end
        
        function Validate(obj)
            % This function performs a self consistency check on the
            % property data in the object.  It should be invoked
            % only after the object is fully populated.
            
            if (obj.LfNoiseLowBoundDbspl > obj.LfNoiseHighBoundDbspl)
                error('LF Noise High Bound should be larger than the Low Bound');
            end
            
            if (obj.HfNoiseLowBoundDbspl > obj.HfNoiseHighBoundDbspl)
                error('HF Noise High Bound should be larger than the Low Bound');
            end
            obj.Validate@BtcBaseClass();
        end
    end
end

function mustBe0or1(a)
    % This is a property validation function
    if ((a~=0)&&(a~=1))
        error('Value assigned must be 0 or 1');
    end
end