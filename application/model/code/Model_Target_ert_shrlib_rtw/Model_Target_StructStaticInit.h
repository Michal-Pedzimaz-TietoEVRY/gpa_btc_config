/*
 * File: Model_Target_StructStaticInit.h
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

#ifndef RTW_HEADER_Model_Target_StructStaticInit_h_
#define RTW_HEADER_Model_Target_StructStaticInit_h_
#include "rtwtypes.h"
#include "Model_Target_types.h"

/* StructStaticInit type definitions */
typedef struct Model_TargetControlDsms_tag
{
    rgain_bus NearAnn1Ann1VolumeRampers;/* '<S1909>/ramp control' */
    rgain_bus NearAnn2Ann2VolumeRampers;/* '<S1989>/ramp control' */
    rgain_bus NearAnn3Ann3VolumeRampers;/* '<S2069>/ramp control' */
    rgain_bus NearAnn4Ann4VolumeRampers;/* '<S2149>/ramp control' */
    rgain_bus PreAmpBalance_CfgRampers[4];/* '<S563>/ramp control' */
    rgain_bus PreAmpBassRampers[2];    /* '<S1523>/ramp control' */
    rgain_bus PreAmpFadeRamperDRRampers[4];/* '<S1375>/ramp control' */
    rgain_bus PreAmpFadeRamperFRRampers[4];/* '<S1382>/ramp control' */
    rgain_bus PreAmpMidrangeRampers[2];/* '<S1524>/ramp control' */
    rgain_bus PreAmpSleepingBeautyDRRampers[4];/* '<S1432>/ramp control' */
    rgain_bus PreAmpSleepingBeautyFRRampers[4];/* '<S1452>/ramp control' */
    rgain_bus PreAmpTrebleRampers[2];  /* '<S1526>/ramp control' */
    rgain_bus PreAmpVolumeCfgRampers;  /* '<S536>/ramp control' */
    real32_T NearAnn1MuteCurrentGain;  /* '<S1885>/currentGain' */
    real32_T NearAnn1MuteNframes;      /* '<S1885>/nFrames' */
    real32_T NearAnn1MuteTargetLinearGain;/* '<S1885>/targetLinearGain' */
    real32_T NearAnn2MuteCurrentGain;  /* '<S1965>/currentGain' */
    real32_T NearAnn2MuteNframes;      /* '<S1965>/nFrames' */
    real32_T NearAnn2MuteTargetLinearGain;/* '<S1965>/targetLinearGain' */
    real32_T NearAnn3MuteCurrentGain;  /* '<S2045>/currentGain' */
    real32_T NearAnn3MuteNframes;      /* '<S2045>/nFrames' */
    real32_T NearAnn3MuteTargetLinearGain;/* '<S2045>/targetLinearGain' */
    real32_T NearAnn4MuteCurrentGain;  /* '<S2125>/currentGain' */
    real32_T NearAnn4MuteNframes;      /* '<S2125>/nFrames' */
    real32_T NearAnn4MuteTargetLinearGain;/* '<S2125>/targetLinearGain' */
    real32_T PostProcessMuteCurrentGain;/* '<S2220>/currentGain' */
    real32_T PostProcessMuteNframes;   /* '<S2220>/nFrames' */
    real32_T PostProcessMuteTargetLinearGain;/* '<S2220>/targetLinearGain' */
    real32_T PreAmpMuteDRCurrentGain;  /* '<S1400>/currentGain' */
    real32_T PreAmpMuteDRNframes;      /* '<S1400>/nFrames' */
    real32_T PreAmpMuteDRTargetLinearGain;/* '<S1400>/targetLinearGain' */
    real32_T PreAmpMuteFRCurrentGain;  /* '<S1413>/currentGain' */
    real32_T PreAmpMuteFRNframes;      /* '<S1413>/nFrames' */
    real32_T PreAmpMuteFRTargetLinearGain;/* '<S1413>/targetLinearGain' */
    uint32_T NearAnn1Ann1VolumeFreeze; /* '<S1909>/freeze control' */
    uint32_T NearAnn2Ann2VolumeFreeze; /* '<S1989>/freeze control' */
    uint32_T NearAnn3Ann3VolumeFreeze; /* '<S2069>/freeze control' */
    uint32_T NearAnn4Ann4VolumeFreeze; /* '<S2149>/freeze control' */
    uint32_T PreAmpBalance_CfgFreeze;  /* '<S563>/freeze control' */
    uint32_T PreAmpBassFreeze;         /* '<S1523>/freeze control' */
    uint32_T PreAmpBassPhase;          /* '<S1523>/phase control' */
    uint32_T PreAmpFadeRamperDRFreeze; /* '<S1375>/freeze control' */
    uint32_T PreAmpFadeRamperFRFreeze; /* '<S1382>/freeze control' */
    uint32_T PreAmpMidrangeFreeze;     /* '<S1524>/freeze control' */
    uint32_T PreAmpMidrangePhase;      /* '<S1524>/phase control' */
    uint32_T PreAmpSleepingBeautyDRFreeze;/* '<S1432>/freeze control' */
    uint32_T PreAmpSleepingBeautyFRFreeze;/* '<S1452>/freeze control' */
    uint32_T PreAmpTrebleFreeze;       /* '<S1526>/freeze control' */
    uint32_T PreAmpTreblePhase;        /* '<S1526>/phase control' */
    uint32_T PreAmpVolumeCfgFreeze;    /* '<S536>/freeze control' */
}
Model_TargetControlDsms_type;

