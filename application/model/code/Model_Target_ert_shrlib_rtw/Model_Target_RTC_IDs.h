/*
 * File: Model_Target_RTC_IDs.h
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

#ifndef RTW_HEADER_Model_Target_RTC_IDs_h_
#define RTW_HEADER_Model_Target_RTC_IDs_h_
#include <stdint.h>
#include "ASDID.h"

// ------------------------------------------------------------
// CORE ENDIAN SETTINGS
// ------------------------------------------------------------
#define ENDIANNESS_CORE                LittleEndian

// ------------------------------------------------------------
// RTC MESSAGE IDS
// ------------------------------------------------------------
#define RTCID_InputSelectRouterCfgSet  (0x10010000U)             // REQ, RSP '<S15>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotmuteReference (0x14210004U)        // REQ, RSP '<S44>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetSpeedIn (0x1422000dU)           // REQ *only* '<S45>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetHVACSetting (0x14220009U)       // REQ *only* '<S48>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetDynEQBoostOverRide (0x14220006U) // REQ *only* '<S142>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetVNCTrebleBoostOverRide (0x14220011U) // REQ *only* '<S145>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetLoudSignalOverRide (0x1422000bU) // REQ *only* '<S171>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetVNCSignalOverRide (0x14220010U) // REQ *only* '<S173>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetLFNoiseOverRide (0x1422000aU)   // REQ *only* '<S193>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetWBNoiseOverRide (0x14220012U)   // REQ *only* '<S196>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetHFNoiseOverRide (0x14220008U)   // REQ *only* '<S192>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetRatioOverRide (0x1422000cU)     // REQ *only* '<S195>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetDyneqOn (0x14210007U)           // REQ, RSP '<S232>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetAudioPilotOn (0x14210005U)      // REQ, RSP '<S233>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetVNCBassBoostOverRide (0x1422000eU) // REQ *only* '<S143>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotgetBassBoost (0x14210001U)         // REQ, RSP '<S69>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotsetVNCMidBoostOverRide (0x1422000fU) // REQ *only* '<S144>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotgetMidBoost (0x14210002U)          // REQ, RSP '<S70>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotgetTrebleBoost (0x14210003U)       // REQ, RSP '<S71>/RTC Request Response Trigger'
#define RTCID_PreAmpAudiopilotgetAverageAudioPilotBoostLevel (0x14210000U) // REQ, RSP '<S107>/RTC Request Response Trigger'
#define RTCID_PreAmpVolumeCfgSet       (0x14200013U)             // REQ, RSP, NTF '<S535>/RTC Request Response Trigger'
#define RTCID_PreAmpBalance_CfgSet     (0x1b200000U)             // REQ, RSP, NTF '<S564>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaSurroundLevelControlIndex (0x15200001U) // REQ, RSP, NTF '<S1113>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaSurroundLevelControlReset (0x15210002U) // REQ, RSP '<S1114>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaPostUpmixDisable (0x15210000U)         // REQ, RSP '<S889>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaHoligramDisable (0x16210000U)          // REQ, RSP '<S1190>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaOverheadHoligramDisable (0x17210000U)  // REQ, RSP '<S1280>/RTC Request Response Trigger'
#define RTCID_PreAmpMedusaPostHoligramDisable (0x11210000U)      // REQ, RSP '<S1300>/RTC Request Response Trigger'
#define RTCID_PreAmpMuteControlSet     (0x19200001U)             // REQ, RSP, NTF '<S1390>/RTC Request Response Trigger'
#define RTCID_PreAmpFadeControlSet     (0x19200000U)             // REQ, RSP, NTF '<S1360>/RTC Request Response Trigger'
#define RTCID_PreAmpSleepingBeautyDRSet (0x19200003U)            // REQ, RSP, NTF '<S1433>/RTC Request Response Trigger'
#define RTCID_PreAmpSleepingBeautyFRSet (0x19200004U)            // REQ, RSP, NTF '<S1453>/RTC Request Response Trigger'
#define RTCID_PreAmpResetSleepingBeauty (0x19210002U)            // REQ, RSP '<S1354>/RTC Request Response Trigger'
#define RTCID_PreAmpBassSet            (0x10200000U)             // REQ, RSP, NTF '<S1527>/RTC Request Response Trigger'
#define RTCID_PreAmpMidrangeSet        (0x10200001U)             // REQ, RSP, NTF '<S1545>/RTC Request Response Trigger'
#define RTCID_PreAmpTrebleSet          (0x10200002U)             // REQ, RSP, NTF '<S1581>/RTC Request Response Trigger'
#define RTCID_NearFr_RouterSet         (0x10110013U)             // REQ, RSP '<S1714>/RTC Request Response Trigger'
#define RTCID_NearAnn1Ann1VolumeSet    (0x10100002U)             // REQ, RSP, NTF '<S1908>/RTC Request Response Trigger'
#define RTCID_NearAnn2Ann2VolumeSet    (0x10100005U)             // REQ, RSP, NTF '<S1988>/RTC Request Response Trigger'
#define RTCID_NearAnn3Ann3VolumeSet    (0x10100008U)             // REQ, RSP, NTF '<S2068>/RTC Request Response Trigger'
#define RTCID_NearAnn4Ann4VolumeSet    (0x1010000bU)             // REQ, RSP, NTF '<S2148>/RTC Request Response Trigger'
#define RTCID_NearAnn1Ann1NonEntGainCalcvncEnableRTC (0x10110001U) // REQ, RSP '<S1857>/RTC Request Response Trigger'
#define RTCID_NearAnn1Ann1MuteSet      (0x10100000U)             // REQ, RSP, NTF '<S1886>/RTC Request Response Trigger'
#define RTCID_NearAnn2Ann2NonEntGainCalcvncEnableRTC (0x10110004U) // REQ, RSP '<S1937>/RTC Request Response Trigger'
#define RTCID_NearAnn2Ann2MuteSet      (0x10100003U)             // REQ, RSP, NTF '<S1966>/RTC Request Response Trigger'
#define RTCID_NearAnn3Ann3NonEntGainCalcvncEnableRTC (0x10110007U) // REQ, RSP '<S2017>/RTC Request Response Trigger'
#define RTCID_NearAnn3Ann3MuteSet      (0x10100006U)             // REQ, RSP, NTF '<S2046>/RTC Request Response Trigger'
#define RTCID_NearAnn4Ann4NonEntGainCalcvncEnableRTC (0x1011000aU) // REQ, RSP '<S2097>/RTC Request Response Trigger'
#define RTCID_NearAnn4Ann4MuteSet      (0x10100009U)             // REQ, RSP, NTF '<S2126>/RTC Request Response Trigger'
#define RTCID_NearAnnNoiseLevel        (0x1012000cU)             // REQ *only* '<S1784>/RTC Request Response Trigger'
#define RTCID_NearChannel1_Location    (0x1011000dU)             // REQ, RSP '<S1736>/RTC Request Response Trigger'
#define RTCID_NearChannel2_Location    (0x1011000eU)             // REQ, RSP '<S1735>/RTC Request Response Trigger'
#define RTCID_NearChannel3_Location    (0x1011000fU)             // REQ, RSP '<S1738>/RTC Request Response Trigger'
#define RTCID_NearChannel4_Location    (0x10110010U)             // REQ, RSP '<S1737>/RTC Request Response Trigger'
#define RTCID_NearDr_RouterSet         (0x10110011U)             // REQ, RSP '<S1656>/RTC Request Response Trigger'
#define RTCID_NearEnable               (0x10110012U)             // REQ, RSP '<S1604>/RTC Request Response Trigger'
#define RTCID_PostProcessMuteSet       (0x10300003U)             // REQ, RSP, NTF '<S2221>/RTC Request Response Trigger'
#define RTCID_PostProcessLimiterSoftclipParamSet (0x10310002U)   // REQ, RSP '<S2185>/RTC Request Response Trigger'
#define RTCID_PostProcessLimiterSoftclipDisable (0x10310001U)    // REQ, RSP '<S2186>/RTC Request Response Trigger'
#define RTCID_PostProcessEnergyLimiterEnableLimiter (0x10300000U) // REQ, RSP, NTF '<S2191>/RTC Request Response Trigger'
#define RTCID_PostProcessPostLimiterEqShutdown (0x10310004U)     // REQ, RSP '<S2244>/RTC Request Response Trigger'
#define RTCID_TestRouterASDRouterMainSelect (0x10510004U)        // REQ, RSP '<S2279>/RTC Request Response Trigger'
#define RTCID_TestRouterASDRouterMainGain (0x10510003U)          // REQ, RSP '<S2278>/RTC Request Response Trigger'
#define RTCID_TestRouterASDRouterAuxEnable (0x10510000U)         // REQ, RSP '<S2274>/RTC Request Response Trigger'
#define RTCID_TestRouterASDRouterAuxSelect (0x10510002U)         // REQ, RSP '<S2276>/RTC Request Response Trigger'
#define RTCID_TestRouterASDRouterAuxGain (0x10510001U)           // REQ, RSP '<S2275>/RTC Request Response Trigger'

// ------------------------------------------------------------
// PAYLOAD UNION MACROS
// ------------------------------------------------------------
#define ALL_REQ_PAYLOADS               InputSelectRouterCfgSet_REQ_T InputSelectRouterCfgSet; PreAmpAudiopilotsetHVACSetting_REQ_T PreAmpAudiopilotsetHVACSetting; PreAmpAudiopilotmuteReference_REQ_T PreAmpAudiopilotmuteReference; PreAmpAudiopilotsetSpeedIn_REQ_T PreAmpAudiopilotsetSpeedIn; PreAmpAudiopilotgetBassBoost_REQ_T PreAmpAudiopilotgetBassBoost; PreAmpAudiopilotgetMidBoost_REQ_T PreAmpAudiopilotgetMidBoost; PreAmpAudiopilotgetTrebleBoost_REQ_T PreAmpAudiopilotgetTrebleBoost; PreAmpAudiopilotsetDynEQBoostOverRide_REQ_T PreAmpAudiopilotsetDynEQBoostOverRide; PreAmpAudiopilotsetVNCBassBoostOverRide_REQ_T PreAmpAudiopilotsetVNCBassBoostOverRide; PreAmpAudiopilotsetVNCMidBoostOverRide_REQ_T PreAmpAudiopilotsetVNCMidBoostOverRide; PreAmpAudiopilotsetVNCTrebleBoostOverRide_REQ_T PreAmpAudiopilotsetVNCTrebleBoostOverRide; PreAmpAudiopilotsetLoudSignalOverRide_REQ_T PreAmpAudiopilotsetLoudSignalOverRide; PreAmpAudiopilotsetVNCSignalOverRide_REQ_T PreAmpAudiopilotsetVNCSignalOverRide; PreAmpAudiopilotgetAverageAudioPilotBoostLevel_REQ_T PreAmpAudiopilotgetAverageAudioPilotBoostLevel; PreAmpAudiopilotsetHFNoiseOverRide_REQ_T PreAmpAudiopilotsetHFNoiseOverRide; PreAmpAudiopilotsetLFNoiseOverRide_REQ_T PreAmpAudiopilotsetLFNoiseOverRide; PreAmpAudiopilotsetRatioOverRide_REQ_T PreAmpAudiopilotsetRatioOverRide; PreAmpAudiopilotsetWBNoiseOverRide_REQ_T PreAmpAudiopilotsetWBNoiseOverRide; PreAmpAudiopilotsetDyneqOn_REQ_T PreAmpAudiopilotsetDyneqOn; PreAmpAudiopilotsetAudioPilotOn_REQ_T PreAmpAudiopilotsetAudioPilotOn; PreAmpVolumeCfgSet_REQ_T PreAmpVolumeCfgSet; PreAmpBalance_CfgSet_REQ_T PreAmpBalance_CfgSet; PreAmpMedusaSurroundLevelControlIndex_REQ_T PreAmpMedusaSurroundLevelControlIndex; PreAmpMedusaSurroundLevelControlReset_REQ_T PreAmpMedusaSurroundLevelControlReset; PreAmpMedusaPostUpmixDisable_REQ_T PreAmpMedusaPostUpmixDisable; PreAmpMedusaHoligramDisable_REQ_T PreAmpMedusaHoligramDisable; PreAmpMedusaOverheadHoligramDisable_REQ_T PreAmpMedusaOverheadHoligramDisable; PreAmpMedusaPostHoligramDisable_REQ_T PreAmpMedusaPostHoligramDisable; PreAmpFadeControlSet_REQ_T PreAmpFadeControlSet; PreAmpMuteControlSet_REQ_T PreAmpMuteControlSet; PreAmpResetSleepingBeauty_REQ_T PreAmpResetSleepingBeauty; PreAmpSleepingBeautyDRSet_REQ_T PreAmpSleepingBeautyDRSet; PreAmpSleepingBeautyFRSet_REQ_T PreAmpSleepingBeautyFRSet; PreAmpBassSet_REQ_T PreAmpBassSet; PreAmpMidrangeSet_REQ_T PreAmpMidrangeSet; PreAmpTrebleSet_REQ_T PreAmpTrebleSet; NearDr_RouterSet_REQ_T NearDr_RouterSet; NearFr_RouterSet_REQ_T NearFr_RouterSet; NearChannel2_Location_REQ_T NearChannel2_Location; NearChannel1_Location_REQ_T NearChannel1_Location; NearChannel4_Location_REQ_T NearChannel4_Location; NearChannel3_Location_REQ_T NearChannel3_Location; NearAnnNoiseLevel_REQ_T NearAnnNoiseLevel; NearAnn1Ann1NonEntGainCalcvncEnableRTC_REQ_T NearAnn1Ann1NonEntGainCalcvncEnableRTC; NearAnn1Ann1MuteSet_REQ_T NearAnn1Ann1MuteSet; NearAnn1Ann1VolumeSet_REQ_T NearAnn1Ann1VolumeSet; NearAnn2Ann2NonEntGainCalcvncEnableRTC_REQ_T NearAnn2Ann2NonEntGainCalcvncEnableRTC; NearAnn2Ann2MuteSet_REQ_T NearAnn2Ann2MuteSet; NearAnn2Ann2VolumeSet_REQ_T NearAnn2Ann2VolumeSet; NearAnn3Ann3NonEntGainCalcvncEnableRTC_REQ_T NearAnn3Ann3NonEntGainCalcvncEnableRTC; NearAnn3Ann3MuteSet_REQ_T NearAnn3Ann3MuteSet; NearAnn3Ann3VolumeSet_REQ_T NearAnn3Ann3VolumeSet; NearAnn4Ann4NonEntGainCalcvncEnableRTC_REQ_T NearAnn4Ann4NonEntGainCalcvncEnableRTC; NearAnn4Ann4MuteSet_REQ_T NearAnn4Ann4MuteSet; NearAnn4Ann4VolumeSet_REQ_T NearAnn4Ann4VolumeSet; NearEnable_REQ_T NearEnable; PostProcessEnergyLimiterEnableLimiter_REQ_T PostProcessEnergyLimiterEnableLimiter; PostProcessMuteSet_REQ_T PostProcessMuteSet; PostProcessPostLimiterEqShutdown_REQ_T PostProcessPostLimiterEqShutdown; PostProcessLimiterSoftclipParamSet_REQ_T PostProcessLimiterSoftclipParamSet; PostProcessLimiterSoftclipDisable_REQ_T PostProcessLimiterSoftclipDisable; TestRouterASDRouterAuxEnable_REQ_T TestRouterASDRouterAuxEnable; TestRouterASDRouterAuxGain_REQ_T TestRouterASDRouterAuxGain; TestRouterASDRouterAuxSelect_REQ_T TestRouterASDRouterAuxSelect; TestRouterASDRouterMainGain_REQ_T TestRouterASDRouterMainGain; TestRouterASDRouterMainSelect_REQ_T TestRouterASDRouterMainSelect;
#define ALL_RSP_PAYLOADS               InputSelectRouterCfgSet_RSP_T InputSelectRouterCfgSet; PreAmpAudiopilotmuteReference_RSP_T PreAmpAudiopilotmuteReference; PreAmpAudiopilotgetBassBoost_RSP_T PreAmpAudiopilotgetBassBoost; PreAmpAudiopilotgetMidBoost_RSP_T PreAmpAudiopilotgetMidBoost; PreAmpAudiopilotgetTrebleBoost_RSP_T PreAmpAudiopilotgetTrebleBoost; PreAmpAudiopilotgetAverageAudioPilotBoostLevel_RSP_T PreAmpAudiopilotgetAverageAudioPilotBoostLevel; PreAmpAudiopilotsetDyneqOn_RSP_T PreAmpAudiopilotsetDyneqOn; PreAmpAudiopilotsetAudioPilotOn_RSP_T PreAmpAudiopilotsetAudioPilotOn; PreAmpVolumeCfgSet_RSP_T PreAmpVolumeCfgSet; PreAmpBalance_CfgSet_RSP_T PreAmpBalance_CfgSet; PreAmpMedusaSurroundLevelControlIndex_RSP_T PreAmpMedusaSurroundLevelControlIndex; PreAmpMedusaSurroundLevelControlReset_RSP_T PreAmpMedusaSurroundLevelControlReset; PreAmpMedusaPostUpmixDisable_RSP_T PreAmpMedusaPostUpmixDisable; PreAmpMedusaHoligramDisable_RSP_T PreAmpMedusaHoligramDisable; PreAmpMedusaOverheadHoligramDisable_RSP_T PreAmpMedusaOverheadHoligramDisable; PreAmpMedusaPostHoligramDisable_RSP_T PreAmpMedusaPostHoligramDisable; PreAmpFadeControlSet_RSP_T PreAmpFadeControlSet; PreAmpMuteControlSet_RSP_T PreAmpMuteControlSet; PreAmpResetSleepingBeauty_RSP_T PreAmpResetSleepingBeauty; PreAmpSleepingBeautyDRSet_RSP_T PreAmpSleepingBeautyDRSet; PreAmpSleepingBeautyFRSet_RSP_T PreAmpSleepingBeautyFRSet; PreAmpBassSet_RSP_T PreAmpBassSet; PreAmpMidrangeSet_RSP_T PreAmpMidrangeSet; PreAmpTrebleSet_RSP_T PreAmpTrebleSet; NearDr_RouterSet_RSP_T NearDr_RouterSet; NearFr_RouterSet_RSP_T NearFr_RouterSet; NearChannel2_Location_RSP_T NearChannel2_Location; NearChannel1_Location_RSP_T NearChannel1_Location; NearChannel4_Location_RSP_T NearChannel4_Location; NearChannel3_Location_RSP_T NearChannel3_Location; NearAnn1Ann1NonEntGainCalcvncEnableRTC_RSP_T NearAnn1Ann1NonEntGainCalcvncEnableRTC; NearAnn1Ann1MuteSet_RSP_T NearAnn1Ann1MuteSet; NearAnn1Ann1VolumeSet_RSP_T NearAnn1Ann1VolumeSet; NearAnn2Ann2NonEntGainCalcvncEnableRTC_RSP_T NearAnn2Ann2NonEntGainCalcvncEnableRTC; NearAnn2Ann2MuteSet_RSP_T NearAnn2Ann2MuteSet; NearAnn2Ann2VolumeSet_RSP_T NearAnn2Ann2VolumeSet; NearAnn3Ann3NonEntGainCalcvncEnableRTC_RSP_T NearAnn3Ann3NonEntGainCalcvncEnableRTC; NearAnn3Ann3MuteSet_RSP_T NearAnn3Ann3MuteSet; NearAnn3Ann3VolumeSet_RSP_T NearAnn3Ann3VolumeSet; NearAnn4Ann4NonEntGainCalcvncEnableRTC_RSP_T NearAnn4Ann4NonEntGainCalcvncEnableRTC; NearAnn4Ann4MuteSet_RSP_T NearAnn4Ann4MuteSet; NearAnn4Ann4VolumeSet_RSP_T NearAnn4Ann4VolumeSet; NearEnable_RSP_T NearEnable; PostProcessEnergyLimiterEnableLimiter_RSP_T PostProcessEnergyLimiterEnableLimiter; PostProcessMuteSet_RSP_T PostProcessMuteSet; PostProcessPostLimiterEqShutdown_RSP_T PostProcessPostLimiterEqShutdown; PostProcessLimiterSoftclipParamSet_RSP_T PostProcessLimiterSoftclipParamSet; PostProcessLimiterSoftclipDisable_RSP_T PostProcessLimiterSoftclipDisable; TestRouterASDRouterAuxEnable_RSP_T TestRouterASDRouterAuxEnable; TestRouterASDRouterAuxGain_RSP_T TestRouterASDRouterAuxGain; TestRouterASDRouterAuxSelect_RSP_T TestRouterASDRouterAuxSelect; TestRouterASDRouterMainGain_RSP_T TestRouterASDRouterMainGain; TestRouterASDRouterMainSelect_RSP_T TestRouterASDRouterMainSelect;
#define ALL_NTF_PAYLOADS               PreAmpVolumeCfgSet_NTF_T PreAmpVolumeCfgSet; PreAmpBalance_CfgSet_NTF_T PreAmpBalance_CfgSet; PreAmpMedusaSurroundLevelControlIndex_NTF_T PreAmpMedusaSurroundLevelControlIndex; PreAmpFadeControlSet_NTF_T PreAmpFadeControlSet; PreAmpMuteControlSet_NTF_T PreAmpMuteControlSet; PreAmpSleepingBeautyDRSet_NTF_T PreAmpSleepingBeautyDRSet; PreAmpSleepingBeautyFRSet_NTF_T PreAmpSleepingBeautyFRSet; PreAmpBassSet_NTF_T PreAmpBassSet; PreAmpMidrangeSet_NTF_T PreAmpMidrangeSet; PreAmpTrebleSet_NTF_T PreAmpTrebleSet; NearAnn1Ann1MuteSet_NTF_T NearAnn1Ann1MuteSet; NearAnn1Ann1VolumeSet_NTF_T NearAnn1Ann1VolumeSet; NearAnn2Ann2MuteSet_NTF_T NearAnn2Ann2MuteSet; NearAnn2Ann2VolumeSet_NTF_T NearAnn2Ann2VolumeSet; NearAnn3Ann3MuteSet_NTF_T NearAnn3Ann3MuteSet; NearAnn3Ann3VolumeSet_NTF_T NearAnn3Ann3VolumeSet; NearAnn4Ann4MuteSet_NTF_T NearAnn4Ann4MuteSet; NearAnn4Ann4VolumeSet_NTF_T NearAnn4Ann4VolumeSet; PostProcessEnergyLimiterEnableLimiter_NTF_T PostProcessEnergyLimiterEnableLimiter; PostProcessMuteSet_NTF_T PostProcessMuteSet;

// ------------------------------------------------------------
// RTC REQUEST PAYLOAD DEFINITIONS
// ------------------------------------------------------------

/// Request Payload Definition for InputSelectRouterCfgSet
/// ----------------------------
/// @ingroup InputSelectRouterCfgSet
/// This page describes the payload format for Request messages
/// used by the InputSelectRouterCfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref InputSelectRouterCfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_InputSelectRouterCfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t routerMap[5];              // startChar:4 charSize:20
}
InputSelectRouterCfgSet_REQ_T;         /* '<S21>/UnpackREQ' */

