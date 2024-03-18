/*
 * File: Enabled.h
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

#ifndef RTW_HEADER_Enabled_h_
#define RTW_HEADER_Enabled_h_
#ifndef Model_TranslationEngine64_COMMON_INCLUDES_
#define Model_TranslationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "TranslateError.h"
#include "Model_TranslationEngine64_TalariaAPI.h"
#endif                          /* Model_TranslationEngine64_COMMON_INCLUDES_ */

#include "Model_TranslationEngine64_types.h"

/* Block signals for system '<S1092>/Filter_Coeffs_Translation' */
typedef struct
{
    real32_T FilterCoeffs[3];          /* '<S1092>/Filter_Coeffs_Translation' */
}
B_Filter_Coeffs_Translation_Model_TranslationEngine64_T;

/* Block signals for system '<S1117>/translation' */
typedef struct
{
    uint32_T tableIdx[30];             /* '<S1117>/translation' */
    real32_T tableDb[30];              /* '<S1117>/translation' */
}
B_translation_Model_TranslationEngine64_T;

extern void Model_TranslationEngine64_Filter_Coeffs_Translation(const
    bus_double_1_1 *rtu_cutoffFreqHz, real32_T rtu_FsHz,
    B_Filter_Coeffs_Translation_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_translation(const bus_double_30__2
    *rtu_sleepingBeautyTable, B_translation_Model_TranslationEngine64_T *localB);
extern void FuncTranslation_Model_449_67_18(void);
extern void FuncTranslation_Model_450_67_18(void);
extern void FuncTranslation_Model_455(void);
extern void FuncTranslation_Model_459_67_18(void);
extern void FuncTranslation_Model_460_67_18(void);
extern void FuncTranslation_Model_175_136_98(void);
extern void FuncTranslation_Model_175_136_99(void);
extern void FuncTranslation_Model_176_136_98(void);
extern void FuncTranslation_Model_176_136_99(void);
extern void FuncTranslation_Model_489_67_18(void);
extern void FuncTranslation_Model_533(void);
extern void FuncTranslation_Model_538_67_18(void);
extern void FuncTranslation_Model_539_67_18(void);
extern void FuncTranslation_Model_540_67_18(void);
extern void FuncTranslation_Model_545(void);
extern void FuncTranslation_Model_596(void);
extern void FuncTranslation_Model_601_67_18(void);
extern void FuncTranslation_Model_602_67_18(void);
extern void FuncTranslation_Model_603_67_18(void);
extern void FuncTranslation_Model_608(void);

#endif                                 /* RTW_HEADER_Enabled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
