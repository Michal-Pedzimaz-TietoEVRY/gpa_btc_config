classdef FirEvenVariantEnum < BtcVariantEnum
% FirEvenVariantEnum Enumerated listing of BTC variants for FirEven.
% This class collaborates with the BtcBassClassWithVariants and BtcVariant
% classes to enable variant configuration. https://wiki.bose.com/x/Uyo9Cg
% Specify all supported variant choices for this block and the name of the
% classdef (inheriting from BtcVariant) associated with each choice. 

%   Copyright 2023 Bose Corporation

   enumeration
        %. Feel free to replace the first "default" variant (e.g. change class)
        Generic     (1,'BtcVariant')
        Hexagon     (2,'FirEvenHexagonVariantConfig')
        SharcPlus   (3,'BtcVariant')
   end

end