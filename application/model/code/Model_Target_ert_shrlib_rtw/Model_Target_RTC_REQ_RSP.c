/*
 * File: Model_Target_RTC_REQ_RSP.c
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
#include "Model_Target_RTC_IDs.h"
#include "Model_Target_RTC_REQ_RSP.h"
#include "ASDID.h"                     // for AsdIdStatus_type and other defines
#include "Model_Target_SCH_API.h"
#include "Model_Target_Partitions.h"   // for partition root

// ----- Function handler prototypes:
extern void RtcReqRsp_InputSelectRouterCfgSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotmuteReference(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetSpeedIn(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetHVACSetting(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetDynEQBoostOverRide(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetVNCTrebleBoostOverRide(void* pReqBuf,
    void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetLoudSignalOverRide(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetVNCSignalOverRide(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetLFNoiseOverRide(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetWBNoiseOverRide(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetHFNoiseOverRide(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetRatioOverRide(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetDyneqOn(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetAudioPilotOn(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetVNCBassBoostOverRide(void* pReqBuf,
    void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotgetBassBoost(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotsetVNCMidBoostOverRide(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotgetMidBoost(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotgetTrebleBoost(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpAudiopilotgetAverageAudioPilotBoostLevel(void
    * pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpVolumeCfgSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpBalance_CfgSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpMedusaSurroundLevelControlIndex(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PreAmpMedusaSurroundLevelControlReset(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PreAmpMedusaPostUpmixDisable(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpMedusaHoligramDisable(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpMedusaOverheadHoligramDisable(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpMedusaPostHoligramDisable(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PreAmpMuteControlSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpFadeControlSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpSleepingBeautyDRSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpSleepingBeautyFRSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpResetSleepingBeauty(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpBassSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpMidrangeSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PreAmpTrebleSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearFr_RouterSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn1Ann1VolumeSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn2Ann2VolumeSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn3Ann3VolumeSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn4Ann4VolumeSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn1Ann1NonEntGainCalcvncEnableRTC(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_NearAnn1Ann1MuteSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn2Ann2NonEntGainCalcvncEnableRTC(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_NearAnn2Ann2MuteSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn3Ann3NonEntGainCalcvncEnableRTC(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_NearAnn3Ann3MuteSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnn4Ann4NonEntGainCalcvncEnableRTC(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_NearAnn4Ann4MuteSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearAnnNoiseLevel(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearChannel1_Location(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearChannel2_Location(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearChannel3_Location(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearChannel4_Location(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearDr_RouterSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_NearEnable(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PostProcessMuteSet(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_PostProcessLimiterSoftclipParamSet(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PostProcessLimiterSoftclipDisable(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_PostProcessEnergyLimiterEnableLimiter(void* pReqBuf, void*
    pRspBuf);
extern void RtcReqRsp_PostProcessPostLimiterEqShutdown(void* pReqBuf, void
    * pRspBuf);
extern void RtcReqRsp_TestRouterASDRouterMainSelect(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_TestRouterASDRouterMainGain(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_TestRouterASDRouterAuxEnable(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_TestRouterASDRouterAuxSelect(void* pReqBuf, void* pRspBuf);
extern void RtcReqRsp_TestRouterASDRouterAuxGain(void* pReqBuf, void* pRspBuf);

// ----- RtcDispatchTable0000 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0000[] =
{
    // "InputSelectRouterCfgSet" request-response handler '<S15>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0000.0*/
        &RtcReqRsp_InputSelectRouterCfgSet,
        sizeof(InputSelectRouterCfgSet_REQ_T),/*28 char*/
        sizeof(InputSelectRouterCfgSet_RSP_T)/*32 char*/
    },
};

uint32_t RtcDispatchTable0000Count = sizeof(RtcDispatchTable0000)/sizeof
    (RtcDispatchTable0000[0]);

