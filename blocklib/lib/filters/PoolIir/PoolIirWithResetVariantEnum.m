classdef PoolIirWithResetVariantEnum < BtcVariantEnum
% PoolIirWithResetVariantEnum Enumerated listing of BTC variants for PoolIir.
% This class collaborates with the BtcBassClassWithVariants and BtcVariant
% classes to enable variant configuration. https://wiki.bose.com/x/Uyo9Cg

%   Copyright 2023 Bose Corporation

   enumeration
        Generic             (1, 'PoolIirWithResetGenericVariantConfig')
        SharcPlusCore       (2, 'PoolIirWithResetSharcPlusCoreVariantConfig')
        SharcPlusAccelGul   (3, 'PoolIirWithResetSharcPlusAccelGulVariantConfig')
        SharcPlusAccelGxp   (4, 'PoolIirWithResetSharcPlusAccelGxpVariantConfig')
        Hexagon             (5, 'PoolIirWithResetHexagonVariantConfig')
        ArmNeonV7V8         (6, 'PoolIirWithResetArmNeonV7V8VariantConfig')
   end

end