function ExportToTools(~)
% ExportToTools masquerades as a classdef property validation, but only flags
% build-time-configuration properties that we wish to export to the tools.
% The ExtractToolsApiBtc function uses this property flag to work.
%
% See also: ExtractModelBtcToolsExport
