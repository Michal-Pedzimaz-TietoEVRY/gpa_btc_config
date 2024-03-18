###########################################################################
## Makefile generated for component 'Model_Target'. 
## 
## Makefile     : Model_Target.mk
## Generated on : Wed Mar 06 16:08:14 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Model_Target_win64.dll
## Product type : shared library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# DEF_FILE                Definition file

PRODUCT_NAME              = Model_Target
MAKEFILE                  = Model_Target.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/volvo_gpa_ip4/ModelConfigHERA2144/application/model/code
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = Model_Target_comp.rsp
CMD_FILE                  = Model_Target.rsp
DEF_FILE                  = $(PRODUCT_NAME).def
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Model_Target_win64.dll
PRODUCT_TYPE = "shared library"
BUILD_TYPE = "Shared Library Target"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=Model_Target -DNUMST=9 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Model_Target_ert_shrlib_rtw/blkutil.c $(START_DIR)/Model_Target_ert_shrlib_rtw/fir_hexagon.c $(START_DIR)/Model_Target_ert_shrlib_rtw/fireven_hexagon.c flt_bkfir.S flt_iir_cas_bq.S $(START_DIR)/Model_Target_ert_shrlib_rtw/pooliir_hexagon.c $(START_DIR)/Model_Target_ert_shrlib_rtw/qhdsp_fft_internal.c qhdsp_fir_af_bose.S $(START_DIR)/Model_Target_ert_shrlib_rtw/rfft_hexagon.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Enabled.c $(START_DIR)/Model_Target_ert_shrlib_rtw/FFTBuffers.c $(START_DIR)/Model_Target_ert_shrlib_rtw/FirStorage.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Ifir.c $(START_DIR)/Model_Target_ert_shrlib_rtw/MedusaExpandTailComps.c $(START_DIR)/Model_Target_ert_shrlib_rtw/MedusaPostHoligram.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_FirGenericStorage.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_InputSelect_p0_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_Near_p0_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_Partitions.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PostProcess_p0_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p0_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p10_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p10_b1_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p11_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p13_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p1_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p2_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p3_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p4_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p5_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p6_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p6_b1_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p8_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p9_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_RTC_NTF.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_RTC_REQ_RSP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_SCH_API.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_StructStaticInit.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TOP_Access.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TSP_Capture.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TalariaAPI.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TestRouter_p0_b0_TOP.c $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_data.c $(START_DIR)/Model_Target_ert_shrlib_rtw/PoolDelayStorage.c $(START_DIR)/Model_Target_ert_shrlib_rtw/PostProcess.c $(START_DIR)/Model_Target_ert_shrlib_rtw/PostProcess_data.c $(START_DIR)/Model_Target_ert_shrlib_rtw/VLS.c $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_530.c $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_535.c $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_536.c $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_543.c $(START_DIR)/Model_Target_ert_shrlib_rtw/rtmodel.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = blkutil.obj fir_hexagon.obj fireven_hexagon.obj flt_bkfir.S flt_iir_cas_bq.S pooliir_hexagon.obj qhdsp_fft_internal.obj qhdsp_fir_af_bose.S rfft_hexagon.obj Enabled.obj FFTBuffers.obj FirStorage.obj Ifir.obj MedusaExpandTailComps.obj MedusaPostHoligram.obj Model_Target.obj Model_Target_FirGenericStorage.obj Model_Target_InputSelect_p0_b0_TOP.obj Model_Target_Near_p0_b0_TOP.obj Model_Target_Partitions.obj Model_Target_PostProcess_p0_b0_TOP.obj Model_Target_PreAmp_p0_b0_TOP.obj Model_Target_PreAmp_p10_b0_TOP.obj Model_Target_PreAmp_p10_b1_TOP.obj Model_Target_PreAmp_p11_b0_TOP.obj Model_Target_PreAmp_p13_b0_TOP.obj Model_Target_PreAmp_p1_b0_TOP.obj Model_Target_PreAmp_p2_b0_TOP.obj Model_Target_PreAmp_p3_b0_TOP.obj Model_Target_PreAmp_p4_b0_TOP.obj Model_Target_PreAmp_p5_b0_TOP.obj Model_Target_PreAmp_p6_b0_TOP.obj Model_Target_PreAmp_p6_b1_TOP.obj Model_Target_PreAmp_p8_b0_TOP.obj Model_Target_PreAmp_p9_b0_TOP.obj Model_Target_RTC_NTF.obj Model_Target_RTC_REQ_RSP.obj Model_Target_SCH_API.obj Model_Target_StructStaticInit.obj Model_Target_TOP_Access.obj Model_Target_TSP_Capture.obj Model_Target_TalariaAPI.obj Model_Target_TestRouter_p0_b0_TOP.obj Model_Target_data.obj PoolDelayStorage.obj PostProcess.obj PostProcess_data.obj VLS.obj rt_sys_Enabled_530.obj rt_sys_Enabled_535.obj rt_sys_Enabled_536.obj rt_sys_Enabled_543.obj rtmodel.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#----------------------------------------
# Create a shared library
#----------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating shared library "$(PRODUCT)" ..."
	$(LD) $(SHAREDLIB_LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/volvo_gpa_ip4/ModelConfigHERA2144/blocklib/lib/SampleRateConverter/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/volvo_gpa_ip4/ModelConfigHERA2144/blocklib/lib/SampleRateConverter/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/volvo_gpa_ip4/ModelConfigHERA2144/blocklib/arch/hexagon/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/volvo_gpa_ip4/ModelConfigHERA2144/blocklib/arch/hexagon/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


blkutil.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/blkutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fir_hexagon.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/fir_hexagon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fireven_hexagon.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/fireven_hexagon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


pooliir_hexagon.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/pooliir_hexagon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qhdsp_fft_internal.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/qhdsp_fft_internal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rfft_hexagon.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rfft_hexagon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Enabled.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Enabled.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FFTBuffers.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/FFTBuffers.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FirStorage.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/FirStorage.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Ifir.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Ifir.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MedusaExpandTailComps.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/MedusaExpandTailComps.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MedusaPostHoligram.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/MedusaPostHoligram.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_FirGenericStorage.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_FirGenericStorage.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_InputSelect_p0_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_InputSelect_p0_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_Near_p0_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_Near_p0_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_Partitions.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_Partitions.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PostProcess_p0_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PostProcess_p0_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p0_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p0_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p10_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p10_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p10_b1_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p10_b1_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p11_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p11_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p13_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p13_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p1_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p1_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p2_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p2_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p3_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p3_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p4_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p4_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p5_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p5_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p6_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p6_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p6_b1_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p6_b1_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p8_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p8_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_PreAmp_p9_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_PreAmp_p9_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_RTC_NTF.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_RTC_NTF.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_RTC_REQ_RSP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_RTC_REQ_RSP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_SCH_API.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_SCH_API.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_StructStaticInit.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_StructStaticInit.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_TOP_Access.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TOP_Access.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_TSP_Capture.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TSP_Capture.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_TalariaAPI.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TalariaAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_TestRouter_p0_b0_TOP.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_TestRouter_p0_b0_TOP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Model_Target_data.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/Model_Target_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PoolDelayStorage.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/PoolDelayStorage.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PostProcess.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/PostProcess.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PostProcess_data.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/PostProcess_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


VLS.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/VLS.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_Enabled_530.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_530.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_Enabled_535.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_535.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_Enabled_536.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_536.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_Enabled_543.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rt_sys_Enabled_543.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtmodel.obj : $(START_DIR)/Model_Target_ert_shrlib_rtw/rtmodel.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


