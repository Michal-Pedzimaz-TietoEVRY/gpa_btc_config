/*
 * File: Model_Target_TOP_Access.c
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

#include "rtwtypes.h"
#include "ASDID.h"                     // for ASDID parsing macros
#include "Model_Target_TOP.h"
#include <string.h>                    // for memcpy
#include "Model_Target_TOP_Access.h"
#include "Model_Target_TOP_IDs.h"      // for request structure
#include "Model_Target_Partitions.h"   // for partition root

void* TopGroup0Partition0[] =          /* '<S3>/Partition' */
{
    &Model_Target_InputSelect_p0_b0.RouterCfgOutMap,
};

uint32_t TopGroup0Partition0Size[] =   /* '<S3>/Partition' */
{
    sizeof(Model_Target_InputSelect_p0_b0.RouterCfgOutMap),
};

void* TopGroup2Partition4[] =          /* '<S32>/Partition' */
{
    &Model_Target_PreAmp_p4_b0.AudiopilotAntiZipperRampLpfDenominator,
    &Model_Target_PreAmp_p4_b0.AudiopilotAntiZipperRampLpfNumerator,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassBpfDenominator,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassBpfNumerator,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassDownwardSlopeDbPerDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassDownwardThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassMaxAudiopilotBoostDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassMaxDyneqBoostDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassMaxTotalBoostDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassSlope0Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassSlope1Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassThresh0Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotBassThresh1Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotDyneqBassSlopeDbPerDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotDyneqBassThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotEnableRampCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseHighBoundDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessHighIndex,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessLowIndex,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessThresh,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinSearchCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinSearchMinGain,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatBeta,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatMin,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionSubWinLenSamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseLowBoundDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseOffsetDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessAntiAliasPooliirNumStages,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseRefLatencySamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseRefPowerMin,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewAttackDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewThresholdDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotHvacTable,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectFastDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectHoldMarginDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectHoldTimeSamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectMaxVolumeDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectMinVolumeDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectSlowDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseEnergyLpfCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseHighBoundDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionGamma0,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionImpulseVarianceScale,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionMusicVarianceScale,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionNoiseVarianceScale,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionOutputMin,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseLowBoundDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseMicPooliirNumStages,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseMicpooliirCoeffs,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseOffsetDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefLatencySamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefPooliirNumStages,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefpooliirCoeffs,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewAttackDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewSlowDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewThresholdDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsAxis,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMaxDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMinDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsOn,
    &Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSysMaxDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeDownwardSlopeDbPerDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeDownwardThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfAlignDelaySamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfDenominator,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfNumerator,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeMaxTotalBoostDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeSlope0Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeSlope1Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeThresh0Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotMidrangeThresh1Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotMinSignalLevelDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioEnergyLpfCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioHighBoundDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionGamma0,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionImpulseVarianceScale,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionNoiseVarianceScale,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioLowBoundDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewAttackDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewThresholdDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateFlagHoldTimeSamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateHfNoiseThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseUpdatePeriodSamples,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseUpdateThreshDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateSpeedUpdateThreshMph,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleDownwardSlopeDbPerDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleDownwardThreshDbspl,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleMaxTotalBoostDb,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleSlope0Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleSlope1Dbperdb,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleThresh0Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotTrebleThresh1Db,
    &Model_Target_PreAmp_p4_b0.AudiopilotTwoDowngrade,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectFastDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectHoldMarginDb,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectHoldTimeSamples,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectMaxVolumeDb,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectMinVolumeDb,
    &Model_Target_PreAmp_p4_b0.DyneqLevelDetectSlowDecayDbPerSample,
    &Model_Target_PreAmp_p4_b0.LevelDetectMusicDelaySamples,
    &Model_Target_PreAmp_p4_b0.LevelDetectPreemphasisPooliirNumStages,
    &Model_Target_PreAmp_p4_b0.LevelDetectPreemphasispooliirCoeffs,
    &Model_Target_PreAmp_p4_b0.LevelDetectSysMaxDbspl,
    &Model_Target_PreAmp_p4_b0.VolumeCfgRampTime,
    &Model_Target_PreAmp_p4_b0.VolumeCfgTable_Idx,
    &Model_Target_PreAmp_p4_b0.VolumeCfgTable_dB,
    &Model_Target_PreAmp_p4_b0.VolumeCfgmaxgain,
};

