/*
 * File: Model_Target_PreAmp_p3_b0_TOP.c
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

#pragma section("MODEL_TARGET_PREAMP_P3_B0_MEMORY_SECTION")

#endif

Model_Target_PreAmp_p3_b0_type Model_Target_PreAmp_p3_b0 =
{
    /* MedusaMonoDetectorEnable */
    1,

    /* MedusaTrebleDelay */
    1152,

    /* MedusaDeciRateFdpCoeffsESDLowerbounddB */
    -10.0F,

    /* MedusaDeciRateFdpCoeffsESDStepSize */
    0.125F,

    /* MedusaDeciRateFdpCoeffsESDUpperbounddB */
    -2.0F,

    /* MedusaDeciRateFdpCoeffsLokRokMaxScaleFactor */
    4.5F,

    /* MedusaDeciRateFdpCoeffsXpMax */
    0.9F,

    /* MedusaDeciRateFdpCoeffsXpMin */
    0.2F,

    /* MedusaDeciRateFdpSpumDirectPathSamplesDec */
    258.0F,

    /* MedusaDeciRateFdpSpumFastPsdSmoothFactor */
    0.00368157052F,

    /* MedusaDeciRateFdpSpumLsSmoothFactor */
    0.900446236F,

    /* MedusaDeciRateFdpSpumOverwrite */
    0.0F,

    /* MedusaDeciRateFdpSpumSlowPsdSmoothFactor */
    0.800851047F,

    /* MedusaFullRateFdpCoeffsESDLowerbounddB */
    -4.8571F,

    /* MedusaFullRateFdpCoeffsESDStepSize */
    0.350005239F,

    /* MedusaFullRateFdpCoeffsESDUpperbounddB */
    -2.0F,

    /* MedusaFullRateFdpCoeffsLokRokMaxScaleFactor */
    4.5F,

    /* MedusaFullRateFdpCoeffsXpMax */
    0.7F,

    /* MedusaFullRateFdpCoeffsXpMin */
    0.2F,

    /* MedusaFullRateFdpSpumDirectPathSamplesDec */
    1032.0F,

    /* MedusaFullRateFdpSpumFastPsdSmoothFactor */
    0.669510782F,

    /* MedusaFullRateFdpSpumLsSmoothFactor */
    0.974168241F,

    /* MedusaFullRateFdpSpumOverwrite */
    0.0F,

    /* MedusaFullRateFdpSpumSlowPsdSmoothFactor */
    0.946393251F,

    /* MedusaMonoDetectorHPFCoeffs */
    {
        0.904579461F, 0.818284869F, -1.80003309F, 1.0F, -2.0F, 0.904579461F,
        0.818284869F, -1.80003309F, 1.0F, -2.0F
    },

    /* MedusaMonoDetectorLRMatchTolerance */
    1.05925369F,

    /* MedusaMonoDetectorLSSmoothGain */
    0.00113382097F,

    /* MedusaMonoDetectorLSSmoothPole */
    0.9988662F,

    /* MedusaMonoDetectorLSSmoothResetGain */
    0.166831404F,

    /* MedusaMonoDetectorLSSmoothResetPole */
    0.833168566F,

    /* MedusaMonoDetectorLevelGain */
    0.166831404F,

    /* MedusaMonoDetectorLevelPole */
    0.833168566F,

    /* MedusaMonoDetectorThresholdMono */
    0.999921679F,

    /* MedusaMonoDetectorThresholdStereo */
    0.999843F,

    /* MedusaMonoDetectorThresholdZeroLevel */
    2.0E-5F,

    /* MedusaSPUMDecayEstDecaySmoothFactor */
    0.997502387F,

    /* MedusaSPUMDecayEstDirectPathFramesFs */
    8.0F,

    /* MedusaSPUMDecayEstFastAttack */
    0.14854601F,

    /* MedusaSPUMDecayEstHPFpooliirCoeffs */
    {
        0.763918F, -2.0F, -0.158599868F, 1.0F, 0.860972106F, -2.0F,
        -0.305797517F, 1.0F, 1.10388601F, -2.0F, -0.674213946F, 1.0F, 0.763918F,
        -2.0F, -0.158599868F, 1.0F, 0.860972106F, -2.0F, -0.305797517F, 1.0F,
        1.10388601F, -2.0F, -0.674213946F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.180821896F, 0.180821896F
    },

    /* MedusaSPUMDecayEstNoiseFloor */
    3.0F,

    /* MedusaSPUMDecayEstOnsetThreshold */
    1.875F,

    /* MedusaSPUMDecayEstPSDSmoothFactor */
    0.931764901F,

    /* MedusaSPUMDecayEstSlewThreshold */
    0.8F,

    /* MedusaSPUMDecayEstSlowAttack */
    0.00501406845F,

    /* MedusaSPUMDecayEstStepDecrement */
    -0.00577777764F,

    /* MedusaSPUMDecayEstStepIncrement */
    0.00577777764F,

    /* MedusaMonoDetectorHPFNumStages */
    {
        1U, 1U
    },

    /* MedusaSPUMDecayEstHPFPooliirNumStages */
    {
        3U, 3U
    },
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
