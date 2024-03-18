/*
 * File: Model_Target_TOP.h
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

#ifndef RTW_HEADER_Model_Target_TOP_h_
#define RTW_HEADER_Model_Target_TOP_h_
#include "rtwtypes.h"

typedef struct Model_Target_InputSelect_p0_b0_tag
{
    int32_T RouterCfgOutMap[5];        /* '<S12>/TOP' */
}
Model_Target_InputSelect_p0_b0_type;

typedef struct Model_Target_Near_p0_b0_tag
{
    int32_T Dr_EqDelays[7];            /* '<S1618>/TOP' */
    int32_T Dr_RouterOutMap[18];       /* '<S1654>/TOP' */
    int32_T Fr_EqDelays[7];            /* '<S1676>/TOP' */
    int32_T Fr_RouterOutMap[18];       /* '<S1712>/TOP' */
    real32_T Ann1Ann1MuteRampTime;     /* '<S1888>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcBoostOverRide;/* '<S1863>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcBoostOverRideFlag;/* '<S1864>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcDen[2];/* '<S1866>/den' */
    real32_T Ann1Ann1NonEntGainCalcMaxBoost;/* '<S1860>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcMaxSpl;/* '<S1879>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcMinVncSignal;/* '<S1878>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcNoiseOverRide;/* '<S1861>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcNoiseOverRideFlag;/* '<S1862>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcNum[2];/* '<S1866>/num' */
    real32_T Ann1Ann1NonEntGainCalcVncEnableTuneVar;/* '<S1865>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcVncSlope;/* '<S1859>/TOP' */
    real32_T Ann1Ann1NonEntGainCalcVncThresh;/* '<S1858>/TOP' */
    real32_T Ann1Ann1NonEntVncAppliedNum[2];/* '<S1883>/num' */
    real32_T Ann1Ann1NonEntVncAppliedden[2];/* '<S1883>/den' */
    real32_T Ann1Ann1VolumeRampRate;   /* '<S1911>/TOP' */
    real32_T Ann1Ann1VolumeRampTime;   /* '<S1912>/TOP' */
    real32_T Ann1Ann1VolumeTable_dB[16];/* '<S1855>/TOP_GainDB' */
    real32_T Ann1LevelDetectFastDecayDbPerSample;/* '<S1815>/TOP' */
    real32_T Ann1LevelDetectHoldTimeSamples;/* '<S1817>/TOP' */
    real32_T Ann1LevelDetectMaxVolumeDb;/* '<S1818>/TOP' */
    real32_T Ann1LevelDetectMinVolumeDb;/* '<S1819>/TOP' */
    real32_T Ann1LevelDetectSlowDecayDbPerSample;/* '<S1820>/TOP' */
    real32_T Ann1LevelDetecthold_margin_db;/* '<S1816>/TOP' */
    real32_T Ann2Ann2MuteRampTime;     /* '<S1968>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcBoostOverRide;/* '<S1943>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcBoostOverRideFlag;/* '<S1944>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcDen[2];/* '<S1946>/den' */
    real32_T Ann2Ann2NonEntGainCalcMaxBoost;/* '<S1940>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcMaxSpl;/* '<S1959>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcMinVncSignal;/* '<S1958>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcNoiseOverRide;/* '<S1941>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcNoiseOverRideFlag;/* '<S1942>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcNum[2];/* '<S1946>/num' */
    real32_T Ann2Ann2NonEntGainCalcVncEnableTuneVar;/* '<S1945>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcVncSlope;/* '<S1939>/TOP' */
    real32_T Ann2Ann2NonEntGainCalcVncThresh;/* '<S1938>/TOP' */
    real32_T Ann2Ann2NonEntVncAppliedNum[2];/* '<S1963>/num' */
    real32_T Ann2Ann2NonEntVncAppliedden[2];/* '<S1963>/den' */
    real32_T Ann2Ann2VolumeRampRate;   /* '<S1991>/TOP' */
    real32_T Ann2Ann2VolumeRampTime;   /* '<S1992>/TOP' */
    real32_T Ann2Ann2VolumeTable_dB[16];/* '<S1935>/TOP_GainDB' */
    real32_T Ann2LevelDetectFastDecayDbPerSample;/* '<S1823>/TOP' */
    real32_T Ann2LevelDetectHoldMarginDb;/* '<S1824>/TOP' */
    real32_T Ann2LevelDetectHoldTimeSamples;/* '<S1825>/TOP' */
    real32_T Ann2LevelDetectMaxVolumeDb;/* '<S1826>/TOP' */
    real32_T Ann2LevelDetectMinVolumeDb;/* '<S1827>/TOP' */
    real32_T Ann2LevelDetectSlowDecayDbPerSample;/* '<S1828>/TOP' */
    real32_T Ann3Ann3MuteRampTime;     /* '<S2048>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcBoostOverRide;/* '<S2023>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcBoostOverRideFlag;/* '<S2024>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcDen[2];/* '<S2026>/den' */
    real32_T Ann3Ann3NonEntGainCalcMaxBoost;/* '<S2020>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcMaxSpl;/* '<S2039>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcMinVncSignal;/* '<S2038>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcNoiseOverRide;/* '<S2021>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcNoiseOverRideFlag;/* '<S2022>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcNum[2];/* '<S2026>/num' */
    real32_T Ann3Ann3NonEntGainCalcVncEnableTuneVar;/* '<S2025>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcVncSlope;/* '<S2019>/TOP' */
    real32_T Ann3Ann3NonEntGainCalcVncThresh;/* '<S2018>/TOP' */
    real32_T Ann3Ann3NonEntVncAppliedNum[2];/* '<S2043>/num' */
    real32_T Ann3Ann3NonEntVncAppliedden[2];/* '<S2043>/den' */
    real32_T Ann3Ann3VolumeRampRate;   /* '<S2071>/TOP' */
    real32_T Ann3Ann3VolumeRampTime;   /* '<S2072>/TOP' */
    real32_T Ann3Ann3VolumeTable_dB[16];/* '<S2015>/TOP_GainDB' */
    real32_T Ann3LevelDetectFastDecayDbPerSample;/* '<S1831>/TOP' */
    real32_T Ann3LevelDetectHoldMarginDb;/* '<S1832>/TOP' */
    real32_T Ann3LevelDetectHoldTimeSamples;/* '<S1833>/TOP' */
    real32_T Ann3LevelDetectMaxVolumeDb;/* '<S1834>/TOP' */
    real32_T Ann3LevelDetectMinVolumeDb;/* '<S1835>/TOP' */
    real32_T Ann3LevelDetectSlowDecayDbPerSample;/* '<S1836>/TOP' */
    real32_T Ann4Ann4MuteRampTime;     /* '<S2128>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcBoostOverRide;/* '<S2103>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcBoostOverRideFlag;/* '<S2104>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcDen[2];/* '<S2106>/den' */
    real32_T Ann4Ann4NonEntGainCalcMaxBoost;/* '<S2100>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcMaxSpl;/* '<S2119>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcMinVncSignal;/* '<S2118>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcNoiseOverRide;/* '<S2101>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcNoiseOverRideFlag;/* '<S2102>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcNum[2];/* '<S2106>/num' */
    real32_T Ann4Ann4NonEntGainCalcVncEnableTuneVar;/* '<S2105>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcVncSlope;/* '<S2099>/TOP' */
    real32_T Ann4Ann4NonEntGainCalcVncThresh;/* '<S2098>/TOP' */
    real32_T Ann4Ann4NonEntVncAppliedNum[2];/* '<S2123>/num' */
    real32_T Ann4Ann4NonEntVncAppliedden[2];/* '<S2123>/den' */
    real32_T Ann4Ann4VolumeRampRate;   /* '<S2151>/TOP' */
    real32_T Ann4Ann4VolumeRampTime;   /* '<S2152>/TOP' */
    real32_T Ann4Ann4VolumeTable_dB[16];/* '<S2095>/TOP_GainDB' */
    real32_T Ann4LevelDetectFastDecayDbPerSample;/* '<S1839>/TOP' */
    real32_T Ann4LevelDetectHoldMarginDb;/* '<S1840>/TOP' */
    real32_T Ann4LevelDetectHoldTimeSamples;/* '<S1841>/TOP' */
    real32_T Ann4LevelDetectMaxVolumeDb;/* '<S1842>/TOP' */
    real32_T Ann4LevelDetectMinVolumeDb;/* '<S1843>/TOP' */
    real32_T Ann4LevelDetectSlowDecayDbPerSample;/* '<S1844>/TOP' */
    real32_T Coefficients[164];        /* '<S1764>/TOP' */
    real32_T Dr_PoolIirTunablepooliirCoeffs[404];/* '<S1639>/TOP1' */
    real32_T Dr_PooliirpooliirCoeffs[407];/* '<S1620>/TOP1' */
    real32_T Dr_eqdelays[4];           /* '<S1637>/TOP' */
    real32_T Dr_mix[875];              /* '<S1667>/TOP' */
    real32_T Fr_PoolIirTunablepooliirCoeffs[404];/* '<S1697>/TOP1' */
    real32_T Fr_PooliirpooliirCoeffs[405];/* '<S1678>/TOP1' */
    real32_T Fr_eqdelays[4];           /* '<S1695>/TOP' */
    real32_T Fr_mix[225];              /* '<S1725>/TOP' */
    real32_T LevelDetectPreEmphasisShelfFilterpooliirCoeffs[10];/* '<S1799>/TOP1' */
    real32_T LevelDetectSysMaxDbspl;   /* '<S1798>/TOP' */
    real32_T RampDbPerSample;          /* '<S1734>/TOP' */
    uint32_T Ann1Ann1VolumeTable_Idx[16];/* '<S1855>/TOP_Index' */
    uint32_T Ann2Ann2VolumeTable_Idx[16];/* '<S1935>/TOP_Index' */
    uint32_T Ann3Ann3VolumeTable_Idx[16];/* '<S2015>/TOP_Index' */
    uint32_T Ann4Ann4VolumeTable_Idx[16];/* '<S2095>/TOP_Index' */
    uint32_T Dr_PoolIirTunablePooliirNumStages[4];/* '<S1639>/TOP' */
    uint32_T Dr_PooliirPooliirNumStages[7];/* '<S1620>/TOP' */
    uint32_T Fr_PoolIirTunablePooliirNumStages[4];/* '<S1697>/TOP' */
    uint32_T Fr_PooliirPooliirNumStages[5];/* '<S1678>/TOP' */
    uint32_T LevelDetectPreEmphasisShelfFilterPooliirNumStages[2];/* '<S1799>/TOP' */
    uint32_T NumStages[4];             /* '<S1764>/TOP1' */
}
Model_Target_Near_p0_b0_type;

