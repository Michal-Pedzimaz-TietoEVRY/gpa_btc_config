/*
 * File: MedusaPostHoligram.h
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

#ifndef RTW_HEADER_MedusaPostHoligram_h_
#define RTW_HEADER_MedusaPostHoligram_h_
#ifndef Model_TranslationEngine64_COMMON_INCLUDES_
#define Model_TranslationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "TranslateError.h"
#include "Model_TranslationEngine64_TalariaAPI.h"
#endif                          /* Model_TranslationEngine64_COMMON_INCLUDES_ */

#include "Model_TranslationEngine64_types.h"

/* Block signals for system '<S561>/MedusaPostHoligram' */
typedef struct
{
    bus_double_1_24 RoutingMap;        /* '<S1041>/Tune Variable' */
    real_T Value[24];
}
B_MedusaPostHoligram_Model_TranslationEngine64_T;

/* Extern declarations of internal data for system '<S561>/MedusaPostHoligram' */
extern B_MedusaPostHoligram_Model_TranslationEngine64_T
    Model_TranslationEngine64_MedusaPostHoligram_B;
extern void Model_TranslationEngine64_MedusaPostHoligram_initialize(void);
extern void FuncTranslation_Model_150_574_67_18(void);

#endif                                 /* RTW_HEADER_MedusaPostHoligram_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
