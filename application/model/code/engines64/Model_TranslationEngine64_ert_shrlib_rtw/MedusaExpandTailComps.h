/*
 * File: MedusaExpandTailComps.h
 *
 * Code generated for Simulink model 'Model_TranslationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:20:04 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MedusaExpandTailComps_h_
#define RTW_HEADER_MedusaExpandTailComps_h_
#ifndef Model_TranslationEngine64_COMMON_INCLUDES_
#define Model_TranslationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "TranslateError.h"
#include "Model_TranslationEngine64_TalariaAPI.h"
#endif                          /* Model_TranslationEngine64_COMMON_INCLUDES_ */

#include "Model_TranslationEngine64_types.h"

/* Block signals for system '<S752>/Expand Tail Components' */
typedef struct
{
    bus_double_444___4 WiggleFilter;   /* '<S763>/Tune Variable' */
    bus_single_40__6 sosCoefficients;  /* '<S765>/Tune Variable2' */
    bus_single_1_4 numStages;          /* '<S765>/Tune Variable1' */
    real_T Value[1776];
    real32_T PoolCoeffs[164];          /* '<S765>/Translation' */
    int32_T PoolNumStages[4];          /* '<S765>/Translation' */
}
B_ExpandTailComponents_Model_TranslationEngine64_T;

/* Invariant block signals for system '<S752>/Expand Tail Components' */
typedef struct
{
    const int32_T CapturedTuneConst;   /* '<S765>/CapturedTuneConst' */
}
ConstB_ExpandTailComponents_Model_TranslationEngine64_T;

/* Extern declarations of internal data for system '<S752>/Expand Tail Components' */
extern B_ExpandTailComponents_Model_TranslationEngine64_T
    Model_TranslationEngine64_ExpandTailComponents_B;
extern const ConstB_ExpandTailComponents_Model_TranslationEngine64_T
    Model_TranslationEngine64_ExpandTailComponents_ConstB;
extern void Model_TranslationEngine64_ExpandTailComponents_initialize(void);
extern void FuncTranslation_Model_141_345_50_36(void);
extern void FuncTranslation_Model_141_346_67_18(void);

#endif                                 /* RTW_HEADER_MedusaExpandTailComps_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