typedef struct Model_Target_PostProcess_p0_b0_tag
{
    real32_T Limiterattack[24];        /* '<S2216>/attack' */
    real32_T Limiterattack_low[24];    /* '<S2216>/attack1' */
    real32_T Limiterdecay[24];         /* '<S2216>/decay' */
    real32_T Limiterdecay_low[24];     /* '<S2216>/decay1' */
    real32_T Limiterk1[24];            /* '<S2216>/k1' */
    real32_T Limiterk1_low[24];        /* '<S2216>/k2' */
    real32_T LimitermaxAttack[24];     /* '<S2216>/maxAttack' */
    real32_T LimitermaxAttack_low[24]; /* '<S2216>/maxAttack1' */
    real32_T MuteRampTime;             /* '<S2223>/TOP' */
    real32_T PostLimiterEqpooliirCoeffs[536];/* '<S2243>/TOP1' */
    real32_T SoftClipperp2;            /* '<S2268>/p2 TOP' */
    real32_T SoftClipperp2_low;        /* '<S2268>/p2 TOP1' */
    real32_T SoftClipperxmax;          /* '<S2268>/xmax TOP' */
    real32_T SoftClipperxmax_low;      /* '<S2268>/xmax TOP1' */
    real32_T SoftClipperxmin;          /* '<S2268>/xmin TOP' */
    real32_T SoftClipperxmin_low;      /* '<S2268>/xmin TOP1' */
    uint32_T PostLimiterEqPooliirNumStages[24];/* '<S2243>/TOP' */
}
Model_Target_PostProcess_p0_b0_type;

