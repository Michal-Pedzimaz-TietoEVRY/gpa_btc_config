/*
 * File: MedusaPostHoligram.h
 *
 * Code generated for Simulink model 'Model_Target'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:05:06 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Qualcomm->Hexagon
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MedusaPostHoligram_h_
#define RTW_HEADER_MedusaPostHoligram_h_
#ifndef Model_Target_COMMON_INCLUDES_
#define Model_Target_COMMON_INCLUDES_
#include <stdlib.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "Model_Target_RTC_IDs.h"
#include "Model_Target_TalariaAPI.h"
#include "Model_Target_TSP_Capture.h"
#include "Model_Target_StructStaticInit.h"
#include "Model_Target_TOP.h"
#endif                                 /* Model_Target_COMMON_INCLUDES_ */

/* Block signals for system '<S559>/MedusaPostHoligram' */
typedef struct
{
    uint32_T CoeffsLengths[88];        /* '<S1305>/GetFirMappings' */
    uint32_T InputMapping[88];         /* '<S1305>/GetFirMappings' */
    uint32_T CoeffsMapping[88];        /* '<S1305>/GetFirMappings' */
    real32_T MatrixConcatenate[176];   /* '<S1296>/Matrix Concatenate' */
    real32_T Merge[768];               /* '<S1296>/Merge' */
    real32_T y_c[768];                 /* '<S1299>/Router' */
    real32_T y_m[704];                 /* '<S1311>/FirGenericProcessFcn' */
    real32_T Output_h[704];            /* '<S1305>/TransformPolphaseOutputs' */
}
B_MedusaPostHoligram_Model_Target_T;

/* Block states (default storage) for system '<S559>/MedusaPostHoligram' */
typedef struct
{
    uint32_T MedusaPostHoligramEnable; /* '<S1296>/Data Store Memory' */
    int8_T If_ActiveSubsystem;         /* '<S1296>/If' */
}
DW_MedusaPostHoligram_Model_Target_T;

/* Extern declarations of internal data for system '<S559>/MedusaPostHoligram' */
extern B_MedusaPostHoligram_Model_Target_T Model_Target_MedusaPostHoligram_B;
extern DW_MedusaPostHoligram_Model_Target_T Model_Target_MedusaPostHoligram_DW;
extern void InitTrigger_Model_150_610_443_99(void);
extern void InitTrigger_Model_150_610_443_224(void);
extern void InitTrigger_Model_150_610_446(void);
extern void HandleReqPreAmpMedusaPostHoligramDisable(void);
extern void Model_Target_MedusaPostHoligram_Init(void);
extern void Model_Target_MedusaPostHoligram(void);

#endif                                 /* RTW_HEADER_MedusaPostHoligram_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
