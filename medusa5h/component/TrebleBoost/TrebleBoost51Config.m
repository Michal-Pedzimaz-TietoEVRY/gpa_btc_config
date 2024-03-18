classdef TrebleBoost51Config < TrebleBoostStereoConfig
% TrebleBoost51Config Build-time configuration class for the
%   TrebleBoost51 block. The surroud version of the treble boost block
%   does the exact same thing that the Stereo version does but simply
%   selects the first two channels from the 6-channel input. There's no
%   extra properties or configuration needed. This file exsits to conform
%   to the BTC convention that each block has it's own config class.
% 
% Usage:
%    aConfig = TrebleBoost51Config
%

%   Copyright 2023 Bose Corporation
end