// ----- RtcDispatchTable0204 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0204[] =
{
    // "PreAmpAudiopilotgetAverageAudioPilotBoostLevel" request-response handler '<S107>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.0*/
        &RtcReqRsp_PreAmpAudiopilotgetAverageAudioPilotBoostLevel,
        sizeof(PreAmpAudiopilotgetAverageAudioPilotBoostLevel_REQ_T),/*8 char*/
        sizeof(PreAmpAudiopilotgetAverageAudioPilotBoostLevel_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotgetBassBoost" request-response handler '<S69>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.1*/
        &RtcReqRsp_PreAmpAudiopilotgetBassBoost,
        sizeof(PreAmpAudiopilotgetBassBoost_REQ_T),/*8 char*/
        sizeof(PreAmpAudiopilotgetBassBoost_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotgetMidBoost" request-response handler '<S70>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.2*/
        &RtcReqRsp_PreAmpAudiopilotgetMidBoost,
        sizeof(PreAmpAudiopilotgetMidBoost_REQ_T),/*8 char*/
        sizeof(PreAmpAudiopilotgetMidBoost_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotgetTrebleBoost" request-response handler '<S71>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.3*/
        &RtcReqRsp_PreAmpAudiopilotgetTrebleBoost,
        sizeof(PreAmpAudiopilotgetTrebleBoost_REQ_T),/*8 char*/
        sizeof(PreAmpAudiopilotgetTrebleBoost_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotmuteReference" request-response handler '<S44>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.4*/
        &RtcReqRsp_PreAmpAudiopilotmuteReference,
        sizeof(PreAmpAudiopilotmuteReference_REQ_T),/*12 char*/
        sizeof(PreAmpAudiopilotmuteReference_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotsetAudioPilotOn" request-response handler '<S233>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.5*/
        &RtcReqRsp_PreAmpAudiopilotsetAudioPilotOn,
        sizeof(PreAmpAudiopilotsetAudioPilotOn_REQ_T),/*12 char*/
        sizeof(PreAmpAudiopilotsetAudioPilotOn_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotsetDynEQBoostOverRide" request-response handler '<S142>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.6*/
        &RtcReqRsp_PreAmpAudiopilotsetDynEQBoostOverRide,
        sizeof(PreAmpAudiopilotsetDynEQBoostOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetDyneqOn" request-response handler '<S232>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.7*/
        &RtcReqRsp_PreAmpAudiopilotsetDyneqOn,
        sizeof(PreAmpAudiopilotsetDyneqOn_REQ_T),/*12 char*/
        sizeof(PreAmpAudiopilotsetDyneqOn_RSP_T)/*16 char*/
    },

    // "PreAmpAudiopilotsetHFNoiseOverRide" request-response handler '<S192>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.8*/
        &RtcReqRsp_PreAmpAudiopilotsetHFNoiseOverRide,
        sizeof(PreAmpAudiopilotsetHFNoiseOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetHVACSetting" request-response handler '<S48>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.9*/
        &RtcReqRsp_PreAmpAudiopilotsetHVACSetting,
        sizeof(PreAmpAudiopilotsetHVACSetting_REQ_T),/*8 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetLFNoiseOverRide" request-response handler '<S193>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.10*/
        &RtcReqRsp_PreAmpAudiopilotsetLFNoiseOverRide,
        sizeof(PreAmpAudiopilotsetLFNoiseOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetLoudSignalOverRide" request-response handler '<S171>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.11*/
        &RtcReqRsp_PreAmpAudiopilotsetLoudSignalOverRide,
        sizeof(PreAmpAudiopilotsetLoudSignalOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetRatioOverRide" request-response handler '<S195>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.12*/
        &RtcReqRsp_PreAmpAudiopilotsetRatioOverRide,
        sizeof(PreAmpAudiopilotsetRatioOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetSpeedIn" request-response handler '<S45>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.13*/
        &RtcReqRsp_PreAmpAudiopilotsetSpeedIn,
        sizeof(PreAmpAudiopilotsetSpeedIn_REQ_T),/*8 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetVNCBassBoostOverRide" request-response handler '<S143>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.14*/
        &RtcReqRsp_PreAmpAudiopilotsetVNCBassBoostOverRide,
        sizeof(PreAmpAudiopilotsetVNCBassBoostOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetVNCMidBoostOverRide" request-response handler '<S144>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.15*/
        &RtcReqRsp_PreAmpAudiopilotsetVNCMidBoostOverRide,
        sizeof(PreAmpAudiopilotsetVNCMidBoostOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetVNCSignalOverRide" request-response handler '<S173>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.16*/
        &RtcReqRsp_PreAmpAudiopilotsetVNCSignalOverRide,
        sizeof(PreAmpAudiopilotsetVNCSignalOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetVNCTrebleBoostOverRide" request-response handler '<S145>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.17*/
        &RtcReqRsp_PreAmpAudiopilotsetVNCTrebleBoostOverRide,
        sizeof(PreAmpAudiopilotsetVNCTrebleBoostOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpAudiopilotsetWBNoiseOverRide" request-response handler '<S196>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.18*/
        &RtcReqRsp_PreAmpAudiopilotsetWBNoiseOverRide,
        sizeof(PreAmpAudiopilotsetWBNoiseOverRide_REQ_T),/*12 char*/
        0                              /*0 char*/
    },

    // "PreAmpVolumeCfgSet" request-response handler '<S535>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0204.19*/
        &RtcReqRsp_PreAmpVolumeCfgSet,
        sizeof(PreAmpVolumeCfgSet_REQ_T),/*24 char*/
        sizeof(PreAmpVolumeCfgSet_RSP_T)/*16 char*/
    },
};

uint32_t RtcDispatchTable0204Count = sizeof(RtcDispatchTable0204)/sizeof
    (RtcDispatchTable0204[0]);

// ----- RtcDispatchTable0211 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0211[] =
{
    // "PreAmpBalance_CfgSet" request-response handler '<S564>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0211.0*/
        &RtcReqRsp_PreAmpBalance_CfgSet,
        sizeof(PreAmpBalance_CfgSet_REQ_T),/*20 char*/
        sizeof(PreAmpBalance_CfgSet_RSP_T)/*16 char*/
    },
};

uint32_t RtcDispatchTable0211Count = sizeof(RtcDispatchTable0211)/sizeof
    (RtcDispatchTable0211[0]);

// ----- RtcDispatchTable0205 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0205[] =
{
    // "PreAmpMedusaPostUpmixDisable" request-response handler '<S889>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0205.0*/
        &RtcReqRsp_PreAmpMedusaPostUpmixDisable,
        sizeof(PreAmpMedusaPostUpmixDisable_REQ_T),/*8 char*/
        sizeof(PreAmpMedusaPostUpmixDisable_RSP_T)/*12 char*/
    },

    // "PreAmpMedusaSurroundLevelControlIndex" request-response handler '<S1113>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0205.1*/
        &RtcReqRsp_PreAmpMedusaSurroundLevelControlIndex,
        sizeof(PreAmpMedusaSurroundLevelControlIndex_REQ_T),/*20 char*/
        sizeof(PreAmpMedusaSurroundLevelControlIndex_RSP_T)/*16 char*/
    },

    // "PreAmpMedusaSurroundLevelControlReset" request-response handler '<S1114>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0205.2*/
        &RtcReqRsp_PreAmpMedusaSurroundLevelControlReset,
        sizeof(PreAmpMedusaSurroundLevelControlReset_REQ_T),/*8 char*/
        sizeof(PreAmpMedusaSurroundLevelControlReset_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0205Count = sizeof(RtcDispatchTable0205)/sizeof
    (RtcDispatchTable0205[0]);

// ----- RtcDispatchTable0206 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0206[] =
{
    // "PreAmpMedusaHoligramDisable" request-response handler '<S1190>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0206.0*/
        &RtcReqRsp_PreAmpMedusaHoligramDisable,
        sizeof(PreAmpMedusaHoligramDisable_REQ_T),/*8 char*/
        sizeof(PreAmpMedusaHoligramDisable_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0206Count = sizeof(RtcDispatchTable0206)/sizeof
    (RtcDispatchTable0206[0]);

// ----- RtcDispatchTable0207 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0207[] =
{
    // "PreAmpMedusaOverheadHoligramDisable" request-response handler '<S1280>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0207.0*/
        &RtcReqRsp_PreAmpMedusaOverheadHoligramDisable,
        sizeof(PreAmpMedusaOverheadHoligramDisable_REQ_T),/*8 char*/
        sizeof(PreAmpMedusaOverheadHoligramDisable_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0207Count = sizeof(RtcDispatchTable0207)/sizeof
    (RtcDispatchTable0207[0]);

// ----- RtcDispatchTable0201 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0201[] =
{
    // "PreAmpMedusaPostHoligramDisable" request-response handler '<S1300>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0201.0*/
        &RtcReqRsp_PreAmpMedusaPostHoligramDisable,
        sizeof(PreAmpMedusaPostHoligramDisable_REQ_T),/*8 char*/
        sizeof(PreAmpMedusaPostHoligramDisable_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0201Count = sizeof(RtcDispatchTable0201)/sizeof
    (RtcDispatchTable0201[0]);

// ----- RtcDispatchTable0209 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0209[] =
{
    // "PreAmpFadeControlSet" request-response handler '<S1360>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0209.0*/
        &RtcReqRsp_PreAmpFadeControlSet,
        sizeof(PreAmpFadeControlSet_REQ_T),/*20 char*/
        sizeof(PreAmpFadeControlSet_RSP_T)/*16 char*/
    },

    // "PreAmpMuteControlSet" request-response handler '<S1390>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0209.1*/
        &RtcReqRsp_PreAmpMuteControlSet,
        sizeof(PreAmpMuteControlSet_REQ_T),/*20 char*/
        sizeof(PreAmpMuteControlSet_RSP_T)/*16 char*/
    },

    // "PreAmpResetSleepingBeauty" request-response handler '<S1354>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0209.2*/
        &RtcReqRsp_PreAmpResetSleepingBeauty,
        sizeof(PreAmpResetSleepingBeauty_REQ_T),/*8 char*/
        sizeof(PreAmpResetSleepingBeauty_RSP_T)/*12 char*/
    },

    // "PreAmpSleepingBeautyDRSet" request-response handler '<S1433>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0209.3*/
        &RtcReqRsp_PreAmpSleepingBeautyDRSet,
        sizeof(PreAmpSleepingBeautyDRSet_REQ_T),/*20 char*/
        sizeof(PreAmpSleepingBeautyDRSet_RSP_T)/*16 char*/
    },

    // "PreAmpSleepingBeautyFRSet" request-response handler '<S1453>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0209.4*/
        &RtcReqRsp_PreAmpSleepingBeautyFRSet,
        sizeof(PreAmpSleepingBeautyFRSet_REQ_T),/*20 char*/
        sizeof(PreAmpSleepingBeautyFRSet_RSP_T)/*16 char*/
    },
};

uint32_t RtcDispatchTable0209Count = sizeof(RtcDispatchTable0209)/sizeof
    (RtcDispatchTable0209[0]);

// ----- RtcDispatchTable0200 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0200[] =
{
    // "PreAmpBassSet" request-response handler '<S1527>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0200.0*/
        &RtcReqRsp_PreAmpBassSet,
        sizeof(PreAmpBassSet_REQ_T),   /*20 char*/
        sizeof(PreAmpBassSet_RSP_T)    /*16 char*/
    },

    // "PreAmpMidrangeSet" request-response handler '<S1545>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0200.1*/
        &RtcReqRsp_PreAmpMidrangeSet,
        sizeof(PreAmpMidrangeSet_REQ_T),/*20 char*/
        sizeof(PreAmpMidrangeSet_RSP_T)/*16 char*/
    },

    // "PreAmpTrebleSet" request-response handler '<S1581>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0200.2*/
        &RtcReqRsp_PreAmpTrebleSet,
        sizeof(PreAmpTrebleSet_REQ_T), /*20 char*/
        sizeof(PreAmpTrebleSet_RSP_T)  /*16 char*/
    },
};

uint32_t RtcDispatchTable0200Count = sizeof(RtcDispatchTable0200)/sizeof
    (RtcDispatchTable0200[0]);

// ----- RtcDispatchTable0100 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0100[] =
{
    // "NearAnn1Ann1MuteSet" request-response handler '<S1886>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.0*/
        &RtcReqRsp_NearAnn1Ann1MuteSet,
        sizeof(NearAnn1Ann1MuteSet_REQ_T),/*20 char*/
        sizeof(NearAnn1Ann1MuteSet_RSP_T)/*16 char*/
    },

    // "NearAnn1Ann1NonEntGainCalcvncEnableRTC" request-response handler '<S1857>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.1*/
        &RtcReqRsp_NearAnn1Ann1NonEntGainCalcvncEnableRTC,
        sizeof(NearAnn1Ann1NonEntGainCalcvncEnableRTC_REQ_T),/*12 char*/
        sizeof(NearAnn1Ann1NonEntGainCalcvncEnableRTC_RSP_T)/*16 char*/
    },

    // "NearAnn1Ann1VolumeSet" request-response handler '<S1908>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.2*/
        &RtcReqRsp_NearAnn1Ann1VolumeSet,
        sizeof(NearAnn1Ann1VolumeSet_REQ_T),/*20 char*/
        sizeof(NearAnn1Ann1VolumeSet_RSP_T)/*16 char*/
    },

    // "NearAnn2Ann2MuteSet" request-response handler '<S1966>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.3*/
        &RtcReqRsp_NearAnn2Ann2MuteSet,
        sizeof(NearAnn2Ann2MuteSet_REQ_T),/*20 char*/
        sizeof(NearAnn2Ann2MuteSet_RSP_T)/*16 char*/
    },

    // "NearAnn2Ann2NonEntGainCalcvncEnableRTC" request-response handler '<S1937>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.4*/
        &RtcReqRsp_NearAnn2Ann2NonEntGainCalcvncEnableRTC,
        sizeof(NearAnn2Ann2NonEntGainCalcvncEnableRTC_REQ_T),/*12 char*/
        sizeof(NearAnn2Ann2NonEntGainCalcvncEnableRTC_RSP_T)/*16 char*/
    },

    // "NearAnn2Ann2VolumeSet" request-response handler '<S1988>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.5*/
        &RtcReqRsp_NearAnn2Ann2VolumeSet,
        sizeof(NearAnn2Ann2VolumeSet_REQ_T),/*20 char*/
        sizeof(NearAnn2Ann2VolumeSet_RSP_T)/*16 char*/
    },

    // "NearAnn3Ann3MuteSet" request-response handler '<S2046>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.6*/
        &RtcReqRsp_NearAnn3Ann3MuteSet,
        sizeof(NearAnn3Ann3MuteSet_REQ_T),/*20 char*/
        sizeof(NearAnn3Ann3MuteSet_RSP_T)/*16 char*/
    },

    // "NearAnn3Ann3NonEntGainCalcvncEnableRTC" request-response handler '<S2017>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.7*/
        &RtcReqRsp_NearAnn3Ann3NonEntGainCalcvncEnableRTC,
        sizeof(NearAnn3Ann3NonEntGainCalcvncEnableRTC_REQ_T),/*12 char*/
        sizeof(NearAnn3Ann3NonEntGainCalcvncEnableRTC_RSP_T)/*16 char*/
    },

    // "NearAnn3Ann3VolumeSet" request-response handler '<S2068>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.8*/
        &RtcReqRsp_NearAnn3Ann3VolumeSet,
        sizeof(NearAnn3Ann3VolumeSet_REQ_T),/*20 char*/
        sizeof(NearAnn3Ann3VolumeSet_RSP_T)/*16 char*/
    },

    // "NearAnn4Ann4MuteSet" request-response handler '<S2126>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.9*/
        &RtcReqRsp_NearAnn4Ann4MuteSet,
        sizeof(NearAnn4Ann4MuteSet_REQ_T),/*20 char*/
        sizeof(NearAnn4Ann4MuteSet_RSP_T)/*16 char*/
    },

    // "NearAnn4Ann4NonEntGainCalcvncEnableRTC" request-response handler '<S2097>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.10*/
        &RtcReqRsp_NearAnn4Ann4NonEntGainCalcvncEnableRTC,
        sizeof(NearAnn4Ann4NonEntGainCalcvncEnableRTC_REQ_T),/*12 char*/
        sizeof(NearAnn4Ann4NonEntGainCalcvncEnableRTC_RSP_T)/*16 char*/
    },

    // "NearAnn4Ann4VolumeSet" request-response handler '<S2148>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.11*/
        &RtcReqRsp_NearAnn4Ann4VolumeSet,
        sizeof(NearAnn4Ann4VolumeSet_REQ_T),/*20 char*/
        sizeof(NearAnn4Ann4VolumeSet_RSP_T)/*16 char*/
    },

    // "NearAnnNoiseLevel" request-response handler '<S1784>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.12*/
        &RtcReqRsp_NearAnnNoiseLevel,
        sizeof(NearAnnNoiseLevel_REQ_T),/*8 char*/
        0                              /*0 char*/
    },

    // "NearChannel1_Location" request-response handler '<S1736>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.13*/
        &RtcReqRsp_NearChannel1_Location,
        sizeof(NearChannel1_Location_REQ_T),/*16 char*/
        sizeof(NearChannel1_Location_RSP_T)/*12 char*/
    },

    // "NearChannel2_Location" request-response handler '<S1735>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.14*/
        &RtcReqRsp_NearChannel2_Location,
        sizeof(NearChannel2_Location_REQ_T),/*16 char*/
        sizeof(NearChannel2_Location_RSP_T)/*12 char*/
    },

    // "NearChannel3_Location" request-response handler '<S1738>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.15*/
        &RtcReqRsp_NearChannel3_Location,
        sizeof(NearChannel3_Location_REQ_T),/*16 char*/
        sizeof(NearChannel3_Location_RSP_T)/*12 char*/
    },

    // "NearChannel4_Location" request-response handler '<S1737>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.16*/
        &RtcReqRsp_NearChannel4_Location,
        sizeof(NearChannel4_Location_REQ_T),/*16 char*/
        sizeof(NearChannel4_Location_RSP_T)/*12 char*/
    },

    // "NearDr_RouterSet" request-response handler '<S1656>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.17*/
        &RtcReqRsp_NearDr_RouterSet,
        sizeof(NearDr_RouterSet_REQ_T),/*80 char*/
        sizeof(NearDr_RouterSet_RSP_T) /*84 char*/
    },

    // "NearEnable" request-response handler '<S1604>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.18*/
        &RtcReqRsp_NearEnable,
        sizeof(NearEnable_REQ_T),      /*12 char*/
        sizeof(NearEnable_RSP_T)       /*12 char*/
    },

    // "NearFr_RouterSet" request-response handler '<S1714>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0100.19*/
        &RtcReqRsp_NearFr_RouterSet,
        sizeof(NearFr_RouterSet_REQ_T),/*80 char*/
        sizeof(NearFr_RouterSet_RSP_T) /*84 char*/
    },
};

