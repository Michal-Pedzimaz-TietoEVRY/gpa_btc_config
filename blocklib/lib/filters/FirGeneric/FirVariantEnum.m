classdef FirVariantEnum < BtcVariantEnum
% FirVariantEnum Enumerated listing of BTC variants for Fir.
% This class collaborates with the BtcBassClassWithVariants and BtcVariant
% classes to enable variant configuration. https://wiki.bose.com/x/Uyo9Cg
% Specify all supported variant choices for this block and the name of the
% classdef (inheriting from BtcVariant) associated with each choice. 

%   Copyright 2023 Bose Corporation

   enumeration
        Generic             (1, 'FirGenericVariantConfig')
        SharcPlusCore       (2, 'FirSharcPlusCoreVariantConfig')
        SharcPlusAccel      (3, 'FirSharcPlusAccelVariantConfig')
        SharcPlusEven       (4, 'FirSharcPlusEvenVariantConfig')
        Hexagon             (5, 'FirHexagonVariantConfig')
        ArmNeonV7V8         (6, 'FirArmNeonV7V8VariantConfig')
   end

end