typedef struct Model_Target_PreAmp_p0_b0_tag
{
    real32_T A;                        /* '<S1568>/TOP' */
    real32_T AnnPred;                  /* '<S1575>/TOP' */
    real32_T BassBoostCoeffs[3];       /* '<S1523>/BoostCoeffs' */
    real32_T BassBoostMaximum_dB;      /* '<S1523>/Boost_dB TOP' */
    real32_T BassCutCoeffs[3];         /* '<S1523>/CutCoeffs' */
    real32_T BassCutMaximum_dB;        /* '<S1523>/Cut_dB TOP' */
    real32_T BassOffset;               /* '<S1531>/TOP' */
    real32_T BassScale;                /* '<S1533>/TOP' */
    real32_T Bassramptime;             /* '<S1532>/TOP' */
    real32_T G;                        /* '<S1572>/TOP' */
    real32_T Limiterattack[32];        /* '<S1576>/attack' */
    real32_T Limiterdecay[32];         /* '<S1576>/decay' */
    real32_T LimitermaxAttack[32];     /* '<S1576>/maxAttack' */
    real32_T MidrangeBoostCoeffs[5];   /* '<S1524>/BoostCoeffs' */
    real32_T MidrangeBoostMaximum_dB;  /* '<S1524>/Boost_dB TOP' */
    real32_T MidrangeCutCoeffs[5];     /* '<S1524>/CutCoeffs' */
    real32_T MidrangeCutMaximum_dB;    /* '<S1524>/Cut_dB TOP' */
    real32_T MidrangeOffset;           /* '<S1549>/TOP' */
    real32_T MidrangeRampTime;         /* '<S1550>/TOP' */
    real32_T MidrangeScale;            /* '<S1551>/TOP' */
    real32_T Offset;                   /* '<S1577>/TOP' */
    real32_T TrebleBoostCoeffs[3];     /* '<S1526>/BoostCoeffs' */
    real32_T TrebleBoostMaximum_dB;    /* '<S1526>/Boost_dB TOP' */
    real32_T TrebleCutCoeffs[3];       /* '<S1526>/CutCoeffs' */
    real32_T TrebleCutMaximum_dB;      /* '<S1526>/Cut_dB TOP' */
    real32_T TrebleOffset;             /* '<S1585>/TOP' */
    real32_T TrebleScale;              /* '<S1587>/TOP' */
    real32_T Trebleramptime;           /* '<S1586>/TOP' */
    real32_T UpperThreshold;           /* '<S1578>/TOP' */
}
Model_Target_PreAmp_p0_b0_type;

typedef struct Model_Target_PreAmp_p10_b0_tag
{
    int32_T VLSXtalkCancellationDelay[16];/* '<S1479>/TOP' */
    real32_T VLSXtalkCancellationIIRpooliirCoeffs[976];/* '<S1482>/TOP1' */
    uint32_T VLSGenerationDrvPaddedFilterLengths[20];/* '<S1473>/TOP2' */
    uint32_T VLSGenerationPaxPaddedFilterLengths[20];/* '<S1474>/TOP2' */
    uint32_T VLSXtalkCancellationIIRPooliirNumStages[16];/* '<S1482>/TOP' */
}
Model_Target_PreAmp_p10_b0_type;

typedef struct Model_Target_PreAmp_p10_b1_tag
{
    real32_T VLSGenerationDrvFIRCoeffs[5760];/* '<S1473>/TOP' */
    real32_T VLSGenerationPaxFIRCoeffs[5760];/* '<S1474>/TOP' */
}
Model_Target_PreAmp_p10_b1_type;

typedef struct Model_Target_PreAmp_p11_b0_tag
{
    real32_T Balance_CfgBoostDisable;  /* '<S568>/TOP' */
    real32_T Balance_CfgChanRampMap[2];/* '<S563>/TOP' */
    real32_T Balance_CfgEnableSilentExtreme;/* '<S572>/TOP' */
    real32_T Balance_CfgOffset;        /* '<S569>/TOP' */
    real32_T Balance_CfgRampTime;      /* '<S570>/TOP' */
    real32_T Balance_CfgSleepingBeautyMutesBass;/* '<S571>/TOP' */
    real32_T Balance_CfgTableDb[30];   /* '<S573>/TOP_TableIDb' */
    real32_T Balance_CfgTableIdx[30];  /* '<S573>/TOP_TableIdx' */
}
Model_Target_PreAmp_p11_b0_type;

typedef struct Model_Target_PreAmp_p13_b0_tag
{
    real32_T NearDelay;                /* '<S1334>/TOP' */
    real32_T NearWiggleCoeffs[2048];   /* '<S1333>/TOP' */
}
Model_Target_PreAmp_p13_b0_type;

typedef struct Model_Target_PreAmp_p1_b0_tag
{
    real32_T MedusaRoutingMap[24];     /* '<S1303>/TOP' */
}
Model_Target_PreAmp_p1_b0_type;

typedef struct Model_Target_PreAmp_p2_b0_tag
{
    real32_T MedusaBassManagerGainLfe2C;/* '<S597>/TOP' */
    real32_T MedusaBassManagerHpfpooliirCoeffs[26];/* '<S600>/TOP1' */
    real32_T MedusaBassManagerLeftMixWeights;/* '<S594>/LeftMixWeight' */
    real32_T MedusaBassManagerLpfpooliirCoeffs[26];/* '<S615>/TOP1' */
    real32_T MedusaBassManagerRightMixWeights;/* '<S594>/RightMixWeight' */
    real32_T MedusaDummyTune;          /* '<S633>/TOP' */
    uint32_T MedusaBassManagerHpfPooliirNumStages[2];/* '<S600>/TOP' */
    uint32_T MedusaBassManagerLpfPooliirNumStages[2];/* '<S615>/TOP' */
}
Model_Target_PreAmp_p2_b0_type;

