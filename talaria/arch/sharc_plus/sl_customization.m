function sl_customization(cm)
% SL_CUSTOMIZATION for SharcPlus target

%   Copyright 2019 Bose Corporation

cm.registerTargetInfo(@loc_createConfig);

end

function config = loc_createConfig
% Register the SharcPlus PIL configuration
config = rtw.connectivity.ConfigRegistry;
config.ConfigName = 'SharcPlus PIL';
config.ConfigClass = 'SharcPlusPILConfig.ConnectivityConfig';

% match only ert.tlc
config.SystemTargetFile = {'ert.tlc'};

% match any template makefile
config.TemplateMakefile = {};

% match using the host-based toolchains
info = get_sc58x_ToolChainInfo();
config.Toolchain = {info.ToolChainName};

% match regular 32-bit machines and Custom for e.g. 64-bit Linux
config.TargetHWDeviceType = {'Analog Devices-SharcPlus'};

end

%--------------------------------------------------------------------------
% Regarding ***SharcPlus*** :
% See "target.upgrade" and the impending doom of "RTW.HWDeviceRegistry"
% The function to setup the SharcPlus target processor that used to be here
% gone. Replaced instead by "registerTargetProcessors" and handled as part
% of project startup and shutdown.
%--------------------------------------------------------------------------
