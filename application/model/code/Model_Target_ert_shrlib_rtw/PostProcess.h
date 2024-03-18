/*
 * File: PostProcess.h
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

#ifndef RTW_HEADER_PostProcess_h_
#define RTW_HEADER_PostProcess_h_
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

#include "rt_sys_Enabled_530.h"

/* Block signals for system '<S7>/PostProcess' */
typedef struct
{
    real32_T Magsq[768];               /* '<S2190>/Magsq' */
    uint32_T In1;                      /* '<S2222>/In1' */
    uint32_T DataTypeConversion;       /* '<S2194>/Data Type Conversion' */
    real32_T DataStoreRead;            /* '<S2220>/Data Store Read' */
    real32_T DataTypeConversion1[24];  /* '<S2189>/Data Type Conversion1' */
    real32_T CurrentGain;              /* '<S2189>/Delay1' */
    real32_T y[768];                   /* '<S2268>/MATLAB Function' */
    real32_T ImpAsg_InsertedFor_Out1_at_inport_0[768];/* '<S2242>/Multiply' */
    real32_T ramping_coeff;            /* '<S2220>/get_ramp_coeffs' */
    real32_T y_b[768];                 /* '<S2216>/MATLAB Function' */
    real32_T transition;               /* '<S2189>/EBL Transition' */
    int16_T DataTypeConversion5;       /* '<S2189>/Data Type Conversion5' */
    int16_T DataTypeConversion6;       /* '<S2189>/Data Type Conversion6' */
    boolean_T done;                    /* '<S2220>/TriggeredFunction' */
    boolean_T DataTypeConversion_f;    /* '<S2193>/Data Type Conversion' */
    B_calculate_ramp_rate_Model_Target_T sf_calculate_ramp_rate_g;/* '<S2219>/calculate_ramp_rate' */
}
B_PostProcess_Model_Target_T;

/* Block states (default storage) for system '<S7>/PostProcess' */
typedef struct
{
    real_T Delay2_DSTATE[24];          /* '<S2196>/Delay2' */
    real32_T Delay1_DSTATE;            /* '<S2189>/Delay1' */
    real32_T Delay2_DSTATE_i;          /* '<S2189>/Delay2' */
    real32_T Delay_DSTATE;             /* '<S2189>/Delay' */
    real32_T Delay3_DSTATE;            /* '<S2189>/Delay3' */
    real32_T Delay_DSTATE_l;           /* '<S2239>/Delay' */
    real32_T ramping_filter_states;    /* '<S2237>/ramping_filter' */
    real32_T CurrentGainValue;         /* '<S2188>/CurrentGain' */
    real32_T states[256];              /* '<S2247>/Data Store Memory' */
    real32_T state[24];                /* '<S2216>/MATLAB Function' */
    real32_T prevGain;                 /* '<S2188>/RamperProcess' */
    int16_T EBL_EnableCounter;         /* '<S2189>/Data Store Memory' */
    int16_T EBL_EnableCounter_d;       /* '<S2189>/EBL Transition' */
    uint8_T ramping_filter_icLoad;     /* '<S2237>/ramping_filter' */
    boolean_T icLoad;                  /* '<S2189>/Delay1' */
    boolean_T prevGain_not_empty;      /* '<S2188>/RamperProcess' */
}
DW_PostProcess_Model_Target_T;

/* Invariant block signals for system '<S7>/PostProcess' */
typedef struct
{
    const real_T Add1;                 /* '<S2189>/Add1' */
    const real_T Product;              /* '<S2195>/Product' */
    const real_T Divide;               /* '<S2195>/Divide' */
    const real_T MathFunction;         /* '<S2195>/Math Function' */
    const real_T Subtract1;            /* '<S2196>/Subtract1' */
    const real_T Divide1;              /* '<S2199>/Divide1' */
    const real_T Gain;                 /* '<S2199>/Gain' */
    const real_T MathFunction1;        /* '<S2199>/Math Function1' */
    const real_T MathFunction2;        /* '<S2199>/Math Function2' */
    const real_T Product5;             /* '<S2200>/Product5' */
    const real_T Product6;             /* '<S2200>/Product6' */
    const real_T RoundingFunction;     /* '<S2200>/Rounding Function' */
    const real_T RoundingFunction1;    /* '<S2200>/Rounding Function1' */
    const real_T RoundingFunction_b;   /* '<S2201>/Rounding Function' */
    const real_T Gain1;                /* '<S2202>/Gain1' */
    const real_T Divide4;              /* '<S2202>/Divide4' */
    const real_T MathFunction4;        /* '<S2202>/Math Function4' */
    const real_T DEBUG_EBL_THRESHOLD_DBSPL;/* '<S2209>/Add1' */
    const real32_T DataTypeConversion3;/* '<S2189>/Data Type Conversion3' */
}
ConstB_PostProcess_Model_Target_T;

/* Extern declarations of internal data for system '<S7>/PostProcess' */
extern B_PostProcess_Model_Target_T Model_Target_PostProcess_B;
extern DW_PostProcess_Model_Target_T Model_Target_PostProcess_DW;
extern const ConstB_PostProcess_Model_Target_T Model_Target_PostProcess_ConstB;
extern void HandleReqPostProcessMuteSet(void);
extern void HandleReqPostProcessPostLimiterEqShutdown(void);
extern void Model_Target_PostProcess_Init(void);
extern void Model_Target_PostProcess(void);

#endif                                 /* RTW_HEADER_PostProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