typedef struct Model_Target_PreAmp_p3_b0_tag
{
    int32_T MedusaMonoDetectorEnable;  /* '<S838>/TOP' */
    int32_T MedusaTrebleDelay;         /* '<S651>/Treble Delay' */
    real32_T MedusaDeciRateFdpCoeffsESDLowerbounddB;/* '<S670>/TOP3' */
    real32_T MedusaDeciRateFdpCoeffsESDStepSize;/* '<S670>/TOP4' */
    real32_T MedusaDeciRateFdpCoeffsESDUpperbounddB;/* '<S670>/TOP2' */
    real32_T MedusaDeciRateFdpCoeffsLokRokMaxScaleFactor;/* '<S670>/TOP1' */
    real32_T MedusaDeciRateFdpCoeffsXpMax;/* '<S670>/TOP' */
    real32_T MedusaDeciRateFdpCoeffsXpMin;/* '<S670>/TOP5' */
    real32_T MedusaDeciRateFdpSpumDirectPathSamplesDec;/* '<S660>/TOP3' */
    real32_T MedusaDeciRateFdpSpumFastPsdSmoothFactor;/* '<S660>/TOP' */
    real32_T MedusaDeciRateFdpSpumLsSmoothFactor;/* '<S660>/TOP4' */
    real32_T MedusaDeciRateFdpSpumOverwrite;/* '<S658>/TOP' */
    real32_T MedusaDeciRateFdpSpumSlowPsdSmoothFactor;/* '<S660>/TOP1' */
    real32_T MedusaFullRateFdpCoeffsESDLowerbounddB;/* '<S765>/TOP3' */
    real32_T MedusaFullRateFdpCoeffsESDStepSize;/* '<S765>/TOP4' */
    real32_T MedusaFullRateFdpCoeffsESDUpperbounddB;/* '<S765>/TOP2' */
    real32_T MedusaFullRateFdpCoeffsLokRokMaxScaleFactor;/* '<S765>/TOP1' */
    real32_T MedusaFullRateFdpCoeffsXpMax;/* '<S765>/TOP' */
    real32_T MedusaFullRateFdpCoeffsXpMin;/* '<S765>/TOP5' */
    real32_T MedusaFullRateFdpSpumDirectPathSamplesDec;/* '<S756>/TOP3' */
    real32_T MedusaFullRateFdpSpumFastPsdSmoothFactor;/* '<S756>/TOP' */
    real32_T MedusaFullRateFdpSpumLsSmoothFactor;/* '<S756>/TOP4' */
    real32_T MedusaFullRateFdpSpumOverwrite;/* '<S754>/TOP' */
    real32_T MedusaFullRateFdpSpumSlowPsdSmoothFactor;/* '<S756>/TOP1' */
    real32_T MedusaMonoDetectorHPFCoeffs[10];/* '<S842>/TOP11' */
    real32_T MedusaMonoDetectorLRMatchTolerance;/* '<S842>/TOP7' */
    real32_T MedusaMonoDetectorLSSmoothGain;/* '<S842>/TOP3' */
    real32_T MedusaMonoDetectorLSSmoothPole;/* '<S842>/TOP2' */
    real32_T MedusaMonoDetectorLSSmoothResetGain;/* '<S842>/TOP5' */
    real32_T MedusaMonoDetectorLSSmoothResetPole;/* '<S842>/TOP4' */
    real32_T MedusaMonoDetectorLevelGain;/* '<S842>/TOP1' */
    real32_T MedusaMonoDetectorLevelPole;/* '<S842>/TOP' */
    real32_T MedusaMonoDetectorThresholdMono;/* '<S842>/TOP8' */
    real32_T MedusaMonoDetectorThresholdStereo;/* '<S842>/TOP9' */
    real32_T MedusaMonoDetectorThresholdZeroLevel;/* '<S842>/TOP6' */
    real32_T MedusaSPUMDecayEstDecaySmoothFactor;/* '<S856>/TOP1' */
    real32_T MedusaSPUMDecayEstDirectPathFramesFs;/* '<S856>/TOP6' */
    real32_T MedusaSPUMDecayEstFastAttack;/* '<S856>/TOP2' */
    real32_T MedusaSPUMDecayEstHPFpooliirCoeffs[50];/* '<S870>/TOP1' */
    real32_T MedusaSPUMDecayEstNoiseFloor;/* '<S863>/TOP' */
    real32_T MedusaSPUMDecayEstOnsetThreshold;/* '<S864>/TOP' */
    real32_T MedusaSPUMDecayEstPSDSmoothFactor;/* '<S856>/TOP' */
    real32_T MedusaSPUMDecayEstSlewThreshold;/* '<S865>/TOP' */
    real32_T MedusaSPUMDecayEstSlowAttack;/* '<S856>/TOP3' */
    real32_T MedusaSPUMDecayEstStepDecrement;/* '<S856>/TOP5' */
    real32_T MedusaSPUMDecayEstStepIncrement;/* '<S856>/TOP4' */
    uint32_T MedusaMonoDetectorHPFNumStages[2];/* '<S842>/TOP10' */
    uint32_T MedusaSPUMDecayEstHPFPooliirNumStages[2];/* '<S870>/TOP' */
}
Model_Target_PreAmp_p3_b0_type;