typedef struct Model_TargetInputSelectRouterCfgSetRtcOut_tag
{
    int32_T REQ_routerMap[5];          /* '<S21>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S21>/UnpackREQ' */
}
Model_TargetInputSelectRouterCfgSetRtcOut_type;

typedef struct Model_TargetNearAnn1Ann1MuteSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1894>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S1894>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1894>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1894>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1894>/UnpackREQ' */
}
Model_TargetNearAnn1Ann1MuteSetRtcOut_type;

typedef struct Model_TargetNearAnn1Ann1NonEntGainCalcvncEnableRTCRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1874>/UnpackREQ' */
    uint32_T REQ_vncEnable;            /* '<S1874>/UnpackREQ' */
}
Model_TargetNearAnn1Ann1NonEntGainCalcvncEnableRTCRtcOut_type;

typedef struct Model_TargetNearAnn1Ann1VolumeSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1922>/UnpackREQ' */
    uint32_T REQ_db_per_second;        /* '<S1922>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1922>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1922>/UnpackREQ' */
    uint32_T REQ_volume_index;         /* '<S1922>/UnpackREQ' */
}
Model_TargetNearAnn1Ann1VolumeSetRtcOut_type;

typedef struct Model_TargetNearAnn2Ann2MuteSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1974>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S1974>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1974>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1974>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1974>/UnpackREQ' */
}
Model_TargetNearAnn2Ann2MuteSetRtcOut_type;

typedef struct Model_TargetNearAnn2Ann2NonEntGainCalcvncEnableRTCRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1954>/UnpackREQ' */
    uint32_T REQ_vncEnable;            /* '<S1954>/UnpackREQ' */
}
Model_TargetNearAnn2Ann2NonEntGainCalcvncEnableRTCRtcOut_type;

typedef struct Model_TargetNearAnn2Ann2VolumeSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2002>/UnpackREQ' */
    uint32_T REQ_db_per_second;        /* '<S2002>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2002>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2002>/UnpackREQ' */
    uint32_T REQ_volume_index;         /* '<S2002>/UnpackREQ' */
}
Model_TargetNearAnn2Ann2VolumeSetRtcOut_type;

typedef struct Model_TargetNearAnn3Ann3MuteSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2054>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S2054>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S2054>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2054>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2054>/UnpackREQ' */
}
Model_TargetNearAnn3Ann3MuteSetRtcOut_type;