uint32_t TopGroup2Partition4Size[] =   /* '<S32>/Partition' */
{
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotAntiZipperRampLpfDenominator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotAntiZipperRampLpfNumerator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassBpfDenominator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassBpfNumerator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassDownwardSlopeDbPerDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassDownwardThreshDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassMaxAudiopilotBoostDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassMaxDyneqBoostDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassMaxTotalBoostDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassSlope0Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassSlope1Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassThresh0Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotBassThresh1Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotDyneqBassSlopeDbPerDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotDyneqBassThreshDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotEnableRampCoef),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseHighBoundDbspl),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessHighIndex),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessLowIndex),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionFlatnessThresh),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionLevelUpdateCoef),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinSearchCoef),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinSearchMinGain),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatAlphaMin),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatBeta),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionMinstatMin),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseImpulseRejectionSubWinLenSamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseLowBoundDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseOffsetDb),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessAntiAliasPooliirNumStages),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseRefLatencySamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseRefPowerMin),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewAttackDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHfNoiseSlewThresholdDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotHvacTable),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectHoldMarginDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectHoldTimeSamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectMaxVolumeDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectMinVolumeDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseEnergyLpfCoef),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseHighBoundDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionGamma0),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionImpulseVarianceScale),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionMusicVarianceScale),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionNoiseVarianceScale),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseImpulseRejectionOutputMin),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseLowBoundDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseMicPooliirNumStages),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseMicpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseOffsetDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefLatencySamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefPooliirNumStages),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseRefpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewAttackDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewSlowDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSlewThresholdDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsAxis),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMaxDbspl),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsMinDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSpeedBoundsOn),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotLfNoiseSysMaxDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeDownwardSlopeDbPerDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeDownwardThreshDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfAlignDelaySamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfDenominator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeLpfNumerator),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeMaxTotalBoostDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeSlope0Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeSlope1Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeThresh0Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMidrangeThresh1Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotMinSignalLevelDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioEnergyLpfCoef),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioHighBoundDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionGamma0),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionImpulseVarianceScale),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotRatioImpulseRejectionNoiseVarianceScale),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioLowBoundDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewAttackDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioSlewThresholdDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateFlagHoldTimeSamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateHfNoiseThreshDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseThreshDbspl),
    sizeof
    (Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseUpdatePeriodSamples),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateLfNoiseUpdateThreshDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotRatioUpdateSpeedUpdateThreshMph),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleDownwardSlopeDbPerDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleDownwardThreshDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleMaxTotalBoostDb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleSlope0Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleSlope1Dbperdb),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleThresh0Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTrebleThresh1Db),
    sizeof(Model_Target_PreAmp_p4_b0.AudiopilotTwoDowngrade),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectHoldMarginDb),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectHoldTimeSamples),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectMaxVolumeDb),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectMinVolumeDb),
    sizeof(Model_Target_PreAmp_p4_b0.DyneqLevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_PreAmp_p4_b0.LevelDetectMusicDelaySamples),
    sizeof(Model_Target_PreAmp_p4_b0.LevelDetectPreemphasisPooliirNumStages),
    sizeof(Model_Target_PreAmp_p4_b0.LevelDetectPreemphasispooliirCoeffs),
    sizeof(Model_Target_PreAmp_p4_b0.LevelDetectSysMaxDbspl),
    sizeof(Model_Target_PreAmp_p4_b0.VolumeCfgRampTime),
    sizeof(Model_Target_PreAmp_p4_b0.VolumeCfgTable_Idx),
    sizeof(Model_Target_PreAmp_p4_b0.VolumeCfgTable_dB),
    sizeof(Model_Target_PreAmp_p4_b0.VolumeCfgmaxgain),
};

void* TopGroup2Partition11[] =         /* '<S557>/Partition' */
{
    &Model_Target_PreAmp_p11_b0.Balance_CfgBoostDisable,
    &Model_Target_PreAmp_p11_b0.Balance_CfgChanRampMap,
    &Model_Target_PreAmp_p11_b0.Balance_CfgEnableSilentExtreme,
    &Model_Target_PreAmp_p11_b0.Balance_CfgOffset,
    &Model_Target_PreAmp_p11_b0.Balance_CfgRampTime,
    &Model_Target_PreAmp_p11_b0.Balance_CfgSleepingBeautyMutesBass,
    &Model_Target_PreAmp_p11_b0.Balance_CfgTableDb,
    &Model_Target_PreAmp_p11_b0.Balance_CfgTableIdx,
};

uint32_t TopGroup2Partition11Size[] =  /* '<S557>/Partition' */
{
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgBoostDisable),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgChanRampMap),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgEnableSilentExtreme),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgOffset),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgRampTime),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgSleepingBeautyMutesBass),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgTableDb),
    sizeof(Model_Target_PreAmp_p11_b0.Balance_CfgTableIdx),
};

void* TopGroup2Partition2[] =          /* '<S585>/Partition' */
{
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerGainLfe2C,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerHpfPooliirNumStages,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerHpfpooliirCoeffs,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerLeftMixWeights,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerLpfPooliirNumStages,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerLpfpooliirCoeffs,
    &Model_Target_PreAmp_p2_b0.MedusaBassManagerRightMixWeights,
    &Model_Target_PreAmp_p2_b0.MedusaDummyTune,
};

uint32_t TopGroup2Partition2Size[] =   /* '<S585>/Partition' */
{
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerGainLfe2C),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerHpfPooliirNumStages),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerHpfpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerLeftMixWeights),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerLpfPooliirNumStages),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerLpfpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaBassManagerRightMixWeights),
    sizeof(Model_Target_PreAmp_p2_b0.MedusaDummyTune),
};

void* TopGroup2Partition3[] =          /* '<S586>/Partition' */
{
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDLowerbounddB,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDStepSize,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDUpperbounddB,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsLokRokMaxScaleFactor,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsXpMax,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsXpMin,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumDirectPathSamplesDec,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumFastPsdSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumLsSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumOverwrite,
    &Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumSlowPsdSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDLowerbounddB,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDStepSize,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDUpperbounddB,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsLokRokMaxScaleFactor,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsXpMax,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsXpMin,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumDirectPathSamplesDec,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumFastPsdSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumLsSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumOverwrite,
    &Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumSlowPsdSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorEnable,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorHPFCoeffs,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorHPFNumStages,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLRMatchTolerance,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothGain,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothPole,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothResetGain,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothResetPole,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLevelGain,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLevelPole,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdMono,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdStereo,
    &Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdZeroLevel,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstDecaySmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstDirectPathFramesFs,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstFastAttack,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstHPFPooliirNumStages,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstHPFpooliirCoeffs,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstNoiseFloor,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstOnsetThreshold,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstPSDSmoothFactor,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstSlewThreshold,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstSlowAttack,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstStepDecrement,
    &Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstStepIncrement,
    &Model_Target_PreAmp_p3_b0.MedusaTrebleDelay,
};

uint32_t TopGroup2Partition3Size[] =   /* '<S586>/Partition' */
{
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDLowerbounddB),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDStepSize),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsESDUpperbounddB),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsLokRokMaxScaleFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsXpMax),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpCoeffsXpMin),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumDirectPathSamplesDec),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumFastPsdSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumLsSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumOverwrite),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaDeciRateFdpSpumSlowPsdSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDLowerbounddB),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDStepSize),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsESDUpperbounddB),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsLokRokMaxScaleFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsXpMax),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpCoeffsXpMin),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumDirectPathSamplesDec),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumFastPsdSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumLsSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumOverwrite),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaFullRateFdpSpumSlowPsdSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorEnable),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorHPFCoeffs),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorHPFNumStages),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLRMatchTolerance),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothGain),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothPole),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothResetGain),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLSSmoothResetPole),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLevelGain),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorLevelPole),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdMono),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdStereo),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorThresholdZeroLevel),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstDecaySmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstDirectPathFramesFs),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstFastAttack),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstHPFPooliirNumStages),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstHPFpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstNoiseFloor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstOnsetThreshold),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstPSDSmoothFactor),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstSlewThreshold),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstSlowAttack),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstStepDecrement),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaSPUMDecayEstStepIncrement),
    sizeof(Model_Target_PreAmp_p3_b0.MedusaTrebleDelay),
};