typedef struct Model_Target_PreAmp_p4_b0_tag
{
    int32_T AudiopilotHfNoiseRefLatencySamples;/* '<S348>/TOP' */
    int32_T AudiopilotLfNoiseRefLatencySamples;/* '<S430>/TOP' */
    int32_T AudiopilotMidrangeLpfAlignDelaySamples;/* '<S82>/TOP' */
    int32_T LevelDetectMusicDelaySamples;/* '<S514>/TOP' */
    real32_T AudiopilotAntiZipperRampLpfDenominator[2];/* '<S72>/TOP1' */
    real32_T AudiopilotAntiZipperRampLpfNumerator;/* '<S72>/TOP' */
    real32_T AudiopilotBassBpfDenominator[3];/* '<S76>/TOP1' */
    real32_T AudiopilotBassBpfNumerator[3];/* '<S76>/TOP' */
    real32_T AudiopilotBassDownwardSlopeDbPerDb;/* '<S130>/TOP1' */
    real32_T AudiopilotBassDownwardThreshDbspl;/* '<S125>/TOP' */
    real32_T AudiopilotBassMaxAudiopilotBoostDb;/* '<S126>/TOP' */
    real32_T AudiopilotBassMaxDyneqBoostDb;/* '<S127>/TOP' */
    real32_T AudiopilotBassMaxTotalBoostDb;/* '<S128>/TOP' */
    real32_T AudiopilotBassSlope0Dbperdb;/* '<S112>/TOP' */
    real32_T AudiopilotBassSlope1Dbperdb;/* '<S112>/TOP3' */
    real32_T AudiopilotBassThresh0Db;  /* '<S113>/TOP' */
    real32_T AudiopilotBassThresh1Db;  /* '<S114>/TOP' */
    real32_T AudiopilotDyneqBassSlopeDbPerDb;/* '<S132>/TOP' */
    real32_T AudiopilotDyneqBassThreshDbspl;/* '<S131>/TOP' */
    real32_T AudiopilotEnableRampCoef; /* '<S231>/TOP' */
    real32_T AudiopilotHfNoiseHighBoundDbspl;/* '<S116>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionFlatnessHighIndex;/* '<S302>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionFlatnessLowIndex;/* '<S303>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionFlatnessThresh;/* '<S304>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionLevelUpdateCoef;/* '<S308>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinSearchCoef;/* '<S305>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinSearchMinGain;/* '<S306>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor;/* '<S294>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinstatAlphaMin;/* '<S295>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinstatBeta;/* '<S298>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionMinstatMin;/* '<S299>/TOP' */
    real32_T AudiopilotHfNoiseImpulseRejectionSubWinLenSamples;/* '<S307>/TOP' */
    real32_T AudiopilotHfNoiseLowBoundDbspl;/* '<S117>/TOP' */
    real32_T AudiopilotHfNoiseOffsetDb;/* '<S285>/TOP' */
    real32_T AudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs[45];/* '<S316>/TOP1' */
    real32_T AudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs[77];/* '<S332>/TOP1' */
    real32_T AudiopilotHfNoiseRefPowerMin;/* '<S263>/RefPowerMin' */
    real32_T AudiopilotHfNoiseSlewAttackDbPerSample;/* '<S310>/TOP' */
    real32_T AudiopilotHfNoiseSlewDecayDbPerSample;/* '<S311>/TOP' */
    real32_T AudiopilotHfNoiseSlewThresholdDb;/* '<S312>/TOP' */
    real32_T AudiopilotHvacTable[32];  /* '<S49>/TOP' */
    real32_T AudiopilotLevelDetectFastDecayDbPerSample;/* '<S488>/TOP' */
    real32_T AudiopilotLevelDetectHoldMarginDb;/* '<S489>/TOP' */
    real32_T AudiopilotLevelDetectHoldTimeSamples;/* '<S490>/TOP' */
    real32_T AudiopilotLevelDetectMaxVolumeDb;/* '<S492>/TOP' */
    real32_T AudiopilotLevelDetectMinVolumeDb;/* '<S493>/TOP' */
    real32_T AudiopilotLevelDetectSlowDecayDbPerSample;/* '<S494>/TOP' */
    real32_T AudiopilotLfNoiseEnergyLpfCoef;/* '<S351>/TOP' */
    real32_T AudiopilotLfNoiseHighBoundDbspl;/* '<S118>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionGamma0;/* '<S383>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef;/* '<S386>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionImpulseVarianceScale;/* '<S387>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionMusicVarianceScale;/* '<S389>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionNoiseVarianceScale;/* '<S392>/TOP' */
    real32_T AudiopilotLfNoiseImpulseRejectionOutputMin;/* '<S393>/TOP' */
    real32_T AudiopilotLfNoiseLowBoundDbspl;/* '<S119>/TOP' */
    real32_T AudiopilotLfNoiseMicpooliirCoeffs[13];/* '<S398>/TOP1' */
    real32_T AudiopilotLfNoiseOffsetDb;/* '<S360>/TOP' */
    real32_T AudiopilotLfNoiseRefpooliirCoeffs[13];/* '<S414>/TOP1' */
    real32_T AudiopilotLfNoiseSlewAttackDbPerSample;/* '<S435>/TOP' */
    real32_T AudiopilotLfNoiseSlewDecayDbPerSample;/* '<S436>/TOP' */
    real32_T AudiopilotLfNoiseSlewSlowDbPerSample;/* '<S438>/TOP' */
    real32_T AudiopilotLfNoiseSlewThresholdDb;/* '<S439>/TOP' */
    real32_T AudiopilotLfNoiseSpeedBoundsAxis[128];/* '<S444>/TOP' */
    real32_T AudiopilotLfNoiseSpeedBoundsMaxDbspl[128];/* '<S445>/TOP' */
    real32_T AudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl;/* '<S446>/TOP1' */
    real32_T AudiopilotLfNoiseSpeedBoundsMinDbspl[128];/* '<S446>/TOP' */
    real32_T AudiopilotLfNoiseSpeedBoundsOn;/* '<S447>/TOP' */
    real32_T AudiopilotLfNoiseSysMaxDbspl;/* '<S367>/TOP' */
    real32_T AudiopilotMidrangeDownwardSlopeDbPerDb;/* '<S130>/TOP' */
    real32_T AudiopilotMidrangeDownwardThreshDbspl;/* '<S134>/TOP' */
    real32_T AudiopilotMidrangeLpfDenominator[5];/* '<S77>/TOP1' */
    real32_T AudiopilotMidrangeLpfNumerator[5];/* '<S77>/TOP' */
    real32_T AudiopilotMidrangeMaxTotalBoostDb;/* '<S135>/TOP' */
    real32_T AudiopilotMidrangeSlope0Dbperdb;/* '<S112>/TOP1' */
    real32_T AudiopilotMidrangeSlope1Dbperdb;/* '<S112>/TOP4' */
    real32_T AudiopilotMidrangeThresh0Db;/* '<S120>/TOP' */
    real32_T AudiopilotMidrangeThresh1Db;/* '<S121>/TOP' */
    real32_T AudiopilotMinSignalLevelDbspl;/* '<S172>/TOP' */
    real32_T AudiopilotRatioEnergyLpfCoef;/* '<S449>/TOP' */
    real32_T AudiopilotRatioHighBoundDb;/* '<S450>/TOP' */
    real32_T AudiopilotRatioImpulseRejectionGamma0;/* '<S469>/TOP' */
    real32_T AudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef;/* '<S470>/TOP' */
    real32_T AudiopilotRatioImpulseRejectionImpulseVarianceScale;/* '<S471>/TOP' */
    real32_T AudiopilotRatioImpulseRejectionNoiseVarianceScale;/* '<S472>/TOP' */
    real32_T AudiopilotRatioLowBoundDb;/* '<S451>/TOP' */
    real32_T AudiopilotRatioSlewAttackDbPerSample;/* '<S465>/TOP' */
    real32_T AudiopilotRatioSlewDecayDbPerSample;/* '<S466>/TOP' */
    real32_T AudiopilotRatioSlewThresholdDb;/* '<S467>/TOP' */
    real32_T AudiopilotRatioUpdateFlagHoldTimeSamples;/* '<S458>/TOP' */
    real32_T AudiopilotRatioUpdateHfNoiseThreshDbspl;/* '<S459>/TOP' */
    real32_T AudiopilotRatioUpdateLfNoiseThreshDbspl;/* '<S460>/TOP' */
    real32_T AudiopilotRatioUpdateLfNoiseUpdatePeriodSamples;/* '<S461>/TOP' */
    real32_T AudiopilotRatioUpdateLfNoiseUpdateThreshDb;/* '<S462>/TOP' */
    real32_T AudiopilotRatioUpdateSpeedUpdateThreshMph;/* '<S463>/TOP' */
    real32_T AudiopilotTrebleDownwardSlopeDbPerDb;/* '<S130>/TOP3' */
    real32_T AudiopilotTrebleDownwardThreshDbspl;/* '<S136>/TOP' */
    real32_T AudiopilotTrebleMaxTotalBoostDb;/* '<S137>/TOP' */
    real32_T AudiopilotTrebleSlope0Dbperdb;/* '<S112>/TOP2' */
    real32_T AudiopilotTrebleSlope1Dbperdb;/* '<S112>/TOP5' */
    real32_T AudiopilotTrebleThresh0Db;/* '<S123>/TOP' */
    real32_T AudiopilotTrebleThresh1Db;/* '<S124>/TOP' */
    real32_T DyneqLevelDetectFastDecayDbPerSample;/* '<S501>/TOP' */
    real32_T DyneqLevelDetectHoldMarginDb;/* '<S502>/TOP' */
    real32_T DyneqLevelDetectHoldTimeSamples;/* '<S503>/TOP' */
    real32_T DyneqLevelDetectMaxVolumeDb;/* '<S505>/TOP' */
    real32_T DyneqLevelDetectMinVolumeDb;/* '<S506>/TOP' */
    real32_T DyneqLevelDetectSlowDecayDbPerSample;/* '<S507>/TOP' */
    real32_T LevelDetectPreemphasispooliirCoeffs[10];/* '<S519>/TOP1' */
    real32_T LevelDetectSysMaxDbspl;   /* '<S517>/TOP' */
    real32_T VolumeCfgRampTime;        /* '<S538>/TOP' */
    real32_T VolumeCfgTable_dB[8];     /* '<S534>/TOP_GainDB' */
    real32_T VolumeCfgmaxgain;         /* '<S541>/TOP' */
    uint32_T AudiopilotHfNoisePreprocessAntiAliasPooliirNumStages[5];/* '<S316>/TOP' */
    uint32_T AudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages[5];/* '<S332>/TOP' */
    uint32_T AudiopilotLfNoiseMicPooliirNumStages;/* '<S398>/TOP' */
    uint32_T AudiopilotLfNoiseRefPooliirNumStages;/* '<S414>/TOP' */
    uint32_T AudiopilotTwoDowngrade;   /* '<S42>/TOP' */
    uint32_T LevelDetectPreemphasisPooliirNumStages[2];/* '<S519>/TOP' */
    uint32_T VolumeCfgTable_Idx[8];    /* '<S534>/TOP_Index' */
}
Model_Target_PreAmp_p4_b0_type;