typedef struct Model_TargetNearAnn3Ann3NonEntGainCalcvncEnableRTCRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2034>/UnpackREQ' */
    uint32_T REQ_vncEnable;            /* '<S2034>/UnpackREQ' */
}
Model_TargetNearAnn3Ann3NonEntGainCalcvncEnableRTCRtcOut_type;

typedef struct Model_TargetNearAnn3Ann3VolumeSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2082>/UnpackREQ' */
    uint32_T REQ_db_per_second;        /* '<S2082>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2082>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2082>/UnpackREQ' */
    uint32_T REQ_volume_index;         /* '<S2082>/UnpackREQ' */
}
Model_TargetNearAnn3Ann3VolumeSetRtcOut_type;

typedef struct Model_TargetNearAnn4Ann4MuteSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2134>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S2134>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S2134>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2134>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2134>/UnpackREQ' */
}
Model_TargetNearAnn4Ann4MuteSetRtcOut_type;

typedef struct Model_TargetNearAnn4Ann4NonEntGainCalcvncEnableRTCRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2114>/UnpackREQ' */
    uint32_T REQ_vncEnable;            /* '<S2114>/UnpackREQ' */
}
Model_TargetNearAnn4Ann4NonEntGainCalcvncEnableRTCRtcOut_type;

typedef struct Model_TargetNearAnn4Ann4VolumeSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2162>/UnpackREQ' */
    uint32_T REQ_db_per_second;        /* '<S2162>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2162>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2162>/UnpackREQ' */
    uint32_T REQ_volume_index;         /* '<S2162>/UnpackREQ' */
}
Model_TargetNearAnn4Ann4VolumeSetRtcOut_type;

typedef struct Model_TargetNearAnnNoiseLevelRtcOut_tag
{
    real32_T REQ_NoiseSig;             /* '<S1850>/UnpackREQ' */
}
Model_TargetNearAnnNoiseLevelRtcOut_type;

typedef struct Model_TargetNearChannel1_LocationRtcOut_tag
{
    real32_T REQ_loc[2];               /* '<S1749>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1749>/UnpackREQ' */
}
Model_TargetNearChannel1_LocationRtcOut_type;

typedef struct Model_TargetNearChannel2_LocationRtcOut_tag
{
    real32_T REQ_loc[2];               /* '<S1743>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1743>/UnpackREQ' */
}
Model_TargetNearChannel2_LocationRtcOut_type;

typedef struct Model_TargetNearChannel3_LocationRtcOut_tag
{
    real32_T REQ_loc[2];               /* '<S1761>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1761>/UnpackREQ' */
}
Model_TargetNearChannel3_LocationRtcOut_type;

typedef struct Model_TargetNearChannel4_LocationRtcOut_tag
{
    real32_T REQ_loc[2];               /* '<S1755>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1755>/UnpackREQ' */
}
Model_TargetNearChannel4_LocationRtcOut_type;

typedef struct Model_TargetNearDr_RouterSetRtcOut_tag
{
    int32_T REQ_routerMap[18];         /* '<S1662>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1662>/UnpackREQ' */
}
Model_TargetNearDr_RouterSetRtcOut_type;

typedef struct Model_TargetNearEnableRtcOut_tag
{
    uint32_T REQ_Enable;               /* '<S2176>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2176>/UnpackREQ' */
}
Model_TargetNearEnableRtcOut_type;

typedef struct Model_TargetNearFr_RouterSetRtcOut_tag
{
    int32_T REQ_routerMap[18];         /* '<S1720>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S1720>/UnpackREQ' */
}
Model_TargetNearFr_RouterSetRtcOut_type;

typedef struct Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut_tag
{
    uint32_T REQ_EnableGainLimiter;    /* '<S2214>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2214>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2214>/UnpackREQ' */
}
Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut_type;

