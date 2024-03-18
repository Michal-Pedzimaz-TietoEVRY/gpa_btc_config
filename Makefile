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
# Set default recipe name to be filled out after including sub-makefile
################################################################################

all:

################################################################################
# Path definitions
################################################################################

TALARIA_ROOT_DIR    := talaria
APP_MODEL_DIR       := application
MODEL_CFG_DIR       := .
PROJECT_DIR         := .
PROJECT_FILE        := $(PROJECT_DIR)/Project.prj

API_DIR             := ../../cars/zinger/images/apis
BOSE_LIB_DIR        := ../../ship/to_qcom/sw_release_10_qcom_dynEQ

################################################################################
# Pull in Talaria make info
################################################################################

# To hide HCI, the command and application content may not be present. To
# determine if this is the case, check on the presence of the project folder.
# If it's not there, don't build anything and just use pre-built binary.

DIR_CHECK           := $(shell if [ -d $(APP_MODEL_DIR) ]; then echo "yes"; else echo "no"; fi)
BOSE_LIB_DIR_CHECK  := $(shell if [ -d $(BOSE_LIB_DIR) ]; then echo "yes"; else echo "no"; fi)

ifeq ($(DIR_CHECK),yes)
  include $(APP_MODEL_DIR)/model.mk
else
  $(error No model content found)
endif
