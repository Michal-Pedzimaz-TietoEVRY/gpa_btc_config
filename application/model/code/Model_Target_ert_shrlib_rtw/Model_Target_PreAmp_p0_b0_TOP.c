/*
 * File: Model_Target_PreAmp_p0_b0_TOP.c
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

#pragma section("MODEL_TARGET_PREAMP_P0_B0_MEMORY_SECTION")

#endif

Model_Target_PreAmp_p0_b0_type Model_Target_PreAmp_p0_b0 =
{
    /* A */
    0.316227764F,

    /* AnnPred */
    31622.7773F,

    /* BassBoostCoeffs */
    {
        0.00843688846F, 0.00843688846F, 0.983126223F
    },

    /* BassBoostMaximum_dB */
    20.0F,

    /* BassCutCoeffs */
    {
        0.00843688846F, 0.00843688846F, 0.983126223F
    },

    /* BassCutMaximum_dB */
    20.0F,

    /* BassOffset */
    128.0F,

    /* BassScale */
    127.0F,

    /* Bassramptime */
    30.0F,

    /* G */
    1.0F,

    /* Limiterattack */
    {
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F,
        0.0256493539F, 0.0256493539F, 0.0256493539F, 0.0256493539F
    },

    /* Limiterdecay */
    {
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F, 1.00025988F,
        1.00025988F, 1.00025988F
    },

    /* LimitermaxAttack */
    {
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F, 0.316227764F,
        0.316227764F, 0.316227764F
    },

    /* MidrangeBoostCoeffs */
    {
        -1.87375939F, 0.885132551F, 0.0574337579F, 0.0F, -0.0574337579F
    },

    /* MidrangeBoostMaximum_dB */
    20.0F,

    /* MidrangeCutCoeffs */
    {
        -1.87375939F, 0.885132551F, 0.0574337579F, 0.0F, -0.0574337579F
    },

    /* MidrangeCutMaximum_dB */
    20.0F,

    /* MidrangeOffset */
    128.0F,

    /* MidrangeRampTime */
    30.0F,

    /* MidrangeScale */
    127.0F,

    /* Offset */
    1.99526227F,

    /* TrebleBoostCoeffs */
    {
        0.774309397F, -0.774309397F, 0.548618793F
    },

    /* TrebleBoostMaximum_dB */
    20.0F,

    /* TrebleCutCoeffs */
    {
        0.774309397F, -0.774309397F, 0.548618793F
    },

    /* TrebleCutMaximum_dB */
    20.0F,

    /* TrebleOffset */
    128.0F,

    /* TrebleScale */
    127.0F,

    /* Trebleramptime */
    30.0F,

    /* UpperThreshold */
    31622.7773F,
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
