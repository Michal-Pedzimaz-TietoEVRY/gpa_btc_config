/*
 * File: Model_Target_RTC_doxygen.h
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

#ifndef RTW_HEADER_Model_Target_RTC_doxygen_h_
#define RTW_HEADER_Model_Target_RTC_doxygen_h_

// ------------------------------------------------------------
// RUNTIME CONTROL MESSAGING SUMMARY
// ------------------------------------------------------------
/** @defgroup rtc Runtime Control (RTC)
 * The Runtime Control mechanism (RTC) supports communication with DSP algorithms.
 * For a list of the RTC messages, see the @ref rtc_messages.
 * Algorithm developers can define three types of payloads for each message as
 * described below.
 * Requests     (Control >>> DSP):
 * ---------
 *  RTC communication always begins with a request sent to the DSP algorithm
 *  code. RTC requests include a message ID and an accompanying data values
 *  (if any) as defined by the DSP algorithmic code.
 *  Request messages signal one of the following actions:
 *  - Initiate an action to take (e.g. mute the audio)
 *  - Update a state value (e.g. engine speed is now "0")
 *
 * Responses     (DSP >>> Control):
 * ---------
 *  Each RTC message definition has the option to include responses or not.
 *  If responses are defined for a message, then EVERY request receives a response.
 *  Note the following characteristics about response payloads:
 *  - They are generated immediately upon receipt of request
 *  - They contain the same RTCID as their matching request along with any
 *    additional information (if any) as defined for the message.
 *  - If a notification payload is also defined, the response will also
 *    contain a sequence tracking number to be referenced by the notification.
 *
 * Notifications (DSP >>> Control):
 * -------------
 *  Notification definitions are optional and only available if a response
 *  is also defined. A notification usually indicates that a request has finally
 *  been satisfied.
 *  Note the following characteristics about notification payloads:
 *  - They are generated at some time later after request is received
 *  - They reference the same RTCID as their matching request and response
 *  - They also reference the sequence number previously reported by
 *    an earlier response.
 *  - If a second request comes in before the first request generates a
 *    the first request may never generate a notification. In other words,
 *    only the "last request" is guaranteed to receive a notification.
 */