void* TopGroup2Partition5[] =          /* '<S587>/Partition' */
{
    &Model_Target_PreAmp_p5_b0.MedusaDeciRateBassDelay,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateBassDelay,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerBackwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerBackwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_CS,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Left,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Right,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerForwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerForwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerInterpolation_Method,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaMidrangeDelay,
    &Model_Target_PreAmp_p5_b0.MedusaPremixBackwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaPremixBackwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_CS,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Left,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Right,
    &Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixForwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaPremixForwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaPremixInterpolation_Method,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_CS,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_CS_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Left,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Left_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Right,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Right_CAE,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundCosPhi,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundPhi,
    &Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundSinPhi,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsBackwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsBackwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsDetentLevel,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsDownmixWeights,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsForwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsForwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsInterpolation_Method,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsMaxLevel,
    &Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsMinLevel,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsBackwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsBackwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsDetentLevel,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsDownmixWeights,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsForwardDownmixMax,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsForwardDownmixThreshold,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsInterpolation_Method,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsMaxLevel,
    &Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsMinLevel,
    &Model_Target_PreAmp_p5_b0.MedusaWiggleFilter,
    &Model_Target_PreAmp_p5_b0.MedusatailCompEQPooliirNumStages,
    &Model_Target_PreAmp_p5_b0.MedusatailCompEQpooliirCoeffs,
};

uint32_t TopGroup2Partition5Size[] =   /* '<S587>/Partition' */
{
    sizeof(Model_Target_PreAmp_p5_b0.MedusaDeciRateBassDelay),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateBassDelay),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerBackwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerBackwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDetentLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerDownmixWeights_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerForwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerForwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerInterpolation_Method),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMaxLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaFullRateMixerMinLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaMidrangeDelay),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixBackwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixBackwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDetentLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixDownmixWeights_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixForwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixForwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixInterpolation_Method),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMaxLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_CS),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_CS_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Left),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Left_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Right),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMinLevel_Right_CAE),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundCosPhi),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundPhi),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaPremixMonoSurroundSinPhi),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsBackwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsBackwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsDetentLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsDownmixWeights),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsForwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsForwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsInterpolation_Method),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsMaxLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSDrvGainsMinLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsBackwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsBackwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsDetentLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsDownmixWeights),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsForwardDownmixMax),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsForwardDownmixThreshold),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsInterpolation_Method),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsMaxLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaVLSPaxGainsMinLevel),
    sizeof(Model_Target_PreAmp_p5_b0.MedusaWiggleFilter),
    sizeof(Model_Target_PreAmp_p5_b0.MedusatailCompEQPooliirNumStages),
    sizeof(Model_Target_PreAmp_p5_b0.MedusatailCompEQpooliirCoeffs),
};

void* TopGroup2Partition6[] =          /* '<S588>/Partition' */
{
    &Model_Target_PreAmp_p6_b1.MedusaDRHoligramFIRCoeffs,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramFilterLengths,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramInputMapping,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramOutputMapping,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramPaddedFilterLengths,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramPoolIirTunableConfigPooliirNumStages,
    &Model_Target_PreAmp_p6_b0.MedusaDRHoligramPoolIirTunableConfigpooliirCoeffs,
    &Model_Target_PreAmp_p6_b0.MedusaFRHoligramIirConfigPooliirNumStages,
    &Model_Target_PreAmp_p6_b0.MedusaFRHoligramIirConfigpooliirCoeffs,
    &Model_Target_PreAmp_p6_b1.MedusaHeadrestCompEQFIRCoeffs,
    &Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQFilterLengths,
    &Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQIirConfigPooliirNumStages,
    &Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQIirConfigpooliirCoeffs,
    &Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQPaddedFilterLengths,
};

uint32_t TopGroup2Partition6Size[] =   /* '<S588>/Partition' */
{
    sizeof(Model_Target_PreAmp_p6_b1.MedusaDRHoligramFIRCoeffs),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaDRHoligramFilterLengths),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaDRHoligramInputMapping),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaDRHoligramOutputMapping),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaDRHoligramPaddedFilterLengths),
    sizeof
    (Model_Target_PreAmp_p6_b0.MedusaDRHoligramPoolIirTunableConfigPooliirNumStages),
    sizeof
    (Model_Target_PreAmp_p6_b0.MedusaDRHoligramPoolIirTunableConfigpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaFRHoligramIirConfigPooliirNumStages),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaFRHoligramIirConfigpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p6_b1.MedusaHeadrestCompEQFIRCoeffs),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQFilterLengths),
    sizeof
    (Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQIirConfigPooliirNumStages),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQIirConfigpooliirCoeffs),
    sizeof(Model_Target_PreAmp_p6_b0.MedusaHeadrestCompEQPaddedFilterLengths),
};

void* TopGroup2Partition8[] =          /* '<S590>/Partition' */
{
    &Model_Target_PreAmp_p8_b0.MedusaDRSpeakerDelay,
    &Model_Target_PreAmp_p8_b0.MedusaFRSpeakerDelay,
};

uint32_t TopGroup2Partition8Size[] =   /* '<S590>/Partition' */
{
    sizeof(Model_Target_PreAmp_p8_b0.MedusaDRSpeakerDelay),
    sizeof(Model_Target_PreAmp_p8_b0.MedusaFRSpeakerDelay),
};

void* TopGroup2Partition1[] =          /* '<S559>/Partition' */
{
    &Model_Target_PreAmp_p1_b0.MedusaRoutingMap,
};

uint32_t TopGroup2Partition1Size[] =   /* '<S559>/Partition' */
{
    sizeof(Model_Target_PreAmp_p1_b0.MedusaRoutingMap),
};

