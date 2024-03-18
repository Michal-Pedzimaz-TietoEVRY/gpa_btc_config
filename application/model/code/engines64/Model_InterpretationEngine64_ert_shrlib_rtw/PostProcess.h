/*
 * File: PostProcess.h
 *
 * Code generated for Simulink model 'Model_InterpretationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:16:14 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PostProcess_h_
#define RTW_HEADER_PostProcess_h_
#ifndef Model_InterpretationEngine64_COMMON_INCLUDES_
#define Model_InterpretationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_InterpretationEngine64_InterpretError.h"
#include "Model_InterpretationEngine64_TalariaAPI.h"
#endif                       /* Model_InterpretationEngine64_COMMON_INCLUDES_ */

/* Block signals for system '<S4>/PostProcess' */
typedef struct
{
    real32_T TSP[24];                  /* '<S305>/TSP' */
    real32_T TSP_b;                    /* '<S306>/TSP' */
    real32_T TSP_f;                    /* '<S307>/TSP' */
    real32_T In1;                      /* '<S320>/In1' */
    real32_T In1_p;                    /* '<S316>/In1' */
    real32_T In1_b[24];                /* '<S312>/In1' */
    int16_T TSP_i;                     /* '<S308>/TSP' */
    int16_T TSP_fc;                    /* '<S309>/TSP' */
    int16_T In1_g;                     /* '<S328>/In1' */
    int16_T In1_n;                     /* '<S324>/In1' */
}
B_PostProcess_Model_InterpretationEngine64_T;

/* Extern declarations of internal data for system '<S4>/PostProcess' */
extern B_PostProcess_Model_InterpretationEngine64_T
    Model_InterpretationEngine64_PostProcess_B;
extern void Model_InterpretationEngine64_PostProcess_initialize(void);
extern void Model_InterpretationEngine64_ifunc_em(void);
extern void Model_InterpretationEngine64_ifunc_lv(void);
extern void Model_InterpretationEngine64_ifunc_jl(void);
extern void Model_InterpretationEngine64_ifunc_jt(void);
extern void Model_InterpretationEngine64_ifunc_cj(void);

#endif                                 /* RTW_HEADER_PostProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