#define InputSelectRouterCfgSet_REQ_routerMap_SIZE 5             /* '<S21>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetHVACSetting
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetHVACSetting
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetHVACSetting RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetHVACSetting.
typedef struct
{
    uint32_t msgId;               // always RTCID_PreAmpAudiopilotsetHVACSetting
    float HVACSetting;                 // startChar:0 charSize:4
}
PreAmpAudiopilotsetHVACSetting_REQ_T;  /* '<S54>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotmuteReference
/// ----------------------------
/// @ingroup PreAmpAudiopilotmuteReference
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotmuteReference RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotmuteReference.
typedef struct
{
    uint32_t msgId;                // always RTCID_PreAmpAudiopilotmuteReference
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t muteReference;            // startChar:4 charSize:4
}
PreAmpAudiopilotmuteReference_REQ_T;   /* '<S60>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetSpeedIn
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetSpeedIn
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetSpeedIn RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetSpeedIn.
typedef struct
{
    uint32_t msgId;                   // always RTCID_PreAmpAudiopilotsetSpeedIn
    float speedIn;                     // startChar:0 charSize:4
}
PreAmpAudiopilotsetSpeedIn_REQ_T;      /* '<S66>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotgetBassBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetBassBoost
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotgetBassBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetBassBoost.
typedef struct
{
    uint32_t msgId;                 // always RTCID_PreAmpAudiopilotgetBassBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpAudiopilotgetBassBoost_REQ_T;    /* '<S90>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotgetMidBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetMidBoost
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotgetMidBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetMidBoost.
typedef struct
{
    uint32_t msgId;                  // always RTCID_PreAmpAudiopilotgetMidBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpAudiopilotgetMidBoost_REQ_T;     /* '<S96>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotgetTrebleBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetTrebleBoost
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotgetTrebleBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetTrebleBoost.
typedef struct
{
    uint32_t msgId;               // always RTCID_PreAmpAudiopilotgetTrebleBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpAudiopilotgetTrebleBoost_REQ_T;  /* '<S102>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetDynEQBoostOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetDynEQBoostOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetDynEQBoostOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetDynEQBoostOverRide.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpAudiopilotsetDynEQBoostOverRide
    uint32_t DynEQBoostOverRideFlag;   // startChar:0 charSize:4
    float DynEQBoostOverRide;          // startChar:4 charSize:4
}
PreAmpAudiopilotsetDynEQBoostOverRide_REQ_T;/* '<S150>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetVNCBassBoostOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetVNCBassBoostOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetVNCBassBoostOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetVNCBassBoostOverRide.
typedef struct
{
    uint32_t msgId;      // always RTCID_PreAmpAudiopilotsetVNCBassBoostOverRide
    uint32_t VNCBassBoostOverRideFlag; // startChar:0 charSize:4
    float VNCBassBoostOverRide;        // startChar:4 charSize:4
}
PreAmpAudiopilotsetVNCBassBoostOverRide_REQ_T;/* '<S156>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetVNCMidBoostOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetVNCMidBoostOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetVNCMidBoostOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetVNCMidBoostOverRide.
typedef struct
{
    uint32_t msgId;       // always RTCID_PreAmpAudiopilotsetVNCMidBoostOverRide
    uint32_t VNCMidBoostOverRideFlag;  // startChar:0 charSize:4
    float VNCMidBoostOverRide;         // startChar:4 charSize:4
}
PreAmpAudiopilotsetVNCMidBoostOverRide_REQ_T;/* '<S162>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetVNCTrebleBoostOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetVNCTrebleBoostOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetVNCTrebleBoostOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetVNCTrebleBoostOverRide.
typedef struct
{
    uint32_t msgId;    // always RTCID_PreAmpAudiopilotsetVNCTrebleBoostOverRide
    uint32_t VNCTrebleBoostOverRideFlag;// startChar:0 charSize:4
    float VNCTrebleBoostOverRide;      // startChar:4 charSize:4
}
PreAmpAudiopilotsetVNCTrebleBoostOverRide_REQ_T;/* '<S168>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetLoudSignalOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetLoudSignalOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetLoudSignalOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetLoudSignalOverRide.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpAudiopilotsetLoudSignalOverRide
    uint32_t LoudSignalOverRideFlag;   // startChar:0 charSize:4
    float LoudSignalOverRide;          // startChar:4 charSize:4
}
PreAmpAudiopilotsetLoudSignalOverRide_REQ_T;/* '<S178>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetVNCSignalOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetVNCSignalOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetVNCSignalOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetVNCSignalOverRide.
typedef struct
{
    uint32_t msgId;         // always RTCID_PreAmpAudiopilotsetVNCSignalOverRide
    uint32_t VNCSignalOverRideFlag;    // startChar:0 charSize:4
    float VNCSignalOverRide;           // startChar:4 charSize:4
}
PreAmpAudiopilotsetVNCSignalOverRide_REQ_T;/* '<S184>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotgetAverageAudioPilotBoostLevel
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetAverageAudioPilotBoostLevel
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotgetAverageAudioPilotBoostLevel RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetAverageAudioPilotBoostLevel.
typedef struct
{
    uint32_t msgId;
                  // always RTCID_PreAmpAudiopilotgetAverageAudioPilotBoostLevel
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpAudiopilotgetAverageAudioPilotBoostLevel_REQ_T;/* '<S190>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetHFNoiseOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetHFNoiseOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetHFNoiseOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetHFNoiseOverRide.
typedef struct
{
    uint32_t msgId;           // always RTCID_PreAmpAudiopilotsetHFNoiseOverRide
    uint32_t HFNoiseOverRideFlag;      // startChar:0 charSize:4
    float HFNoiseOverRide;             // startChar:4 charSize:4
}
PreAmpAudiopilotsetHFNoiseOverRide_REQ_T;/* '<S201>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetLFNoiseOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetLFNoiseOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetLFNoiseOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetLFNoiseOverRide.
typedef struct
{
    uint32_t msgId;           // always RTCID_PreAmpAudiopilotsetLFNoiseOverRide
    uint32_t LFNoiseOverRideFlag;      // startChar:0 charSize:4
    float LFNoiseOverRide;             // startChar:4 charSize:4
}
PreAmpAudiopilotsetLFNoiseOverRide_REQ_T;/* '<S207>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetRatioOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetRatioOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetRatioOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetRatioOverRide.
typedef struct
{
    uint32_t msgId;             // always RTCID_PreAmpAudiopilotsetRatioOverRide
    uint32_t RatioOverRideFlag;        // startChar:0 charSize:4
    float RatioOverRide;               // startChar:4 charSize:4
}
PreAmpAudiopilotsetRatioOverRide_REQ_T;/* '<S213>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetWBNoiseOverRide
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetWBNoiseOverRide
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetWBNoiseOverRide RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetWBNoiseOverRide.
typedef struct
{
    uint32_t msgId;           // always RTCID_PreAmpAudiopilotsetWBNoiseOverRide
    uint32_t WBNoiseOverRideFlag;      // startChar:0 charSize:4
    float WBNoiseOverRide;             // startChar:4 charSize:4
}
PreAmpAudiopilotsetWBNoiseOverRide_REQ_T;/* '<S219>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetDyneqOn
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetDyneqOn
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetDyneqOn RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetDyneqOn.
typedef struct
{
    uint32_t msgId;                   // always RTCID_PreAmpAudiopilotsetDyneqOn
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t dyneq_on;                 // startChar:4 charSize:4
}
PreAmpAudiopilotsetDyneqOn_REQ_T;      /* '<S241>/UnpackREQ' */

