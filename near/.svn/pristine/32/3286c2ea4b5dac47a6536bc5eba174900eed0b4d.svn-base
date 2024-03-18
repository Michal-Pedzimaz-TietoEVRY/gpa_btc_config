classdef NEARClass
    properties
        sample_rate_in_hertz
        frame_size
        ann_sysin_channel_count
        front_peripheral_channel_count
        NEAR1p1FrontPeripheralChannelCountFullRate
        headrest_count
        channels_per_headrest
        decimation_factor
        rear_channel_count
        vm
        NearWbAnnCount
        NearPhoneCount
        
        % Not required as constructor args
        decimated_frame_size
        decimated_sample_rate_in_hertz
    end
    
    methods
        function obj = NEARClass(...
            sample_rate_in_hertz,...
            frame_size,...
            ann_sysin_channel_count,...
            front_peripheral_channel_count,...
            headrest_count,...
            decimation_factor,...
            rear_channel_count,...
            vm)
            if nargin==8
                obj.sample_rate_in_hertz = sample_rate_in_hertz;
                obj.frame_size = frame_size;
                obj.ann_sysin_channel_count = ann_sysin_channel_count;
                obj.front_peripheral_channel_count = front_peripheral_channel_count;
                obj.headrest_count = headrest_count;
                obj.decimation_factor = decimation_factor;
                obj.rear_channel_count = rear_channel_count;
                obj.vm = vm;
                
                obj.decimated_frame_size = frame_size/decimation_factor;
                obj.decimated_sample_rate_in_hertz = sample_rate_in_hertz/decimation_factor;
            end 
        end
    end
end




