/*
 * File: Model_Target_RTC_XmlEmbed.h
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

#ifndef RTW_HEADER_Model_Target_RTC_XmlEmbed_h_
#define RTW_HEADER_Model_Target_RTC_XmlEmbed_h_

// ------------------------------------------------------------
// EMBEDDED XML FILE OF RTC TOKEN VALUES
// ------------------------------------------------------------
/* [XMLBEGIN]<?xml version="1.0" encoding="utf-8"?>
   <root version="1.0">
   <REQ id="InputSelectRouterCfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="routerMap" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="5"/>
   </REQ>
   <RSP id="InputSelectRouterCfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="routerMap" charOffset="12" dtypeStr="int32_t" dtypeNum="6" width="5"/>
   </RSP>
   <RTC id="InputSelectRouterCfgSet" msgId="0x10010000" payloadMetaHash="0x1C6FF7B5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="28" RSP="32" NTF="0"/>
   </RTC>
   <REQ id="PreAmpAudiopilotsetHVACSetting">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="HVACSetting" charOffset="4" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotmuteReference">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="muteReference" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotmuteReference">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="muteReference" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotsetSpeedIn">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="speedIn" charOffset="4" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotgetBassBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotgetBassBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="bassBoost" charOffset="12" dtypeStr="float" dtypeNum="1" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotgetMidBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotgetMidBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="midBoost" charOffset="12" dtypeStr="float" dtypeNum="1" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotgetTrebleBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotgetTrebleBoost">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="trebleBoost" charOffset="12" dtypeStr="float" dtypeNum="1" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotsetDynEQBoostOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="DynEQBoostOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="DynEQBoostOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetVNCBassBoostOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCBassBoostOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCBassBoostOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetVNCMidBoostOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCMidBoostOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCMidBoostOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetVNCTrebleBoostOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCTrebleBoostOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCTrebleBoostOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetLoudSignalOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="LoudSignalOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="LoudSignalOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetVNCSignalOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCSignalOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="VNCSignalOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotgetAverageAudioPilotBoostLevel">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotgetAverageAudioPilotBoostLevel">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="level" charOffset="12" dtypeStr="float" dtypeNum="1" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotsetHFNoiseOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="HFNoiseOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="HFNoiseOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetLFNoiseOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="LFNoiseOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="LFNoiseOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetRatioOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="RatioOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="RatioOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetWBNoiseOverRide">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="WBNoiseOverRideFlag" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="WBNoiseOverRide" charOffset="8" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="PreAmpAudiopilotsetDyneqOn">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="dyneq_on" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotsetDyneqOn">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="dyneq_on" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PreAmpAudiopilotsetAudioPilotOn">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="audiopilot_on" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpAudiopilotsetAudioPilotOn">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="audiopilot_on" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="PreAmpVolumeCfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpVolumeCfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_offset" charOffset="20" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </REQ>
   <RSP id="PreAmpVolumeCfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <RTC id="PreAmpAudiopilotmuteReference" msgId="0x14210004" payloadMetaHash="0x247693AC" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetSpeedIn" msgId="0x1422000d" payloadMetaHash="0xA43BA642" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetHVACSetting" msgId="0x14220009" payloadMetaHash="0x6EE8A0D9" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetDynEQBoostOverRide" msgId="0x14220006" payloadMetaHash="0x299F303C" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetVNCTrebleBoostOverRide" msgId="0x14220011" payloadMetaHash="0xCBB6EED1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetLoudSignalOverRide" msgId="0x1422000b" payloadMetaHash="0x79599FBF" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetVNCSignalOverRide" msgId="0x14220010" payloadMetaHash="0xD688E8DC" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetLFNoiseOverRide" msgId="0x1422000a" payloadMetaHash="0x8E903DE4" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetWBNoiseOverRide" msgId="0x14220012" payloadMetaHash="0x9ECB53E9" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetHFNoiseOverRide" msgId="0x14220008" payloadMetaHash="0x86AD18E3" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetRatioOverRide" msgId="0x1422000c" payloadMetaHash="0x49205226" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetDyneqOn" msgId="0x14210007" payloadMetaHash="0x53D37064" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetAudioPilotOn" msgId="0x14210005" payloadMetaHash="0xA612D44C" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetVNCBassBoostOverRide" msgId="0x1422000e" payloadMetaHash="0x83723975" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotgetBassBoost" msgId="0x14210001" payloadMetaHash="0x2D89CD76" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotsetVNCMidBoostOverRide" msgId="0x1422000f" payloadMetaHash="0xD332BCCC" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotgetMidBoost" msgId="0x14210002" payloadMetaHash="0x9875CD1C" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotgetTrebleBoost" msgId="0x14210003" payloadMetaHash="0x42018522" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpAudiopilotgetAverageAudioPilotBoostLevel" msgId="0x14210000" payloadMetaHash="0xF7974203" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PreAmpVolumeCfgSet" msgId="0x14200013" payloadMetaHash="0x3B6D65F2" coreIndex="0" coreTag="">
   <Description>Sets new target volume.&#13;Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="24" RSP="16" NTF="16"/>
   </RTC>
   <NTF id="PreAmpBalance_CfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpBalance_CfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpBalance_CfgSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <RTC id="PreAmpBalance_CfgSet" msgId="0x1b200000" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <NTF id="PreAmpMedusaSurroundLevelControlIndex">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="surround_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpMedusaSurroundLevelControlIndex">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="surround_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaSurroundLevelControlIndex">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="surround_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PreAmpMedusaSurroundLevelControlReset">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaSurroundLevelControlReset">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="PreAmpMedusaSurroundLevelControlIndex" msgId="0x15200001" payloadMetaHash="0x86D84C4B" coreIndex="0" coreTag="">
   <Description>Contains the value indicated by the surround knob.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpMedusaSurroundLevelControlReset" msgId="0x15210002" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <REQ id="PreAmpMedusaPostUpmixDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaPostUpmixDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="PreAmpMedusaPostUpmixDisable" msgId="0x15210000" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <REQ id="PreAmpMedusaHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="PreAmpMedusaHoligramDisable" msgId="0x16210000" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <REQ id="PreAmpMedusaOverheadHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaOverheadHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="PreAmpMedusaOverheadHoligramDisable" msgId="0x17210000" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <REQ id="PreAmpMedusaPostHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMedusaPostHoligramDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="PreAmpMedusaPostHoligramDisable" msgId="0x11210000" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <NTF id="PreAmpFadeControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpFadeControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpFadeControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="PreAmpMuteControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpMuteControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMuteControlSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PreAmpResetSleepingBeauty">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpResetSleepingBeauty">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <NTF id="PreAmpSleepingBeautyDRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpSleepingBeautyDRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpSleepingBeautyDRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="PreAmpSleepingBeautyFRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpSleepingBeautyFRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpSleepingBeautyFRSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <RTC id="PreAmpMuteControlSet" msgId="0x19200001" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpFadeControlSet" msgId="0x19200000" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpSleepingBeautyDRSet" msgId="0x19200003" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpSleepingBeautyFRSet" msgId="0x19200004" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpResetSleepingBeauty" msgId="0x19210002" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <NTF id="PreAmpBassSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpBassSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpBassSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="PreAmpMidrangeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpMidrangeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpMidrangeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="PreAmpTrebleSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PreAmpTrebleSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="gain_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PreAmpTrebleSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <RTC id="PreAmpBassSet" msgId="0x10200000" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpMidrangeSet" msgId="0x10200001" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PreAmpTrebleSet" msgId="0x10200002" payloadMetaHash="0xB435421A" coreIndex="0" coreTag="">
   <Description>Provide the target value as a 32-bit signed integer index value (to be mapped through a tunable calibration into a normalized float between -1 and 1).&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <REQ id="NearDr_RouterSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="routerMap" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="18"/>
   </REQ>
   <RSP id="NearDr_RouterSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="routerMap" charOffset="12" dtypeStr="int32_t" dtypeNum="6" width="18"/>
   </RSP>
   <REQ id="NearFr_RouterSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="routerMap" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="18"/>
   </REQ>
   <RSP id="NearFr_RouterSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="routerMap" charOffset="12" dtypeStr="int32_t" dtypeNum="6" width="18"/>
   </RSP>
   <RTC id="NearFr_RouterSet" msgId="0x10110013" payloadMetaHash="0x52721D54" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="80" RSP="84" NTF="0"/>
   </RTC>
   <REQ id="NearChannel2_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="loc" charOffset="8" dtypeStr="float" dtypeNum="1" width="2"/>
   </REQ>
   <RSP id="NearChannel2_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="NearChannel1_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="loc" charOffset="8" dtypeStr="float" dtypeNum="1" width="2"/>
   </REQ>
   <RSP id="NearChannel1_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="NearChannel4_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="loc" charOffset="8" dtypeStr="float" dtypeNum="1" width="2"/>
   </REQ>
   <RSP id="NearChannel4_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="NearChannel3_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="loc" charOffset="8" dtypeStr="float" dtypeNum="1" width="2"/>
   </REQ>
   <RSP id="NearChannel3_Location">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="NearAnnNoiseLevel">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="NoiseSig" charOffset="4" dtypeStr="float" dtypeNum="1" width="1"/>
   </REQ>
   <REQ id="NearAnn1Ann1NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="vncEnable" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn1Ann1NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="enable" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn1Ann1MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn1Ann1MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn1Ann1MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn1Ann1VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn1Ann1VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="volume_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn1Ann1VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="NearAnn2Ann2NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="vncEnable" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn2Ann2NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="enable" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn2Ann2MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn2Ann2MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn2Ann2MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn2Ann2VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn2Ann2VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="volume_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn2Ann2VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="NearAnn3Ann3NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="vncEnable" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn3Ann3NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="enable" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn3Ann3MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn3Ann3MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn3Ann3MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn3Ann3VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn3Ann3VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="volume_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn3Ann3VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="NearAnn4Ann4NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="vncEnable" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn4Ann4NonEntGainCalcvncEnableRTC">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="enable" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn4Ann4MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn4Ann4MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn4Ann4MuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <NTF id="NearAnn4Ann4VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="NearAnn4Ann4VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="volume_index" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearAnn4Ann4VolumeSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="gain_index" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="NearEnable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="Enable" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="NearEnable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="NearAnn1Ann1VolumeSet" msgId="0x10100002" payloadMetaHash="0x569B6C88" coreIndex="0" coreTag="">
   <Description>Sets new target volume.&#13;Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn2Ann2VolumeSet" msgId="0x10100005" payloadMetaHash="0x569B6C88" coreIndex="0" coreTag="">
   <Description>Sets new target volume.&#13;Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn3Ann3VolumeSet" msgId="0x10100008" payloadMetaHash="0x569B6C88" coreIndex="0" coreTag="">
   <Description>Sets new target volume.&#13;Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn4Ann4VolumeSet" msgId="0x1010000b" payloadMetaHash="0x569B6C88" coreIndex="0" coreTag="">
   <Description>Sets new target volume.&#13;Provide the target volume as 8 bit index value to be mapped through a tunable VolumeTable.&#13; &#13;To use slope-based ramping:&#13;----------------------------------&#13;When db_per_second has a non-zero value,ramp_milliseconds is ignored and db_per_second controls the ramp.&#13; &#13;To use time-based ramping:&#13;----------------------------------&#13;The value of db_per_second must be zero for ramp milliseconds to then control the ramping.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn1Ann1NonEntGainCalcvncEnableRTC" msgId="0x10110001" payloadMetaHash="0x8D6E73D5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="NearAnn1Ann1MuteSet" msgId="0x10100000" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn2Ann2NonEntGainCalcvncEnableRTC" msgId="0x10110004" payloadMetaHash="0x8D6E73D5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="NearAnn2Ann2MuteSet" msgId="0x10100003" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn3Ann3NonEntGainCalcvncEnableRTC" msgId="0x10110007" payloadMetaHash="0x8D6E73D5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="NearAnn3Ann3MuteSet" msgId="0x10100006" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnn4Ann4NonEntGainCalcvncEnableRTC" msgId="0x1011000a" payloadMetaHash="0x8D6E73D5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="NearAnn4Ann4MuteSet" msgId="0x10100009" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="NearAnnNoiseLevel" msgId="0x1012000c" payloadMetaHash="0xB0272F3F" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="0" NTF="0"/>
   </RTC>
   <RTC id="NearChannel1_Location" msgId="0x1011000d" payloadMetaHash="0xA6514C61" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="16" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="NearChannel2_Location" msgId="0x1011000e" payloadMetaHash="0xA6514C61" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="16" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="NearChannel3_Location" msgId="0x1011000f" payloadMetaHash="0xA6514C61" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="16" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="NearChannel4_Location" msgId="0x10110010" payloadMetaHash="0xA6514C61" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="16" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="NearDr_RouterSet" msgId="0x10110011" payloadMetaHash="0x52721D54" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="80" RSP="84" NTF="0"/>
   </RTC>
   <RTC id="NearEnable" msgId="0x10110012" payloadMetaHash="0x41D4C2C5" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="12" NTF="0"/>
   </RTC>
   <NTF id="PostProcessEnergyLimiterEnableLimiter">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="ELNotification" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PostProcessEnergyLimiterEnableLimiter">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="EnableGainLimiter" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PostProcessEnergyLimiterEnableLimiter">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <NTF id="PostProcessMuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </NTF>
   <REQ id="PostProcessMuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mute_switch" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_db_per_second" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="ramp_milliseconds" charOffset="16" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PostProcessMuteSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="mute_switch" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PostProcessPostLimiterEqShutdown">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PostProcessPostLimiterEqShutdown">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="PostProcessLimiterSoftclipParamSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="paramSet" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PostProcessLimiterSoftclipParamSet">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="paramSet" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <REQ id="PostProcessLimiterSoftclipDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="disableMsg" charOffset="8" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </REQ>
   <RSP id="PostProcessLimiterSoftclipDisable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   <Signal id="disableMsg" charOffset="12" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   </RSP>
   <RTC id="PostProcessMuteSet" msgId="0x10300003" payloadMetaHash="0xF0568ABA" coreIndex="0" coreTag="">
   <Description>Command a mute by specifying whether mute is active (non zero mute_switch) or inactive (mute_switch is "0"). If db_per_second is non-zero, it commands the timing of the mute, otherwise the ramp_milliseconds is used.</Description>
   <PayloadSizes REQ="20" RSP="16" NTF="16"/>
   </RTC>
   <RTC id="PostProcessLimiterSoftclipParamSet" msgId="0x10310002" payloadMetaHash="0xFF02D3AC" coreIndex="0" coreTag="">
   <Description>Choose parameter set for limiter and soft clipper.&#13;1: normal set&#13;2: used in start-stop situation </Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PostProcessLimiterSoftclipDisable" msgId="0x10310001" payloadMetaHash="0x6AD144C2" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="16" NTF="0"/>
   </RTC>
   <RTC id="PostProcessEnergyLimiterEnableLimiter" msgId="0x10300000" payloadMetaHash="0x87256586" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="12" NTF="16"/>
   </RTC>
   <RTC id="PostProcessPostLimiterEqShutdown" msgId="0x10310004" payloadMetaHash="0x97135BB1" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="8" RSP="12" NTF="0"/>
   </RTC>
   <REQ id="TestRouterASDRouterAuxEnable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="EnableAuxFlag" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </REQ>
   <RSP id="TestRouterASDRouterAuxEnable">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="TestRouterASDRouterAuxGain">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="AuxGain" charOffset="8" dtypeStr="float" dtypeNum="1" width="24"/>
   </REQ>
   <RSP id="TestRouterASDRouterAuxGain">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="TestRouterASDRouterAuxSelect">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="AuxSelect" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="24"/>
   </REQ>
   <RSP id="TestRouterASDRouterAuxSelect">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="TestRouterASDRouterMainGain">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mainGain" charOffset="8" dtypeStr="float" dtypeNum="1" width="24"/>
   </REQ>
   <RSP id="TestRouterASDRouterMainGain">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <REQ id="TestRouterASDRouterMainSelect">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="mainSelect" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="24"/>
   </REQ>
   <RSP id="TestRouterASDRouterMainSelect">
   <Signal id="msgId" charOffset="0" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="caller_handle" charOffset="4" dtypeStr="uint32_t" dtypeNum="7" width="1"/>
   <Signal id="status_code" charOffset="8" dtypeStr="int32_t" dtypeNum="6" width="1"/>
   </RSP>
   <RTC id="TestRouterASDRouterMainSelect" msgId="0x10510004" payloadMetaHash="0x637F1EA4" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="104" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="TestRouterASDRouterMainGain" msgId="0x10510003" payloadMetaHash="0xE4178B13" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="104" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="TestRouterASDRouterAuxEnable" msgId="0x10510000" payloadMetaHash="0x41CB1A64" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="12" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="TestRouterASDRouterAuxSelect" msgId="0x10510002" payloadMetaHash="0x16CBDC84" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="104" RSP="12" NTF="0"/>
   </RTC>
   <RTC id="TestRouterASDRouterAuxGain" msgId="0x10510001" payloadMetaHash="0x3E358CFE" coreIndex="0" coreTag="">
   <Description>[]</Description>
   <PayloadSizes REQ="104" RSP="12" NTF="0"/>
   </RTC>
   </root>
   [XMLEND] */
#endif                             /* RTW_HEADER_Model_Target_RTC_XmlEmbed_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