typedef struct Model_TargetPostProcessLimiterSoftclipDisableRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2266>/UnpackREQ' */
    uint32_T REQ_disableMsg;           /* '<S2266>/UnpackREQ' */
}
Model_TargetPostProcessLimiterSoftclipDisableRtcOut_type;

typedef struct Model_TargetPostProcessLimiterSoftclipParamSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2260>/UnpackREQ' */
    uint32_T REQ_paramSet;             /* '<S2260>/UnpackREQ' */
}
Model_TargetPostProcessLimiterSoftclipParamSetRtcOut_type;

typedef struct Model_TargetPostProcessMuteSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2229>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S2229>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S2229>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S2229>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S2229>/UnpackREQ' */
}
Model_TargetPostProcessMuteSetRtcOut_type;

typedef struct Model_TargetPostProcessPostLimiterEqShutdownRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S2254>/UnpackREQ' */
}
Model_TargetPostProcessPostLimiterEqShutdownRtcOut_type;

typedef struct
    Model_TargetPreAmpAudiopilotgetAverageAudioPilotBoostLevelRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S190>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotgetAverageAudioPilotBoostLevelRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotgetBassBoostRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S90>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotgetBassBoostRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotgetMidBoostRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S96>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotgetMidBoostRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotgetTrebleBoostRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S102>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotgetTrebleBoostRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotmuteReferenceRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S60>/UnpackREQ' */
    uint32_T REQ_muteReference;        /* '<S60>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotmuteReferenceRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetAudioPilotOnRtcOut_tag
{
    uint32_T REQ_audiopilot_on;        /* '<S247>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S247>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetAudioPilotOnRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetDynEQBoostOverRideRtcOut_tag
{
    real32_T REQ_DynEQBoostOverRide;   /* '<S150>/UnpackREQ' */
    uint32_T REQ_DynEQBoostOverRideFlag;/* '<S150>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetDynEQBoostOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetDyneqOnRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S241>/UnpackREQ' */
    uint32_T REQ_dyneq_on;             /* '<S241>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetDyneqOnRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetHFNoiseOverRideRtcOut_tag
{
    real32_T REQ_HFNoiseOverRide;      /* '<S201>/UnpackREQ' */
    uint32_T REQ_HFNoiseOverRideFlag;  /* '<S201>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetHFNoiseOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetHVACSettingRtcOut_tag
{
    real32_T REQ_HVACSetting;          /* '<S54>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetHVACSettingRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetLFNoiseOverRideRtcOut_tag
{
    real32_T REQ_LFNoiseOverRide;      /* '<S207>/UnpackREQ' */
    uint32_T REQ_LFNoiseOverRideFlag;  /* '<S207>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetLFNoiseOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetLoudSignalOverRideRtcOut_tag
{
    real32_T REQ_LoudSignalOverRide;   /* '<S178>/UnpackREQ' */
    uint32_T REQ_LoudSignalOverRideFlag;/* '<S178>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetLoudSignalOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetRatioOverRideRtcOut_tag
{
    real32_T REQ_RatioOverRide;        /* '<S213>/UnpackREQ' */
    uint32_T REQ_RatioOverRideFlag;    /* '<S213>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetRatioOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetSpeedInRtcOut_tag
{
    real32_T REQ_speedIn;              /* '<S66>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetSpeedInRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetVNCBassBoostOverRideRtcOut_tag
{
    real32_T REQ_VNCBassBoostOverRide; /* '<S156>/UnpackREQ' */
    uint32_T REQ_VNCBassBoostOverRideFlag;/* '<S156>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetVNCBassBoostOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetVNCMidBoostOverRideRtcOut_tag
{
    real32_T REQ_VNCMidBoostOverRide;  /* '<S162>/UnpackREQ' */
    uint32_T REQ_VNCMidBoostOverRideFlag;/* '<S162>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetVNCMidBoostOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetVNCSignalOverRideRtcOut_tag
{
    real32_T REQ_VNCSignalOverRide;    /* '<S184>/UnpackREQ' */
    uint32_T REQ_VNCSignalOverRideFlag;/* '<S184>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetVNCSignalOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetVNCTrebleBoostOverRideRtcOut_tag
{
    real32_T REQ_VNCTrebleBoostOverRide;/* '<S168>/UnpackREQ' */
    uint32_T REQ_VNCTrebleBoostOverRideFlag;/* '<S168>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetVNCTrebleBoostOverRideRtcOut_type;

typedef struct Model_TargetPreAmpAudiopilotsetWBNoiseOverRideRtcOut_tag
{
    real32_T REQ_WBNoiseOverRide;      /* '<S219>/UnpackREQ' */
    uint32_T REQ_WBNoiseOverRideFlag;  /* '<S219>/UnpackREQ' */
}
Model_TargetPreAmpAudiopilotsetWBNoiseOverRideRtcOut_type;

