#
#   BOSE CORPORATION
#   COPYRIGHT (c) BOSE CORPORATION ALL RIGHTS RESERVED
#   This program may not be reproduced, in whole or in part in an
#   form or any means whatsoever without the written permission of:
#
#       BOSE CORPORATION
#       The Mountain
#       Framingham, MA 01701-9168
#
################################################################################

################################################################################
# These should defined by the file including this
################################################################################

# TALARIA_ROOT_DIR
# PROJECT_DIR
# API_DIR

################################################################################
# Path definitions
################################################################################

MODEL_NAME          := Model
MODEL_DIR           := $(APP_MODEL_DIR)/model
code_gen_dir        := $(MODEL_DIR)/code
model_parts_dir     := $(MODEL_DIR)/parts

generated_files     :=
generated_dirs      := $(code_gen_dir) $(model_parts_dir)

################################################################################
# Pull in Talaria make info
################################################################################

include $(TALARIA_ROOT_DIR)/talaria.mk

################################################################################
# Vars
################################################################################

post_build_witness_file := .post_build_check
core_tags               := 1_1 1_2 2_1 2_2
core_nums               := 1 2 3 4
model_code_dir_suffix   := ert_shrlib_rtw

################################################################################
# Post build header files to copy
################################################################################

# [TODO] Update to latest version of Talaria which should reduce the number of these

api_header_file         := TalariaAPI.h
rtw_types               := rtwtypes.h   
asdid                   := ASDID.h
cross_core_api          := TalariaCrossCore.h
core_api_header_files   := $(foreach core_id,$(core_tags),$(MODEL_NAME)_$(core_id)_$(api_header_file))
core_cross_core_api     := $(foreach core_id,$(core_tags),$(MODEL_NAME)_$(core_id)_$(cross_core_api))

translation_engine      := $(MODEL_NAME)_TranslationEngine64_win64.dll
interpretation_engine   := $(MODEL_NAME)_InterpretationEngine64_win64.dll

xml_file_types          := StateVar TOP_Tokens TSP TSP_Tokens TuneVar
xml_files               := $(addsuffix .xml,$(addprefix $(MODEL_NAME)_,$(xml_file_types)))


################################################################################
# Recipes
################################################################################

all: $(witness_file) $(post_build_witness_file)
	@echo "Talaria build complete"

$(post_build_witness_file): $(witness_file)
	@echo "Running post build steps"
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(api_header_file) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(api_header_file) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(api_header_file) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(api_header_file) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(word 1,$(core_api_header_files)) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(word 2,$(core_api_header_files)) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(word 3,$(core_api_header_files)) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(word 4,$(core_api_header_files)) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(rtw_types) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(rtw_types) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(rtw_types) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(rtw_types) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(asdid) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(asdid) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(asdid) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(asdid) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(cross_core_api) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(cross_core_api) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(cross_core_api) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(cross_core_api) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 1,$(core_tags))_$(model_code_dir_suffix)/$(word 1,$(core_cross_core_api)) \
            $(API_DIR)/core$(word 1,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 2,$(core_tags))_$(model_code_dir_suffix)/$(word 2,$(core_cross_core_api)) \
            $(API_DIR)/core$(word 2,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 3,$(core_tags))_$(model_code_dir_suffix)/$(word 3,$(core_cross_core_api)) \
            $(API_DIR)/core$(word 3,$(core_nums))/inc
	@cp $(code_gen_dir)/$(MODEL_NAME)_$(word 4,$(core_tags))_$(model_code_dir_suffix)/$(word 4,$(core_cross_core_api)) \
            $(API_DIR)/core$(word 4,$(core_nums))/inc

	@cp -r $(code_gen_dir)/$(MODEL_NAME)_Control $(API_DIR)

	@if [ -a $(code_gen_dir)/$(translation_engine) ]; then cp $(code_gen_dir)/$(translation_engine) $(API_DIR)/common/lib; fi
	@if [ -a $(code_gen_dir)/$(interpretation_engine) ]; then cp $(code_gen_dir)/$(interpretation_engine) $(API_DIR)/common/lib; fi

	@cp $(addprefix $(code_gen_dir)/,$(xml_files)) $(API_DIR)/common/doc
	@touch $@