uint32_t RtcDispatchTable0100Count = sizeof(RtcDispatchTable0100)/sizeof
    (RtcDispatchTable0100[0]);

// ----- RtcDispatchTable0300 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0300[] =
{
    // "PostProcessEnergyLimiterEnableLimiter" request-response handler '<S2191>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0300.0*/
        &RtcReqRsp_PostProcessEnergyLimiterEnableLimiter,
        sizeof(PostProcessEnergyLimiterEnableLimiter_REQ_T),/*12 char*/
        sizeof(PostProcessEnergyLimiterEnableLimiter_RSP_T)/*12 char*/
    },

    // "PostProcessLimiterSoftclipDisable" request-response handler '<S2186>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0300.1*/
        &RtcReqRsp_PostProcessLimiterSoftclipDisable,
        sizeof(PostProcessLimiterSoftclipDisable_REQ_T),/*12 char*/
        sizeof(PostProcessLimiterSoftclipDisable_RSP_T)/*16 char*/
    },

    // "PostProcessLimiterSoftclipParamSet" request-response handler '<S2185>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0300.2*/
        &RtcReqRsp_PostProcessLimiterSoftclipParamSet,
        sizeof(PostProcessLimiterSoftclipParamSet_REQ_T),/*12 char*/
        sizeof(PostProcessLimiterSoftclipParamSet_RSP_T)/*16 char*/
    },

    // "PostProcessMuteSet" request-response handler '<S2221>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0300.3*/
        &RtcReqRsp_PostProcessMuteSet,
        sizeof(PostProcessMuteSet_REQ_T),/*20 char*/
        sizeof(PostProcessMuteSet_RSP_T)/*16 char*/
    },

    // "PostProcessPostLimiterEqShutdown" request-response handler '<S2244>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0300.4*/
        &RtcReqRsp_PostProcessPostLimiterEqShutdown,
        sizeof(PostProcessPostLimiterEqShutdown_REQ_T),/*8 char*/
        sizeof(PostProcessPostLimiterEqShutdown_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0300Count = sizeof(RtcDispatchTable0300)/sizeof
    (RtcDispatchTable0300[0]);

// ----- RtcDispatchTable0500 DISPATCH TABLE -----:
Model_Target_RTC_REQ_RSP_type RtcDispatchTable0500[] =
{
    // "TestRouterASDRouterAuxEnable" request-response handler '<S2274>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0500.0*/
        &RtcReqRsp_TestRouterASDRouterAuxEnable,
        sizeof(TestRouterASDRouterAuxEnable_REQ_T),/*12 char*/
        sizeof(TestRouterASDRouterAuxEnable_RSP_T)/*12 char*/
    },

    // "TestRouterASDRouterAuxGain" request-response handler '<S2275>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0500.1*/
        &RtcReqRsp_TestRouterASDRouterAuxGain,
        sizeof(TestRouterASDRouterAuxGain_REQ_T),/*104 char*/
        sizeof(TestRouterASDRouterAuxGain_RSP_T)/*12 char*/
    },

    // "TestRouterASDRouterAuxSelect" request-response handler '<S2276>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0500.2*/
        &RtcReqRsp_TestRouterASDRouterAuxSelect,
        sizeof(TestRouterASDRouterAuxSelect_REQ_T),/*104 char*/
        sizeof(TestRouterASDRouterAuxSelect_RSP_T)/*12 char*/
    },

    // "TestRouterASDRouterMainGain" request-response handler '<S2278>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0500.3*/
        &RtcReqRsp_TestRouterASDRouterMainGain,
        sizeof(TestRouterASDRouterMainGain_REQ_T),/*104 char*/
        sizeof(TestRouterASDRouterMainGain_RSP_T)/*12 char*/
    },

    // "TestRouterASDRouterMainSelect" request-response handler '<S2279>/RTC Request Response Trigger':
    {                                  /*Index RtcDispatchTable0500.4*/
        &RtcReqRsp_TestRouterASDRouterMainSelect,
        sizeof(TestRouterASDRouterMainSelect_REQ_T),/*104 char*/
        sizeof(TestRouterASDRouterMainSelect_RSP_T)/*12 char*/
    },
};