/** Setup for Doxygen RTC Service Table
   @defgroup rtc_messages RTC Message Index
   @ingroup rtc
   | Message | Message ID | Request | Response| Notification |
   |---------|------------|---------|---------|--------------|
   | @ref InputSelectRouterCfgSet | 0x10010000 | @ref InputSelectRouterCfgSet_REQ | @ref InputSelectRouterCfgSet_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref GetTalariaVersion1 | 0x10f70000 | @ref GetTalariaVersion1_REQ | @ref GetTalariaVersion1_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref GetTopCompatHash1 | 0x10f70001 | @ref GetTopCompatHash1_REQ | @ref GetTopCompatHash1_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref GetTspCompatHash1 | 0x10f70002 | @ref GetTspCompatHash1_REQ | @ref GetTspCompatHash1_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref GetRtcCompatHash1 | 0x10f70003 | @ref GetRtcCompatHash1_REQ | @ref GetRtcCompatHash1_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotmuteReference | 0x14210004 | @ref PreAmpAudiopilotmuteReference_REQ | @ref PreAmpAudiopilotmuteReference_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetSpeedIn | 0x1422000d | @ref PreAmpAudiopilotsetSpeedIn_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetHVACSetting | 0x14220009 | @ref PreAmpAudiopilotsetHVACSetting_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetDynEQBoostOverRide | 0x14220006 | @ref PreAmpAudiopilotsetDynEQBoostOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetVNCTrebleBoostOverRide | 0x14220011 | @ref PreAmpAudiopilotsetVNCTrebleBoostOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetLoudSignalOverRide | 0x1422000b | @ref PreAmpAudiopilotsetLoudSignalOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetVNCSignalOverRide | 0x14220010 | @ref PreAmpAudiopilotsetVNCSignalOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetLFNoiseOverRide | 0x1422000a | @ref PreAmpAudiopilotsetLFNoiseOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetWBNoiseOverRide | 0x14220012 | @ref PreAmpAudiopilotsetWBNoiseOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetHFNoiseOverRide | 0x14220008 | @ref PreAmpAudiopilotsetHFNoiseOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetRatioOverRide | 0x1422000c | @ref PreAmpAudiopilotsetRatioOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetDyneqOn | 0x14210007 | @ref PreAmpAudiopilotsetDyneqOn_REQ | @ref PreAmpAudiopilotsetDyneqOn_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetAudioPilotOn | 0x14210005 | @ref PreAmpAudiopilotsetAudioPilotOn_REQ | @ref PreAmpAudiopilotsetAudioPilotOn_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetVNCBassBoostOverRide | 0x1422000e | @ref PreAmpAudiopilotsetVNCBassBoostOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotgetBassBoost | 0x14210001 | @ref PreAmpAudiopilotgetBassBoost_REQ | @ref PreAmpAudiopilotgetBassBoost_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotsetVNCMidBoostOverRide | 0x1422000f | @ref PreAmpAudiopilotsetVNCMidBoostOverRide_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotgetMidBoost | 0x14210002 | @ref PreAmpAudiopilotgetMidBoost_REQ | @ref PreAmpAudiopilotgetMidBoost_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotgetTrebleBoost | 0x14210003 | @ref PreAmpAudiopilotgetTrebleBoost_REQ | @ref PreAmpAudiopilotgetTrebleBoost_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpAudiopilotgetAverageAudioPilotBoostLevel | 0x14210000 | @ref PreAmpAudiopilotgetAverageAudioPilotBoostLevel_REQ | @ref PreAmpAudiopilotgetAverageAudioPilotBoostLevel_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpVolumeCfgSet | 0x14200013 | @ref PreAmpVolumeCfgSet_REQ | @ref PreAmpVolumeCfgSet_RSP | @ref PreAmpVolumeCfgSet_NTF |
   | @ref PreAmpBalance_CfgSet | 0x1b200000 | @ref PreAmpBalance_CfgSet_REQ | @ref PreAmpBalance_CfgSet_RSP | @ref PreAmpBalance_CfgSet_NTF |
   | @ref PreAmpMedusaSurroundLevelControlIndex | 0x15200001 | @ref PreAmpMedusaSurroundLevelControlIndex_REQ | @ref PreAmpMedusaSurroundLevelControlIndex_RSP | @ref PreAmpMedusaSurroundLevelControlIndex_NTF |
   | @ref PreAmpMedusaSurroundLevelControlReset | 0x15210002 | @ref PreAmpMedusaSurroundLevelControlReset_REQ | @ref PreAmpMedusaSurroundLevelControlReset_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpMedusaPostUpmixDisable | 0x15210000 | @ref PreAmpMedusaPostUpmixDisable_REQ | @ref PreAmpMedusaPostUpmixDisable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpMedusaHoligramDisable | 0x16210000 | @ref PreAmpMedusaHoligramDisable_REQ | @ref PreAmpMedusaHoligramDisable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpMedusaOverheadHoligramDisable | 0x17210000 | @ref PreAmpMedusaOverheadHoligramDisable_REQ | @ref PreAmpMedusaOverheadHoligramDisable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpMedusaPostHoligramDisable | 0x11210000 | @ref PreAmpMedusaPostHoligramDisable_REQ | @ref PreAmpMedusaPostHoligramDisable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpMuteControlSet | 0x19200001 | @ref PreAmpMuteControlSet_REQ | @ref PreAmpMuteControlSet_RSP | @ref PreAmpMuteControlSet_NTF |
   | @ref PreAmpFadeControlSet | 0x19200000 | @ref PreAmpFadeControlSet_REQ | @ref PreAmpFadeControlSet_RSP | @ref PreAmpFadeControlSet_NTF |
   | @ref PreAmpSleepingBeautyDRSet | 0x19200003 | @ref PreAmpSleepingBeautyDRSet_REQ | @ref PreAmpSleepingBeautyDRSet_RSP | @ref PreAmpSleepingBeautyDRSet_NTF |
   | @ref PreAmpSleepingBeautyFRSet | 0x19200004 | @ref PreAmpSleepingBeautyFRSet_REQ | @ref PreAmpSleepingBeautyFRSet_RSP | @ref PreAmpSleepingBeautyFRSet_NTF |
   | @ref PreAmpResetSleepingBeauty | 0x19210002 | @ref PreAmpResetSleepingBeauty_REQ | @ref PreAmpResetSleepingBeauty_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PreAmpBassSet | 0x10200000 | @ref PreAmpBassSet_REQ | @ref PreAmpBassSet_RSP | @ref PreAmpBassSet_NTF |
   | @ref PreAmpMidrangeSet | 0x10200001 | @ref PreAmpMidrangeSet_REQ | @ref PreAmpMidrangeSet_RSP | @ref PreAmpMidrangeSet_NTF |
   | @ref PreAmpTrebleSet | 0x10200002 | @ref PreAmpTrebleSet_REQ | @ref PreAmpTrebleSet_RSP | @ref PreAmpTrebleSet_NTF |
   | @ref NearFr_RouterSet | 0x10110013 | @ref NearFr_RouterSet_REQ | @ref NearFr_RouterSet_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearAnn1Ann1VolumeSet | 0x10100002 | @ref NearAnn1Ann1VolumeSet_REQ | @ref NearAnn1Ann1VolumeSet_RSP | @ref NearAnn1Ann1VolumeSet_NTF |
   | @ref NearAnn2Ann2VolumeSet | 0x10100005 | @ref NearAnn2Ann2VolumeSet_REQ | @ref NearAnn2Ann2VolumeSet_RSP | @ref NearAnn2Ann2VolumeSet_NTF |
   | @ref NearAnn3Ann3VolumeSet | 0x10100008 | @ref NearAnn3Ann3VolumeSet_REQ | @ref NearAnn3Ann3VolumeSet_RSP | @ref NearAnn3Ann3VolumeSet_NTF |
   | @ref NearAnn4Ann4VolumeSet | 0x1010000b | @ref NearAnn4Ann4VolumeSet_REQ | @ref NearAnn4Ann4VolumeSet_RSP | @ref NearAnn4Ann4VolumeSet_NTF |
   | @ref NearAnn1Ann1NonEntGainCalcvncEnableRTC | 0x10110001 | @ref NearAnn1Ann1NonEntGainCalcvncEnableRTC_REQ | @ref NearAnn1Ann1NonEntGainCalcvncEnableRTC_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearAnn1Ann1MuteSet | 0x10100000 | @ref NearAnn1Ann1MuteSet_REQ | @ref NearAnn1Ann1MuteSet_RSP | @ref NearAnn1Ann1MuteSet_NTF |
   | @ref NearAnn2Ann2NonEntGainCalcvncEnableRTC | 0x10110004 | @ref NearAnn2Ann2NonEntGainCalcvncEnableRTC_REQ | @ref NearAnn2Ann2NonEntGainCalcvncEnableRTC_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearAnn2Ann2MuteSet | 0x10100003 | @ref NearAnn2Ann2MuteSet_REQ | @ref NearAnn2Ann2MuteSet_RSP | @ref NearAnn2Ann2MuteSet_NTF |
   | @ref NearAnn3Ann3NonEntGainCalcvncEnableRTC | 0x10110007 | @ref NearAnn3Ann3NonEntGainCalcvncEnableRTC_REQ | @ref NearAnn3Ann3NonEntGainCalcvncEnableRTC_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearAnn3Ann3MuteSet | 0x10100006 | @ref NearAnn3Ann3MuteSet_REQ | @ref NearAnn3Ann3MuteSet_RSP | @ref NearAnn3Ann3MuteSet_NTF |
   | @ref NearAnn4Ann4NonEntGainCalcvncEnableRTC | 0x1011000a | @ref NearAnn4Ann4NonEntGainCalcvncEnableRTC_REQ | @ref NearAnn4Ann4NonEntGainCalcvncEnableRTC_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearAnn4Ann4MuteSet | 0x10100009 | @ref NearAnn4Ann4MuteSet_REQ | @ref NearAnn4Ann4MuteSet_RSP | @ref NearAnn4Ann4MuteSet_NTF |
   | @ref NearAnnNoiseLevel | 0x1012000c | @ref NearAnnNoiseLevel_REQ | <CENTER><EM>n/a</CENTER></EM> | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearChannel1_Location | 0x1011000d | @ref NearChannel1_Location_REQ | @ref NearChannel1_Location_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearChannel2_Location | 0x1011000e | @ref NearChannel2_Location_REQ | @ref NearChannel2_Location_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearChannel3_Location | 0x1011000f | @ref NearChannel3_Location_REQ | @ref NearChannel3_Location_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearChannel4_Location | 0x10110010 | @ref NearChannel4_Location_REQ | @ref NearChannel4_Location_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearDr_RouterSet | 0x10110011 | @ref NearDr_RouterSet_REQ | @ref NearDr_RouterSet_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref NearEnable | 0x10110012 | @ref NearEnable_REQ | @ref NearEnable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PostProcessMuteSet | 0x10300003 | @ref PostProcessMuteSet_REQ | @ref PostProcessMuteSet_RSP | @ref PostProcessMuteSet_NTF |
   | @ref PostProcessLimiterSoftclipParamSet | 0x10310002 | @ref PostProcessLimiterSoftclipParamSet_REQ | @ref PostProcessLimiterSoftclipParamSet_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PostProcessLimiterSoftclipDisable | 0x10310001 | @ref PostProcessLimiterSoftclipDisable_REQ | @ref PostProcessLimiterSoftclipDisable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref PostProcessEnergyLimiterEnableLimiter | 0x10300000 | @ref PostProcessEnergyLimiterEnableLimiter_REQ | @ref PostProcessEnergyLimiterEnableLimiter_RSP | @ref PostProcessEnergyLimiterEnableLimiter_NTF |
   | @ref PostProcessPostLimiterEqShutdown | 0x10310004 | @ref PostProcessPostLimiterEqShutdown_REQ | @ref PostProcessPostLimiterEqShutdown_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref TestRouterASDRouterMainSelect | 0x10510004 | @ref TestRouterASDRouterMainSelect_REQ | @ref TestRouterASDRouterMainSelect_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref TestRouterASDRouterMainGain | 0x10510003 | @ref TestRouterASDRouterMainGain_REQ | @ref TestRouterASDRouterMainGain_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref TestRouterASDRouterAuxEnable | 0x10510000 | @ref TestRouterASDRouterAuxEnable_REQ | @ref TestRouterASDRouterAuxEnable_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref TestRouterASDRouterAuxSelect | 0x10510002 | @ref TestRouterASDRouterAuxSelect_REQ | @ref TestRouterASDRouterAuxSelect_RSP | <CENTER><EM>n/a</CENTER></EM> |
   | @ref TestRouterASDRouterAuxGain | 0x10510001 | @ref TestRouterASDRouterAuxGain_REQ | @ref TestRouterASDRouterAuxGain_RSP | <CENTER><EM>n/a</CENTER></EM> |
 */