typedef struct Model_TargetPreAmpBalance_CfgSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S583>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S583>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S583>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S583>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S583>/UnpackREQ' */
}
Model_TargetPreAmpBalance_CfgSetRtcOut_type;

typedef struct Model_TargetPreAmpBassSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1543>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1543>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1543>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1543>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1543>/UnpackREQ' */
}
Model_TargetPreAmpBassSetRtcOut_type;

typedef struct Model_TargetPreAmpFadeControlSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1373>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1373>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1373>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1373>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1373>/UnpackREQ' */
}
Model_TargetPreAmpFadeControlSetRtcOut_type;

typedef struct Model_TargetPreAmpMedusaHoligramDisableRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1276>/UnpackREQ' */
}
Model_TargetPreAmpMedusaHoligramDisableRtcOut_type;

typedef struct Model_TargetPreAmpMedusaOverheadHoligramDisableRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1288>/UnpackREQ' */
}
Model_TargetPreAmpMedusaOverheadHoligramDisableRtcOut_type;

typedef struct Model_TargetPreAmpMedusaPostHoligramDisableRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1326>/UnpackREQ' */
}
Model_TargetPreAmpMedusaPostHoligramDisableRtcOut_type;

typedef struct Model_TargetPreAmpMedusaPostUpmixDisableRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1185>/UnpackREQ' */
}
Model_TargetPreAmpMedusaPostUpmixDisableRtcOut_type;

typedef struct Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1121>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1121>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1121>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1121>/UnpackREQ' */
    uint32_T REQ_surround_index;       /* '<S1121>/UnpackREQ' */
}
Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut_type;

typedef struct Model_TargetPreAmpMedusaSurroundLevelControlResetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1127>/UnpackREQ' */
}
Model_TargetPreAmpMedusaSurroundLevelControlResetRtcOut_type;

typedef struct Model_TargetPreAmpMidrangeSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1561>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1561>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1561>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1561>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1561>/UnpackREQ' */
}
Model_TargetPreAmpMidrangeSetRtcOut_type;

typedef struct Model_TargetPreAmpMuteControlSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1398>/UnpackREQ' */
    uint32_T REQ_mute_switch;          /* '<S1398>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1398>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1398>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1398>/UnpackREQ' */
}
Model_TargetPreAmpMuteControlSetRtcOut_type;

typedef struct Model_TargetPreAmpResetSleepingBeautyRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1430>/UnpackREQ' */
}
Model_TargetPreAmpResetSleepingBeautyRtcOut_type;

typedef struct Model_TargetPreAmpSleepingBeautyDRSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1450>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1450>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1450>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1450>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1450>/UnpackREQ' */
}
Model_TargetPreAmpSleepingBeautyDRSetRtcOut_type;

typedef struct Model_TargetPreAmpSleepingBeautyFRSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1470>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1470>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1470>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1470>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1470>/UnpackREQ' */
}
Model_TargetPreAmpSleepingBeautyFRSetRtcOut_type;