/// Request Payload Definition for PreAmpAudiopilotsetAudioPilotOn
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetAudioPilotOn
/// This page describes the payload format for Request messages
/// used by the PreAmpAudiopilotsetAudioPilotOn RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetAudioPilotOn.
typedef struct
{
    uint32_t msgId;              // always RTCID_PreAmpAudiopilotsetAudioPilotOn
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t audiopilot_on;            // startChar:4 charSize:4
}
PreAmpAudiopilotsetAudioPilotOn_REQ_T; /* '<S247>/UnpackREQ' */

/// Request Payload Definition for PreAmpVolumeCfgSet
/// ----------------------------
/// @ingroup PreAmpVolumeCfgSet
/// This page describes the payload format for Request messages
/// used by the PreAmpVolumeCfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpVolumeCfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpVolumeCfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
    int32_t gain_offset;               // startChar:16 charSize:4
}
PreAmpVolumeCfgSet_REQ_T;              /* '<S547>/UnpackREQ' */

/// Request Payload Definition for PreAmpBalance_CfgSet
/// ----------------------------
/// @ingroup PreAmpBalance_CfgSet
/// This page describes the payload format for Request messages
/// used by the PreAmpBalance_CfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBalance_CfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBalance_CfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpBalance_CfgSet_REQ_T;            /* '<S583>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaSurroundLevelControlIndex
/// ----------------------------
/// @ingroup PreAmpMedusaSurroundLevelControlIndex
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaSurroundLevelControlIndex RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaSurroundLevelControlIndex.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpMedusaSurroundLevelControlIndex
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t surround_index;           // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpMedusaSurroundLevelControlIndex_REQ_T;/* '<S1121>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaSurroundLevelControlReset
/// ----------------------------
/// @ingroup PreAmpMedusaSurroundLevelControlReset
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaSurroundLevelControlReset RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaSurroundLevelControlReset.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpMedusaSurroundLevelControlReset
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpMedusaSurroundLevelControlReset_REQ_T;/* '<S1127>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaPostUpmixDisable
/// ----------------------------
/// @ingroup PreAmpMedusaPostUpmixDisable
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaPostUpmixDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaPostUpmixDisable.
typedef struct
{
    uint32_t msgId;                 // always RTCID_PreAmpMedusaPostUpmixDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpMedusaPostUpmixDisable_REQ_T;    /* '<S1185>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaHoligramDisable
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaHoligramDisable.
typedef struct
{
    uint32_t msgId;                  // always RTCID_PreAmpMedusaHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpMedusaHoligramDisable_REQ_T;     /* '<S1276>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaOverheadHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaOverheadHoligramDisable
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaOverheadHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaOverheadHoligramDisable.
typedef struct
{
    uint32_t msgId;          // always RTCID_PreAmpMedusaOverheadHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpMedusaOverheadHoligramDisable_REQ_T;/* '<S1288>/UnpackREQ' */