typedef struct Model_Target_PreAmp_p5_b0_tag
{
    int32_T MedusaDeciRateBassDelay;   /* '<S902>/Decimated Bass Delay' */
    int32_T MedusaFullRateBassDelay;   /* '<S902>/Full Rate Bass Delay' */
    int32_T MedusaMidrangeDelay;       /* '<S902>/Alignment Delay' */
    real32_T MedusaFullRateMixerBackwardDownmixMax;/* '<S943>/TOP' */
    real32_T MedusaFullRateMixerBackwardDownmixThreshold;/* '<S944>/TOP' */
    real32_T MedusaFullRateMixerDetentLevel_CS[12];/* '<S988>/TOP' */
    real32_T MedusaFullRateMixerDetentLevel_CS_CAE[4];/* '<S988>/TOP1' */
    real32_T MedusaFullRateMixerDetentLevel_Left[30];/* '<S989>/TOP' */
    real32_T MedusaFullRateMixerDetentLevel_Left_CAE[10];/* '<S989>/TOP1' */
    real32_T MedusaFullRateMixerDetentLevel_Right[30];/* '<S990>/TOP' */
    real32_T MedusaFullRateMixerDetentLevel_Right_CAE[10];/* '<S990>/TOP1' */
    real32_T MedusaFullRateMixerDownmixWeights_CS[12];/* '<S945>/TOP' */
    real32_T MedusaFullRateMixerDownmixWeights_CS_CAE[4];/* '<S945>/TOP1' */
    real32_T MedusaFullRateMixerDownmixWeights_Left[30];/* '<S946>/TOP' */
    real32_T MedusaFullRateMixerDownmixWeights_Left_CAE[10];/* '<S946>/TOP1' */
    real32_T MedusaFullRateMixerDownmixWeights_Right[30];/* '<S947>/TOP' */
    real32_T MedusaFullRateMixerDownmixWeights_Right_CAE[10];/* '<S947>/TOP1' */
    real32_T MedusaFullRateMixerForwardDownmixMax;/* '<S949>/TOP' */
    real32_T MedusaFullRateMixerForwardDownmixThreshold;/* '<S948>/TOP' */
    real32_T MedusaFullRateMixerInterpolation_Method;/* '<S991>/TOP' */
    real32_T MedusaFullRateMixerMaxLevel_CS[12];/* '<S992>/TOP' */
    real32_T MedusaFullRateMixerMaxLevel_CS_CAE[4];/* '<S992>/TOP1' */
    real32_T MedusaFullRateMixerMaxLevel_Left[30];/* '<S993>/TOP' */
    real32_T MedusaFullRateMixerMaxLevel_Left_CAE[10];/* '<S993>/TOP1' */
    real32_T MedusaFullRateMixerMaxLevel_Right[30];/* '<S994>/TOP' */
    real32_T MedusaFullRateMixerMaxLevel_Right_CAE[10];/* '<S994>/TOP1' */
    real32_T MedusaFullRateMixerMinLevel_CS[12];/* '<S995>/TOP' */
    real32_T MedusaFullRateMixerMinLevel_CS_CAE[4];/* '<S995>/TOP1' */
    real32_T MedusaFullRateMixerMinLevel_Left[30];/* '<S996>/TOP' */
    real32_T MedusaFullRateMixerMinLevel_Left_CAE[10];/* '<S996>/TOP1' */
    real32_T MedusaFullRateMixerMinLevel_Right[30];/* '<S997>/TOP' */
    real32_T MedusaFullRateMixerMinLevel_Right_CAE[10];/* '<S997>/TOP1' */
    real32_T MedusaPremixBackwardDownmixMax;/* '<S1052>/TOP' */
    real32_T MedusaPremixBackwardDownmixThreshold;/* '<S1053>/TOP' */
    real32_T MedusaPremixDetentLevel_CS[20];/* '<S1099>/TOP' */
    real32_T MedusaPremixDetentLevel_CS_CAE[4];/* '<S1099>/TOP1' */
    real32_T MedusaPremixDetentLevel_Left[77];/* '<S1100>/TOP' */
    real32_T MedusaPremixDetentLevel_Left_CAE[33];/* '<S1100>/TOP1' */
    real32_T MedusaPremixDetentLevel_Right[77];/* '<S1101>/TOP' */
    real32_T MedusaPremixDetentLevel_Right_CAE[33];/* '<S1101>/TOP1' */
    real32_T MedusaPremixDownmixWeights_CS[20];/* '<S1054>/TOP' */
    real32_T MedusaPremixDownmixWeights_CS_CAE[4];/* '<S1054>/TOP1' */
    real32_T MedusaPremixDownmixWeights_Left[77];/* '<S1055>/TOP' */
    real32_T MedusaPremixDownmixWeights_Left_CAE[33];/* '<S1055>/TOP1' */
    real32_T MedusaPremixDownmixWeights_Right[77];/* '<S1056>/TOP' */
    real32_T MedusaPremixDownmixWeights_Right_CAE[33];/* '<S1056>/TOP1' */
    real32_T MedusaPremixForwardDownmixMax;/* '<S1058>/TOP' */
    real32_T MedusaPremixForwardDownmixThreshold;/* '<S1057>/TOP' */
    real32_T MedusaPremixInterpolation_Method;/* '<S1102>/TOP' */
    real32_T MedusaPremixMaxLevel_CS[20];/* '<S1103>/TOP' */
    real32_T MedusaPremixMaxLevel_CS_CAE[4];/* '<S1103>/TOP1' */
    real32_T MedusaPremixMaxLevel_Left[77];/* '<S1104>/TOP' */
    real32_T MedusaPremixMaxLevel_Left_CAE[33];/* '<S1104>/TOP1' */
    real32_T MedusaPremixMaxLevel_Right[77];/* '<S1105>/TOP' */
    real32_T MedusaPremixMaxLevel_Right_CAE[33];/* '<S1105>/TOP1' */
    real32_T MedusaPremixMinLevel_CS[20];/* '<S1106>/TOP' */
    real32_T MedusaPremixMinLevel_CS_CAE[4];/* '<S1106>/TOP1' */
    real32_T MedusaPremixMinLevel_Left[77];/* '<S1107>/TOP' */
    real32_T MedusaPremixMinLevel_Left_CAE[33];/* '<S1107>/TOP1' */
    real32_T MedusaPremixMinLevel_Right[77];/* '<S1108>/TOP' */
    real32_T MedusaPremixMinLevel_Right_CAE[33];/* '<S1108>/TOP1' */
    real32_T MedusaPremixMonoSurroundCosPhi;/* '<S1010>/TOP1' */
    real32_T MedusaPremixMonoSurroundPhi;/* '<S1010>/TOP' */
    real32_T MedusaPremixMonoSurroundSinPhi;/* '<S1010>/TOP2' */
    real32_T MedusaVLSDrvGainsBackwardDownmixMax;/* '<S1137>/TOP' */
    real32_T MedusaVLSDrvGainsBackwardDownmixThreshold;/* '<S1138>/TOP' */
    real32_T MedusaVLSDrvGainsDetentLevel[12];/* '<S1152>/TOP' */
    real32_T MedusaVLSDrvGainsDownmixWeights[12];/* '<S1139>/TOP' */
    real32_T MedusaVLSDrvGainsForwardDownmixMax;/* '<S1141>/TOP' */
    real32_T MedusaVLSDrvGainsForwardDownmixThreshold;/* '<S1140>/TOP' */
    real32_T MedusaVLSDrvGainsInterpolation_Method;/* '<S1153>/TOP' */
    real32_T MedusaVLSDrvGainsMaxLevel[12];/* '<S1154>/TOP' */
    real32_T MedusaVLSDrvGainsMinLevel[12];/* '<S1155>/TOP' */
    real32_T MedusaVLSPaxGainsBackwardDownmixMax;/* '<S1162>/TOP' */
    real32_T MedusaVLSPaxGainsBackwardDownmixThreshold;/* '<S1163>/TOP' */
    real32_T MedusaVLSPaxGainsDetentLevel[12];/* '<S1177>/TOP' */
    real32_T MedusaVLSPaxGainsDownmixWeights[12];/* '<S1164>/TOP' */
    real32_T MedusaVLSPaxGainsForwardDownmixMax;/* '<S1166>/TOP' */
    real32_T MedusaVLSPaxGainsForwardDownmixThreshold;/* '<S1165>/TOP' */
    real32_T MedusaVLSPaxGainsInterpolation_Method;/* '<S1178>/TOP' */
    real32_T MedusaVLSPaxGainsMaxLevel[12];/* '<S1179>/TOP' */
    real32_T MedusaVLSPaxGainsMinLevel[12];/* '<S1180>/TOP' */
    real32_T MedusaWiggleFilter[1776]; /* '<S904>/TOP' */
    real32_T MedusatailCompEQpooliirCoeffs[164];/* '<S907>/TOP1' */
    uint32_T MedusatailCompEQPooliirNumStages[4];/* '<S907>/TOP' */
}
Model_Target_PreAmp_p5_b0_type;