/**
   @defgroup InputSelectRouterCfgSet
   @ingroup rtc_messages
   No further description of InputSelectRouterCfgSet has been defined yet.
 */
/**
   @defgroup GetTalariaVersion1
   @ingroup rtc_messages
   GetTalariaVersion1
   ==============
   Get Talaria Version String e.g. V2100AE
 */
/**
   @defgroup GetTopCompatHash1
   @ingroup rtc_messages
   GetTopCompatHash1
   ==============
   Get TOP compatibility hash based on module name hash
 */
/**
   @defgroup GetTspCompatHash1
   @ingroup rtc_messages
   GetTspCompatHash1
   ==============
   Get TSP compatibility hash based on module name hash
 */
/**
   @defgroup GetRtcCompatHash1
   @ingroup rtc_messages
   GetRtcCompatHash1
   ==============
   Get RTC compatibility hash based on module name hash
 */
/**
   @defgroup PreAmpAudiopilotmuteReference
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotmuteReference has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetSpeedIn
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetSpeedIn has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetHVACSetting
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetHVACSetting has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetDynEQBoostOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetDynEQBoostOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetVNCTrebleBoostOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetVNCTrebleBoostOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetLoudSignalOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetLoudSignalOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetVNCSignalOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetVNCSignalOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetLFNoiseOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetLFNoiseOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetWBNoiseOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetWBNoiseOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetHFNoiseOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetHFNoiseOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetRatioOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetRatioOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetDyneqOn
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetDyneqOn has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetAudioPilotOn
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetAudioPilotOn has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetVNCBassBoostOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetVNCBassBoostOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotgetBassBoost
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotgetBassBoost has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotsetVNCMidBoostOverRide
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotsetVNCMidBoostOverRide has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotgetMidBoost
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotgetMidBoost has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotgetTrebleBoost
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotgetTrebleBoost has been defined yet.
 */