uint32_t RtcDispatchTable0500Count = sizeof(RtcDispatchTable0500)/sizeof
    (RtcDispatchTable0500[0]);

/** Handle Run Time Control request (RTC) and generate response payload (if any).
 * NOTE: This function integrates with HandleAsdIdRequest. It is not intended
 * to be called directly if @ref HandleAsdIdRequest is more convenient.
 *  @param pReqBuf Request buffer containing RTC request*  @param reqBufSize number of bytes used in the request buffer
 *  @param pRspBuf Response buffer to receive response of AsdIdStatus_type*  @param rspBufSize Size of available bytes provided for the response to fill
 *  @return Returns the toal number of bytes utilized in the response buffer, or
 *          ASDSTATUS_RSP_BUFFER_SMALL if the response buffer is too small to
 *          contain a AsdIdStatus_type payload. If the returned value is positive,
 *          the caller must check the AsdIdStatus_type's statusCode. If the
 *          status code is less than zero, then any further reponse "data" as
 *          defined by the RTC service will not be present (i.e. there probably
 *          was not space for it anyway).
 *
 * @ingroup rtc
 */
int Model_Target_HandleRtcRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize)
{
    // Gain access to the appropriate command table
    uint32_t msgId = ((uint32_t*)pReqBuf)[0];
    Model_Target_RTC_REQ_RSP_type* theTable = 0;
    uint32_t tableSize = 0;
    uint32_t rtcPartition = ASDID_PARTITION(msgId);
    uint32_t rtcGroup = ASDID_GROUP(msgId);
    PartitionRoot_type* partitionRoot = GetPartitionRoot(rtcGroup,rtcPartition);
    if (partitionRoot && partitionRoot->rtcTable && partitionRoot->rtcCount)
    {
        theTable = (Model_Target_RTC_REQ_RSP_type*)partitionRoot->rtcTable;
        tableSize = *partitionRoot->rtcCount;
    }

    return Model_Target_UseDispatchTable(pReqBuf,reqBufSize,pRspBuf,rspBufSize,
        theTable,tableSize);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