typedef struct Model_Target_PreAmp_p6_b0_tag
{
    real32_T MedusaDRHoligramOutputMapping[18];/* '<S1226>/TOP' */
    real32_T MedusaDRHoligramPoolIirTunableConfigpooliirCoeffs[5346];/* '<S1210>/TOP1' */
    real32_T MedusaFRHoligramIirConfigpooliirCoeffs[726];/* '<S1228>/TOP1' */
    real32_T MedusaHeadrestCompEQIirConfigpooliirCoeffs[972];/* '<S1257>/TOP1' */
    uint32_T MedusaDRHoligramFilterLengths[66];/* '<S1198>/TOP1' */
    uint32_T MedusaDRHoligramInputMapping[66];/* '<S1225>/TOP' */
    uint32_T MedusaDRHoligramPaddedFilterLengths[66];/* '<S1198>/TOP2' */
    uint32_T MedusaDRHoligramPoolIirTunableConfigPooliirNumStages[66];/* '<S1210>/TOP' */
    uint32_T MedusaFRHoligramIirConfigPooliirNumStages[22];/* '<S1228>/TOP' */
    uint32_T MedusaHeadrestCompEQFilterLengths[12];/* '<S1193>/TOP1' */
    uint32_T MedusaHeadrestCompEQIirConfigPooliirNumStages[12];/* '<S1257>/TOP' */
    uint32_T MedusaHeadrestCompEQPaddedFilterLengths[12];/* '<S1193>/TOP2' */
}
Model_Target_PreAmp_p6_b0_type;

