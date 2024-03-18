/*
 * File: Model_Target_TSP_IDs.h
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

#ifndef RTW_HEADER_Model_Target_TSP_IDs_h_
#define RTW_HEADER_Model_Target_TSP_IDs_h_
#include <stdint.h>

// ------------------------------------------------------------
// TSP COMMAND INFO CODES FOUND INSIDE TOKENS
// ------------------------------------------------------------
#define TSP_COMMAND_LIST_ADD           (8U)
#define TSP_COMMAND_LIST_SUB           (9U)
#define TSP_COMMAND_LIST_CLEAR         (12U)
#define TSP_COMMAND_CAPTURE            (13U)
#define TSP_COMMAND_RETRIEVE           (10U)
#define TSP_COMMAND_BLIND_READ         (11U)

// ------------------------------------------------------------
// TSP ACCESS TOKENS
// ------------------------------------------------------------
#define Model_Target_TSPID_CAPTURE     (0x200d0000U)
#define Model_Target_TSPID_CLEAR       (0x200c0000U)
#define TSP_ADD_PreAmpAudiopilotVehicleSpeed (0x24280025U)
#define TSP_SUB_PreAmpAudiopilotVehicleSpeed (0x24290025U)
#define TSP_RETRIEVE_PreAmpAudiopilotVehicleSpeed (0x242a0025U)
#define TSP_BLIND_READ_PreAmpAudiopilotVehicleSpeed (0x242b0025U)
#define TSP_ADD_PreAmpAudiopilotHvacDbspl (0x2428000dU)
#define TSP_SUB_PreAmpAudiopilotHvacDbspl (0x2429000dU)
#define TSP_RETRIEVE_PreAmpAudiopilotHvacDbspl (0x242a000dU)
#define TSP_BLIND_READ_PreAmpAudiopilotHvacDbspl (0x242b000dU)
#define TSP_ADD_PreAmpAudiopilotLfNoiseDbspl (0x2428000fU)
#define TSP_SUB_PreAmpAudiopilotLfNoiseDbspl (0x2429000fU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseDbspl (0x242a000fU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseDbspl (0x242b000fU)
#define TSP_ADD_PreAmpAudiopilotWbNoiseDbspl (0x24280026U)
#define TSP_SUB_PreAmpAudiopilotWbNoiseDbspl (0x24290026U)
#define TSP_RETRIEVE_PreAmpAudiopilotWbNoiseDbspl (0x242a0026U)
#define TSP_BLIND_READ_PreAmpAudiopilotWbNoiseDbspl (0x242b0026U)
#define TSP_ADD_PreAmpAudiopilotHfNoiseDbspl (0x24280006U)
#define TSP_SUB_PreAmpAudiopilotHfNoiseDbspl (0x24290006U)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoiseDbspl (0x242a0006U)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoiseDbspl (0x242b0006U)
#define TSP_ADD_PreAmpAudiopilotNoiseRatio (0x24280020U)
#define TSP_SUB_PreAmpAudiopilotNoiseRatio (0x24290020U)
#define TSP_RETRIEVE_PreAmpAudiopilotNoiseRatio (0x242a0020U)
#define TSP_BLIND_READ_PreAmpAudiopilotNoiseRatio (0x242b0020U)
#define TSP_ADD_PreAmpAudiopilotTotalBassBoostDb (0x24280024U)
#define TSP_SUB_PreAmpAudiopilotTotalBassBoostDb (0x24290024U)
#define TSP_RETRIEVE_PreAmpAudiopilotTotalBassBoostDb (0x242a0024U)
#define TSP_BLIND_READ_PreAmpAudiopilotTotalBassBoostDb (0x242b0024U)
#define TSP_ADD_PreAmpAudiopilotAudiopilotMidrangeBoostDb (0x24280002U)
#define TSP_SUB_PreAmpAudiopilotAudiopilotMidrangeBoostDb (0x24290002U)
#define TSP_RETRIEVE_PreAmpAudiopilotAudiopilotMidrangeBoostDb (0x242a0002U)
#define TSP_BLIND_READ_PreAmpAudiopilotAudiopilotMidrangeBoostDb (0x242b0002U)
#define TSP_ADD_PreAmpAudiopilotAudiopilotTrebleBoostDb (0x24280003U)
#define TSP_SUB_PreAmpAudiopilotAudiopilotTrebleBoostDb (0x24290003U)
#define TSP_RETRIEVE_PreAmpAudiopilotAudiopilotTrebleBoostDb (0x242a0003U)
#define TSP_BLIND_READ_PreAmpAudiopilotAudiopilotTrebleBoostDb (0x242b0003U)
#define TSP_ADD_PreAmpAudiopilotDyneqBassBoostDb (0x24280004U)
#define TSP_SUB_PreAmpAudiopilotDyneqBassBoostDb (0x24290004U)
#define TSP_RETRIEVE_PreAmpAudiopilotDyneqBassBoostDb (0x242a0004U)
#define TSP_BLIND_READ_PreAmpAudiopilotDyneqBassBoostDb (0x242b0004U)
#define TSP_ADD_PreAmpAudiopilotAudiopilotBassBoostDb (0x24280000U)
#define TSP_SUB_PreAmpAudiopilotAudiopilotBassBoostDb (0x24290000U)
#define TSP_RETRIEVE_PreAmpAudiopilotAudiopilotBassBoostDb (0x242a0000U)
#define TSP_BLIND_READ_PreAmpAudiopilotAudiopilotBassBoostDb (0x242b0000U)
#define TSP_ADD_PreAmpAudiopilotIgnoreMicFlag (0x2428000eU)
#define TSP_SUB_PreAmpAudiopilotIgnoreMicFlag (0x2429000eU)
#define TSP_RETRIEVE_PreAmpAudiopilotIgnoreMicFlag (0x242a000eU)
#define TSP_BLIND_READ_PreAmpAudiopilotIgnoreMicFlag (0x242b000eU)
#define TSP_ADD_PreAmpAudiopilotAudiopilotBoostGain (0x24280001U)
#define TSP_SUB_PreAmpAudiopilotAudiopilotBoostGain (0x24290001U)
#define TSP_RETRIEVE_PreAmpAudiopilotAudiopilotBoostGain (0x242a0001U)
#define TSP_BLIND_READ_PreAmpAudiopilotAudiopilotBoostGain (0x242b0001U)
#define TSP_ADD_PreAmpAudiopilotDyneqBoostGain (0x24280005U)
#define TSP_SUB_PreAmpAudiopilotDyneqBoostGain (0x24290005U)
#define TSP_RETRIEVE_PreAmpAudiopilotDyneqBoostGain (0x242a0005U)
#define TSP_BLIND_READ_PreAmpAudiopilotDyneqBoostGain (0x242b0005U)
#define TSP_ADD_PreAmpLevelWatchAudiopilotEnvDb (0x24280027U)
#define TSP_SUB_PreAmpLevelWatchAudiopilotEnvDb (0x24290027U)
#define TSP_RETRIEVE_PreAmpLevelWatchAudiopilotEnvDb (0x242a0027U)
#define TSP_BLIND_READ_PreAmpLevelWatchAudiopilotEnvDb (0x242b0027U)
#define TSP_ADD_PreAmpLevelWatchAudiopilotLevelDbspl (0x24280028U)
#define TSP_SUB_PreAmpLevelWatchAudiopilotLevelDbspl (0x24290028U)
#define TSP_RETRIEVE_PreAmpLevelWatchAudiopilotLevelDbspl (0x242a0028U)
#define TSP_BLIND_READ_PreAmpLevelWatchAudiopilotLevelDbspl (0x242b0028U)
#define TSP_ADD_PreAmpLevelWatchDyneqEnvDb (0x24280029U)
#define TSP_SUB_PreAmpLevelWatchDyneqEnvDb (0x24290029U)
#define TSP_RETRIEVE_PreAmpLevelWatchDyneqEnvDb (0x242a0029U)
#define TSP_BLIND_READ_PreAmpLevelWatchDyneqEnvDb (0x242b0029U)
#define TSP_ADD_PreAmpLevelWatchDyneqLevelDbspl (0x2428002aU)
#define TSP_SUB_PreAmpLevelWatchDyneqLevelDbspl (0x2429002aU)
#define TSP_RETRIEVE_PreAmpLevelWatchDyneqLevelDbspl (0x242a002aU)
#define TSP_BLIND_READ_PreAmpLevelWatchDyneqLevelDbspl (0x242b002aU)
#define TSP_ADD_PreAmpAudiopilotHfNoiseMicPsdLevel (0x24280009U)
#define TSP_SUB_PreAmpAudiopilotHfNoiseMicPsdLevel (0x24290009U)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoiseMicPsdLevel (0x242a0009U)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoiseMicPsdLevel (0x242b0009U)
#define TSP_ADD_PreAmpAudiopilotHfNoisePowerSpectralDensity (0x2428000bU)
#define TSP_SUB_PreAmpAudiopilotHfNoisePowerSpectralDensity (0x2429000bU)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoisePowerSpectralDensity (0x242a000bU)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoisePowerSpectralDensity (0x242b000bU)
#define TSP_ADD_PreAmpAudiopilotHfNoisePostSlew (0x2428000aU)
#define TSP_SUB_PreAmpAudiopilotHfNoisePostSlew (0x2429000aU)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoisePostSlew (0x242a000aU)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoisePostSlew (0x242b000aU)
#define TSP_ADD_PreAmpAudiopilotHfNoisePreSlew (0x2428000cU)
#define TSP_SUB_PreAmpAudiopilotHfNoisePreSlew (0x2429000cU)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoisePreSlew (0x242a000cU)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoisePreSlew (0x242b000cU)
#define TSP_ADD_PreAmpAudiopilotHfNoiseImpulseRejectionPmin (0x24280008U)
#define TSP_SUB_PreAmpAudiopilotHfNoiseImpulseRejectionPmin (0x24290008U)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoiseImpulseRejectionPmin (0x242a0008U)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoiseImpulseRejectionPmin (0x242b0008U)
#define TSP_ADD_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness (0x24280007U)
#define TSP_SUB_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness (0x24290007U)
#define TSP_RETRIEVE_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness (0x242a0007U)
#define TSP_BLIND_READ_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness (0x242b0007U)
#define TSP_ADD_PreAmpAudiopilotRatioPostSlew (0x24280021U)
#define TSP_SUB_PreAmpAudiopilotRatioPostSlew (0x24290021U)
#define TSP_RETRIEVE_PreAmpAudiopilotRatioPostSlew (0x242a0021U)
#define TSP_BLIND_READ_PreAmpAudiopilotRatioPostSlew (0x242b0021U)
#define TSP_ADD_PreAmpAudiopilotRatioPreSlew (0x24280022U)
#define TSP_SUB_PreAmpAudiopilotRatioPreSlew (0x24290022U)
#define TSP_RETRIEVE_PreAmpAudiopilotRatioPreSlew (0x242a0022U)
#define TSP_BLIND_READ_PreAmpAudiopilotRatioPreSlew (0x242b0022U)
#define TSP_ADD_PreAmpAudiopilotRatioUpdateFlag (0x24280023U)
#define TSP_SUB_PreAmpAudiopilotRatioUpdateFlag (0x24290023U)
#define TSP_RETRIEVE_PreAmpAudiopilotRatioUpdateFlag (0x242a0023U)
#define TSP_BLIND_READ_PreAmpAudiopilotRatioUpdateFlag (0x242b0023U)
#define TSP_ADD_PreAmpAudiopilotLfNoisePostSlew (0x2428001aU)
#define TSP_SUB_PreAmpAudiopilotLfNoisePostSlew (0x2429001aU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoisePostSlew (0x242a001aU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoisePostSlew (0x242b001aU)
#define TSP_ADD_PreAmpAudiopilotLfNoisePreSlew (0x2428001bU)
#define TSP_SUB_PreAmpAudiopilotLfNoisePreSlew (0x2429001bU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoisePreSlew (0x242a001bU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoisePreSlew (0x242b001bU)
#define TSP_ADD_PreAmpAudiopilotLfNoisePreSpeedBound (0x2428001cU)
#define TSP_SUB_PreAmpAudiopilotLfNoisePreSpeedBound (0x2429001cU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoisePreSpeedBound (0x242a001cU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoisePreSpeedBound (0x242b001cU)
#define TSP_ADD_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax (0x2428001dU)
#define TSP_SUB_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax (0x2429001dU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax (0x242a001dU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax (0x242b001dU)
#define TSP_ADD_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin (0x2428001eU)
#define TSP_SUB_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin (0x2429001eU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin (0x242a001eU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin (0x242b001eU)
#define TSP_ADD_PreAmpAudiopilotLfNoiseSpeedBoundsFlag (0x2428001fU)
#define TSP_SUB_PreAmpAudiopilotLfNoiseSpeedBoundsFlag (0x2429001fU)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseSpeedBoundsFlag (0x242a001fU)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseSpeedBoundsFlag (0x242b001fU)
#define TSP_ADD_PreAmpAudiopilotLfNoiseMicLevel (0x24280016U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseMicLevel (0x24290016U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseMicLevel (0x242a0016U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseMicLevel (0x242b0016U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseMicOut (0x24280017U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseMicOut (0x24290017U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseMicOut (0x242a0017U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseMicOut (0x242b0017U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseMusicOut (0x24280018U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseMusicOut (0x24290018U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseMusicOut (0x242a0018U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseMusicOut (0x242b0018U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseNoiseOut (0x24280019U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseNoiseOut (0x24290019U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseNoiseOut (0x242a0019U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseNoiseOut (0x242b0019U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut (0x24280011U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut (0x24290011U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut (0x242a0011U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut (0x242b0011U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef (0x24280010U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef (0x24290010U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef (0x242a0010U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef (0x242b0010U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance (0x24280012U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance (0x24290012U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance (0x242a0012U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance (0x242b0012U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance (0x24280013U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance (0x24290013U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance (0x242a0013U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance (0x242b0013U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance (0x24280014U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance (0x24290014U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance (0x242a0014U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance (0x242b0014U)
#define TSP_ADD_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance (0x24280015U)
#define TSP_SUB_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance (0x24290015U)
#define TSP_RETRIEVE_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance (0x242a0015U)
#define TSP_BLIND_READ_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance (0x242b0015U)
#define TSP_ADD_PreAmpMedusaDummyState (0x22280000U)
#define TSP_SUB_PreAmpMedusaDummyState (0x22290000U)
#define TSP_RETRIEVE_PreAmpMedusaDummyState (0x222a0000U)
#define TSP_BLIND_READ_PreAmpMedusaDummyState (0x222b0000U)
#define TSP_ADD_PreAmpMedusaMonoDetectorLevelCenter (0x23280002U)
#define TSP_SUB_PreAmpMedusaMonoDetectorLevelCenter (0x23290002U)
#define TSP_RETRIEVE_PreAmpMedusaMonoDetectorLevelCenter (0x232a0002U)
#define TSP_BLIND_READ_PreAmpMedusaMonoDetectorLevelCenter (0x232b0002U)
#define TSP_ADD_PreAmpMedusaMonoDetectorIsStereo (0x23280001U)
#define TSP_SUB_PreAmpMedusaMonoDetectorIsStereo (0x23290001U)
#define TSP_RETRIEVE_PreAmpMedusaMonoDetectorIsStereo (0x232a0001U)
#define TSP_BLIND_READ_PreAmpMedusaMonoDetectorIsStereo (0x232b0001U)
#define TSP_ADD_PreAmpMedusaMonoDetectorIsActive (0x23280000U)
#define TSP_SUB_PreAmpMedusaMonoDetectorIsActive (0x23290000U)
#define TSP_RETRIEVE_PreAmpMedusaMonoDetectorIsActive (0x232a0000U)
#define TSP_BLIND_READ_PreAmpMedusaMonoDetectorIsActive (0x232b0000U)
#define TSP_ADD_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB (0x20180000U)
#define TSP_SUB_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB (0x20190000U)
#define TSP_RETRIEVE_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB (0x201a0000U)
#define TSP_BLIND_READ_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB (0x201b0000U)
#define TSP_ADD_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB (0x20180001U)
#define TSP_SUB_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB (0x20190001U)
#define TSP_RETRIEVE_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB (0x201a0001U)
#define TSP_BLIND_READ_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB (0x201b0001U)
#define TSP_ADD_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB (0x20180002U)
#define TSP_SUB_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB (0x20190002U)
#define TSP_RETRIEVE_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB (0x201a0002U)
#define TSP_BLIND_READ_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB (0x201b0002U)
#define TSP_ADD_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB (0x20180003U)
#define TSP_SUB_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB (0x20190003U)
#define TSP_RETRIEVE_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB (0x201a0003U)
#define TSP_BLIND_READ_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB (0x201b0003U)
#define TSP_ADD_PostProcessEnergyLimiterComputedEnergy (0x20380000U)
#define TSP_SUB_PostProcessEnergyLimiterComputedEnergy (0x20390000U)
#define TSP_RETRIEVE_PostProcessEnergyLimiterComputedEnergy (0x203a0000U)
#define TSP_BLIND_READ_PostProcessEnergyLimiterComputedEnergy (0x203b0000U)
#define TSP_ADD_PostProcessEnergyLimiterCurGain (0x20380001U)
#define TSP_SUB_PostProcessEnergyLimiterCurGain (0x20390001U)
#define TSP_RETRIEVE_PostProcessEnergyLimiterCurGain (0x203a0001U)
#define TSP_BLIND_READ_PostProcessEnergyLimiterCurGain (0x203b0001U)
#define TSP_ADD_PostProcessEnergyLimiterEnergyThreshold (0x20380004U)
#define TSP_SUB_PostProcessEnergyLimiterEnergyThreshold (0x20390004U)
#define TSP_RETRIEVE_PostProcessEnergyLimiterEnergyThreshold (0x203a0004U)
#define TSP_BLIND_READ_PostProcessEnergyLimiterEnergyThreshold (0x203b0004U)
#define TSP_ADD_PostProcessEnergyLimiterCurState (0x20380002U)
#define TSP_SUB_PostProcessEnergyLimiterCurState (0x20390002U)
#define TSP_RETRIEVE_PostProcessEnergyLimiterCurState (0x203a0002U)
#define TSP_BLIND_READ_PostProcessEnergyLimiterCurState (0x203b0002U)
#define TSP_ADD_PostProcessEnergyLimiterEnableFlag (0x20380003U)
#define TSP_SUB_PostProcessEnergyLimiterEnableFlag (0x20390003U)
#define TSP_RETRIEVE_PostProcessEnergyLimiterEnableFlag (0x203a0003U)
#define TSP_BLIND_READ_PostProcessEnergyLimiterEnableFlag (0x203b0003U)

// ------------------------------------------------------------
// TSP REQUEST PAYLOADS
// ------------------------------------------------------------
typedef struct TspListAddReqTag
{
    uint32_t msgId;                    // add token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    uint32_t captureCount;             // startChar:4 charSize:4
    uint32_t skipInterval;             // startChar:8 charSize:4
}

TspListAddReqType;

typedef struct TspListSubReqTag
{
    uint32_t msgId;                    // sub token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
}
TspListSubReqType;

typedef struct TspListClearReqTag
{
    uint32_t msgId;                    // TSPID_CLEAR - send to desired core
    uint32_t callerHandle;             // startChar:0 charSize:4
}
TspListClearReqType;

typedef struct TspCaptureReqTag
{
    uint32_t msgId;                    // TSPID_CAPTURE
    uint32_t callerHandle;             // startChar:0 charSize:4
}
TspCaptureReqType;

typedef struct TspRetrieveReqTag
{
    uint32_t msgId;                    // retrieve token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    uint32_t captureIndex;             // startChar:4 charSize:4
    uint32_t charOffset;               // startChar:8 charSize:4
    uint32_t charCount;                // startChar:12 charSize:4
}
TspRetrieveReqType;

typedef struct TspBlindReadReqTag
{
    uint32_t msgId;                    // blind read token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    uint32_t charOffset;               // startChar:8 charSize:4
    uint32_t charCount;                // startChar:12 charSize:4
}
TspBlindReadReqType;

// ------------------------------------------------------------
// TSP RESPONSE PAYLOADS
// ------------------------------------------------------------
typedef struct TspListAddRspTag
{
    uint32_t msgId;                    // list add token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
}
TspListAddRspType;

typedef struct TspListSubRspTag
{
    uint32_t msgId;                    // list sub token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
}
TspListSubRspType;

typedef struct TspListClearRspTag
{
    uint32_t msgId;                    // TSPID_CLEAR
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
}
TspListClearRspType;

typedef struct TspCaptureRspTag
{
    uint32_t msgId;                    // TSPID_CAPTURE
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
}
TspCaptureRspType;

typedef struct TspRetrieveRspTag
{
    uint32_t msgId;                    // retrieve token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
    uint32_t charCount;                // startChar:8 charSize:4
    int8_t data[];
}
TspRetrieveRspType;

typedef struct TspBlindReadRspTag
{
    uint32_t msgId;                    // blind read token for TSP
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;                // startChar:4 charSize:4
    uint32_t charCount;                // startChar:8 charSize:4
    int8_t data[];
}
TspBlindReadRspType;

// ------------------------------------------------------------
// TSP NOTIFICATION PAYLOADS
// ------------------------------------------------------------
typedef struct TspCaptureNtfTag
{
    uint32_t msgId;                    // TSPID_CAPTURE
    uint32_t callerHandle;             // startChar:0 charSize:4
    int32_t statusCode;     // startChar:4 charSize:4 ASDSTATUS_RTC_NOTIFICATION
    uint32_t totalCaptureCount;        // startChar:8 charSize:4
}
TspCaptureNtfType;

// ------------------------------------------------------------
// EMBEDDED XML FILE OF TSP TOKEN VALUES
// ------------------------------------------------------------
/* [XMLBEGIN]<?xml version="1.0" encoding="utf-8"?>
   <root version="1.0">
   <Core coreIndex="1" captureToken="0x200d0000" clearToken="0x200c0000"/>
   <TSP id="PreAmpAudiopilotVehicleSpeed" addToken="0x24280025" subToken="0x24290025" retrieveToken="0x242a0025" blindReadToken="0x242b0025" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHvacDbspl" addToken="0x2428000d" subToken="0x2429000d" retrieveToken="0x242a000d" blindReadToken="0x242b000d" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseDbspl" addToken="0x2428000f" subToken="0x2429000f" retrieveToken="0x242a000f" blindReadToken="0x242b000f" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotWbNoiseDbspl" addToken="0x24280026" subToken="0x24290026" retrieveToken="0x242a0026" blindReadToken="0x242b0026" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoiseDbspl" addToken="0x24280006" subToken="0x24290006" retrieveToken="0x242a0006" blindReadToken="0x242b0006" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotNoiseRatio" addToken="0x24280020" subToken="0x24290020" retrieveToken="0x242a0020" blindReadToken="0x242b0020" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotTotalBassBoostDb" addToken="0x24280024" subToken="0x24290024" retrieveToken="0x242a0024" blindReadToken="0x242b0024" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotAudiopilotMidrangeBoostDb" addToken="0x24280002" subToken="0x24290002" retrieveToken="0x242a0002" blindReadToken="0x242b0002" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotAudiopilotTrebleBoostDb" addToken="0x24280003" subToken="0x24290003" retrieveToken="0x242a0003" blindReadToken="0x242b0003" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotDyneqBassBoostDb" addToken="0x24280004" subToken="0x24290004" retrieveToken="0x242a0004" blindReadToken="0x242b0004" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotAudiopilotBassBoostDb" addToken="0x24280000" subToken="0x24290000" retrieveToken="0x242a0000" blindReadToken="0x242b0000" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotIgnoreMicFlag" addToken="0x2428000e" subToken="0x2429000e" retrieveToken="0x242a000e" blindReadToken="0x242b000e" dataType="boolean" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotAudiopilotBoostGain" addToken="0x24280001" subToken="0x24290001" retrieveToken="0x242a0001" blindReadToken="0x242b0001" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotDyneqBoostGain" addToken="0x24280005" subToken="0x24290005" retrieveToken="0x242a0005" blindReadToken="0x242b0005" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpLevelWatchAudiopilotEnvDb" addToken="0x24280027" subToken="0x24290027" retrieveToken="0x242a0027" blindReadToken="0x242b0027" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpLevelWatchAudiopilotLevelDbspl" addToken="0x24280028" subToken="0x24290028" retrieveToken="0x242a0028" blindReadToken="0x242b0028" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpLevelWatchDyneqEnvDb" addToken="0x24280029" subToken="0x24290029" retrieveToken="0x242a0029" blindReadToken="0x242b0029" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpLevelWatchDyneqLevelDbspl" addToken="0x2428002a" subToken="0x2429002a" retrieveToken="0x242a002a" blindReadToken="0x242b002a" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoiseMicPsdLevel" addToken="0x24280009" subToken="0x24290009" retrieveToken="0x242a0009" blindReadToken="0x242b0009" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoisePowerSpectralDensity" addToken="0x2428000b" subToken="0x2429000b" retrieveToken="0x242a000b" blindReadToken="0x242b000b" dataType="single" width="65" dimensions="[65, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoisePostSlew" addToken="0x2428000a" subToken="0x2429000a" retrieveToken="0x242a000a" blindReadToken="0x242b000a" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoisePreSlew" addToken="0x2428000c" subToken="0x2429000c" retrieveToken="0x242a000c" blindReadToken="0x242b000c" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoiseImpulseRejectionPmin" addToken="0x24280008" subToken="0x24290008" retrieveToken="0x242a0008" blindReadToken="0x242b0008" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotHfNoiseImpulseRejectionFlatness" addToken="0x24280007" subToken="0x24290007" retrieveToken="0x242a0007" blindReadToken="0x242b0007" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotRatioPostSlew" addToken="0x24280021" subToken="0x24290021" retrieveToken="0x242a0021" blindReadToken="0x242b0021" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotRatioPreSlew" addToken="0x24280022" subToken="0x24290022" retrieveToken="0x242a0022" blindReadToken="0x242b0022" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotRatioUpdateFlag" addToken="0x24280023" subToken="0x24290023" retrieveToken="0x242a0023" blindReadToken="0x242b0023" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoisePostSlew" addToken="0x2428001a" subToken="0x2429001a" retrieveToken="0x242a001a" blindReadToken="0x242b001a" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoisePreSlew" addToken="0x2428001b" subToken="0x2429001b" retrieveToken="0x242a001b" blindReadToken="0x242b001b" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoisePreSpeedBound" addToken="0x2428001c" subToken="0x2429001c" retrieveToken="0x242a001c" blindReadToken="0x242b001c" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax" addToken="0x2428001d" subToken="0x2429001d" retrieveToken="0x242a001d" blindReadToken="0x242b001d" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin" addToken="0x2428001e" subToken="0x2429001e" retrieveToken="0x242a001e" blindReadToken="0x242b001e" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseSpeedBoundsFlag" addToken="0x2428001f" subToken="0x2429001f" retrieveToken="0x242a001f" blindReadToken="0x242b001f" dataType="double" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseMicLevel" addToken="0x24280016" subToken="0x24290016" retrieveToken="0x242a0016" blindReadToken="0x242b0016" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseMicOut" addToken="0x24280017" subToken="0x24290017" retrieveToken="0x242a0017" blindReadToken="0x242b0017" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseMusicOut" addToken="0x24280018" subToken="0x24290018" retrieveToken="0x242a0018" blindReadToken="0x242b0018" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseNoiseOut" addToken="0x24280019" subToken="0x24290019" retrieveToken="0x242a0019" blindReadToken="0x242b0019" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut" addToken="0x24280011" subToken="0x24290011" retrieveToken="0x242a0011" blindReadToken="0x242b0011" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef" addToken="0x24280010" subToken="0x24290010" retrieveToken="0x242a0010" blindReadToken="0x242b0010" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance" addToken="0x24280012" subToken="0x24290012" retrieveToken="0x242a0012" blindReadToken="0x242b0012" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance" addToken="0x24280013" subToken="0x24290013" retrieveToken="0x242a0013" blindReadToken="0x242b0013" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance" addToken="0x24280014" subToken="0x24290014" retrieveToken="0x242a0014" blindReadToken="0x242b0014" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance" addToken="0x24280015" subToken="0x24290015" retrieveToken="0x242a0015" blindReadToken="0x242b0015" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpMedusaDummyState" addToken="0x22280000" subToken="0x22290000" retrieveToken="0x222a0000" blindReadToken="0x222b0000" dataType="int32" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpMedusaMonoDetectorLevelCenter" addToken="0x23280002" subToken="0x23290002" retrieveToken="0x232a0002" blindReadToken="0x232b0002" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpMedusaMonoDetectorIsStereo" addToken="0x23280001" subToken="0x23290001" retrieveToken="0x232a0001" blindReadToken="0x232b0001" dataType="uint32" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PreAmpMedusaMonoDetectorIsActive" addToken="0x23280000" subToken="0x23290000" retrieveToken="0x232a0000" blindReadToken="0x232b0000" dataType="int32" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB" addToken="0x20180000" subToken="0x20190000" retrieveToken="0x201a0000" blindReadToken="0x201b0000" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB" addToken="0x20180001" subToken="0x20190001" retrieveToken="0x201a0001" blindReadToken="0x201b0001" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB" addToken="0x20180002" subToken="0x20190002" retrieveToken="0x201a0002" blindReadToken="0x201b0002" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB" addToken="0x20180003" subToken="0x20190003" retrieveToken="0x201a0003" blindReadToken="0x201b0003" dataType="single" width="1" dimensions="[1, 1]" coreIndex="0" coreTag=""/>
   <TSP id="PostProcessEnergyLimiterComputedEnergy" addToken="0x20380000" subToken="0x20390000" retrieveToken="0x203a0000" blindReadToken="0x203b0000" dataType="single" width="24" dimensions="[1, 24]" coreIndex="0" coreTag=""/>
   <TSP id="PostProcessEnergyLimiterCurGain" addToken="0x20380001" subToken="0x20390001" retrieveToken="0x203a0001" blindReadToken="0x203b0001" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PostProcessEnergyLimiterEnergyThreshold" addToken="0x20380004" subToken="0x20390004" retrieveToken="0x203a0004" blindReadToken="0x203b0004" dataType="single" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PostProcessEnergyLimiterCurState" addToken="0x20380002" subToken="0x20390002" retrieveToken="0x203a0002" blindReadToken="0x203b0002" dataType="int16" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   <TSP id="PostProcessEnergyLimiterEnableFlag" addToken="0x20380003" subToken="0x20390003" retrieveToken="0x203a0003" blindReadToken="0x203b0003" dataType="int16" width="1" dimensions="1" coreIndex="0" coreTag=""/>
   </root>
   [XMLEND] */
#endif                                 /* RTW_HEADER_Model_Target_TSP_IDs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