/// Request Payload Definition for PreAmpMedusaPostHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaPostHoligramDisable
/// This page describes the payload format for Request messages
/// used by the PreAmpMedusaPostHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaPostHoligramDisable.
typedef struct
{
    uint32_t msgId;              // always RTCID_PreAmpMedusaPostHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpMedusaPostHoligramDisable_REQ_T; /* '<S1326>/UnpackREQ' */

/// Request Payload Definition for PreAmpFadeControlSet
/// ----------------------------
/// @ingroup PreAmpFadeControlSet
/// This page describes the payload format for Request messages
/// used by the PreAmpFadeControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpFadeControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpFadeControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpFadeControlSet_REQ_T;            /* '<S1373>/UnpackREQ' */

/// Request Payload Definition for PreAmpMuteControlSet
/// ----------------------------
/// @ingroup PreAmpMuteControlSet
/// This page describes the payload format for Request messages
/// used by the PreAmpMuteControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMuteControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMuteControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpMuteControlSet_REQ_T;            /* '<S1398>/UnpackREQ' */

/// Request Payload Definition for PreAmpResetSleepingBeauty
/// ----------------------------
/// @ingroup PreAmpResetSleepingBeauty
/// This page describes the payload format for Request messages
/// used by the PreAmpResetSleepingBeauty RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpResetSleepingBeauty.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpResetSleepingBeauty
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PreAmpResetSleepingBeauty_REQ_T;       /* '<S1430>/UnpackREQ' */

/// Request Payload Definition for PreAmpSleepingBeautyDRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyDRSet
/// This page describes the payload format for Request messages
/// used by the PreAmpSleepingBeautyDRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyDRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyDRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpSleepingBeautyDRSet_REQ_T;       /* '<S1450>/UnpackREQ' */

/// Request Payload Definition for PreAmpSleepingBeautyFRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyFRSet
/// This page describes the payload format for Request messages
/// used by the PreAmpSleepingBeautyFRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyFRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyFRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpSleepingBeautyFRSet_REQ_T;       /* '<S1470>/UnpackREQ' */

/// Request Payload Definition for PreAmpBassSet
/// ----------------------------
/// @ingroup PreAmpBassSet
/// This page describes the payload format for Request messages
/// used by the PreAmpBassSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBassSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBassSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpBassSet_REQ_T;                   /* '<S1543>/UnpackREQ' */

/// Request Payload Definition for PreAmpMidrangeSet
/// ----------------------------
/// @ingroup PreAmpMidrangeSet
/// This page describes the payload format for Request messages
/// used by the PreAmpMidrangeSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMidrangeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMidrangeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpMidrangeSet_REQ_T;               /* '<S1561>/UnpackREQ' */

/// Request Payload Definition for PreAmpTrebleSet
/// ----------------------------
/// @ingroup PreAmpTrebleSet
/// This page describes the payload format for Request messages
/// used by the PreAmpTrebleSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpTrebleSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpTrebleSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t gain_index;               // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PreAmpTrebleSet_REQ_T;                 /* '<S1597>/UnpackREQ' */

/// Request Payload Definition for NearDr_RouterSet
/// ----------------------------
/// @ingroup NearDr_RouterSet
/// This page describes the payload format for Request messages
/// used by the NearDr_RouterSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearDr_RouterSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearDr_RouterSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t routerMap[18];             // startChar:4 charSize:72
}
NearDr_RouterSet_REQ_T;                /* '<S1662>/UnpackREQ' */

#define NearDr_RouterSet_REQ_routerMap_SIZE 18                   /* '<S1662>/UnpackREQ' */

/// Request Payload Definition for NearFr_RouterSet
/// ----------------------------
/// @ingroup NearFr_RouterSet
/// This page describes the payload format for Request messages
/// used by the NearFr_RouterSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearFr_RouterSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearFr_RouterSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t routerMap[18];             // startChar:4 charSize:72
}
NearFr_RouterSet_REQ_T;                /* '<S1720>/UnpackREQ' */

#define NearFr_RouterSet_REQ_routerMap_SIZE 18                   /* '<S1720>/UnpackREQ' */

/// Request Payload Definition for NearChannel2_Location
/// ----------------------------
/// @ingroup NearChannel2_Location
/// This page describes the payload format for Request messages
/// used by the NearChannel2_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel2_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel2_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    float loc[2];                      // startChar:4 charSize:8
}
NearChannel2_Location_REQ_T;           /* '<S1743>/UnpackREQ' */

#define NearChannel2_Location_REQ_loc_SIZE 2                     /* '<S1743>/UnpackREQ' */

/// Request Payload Definition for NearChannel1_Location
/// ----------------------------
/// @ingroup NearChannel1_Location
/// This page describes the payload format for Request messages
/// used by the NearChannel1_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel1_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel1_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    float loc[2];                      // startChar:4 charSize:8
}
NearChannel1_Location_REQ_T;           /* '<S1749>/UnpackREQ' */

#define NearChannel1_Location_REQ_loc_SIZE 2                     /* '<S1749>/UnpackREQ' */

/// Request Payload Definition for NearChannel4_Location
/// ----------------------------
/// @ingroup NearChannel4_Location
/// This page describes the payload format for Request messages
/// used by the NearChannel4_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel4_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel4_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    float loc[2];                      // startChar:4 charSize:8
}
NearChannel4_Location_REQ_T;           /* '<S1755>/UnpackREQ' */

#define NearChannel4_Location_REQ_loc_SIZE 2                     /* '<S1755>/UnpackREQ' */

/// Request Payload Definition for NearChannel3_Location
/// ----------------------------
/// @ingroup NearChannel3_Location
/// This page describes the payload format for Request messages
/// used by the NearChannel3_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel3_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel3_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    float loc[2];                      // startChar:4 charSize:8
}
NearChannel3_Location_REQ_T;           /* '<S1761>/UnpackREQ' */

#define NearChannel3_Location_REQ_loc_SIZE 2                     /* '<S1761>/UnpackREQ' */

/// Request Payload Definition for NearAnnNoiseLevel
/// ----------------------------
/// @ingroup NearAnnNoiseLevel
/// This page describes the payload format for Request messages
/// used by the NearAnnNoiseLevel RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnnNoiseLevel.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnnNoiseLevel
    float NoiseSig;                    // startChar:0 charSize:4
}
NearAnnNoiseLevel_REQ_T;               /* '<S1850>/UnpackREQ' */

/// Request Payload Definition for NearAnn1Ann1NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn1Ann1NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Request messages
/// used by the NearAnn1Ann1NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn1Ann1NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t vncEnable;                // startChar:4 charSize:4
}
NearAnn1Ann1NonEntGainCalcvncEnableRTC_REQ_T;/* '<S1874>/UnpackREQ' */

/// Request Payload Definition for NearAnn1Ann1MuteSet
/// ----------------------------
/// @ingroup NearAnn1Ann1MuteSet
/// This page describes the payload format for Request messages
/// used by the NearAnn1Ann1MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn1Ann1MuteSet_REQ_T;             /* '<S1894>/UnpackREQ' */

/// Request Payload Definition for NearAnn1Ann1VolumeSet
/// ----------------------------
/// @ingroup NearAnn1Ann1VolumeSet
/// This page describes the payload format for Request messages
/// used by the NearAnn1Ann1VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t volume_index;             // startChar:4 charSize:4
    uint32_t db_per_second;            // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn1Ann1VolumeSet_REQ_T;           /* '<S1922>/UnpackREQ' */

/// Request Payload Definition for NearAnn2Ann2NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn2Ann2NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Request messages
/// used by the NearAnn2Ann2NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn2Ann2NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t vncEnable;                // startChar:4 charSize:4
}
NearAnn2Ann2NonEntGainCalcvncEnableRTC_REQ_T;/* '<S1954>/UnpackREQ' */

/// Request Payload Definition for NearAnn2Ann2MuteSet
/// ----------------------------
/// @ingroup NearAnn2Ann2MuteSet
/// This page describes the payload format for Request messages
/// used by the NearAnn2Ann2MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn2Ann2MuteSet_REQ_T;             /* '<S1974>/UnpackREQ' */

