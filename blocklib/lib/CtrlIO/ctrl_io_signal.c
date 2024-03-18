/*
Copyright 2023 Bose Corporation
Contact: Michal Pedzimaz (michal_pedzimaz@bose.com)
$Revision: 4 $ $Date: 2023-12-29 12:04:52 (Fri, 29 Dec 2023) $
*/

#define S_FUNCTION_LEVEL              2
#define S_FUNCTION_NAME               ctrl_io_signal

#define NUM_DISC_STATES               0
#define DISC_STATES_IC                [0]
#define NUM_CONT_STATES               0
#define CONT_STATES_IC                [0]

#define NUM_INPUTS                    3
#define NUM_OUTPUTS                   1

#define INPUT_STRAIGHT_INDEX          0
#define INPUT_BYPASS_INDEX            1
#define INPUT_MODE_INDEX              2
#define OUTPUT_SIGNAL_INDEX           0


#include "simstruc.h"


/*====================*
 * S-function methods *
 *====================*/
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
  uint8_T i;  

  ssSetNumSFcnParams(S, 0);
  if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) 
  {
	  return;
  }

  ssSetArrayLayoutForCodeGen(S, SS_ALL);
  ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);
  ssSetNumContStates(S, NUM_CONT_STATES);
  ssSetNumDiscStates(S, NUM_DISC_STATES);
  if (!ssSetNumInputPorts(S, NUM_INPUTS)) 
  {
	  return;
  }
  /* Input Port 0 and 1 (STRAIGHT, BYPASS) */
  for(i = 0; i < 2; i++) 
  {
    //i == 0 -> STRAIGHT input
    //i == 1 -> BYPASS input
    ssSetInputPortMatrixDimensions(S, i, DYNAMICALLY_SIZED, DYNAMICALLY_SIZED);
    ssSetInputPortDataType(S, i, SS_SINGLE);
    ssSetInputPortComplexSignal(S, i, COMPLEX_NO);
    ssSetInputPortSampleTime(S, i, INHERITED_SAMPLE_TIME);
    ssSetInputPortOffsetTime(S, i, 0.0);
    ssSetInputPortDirectFeedThrough(S, i, 1);
    ssSetInputPortRequiredContiguous(S, i, 1);
  }

  /* Input Port 2 (MODE) */
  ssSetInputPortWidth(S, INPUT_MODE_INDEX, 1);
  ssSetInputPortDataType(S, INPUT_MODE_INDEX, SS_INT32);
  ssSetInputPortComplexSignal(S, INPUT_MODE_INDEX, COMPLEX_NO);
  ssSetInputPortDirectFeedThrough(S, INPUT_MODE_INDEX, 1);
  ssSetInputPortRequiredContiguous(S, INPUT_MODE_INDEX, 1);

  if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) 
  {
	  return;
  }

  /* Output Port 0 */
  ssSetOutputPortMatrixDimensions(S, OUTPUT_SIGNAL_INDEX, DYNAMICALLY_SIZED, DYNAMICALLY_SIZED);
  ssSetOutputPortDataType(S, OUTPUT_SIGNAL_INDEX, SS_SINGLE);
  ssSetOutputPortComplexSignal(S, OUTPUT_SIGNAL_INDEX, COMPLEX_NO);
  ssSetOutputPortSampleTime(S, OUTPUT_SIGNAL_INDEX, INHERITED_SAMPLE_TIME);
  ssSetOutputPortOffsetTime(S, OUTPUT_SIGNAL_INDEX, 0.0);
  
  /* S-Function Settings */
  ssSetNumPWork(S, 0);
  ssSetNumSampleTimes(S, 1);
  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumNonsampledZCs(S, 0);

  ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_ALLOW_CONSTANT_PORT_SAMPLE_TIME));
}

#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_DIMENSION_INFO

static void mdlSetInputPortDimensionInfo(
  SimStruct *S,
  int_T port,
  const DimsInfo_T *dimsInfo)
{
  int_T *uDims = dimsInfo->dims;
  int myDims[2], nFrame;
  DECL_AND_INIT_DIMSINFO(myDimsInfo);
  if (!ssSetInputPortDimensionInfo(S, port, dimsInfo)) 
  {
	  return;
  }
  
  //Here the output signal port size is configured - the same dimensions as the STRAIGHT input
  if (port == INPUT_STRAIGHT_INDEX)
  {
    nFrame = (((int*)ssGetInputPortDimensions(S, INPUT_STRAIGHT_INDEX))[0]);
    // Set output port dimensions, the same as STRAIGHT input
    myDimsInfo.dims = myDims;
    myDimsInfo.numDims = 2;
    myDimsInfo.width = nFrame * uDims[1];
    myDims[0] = nFrame;
    myDims[1] = uDims[1];
    if (!ssSetOutputPortDimensionInfo(S, OUTPUT_SIGNAL_INDEX, &myDimsInfo)) 
	{
		return;
	}
  }
}