typedef struct Model_TargetPreAmpTrebleSetRtcOut_tag
{
    uint32_T REQ_caller_handle;        /* '<S1597>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S1597>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S1597>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S1597>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S1597>/UnpackREQ' */
}
Model_TargetPreAmpTrebleSetRtcOut_type;

typedef struct Model_TargetPreAmpVolumeCfgSetRtcOut_tag
{
    int32_T REQ_gain_offset;           /* '<S547>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S547>/UnpackREQ' */
    uint32_T REQ_gain_index;           /* '<S547>/UnpackREQ' */
    uint32_T REQ_ramp_db_per_second;   /* '<S547>/UnpackREQ' */
    uint32_T REQ_ramp_milliseconds;    /* '<S547>/UnpackREQ' */
    uint32_T REQ_sequence;             /* '<S547>/UnpackREQ' */
}
Model_TargetPreAmpVolumeCfgSetRtcOut_type;

typedef struct Model_TargetTestRouterASDRouterAuxEnableRtcOut_tag
{
    int32_T REQ_EnableAuxFlag;         /* '<S2287>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2287>/UnpackREQ' */
}
Model_TargetTestRouterASDRouterAuxEnableRtcOut_type;

typedef struct Model_TargetTestRouterASDRouterAuxGainRtcOut_tag
{
    real32_T REQ_AuxGain[24];          /* '<S2293>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2293>/UnpackREQ' */
}
Model_TargetTestRouterASDRouterAuxGainRtcOut_type;

typedef struct Model_TargetTestRouterASDRouterAuxSelectRtcOut_tag
{
    int32_T REQ_AuxSelect[24];         /* '<S2299>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2299>/UnpackREQ' */
}
Model_TargetTestRouterASDRouterAuxSelectRtcOut_type;

typedef struct Model_TargetTestRouterASDRouterMainGainRtcOut_tag
{
    real32_T REQ_mainGain[24];         /* '<S2311>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2311>/UnpackREQ' */
}
Model_TargetTestRouterASDRouterMainGainRtcOut_type;

typedef struct Model_TargetTestRouterASDRouterMainSelectRtcOut_tag
{
    int32_T REQ_mainSelect[24];        /* '<S2317>/UnpackREQ' */
    uint32_T REQ_caller_handle;        /* '<S2317>/UnpackREQ' */
}
Model_TargetTestRouterASDRouterMainSelectRtcOut_type;

/* StructStaticInit instance declarations */
extern Model_TargetControlDsms_type Model_TargetControlDsms;
extern Model_TargetInputSelectRouterCfgSetRtcOut_type
    Model_TargetInputSelectRouterCfgSetRtcOut;
extern Model_TargetNearAnn1Ann1MuteSetRtcOut_type
    Model_TargetNearAnn1Ann1MuteSetRtcOut;
extern Model_TargetNearAnn1Ann1NonEntGainCalcvncEnableRTCRtcOut_type
    Model_TargetNearAnn1Ann1NonEntGainCalcvncEnableRTCRtcOut;
extern Model_TargetNearAnn1Ann1VolumeSetRtcOut_type
    Model_TargetNearAnn1Ann1VolumeSetRtcOut;
extern Model_TargetNearAnn2Ann2MuteSetRtcOut_type
    Model_TargetNearAnn2Ann2MuteSetRtcOut;
extern Model_TargetNearAnn2Ann2NonEntGainCalcvncEnableRTCRtcOut_type
    Model_TargetNearAnn2Ann2NonEntGainCalcvncEnableRTCRtcOut;
extern Model_TargetNearAnn2Ann2VolumeSetRtcOut_type
    Model_TargetNearAnn2Ann2VolumeSetRtcOut;
extern Model_TargetNearAnn3Ann3MuteSetRtcOut_type
    Model_TargetNearAnn3Ann3MuteSetRtcOut;
extern Model_TargetNearAnn3Ann3NonEntGainCalcvncEnableRTCRtcOut_type
    Model_TargetNearAnn3Ann3NonEntGainCalcvncEnableRTCRtcOut;
