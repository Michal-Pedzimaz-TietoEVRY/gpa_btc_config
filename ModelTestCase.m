classdef ModelTestCase < TalariaTest
%VOLUMETESTCASE Test cases for volume block

    methods(TestMethodSetup)
        function init(self)
           % Set the model name so the test runner knows what model to run
           self.setModelName('Model');

           % Set the testcase projectPath based on this script's location
           [current_path, ~] = fileparts(mfilename('fullpath'));
           self.projectPath = current_path;
        end
    end % methods(TestMethodSetup)

    methods (Test)
        function Test(self)
           self.setStopTime(1);
           self.simulateModel;
        end

    end % methods(Test)



end
