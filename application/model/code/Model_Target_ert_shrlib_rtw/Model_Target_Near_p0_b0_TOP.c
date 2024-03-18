/*
 * File: Model_Target_Near_p0_b0_TOP.c
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

#pragma section("MODEL_TARGET_NEAR_P0_B0_MEMORY_SECTION")

#endif

Model_Target_Near_p0_b0_type Model_Target_Near_p0_b0 =
{
    /* Dr_EqDelays */
    {
        0, 0, 0, 0, 0, 0, 0
    },

    /* Dr_RouterOutMap */
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    },

    /* Fr_EqDelays */
    {
        0, 0, 0, 0, 0, 0, 0
    },

    /* Fr_RouterOutMap */
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    },

    /* Ann1Ann1MuteRampTime */
    100.0F,

    /* Ann1Ann1NonEntGainCalcBoostOverRide */
    0.0F,

    /* Ann1Ann1NonEntGainCalcBoostOverRideFlag */
    0.0F,

    /* Ann1Ann1NonEntGainCalcDen */
    {
        1.0F, -0.999093413F
    },

    /* Ann1Ann1NonEntGainCalcMaxBoost */
    18.0F,

    /* Ann1Ann1NonEntGainCalcMaxSpl */
    120.0F,

    /* Ann1Ann1NonEntGainCalcMinVncSignal */
    40.0F,

    /* Ann1Ann1NonEntGainCalcNoiseOverRide */
    0.0F,

    /* Ann1Ann1NonEntGainCalcNoiseOverRideFlag */
    0.0F,

    /* Ann1Ann1NonEntGainCalcNum */
    {
        0.000906586647F, 0.0F
    },

    /* Ann1Ann1NonEntGainCalcVncEnableTuneVar */
    1.0F,

    /* Ann1Ann1NonEntGainCalcVncSlope */
    0.4F,

    /* Ann1Ann1NonEntGainCalcVncThresh */
    0.0F,

    /* Ann1Ann1NonEntVncAppliedNum */
    {
        0.0434372649F, 0.0434372649F
    },

    /* Ann1Ann1NonEntVncAppliedden */
    {
        1.0F, -0.913125515F
    },

    /* Ann1Ann1VolumeRampRate */
    100.0F,

    /* Ann1Ann1VolumeRampTime */
    100.0F,

    /* Ann1Ann1VolumeTable_dB */
    {
        -126.5F, -100.0F, -90.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Ann1LevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* Ann1LevelDetectHoldTimeSamples */
    4135.0F,

    /* Ann1LevelDetectMaxVolumeDb */
    0.0F,

    /* Ann1LevelDetectMinVolumeDb */
    -80.0F,

    /* Ann1LevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* Ann1LevelDetecthold_margin_db */
    6.0F,

    /* Ann2Ann2MuteRampTime */
    100.0F,

    /* Ann2Ann2NonEntGainCalcBoostOverRide */
    0.0F,

    /* Ann2Ann2NonEntGainCalcBoostOverRideFlag */
    0.0F,

    /* Ann2Ann2NonEntGainCalcDen */
    {
        1.0F, -0.999093413F
    },

    /* Ann2Ann2NonEntGainCalcMaxBoost */
    18.0F,

    /* Ann2Ann2NonEntGainCalcMaxSpl */
    120.0F,

    /* Ann2Ann2NonEntGainCalcMinVncSignal */
    40.0F,

    /* Ann2Ann2NonEntGainCalcNoiseOverRide */
    0.0F,

    /* Ann2Ann2NonEntGainCalcNoiseOverRideFlag */
    0.0F,

    /* Ann2Ann2NonEntGainCalcNum */
    {
        0.000906586647F, 0.0F
    },

    /* Ann2Ann2NonEntGainCalcVncEnableTuneVar */
    1.0F,

    /* Ann2Ann2NonEntGainCalcVncSlope */
    0.4F,

    /* Ann2Ann2NonEntGainCalcVncThresh */
    0.0F,

    /* Ann2Ann2NonEntVncAppliedNum */
    {
        0.0434372649F, 0.0434372649F
    },

    /* Ann2Ann2NonEntVncAppliedden */
    {
        1.0F, -0.913125515F
    },

    /* Ann2Ann2VolumeRampRate */
    100.0F,

    /* Ann2Ann2VolumeRampTime */
    100.0F,

    /* Ann2Ann2VolumeTable_dB */
    {
        -126.5F, -100.0F, -90.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Ann2LevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* Ann2LevelDetectHoldMarginDb */
    6.0F,

    /* Ann2LevelDetectHoldTimeSamples */
    4135.0F,

    /* Ann2LevelDetectMaxVolumeDb */
    0.0F,

    /* Ann2LevelDetectMinVolumeDb */
    -80.0F,

    /* Ann2LevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* Ann3Ann3MuteRampTime */
    100.0F,

    /* Ann3Ann3NonEntGainCalcBoostOverRide */
    0.0F,

    /* Ann3Ann3NonEntGainCalcBoostOverRideFlag */
    0.0F,

    /* Ann3Ann3NonEntGainCalcDen */
    {
        1.0F, -0.999093413F
    },

    /* Ann3Ann3NonEntGainCalcMaxBoost */
    18.0F,

    /* Ann3Ann3NonEntGainCalcMaxSpl */
    120.0F,

    /* Ann3Ann3NonEntGainCalcMinVncSignal */
    40.0F,

    /* Ann3Ann3NonEntGainCalcNoiseOverRide */
    0.0F,

    /* Ann3Ann3NonEntGainCalcNoiseOverRideFlag */
    0.0F,

    /* Ann3Ann3NonEntGainCalcNum */
    {
        0.000906586647F, 0.0F
    },

    /* Ann3Ann3NonEntGainCalcVncEnableTuneVar */
    1.0F,

    /* Ann3Ann3NonEntGainCalcVncSlope */
    0.4F,

    /* Ann3Ann3NonEntGainCalcVncThresh */
    0.0F,

    /* Ann3Ann3NonEntVncAppliedNum */
    {
        0.0434372649F, 0.0434372649F
    },

    /* Ann3Ann3NonEntVncAppliedden */
    {
        1.0F, -0.913125515F
    },

    /* Ann3Ann3VolumeRampRate */
    100.0F,

    /* Ann3Ann3VolumeRampTime */
    100.0F,

    /* Ann3Ann3VolumeTable_dB */
    {
        -126.5F, -100.0F, -90.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Ann3LevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* Ann3LevelDetectHoldMarginDb */
    6.0F,

    /* Ann3LevelDetectHoldTimeSamples */
    4135.0F,

    /* Ann3LevelDetectMaxVolumeDb */
    0.0F,

    /* Ann3LevelDetectMinVolumeDb */
    -80.0F,

    /* Ann3LevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* Ann4Ann4MuteRampTime */
    100.0F,

    /* Ann4Ann4NonEntGainCalcBoostOverRide */
    0.0F,

    /* Ann4Ann4NonEntGainCalcBoostOverRideFlag */
    0.0F,

    /* Ann4Ann4NonEntGainCalcDen */
    {
        1.0F, -0.999093413F
    },

    /* Ann4Ann4NonEntGainCalcMaxBoost */
    18.0F,

    /* Ann4Ann4NonEntGainCalcMaxSpl */
    120.0F,

    /* Ann4Ann4NonEntGainCalcMinVncSignal */
    40.0F,

    /* Ann4Ann4NonEntGainCalcNoiseOverRide */
    0.0F,

    /* Ann4Ann4NonEntGainCalcNoiseOverRideFlag */
    0.0F,

    /* Ann4Ann4NonEntGainCalcNum */
    {
        0.000906586647F, 0.0F
    },

    /* Ann4Ann4NonEntGainCalcVncEnableTuneVar */
    1.0F,

    /* Ann4Ann4NonEntGainCalcVncSlope */
    0.4F,

    /* Ann4Ann4NonEntGainCalcVncThresh */
    0.0F,

    /* Ann4Ann4NonEntVncAppliedNum */
    {
        0.0434372649F, 0.0434372649F
    },

    /* Ann4Ann4NonEntVncAppliedden */
    {
        1.0F, -0.913125515F
    },

    /* Ann4Ann4VolumeRampRate */
    100.0F,

    /* Ann4Ann4VolumeRampTime */
    100.0F,

    /* Ann4Ann4VolumeTable_dB */
    {
        -126.5F, -100.0F, -90.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Ann4LevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* Ann4LevelDetectHoldMarginDb */
    6.0F,

    /* Ann4LevelDetectHoldTimeSamples */
    4135.0F,

    /* Ann4LevelDetectMaxVolumeDb */
    0.0F,

    /* Ann4LevelDetectMinVolumeDb */
    -80.0F,

    /* Ann4LevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* Coefficients */
    {
        0.974680603F, 0.987259388F, -1.98709595F, 1.0F, -2.0F, 0.987259388F,
        -1.98709595F, 1.0F, -2.0F, 0.974680066F, -1.9745177F, 1.0F, -2.0F,
        0.974680603F, 0.987259388F, -1.98709595F, 1.0F, -2.0F, 0.987259388F,
        -1.98709595F, 1.0F, -2.0F, 0.974680066F, -1.9745177F, 1.0F, -2.0F,
        0.974680603F, 0.987259388F, -1.98709595F, 1.0F, -2.0F, 0.987259388F,
        -1.98709595F, 1.0F, -2.0F, 0.974680066F, -1.9745177F, 1.0F, -2.0F,
        0.974680603F, 0.987259388F, -1.98709595F, 1.0F, -2.0F, 0.987259388F,
        -1.98709595F, 1.0F, -2.0F, 0.974680066F, -1.9745177F, 1.0F, -2.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F
    },

    /* Dr_PoolIirTunablepooliirCoeffs */
    {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* Dr_PooliirpooliirCoeffs */
    {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* Dr_eqdelays */
    {
        0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Dr_mix */
    {
        4.0F, 3.0F, 2.0F, 1.0F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 2.0F, 1.5F,
        1.0F, 0.5F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 2.0F,
        1.5F, 1.0F, 0.5F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 4.0F, 3.0F, 2.0F,
        1.0F, 0.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F,
        0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.5F, 0.75F,
        1.0F, 0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F,
        1.0F, 2.0F, 3.0F, 4.0F, 9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 8.0F, 7.25F, 6.5F,
        5.75F, 5.0F, 7.0F, 6.5F, 6.0F, 5.5F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F,
        5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 6.0F,
        5.75F, 5.5F, 5.25F, 5.0F, 7.0F, 6.5F, 6.0F, 5.5F, 5.0F, 8.0F, 7.25F,
        6.5F, 5.75F, 5.0F, 9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 5.0F, 6.0F, 7.0F, 8.0F,
        9.0F, 5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 5.5F, 6.0F, 6.5F, 7.0F, 5.0F,
        5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
        5.0F, 5.0F, 5.0F, 5.25F, 5.5F, 5.75F, 6.0F, 5.0F, 5.5F, 6.0F, 6.5F, 7.0F,
        5.0F, 5.75F, 6.5F, 7.25F, 8.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 14.0F,
        13.0F, 12.0F, 11.0F, 10.0F, 13.0F, 12.25F, 11.5F, 10.75F, 10.0F, 12.0F,
        11.5F, 11.0F, 10.5F, 10.0F, 11.0F, 10.75F, 10.5F, 10.25F, 10.0F, 10.0F,
        10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 11.0F,
        10.75F, 10.5F, 10.25F, 10.0F, 12.0F, 11.5F, 11.0F, 10.5F, 10.0F, 13.0F,
        12.25F, 11.5F, 10.75F, 10.0F, 14.0F, 13.0F, 12.0F, 11.0F, 10.0F, 10.0F,
        11.0F, 12.0F, 13.0F, 14.0F, 10.0F, 10.75F, 11.5F, 12.25F, 13.0F, 10.0F,
        10.5F, 11.0F, 11.5F, 12.0F, 10.0F, 10.25F, 10.5F, 10.75F, 11.0F, 10.0F,
        10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F,
        10.25F, 10.5F, 10.75F, 11.0F, 10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 10.0F,
        10.75F, 11.5F, 12.25F, 13.0F, 10.0F, 11.0F, 12.0F, 13.0F, 14.0F, 19.0F,
        18.0F, 17.0F, 16.0F, 15.0F, 18.0F, 17.25F, 16.5F, 15.75F, 15.0F, 17.0F,
        16.5F, 16.0F, 15.5F, 15.0F, 16.0F, 15.75F, 15.5F, 15.25F, 15.0F, 15.0F,
        15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 16.0F,
        15.75F, 15.5F, 15.25F, 15.0F, 17.0F, 16.5F, 16.0F, 15.5F, 15.0F, 18.0F,
        17.25F, 16.5F, 15.75F, 15.0F, 19.0F, 18.0F, 17.0F, 16.0F, 15.0F, 15.0F,
        16.0F, 17.0F, 18.0F, 19.0F, 15.0F, 15.75F, 16.5F, 17.25F, 18.0F, 15.0F,
        15.5F, 16.0F, 16.5F, 17.0F, 15.0F, 15.25F, 15.5F, 15.75F, 16.0F, 15.0F,
        15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
        15.25F, 15.5F, 15.75F, 16.0F, 15.0F, 15.5F, 16.0F, 16.5F, 17.0F, 15.0F,
        15.75F, 16.5F, 17.25F, 18.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 24.0F,
        23.0F, 22.0F, 21.0F, 20.0F, 23.0F, 22.25F, 21.5F, 20.75F, 20.0F, 22.0F,
        21.5F, 21.0F, 20.5F, 20.0F, 21.0F, 20.75F, 20.5F, 20.25F, 20.0F, 20.0F,
        20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 21.0F,
        20.75F, 20.5F, 20.25F, 20.0F, 22.0F, 21.5F, 21.0F, 20.5F, 20.0F, 23.0F,
        22.25F, 21.5F, 20.75F, 20.0F, 24.0F, 23.0F, 22.0F, 21.0F, 20.0F, 20.0F,
        21.0F, 22.0F, 23.0F, 24.0F, 20.0F, 20.75F, 21.5F, 22.25F, 23.0F, 20.0F,
        20.5F, 21.0F, 21.5F, 22.0F, 20.0F, 20.25F, 20.5F, 20.75F, 21.0F, 20.0F,
        20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F,
        20.25F, 20.5F, 20.75F, 21.0F, 20.0F, 20.5F, 21.0F, 21.5F, 22.0F, 20.0F,
        20.75F, 21.5F, 22.25F, 23.0F, 20.0F, 21.0F, 22.0F, 23.0F, 24.0F, 29.0F,
        28.0F, 27.0F, 26.0F, 25.0F, 28.0F, 27.25F, 26.5F, 25.75F, 25.0F, 27.0F,
        26.5F, 26.0F, 25.5F, 25.0F, 26.0F, 25.75F, 25.5F, 25.25F, 25.0F, 25.0F,
        25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 26.0F,
        25.75F, 25.5F, 25.25F, 25.0F, 27.0F, 26.5F, 26.0F, 25.5F, 25.0F, 28.0F,
        27.25F, 26.5F, 25.75F, 25.0F, 29.0F, 28.0F, 27.0F, 26.0F, 25.0F, 25.0F,
        26.0F, 27.0F, 28.0F, 29.0F, 25.0F, 25.75F, 26.5F, 27.25F, 28.0F, 25.0F,
        25.5F, 26.0F, 26.5F, 27.0F, 25.0F, 25.25F, 25.5F, 25.75F, 26.0F, 25.0F,
        25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F, 25.0F,
        25.25F, 25.5F, 25.75F, 26.0F, 25.0F, 25.5F, 26.0F, 26.5F, 27.0F, 25.0F,
        25.75F, 26.5F, 27.25F, 28.0F, 25.0F, 26.0F, 27.0F, 28.0F, 29.0F, 34.0F,
        33.0F, 32.0F, 31.0F, 30.0F, 33.0F, 32.25F, 31.5F, 30.75F, 30.0F, 32.0F,
        31.5F, 31.0F, 30.5F, 30.0F, 31.0F, 30.75F, 30.5F, 30.25F, 30.0F, 30.0F,
        30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 31.0F,
        30.75F, 30.5F, 30.25F, 30.0F, 32.0F, 31.5F, 31.0F, 30.5F, 30.0F, 33.0F,
        32.25F, 31.5F, 30.75F, 30.0F, 34.0F, 33.0F, 32.0F, 31.0F, 30.0F, 30.0F,
        31.0F, 32.0F, 33.0F, 34.0F, 30.0F, 30.75F, 31.5F, 32.25F, 33.0F, 30.0F,
        30.5F, 31.0F, 31.5F, 32.0F, 30.0F, 30.25F, 30.5F, 30.75F, 31.0F, 30.0F,
        30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F,
        30.25F, 30.5F, 30.75F, 31.0F, 30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 30.0F,
        30.75F, 31.5F, 32.25F, 33.0F, 30.0F, 31.0F, 32.0F, 33.0F, 34.0F, 39.0F,
        38.0F, 37.0F, 36.0F, 35.0F, 38.0F, 37.25F, 36.5F, 35.75F, 35.0F, 37.0F,
        36.5F, 36.0F, 35.5F, 35.0F, 36.0F, 35.75F, 35.5F, 35.25F, 35.0F, 35.0F,
        35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 36.0F,
        35.75F, 35.5F, 35.25F, 35.0F, 37.0F, 36.5F, 36.0F, 35.5F, 35.0F, 38.0F,
        37.25F, 36.5F, 35.75F, 35.0F, 39.0F, 38.0F, 37.0F, 36.0F, 35.0F, 35.0F,
        36.0F, 37.0F, 38.0F, 39.0F, 35.0F, 35.75F, 36.5F, 37.25F, 38.0F, 35.0F,
        35.5F, 36.0F, 36.5F, 37.0F, 35.0F, 35.25F, 35.5F, 35.75F, 36.0F, 35.0F,
        35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F,
        35.25F, 35.5F, 35.75F, 36.0F, 35.0F, 35.5F, 36.0F, 36.5F, 37.0F, 35.0F,
        35.75F, 36.5F, 37.25F, 38.0F, 35.0F, 36.0F, 37.0F, 38.0F, 39.0F, 44.0F,
        43.0F, 42.0F, 41.0F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F, 42.0F,
        41.5F, 41.0F, 40.5F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F, 40.0F,
        40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 41.0F,
        40.75F, 40.5F, 40.25F, 40.0F, 42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 43.0F,
        42.25F, 41.5F, 40.75F, 40.0F, 44.0F, 43.0F, 42.0F, 41.0F, 40.0F, 40.0F,
        41.0F, 42.0F, 43.0F, 44.0F, 40.0F, 40.75F, 41.5F, 42.25F, 43.0F, 40.0F,
        40.5F, 41.0F, 41.5F, 42.0F, 40.0F, 40.25F, 40.5F, 40.75F, 41.0F, 40.0F,
        40.0F, 40.0F, 40.0F, 40.0F
    },

    /* Fr_PoolIirTunablepooliirCoeffs */
    {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* Fr_PooliirpooliirCoeffs */
    {
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
    },

    /* Fr_eqdelays */
    {
        0.0F, 0.0F, 0.0F, 0.0F
    },

    /* Fr_mix */
    {
        4.0F, 3.0F, 2.0F, 1.0F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 2.0F, 1.5F,
        1.0F, 0.5F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.75F, 0.5F, 0.25F, 0.0F, 2.0F,
        1.5F, 1.0F, 0.5F, 0.0F, 3.0F, 2.25F, 1.5F, 0.75F, 0.0F, 4.0F, 3.0F, 2.0F,
        1.0F, 0.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F,
        0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 0.0F, 0.25F, 0.5F, 0.75F, 1.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.25F, 0.5F, 0.75F,
        1.0F, 0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 0.0F, 0.75F, 1.5F, 2.25F, 3.0F, 0.0F,
        1.0F, 2.0F, 3.0F, 4.0F, 9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 8.0F, 7.25F, 6.5F,
        5.75F, 5.0F, 7.0F, 6.5F, 6.0F, 5.5F, 5.0F, 6.0F, 5.75F, 5.5F, 5.25F,
        5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 35.0F, 35.0F, 35.0F, 35.0F, 35.0F,
        35.0F, 35.25F, 35.5F, 35.75F, 36.0F, 35.0F, 35.5F, 36.0F, 36.5F, 37.0F,
        35.0F, 35.75F, 36.5F, 37.25F, 38.0F, 35.0F, 36.0F, 37.0F, 38.0F, 39.0F,
        44.0F, 43.0F, 42.0F, 41.0F, 40.0F, 43.0F, 42.25F, 41.5F, 40.75F, 40.0F,
        42.0F, 41.5F, 41.0F, 40.5F, 40.0F, 41.0F, 40.75F, 40.5F, 40.25F, 40.0F,
        40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F,
        41.0F, 40.75F, 40.5F, 40.25F, 40.0F, 42.0F, 41.5F, 41.0F, 40.5F, 40.0F,
        43.0F, 42.25F, 41.5F, 40.75F, 40.0F, 44.0F, 43.0F, 42.0F, 41.0F, 40.0F,
        40.0F, 41.0F, 42.0F, 43.0F, 44.0F, 40.0F, 40.75F, 41.5F, 42.25F, 43.0F,
        40.0F, 40.5F, 41.0F, 41.5F, 42.0F, 40.0F, 40.25F, 40.5F, 40.75F, 41.0F,
        40.0F, 40.0F, 40.0F, 40.0F, 40.0F
    },

    /* LevelDetectPreEmphasisShelfFilterpooliirCoeffs */
    {
        1.97739339F, -1.98204243F, -0.977646053F, 0.982202291F, 1.97739339F,
        -1.98204243F, -0.977646053F, 0.982202291F, 1.58121288F, 1.58121288F
    },

    /* LevelDetectSysMaxDbspl */
    123.0F,

    /* RampDbPerSample */
    0.005F,

    /* Ann1Ann1VolumeTable_Idx */
    {
        1U, 32U, 64U, 96U, 128U, 160U, 192U, 224U, 224U, 224U, 224U, 224U, 224U,
        224U, 224U, 224U
    },

    /* Ann2Ann2VolumeTable_Idx */
    {
        1U, 32U, 64U, 96U, 128U, 160U, 192U, 224U, 224U, 224U, 224U, 224U, 224U,
        224U, 224U, 224U
    },

    /* Ann3Ann3VolumeTable_Idx */
    {
        1U, 32U, 64U, 96U, 128U, 160U, 192U, 224U, 224U, 224U, 224U, 224U, 224U,
        224U, 224U, 224U
    },

    /* Ann4Ann4VolumeTable_Idx */
    {
        1U, 32U, 64U, 96U, 128U, 160U, 192U, 224U, 224U, 224U, 224U, 224U, 224U,
        224U, 224U, 224U
    },

    /* Dr_PoolIirTunablePooliirNumStages */
    {
        25U, 25U, 25U, 25U
    },

    /* Dr_PooliirPooliirNumStages */
    {
        14U, 14U, 14U, 14U, 14U, 14U, 14U
    },

    /* Fr_PoolIirTunablePooliirNumStages */
    {
        25U, 25U, 25U, 25U
    },

    /* Fr_PooliirPooliirNumStages */
    {
        20U, 20U, 20U, 20U, 20U
    },

    /* LevelDetectPreEmphasisShelfFilterPooliirNumStages */
    {
        1U, 1U
    },

    /* NumStages */
    {
        3U, 3U, 3U, 3U
    },
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