#endif

#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO
#if defined(MDL_SET_OUTPUT_PORT_DIMENSION_INFO)

static void mdlSetOutputPortDimensionInfo(SimStruct *S,
  int_T port,
  const DimsInfo_T *dimsInfo)
{
  if (!ssSetOutputPortDimensionInfo(S, port, dimsInfo)) 
  {
	  return;
  }
}
#endif

#define MDL_SET_DEFAULT_PORT_DIMENSION_INFO

static void mdlSetDefaultPortDimensionInfo(SimStruct *S)
{
  /* Straight input */
  if (ssGetInputPortWidth(S, INPUT_STRAIGHT_INDEX) == DYNAMICALLY_SIZED) {
      if (!ssSetInputPortMatrixDimensions(S, INPUT_STRAIGHT_INDEX, 1, 1)) 
	  {
		  return;
	  }
  }
  /* Bypass input */
  if (ssGetInputPortWidth(S, INPUT_BYPASS_INDEX) == DYNAMICALLY_SIZED) {
      if (!ssSetInputPortMatrixDimensions(S, INPUT_BYPASS_INDEX, 1, 1)) 
	  {
		  return;
	  }
  }
  /* The MODE input is hardcoded to be 1x1 dimension */
  
  /* Signal output */
  if (ssGetOutputPortWidth(S, OUTPUT_SIGNAL_INDEX) == DYNAMICALLY_SIZED) {
      if (!ssSetOutputPortMatrixDimensions(S, OUTPUT_SIGNAL_INDEX, 1, 1)) 
	  {
		  return;
	  }
  }
  return;
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
  ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
  ssSetModelReferenceSampleTimeDefaultInheritance(S);
  ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE

static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
  ssSetInputPortDataType(S, 0, dType);
}

#define MDL_SET_OUTPUT_PORT_DATA_TYPE

static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
  ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES

static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  ssSetInputPortDataType(S, 0, SS_DOUBLE);
  ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  const real32_T *straight_ptr = (real32_T *) ssGetInputPortRealSignal(S, INPUT_STRAIGHT_INDEX);
  const real32_T *bypass_ptr = (real32_T *) ssGetInputPortRealSignal(S, INPUT_BYPASS_INDEX);
  const int32_T *mode_ptr = (int32_T *) ssGetInputPortRealSignal(S, INPUT_MODE_INDEX);  
  real32_T *output_ptr = (real32_T *) ssGetOutputPortRealSignal(S, OUTPUT_SIGNAL_INDEX);
  uint32_T frame_size = (((uint32_T *)ssGetInputPortDimensions(S, INPUT_STRAIGHT_INDEX))[0]);
  uint32_T nChStraight = (((uint32_T *)ssGetInputPortDimensions(S, INPUT_STRAIGHT_INDEX))[1]);
  uint32_T nChBypass = (((uint32_T *)ssGetInputPortDimensions(S, INPUT_BYPASS_INDEX))[1]);
  uint8_T i;
  real32_T *ch_out_ptr, *ch_bypass_ptr;

  #define NUM_BYTES_PROCESS (sizeof(float) * frame_size * nChStraight)

  //STRAIGHT mode
  if (*mode_ptr > 0) 
  { 
	memcpy((void *)output_ptr, (void *)straight_ptr, NUM_BYTES_PROCESS);
  }
  //BYPASS mode
  else if (*mode_ptr < 0) 
  {
      //equal number of input and output channel in a block
      if (nChStraight == nChBypass) 
	  {
		  memcpy((void *)output_ptr, (void *)bypass_ptr, NUM_BYTES_PROCESS);
	  }
      //different number of input and output channel in a block - copy input to output channels in a circular manner
      else
      {
          for (i=0; i<nChStraight; i++)
          {
              ch_out_ptr = output_ptr + frame_size * i;
              ch_bypass_ptr = (real32_T *)bypass_ptr + (i % nChBypass) * frame_size;
              memcpy((void *)ch_out_ptr, (void *)ch_bypass_ptr, (sizeof(float) * frame_size));
          }
      }
  }
  //MUTE mode
  else 
  {
	  memset(output_ptr, 0x00, NUM_BYTES_PROCESS);
  }
}

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
}

/* The following code is required by Simulink to compile the S-Function */

#ifdef MATLAB_MEX_FILE                 /* Is this file being compiled as a MEX-file? */
#include "simulink.c"                  /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"                   /* Code generation registration function */
#endif