/**
   @defgroup PreAmpAudiopilotgetAverageAudioPilotBoostLevel
   @ingroup rtc_messages
   No further description of PreAmpAudiopilotgetAverageAudioPilotBoostLevel has been defined yet.
 */
/**
   @defgroup PreAmpVolumeCfgSet
   @ingroup rtc_messages
   PreAmpVolumeCfgSet
   ==============
   Sets new target volume.
   Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup PreAmpBalance_CfgSet
   @ingroup rtc_messages
   No further description of PreAmpBalance_CfgSet has been defined yet.
 */
/**
   @defgroup PreAmpMedusaSurroundLevelControlIndex
   @ingroup rtc_messages
   PreAmpMedusaSurroundLevelControlIndex
   ==============
   Contains the value indicated by the surround knob.
 */
/**
   @defgroup PreAmpMedusaSurroundLevelControlReset
   @ingroup rtc_messages
   No further description of PreAmpMedusaSurroundLevelControlReset has been defined yet.
 */
/**
   @defgroup PreAmpMedusaPostUpmixDisable
   @ingroup rtc_messages
   No further description of PreAmpMedusaPostUpmixDisable has been defined yet.
 */
/**
   @defgroup PreAmpMedusaHoligramDisable
   @ingroup rtc_messages
   No further description of PreAmpMedusaHoligramDisable has been defined yet.
 */