/// Request Payload Definition for NearAnn2Ann2VolumeSet
/// ----------------------------
/// @ingroup NearAnn2Ann2VolumeSet
/// This page describes the payload format for Request messages
/// used by the NearAnn2Ann2VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t volume_index;             // startChar:4 charSize:4
    uint32_t db_per_second;            // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn2Ann2VolumeSet_REQ_T;           /* '<S2002>/UnpackREQ' */

/// Request Payload Definition for NearAnn3Ann3NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn3Ann3NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Request messages
/// used by the NearAnn3Ann3NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn3Ann3NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t vncEnable;                // startChar:4 charSize:4
}
NearAnn3Ann3NonEntGainCalcvncEnableRTC_REQ_T;/* '<S2034>/UnpackREQ' */

/// Request Payload Definition for NearAnn3Ann3MuteSet
/// ----------------------------
/// @ingroup NearAnn3Ann3MuteSet
/// This page describes the payload format for Request messages
/// used by the NearAnn3Ann3MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn3Ann3MuteSet_REQ_T;             /* '<S2054>/UnpackREQ' */

/// Request Payload Definition for NearAnn3Ann3VolumeSet
/// ----------------------------
/// @ingroup NearAnn3Ann3VolumeSet
/// This page describes the payload format for Request messages
/// used by the NearAnn3Ann3VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t volume_index;             // startChar:4 charSize:4
    uint32_t db_per_second;            // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn3Ann3VolumeSet_REQ_T;           /* '<S2082>/UnpackREQ' */

/// Request Payload Definition for NearAnn4Ann4NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn4Ann4NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Request messages
/// used by the NearAnn4Ann4NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn4Ann4NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t vncEnable;                // startChar:4 charSize:4
}
NearAnn4Ann4NonEntGainCalcvncEnableRTC_REQ_T;/* '<S2114>/UnpackREQ' */

/// Request Payload Definition for NearAnn4Ann4MuteSet
/// ----------------------------
/// @ingroup NearAnn4Ann4MuteSet
/// This page describes the payload format for Request messages
/// used by the NearAnn4Ann4MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn4Ann4MuteSet_REQ_T;             /* '<S2134>/UnpackREQ' */

/// Request Payload Definition for NearAnn4Ann4VolumeSet
/// ----------------------------
/// @ingroup NearAnn4Ann4VolumeSet
/// This page describes the payload format for Request messages
/// used by the NearAnn4Ann4VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t volume_index;             // startChar:4 charSize:4
    uint32_t db_per_second;            // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
NearAnn4Ann4VolumeSet_REQ_T;           /* '<S2162>/UnpackREQ' */

/// Request Payload Definition for NearEnable
/// ----------------------------
/// @ingroup NearEnable
/// This page describes the payload format for Request messages
/// used by the NearEnable RTC mechanism. For a more general
/// description of how this message works, see @ref NearEnable.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearEnable
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t Enable;                   // startChar:4 charSize:4
}
NearEnable_REQ_T;                      /* '<S2176>/UnpackREQ' */

/// Request Payload Definition for PostProcessEnergyLimiterEnableLimiter
/// ----------------------------
/// @ingroup PostProcessEnergyLimiterEnableLimiter
/// This page describes the payload format for Request messages
/// used by the PostProcessEnergyLimiterEnableLimiter RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessEnergyLimiterEnableLimiter.
typedef struct
{
    uint32_t msgId;        // always RTCID_PostProcessEnergyLimiterEnableLimiter
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t EnableGainLimiter;        // startChar:4 charSize:4
}
PostProcessEnergyLimiterEnableLimiter_REQ_T;/* '<S2214>/UnpackREQ' */

/// Request Payload Definition for PostProcessMuteSet
/// ----------------------------
/// @ingroup PostProcessMuteSet
/// This page describes the payload format for Request messages
/// used by the PostProcessMuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessMuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PostProcessMuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t mute_switch;              // startChar:4 charSize:4
    uint32_t ramp_db_per_second;       // startChar:8 charSize:4
    uint32_t ramp_milliseconds;        // startChar:12 charSize:4
}
PostProcessMuteSet_REQ_T;              /* '<S2229>/UnpackREQ' */

/// Request Payload Definition for PostProcessPostLimiterEqShutdown
/// ----------------------------
/// @ingroup PostProcessPostLimiterEqShutdown
/// This page describes the payload format for Request messages
/// used by the PostProcessPostLimiterEqShutdown RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessPostLimiterEqShutdown.
typedef struct
{
    uint32_t msgId;             // always RTCID_PostProcessPostLimiterEqShutdown
    uint32_t caller_handle;            // startChar:0 charSize:4
}
PostProcessPostLimiterEqShutdown_REQ_T;/* '<S2254>/UnpackREQ' */

/// Request Payload Definition for PostProcessLimiterSoftclipParamSet
/// ----------------------------
/// @ingroup PostProcessLimiterSoftclipParamSet
/// This page describes the payload format for Request messages
/// used by the PostProcessLimiterSoftclipParamSet RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessLimiterSoftclipParamSet.
typedef struct
{
    uint32_t msgId;           // always RTCID_PostProcessLimiterSoftclipParamSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t paramSet;                 // startChar:4 charSize:4
}
PostProcessLimiterSoftclipParamSet_REQ_T;/* '<S2260>/UnpackREQ' */

/// Request Payload Definition for PostProcessLimiterSoftclipDisable
/// ----------------------------
/// @ingroup PostProcessLimiterSoftclipDisable
/// This page describes the payload format for Request messages
/// used by the PostProcessLimiterSoftclipDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessLimiterSoftclipDisable.
typedef struct
{
    uint32_t msgId;            // always RTCID_PostProcessLimiterSoftclipDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    uint32_t disableMsg;               // startChar:4 charSize:4
}
PostProcessLimiterSoftclipDisable_REQ_T;/* '<S2266>/UnpackREQ' */

/// Request Payload Definition for TestRouterASDRouterAuxEnable
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxEnable
/// This page describes the payload format for Request messages
/// used by the TestRouterASDRouterAuxEnable RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxEnable.
typedef struct
{
    uint32_t msgId;                 // always RTCID_TestRouterASDRouterAuxEnable
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t EnableAuxFlag;             // startChar:4 charSize:4
}
TestRouterASDRouterAuxEnable_REQ_T;    /* '<S2287>/UnpackREQ' */

/// Request Payload Definition for TestRouterASDRouterAuxGain
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxGain
/// This page describes the payload format for Request messages
/// used by the TestRouterASDRouterAuxGain RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxGain.
typedef struct
{
    uint32_t msgId;                   // always RTCID_TestRouterASDRouterAuxGain
    uint32_t caller_handle;            // startChar:0 charSize:4
    float AuxGain[24];                 // startChar:4 charSize:96
}
TestRouterASDRouterAuxGain_REQ_T;      /* '<S2293>/UnpackREQ' */

#define TestRouterASDRouterAuxGain_REQ_AuxGain_SIZE 24           /* '<S2293>/UnpackREQ' */

/// Request Payload Definition for TestRouterASDRouterAuxSelect
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxSelect
/// This page describes the payload format for Request messages
/// used by the TestRouterASDRouterAuxSelect RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxSelect.
typedef struct
{
    uint32_t msgId;                 // always RTCID_TestRouterASDRouterAuxSelect
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t AuxSelect[24];             // startChar:4 charSize:96
}
TestRouterASDRouterAuxSelect_REQ_T;    /* '<S2299>/UnpackREQ' */

#define TestRouterASDRouterAuxSelect_REQ_AuxSelect_SIZE 24       /* '<S2299>/UnpackREQ' */

/// Request Payload Definition for TestRouterASDRouterMainGain
/// ----------------------------
/// @ingroup TestRouterASDRouterMainGain
/// This page describes the payload format for Request messages
/// used by the TestRouterASDRouterMainGain RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterMainGain.
typedef struct
{
    uint32_t msgId;                  // always RTCID_TestRouterASDRouterMainGain
    uint32_t caller_handle;            // startChar:0 charSize:4
    float mainGain[24];                // startChar:4 charSize:96
}
TestRouterASDRouterMainGain_REQ_T;     /* '<S2311>/UnpackREQ' */

#define TestRouterASDRouterMainGain_REQ_mainGain_SIZE 24         /* '<S2311>/UnpackREQ' */

/// Request Payload Definition for TestRouterASDRouterMainSelect
/// ----------------------------
/// @ingroup TestRouterASDRouterMainSelect
/// This page describes the payload format for Request messages
/// used by the TestRouterASDRouterMainSelect RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterMainSelect.
typedef struct
{
    uint32_t msgId;                // always RTCID_TestRouterASDRouterMainSelect
    uint32_t caller_handle;            // startChar:0 charSize:4
    int32_t mainSelect[24];            // startChar:4 charSize:96
}
TestRouterASDRouterMainSelect_REQ_T;   /* '<S2317>/UnpackREQ' */

#define TestRouterASDRouterMainSelect_REQ_mainSelect_SIZE 24     /* '<S2317>/UnpackREQ' */

// ------------------------------------------------------------
// RTC RESPONSE PAYLOAD DEFINITIONS
// ------------------------------------------------------------

/// Response Payload Definition for InputSelectRouterCfgSet
/// ----------------------------
/// @ingroup InputSelectRouterCfgSet
/// This page describes the payload format for Response messages
/// used by the InputSelectRouterCfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref InputSelectRouterCfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_InputSelectRouterCfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    int32_t routerMap[5];              // startChar:8 charSize:20
}
InputSelectRouterCfgSet_RSP_T;         /* '<S22>/PackRSP' */

#define InputSelectRouterCfgSet_RSP_routerMap_SIZE 5             /* '<S22>/PackRSP' */

// PreAmpAudiopilotsetHVACSetting does not define a Response payload.

/// Response Payload Definition for PreAmpAudiopilotmuteReference
/// ----------------------------
/// @ingroup PreAmpAudiopilotmuteReference
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotmuteReference RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotmuteReference.
typedef struct
{
    uint32_t msgId;                // always RTCID_PreAmpAudiopilotmuteReference
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t muteReference;            // startChar:8 charSize:4
}
PreAmpAudiopilotmuteReference_RSP_T;   /* '<S61>/PackRSP' */

// PreAmpAudiopilotsetSpeedIn does not define a Response payload.

