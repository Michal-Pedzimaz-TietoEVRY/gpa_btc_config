/*
 * File: PostProcess.h
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

#ifndef RTW_HEADER_PostProcess_h_
#define RTW_HEADER_PostProcess_h_
#ifndef Model_TranslationEngine64_COMMON_INCLUDES_
#define Model_TranslationEngine64_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "TranslateError.h"
#include "Model_TranslationEngine64_TalariaAPI.h"
#endif                          /* Model_TranslationEngine64_COMMON_INCLUDES_ */

#include "Model_TranslationEngine64_types.h"

/* Block signals for system '<S1850>/MATLAB Function3' */
typedef struct
{
    real32_T attack[24];               /* '<S1850>/MATLAB Function3' */
    real32_T k1[24];                   /* '<S1850>/MATLAB Function3' */
}
B_MATLABFunction3_Model_TranslationEngine64_T;

/* Block signals for system '<S5>/PostProcess' */
typedef struct
{
    real_T ChannelCoeffs_data[513];
    bus_single_128___6 sosCoefficients;/* '<S1876>/Tune Variable2' */
    bus_double_1_24 Attack;            /* '<S1850>/attackTune' */
    bus_double_1_24 Threshold;         /* '<S1850>/threshhold tune' */
    bus_double_1_24 Attack_low;        /* '<S1850>/attackTune1' */
    bus_double_1_24 Threshold_low;     /* '<S1850>/threshhold tune1' */
    bus_double_1_24 Decay;             /* '<S1850>/decay tune' */
    bus_double_1_24 Decay_low;         /* '<S1850>/decay tune1' */
    bus_double_1_24 MaxAttack;         /* '<S1850>/maxAttack tune' */
    bus_double_1_24 MaxAttack_low;     /* '<S1850>/maxAttack tune1' */
    bus_single_1_24 numStages;         /* '<S1876>/Tune Variable1' */
    bus_double_1_1 RampTime;           /* '<S1871>/Tune Variable' */
    bus_double_1_1 YMax;               /* '<S1880>/ymax TuneVar' */
    bus_double_1_1 XMin;               /* '<S1880>/xmin TuneVar' */
    bus_double_1_1 YMaxLow;            /* '<S1880>/ymax TuneVar1' */
    bus_double_1_1 XMinLow;            /* '<S1880>/xmin TuneVar1' */
    real_T xmin_top;                   /* '<S1880>/translation1' */
    real_T xmax_top;                   /* '<S1880>/translation1' */
    real_T p2;                         /* '<S1880>/translation1' */
    real_T xmin_top_c;                 /* '<S1880>/translation' */
    real_T xmax_top_m;                 /* '<S1880>/translation' */
    real_T p2_e;                       /* '<S1880>/translation' */
    real_T Value;
    real32_T PoolCoeffs[536];          /* '<S1876>/Translation' */
    real32_T y[24];                    /* '<S1850>/MATLAB Function6' */
    real32_T y_j[24];                  /* '<S1850>/MATLAB Function1' */
    real32_T y_n[24];                  /* '<S1850>/MATLAB Function4' */
    real32_T y_b[24];                  /* '<S1850>/MATLAB Function2' */
    int32_T PoolNumStages[24];         /* '<S1876>/Translation' */
    B_MATLABFunction3_Model_TranslationEngine64_T sf_MATLABFunction5_h;/* '<S1850>/MATLAB Function5' */
    B_MATLABFunction3_Model_TranslationEngine64_T sf_MATLABFunction3;/* '<S1850>/MATLAB Function3' */
}
B_PostProcess_Model_TranslationEngine64_T;

/* Invariant block signals for system '<S5>/PostProcess' */
typedef struct
{
    const real_T CapturedTuneConst;    /* '<S1850>/Captured Tune Const' */
    const int32_T CapturedTuneConst_g; /* '<S1876>/CapturedTuneConst' */
}
ConstB_PostProcess_Model_TranslationEngine64_T;

/* Extern declarations of internal data for system '<S5>/PostProcess' */
extern B_PostProcess_Model_TranslationEngine64_T
    Model_TranslationEngine64_PostProcess_B;
extern const ConstB_PostProcess_Model_TranslationEngine64_T
    Model_TranslationEngine64_PostProcess_ConstB;
extern void Model_TranslationEngine64_PostProcess_initialize(void);
extern void Model_TranslationEngine64_MATLABFunction3(const bus_double_1_24
    *rtu_attackDB, const bus_double_1_24 *rtu_threshold, real_T rtu_Fs,
    B_MATLABFunction3_Model_TranslationEngine64_T *localB);
extern void FuncTranslation_Model_1495(void);
extern void FuncTranslation_Model_1496(void);
extern void FuncTranslation_Model_1497(void);
extern void FuncTranslation_Model_1498(void);
extern void FuncTranslation_Model_1499(void);
extern void FuncTranslation_Model_1500(void);
extern void FuncTranslation_Model_72_276_67_18(void);
extern void FuncTranslation_Model_76_36(void);
extern void FuncTranslation_Model_1527(void);
extern void FuncTranslation_Model_1528(void);

#endif                                 /* RTW_HEADER_PostProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