/**
   @defgroup PreAmpMedusaOverheadHoligramDisable
   @ingroup rtc_messages
   No further description of PreAmpMedusaOverheadHoligramDisable has been defined yet.
 */
/**
   @defgroup PreAmpMedusaPostHoligramDisable
   @ingroup rtc_messages
   No further description of PreAmpMedusaPostHoligramDisable has been defined yet.
 */
/**
   @defgroup PreAmpMuteControlSet
   @ingroup rtc_messages
   PreAmpMuteControlSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup PreAmpFadeControlSet
   @ingroup rtc_messages
   PreAmpFadeControlSet
   ==============
   Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup PreAmpSleepingBeautyDRSet
   @ingroup rtc_messages
   No further description of PreAmpSleepingBeautyDRSet has been defined yet.
 */
/**
   @defgroup PreAmpSleepingBeautyFRSet
   @ingroup rtc_messages
   No further description of PreAmpSleepingBeautyFRSet has been defined yet.
 */
/**
   @defgroup PreAmpResetSleepingBeauty
   @ingroup rtc_messages
   No further description of PreAmpResetSleepingBeauty has been defined yet.
 */
/**
   @defgroup PreAmpBassSet
   @ingroup rtc_messages
   PreAmpBassSet
   ==============
   Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup PreAmpMidrangeSet
   @ingroup rtc_messages
   No further description of PreAmpMidrangeSet has been defined yet.
 */
/**
   @defgroup PreAmpTrebleSet
   @ingroup rtc_messages
   PreAmpTrebleSet
   ==============
   Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup NearFr_RouterSet
   @ingroup rtc_messages
   No further description of NearFr_RouterSet has been defined yet.
 */
/**
   @defgroup NearAnn1Ann1VolumeSet
   @ingroup rtc_messages
   NearAnn1Ann1VolumeSet
   ==============
   Sets new target volume.
   Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup NearAnn2Ann2VolumeSet
   @ingroup rtc_messages
   NearAnn2Ann2VolumeSet
   ==============
   Sets new target volume.
   Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup NearAnn3Ann3VolumeSet
   @ingroup rtc_messages
   NearAnn3Ann3VolumeSet
   ==============
   Sets new target volume.
   Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup NearAnn4Ann4VolumeSet
   @ingroup rtc_messages
   NearAnn4Ann4VolumeSet
   ==============
   Sets new target volume.
   Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.

   To use slope-based ramping:
   ----------------------------------
   When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.

   To use time-based ramping:
   ----------------------------------
   The value of db_per_second must be zero for ramp milliseconds to then control the ramping.
 */