typedef struct Model_Target_PreAmp_p6_b1_tag
{
    real32_T MedusaDRHoligramFIRCoeffs[35112];/* '<S1198>/TOP' */
    real32_T MedusaHeadrestCompEQFIRCoeffs[6384];/* '<S1193>/TOP' */
}
Model_Target_PreAmp_p6_b1_type;

typedef struct Model_Target_PreAmp_p8_b0_tag
{
    int32_T MedusaDRSpeakerDelay[30];  /* '<S1292>/TOP5' */
    int32_T MedusaFRSpeakerDelay[22];  /* '<S1292>/TOP3' */
}
Model_Target_PreAmp_p8_b0_type;

typedef struct Model_Target_PreAmp_p9_b0_tag
{
    real32_T FadeControlBoostDisable;  /* '<S1362>/TOP' */
    real32_T FadeControlEnableSilentExtreme;/* '<S1363>/TOP' */
    real32_T FadeControlRampTime;      /* '<S1366>/TOP' */
    real32_T FadeControlTableDb[30];   /* '<S1364>/TOPDb' */
    real32_T FadeControlTableIdx[30];  /* '<S1364>/TOPIndex' */
    real32_T FadeControloffset;        /* '<S1365>/TOP' */
    real32_T FadeRamperDRChannelToRamperMap[30];/* '<S1375>/TOP_ChanRampMap' */
    real32_T FadeRamperDRTOPFilterCoefficients[3];/* '<S1375>/TOP' */
    real32_T FadeRamperFRChannelToRamperMap[22];/* '<S1382>/TOP_ChanRampMap' */
    real32_T FadeRamperFRTOPFilterCoefficients[3];/* '<S1382>/TOP' */
    real32_T MuteControlRampTime;      /* '<S1392>/TOP' */
    real32_T SleepingBeautyDRChannelToRamperMap[30];/* '<S1432>/TOP' */
    real32_T SleepingBeautyDRMutesBass;/* '<S1439>/TOP' */
    real32_T SleepingBeautyDROffset;   /* '<S1437>/TOP' */
    real32_T SleepingBeautyDRRampTime; /* '<S1438>/TOP' */
    real32_T SleepingBeautyDRTableDb[30];/* '<S1440>/TOP' */
    real32_T SleepingBeautyDRTableIdx[30];/* '<S1440>/TOP1' */
    real32_T SleepingBeautyFRChannelToRamperMap[22];/* '<S1452>/TOP' */
    real32_T SleepingBeautyFRMutesBass;/* '<S1459>/TOP' */
    real32_T SleepingBeautyFROffset;   /* '<S1457>/TOP' */
    real32_T SleepingBeautyFRRampTime; /* '<S1458>/TOP' */
    real32_T SleepingBeautyFRTableDb[30];/* '<S1460>/TOP' */
    real32_T SleepingBeautyFRTableIdx[30];/* '<S1460>/TOP1' */
}
Model_Target_PreAmp_p9_b0_type;

typedef struct Model_Target_TestRouter_p0_b0_tag
{
    int32_T ASDRouterEnableAux;        /* '<S2281>/TOP' */
    int32_T ASDRouterMainSelect[24];   /* '<S2302>/TOP' */
    int32_T AuxSelect[24];             /* '<S2271>/TOP' */
}
Model_Target_TestRouter_p0_b0_type;

extern Model_Target_InputSelect_p0_b0_type Model_Target_InputSelect_p0_b0;
extern Model_Target_Near_p0_b0_type Model_Target_Near_p0_b0;
extern Model_Target_PostProcess_p0_b0_type Model_Target_PostProcess_p0_b0;
extern Model_Target_PreAmp_p0_b0_type Model_Target_PreAmp_p0_b0;
extern Model_Target_PreAmp_p10_b0_type Model_Target_PreAmp_p10_b0;
extern Model_Target_PreAmp_p10_b1_type Model_Target_PreAmp_p10_b1;
extern Model_Target_PreAmp_p11_b0_type Model_Target_PreAmp_p11_b0;
extern Model_Target_PreAmp_p13_b0_type Model_Target_PreAmp_p13_b0;
extern Model_Target_PreAmp_p1_b0_type Model_Target_PreAmp_p1_b0;
extern Model_Target_PreAmp_p2_b0_type Model_Target_PreAmp_p2_b0;
extern Model_Target_PreAmp_p3_b0_type Model_Target_PreAmp_p3_b0;
extern Model_Target_PreAmp_p4_b0_type Model_Target_PreAmp_p4_b0;
extern Model_Target_PreAmp_p5_b0_type Model_Target_PreAmp_p5_b0;
extern Model_Target_PreAmp_p6_b0_type Model_Target_PreAmp_p6_b0;
extern Model_Target_PreAmp_p6_b1_type Model_Target_PreAmp_p6_b1;
extern Model_Target_PreAmp_p8_b0_type Model_Target_PreAmp_p8_b0;
extern Model_Target_PreAmp_p9_b0_type Model_Target_PreAmp_p9_b0;
extern Model_Target_TestRouter_p0_b0_type Model_Target_TestRouter_p0_b0;

#endif                                 /* RTW_HEADER_Model_Target_TOP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
