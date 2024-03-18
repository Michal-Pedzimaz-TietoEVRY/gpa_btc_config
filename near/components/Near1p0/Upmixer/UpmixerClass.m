classdef UpmixerClass
    properties
        ann_sysin_channel_count
        front_peripheral_channel_count
        headrest_count
        channels_per_headrest
        mix
        loc_init
        eqdelays
        interp
    end
    
    methods
        function obj = UpmixerClass(...
            ann_sysin_channel_count, ...
            front_peripheral_channel_count, ...
            headrest_count, ...
            channels_per_headrest, ...
            mix, ...
            loc_init, ...
            eqdelays, ...
            interp)
            if nargin==8
                obj.ann_sysin_channel_count = ann_sysin_channel_count;
                obj.front_peripheral_channel_count = front_peripheral_channel_count;
                obj.headrest_count = headrest_count;
                obj.channels_per_headrest = channels_per_headrest;
                obj.mix = mix;
                obj.loc_init = loc_init;
                obj.eqdelays = eqdelays;
                obj.interp = interp;
            end 
        end
    end
end




