%---------------------------------------------------------------------
%
%  COPYRIGHT BOSE CORPORATION ALL RIGHTS RESERVED
%  This program may not be reproduced, in whole or in part in any
%  form or any means whatsoever without the written permission of:
%
%     BOSE CORPORATION
%     The Mountain
%     Framingham, MA 01701-9168
%
%---------------------------------------------------------------------

function build_model_cmdline(prj_file, model_name, model_build_parallel)
% BUILD_MODEL_CMDLINE Call build_model from the cygwin shell
%    BUILD_MODEL_CMDLINE(PRJ_FILE, MODEL_NAME) calls
%    build_model.m. This script is simplified from previous version due to
%    the ability to launch Matlab with the -batch switch, which
%    automatically pipes things to stdout/stderr.
%    PRJ_FILE is a string name of the Simulink Project file.
%    MODEL_NAME is the name of the Simulink model to build.
    open(prj_file);
    partition_and_generate(model_name, '-t32 -i32');
    bdclose all;
end

