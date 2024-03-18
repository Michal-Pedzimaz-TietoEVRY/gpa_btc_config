function clean_up_project()
%clean_up_project   Clean up local customizations of the environment
%
%   Clean up the environment for the current project. This function undoes
%   the settings applied in "set_up_project". It is set to Run at Shutdown.

% HOWEVER- this code is no longer needed because Simulink Project includes
% settings for cache and codegen folders in project details- doing all this
% automatically including even creating of missing folders.

            % Reset the location where generated code and other temporary files are
            % created (slprj) to the default:
            % Simulink.fileGenControl('reset');
            % 
            % end
            % 

