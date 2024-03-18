/*
 * File: VLS.h
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

#ifndef RTW_HEADER_VLS_h_
#define RTW_HEADER_VLS_h_
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

/* Block signals for system '<S33>/VLS' */
typedef struct
{
    real32_T Add[96];                  /* '<S1473>/Add' */
    real32_T Add_b[96];                /* '<S1474>/Add' */
}
B_VLS_Model_Target_T;

/* Block states (default storage) for system '<S33>/VLS' */
typedef struct
{
    real32_T delayBuffer[600];         /* '<S1476>/Data Store Memory' */
    int32_T delayIndex;                /* '<S1476>/MATLAB Function' */
}
DW_VLS_Model_Target_T;

/* Extern declarations of internal data for system '<S33>/VLS' */
extern B_VLS_Model_Target_T Model_Target_VLS_B;
extern DW_VLS_Model_Target_T Model_Target_VLS_DW;
extern void InitTrigger_Model_232_8_34_50_172_156(void);
extern void InitTrigger_Model_232_8_34_50_172_192(void);
extern void InitTrigger_Model_232_11_239_99(void);
extern void InitTrigger_Model_232_11_239_224(void);
extern void InitTrigger_Model_232_12_239_99(void);
extern void InitTrigger_Model_232_12_239_224(void);
extern void Model_Target_VLS_Init(void);
extern void Model_Target_VLS(void);

#endif                                 /* RTW_HEADER_VLS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