void* TopGroup2Partition13[] =         /* '<S560>/Partition' */
{
    &Model_Target_PreAmp_p13_b0.NearDelay,
    &Model_Target_PreAmp_p13_b0.NearWiggleCoeffs,
};

uint32_t TopGroup2Partition13Size[] =  /* '<S560>/Partition' */
{
    sizeof(Model_Target_PreAmp_p13_b0.NearDelay),
    sizeof(Model_Target_PreAmp_p13_b0.NearWiggleCoeffs),
};

void* TopGroup2Partition9[] =          /* '<S561>/Partition' */
{
    &Model_Target_PreAmp_p9_b0.FadeControlBoostDisable,
    &Model_Target_PreAmp_p9_b0.FadeControlEnableSilentExtreme,
    &Model_Target_PreAmp_p9_b0.FadeControlRampTime,
    &Model_Target_PreAmp_p9_b0.FadeControlTableDb,
    &Model_Target_PreAmp_p9_b0.FadeControlTableIdx,
    &Model_Target_PreAmp_p9_b0.FadeControloffset,
    &Model_Target_PreAmp_p9_b0.FadeRamperDRChannelToRamperMap,
    &Model_Target_PreAmp_p9_b0.FadeRamperDRTOPFilterCoefficients,
    &Model_Target_PreAmp_p9_b0.FadeRamperFRChannelToRamperMap,
    &Model_Target_PreAmp_p9_b0.FadeRamperFRTOPFilterCoefficients,
    &Model_Target_PreAmp_p9_b0.MuteControlRampTime,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDRChannelToRamperMap,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDRMutesBass,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDROffset,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDRRampTime,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableDb,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableIdx,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFRChannelToRamperMap,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFRMutesBass,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFROffset,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFRRampTime,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableDb,
    &Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableIdx,
};

uint32_t TopGroup2Partition9Size[] =   /* '<S561>/Partition' */
{
    sizeof(Model_Target_PreAmp_p9_b0.FadeControlBoostDisable),
    sizeof(Model_Target_PreAmp_p9_b0.FadeControlEnableSilentExtreme),
    sizeof(Model_Target_PreAmp_p9_b0.FadeControlRampTime),
    sizeof(Model_Target_PreAmp_p9_b0.FadeControlTableDb),
    sizeof(Model_Target_PreAmp_p9_b0.FadeControlTableIdx),
    sizeof(Model_Target_PreAmp_p9_b0.FadeControloffset),
    sizeof(Model_Target_PreAmp_p9_b0.FadeRamperDRChannelToRamperMap),
    sizeof(Model_Target_PreAmp_p9_b0.FadeRamperDRTOPFilterCoefficients),
    sizeof(Model_Target_PreAmp_p9_b0.FadeRamperFRChannelToRamperMap),
    sizeof(Model_Target_PreAmp_p9_b0.FadeRamperFRTOPFilterCoefficients),
    sizeof(Model_Target_PreAmp_p9_b0.MuteControlRampTime),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDRChannelToRamperMap),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDRMutesBass),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDROffset),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDRRampTime),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableDb),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableIdx),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFRChannelToRamperMap),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFRMutesBass),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFROffset),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFRRampTime),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableDb),
    sizeof(Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableIdx),
};

void* TopGroup2Partition10[] =         /* '<S562>/Partition' */
{
    &Model_Target_PreAmp_p10_b1.VLSGenerationDrvFIRCoeffs,
    &Model_Target_PreAmp_p10_b0.VLSGenerationDrvPaddedFilterLengths,
    &Model_Target_PreAmp_p10_b1.VLSGenerationPaxFIRCoeffs,
    &Model_Target_PreAmp_p10_b0.VLSGenerationPaxPaddedFilterLengths,
    &Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay,
    &Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRPooliirNumStages,
    &Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRpooliirCoeffs,
};

uint32_t TopGroup2Partition10Size[] =  /* '<S562>/Partition' */
{
    sizeof(Model_Target_PreAmp_p10_b1.VLSGenerationDrvFIRCoeffs),
    sizeof(Model_Target_PreAmp_p10_b0.VLSGenerationDrvPaddedFilterLengths),
    sizeof(Model_Target_PreAmp_p10_b1.VLSGenerationPaxFIRCoeffs),
    sizeof(Model_Target_PreAmp_p10_b0.VLSGenerationPaxPaddedFilterLengths),
    sizeof(Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay),
    sizeof(Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRPooliirNumStages),
    sizeof(Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRpooliirCoeffs),
};

void* TopGroup2Partition0[] =          /* '<S26>/Partition' */
{
    &Model_Target_PreAmp_p0_b0.A,
    &Model_Target_PreAmp_p0_b0.AnnPred,
    &Model_Target_PreAmp_p0_b0.BassBoostCoeffs,
    &Model_Target_PreAmp_p0_b0.BassBoostMaximum_dB,
    &Model_Target_PreAmp_p0_b0.BassCutCoeffs,
    &Model_Target_PreAmp_p0_b0.BassCutMaximum_dB,
    &Model_Target_PreAmp_p0_b0.BassOffset,
    &Model_Target_PreAmp_p0_b0.BassScale,
    &Model_Target_PreAmp_p0_b0.Bassramptime,
    &Model_Target_PreAmp_p0_b0.G,
    &Model_Target_PreAmp_p0_b0.Limiterattack,
    &Model_Target_PreAmp_p0_b0.Limiterdecay,
    &Model_Target_PreAmp_p0_b0.LimitermaxAttack,
    &Model_Target_PreAmp_p0_b0.MidrangeBoostCoeffs,
    &Model_Target_PreAmp_p0_b0.MidrangeBoostMaximum_dB,
    &Model_Target_PreAmp_p0_b0.MidrangeCutCoeffs,
    &Model_Target_PreAmp_p0_b0.MidrangeCutMaximum_dB,
    &Model_Target_PreAmp_p0_b0.MidrangeOffset,
    &Model_Target_PreAmp_p0_b0.MidrangeRampTime,
    &Model_Target_PreAmp_p0_b0.MidrangeScale,
    &Model_Target_PreAmp_p0_b0.Offset,
    &Model_Target_PreAmp_p0_b0.TrebleBoostCoeffs,
    &Model_Target_PreAmp_p0_b0.TrebleBoostMaximum_dB,
    &Model_Target_PreAmp_p0_b0.TrebleCutCoeffs,
    &Model_Target_PreAmp_p0_b0.TrebleCutMaximum_dB,
    &Model_Target_PreAmp_p0_b0.TrebleOffset,
    &Model_Target_PreAmp_p0_b0.TrebleScale,
    &Model_Target_PreAmp_p0_b0.Trebleramptime,
    &Model_Target_PreAmp_p0_b0.UpperThreshold,
};