extern Model_TargetNearAnn3Ann3VolumeSetRtcOut_type
    Model_TargetNearAnn3Ann3VolumeSetRtcOut;
extern Model_TargetNearAnn4Ann4MuteSetRtcOut_type
    Model_TargetNearAnn4Ann4MuteSetRtcOut;
extern Model_TargetNearAnn4Ann4NonEntGainCalcvncEnableRTCRtcOut_type
    Model_TargetNearAnn4Ann4NonEntGainCalcvncEnableRTCRtcOut;
extern Model_TargetNearAnn4Ann4VolumeSetRtcOut_type
    Model_TargetNearAnn4Ann4VolumeSetRtcOut;
extern Model_TargetNearAnnNoiseLevelRtcOut_type
    Model_TargetNearAnnNoiseLevelRtcOut;
extern Model_TargetNearChannel1_LocationRtcOut_type
    Model_TargetNearChannel1_LocationRtcOut;
extern Model_TargetNearChannel2_LocationRtcOut_type
    Model_TargetNearChannel2_LocationRtcOut;
extern Model_TargetNearChannel3_LocationRtcOut_type
    Model_TargetNearChannel3_LocationRtcOut;
extern Model_TargetNearChannel4_LocationRtcOut_type
    Model_TargetNearChannel4_LocationRtcOut;
extern Model_TargetNearDr_RouterSetRtcOut_type
    Model_TargetNearDr_RouterSetRtcOut;
extern Model_TargetNearEnableRtcOut_type Model_TargetNearEnableRtcOut;
extern Model_TargetNearFr_RouterSetRtcOut_type
    Model_TargetNearFr_RouterSetRtcOut;
extern Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut_type
    Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut;
extern Model_TargetPostProcessLimiterSoftclipDisableRtcOut_type
    Model_TargetPostProcessLimiterSoftclipDisableRtcOut;
extern Model_TargetPostProcessLimiterSoftclipParamSetRtcOut_type
    Model_TargetPostProcessLimiterSoftclipParamSetRtcOut;
extern Model_TargetPostProcessMuteSetRtcOut_type
    Model_TargetPostProcessMuteSetRtcOut;
extern Model_TargetPostProcessPostLimiterEqShutdownRtcOut_type
    Model_TargetPostProcessPostLimiterEqShutdownRtcOut;
extern Model_TargetPreAmpAudiopilotgetAverageAudioPilotBoostLevelRtcOut_type
    Model_TargetPreAmpAudiopilotgetAverageAudioPilotBoostLevelRtcOut;
extern Model_TargetPreAmpAudiopilotgetBassBoostRtcOut_type
    Model_TargetPreAmpAudiopilotgetBassBoostRtcOut;
extern Model_TargetPreAmpAudiopilotgetMidBoostRtcOut_type
    Model_TargetPreAmpAudiopilotgetMidBoostRtcOut;
extern Model_TargetPreAmpAudiopilotgetTrebleBoostRtcOut_type
    Model_TargetPreAmpAudiopilotgetTrebleBoostRtcOut;
extern Model_TargetPreAmpAudiopilotmuteReferenceRtcOut_type
    Model_TargetPreAmpAudiopilotmuteReferenceRtcOut;
extern Model_TargetPreAmpAudiopilotsetAudioPilotOnRtcOut_type
    Model_TargetPreAmpAudiopilotsetAudioPilotOnRtcOut;
extern Model_TargetPreAmpAudiopilotsetDynEQBoostOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetDynEQBoostOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetDyneqOnRtcOut_type
    Model_TargetPreAmpAudiopilotsetDyneqOnRtcOut;
extern Model_TargetPreAmpAudiopilotsetHFNoiseOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetHFNoiseOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetHVACSettingRtcOut_type
    Model_TargetPreAmpAudiopilotsetHVACSettingRtcOut;
