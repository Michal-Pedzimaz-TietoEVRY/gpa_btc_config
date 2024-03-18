% This is a script to run BalanceTest for verification.
clear;
% Model name
model_name = 'Model';
% Test Case file name
testcase_filename = 'ModelTestCase.m';
% Test Case function name
testcase_stu = struct();
testcase_stu(1).name = 'Test';
testcase_stu(1).codegen = 0;


% X86, DSP_HEXAGON, ARM_ANDROID, ARM_QNX, DSP_GUL
profiling_platform = 'DSP_HEXAGON';
% software, hadware
profiling_type = 'software';
% Model relative path 
model_relative_path = '\application\model';
% Frame Size
frame_size = 32;
% Build Option
build_option = '-Wno-unused-variable -Wno-unused-function -Wno-undefined-optimized -Wno-incompatible-pointer-types -Wno-tautological-compare -Wno-strict-prototypes -DABCDEF=1';

currproj = matlab.project.rootProject;
model_path = fullfile(currproj.RootFolder, model_relative_path);
%curr_path = pwd;
model_file_name = strcat(model_name, '.slx');
model_full_path = fullfile(model_path, model_file_name);
model_cfg_file = fullfile(model_path, strcat(model_name, '_Cfg.json'));
% Check the existance of the model
if isfile(model_full_path)
    % Detect Python automatically
    %[~, pypath] = system('where python3');
    %pypath = regexprep(pypath,'[\n\r]+','');
    %if ~isempty(pypath)
    %    pyarr = strsplit(pypath, '\n');
    %    pystr = char(pyarr(1));
    %    if endsWith(pystr, '.exe')
    %        disp('Python3 found....');
    %        ja = JArtemis;
    %        tool_cfg = ja.JA_ReadToolCfg(currproj.RootFolder);
    %        %tool_cfg.Python.path = "C:/Program Files/Python311/python3.exe";strrep(pystr, '\', '/');
    %        ja.JA_WriteToolCfg(currproj.RootFolder, tool_cfg);
    %    else
    %        disp('Cannot find Python3 EXE, the default python in userprofile/ToolCfg.json is used.');
    %    end
    %else
    %    disp('Cannot find Python3 EXE, the default python in userprofile/ToolCfg.json is used.');
    %end
    ja = JArtemis;
    tool_cfg = ja.JA_ReadToolCfg(currproj.RootFolder);
    %tool_cfg.Python.path = "C:/Program Files/Python311/python3.exe";
    tool_cfg.Python.path = "C:/Python37/python.exe";
    ja.JA_WriteToolCfg(currproj.RootFolder, tool_cfg);

    % clear the model if model configuration file exists
    jaclearFunc(model_name, model_relative_path);
    % load and open Simulink model
    disp('LOG: Open Simulink Model and Run Simulation....');
    try
        load_system(model_full_path);
        open_system(model_full_path);
        % Run simulation
        sim_out = sim(model_name);
    catch
        disp('Simulation ERROR: Please check the log in command window.');
        return;
    end
    % Call JArtemis to generate Model Configuration File
    disp('LOG: Call JArtemis to scan the Model and generate Configuration File....');
    ret = jasyncFunc();
    if ret == false
        disp('JArtemis Sync ERROR.');
        return;
    end
    % Add TestCases
    testcase_full_path = fullfile(currproj.RootFolder, testcase_filename);
    if isfile(testcase_full_path)
        disp('LOG: Call JArtemis to run MIL and add testcase to Configuration File....');
        % Run MIL and Add each test case
        for i = 1:length(testcase_stu)
            ret = jatestcaseBtcFunc(testcase_full_path, testcase_stu(i).name, model_cfg_file, model_path, testcase_stu(i).codegen);
            if ret == false
                disp('JArtemis adding testcase ERROR.');
                return;
            end
        end
    else
        disp('===================================');
        disp('ERROR: No XXXXTestCase.m file found.');
        return;
    end

    % Run Partition and Generate
    disp('LOG: Run Partition_And_Generate');
    try
        partition_and_generate(model_name, '+c +p');
    catch
        disp('Partition and Generate ERROR: Please check log in command window.');
        return;
    end
    % Configure Build Option
    ret = jabuildoptFunc(profiling_platform, build_option);
    if ret == false
        disp('JArtemis adding build option error.');
        return;
    end
    % Call JArtemis to generate platform C code
    disp('LOG: Call JArtemis to generate platform code.');
    vl = jagenFunc(model_path, model_name, 'Target');
    if vl == false
        disp('JArtemis generating Platform C code error.');
        return;
    end
    for i = 1:length(testcase_stu)
        % Call JArtemis to add profiling
        disp('LOG: Call JArtemis to add profiling');
        jaaddprofileBtcFunc(model_name, model_path, profiling_platform, profiling_type, testcase_stu(i).name);
        disp('LOG: Call JArtemis to run profiling for testcase');
    	jabuildFunc(model_name, model_path, profiling_platform, profiling_type, 'Release', testcase_stu(i).name);
    end
    % Call JArtemis to generate report in HTML
    for i = 1:length(testcase_stu)
        japrofilereportFunc(model_name, 'Target', testcase_stu(i).name);
    end
    % Call JArtemis to generate plot and save as JPEG under "report"
    % folder
    report_path = fullfile(currproj.RootFolder, strcat(model_name, '_Target'), 'report');
    for i = 1:length(testcase_stu)
        japlotrefandoutFunc(model_name, model_path, 'Target', frame_size, testcase_stu(i).name);
        report_file = fullfile(report_path, strcat('plot_', testcase_stu(i).name, '.jpg'));
        saveas(gcf, report_file);
        close;
    end
else
    disp('===================================');
    disp('ERROR: Cannot find model file.'); 
end