uint32_t TopGroup2Partition0Size[] =   /* '<S26>/Partition' */
{
    sizeof(Model_Target_PreAmp_p0_b0.A),
    sizeof(Model_Target_PreAmp_p0_b0.AnnPred),
    sizeof(Model_Target_PreAmp_p0_b0.BassBoostCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.BassBoostMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.BassCutCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.BassCutMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.BassOffset),
    sizeof(Model_Target_PreAmp_p0_b0.BassScale),
    sizeof(Model_Target_PreAmp_p0_b0.Bassramptime),
    sizeof(Model_Target_PreAmp_p0_b0.G),
    sizeof(Model_Target_PreAmp_p0_b0.Limiterattack),
    sizeof(Model_Target_PreAmp_p0_b0.Limiterdecay),
    sizeof(Model_Target_PreAmp_p0_b0.LimitermaxAttack),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeBoostCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeBoostMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeCutCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeCutMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeOffset),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeRampTime),
    sizeof(Model_Target_PreAmp_p0_b0.MidrangeScale),
    sizeof(Model_Target_PreAmp_p0_b0.Offset),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleBoostCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleBoostMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleCutCoeffs),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleCutMaximum_dB),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleOffset),
    sizeof(Model_Target_PreAmp_p0_b0.TrebleScale),
    sizeof(Model_Target_PreAmp_p0_b0.Trebleramptime),
    sizeof(Model_Target_PreAmp_p0_b0.UpperThreshold),
};

void* TopGroup1Partition0[] =          /* '<S5>/Partition' */
{
    &Model_Target_Near_p0_b0.Ann1Ann1MuteRampTime,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcBoostOverRide,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcBoostOverRideFlag,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcDen,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMaxBoost,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMaxSpl,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMinVncSignal,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNoiseOverRide,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNoiseOverRideFlag,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNum,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncEnableTuneVar,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncSlope,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncThresh,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntVncAppliedNum,
    &Model_Target_Near_p0_b0.Ann1Ann1NonEntVncAppliedden,
    &Model_Target_Near_p0_b0.Ann1Ann1VolumeRampRate,
    &Model_Target_Near_p0_b0.Ann1Ann1VolumeRampTime,
    &Model_Target_Near_p0_b0.Ann1Ann1VolumeTable_Idx,
    &Model_Target_Near_p0_b0.Ann1Ann1VolumeTable_dB,
    &Model_Target_Near_p0_b0.Ann1LevelDetectFastDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann1LevelDetectHoldTimeSamples,
    &Model_Target_Near_p0_b0.Ann1LevelDetectMaxVolumeDb,
    &Model_Target_Near_p0_b0.Ann1LevelDetectMinVolumeDb,
    &Model_Target_Near_p0_b0.Ann1LevelDetectSlowDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann1LevelDetecthold_margin_db,
    &Model_Target_Near_p0_b0.Ann2Ann2MuteRampTime,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcBoostOverRide,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcBoostOverRideFlag,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcDen,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMaxBoost,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMaxSpl,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMinVncSignal,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNoiseOverRide,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNoiseOverRideFlag,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNum,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncEnableTuneVar,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncSlope,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncThresh,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntVncAppliedNum,
    &Model_Target_Near_p0_b0.Ann2Ann2NonEntVncAppliedden,
    &Model_Target_Near_p0_b0.Ann2Ann2VolumeRampRate,
    &Model_Target_Near_p0_b0.Ann2Ann2VolumeRampTime,
    &Model_Target_Near_p0_b0.Ann2Ann2VolumeTable_Idx,
    &Model_Target_Near_p0_b0.Ann2Ann2VolumeTable_dB,
    &Model_Target_Near_p0_b0.Ann2LevelDetectFastDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann2LevelDetectHoldMarginDb,
    &Model_Target_Near_p0_b0.Ann2LevelDetectHoldTimeSamples,
    &Model_Target_Near_p0_b0.Ann2LevelDetectMaxVolumeDb,
    &Model_Target_Near_p0_b0.Ann2LevelDetectMinVolumeDb,
    &Model_Target_Near_p0_b0.Ann2LevelDetectSlowDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann3Ann3MuteRampTime,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcBoostOverRide,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcBoostOverRideFlag,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcDen,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMaxBoost,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMaxSpl,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMinVncSignal,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNoiseOverRide,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNoiseOverRideFlag,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNum,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncEnableTuneVar,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncSlope,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncThresh,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntVncAppliedNum,
    &Model_Target_Near_p0_b0.Ann3Ann3NonEntVncAppliedden,
    &Model_Target_Near_p0_b0.Ann3Ann3VolumeRampRate,
    &Model_Target_Near_p0_b0.Ann3Ann3VolumeRampTime,
    &Model_Target_Near_p0_b0.Ann3Ann3VolumeTable_Idx,
    &Model_Target_Near_p0_b0.Ann3Ann3VolumeTable_dB,
    &Model_Target_Near_p0_b0.Ann3LevelDetectFastDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann3LevelDetectHoldMarginDb,
    &Model_Target_Near_p0_b0.Ann3LevelDetectHoldTimeSamples,
    &Model_Target_Near_p0_b0.Ann3LevelDetectMaxVolumeDb,
    &Model_Target_Near_p0_b0.Ann3LevelDetectMinVolumeDb,
    &Model_Target_Near_p0_b0.Ann3LevelDetectSlowDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann4Ann4MuteRampTime,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcBoostOverRide,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcBoostOverRideFlag,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcDen,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMaxBoost,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMaxSpl,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMinVncSignal,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNoiseOverRide,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNoiseOverRideFlag,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNum,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncEnableTuneVar,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncSlope,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncThresh,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntVncAppliedNum,
    &Model_Target_Near_p0_b0.Ann4Ann4NonEntVncAppliedden,
    &Model_Target_Near_p0_b0.Ann4Ann4VolumeRampRate,
    &Model_Target_Near_p0_b0.Ann4Ann4VolumeRampTime,
    &Model_Target_Near_p0_b0.Ann4Ann4VolumeTable_Idx,
    &Model_Target_Near_p0_b0.Ann4Ann4VolumeTable_dB,
    &Model_Target_Near_p0_b0.Ann4LevelDetectFastDecayDbPerSample,
    &Model_Target_Near_p0_b0.Ann4LevelDetectHoldMarginDb,
    &Model_Target_Near_p0_b0.Ann4LevelDetectHoldTimeSamples,
    &Model_Target_Near_p0_b0.Ann4LevelDetectMaxVolumeDb,
    &Model_Target_Near_p0_b0.Ann4LevelDetectMinVolumeDb,
    &Model_Target_Near_p0_b0.Ann4LevelDetectSlowDecayDbPerSample,
    &Model_Target_Near_p0_b0.Coefficients,
    &Model_Target_Near_p0_b0.Dr_EqDelays,
    &Model_Target_Near_p0_b0.Dr_PoolIirTunablePooliirNumStages,
    &Model_Target_Near_p0_b0.Dr_PoolIirTunablepooliirCoeffs,
    &Model_Target_Near_p0_b0.Dr_PooliirPooliirNumStages,
    &Model_Target_Near_p0_b0.Dr_PooliirpooliirCoeffs,
    &Model_Target_Near_p0_b0.Dr_RouterOutMap,
    &Model_Target_Near_p0_b0.Dr_eqdelays,
    &Model_Target_Near_p0_b0.Dr_mix,
    &Model_Target_Near_p0_b0.Fr_EqDelays,
    &Model_Target_Near_p0_b0.Fr_PoolIirTunablePooliirNumStages,
    &Model_Target_Near_p0_b0.Fr_PoolIirTunablepooliirCoeffs,
    &Model_Target_Near_p0_b0.Fr_PooliirPooliirNumStages,
    &Model_Target_Near_p0_b0.Fr_PooliirpooliirCoeffs,
    &Model_Target_Near_p0_b0.Fr_RouterOutMap,
    &Model_Target_Near_p0_b0.Fr_eqdelays,
    &Model_Target_Near_p0_b0.Fr_mix,
    &Model_Target_Near_p0_b0.LevelDetectPreEmphasisShelfFilterPooliirNumStages,
    &Model_Target_Near_p0_b0.LevelDetectPreEmphasisShelfFilterpooliirCoeffs,
    &Model_Target_Near_p0_b0.LevelDetectSysMaxDbspl,
    &Model_Target_Near_p0_b0.NumStages,
    &Model_Target_Near_p0_b0.RampDbPerSample,
};

