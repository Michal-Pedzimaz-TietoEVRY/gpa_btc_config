/*
 * File: Model_Target_PreAmp_p9_b0_TOP.c
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

#pragma section("MODEL_TARGET_PREAMP_P9_B0_MEMORY_SECTION")

#endif

Model_Target_PreAmp_p9_b0_type Model_Target_PreAmp_p9_b0 =
{
    /* FadeControlBoostDisable */
    0.0F,

    /* FadeControlEnableSilentExtreme */
    1.0F,

    /* FadeControlRampTime */
    30.0F,

    /* FadeControlTableDb */
    {
        -30.0F, -27.0F, -14.0F, -7.0F, -5.0F, -3.0F, -1.0F, 0.0F, -1.0F, -3.0F,
        -5.0F, -7.0F, -14.0F, -27.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F,
        -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F,
        -30.0F, -30.0F
    },

    /* FadeControlTableIdx */
    {
        0.0F, 10.0F, 31.0F, 52.0F, 74.0F, 95.0F, 116.0F, 128.0F, 138.0F, 159.0F,
        180.0F, 202.0F, 223.0F, 244.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F
    },

    /* FadeControloffset */
    128.0F,

    /* FadeRamperDRChannelToRamperMap */
    {
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* FadeRamperDRTOPFilterCoefficients */
    {
        0.034086585F, 0.034086585F, 0.93182683F
    },

    /* FadeRamperFRChannelToRamperMap */
    {
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* FadeRamperFRTOPFilterCoefficients */
    {
        0.0085093081F, 0.0085093081F, 0.982981384F
    },

    /* MuteControlRampTime */
    100.0F,

    /* SleepingBeautyDRChannelToRamperMap */
    {
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* SleepingBeautyDRMutesBass */
    0.0F,

    /* SleepingBeautyDROffset */
    128.0F,

    /* SleepingBeautyDRRampTime */
    30.0F,

    /* SleepingBeautyDRTableDb */
    {
        -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -10.0F, -20.0F, -30.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F,
        -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F,
        -40.0F
    },

    /* SleepingBeautyDRTableIdx */
    {
        0.0F, 10.0F, 31.0F, 52.0F, 74.0F, 95.0F, 116.0F, 128.0F, 138.0F, 159.0F,
        180.0F, 202.0F, 223.0F, 244.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F
    },

    /* SleepingBeautyFRChannelToRamperMap */
    {
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* SleepingBeautyFRMutesBass */
    0.0F,

    /* SleepingBeautyFROffset */
    128.0F,

    /* SleepingBeautyFRRampTime */
    30.0F,

    /* SleepingBeautyFRTableDb */
    {
        -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -10.0F, -20.0F, -30.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F,
        -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F, -40.0F,
        -40.0F
    },

    /* SleepingBeautyFRTableIdx */
    {
        0.0F, 10.0F, 31.0F, 52.0F, 74.0F, 95.0F, 116.0F, 128.0F, 138.0F, 159.0F,
        180.0F, 202.0F, 223.0F, 244.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F, 255.0F,
        255.0F, 255.0F
    },
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