/// Response Payload Definition for PreAmpAudiopilotgetBassBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetBassBoost
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotgetBassBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetBassBoost.
typedef struct
{
    uint32_t msgId;                 // always RTCID_PreAmpAudiopilotgetBassBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    float bassBoost;                   // startChar:8 charSize:4
}
PreAmpAudiopilotgetBassBoost_RSP_T;    /* '<S91>/PackRSP' */

/// Response Payload Definition for PreAmpAudiopilotgetMidBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetMidBoost
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotgetMidBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetMidBoost.
typedef struct
{
    uint32_t msgId;                  // always RTCID_PreAmpAudiopilotgetMidBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    float midBoost;                    // startChar:8 charSize:4
}
PreAmpAudiopilotgetMidBoost_RSP_T;     /* '<S97>/PackRSP' */

/// Response Payload Definition for PreAmpAudiopilotgetTrebleBoost
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetTrebleBoost
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotgetTrebleBoost RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetTrebleBoost.
typedef struct
{
    uint32_t msgId;               // always RTCID_PreAmpAudiopilotgetTrebleBoost
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    float trebleBoost;                 // startChar:8 charSize:4
}
PreAmpAudiopilotgetTrebleBoost_RSP_T;  /* '<S103>/PackRSP' */

// PreAmpAudiopilotsetDynEQBoostOverRide does not define a Response payload.

// PreAmpAudiopilotsetVNCBassBoostOverRide does not define a Response payload.

// PreAmpAudiopilotsetVNCMidBoostOverRide does not define a Response payload.

// PreAmpAudiopilotsetVNCTrebleBoostOverRide does not define a Response payload.

// PreAmpAudiopilotsetLoudSignalOverRide does not define a Response payload.

// PreAmpAudiopilotsetVNCSignalOverRide does not define a Response payload.

/// Response Payload Definition for PreAmpAudiopilotgetAverageAudioPilotBoostLevel
/// ----------------------------
/// @ingroup PreAmpAudiopilotgetAverageAudioPilotBoostLevel
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotgetAverageAudioPilotBoostLevel RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotgetAverageAudioPilotBoostLevel.
typedef struct
{
    uint32_t msgId;
                  // always RTCID_PreAmpAudiopilotgetAverageAudioPilotBoostLevel
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    float level;                       // startChar:8 charSize:4
}
PreAmpAudiopilotgetAverageAudioPilotBoostLevel_RSP_T;/* '<S191>/PackRSP' */

// PreAmpAudiopilotsetHFNoiseOverRide does not define a Response payload.

// PreAmpAudiopilotsetLFNoiseOverRide does not define a Response payload.

// PreAmpAudiopilotsetRatioOverRide does not define a Response payload.

// PreAmpAudiopilotsetWBNoiseOverRide does not define a Response payload.

/// Response Payload Definition for PreAmpAudiopilotsetDyneqOn
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetDyneqOn
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotsetDyneqOn RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetDyneqOn.
typedef struct
{
    uint32_t msgId;                   // always RTCID_PreAmpAudiopilotsetDyneqOn
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t dyneq_on;                 // startChar:8 charSize:4
}
PreAmpAudiopilotsetDyneqOn_RSP_T;      /* '<S242>/PackRSP' */

/// Response Payload Definition for PreAmpAudiopilotsetAudioPilotOn
/// ----------------------------
/// @ingroup PreAmpAudiopilotsetAudioPilotOn
/// This page describes the payload format for Response messages
/// used by the PreAmpAudiopilotsetAudioPilotOn RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpAudiopilotsetAudioPilotOn.
typedef struct
{
    uint32_t msgId;              // always RTCID_PreAmpAudiopilotsetAudioPilotOn
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t audiopilot_on;            // startChar:8 charSize:4
}
PreAmpAudiopilotsetAudioPilotOn_RSP_T; /* '<S248>/PackRSP' */

/// Response Payload Definition for PreAmpVolumeCfgSet
/// ----------------------------
/// @ingroup PreAmpVolumeCfgSet
/// This page describes the payload format for Response messages
/// used by the PreAmpVolumeCfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpVolumeCfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpVolumeCfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpVolumeCfgSet_RSP_T;              /* '<S548>/PackRSP' */

/// Response Payload Definition for PreAmpBalance_CfgSet
/// ----------------------------
/// @ingroup PreAmpBalance_CfgSet
/// This page describes the payload format for Response messages
/// used by the PreAmpBalance_CfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBalance_CfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBalance_CfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpBalance_CfgSet_RSP_T;            /* '<S584>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaSurroundLevelControlIndex
/// ----------------------------
/// @ingroup PreAmpMedusaSurroundLevelControlIndex
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaSurroundLevelControlIndex RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaSurroundLevelControlIndex.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpMedusaSurroundLevelControlIndex
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t surround_index;           // startChar:8 charSize:4
}
PreAmpMedusaSurroundLevelControlIndex_RSP_T;/* '<S1122>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaSurroundLevelControlReset
/// ----------------------------
/// @ingroup PreAmpMedusaSurroundLevelControlReset
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaSurroundLevelControlReset RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaSurroundLevelControlReset.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpMedusaSurroundLevelControlReset
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpMedusaSurroundLevelControlReset_RSP_T;/* '<S1128>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaPostUpmixDisable
/// ----------------------------
/// @ingroup PreAmpMedusaPostUpmixDisable
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaPostUpmixDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaPostUpmixDisable.
typedef struct
{
    uint32_t msgId;                 // always RTCID_PreAmpMedusaPostUpmixDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpMedusaPostUpmixDisable_RSP_T;    /* '<S1186>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaHoligramDisable
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaHoligramDisable.
typedef struct
{
    uint32_t msgId;                  // always RTCID_PreAmpMedusaHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpMedusaHoligramDisable_RSP_T;     /* '<S1277>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaOverheadHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaOverheadHoligramDisable
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaOverheadHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaOverheadHoligramDisable.
typedef struct
{
    uint32_t msgId;          // always RTCID_PreAmpMedusaOverheadHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpMedusaOverheadHoligramDisable_RSP_T;/* '<S1289>/PackRSP' */

/// Response Payload Definition for PreAmpMedusaPostHoligramDisable
/// ----------------------------
/// @ingroup PreAmpMedusaPostHoligramDisable
/// This page describes the payload format for Response messages
/// used by the PreAmpMedusaPostHoligramDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaPostHoligramDisable.
typedef struct
{
    uint32_t msgId;              // always RTCID_PreAmpMedusaPostHoligramDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpMedusaPostHoligramDisable_RSP_T; /* '<S1327>/PackRSP' */

/// Response Payload Definition for PreAmpFadeControlSet
/// ----------------------------
/// @ingroup PreAmpFadeControlSet
/// This page describes the payload format for Response messages
/// used by the PreAmpFadeControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpFadeControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpFadeControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpFadeControlSet_RSP_T;            /* '<S1374>/PackRSP' */

/// Response Payload Definition for PreAmpMuteControlSet
/// ----------------------------
/// @ingroup PreAmpMuteControlSet
/// This page describes the payload format for Response messages
/// used by the PreAmpMuteControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMuteControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMuteControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
PreAmpMuteControlSet_RSP_T;            /* '<S1399>/PackRSP' */

/// Response Payload Definition for PreAmpResetSleepingBeauty
/// ----------------------------
/// @ingroup PreAmpResetSleepingBeauty
/// This page describes the payload format for Response messages
/// used by the PreAmpResetSleepingBeauty RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpResetSleepingBeauty.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpResetSleepingBeauty
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PreAmpResetSleepingBeauty_RSP_T;       /* '<S1431>/PackRSP' */

/// Response Payload Definition for PreAmpSleepingBeautyDRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyDRSet
/// This page describes the payload format for Response messages
/// used by the PreAmpSleepingBeautyDRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyDRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyDRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpSleepingBeautyDRSet_RSP_T;       /* '<S1451>/PackRSP' */

/// Response Payload Definition for PreAmpSleepingBeautyFRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyFRSet
/// This page describes the payload format for Response messages
/// used by the PreAmpSleepingBeautyFRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyFRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyFRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpSleepingBeautyFRSet_RSP_T;       /* '<S1471>/PackRSP' */

/// Response Payload Definition for PreAmpBassSet
/// ----------------------------
/// @ingroup PreAmpBassSet
/// This page describes the payload format for Response messages
/// used by the PreAmpBassSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBassSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBassSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpBassSet_RSP_T;                   /* '<S1544>/PackRSP' */

/// Response Payload Definition for PreAmpMidrangeSet
/// ----------------------------
/// @ingroup PreAmpMidrangeSet
/// This page describes the payload format for Response messages
/// used by the PreAmpMidrangeSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMidrangeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMidrangeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpMidrangeSet_RSP_T;               /* '<S1562>/PackRSP' */

/// Response Payload Definition for PreAmpTrebleSet
/// ----------------------------
/// @ingroup PreAmpTrebleSet
/// This page describes the payload format for Response messages
/// used by the PreAmpTrebleSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpTrebleSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpTrebleSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpTrebleSet_RSP_T;                 /* '<S1598>/PackRSP' */

/// Response Payload Definition for NearDr_RouterSet
/// ----------------------------
/// @ingroup NearDr_RouterSet
/// This page describes the payload format for Response messages
/// used by the NearDr_RouterSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearDr_RouterSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearDr_RouterSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    int32_t routerMap[18];             // startChar:8 charSize:72
}
NearDr_RouterSet_RSP_T;                /* '<S1663>/PackRSP' */

#define NearDr_RouterSet_RSP_routerMap_SIZE 18                   /* '<S1663>/PackRSP' */

/// Response Payload Definition for NearFr_RouterSet
/// ----------------------------
/// @ingroup NearFr_RouterSet
/// This page describes the payload format for Response messages
/// used by the NearFr_RouterSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearFr_RouterSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearFr_RouterSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    int32_t routerMap[18];             // startChar:8 charSize:72
}
NearFr_RouterSet_RSP_T;                /* '<S1721>/PackRSP' */

#define NearFr_RouterSet_RSP_routerMap_SIZE 18                   /* '<S1721>/PackRSP' */

/// Response Payload Definition for NearChannel2_Location
/// ----------------------------
/// @ingroup NearChannel2_Location
/// This page describes the payload format for Response messages
/// used by the NearChannel2_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel2_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel2_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
NearChannel2_Location_RSP_T;           /* '<S1744>/PackRSP' */