uint32_t TopGroup1Partition0Size[] =   /* '<S5>/Partition' */
{
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1MuteRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcBoostOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcBoostOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcDen),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMaxBoost),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMaxSpl),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcMinVncSignal),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNoiseOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNoiseOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcNum),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncEnableTuneVar),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncSlope),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntGainCalcVncThresh),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntVncAppliedNum),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1NonEntVncAppliedden),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1VolumeRampRate),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1VolumeRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1VolumeTable_Idx),
    sizeof(Model_Target_Near_p0_b0.Ann1Ann1VolumeTable_dB),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetectHoldTimeSamples),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetectMaxVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetectMinVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann1LevelDetecthold_margin_db),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2MuteRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcBoostOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcBoostOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcDen),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMaxBoost),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMaxSpl),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcMinVncSignal),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNoiseOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNoiseOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcNum),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncEnableTuneVar),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncSlope),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntGainCalcVncThresh),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntVncAppliedNum),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2NonEntVncAppliedden),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2VolumeRampRate),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2VolumeRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2VolumeTable_Idx),
    sizeof(Model_Target_Near_p0_b0.Ann2Ann2VolumeTable_dB),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectHoldMarginDb),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectHoldTimeSamples),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectMaxVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectMinVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann2LevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3MuteRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcBoostOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcBoostOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcDen),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMaxBoost),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMaxSpl),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcMinVncSignal),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNoiseOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNoiseOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcNum),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncEnableTuneVar),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncSlope),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntGainCalcVncThresh),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntVncAppliedNum),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3NonEntVncAppliedden),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3VolumeRampRate),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3VolumeRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3VolumeTable_Idx),
    sizeof(Model_Target_Near_p0_b0.Ann3Ann3VolumeTable_dB),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectHoldMarginDb),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectHoldTimeSamples),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectMaxVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectMinVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann3LevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4MuteRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcBoostOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcBoostOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcDen),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMaxBoost),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMaxSpl),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcMinVncSignal),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNoiseOverRide),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNoiseOverRideFlag),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcNum),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncEnableTuneVar),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncSlope),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntGainCalcVncThresh),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntVncAppliedNum),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4NonEntVncAppliedden),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4VolumeRampRate),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4VolumeRampTime),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4VolumeTable_Idx),
    sizeof(Model_Target_Near_p0_b0.Ann4Ann4VolumeTable_dB),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectFastDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectHoldMarginDb),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectHoldTimeSamples),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectMaxVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectMinVolumeDb),
    sizeof(Model_Target_Near_p0_b0.Ann4LevelDetectSlowDecayDbPerSample),
    sizeof(Model_Target_Near_p0_b0.Coefficients),
    sizeof(Model_Target_Near_p0_b0.Dr_EqDelays),
    sizeof(Model_Target_Near_p0_b0.Dr_PoolIirTunablePooliirNumStages),
    sizeof(Model_Target_Near_p0_b0.Dr_PoolIirTunablepooliirCoeffs),
    sizeof(Model_Target_Near_p0_b0.Dr_PooliirPooliirNumStages),
    sizeof(Model_Target_Near_p0_b0.Dr_PooliirpooliirCoeffs),
    sizeof(Model_Target_Near_p0_b0.Dr_RouterOutMap),
    sizeof(Model_Target_Near_p0_b0.Dr_eqdelays),
    sizeof(Model_Target_Near_p0_b0.Dr_mix),
    sizeof(Model_Target_Near_p0_b0.Fr_EqDelays),
    sizeof(Model_Target_Near_p0_b0.Fr_PoolIirTunablePooliirNumStages),
    sizeof(Model_Target_Near_p0_b0.Fr_PoolIirTunablepooliirCoeffs),
    sizeof(Model_Target_Near_p0_b0.Fr_PooliirPooliirNumStages),
    sizeof(Model_Target_Near_p0_b0.Fr_PooliirpooliirCoeffs),
    sizeof(Model_Target_Near_p0_b0.Fr_RouterOutMap),
    sizeof(Model_Target_Near_p0_b0.Fr_eqdelays),
    sizeof(Model_Target_Near_p0_b0.Fr_mix),
    sizeof
    (Model_Target_Near_p0_b0.LevelDetectPreEmphasisShelfFilterPooliirNumStages),
    sizeof
    (Model_Target_Near_p0_b0.LevelDetectPreEmphasisShelfFilterpooliirCoeffs),
    sizeof(Model_Target_Near_p0_b0.LevelDetectSysMaxDbspl),
    sizeof(Model_Target_Near_p0_b0.NumStages),
    sizeof(Model_Target_Near_p0_b0.RampDbPerSample),
};