/**
   @defgroup NearAnn1Ann1NonEntGainCalcvncEnableRTC
   @ingroup rtc_messages
   No further description of NearAnn1Ann1NonEntGainCalcvncEnableRTC has been defined yet.
 */
/**
   @defgroup NearAnn1Ann1MuteSet
   @ingroup rtc_messages
   NearAnn1Ann1MuteSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup NearAnn2Ann2NonEntGainCalcvncEnableRTC
   @ingroup rtc_messages
   No further description of NearAnn2Ann2NonEntGainCalcvncEnableRTC has been defined yet.
 */
/**
   @defgroup NearAnn2Ann2MuteSet
   @ingroup rtc_messages
   NearAnn2Ann2MuteSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup NearAnn3Ann3NonEntGainCalcvncEnableRTC
   @ingroup rtc_messages
   No further description of NearAnn3Ann3NonEntGainCalcvncEnableRTC has been defined yet.
 */
/**
   @defgroup NearAnn3Ann3MuteSet
   @ingroup rtc_messages
   NearAnn3Ann3MuteSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup NearAnn4Ann4NonEntGainCalcvncEnableRTC
   @ingroup rtc_messages
   No further description of NearAnn4Ann4NonEntGainCalcvncEnableRTC has been defined yet.
 */
/**
   @defgroup NearAnn4Ann4MuteSet
   @ingroup rtc_messages
   NearAnn4Ann4MuteSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup NearAnnNoiseLevel
   @ingroup rtc_messages
   No further description of NearAnnNoiseLevel has been defined yet.
 */
/**
   @defgroup NearChannel1_Location
   @ingroup rtc_messages
   No further description of NearChannel1_Location has been defined yet.
 */
/**
   @defgroup NearChannel2_Location
   @ingroup rtc_messages
   No further description of NearChannel2_Location has been defined yet.
 */
/**
   @defgroup NearChannel3_Location
   @ingroup rtc_messages
   No further description of NearChannel3_Location has been defined yet.
 */
/**
   @defgroup NearChannel4_Location
   @ingroup rtc_messages
   No further description of NearChannel4_Location has been defined yet.
 */
/**
   @defgroup NearDr_RouterSet
   @ingroup rtc_messages
   No further description of NearDr_RouterSet has been defined yet.
 */
/**
   @defgroup NearEnable
   @ingroup rtc_messages
   No further description of NearEnable has been defined yet.
 */
/**
   @defgroup PostProcessMuteSet
   @ingroup rtc_messages
   PostProcessMuteSet
   ==============
   Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.
 */
/**
   @defgroup PostProcessLimiterSoftclipParamSet
   @ingroup rtc_messages
   PostProcessLimiterSoftclipParamSet
   ==============
   Choose parameter set for limiter and soft clipper.
   1: normal set
   2: used in start-stop situation
 */
/**
   @defgroup PostProcessLimiterSoftclipDisable
   @ingroup rtc_messages
   No further description of PostProcessLimiterSoftclipDisable has been defined yet.
 */
/**
   @defgroup PostProcessEnergyLimiterEnableLimiter
   @ingroup rtc_messages
   No further description of PostProcessEnergyLimiterEnableLimiter has been defined yet.
 */
/**
   @defgroup PostProcessPostLimiterEqShutdown
   @ingroup rtc_messages
   No further description of PostProcessPostLimiterEqShutdown has been defined yet.
 */
/**
   @defgroup TestRouterASDRouterMainSelect
   @ingroup rtc_messages
   No further description of TestRouterASDRouterMainSelect has been defined yet.
 */
/**
   @defgroup TestRouterASDRouterMainGain
   @ingroup rtc_messages
   No further description of TestRouterASDRouterMainGain has been defined yet.
 */
/**
   @defgroup TestRouterASDRouterAuxEnable
   @ingroup rtc_messages
   No further description of TestRouterASDRouterAuxEnable has been defined yet.
 */
/**
   @defgroup TestRouterASDRouterAuxSelect
   @ingroup rtc_messages
   No further description of TestRouterASDRouterAuxSelect has been defined yet.
 */
/**
   @defgroup TestRouterASDRouterAuxGain
   @ingroup rtc_messages
   No further description of TestRouterASDRouterAuxGain has been defined yet.
 */
#endif                              /* RTW_HEADER_Model_Target_RTC_doxygen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
