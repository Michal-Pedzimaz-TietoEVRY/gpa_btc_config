function SetupNearProject
%SETUPNEARPROJECT Set up the Simulink Project

% "Touch" all the *.p files to avoid warnings about bad timestamps
project=currentProject;
thisPath = fileparts(mfilename('fullpath'));
scriptName = fullfile(thisPath,'touch-p-files');
theCmd = sprintf('%s %s', scriptName, project.RootFolder);
[status,result] = system(theCmd);
if (status)
    warning(result);
end

end