void* TopGroup3Partition0[] =          /* '<S7>/Partition' */
{
    &Model_Target_PostProcess_p0_b0.Limiterattack,
    &Model_Target_PostProcess_p0_b0.Limiterattack_low,
    &Model_Target_PostProcess_p0_b0.Limiterdecay,
    &Model_Target_PostProcess_p0_b0.Limiterdecay_low,
    &Model_Target_PostProcess_p0_b0.Limiterk1,
    &Model_Target_PostProcess_p0_b0.Limiterk1_low,
    &Model_Target_PostProcess_p0_b0.LimitermaxAttack,
    &Model_Target_PostProcess_p0_b0.LimitermaxAttack_low,
    &Model_Target_PostProcess_p0_b0.MuteRampTime,
    &Model_Target_PostProcess_p0_b0.PostLimiterEqPooliirNumStages,
    &Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs,
    &Model_Target_PostProcess_p0_b0.SoftClipperp2,
    &Model_Target_PostProcess_p0_b0.SoftClipperp2_low,
    &Model_Target_PostProcess_p0_b0.SoftClipperxmax,
    &Model_Target_PostProcess_p0_b0.SoftClipperxmax_low,
    &Model_Target_PostProcess_p0_b0.SoftClipperxmin,
    &Model_Target_PostProcess_p0_b0.SoftClipperxmin_low,
};

uint32_t TopGroup3Partition0Size[] =   /* '<S7>/Partition' */
{
    sizeof(Model_Target_PostProcess_p0_b0.Limiterattack),
    sizeof(Model_Target_PostProcess_p0_b0.Limiterattack_low),
    sizeof(Model_Target_PostProcess_p0_b0.Limiterdecay),
    sizeof(Model_Target_PostProcess_p0_b0.Limiterdecay_low),
    sizeof(Model_Target_PostProcess_p0_b0.Limiterk1),
    sizeof(Model_Target_PostProcess_p0_b0.Limiterk1_low),
    sizeof(Model_Target_PostProcess_p0_b0.LimitermaxAttack),
    sizeof(Model_Target_PostProcess_p0_b0.LimitermaxAttack_low),
    sizeof(Model_Target_PostProcess_p0_b0.MuteRampTime),
    sizeof(Model_Target_PostProcess_p0_b0.PostLimiterEqPooliirNumStages),
    sizeof(Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperp2),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperp2_low),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperxmax),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperxmax_low),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperxmin),
    sizeof(Model_Target_PostProcess_p0_b0.SoftClipperxmin_low),
};

void* TopGroup5Partition0[] =          /* '<S9>/Partition' */
{
    &Model_Target_TestRouter_p0_b0.ASDRouterEnableAux,
    &Model_Target_TestRouter_p0_b0.ASDRouterMainSelect,
    &Model_Target_TestRouter_p0_b0.AuxSelect,
};

uint32_t TopGroup5Partition0Size[] =   /* '<S9>/Partition' */
{
    sizeof(Model_Target_TestRouter_p0_b0.ASDRouterEnableAux),
    sizeof(Model_Target_TestRouter_p0_b0.ASDRouterMainSelect),
    sizeof(Model_Target_TestRouter_p0_b0.AuxSelect),
};

// -----------------------------------------------------------------
static void* ValidateArgsForTOP(const uint32_t token, const uint32_t offset,
    const
    uint32_t byteCount, int* retVal)
{
    void *addressOut = 0;
    *retVal = ASDSTATUS_OK;

    // Break apart the TOP token to get the pieces of interest
    uint32_t groupIdx = ASDID_GROUP(token);
    uint32_t partitionIdx = ASDID_PARTITION(token);
    uint32_t topIdx = TOPID_INDEX(token);

    // Use these pieces to access the partition root for this partition
    void** pointerArray = 0;
    uint32_t* sizeArray = 0;
    uint32_t count = 0;
    PartitionRoot_type* partitionRoot = GetPartitionRoot(groupIdx,partitionIdx);
    if (partitionRoot && partitionRoot->topTable && partitionRoot->topSize)
    {
        pointerArray = partitionRoot->topTable;
        sizeArray = partitionRoot->topSize;
        count = partitionRoot->topCount;
    }
    else
    {
        // This partition does not have TOPs*retVal = ASDSTATUS_TOP_BAD_PARTITION_ID;
    }

    // Try to acquire the TOP pointer from the partition root
    if (pointerArray && sizeArray)
    {
        // validate TOP index within partition is good
        if (topIdx >= count)
        {
            *retVal = ASDSTATUS_TOP_BAD_INDEX;
        }
        else
        {
            // validate overlay data range is good
            uint32_t topSize = sizeArray[topIdx];
            uint32_t endOffset = offset + byteCount;
            if (endOffset > topSize)
            {
                *retVal = ASDSTATUS_TOP_OUT_OF_RANGE;
            }
            else
            {
                // input arguments have passed validation
                uint8_t* bytebuffer = pointerArray[topIdx];
                addressOut = &bytebuffer[offset];
            }
        }
    }

    return addressOut;
}

