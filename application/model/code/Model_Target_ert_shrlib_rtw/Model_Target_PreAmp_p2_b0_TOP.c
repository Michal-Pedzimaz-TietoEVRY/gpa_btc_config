/*
 * File: Model_Target_PreAmp_p2_b0_TOP.c
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

#include "Model_Target_TOP.h"
#if defined __SPECIFY_TOP_MEMORY_SECTION__

#pragma section("MODEL_TARGET_PREAMP_P2_B0_MEMORY_SECTION")

#endif

Model_Target_PreAmp_p2_b0_type Model_Target_PreAmp_p2_b0 =
{
    /* MedusaBassManagerGainLfe2C */
    1.0F,

    /* MedusaBassManagerHpfpooliirCoeffs */
    {
        0.987318039F, -1.0F, 0.0F, 0.0F, 1.98715675F, -2.0F, -0.987318575F, 1.0F,
        0.987318039F, -1.0F, 0.0F, 0.0F, 1.98715675F, -2.0F, -0.987318575F, 1.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.987318277F,
        0.987318277F
    },

    /* MedusaBassManagerLeftMixWeights */
    1.0F,

    /* MedusaBassManagerLpfpooliirCoeffs */
    {
        0.987318039F, 1.0F, 0.0F, 0.0F, 1.98715675F, 2.0F, -0.987318575F, 1.0F,
        0.987318039F, 1.0F, 0.0F, 0.0F, 1.98715675F, 2.0F, -0.987318575F, 1.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 2.56575163E-7F,
        2.56575163E-7F
    },

    /* MedusaBassManagerRightMixWeights */
    1.0F,

    /* MedusaDummyTune */
    1.0F,

    /* MedusaBassManagerHpfPooliirNumStages */
    {
        2U, 2U
    },

    /* MedusaBassManagerLpfPooliirNumStages */
    {
        2U, 2U
    },
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
