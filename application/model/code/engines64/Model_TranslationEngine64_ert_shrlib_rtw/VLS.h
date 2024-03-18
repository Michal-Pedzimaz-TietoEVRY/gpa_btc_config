/*
 * File: VLS.h
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

#ifndef RTW_HEADER_VLS_h_
#define RTW_HEADER_VLS_h_
#ifndef Model_TranslationEngine64_COMMON_INCLUDES_
#define Model_TranslationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "TranslateError.h"
#include "Model_TranslationEngine64_TalariaAPI.h"
#endif                          /* Model_TranslationEngine64_COMMON_INCLUDES_ */

#include "Model_TranslationEngine64_types.h"

/* Block signals for system '<S1159>/translation' */
typedef struct
{
    real_T FIRCoeffs[5760];            /* '<S1159>/translation' */
    real_T PaddedFIRLengths[20];       /* '<S1159>/translation' */
}
B_translation_Model_TranslationEngine64_p_T;

/* Block signals for system '<S14>/VLS' */
typedef struct
{
    bus_double_5760____1 FIRCoeffs;    /* '<S1159>/Tune Variable' */
    bus_double_5760____1 FIRCoeffs_l;  /* '<S1160>/Tune Variable' */
    real_T ChannelCoeffs[960];
    bus_single_240___6 sosCoefficients;/* '<S1164>/Tune Variable2' */
    real32_T ChannelSOS_data[1440];
    bus_double_20__1 PaddedFIRLengths; /* '<S1159>/Tune Variable2' */
    bus_double_20__1 PaddedFIRLengths_b;/* '<S1160>/Tune Variable2' */
    bus_double_16__1 Delay;            /* '<S1162>/Tune Variable' */
    bus_single_1_16 numStages;         /* '<S1164>/Tune Variable1' */
    real_T Value[16];
    real32_T PoolCoeffs[976];          /* '<S1164>/Translation' */
    int32_T PoolNumStages[16];         /* '<S1164>/Translation' */
    B_translation_Model_TranslationEngine64_p_T sf_translation_pa;/* '<S1160>/translation' */
    B_translation_Model_TranslationEngine64_p_T sf_translation;/* '<S1159>/translation' */
}
B_VLS_Model_TranslationEngine64_T;

/* Invariant block signals for system '<S14>/VLS' */
typedef struct
{
    const int32_T CapturedTuneConst;   /* '<S1164>/CapturedTuneConst' */
}
ConstB_VLS_Model_TranslationEngine64_T;

/* Extern declarations of internal data for system '<S14>/VLS' */
extern B_VLS_Model_TranslationEngine64_T Model_TranslationEngine64_VLS_B;
extern const ConstB_VLS_Model_TranslationEngine64_T
    Model_TranslationEngine64_VLS_ConstB;
extern void Model_TranslationEngine64_VLS_initialize(void);
extern void Model_TranslationEngine64_translation_o(const bus_double_5760____1
    *rtu_FIRCoeffsIn, const bus_double_20__1 *rtu_PaddedFIRLengthsIn,
    B_translation_Model_TranslationEngine64_p_T *localB);
extern void FuncTranslation_Model_232_8_34_50_36(void);
extern void FuncTranslation_Model_232_8_36_67_18(void);
extern void FuncTranslation_Model_232_11_191(void);
extern void FuncTranslation_Model_232_12_191(void);

#endif                                 /* RTW_HEADER_VLS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
