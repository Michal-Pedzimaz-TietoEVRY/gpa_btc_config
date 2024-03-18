classdef WiggleDelayClass
    %WiggleDelayClass contains properties and functions for the Simulink WiggleDelayLib
    % model
    
    properties (Constant)
        MS_PER_SECOND = 1000;
        MAX_DELAY_MS = 60;
end
    
    properties
        delaySamples
        maxDelaySamples
        sampleRate
        channelCount;
        unitDelayMs
        
    end
    
    methods
        % Constructor
        function obj = WiggleDelayClass(delaySamples, numChannels, sampleRate)

            obj.channelCount = numChannels;
            obj.sampleRate = sampleRate;
            
            obj.unitDelayMs = WiggleDelayClass.MS_PER_SECOND/sampleRate;
            
            obj.maxDelaySamples = int32(WiggleDelayClass.MAX_DELAY_MS/obj.unitDelayMs);
           

            obj.delaySamples = delaySamples;
        end
        
        function obj = SetDelayInMilliseconds(obj, delayInMs)
            obj.delaySamples = int32(delayInMs/obj.unitDelayMs);
        end
    end
end
