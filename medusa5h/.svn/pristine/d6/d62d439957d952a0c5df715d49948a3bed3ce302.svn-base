function targetGain = MedusaPremixGainComputation(minGain, detentGain, maxGain, interpolationMethod, surroundLevel, ConfigStruct)
% #codegen
    % Extracting the surround level indices correponding to the anchor
    % points from the specified Config Struct
    midIndex = ceil(length(ConfigStruct.granularity)/2);
    
    min_level = ConfigStruct.granularity(1);
    detent_level = ConfigStruct.granularity(midIndex);
    max_level = ConfigStruct.granularity(end);
 
    % Performing bound check on Surround Level value
    surroundLevel = min(surroundLevel, max_level);
        
    % Computing the 'surround' part of mixing gains depending on the surround
    % level index; The other part of mixing gain comes from 'fade downmix'
    switch surroundLevel
        case min_level
            targetGain = minGain;        % when surround index corresponds to 'min' anchor point
        case detent_level
            targetGain = detentGain;     % when surround index corresponds to 'detent' anchor point
        case max_level
            targetGain = maxGain;        % when surround index corresponds to 'max' anchor point
        otherwise
            position = (single(surroundLevel) - min_level)/(max_level - min_level);    % when surround index lies in between the anchor points
            if (interpolationMethod(1) == 0)
                targetGain = (maxGain - minGain)*position + minGain;       % Linear Interpolation
            else
                minGain_dB = 20*log10(max(minGain, eps('single')));
                maxGain_dB = 20*log10(max(maxGain, eps('single')));
                targetGain_dB = (maxGain_dB - minGain_dB)*position + minGain_dB; 
                targetGain = 10.^(targetGain_dB/20);                                      % dB-Linear Interpolation
            end
    end
end