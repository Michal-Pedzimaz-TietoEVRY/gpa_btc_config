classdef FirUpVariantEnum < BtcVariantEnum
% FirUpVariantEnum Enumerated listing of BTC variants for FirUp.
% This class collaborates with the BtcBassClassWithVariants and BtcVariant
% classes to enable variant configuration. https://wiki.bose.com/x/Uyo9Cg
% Specify all supported variant choices for this block and the name of the
% classdef (inheriting from BtcVariant) associated with each choice. 

%   Copyright 2023 Bose Corporation

   enumeration
        Simulink    (1, 'BtcVariant')                   % Simulink Fir Interpolation Block
        Generic     (2, 'FirUpGenericVariantConfig')    % CRL with custom C code Fir
        Hexagon     (3, 'FirUpHexagonVariantConfig')    % Hexagon CRL. Inherits from Generic Variant
        Simulation  (4, 'BtcVariant')                   % FirUp Implemented in Matlab Fcn Block
        SharcPlus   (5, 'FirUpSharcPlusVariantConfig')
        WithFir     (6, 'FirUpWithFirVariantConfig')    % FirUp Implemented with Blocklib Fir block
   end

end