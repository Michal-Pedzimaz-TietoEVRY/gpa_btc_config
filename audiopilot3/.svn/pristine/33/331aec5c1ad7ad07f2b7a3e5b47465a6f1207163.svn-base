classdef CodeImplementationVariant < Simulink.IntEnumType
    % CodeImplementationVariant:
    %   Enumerated class for use in build-time configuration
    % Usage:
    %   Values of type CodeImplementationVariant can be set three ways:
    %   1- By number such as value=2;
    %   2- By name such as value="SharcPlusCore";
    %   3- By scoped class reference such as value=CodeImplementationVariant.SharcPlusCore;
    
    %   (c) Bose Corporation
    
    enumeration
        % There are three implementation types and they have been assigned integer
        % numbers for enhanced backwards/external compatibility
        % Type    Value  Description
        % Generic           1      Generic implementation for other targets without CRL
        % SharcPlusCore     2      Optimized assembly running on core
        % SharcPlusAccel    3      Computing offloaded to accelerator peripheral
        Generic (1) 
        SharcPlusCore (2)
        SharcPlusAccel (3)      
    end
end