extern Model_TargetPreAmpAudiopilotsetLFNoiseOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetLFNoiseOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetLoudSignalOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetLoudSignalOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetRatioOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetRatioOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetSpeedInRtcOut_type
    Model_TargetPreAmpAudiopilotsetSpeedInRtcOut;
extern Model_TargetPreAmpAudiopilotsetVNCBassBoostOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetVNCBassBoostOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetVNCMidBoostOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetVNCMidBoostOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetVNCSignalOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetVNCSignalOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetVNCTrebleBoostOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetVNCTrebleBoostOverRideRtcOut;
extern Model_TargetPreAmpAudiopilotsetWBNoiseOverRideRtcOut_type
    Model_TargetPreAmpAudiopilotsetWBNoiseOverRideRtcOut;
extern Model_TargetPreAmpBalance_CfgSetRtcOut_type
    Model_TargetPreAmpBalance_CfgSetRtcOut;
extern Model_TargetPreAmpBassSetRtcOut_type Model_TargetPreAmpBassSetRtcOut;
extern Model_TargetPreAmpFadeControlSetRtcOut_type
    Model_TargetPreAmpFadeControlSetRtcOut;
extern Model_TargetPreAmpMedusaHoligramDisableRtcOut_type
    Model_TargetPreAmpMedusaHoligramDisableRtcOut;
extern Model_TargetPreAmpMedusaOverheadHoligramDisableRtcOut_type
    Model_TargetPreAmpMedusaOverheadHoligramDisableRtcOut;
extern Model_TargetPreAmpMedusaPostHoligramDisableRtcOut_type
    Model_TargetPreAmpMedusaPostHoligramDisableRtcOut;
extern Model_TargetPreAmpMedusaPostUpmixDisableRtcOut_type
    Model_TargetPreAmpMedusaPostUpmixDisableRtcOut;
extern Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut_type
    Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut;
extern Model_TargetPreAmpMedusaSurroundLevelControlResetRtcOut_type
    Model_TargetPreAmpMedusaSurroundLevelControlResetRtcOut;
extern Model_TargetPreAmpMidrangeSetRtcOut_type
    Model_TargetPreAmpMidrangeSetRtcOut;
extern Model_TargetPreAmpMuteControlSetRtcOut_type
    Model_TargetPreAmpMuteControlSetRtcOut;
extern Model_TargetPreAmpResetSleepingBeautyRtcOut_type
    Model_TargetPreAmpResetSleepingBeautyRtcOut;
extern Model_TargetPreAmpSleepingBeautyDRSetRtcOut_type
    Model_TargetPreAmpSleepingBeautyDRSetRtcOut;
extern Model_TargetPreAmpSleepingBeautyFRSetRtcOut_type
    Model_TargetPreAmpSleepingBeautyFRSetRtcOut;
extern Model_TargetPreAmpTrebleSetRtcOut_type Model_TargetPreAmpTrebleSetRtcOut;
extern Model_TargetPreAmpVolumeCfgSetRtcOut_type
    Model_TargetPreAmpVolumeCfgSetRtcOut;
extern Model_TargetTestRouterASDRouterAuxEnableRtcOut_type
    Model_TargetTestRouterASDRouterAuxEnableRtcOut;
extern Model_TargetTestRouterASDRouterAuxGainRtcOut_type
    Model_TargetTestRouterASDRouterAuxGainRtcOut;
extern Model_TargetTestRouterASDRouterAuxSelectRtcOut_type
    Model_TargetTestRouterASDRouterAuxSelectRtcOut;
extern Model_TargetTestRouterASDRouterMainGainRtcOut_type
    Model_TargetTestRouterASDRouterMainGainRtcOut;
extern Model_TargetTestRouterASDRouterMainSelectRtcOut_type
    Model_TargetTestRouterASDRouterMainSelectRtcOut;

#endif                         /* RTW_HEADER_Model_Target_StructStaticInit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
