function createAssemblyCRL()
%CREATEASSEMBLYCRL Creates a static library containing assembly CRL
%functions

% List of functions to put in library. Specifically, the assembly file name
functions = {'pooliirSharcPlus', ...
             'FirEvenProcessSharc_Plus', ...
             'IFirProcessSharc_plus',...
             'fir_vec_mc_21XI',...
             'fir_core',...
             'upfirProcessSharc_plus'};

% Creat object files list based on function list
objectFiles = cell(size(functions));
for i = 1:numel(functions)
    objectFiles{i} = [functions{i} '.doj'];
end

% Specify the library generated by the model
inputLibName = 'assembly_crl_win64.dlb';
codeGenDir = Simulink.fileGenControl('get', 'CodeGenFolder');
inputLib = fullfile(codeGenDir, inputLibName);

% Build the model with all the assembly CRL content
rtwbuild('assembly_crl');

% Get a list of object files in the library
archiver = ['"' getenv('CCES_DIR') '\elfar.exe"'];
listCmd = [archiver ' -p ' inputLib];
files = runCmd(listCmd);

% Go through the list and determine what stays and goes
filesInLib = split(files);
filesToRemove = {};
found = zeros(1,numel(objectFiles));
for i = 1:numel(filesInLib)
    filename = filesInLib{i};
    removeFromLib = 1;
    
    % Look for this in the list 
    for j = 1:numel(objectFiles)
        objectFile = objectFiles{j};
        if strcmp(objectFile, filename)
            found(j) = 1;
            removeFromLib = 0;
        end
    end
    
    % Add to the remove list if not found
    if removeFromLib
        filesToRemove{end+1} = filesInLib{i};
    end
end

% Flag an error if any object files weren't found
if any(~found)
    badIndex = find(~found);
    if numel(badIndex) > 1
        badIndex = badIndex(1);
    end
    error('Could not find %s', functions{badIndex});
end

% Copy library to this directory
outputLibName = 'libcrlassembly.dlb';
outputLib = fullfile(fileparts(mfilename('fullpath')), outputLibName);
copyfile(inputLib, outputLib);

% Run command to remove files from the library
cmd = [archiver ' -d ' outputLib];
for i = 1:numel(filesToRemove)
    cmd = [cmd ' ' filesToRemove{i}];
end
runCmd(cmd);

disp(['Library ' outputLibName ' created successfully']);

end

function reply = runCmd(cmd)
% RUNCMD Runs system command, and prints error message if one occured
[status, reply] = system(cmd);
if (status ~= 0)
    error(['Error running ' cmd ' : ' reply]);
end
end