/// Response Payload Definition for NearChannel1_Location
/// ----------------------------
/// @ingroup NearChannel1_Location
/// This page describes the payload format for Response messages
/// used by the NearChannel1_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel1_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel1_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
NearChannel1_Location_RSP_T;           /* '<S1750>/PackRSP' */

/// Response Payload Definition for NearChannel4_Location
/// ----------------------------
/// @ingroup NearChannel4_Location
/// This page describes the payload format for Response messages
/// used by the NearChannel4_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel4_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel4_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
NearChannel4_Location_RSP_T;           /* '<S1756>/PackRSP' */

/// Response Payload Definition for NearChannel3_Location
/// ----------------------------
/// @ingroup NearChannel3_Location
/// This page describes the payload format for Response messages
/// used by the NearChannel3_Location RTC mechanism. For a more general
/// description of how this message works, see @ref NearChannel3_Location.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearChannel3_Location
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
NearChannel3_Location_RSP_T;           /* '<S1762>/PackRSP' */

// NearAnnNoiseLevel does not define a Response payload.

/// Response Payload Definition for NearAnn1Ann1NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn1Ann1NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Response messages
/// used by the NearAnn1Ann1NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn1Ann1NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t enable;                   // startChar:8 charSize:4
}
NearAnn1Ann1NonEntGainCalcvncEnableRTC_RSP_T;/* '<S1875>/PackRSP' */

/// Response Payload Definition for NearAnn1Ann1MuteSet
/// ----------------------------
/// @ingroup NearAnn1Ann1MuteSet
/// This page describes the payload format for Response messages
/// used by the NearAnn1Ann1MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn1Ann1MuteSet_RSP_T;             /* '<S1895>/PackRSP' */

/// Response Payload Definition for NearAnn1Ann1VolumeSet
/// ----------------------------
/// @ingroup NearAnn1Ann1VolumeSet
/// This page describes the payload format for Response messages
/// used by the NearAnn1Ann1VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn1Ann1VolumeSet_RSP_T;           /* '<S1923>/PackRSP' */

/// Response Payload Definition for NearAnn2Ann2NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn2Ann2NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Response messages
/// used by the NearAnn2Ann2NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn2Ann2NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t enable;                   // startChar:8 charSize:4
}
NearAnn2Ann2NonEntGainCalcvncEnableRTC_RSP_T;/* '<S1955>/PackRSP' */

/// Response Payload Definition for NearAnn2Ann2MuteSet
/// ----------------------------
/// @ingroup NearAnn2Ann2MuteSet
/// This page describes the payload format for Response messages
/// used by the NearAnn2Ann2MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn2Ann2MuteSet_RSP_T;             /* '<S1975>/PackRSP' */

/// Response Payload Definition for NearAnn2Ann2VolumeSet
/// ----------------------------
/// @ingroup NearAnn2Ann2VolumeSet
/// This page describes the payload format for Response messages
/// used by the NearAnn2Ann2VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn2Ann2VolumeSet_RSP_T;           /* '<S2003>/PackRSP' */

/// Response Payload Definition for NearAnn3Ann3NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn3Ann3NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Response messages
/// used by the NearAnn3Ann3NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn3Ann3NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t enable;                   // startChar:8 charSize:4
}
NearAnn3Ann3NonEntGainCalcvncEnableRTC_RSP_T;/* '<S2035>/PackRSP' */

/// Response Payload Definition for NearAnn3Ann3MuteSet
/// ----------------------------
/// @ingroup NearAnn3Ann3MuteSet
/// This page describes the payload format for Response messages
/// used by the NearAnn3Ann3MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn3Ann3MuteSet_RSP_T;             /* '<S2055>/PackRSP' */

/// Response Payload Definition for NearAnn3Ann3VolumeSet
/// ----------------------------
/// @ingroup NearAnn3Ann3VolumeSet
/// This page describes the payload format for Response messages
/// used by the NearAnn3Ann3VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn3Ann3VolumeSet_RSP_T;           /* '<S2083>/PackRSP' */

/// Response Payload Definition for NearAnn4Ann4NonEntGainCalcvncEnableRTC
/// ----------------------------
/// @ingroup NearAnn4Ann4NonEntGainCalcvncEnableRTC
/// This page describes the payload format for Response messages
/// used by the NearAnn4Ann4NonEntGainCalcvncEnableRTC RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4NonEntGainCalcvncEnableRTC.
typedef struct
{
    uint32_t msgId;       // always RTCID_NearAnn4Ann4NonEntGainCalcvncEnableRTC
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t enable;                   // startChar:8 charSize:4
}
NearAnn4Ann4NonEntGainCalcvncEnableRTC_RSP_T;/* '<S2115>/PackRSP' */

/// Response Payload Definition for NearAnn4Ann4MuteSet
/// ----------------------------
/// @ingroup NearAnn4Ann4MuteSet
/// This page describes the payload format for Response messages
/// used by the NearAnn4Ann4MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn4Ann4MuteSet_RSP_T;             /* '<S2135>/PackRSP' */

/// Response Payload Definition for NearAnn4Ann4VolumeSet
/// ----------------------------
/// @ingroup NearAnn4Ann4VolumeSet
/// This page describes the payload format for Response messages
/// used by the NearAnn4Ann4VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn4Ann4VolumeSet_RSP_T;           /* '<S2163>/PackRSP' */

/// Response Payload Definition for NearEnable
/// ----------------------------
/// @ingroup NearEnable
/// This page describes the payload format for Response messages
/// used by the NearEnable RTC mechanism. For a more general
/// description of how this message works, see @ref NearEnable.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearEnable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
NearEnable_RSP_T;                      /* '<S2177>/PackRSP' */

