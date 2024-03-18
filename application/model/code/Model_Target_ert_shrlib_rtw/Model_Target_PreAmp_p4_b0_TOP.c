/*
 * File: Model_Target_PreAmp_p4_b0_TOP.c
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

#pragma section("MODEL_TARGET_PREAMP_P4_B0_MEMORY_SECTION")

#endif

Model_Target_PreAmp_p4_b0_type Model_Target_PreAmp_p4_b0 =
{
    /* AudiopilotHfNoiseRefLatencySamples */
    69,

    /* AudiopilotLfNoiseRefLatencySamples */
    48,

    /* AudiopilotMidrangeLpfAlignDelaySamples */
    4,

    /* LevelDetectMusicDelaySamples */
    66,

    /* AudiopilotAntiZipperRampLpfDenominator */
    {
        1.0F, -0.972033083F
    },

    /* AudiopilotAntiZipperRampLpfNumerator */
    0.0279669166F,

    /* AudiopilotBassBpfDenominator */
    {
        1.0F, -1.99482453F, 0.994856715F
    },

    /* AudiopilotBassBpfNumerator */
    {
        0.00257168314F, 0.0F, -0.00257168314F
    },

    /* AudiopilotBassDownwardSlopeDbPerDb */
    0.0F,

    /* AudiopilotBassDownwardThreshDbspl */
    40.0F,

    /* AudiopilotBassMaxAudiopilotBoostDb */
    20.0F,

    /* AudiopilotBassMaxDyneqBoostDb */
    20.0F,

    /* AudiopilotBassMaxTotalBoostDb */
    40.0F,

    /* AudiopilotBassSlope0Dbperdb */
    0.65F,

    /* AudiopilotBassSlope1Dbperdb */
    0.75F,

    /* AudiopilotBassThresh0Db */
    -3.0F,

    /* AudiopilotBassThresh1Db */
    -4.0F,

    /* AudiopilotDyneqBassSlopeDbPerDb */
    0.35F,

    /* AudiopilotDyneqBassThreshDbspl */
    95.0F,

    /* AudiopilotEnableRampCoef */
    0.992803752F,

    /* AudiopilotHfNoiseHighBoundDbspl */
    30.0F,

    /* AudiopilotHfNoiseImpulseRejectionFlatnessHighIndex */
    40.0F,

    /* AudiopilotHfNoiseImpulseRejectionFlatnessLowIndex */
    10.0F,

    /* AudiopilotHfNoiseImpulseRejectionFlatnessThresh */
    0.9F,

    /* AudiopilotHfNoiseImpulseRejectionLevelUpdateCoef */
    0.07F,

    /* AudiopilotHfNoiseImpulseRejectionMinSearchCoef */
    0.7F,

    /* AudiopilotHfNoiseImpulseRejectionMinSearchMinGain */
    2.12F,

    /* AudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor */
    0.96F,

    /* AudiopilotHfNoiseImpulseRejectionMinstatAlphaMin */
    0.2F,

    /* AudiopilotHfNoiseImpulseRejectionMinstatBeta */
    0.7F,

    /* AudiopilotHfNoiseImpulseRejectionMinstatMin */
    0.7F,

    /* AudiopilotHfNoiseImpulseRejectionSubWinLenSamples */
    22.0F,

    /* AudiopilotHfNoiseLowBoundDbspl */
    20.0F,

    /* AudiopilotHfNoiseOffsetDb */
    72.0F,

    /* AudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs */
    {
        1.84952378F, -1.36041093F, -0.86048317F, 1.0F, 1.91980386F, -1.86167896F,
        -0.949717343F, 1.0F, 1.84952378F, -1.36041093F, -0.86048317F, 1.0F,
        1.91980386F, -1.86167896F, -0.949717343F, 1.0F, 1.84952378F,
        -1.36041093F, -0.86048317F, 1.0F, 1.91980386F, -1.86167896F,
        -0.949717343F, 1.0F, 1.84952378F, -1.36041093F, -0.86048317F, 1.0F,
        1.91980386F, -1.86167896F, -0.949717343F, 1.0F, 1.84952378F,
        -1.36041093F, -0.86048317F, 1.0F, 1.91980386F, -1.86167896F,
        -0.949717343F, 1.0F, 0.0034983512F, 0.0034983512F, 0.0034983512F,
        0.0034983512F, 0.0034983512F
    },

    /* AudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs */
    {
        1.38827622F, 2.0F, -0.869090617F, 1.0F, 1.4374969F, 2.0F, -0.874203324F,
        1.0F, 1.36788642F, 2.0F, -0.899350464F, 1.0F, 1.50163555F, -2.0F,
        -0.909862041F, 1.0F, 1.38578272F, -2.0F, -0.961295F, 1.0F, 1.56682026F,
        -2.0F, -0.966843963F, 1.0F, 0.836346388F, 2.0F, -0.186740249F, 1.0F,
        0.93861413F, 2.0F, -0.331853926F, 1.0F, 1.19082308F, 2.0F, -0.689727843F,
        1.0F, 0.836346388F, 2.0F, -0.186740249F, 1.0F, 0.93861413F, 2.0F,
        -0.331853926F, 1.0F, 1.19082308F, 2.0F, -0.689727843F, 1.0F,
        0.836346388F, 2.0F, -0.186740249F, 1.0F, 0.93861413F, 2.0F,
        -0.331853926F, 1.0F, 1.19082308F, 2.0F, -0.689727843F, 1.0F,
        0.836346388F, 2.0F, -0.186740249F, 1.0F, 0.93861413F, 2.0F,
        -0.331853926F, 1.0F, 1.19082308F, 2.0F, -0.689727843F, 1.0F,
        9.7564957E-8F, 0.00107411703F, 0.00107411703F, 0.00107411703F,
        0.00107411703F
    },

    /* AudiopilotHfNoiseRefPowerMin */
    9.99999727E-9F,

    /* AudiopilotHfNoiseSlewAttackDbPerSample */
    0.138666674F,

    /* AudiopilotHfNoiseSlewDecayDbPerSample */
    -0.554666698F,

    /* AudiopilotHfNoiseSlewThresholdDb */
    2.0F,

    /* AudiopilotHvacTable */
    {
        0.0F, 0.0666666701F, 0.13333334F, 0.2F, 0.266666681F, 0.333333343F, 0.4F,
        0.466666669F, 0.533333361F, 0.6F, 0.666666687F, 0.733333349F, 0.8F,
        0.866666675F, 0.933333337F, 1.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
        60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
        60.0F
    },

    /* AudiopilotLevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* AudiopilotLevelDetectHoldMarginDb */
    6.0F,

    /* AudiopilotLevelDetectHoldTimeSamples */
    4135.0F,

    /* AudiopilotLevelDetectMaxVolumeDb */
    0.0F,

    /* AudiopilotLevelDetectMinVolumeDb */
    -80.0F,

    /* AudiopilotLevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* AudiopilotLfNoiseEnergyLpfCoef */
    0.234915063F,

    /* AudiopilotLfNoiseHighBoundDbspl */
    88.0F,

    /* AudiopilotLfNoiseImpulseRejectionGamma0 */
    0.441329688F,

    /* AudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef */
    0.684884727F,

    /* AudiopilotLfNoiseImpulseRejectionImpulseVarianceScale */
    10.0F,

    /* AudiopilotLfNoiseImpulseRejectionMusicVarianceScale */
    -0.05F,

    /* AudiopilotLfNoiseImpulseRejectionNoiseVarianceScale */
    0.1F,

    /* AudiopilotLfNoiseImpulseRejectionOutputMin */
    0.0001F,

    /* AudiopilotLfNoiseLowBoundDbspl */
    83.0F,

    /* AudiopilotLfNoiseMicpooliirCoeffs */
    {
        1.99280834F, -1.99303508F, -0.992839098F, 1.0F, 1.99538469F,
        -1.99897337F, -0.995508671F, 1.0F, 1.99838531F, -1.99939823F,
        -0.998585045F, 1.0F, 0.000157780625F
    },

    /* AudiopilotLfNoiseOffsetDb */
    0.0F,

    /* AudiopilotLfNoiseRefpooliirCoeffs */
    {
        1.99280834F, -1.99303508F, -0.992839098F, 1.0F, 1.99538469F,
        -1.99897337F, -0.995508671F, 1.0F, 1.99838531F, -1.99939823F,
        -0.998585045F, 1.0F, 0.000157780625F
    },

    /* AudiopilotLfNoiseSlewAttackDbPerSample */
    0.554666698F,

    /* AudiopilotLfNoiseSlewDecayDbPerSample */
    -2.21866679F,

    /* AudiopilotLfNoiseSlewSlowDbPerSample */
    0.0924444497F,

    /* AudiopilotLfNoiseSlewThresholdDb */
    3.0F,

    /* AudiopilotLfNoiseSpeedBoundsAxis */
    {
        0.0F, 4.0F, 8.0F, 12.0F, 16.0F, 20.0F, 24.0F, 28.0F, 32.0F, 36.0F, 40.0F,
        44.0F, 48.0F, 52.0F, 56.0F, 60.0F, 64.0F, 68.0F, 72.0F, 76.0F, 80.0F,
        84.0F, 88.0F, 92.0F, 96.0F, 100.0F, 104.0F, 108.0F, 112.0F, 116.0F,
        120.0F, 124.0F, 128.0F, 132.0F, 136.0F, 140.0F, 144.0F, 148.0F, 152.0F,
        156.0F, 160.0F, 164.0F, 168.0F, 172.0F, 176.0F, 180.0F, 184.0F, 188.0F,
        192.0F, 196.0F, 200.0F, 204.0F, 208.0F, 212.0F, 216.0F, 220.0F, 224.0F,
        228.0F, 232.0F, 236.0F, 240.0F, 244.0F, 248.0F, 252.0F, 256.0F, 260.0F,
        264.0F, 268.0F, 272.0F, 276.0F, 280.0F, 284.0F, 288.0F, 292.0F, 296.0F,
        300.0F, 304.0F, 308.0F, 312.0F, 316.0F, 320.0F, 324.0F, 328.0F, 332.0F,
        336.0F, 340.0F, 344.0F, 348.0F, 352.0F, 356.0F, 360.0F, 364.0F, 368.0F,
        372.0F, 376.0F, 380.0F, 384.0F, 388.0F, 392.0F, 396.0F, 400.0F, 404.0F,
        408.0F, 412.0F, 416.0F, 420.0F, 424.0F, 428.0F, 432.0F, 436.0F, 440.0F,
        444.0F, 448.0F, 452.0F, 456.0F, 460.0F, 464.0F, 468.0F, 472.0F, 476.0F,
        480.0F, 484.0F, 488.0F, 492.0F, 496.0F, 500.0F, 504.0F, 508.0F
    },

    /* AudiopilotLfNoiseSpeedBoundsMaxDbspl */
    {
        3.0F, 6.0F, 9.0F, 12.0F, 15.0F, 18.0F, 21.0F, 24.0F, 27.0F, 30.0F, 33.0F,
        36.0F, 39.0F, 42.0F, 45.0F, 48.0F, 51.0F, 54.0F, 57.0F, 60.0F, 63.0F,
        66.0F, 69.0F, 72.0F, 75.0F, 78.0F, 81.0F, 84.0F, 87.0F, 90.0F, 93.0F,
        96.0F, 99.0F, 102.0F, 105.0F, 108.0F, 111.0F, 114.0F, 117.0F, 120.0F,
        123.0F, 126.0F, 129.0F, 132.0F, 135.0F, 138.0F, 141.0F, 144.0F, 147.0F,
        150.0F, 153.0F, 156.0F, 159.0F, 162.0F, 165.0F, 168.0F, 171.0F, 174.0F,
        177.0F, 180.0F, 183.0F, 186.0F, 189.0F, 192.0F, 195.0F, 198.0F, 201.0F,
        204.0F, 207.0F, 210.0F, 213.0F, 216.0F, 219.0F, 222.0F, 225.0F, 228.0F,
        231.0F, 234.0F, 237.0F, 240.0F, 243.0F, 246.0F, 249.0F, 252.0F, 255.0F,
        258.0F, 261.0F, 264.0F, 267.0F, 270.0F, 273.0F, 276.0F, 279.0F, 282.0F,
        285.0F, 288.0F, 291.0F, 294.0F, 297.0F, 300.0F, 303.0F, 306.0F, 309.0F,
        312.0F, 315.0F, 318.0F, 321.0F, 324.0F, 327.0F, 330.0F, 333.0F, 336.0F,
        339.0F, 342.0F, 345.0F, 348.0F, 351.0F, 354.0F, 357.0F, 360.0F, 363.0F,
        366.0F, 369.0F, 372.0F, 375.0F, 378.0F, 381.0F, 384.0F
    },

    /* AudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl */
    3.0F,

    /* AudiopilotLfNoiseSpeedBoundsMinDbspl */
    {
        3.0F, 6.0F, 9.0F, 12.0F, 15.0F, 18.0F, 21.0F, 24.0F, 27.0F, 30.0F, 33.0F,
        36.0F, 39.0F, 42.0F, 45.0F, 48.0F, 51.0F, 54.0F, 57.0F, 60.0F, 63.0F,
        66.0F, 69.0F, 72.0F, 75.0F, 78.0F, 81.0F, 84.0F, 87.0F, 90.0F, 93.0F,
        96.0F, 99.0F, 102.0F, 105.0F, 108.0F, 111.0F, 114.0F, 117.0F, 120.0F,
        123.0F, 126.0F, 129.0F, 132.0F, 135.0F, 138.0F, 141.0F, 144.0F, 147.0F,
        150.0F, 153.0F, 156.0F, 159.0F, 162.0F, 165.0F, 168.0F, 171.0F, 174.0F,
        177.0F, 180.0F, 183.0F, 186.0F, 189.0F, 192.0F, 195.0F, 198.0F, 201.0F,
        204.0F, 207.0F, 210.0F, 213.0F, 216.0F, 219.0F, 222.0F, 225.0F, 228.0F,
        231.0F, 234.0F, 237.0F, 240.0F, 243.0F, 246.0F, 249.0F, 252.0F, 255.0F,
        258.0F, 261.0F, 264.0F, 267.0F, 270.0F, 273.0F, 276.0F, 279.0F, 282.0F,
        285.0F, 288.0F, 291.0F, 294.0F, 297.0F, 300.0F, 303.0F, 306.0F, 309.0F,
        312.0F, 315.0F, 318.0F, 321.0F, 324.0F, 327.0F, 330.0F, 333.0F, 336.0F,
        339.0F, 342.0F, 345.0F, 348.0F, 351.0F, 354.0F, 357.0F, 360.0F, 363.0F,
        366.0F, 369.0F, 372.0F, 375.0F, 378.0F, 381.0F, 384.0F
    },

    /* AudiopilotLfNoiseSpeedBoundsOn */
    1.0F,

    /* AudiopilotLfNoiseSysMaxDbspl */
    120.0F,

    /* AudiopilotMidrangeDownwardSlopeDbPerDb */
    0.0F,

    /* AudiopilotMidrangeDownwardThreshDbspl */
    40.0F,

    /* AudiopilotMidrangeLpfDenominator */
    {
        1.0F, -2.48273325F, 2.45807505F, -1.13843739F, 0.210260749F
    },

    /* AudiopilotMidrangeLpfNumerator */
    {
        0.00294782105F, 0.0117912842F, 0.0176869258F, 0.0117912842F,
        0.00294782105F
    },

    /* AudiopilotMidrangeMaxTotalBoostDb */
    20.0F,

    /* AudiopilotMidrangeSlope0Dbperdb */
    0.52F,

    /* AudiopilotMidrangeSlope1Dbperdb */
    0.8F,

    /* AudiopilotMidrangeThresh0Db */
    -4.5F,

    /* AudiopilotMidrangeThresh1Db */
    -5.5F,

    /* AudiopilotMinSignalLevelDbspl */
    40.0F,

    /* AudiopilotRatioEnergyLpfCoef */
    0.791998088F,

    /* AudiopilotRatioHighBoundDb */
    60.0F,

    /* AudiopilotRatioImpulseRejectionGamma0 */
    0.0303496122F,

    /* AudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef */
    0.791998088F,

    /* AudiopilotRatioImpulseRejectionImpulseVarianceScale */
    100.0F,

    /* AudiopilotRatioImpulseRejectionNoiseVarianceScale */
    0.1F,

    /* AudiopilotRatioLowBoundDb */
    50.0F,

    /* AudiopilotRatioSlewAttackDbPerSample */
    0.138666674F,

    /* AudiopilotRatioSlewDecayDbPerSample */
    -0.554666698F,

    /* AudiopilotRatioSlewThresholdDb */
    1.0F,

    /* AudiopilotRatioUpdateFlagHoldTimeSamples */
    130.0F,

    /* AudiopilotRatioUpdateHfNoiseThreshDbspl */
    30.0F,

    /* AudiopilotRatioUpdateLfNoiseThreshDbspl */
    60.0F,

    /* AudiopilotRatioUpdateLfNoiseUpdatePeriodSamples */
    33.0F,

    /* AudiopilotRatioUpdateLfNoiseUpdateThreshDb */
    2.0F,

    /* AudiopilotRatioUpdateSpeedUpdateThreshMph */
    40.0F,

    /* AudiopilotTrebleDownwardSlopeDbPerDb */
    0.0F,

    /* AudiopilotTrebleDownwardThreshDbspl */
    43.0F,

    /* AudiopilotTrebleMaxTotalBoostDb */
    14.0F,

    /* AudiopilotTrebleSlope0Dbperdb */
    0.35F,

    /* AudiopilotTrebleSlope1Dbperdb */
    0.5F,

    /* AudiopilotTrebleThresh0Db */
    -7.0F,

    /* AudiopilotTrebleThresh1Db */
    -7.5F,

    /* DyneqLevelDetectFastDecayDbPerSample */
    -0.00362811796F,

    /* DyneqLevelDetectHoldMarginDb */
    6.0F,

    /* DyneqLevelDetectHoldTimeSamples */
    4135.0F,

    /* DyneqLevelDetectMaxVolumeDb */
    0.0F,

    /* DyneqLevelDetectMinVolumeDb */
    -80.0F,

    /* DyneqLevelDetectSlowDecayDbPerSample */
    -7.25623613E-5F,

    /* LevelDetectPreemphasispooliirCoeffs */
    {
        1.97739339F, -1.98204243F, -0.977646053F, 0.982202291F, 1.97739339F,
        -1.98204243F, -0.977646053F, 0.982202291F, 0.997677922F, 0.997677922F
    },

    /* LevelDetectSysMaxDbspl */
    123.0F,

    /* VolumeCfgRampTime */
    100.0F,

    /* VolumeCfgTable_dB */
    {
        -100.0F, -30.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
    },

    /* VolumeCfgmaxgain */
    0.0F,

    /* AudiopilotHfNoisePreprocessAntiAliasPooliirNumStages */
    {
        2U, 2U, 2U, 2U, 2U
    },

    /* AudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages */
    {
        6U, 3U, 3U, 3U, 3U
    },

    /* AudiopilotLfNoiseMicPooliirNumStages */
    3U,

    /* AudiopilotLfNoiseRefPooliirNumStages */
    3U,

    /* AudiopilotTwoDowngrade */
    0U,

    /* LevelDetectPreemphasisPooliirNumStages */
    {
        1U, 1U
    },

    /* VolumeCfgTable_Idx */
    {
        0U, 128U, 255U, 255U, 255U, 255U, 255U, 255U
    },
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