// -----------------------------------------------------------------
static int SetTOP(const uint32_t token, const uint32_t offset, const uint32_t
                  byteCount,
                  const void* data)
{
    int errCode;
    void* theAddress = ValidateArgsForTOP(token, offset, byteCount, &errCode);
    if (theAddress && errCode == 0)
    {
        // Set the TOP data range
        memcpy(theAddress, data, byteCount);
    }

    return errCode;
}

// -----------------------------------------------------------------
static int GetTOP(const uint32_t token, const uint32_t offset, const uint32_t
                  byteCount,
                  void* data)
{
    int errCode;
    void* theAddress;
    theAddress = ValidateArgsForTOP(token, offset, byteCount, &errCode);
    if (theAddress && errCode == 0)
    {
        // Retrieve data from the TOP data range
        memcpy(data, theAddress, byteCount);
    }

    return errCode;
}

// -----------------------------------------------------------------
/** Handle request to read or write Target Overlay Parameter (TOP).
 *  @param pReqBuf Request buffer containing @ref TOP_WriteRequest_type
 *  @param reqBufSize number of bytes used in the request buffer, which can
 *         be described by the structure appropriate to the request:
 *         either @ref TOP_WriteResponse_type or @ref TOP_ReadResponse_type.
 *  @param pRspBuf Response buffer to receive response of either TOP_ReadResponse_type
 *         or TOP_WriteResponse_type, depending on the type of request
 *  @param rspBufSize Size of available bytes provided for the response to fill
 *  @return Returns the number of bytes utilized in the response buffer, or
 *          ASDSTATUS_RSP_BUFFER_SMALL if the response buffer is too small to
 *          contain a AsdIdStatus_type payload (which could in turn hold
 *          an error).
 **/
int Model_Target_HandleTopRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize)
{
    // returns number of bytes
    int retVal = 0;
    int status = ASDSTATUS_OK;
    uint32_t reqRequiredBytes;
    uint32_t rspRequiredBytes;

    // parse out the message id and caller handle
    if (reqBufSize < (sizeof(uint32_T)*2) ||
        pReqBuf == 0)
    {
        return ASDSTATUS_REQ_BUFFER_SMALL;
    }

    uint32_t msgId = ((uint32_T*)pReqBuf)[0];
    uint32_t callerHandle = ((uint32_T*)pReqBuf)[1];
    if (TOPID_IS_WRITE(msgId))
    {
        // WRITE data from request buffer into memory. Respond with just the topId
        TOP_WriteRequest_type* topREQ = (TOP_WriteRequest_type*)pReqBuf;
        TOP_WriteResponse_type* topRSP = (TOP_WriteResponse_type*)pRspBuf;
        reqRequiredBytes = sizeof(TOP_WriteRequest_type) + topREQ->byteCount;
        rspRequiredBytes = sizeof(TOP_WriteResponse_type);
        uint8_t reqBufOK = (reqBufSize >= reqRequiredBytes) && pReqBuf;
        uint8_t rspBufOK = (rspBufSize >= rspRequiredBytes) && pRspBuf;
        if (reqBufOK && rspBufOK)
        {
            // Write the data into memory
            status = SetTOP(topREQ->topId, topREQ->offset, topREQ->byteCount,
                            topREQ->data);

            // Prepare response payload
            topRSP->topId = msgId;
            topRSP->callerHandle = callerHandle;
            topRSP->statusCode = status;
            retVal = (int)rspRequiredBytes;
        }
        else
        {
            // one of the buffers was too small
            status = reqBufOK ? ASDSTATUS_RSP_BUFFER_SMALL :
                ASDSTATUS_REQ_BUFFER_SMALL;
        }
    }
    else                               // (checking read vs. write)
    {
        // READ data from memory into the response buffer
        TOP_ReadRequest_type* topREQ = (TOP_ReadRequest_type*)pReqBuf;
        TOP_ReadResponse_type* topRSP = (TOP_ReadResponse_type*)pRspBuf;
        reqRequiredBytes = sizeof(TOP_ReadRequest_type);
        rspRequiredBytes = sizeof(TOP_ReadResponse_type) + topREQ->byteCount;
        uint8_t reqBufOK = (reqBufSize >= reqRequiredBytes) && pReqBuf;
        uint8_t rspBufOK = (rspBufSize >= rspRequiredBytes) && pRspBuf;
        if (reqBufOK && rspBufOK)
        {
            // Save the byte count
            uint32_t byteCount = topREQ->byteCount;

            // Copy the data from memory into the response buffer
            status = GetTOP(
                            topREQ->topId, topREQ->offset, topREQ->byteCount, // from REQ
                            topRSP->data);// to RSP

            // Prepare the rest of the response payload
            topRSP->topId = msgId;
            topRSP->callerHandle = callerHandle;
            topRSP->statusCode = status;
            topRSP->byteCount = byteCount;
            retVal = (int)rspRequiredBytes;
        }
        else
        {
            // one of the buffers was too small
            status = reqBufOK ? ASDSTATUS_RSP_BUFFER_SMALL :
                ASDSTATUS_REQ_BUFFER_SMALL;
        }
    }

    // If a problem has arisen, the response is only a status payload
    if (status < 0)
    {
        rspRequiredBytes = sizeof(AsdIdStatus_type);
        if ((rspBufSize >= rspRequiredBytes) && pRspBuf)
        {
            // Fill in the response with information from the request
            AsdIdStatus_type* topRSP = (AsdIdStatus_type*)pReqBuf;
            topRSP->msgId = msgId;
            topRSP->callerHandle = callerHandle;
            topRSP->statusCode = status;
            retVal = (int)rspRequiredBytes;
        }
        else
        {
            // otherwise, we cannot return a response buffer!
            retVal = ASDSTATUS_RSP_BUFFER_SMALL;
        }
    }

    return retVal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