/// Response Payload Definition for PostProcessEnergyLimiterEnableLimiter
/// ----------------------------
/// @ingroup PostProcessEnergyLimiterEnableLimiter
/// This page describes the payload format for Response messages
/// used by the PostProcessEnergyLimiterEnableLimiter RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessEnergyLimiterEnableLimiter.
typedef struct
{
    uint32_t msgId;        // always RTCID_PostProcessEnergyLimiterEnableLimiter
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PostProcessEnergyLimiterEnableLimiter_RSP_T;/* '<S2215>/PackRSP' */

/// Response Payload Definition for PostProcessMuteSet
/// ----------------------------
/// @ingroup PostProcessMuteSet
/// This page describes the payload format for Response messages
/// used by the PostProcessMuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessMuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PostProcessMuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
PostProcessMuteSet_RSP_T;              /* '<S2230>/PackRSP' */

/// Response Payload Definition for PostProcessPostLimiterEqShutdown
/// ----------------------------
/// @ingroup PostProcessPostLimiterEqShutdown
/// This page describes the payload format for Response messages
/// used by the PostProcessPostLimiterEqShutdown RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessPostLimiterEqShutdown.
typedef struct
{
    uint32_t msgId;             // always RTCID_PostProcessPostLimiterEqShutdown
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
PostProcessPostLimiterEqShutdown_RSP_T;/* '<S2255>/PackRSP' */

/// Response Payload Definition for PostProcessLimiterSoftclipParamSet
/// ----------------------------
/// @ingroup PostProcessLimiterSoftclipParamSet
/// This page describes the payload format for Response messages
/// used by the PostProcessLimiterSoftclipParamSet RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessLimiterSoftclipParamSet.
typedef struct
{
    uint32_t msgId;           // always RTCID_PostProcessLimiterSoftclipParamSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t paramSet;                 // startChar:8 charSize:4
}
PostProcessLimiterSoftclipParamSet_RSP_T;/* '<S2261>/PackRSP' */

/// Response Payload Definition for PostProcessLimiterSoftclipDisable
/// ----------------------------
/// @ingroup PostProcessLimiterSoftclipDisable
/// This page describes the payload format for Response messages
/// used by the PostProcessLimiterSoftclipDisable RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessLimiterSoftclipDisable.
typedef struct
{
    uint32_t msgId;            // always RTCID_PostProcessLimiterSoftclipDisable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t disableMsg;               // startChar:8 charSize:4
}
PostProcessLimiterSoftclipDisable_RSP_T;/* '<S2267>/PackRSP' */

/// Response Payload Definition for TestRouterASDRouterAuxEnable
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxEnable
/// This page describes the payload format for Response messages
/// used by the TestRouterASDRouterAuxEnable RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxEnable.
typedef struct
{
    uint32_t msgId;                 // always RTCID_TestRouterASDRouterAuxEnable
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
TestRouterASDRouterAuxEnable_RSP_T;    /* '<S2288>/PackRSP' */

/// Response Payload Definition for TestRouterASDRouterAuxGain
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxGain
/// This page describes the payload format for Response messages
/// used by the TestRouterASDRouterAuxGain RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxGain.
typedef struct
{
    uint32_t msgId;                   // always RTCID_TestRouterASDRouterAuxGain
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
TestRouterASDRouterAuxGain_RSP_T;      /* '<S2294>/PackRSP' */

/// Response Payload Definition for TestRouterASDRouterAuxSelect
/// ----------------------------
/// @ingroup TestRouterASDRouterAuxSelect
/// This page describes the payload format for Response messages
/// used by the TestRouterASDRouterAuxSelect RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterAuxSelect.
typedef struct
{
    uint32_t msgId;                 // always RTCID_TestRouterASDRouterAuxSelect
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
TestRouterASDRouterAuxSelect_RSP_T;    /* '<S2300>/PackRSP' */

/// Response Payload Definition for TestRouterASDRouterMainGain
/// ----------------------------
/// @ingroup TestRouterASDRouterMainGain
/// This page describes the payload format for Response messages
/// used by the TestRouterASDRouterMainGain RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterMainGain.
typedef struct
{
    uint32_t msgId;                  // always RTCID_TestRouterASDRouterMainGain
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
TestRouterASDRouterMainGain_RSP_T;     /* '<S2312>/PackRSP' */

/// Response Payload Definition for TestRouterASDRouterMainSelect
/// ----------------------------
/// @ingroup TestRouterASDRouterMainSelect
/// This page describes the payload format for Response messages
/// used by the TestRouterASDRouterMainSelect RTC mechanism. For a more general
/// description of how this message works, see @ref TestRouterASDRouterMainSelect.
typedef struct
{
    uint32_t msgId;                // always RTCID_TestRouterASDRouterMainSelect
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
}
TestRouterASDRouterMainSelect_RSP_T;   /* '<S2318>/PackRSP' */

// ------------------------------------------------------------
// RTC NOTIFICATION PAYLOAD DEFINITIONS
// ------------------------------------------------------------

// InputSelectRouterCfgSet does not define a Notification payload.

// PreAmpAudiopilotsetHVACSetting does not define a Notification payload.

// PreAmpAudiopilotmuteReference does not define a Notification payload.

// PreAmpAudiopilotsetSpeedIn does not define a Notification payload.

// PreAmpAudiopilotgetBassBoost does not define a Notification payload.

// PreAmpAudiopilotgetMidBoost does not define a Notification payload.

// PreAmpAudiopilotgetTrebleBoost does not define a Notification payload.

// PreAmpAudiopilotsetDynEQBoostOverRide does not define a Notification payload.

// PreAmpAudiopilotsetVNCBassBoostOverRide does not define a Notification payload.

// PreAmpAudiopilotsetVNCMidBoostOverRide does not define a Notification payload.

// PreAmpAudiopilotsetVNCTrebleBoostOverRide does not define a Notification payload.

// PreAmpAudiopilotsetLoudSignalOverRide does not define a Notification payload.

// PreAmpAudiopilotsetVNCSignalOverRide does not define a Notification payload.

// PreAmpAudiopilotgetAverageAudioPilotBoostLevel does not define a Notification payload.

// PreAmpAudiopilotsetHFNoiseOverRide does not define a Notification payload.

// PreAmpAudiopilotsetLFNoiseOverRide does not define a Notification payload.

// PreAmpAudiopilotsetRatioOverRide does not define a Notification payload.

// PreAmpAudiopilotsetWBNoiseOverRide does not define a Notification payload.

// PreAmpAudiopilotsetDyneqOn does not define a Notification payload.

// PreAmpAudiopilotsetAudioPilotOn does not define a Notification payload.

/// Notification Payload Definition for PreAmpVolumeCfgSet
/// ----------------------------
/// @ingroup PreAmpVolumeCfgSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpVolumeCfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpVolumeCfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpVolumeCfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpVolumeCfgSet_NTF_T;              /* '<S543>/PackNTF' */

/// Notification Payload Definition for PreAmpBalance_CfgSet
/// ----------------------------
/// @ingroup PreAmpBalance_CfgSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpBalance_CfgSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBalance_CfgSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBalance_CfgSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpBalance_CfgSet_NTF_T;            /* '<S579>/PackNTF' */

/// Notification Payload Definition for PreAmpMedusaSurroundLevelControlIndex
/// ----------------------------
/// @ingroup PreAmpMedusaSurroundLevelControlIndex
/// This page describes the payload format for Notification messages
/// used by the PreAmpMedusaSurroundLevelControlIndex RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMedusaSurroundLevelControlIndex.
typedef struct
{
    uint32_t msgId;        // always RTCID_PreAmpMedusaSurroundLevelControlIndex
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t surround_index;           // startChar:8 charSize:4
}
PreAmpMedusaSurroundLevelControlIndex_NTF_T;/* '<S1117>/PackNTF' */

// PreAmpMedusaSurroundLevelControlReset does not define a Notification payload.

// PreAmpMedusaPostUpmixDisable does not define a Notification payload.

// PreAmpMedusaHoligramDisable does not define a Notification payload.

// PreAmpMedusaOverheadHoligramDisable does not define a Notification payload.

// PreAmpMedusaPostHoligramDisable does not define a Notification payload.

/// Notification Payload Definition for PreAmpFadeControlSet
/// ----------------------------
/// @ingroup PreAmpFadeControlSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpFadeControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpFadeControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpFadeControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpFadeControlSet_NTF_T;            /* '<S1369>/PackNTF' */

/// Notification Payload Definition for PreAmpMuteControlSet
/// ----------------------------
/// @ingroup PreAmpMuteControlSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpMuteControlSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMuteControlSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMuteControlSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
PreAmpMuteControlSet_NTF_T;            /* '<S1394>/PackNTF' */

// PreAmpResetSleepingBeauty does not define a Notification payload.

/// Notification Payload Definition for PreAmpSleepingBeautyDRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyDRSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpSleepingBeautyDRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyDRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyDRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpSleepingBeautyDRSet_NTF_T;       /* '<S1446>/PackNTF' */

/// Notification Payload Definition for PreAmpSleepingBeautyFRSet
/// ----------------------------
/// @ingroup PreAmpSleepingBeautyFRSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpSleepingBeautyFRSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpSleepingBeautyFRSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpSleepingBeautyFRSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpSleepingBeautyFRSet_NTF_T;       /* '<S1466>/PackNTF' */

/// Notification Payload Definition for PreAmpBassSet
/// ----------------------------
/// @ingroup PreAmpBassSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpBassSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpBassSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpBassSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpBassSet_NTF_T;                   /* '<S1539>/PackNTF' */

/// Notification Payload Definition for PreAmpMidrangeSet
/// ----------------------------
/// @ingroup PreAmpMidrangeSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpMidrangeSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpMidrangeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpMidrangeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpMidrangeSet_NTF_T;               /* '<S1557>/PackNTF' */

/// Notification Payload Definition for PreAmpTrebleSet
/// ----------------------------
/// @ingroup PreAmpTrebleSet
/// This page describes the payload format for Notification messages
/// used by the PreAmpTrebleSet RTC mechanism. For a more general
/// description of how this message works, see @ref PreAmpTrebleSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PreAmpTrebleSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
PreAmpTrebleSet_NTF_T;                 /* '<S1593>/PackNTF' */

// NearDr_RouterSet does not define a Notification payload.

// NearFr_RouterSet does not define a Notification payload.

// NearChannel2_Location does not define a Notification payload.

// NearChannel1_Location does not define a Notification payload.

// NearChannel4_Location does not define a Notification payload.

// NearChannel3_Location does not define a Notification payload.

// NearAnnNoiseLevel does not define a Notification payload.

// NearAnn1Ann1NonEntGainCalcvncEnableRTC does not define a Notification payload.

/// Notification Payload Definition for NearAnn1Ann1MuteSet
/// ----------------------------
/// @ingroup NearAnn1Ann1MuteSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn1Ann1MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn1Ann1MuteSet_NTF_T;             /* '<S1890>/PackNTF' */

/// Notification Payload Definition for NearAnn1Ann1VolumeSet
/// ----------------------------
/// @ingroup NearAnn1Ann1VolumeSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn1Ann1VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn1Ann1VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn1Ann1VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn1Ann1VolumeSet_NTF_T;           /* '<S1918>/PackNTF' */

// NearAnn2Ann2NonEntGainCalcvncEnableRTC does not define a Notification payload.

/// Notification Payload Definition for NearAnn2Ann2MuteSet
/// ----------------------------
/// @ingroup NearAnn2Ann2MuteSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn2Ann2MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn2Ann2MuteSet_NTF_T;             /* '<S1970>/PackNTF' */

/// Notification Payload Definition for NearAnn2Ann2VolumeSet
/// ----------------------------
/// @ingroup NearAnn2Ann2VolumeSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn2Ann2VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn2Ann2VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn2Ann2VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn2Ann2VolumeSet_NTF_T;           /* '<S1998>/PackNTF' */

// NearAnn3Ann3NonEntGainCalcvncEnableRTC does not define a Notification payload.

/// Notification Payload Definition for NearAnn3Ann3MuteSet
/// ----------------------------
/// @ingroup NearAnn3Ann3MuteSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn3Ann3MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn3Ann3MuteSet_NTF_T;             /* '<S2050>/PackNTF' */

/// Notification Payload Definition for NearAnn3Ann3VolumeSet
/// ----------------------------
/// @ingroup NearAnn3Ann3VolumeSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn3Ann3VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn3Ann3VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn3Ann3VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn3Ann3VolumeSet_NTF_T;           /* '<S2078>/PackNTF' */

// NearAnn4Ann4NonEntGainCalcvncEnableRTC does not define a Notification payload.

/// Notification Payload Definition for NearAnn4Ann4MuteSet
/// ----------------------------
/// @ingroup NearAnn4Ann4MuteSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn4Ann4MuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4MuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4MuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
NearAnn4Ann4MuteSet_NTF_T;             /* '<S2130>/PackNTF' */

/// Notification Payload Definition for NearAnn4Ann4VolumeSet
/// ----------------------------
/// @ingroup NearAnn4Ann4VolumeSet
/// This page describes the payload format for Notification messages
/// used by the NearAnn4Ann4VolumeSet RTC mechanism. For a more general
/// description of how this message works, see @ref NearAnn4Ann4VolumeSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_NearAnn4Ann4VolumeSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t gain_index;               // startChar:8 charSize:4
}
NearAnn4Ann4VolumeSet_NTF_T;           /* '<S2158>/PackNTF' */

// NearEnable does not define a Notification payload.

/// Notification Payload Definition for PostProcessEnergyLimiterEnableLimiter
/// ----------------------------
/// @ingroup PostProcessEnergyLimiterEnableLimiter
/// This page describes the payload format for Notification messages
/// used by the PostProcessEnergyLimiterEnableLimiter RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessEnergyLimiterEnableLimiter.
typedef struct
{
    uint32_t msgId;        // always RTCID_PostProcessEnergyLimiterEnableLimiter
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t ELNotification;           // startChar:8 charSize:4
}
PostProcessEnergyLimiterEnableLimiter_NTF_T;/* '<S2210>/PackNTF' */

/// Notification Payload Definition for PostProcessMuteSet
/// ----------------------------
/// @ingroup PostProcessMuteSet
/// This page describes the payload format for Notification messages
/// used by the PostProcessMuteSet RTC mechanism. For a more general
/// description of how this message works, see @ref PostProcessMuteSet.
typedef struct
{
    uint32_t msgId;                    // always RTCID_PostProcessMuteSet
    uint32_t caller_handle;            // startChar:0 charSize:4
    ASDSTATUS status_code;             // startChar:4 charSize:4
    uint32_t mute_switch;              // startChar:8 charSize:4
}
PostProcessMuteSet_NTF_T;              /* '<S2225>/PackNTF' */

// PostProcessPostLimiterEqShutdown does not define a Notification payload.

// PostProcessLimiterSoftclipParamSet does not define a Notification payload.

// PostProcessLimiterSoftclipDisable does not define a Notification payload.

// TestRouterASDRouterAuxEnable does not define a Notification payload.

// TestRouterASDRouterAuxGain does not define a Notification payload.

// TestRouterASDRouterAuxSelect does not define a Notification payload.

// TestRouterASDRouterMainGain does not define a Notification payload.

// TestRouterASDRouterMainSelect does not define a Notification payload.
#endif                                 /* RTW_HEADER_Model_Target_RTC_IDs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
