classdef GainApplicationConfig < BtcBaseClass
    % GainApplicationConfig
    % Configuration Parameters for Gain Application Block
 
    properties(GetAccess = public, SetAccess = public,GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the Gain Application block.

        SampleRateHz                {mustBePositive}                = 44100;
        FrameSize                   {mustBePositive,mustBeInteger}  = 32;

        % Zipper noise reduction filter
        AntizipperRampFreqHz        single  {mustBePositive}    = 200;
        
        % Bass band BPF
        BassBpfCenterFreqHz         single  {mustBePositive}    = 40;
        BassBpfQ                    single  {mustBePositive}    = 1.1;
        
        % Mid band LPF
        MidrangeLpfCutoffFreqHz     single  {mustBePositive}    = 4000;
        MidrangeLpfAlignDelaySamples        single ...
                            {mustBeNonnegative,mustBeInteger}   = 4;
        MidrangeLpfMaxAlignDelaySamples     single ...
                            {mustBeNonnegative,mustBeInteger}   = 6;
    end
       
    methods
        function obj = GainApplicationConfig()
            % Constructor that creates an instance of the
            % GainApplicationConfig class.
         end
 
        function Validate(obj)
            % This function performs a self consistency check on the
            % property data in the object.  It should be invoked
            % only after the object is fully populated.
            
            if (obj.MidrangeLpfCutoffFreqHz < obj.BassBpfCenterFreqHz)
                error(['The midrange LPF Cutoff Frequency should be ' ...
                    ' higher than the bass BPF Center Frequency']);
            end
            
            checkBelowNyquist(obj,'AntizipperRampFreqHz');
            checkBelowNyquist(obj,'BassBpfCenterFreqHz');
            checkBelowNyquist(obj,'MidrangeLpfCutoffFreqHz');
            obj.Validate@BtcBaseClass();
        end
    end     
    methods (Access = protected)        
        function checkBelowNyquist(obj,freqName)
            if (obj.(freqName) > (obj.SampleRateHz / 2))
                error([freqName ' must be within Nyquist']);
            end
        end
    end      
end



