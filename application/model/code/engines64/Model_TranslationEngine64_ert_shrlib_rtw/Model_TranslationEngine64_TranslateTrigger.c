/*
 * File: Model_TranslationEngine64_TranslateTrigger.c
 *
 * Code generated for Simulink model 'Model_TranslationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:20:04 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdint.h>
#include "TranslateError.h"
#include "Model_TranslationEngine64_TranslateTrigger.h"
#include "Model_TranslationEngine64_TuneVar.h"
#include "Model_TranslationEngine64_TOP_RcvTrans.h"
#include "Model_TranslationEngine64_ModelCount.h"
#include <stdio.h>                     // for vsnprintf
#include <string.h>                    // for strncpy
#include <stdarg.h>                    // for variadic args (va_start)

// Translation table record
typedef void (*TranslationFunc)(void);
typedef struct TranslationRecord_tag
{
    int updated_tune_vars;             // "dirty flag" counting updated TuneVars
    TranslationFunc translation_func;  // translation function
    int tunevar_count;      // indicates how many TuneVars feed this translation
    enum TuneVarNumber *tunevars;
                              // array of TuneVar IDs that feed this translation
    int top_count;// indicates how many TOPs receive value from this translation
    enum TOP_RcvTransNumber *tops;
    // array of TOP_RcvTrans numbers that receive values from this translation
}
TranslationRecord_type;

enum TuneVarNumber
{
    ID_TuneVar_PreAmpMedusaDeciRateWiggleFilterDelaySamples,/* '<S630>/Tune Variable4' */
    ID_TuneVar_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples,/* '<S630>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaHoligramFilterAlignmentDelaySamples,/* '<S630>/Tune Variable5' */
    ID_TuneVar_PreAmpMedusatailCompEQsosCoefficients,/* '<S765>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusatailCompEQnumStages,/* '<S765>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaWiggleFilter,/* '<S763>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDeciRateWiggleFilterDelaySamples1,/* '<S753>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1,/* '<S753>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaFullRateMixerBackwardDownmixMax,/* '<S776>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerBackwardDownmixThreshold,/* '<S777>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_CS,/* '<S778>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_Left,/* '<S779>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_Right,/* '<S780>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerForwardDownmixThreshold,/* '<S781>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerForwardDownmixMax,/* '<S782>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_CS,/* '<S804>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_Left,/* '<S805>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_Right,/* '<S806>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerInterpolation_Method,/* '<S807>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_CS,/* '<S808>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_Left,/* '<S809>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_Right,/* '<S810>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_CS,/* '<S811>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_Left,/* '<S812>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_Right,/* '<S813>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMonoSurroundPhaseAngle,/* '<S848>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixBackwardDownmixMax,/* '<S852>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixBackwardDownmixThreshold,/* '<S853>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_CS,/* '<S854>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_Left,/* '<S855>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_Right,/* '<S856>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixForwardDownmixThreshold,/* '<S857>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixForwardDownmixMax,/* '<S858>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_CS,/* '<S880>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_Left,/* '<S881>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_Right,/* '<S882>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixInterpolation_Method,/* '<S883>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_CS,/* '<S884>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_Left,/* '<S885>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_Right,/* '<S886>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_CS,/* '<S887>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_Left,/* '<S888>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_Right,/* '<S889>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsBackwardDownmixMax,/* '<S924>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold,/* '<S925>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsDownmixWeights,/* '<S926>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold,/* '<S927>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsForwardDownmixMax,/* '<S928>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsDetentLevel,/* '<S944>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsInterpolation_Method,/* '<S945>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsMaxLevel,/* '<S946>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsMinLevel,/* '<S947>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsBackwardDownmixMax,/* '<S962>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold,/* '<S963>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsDownmixWeights,/* '<S964>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold,/* '<S965>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsForwardDownmixMax,/* '<S966>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsDetentLevel,/* '<S982>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsInterpolation_Method,/* '<S983>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsMaxLevel,/* '<S984>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsMinLevel,/* '<S985>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients,/* '<S1004>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaDRHoligramPoolIirTunableConfignumStages,/* '<S1004>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaDRHoligramFIRCoeffs,/* '<S1003>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDRHoligramFIRLengths,/* '<S1003>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaDRHoligramPaddedFIRLengths,/* '<S1003>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaDRHoligramInputMapping,/* '<S1009>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDRHoligramOutputMapping,/* '<S1010>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFRHoligramIirConfigsosCoefficients,/* '<S1022>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaFRHoligramIirConfignumStages,/* '<S1022>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQFIRCoeffs,/* '<S1001>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQFIRLengths,/* '<S1001>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQPaddedFIRLengths,/* '<S1001>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients,/* '<S1029>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQIirConfignumStages,/* '<S1029>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaNonHeadrestSpeakerDelaySamples,/* '<S1034>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaHeadrestDrvSpeakerDelaySamples,/* '<S1034>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaHeadrestPaxSpeakerDelaySamples,/* '<S1034>/Tune Variable4' */
    ID_TuneVar_PreAmpMedusaFRHoligramDelaySamples,/* '<S1034>/Tune Variable5' */
    ID_TuneVar_PreAmpMedusaRoutingMap, /* '<S1041>/Tune Variable' */
    ID_TuneVar_PreAmpVLSXtalkCancellationIIRsosCoefficients,/* '<S1164>/Tune Variable2' */
    ID_TuneVar_PreAmpVLSXtalkCancellationIIRnumStages,/* '<S1164>/Tune Variable1' */
    ID_TuneVar_PreAmpVLSXtalkCancellationDelay,/* '<S1162>/Tune Variable' */
    ID_TuneVar_PreAmpVLSGenerationDrvFIRCoeffs,/* '<S1159>/Tune Variable' */
    ID_TuneVar_PreAmpVLSGenerationDrvPaddedFIRLengths,/* '<S1159>/Tune Variable2' */
    ID_TuneVar_PreAmpVLSGenerationPaxFIRCoeffs,/* '<S1160>/Tune Variable' */
    ID_TuneVar_PreAmpVLSGenerationPaxPaddedFIRLengths,/* '<S1160>/Tune Variable2' */
    ID_TuneVar_PreAmpBassBoostFrequencyHz,/* '<S1178>/BoostHz' */
    ID_TuneVar_PreAmpBassCutFrequencyHz,/* '<S1178>/CutHz' */
    ID_TuneVar_PreAmpBassBoostMaximum_dB,/* '<S1178>/Boost_dB' */
    ID_TuneVar_PreAmpBassCutMaximum_dB,/* '<S1178>/Cut_dB' */
    ID_TuneVar_PreAmpBassOffset,       /* '<S1186>/Tune Variable' */
    ID_TuneVar_PreAmpBassramptime,     /* '<S1187>/Tune Variable' */
    ID_TuneVar_PreAmpBassScale,        /* '<S1188>/Tune Variable' */
    ID_TuneVar_PreAmpMidrangeBoostFrequencyHz,/* '<S1179>/BoostHz' */
    ID_TuneVar_PreAmpMidrangeBoostQValue,/* '<S1179>/Boost_Q' */
    ID_TuneVar_PreAmpMidrangeCutFrequencyHz,/* '<S1179>/CutHz' */
    ID_TuneVar_PreAmpMidrangeCutQValue,/* '<S1179>/Cut_Q' */
    ID_TuneVar_PreAmpMidrangeBoostMaximum_dB,/* '<S1179>/Boost_dB' */
    ID_TuneVar_PreAmpMidrangeCutMaximum_dB,/* '<S1179>/Cut_dB' */
    ID_TuneVar_PreAmpMidrangeOffset,   /* '<S1213>/Tune Variable' */
    ID_TuneVar_PreAmpMidrangeRampTime, /* '<S1214>/Tune Variable' */
    ID_TuneVar_PreAmpMidrangeScale,    /* '<S1215>/Tune Variable' */
    ID_TuneVar_PreAmpA,                /* '<S1239>/Tune Variable' */
    ID_TuneVar_PreAmpG,                /* '<S1247>/Tune Variable' */
    ID_TuneVar_PreAmpAnnPred,          /* '<S1252>/Tune Variable' */
    ID_TuneVar_PreAmpLimiterAttack,    /* '<S1253>/attackTune' */
    ID_TuneVar_PreAmpLimiterDecay,     /* '<S1253>/decay tune' */
    ID_TuneVar_PreAmpLimiterMaxAttack, /* '<S1253>/maxAttack tune' */
    ID_TuneVar_PreAmpOffset,           /* '<S1254>/Tune Variable' */
    ID_TuneVar_PreAmpUpperThreshold,   /* '<S1255>/Tune Variable' */
    ID_TuneVar_PreAmpTrebleBoostFrequencyHz,/* '<S1181>/BoostHz' */
    ID_TuneVar_PreAmpTrebleCutFrequencyHz,/* '<S1181>/CutHz' */
    ID_TuneVar_PreAmpTrebleBoostMaximum_dB,/* '<S1181>/Boost_dB' */
    ID_TuneVar_PreAmpTrebleCutMaximum_dB,/* '<S1181>/Cut_dB' */
    ID_TuneVar_PreAmpTrebleOffset,     /* '<S1278>/Tune Variable' */
    ID_TuneVar_PreAmpTrebleramptime,   /* '<S1279>/Tune Variable' */
    ID_TuneVar_PreAmpTrebleScale,      /* '<S1280>/Tune Variable' */
    ID_TuneVar_PostProcessLimiterAttack,/* '<S1850>/attackTune' */
    ID_TuneVar_PostProcessLimiterThreshold,/* '<S1850>/threshhold tune' */
    ID_TuneVar_PostProcessLimiterAttack_low,/* '<S1850>/attackTune1' */
    ID_TuneVar_PostProcessLimiterThreshold_low,/* '<S1850>/threshhold tune1' */
    ID_TuneVar_PostProcessLimiterDecay,/* '<S1850>/decay tune' */
    ID_TuneVar_PostProcessLimiterDecay_low,/* '<S1850>/decay tune1' */
    ID_TuneVar_PostProcessLimiterMaxAttack,/* '<S1850>/maxAttack tune' */
    ID_TuneVar_PostProcessLimiterMaxAttack_low,/* '<S1850>/maxAttack tune1' */
    ID_TuneVar_PostProcessMuteRampTime,/* '<S1871>/Tune Variable' */
    ID_TuneVar_PostProcessPostLimiterEqsosCoefficients,/* '<S1876>/Tune Variable2' */
    ID_TuneVar_PostProcessPostLimiterEqnumStages,/* '<S1876>/Tune Variable1' */
    ID_TuneVar_PostProcessSoftClipperYMax,/* '<S1880>/ymax TuneVar' */
    ID_TuneVar_PostProcessSoftClipperXMin,/* '<S1880>/xmin TuneVar' */
    ID_TuneVar_PostProcessSoftClipperYMaxLow,/* '<S1880>/ymax TuneVar1' */
    ID_TuneVar_PostProcessSoftClipperXMinLow,/* '<S1880>/xmin TuneVar1' */
    ID_TuneVar_InputSelectRouterCfgMap,/* '<S7>/TuneVarRouterMap' */
    ID_TuneVar_PreAmpMedusaSurroundOn, /* '<S598>/TuneVar' */
    ID_TuneVar_PreAmpMedusaBassManagerLeftMixWeights,/* '<S605>/LeftMixIns' */
    ID_TuneVar_PreAmpMedusaBassManagerRightMixWeights,/* '<S605>/RightMixIns' */
    ID_TuneVar_PreAmpMedusaBassManagerHpfsosCoefficients,/* '<S612>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaBassManagerHpfnumStages,/* '<S612>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaBassManagerLpfsosCoefficients,/* '<S616>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaBassManagerLpfnumStages,/* '<S616>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaBassManagerGainLfe2C,/* '<S608>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDummyTune,  /* '<S625>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpLsSmoothCutoff,/* '<S639>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff,/* '<S639>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff,/* '<S639>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpDirectPathSec,/* '<S639>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpXpMax,/* '<S639>/Tune Variable7' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsXpMin,/* '<S646>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,/* '<S646>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,/* '<S646>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpSpumOverwrite,/* '<S641>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateFdpLsSmoothCutoff,/* '<S666>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff,/* '<S666>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateFdpFastPsdSmoothCutoff,/* '<S666>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaFullRateFdpDirectPathSec,/* '<S666>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaFullRateFdpXpMax,/* '<S666>/Tune Variable7' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsXpMax,/* '<S673>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsXpMin,/* '<S673>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,/* '<S673>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,/* '<S673>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaFullRateFdpSpumOverwrite,/* '<S668>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLevelCutoff,/* '<S695>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLSSmoothCutoff,/* '<S695>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLSSmoothResetCutoff,/* '<S695>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaMonoDetectorHPFCutoff,/* '<S695>/Tune Variable7' */
    ID_TuneVar_PreAmpMedusaMonoDetectorNoiseFloordB,/* '<S695>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLRMatchTolerancedB,/* '<S695>/Tune Variable4' */
    ID_TuneVar_PreAmpMedusaMonoDetectorThresholdMonoInput,/* '<S695>/Tune Variable5' */
    ID_TuneVar_PreAmpMedusaMonoDetectorThresholdStereoInput,/* '<S695>/Tune Variable6' */
    ID_TuneVar_PreAmpMedusaMonoDetectorEnable,/* '<S694>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstPSDSmoothCutoff,/* '<S715>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstDecaySmoothCutoff,/* '<S715>/Tune Variable1' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstFastAttackCutoff,/* '<S715>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstSlowAttackCutoff,/* '<S715>/Tune Variable3' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstStepSize,/* '<S715>/Tune Variable4' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstDirectPathSec,/* '<S715>/Tune Variable5' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstNoiseFloor,/* '<S727>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstOnsetThreshold,/* '<S728>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstSlewThreshold,/* '<S729>/Tune Variable' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstHPFsosCoefficients,/* '<S748>/Tune Variable2' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstHPFnumStages,/* '<S748>/Tune Variable1' */
    ID_TuneVar_PreAmpFadeControlBoostDisable,/* '<S1068>/Tune Variable' */
    ID_TuneVar_PreAmpFadeControlEnableSilentExtreme,/* '<S1069>/Tune Variable' */
    ID_TuneVar_PreAmpFadeControlTable, /* '<S1070>/TuneVarFadeTable' */
    ID_TuneVar_PreAmpFadeControloffset,/* '<S1071>/Tune Variable' */
    ID_TuneVar_PreAmpFadeControlRampTime,/* '<S1072>/Tune Variable' */
    ID_TuneVar_PreAmpFadeRamperDRChannelToRamperMap,/* '<S1092>/TuneVarChannelRamperMap' */
    ID_TuneVar_PreAmpFadeRamperDRCutoffHz,/* '<S1092>/TuneVarCutoffHz' */
    ID_TuneVar_PreAmpFadeRamperFRChannelToRamperMap,/* '<S1099>/TuneVarChannelRamperMap' */
    ID_TuneVar_PreAmpFadeRamperFRCutoffHz,/* '<S1099>/TuneVarCutoffHz' */
    ID_TuneVar_PreAmpMuteControlRampTime,/* '<S1107>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyDRChannelToRamperMap,/* '<S1112>/TuneVarChannelRamperMap' */
    ID_TuneVar_PreAmpSleepingBeautyDROffset,/* '<S1114>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyDRRampTime,/* '<S1115>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyDRMutesBass,/* '<S1116>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyDRTaperGainTable,/* '<S1117>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyFRChannelToRamperMap,/* '<S1135>/TuneVarChannelRamperMap' */
    ID_TuneVar_PreAmpSleepingBeautyFROffset,/* '<S1137>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyFRRampTime,/* '<S1138>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyFRMutesBass,/* '<S1139>/Tune Variable' */
    ID_TuneVar_PreAmpSleepingBeautyFRTaperGainTable,/* '<S1140>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotTwoDowngrade,/* '<S22>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHvacTable,/* '<S28>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotAntiZipperRampFreqHz,/* '<S33>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassBpfCenterFreqHz,/* '<S34>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassBpfQ,/* '<S34>/Tune Variable1' */
    ID_TuneVar_PreAmpAudiopilotMidrangeLpfCutoffFreqHz,/* '<S35>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotMidrangeLpfAlignDelaySamples,/* '<S46>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,/* '<S53>/AudiopilotOn' */
    ID_TuneVar_PreAmpAudiopilotBassSlope0Dbperdb,/* '<S53>/BassSlope0' */
    ID_TuneVar_PreAmpAudiopilotMidrangeSlope0DbPerDb,/* '<S53>/MidrangeSlope0' */
    ID_TuneVar_PreAmpAudiopilotTrebleSlope0DbPerDb,/* '<S53>/TrebleSlope0' */
    ID_TuneVar_PreAmpAudiopilotBassSlope1DbPerDb,/* '<S53>/BassSlope1' */
    ID_TuneVar_PreAmpAudiopilotMidrangeSlope1DbPerDb,/* '<S53>/MidrangeSlope1' */
    ID_TuneVar_PreAmpAudiopilotTrebleSlope1DbPerDb,/* '<S53>/TrebleSlope1' */
    ID_TuneVar_PreAmpAudiopilotBassThresh0Db,/* '<S54>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassThresh1Db,/* '<S55>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseHighBoundDbspl,/* '<S56>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseLowBoundDbspl,/* '<S57>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseHighBoundDbspl,/* '<S58>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseLowBoundDbspl,/* '<S59>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotMidrangeThresh0Db,/* '<S60>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotMidrangeThresh1Db,/* '<S61>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotTrebleThresh0Db,/* '<S62>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotTrebleThresh1Db,/* '<S63>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassDownwardThreshDbspl,/* '<S122>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassMaxAudiopilotBoostDb,/* '<S123>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassMaxDyneqBoostDb,/* '<S124>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotBassMaxTotalBoostDb,/* '<S125>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotDownwardExpansionOn,/* '<S126>/DownwardExpansionOn' */
    ID_TuneVar_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb,/* '<S126>/MidrangeDownwardSlope' */
    ID_TuneVar_PreAmpAudiopilotBassDownwardSlopeDbPerDb,/* '<S126>/BassDownwardSlope' */
    ID_TuneVar_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb,/* '<S126>/TrebleDownwardSlope' */
    ID_TuneVar_PreAmpAudiopilotDyneqBassThreshDbspl,/* '<S127>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotDyneqBassSlopeDbPerDb,/* '<S128>/DyneqBassSlope' */
    ID_TuneVar_PreAmpAudiopilotDyneqOn,/* '<S128>/DyneqOn' */
    ID_TuneVar_PreAmpAudiopilotMinSignalLevelDbspl,/* '<S166>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotMidrangeDownwardThreshDbspl,/* '<S130>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotMidrangeMaxTotalBoostDb,/* '<S131>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotTrebleDownwardThreshDbspl,/* '<S132>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotTrebleMaxTotalBoostDb,/* '<S133>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotEnableRampTauS,/* '<S187>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseRefPowerMinDb,/* '<S199>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor,/* '<S210>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,/* '<S211>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta,/* '<S220>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin,/* '<S221>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex,/* '<S230>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex,/* '<S231>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh,/* '<S232>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef,/* '<S233>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain,/* '<S234>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS,/* '<S235>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,/* '<S259>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewAttackDbPerS,/* '<S264>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewDecayDbPerS,/* '<S265>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewThresholdDb,/* '<S266>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseOffsetDb,/* '<S205>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients,/* '<S284>/Tune Variable2' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages,/* '<S284>/Tune Variable1' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients,/* '<S289>/Tune Variable2' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages,/* '<S289>/Tune Variable1' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseRefLatencyMs,/* '<S293>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseEnergyLpfTauS,/* '<S297>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS,/* '<S307>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS,/* '<S308>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale,/* '<S309>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale,/* '<S310>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale,/* '<S311>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin,/* '<S312>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseMicsosCoefficients,/* '<S338>/Tune Variable2' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseMicnumStages,/* '<S338>/Tune Variable1' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefsosCoefficients,/* '<S343>/Tune Variable2' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefnumStages,/* '<S343>/Tune Variable1' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseOffsetDb,/* '<S300>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefLatencyMs,/* '<S351>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewAttackDbPerS,/* '<S357>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewDecayDbPerS,/* '<S358>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewSlowDbPerS,/* '<S359>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewThresholdDb,/* '<S360>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsAxis,/* '<S374>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl,/* '<S375>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL,/* '<S376>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsOn,/* '<S377>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSysMaxDbspl,/* '<S303>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateFlagHoldTimeS,/* '<S403>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl,/* '<S404>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl,/* '<S405>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS,/* '<S406>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb,/* '<S407>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph,/* '<S408>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioEnergyLpfTauS,/* '<S398>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioHighBoundDb,/* '<S399>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioLowBoundDb,/* '<S400>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewAttackDbPerS,/* '<S442>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewDecayDbPerS,/* '<S443>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewThresholdDb,/* '<S444>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionGamma0TauS,/* '<S455>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS,/* '<S456>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale,/* '<S457>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale,/* '<S458>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectFastDecayDbPerS,/* '<S477>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectHoldMarginDb,/* '<S478>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectHoldTimeS,/* '<S479>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectMaxVolumeDb,/* '<S480>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectMinVolumeDb,/* '<S481>/Tune Variable' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectSlowDecayDbPerS,/* '<S482>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectFastDecayDbPerS,/* '<S504>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectHoldMarginDb,/* '<S505>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectHoldTimeS,/* '<S506>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectMaxVolumeDb,/* '<S507>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectMinVolumeDb,/* '<S508>/Tune Variable' */
    ID_TuneVar_PreAmpDyneqLevelDetectSlowDecayDbPerS,/* '<S509>/Tune Variable' */
    ID_TuneVar_PreAmpLevelDetectLatencyMs,/* '<S530>/Tune Variable' */
    ID_TuneVar_PreAmpLevelDetectPreemphasissosCoefficients,/* '<S537>/Tune Variable2' */
    ID_TuneVar_PreAmpLevelDetectPreemphasisnumStages,/* '<S537>/Tune Variable1' */
    ID_TuneVar_PreAmpLevelDetectSysMaxDbspl,/* '<S532>/Tune Variable' */
    ID_TuneVar_PreAmpVolumeCfgTable,   /* '<S545>/TuneVar_Table' */
    ID_TuneVar_PreAmpVolumeCfgmaxgain, /* '<S548>/Tune Variable' */
    ID_TuneVar_PreAmpVolumeCfgRampTime,/* '<S546>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgChanRampMap,/* '<S565>/TuneVarChanRampMap' */
    ID_TuneVar_PreAmpBalance_CfgBoostDisable,/* '<S567>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgOffset,/* '<S568>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgRampTime,/* '<S569>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgSleepingBeautyMutesBass,/* '<S570>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgEnableSilentExtreme,/* '<S571>/Tune Variable' */
    ID_TuneVar_PreAmpBalance_CfgTable, /* '<S572>/TuneVarBalanceTable' */
    ID_TuneVar_PreAmpNearWiggleCoeffs, /* '<S1049>/Tune Variable' */
    ID_TuneVar_PreAmpNearDelay,        /* '<S1050>/Tune Variable' */
    ID_TuneVar_NearDr_PooliirsosCoefficients,/* '<S1313>/Tune Variable2' */
    ID_TuneVar_NearDr_PooliirnumStages,/* '<S1313>/Tune Variable1' */
    ID_TuneVar_NearDr_f1_del,          /* '<S1317>/Tune Variable' */
    ID_TuneVar_NearDr_f2_del,          /* '<S1317>/Tune Variable1' */
    ID_TuneVar_NearDr_f3_del,          /* '<S1317>/Tune Variable2' */
    ID_TuneVar_NearDr_f4_del,          /* '<S1317>/Tune Variable3' */
    ID_TuneVar_NearDr_f5_del,          /* '<S1317>/Tune Variable4' */
    ID_TuneVar_NearDr_f6_del,          /* '<S1317>/Tune Variable5' */
    ID_TuneVar_NearDr_f7_del,          /* '<S1317>/Tune Variable7' */
    ID_TuneVar_NearDr_PoolIirTunablesosCoefficients,/* '<S1323>/Tune Variable2' */
    ID_TuneVar_NearDr_PoolIirTunablenumStages,/* '<S1323>/Tune Variable1' */
    ID_TuneVar_NearDr_driver_src1,     /* '<S1327>/Tune Variable1' */
    ID_TuneVar_NearDr_driver_src2,     /* '<S1327>/Tune Variable2' */
    ID_TuneVar_NearDr_driver_src3,     /* '<S1327>/Tune Variable3' */
    ID_TuneVar_NearDr_driver_src4,     /* '<S1327>/Tune Variable4' */
    ID_TuneVar_NearDr_passenger_src1,  /* '<S1327>/Tune Variable5' */
    ID_TuneVar_NearDr_passenger_src2,  /* '<S1327>/Tune Variable7' */
    ID_TuneVar_NearDr_passenger_src3,  /* '<S1327>/Tune Variable6' */
    ID_TuneVar_NearDr_passenger_src4,  /* '<S1327>/Tune Variable8' */
    ID_TuneVar_NearDr_RouterMap,       /* '<S1331>/TuneVarRouterMap' */
    ID_TuneVar_NearDr_f1_mix,          /* '<S1336>/Tune Variable' */
    ID_TuneVar_NearDr_f2_mix,          /* '<S1336>/Tune Variable1' */
    ID_TuneVar_NearDr_f3_mix,          /* '<S1336>/Tune Variable2' */
    ID_TuneVar_NearDr_f4_mix,          /* '<S1336>/Tune Variable3' */
    ID_TuneVar_NearDr_f5_mix,          /* '<S1336>/Tune Variable4' */
    ID_TuneVar_NearDr_f6_mix,          /* '<S1336>/Tune Variable5' */
    ID_TuneVar_NearDr_f7_mix,          /* '<S1336>/Tune Variable7' */
    ID_TuneVar_NearDr_LFI0_mix,        /* '<S1337>/Tune Variable' */
    ID_TuneVar_NearDr_LFT0_mix,        /* '<S1337>/Tune Variable1' */
    ID_TuneVar_NearDr_RFI0_mix,        /* '<S1337>/Tune Variable2' */
    ID_TuneVar_NearDr_RFT0_mix,        /* '<S1337>/Tune Variable3' */
    ID_TuneVar_NearDr_LSI0_mix,        /* '<S1337>/Tune Variable4' */
    ID_TuneVar_NearDr_LST0_mix,        /* '<S1337>/Tune Variable5' */
    ID_TuneVar_NearDr_RSI0_mix,        /* '<S1337>/Tune Variable7' */
    ID_TuneVar_NearDr_RST0_mix,        /* '<S1337>/Tune Variable6' */
    ID_TuneVar_NearDr_LCI0_mix,        /* '<S1337>/Tune Variable8' */
    ID_TuneVar_NearDr_LCT0_mix,        /* '<S1337>/Tune Variable9' */
    ID_TuneVar_NearDr_RCI0_mix,        /* '<S1337>/Tune Variable10' */
    ID_TuneVar_NearDr_RCT0_mix,        /* '<S1337>/Tune Variable11' */
    ID_TuneVar_NearDr_LFI1_mix,        /* '<S1338>/Tune Variable' */
    ID_TuneVar_NearDr_LFT1_mix,        /* '<S1338>/Tune Variable1' */
    ID_TuneVar_NearDr_RFI1_mix,        /* '<S1338>/Tune Variable2' */
    ID_TuneVar_NearDr_RFT1_mix,        /* '<S1338>/Tune Variable3' */
    ID_TuneVar_NearDr_LSI1_mix,        /* '<S1338>/Tune Variable4' */
    ID_TuneVar_NearDr_LST1_mix,        /* '<S1338>/Tune Variable5' */
    ID_TuneVar_NearDr_RSI1_mix,        /* '<S1338>/Tune Variable7' */
    ID_TuneVar_NearDr_RST1_mix,        /* '<S1338>/Tune Variable6' */
    ID_TuneVar_NearDr_LCI1_mix,        /* '<S1338>/Tune Variable8' */
    ID_TuneVar_NearDr_LCT1_mix,        /* '<S1338>/Tune Variable9' */
    ID_TuneVar_NearDr_RCI1_mix,        /* '<S1338>/Tune Variable10' */
    ID_TuneVar_NearDr_RCT1_mix,        /* '<S1338>/Tune Variable11' */
    ID_TuneVar_NearDr_nv0l_mix,        /* '<S1339>/Tune Variable' */
    ID_TuneVar_NearDr_nv0r_mix,        /* '<S1339>/Tune Variable1' */
    ID_TuneVar_NearDr_nv1l_mix,        /* '<S1339>/Tune Variable2' */
    ID_TuneVar_NearDr_nv1r_mix,        /* '<S1339>/Tune Variable3' */
    ID_TuneVar_NearFr_PooliirsosCoefficients,/* '<S1350>/Tune Variable2' */
    ID_TuneVar_NearFr_PooliirnumStages,/* '<S1350>/Tune Variable1' */
    ID_TuneVar_NearFr_f1_del,          /* '<S1354>/Tune Variable' */
    ID_TuneVar_NearFr_f2_del,          /* '<S1354>/Tune Variable1' */
    ID_TuneVar_NearFr_f3_del,          /* '<S1354>/Tune Variable2' */
    ID_TuneVar_NearFr_f4_del,          /* '<S1354>/Tune Variable3' */
    ID_TuneVar_NearFr_f5_del,          /* '<S1354>/Tune Variable4' */
    ID_TuneVar_NearFr_f6_del,          /* '<S1354>/Tune Variable5' */
    ID_TuneVar_NearFr_f7_del,          /* '<S1354>/Tune Variable7' */
    ID_TuneVar_NearFr_PoolIirTunablesosCoefficients,/* '<S1360>/Tune Variable2' */
    ID_TuneVar_NearFr_PoolIirTunablenumStages,/* '<S1360>/Tune Variable1' */
    ID_TuneVar_NearFr_driver_src1,     /* '<S1364>/Tune Variable1' */
    ID_TuneVar_NearFr_driver_src2,     /* '<S1364>/Tune Variable2' */
    ID_TuneVar_NearFr_driver_src3,     /* '<S1364>/Tune Variable3' */
    ID_TuneVar_NearFr_driver_src4,     /* '<S1364>/Tune Variable4' */
    ID_TuneVar_NearFr_passenger_src1,  /* '<S1364>/Tune Variable5' */
    ID_TuneVar_NearFr_passenger_src2,  /* '<S1364>/Tune Variable7' */
    ID_TuneVar_NearFr_passenger_src3,  /* '<S1364>/Tune Variable6' */
    ID_TuneVar_NearFr_passenger_src4,  /* '<S1364>/Tune Variable8' */
    ID_TuneVar_NearFr_RouterMap,       /* '<S1368>/TuneVarRouterMap' */
    ID_TuneVar_NearFr_f1_mix,          /* '<S1373>/Tune Variable' */
    ID_TuneVar_NearFr_f2_mix,          /* '<S1373>/Tune Variable1' */
    ID_TuneVar_NearFr_f3_mix,          /* '<S1373>/Tune Variable2' */
    ID_TuneVar_NearFr_f4_mix,          /* '<S1373>/Tune Variable3' */
    ID_TuneVar_NearFr_f5_mix,          /* '<S1373>/Tune Variable4' */
    ID_TuneVar_NearFr_f6_mix,          /* '<S1373>/Tune Variable5' */
    ID_TuneVar_NearFr_f7_mix,          /* '<S1373>/Tune Variable7' */
    ID_TuneVar_NearFr_LFI0_mix,        /* '<S1374>/Tune Variable' */
    ID_TuneVar_NearFr_LFT0_mix,        /* '<S1374>/Tune Variable1' */
    ID_TuneVar_NearFr_RFI0_mix,        /* '<S1374>/Tune Variable2' */
    ID_TuneVar_NearFr_RFT0_mix,        /* '<S1374>/Tune Variable3' */
    ID_TuneVar_NearFr_LSI0_mix,        /* '<S1374>/Tune Variable4' */
    ID_TuneVar_NearFr_LST0_mix,        /* '<S1374>/Tune Variable5' */
    ID_TuneVar_NearFr_RSI0_mix,        /* '<S1374>/Tune Variable7' */
    ID_TuneVar_NearFr_RST0_mix,        /* '<S1374>/Tune Variable6' */
    ID_TuneVar_NearFr_LCI0_mix,        /* '<S1374>/Tune Variable8' */
    ID_TuneVar_NearFr_LCT0_mix,        /* '<S1374>/Tune Variable9' */
    ID_TuneVar_NearFr_RCI0_mix,        /* '<S1374>/Tune Variable10' */
    ID_TuneVar_NearFr_RCT0_mix,        /* '<S1374>/Tune Variable11' */
    ID_TuneVar_NearFr_LFI1_mix,        /* '<S1375>/Tune Variable' */
    ID_TuneVar_NearFr_LFT1_mix,        /* '<S1375>/Tune Variable1' */
    ID_TuneVar_NearFr_RFI1_mix,        /* '<S1375>/Tune Variable2' */
    ID_TuneVar_NearFr_RFT1_mix,        /* '<S1375>/Tune Variable3' */
    ID_TuneVar_NearFr_LSI1_mix,        /* '<S1375>/Tune Variable4' */
    ID_TuneVar_NearFr_LST1_mix,        /* '<S1375>/Tune Variable5' */
    ID_TuneVar_NearFr_RSI1_mix,        /* '<S1375>/Tune Variable7' */
    ID_TuneVar_NearFr_RST1_mix,        /* '<S1375>/Tune Variable6' */
    ID_TuneVar_NearFr_LCI1_mix,        /* '<S1375>/Tune Variable8' */
    ID_TuneVar_NearFr_LCT1_mix,        /* '<S1375>/Tune Variable9' */
    ID_TuneVar_NearFr_RCI1_mix,        /* '<S1375>/Tune Variable10' */
    ID_TuneVar_NearFr_RCT1_mix,        /* '<S1375>/Tune Variable11' */
    ID_TuneVar_NearFr_nv0l_mix,        /* '<S1376>/Tune Variable' */
    ID_TuneVar_NearFr_nv0r_mix,        /* '<S1376>/Tune Variable1' */
    ID_TuneVar_NearFr_nv1l_mix,        /* '<S1376>/Tune Variable2' */
    ID_TuneVar_NearFr_nv1r_mix,        /* '<S1376>/Tune Variable3' */
    ID_TuneVar_NearRampDbPerSample,    /* '<S1380>/Tune Variable' */
    ID_TuneVar_NearHpfCutoffFrequency, /* '<S1385>/HpfCutOffTuneVar' */
    ID_TuneVar_NearHpfFilterOrder,     /* '<S1385>/HpfOrderTuneVar' */
    ID_TuneVar_NearLevelDetectPreEmphasisShelfFiltersosCoefficients,/* '<S1401>/Tune Variable2' */
    ID_TuneVar_NearLevelDetectPreEmphasisShelfFilternumStages,/* '<S1401>/Tune Variable1' */
    ID_TuneVar_NearLevelDetectSysMaxDbspl,/* '<S1400>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectFastDecayDbPers,/* '<S1409>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectHoldMarginDb,/* '<S1410>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectHoldTimes,/* '<S1411>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectMaxVolumeDb,/* '<S1412>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectMinVolumeDb,/* '<S1413>/Tune Variable' */
    ID_TuneVar_NearAnn1LevelDetectSlowDecayDbPers,/* '<S1414>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectFastDecayDbPers,/* '<S1435>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectHoldMarginDb,/* '<S1436>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectHoldTimes,/* '<S1437>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectMaxVolumeDb,/* '<S1438>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectMinVolumeDb,/* '<S1439>/Tune Variable' */
    ID_TuneVar_NearAnn2LevelDetectSlowDecayDbPers,/* '<S1440>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectFastDecayDbPers,/* '<S1461>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectHoldMarginDb,/* '<S1462>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectHoldTimes,/* '<S1463>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectMaxVolumeDb,/* '<S1464>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectMinVolumeDb,/* '<S1465>/Tune Variable' */
    ID_TuneVar_NearAnn3LevelDetectSlowDecayDbPers,/* '<S1466>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectFastDecayDbPers,/* '<S1487>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectHoldMarginDb,/* '<S1488>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectHoldTimes,/* '<S1489>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectMaxVolumeDb,/* '<S1490>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectMinVolumeDb,/* '<S1491>/Tune Variable' */
    ID_TuneVar_NearAnn4LevelDetectSlowDecayDbPers,/* '<S1492>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncThresh,/* '<S1517>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncSlope,/* '<S1518>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMaxBoost,/* '<S1519>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcNoiseOverRide,/* '<S1520>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag,/* '<S1521>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcBoostOverRide,/* '<S1522>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag,/* '<S1523>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar,/* '<S1524>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcTau,/* '<S1525>/tuneVARTau' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMinVncSignal,/* '<S1562>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMaxSpl,/* '<S1563>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1NonEntVncAppliedTau,/* '<S1573>/tuneVARTau' */
    ID_TuneVar_NearAnn1Ann1MuteRampTime,/* '<S1578>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1VolumeTable,/* '<S1516>/TuneVarVolumeTable' */
    ID_TuneVar_NearAnn1Ann1VolumeRampRate,/* '<S1584>/Tune Variable' */
    ID_TuneVar_NearAnn1Ann1VolumeRampTime,/* '<S1585>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncThresh,/* '<S1600>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncSlope,/* '<S1601>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMaxBoost,/* '<S1602>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcNoiseOverRide,/* '<S1603>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag,/* '<S1604>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcBoostOverRide,/* '<S1605>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag,/* '<S1606>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar,/* '<S1607>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcTau,/* '<S1608>/tuneVARTau' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMinVncSignal,/* '<S1645>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMaxSpl,/* '<S1646>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2NonEntVncAppliedTau,/* '<S1656>/tuneVARTau' */
    ID_TuneVar_NearAnn2Ann2MuteRampTime,/* '<S1661>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2VolumeTable,/* '<S1599>/TuneVarVolumeTable' */
    ID_TuneVar_NearAnn2Ann2VolumeRampRate,/* '<S1667>/Tune Variable' */
    ID_TuneVar_NearAnn2Ann2VolumeRampTime,/* '<S1668>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncThresh,/* '<S1683>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncSlope,/* '<S1684>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMaxBoost,/* '<S1685>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcNoiseOverRide,/* '<S1686>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag,/* '<S1687>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcBoostOverRide,/* '<S1688>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag,/* '<S1689>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar,/* '<S1690>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcTau,/* '<S1691>/tuneVARTau' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMinVncSignal,/* '<S1728>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMaxSpl,/* '<S1729>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3NonEntVncAppliedTau,/* '<S1739>/tuneVARTau' */
    ID_TuneVar_NearAnn3Ann3MuteRampTime,/* '<S1744>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3VolumeTable,/* '<S1682>/TuneVarVolumeTable' */
    ID_TuneVar_NearAnn3Ann3VolumeRampRate,/* '<S1750>/Tune Variable' */
    ID_TuneVar_NearAnn3Ann3VolumeRampTime,/* '<S1751>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncThresh,/* '<S1766>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncSlope,/* '<S1767>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMaxBoost,/* '<S1768>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcNoiseOverRide,/* '<S1769>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag,/* '<S1770>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcBoostOverRide,/* '<S1771>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag,/* '<S1772>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar,/* '<S1773>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcTau,/* '<S1774>/tuneVARTau' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMinVncSignal,/* '<S1811>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMaxSpl,/* '<S1812>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4NonEntVncAppliedTau,/* '<S1822>/tuneVARTau' */
    ID_TuneVar_NearAnn4Ann4MuteRampTime,/* '<S1827>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4VolumeTable,/* '<S1765>/TuneVarVolumeTable' */
    ID_TuneVar_NearAnn4Ann4VolumeRampRate,/* '<S1833>/Tune Variable' */
    ID_TuneVar_NearAnn4Ann4VolumeRampTime,/* '<S1834>/Tune Variable' */
    ID_TuneVar_TestRouterASDRouterEnableAux,/* '<S1892>/Tune Variable' */
    ID_TuneVar_TestRouterASDRouterMainSelect,/* '<S1897>/Tune Variable' */
    ID_TuneVar_TestRouterAuxSelect,    /* '<S1888>/Tune Variable' */
    NUM_TUNEVAR_NUMBERS
};

enum TOP_RcvTransNumber
{
    ID_TOP_RcvTrans_InputSelectRouterCfgOutMap,/* '<S7>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTwoDowngrade,/* '<S22>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHvacTable,/* '<S28>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotAntiZipperRampLpfNumerator,/* '<S33>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotAntiZipperRampLpfDenominator,/* '<S33>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassBpfNumerator,/* '<S34>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassBpfDenominator,/* '<S34>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfNumerator,/* '<S35>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfDenominator,/* '<S35>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfAlignDelaySamples,/* '<S46>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassSlope0Dbperdb,/* '<S53>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeSlope0Dbperdb,/* '<S53>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleSlope0Dbperdb,/* '<S53>/TOP2' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassSlope1Dbperdb,/* '<S53>/TOP3' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeSlope1Dbperdb,/* '<S53>/TOP4' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleSlope1Dbperdb,/* '<S53>/TOP5' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassThresh0Db,/* '<S54>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassThresh1Db,/* '<S55>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseHighBoundDbspl,/* '<S56>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseLowBoundDbspl,/* '<S57>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseHighBoundDbspl,/* '<S58>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseLowBoundDbspl,/* '<S59>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeThresh0Db,/* '<S60>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeThresh1Db,/* '<S61>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleThresh0Db,/* '<S62>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleThresh1Db,/* '<S63>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassDownwardThreshDbspl,/* '<S122>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxAudiopilotBoostDb,/* '<S123>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxDyneqBoostDb,/* '<S124>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxTotalBoostDb,/* '<S125>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb,/* '<S126>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassDownwardSlopeDbPerDb,/* '<S126>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb,/* '<S126>/TOP3' */
    ID_TOP_RcvTrans_PreAmpAudiopilotDyneqBassThreshDbspl,/* '<S127>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotDyneqBassSlopeDbPerDb,/* '<S128>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMinSignalLevelDbspl,/* '<S166>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeDownwardThreshDbspl,/* '<S130>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeMaxTotalBoostDb,/* '<S131>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleDownwardThreshDbspl,/* '<S132>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleMaxTotalBoostDb,/* '<S133>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotEnableRampCoef,/* '<S187>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseRefPowerMin,/* '<S199>/RefPowerMin' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor,/* '<S210>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,/* '<S211>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta,/* '<S220>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin,/* '<S221>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex,/* '<S230>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex,/* '<S231>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh,/* '<S232>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef,/* '<S233>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain,/* '<S234>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinLenSamples,/* '<S235>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,/* '<S259>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewAttackDbPerSample,/* '<S264>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewDecayDbPerSample,/* '<S265>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewThresholdDb,/* '<S266>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseOffsetDb,/* '<S205>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessAntiAliasPooliirNumStages,/* '<S284>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs,/* '<S284>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages,/* '<S289>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs,/* '<S289>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseRefLatencySamples,/* '<S293>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseEnergyLpfCoef,/* '<S297>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0,/* '<S307>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef,/* '<S308>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale,/* '<S309>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale,/* '<S310>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale,/* '<S311>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin,/* '<S312>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseMicPooliirNumStages,/* '<S338>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseMicpooliirCoeffs,/* '<S338>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefPooliirNumStages,/* '<S343>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefpooliirCoeffs,/* '<S343>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseOffsetDb,/* '<S300>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefLatencySamples,/* '<S351>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewAttackDbPerSample,/* '<S357>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewDecayDbPerSample,/* '<S358>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewSlowDbPerSample,/* '<S359>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewThresholdDb,/* '<S360>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsAxis,/* '<S374>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl,/* '<S375>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMinDbspl,/* '<S376>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl,/* '<S376>/TOP1' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsOn,/* '<S377>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSysMaxDbspl,/* '<S303>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateFlagHoldTimeSamples,/* '<S403>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl,/* '<S404>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl,/* '<S405>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodSamples,/* '<S406>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb,/* '<S407>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph,/* '<S408>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioEnergyLpfCoef,/* '<S398>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioHighBoundDb,/* '<S399>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioLowBoundDb,/* '<S400>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewAttackDbPerSample,/* '<S442>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewDecayDbPerSample,/* '<S443>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewThresholdDb,/* '<S444>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionGamma0,/* '<S455>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef,/* '<S456>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale,/* '<S457>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale,/* '<S458>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectFastDecayDbPerSample,/* '<S477>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectHoldMarginDb,/* '<S478>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectHoldTimeSamples,/* '<S479>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectMaxVolumeDb,/* '<S480>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectMinVolumeDb,/* '<S481>/TOP' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectSlowDecayDbPerSample,/* '<S482>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectFastDecayDbPerSample,/* '<S504>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectHoldMarginDb,/* '<S505>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectHoldTimeSamples,/* '<S506>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectMaxVolumeDb,/* '<S507>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectMinVolumeDb,/* '<S508>/TOP' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectSlowDecayDbPerSample,/* '<S509>/TOP' */
    ID_TOP_RcvTrans_PreAmpLevelDetectMusicDelaySamples,/* '<S530>/TOP' */
    ID_TOP_RcvTrans_PreAmpLevelDetectPreemphasisPooliirNumStages,/* '<S537>/TOP' */
    ID_TOP_RcvTrans_PreAmpLevelDetectPreemphasispooliirCoeffs,/* '<S537>/TOP1' */
    ID_TOP_RcvTrans_PreAmpLevelDetectSysMaxDbspl,/* '<S532>/TOP' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgTable_dB,/* '<S545>/TOP_GainDB' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgTable_Idx,/* '<S545>/TOP_Index' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgmaxgain,/* '<S548>/TOP' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgRampTime,/* '<S546>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgChanRampMap,/* '<S565>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgBoostDisable,/* '<S567>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgOffset,/* '<S568>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgRampTime,/* '<S569>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgSleepingBeautyMutesBass,/* '<S570>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgEnableSilentExtreme,/* '<S571>/TOP' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgTableDb,/* '<S572>/TOP_TableIDb' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgTableIdx,/* '<S572>/TOP_TableIdx' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLeftMixWeights,/* '<S605>/LeftMixWeight' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerRightMixWeights,/* '<S605>/RightMixWeight' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerHpfPooliirNumStages,/* '<S612>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerHpfpooliirCoeffs,/* '<S612>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLpfPooliirNumStages,/* '<S616>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLpfpooliirCoeffs,/* '<S616>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerGainLfe2C,/* '<S608>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDummyTune,/* '<S625>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaTrebleDelay,/* '<S635>/Treble Delay' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsXpMax,/* '<S646>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsLokRokMaxScaleFactor,/* '<S646>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsXpMin,/* '<S646>/TOP5' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,/* '<S646>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,/* '<S646>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDStepSize,/* '<S646>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumFastPsdSmoothFactor,/* '<S643>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumSlowPsdSmoothFactor,/* '<S643>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumDirectPathSamplesDec,/* '<S643>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumLsSmoothFactor,/* '<S643>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumOverwrite,/* '<S641>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsXpMax,/* '<S673>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsLokRokMaxScaleFactor,/* '<S673>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsXpMin,/* '<S673>/TOP5' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,/* '<S673>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,/* '<S673>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDStepSize,/* '<S673>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumFastPsdSmoothFactor,/* '<S670>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumSlowPsdSmoothFactor,/* '<S670>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumDirectPathSamplesDec,/* '<S670>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumLsSmoothFactor,/* '<S670>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumOverwrite,/* '<S668>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLevelPole,/* '<S695>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLevelGain,/* '<S695>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothPole,/* '<S695>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothGain,/* '<S695>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothResetPole,/* '<S695>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothResetGain,/* '<S695>/TOP5' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorHPFNumStages,/* '<S695>/TOP10' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorHPFCoeffs,/* '<S695>/TOP11' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdZeroLevel,/* '<S695>/TOP6' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLRMatchTolerance,/* '<S695>/TOP7' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdMono,/* '<S695>/TOP8' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdStereo,/* '<S695>/TOP9' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorEnable,/* '<S694>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstPSDSmoothFactor,/* '<S715>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstDecaySmoothFactor,/* '<S715>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstFastAttack,/* '<S715>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstSlowAttack,/* '<S715>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstStepIncrement,/* '<S715>/TOP4' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstStepDecrement,/* '<S715>/TOP5' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstDirectPathFramesFs,/* '<S715>/TOP6' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstNoiseFloor,/* '<S727>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstOnsetThreshold,/* '<S728>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstSlewThreshold,/* '<S729>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstHPFPooliirNumStages,/* '<S748>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstHPFpooliirCoeffs,/* '<S748>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusatailCompEQPooliirNumStages,/* '<S765>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusatailCompEQpooliirCoeffs,/* '<S765>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaWiggleFilter,/* '<S763>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaMidrangeDelay,/* '<S758>/Alignment Delay' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateBassDelay,/* '<S758>/Decimated Bass Delay' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateBassDelay,/* '<S758>/Full Rate Bass Delay' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerBackwardDownmixMax,/* '<S776>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerBackwardDownmixThreshold,/* '<S777>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_CS,/* '<S778>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_CS_CAE,/* '<S778>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Left,/* '<S779>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Left_CAE,/* '<S779>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Right,/* '<S780>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Right_CAE,/* '<S780>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerForwardDownmixThreshold,/* '<S781>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerForwardDownmixMax,/* '<S782>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_CS,/* '<S804>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_CS_CAE,/* '<S804>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Left,/* '<S805>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Left_CAE,/* '<S805>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Right,/* '<S806>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Right_CAE,/* '<S806>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerInterpolation_Method,/* '<S807>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_CS,/* '<S808>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_CS_CAE,/* '<S808>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Left,/* '<S809>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Left_CAE,/* '<S809>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Right,/* '<S810>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Right_CAE,/* '<S810>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_CS,/* '<S811>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_CS_CAE,/* '<S811>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Left,/* '<S812>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Left_CAE,/* '<S812>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Right,/* '<S813>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Right_CAE,/* '<S813>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundPhi,/* '<S848>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundCosPhi,/* '<S848>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundSinPhi,/* '<S848>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixBackwardDownmixMax,/* '<S852>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixBackwardDownmixThreshold,/* '<S853>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_CS,/* '<S854>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_CS_CAE,/* '<S854>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Left,/* '<S855>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Left_CAE,/* '<S855>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Right,/* '<S856>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Right_CAE,/* '<S856>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixForwardDownmixThreshold,/* '<S857>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixForwardDownmixMax,/* '<S858>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_CS,/* '<S880>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_CS_CAE,/* '<S880>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Left,/* '<S881>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Left_CAE,/* '<S881>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Right,/* '<S882>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Right_CAE,/* '<S882>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixInterpolation_Method,/* '<S883>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_CS,/* '<S884>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_CS_CAE,/* '<S884>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Left,/* '<S885>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Left_CAE,/* '<S885>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Right,/* '<S886>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Right_CAE,/* '<S886>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_CS,/* '<S887>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_CS_CAE,/* '<S887>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Left,/* '<S888>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Left_CAE,/* '<S888>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Right,/* '<S889>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Right_CAE,/* '<S889>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsBackwardDownmixMax,/* '<S924>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold,/* '<S925>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsDownmixWeights,/* '<S926>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold,/* '<S927>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsForwardDownmixMax,/* '<S928>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsDetentLevel,/* '<S944>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsInterpolation_Method,/* '<S945>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsMaxLevel,/* '<S946>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsMinLevel,/* '<S947>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsBackwardDownmixMax,/* '<S962>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold,/* '<S963>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsDownmixWeights,/* '<S964>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold,/* '<S965>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsForwardDownmixMax,/* '<S966>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsDetentLevel,/* '<S982>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsInterpolation_Method,/* '<S983>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsMaxLevel,/* '<S984>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsMinLevel,/* '<S985>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPoolIirTunableConfigPooliirNumStages,/* '<S1004>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPoolIirTunableConfigpooliirCoeffs,/* '<S1004>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramFIRCoeffs,/* '<S1003>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramFilterLengths,/* '<S1003>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPaddedFilterLengths,/* '<S1003>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramInputMapping,/* '<S1009>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramOutputMapping,/* '<S1010>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFRHoligramIirConfigPooliirNumStages,/* '<S1022>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaFRHoligramIirConfigpooliirCoeffs,/* '<S1022>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQFIRCoeffs,/* '<S1001>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQFilterLengths,/* '<S1001>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQPaddedFilterLengths,/* '<S1001>/TOP2' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQIirConfigPooliirNumStages,/* '<S1029>/TOP' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQIirConfigpooliirCoeffs,/* '<S1029>/TOP1' */
    ID_TOP_RcvTrans_PreAmpMedusaFRSpeakerDelay,/* '<S1034>/TOP3' */
    ID_TOP_RcvTrans_PreAmpMedusaDRSpeakerDelay,/* '<S1034>/TOP5' */
    ID_TOP_RcvTrans_PreAmpMedusaRoutingMap,/* '<S1041>/TOP' */
    ID_TOP_RcvTrans_PreAmpNearWiggleCoeffs,/* '<S1049>/TOP' */
    ID_TOP_RcvTrans_PreAmpNearDelay,   /* '<S1050>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeControlBoostDisable,/* '<S1068>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeControlEnableSilentExtreme,/* '<S1069>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeControlTableDb,/* '<S1070>/TOPDb' */
    ID_TOP_RcvTrans_PreAmpFadeControlTableIdx,/* '<S1070>/TOPIndex' */
    ID_TOP_RcvTrans_PreAmpFadeControloffset,/* '<S1071>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeControlRampTime,/* '<S1072>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeRamperDRChannelToRamperMap,/* '<S1092>/TOP_ChanRampMap' */
    ID_TOP_RcvTrans_PreAmpFadeRamperDRTOPFilterCoefficients,/* '<S1092>/TOP' */
    ID_TOP_RcvTrans_PreAmpFadeRamperFRChannelToRamperMap,/* '<S1099>/TOP_ChanRampMap' */
    ID_TOP_RcvTrans_PreAmpFadeRamperFRTOPFilterCoefficients,/* '<S1099>/TOP' */
    ID_TOP_RcvTrans_PreAmpMuteControlRampTime,/* '<S1107>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRChannelToRamperMap,/* '<S1112>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDROffset,/* '<S1114>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRRampTime,/* '<S1115>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRMutesBass,/* '<S1116>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRTableDb,/* '<S1117>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRTableIdx,/* '<S1117>/TOP1' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRChannelToRamperMap,/* '<S1135>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFROffset,/* '<S1137>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRRampTime,/* '<S1138>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRMutesBass,/* '<S1139>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRTableDb,/* '<S1140>/TOP' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRTableIdx,/* '<S1140>/TOP1' */
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationIIRPooliirNumStages,/* '<S1164>/TOP' */
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationIIRpooliirCoeffs,/* '<S1164>/TOP1' */
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationDelay,/* '<S1162>/TOP' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationDrvFIRCoeffs,/* '<S1159>/TOP' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationDrvPaddedFilterLengths,/* '<S1159>/TOP2' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationPaxFIRCoeffs,/* '<S1160>/TOP' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationPaxPaddedFilterLengths,/* '<S1160>/TOP2' */
    ID_TOP_RcvTrans_PreAmpBassBoostCoeffs,/* '<S1178>/BoostCoeffs' */
    ID_TOP_RcvTrans_PreAmpBassCutCoeffs,/* '<S1178>/CutCoeffs' */
    ID_TOP_RcvTrans_PreAmpBassBoostMaximum_dB,/* '<S1178>/Boost_dB TOP' */
    ID_TOP_RcvTrans_PreAmpBassCutMaximum_dB,/* '<S1178>/Cut_dB TOP' */
    ID_TOP_RcvTrans_PreAmpBassOffset,  /* '<S1186>/TOP' */
    ID_TOP_RcvTrans_PreAmpBassramptime,/* '<S1187>/TOP' */
    ID_TOP_RcvTrans_PreAmpBassScale,   /* '<S1188>/TOP' */
    ID_TOP_RcvTrans_PreAmpMidrangeBoostCoeffs,/* '<S1179>/BoostCoeffs' */
    ID_TOP_RcvTrans_PreAmpMidrangeCutCoeffs,/* '<S1179>/CutCoeffs' */
    ID_TOP_RcvTrans_PreAmpMidrangeBoostMaximum_dB,/* '<S1179>/Boost_dB TOP' */
    ID_TOP_RcvTrans_PreAmpMidrangeCutMaximum_dB,/* '<S1179>/Cut_dB TOP' */
    ID_TOP_RcvTrans_PreAmpMidrangeOffset,/* '<S1213>/TOP' */
    ID_TOP_RcvTrans_PreAmpMidrangeRampTime,/* '<S1214>/TOP' */
    ID_TOP_RcvTrans_PreAmpMidrangeScale,/* '<S1215>/TOP' */
    ID_TOP_RcvTrans_PreAmpA,           /* '<S1239>/TOP' */
    ID_TOP_RcvTrans_PreAmpG,           /* '<S1247>/TOP' */
    ID_TOP_RcvTrans_PreAmpAnnPred,     /* '<S1252>/TOP' */
    ID_TOP_RcvTrans_PreAmpLimiterattack,/* '<S1253>/attack' */
    ID_TOP_RcvTrans_PreAmpLimiterdecay,/* '<S1253>/decay' */
    ID_TOP_RcvTrans_PreAmpLimitermaxAttack,/* '<S1253>/maxAttack' */
    ID_TOP_RcvTrans_PreAmpOffset,      /* '<S1254>/TOP' */
    ID_TOP_RcvTrans_PreAmpUpperThreshold,/* '<S1255>/TOP' */
    ID_TOP_RcvTrans_PreAmpTrebleBoostCoeffs,/* '<S1181>/BoostCoeffs' */
    ID_TOP_RcvTrans_PreAmpTrebleCutCoeffs,/* '<S1181>/CutCoeffs' */
    ID_TOP_RcvTrans_PreAmpTrebleBoostMaximum_dB,/* '<S1181>/Boost_dB TOP' */
    ID_TOP_RcvTrans_PreAmpTrebleCutMaximum_dB,/* '<S1181>/Cut_dB TOP' */
    ID_TOP_RcvTrans_PreAmpTrebleOffset,/* '<S1278>/TOP' */
    ID_TOP_RcvTrans_PreAmpTrebleramptime,/* '<S1279>/TOP' */
    ID_TOP_RcvTrans_PreAmpTrebleScale, /* '<S1280>/TOP' */
    ID_TOP_RcvTrans_NearDr_PooliirPooliirNumStages,/* '<S1313>/TOP' */
    ID_TOP_RcvTrans_NearDr_PooliirpooliirCoeffs,/* '<S1313>/TOP1' */
    ID_TOP_RcvTrans_NearDr_EqDelays,   /* '<S1312>/TOP' */
    ID_TOP_RcvTrans_NearDr_PoolIirTunablePooliirNumStages,/* '<S1323>/TOP' */
    ID_TOP_RcvTrans_NearDr_PoolIirTunablepooliirCoeffs,/* '<S1323>/TOP1' */
    ID_TOP_RcvTrans_NearDr_eqdelays,   /* '<S1322>/TOP' */
    ID_TOP_RcvTrans_NearDr_RouterOutMap,/* '<S1331>/TOP' */
    ID_TOP_RcvTrans_NearDr_mix,        /* '<S1335>/TOP' */
    ID_TOP_RcvTrans_NearFr_PooliirPooliirNumStages,/* '<S1350>/TOP' */
    ID_TOP_RcvTrans_NearFr_PooliirpooliirCoeffs,/* '<S1350>/TOP1' */
    ID_TOP_RcvTrans_NearFr_EqDelays,   /* '<S1349>/TOP' */
    ID_TOP_RcvTrans_NearFr_PoolIirTunablePooliirNumStages,/* '<S1360>/TOP' */
    ID_TOP_RcvTrans_NearFr_PoolIirTunablepooliirCoeffs,/* '<S1360>/TOP1' */
    ID_TOP_RcvTrans_NearFr_eqdelays,   /* '<S1359>/TOP' */
    ID_TOP_RcvTrans_NearFr_RouterOutMap,/* '<S1368>/TOP' */
    ID_TOP_RcvTrans_NearFr_mix,        /* '<S1372>/TOP' */
    ID_TOP_RcvTrans_NearRampDbPerSample,/* '<S1380>/TOP' */
    ID_TOP_RcvTrans_NearCoefficients,  /* '<S1385>/TOP' */
    ID_TOP_RcvTrans_NearNumStages,     /* '<S1385>/TOP1' */
    ID_TOP_RcvTrans_NearLevelDetectPreEmphasisShelfFilterPooliirNumStages,/* '<S1401>/TOP' */
    ID_TOP_RcvTrans_NearLevelDetectPreEmphasisShelfFilterpooliirCoeffs,/* '<S1401>/TOP1' */
    ID_TOP_RcvTrans_NearLevelDetectSysMaxDbspl,/* '<S1400>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectFastDecayDbPerSample,/* '<S1409>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetecthold_margin_db,/* '<S1410>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectHoldTimeSamples,/* '<S1411>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectMaxVolumeDb,/* '<S1412>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectMinVolumeDb,/* '<S1413>/TOP' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectSlowDecayDbPerSample,/* '<S1414>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectFastDecayDbPerSample,/* '<S1435>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectHoldMarginDb,/* '<S1436>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectHoldTimeSamples,/* '<S1437>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectMaxVolumeDb,/* '<S1438>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectMinVolumeDb,/* '<S1439>/TOP' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectSlowDecayDbPerSample,/* '<S1440>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectFastDecayDbPerSample,/* '<S1461>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectHoldMarginDb,/* '<S1462>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectHoldTimeSamples,/* '<S1463>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectMaxVolumeDb,/* '<S1464>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectMinVolumeDb,/* '<S1465>/TOP' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectSlowDecayDbPerSample,/* '<S1466>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectFastDecayDbPerSample,/* '<S1487>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectHoldMarginDb,/* '<S1488>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectHoldTimeSamples,/* '<S1489>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectMaxVolumeDb,/* '<S1490>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectMinVolumeDb,/* '<S1491>/TOP' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectSlowDecayDbPerSample,/* '<S1492>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncThresh,/* '<S1517>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncSlope,/* '<S1518>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMaxBoost,/* '<S1519>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNoiseOverRide,/* '<S1520>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag,/* '<S1521>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcBoostOverRide,/* '<S1522>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag,/* '<S1523>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar,/* '<S1524>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcDen,/* '<S1525>/den' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNum,/* '<S1525>/num' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMinVncSignal,/* '<S1562>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMaxSpl,/* '<S1563>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntVncAppliedden,/* '<S1573>/den' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntVncAppliedNum,/* '<S1573>/num' */
    ID_TOP_RcvTrans_NearAnn1Ann1MuteRampTime,/* '<S1578>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeTable_dB,/* '<S1516>/TOP_GainDB' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeTable_Idx,/* '<S1516>/TOP_Index' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeRampRate,/* '<S1584>/TOP' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeRampTime,/* '<S1585>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncThresh,/* '<S1600>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncSlope,/* '<S1601>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMaxBoost,/* '<S1602>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNoiseOverRide,/* '<S1603>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag,/* '<S1604>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcBoostOverRide,/* '<S1605>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag,/* '<S1606>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar,/* '<S1607>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcDen,/* '<S1608>/den' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNum,/* '<S1608>/num' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMinVncSignal,/* '<S1645>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMaxSpl,/* '<S1646>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntVncAppliedden,/* '<S1656>/den' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntVncAppliedNum,/* '<S1656>/num' */
    ID_TOP_RcvTrans_NearAnn2Ann2MuteRampTime,/* '<S1661>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeTable_dB,/* '<S1599>/TOP_GainDB' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeTable_Idx,/* '<S1599>/TOP_Index' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeRampRate,/* '<S1667>/TOP' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeRampTime,/* '<S1668>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncThresh,/* '<S1683>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncSlope,/* '<S1684>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMaxBoost,/* '<S1685>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNoiseOverRide,/* '<S1686>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag,/* '<S1687>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcBoostOverRide,/* '<S1688>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag,/* '<S1689>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar,/* '<S1690>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcDen,/* '<S1691>/den' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNum,/* '<S1691>/num' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMinVncSignal,/* '<S1728>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMaxSpl,/* '<S1729>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntVncAppliedden,/* '<S1739>/den' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntVncAppliedNum,/* '<S1739>/num' */
    ID_TOP_RcvTrans_NearAnn3Ann3MuteRampTime,/* '<S1744>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeTable_dB,/* '<S1682>/TOP_GainDB' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeTable_Idx,/* '<S1682>/TOP_Index' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeRampRate,/* '<S1750>/TOP' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeRampTime,/* '<S1751>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncThresh,/* '<S1766>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncSlope,/* '<S1767>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMaxBoost,/* '<S1768>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNoiseOverRide,/* '<S1769>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag,/* '<S1770>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcBoostOverRide,/* '<S1771>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag,/* '<S1772>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar,/* '<S1773>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcDen,/* '<S1774>/den' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNum,/* '<S1774>/num' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMinVncSignal,/* '<S1811>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMaxSpl,/* '<S1812>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntVncAppliedden,/* '<S1822>/den' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntVncAppliedNum,/* '<S1822>/num' */
    ID_TOP_RcvTrans_NearAnn4Ann4MuteRampTime,/* '<S1827>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeTable_dB,/* '<S1765>/TOP_GainDB' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeTable_Idx,/* '<S1765>/TOP_Index' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeRampRate,/* '<S1833>/TOP' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeRampTime,/* '<S1834>/TOP' */
    ID_TOP_RcvTrans_PostProcessLimiterattack,/* '<S1850>/attack' */
    ID_TOP_RcvTrans_PostProcessLimiterattack_low,/* '<S1850>/attack1' */
    ID_TOP_RcvTrans_PostProcessLimiterdecay,/* '<S1850>/decay' */
    ID_TOP_RcvTrans_PostProcessLimiterdecay_low,/* '<S1850>/decay1' */
    ID_TOP_RcvTrans_PostProcessLimiterk1,/* '<S1850>/k1' */
    ID_TOP_RcvTrans_PostProcessLimiterk1_low,/* '<S1850>/k2' */
    ID_TOP_RcvTrans_PostProcessLimitermaxAttack,/* '<S1850>/maxAttack' */
    ID_TOP_RcvTrans_PostProcessLimitermaxAttack_low,/* '<S1850>/maxAttack1' */
    ID_TOP_RcvTrans_PostProcessMuteRampTime,/* '<S1871>/TOP' */
    ID_TOP_RcvTrans_PostProcessPostLimiterEqPooliirNumStages,/* '<S1876>/TOP' */
    ID_TOP_RcvTrans_PostProcessPostLimiterEqpooliirCoeffs,/* '<S1876>/TOP1' */
    ID_TOP_RcvTrans_PostProcessSoftClipperp2,/* '<S1880>/p2 TOP' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmax,/* '<S1880>/xmax TOP' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmin,/* '<S1880>/xmin TOP' */
    ID_TOP_RcvTrans_PostProcessSoftClipperp2_low,/* '<S1880>/p2 TOP1' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmax_low,/* '<S1880>/xmax TOP1' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmin_low,/* '<S1880>/xmin TOP1' */
    ID_TOP_RcvTrans_TestRouterASDRouterEnableAux,/* '<S1892>/TOP' */
    ID_TOP_RcvTrans_TestRouterASDRouterMainSelect,/* '<S1897>/TOP' */
    ID_TOP_RcvTrans_TestRouterAuxSelect,/* '<S1888>/TOP' */
    NUM_TOP_RCVTRANSNUMBERS
};

// ----- Translation functions (generated in the model):
extern void
/* [PreAmpMedusaDeciRateWiggleFilterDelaySamples,PreAmpMedusaDeciRateNearWiggleFilterDelaySamples,PreAmpMedusaHoligramFilterAlignmentDelaySamples]-->[PreAmpMedusaTrebleDelay] */
    FuncTranslation_Model_141_1371(void);
                            /* Translation_Model_141_1371:'<S636>/S-Function' */
extern void
/* [PreAmpMedusatailCompEQsosCoefficients,PreAmpMedusatailCompEQnumStages]-->[PreAmpMedusatailCompEQPooliirNumStages,PreAmpMedusatailCompEQpooliirCoeffs] */
    FuncTranslation_Model_141_345_50_36(void);
                       /* Translation_Model_141_345_50_36:'<S766>/S-Function' */
extern void        /* [PreAmpMedusaWiggleFilter]-->[PreAmpMedusaWiggleFilter] */
    FuncTranslation_Model_141_346_67_18(void);
                       /* Translation_Model_141_346_67_18:'<S771>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateWiggleFilterDelaySamples1,PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1]-->[PreAmpMedusaDeciRateBassDelay,PreAmpMedusaFullRateBassDelay,PreAmpMedusaMidrangeDelay] */
    FuncTranslation_Model_141_2888(void);
                            /* Translation_Model_141_2888:'<S759>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerBackwardDownmixMax]-->[PreAmpMedusaFullRateMixerBackwardDownmixMax] */
    FuncTranslation_Model_141_2926(void);
                            /* Translation_Model_141_2926:'<S783>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerBackwardDownmixThreshold]-->[PreAmpMedusaFullRateMixerBackwardDownmixThreshold] */
    FuncTranslation_Model_141_2932(void);
                            /* Translation_Model_141_2932:'<S786>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDownmixWeights_CS]-->[PreAmpMedusaFullRateMixerDownmixWeights_CS,PreAmpMedusaFullRateMixerDownmixWeights_CS_CAE] */
    FuncTranslation_Model_141_2939(void);
                            /* Translation_Model_141_2939:'<S789>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDownmixWeights_Left]-->[PreAmpMedusaFullRateMixerDownmixWeights_Left,PreAmpMedusaFullRateMixerDownmixWeights_Left_CAE] */
    FuncTranslation_Model_141_2947(void);
                            /* Translation_Model_141_2947:'<S792>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDownmixWeights_Right]-->[PreAmpMedusaFullRateMixerDownmixWeights_Right,PreAmpMedusaFullRateMixerDownmixWeights_Right_CAE] */
    FuncTranslation_Model_141_2955(void);
                            /* Translation_Model_141_2955:'<S795>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerForwardDownmixThreshold]-->[PreAmpMedusaFullRateMixerForwardDownmixThreshold] */
    FuncTranslation_Model_141_2962(void);
                            /* Translation_Model_141_2962:'<S798>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerForwardDownmixMax]-->[PreAmpMedusaFullRateMixerForwardDownmixMax] */
    FuncTranslation_Model_141_2968(void);
                            /* Translation_Model_141_2968:'<S801>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDetentLevel_CS]-->[PreAmpMedusaFullRateMixerDetentLevel_CS,PreAmpMedusaFullRateMixerDetentLevel_CS_CAE] */
    FuncTranslation_Model_141_3372(void);
                            /* Translation_Model_141_3372:'<S814>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDetentLevel_Left]-->[PreAmpMedusaFullRateMixerDetentLevel_Left,PreAmpMedusaFullRateMixerDetentLevel_Left_CAE] */
    FuncTranslation_Model_141_3380(void);
                            /* Translation_Model_141_3380:'<S817>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerDetentLevel_Right]-->[PreAmpMedusaFullRateMixerDetentLevel_Right,PreAmpMedusaFullRateMixerDetentLevel_Right_CAE] */
    FuncTranslation_Model_141_3388(void);
                            /* Translation_Model_141_3388:'<S820>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerInterpolation_Method]-->[PreAmpMedusaFullRateMixerInterpolation_Method] */
    FuncTranslation_Model_141_3395(void);
                            /* Translation_Model_141_3395:'<S823>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMaxLevel_CS]-->[PreAmpMedusaFullRateMixerMaxLevel_CS,PreAmpMedusaFullRateMixerMaxLevel_CS_CAE] */
    FuncTranslation_Model_141_3402(void);
                            /* Translation_Model_141_3402:'<S826>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMaxLevel_Left]-->[PreAmpMedusaFullRateMixerMaxLevel_Left,PreAmpMedusaFullRateMixerMaxLevel_Left_CAE] */
    FuncTranslation_Model_141_3410(void);
                            /* Translation_Model_141_3410:'<S829>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMaxLevel_Right]-->[PreAmpMedusaFullRateMixerMaxLevel_Right,PreAmpMedusaFullRateMixerMaxLevel_Right_CAE] */
    FuncTranslation_Model_141_3418(void);
                            /* Translation_Model_141_3418:'<S832>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMinLevel_CS]-->[PreAmpMedusaFullRateMixerMinLevel_CS,PreAmpMedusaFullRateMixerMinLevel_CS_CAE] */
    FuncTranslation_Model_141_3426(void);
                            /* Translation_Model_141_3426:'<S835>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMinLevel_Left]-->[PreAmpMedusaFullRateMixerMinLevel_Left,PreAmpMedusaFullRateMixerMinLevel_Left_CAE] */
    FuncTranslation_Model_141_3434(void);
                            /* Translation_Model_141_3434:'<S838>/S-Function' */
extern void
/* [PreAmpMedusaFullRateMixerMinLevel_Right]-->[PreAmpMedusaFullRateMixerMinLevel_Right,PreAmpMedusaFullRateMixerMinLevel_Right_CAE] */
    FuncTranslation_Model_141_3442(void);
                            /* Translation_Model_141_3442:'<S841>/S-Function' */
extern void
/* [PreAmpMedusaPremixMonoSurroundPhaseAngle]-->[PreAmpMedusaPremixMonoSurroundPhi,PreAmpMedusaPremixMonoSurroundCosPhi,PreAmpMedusaPremixMonoSurroundSinPhi] */
    FuncTranslation_Model_141_3495(void);
                            /* Translation_Model_141_3495:'<S849>/S-Function' */
extern void
/* [PreAmpMedusaPremixBackwardDownmixMax]-->[PreAmpMedusaPremixBackwardDownmixMax] */
    FuncTranslation_Model_141_3596(void);
                            /* Translation_Model_141_3596:'<S859>/S-Function' */
extern void
/* [PreAmpMedusaPremixBackwardDownmixThreshold]-->[PreAmpMedusaPremixBackwardDownmixThreshold] */
    FuncTranslation_Model_141_3602(void);
                            /* Translation_Model_141_3602:'<S862>/S-Function' */
extern void
/* [PreAmpMedusaPremixDownmixWeights_CS]-->[PreAmpMedusaPremixDownmixWeights_CS,PreAmpMedusaPremixDownmixWeights_CS_CAE] */
    FuncTranslation_Model_141_3609(void);
                            /* Translation_Model_141_3609:'<S865>/S-Function' */
extern void
/* [PreAmpMedusaPremixDownmixWeights_Left]-->[PreAmpMedusaPremixDownmixWeights_Left,PreAmpMedusaPremixDownmixWeights_Left_CAE] */
    FuncTranslation_Model_141_3617(void);
                            /* Translation_Model_141_3617:'<S868>/S-Function' */
extern void
/* [PreAmpMedusaPremixDownmixWeights_Right]-->[PreAmpMedusaPremixDownmixWeights_Right,PreAmpMedusaPremixDownmixWeights_Right_CAE] */
    FuncTranslation_Model_141_3625(void);
                            /* Translation_Model_141_3625:'<S871>/S-Function' */
extern void
/* [PreAmpMedusaPremixForwardDownmixThreshold]-->[PreAmpMedusaPremixForwardDownmixThreshold] */
    FuncTranslation_Model_141_3632(void);
                            /* Translation_Model_141_3632:'<S874>/S-Function' */
extern void
/* [PreAmpMedusaPremixForwardDownmixMax]-->[PreAmpMedusaPremixForwardDownmixMax] */
    FuncTranslation_Model_141_3638(void);
                            /* Translation_Model_141_3638:'<S877>/S-Function' */
extern void
/* [PreAmpMedusaPremixDetentLevel_CS]-->[PreAmpMedusaPremixDetentLevel_CS,PreAmpMedusaPremixDetentLevel_CS_CAE] */
    FuncTranslation_Model_141_4091(void);
                            /* Translation_Model_141_4091:'<S890>/S-Function' */
extern void
/* [PreAmpMedusaPremixDetentLevel_Left]-->[PreAmpMedusaPremixDetentLevel_Left,PreAmpMedusaPremixDetentLevel_Left_CAE] */
    FuncTranslation_Model_141_4099(void);
                            /* Translation_Model_141_4099:'<S893>/S-Function' */
extern void
/* [PreAmpMedusaPremixDetentLevel_Right]-->[PreAmpMedusaPremixDetentLevel_Right,PreAmpMedusaPremixDetentLevel_Right_CAE] */
    FuncTranslation_Model_141_4107(void);
                            /* Translation_Model_141_4107:'<S896>/S-Function' */
extern void
/* [PreAmpMedusaPremixInterpolation_Method]-->[PreAmpMedusaPremixInterpolation_Method] */
    FuncTranslation_Model_141_4114(void);
                            /* Translation_Model_141_4114:'<S899>/S-Function' */
extern void
/* [PreAmpMedusaPremixMaxLevel_CS]-->[PreAmpMedusaPremixMaxLevel_CS,PreAmpMedusaPremixMaxLevel_CS_CAE] */
    FuncTranslation_Model_141_4121(void);
                            /* Translation_Model_141_4121:'<S902>/S-Function' */
extern void
/* [PreAmpMedusaPremixMaxLevel_Left]-->[PreAmpMedusaPremixMaxLevel_Left,PreAmpMedusaPremixMaxLevel_Left_CAE] */
    FuncTranslation_Model_141_4129(void);
                            /* Translation_Model_141_4129:'<S905>/S-Function' */
extern void
/* [PreAmpMedusaPremixMaxLevel_Right]-->[PreAmpMedusaPremixMaxLevel_Right,PreAmpMedusaPremixMaxLevel_Right_CAE] */
    FuncTranslation_Model_141_4137(void);
                            /* Translation_Model_141_4137:'<S908>/S-Function' */
extern void
/* [PreAmpMedusaPremixMinLevel_CS]-->[PreAmpMedusaPremixMinLevel_CS,PreAmpMedusaPremixMinLevel_CS_CAE] */
    FuncTranslation_Model_141_4145(void);
                            /* Translation_Model_141_4145:'<S911>/S-Function' */
extern void
/* [PreAmpMedusaPremixMinLevel_Left]-->[PreAmpMedusaPremixMinLevel_Left,PreAmpMedusaPremixMinLevel_Left_CAE] */
    FuncTranslation_Model_141_4153(void);
                            /* Translation_Model_141_4153:'<S914>/S-Function' */
extern void
/* [PreAmpMedusaPremixMinLevel_Right]-->[PreAmpMedusaPremixMinLevel_Right,PreAmpMedusaPremixMinLevel_Right_CAE] */
    FuncTranslation_Model_141_4161(void);
                            /* Translation_Model_141_4161:'<S917>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsBackwardDownmixMax]-->[PreAmpMedusaVLSDrvGainsBackwardDownmixMax] */
    FuncTranslation_Model_141_983_182(void);
                         /* Translation_Model_141_983_182:'<S929>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold]-->[PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold] */
    FuncTranslation_Model_141_983_188(void);
                         /* Translation_Model_141_983_188:'<S932>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsDownmixWeights]-->[PreAmpMedusaVLSDrvGainsDownmixWeights] */
    FuncTranslation_Model_141_983_194(void);
                         /* Translation_Model_141_983_194:'<S935>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsForwardDownmixThreshold]-->[PreAmpMedusaVLSDrvGainsForwardDownmixThreshold] */
    FuncTranslation_Model_141_983_200(void);
                         /* Translation_Model_141_983_200:'<S938>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsForwardDownmixMax]-->[PreAmpMedusaVLSDrvGainsForwardDownmixMax] */
    FuncTranslation_Model_141_983_206(void);
                         /* Translation_Model_141_983_206:'<S941>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsDetentLevel]-->[PreAmpMedusaVLSDrvGainsDetentLevel] */
    FuncTranslation_Model_141_983_287(void);
                         /* Translation_Model_141_983_287:'<S948>/S-Function' */
extern void
/* [PreAmpMedusaVLSDrvGainsInterpolation_Method]-->[PreAmpMedusaVLSDrvGainsInterpolation_Method] */
    FuncTranslation_Model_141_983_293(void);
                         /* Translation_Model_141_983_293:'<S951>/S-Function' */
extern void
     /* [PreAmpMedusaVLSDrvGainsMaxLevel]-->[PreAmpMedusaVLSDrvGainsMaxLevel] */
    FuncTranslation_Model_141_983_299(void);
                         /* Translation_Model_141_983_299:'<S954>/S-Function' */
extern void
     /* [PreAmpMedusaVLSDrvGainsMinLevel]-->[PreAmpMedusaVLSDrvGainsMinLevel] */
    FuncTranslation_Model_141_983_305(void);
                         /* Translation_Model_141_983_305:'<S957>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsBackwardDownmixMax]-->[PreAmpMedusaVLSPaxGainsBackwardDownmixMax] */
    FuncTranslation_Model_141_984_182(void);
                         /* Translation_Model_141_984_182:'<S967>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold]-->[PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold] */
    FuncTranslation_Model_141_984_188(void);
                         /* Translation_Model_141_984_188:'<S970>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsDownmixWeights]-->[PreAmpMedusaVLSPaxGainsDownmixWeights] */
    FuncTranslation_Model_141_984_194(void);
                         /* Translation_Model_141_984_194:'<S973>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsForwardDownmixThreshold]-->[PreAmpMedusaVLSPaxGainsForwardDownmixThreshold] */
    FuncTranslation_Model_141_984_200(void);
                         /* Translation_Model_141_984_200:'<S976>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsForwardDownmixMax]-->[PreAmpMedusaVLSPaxGainsForwardDownmixMax] */
    FuncTranslation_Model_141_984_206(void);
                         /* Translation_Model_141_984_206:'<S979>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsDetentLevel]-->[PreAmpMedusaVLSPaxGainsDetentLevel] */
    FuncTranslation_Model_141_984_287(void);
                         /* Translation_Model_141_984_287:'<S986>/S-Function' */
extern void
/* [PreAmpMedusaVLSPaxGainsInterpolation_Method]-->[PreAmpMedusaVLSPaxGainsInterpolation_Method] */
    FuncTranslation_Model_141_984_293(void);
                         /* Translation_Model_141_984_293:'<S989>/S-Function' */
extern void
     /* [PreAmpMedusaVLSPaxGainsMaxLevel]-->[PreAmpMedusaVLSPaxGainsMaxLevel] */
    FuncTranslation_Model_141_984_299(void);
                         /* Translation_Model_141_984_299:'<S992>/S-Function' */
extern void
     /* [PreAmpMedusaVLSPaxGainsMinLevel]-->[PreAmpMedusaVLSPaxGainsMinLevel] */
    FuncTranslation_Model_141_984_305(void);
                         /* Translation_Model_141_984_305:'<S995>/S-Function' */
extern void
/* [PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients,PreAmpMedusaDRHoligramPoolIirTunableConfignumStages]-->[PreAmpMedusaDRHoligramPoolIirTunableConfigPooliirNumStages,PreAmpMedusaDRHoligramPoolIirTunableConfigpooliirCoeffs] */
    FuncTranslation_Model_141_472_255_36(void);
                     /* Translation_Model_141_472_255_36:'<S1005>/S-Function' */
extern void
/* [PreAmpMedusaDRHoligramFIRCoeffs,PreAmpMedusaDRHoligramFIRLengths,PreAmpMedusaDRHoligramPaddedFIRLengths]-->[PreAmpMedusaDRHoligramFIRCoeffs,PreAmpMedusaDRHoligramFilterLengths,PreAmpMedusaDRHoligramPaddedFilterLengths] */
    FuncTranslation_Model_141_472_235(void);
                        /* Translation_Model_141_472_235:'<S1008>/S-Function' */
extern void
/* [PreAmpMedusaDRHoligramInputMapping]-->[PreAmpMedusaDRHoligramInputMapping] */
    FuncTranslation_Model_141_472_239_67_18(void);
                  /* Translation_Model_141_472_239_67_18:'<S1015>/S-Function' */
extern void
/* [PreAmpMedusaDRHoligramOutputMapping]-->[PreAmpMedusaDRHoligramOutputMapping] */
    FuncTranslation_Model_141_472_240_67_18(void);
                  /* Translation_Model_141_472_240_67_18:'<S1019>/S-Function' */
extern void
/* [PreAmpMedusaFRHoligramIirConfigsosCoefficients,PreAmpMedusaFRHoligramIirConfignumStages]-->[PreAmpMedusaFRHoligramIirConfigPooliirNumStages,PreAmpMedusaFRHoligramIirConfigpooliirCoeffs] */
    FuncTranslation_Model_141_473_12_36(void);
                      /* Translation_Model_141_473_12_36:'<S1023>/S-Function' */
extern void
/* [PreAmpMedusaHeadrestCompEQFIRCoeffs,PreAmpMedusaHeadrestCompEQFIRLengths,PreAmpMedusaHeadrestCompEQPaddedFIRLengths]-->[PreAmpMedusaHeadrestCompEQFIRCoeffs,PreAmpMedusaHeadrestCompEQFilterLengths,PreAmpMedusaHeadrestCompEQPaddedFilterLengths] */
    FuncTranslation_Model_141_595_191(void);
                        /* Translation_Model_141_595_191:'<S1027>/S-Function' */
extern void
/* [PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients,PreAmpMedusaHeadrestCompEQIirConfignumStages]-->[PreAmpMedusaHeadrestCompEQIirConfigPooliirNumStages,PreAmpMedusaHeadrestCompEQIirConfigpooliirCoeffs] */
    FuncTranslation_Model_141_595_238_36(void);
                     /* Translation_Model_141_595_238_36:'<S1030>/S-Function' */
extern void
/* [PreAmpMedusaNonHeadrestSpeakerDelaySamples,PreAmpMedusaHeadrestDrvSpeakerDelaySamples,PreAmpMedusaHeadrestPaxSpeakerDelaySamples,PreAmpMedusaFRHoligramDelaySamples]-->[PreAmpMedusaDRSpeakerDelay,PreAmpMedusaFRSpeakerDelay] */
    FuncTranslation_Model_141_4193(void);
                           /* Translation_Model_141_4193:'<S1036>/S-Function' */
extern void            /* [PreAmpMedusaRoutingMap]-->[PreAmpMedusaRoutingMap] */
    FuncTranslation_Model_150_574_67_18(void);
                      /* Translation_Model_150_574_67_18:'<S1044>/S-Function' */
extern void
/* [PreAmpVLSXtalkCancellationIIRsosCoefficients,PreAmpVLSXtalkCancellationIIRnumStages]-->[PreAmpVLSXtalkCancellationIIRPooliirNumStages,PreAmpVLSXtalkCancellationIIRpooliirCoeffs] */
    FuncTranslation_Model_232_8_34_50_36(void);
                     /* Translation_Model_232_8_34_50_36:'<S1165>/S-Function' */
extern void
     /* [PreAmpVLSXtalkCancellationDelay]-->[PreAmpVLSXtalkCancellationDelay] */
    FuncTranslation_Model_232_8_36_67_18(void);
                     /* Translation_Model_232_8_36_67_18:'<S1170>/S-Function' */
extern void
/* [PreAmpVLSGenerationDrvFIRCoeffs,PreAmpVLSGenerationDrvPaddedFIRLengths]-->[PreAmpVLSGenerationDrvFIRCoeffs,PreAmpVLSGenerationDrvPaddedFilterLengths] */
    FuncTranslation_Model_232_11_191(void);
                         /* Translation_Model_232_11_191:'<S1172>/S-Function' */
extern void
/* [PreAmpVLSGenerationPaxFIRCoeffs,PreAmpVLSGenerationPaxPaddedFIRLengths]-->[PreAmpVLSGenerationPaxFIRCoeffs,PreAmpVLSGenerationPaxPaddedFilterLengths] */
    FuncTranslation_Model_232_12_191(void);
                         /* Translation_Model_232_12_191:'<S1175>/S-Function' */
extern void         /* [PreAmpBassBoostFrequencyHz]-->[PreAmpBassBoostCoeffs] */
    FuncTranslation_Model_247_149(void);
                            /* Translation_Model_247_149:'<S1183>/S-Function' */
extern void             /* [PreAmpBassCutFrequencyHz]-->[PreAmpBassCutCoeffs] */
    FuncTranslation_Model_247_153(void);
                            /* Translation_Model_247_153:'<S1184>/S-Function' */
extern void      /* [PreAmpBassBoostMaximum_dB]-->[PreAmpBassBoostMaximum_dB] */
    FuncTranslation_Model_247_174(void);
                            /* Translation_Model_247_174:'<S1182>/S-Function' */
extern void          /* [PreAmpBassCutMaximum_dB]-->[PreAmpBassCutMaximum_dB] */
    FuncTranslation_Model_247_176(void);
                            /* Translation_Model_247_176:'<S1185>/S-Function' */
extern void                        /* [PreAmpBassOffset]-->[PreAmpBassOffset] */
    FuncTranslation_Model_247_210_67_18(void);
                      /* Translation_Model_247_210_67_18:'<S1199>/S-Function' */
extern void                    /* [PreAmpBassramptime]-->[PreAmpBassramptime] */
    FuncTranslation_Model_247_229_67_18(void);
                      /* Translation_Model_247_229_67_18:'<S1203>/S-Function' */
extern void                          /* [PreAmpBassScale]-->[PreAmpBassScale] */
    FuncTranslation_Model_247_209_67_18(void);
                      /* Translation_Model_247_209_67_18:'<S1207>/S-Function' */
extern void
/* [PreAmpMidrangeBoostFrequencyHz,PreAmpMidrangeBoostQValue]-->[PreAmpMidrangeBoostCoeffs] */
    FuncTranslation_Model_249_47(void);
                             /* Translation_Model_249_47:'<S1210>/S-Function' */
extern void
/* [PreAmpMidrangeCutFrequencyHz,PreAmpMidrangeCutQValue]-->[PreAmpMidrangeCutCoeffs] */
    FuncTranslation_Model_249_48(void);
                             /* Translation_Model_249_48:'<S1211>/S-Function' */
extern void
         /* [PreAmpMidrangeBoostMaximum_dB]-->[PreAmpMidrangeBoostMaximum_dB] */
    FuncTranslation_Model_249_46(void);
                             /* Translation_Model_249_46:'<S1209>/S-Function' */
extern void  /* [PreAmpMidrangeCutMaximum_dB]-->[PreAmpMidrangeCutMaximum_dB] */
    FuncTranslation_Model_249_49(void);
                             /* Translation_Model_249_49:'<S1212>/S-Function' */
extern void                /* [PreAmpMidrangeOffset]-->[PreAmpMidrangeOffset] */
    FuncTranslation_Model_249_50_67_18(void);
                       /* Translation_Model_249_50_67_18:'<S1226>/S-Function' */
extern void            /* [PreAmpMidrangeRampTime]-->[PreAmpMidrangeRampTime] */
    FuncTranslation_Model_249_51_67_18(void);
                       /* Translation_Model_249_51_67_18:'<S1230>/S-Function' */
extern void                  /* [PreAmpMidrangeScale]-->[PreAmpMidrangeScale] */
    FuncTranslation_Model_249_52_67_18(void);
                       /* Translation_Model_249_52_67_18:'<S1234>/S-Function' */
extern void                            /* [PreAmpA]-->[PreAmpA] */
    FuncTranslation_Model_642(void);
                                /* Translation_Model_642:'<S1241>/S-Function' */
extern void                            /* [PreAmpG]-->[PreAmpG] */
    FuncTranslation_Model_670_67_18(void);
                          /* Translation_Model_670_67_18:'<S1250>/S-Function' */
extern void                            /* [PreAmpAnnPred]-->[PreAmpAnnPred] */
    FuncTranslation_Model_712(void);
                                /* Translation_Model_712:'<S1256>/S-Function' */
extern void                  /* [PreAmpLimiterAttack]-->[PreAmpLimiterattack] */
    FuncTranslation_Model_729(void);
                                /* Translation_Model_729:'<S1262>/S-Function' */
extern void                    /* [PreAmpLimiterDecay]-->[PreAmpLimiterdecay] */
    FuncTranslation_Model_730(void);
                                /* Translation_Model_730:'<S1263>/S-Function' */
extern void            /* [PreAmpLimiterMaxAttack]-->[PreAmpLimitermaxAttack] */
    FuncTranslation_Model_731(void);
                                /* Translation_Model_731:'<S1264>/S-Function' */
extern void                            /* [PreAmpOffset]-->[PreAmpOffset] */
    FuncTranslation_Model_741(void);
                                /* Translation_Model_741:'<S1268>/S-Function' */
extern void                /* [PreAmpUpperThreshold]-->[PreAmpUpperThreshold] */
    FuncTranslation_Model_747(void);
                                /* Translation_Model_747:'<S1271>/S-Function' */
extern void     /* [PreAmpTrebleBoostFrequencyHz]-->[PreAmpTrebleBoostCoeffs] */
    FuncTranslation_Model_251_149(void);
                            /* Translation_Model_251_149:'<S1275>/S-Function' */
extern void         /* [PreAmpTrebleCutFrequencyHz]-->[PreAmpTrebleCutCoeffs] */
    FuncTranslation_Model_251_153(void);
                            /* Translation_Model_251_153:'<S1276>/S-Function' */
extern void  /* [PreAmpTrebleBoostMaximum_dB]-->[PreAmpTrebleBoostMaximum_dB] */
    FuncTranslation_Model_251_174(void);
                            /* Translation_Model_251_174:'<S1274>/S-Function' */
extern void      /* [PreAmpTrebleCutMaximum_dB]-->[PreAmpTrebleCutMaximum_dB] */
    FuncTranslation_Model_251_176(void);
                            /* Translation_Model_251_176:'<S1277>/S-Function' */
extern void                    /* [PreAmpTrebleOffset]-->[PreAmpTrebleOffset] */
    FuncTranslation_Model_251_210_67_18(void);
                      /* Translation_Model_251_210_67_18:'<S1291>/S-Function' */
extern void                /* [PreAmpTrebleramptime]-->[PreAmpTrebleramptime] */
    FuncTranslation_Model_251_229_67_18(void);
                      /* Translation_Model_251_229_67_18:'<S1295>/S-Function' */
extern void                      /* [PreAmpTrebleScale]-->[PreAmpTrebleScale] */
    FuncTranslation_Model_251_209_67_18(void);
                      /* Translation_Model_251_209_67_18:'<S1299>/S-Function' */
extern void
/* [PostProcessLimiterAttack,PostProcessLimiterThreshold]-->[PostProcessLimiterattack,PostProcessLimiterk1] */
    FuncTranslation_Model_1495(void);
                               /* Translation_Model_1495:'<S1857>/S-Function' */
extern void
/* [PostProcessLimiterAttack_low,PostProcessLimiterThreshold_low]-->[PostProcessLimiterattack_low,PostProcessLimiterk1_low] */
    FuncTranslation_Model_1498(void);
                               /* Translation_Model_1498:'<S1860>/S-Function' */
extern void          /* [PostProcessLimiterDecay]-->[PostProcessLimiterdecay] */
    FuncTranslation_Model_1496(void);
                               /* Translation_Model_1496:'<S1858>/S-Function' */
extern void  /* [PostProcessLimiterDecay_low]-->[PostProcessLimiterdecay_low] */
    FuncTranslation_Model_1499(void);
                               /* Translation_Model_1499:'<S1861>/S-Function' */
extern void  /* [PostProcessLimiterMaxAttack]-->[PostProcessLimitermaxAttack] */
    FuncTranslation_Model_1497(void);
                               /* Translation_Model_1497:'<S1859>/S-Function' */
extern void
     /* [PostProcessLimiterMaxAttack_low]-->[PostProcessLimitermaxAttack_low] */
    FuncTranslation_Model_1500(void);
                               /* Translation_Model_1500:'<S1862>/S-Function' */
extern void          /* [PostProcessMuteRampTime]-->[PostProcessMuteRampTime] */
    FuncTranslation_Model_72_276_67_18(void);
                       /* Translation_Model_72_276_67_18:'<S1874>/S-Function' */
extern void
/* [PostProcessPostLimiterEqsosCoefficients,PostProcessPostLimiterEqnumStages]-->[PostProcessPostLimiterEqPooliirNumStages,PostProcessPostLimiterEqpooliirCoeffs] */
    FuncTranslation_Model_76_36(void);
                              /* Translation_Model_76_36:'<S1877>/S-Function' */
extern void
/* [PostProcessSoftClipperYMax,PostProcessSoftClipperXMin]-->[PostProcessSoftClipperxmin,PostProcessSoftClipperxmax,PostProcessSoftClipperp2] */
    FuncTranslation_Model_1527(void);
                               /* Translation_Model_1527:'<S1881>/S-Function' */
extern void
/* [PostProcessSoftClipperYMaxLow,PostProcessSoftClipperXMinLow]-->[PostProcessSoftClipperxmin_low,PostProcessSoftClipperxmax_low,PostProcessSoftClipperp2_low] */
    FuncTranslation_Model_1528(void);
                               /* Translation_Model_1528:'<S1882>/S-Function' */
extern void       /* [InputSelectRouterCfgMap]-->[InputSelectRouterCfgOutMap] */
    FuncTranslation_Model_397(void);
                                   /* Translation_Model_397:'<S8>/S-Function' */
extern void
/* [PreAmpMedusaBassManagerLeftMixWeights,PreAmpMedusaBassManagerRightMixWeights,PreAmpMedusaSurroundOn]-->[PreAmpMedusaBassManagerLeftMixWeights,PreAmpMedusaBassManagerRightMixWeights] */
    FuncTranslation_Model_141_246_96(void);
                          /* Translation_Model_141_246_96:'<S609>/S-Function' */
extern void
/* [PreAmpMedusaBassManagerHpfsosCoefficients,PreAmpMedusaBassManagerHpfnumStages]-->[PreAmpMedusaBassManagerHpfPooliirNumStages,PreAmpMedusaBassManagerHpfpooliirCoeffs] */
    FuncTranslation_Model_141_246_141_36(void);
                      /* Translation_Model_141_246_141_36:'<S613>/S-Function' */
extern void
/* [PreAmpMedusaBassManagerLpfsosCoefficients,PreAmpMedusaBassManagerLpfnumStages]-->[PreAmpMedusaBassManagerLpfPooliirNumStages,PreAmpMedusaBassManagerLpfpooliirCoeffs] */
    FuncTranslation_Model_141_246_148_36(void);
                      /* Translation_Model_141_246_148_36:'<S617>/S-Function' */
extern void
/* [PreAmpMedusaBassManagerGainLfe2C]-->[PreAmpMedusaBassManagerGainLfe2C] */
    FuncTranslation_Model_141_246_111_67_18(void);
                   /* Translation_Model_141_246_111_67_18:'<S622>/S-Function' */
extern void              /* [PreAmpMedusaDummyTune]-->[PreAmpMedusaDummyTune] */
    FuncTranslation_Model_141_1196_67_18(void);
                      /* Translation_Model_141_1196_67_18:'<S628>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpCoeffsXpMin,PreAmpMedusaDeciRateFdpXpMax]-->[PreAmpMedusaDeciRateFdpCoeffsXpMax,PreAmpMedusaDeciRateFdpCoeffsLokRokMaxScaleFactor,PreAmpMedusaDeciRateFdpCoeffsXpMin] */
    FuncTranslation_Model_141_1560(void);
                            /* Translation_Model_141_1560:'<S647>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB]-->[PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,PreAmpMedusaDeciRateFdpCoeffsESDStepSize] */
    FuncTranslation_Model_141_1561(void);
                            /* Translation_Model_141_1561:'<S648>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff,PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff]-->[PreAmpMedusaDeciRateFdpSpumFastPsdSmoothFactor,PreAmpMedusaDeciRateFdpSpumSlowPsdSmoothFactor] */
    FuncTranslation_Model_141_1988(void);
                            /* Translation_Model_141_1988:'<S653>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpDirectPathSec]-->[PreAmpMedusaDeciRateFdpSpumDirectPathSamplesDec] */
    FuncTranslation_Model_141_1989(void);
                            /* Translation_Model_141_1989:'<S654>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpLsSmoothCutoff]-->[PreAmpMedusaDeciRateFdpSpumLsSmoothFactor] */
    FuncTranslation_Model_141_1990(void);
                            /* Translation_Model_141_1990:'<S655>/S-Function' */
extern void
/* [PreAmpMedusaDeciRateFdpSpumOverwrite]-->[PreAmpMedusaDeciRateFdpSpumOverwrite] */
    FuncTranslation_Model_141_2031_67_18(void);
                      /* Translation_Model_141_2031_67_18:'<S664>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpCoeffsXpMax,PreAmpMedusaFullRateFdpCoeffsXpMin,PreAmpMedusaFullRateFdpXpMax]-->[PreAmpMedusaFullRateFdpCoeffsXpMax,PreAmpMedusaFullRateFdpCoeffsLokRokMaxScaleFactor,PreAmpMedusaFullRateFdpCoeffsXpMin] */
    FuncTranslation_Model_141_2423(void);
                            /* Translation_Model_141_2423:'<S674>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB]-->[PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,PreAmpMedusaFullRateFdpCoeffsESDStepSize] */
    FuncTranslation_Model_141_2424(void);
                            /* Translation_Model_141_2424:'<S675>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpFastPsdSmoothCutoff,PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff]-->[PreAmpMedusaFullRateFdpSpumFastPsdSmoothFactor,PreAmpMedusaFullRateFdpSpumSlowPsdSmoothFactor] */
    FuncTranslation_Model_141_2654(void);
                            /* Translation_Model_141_2654:'<S680>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpDirectPathSec]-->[PreAmpMedusaFullRateFdpSpumDirectPathSamplesDec] */
    FuncTranslation_Model_141_2655(void);
                            /* Translation_Model_141_2655:'<S681>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpLsSmoothCutoff]-->[PreAmpMedusaFullRateFdpSpumLsSmoothFactor] */
    FuncTranslation_Model_141_2656(void);
                            /* Translation_Model_141_2656:'<S682>/S-Function' */
extern void
/* [PreAmpMedusaFullRateFdpSpumOverwrite]-->[PreAmpMedusaFullRateFdpSpumOverwrite] */
    FuncTranslation_Model_141_2697_67_18(void);
                      /* Translation_Model_141_2697_67_18:'<S691>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorLevelCutoff,PreAmpMedusaMonoDetectorLSSmoothCutoff,PreAmpMedusaMonoDetectorLSSmoothResetCutoff]-->[PreAmpMedusaMonoDetectorLevelPole,PreAmpMedusaMonoDetectorLevelGain,PreAmpMedusaMonoDetectorLSSmoothPole,PreAmpMedusaMonoDetectorLSSmoothGain,PreAmpMedusaMonoDetectorLSSmoothResetPole,PreAmpMedusaMonoDetectorLSSmoothResetGain] */
    FuncTranslation_Model_141_2783(void);
                            /* Translation_Model_141_2783:'<S696>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorHPFCutoff]-->[PreAmpMedusaMonoDetectorHPFNumStages,PreAmpMedusaMonoDetectorHPFCoeffs] */
    FuncTranslation_Model_141_2787(void);
                            /* Translation_Model_141_2787:'<S700>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorNoiseFloordB]-->[PreAmpMedusaMonoDetectorThresholdZeroLevel] */
    FuncTranslation_Model_141_2784(void);
                            /* Translation_Model_141_2784:'<S697>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorLRMatchTolerancedB]-->[PreAmpMedusaMonoDetectorLRMatchTolerance] */
    FuncTranslation_Model_141_2785(void);
                            /* Translation_Model_141_2785:'<S698>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorThresholdMonoInput,PreAmpMedusaMonoDetectorThresholdStereoInput]-->[PreAmpMedusaMonoDetectorThresholdMono,PreAmpMedusaMonoDetectorThresholdStereo] */
    FuncTranslation_Model_141_2786(void);
                            /* Translation_Model_141_2786:'<S699>/S-Function' */
extern void
       /* [PreAmpMedusaMonoDetectorEnable]-->[PreAmpMedusaMonoDetectorEnable] */
    FuncTranslation_Model_141_2808_67_18(void);
                      /* Translation_Model_141_2808_67_18:'<S713>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstPSDSmoothCutoff]-->[PreAmpMedusaSPUMDecayEstPSDSmoothFactor] */
    FuncTranslation_Model_141_2849(void);
                            /* Translation_Model_141_2849:'<S717>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstDecaySmoothCutoff]-->[PreAmpMedusaSPUMDecayEstDecaySmoothFactor] */
    FuncTranslation_Model_141_2850(void);
                            /* Translation_Model_141_2850:'<S718>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstFastAttackCutoff,PreAmpMedusaSPUMDecayEstSlowAttackCutoff]-->[PreAmpMedusaSPUMDecayEstFastAttack,PreAmpMedusaSPUMDecayEstSlowAttack] */
    FuncTranslation_Model_141_2851(void);
                            /* Translation_Model_141_2851:'<S719>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstStepSize]-->[PreAmpMedusaSPUMDecayEstStepIncrement,PreAmpMedusaSPUMDecayEstStepDecrement] */
    FuncTranslation_Model_141_2852(void);
                            /* Translation_Model_141_2852:'<S720>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstDirectPathSec]-->[PreAmpMedusaSPUMDecayEstDirectPathFramesFs] */
    FuncTranslation_Model_141_2853(void);
                            /* Translation_Model_141_2853:'<S721>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstNoiseFloor]-->[PreAmpMedusaSPUMDecayEstNoiseFloor] */
    FuncTranslation_Model_141_2865_67_18(void);
                      /* Translation_Model_141_2865_67_18:'<S737>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstOnsetThreshold]-->[PreAmpMedusaSPUMDecayEstOnsetThreshold] */
    FuncTranslation_Model_141_2866_67_18(void);
                      /* Translation_Model_141_2866_67_18:'<S741>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstSlewThreshold]-->[PreAmpMedusaSPUMDecayEstSlewThreshold] */
    FuncTranslation_Model_141_2867_67_18(void);
                      /* Translation_Model_141_2867_67_18:'<S745>/S-Function' */
extern void
/* [PreAmpMedusaSPUMDecayEstHPFsosCoefficients,PreAmpMedusaSPUMDecayEstHPFnumStages]-->[PreAmpMedusaSPUMDecayEstHPFPooliirNumStages,PreAmpMedusaSPUMDecayEstHPFpooliirCoeffs] */
    FuncTranslation_Model_141_2878_50_36(void);
                      /* Translation_Model_141_2878_50_36:'<S749>/S-Function' */
extern void
         /* [PreAmpFadeControlBoostDisable]-->[PreAmpFadeControlBoostDisable] */
    FuncTranslation_Model_449_67_18(void);
                          /* Translation_Model_449_67_18:'<S1075>/S-Function' */
extern void
/* [PreAmpFadeControlEnableSilentExtreme]-->[PreAmpFadeControlEnableSilentExtreme] */
    FuncTranslation_Model_450_67_18(void);
                          /* Translation_Model_450_67_18:'<S1079>/S-Function' */
extern void
/* [PreAmpFadeControlTable]-->[PreAmpFadeControlTableDb,PreAmpFadeControlTableIdx] */
    FuncTranslation_Model_455(void);
                                /* Translation_Model_455:'<S1082>/S-Function' */
extern void          /* [PreAmpFadeControloffset]-->[PreAmpFadeControloffset] */
    FuncTranslation_Model_459_67_18(void);
                          /* Translation_Model_459_67_18:'<S1086>/S-Function' */
extern void      /* [PreAmpFadeControlRampTime]-->[PreAmpFadeControlRampTime] */
    FuncTranslation_Model_460_67_18(void);
                          /* Translation_Model_460_67_18:'<S1090>/S-Function' */
extern void
/* [PreAmpFadeRamperDRChannelToRamperMap]-->[PreAmpFadeRamperDRChannelToRamperMap] */
    FuncTranslation_Model_175_136_99(void);
                         /* Translation_Model_175_136_99:'<S1096>/S-Function' */
extern void
/* [PreAmpFadeRamperDRCutoffHz]-->[PreAmpFadeRamperDRTOPFilterCoefficients] */
    FuncTranslation_Model_175_136_98(void);
                         /* Translation_Model_175_136_98:'<S1095>/S-Function' */
extern void
/* [PreAmpFadeRamperFRChannelToRamperMap]-->[PreAmpFadeRamperFRChannelToRamperMap] */
    FuncTranslation_Model_176_136_99(void);
                         /* Translation_Model_176_136_99:'<S1103>/S-Function' */
extern void
/* [PreAmpFadeRamperFRCutoffHz]-->[PreAmpFadeRamperFRTOPFilterCoefficients] */
    FuncTranslation_Model_176_136_98(void);
                         /* Translation_Model_176_136_98:'<S1102>/S-Function' */
extern void      /* [PreAmpMuteControlRampTime]-->[PreAmpMuteControlRampTime] */
    FuncTranslation_Model_489_67_18(void);
                          /* Translation_Model_489_67_18:'<S1110>/S-Function' */
extern void
/* [PreAmpSleepingBeautyDRChannelToRamperMap]-->[PreAmpSleepingBeautyDRChannelToRamperMap] */
    FuncTranslation_Model_533(void);
                                /* Translation_Model_533:'<S1113>/S-Function' */
extern void
           /* [PreAmpSleepingBeautyDROffset]-->[PreAmpSleepingBeautyDROffset] */
    FuncTranslation_Model_538_67_18(void);
                          /* Translation_Model_538_67_18:'<S1122>/S-Function' */
extern void
       /* [PreAmpSleepingBeautyDRRampTime]-->[PreAmpSleepingBeautyDRRampTime] */
    FuncTranslation_Model_539_67_18(void);
                          /* Translation_Model_539_67_18:'<S1126>/S-Function' */
extern void
     /* [PreAmpSleepingBeautyDRMutesBass]-->[PreAmpSleepingBeautyDRMutesBass] */
    FuncTranslation_Model_540_67_18(void);
                          /* Translation_Model_540_67_18:'<S1130>/S-Function' */
extern void
/* [PreAmpSleepingBeautyDRTaperGainTable]-->[PreAmpSleepingBeautyDRTableDb,PreAmpSleepingBeautyDRTableIdx] */
    FuncTranslation_Model_545(void);
                                /* Translation_Model_545:'<S1132>/S-Function' */
extern void
/* [PreAmpSleepingBeautyFRChannelToRamperMap]-->[PreAmpSleepingBeautyFRChannelToRamperMap] */
    FuncTranslation_Model_596(void);
                                /* Translation_Model_596:'<S1136>/S-Function' */
extern void
           /* [PreAmpSleepingBeautyFROffset]-->[PreAmpSleepingBeautyFROffset] */
    FuncTranslation_Model_601_67_18(void);
                          /* Translation_Model_601_67_18:'<S1145>/S-Function' */
extern void
       /* [PreAmpSleepingBeautyFRRampTime]-->[PreAmpSleepingBeautyFRRampTime] */
    FuncTranslation_Model_602_67_18(void);
                          /* Translation_Model_602_67_18:'<S1149>/S-Function' */
extern void
     /* [PreAmpSleepingBeautyFRMutesBass]-->[PreAmpSleepingBeautyFRMutesBass] */
    FuncTranslation_Model_603_67_18(void);
                          /* Translation_Model_603_67_18:'<S1153>/S-Function' */
extern void
/* [PreAmpSleepingBeautyFRTaperGainTable]-->[PreAmpSleepingBeautyFRTableDb,PreAmpSleepingBeautyFRTableIdx] */
    FuncTranslation_Model_608(void);
                                /* Translation_Model_608:'<S1155>/S-Function' */
extern void
           /* [PreAmpAudiopilotTwoDowngrade]-->[PreAmpAudiopilotTwoDowngrade] */
    FuncTranslation_Model_117_21_67_18(void);
                         /* Translation_Model_117_21_67_18:'<S26>/S-Function' */
extern void      /* [PreAmpAudiopilotHvacTable]-->[PreAmpAudiopilotHvacTable] */
    FuncTranslation_Model_117_1781(void);
                             /* Translation_Model_117_1781:'<S30>/S-Function' */
extern void
/* [PreAmpAudiopilotAntiZipperRampFreqHz]-->[PreAmpAudiopilotAntiZipperRampLpfNumerator,PreAmpAudiopilotAntiZipperRampLpfDenominator] */
    FuncTranslation_Model_117_43_332(void);
                           /* Translation_Model_117_43_332:'<S38>/S-Function' */
extern void
/* [PreAmpAudiopilotBassBpfCenterFreqHz,PreAmpAudiopilotBassBpfQ]-->[PreAmpAudiopilotBassBpfNumerator,PreAmpAudiopilotBassBpfDenominator] */
    FuncTranslation_Model_117_43_351(void);
                           /* Translation_Model_117_43_351:'<S40>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeLpfCutoffFreqHz]-->[PreAmpAudiopilotMidrangeLpfNumerator,PreAmpAudiopilotMidrangeLpfDenominator] */
    FuncTranslation_Model_117_43_340(void);
                           /* Translation_Model_117_43_340:'<S44>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeLpfAlignDelaySamples]-->[PreAmpAudiopilotMidrangeLpfAlignDelaySamples] */
    FuncTranslation_Model_117_43_403(void);
                           /* Translation_Model_117_43_403:'<S48>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotBassSlope0Dbperdb]-->[PreAmpAudiopilotBassSlope0Dbperdb] */
    FuncTranslation_Model_117_44_721(void);
                           /* Translation_Model_117_44_721:'<S68>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotMidrangeSlope0DbPerDb]-->[PreAmpAudiopilotMidrangeSlope0Dbperdb] */
    FuncTranslation_Model_117_44_722(void);
                           /* Translation_Model_117_44_722:'<S69>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotTrebleSlope0DbPerDb]-->[PreAmpAudiopilotTrebleSlope0Dbperdb] */
    FuncTranslation_Model_117_44_723(void);
                           /* Translation_Model_117_44_723:'<S70>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotBassSlope1DbPerDb]-->[PreAmpAudiopilotBassSlope1Dbperdb] */
    FuncTranslation_Model_117_44_894(void);
                           /* Translation_Model_117_44_894:'<S73>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotMidrangeSlope1DbPerDb]-->[PreAmpAudiopilotMidrangeSlope1Dbperdb] */
    FuncTranslation_Model_117_44_736(void);
                           /* Translation_Model_117_44_736:'<S72>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotOn,PreAmpAudiopilotTrebleSlope1DbPerDb]-->[PreAmpAudiopilotTrebleSlope1Dbperdb] */
    FuncTranslation_Model_117_44_895(void);
                           /* Translation_Model_117_44_895:'<S71>/S-Function' */
extern void
         /* [PreAmpAudiopilotBassThresh0Db]-->[PreAmpAudiopilotBassThresh0Db] */
    FuncTranslation_Model_117_44_469_67_18(void);
                     /* Translation_Model_117_44_469_67_18:'<S84>/S-Function' */
extern void
         /* [PreAmpAudiopilotBassThresh1Db]-->[PreAmpAudiopilotBassThresh1Db] */
    FuncTranslation_Model_117_44_470_67_18(void);
                     /* Translation_Model_117_44_470_67_18:'<S88>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseHighBoundDbspl]-->[PreAmpAudiopilotHfNoiseHighBoundDbspl] */
    FuncTranslation_Model_117_44_332_67_18(void);
                     /* Translation_Model_117_44_332_67_18:'<S92>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseLowBoundDbspl]-->[PreAmpAudiopilotHfNoiseLowBoundDbspl] */
    FuncTranslation_Model_117_44_333_67_18(void);
                     /* Translation_Model_117_44_333_67_18:'<S96>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseHighBoundDbspl]-->[PreAmpAudiopilotLfNoiseHighBoundDbspl] */
    FuncTranslation_Model_117_44_334_67_18(void);
                    /* Translation_Model_117_44_334_67_18:'<S100>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseLowBoundDbspl]-->[PreAmpAudiopilotLfNoiseLowBoundDbspl] */
    FuncTranslation_Model_117_44_335_67_18(void);
                    /* Translation_Model_117_44_335_67_18:'<S104>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeThresh0Db]-->[PreAmpAudiopilotMidrangeThresh0Db] */
    FuncTranslation_Model_117_44_341_67_18(void);
                    /* Translation_Model_117_44_341_67_18:'<S108>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeThresh1Db]-->[PreAmpAudiopilotMidrangeThresh1Db] */
    FuncTranslation_Model_117_44_342_67_18(void);
                    /* Translation_Model_117_44_342_67_18:'<S112>/S-Function' */
extern void
     /* [PreAmpAudiopilotTrebleThresh0Db]-->[PreAmpAudiopilotTrebleThresh0Db] */
    FuncTranslation_Model_117_44_484_67_18(void);
                    /* Translation_Model_117_44_484_67_18:'<S116>/S-Function' */
extern void
     /* [PreAmpAudiopilotTrebleThresh1Db]-->[PreAmpAudiopilotTrebleThresh1Db] */
    FuncTranslation_Model_117_44_485_67_18(void);
                    /* Translation_Model_117_44_485_67_18:'<S120>/S-Function' */
extern void
/* [PreAmpAudiopilotBassDownwardThreshDbspl]-->[PreAmpAudiopilotBassDownwardThreshDbspl] */
    FuncTranslation_Model_117_44_315_67_18(void);
                    /* Translation_Model_117_44_315_67_18:'<S136>/S-Function' */
extern void
/* [PreAmpAudiopilotBassMaxAudiopilotBoostDb]-->[PreAmpAudiopilotBassMaxAudiopilotBoostDb] */
    FuncTranslation_Model_117_44_316_67_18(void);
                    /* Translation_Model_117_44_316_67_18:'<S140>/S-Function' */
extern void
/* [PreAmpAudiopilotBassMaxDyneqBoostDb]-->[PreAmpAudiopilotBassMaxDyneqBoostDb] */
    FuncTranslation_Model_117_44_317_67_18(void);
                    /* Translation_Model_117_44_317_67_18:'<S144>/S-Function' */
extern void
/* [PreAmpAudiopilotBassMaxTotalBoostDb]-->[PreAmpAudiopilotBassMaxTotalBoostDb] */
    FuncTranslation_Model_117_44_318_67_18(void);
                    /* Translation_Model_117_44_318_67_18:'<S148>/S-Function' */
extern void
/* [PreAmpAudiopilotDownwardExpansionOn,PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb]-->[PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb] */
    FuncTranslation_Model_117_44_666(void);
                          /* Translation_Model_117_44_666:'<S153>/S-Function' */
extern void
/* [PreAmpAudiopilotDownwardExpansionOn,PreAmpAudiopilotBassDownwardSlopeDbPerDb]-->[PreAmpAudiopilotBassDownwardSlopeDbPerDb] */
    FuncTranslation_Model_117_44_645(void);
                          /* Translation_Model_117_44_645:'<S152>/S-Function' */
extern void
/* [PreAmpAudiopilotDownwardExpansionOn,PreAmpAudiopilotTrebleDownwardSlopeDbPerDb]-->[PreAmpAudiopilotTrebleDownwardSlopeDbPerDb] */
    FuncTranslation_Model_117_44_672(void);
                          /* Translation_Model_117_44_672:'<S154>/S-Function' */
extern void
/* [PreAmpAudiopilotDyneqBassThreshDbspl]-->[PreAmpAudiopilotDyneqBassThreshDbspl] */
    FuncTranslation_Model_117_44_325_67_18(void);
                    /* Translation_Model_117_44_325_67_18:'<S161>/S-Function' */
extern void
/* [PreAmpAudiopilotDyneqBassSlopeDbPerDb,PreAmpAudiopilotDyneqOn]-->[PreAmpAudiopilotDyneqBassSlopeDbPerDb] */
    FuncTranslation_Model_117_44_633(void);
                          /* Translation_Model_117_44_633:'<S164>/S-Function' */
extern void
/* [PreAmpAudiopilotMinSignalLevelDbspl]-->[PreAmpAudiopilotMinSignalLevelDbspl] */
    FuncTranslation_Model_117_44_343_67_18(void);
                    /* Translation_Model_117_44_343_67_18:'<S169>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeDownwardThreshDbspl]-->[PreAmpAudiopilotMidrangeDownwardThreshDbspl] */
    FuncTranslation_Model_117_44_337_67_18(void);
                    /* Translation_Model_117_44_337_67_18:'<S173>/S-Function' */
extern void
/* [PreAmpAudiopilotMidrangeMaxTotalBoostDb]-->[PreAmpAudiopilotMidrangeMaxTotalBoostDb] */
    FuncTranslation_Model_117_44_338_67_18(void);
                    /* Translation_Model_117_44_338_67_18:'<S177>/S-Function' */
extern void
/* [PreAmpAudiopilotTrebleDownwardThreshDbspl]-->[PreAmpAudiopilotTrebleDownwardThreshDbspl] */
    FuncTranslation_Model_117_44_913_67_18(void);
                    /* Translation_Model_117_44_913_67_18:'<S181>/S-Function' */
extern void
/* [PreAmpAudiopilotTrebleMaxTotalBoostDb]-->[PreAmpAudiopilotTrebleMaxTotalBoostDb] */
    FuncTranslation_Model_117_44_346_67_18(void);
                    /* Translation_Model_117_44_346_67_18:'<S185>/S-Function' */
extern void
       /* [PreAmpAudiopilotEnableRampTauS]-->[PreAmpAudiopilotEnableRampCoef] */
    FuncTranslation_Model_117_44_328(void);
                          /* Translation_Model_117_44_328:'<S188>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseRefPowerMinDb]-->[PreAmpAudiopilotHfNoiseRefPowerMin] */
    FuncTranslation_Model_117_516_1944(void);
                        /* Translation_Model_117_516_1944:'<S200>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor] */
    FuncTranslation_Model_117_516_1707_67_18(void);
                  /* Translation_Model_117_516_1707_67_18:'<S214>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin] */
    FuncTranslation_Model_117_516_1708_67_18(void);
                  /* Translation_Model_117_516_1708_67_18:'<S218>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta] */
    FuncTranslation_Model_117_516_1732_67_18(void);
                  /* Translation_Model_117_516_1732_67_18:'<S224>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin] */
    FuncTranslation_Model_117_516_1733_67_18(void);
                  /* Translation_Model_117_516_1733_67_18:'<S228>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex]-->[PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex] */
    FuncTranslation_Model_117_516_1751_67_18(void);
                  /* Translation_Model_117_516_1751_67_18:'<S238>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex]-->[PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex] */
    FuncTranslation_Model_117_516_1752_67_18(void);
                  /* Translation_Model_117_516_1752_67_18:'<S242>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh]-->[PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh] */
    FuncTranslation_Model_117_516_1753_67_18(void);
                  /* Translation_Model_117_516_1753_67_18:'<S246>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef] */
    FuncTranslation_Model_117_516_1755_67_18(void);
                  /* Translation_Model_117_516_1755_67_18:'<S250>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain]-->[PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain] */
    FuncTranslation_Model_117_516_1754_67_18(void);
                  /* Translation_Model_117_516_1754_67_18:'<S254>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS]-->[PreAmpAudiopilotHfNoiseImpulseRejectionSubWinLenSamples] */
    FuncTranslation_Model_117_516_1758(void);
                        /* Translation_Model_117_516_1758:'<S257>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef]-->[PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef] */
    FuncTranslation_Model_117_516_1774_67_18(void);
                  /* Translation_Model_117_516_1774_67_18:'<S262>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseSlewAttackDbPerS]-->[PreAmpAudiopilotHfNoiseSlewAttackDbPerSample] */
    FuncTranslation_Model_117_516_1789(void);
                        /* Translation_Model_117_516_1789:'<S267>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseSlewDecayDbPerS]-->[PreAmpAudiopilotHfNoiseSlewDecayDbPerSample] */
    FuncTranslation_Model_117_516_1795(void);
                        /* Translation_Model_117_516_1795:'<S270>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseSlewThresholdDb]-->[PreAmpAudiopilotHfNoiseSlewThresholdDb] */
    FuncTranslation_Model_117_516_1804_67_18(void);
                  /* Translation_Model_117_516_1804_67_18:'<S275>/S-Function' */
extern void
     /* [PreAmpAudiopilotHfNoiseOffsetDb]-->[PreAmpAudiopilotHfNoiseOffsetDb] */
    FuncTranslation_Model_117_516_1778_67_18(void);
                  /* Translation_Model_117_516_1778_67_18:'<S279>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients,PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages]-->[PreAmpAudiopilotHfNoisePreprocessAntiAliasPooliirNumStages,PreAmpAudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs] */
    FuncTranslation_Model_117_516_1849_50_36(void);
                  /* Translation_Model_117_516_1849_50_36:'<S285>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients,PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages]-->[PreAmpAudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages,PreAmpAudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs] */
    FuncTranslation_Model_117_516_1847_50_36(void);
                  /* Translation_Model_117_516_1847_50_36:'<S290>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseRefLatencyMs]-->[PreAmpAudiopilotHfNoiseRefLatencySamples] */
    FuncTranslation_Model_117_516_957(void);
                         /* Translation_Model_117_516_957:'<S294>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseEnergyLpfTauS]-->[PreAmpAudiopilotLfNoiseEnergyLpfCoef] */
    FuncTranslation_Model_117_517_435(void);
                         /* Translation_Model_117_517_435:'<S305>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS]-->[PreAmpAudiopilotLfNoiseImpulseRejectionGamma0] */
    FuncTranslation_Model_117_517_422(void);
                         /* Translation_Model_117_517_422:'<S314>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS]-->[PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef] */
    FuncTranslation_Model_117_517_415(void);
                         /* Translation_Model_117_517_415:'<S317>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale]-->[PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale] */
    FuncTranslation_Model_117_517_330_67_18(void);
                   /* Translation_Model_117_517_330_67_18:'<S321>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale]-->[PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale] */
    FuncTranslation_Model_117_517_331_67_18(void);
                   /* Translation_Model_117_517_331_67_18:'<S325>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale]-->[PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale] */
    FuncTranslation_Model_117_517_332_67_18(void);
                   /* Translation_Model_117_517_332_67_18:'<S329>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin]-->[PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin] */
    FuncTranslation_Model_117_517_429_67_18(void);
                   /* Translation_Model_117_517_429_67_18:'<S333>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseMicsosCoefficients,PreAmpAudiopilotLfNoiseMicnumStages]-->[PreAmpAudiopilotLfNoiseMicPooliirNumStages,PreAmpAudiopilotLfNoiseMicpooliirCoeffs] */
    FuncTranslation_Model_117_517_515_50_36(void);
                   /* Translation_Model_117_517_515_50_36:'<S339>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseRefsosCoefficients,PreAmpAudiopilotLfNoiseRefnumStages]-->[PreAmpAudiopilotLfNoiseRefPooliirNumStages,PreAmpAudiopilotLfNoiseRefpooliirCoeffs] */
    FuncTranslation_Model_117_517_516_50_36(void);
                   /* Translation_Model_117_517_516_50_36:'<S344>/S-Function' */
extern void
     /* [PreAmpAudiopilotLfNoiseOffsetDb]-->[PreAmpAudiopilotLfNoiseOffsetDb] */
    FuncTranslation_Model_117_517_459_67_18(void);
                   /* Translation_Model_117_517_459_67_18:'<S349>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseRefLatencyMs]-->[PreAmpAudiopilotLfNoiseRefLatencySamples] */
    FuncTranslation_Model_117_517_351(void);
                         /* Translation_Model_117_517_351:'<S352>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSlewAttackDbPerS]-->[PreAmpAudiopilotLfNoiseSlewAttackDbPerSample] */
    FuncTranslation_Model_117_517_388(void);
                         /* Translation_Model_117_517_388:'<S361>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSlewDecayDbPerS]-->[PreAmpAudiopilotLfNoiseSlewDecayDbPerSample] */
    FuncTranslation_Model_117_517_397(void);
                         /* Translation_Model_117_517_397:'<S364>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSlewSlowDbPerS]-->[PreAmpAudiopilotLfNoiseSlewSlowDbPerSample] */
    FuncTranslation_Model_117_517_404(void);
                         /* Translation_Model_117_517_404:'<S367>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSlewThresholdDb]-->[PreAmpAudiopilotLfNoiseSlewThresholdDb] */
    FuncTranslation_Model_117_517_270_67_18(void);
                   /* Translation_Model_117_517_270_67_18:'<S372>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsAxis]-->[PreAmpAudiopilotLfNoiseSpeedBoundsAxis] */
    FuncTranslation_Model_117_517_572_67_18(void);
                   /* Translation_Model_117_517_572_67_18:'<S380>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl]-->[PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl] */
    FuncTranslation_Model_117_517_573_67_18(void);
                   /* Translation_Model_117_517_573_67_18:'<S384>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL]-->[PreAmpAudiopilotLfNoiseSpeedBoundsMinDbspl,PreAmpAudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl] */
    FuncTranslation_Model_117_517_577(void);
                         /* Translation_Model_117_517_577:'<S386>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsOn]-->[PreAmpAudiopilotLfNoiseSpeedBoundsOn] */
    FuncTranslation_Model_117_517_582_67_18(void);
                   /* Translation_Model_117_517_582_67_18:'<S391>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSysMaxDbspl]-->[PreAmpAudiopilotLfNoiseSysMaxDbspl] */
    FuncTranslation_Model_117_517_553_67_18(void);
                   /* Translation_Model_117_517_553_67_18:'<S395>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateFlagHoldTimeS]-->[PreAmpAudiopilotRatioUpdateFlagHoldTimeSamples] */
    FuncTranslation_Model_117_2074(void);
                            /* Translation_Model_117_2074:'<S409>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl]-->[PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl] */
    FuncTranslation_Model_117_2078_67_18(void);
                      /* Translation_Model_117_2078_67_18:'<S414>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl]-->[PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl] */
    FuncTranslation_Model_117_2079_67_18(void);
                      /* Translation_Model_117_2079_67_18:'<S418>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS]-->[PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodSamples] */
    FuncTranslation_Model_117_2082(void);
                            /* Translation_Model_117_2082:'<S420>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb]-->[PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb] */
    FuncTranslation_Model_117_2086_67_18(void);
                      /* Translation_Model_117_2086_67_18:'<S425>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph]-->[PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph] */
    FuncTranslation_Model_117_2087_67_18(void);
                      /* Translation_Model_117_2087_67_18:'<S429>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioEnergyLpfTauS]-->[PreAmpAudiopilotRatioEnergyLpfCoef] */
    FuncTranslation_Model_117_2093(void);
                            /* Translation_Model_117_2093:'<S432>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioHighBoundDb]-->[PreAmpAudiopilotRatioHighBoundDb] */
    FuncTranslation_Model_117_2099_67_18(void);
                      /* Translation_Model_117_2099_67_18:'<S436>/S-Function' */
extern void
     /* [PreAmpAudiopilotRatioLowBoundDb]-->[PreAmpAudiopilotRatioLowBoundDb] */
    FuncTranslation_Model_117_2100_67_18(void);
                      /* Translation_Model_117_2100_67_18:'<S440>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioSlewAttackDbPerS]-->[PreAmpAudiopilotRatioSlewAttackDbPerSample] */
    FuncTranslation_Model_117_2115(void);
                            /* Translation_Model_117_2115:'<S445>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioSlewDecayDbPerS]-->[PreAmpAudiopilotRatioSlewDecayDbPerSample] */
    FuncTranslation_Model_117_2121(void);
                            /* Translation_Model_117_2121:'<S448>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioSlewThresholdDb]-->[PreAmpAudiopilotRatioSlewThresholdDb] */
    FuncTranslation_Model_117_2125_67_18(void);
                      /* Translation_Model_117_2125_67_18:'<S453>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioImpulseRejectionGamma0TauS]-->[PreAmpAudiopilotRatioImpulseRejectionGamma0] */
    FuncTranslation_Model_117_2149(void);
                            /* Translation_Model_117_2149:'<S460>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS]-->[PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef] */
    FuncTranslation_Model_117_2155(void);
                            /* Translation_Model_117_2155:'<S463>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale]-->[PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale] */
    FuncTranslation_Model_117_2158_67_18(void);
                      /* Translation_Model_117_2158_67_18:'<S467>/S-Function' */
extern void
/* [PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale]-->[PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale] */
    FuncTranslation_Model_117_2159_67_18(void);
                      /* Translation_Model_117_2159_67_18:'<S471>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectFastDecayDbPerS]-->[PreAmpAudiopilotLevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_120_196(void);
                             /* Translation_Model_120_196:'<S483>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectHoldMarginDb]-->[PreAmpAudiopilotLevelDetectHoldMarginDb] */
    FuncTranslation_Model_120_446(void);
                             /* Translation_Model_120_446:'<S487>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectHoldTimeS]-->[PreAmpAudiopilotLevelDetectHoldTimeSamples] */
    FuncTranslation_Model_120_203(void);
                             /* Translation_Model_120_203:'<S489>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectMaxVolumeDb]-->[PreAmpAudiopilotLevelDetectMaxVolumeDb] */
    FuncTranslation_Model_120_122_67_18(void);
                       /* Translation_Model_120_122_67_18:'<S494>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectMinVolumeDb]-->[PreAmpAudiopilotLevelDetectMinVolumeDb] */
    FuncTranslation_Model_120_123_67_18(void);
                       /* Translation_Model_120_123_67_18:'<S498>/S-Function' */
extern void
/* [PreAmpAudiopilotLevelDetectSlowDecayDbPerS]-->[PreAmpAudiopilotLevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_120_189(void);
                             /* Translation_Model_120_189:'<S500>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectFastDecayDbPerS]-->[PreAmpDyneqLevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_120_264(void);
                             /* Translation_Model_120_264:'<S510>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectHoldMarginDb]-->[PreAmpDyneqLevelDetectHoldMarginDb] */
    FuncTranslation_Model_120_514(void);
                             /* Translation_Model_120_514:'<S514>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectHoldTimeS]-->[PreAmpDyneqLevelDetectHoldTimeSamples] */
    FuncTranslation_Model_120_257(void);
                             /* Translation_Model_120_257:'<S516>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectMaxVolumeDb]-->[PreAmpDyneqLevelDetectMaxVolumeDb] */
    FuncTranslation_Model_120_218_67_18(void);
                       /* Translation_Model_120_218_67_18:'<S521>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectMinVolumeDb]-->[PreAmpDyneqLevelDetectMinVolumeDb] */
    FuncTranslation_Model_120_219_67_18(void);
                       /* Translation_Model_120_219_67_18:'<S525>/S-Function' */
extern void
/* [PreAmpDyneqLevelDetectSlowDecayDbPerS]-->[PreAmpDyneqLevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_120_250(void);
                             /* Translation_Model_120_250:'<S527>/S-Function' */
extern void
       /* [PreAmpLevelDetectLatencyMs]-->[PreAmpLevelDetectMusicDelaySamples] */
    FuncTranslation_Model_120_439(void);
                             /* Translation_Model_120_439:'<S534>/S-Function' */
extern void
/* [PreAmpLevelDetectPreemphasissosCoefficients,PreAmpLevelDetectPreemphasisnumStages]-->[PreAmpLevelDetectPreemphasisPooliirNumStages,PreAmpLevelDetectPreemphasispooliirCoeffs] */
    FuncTranslation_Model_120_422_50_36(void);
                       /* Translation_Model_120_422_50_36:'<S538>/S-Function' */
extern void
           /* [PreAmpLevelDetectSysMaxDbspl]-->[PreAmpLevelDetectSysMaxDbspl] */
    FuncTranslation_Model_120_319_67_18(void);
                       /* Translation_Model_120_319_67_18:'<S543>/S-Function' */
extern void
/* [PreAmpVolumeCfgTable]-->[PreAmpVolumeCfgTable_Idx,PreAmpVolumeCfgTable_dB] */
    FuncTranslation_Model_123_280(void);
                             /* Translation_Model_123_280:'<S547>/S-Function' */
extern void            /* [PreAmpVolumeCfgmaxgain]-->[PreAmpVolumeCfgmaxgain] */
    FuncTranslation_Model_123_281_67_18(void);
                       /* Translation_Model_123_281_67_18:'<S553>/S-Function' */
extern void          /* [PreAmpVolumeCfgRampTime]-->[PreAmpVolumeCfgRampTime] */
    FuncTranslation_Model_123_256_67_18(void);
                       /* Translation_Model_123_256_67_18:'<S557>/S-Function' */
extern void
           /* [PreAmpBalance_CfgChanRampMap]-->[PreAmpBalance_CfgChanRampMap] */
    FuncTranslation_Model_135_79(void);
                              /* Translation_Model_135_79:'<S566>/S-Function' */
extern void
         /* [PreAmpBalance_CfgBoostDisable]-->[PreAmpBalance_CfgBoostDisable] */
    FuncTranslation_Model_135_81_67_18(void);
                        /* Translation_Model_135_81_67_18:'<S577>/S-Function' */
extern void          /* [PreAmpBalance_CfgOffset]-->[PreAmpBalance_CfgOffset] */
    FuncTranslation_Model_135_83_67_18(void);
                        /* Translation_Model_135_83_67_18:'<S581>/S-Function' */
extern void      /* [PreAmpBalance_CfgRampTime]-->[PreAmpBalance_CfgRampTime] */
    FuncTranslation_Model_135_84_67_18(void);
                        /* Translation_Model_135_84_67_18:'<S585>/S-Function' */
extern void
/* [PreAmpBalance_CfgSleepingBeautyMutesBass]-->[PreAmpBalance_CfgSleepingBeautyMutesBass] */
    FuncTranslation_Model_135_143_67_18(void);
                       /* Translation_Model_135_143_67_18:'<S589>/S-Function' */
extern void
/* [PreAmpBalance_CfgEnableSilentExtreme]-->[PreAmpBalance_CfgEnableSilentExtreme] */
    FuncTranslation_Model_135_85_67_18(void);
                        /* Translation_Model_135_85_67_18:'<S593>/S-Function' */
extern void
/* [PreAmpBalance_CfgTable]-->[PreAmpBalance_CfgTableDb,PreAmpBalance_CfgTableIdx] */
    FuncTranslation_Model_135_90(void);
                              /* Translation_Model_135_90:'<S596>/S-Function' */
extern void            /* [PreAmpNearWiggleCoeffs]-->[PreAmpNearWiggleCoeffs] */
    FuncTranslation_Model_420_67_18(void);
                          /* Translation_Model_420_67_18:'<S1053>/S-Function' */
extern void                          /* [PreAmpNearDelay]-->[PreAmpNearDelay] */
    FuncTranslation_Model_421_67_18(void);
                          /* Translation_Model_421_67_18:'<S1057>/S-Function' */
extern void
/* [NearDr_PooliirsosCoefficients,NearDr_PooliirnumStages]-->[NearDr_PooliirPooliirNumStages,NearDr_PooliirpooliirCoeffs] */
    FuncTranslation_Model_874_36(void);
                             /* Translation_Model_874_36:'<S1314>/S-Function' */
extern void
/* [NearDr_f1_del,NearDr_f2_del,NearDr_f3_del,NearDr_f4_del,NearDr_f5_del,NearDr_f6_del,NearDr_f7_del]-->[NearDr_EqDelays] */
    FuncTranslation_Model_863(void);
                                /* Translation_Model_863:'<S1318>/S-Function' */
extern void
/* [NearDr_PoolIirTunablesosCoefficients,NearDr_PoolIirTunablenumStages]-->[NearDr_PoolIirTunablePooliirNumStages,NearDr_PoolIirTunablepooliirCoeffs] */
    FuncTranslation_Model_915_36(void);
                             /* Translation_Model_915_36:'<S1324>/S-Function' */
extern void
/* [NearDr_driver_src1,NearDr_driver_src2,NearDr_driver_src3,NearDr_driver_src4,NearDr_passenger_src1,NearDr_passenger_src2,NearDr_passenger_src3,NearDr_passenger_src4]-->[NearDr_eqdelays] */
    FuncTranslation_Model_903(void);
                                /* Translation_Model_903:'<S1328>/S-Function' */
extern void                     /* [NearDr_RouterMap]-->[NearDr_RouterOutMap] */
    FuncTranslation_Model_926(void);
                                /* Translation_Model_926:'<S1332>/S-Function' */
extern void
/* [NearDr_f1_mix,NearDr_f2_mix,NearDr_f3_mix,NearDr_f4_mix,NearDr_f5_mix,NearDr_f6_mix,NearDr_f7_mix,NearDr_LFI0_mix,NearDr_LFT0_mix,NearDr_RFI0_mix,NearDr_RFT0_mix,NearDr_LSI0_mix,NearDr_LST0_mix,NearDr_RSI0_mix,NearDr_RST0_mix,NearDr_LCI0_mix,NearDr_LCT0_mix,NearDr_RCI0_mix,NearDr_RCT0_mix,NearDr_LFI1_mix,NearDr_LFT1_mix,NearDr_RFI1_mix,NearDr_RFT1_mix,NearDr_LSI1_mix,NearDr_LST1_mix,NearDr_RSI1_mix,NearDr_RST1_mix,NearDr_LCI1_mix,NearDr_LCT1_mix,NearDr_RCI1_mix,NearDr_RCT1_mix,NearDr_nv0l_mix,NearDr_nv0r_mix,NearDr_nv1l_mix,NearDr_nv1r_mix]-->[NearDr_mix] */
    FuncTranslation_Model_1026(void);
                               /* Translation_Model_1026:'<S1340>/S-Function' */
extern void
/* [NearFr_PooliirsosCoefficients,NearFr_PooliirnumStages]-->[NearFr_PooliirPooliirNumStages,NearFr_PooliirpooliirCoeffs] */
    FuncTranslation_Model_1063_36(void);
                            /* Translation_Model_1063_36:'<S1351>/S-Function' */
extern void
/* [NearFr_f1_del,NearFr_f2_del,NearFr_f3_del,NearFr_f4_del,NearFr_f5_del,NearFr_f6_del,NearFr_f7_del]-->[NearFr_EqDelays] */
    FuncTranslation_Model_1052(void);
                               /* Translation_Model_1052:'<S1355>/S-Function' */
extern void
/* [NearFr_PoolIirTunablesosCoefficients,NearFr_PoolIirTunablenumStages]-->[NearFr_PoolIirTunablePooliirNumStages,NearFr_PoolIirTunablepooliirCoeffs] */
    FuncTranslation_Model_1104_36(void);
                            /* Translation_Model_1104_36:'<S1361>/S-Function' */
extern void
/* [NearFr_driver_src1,NearFr_driver_src2,NearFr_driver_src3,NearFr_driver_src4,NearFr_passenger_src1,NearFr_passenger_src2,NearFr_passenger_src3,NearFr_passenger_src4]-->[NearFr_eqdelays] */
    FuncTranslation_Model_1092(void);
                               /* Translation_Model_1092:'<S1365>/S-Function' */
extern void                     /* [NearFr_RouterMap]-->[NearFr_RouterOutMap] */
    FuncTranslation_Model_1115(void);
                               /* Translation_Model_1115:'<S1369>/S-Function' */
extern void
/* [NearFr_f1_mix,NearFr_f2_mix,NearFr_f3_mix,NearFr_f4_mix,NearFr_f5_mix,NearFr_f6_mix,NearFr_f7_mix,NearFr_LFI0_mix,NearFr_LFT0_mix,NearFr_RFI0_mix,NearFr_RFT0_mix,NearFr_LSI0_mix,NearFr_LST0_mix,NearFr_RSI0_mix,NearFr_RST0_mix,NearFr_LCI0_mix,NearFr_LCT0_mix,NearFr_RCI0_mix,NearFr_RCT0_mix,NearFr_LFI1_mix,NearFr_LFT1_mix,NearFr_RFI1_mix,NearFr_RFT1_mix,NearFr_LSI1_mix,NearFr_LST1_mix,NearFr_RSI1_mix,NearFr_RST1_mix,NearFr_LCI1_mix,NearFr_LCT1_mix,NearFr_RCI1_mix,NearFr_RCT1_mix,NearFr_nv0l_mix,NearFr_nv0r_mix,NearFr_nv1l_mix,NearFr_nv1r_mix]-->[NearFr_mix] */
    FuncTranslation_Model_1215(void);
                               /* Translation_Model_1215:'<S1377>/S-Function' */
extern void                  /* [NearRampDbPerSample]-->[NearRampDbPerSample] */
    FuncTranslation_Model_831_67_18(void);
                          /* Translation_Model_831_67_18:'<S1383>/S-Function' */
extern void
/* [NearHpfCutoffFrequency,NearHpfFilterOrder]-->[NearNumStages,NearCoefficients] */
    FuncTranslation_Model_1234(void);
                               /* Translation_Model_1234:'<S1386>/S-Function' */
extern void
/* [NearLevelDetectPreEmphasisShelfFiltersosCoefficients,NearLevelDetectPreEmphasisShelfFilternumStages]-->[NearLevelDetectPreEmphasisShelfFilterPooliirNumStages,NearLevelDetectPreEmphasisShelfFilterpooliirCoeffs] */
    FuncTranslation_Model_1475_36(void);
                            /* Translation_Model_1475_36:'<S1402>/S-Function' */
extern void    /* [NearLevelDetectSysMaxDbspl]-->[NearLevelDetectSysMaxDbspl] */
    FuncTranslation_Model_1310_67_18(void);
                         /* Translation_Model_1310_67_18:'<S1407>/S-Function' */
extern void
/* [NearAnn1LevelDetectFastDecayDbPers]-->[NearAnn1LevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_1331(void);
                               /* Translation_Model_1331:'<S1415>/S-Function' */
extern void
/* [NearAnn1LevelDetectHoldMarginDb]-->[NearAnn1LevelDetecthold_margin_db] */
    FuncTranslation_Model_1338(void);
                               /* Translation_Model_1338:'<S1419>/S-Function' */
extern void
     /* [NearAnn1LevelDetectHoldTimes]-->[NearAnn1LevelDetectHoldTimeSamples] */
    FuncTranslation_Model_1343(void);
                               /* Translation_Model_1343:'<S1421>/S-Function' */
extern void
       /* [NearAnn1LevelDetectMaxVolumeDb]-->[NearAnn1LevelDetectMaxVolumeDb] */
    FuncTranslation_Model_1347_67_18(void);
                         /* Translation_Model_1347_67_18:'<S1426>/S-Function' */
extern void
       /* [NearAnn1LevelDetectMinVolumeDb]-->[NearAnn1LevelDetectMinVolumeDb] */
    FuncTranslation_Model_1348_67_18(void);
                         /* Translation_Model_1348_67_18:'<S1430>/S-Function' */
extern void
/* [NearAnn1LevelDetectSlowDecayDbPers]-->[NearAnn1LevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_1351(void);
                               /* Translation_Model_1351:'<S1432>/S-Function' */
extern void
/* [NearAnn2LevelDetectFastDecayDbPers]-->[NearAnn2LevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_1368(void);
                               /* Translation_Model_1368:'<S1441>/S-Function' */
extern void
     /* [NearAnn2LevelDetectHoldMarginDb]-->[NearAnn2LevelDetectHoldMarginDb] */
    FuncTranslation_Model_1375(void);
                               /* Translation_Model_1375:'<S1445>/S-Function' */
extern void
     /* [NearAnn2LevelDetectHoldTimes]-->[NearAnn2LevelDetectHoldTimeSamples] */
    FuncTranslation_Model_1380(void);
                               /* Translation_Model_1380:'<S1447>/S-Function' */
extern void
       /* [NearAnn2LevelDetectMaxVolumeDb]-->[NearAnn2LevelDetectMaxVolumeDb] */
    FuncTranslation_Model_1384_67_18(void);
                         /* Translation_Model_1384_67_18:'<S1452>/S-Function' */
extern void
       /* [NearAnn2LevelDetectMinVolumeDb]-->[NearAnn2LevelDetectMinVolumeDb] */
    FuncTranslation_Model_1385_67_18(void);
                         /* Translation_Model_1385_67_18:'<S1456>/S-Function' */
extern void
/* [NearAnn2LevelDetectSlowDecayDbPers]-->[NearAnn2LevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_1388(void);
                               /* Translation_Model_1388:'<S1458>/S-Function' */
extern void
/* [NearAnn3LevelDetectFastDecayDbPers]-->[NearAnn3LevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_1405(void);
                               /* Translation_Model_1405:'<S1467>/S-Function' */
extern void
     /* [NearAnn3LevelDetectHoldMarginDb]-->[NearAnn3LevelDetectHoldMarginDb] */
    FuncTranslation_Model_1412(void);
                               /* Translation_Model_1412:'<S1471>/S-Function' */
extern void
     /* [NearAnn3LevelDetectHoldTimes]-->[NearAnn3LevelDetectHoldTimeSamples] */
    FuncTranslation_Model_1417(void);
                               /* Translation_Model_1417:'<S1473>/S-Function' */
extern void
       /* [NearAnn3LevelDetectMaxVolumeDb]-->[NearAnn3LevelDetectMaxVolumeDb] */
    FuncTranslation_Model_1421_67_18(void);
                         /* Translation_Model_1421_67_18:'<S1478>/S-Function' */
extern void
       /* [NearAnn3LevelDetectMinVolumeDb]-->[NearAnn3LevelDetectMinVolumeDb] */
    FuncTranslation_Model_1422_67_18(void);
                         /* Translation_Model_1422_67_18:'<S1482>/S-Function' */
extern void
/* [NearAnn3LevelDetectSlowDecayDbPers]-->[NearAnn3LevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_1425(void);
                               /* Translation_Model_1425:'<S1484>/S-Function' */
extern void
/* [NearAnn4LevelDetectFastDecayDbPers]-->[NearAnn4LevelDetectFastDecayDbPerSample] */
    FuncTranslation_Model_1442(void);
                               /* Translation_Model_1442:'<S1493>/S-Function' */
extern void
     /* [NearAnn4LevelDetectHoldMarginDb]-->[NearAnn4LevelDetectHoldMarginDb] */
    FuncTranslation_Model_1449(void);
                               /* Translation_Model_1449:'<S1497>/S-Function' */
extern void
     /* [NearAnn4LevelDetectHoldTimes]-->[NearAnn4LevelDetectHoldTimeSamples] */
    FuncTranslation_Model_1454(void);
                               /* Translation_Model_1454:'<S1499>/S-Function' */
extern void
       /* [NearAnn4LevelDetectMaxVolumeDb]-->[NearAnn4LevelDetectMaxVolumeDb] */
    FuncTranslation_Model_1458_67_18(void);
                         /* Translation_Model_1458_67_18:'<S1504>/S-Function' */
extern void
       /* [NearAnn4LevelDetectMinVolumeDb]-->[NearAnn4LevelDetectMinVolumeDb] */
    FuncTranslation_Model_1459_67_18(void);
                         /* Translation_Model_1459_67_18:'<S1508>/S-Function' */
extern void
/* [NearAnn4LevelDetectSlowDecayDbPers]-->[NearAnn4LevelDetectSlowDecayDbPerSample] */
    FuncTranslation_Model_1462(void);
                               /* Translation_Model_1462:'<S1510>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcVncThresh]-->[NearAnn1Ann1NonEntGainCalcVncThresh] */
    FuncTranslation_Model_1254_7_67_18(void);
                       /* Translation_Model_1254_7_67_18:'<S1529>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcVncSlope]-->[NearAnn1Ann1NonEntGainCalcVncSlope] */
    FuncTranslation_Model_1254_8_67_18(void);
                       /* Translation_Model_1254_8_67_18:'<S1533>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcMaxBoost]-->[NearAnn1Ann1NonEntGainCalcMaxBoost] */
    FuncTranslation_Model_1254_9_67_18(void);
                       /* Translation_Model_1254_9_67_18:'<S1537>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcNoiseOverRide]-->[NearAnn1Ann1NonEntGainCalcNoiseOverRide] */
    FuncTranslation_Model_1254_72_67_18(void);
                      /* Translation_Model_1254_72_67_18:'<S1541>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag]-->[NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag] */
    FuncTranslation_Model_1254_74_67_18(void);
                      /* Translation_Model_1254_74_67_18:'<S1545>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcBoostOverRide]-->[NearAnn1Ann1NonEntGainCalcBoostOverRide] */
    FuncTranslation_Model_1254_75_67_18(void);
                      /* Translation_Model_1254_75_67_18:'<S1549>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcBoostOverRideFlag]-->[NearAnn1Ann1NonEntGainCalcBoostOverRideFlag] */
    FuncTranslation_Model_1254_76_67_18(void);
                      /* Translation_Model_1254_76_67_18:'<S1553>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcVncEnableTuneVar]-->[NearAnn1Ann1NonEntGainCalcVncEnableTuneVar] */
    FuncTranslation_Model_1254_99_67_18(void);
                      /* Translation_Model_1254_99_67_18:'<S1557>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcTau]-->[NearAnn1Ann1NonEntGainCalcNum,NearAnn1Ann1NonEntGainCalcDen] */
    FuncTranslation_Model_1254_85(void);
                            /* Translation_Model_1254_85:'<S1559>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcMinVncSignal]-->[NearAnn1Ann1NonEntGainCalcMinVncSignal] */
    FuncTranslation_Model_1254_53_67_18(void);
                      /* Translation_Model_1254_53_67_18:'<S1566>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcMaxSpl]-->[NearAnn1Ann1NonEntGainCalcMaxSpl] */
    FuncTranslation_Model_1254_54_67_18(void);
                      /* Translation_Model_1254_54_67_18:'<S1570>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntVncAppliedTau]-->[NearAnn1Ann1NonEntVncAppliedNum,NearAnn1Ann1NonEntVncAppliedden] */
    FuncTranslation_Model_1255_44(void);
                            /* Translation_Model_1255_44:'<S1574>/S-Function' */
extern void        /* [NearAnn1Ann1MuteRampTime]-->[NearAnn1Ann1MuteRampTime] */
    FuncTranslation_Model_1257_276_67_18(void);
                     /* Translation_Model_1257_276_67_18:'<S1581>/S-Function' */
extern void
/* [NearAnn1Ann1VolumeTable]-->[NearAnn1Ann1VolumeTable_Idx,NearAnn1Ann1VolumeTable_dB] */
    FuncTranslation_Model_1259_139(void);
                           /* Translation_Model_1259_139:'<S1583>/S-Function' */
extern void    /* [NearAnn1Ann1VolumeRampRate]-->[NearAnn1Ann1VolumeRampRate] */
    FuncTranslation_Model_1259_192_67_18(void);
                     /* Translation_Model_1259_192_67_18:'<S1590>/S-Function' */
extern void    /* [NearAnn1Ann1VolumeRampTime]-->[NearAnn1Ann1VolumeRampTime] */
    FuncTranslation_Model_1259_190_67_18(void);
                     /* Translation_Model_1259_190_67_18:'<S1594>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcVncThresh]-->[NearAnn2Ann2NonEntGainCalcVncThresh] */
    FuncTranslation_Model_1265_7_67_18(void);
                       /* Translation_Model_1265_7_67_18:'<S1612>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcVncSlope]-->[NearAnn2Ann2NonEntGainCalcVncSlope] */
    FuncTranslation_Model_1265_8_67_18(void);
                       /* Translation_Model_1265_8_67_18:'<S1616>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcMaxBoost]-->[NearAnn2Ann2NonEntGainCalcMaxBoost] */
    FuncTranslation_Model_1265_9_67_18(void);
                       /* Translation_Model_1265_9_67_18:'<S1620>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcNoiseOverRide]-->[NearAnn2Ann2NonEntGainCalcNoiseOverRide] */
    FuncTranslation_Model_1265_72_67_18(void);
                      /* Translation_Model_1265_72_67_18:'<S1624>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag]-->[NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag] */
    FuncTranslation_Model_1265_74_67_18(void);
                      /* Translation_Model_1265_74_67_18:'<S1628>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcBoostOverRide]-->[NearAnn2Ann2NonEntGainCalcBoostOverRide] */
    FuncTranslation_Model_1265_75_67_18(void);
                      /* Translation_Model_1265_75_67_18:'<S1632>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcBoostOverRideFlag]-->[NearAnn2Ann2NonEntGainCalcBoostOverRideFlag] */
    FuncTranslation_Model_1265_76_67_18(void);
                      /* Translation_Model_1265_76_67_18:'<S1636>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcVncEnableTuneVar]-->[NearAnn2Ann2NonEntGainCalcVncEnableTuneVar] */
    FuncTranslation_Model_1265_99_67_18(void);
                      /* Translation_Model_1265_99_67_18:'<S1640>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcTau]-->[NearAnn2Ann2NonEntGainCalcNum,NearAnn2Ann2NonEntGainCalcDen] */
    FuncTranslation_Model_1265_85(void);
                            /* Translation_Model_1265_85:'<S1642>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcMinVncSignal]-->[NearAnn2Ann2NonEntGainCalcMinVncSignal] */
    FuncTranslation_Model_1265_53_67_18(void);
                      /* Translation_Model_1265_53_67_18:'<S1649>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcMaxSpl]-->[NearAnn2Ann2NonEntGainCalcMaxSpl] */
    FuncTranslation_Model_1265_54_67_18(void);
                      /* Translation_Model_1265_54_67_18:'<S1653>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntVncAppliedTau]-->[NearAnn2Ann2NonEntVncAppliedNum,NearAnn2Ann2NonEntVncAppliedden] */
    FuncTranslation_Model_1266_44(void);
                            /* Translation_Model_1266_44:'<S1657>/S-Function' */
extern void        /* [NearAnn2Ann2MuteRampTime]-->[NearAnn2Ann2MuteRampTime] */
    FuncTranslation_Model_1268_276_67_18(void);
                     /* Translation_Model_1268_276_67_18:'<S1664>/S-Function' */
extern void
/* [NearAnn2Ann2VolumeTable]-->[NearAnn2Ann2VolumeTable_Idx,NearAnn2Ann2VolumeTable_dB] */
    FuncTranslation_Model_1270_139(void);
                           /* Translation_Model_1270_139:'<S1666>/S-Function' */
extern void    /* [NearAnn2Ann2VolumeRampRate]-->[NearAnn2Ann2VolumeRampRate] */
    FuncTranslation_Model_1270_192_67_18(void);
                     /* Translation_Model_1270_192_67_18:'<S1673>/S-Function' */
extern void    /* [NearAnn2Ann2VolumeRampTime]-->[NearAnn2Ann2VolumeRampTime] */
    FuncTranslation_Model_1270_190_67_18(void);
                     /* Translation_Model_1270_190_67_18:'<S1677>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcVncThresh]-->[NearAnn3Ann3NonEntGainCalcVncThresh] */
    FuncTranslation_Model_1276_7_67_18(void);
                       /* Translation_Model_1276_7_67_18:'<S1695>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcVncSlope]-->[NearAnn3Ann3NonEntGainCalcVncSlope] */
    FuncTranslation_Model_1276_8_67_18(void);
                       /* Translation_Model_1276_8_67_18:'<S1699>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcMaxBoost]-->[NearAnn3Ann3NonEntGainCalcMaxBoost] */
    FuncTranslation_Model_1276_9_67_18(void);
                       /* Translation_Model_1276_9_67_18:'<S1703>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcNoiseOverRide]-->[NearAnn3Ann3NonEntGainCalcNoiseOverRide] */
    FuncTranslation_Model_1276_72_67_18(void);
                      /* Translation_Model_1276_72_67_18:'<S1707>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag]-->[NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag] */
    FuncTranslation_Model_1276_74_67_18(void);
                      /* Translation_Model_1276_74_67_18:'<S1711>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcBoostOverRide]-->[NearAnn3Ann3NonEntGainCalcBoostOverRide] */
    FuncTranslation_Model_1276_75_67_18(void);
                      /* Translation_Model_1276_75_67_18:'<S1715>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcBoostOverRideFlag]-->[NearAnn3Ann3NonEntGainCalcBoostOverRideFlag] */
    FuncTranslation_Model_1276_76_67_18(void);
                      /* Translation_Model_1276_76_67_18:'<S1719>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcVncEnableTuneVar]-->[NearAnn3Ann3NonEntGainCalcVncEnableTuneVar] */
    FuncTranslation_Model_1276_99_67_18(void);
                      /* Translation_Model_1276_99_67_18:'<S1723>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcTau]-->[NearAnn3Ann3NonEntGainCalcNum,NearAnn3Ann3NonEntGainCalcDen] */
    FuncTranslation_Model_1276_85(void);
                            /* Translation_Model_1276_85:'<S1725>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcMinVncSignal]-->[NearAnn3Ann3NonEntGainCalcMinVncSignal] */
    FuncTranslation_Model_1276_53_67_18(void);
                      /* Translation_Model_1276_53_67_18:'<S1732>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcMaxSpl]-->[NearAnn3Ann3NonEntGainCalcMaxSpl] */
    FuncTranslation_Model_1276_54_67_18(void);
                      /* Translation_Model_1276_54_67_18:'<S1736>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntVncAppliedTau]-->[NearAnn3Ann3NonEntVncAppliedNum,NearAnn3Ann3NonEntVncAppliedden] */
    FuncTranslation_Model_1277_44(void);
                            /* Translation_Model_1277_44:'<S1740>/S-Function' */
extern void        /* [NearAnn3Ann3MuteRampTime]-->[NearAnn3Ann3MuteRampTime] */
    FuncTranslation_Model_1279_276_67_18(void);
                     /* Translation_Model_1279_276_67_18:'<S1747>/S-Function' */
extern void
/* [NearAnn3Ann3VolumeTable]-->[NearAnn3Ann3VolumeTable_Idx,NearAnn3Ann3VolumeTable_dB] */
    FuncTranslation_Model_1281_139(void);
                           /* Translation_Model_1281_139:'<S1749>/S-Function' */
extern void    /* [NearAnn3Ann3VolumeRampRate]-->[NearAnn3Ann3VolumeRampRate] */
    FuncTranslation_Model_1281_192_67_18(void);
                     /* Translation_Model_1281_192_67_18:'<S1756>/S-Function' */
extern void    /* [NearAnn3Ann3VolumeRampTime]-->[NearAnn3Ann3VolumeRampTime] */
    FuncTranslation_Model_1281_190_67_18(void);
                     /* Translation_Model_1281_190_67_18:'<S1760>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcVncThresh]-->[NearAnn4Ann4NonEntGainCalcVncThresh] */
    FuncTranslation_Model_1287_7_67_18(void);
                       /* Translation_Model_1287_7_67_18:'<S1778>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcVncSlope]-->[NearAnn4Ann4NonEntGainCalcVncSlope] */
    FuncTranslation_Model_1287_8_67_18(void);
                       /* Translation_Model_1287_8_67_18:'<S1782>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcMaxBoost]-->[NearAnn4Ann4NonEntGainCalcMaxBoost] */
    FuncTranslation_Model_1287_9_67_18(void);
                       /* Translation_Model_1287_9_67_18:'<S1786>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcNoiseOverRide]-->[NearAnn4Ann4NonEntGainCalcNoiseOverRide] */
    FuncTranslation_Model_1287_72_67_18(void);
                      /* Translation_Model_1287_72_67_18:'<S1790>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag]-->[NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag] */
    FuncTranslation_Model_1287_74_67_18(void);
                      /* Translation_Model_1287_74_67_18:'<S1794>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcBoostOverRide]-->[NearAnn4Ann4NonEntGainCalcBoostOverRide] */
    FuncTranslation_Model_1287_75_67_18(void);
                      /* Translation_Model_1287_75_67_18:'<S1798>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcBoostOverRideFlag]-->[NearAnn4Ann4NonEntGainCalcBoostOverRideFlag] */
    FuncTranslation_Model_1287_76_67_18(void);
                      /* Translation_Model_1287_76_67_18:'<S1802>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcVncEnableTuneVar]-->[NearAnn4Ann4NonEntGainCalcVncEnableTuneVar] */
    FuncTranslation_Model_1287_99_67_18(void);
                      /* Translation_Model_1287_99_67_18:'<S1806>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcTau]-->[NearAnn4Ann4NonEntGainCalcNum,NearAnn4Ann4NonEntGainCalcDen] */
    FuncTranslation_Model_1287_85(void);
                            /* Translation_Model_1287_85:'<S1808>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcMinVncSignal]-->[NearAnn4Ann4NonEntGainCalcMinVncSignal] */
    FuncTranslation_Model_1287_53_67_18(void);
                      /* Translation_Model_1287_53_67_18:'<S1815>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcMaxSpl]-->[NearAnn4Ann4NonEntGainCalcMaxSpl] */
    FuncTranslation_Model_1287_54_67_18(void);
                      /* Translation_Model_1287_54_67_18:'<S1819>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntVncAppliedTau]-->[NearAnn4Ann4NonEntVncAppliedNum,NearAnn4Ann4NonEntVncAppliedden] */
    FuncTranslation_Model_1288_44(void);
                            /* Translation_Model_1288_44:'<S1823>/S-Function' */
extern void        /* [NearAnn4Ann4MuteRampTime]-->[NearAnn4Ann4MuteRampTime] */
    FuncTranslation_Model_1290_276_67_18(void);
                     /* Translation_Model_1290_276_67_18:'<S1830>/S-Function' */
extern void
/* [NearAnn4Ann4VolumeTable]-->[NearAnn4Ann4VolumeTable_Idx,NearAnn4Ann4VolumeTable_dB] */
    FuncTranslation_Model_1292_139(void);
                           /* Translation_Model_1292_139:'<S1832>/S-Function' */
extern void    /* [NearAnn4Ann4VolumeRampRate]-->[NearAnn4Ann4VolumeRampRate] */
    FuncTranslation_Model_1292_192_67_18(void);
                     /* Translation_Model_1292_192_67_18:'<S1839>/S-Function' */
extern void    /* [NearAnn4Ann4VolumeRampTime]-->[NearAnn4Ann4VolumeRampTime] */
    FuncTranslation_Model_1292_190_67_18(void);
                     /* Translation_Model_1292_190_67_18:'<S1843>/S-Function' */
extern void
           /* [TestRouterASDRouterEnableAux]-->[TestRouterASDRouterEnableAux] */
    FuncTranslation_Model_291_138_8_67_18(void);
                    /* Translation_Model_291_138_8_67_18:'<S1895>/S-Function' */
extern void
         /* [TestRouterASDRouterMainSelect]-->[TestRouterASDRouterMainSelect] */
    FuncTranslation_Model_291_138_44_67_18(void);
                   /* Translation_Model_291_138_44_67_18:'<S1900>/S-Function' */
extern void                  /* [TestRouterAuxSelect]-->[TestRouterAuxSelect] */
    FuncTranslation_Model_296_67_18(void);
                          /* Translation_Model_296_67_18:'<S1904>/S-Function' */

// -----------------------------------------------------
// ----- Source TuneVars for each translation function:
static enum TuneVarNumber Translation_Model_141_1371_Sources[] =
{                                      /* '<S636>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateWiggleFilterDelaySamples,
    ID_TuneVar_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples,
    ID_TuneVar_PreAmpMedusaHoligramFilterAlignmentDelaySamples,
};

static enum TuneVarNumber Translation_Model_141_345_50_36_Sources[] =
{                                      /* '<S766>/S-Function' */
    ID_TuneVar_PreAmpMedusatailCompEQsosCoefficients,
    ID_TuneVar_PreAmpMedusatailCompEQnumStages,
};

static enum TuneVarNumber Translation_Model_141_346_67_18_Sources[] =
{                                      /* '<S771>/S-Function' */
    ID_TuneVar_PreAmpMedusaWiggleFilter,
};

static enum TuneVarNumber Translation_Model_141_2888_Sources[] =
{                                      /* '<S759>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateWiggleFilterDelaySamples1,
    ID_TuneVar_PreAmpMedusaDeciRateNearWiggleFilterDelaySamples1,
};

static enum TuneVarNumber Translation_Model_141_2926_Sources[] =
{                                      /* '<S783>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerBackwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_2932_Sources[] =
{                                      /* '<S786>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerBackwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_2939_Sources[] =
{                                      /* '<S789>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_CS,
};

static enum TuneVarNumber Translation_Model_141_2947_Sources[] =
{                                      /* '<S792>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_Left,
};

static enum TuneVarNumber Translation_Model_141_2955_Sources[] =
{                                      /* '<S795>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDownmixWeights_Right,
};

static enum TuneVarNumber Translation_Model_141_2962_Sources[] =
{                                      /* '<S798>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerForwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_2968_Sources[] =
{                                      /* '<S801>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerForwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_3372_Sources[] =
{                                      /* '<S814>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_3380_Sources[] =
{                                      /* '<S817>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_3388_Sources[] =
{                                      /* '<S820>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerDetentLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_3395_Sources[] =
{                                      /* '<S823>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerInterpolation_Method,
};

static enum TuneVarNumber Translation_Model_141_3402_Sources[] =
{                                      /* '<S826>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_3410_Sources[] =
{                                      /* '<S829>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_3418_Sources[] =
{                                      /* '<S832>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMaxLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_3426_Sources[] =
{                                      /* '<S835>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_3434_Sources[] =
{                                      /* '<S838>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_3442_Sources[] =
{                                      /* '<S841>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateMixerMinLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_3495_Sources[] =
{                                      /* '<S849>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMonoSurroundPhaseAngle,
};

static enum TuneVarNumber Translation_Model_141_3596_Sources[] =
{                                      /* '<S859>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixBackwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_3602_Sources[] =
{                                      /* '<S862>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixBackwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_3609_Sources[] =
{                                      /* '<S865>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_CS,
};

static enum TuneVarNumber Translation_Model_141_3617_Sources[] =
{                                      /* '<S868>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_Left,
};

static enum TuneVarNumber Translation_Model_141_3625_Sources[] =
{                                      /* '<S871>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDownmixWeights_Right,
};

static enum TuneVarNumber Translation_Model_141_3632_Sources[] =
{                                      /* '<S874>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixForwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_3638_Sources[] =
{                                      /* '<S877>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixForwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_4091_Sources[] =
{                                      /* '<S890>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_4099_Sources[] =
{                                      /* '<S893>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_4107_Sources[] =
{                                      /* '<S896>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixDetentLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_4114_Sources[] =
{                                      /* '<S899>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixInterpolation_Method,
};

static enum TuneVarNumber Translation_Model_141_4121_Sources[] =
{                                      /* '<S902>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_4129_Sources[] =
{                                      /* '<S905>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_4137_Sources[] =
{                                      /* '<S908>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMaxLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_4145_Sources[] =
{                                      /* '<S911>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_CS,
};

static enum TuneVarNumber Translation_Model_141_4153_Sources[] =
{                                      /* '<S914>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_Left,
};

static enum TuneVarNumber Translation_Model_141_4161_Sources[] =
{                                      /* '<S917>/S-Function' */
    ID_TuneVar_PreAmpMedusaPremixMinLevel_Right,
};

static enum TuneVarNumber Translation_Model_141_983_182_Sources[] =
{                                      /* '<S929>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsBackwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_983_188_Sources[] =
{                                      /* '<S932>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_983_194_Sources[] =
{                                      /* '<S935>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsDownmixWeights,
};

static enum TuneVarNumber Translation_Model_141_983_200_Sources[] =
{                                      /* '<S938>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_983_206_Sources[] =
{                                      /* '<S941>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsForwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_983_287_Sources[] =
{                                      /* '<S948>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsDetentLevel,
};

static enum TuneVarNumber Translation_Model_141_983_293_Sources[] =
{                                      /* '<S951>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsInterpolation_Method,
};

static enum TuneVarNumber Translation_Model_141_983_299_Sources[] =
{                                      /* '<S954>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsMaxLevel,
};

static enum TuneVarNumber Translation_Model_141_983_305_Sources[] =
{                                      /* '<S957>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSDrvGainsMinLevel,
};

static enum TuneVarNumber Translation_Model_141_984_182_Sources[] =
{                                      /* '<S967>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsBackwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_984_188_Sources[] =
{                                      /* '<S970>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_984_194_Sources[] =
{                                      /* '<S973>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsDownmixWeights,
};

static enum TuneVarNumber Translation_Model_141_984_200_Sources[] =
{                                      /* '<S976>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold,
};

static enum TuneVarNumber Translation_Model_141_984_206_Sources[] =
{                                      /* '<S979>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsForwardDownmixMax,
};

static enum TuneVarNumber Translation_Model_141_984_287_Sources[] =
{                                      /* '<S986>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsDetentLevel,
};

static enum TuneVarNumber Translation_Model_141_984_293_Sources[] =
{                                      /* '<S989>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsInterpolation_Method,
};

static enum TuneVarNumber Translation_Model_141_984_299_Sources[] =
{                                      /* '<S992>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsMaxLevel,
};

static enum TuneVarNumber Translation_Model_141_984_305_Sources[] =
{                                      /* '<S995>/S-Function' */
    ID_TuneVar_PreAmpMedusaVLSPaxGainsMinLevel,
};

static enum TuneVarNumber Translation_Model_141_472_255_36_Sources[] =
{                                      /* '<S1005>/S-Function' */
    ID_TuneVar_PreAmpMedusaDRHoligramPoolIirTunableConfigsosCoefficients,
    ID_TuneVar_PreAmpMedusaDRHoligramPoolIirTunableConfignumStages,
};

static enum TuneVarNumber Translation_Model_141_472_235_Sources[] =
{                                      /* '<S1008>/S-Function' */
    ID_TuneVar_PreAmpMedusaDRHoligramFIRCoeffs,
    ID_TuneVar_PreAmpMedusaDRHoligramFIRLengths,
    ID_TuneVar_PreAmpMedusaDRHoligramPaddedFIRLengths,
};

static enum TuneVarNumber Translation_Model_141_472_239_67_18_Sources[] =
{                                      /* '<S1015>/S-Function' */
    ID_TuneVar_PreAmpMedusaDRHoligramInputMapping,
};

static enum TuneVarNumber Translation_Model_141_472_240_67_18_Sources[] =
{                                      /* '<S1019>/S-Function' */
    ID_TuneVar_PreAmpMedusaDRHoligramOutputMapping,
};

static enum TuneVarNumber Translation_Model_141_473_12_36_Sources[] =
{                                      /* '<S1023>/S-Function' */
    ID_TuneVar_PreAmpMedusaFRHoligramIirConfigsosCoefficients,
    ID_TuneVar_PreAmpMedusaFRHoligramIirConfignumStages,
};

static enum TuneVarNumber Translation_Model_141_595_191_Sources[] =
{                                      /* '<S1027>/S-Function' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQFIRCoeffs,
    ID_TuneVar_PreAmpMedusaHeadrestCompEQFIRLengths,
    ID_TuneVar_PreAmpMedusaHeadrestCompEQPaddedFIRLengths,
};

static enum TuneVarNumber Translation_Model_141_595_238_36_Sources[] =
{                                      /* '<S1030>/S-Function' */
    ID_TuneVar_PreAmpMedusaHeadrestCompEQIirConfigsosCoefficients,
    ID_TuneVar_PreAmpMedusaHeadrestCompEQIirConfignumStages,
};

static enum TuneVarNumber Translation_Model_141_4193_Sources[] =
{                                      /* '<S1036>/S-Function' */
    ID_TuneVar_PreAmpMedusaNonHeadrestSpeakerDelaySamples,
    ID_TuneVar_PreAmpMedusaHeadrestDrvSpeakerDelaySamples,
    ID_TuneVar_PreAmpMedusaHeadrestPaxSpeakerDelaySamples,
    ID_TuneVar_PreAmpMedusaFRHoligramDelaySamples,
};

static enum TuneVarNumber Translation_Model_150_574_67_18_Sources[] =
{                                      /* '<S1044>/S-Function' */
    ID_TuneVar_PreAmpMedusaRoutingMap,
};

static enum TuneVarNumber Translation_Model_232_8_34_50_36_Sources[] =
{                                      /* '<S1165>/S-Function' */
    ID_TuneVar_PreAmpVLSXtalkCancellationIIRsosCoefficients,
    ID_TuneVar_PreAmpVLSXtalkCancellationIIRnumStages,
};

static enum TuneVarNumber Translation_Model_232_8_36_67_18_Sources[] =
{                                      /* '<S1170>/S-Function' */
    ID_TuneVar_PreAmpVLSXtalkCancellationDelay,
};

static enum TuneVarNumber Translation_Model_232_11_191_Sources[] =
{                                      /* '<S1172>/S-Function' */
    ID_TuneVar_PreAmpVLSGenerationDrvFIRCoeffs,
    ID_TuneVar_PreAmpVLSGenerationDrvPaddedFIRLengths,
};

static enum TuneVarNumber Translation_Model_232_12_191_Sources[] =
{                                      /* '<S1175>/S-Function' */
    ID_TuneVar_PreAmpVLSGenerationPaxFIRCoeffs,
    ID_TuneVar_PreAmpVLSGenerationPaxPaddedFIRLengths,
};

static enum TuneVarNumber Translation_Model_247_149_Sources[] =
{                                      /* '<S1183>/S-Function' */
    ID_TuneVar_PreAmpBassBoostFrequencyHz,
};

static enum TuneVarNumber Translation_Model_247_153_Sources[] =
{                                      /* '<S1184>/S-Function' */
    ID_TuneVar_PreAmpBassCutFrequencyHz,
};

static enum TuneVarNumber Translation_Model_247_174_Sources[] =
{                                      /* '<S1182>/S-Function' */
    ID_TuneVar_PreAmpBassBoostMaximum_dB,
};

static enum TuneVarNumber Translation_Model_247_176_Sources[] =
{                                      /* '<S1185>/S-Function' */
    ID_TuneVar_PreAmpBassCutMaximum_dB,
};

static enum TuneVarNumber Translation_Model_247_210_67_18_Sources[] =
{                                      /* '<S1199>/S-Function' */
    ID_TuneVar_PreAmpBassOffset,
};

static enum TuneVarNumber Translation_Model_247_229_67_18_Sources[] =
{                                      /* '<S1203>/S-Function' */
    ID_TuneVar_PreAmpBassramptime,
};

static enum TuneVarNumber Translation_Model_247_209_67_18_Sources[] =
{                                      /* '<S1207>/S-Function' */
    ID_TuneVar_PreAmpBassScale,
};

static enum TuneVarNumber Translation_Model_249_47_Sources[] =
{                                      /* '<S1210>/S-Function' */
    ID_TuneVar_PreAmpMidrangeBoostFrequencyHz,
    ID_TuneVar_PreAmpMidrangeBoostQValue,
};

static enum TuneVarNumber Translation_Model_249_48_Sources[] =
{                                      /* '<S1211>/S-Function' */
    ID_TuneVar_PreAmpMidrangeCutFrequencyHz,
    ID_TuneVar_PreAmpMidrangeCutQValue,
};

static enum TuneVarNumber Translation_Model_249_46_Sources[] =
{                                      /* '<S1209>/S-Function' */
    ID_TuneVar_PreAmpMidrangeBoostMaximum_dB,
};

static enum TuneVarNumber Translation_Model_249_49_Sources[] =
{                                      /* '<S1212>/S-Function' */
    ID_TuneVar_PreAmpMidrangeCutMaximum_dB,
};

static enum TuneVarNumber Translation_Model_249_50_67_18_Sources[] =
{                                      /* '<S1226>/S-Function' */
    ID_TuneVar_PreAmpMidrangeOffset,
};

static enum TuneVarNumber Translation_Model_249_51_67_18_Sources[] =
{                                      /* '<S1230>/S-Function' */
    ID_TuneVar_PreAmpMidrangeRampTime,
};

static enum TuneVarNumber Translation_Model_249_52_67_18_Sources[] =
{                                      /* '<S1234>/S-Function' */
    ID_TuneVar_PreAmpMidrangeScale,
};

static enum TuneVarNumber Translation_Model_642_Sources[] =
{                                      /* '<S1241>/S-Function' */
    ID_TuneVar_PreAmpA,
};

static enum TuneVarNumber Translation_Model_670_67_18_Sources[] =
{                                      /* '<S1250>/S-Function' */
    ID_TuneVar_PreAmpG,
};

static enum TuneVarNumber Translation_Model_712_Sources[] =
{                                      /* '<S1256>/S-Function' */
    ID_TuneVar_PreAmpAnnPred,
};

static enum TuneVarNumber Translation_Model_729_Sources[] =
{                                      /* '<S1262>/S-Function' */
    ID_TuneVar_PreAmpLimiterAttack,
};

static enum TuneVarNumber Translation_Model_730_Sources[] =
{                                      /* '<S1263>/S-Function' */
    ID_TuneVar_PreAmpLimiterDecay,
};

static enum TuneVarNumber Translation_Model_731_Sources[] =
{                                      /* '<S1264>/S-Function' */
    ID_TuneVar_PreAmpLimiterMaxAttack,
};

static enum TuneVarNumber Translation_Model_741_Sources[] =
{                                      /* '<S1268>/S-Function' */
    ID_TuneVar_PreAmpOffset,
};

static enum TuneVarNumber Translation_Model_747_Sources[] =
{                                      /* '<S1271>/S-Function' */
    ID_TuneVar_PreAmpUpperThreshold,
};

static enum TuneVarNumber Translation_Model_251_149_Sources[] =
{                                      /* '<S1275>/S-Function' */
    ID_TuneVar_PreAmpTrebleBoostFrequencyHz,
};

static enum TuneVarNumber Translation_Model_251_153_Sources[] =
{                                      /* '<S1276>/S-Function' */
    ID_TuneVar_PreAmpTrebleCutFrequencyHz,
};

static enum TuneVarNumber Translation_Model_251_174_Sources[] =
{                                      /* '<S1274>/S-Function' */
    ID_TuneVar_PreAmpTrebleBoostMaximum_dB,
};

static enum TuneVarNumber Translation_Model_251_176_Sources[] =
{                                      /* '<S1277>/S-Function' */
    ID_TuneVar_PreAmpTrebleCutMaximum_dB,
};

static enum TuneVarNumber Translation_Model_251_210_67_18_Sources[] =
{                                      /* '<S1291>/S-Function' */
    ID_TuneVar_PreAmpTrebleOffset,
};

static enum TuneVarNumber Translation_Model_251_229_67_18_Sources[] =
{                                      /* '<S1295>/S-Function' */
    ID_TuneVar_PreAmpTrebleramptime,
};

static enum TuneVarNumber Translation_Model_251_209_67_18_Sources[] =
{                                      /* '<S1299>/S-Function' */
    ID_TuneVar_PreAmpTrebleScale,
};

static enum TuneVarNumber Translation_Model_1495_Sources[] =
{                                      /* '<S1857>/S-Function' */
    ID_TuneVar_PostProcessLimiterAttack,
    ID_TuneVar_PostProcessLimiterThreshold,
};

static enum TuneVarNumber Translation_Model_1498_Sources[] =
{                                      /* '<S1860>/S-Function' */
    ID_TuneVar_PostProcessLimiterAttack_low,
    ID_TuneVar_PostProcessLimiterThreshold_low,
};

static enum TuneVarNumber Translation_Model_1496_Sources[] =
{                                      /* '<S1858>/S-Function' */
    ID_TuneVar_PostProcessLimiterDecay,
};

static enum TuneVarNumber Translation_Model_1499_Sources[] =
{                                      /* '<S1861>/S-Function' */
    ID_TuneVar_PostProcessLimiterDecay_low,
};

static enum TuneVarNumber Translation_Model_1497_Sources[] =
{                                      /* '<S1859>/S-Function' */
    ID_TuneVar_PostProcessLimiterMaxAttack,
};

static enum TuneVarNumber Translation_Model_1500_Sources[] =
{                                      /* '<S1862>/S-Function' */
    ID_TuneVar_PostProcessLimiterMaxAttack_low,
};

static enum TuneVarNumber Translation_Model_72_276_67_18_Sources[] =
{                                      /* '<S1874>/S-Function' */
    ID_TuneVar_PostProcessMuteRampTime,
};

static enum TuneVarNumber Translation_Model_76_36_Sources[] =
{                                      /* '<S1877>/S-Function' */
    ID_TuneVar_PostProcessPostLimiterEqsosCoefficients,
    ID_TuneVar_PostProcessPostLimiterEqnumStages,
};

static enum TuneVarNumber Translation_Model_1527_Sources[] =
{                                      /* '<S1881>/S-Function' */
    ID_TuneVar_PostProcessSoftClipperYMax,
    ID_TuneVar_PostProcessSoftClipperXMin,
};

static enum TuneVarNumber Translation_Model_1528_Sources[] =
{                                      /* '<S1882>/S-Function' */
    ID_TuneVar_PostProcessSoftClipperYMaxLow,
    ID_TuneVar_PostProcessSoftClipperXMinLow,
};

static enum TuneVarNumber Translation_Model_397_Sources[] =
{                                      /* '<S8>/S-Function' */
    ID_TuneVar_InputSelectRouterCfgMap,
};

static enum TuneVarNumber Translation_Model_141_246_96_Sources[] =
{                                      /* '<S609>/S-Function' */
    ID_TuneVar_PreAmpMedusaBassManagerLeftMixWeights,
    ID_TuneVar_PreAmpMedusaBassManagerRightMixWeights,
    ID_TuneVar_PreAmpMedusaSurroundOn,
};

static enum TuneVarNumber Translation_Model_141_246_141_36_Sources[] =
{                                      /* '<S613>/S-Function' */
    ID_TuneVar_PreAmpMedusaBassManagerHpfsosCoefficients,
    ID_TuneVar_PreAmpMedusaBassManagerHpfnumStages,
};

static enum TuneVarNumber Translation_Model_141_246_148_36_Sources[] =
{                                      /* '<S617>/S-Function' */
    ID_TuneVar_PreAmpMedusaBassManagerLpfsosCoefficients,
    ID_TuneVar_PreAmpMedusaBassManagerLpfnumStages,
};

static enum TuneVarNumber Translation_Model_141_246_111_67_18_Sources[] =
{                                      /* '<S622>/S-Function' */
    ID_TuneVar_PreAmpMedusaBassManagerGainLfe2C,
};

static enum TuneVarNumber Translation_Model_141_1196_67_18_Sources[] =
{                                      /* '<S628>/S-Function' */
    ID_TuneVar_PreAmpMedusaDummyTune,
};

static enum TuneVarNumber Translation_Model_141_1560_Sources[] =
{                                      /* '<S647>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsXpMin,
    ID_TuneVar_PreAmpMedusaDeciRateFdpXpMax,
};

static enum TuneVarNumber Translation_Model_141_1561_Sources[] =
{                                      /* '<S648>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,
    ID_TuneVar_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,
};

static enum TuneVarNumber Translation_Model_141_1988_Sources[] =
{                                      /* '<S653>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpFastPsdSmoothCutoff,
    ID_TuneVar_PreAmpMedusaDeciRateFdpSlowPsdSmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_1989_Sources[] =
{                                      /* '<S654>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpDirectPathSec,
};

static enum TuneVarNumber Translation_Model_141_1990_Sources[] =
{                                      /* '<S655>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpLsSmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_2031_67_18_Sources[] =
{                                      /* '<S664>/S-Function' */
    ID_TuneVar_PreAmpMedusaDeciRateFdpSpumOverwrite,
};

static enum TuneVarNumber Translation_Model_141_2423_Sources[] =
{                                      /* '<S674>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsXpMax,
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsXpMin,
    ID_TuneVar_PreAmpMedusaFullRateFdpXpMax,
};

static enum TuneVarNumber Translation_Model_141_2424_Sources[] =
{                                      /* '<S675>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,
    ID_TuneVar_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,
};

static enum TuneVarNumber Translation_Model_141_2654_Sources[] =
{                                      /* '<S680>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpFastPsdSmoothCutoff,
    ID_TuneVar_PreAmpMedusaFullRateFdpSlowPsdSmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_2655_Sources[] =
{                                      /* '<S681>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpDirectPathSec,
};

static enum TuneVarNumber Translation_Model_141_2656_Sources[] =
{                                      /* '<S682>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpLsSmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_2697_67_18_Sources[] =
{                                      /* '<S691>/S-Function' */
    ID_TuneVar_PreAmpMedusaFullRateFdpSpumOverwrite,
};

static enum TuneVarNumber Translation_Model_141_2783_Sources[] =
{                                      /* '<S696>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLevelCutoff,
    ID_TuneVar_PreAmpMedusaMonoDetectorLSSmoothCutoff,
    ID_TuneVar_PreAmpMedusaMonoDetectorLSSmoothResetCutoff,
};

static enum TuneVarNumber Translation_Model_141_2787_Sources[] =
{                                      /* '<S700>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorHPFCutoff,
};

static enum TuneVarNumber Translation_Model_141_2784_Sources[] =
{                                      /* '<S697>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorNoiseFloordB,
};

static enum TuneVarNumber Translation_Model_141_2785_Sources[] =
{                                      /* '<S698>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorLRMatchTolerancedB,
};

static enum TuneVarNumber Translation_Model_141_2786_Sources[] =
{                                      /* '<S699>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorThresholdMonoInput,
    ID_TuneVar_PreAmpMedusaMonoDetectorThresholdStereoInput,
};

static enum TuneVarNumber Translation_Model_141_2808_67_18_Sources[] =
{                                      /* '<S713>/S-Function' */
    ID_TuneVar_PreAmpMedusaMonoDetectorEnable,
};

static enum TuneVarNumber Translation_Model_141_2849_Sources[] =
{                                      /* '<S717>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstPSDSmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_2850_Sources[] =
{                                      /* '<S718>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstDecaySmoothCutoff,
};

static enum TuneVarNumber Translation_Model_141_2851_Sources[] =
{                                      /* '<S719>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstFastAttackCutoff,
    ID_TuneVar_PreAmpMedusaSPUMDecayEstSlowAttackCutoff,
};

static enum TuneVarNumber Translation_Model_141_2852_Sources[] =
{                                      /* '<S720>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstStepSize,
};

static enum TuneVarNumber Translation_Model_141_2853_Sources[] =
{                                      /* '<S721>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstDirectPathSec,
};

static enum TuneVarNumber Translation_Model_141_2865_67_18_Sources[] =
{                                      /* '<S737>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstNoiseFloor,
};

static enum TuneVarNumber Translation_Model_141_2866_67_18_Sources[] =
{                                      /* '<S741>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstOnsetThreshold,
};

static enum TuneVarNumber Translation_Model_141_2867_67_18_Sources[] =
{                                      /* '<S745>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstSlewThreshold,
};

static enum TuneVarNumber Translation_Model_141_2878_50_36_Sources[] =
{                                      /* '<S749>/S-Function' */
    ID_TuneVar_PreAmpMedusaSPUMDecayEstHPFsosCoefficients,
    ID_TuneVar_PreAmpMedusaSPUMDecayEstHPFnumStages,
};

static enum TuneVarNumber Translation_Model_449_67_18_Sources[] =
{                                      /* '<S1075>/S-Function' */
    ID_TuneVar_PreAmpFadeControlBoostDisable,
};

static enum TuneVarNumber Translation_Model_450_67_18_Sources[] =
{                                      /* '<S1079>/S-Function' */
    ID_TuneVar_PreAmpFadeControlEnableSilentExtreme,
};

static enum TuneVarNumber Translation_Model_455_Sources[] =
{                                      /* '<S1082>/S-Function' */
    ID_TuneVar_PreAmpFadeControlTable,
};

static enum TuneVarNumber Translation_Model_459_67_18_Sources[] =
{                                      /* '<S1086>/S-Function' */
    ID_TuneVar_PreAmpFadeControloffset,
};

static enum TuneVarNumber Translation_Model_460_67_18_Sources[] =
{                                      /* '<S1090>/S-Function' */
    ID_TuneVar_PreAmpFadeControlRampTime,
};

static enum TuneVarNumber Translation_Model_175_136_99_Sources[] =
{                                      /* '<S1096>/S-Function' */
    ID_TuneVar_PreAmpFadeRamperDRChannelToRamperMap,
};

static enum TuneVarNumber Translation_Model_175_136_98_Sources[] =
{                                      /* '<S1095>/S-Function' */
    ID_TuneVar_PreAmpFadeRamperDRCutoffHz,
};

static enum TuneVarNumber Translation_Model_176_136_99_Sources[] =
{                                      /* '<S1103>/S-Function' */
    ID_TuneVar_PreAmpFadeRamperFRChannelToRamperMap,
};

static enum TuneVarNumber Translation_Model_176_136_98_Sources[] =
{                                      /* '<S1102>/S-Function' */
    ID_TuneVar_PreAmpFadeRamperFRCutoffHz,
};

static enum TuneVarNumber Translation_Model_489_67_18_Sources[] =
{                                      /* '<S1110>/S-Function' */
    ID_TuneVar_PreAmpMuteControlRampTime,
};

static enum TuneVarNumber Translation_Model_533_Sources[] =
{                                      /* '<S1113>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyDRChannelToRamperMap,
};

static enum TuneVarNumber Translation_Model_538_67_18_Sources[] =
{                                      /* '<S1122>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyDROffset,
};

static enum TuneVarNumber Translation_Model_539_67_18_Sources[] =
{                                      /* '<S1126>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyDRRampTime,
};

static enum TuneVarNumber Translation_Model_540_67_18_Sources[] =
{                                      /* '<S1130>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyDRMutesBass,
};

static enum TuneVarNumber Translation_Model_545_Sources[] =
{                                      /* '<S1132>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyDRTaperGainTable,
};

static enum TuneVarNumber Translation_Model_596_Sources[] =
{                                      /* '<S1136>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyFRChannelToRamperMap,
};

static enum TuneVarNumber Translation_Model_601_67_18_Sources[] =
{                                      /* '<S1145>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyFROffset,
};

static enum TuneVarNumber Translation_Model_602_67_18_Sources[] =
{                                      /* '<S1149>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyFRRampTime,
};

static enum TuneVarNumber Translation_Model_603_67_18_Sources[] =
{                                      /* '<S1153>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyFRMutesBass,
};

static enum TuneVarNumber Translation_Model_608_Sources[] =
{                                      /* '<S1155>/S-Function' */
    ID_TuneVar_PreAmpSleepingBeautyFRTaperGainTable,
};

static enum TuneVarNumber Translation_Model_117_21_67_18_Sources[] =
{                                      /* '<S26>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotTwoDowngrade,
};

static enum TuneVarNumber Translation_Model_117_1781_Sources[] =
{                                      /* '<S30>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHvacTable,
};

static enum TuneVarNumber Translation_Model_117_43_332_Sources[] =
{                                      /* '<S38>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAntiZipperRampFreqHz,
};

static enum TuneVarNumber Translation_Model_117_43_351_Sources[] =
{                                      /* '<S40>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassBpfCenterFreqHz,
    ID_TuneVar_PreAmpAudiopilotBassBpfQ,
};

static enum TuneVarNumber Translation_Model_117_43_340_Sources[] =
{                                      /* '<S44>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeLpfCutoffFreqHz,
};

static enum TuneVarNumber Translation_Model_117_43_403_Sources[] =
{                                      /* '<S48>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeLpfAlignDelaySamples,
};

static enum TuneVarNumber Translation_Model_117_44_721_Sources[] =
{                                      /* '<S68>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotBassSlope0Dbperdb,
};

static enum TuneVarNumber Translation_Model_117_44_722_Sources[] =
{                                      /* '<S69>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotMidrangeSlope0DbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_723_Sources[] =
{                                      /* '<S70>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotTrebleSlope0DbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_894_Sources[] =
{                                      /* '<S73>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotBassSlope1DbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_736_Sources[] =
{                                      /* '<S72>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotMidrangeSlope1DbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_895_Sources[] =
{                                      /* '<S71>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotAudiopilotOn,
    ID_TuneVar_PreAmpAudiopilotTrebleSlope1DbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_469_67_18_Sources[] =
{                                      /* '<S84>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassThresh0Db,
};

static enum TuneVarNumber Translation_Model_117_44_470_67_18_Sources[] =
{                                      /* '<S88>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassThresh1Db,
};

static enum TuneVarNumber Translation_Model_117_44_332_67_18_Sources[] =
{                                      /* '<S92>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseHighBoundDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_333_67_18_Sources[] =
{                                      /* '<S96>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseLowBoundDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_334_67_18_Sources[] =
{                                      /* '<S100>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseHighBoundDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_335_67_18_Sources[] =
{                                      /* '<S104>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseLowBoundDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_341_67_18_Sources[] =
{                                      /* '<S108>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeThresh0Db,
};

static enum TuneVarNumber Translation_Model_117_44_342_67_18_Sources[] =
{                                      /* '<S112>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeThresh1Db,
};

static enum TuneVarNumber Translation_Model_117_44_484_67_18_Sources[] =
{                                      /* '<S116>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotTrebleThresh0Db,
};

static enum TuneVarNumber Translation_Model_117_44_485_67_18_Sources[] =
{                                      /* '<S120>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotTrebleThresh1Db,
};

static enum TuneVarNumber Translation_Model_117_44_315_67_18_Sources[] =
{                                      /* '<S136>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassDownwardThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_316_67_18_Sources[] =
{                                      /* '<S140>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassMaxAudiopilotBoostDb,
};

static enum TuneVarNumber Translation_Model_117_44_317_67_18_Sources[] =
{                                      /* '<S144>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassMaxDyneqBoostDb,
};

static enum TuneVarNumber Translation_Model_117_44_318_67_18_Sources[] =
{                                      /* '<S148>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotBassMaxTotalBoostDb,
};

static enum TuneVarNumber Translation_Model_117_44_666_Sources[] =
{                                      /* '<S153>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotDownwardExpansionOn,
    ID_TuneVar_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_645_Sources[] =
{                                      /* '<S152>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotDownwardExpansionOn,
    ID_TuneVar_PreAmpAudiopilotBassDownwardSlopeDbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_672_Sources[] =
{                                      /* '<S154>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotDownwardExpansionOn,
    ID_TuneVar_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb,
};

static enum TuneVarNumber Translation_Model_117_44_325_67_18_Sources[] =
{                                      /* '<S161>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotDyneqBassThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_633_Sources[] =
{                                      /* '<S164>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotDyneqBassSlopeDbPerDb,
    ID_TuneVar_PreAmpAudiopilotDyneqOn,
};

static enum TuneVarNumber Translation_Model_117_44_343_67_18_Sources[] =
{                                      /* '<S169>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMinSignalLevelDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_337_67_18_Sources[] =
{                                      /* '<S173>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeDownwardThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_338_67_18_Sources[] =
{                                      /* '<S177>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotMidrangeMaxTotalBoostDb,
};

static enum TuneVarNumber Translation_Model_117_44_913_67_18_Sources[] =
{                                      /* '<S181>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotTrebleDownwardThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_44_346_67_18_Sources[] =
{                                      /* '<S185>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotTrebleMaxTotalBoostDb,
};

static enum TuneVarNumber Translation_Model_117_44_328_Sources[] =
{                                      /* '<S188>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotEnableRampTauS,
};

static enum TuneVarNumber Translation_Model_117_516_1944_Sources[] =
{                                      /* '<S200>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseRefPowerMinDb,
};

static enum TuneVarNumber Translation_Model_117_516_1707_67_18_Sources[] =
{                                      /* '<S214>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor,
};

static enum TuneVarNumber Translation_Model_117_516_1708_67_18_Sources[] =
{                                      /* '<S218>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,
};

static enum TuneVarNumber Translation_Model_117_516_1732_67_18_Sources[] =
{                                      /* '<S224>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta,
};

static enum TuneVarNumber Translation_Model_117_516_1733_67_18_Sources[] =
{                                      /* '<S228>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin,
};

static enum TuneVarNumber Translation_Model_117_516_1751_67_18_Sources[] =
{                                      /* '<S238>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex,
};

static enum TuneVarNumber Translation_Model_117_516_1752_67_18_Sources[] =
{                                      /* '<S242>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex,
};

static enum TuneVarNumber Translation_Model_117_516_1753_67_18_Sources[] =
{                                      /* '<S246>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh,
};

static enum TuneVarNumber Translation_Model_117_516_1755_67_18_Sources[] =
{                                      /* '<S250>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef,
};

static enum TuneVarNumber Translation_Model_117_516_1754_67_18_Sources[] =
{                                      /* '<S254>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain,
};

static enum TuneVarNumber Translation_Model_117_516_1758_Sources[] =
{                                      /* '<S257>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinTimeS,
};

static enum TuneVarNumber Translation_Model_117_516_1774_67_18_Sources[] =
{                                      /* '<S262>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,
};

static enum TuneVarNumber Translation_Model_117_516_1789_Sources[] =
{                                      /* '<S267>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewAttackDbPerS,
};

static enum TuneVarNumber Translation_Model_117_516_1795_Sources[] =
{                                      /* '<S270>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_117_516_1804_67_18_Sources[] =
{                                      /* '<S275>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseSlewThresholdDb,
};

static enum TuneVarNumber Translation_Model_117_516_1778_67_18_Sources[] =
{                                      /* '<S279>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseOffsetDb,
};

static enum TuneVarNumber Translation_Model_117_516_1849_50_36_Sources[] =
{                                      /* '<S285>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessAntiAliassosCoefficients,
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessAntiAliasnumStages,
};

static enum TuneVarNumber Translation_Model_117_516_1847_50_36_Sources[] =
{                                      /* '<S290>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasssosCoefficients,
    ID_TuneVar_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassnumStages,
};

static enum TuneVarNumber Translation_Model_117_516_957_Sources[] =
{                                      /* '<S294>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotHfNoiseRefLatencyMs,
};

static enum TuneVarNumber Translation_Model_117_517_435_Sources[] =
{                                      /* '<S305>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseEnergyLpfTauS,
};

static enum TuneVarNumber Translation_Model_117_517_422_Sources[] =
{                                      /* '<S314>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0TauS,
};

static enum TuneVarNumber Translation_Model_117_517_415_Sources[] =
{                                      /* '<S317>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFiltTauS,
};

static enum TuneVarNumber Translation_Model_117_517_330_67_18_Sources[] =
{                                      /* '<S321>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale,
};

static enum TuneVarNumber Translation_Model_117_517_331_67_18_Sources[] =
{                                      /* '<S325>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale,
};

static enum TuneVarNumber Translation_Model_117_517_332_67_18_Sources[] =
{                                      /* '<S329>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale,
};

static enum TuneVarNumber Translation_Model_117_517_429_67_18_Sources[] =
{                                      /* '<S333>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin,
};

static enum TuneVarNumber Translation_Model_117_517_515_50_36_Sources[] =
{                                      /* '<S339>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseMicsosCoefficients,
    ID_TuneVar_PreAmpAudiopilotLfNoiseMicnumStages,
};

static enum TuneVarNumber Translation_Model_117_517_516_50_36_Sources[] =
{                                      /* '<S344>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefsosCoefficients,
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefnumStages,
};

static enum TuneVarNumber Translation_Model_117_517_459_67_18_Sources[] =
{                                      /* '<S349>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseOffsetDb,
};

static enum TuneVarNumber Translation_Model_117_517_351_Sources[] =
{                                      /* '<S352>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseRefLatencyMs,
};

static enum TuneVarNumber Translation_Model_117_517_388_Sources[] =
{                                      /* '<S361>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewAttackDbPerS,
};

static enum TuneVarNumber Translation_Model_117_517_397_Sources[] =
{                                      /* '<S364>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_117_517_404_Sources[] =
{                                      /* '<S367>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewSlowDbPerS,
};

static enum TuneVarNumber Translation_Model_117_517_270_67_18_Sources[] =
{                                      /* '<S372>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSlewThresholdDb,
};

static enum TuneVarNumber Translation_Model_117_517_572_67_18_Sources[] =
{                                      /* '<S380>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsAxis,
};

static enum TuneVarNumber Translation_Model_117_517_573_67_18_Sources[] =
{                                      /* '<S384>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl,
};

static enum TuneVarNumber Translation_Model_117_517_577_Sources[] =
{                                      /* '<S386>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsMindBSPL,
};

static enum TuneVarNumber Translation_Model_117_517_582_67_18_Sources[] =
{                                      /* '<S391>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSpeedBoundsOn,
};

static enum TuneVarNumber Translation_Model_117_517_553_67_18_Sources[] =
{                                      /* '<S395>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLfNoiseSysMaxDbspl,
};

static enum TuneVarNumber Translation_Model_117_2074_Sources[] =
{                                      /* '<S409>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateFlagHoldTimeS,
};

static enum TuneVarNumber Translation_Model_117_2078_67_18_Sources[] =
{                                      /* '<S414>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_2079_67_18_Sources[] =
{                                      /* '<S418>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl,
};

static enum TuneVarNumber Translation_Model_117_2082_Sources[] =
{                                      /* '<S420>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodS,
};

static enum TuneVarNumber Translation_Model_117_2086_67_18_Sources[] =
{                                      /* '<S425>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb,
};

static enum TuneVarNumber Translation_Model_117_2087_67_18_Sources[] =
{                                      /* '<S429>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph,
};

static enum TuneVarNumber Translation_Model_117_2093_Sources[] =
{                                      /* '<S432>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioEnergyLpfTauS,
};

static enum TuneVarNumber Translation_Model_117_2099_67_18_Sources[] =
{                                      /* '<S436>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioHighBoundDb,
};

static enum TuneVarNumber Translation_Model_117_2100_67_18_Sources[] =
{                                      /* '<S440>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioLowBoundDb,
};

static enum TuneVarNumber Translation_Model_117_2115_Sources[] =
{                                      /* '<S445>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewAttackDbPerS,
};

static enum TuneVarNumber Translation_Model_117_2121_Sources[] =
{                                      /* '<S448>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_117_2125_67_18_Sources[] =
{                                      /* '<S453>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioSlewThresholdDb,
};

static enum TuneVarNumber Translation_Model_117_2149_Sources[] =
{                                      /* '<S460>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionGamma0TauS,
};

static enum TuneVarNumber Translation_Model_117_2155_Sources[] =
{                                      /* '<S463>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfTauS,
};

static enum TuneVarNumber Translation_Model_117_2158_67_18_Sources[] =
{                                      /* '<S467>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale,
};

static enum TuneVarNumber Translation_Model_117_2159_67_18_Sources[] =
{                                      /* '<S471>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale,
};

static enum TuneVarNumber Translation_Model_120_196_Sources[] =
{                                      /* '<S483>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectFastDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_120_446_Sources[] =
{                                      /* '<S487>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_120_203_Sources[] =
{                                      /* '<S489>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectHoldTimeS,
};

static enum TuneVarNumber Translation_Model_120_122_67_18_Sources[] =
{                                      /* '<S494>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_120_123_67_18_Sources[] =
{                                      /* '<S498>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_120_189_Sources[] =
{                                      /* '<S500>/S-Function' */
    ID_TuneVar_PreAmpAudiopilotLevelDetectSlowDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_120_264_Sources[] =
{                                      /* '<S510>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectFastDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_120_514_Sources[] =
{                                      /* '<S514>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_120_257_Sources[] =
{                                      /* '<S516>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectHoldTimeS,
};

static enum TuneVarNumber Translation_Model_120_218_67_18_Sources[] =
{                                      /* '<S521>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_120_219_67_18_Sources[] =
{                                      /* '<S525>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_120_250_Sources[] =
{                                      /* '<S527>/S-Function' */
    ID_TuneVar_PreAmpDyneqLevelDetectSlowDecayDbPerS,
};

static enum TuneVarNumber Translation_Model_120_439_Sources[] =
{                                      /* '<S534>/S-Function' */
    ID_TuneVar_PreAmpLevelDetectLatencyMs,
};

static enum TuneVarNumber Translation_Model_120_422_50_36_Sources[] =
{                                      /* '<S538>/S-Function' */
    ID_TuneVar_PreAmpLevelDetectPreemphasissosCoefficients,
    ID_TuneVar_PreAmpLevelDetectPreemphasisnumStages,
};

static enum TuneVarNumber Translation_Model_120_319_67_18_Sources[] =
{                                      /* '<S543>/S-Function' */
    ID_TuneVar_PreAmpLevelDetectSysMaxDbspl,
};

static enum TuneVarNumber Translation_Model_123_280_Sources[] =
{                                      /* '<S547>/S-Function' */
    ID_TuneVar_PreAmpVolumeCfgTable,
};

static enum TuneVarNumber Translation_Model_123_281_67_18_Sources[] =
{                                      /* '<S553>/S-Function' */
    ID_TuneVar_PreAmpVolumeCfgmaxgain,
};

static enum TuneVarNumber Translation_Model_123_256_67_18_Sources[] =
{                                      /* '<S557>/S-Function' */
    ID_TuneVar_PreAmpVolumeCfgRampTime,
};

static enum TuneVarNumber Translation_Model_135_79_Sources[] =
{                                      /* '<S566>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgChanRampMap,
};

static enum TuneVarNumber Translation_Model_135_81_67_18_Sources[] =
{                                      /* '<S577>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgBoostDisable,
};

static enum TuneVarNumber Translation_Model_135_83_67_18_Sources[] =
{                                      /* '<S581>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgOffset,
};

static enum TuneVarNumber Translation_Model_135_84_67_18_Sources[] =
{                                      /* '<S585>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgRampTime,
};

static enum TuneVarNumber Translation_Model_135_143_67_18_Sources[] =
{                                      /* '<S589>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgSleepingBeautyMutesBass,
};

static enum TuneVarNumber Translation_Model_135_85_67_18_Sources[] =
{                                      /* '<S593>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgEnableSilentExtreme,
};

static enum TuneVarNumber Translation_Model_135_90_Sources[] =
{                                      /* '<S596>/S-Function' */
    ID_TuneVar_PreAmpBalance_CfgTable,
};

static enum TuneVarNumber Translation_Model_420_67_18_Sources[] =
{                                      /* '<S1053>/S-Function' */
    ID_TuneVar_PreAmpNearWiggleCoeffs,
};

static enum TuneVarNumber Translation_Model_421_67_18_Sources[] =
{                                      /* '<S1057>/S-Function' */
    ID_TuneVar_PreAmpNearDelay,
};

static enum TuneVarNumber Translation_Model_874_36_Sources[] =
{                                      /* '<S1314>/S-Function' */
    ID_TuneVar_NearDr_PooliirsosCoefficients,
    ID_TuneVar_NearDr_PooliirnumStages,
};

static enum TuneVarNumber Translation_Model_863_Sources[] =
{                                      /* '<S1318>/S-Function' */
    ID_TuneVar_NearDr_f1_del,
    ID_TuneVar_NearDr_f2_del,
    ID_TuneVar_NearDr_f3_del,
    ID_TuneVar_NearDr_f4_del,
    ID_TuneVar_NearDr_f5_del,
    ID_TuneVar_NearDr_f6_del,
    ID_TuneVar_NearDr_f7_del,
};

static enum TuneVarNumber Translation_Model_915_36_Sources[] =
{                                      /* '<S1324>/S-Function' */
    ID_TuneVar_NearDr_PoolIirTunablesosCoefficients,
    ID_TuneVar_NearDr_PoolIirTunablenumStages,
};

static enum TuneVarNumber Translation_Model_903_Sources[] =
{                                      /* '<S1328>/S-Function' */
    ID_TuneVar_NearDr_driver_src1,
    ID_TuneVar_NearDr_driver_src2,
    ID_TuneVar_NearDr_driver_src3,
    ID_TuneVar_NearDr_driver_src4,
    ID_TuneVar_NearDr_passenger_src1,
    ID_TuneVar_NearDr_passenger_src2,
    ID_TuneVar_NearDr_passenger_src3,
    ID_TuneVar_NearDr_passenger_src4,
};

static enum TuneVarNumber Translation_Model_926_Sources[] =
{                                      /* '<S1332>/S-Function' */
    ID_TuneVar_NearDr_RouterMap,
};

static enum TuneVarNumber Translation_Model_1026_Sources[] =
{                                      /* '<S1340>/S-Function' */
    ID_TuneVar_NearDr_f1_mix,
    ID_TuneVar_NearDr_f2_mix,
    ID_TuneVar_NearDr_f3_mix,
    ID_TuneVar_NearDr_f4_mix,
    ID_TuneVar_NearDr_f5_mix,
    ID_TuneVar_NearDr_f6_mix,
    ID_TuneVar_NearDr_f7_mix,
    ID_TuneVar_NearDr_LFI0_mix,
    ID_TuneVar_NearDr_LFT0_mix,
    ID_TuneVar_NearDr_RFI0_mix,
    ID_TuneVar_NearDr_RFT0_mix,
    ID_TuneVar_NearDr_LSI0_mix,
    ID_TuneVar_NearDr_LST0_mix,
    ID_TuneVar_NearDr_RSI0_mix,
    ID_TuneVar_NearDr_RST0_mix,
    ID_TuneVar_NearDr_LCI0_mix,
    ID_TuneVar_NearDr_LCT0_mix,
    ID_TuneVar_NearDr_RCI0_mix,
    ID_TuneVar_NearDr_RCT0_mix,
    ID_TuneVar_NearDr_LFI1_mix,
    ID_TuneVar_NearDr_LFT1_mix,
    ID_TuneVar_NearDr_RFI1_mix,
    ID_TuneVar_NearDr_RFT1_mix,
    ID_TuneVar_NearDr_LSI1_mix,
    ID_TuneVar_NearDr_LST1_mix,
    ID_TuneVar_NearDr_RSI1_mix,
    ID_TuneVar_NearDr_RST1_mix,
    ID_TuneVar_NearDr_LCI1_mix,
    ID_TuneVar_NearDr_LCT1_mix,
    ID_TuneVar_NearDr_RCI1_mix,
    ID_TuneVar_NearDr_RCT1_mix,
    ID_TuneVar_NearDr_nv0l_mix,
    ID_TuneVar_NearDr_nv0r_mix,
    ID_TuneVar_NearDr_nv1l_mix,
    ID_TuneVar_NearDr_nv1r_mix,
};

static enum TuneVarNumber Translation_Model_1063_36_Sources[] =
{                                      /* '<S1351>/S-Function' */
    ID_TuneVar_NearFr_PooliirsosCoefficients,
    ID_TuneVar_NearFr_PooliirnumStages,
};

static enum TuneVarNumber Translation_Model_1052_Sources[] =
{                                      /* '<S1355>/S-Function' */
    ID_TuneVar_NearFr_f1_del,
    ID_TuneVar_NearFr_f2_del,
    ID_TuneVar_NearFr_f3_del,
    ID_TuneVar_NearFr_f4_del,
    ID_TuneVar_NearFr_f5_del,
    ID_TuneVar_NearFr_f6_del,
    ID_TuneVar_NearFr_f7_del,
};

static enum TuneVarNumber Translation_Model_1104_36_Sources[] =
{                                      /* '<S1361>/S-Function' */
    ID_TuneVar_NearFr_PoolIirTunablesosCoefficients,
    ID_TuneVar_NearFr_PoolIirTunablenumStages,
};

static enum TuneVarNumber Translation_Model_1092_Sources[] =
{                                      /* '<S1365>/S-Function' */
    ID_TuneVar_NearFr_driver_src1,
    ID_TuneVar_NearFr_driver_src2,
    ID_TuneVar_NearFr_driver_src3,
    ID_TuneVar_NearFr_driver_src4,
    ID_TuneVar_NearFr_passenger_src1,
    ID_TuneVar_NearFr_passenger_src2,
    ID_TuneVar_NearFr_passenger_src3,
    ID_TuneVar_NearFr_passenger_src4,
};

static enum TuneVarNumber Translation_Model_1115_Sources[] =
{                                      /* '<S1369>/S-Function' */
    ID_TuneVar_NearFr_RouterMap,
};

static enum TuneVarNumber Translation_Model_1215_Sources[] =
{                                      /* '<S1377>/S-Function' */
    ID_TuneVar_NearFr_f1_mix,
    ID_TuneVar_NearFr_f2_mix,
    ID_TuneVar_NearFr_f3_mix,
    ID_TuneVar_NearFr_f4_mix,
    ID_TuneVar_NearFr_f5_mix,
    ID_TuneVar_NearFr_f6_mix,
    ID_TuneVar_NearFr_f7_mix,
    ID_TuneVar_NearFr_LFI0_mix,
    ID_TuneVar_NearFr_LFT0_mix,
    ID_TuneVar_NearFr_RFI0_mix,
    ID_TuneVar_NearFr_RFT0_mix,
    ID_TuneVar_NearFr_LSI0_mix,
    ID_TuneVar_NearFr_LST0_mix,
    ID_TuneVar_NearFr_RSI0_mix,
    ID_TuneVar_NearFr_RST0_mix,
    ID_TuneVar_NearFr_LCI0_mix,
    ID_TuneVar_NearFr_LCT0_mix,
    ID_TuneVar_NearFr_RCI0_mix,
    ID_TuneVar_NearFr_RCT0_mix,
    ID_TuneVar_NearFr_LFI1_mix,
    ID_TuneVar_NearFr_LFT1_mix,
    ID_TuneVar_NearFr_RFI1_mix,
    ID_TuneVar_NearFr_RFT1_mix,
    ID_TuneVar_NearFr_LSI1_mix,
    ID_TuneVar_NearFr_LST1_mix,
    ID_TuneVar_NearFr_RSI1_mix,
    ID_TuneVar_NearFr_RST1_mix,
    ID_TuneVar_NearFr_LCI1_mix,
    ID_TuneVar_NearFr_LCT1_mix,
    ID_TuneVar_NearFr_RCI1_mix,
    ID_TuneVar_NearFr_RCT1_mix,
    ID_TuneVar_NearFr_nv0l_mix,
    ID_TuneVar_NearFr_nv0r_mix,
    ID_TuneVar_NearFr_nv1l_mix,
    ID_TuneVar_NearFr_nv1r_mix,
};

static enum TuneVarNumber Translation_Model_831_67_18_Sources[] =
{                                      /* '<S1383>/S-Function' */
    ID_TuneVar_NearRampDbPerSample,
};

static enum TuneVarNumber Translation_Model_1234_Sources[] =
{                                      /* '<S1386>/S-Function' */
    ID_TuneVar_NearHpfCutoffFrequency,
    ID_TuneVar_NearHpfFilterOrder,
};

static enum TuneVarNumber Translation_Model_1475_36_Sources[] =
{                                      /* '<S1402>/S-Function' */
    ID_TuneVar_NearLevelDetectPreEmphasisShelfFiltersosCoefficients,
    ID_TuneVar_NearLevelDetectPreEmphasisShelfFilternumStages,
};

static enum TuneVarNumber Translation_Model_1310_67_18_Sources[] =
{                                      /* '<S1407>/S-Function' */
    ID_TuneVar_NearLevelDetectSysMaxDbspl,
};

static enum TuneVarNumber Translation_Model_1331_Sources[] =
{                                      /* '<S1415>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectFastDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1338_Sources[] =
{                                      /* '<S1419>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_1343_Sources[] =
{                                      /* '<S1421>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectHoldTimes,
};

static enum TuneVarNumber Translation_Model_1347_67_18_Sources[] =
{                                      /* '<S1426>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_1348_67_18_Sources[] =
{                                      /* '<S1430>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_1351_Sources[] =
{                                      /* '<S1432>/S-Function' */
    ID_TuneVar_NearAnn1LevelDetectSlowDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1368_Sources[] =
{                                      /* '<S1441>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectFastDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1375_Sources[] =
{                                      /* '<S1445>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_1380_Sources[] =
{                                      /* '<S1447>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectHoldTimes,
};

static enum TuneVarNumber Translation_Model_1384_67_18_Sources[] =
{                                      /* '<S1452>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_1385_67_18_Sources[] =
{                                      /* '<S1456>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_1388_Sources[] =
{                                      /* '<S1458>/S-Function' */
    ID_TuneVar_NearAnn2LevelDetectSlowDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1405_Sources[] =
{                                      /* '<S1467>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectFastDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1412_Sources[] =
{                                      /* '<S1471>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_1417_Sources[] =
{                                      /* '<S1473>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectHoldTimes,
};

static enum TuneVarNumber Translation_Model_1421_67_18_Sources[] =
{                                      /* '<S1478>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_1422_67_18_Sources[] =
{                                      /* '<S1482>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_1425_Sources[] =
{                                      /* '<S1484>/S-Function' */
    ID_TuneVar_NearAnn3LevelDetectSlowDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1442_Sources[] =
{                                      /* '<S1493>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectFastDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1449_Sources[] =
{                                      /* '<S1497>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectHoldMarginDb,
};

static enum TuneVarNumber Translation_Model_1454_Sources[] =
{                                      /* '<S1499>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectHoldTimes,
};

static enum TuneVarNumber Translation_Model_1458_67_18_Sources[] =
{                                      /* '<S1504>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectMaxVolumeDb,
};

static enum TuneVarNumber Translation_Model_1459_67_18_Sources[] =
{                                      /* '<S1508>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectMinVolumeDb,
};

static enum TuneVarNumber Translation_Model_1462_Sources[] =
{                                      /* '<S1510>/S-Function' */
    ID_TuneVar_NearAnn4LevelDetectSlowDecayDbPers,
};

static enum TuneVarNumber Translation_Model_1254_7_67_18_Sources[] =
{                                      /* '<S1529>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncThresh,
};

static enum TuneVarNumber Translation_Model_1254_8_67_18_Sources[] =
{                                      /* '<S1533>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncSlope,
};

static enum TuneVarNumber Translation_Model_1254_9_67_18_Sources[] =
{                                      /* '<S1537>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMaxBoost,
};

static enum TuneVarNumber Translation_Model_1254_72_67_18_Sources[] =
{                                      /* '<S1541>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcNoiseOverRide,
};

static enum TuneVarNumber Translation_Model_1254_74_67_18_Sources[] =
{                                      /* '<S1545>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1254_75_67_18_Sources[] =
{                                      /* '<S1549>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcBoostOverRide,
};

static enum TuneVarNumber Translation_Model_1254_76_67_18_Sources[] =
{                                      /* '<S1553>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1254_99_67_18_Sources[] =
{                                      /* '<S1557>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar,
};

static enum TuneVarNumber Translation_Model_1254_85_Sources[] =
{                                      /* '<S1559>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcTau,
};

static enum TuneVarNumber Translation_Model_1254_53_67_18_Sources[] =
{                                      /* '<S1566>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMinVncSignal,
};

static enum TuneVarNumber Translation_Model_1254_54_67_18_Sources[] =
{                                      /* '<S1570>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntGainCalcMaxSpl,
};

static enum TuneVarNumber Translation_Model_1255_44_Sources[] =
{                                      /* '<S1574>/S-Function' */
    ID_TuneVar_NearAnn1Ann1NonEntVncAppliedTau,
};

static enum TuneVarNumber Translation_Model_1257_276_67_18_Sources[] =
{                                      /* '<S1581>/S-Function' */
    ID_TuneVar_NearAnn1Ann1MuteRampTime,
};

static enum TuneVarNumber Translation_Model_1259_139_Sources[] =
{                                      /* '<S1583>/S-Function' */
    ID_TuneVar_NearAnn1Ann1VolumeTable,
};

static enum TuneVarNumber Translation_Model_1259_192_67_18_Sources[] =
{                                      /* '<S1590>/S-Function' */
    ID_TuneVar_NearAnn1Ann1VolumeRampRate,
};

static enum TuneVarNumber Translation_Model_1259_190_67_18_Sources[] =
{                                      /* '<S1594>/S-Function' */
    ID_TuneVar_NearAnn1Ann1VolumeRampTime,
};

static enum TuneVarNumber Translation_Model_1265_7_67_18_Sources[] =
{                                      /* '<S1612>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncThresh,
};

static enum TuneVarNumber Translation_Model_1265_8_67_18_Sources[] =
{                                      /* '<S1616>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncSlope,
};

static enum TuneVarNumber Translation_Model_1265_9_67_18_Sources[] =
{                                      /* '<S1620>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMaxBoost,
};

static enum TuneVarNumber Translation_Model_1265_72_67_18_Sources[] =
{                                      /* '<S1624>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcNoiseOverRide,
};

static enum TuneVarNumber Translation_Model_1265_74_67_18_Sources[] =
{                                      /* '<S1628>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1265_75_67_18_Sources[] =
{                                      /* '<S1632>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcBoostOverRide,
};

static enum TuneVarNumber Translation_Model_1265_76_67_18_Sources[] =
{                                      /* '<S1636>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1265_99_67_18_Sources[] =
{                                      /* '<S1640>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar,
};

static enum TuneVarNumber Translation_Model_1265_85_Sources[] =
{                                      /* '<S1642>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcTau,
};

static enum TuneVarNumber Translation_Model_1265_53_67_18_Sources[] =
{                                      /* '<S1649>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMinVncSignal,
};

static enum TuneVarNumber Translation_Model_1265_54_67_18_Sources[] =
{                                      /* '<S1653>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntGainCalcMaxSpl,
};

static enum TuneVarNumber Translation_Model_1266_44_Sources[] =
{                                      /* '<S1657>/S-Function' */
    ID_TuneVar_NearAnn2Ann2NonEntVncAppliedTau,
};

static enum TuneVarNumber Translation_Model_1268_276_67_18_Sources[] =
{                                      /* '<S1664>/S-Function' */
    ID_TuneVar_NearAnn2Ann2MuteRampTime,
};

static enum TuneVarNumber Translation_Model_1270_139_Sources[] =
{                                      /* '<S1666>/S-Function' */
    ID_TuneVar_NearAnn2Ann2VolumeTable,
};

static enum TuneVarNumber Translation_Model_1270_192_67_18_Sources[] =
{                                      /* '<S1673>/S-Function' */
    ID_TuneVar_NearAnn2Ann2VolumeRampRate,
};

static enum TuneVarNumber Translation_Model_1270_190_67_18_Sources[] =
{                                      /* '<S1677>/S-Function' */
    ID_TuneVar_NearAnn2Ann2VolumeRampTime,
};

static enum TuneVarNumber Translation_Model_1276_7_67_18_Sources[] =
{                                      /* '<S1695>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncThresh,
};

static enum TuneVarNumber Translation_Model_1276_8_67_18_Sources[] =
{                                      /* '<S1699>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncSlope,
};

static enum TuneVarNumber Translation_Model_1276_9_67_18_Sources[] =
{                                      /* '<S1703>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMaxBoost,
};

static enum TuneVarNumber Translation_Model_1276_72_67_18_Sources[] =
{                                      /* '<S1707>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcNoiseOverRide,
};

static enum TuneVarNumber Translation_Model_1276_74_67_18_Sources[] =
{                                      /* '<S1711>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1276_75_67_18_Sources[] =
{                                      /* '<S1715>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcBoostOverRide,
};

static enum TuneVarNumber Translation_Model_1276_76_67_18_Sources[] =
{                                      /* '<S1719>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1276_99_67_18_Sources[] =
{                                      /* '<S1723>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar,
};

static enum TuneVarNumber Translation_Model_1276_85_Sources[] =
{                                      /* '<S1725>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcTau,
};

static enum TuneVarNumber Translation_Model_1276_53_67_18_Sources[] =
{                                      /* '<S1732>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMinVncSignal,
};

static enum TuneVarNumber Translation_Model_1276_54_67_18_Sources[] =
{                                      /* '<S1736>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntGainCalcMaxSpl,
};

static enum TuneVarNumber Translation_Model_1277_44_Sources[] =
{                                      /* '<S1740>/S-Function' */
    ID_TuneVar_NearAnn3Ann3NonEntVncAppliedTau,
};

static enum TuneVarNumber Translation_Model_1279_276_67_18_Sources[] =
{                                      /* '<S1747>/S-Function' */
    ID_TuneVar_NearAnn3Ann3MuteRampTime,
};

static enum TuneVarNumber Translation_Model_1281_139_Sources[] =
{                                      /* '<S1749>/S-Function' */
    ID_TuneVar_NearAnn3Ann3VolumeTable,
};

static enum TuneVarNumber Translation_Model_1281_192_67_18_Sources[] =
{                                      /* '<S1756>/S-Function' */
    ID_TuneVar_NearAnn3Ann3VolumeRampRate,
};

static enum TuneVarNumber Translation_Model_1281_190_67_18_Sources[] =
{                                      /* '<S1760>/S-Function' */
    ID_TuneVar_NearAnn3Ann3VolumeRampTime,
};

static enum TuneVarNumber Translation_Model_1287_7_67_18_Sources[] =
{                                      /* '<S1778>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncThresh,
};

static enum TuneVarNumber Translation_Model_1287_8_67_18_Sources[] =
{                                      /* '<S1782>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncSlope,
};

static enum TuneVarNumber Translation_Model_1287_9_67_18_Sources[] =
{                                      /* '<S1786>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMaxBoost,
};

static enum TuneVarNumber Translation_Model_1287_72_67_18_Sources[] =
{                                      /* '<S1790>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcNoiseOverRide,
};

static enum TuneVarNumber Translation_Model_1287_74_67_18_Sources[] =
{                                      /* '<S1794>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1287_75_67_18_Sources[] =
{                                      /* '<S1798>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcBoostOverRide,
};

static enum TuneVarNumber Translation_Model_1287_76_67_18_Sources[] =
{                                      /* '<S1802>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag,
};

static enum TuneVarNumber Translation_Model_1287_99_67_18_Sources[] =
{                                      /* '<S1806>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar,
};

static enum TuneVarNumber Translation_Model_1287_85_Sources[] =
{                                      /* '<S1808>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcTau,
};

static enum TuneVarNumber Translation_Model_1287_53_67_18_Sources[] =
{                                      /* '<S1815>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMinVncSignal,
};

static enum TuneVarNumber Translation_Model_1287_54_67_18_Sources[] =
{                                      /* '<S1819>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntGainCalcMaxSpl,
};

static enum TuneVarNumber Translation_Model_1288_44_Sources[] =
{                                      /* '<S1823>/S-Function' */
    ID_TuneVar_NearAnn4Ann4NonEntVncAppliedTau,
};

static enum TuneVarNumber Translation_Model_1290_276_67_18_Sources[] =
{                                      /* '<S1830>/S-Function' */
    ID_TuneVar_NearAnn4Ann4MuteRampTime,
};

static enum TuneVarNumber Translation_Model_1292_139_Sources[] =
{                                      /* '<S1832>/S-Function' */
    ID_TuneVar_NearAnn4Ann4VolumeTable,
};

static enum TuneVarNumber Translation_Model_1292_192_67_18_Sources[] =
{                                      /* '<S1839>/S-Function' */
    ID_TuneVar_NearAnn4Ann4VolumeRampRate,
};

static enum TuneVarNumber Translation_Model_1292_190_67_18_Sources[] =
{                                      /* '<S1843>/S-Function' */
    ID_TuneVar_NearAnn4Ann4VolumeRampTime,
};

static enum TuneVarNumber Translation_Model_291_138_8_67_18_Sources[] =
{                                      /* '<S1895>/S-Function' */
    ID_TuneVar_TestRouterASDRouterEnableAux,
};

static enum TuneVarNumber Translation_Model_291_138_44_67_18_Sources[] =
{                                      /* '<S1900>/S-Function' */
    ID_TuneVar_TestRouterASDRouterMainSelect,
};

static enum TuneVarNumber Translation_Model_296_67_18_Sources[] =
{                                      /* '<S1904>/S-Function' */
    ID_TuneVar_TestRouterAuxSelect,
};

// -----------------------------------------------------
// ----- Dependent TOPs for each translation function:
static enum TOP_RcvTransNumber Translation_Model_141_1371_Destinations[] =
{                                      /* '<S636>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaTrebleDelay,
};

static enum TOP_RcvTransNumber Translation_Model_141_345_50_36_Destinations[] =
{                                      /* '<S766>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusatailCompEQPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusatailCompEQpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_346_67_18_Destinations[] =
{                                      /* '<S771>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaWiggleFilter,
};

static enum TOP_RcvTransNumber Translation_Model_141_2888_Destinations[] =
{                                      /* '<S759>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateBassDelay,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateBassDelay,
    ID_TOP_RcvTrans_PreAmpMedusaMidrangeDelay,
};

static enum TOP_RcvTransNumber Translation_Model_141_2926_Destinations[] =
{                                      /* '<S783>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerBackwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_2932_Destinations[] =
{                                      /* '<S786>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerBackwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_2939_Destinations[] =
{                                      /* '<S789>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_CS,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_2947_Destinations[] =
{                                      /* '<S792>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Left,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_2955_Destinations[] =
{                                      /* '<S795>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Right,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDownmixWeights_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_2962_Destinations[] =
{                                      /* '<S798>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerForwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_2968_Destinations[] =
{                                      /* '<S801>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerForwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_3372_Destinations[] =
{                                      /* '<S814>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3380_Destinations[] =
{                                      /* '<S817>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3388_Destinations[] =
{                                      /* '<S820>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerDetentLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3395_Destinations[] =
{                                      /* '<S823>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerInterpolation_Method,
};

static enum TOP_RcvTransNumber Translation_Model_141_3402_Destinations[] =
{                                      /* '<S826>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3410_Destinations[] =
{                                      /* '<S829>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3418_Destinations[] =
{                                      /* '<S832>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMaxLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3426_Destinations[] =
{                                      /* '<S835>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3434_Destinations[] =
{                                      /* '<S838>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3442_Destinations[] =
{                                      /* '<S841>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateMixerMinLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3495_Destinations[] =
{                                      /* '<S849>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundPhi,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundCosPhi,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMonoSurroundSinPhi,
};

static enum TOP_RcvTransNumber Translation_Model_141_3596_Destinations[] =
{                                      /* '<S859>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixBackwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_3602_Destinations[] =
{                                      /* '<S862>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixBackwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_3609_Destinations[] =
{                                      /* '<S865>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_CS,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3617_Destinations[] =
{                                      /* '<S868>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Left,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3625_Destinations[] =
{                                      /* '<S871>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Right,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDownmixWeights_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_3632_Destinations[] =
{                                      /* '<S874>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixForwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_3638_Destinations[] =
{                                      /* '<S877>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixForwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_4091_Destinations[] =
{                                      /* '<S890>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4099_Destinations[] =
{                                      /* '<S893>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4107_Destinations[] =
{                                      /* '<S896>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaPremixDetentLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4114_Destinations[] =
{                                      /* '<S899>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixInterpolation_Method,
};

static enum TOP_RcvTransNumber Translation_Model_141_4121_Destinations[] =
{                                      /* '<S902>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4129_Destinations[] =
{                                      /* '<S905>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4137_Destinations[] =
{                                      /* '<S908>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMaxLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4145_Destinations[] =
{                                      /* '<S911>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_CS,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_CS_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4153_Destinations[] =
{                                      /* '<S914>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Left,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Left_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_4161_Destinations[] =
{                                      /* '<S917>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Right,
    ID_TOP_RcvTrans_PreAmpMedusaPremixMinLevel_Right_CAE,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_182_Destinations[] =
{                                      /* '<S929>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsBackwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_188_Destinations[] =
{                                      /* '<S932>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_194_Destinations[] =
{                                      /* '<S935>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsDownmixWeights,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_200_Destinations[] =
{                                      /* '<S938>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsForwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_206_Destinations[] =
{                                      /* '<S941>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsForwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_287_Destinations[] =
{                                      /* '<S948>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsDetentLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_293_Destinations[] =
{                                      /* '<S951>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsInterpolation_Method,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_299_Destinations[] =
{                                      /* '<S954>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsMaxLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_983_305_Destinations[] =
{                                      /* '<S957>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSDrvGainsMinLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_182_Destinations[] =
{                                      /* '<S967>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsBackwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_188_Destinations[] =
{                                      /* '<S970>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_194_Destinations[] =
{                                      /* '<S973>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsDownmixWeights,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_200_Destinations[] =
{                                      /* '<S976>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsForwardDownmixThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_206_Destinations[] =
{                                      /* '<S979>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsForwardDownmixMax,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_287_Destinations[] =
{                                      /* '<S986>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsDetentLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_293_Destinations[] =
{                                      /* '<S989>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsInterpolation_Method,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_299_Destinations[] =
{                                      /* '<S992>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsMaxLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_984_305_Destinations[] =
{                                      /* '<S995>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaVLSPaxGainsMinLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_472_255_36_Destinations[] =
{                                      /* '<S1005>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPoolIirTunableConfigPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPoolIirTunableConfigpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_472_235_Destinations[] =
{                                      /* '<S1008>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramFIRCoeffs,
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramFilterLengths,
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramPaddedFilterLengths,
};

static enum TOP_RcvTransNumber Translation_Model_141_472_239_67_18_Destinations[]
    =
{                                      /* '<S1015>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramInputMapping,
};

static enum TOP_RcvTransNumber Translation_Model_141_472_240_67_18_Destinations[]
    =
{                                      /* '<S1019>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDRHoligramOutputMapping,
};

static enum TOP_RcvTransNumber Translation_Model_141_473_12_36_Destinations[] =
{                                      /* '<S1023>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFRHoligramIirConfigPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaFRHoligramIirConfigpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_595_191_Destinations[] =
{                                      /* '<S1027>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQFIRCoeffs,
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQFilterLengths,
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQPaddedFilterLengths,
};

static enum TOP_RcvTransNumber Translation_Model_141_595_238_36_Destinations[] =
{                                      /* '<S1030>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQIirConfigPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaHeadrestCompEQIirConfigpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_4193_Destinations[] =
{                                      /* '<S1036>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDRSpeakerDelay,
    ID_TOP_RcvTrans_PreAmpMedusaFRSpeakerDelay,
};

static enum TOP_RcvTransNumber Translation_Model_150_574_67_18_Destinations[] =
{                                      /* '<S1044>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaRoutingMap,
};

static enum TOP_RcvTransNumber Translation_Model_232_8_34_50_36_Destinations[] =
{                                      /* '<S1165>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationIIRPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationIIRpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_232_8_36_67_18_Destinations[] =
{                                      /* '<S1170>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVLSXtalkCancellationDelay,
};

static enum TOP_RcvTransNumber Translation_Model_232_11_191_Destinations[] =
{                                      /* '<S1172>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationDrvFIRCoeffs,
    ID_TOP_RcvTrans_PreAmpVLSGenerationDrvPaddedFilterLengths,
};

static enum TOP_RcvTransNumber Translation_Model_232_12_191_Destinations[] =
{                                      /* '<S1175>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVLSGenerationPaxFIRCoeffs,
    ID_TOP_RcvTrans_PreAmpVLSGenerationPaxPaddedFilterLengths,
};

static enum TOP_RcvTransNumber Translation_Model_247_149_Destinations[] =
{                                      /* '<S1183>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassBoostCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_247_153_Destinations[] =
{                                      /* '<S1184>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassCutCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_247_174_Destinations[] =
{                                      /* '<S1182>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassBoostMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_247_176_Destinations[] =
{                                      /* '<S1185>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassCutMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_247_210_67_18_Destinations[] =
{                                      /* '<S1199>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassOffset,
};

static enum TOP_RcvTransNumber Translation_Model_247_229_67_18_Destinations[] =
{                                      /* '<S1203>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassramptime,
};

static enum TOP_RcvTransNumber Translation_Model_247_209_67_18_Destinations[] =
{                                      /* '<S1207>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBassScale,
};

static enum TOP_RcvTransNumber Translation_Model_249_47_Destinations[] =
{                                      /* '<S1210>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeBoostCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_249_48_Destinations[] =
{                                      /* '<S1211>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeCutCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_249_46_Destinations[] =
{                                      /* '<S1209>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeBoostMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_249_49_Destinations[] =
{                                      /* '<S1212>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeCutMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_249_50_67_18_Destinations[] =
{                                      /* '<S1226>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeOffset,
};

static enum TOP_RcvTransNumber Translation_Model_249_51_67_18_Destinations[] =
{                                      /* '<S1230>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_249_52_67_18_Destinations[] =
{                                      /* '<S1234>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMidrangeScale,
};

static enum TOP_RcvTransNumber Translation_Model_642_Destinations[] =
{                                      /* '<S1241>/S-Function' */
    ID_TOP_RcvTrans_PreAmpA,
};

static enum TOP_RcvTransNumber Translation_Model_670_67_18_Destinations[] =
{                                      /* '<S1250>/S-Function' */
    ID_TOP_RcvTrans_PreAmpG,
};

static enum TOP_RcvTransNumber Translation_Model_712_Destinations[] =
{                                      /* '<S1256>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAnnPred,
};

static enum TOP_RcvTransNumber Translation_Model_729_Destinations[] =
{                                      /* '<S1262>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLimiterattack,
};

static enum TOP_RcvTransNumber Translation_Model_730_Destinations[] =
{                                      /* '<S1263>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLimiterdecay,
};

static enum TOP_RcvTransNumber Translation_Model_731_Destinations[] =
{                                      /* '<S1264>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLimitermaxAttack,
};

static enum TOP_RcvTransNumber Translation_Model_741_Destinations[] =
{                                      /* '<S1268>/S-Function' */
    ID_TOP_RcvTrans_PreAmpOffset,
};

static enum TOP_RcvTransNumber Translation_Model_747_Destinations[] =
{                                      /* '<S1271>/S-Function' */
    ID_TOP_RcvTrans_PreAmpUpperThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_251_149_Destinations[] =
{                                      /* '<S1275>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleBoostCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_251_153_Destinations[] =
{                                      /* '<S1276>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleCutCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_251_174_Destinations[] =
{                                      /* '<S1274>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleBoostMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_251_176_Destinations[] =
{                                      /* '<S1277>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleCutMaximum_dB,
};

static enum TOP_RcvTransNumber Translation_Model_251_210_67_18_Destinations[] =
{                                      /* '<S1291>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleOffset,
};

static enum TOP_RcvTransNumber Translation_Model_251_229_67_18_Destinations[] =
{                                      /* '<S1295>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleramptime,
};

static enum TOP_RcvTransNumber Translation_Model_251_209_67_18_Destinations[] =
{                                      /* '<S1299>/S-Function' */
    ID_TOP_RcvTrans_PreAmpTrebleScale,
};

static enum TOP_RcvTransNumber Translation_Model_1495_Destinations[] =
{                                      /* '<S1857>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimiterattack,
    ID_TOP_RcvTrans_PostProcessLimiterk1,
};

static enum TOP_RcvTransNumber Translation_Model_1498_Destinations[] =
{                                      /* '<S1860>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimiterattack_low,
    ID_TOP_RcvTrans_PostProcessLimiterk1_low,
};

static enum TOP_RcvTransNumber Translation_Model_1496_Destinations[] =
{                                      /* '<S1858>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimiterdecay,
};

static enum TOP_RcvTransNumber Translation_Model_1499_Destinations[] =
{                                      /* '<S1861>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimiterdecay_low,
};

static enum TOP_RcvTransNumber Translation_Model_1497_Destinations[] =
{                                      /* '<S1859>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimitermaxAttack,
};

static enum TOP_RcvTransNumber Translation_Model_1500_Destinations[] =
{                                      /* '<S1862>/S-Function' */
    ID_TOP_RcvTrans_PostProcessLimitermaxAttack_low,
};

static enum TOP_RcvTransNumber Translation_Model_72_276_67_18_Destinations[] =
{                                      /* '<S1874>/S-Function' */
    ID_TOP_RcvTrans_PostProcessMuteRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_76_36_Destinations[] =
{                                      /* '<S1877>/S-Function' */
    ID_TOP_RcvTrans_PostProcessPostLimiterEqPooliirNumStages,
    ID_TOP_RcvTrans_PostProcessPostLimiterEqpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_1527_Destinations[] =
{                                      /* '<S1881>/S-Function' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmin,
    ID_TOP_RcvTrans_PostProcessSoftClipperxmax,
    ID_TOP_RcvTrans_PostProcessSoftClipperp2,
};

static enum TOP_RcvTransNumber Translation_Model_1528_Destinations[] =
{                                      /* '<S1882>/S-Function' */
    ID_TOP_RcvTrans_PostProcessSoftClipperxmin_low,
    ID_TOP_RcvTrans_PostProcessSoftClipperxmax_low,
    ID_TOP_RcvTrans_PostProcessSoftClipperp2_low,
};

static enum TOP_RcvTransNumber Translation_Model_397_Destinations[] =
{                                      /* '<S8>/S-Function' */
    ID_TOP_RcvTrans_InputSelectRouterCfgOutMap,
};

static enum TOP_RcvTransNumber Translation_Model_141_246_96_Destinations[] =
{                                      /* '<S609>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLeftMixWeights,
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerRightMixWeights,
};

static enum TOP_RcvTransNumber Translation_Model_141_246_141_36_Destinations[] =
{                                      /* '<S613>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerHpfPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerHpfpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_246_148_36_Destinations[] =
{                                      /* '<S617>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLpfPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerLpfpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_246_111_67_18_Destinations[]
    =
{                                      /* '<S622>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaBassManagerGainLfe2C,
};

static enum TOP_RcvTransNumber Translation_Model_141_1196_67_18_Destinations[] =
{                                      /* '<S628>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDummyTune,
};

static enum TOP_RcvTransNumber Translation_Model_141_1560_Destinations[] =
{                                      /* '<S647>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsXpMax,
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsLokRokMaxScaleFactor,
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsXpMin,
};

static enum TOP_RcvTransNumber Translation_Model_141_1561_Destinations[] =
{                                      /* '<S648>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpCoeffsESDStepSize,
};

static enum TOP_RcvTransNumber Translation_Model_141_1988_Destinations[] =
{                                      /* '<S653>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumFastPsdSmoothFactor,
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumSlowPsdSmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_1989_Destinations[] =
{                                      /* '<S654>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumDirectPathSamplesDec,
};

static enum TOP_RcvTransNumber Translation_Model_141_1990_Destinations[] =
{                                      /* '<S655>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumLsSmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2031_67_18_Destinations[] =
{                                      /* '<S664>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaDeciRateFdpSpumOverwrite,
};

static enum TOP_RcvTransNumber Translation_Model_141_2423_Destinations[] =
{                                      /* '<S674>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsXpMax,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsLokRokMaxScaleFactor,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsXpMin,
};

static enum TOP_RcvTransNumber Translation_Model_141_2424_Destinations[] =
{                                      /* '<S675>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpCoeffsESDStepSize,
};

static enum TOP_RcvTransNumber Translation_Model_141_2654_Destinations[] =
{                                      /* '<S680>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumFastPsdSmoothFactor,
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumSlowPsdSmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2655_Destinations[] =
{                                      /* '<S681>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumDirectPathSamplesDec,
};

static enum TOP_RcvTransNumber Translation_Model_141_2656_Destinations[] =
{                                      /* '<S682>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumLsSmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2697_67_18_Destinations[] =
{                                      /* '<S691>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaFullRateFdpSpumOverwrite,
};

static enum TOP_RcvTransNumber Translation_Model_141_2783_Destinations[] =
{                                      /* '<S696>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLevelPole,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLevelGain,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothPole,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothGain,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothResetPole,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLSSmoothResetGain,
};

static enum TOP_RcvTransNumber Translation_Model_141_2787_Destinations[] =
{                                      /* '<S700>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorHPFNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorHPFCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_141_2784_Destinations[] =
{                                      /* '<S697>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdZeroLevel,
};

static enum TOP_RcvTransNumber Translation_Model_141_2785_Destinations[] =
{                                      /* '<S698>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorLRMatchTolerance,
};

static enum TOP_RcvTransNumber Translation_Model_141_2786_Destinations[] =
{                                      /* '<S699>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdMono,
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorThresholdStereo,
};

static enum TOP_RcvTransNumber Translation_Model_141_2808_67_18_Destinations[] =
{                                      /* '<S713>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaMonoDetectorEnable,
};

static enum TOP_RcvTransNumber Translation_Model_141_2849_Destinations[] =
{                                      /* '<S717>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstPSDSmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2850_Destinations[] =
{                                      /* '<S718>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstDecaySmoothFactor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2851_Destinations[] =
{                                      /* '<S719>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstFastAttack,
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstSlowAttack,
};

static enum TOP_RcvTransNumber Translation_Model_141_2852_Destinations[] =
{                                      /* '<S720>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstStepIncrement,
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstStepDecrement,
};

static enum TOP_RcvTransNumber Translation_Model_141_2853_Destinations[] =
{                                      /* '<S721>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstDirectPathFramesFs,
};

static enum TOP_RcvTransNumber Translation_Model_141_2865_67_18_Destinations[] =
{                                      /* '<S737>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstNoiseFloor,
};

static enum TOP_RcvTransNumber Translation_Model_141_2866_67_18_Destinations[] =
{                                      /* '<S741>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstOnsetThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_2867_67_18_Destinations[] =
{                                      /* '<S745>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstSlewThreshold,
};

static enum TOP_RcvTransNumber Translation_Model_141_2878_50_36_Destinations[] =
{                                      /* '<S749>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstHPFPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpMedusaSPUMDecayEstHPFpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_449_67_18_Destinations[] =
{                                      /* '<S1075>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeControlBoostDisable,
};

static enum TOP_RcvTransNumber Translation_Model_450_67_18_Destinations[] =
{                                      /* '<S1079>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeControlEnableSilentExtreme,
};

static enum TOP_RcvTransNumber Translation_Model_455_Destinations[] =
{                                      /* '<S1082>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeControlTableDb,
    ID_TOP_RcvTrans_PreAmpFadeControlTableIdx,
};

static enum TOP_RcvTransNumber Translation_Model_459_67_18_Destinations[] =
{                                      /* '<S1086>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeControloffset,
};

static enum TOP_RcvTransNumber Translation_Model_460_67_18_Destinations[] =
{                                      /* '<S1090>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeControlRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_175_136_99_Destinations[] =
{                                      /* '<S1096>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeRamperDRChannelToRamperMap,
};

static enum TOP_RcvTransNumber Translation_Model_175_136_98_Destinations[] =
{                                      /* '<S1095>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeRamperDRTOPFilterCoefficients,
};

static enum TOP_RcvTransNumber Translation_Model_176_136_99_Destinations[] =
{                                      /* '<S1103>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeRamperFRChannelToRamperMap,
};

static enum TOP_RcvTransNumber Translation_Model_176_136_98_Destinations[] =
{                                      /* '<S1102>/S-Function' */
    ID_TOP_RcvTrans_PreAmpFadeRamperFRTOPFilterCoefficients,
};

static enum TOP_RcvTransNumber Translation_Model_489_67_18_Destinations[] =
{                                      /* '<S1110>/S-Function' */
    ID_TOP_RcvTrans_PreAmpMuteControlRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_533_Destinations[] =
{                                      /* '<S1113>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRChannelToRamperMap,
};

static enum TOP_RcvTransNumber Translation_Model_538_67_18_Destinations[] =
{                                      /* '<S1122>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDROffset,
};

static enum TOP_RcvTransNumber Translation_Model_539_67_18_Destinations[] =
{                                      /* '<S1126>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_540_67_18_Destinations[] =
{                                      /* '<S1130>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRMutesBass,
};

static enum TOP_RcvTransNumber Translation_Model_545_Destinations[] =
{                                      /* '<S1132>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRTableDb,
    ID_TOP_RcvTrans_PreAmpSleepingBeautyDRTableIdx,
};

static enum TOP_RcvTransNumber Translation_Model_596_Destinations[] =
{                                      /* '<S1136>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRChannelToRamperMap,
};

static enum TOP_RcvTransNumber Translation_Model_601_67_18_Destinations[] =
{                                      /* '<S1145>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFROffset,
};

static enum TOP_RcvTransNumber Translation_Model_602_67_18_Destinations[] =
{                                      /* '<S1149>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_603_67_18_Destinations[] =
{                                      /* '<S1153>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRMutesBass,
};

static enum TOP_RcvTransNumber Translation_Model_608_Destinations[] =
{                                      /* '<S1155>/S-Function' */
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRTableDb,
    ID_TOP_RcvTrans_PreAmpSleepingBeautyFRTableIdx,
};

static enum TOP_RcvTransNumber Translation_Model_117_21_67_18_Destinations[] =
{                                      /* '<S26>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTwoDowngrade,
};

static enum TOP_RcvTransNumber Translation_Model_117_1781_Destinations[] =
{                                      /* '<S30>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHvacTable,
};

static enum TOP_RcvTransNumber Translation_Model_117_43_332_Destinations[] =
{                                      /* '<S38>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotAntiZipperRampLpfNumerator,
    ID_TOP_RcvTrans_PreAmpAudiopilotAntiZipperRampLpfDenominator,
};

static enum TOP_RcvTransNumber Translation_Model_117_43_351_Destinations[] =
{                                      /* '<S40>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassBpfNumerator,
    ID_TOP_RcvTrans_PreAmpAudiopilotBassBpfDenominator,
};

static enum TOP_RcvTransNumber Translation_Model_117_43_340_Destinations[] =
{                                      /* '<S44>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfNumerator,
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfDenominator,
};

static enum TOP_RcvTransNumber Translation_Model_117_43_403_Destinations[] =
{                                      /* '<S48>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeLpfAlignDelaySamples,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_721_Destinations[] =
{                                      /* '<S68>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassSlope0Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_722_Destinations[] =
{                                      /* '<S69>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeSlope0Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_723_Destinations[] =
{                                      /* '<S70>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleSlope0Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_894_Destinations[] =
{                                      /* '<S73>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassSlope1Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_736_Destinations[] =
{                                      /* '<S72>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeSlope1Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_895_Destinations[] =
{                                      /* '<S71>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleSlope1Dbperdb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_469_67_18_Destinations[]
    =
{                                      /* '<S84>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassThresh0Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_470_67_18_Destinations[]
    =
{                                      /* '<S88>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassThresh1Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_332_67_18_Destinations[]
    =
{                                      /* '<S92>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseHighBoundDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_333_67_18_Destinations[]
    =
{                                      /* '<S96>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseLowBoundDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_334_67_18_Destinations[]
    =
{                                      /* '<S100>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseHighBoundDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_335_67_18_Destinations[]
    =
{                                      /* '<S104>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseLowBoundDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_341_67_18_Destinations[]
    =
{                                      /* '<S108>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeThresh0Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_342_67_18_Destinations[]
    =
{                                      /* '<S112>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeThresh1Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_484_67_18_Destinations[]
    =
{                                      /* '<S116>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleThresh0Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_485_67_18_Destinations[]
    =
{                                      /* '<S120>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleThresh1Db,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_315_67_18_Destinations[]
    =
{                                      /* '<S136>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassDownwardThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_316_67_18_Destinations[]
    =
{                                      /* '<S140>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxAudiopilotBoostDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_317_67_18_Destinations[]
    =
{                                      /* '<S144>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxDyneqBoostDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_318_67_18_Destinations[]
    =
{                                      /* '<S148>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassMaxTotalBoostDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_666_Destinations[] =
{                                      /* '<S153>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_645_Destinations[] =
{                                      /* '<S152>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotBassDownwardSlopeDbPerDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_672_Destinations[] =
{                                      /* '<S154>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleDownwardSlopeDbPerDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_325_67_18_Destinations[]
    =
{                                      /* '<S161>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotDyneqBassThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_633_Destinations[] =
{                                      /* '<S164>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotDyneqBassSlopeDbPerDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_343_67_18_Destinations[]
    =
{                                      /* '<S169>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMinSignalLevelDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_337_67_18_Destinations[]
    =
{                                      /* '<S173>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeDownwardThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_338_67_18_Destinations[]
    =
{                                      /* '<S177>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotMidrangeMaxTotalBoostDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_913_67_18_Destinations[]
    =
{                                      /* '<S181>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleDownwardThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_346_67_18_Destinations[]
    =
{                                      /* '<S185>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotTrebleMaxTotalBoostDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_44_328_Destinations[] =
{                                      /* '<S188>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotEnableRampCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_516_1944_Destinations[] =
{                                      /* '<S200>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseRefPowerMin,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1707_67_18_Destinations[] =
{                                      /* '<S214>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1708_67_18_Destinations[] =
{                                      /* '<S218>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1732_67_18_Destinations[] =
{                                      /* '<S224>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1733_67_18_Destinations[] =
{                                      /* '<S228>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1751_67_18_Destinations[] =
{                                      /* '<S238>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1752_67_18_Destinations[] =
{                                      /* '<S242>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1753_67_18_Destinations[] =
{                                      /* '<S246>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1755_67_18_Destinations[] =
{                                      /* '<S250>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1754_67_18_Destinations[] =
{                                      /* '<S254>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain,
};

static enum TOP_RcvTransNumber Translation_Model_117_516_1758_Destinations[] =
{                                      /* '<S257>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionSubWinLenSamples,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1774_67_18_Destinations[] =
{                                      /* '<S262>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_516_1789_Destinations[] =
{                                      /* '<S267>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewAttackDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_516_1795_Destinations[] =
{                                      /* '<S270>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewDecayDbPerSample,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1804_67_18_Destinations[] =
{                                      /* '<S275>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseSlewThresholdDb,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1778_67_18_Destinations[] =
{                                      /* '<S279>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseOffsetDb,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1849_50_36_Destinations[] =
{                                      /* '<S285>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessAntiAliasPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs,
};

static enum TOP_RcvTransNumber
    Translation_Model_117_516_1847_50_36_Destinations[] =
{                                      /* '<S290>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_117_516_957_Destinations[] =
{                                      /* '<S294>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotHfNoiseRefLatencySamples,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_435_Destinations[] =
{                                      /* '<S305>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseEnergyLpfCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_422_Destinations[] =
{                                      /* '<S314>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionGamma0,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_415_Destinations[] =
{                                      /* '<S317>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_330_67_18_Destinations[]
    =
{                                      /* '<S321>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_331_67_18_Destinations[]
    =
{                                      /* '<S325>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_332_67_18_Destinations[]
    =
{                                      /* '<S329>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_429_67_18_Destinations[]
    =
{                                      /* '<S333>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_515_50_36_Destinations[]
    =
{                                      /* '<S339>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseMicPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseMicpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_516_50_36_Destinations[]
    =
{                                      /* '<S344>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_459_67_18_Destinations[]
    =
{                                      /* '<S349>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseOffsetDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_351_Destinations[] =
{                                      /* '<S352>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseRefLatencySamples,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_388_Destinations[] =
{                                      /* '<S361>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewAttackDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_397_Destinations[] =
{                                      /* '<S364>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_404_Destinations[] =
{                                      /* '<S367>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewSlowDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_270_67_18_Destinations[]
    =
{                                      /* '<S372>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSlewThresholdDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_572_67_18_Destinations[]
    =
{                                      /* '<S380>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsAxis,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_573_67_18_Destinations[]
    =
{                                      /* '<S384>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_577_Destinations[] =
{                                      /* '<S386>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMinDbspl,
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_582_67_18_Destinations[]
    =
{                                      /* '<S391>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSpeedBoundsOn,
};

static enum TOP_RcvTransNumber Translation_Model_117_517_553_67_18_Destinations[]
    =
{                                      /* '<S395>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLfNoiseSysMaxDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_2074_Destinations[] =
{                                      /* '<S409>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateFlagHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_117_2078_67_18_Destinations[] =
{                                      /* '<S414>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_2079_67_18_Destinations[] =
{                                      /* '<S418>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_117_2082_Destinations[] =
{                                      /* '<S420>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodSamples,
};

static enum TOP_RcvTransNumber Translation_Model_117_2086_67_18_Destinations[] =
{                                      /* '<S425>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_2087_67_18_Destinations[] =
{                                      /* '<S429>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph,
};

static enum TOP_RcvTransNumber Translation_Model_117_2093_Destinations[] =
{                                      /* '<S432>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioEnergyLpfCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_2099_67_18_Destinations[] =
{                                      /* '<S436>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioHighBoundDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_2100_67_18_Destinations[] =
{                                      /* '<S440>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioLowBoundDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_2115_Destinations[] =
{                                      /* '<S445>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewAttackDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_2121_Destinations[] =
{                                      /* '<S448>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_117_2125_67_18_Destinations[] =
{                                      /* '<S453>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioSlewThresholdDb,
};

static enum TOP_RcvTransNumber Translation_Model_117_2149_Destinations[] =
{                                      /* '<S460>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionGamma0,
};

static enum TOP_RcvTransNumber Translation_Model_117_2155_Destinations[] =
{                                      /* '<S463>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef,
};

static enum TOP_RcvTransNumber Translation_Model_117_2158_67_18_Destinations[] =
{                                      /* '<S467>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale,
};

static enum TOP_RcvTransNumber Translation_Model_117_2159_67_18_Destinations[] =
{                                      /* '<S471>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale,
};

static enum TOP_RcvTransNumber Translation_Model_120_196_Destinations[] =
{                                      /* '<S483>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_120_446_Destinations[] =
{                                      /* '<S487>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectHoldMarginDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_203_Destinations[] =
{                                      /* '<S489>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_120_122_67_18_Destinations[] =
{                                      /* '<S494>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_123_67_18_Destinations[] =
{                                      /* '<S498>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_189_Destinations[] =
{                                      /* '<S500>/S-Function' */
    ID_TOP_RcvTrans_PreAmpAudiopilotLevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_120_264_Destinations[] =
{                                      /* '<S510>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_120_514_Destinations[] =
{                                      /* '<S514>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectHoldMarginDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_257_Destinations[] =
{                                      /* '<S516>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_120_218_67_18_Destinations[] =
{                                      /* '<S521>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_219_67_18_Destinations[] =
{                                      /* '<S525>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_120_250_Destinations[] =
{                                      /* '<S527>/S-Function' */
    ID_TOP_RcvTrans_PreAmpDyneqLevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_120_439_Destinations[] =
{                                      /* '<S534>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLevelDetectMusicDelaySamples,
};

static enum TOP_RcvTransNumber Translation_Model_120_422_50_36_Destinations[] =
{                                      /* '<S538>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLevelDetectPreemphasisPooliirNumStages,
    ID_TOP_RcvTrans_PreAmpLevelDetectPreemphasispooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_120_319_67_18_Destinations[] =
{                                      /* '<S543>/S-Function' */
    ID_TOP_RcvTrans_PreAmpLevelDetectSysMaxDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_123_280_Destinations[] =
{                                      /* '<S547>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgTable_Idx,
    ID_TOP_RcvTrans_PreAmpVolumeCfgTable_dB,
};

static enum TOP_RcvTransNumber Translation_Model_123_281_67_18_Destinations[] =
{                                      /* '<S553>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgmaxgain,
};

static enum TOP_RcvTransNumber Translation_Model_123_256_67_18_Destinations[] =
{                                      /* '<S557>/S-Function' */
    ID_TOP_RcvTrans_PreAmpVolumeCfgRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_135_79_Destinations[] =
{                                      /* '<S566>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgChanRampMap,
};

static enum TOP_RcvTransNumber Translation_Model_135_81_67_18_Destinations[] =
{                                      /* '<S577>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgBoostDisable,
};

static enum TOP_RcvTransNumber Translation_Model_135_83_67_18_Destinations[] =
{                                      /* '<S581>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgOffset,
};

static enum TOP_RcvTransNumber Translation_Model_135_84_67_18_Destinations[] =
{                                      /* '<S585>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_135_143_67_18_Destinations[] =
{                                      /* '<S589>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgSleepingBeautyMutesBass,
};

static enum TOP_RcvTransNumber Translation_Model_135_85_67_18_Destinations[] =
{                                      /* '<S593>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgEnableSilentExtreme,
};

static enum TOP_RcvTransNumber Translation_Model_135_90_Destinations[] =
{                                      /* '<S596>/S-Function' */
    ID_TOP_RcvTrans_PreAmpBalance_CfgTableDb,
    ID_TOP_RcvTrans_PreAmpBalance_CfgTableIdx,
};

static enum TOP_RcvTransNumber Translation_Model_420_67_18_Destinations[] =
{                                      /* '<S1053>/S-Function' */
    ID_TOP_RcvTrans_PreAmpNearWiggleCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_421_67_18_Destinations[] =
{                                      /* '<S1057>/S-Function' */
    ID_TOP_RcvTrans_PreAmpNearDelay,
};

static enum TOP_RcvTransNumber Translation_Model_874_36_Destinations[] =
{                                      /* '<S1314>/S-Function' */
    ID_TOP_RcvTrans_NearDr_PooliirPooliirNumStages,
    ID_TOP_RcvTrans_NearDr_PooliirpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_863_Destinations[] =
{                                      /* '<S1318>/S-Function' */
    ID_TOP_RcvTrans_NearDr_EqDelays,
};

static enum TOP_RcvTransNumber Translation_Model_915_36_Destinations[] =
{                                      /* '<S1324>/S-Function' */
    ID_TOP_RcvTrans_NearDr_PoolIirTunablePooliirNumStages,
    ID_TOP_RcvTrans_NearDr_PoolIirTunablepooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_903_Destinations[] =
{                                      /* '<S1328>/S-Function' */
    ID_TOP_RcvTrans_NearDr_eqdelays,
};

static enum TOP_RcvTransNumber Translation_Model_926_Destinations[] =
{                                      /* '<S1332>/S-Function' */
    ID_TOP_RcvTrans_NearDr_RouterOutMap,
};

static enum TOP_RcvTransNumber Translation_Model_1026_Destinations[] =
{                                      /* '<S1340>/S-Function' */
    ID_TOP_RcvTrans_NearDr_mix,
};

static enum TOP_RcvTransNumber Translation_Model_1063_36_Destinations[] =
{                                      /* '<S1351>/S-Function' */
    ID_TOP_RcvTrans_NearFr_PooliirPooliirNumStages,
    ID_TOP_RcvTrans_NearFr_PooliirpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_1052_Destinations[] =
{                                      /* '<S1355>/S-Function' */
    ID_TOP_RcvTrans_NearFr_EqDelays,
};

static enum TOP_RcvTransNumber Translation_Model_1104_36_Destinations[] =
{                                      /* '<S1361>/S-Function' */
    ID_TOP_RcvTrans_NearFr_PoolIirTunablePooliirNumStages,
    ID_TOP_RcvTrans_NearFr_PoolIirTunablepooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_1092_Destinations[] =
{                                      /* '<S1365>/S-Function' */
    ID_TOP_RcvTrans_NearFr_eqdelays,
};

static enum TOP_RcvTransNumber Translation_Model_1115_Destinations[] =
{                                      /* '<S1369>/S-Function' */
    ID_TOP_RcvTrans_NearFr_RouterOutMap,
};

static enum TOP_RcvTransNumber Translation_Model_1215_Destinations[] =
{                                      /* '<S1377>/S-Function' */
    ID_TOP_RcvTrans_NearFr_mix,
};

static enum TOP_RcvTransNumber Translation_Model_831_67_18_Destinations[] =
{                                      /* '<S1383>/S-Function' */
    ID_TOP_RcvTrans_NearRampDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1234_Destinations[] =
{                                      /* '<S1386>/S-Function' */
    ID_TOP_RcvTrans_NearNumStages,
    ID_TOP_RcvTrans_NearCoefficients,
};

static enum TOP_RcvTransNumber Translation_Model_1475_36_Destinations[] =
{                                      /* '<S1402>/S-Function' */
    ID_TOP_RcvTrans_NearLevelDetectPreEmphasisShelfFilterPooliirNumStages,
    ID_TOP_RcvTrans_NearLevelDetectPreEmphasisShelfFilterpooliirCoeffs,
};

static enum TOP_RcvTransNumber Translation_Model_1310_67_18_Destinations[] =
{                                      /* '<S1407>/S-Function' */
    ID_TOP_RcvTrans_NearLevelDetectSysMaxDbspl,
};

static enum TOP_RcvTransNumber Translation_Model_1331_Destinations[] =
{                                      /* '<S1415>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1338_Destinations[] =
{                                      /* '<S1419>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetecthold_margin_db,
};

static enum TOP_RcvTransNumber Translation_Model_1343_Destinations[] =
{                                      /* '<S1421>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_1347_67_18_Destinations[] =
{                                      /* '<S1426>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1348_67_18_Destinations[] =
{                                      /* '<S1430>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1351_Destinations[] =
{                                      /* '<S1432>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1LevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1368_Destinations[] =
{                                      /* '<S1441>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1375_Destinations[] =
{                                      /* '<S1445>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectHoldMarginDb,
};

static enum TOP_RcvTransNumber Translation_Model_1380_Destinations[] =
{                                      /* '<S1447>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_1384_67_18_Destinations[] =
{                                      /* '<S1452>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1385_67_18_Destinations[] =
{                                      /* '<S1456>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1388_Destinations[] =
{                                      /* '<S1458>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2LevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1405_Destinations[] =
{                                      /* '<S1467>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1412_Destinations[] =
{                                      /* '<S1471>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectHoldMarginDb,
};

static enum TOP_RcvTransNumber Translation_Model_1417_Destinations[] =
{                                      /* '<S1473>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_1421_67_18_Destinations[] =
{                                      /* '<S1478>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1422_67_18_Destinations[] =
{                                      /* '<S1482>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1425_Destinations[] =
{                                      /* '<S1484>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3LevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1442_Destinations[] =
{                                      /* '<S1493>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectFastDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1449_Destinations[] =
{                                      /* '<S1497>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectHoldMarginDb,
};

static enum TOP_RcvTransNumber Translation_Model_1454_Destinations[] =
{                                      /* '<S1499>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectHoldTimeSamples,
};

static enum TOP_RcvTransNumber Translation_Model_1458_67_18_Destinations[] =
{                                      /* '<S1504>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectMaxVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1459_67_18_Destinations[] =
{                                      /* '<S1508>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectMinVolumeDb,
};

static enum TOP_RcvTransNumber Translation_Model_1462_Destinations[] =
{                                      /* '<S1510>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4LevelDetectSlowDecayDbPerSample,
};

static enum TOP_RcvTransNumber Translation_Model_1254_7_67_18_Destinations[] =
{                                      /* '<S1529>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncThresh,
};

static enum TOP_RcvTransNumber Translation_Model_1254_8_67_18_Destinations[] =
{                                      /* '<S1533>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncSlope,
};

static enum TOP_RcvTransNumber Translation_Model_1254_9_67_18_Destinations[] =
{                                      /* '<S1537>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMaxBoost,
};

static enum TOP_RcvTransNumber Translation_Model_1254_72_67_18_Destinations[] =
{                                      /* '<S1541>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNoiseOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1254_74_67_18_Destinations[] =
{                                      /* '<S1545>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1254_75_67_18_Destinations[] =
{                                      /* '<S1549>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcBoostOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1254_76_67_18_Destinations[] =
{                                      /* '<S1553>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcBoostOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1254_99_67_18_Destinations[] =
{                                      /* '<S1557>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcVncEnableTuneVar,
};

static enum TOP_RcvTransNumber Translation_Model_1254_85_Destinations[] =
{                                      /* '<S1559>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcNum,
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcDen,
};

static enum TOP_RcvTransNumber Translation_Model_1254_53_67_18_Destinations[] =
{                                      /* '<S1566>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMinVncSignal,
};

static enum TOP_RcvTransNumber Translation_Model_1254_54_67_18_Destinations[] =
{                                      /* '<S1570>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntGainCalcMaxSpl,
};

static enum TOP_RcvTransNumber Translation_Model_1255_44_Destinations[] =
{                                      /* '<S1574>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntVncAppliedNum,
    ID_TOP_RcvTrans_NearAnn1Ann1NonEntVncAppliedden,
};

static enum TOP_RcvTransNumber Translation_Model_1257_276_67_18_Destinations[] =
{                                      /* '<S1581>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1MuteRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1259_139_Destinations[] =
{                                      /* '<S1583>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeTable_Idx,
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeTable_dB,
};

static enum TOP_RcvTransNumber Translation_Model_1259_192_67_18_Destinations[] =
{                                      /* '<S1590>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeRampRate,
};

static enum TOP_RcvTransNumber Translation_Model_1259_190_67_18_Destinations[] =
{                                      /* '<S1594>/S-Function' */
    ID_TOP_RcvTrans_NearAnn1Ann1VolumeRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1265_7_67_18_Destinations[] =
{                                      /* '<S1612>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncThresh,
};

static enum TOP_RcvTransNumber Translation_Model_1265_8_67_18_Destinations[] =
{                                      /* '<S1616>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncSlope,
};

static enum TOP_RcvTransNumber Translation_Model_1265_9_67_18_Destinations[] =
{                                      /* '<S1620>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMaxBoost,
};

static enum TOP_RcvTransNumber Translation_Model_1265_72_67_18_Destinations[] =
{                                      /* '<S1624>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNoiseOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1265_74_67_18_Destinations[] =
{                                      /* '<S1628>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1265_75_67_18_Destinations[] =
{                                      /* '<S1632>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcBoostOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1265_76_67_18_Destinations[] =
{                                      /* '<S1636>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcBoostOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1265_99_67_18_Destinations[] =
{                                      /* '<S1640>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcVncEnableTuneVar,
};

static enum TOP_RcvTransNumber Translation_Model_1265_85_Destinations[] =
{                                      /* '<S1642>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcNum,
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcDen,
};

static enum TOP_RcvTransNumber Translation_Model_1265_53_67_18_Destinations[] =
{                                      /* '<S1649>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMinVncSignal,
};

static enum TOP_RcvTransNumber Translation_Model_1265_54_67_18_Destinations[] =
{                                      /* '<S1653>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntGainCalcMaxSpl,
};

static enum TOP_RcvTransNumber Translation_Model_1266_44_Destinations[] =
{                                      /* '<S1657>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntVncAppliedNum,
    ID_TOP_RcvTrans_NearAnn2Ann2NonEntVncAppliedden,
};

static enum TOP_RcvTransNumber Translation_Model_1268_276_67_18_Destinations[] =
{                                      /* '<S1664>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2MuteRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1270_139_Destinations[] =
{                                      /* '<S1666>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeTable_Idx,
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeTable_dB,
};

static enum TOP_RcvTransNumber Translation_Model_1270_192_67_18_Destinations[] =
{                                      /* '<S1673>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeRampRate,
};

static enum TOP_RcvTransNumber Translation_Model_1270_190_67_18_Destinations[] =
{                                      /* '<S1677>/S-Function' */
    ID_TOP_RcvTrans_NearAnn2Ann2VolumeRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1276_7_67_18_Destinations[] =
{                                      /* '<S1695>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncThresh,
};

static enum TOP_RcvTransNumber Translation_Model_1276_8_67_18_Destinations[] =
{                                      /* '<S1699>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncSlope,
};

static enum TOP_RcvTransNumber Translation_Model_1276_9_67_18_Destinations[] =
{                                      /* '<S1703>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMaxBoost,
};

static enum TOP_RcvTransNumber Translation_Model_1276_72_67_18_Destinations[] =
{                                      /* '<S1707>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNoiseOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1276_74_67_18_Destinations[] =
{                                      /* '<S1711>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1276_75_67_18_Destinations[] =
{                                      /* '<S1715>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcBoostOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1276_76_67_18_Destinations[] =
{                                      /* '<S1719>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcBoostOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1276_99_67_18_Destinations[] =
{                                      /* '<S1723>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcVncEnableTuneVar,
};

static enum TOP_RcvTransNumber Translation_Model_1276_85_Destinations[] =
{                                      /* '<S1725>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcNum,
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcDen,
};

static enum TOP_RcvTransNumber Translation_Model_1276_53_67_18_Destinations[] =
{                                      /* '<S1732>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMinVncSignal,
};

static enum TOP_RcvTransNumber Translation_Model_1276_54_67_18_Destinations[] =
{                                      /* '<S1736>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntGainCalcMaxSpl,
};

static enum TOP_RcvTransNumber Translation_Model_1277_44_Destinations[] =
{                                      /* '<S1740>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntVncAppliedNum,
    ID_TOP_RcvTrans_NearAnn3Ann3NonEntVncAppliedden,
};

static enum TOP_RcvTransNumber Translation_Model_1279_276_67_18_Destinations[] =
{                                      /* '<S1747>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3MuteRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1281_139_Destinations[] =
{                                      /* '<S1749>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeTable_Idx,
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeTable_dB,
};

static enum TOP_RcvTransNumber Translation_Model_1281_192_67_18_Destinations[] =
{                                      /* '<S1756>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeRampRate,
};

static enum TOP_RcvTransNumber Translation_Model_1281_190_67_18_Destinations[] =
{                                      /* '<S1760>/S-Function' */
    ID_TOP_RcvTrans_NearAnn3Ann3VolumeRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1287_7_67_18_Destinations[] =
{                                      /* '<S1778>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncThresh,
};

static enum TOP_RcvTransNumber Translation_Model_1287_8_67_18_Destinations[] =
{                                      /* '<S1782>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncSlope,
};

static enum TOP_RcvTransNumber Translation_Model_1287_9_67_18_Destinations[] =
{                                      /* '<S1786>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMaxBoost,
};

static enum TOP_RcvTransNumber Translation_Model_1287_72_67_18_Destinations[] =
{                                      /* '<S1790>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNoiseOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1287_74_67_18_Destinations[] =
{                                      /* '<S1794>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1287_75_67_18_Destinations[] =
{                                      /* '<S1798>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcBoostOverRide,
};

static enum TOP_RcvTransNumber Translation_Model_1287_76_67_18_Destinations[] =
{                                      /* '<S1802>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcBoostOverRideFlag,
};

static enum TOP_RcvTransNumber Translation_Model_1287_99_67_18_Destinations[] =
{                                      /* '<S1806>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcVncEnableTuneVar,
};

static enum TOP_RcvTransNumber Translation_Model_1287_85_Destinations[] =
{                                      /* '<S1808>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcNum,
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcDen,
};

static enum TOP_RcvTransNumber Translation_Model_1287_53_67_18_Destinations[] =
{                                      /* '<S1815>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMinVncSignal,
};

static enum TOP_RcvTransNumber Translation_Model_1287_54_67_18_Destinations[] =
{                                      /* '<S1819>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntGainCalcMaxSpl,
};

static enum TOP_RcvTransNumber Translation_Model_1288_44_Destinations[] =
{                                      /* '<S1823>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntVncAppliedNum,
    ID_TOP_RcvTrans_NearAnn4Ann4NonEntVncAppliedden,
};

static enum TOP_RcvTransNumber Translation_Model_1290_276_67_18_Destinations[] =
{                                      /* '<S1830>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4MuteRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_1292_139_Destinations[] =
{                                      /* '<S1832>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeTable_Idx,
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeTable_dB,
};

static enum TOP_RcvTransNumber Translation_Model_1292_192_67_18_Destinations[] =
{                                      /* '<S1839>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeRampRate,
};

static enum TOP_RcvTransNumber Translation_Model_1292_190_67_18_Destinations[] =
{                                      /* '<S1843>/S-Function' */
    ID_TOP_RcvTrans_NearAnn4Ann4VolumeRampTime,
};

static enum TOP_RcvTransNumber Translation_Model_291_138_8_67_18_Destinations[] =
{                                      /* '<S1895>/S-Function' */
    ID_TOP_RcvTrans_TestRouterASDRouterEnableAux,
};

static enum TOP_RcvTransNumber Translation_Model_291_138_44_67_18_Destinations[]
    =
{                                      /* '<S1900>/S-Function' */
    ID_TOP_RcvTrans_TestRouterASDRouterMainSelect,
};

static enum TOP_RcvTransNumber Translation_Model_296_67_18_Destinations[] =
{                                      /* '<S1904>/S-Function' */
    ID_TOP_RcvTrans_TestRouterAuxSelect,
};

// -----------------------------------------------------
// ----- Translation object table listing all translations
static TranslationRecord_type translation_table[] =
{
    // Translation record for PreAmpMedusaTrebleDelay '<S636>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1371, 3, Translation_Model_141_1371_Sources, 1,
        Translation_Model_141_1371_Destinations
    },

    // Translation record for PreAmpMedusatailCompEQPooliirNumStages,PreAmpMedusatailCompEQpooliirCoeffs '<S766>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_345_50_36, 2,
        Translation_Model_141_345_50_36_Sources, 2,
        Translation_Model_141_345_50_36_Destinations
    },

    // Translation record for PreAmpMedusaWiggleFilter '<S771>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_346_67_18, 1,
        Translation_Model_141_346_67_18_Sources, 1,
        Translation_Model_141_346_67_18_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateBassDelay,PreAmpMedusaFullRateBassDelay,PreAmpMedusaMidrangeDelay '<S759>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2888, 2, Translation_Model_141_2888_Sources, 3,
        Translation_Model_141_2888_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerBackwardDownmixMax '<S783>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2926, 1, Translation_Model_141_2926_Sources, 1,
        Translation_Model_141_2926_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerBackwardDownmixThreshold '<S786>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2932, 1, Translation_Model_141_2932_Sources, 1,
        Translation_Model_141_2932_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDownmixWeights_CS,PreAmpMedusaFullRateMixerDownmixWeights_CS_CAE '<S789>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2939, 1, Translation_Model_141_2939_Sources, 2,
        Translation_Model_141_2939_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDownmixWeights_Left,PreAmpMedusaFullRateMixerDownmixWeights_Left_CAE '<S792>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2947, 1, Translation_Model_141_2947_Sources, 2,
        Translation_Model_141_2947_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDownmixWeights_Right,PreAmpMedusaFullRateMixerDownmixWeights_Right_CAE '<S795>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2955, 1, Translation_Model_141_2955_Sources, 2,
        Translation_Model_141_2955_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerForwardDownmixThreshold '<S798>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2962, 1, Translation_Model_141_2962_Sources, 1,
        Translation_Model_141_2962_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerForwardDownmixMax '<S801>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2968, 1, Translation_Model_141_2968_Sources, 1,
        Translation_Model_141_2968_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDetentLevel_CS,PreAmpMedusaFullRateMixerDetentLevel_CS_CAE '<S814>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3372, 1, Translation_Model_141_3372_Sources, 2,
        Translation_Model_141_3372_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDetentLevel_Left,PreAmpMedusaFullRateMixerDetentLevel_Left_CAE '<S817>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3380, 1, Translation_Model_141_3380_Sources, 2,
        Translation_Model_141_3380_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerDetentLevel_Right,PreAmpMedusaFullRateMixerDetentLevel_Right_CAE '<S820>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3388, 1, Translation_Model_141_3388_Sources, 2,
        Translation_Model_141_3388_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerInterpolation_Method '<S823>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3395, 1, Translation_Model_141_3395_Sources, 1,
        Translation_Model_141_3395_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMaxLevel_CS,PreAmpMedusaFullRateMixerMaxLevel_CS_CAE '<S826>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3402, 1, Translation_Model_141_3402_Sources, 2,
        Translation_Model_141_3402_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMaxLevel_Left,PreAmpMedusaFullRateMixerMaxLevel_Left_CAE '<S829>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3410, 1, Translation_Model_141_3410_Sources, 2,
        Translation_Model_141_3410_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMaxLevel_Right,PreAmpMedusaFullRateMixerMaxLevel_Right_CAE '<S832>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3418, 1, Translation_Model_141_3418_Sources, 2,
        Translation_Model_141_3418_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMinLevel_CS,PreAmpMedusaFullRateMixerMinLevel_CS_CAE '<S835>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3426, 1, Translation_Model_141_3426_Sources, 2,
        Translation_Model_141_3426_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMinLevel_Left,PreAmpMedusaFullRateMixerMinLevel_Left_CAE '<S838>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3434, 1, Translation_Model_141_3434_Sources, 2,
        Translation_Model_141_3434_Destinations
    },

    // Translation record for PreAmpMedusaFullRateMixerMinLevel_Right,PreAmpMedusaFullRateMixerMinLevel_Right_CAE '<S841>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3442, 1, Translation_Model_141_3442_Sources, 2,
        Translation_Model_141_3442_Destinations
    },

    // Translation record for PreAmpMedusaPremixMonoSurroundPhi,PreAmpMedusaPremixMonoSurroundCosPhi,PreAmpMedusaPremixMonoSurroundSinPhi '<S849>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3495, 1, Translation_Model_141_3495_Sources, 3,
        Translation_Model_141_3495_Destinations
    },

    // Translation record for PreAmpMedusaPremixBackwardDownmixMax '<S859>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3596, 1, Translation_Model_141_3596_Sources, 1,
        Translation_Model_141_3596_Destinations
    },

    // Translation record for PreAmpMedusaPremixBackwardDownmixThreshold '<S862>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3602, 1, Translation_Model_141_3602_Sources, 1,
        Translation_Model_141_3602_Destinations
    },

    // Translation record for PreAmpMedusaPremixDownmixWeights_CS,PreAmpMedusaPremixDownmixWeights_CS_CAE '<S865>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3609, 1, Translation_Model_141_3609_Sources, 2,
        Translation_Model_141_3609_Destinations
    },

    // Translation record for PreAmpMedusaPremixDownmixWeights_Left,PreAmpMedusaPremixDownmixWeights_Left_CAE '<S868>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3617, 1, Translation_Model_141_3617_Sources, 2,
        Translation_Model_141_3617_Destinations
    },

    // Translation record for PreAmpMedusaPremixDownmixWeights_Right,PreAmpMedusaPremixDownmixWeights_Right_CAE '<S871>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3625, 1, Translation_Model_141_3625_Sources, 2,
        Translation_Model_141_3625_Destinations
    },

    // Translation record for PreAmpMedusaPremixForwardDownmixThreshold '<S874>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3632, 1, Translation_Model_141_3632_Sources, 1,
        Translation_Model_141_3632_Destinations
    },

    // Translation record for PreAmpMedusaPremixForwardDownmixMax '<S877>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_3638, 1, Translation_Model_141_3638_Sources, 1,
        Translation_Model_141_3638_Destinations
    },

    // Translation record for PreAmpMedusaPremixDetentLevel_CS,PreAmpMedusaPremixDetentLevel_CS_CAE '<S890>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4091, 1, Translation_Model_141_4091_Sources, 2,
        Translation_Model_141_4091_Destinations
    },

    // Translation record for PreAmpMedusaPremixDetentLevel_Left,PreAmpMedusaPremixDetentLevel_Left_CAE '<S893>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4099, 1, Translation_Model_141_4099_Sources, 2,
        Translation_Model_141_4099_Destinations
    },

    // Translation record for PreAmpMedusaPremixDetentLevel_Right,PreAmpMedusaPremixDetentLevel_Right_CAE '<S896>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4107, 1, Translation_Model_141_4107_Sources, 2,
        Translation_Model_141_4107_Destinations
    },

    // Translation record for PreAmpMedusaPremixInterpolation_Method '<S899>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4114, 1, Translation_Model_141_4114_Sources, 1,
        Translation_Model_141_4114_Destinations
    },

    // Translation record for PreAmpMedusaPremixMaxLevel_CS,PreAmpMedusaPremixMaxLevel_CS_CAE '<S902>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4121, 1, Translation_Model_141_4121_Sources, 2,
        Translation_Model_141_4121_Destinations
    },

    // Translation record for PreAmpMedusaPremixMaxLevel_Left,PreAmpMedusaPremixMaxLevel_Left_CAE '<S905>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4129, 1, Translation_Model_141_4129_Sources, 2,
        Translation_Model_141_4129_Destinations
    },

    // Translation record for PreAmpMedusaPremixMaxLevel_Right,PreAmpMedusaPremixMaxLevel_Right_CAE '<S908>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4137, 1, Translation_Model_141_4137_Sources, 2,
        Translation_Model_141_4137_Destinations
    },

    // Translation record for PreAmpMedusaPremixMinLevel_CS,PreAmpMedusaPremixMinLevel_CS_CAE '<S911>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4145, 1, Translation_Model_141_4145_Sources, 2,
        Translation_Model_141_4145_Destinations
    },

    // Translation record for PreAmpMedusaPremixMinLevel_Left,PreAmpMedusaPremixMinLevel_Left_CAE '<S914>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4153, 1, Translation_Model_141_4153_Sources, 2,
        Translation_Model_141_4153_Destinations
    },

    // Translation record for PreAmpMedusaPremixMinLevel_Right,PreAmpMedusaPremixMinLevel_Right_CAE '<S917>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4161, 1, Translation_Model_141_4161_Sources, 2,
        Translation_Model_141_4161_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsBackwardDownmixMax '<S929>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_182, 1,
        Translation_Model_141_983_182_Sources, 1,
        Translation_Model_141_983_182_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold '<S932>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_188, 1,
        Translation_Model_141_983_188_Sources, 1,
        Translation_Model_141_983_188_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsDownmixWeights '<S935>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_194, 1,
        Translation_Model_141_983_194_Sources, 1,
        Translation_Model_141_983_194_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsForwardDownmixThreshold '<S938>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_200, 1,
        Translation_Model_141_983_200_Sources, 1,
        Translation_Model_141_983_200_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsForwardDownmixMax '<S941>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_206, 1,
        Translation_Model_141_983_206_Sources, 1,
        Translation_Model_141_983_206_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsDetentLevel '<S948>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_287, 1,
        Translation_Model_141_983_287_Sources, 1,
        Translation_Model_141_983_287_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsInterpolation_Method '<S951>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_293, 1,
        Translation_Model_141_983_293_Sources, 1,
        Translation_Model_141_983_293_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsMaxLevel '<S954>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_299, 1,
        Translation_Model_141_983_299_Sources, 1,
        Translation_Model_141_983_299_Destinations
    },

    // Translation record for PreAmpMedusaVLSDrvGainsMinLevel '<S957>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_983_305, 1,
        Translation_Model_141_983_305_Sources, 1,
        Translation_Model_141_983_305_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsBackwardDownmixMax '<S967>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_182, 1,
        Translation_Model_141_984_182_Sources, 1,
        Translation_Model_141_984_182_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold '<S970>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_188, 1,
        Translation_Model_141_984_188_Sources, 1,
        Translation_Model_141_984_188_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsDownmixWeights '<S973>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_194, 1,
        Translation_Model_141_984_194_Sources, 1,
        Translation_Model_141_984_194_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsForwardDownmixThreshold '<S976>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_200, 1,
        Translation_Model_141_984_200_Sources, 1,
        Translation_Model_141_984_200_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsForwardDownmixMax '<S979>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_206, 1,
        Translation_Model_141_984_206_Sources, 1,
        Translation_Model_141_984_206_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsDetentLevel '<S986>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_287, 1,
        Translation_Model_141_984_287_Sources, 1,
        Translation_Model_141_984_287_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsInterpolation_Method '<S989>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_293, 1,
        Translation_Model_141_984_293_Sources, 1,
        Translation_Model_141_984_293_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsMaxLevel '<S992>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_299, 1,
        Translation_Model_141_984_299_Sources, 1,
        Translation_Model_141_984_299_Destinations
    },

    // Translation record for PreAmpMedusaVLSPaxGainsMinLevel '<S995>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_984_305, 1,
        Translation_Model_141_984_305_Sources, 1,
        Translation_Model_141_984_305_Destinations
    },

    // Translation record for PreAmpMedusaDRHoligramPoolIirTunableConfigPooliirNumStages,PreAmpMedusaDRHoligramPoolIirTunableConfigpooliirCoeffs '<S1005>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_472_255_36, 2,
        Translation_Model_141_472_255_36_Sources, 2,
        Translation_Model_141_472_255_36_Destinations
    },

    // Translation record for PreAmpMedusaDRHoligramFIRCoeffs,PreAmpMedusaDRHoligramFilterLengths,PreAmpMedusaDRHoligramPaddedFilterLengths '<S1008>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_472_235, 3,
        Translation_Model_141_472_235_Sources, 3,
        Translation_Model_141_472_235_Destinations
    },

    // Translation record for PreAmpMedusaDRHoligramInputMapping '<S1015>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_472_239_67_18, 1,
        Translation_Model_141_472_239_67_18_Sources, 1,
        Translation_Model_141_472_239_67_18_Destinations
    },

    // Translation record for PreAmpMedusaDRHoligramOutputMapping '<S1019>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_472_240_67_18, 1,
        Translation_Model_141_472_240_67_18_Sources, 1,
        Translation_Model_141_472_240_67_18_Destinations
    },

    // Translation record for PreAmpMedusaFRHoligramIirConfigPooliirNumStages,PreAmpMedusaFRHoligramIirConfigpooliirCoeffs '<S1023>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_473_12_36, 2,
        Translation_Model_141_473_12_36_Sources, 2,
        Translation_Model_141_473_12_36_Destinations
    },

    // Translation record for PreAmpMedusaHeadrestCompEQFIRCoeffs,PreAmpMedusaHeadrestCompEQFilterLengths,PreAmpMedusaHeadrestCompEQPaddedFilterLengths '<S1027>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_595_191, 3,
        Translation_Model_141_595_191_Sources, 3,
        Translation_Model_141_595_191_Destinations
    },

    // Translation record for PreAmpMedusaHeadrestCompEQIirConfigPooliirNumStages,PreAmpMedusaHeadrestCompEQIirConfigpooliirCoeffs '<S1030>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_595_238_36, 2,
        Translation_Model_141_595_238_36_Sources, 2,
        Translation_Model_141_595_238_36_Destinations
    },

    // Translation record for PreAmpMedusaDRSpeakerDelay,PreAmpMedusaFRSpeakerDelay '<S1036>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_4193, 4, Translation_Model_141_4193_Sources, 2,
        Translation_Model_141_4193_Destinations
    },

    // Translation record for PreAmpMedusaRoutingMap '<S1044>/S-Function'
    {
        0, &
        FuncTranslation_Model_150_574_67_18, 1,
        Translation_Model_150_574_67_18_Sources, 1,
        Translation_Model_150_574_67_18_Destinations
    },

    // Translation record for PreAmpVLSXtalkCancellationIIRPooliirNumStages,PreAmpVLSXtalkCancellationIIRpooliirCoeffs '<S1165>/S-Function'
    {
        0, &
        FuncTranslation_Model_232_8_34_50_36, 2,
        Translation_Model_232_8_34_50_36_Sources, 2,
        Translation_Model_232_8_34_50_36_Destinations
    },

    // Translation record for PreAmpVLSXtalkCancellationDelay '<S1170>/S-Function'
    {
        0, &
        FuncTranslation_Model_232_8_36_67_18, 1,
        Translation_Model_232_8_36_67_18_Sources, 1,
        Translation_Model_232_8_36_67_18_Destinations
    },

    // Translation record for PreAmpVLSGenerationDrvFIRCoeffs,PreAmpVLSGenerationDrvPaddedFilterLengths '<S1172>/S-Function'
    {
        0, &
        FuncTranslation_Model_232_11_191, 2,
        Translation_Model_232_11_191_Sources, 2,
        Translation_Model_232_11_191_Destinations
    },

    // Translation record for PreAmpVLSGenerationPaxFIRCoeffs,PreAmpVLSGenerationPaxPaddedFilterLengths '<S1175>/S-Function'
    {
        0, &
        FuncTranslation_Model_232_12_191, 2,
        Translation_Model_232_12_191_Sources, 2,
        Translation_Model_232_12_191_Destinations
    },

    // Translation record for PreAmpBassBoostCoeffs '<S1183>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_149, 1, Translation_Model_247_149_Sources, 1,
        Translation_Model_247_149_Destinations
    },

    // Translation record for PreAmpBassCutCoeffs '<S1184>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_153, 1, Translation_Model_247_153_Sources, 1,
        Translation_Model_247_153_Destinations
    },

    // Translation record for PreAmpBassBoostMaximum_dB '<S1182>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_174, 1, Translation_Model_247_174_Sources, 1,
        Translation_Model_247_174_Destinations
    },

    // Translation record for PreAmpBassCutMaximum_dB '<S1185>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_176, 1, Translation_Model_247_176_Sources, 1,
        Translation_Model_247_176_Destinations
    },

    // Translation record for PreAmpBassOffset '<S1199>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_210_67_18, 1,
        Translation_Model_247_210_67_18_Sources, 1,
        Translation_Model_247_210_67_18_Destinations
    },

    // Translation record for PreAmpBassramptime '<S1203>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_229_67_18, 1,
        Translation_Model_247_229_67_18_Sources, 1,
        Translation_Model_247_229_67_18_Destinations
    },

    // Translation record for PreAmpBassScale '<S1207>/S-Function'
    {
        0, &
        FuncTranslation_Model_247_209_67_18, 1,
        Translation_Model_247_209_67_18_Sources, 1,
        Translation_Model_247_209_67_18_Destinations
    },

    // Translation record for PreAmpMidrangeBoostCoeffs '<S1210>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_47, 2, Translation_Model_249_47_Sources, 1,
        Translation_Model_249_47_Destinations
    },

    // Translation record for PreAmpMidrangeCutCoeffs '<S1211>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_48, 2, Translation_Model_249_48_Sources, 1,
        Translation_Model_249_48_Destinations
    },

    // Translation record for PreAmpMidrangeBoostMaximum_dB '<S1209>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_46, 1, Translation_Model_249_46_Sources, 1,
        Translation_Model_249_46_Destinations
    },

    // Translation record for PreAmpMidrangeCutMaximum_dB '<S1212>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_49, 1, Translation_Model_249_49_Sources, 1,
        Translation_Model_249_49_Destinations
    },

    // Translation record for PreAmpMidrangeOffset '<S1226>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_50_67_18, 1,
        Translation_Model_249_50_67_18_Sources, 1,
        Translation_Model_249_50_67_18_Destinations
    },

    // Translation record for PreAmpMidrangeRampTime '<S1230>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_51_67_18, 1,
        Translation_Model_249_51_67_18_Sources, 1,
        Translation_Model_249_51_67_18_Destinations
    },

    // Translation record for PreAmpMidrangeScale '<S1234>/S-Function'
    {
        0, &
        FuncTranslation_Model_249_52_67_18, 1,
        Translation_Model_249_52_67_18_Sources, 1,
        Translation_Model_249_52_67_18_Destinations
    },

    // Translation record for PreAmpA '<S1241>/S-Function'
    {
        0, &
        FuncTranslation_Model_642, 1, Translation_Model_642_Sources, 1,
        Translation_Model_642_Destinations
    },

    // Translation record for PreAmpG '<S1250>/S-Function'
    {
        0, &
        FuncTranslation_Model_670_67_18, 1, Translation_Model_670_67_18_Sources,
        1, Translation_Model_670_67_18_Destinations
    },

    // Translation record for PreAmpAnnPred '<S1256>/S-Function'
    {
        0, &
        FuncTranslation_Model_712, 1, Translation_Model_712_Sources, 1,
        Translation_Model_712_Destinations
    },

    // Translation record for PreAmpLimiterattack '<S1262>/S-Function'
    {
        0, &
        FuncTranslation_Model_729, 1, Translation_Model_729_Sources, 1,
        Translation_Model_729_Destinations
    },

    // Translation record for PreAmpLimiterdecay '<S1263>/S-Function'
    {
        0, &
        FuncTranslation_Model_730, 1, Translation_Model_730_Sources, 1,
        Translation_Model_730_Destinations
    },

    // Translation record for PreAmpLimitermaxAttack '<S1264>/S-Function'
    {
        0, &
        FuncTranslation_Model_731, 1, Translation_Model_731_Sources, 1,
        Translation_Model_731_Destinations
    },

    // Translation record for PreAmpOffset '<S1268>/S-Function'
    {
        0, &
        FuncTranslation_Model_741, 1, Translation_Model_741_Sources, 1,
        Translation_Model_741_Destinations
    },

    // Translation record for PreAmpUpperThreshold '<S1271>/S-Function'
    {
        0, &
        FuncTranslation_Model_747, 1, Translation_Model_747_Sources, 1,
        Translation_Model_747_Destinations
    },

    // Translation record for PreAmpTrebleBoostCoeffs '<S1275>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_149, 1, Translation_Model_251_149_Sources, 1,
        Translation_Model_251_149_Destinations
    },

    // Translation record for PreAmpTrebleCutCoeffs '<S1276>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_153, 1, Translation_Model_251_153_Sources, 1,
        Translation_Model_251_153_Destinations
    },

    // Translation record for PreAmpTrebleBoostMaximum_dB '<S1274>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_174, 1, Translation_Model_251_174_Sources, 1,
        Translation_Model_251_174_Destinations
    },

    // Translation record for PreAmpTrebleCutMaximum_dB '<S1277>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_176, 1, Translation_Model_251_176_Sources, 1,
        Translation_Model_251_176_Destinations
    },

    // Translation record for PreAmpTrebleOffset '<S1291>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_210_67_18, 1,
        Translation_Model_251_210_67_18_Sources, 1,
        Translation_Model_251_210_67_18_Destinations
    },

    // Translation record for PreAmpTrebleramptime '<S1295>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_229_67_18, 1,
        Translation_Model_251_229_67_18_Sources, 1,
        Translation_Model_251_229_67_18_Destinations
    },

    // Translation record for PreAmpTrebleScale '<S1299>/S-Function'
    {
        0, &
        FuncTranslation_Model_251_209_67_18, 1,
        Translation_Model_251_209_67_18_Sources, 1,
        Translation_Model_251_209_67_18_Destinations
    },

    // Translation record for PostProcessLimiterattack,PostProcessLimiterk1 '<S1857>/S-Function'
    {
        0, &
        FuncTranslation_Model_1495, 2, Translation_Model_1495_Sources, 2,
        Translation_Model_1495_Destinations
    },

    // Translation record for PostProcessLimiterattack_low,PostProcessLimiterk1_low '<S1860>/S-Function'
    {
        0, &
        FuncTranslation_Model_1498, 2, Translation_Model_1498_Sources, 2,
        Translation_Model_1498_Destinations
    },

    // Translation record for PostProcessLimiterdecay '<S1858>/S-Function'
    {
        0, &
        FuncTranslation_Model_1496, 1, Translation_Model_1496_Sources, 1,
        Translation_Model_1496_Destinations
    },

    // Translation record for PostProcessLimiterdecay_low '<S1861>/S-Function'
    {
        0, &
        FuncTranslation_Model_1499, 1, Translation_Model_1499_Sources, 1,
        Translation_Model_1499_Destinations
    },

    // Translation record for PostProcessLimitermaxAttack '<S1859>/S-Function'
    {
        0, &
        FuncTranslation_Model_1497, 1, Translation_Model_1497_Sources, 1,
        Translation_Model_1497_Destinations
    },

    // Translation record for PostProcessLimitermaxAttack_low '<S1862>/S-Function'
    {
        0, &
        FuncTranslation_Model_1500, 1, Translation_Model_1500_Sources, 1,
        Translation_Model_1500_Destinations
    },

    // Translation record for PostProcessMuteRampTime '<S1874>/S-Function'
    {
        0, &
        FuncTranslation_Model_72_276_67_18, 1,
        Translation_Model_72_276_67_18_Sources, 1,
        Translation_Model_72_276_67_18_Destinations
    },

    // Translation record for PostProcessPostLimiterEqPooliirNumStages,PostProcessPostLimiterEqpooliirCoeffs '<S1877>/S-Function'
    {
        0, &
        FuncTranslation_Model_76_36, 2, Translation_Model_76_36_Sources, 2,
        Translation_Model_76_36_Destinations
    },

    // Translation record for PostProcessSoftClipperxmin,PostProcessSoftClipperxmax,PostProcessSoftClipperp2 '<S1881>/S-Function'
    {
        0, &
        FuncTranslation_Model_1527, 2, Translation_Model_1527_Sources, 3,
        Translation_Model_1527_Destinations
    },

    // Translation record for PostProcessSoftClipperxmin_low,PostProcessSoftClipperxmax_low,PostProcessSoftClipperp2_low '<S1882>/S-Function'
    {
        0, &
        FuncTranslation_Model_1528, 2, Translation_Model_1528_Sources, 3,
        Translation_Model_1528_Destinations
    },

    // Translation record for InputSelectRouterCfgOutMap '<S8>/S-Function'
    {
        0, &
        FuncTranslation_Model_397, 1, Translation_Model_397_Sources, 1,
        Translation_Model_397_Destinations
    },

    // Translation record for PreAmpMedusaBassManagerLeftMixWeights,PreAmpMedusaBassManagerRightMixWeights '<S609>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_246_96, 3,
        Translation_Model_141_246_96_Sources, 2,
        Translation_Model_141_246_96_Destinations
    },

    // Translation record for PreAmpMedusaBassManagerHpfPooliirNumStages,PreAmpMedusaBassManagerHpfpooliirCoeffs '<S613>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_246_141_36, 2,
        Translation_Model_141_246_141_36_Sources, 2,
        Translation_Model_141_246_141_36_Destinations
    },

    // Translation record for PreAmpMedusaBassManagerLpfPooliirNumStages,PreAmpMedusaBassManagerLpfpooliirCoeffs '<S617>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_246_148_36, 2,
        Translation_Model_141_246_148_36_Sources, 2,
        Translation_Model_141_246_148_36_Destinations
    },

    // Translation record for PreAmpMedusaBassManagerGainLfe2C '<S622>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_246_111_67_18, 1,
        Translation_Model_141_246_111_67_18_Sources, 1,
        Translation_Model_141_246_111_67_18_Destinations
    },

    // Translation record for PreAmpMedusaDummyTune '<S628>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1196_67_18, 1,
        Translation_Model_141_1196_67_18_Sources, 1,
        Translation_Model_141_1196_67_18_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpCoeffsXpMax,PreAmpMedusaDeciRateFdpCoeffsLokRokMaxScaleFactor,PreAmpMedusaDeciRateFdpCoeffsXpMin '<S647>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1560, 2, Translation_Model_141_1560_Sources, 3,
        Translation_Model_141_1560_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB,PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB,PreAmpMedusaDeciRateFdpCoeffsESDStepSize '<S648>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1561, 2, Translation_Model_141_1561_Sources, 3,
        Translation_Model_141_1561_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpSpumFastPsdSmoothFactor,PreAmpMedusaDeciRateFdpSpumSlowPsdSmoothFactor '<S653>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1988, 2, Translation_Model_141_1988_Sources, 2,
        Translation_Model_141_1988_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpSpumDirectPathSamplesDec '<S654>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1989, 1, Translation_Model_141_1989_Sources, 1,
        Translation_Model_141_1989_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpSpumLsSmoothFactor '<S655>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_1990, 1, Translation_Model_141_1990_Sources, 1,
        Translation_Model_141_1990_Destinations
    },

    // Translation record for PreAmpMedusaDeciRateFdpSpumOverwrite '<S664>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2031_67_18, 1,
        Translation_Model_141_2031_67_18_Sources, 1,
        Translation_Model_141_2031_67_18_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpCoeffsXpMax,PreAmpMedusaFullRateFdpCoeffsLokRokMaxScaleFactor,PreAmpMedusaFullRateFdpCoeffsXpMin '<S674>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2423, 3, Translation_Model_141_2423_Sources, 3,
        Translation_Model_141_2423_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB,PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB,PreAmpMedusaFullRateFdpCoeffsESDStepSize '<S675>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2424, 2, Translation_Model_141_2424_Sources, 3,
        Translation_Model_141_2424_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpSpumFastPsdSmoothFactor,PreAmpMedusaFullRateFdpSpumSlowPsdSmoothFactor '<S680>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2654, 2, Translation_Model_141_2654_Sources, 2,
        Translation_Model_141_2654_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpSpumDirectPathSamplesDec '<S681>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2655, 1, Translation_Model_141_2655_Sources, 1,
        Translation_Model_141_2655_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpSpumLsSmoothFactor '<S682>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2656, 1, Translation_Model_141_2656_Sources, 1,
        Translation_Model_141_2656_Destinations
    },

    // Translation record for PreAmpMedusaFullRateFdpSpumOverwrite '<S691>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2697_67_18, 1,
        Translation_Model_141_2697_67_18_Sources, 1,
        Translation_Model_141_2697_67_18_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorLevelPole,PreAmpMedusaMonoDetectorLevelGain,PreAmpMedusaMonoDetectorLSSmoothPole,PreAmpMedusaMonoDetectorLSSmoothGain,PreAmpMedusaMonoDetectorLSSmoothResetPole,PreAmpMedusaMonoDetectorLSSmoothResetGain '<S696>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2783, 3, Translation_Model_141_2783_Sources, 6,
        Translation_Model_141_2783_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorHPFNumStages,PreAmpMedusaMonoDetectorHPFCoeffs '<S700>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2787, 1, Translation_Model_141_2787_Sources, 2,
        Translation_Model_141_2787_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorThresholdZeroLevel '<S697>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2784, 1, Translation_Model_141_2784_Sources, 1,
        Translation_Model_141_2784_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorLRMatchTolerance '<S698>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2785, 1, Translation_Model_141_2785_Sources, 1,
        Translation_Model_141_2785_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorThresholdMono,PreAmpMedusaMonoDetectorThresholdStereo '<S699>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2786, 2, Translation_Model_141_2786_Sources, 2,
        Translation_Model_141_2786_Destinations
    },

    // Translation record for PreAmpMedusaMonoDetectorEnable '<S713>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2808_67_18, 1,
        Translation_Model_141_2808_67_18_Sources, 1,
        Translation_Model_141_2808_67_18_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstPSDSmoothFactor '<S717>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2849, 1, Translation_Model_141_2849_Sources, 1,
        Translation_Model_141_2849_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstDecaySmoothFactor '<S718>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2850, 1, Translation_Model_141_2850_Sources, 1,
        Translation_Model_141_2850_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstFastAttack,PreAmpMedusaSPUMDecayEstSlowAttack '<S719>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2851, 2, Translation_Model_141_2851_Sources, 2,
        Translation_Model_141_2851_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstStepIncrement,PreAmpMedusaSPUMDecayEstStepDecrement '<S720>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2852, 1, Translation_Model_141_2852_Sources, 2,
        Translation_Model_141_2852_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstDirectPathFramesFs '<S721>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2853, 1, Translation_Model_141_2853_Sources, 1,
        Translation_Model_141_2853_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstNoiseFloor '<S737>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2865_67_18, 1,
        Translation_Model_141_2865_67_18_Sources, 1,
        Translation_Model_141_2865_67_18_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstOnsetThreshold '<S741>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2866_67_18, 1,
        Translation_Model_141_2866_67_18_Sources, 1,
        Translation_Model_141_2866_67_18_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstSlewThreshold '<S745>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2867_67_18, 1,
        Translation_Model_141_2867_67_18_Sources, 1,
        Translation_Model_141_2867_67_18_Destinations
    },

    // Translation record for PreAmpMedusaSPUMDecayEstHPFPooliirNumStages,PreAmpMedusaSPUMDecayEstHPFpooliirCoeffs '<S749>/S-Function'
    {
        0, &
        FuncTranslation_Model_141_2878_50_36, 2,
        Translation_Model_141_2878_50_36_Sources, 2,
        Translation_Model_141_2878_50_36_Destinations
    },

    // Translation record for PreAmpFadeControlBoostDisable '<S1075>/S-Function'
    {
        0, &
        FuncTranslation_Model_449_67_18, 1, Translation_Model_449_67_18_Sources,
        1, Translation_Model_449_67_18_Destinations
    },

    // Translation record for PreAmpFadeControlEnableSilentExtreme '<S1079>/S-Function'
    {
        0, &
        FuncTranslation_Model_450_67_18, 1, Translation_Model_450_67_18_Sources,
        1, Translation_Model_450_67_18_Destinations
    },

    // Translation record for PreAmpFadeControlTableDb,PreAmpFadeControlTableIdx '<S1082>/S-Function'
    {
        0, &
        FuncTranslation_Model_455, 1, Translation_Model_455_Sources, 2,
        Translation_Model_455_Destinations
    },

    // Translation record for PreAmpFadeControloffset '<S1086>/S-Function'
    {
        0, &
        FuncTranslation_Model_459_67_18, 1, Translation_Model_459_67_18_Sources,
        1, Translation_Model_459_67_18_Destinations
    },

    // Translation record for PreAmpFadeControlRampTime '<S1090>/S-Function'
    {
        0, &
        FuncTranslation_Model_460_67_18, 1, Translation_Model_460_67_18_Sources,
        1, Translation_Model_460_67_18_Destinations
    },

    // Translation record for PreAmpFadeRamperDRChannelToRamperMap '<S1096>/S-Function'
    {
        0, &
        FuncTranslation_Model_175_136_99, 1,
        Translation_Model_175_136_99_Sources, 1,
        Translation_Model_175_136_99_Destinations
    },

    // Translation record for PreAmpFadeRamperDRTOPFilterCoefficients '<S1095>/S-Function'
    {
        0, &
        FuncTranslation_Model_175_136_98, 1,
        Translation_Model_175_136_98_Sources, 1,
        Translation_Model_175_136_98_Destinations
    },

    // Translation record for PreAmpFadeRamperFRChannelToRamperMap '<S1103>/S-Function'
    {
        0, &
        FuncTranslation_Model_176_136_99, 1,
        Translation_Model_176_136_99_Sources, 1,
        Translation_Model_176_136_99_Destinations
    },

    // Translation record for PreAmpFadeRamperFRTOPFilterCoefficients '<S1102>/S-Function'
    {
        0, &
        FuncTranslation_Model_176_136_98, 1,
        Translation_Model_176_136_98_Sources, 1,
        Translation_Model_176_136_98_Destinations
    },

    // Translation record for PreAmpMuteControlRampTime '<S1110>/S-Function'
    {
        0, &
        FuncTranslation_Model_489_67_18, 1, Translation_Model_489_67_18_Sources,
        1, Translation_Model_489_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyDRChannelToRamperMap '<S1113>/S-Function'
    {
        0, &
        FuncTranslation_Model_533, 1, Translation_Model_533_Sources, 1,
        Translation_Model_533_Destinations
    },

    // Translation record for PreAmpSleepingBeautyDROffset '<S1122>/S-Function'
    {
        0, &
        FuncTranslation_Model_538_67_18, 1, Translation_Model_538_67_18_Sources,
        1, Translation_Model_538_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyDRRampTime '<S1126>/S-Function'
    {
        0, &
        FuncTranslation_Model_539_67_18, 1, Translation_Model_539_67_18_Sources,
        1, Translation_Model_539_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyDRMutesBass '<S1130>/S-Function'
    {
        0, &
        FuncTranslation_Model_540_67_18, 1, Translation_Model_540_67_18_Sources,
        1, Translation_Model_540_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyDRTableDb,PreAmpSleepingBeautyDRTableIdx '<S1132>/S-Function'
    {
        0, &
        FuncTranslation_Model_545, 1, Translation_Model_545_Sources, 2,
        Translation_Model_545_Destinations
    },

    // Translation record for PreAmpSleepingBeautyFRChannelToRamperMap '<S1136>/S-Function'
    {
        0, &
        FuncTranslation_Model_596, 1, Translation_Model_596_Sources, 1,
        Translation_Model_596_Destinations
    },

    // Translation record for PreAmpSleepingBeautyFROffset '<S1145>/S-Function'
    {
        0, &
        FuncTranslation_Model_601_67_18, 1, Translation_Model_601_67_18_Sources,
        1, Translation_Model_601_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyFRRampTime '<S1149>/S-Function'
    {
        0, &
        FuncTranslation_Model_602_67_18, 1, Translation_Model_602_67_18_Sources,
        1, Translation_Model_602_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyFRMutesBass '<S1153>/S-Function'
    {
        0, &
        FuncTranslation_Model_603_67_18, 1, Translation_Model_603_67_18_Sources,
        1, Translation_Model_603_67_18_Destinations
    },

    // Translation record for PreAmpSleepingBeautyFRTableDb,PreAmpSleepingBeautyFRTableIdx '<S1155>/S-Function'
    {
        0, &
        FuncTranslation_Model_608, 1, Translation_Model_608_Sources, 2,
        Translation_Model_608_Destinations
    },

    // Translation record for PreAmpAudiopilotTwoDowngrade '<S26>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_21_67_18, 1,
        Translation_Model_117_21_67_18_Sources, 1,
        Translation_Model_117_21_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHvacTable '<S30>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_1781, 1, Translation_Model_117_1781_Sources, 1,
        Translation_Model_117_1781_Destinations
    },

    // Translation record for PreAmpAudiopilotAntiZipperRampLpfNumerator,PreAmpAudiopilotAntiZipperRampLpfDenominator '<S38>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_43_332, 1,
        Translation_Model_117_43_332_Sources, 2,
        Translation_Model_117_43_332_Destinations
    },

    // Translation record for PreAmpAudiopilotBassBpfNumerator,PreAmpAudiopilotBassBpfDenominator '<S40>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_43_351, 2,
        Translation_Model_117_43_351_Sources, 2,
        Translation_Model_117_43_351_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeLpfNumerator,PreAmpAudiopilotMidrangeLpfDenominator '<S44>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_43_340, 1,
        Translation_Model_117_43_340_Sources, 2,
        Translation_Model_117_43_340_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeLpfAlignDelaySamples '<S48>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_43_403, 1,
        Translation_Model_117_43_403_Sources, 1,
        Translation_Model_117_43_403_Destinations
    },

    // Translation record for PreAmpAudiopilotBassSlope0Dbperdb '<S68>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_721, 2,
        Translation_Model_117_44_721_Sources, 1,
        Translation_Model_117_44_721_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeSlope0Dbperdb '<S69>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_722, 2,
        Translation_Model_117_44_722_Sources, 1,
        Translation_Model_117_44_722_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleSlope0Dbperdb '<S70>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_723, 2,
        Translation_Model_117_44_723_Sources, 1,
        Translation_Model_117_44_723_Destinations
    },

    // Translation record for PreAmpAudiopilotBassSlope1Dbperdb '<S73>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_894, 2,
        Translation_Model_117_44_894_Sources, 1,
        Translation_Model_117_44_894_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeSlope1Dbperdb '<S72>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_736, 2,
        Translation_Model_117_44_736_Sources, 1,
        Translation_Model_117_44_736_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleSlope1Dbperdb '<S71>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_895, 2,
        Translation_Model_117_44_895_Sources, 1,
        Translation_Model_117_44_895_Destinations
    },

    // Translation record for PreAmpAudiopilotBassThresh0Db '<S84>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_469_67_18, 1,
        Translation_Model_117_44_469_67_18_Sources, 1,
        Translation_Model_117_44_469_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotBassThresh1Db '<S88>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_470_67_18, 1,
        Translation_Model_117_44_470_67_18_Sources, 1,
        Translation_Model_117_44_470_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseHighBoundDbspl '<S92>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_332_67_18, 1,
        Translation_Model_117_44_332_67_18_Sources, 1,
        Translation_Model_117_44_332_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseLowBoundDbspl '<S96>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_333_67_18, 1,
        Translation_Model_117_44_333_67_18_Sources, 1,
        Translation_Model_117_44_333_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseHighBoundDbspl '<S100>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_334_67_18, 1,
        Translation_Model_117_44_334_67_18_Sources, 1,
        Translation_Model_117_44_334_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseLowBoundDbspl '<S104>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_335_67_18, 1,
        Translation_Model_117_44_335_67_18_Sources, 1,
        Translation_Model_117_44_335_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeThresh0Db '<S108>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_341_67_18, 1,
        Translation_Model_117_44_341_67_18_Sources, 1,
        Translation_Model_117_44_341_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeThresh1Db '<S112>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_342_67_18, 1,
        Translation_Model_117_44_342_67_18_Sources, 1,
        Translation_Model_117_44_342_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleThresh0Db '<S116>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_484_67_18, 1,
        Translation_Model_117_44_484_67_18_Sources, 1,
        Translation_Model_117_44_484_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleThresh1Db '<S120>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_485_67_18, 1,
        Translation_Model_117_44_485_67_18_Sources, 1,
        Translation_Model_117_44_485_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotBassDownwardThreshDbspl '<S136>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_315_67_18, 1,
        Translation_Model_117_44_315_67_18_Sources, 1,
        Translation_Model_117_44_315_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotBassMaxAudiopilotBoostDb '<S140>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_316_67_18, 1,
        Translation_Model_117_44_316_67_18_Sources, 1,
        Translation_Model_117_44_316_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotBassMaxDyneqBoostDb '<S144>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_317_67_18, 1,
        Translation_Model_117_44_317_67_18_Sources, 1,
        Translation_Model_117_44_317_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotBassMaxTotalBoostDb '<S148>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_318_67_18, 1,
        Translation_Model_117_44_318_67_18_Sources, 1,
        Translation_Model_117_44_318_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb '<S153>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_666, 2,
        Translation_Model_117_44_666_Sources, 1,
        Translation_Model_117_44_666_Destinations
    },

    // Translation record for PreAmpAudiopilotBassDownwardSlopeDbPerDb '<S152>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_645, 2,
        Translation_Model_117_44_645_Sources, 1,
        Translation_Model_117_44_645_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleDownwardSlopeDbPerDb '<S154>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_672, 2,
        Translation_Model_117_44_672_Sources, 1,
        Translation_Model_117_44_672_Destinations
    },

    // Translation record for PreAmpAudiopilotDyneqBassThreshDbspl '<S161>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_325_67_18, 1,
        Translation_Model_117_44_325_67_18_Sources, 1,
        Translation_Model_117_44_325_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotDyneqBassSlopeDbPerDb '<S164>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_633, 2,
        Translation_Model_117_44_633_Sources, 1,
        Translation_Model_117_44_633_Destinations
    },

    // Translation record for PreAmpAudiopilotMinSignalLevelDbspl '<S169>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_343_67_18, 1,
        Translation_Model_117_44_343_67_18_Sources, 1,
        Translation_Model_117_44_343_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeDownwardThreshDbspl '<S173>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_337_67_18, 1,
        Translation_Model_117_44_337_67_18_Sources, 1,
        Translation_Model_117_44_337_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotMidrangeMaxTotalBoostDb '<S177>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_338_67_18, 1,
        Translation_Model_117_44_338_67_18_Sources, 1,
        Translation_Model_117_44_338_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleDownwardThreshDbspl '<S181>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_913_67_18, 1,
        Translation_Model_117_44_913_67_18_Sources, 1,
        Translation_Model_117_44_913_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotTrebleMaxTotalBoostDb '<S185>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_346_67_18, 1,
        Translation_Model_117_44_346_67_18_Sources, 1,
        Translation_Model_117_44_346_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotEnableRampCoef '<S188>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_44_328, 1,
        Translation_Model_117_44_328_Sources, 1,
        Translation_Model_117_44_328_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseRefPowerMin '<S200>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1944, 1,
        Translation_Model_117_516_1944_Sources, 1,
        Translation_Model_117_516_1944_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor '<S214>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1707_67_18, 1,
        Translation_Model_117_516_1707_67_18_Sources, 1,
        Translation_Model_117_516_1707_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin '<S218>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1708_67_18, 1,
        Translation_Model_117_516_1708_67_18_Sources, 1,
        Translation_Model_117_516_1708_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta '<S224>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1732_67_18, 1,
        Translation_Model_117_516_1732_67_18_Sources, 1,
        Translation_Model_117_516_1732_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin '<S228>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1733_67_18, 1,
        Translation_Model_117_516_1733_67_18_Sources, 1,
        Translation_Model_117_516_1733_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex '<S238>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1751_67_18, 1,
        Translation_Model_117_516_1751_67_18_Sources, 1,
        Translation_Model_117_516_1751_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex '<S242>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1752_67_18, 1,
        Translation_Model_117_516_1752_67_18_Sources, 1,
        Translation_Model_117_516_1752_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh '<S246>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1753_67_18, 1,
        Translation_Model_117_516_1753_67_18_Sources, 1,
        Translation_Model_117_516_1753_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef '<S250>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1755_67_18, 1,
        Translation_Model_117_516_1755_67_18_Sources, 1,
        Translation_Model_117_516_1755_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain '<S254>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1754_67_18, 1,
        Translation_Model_117_516_1754_67_18_Sources, 1,
        Translation_Model_117_516_1754_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionSubWinLenSamples '<S257>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1758, 1,
        Translation_Model_117_516_1758_Sources, 1,
        Translation_Model_117_516_1758_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef '<S262>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1774_67_18, 1,
        Translation_Model_117_516_1774_67_18_Sources, 1,
        Translation_Model_117_516_1774_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseSlewAttackDbPerSample '<S267>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1789, 1,
        Translation_Model_117_516_1789_Sources, 1,
        Translation_Model_117_516_1789_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseSlewDecayDbPerSample '<S270>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1795, 1,
        Translation_Model_117_516_1795_Sources, 1,
        Translation_Model_117_516_1795_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseSlewThresholdDb '<S275>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1804_67_18, 1,
        Translation_Model_117_516_1804_67_18_Sources, 1,
        Translation_Model_117_516_1804_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseOffsetDb '<S279>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1778_67_18, 1,
        Translation_Model_117_516_1778_67_18_Sources, 1,
        Translation_Model_117_516_1778_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoisePreprocessAntiAliasPooliirNumStages,PreAmpAudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs '<S285>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1849_50_36, 2,
        Translation_Model_117_516_1849_50_36_Sources, 2,
        Translation_Model_117_516_1849_50_36_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages,PreAmpAudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs '<S290>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_1847_50_36, 2,
        Translation_Model_117_516_1847_50_36_Sources, 2,
        Translation_Model_117_516_1847_50_36_Destinations
    },

    // Translation record for PreAmpAudiopilotHfNoiseRefLatencySamples '<S294>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_516_957, 1,
        Translation_Model_117_516_957_Sources, 1,
        Translation_Model_117_516_957_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseEnergyLpfCoef '<S305>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_435, 1,
        Translation_Model_117_517_435_Sources, 1,
        Translation_Model_117_517_435_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionGamma0 '<S314>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_422, 1,
        Translation_Model_117_517_422_Sources, 1,
        Translation_Model_117_517_422_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef '<S317>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_415, 1,
        Translation_Model_117_517_415_Sources, 1,
        Translation_Model_117_517_415_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale '<S321>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_330_67_18, 1,
        Translation_Model_117_517_330_67_18_Sources, 1,
        Translation_Model_117_517_330_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale '<S325>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_331_67_18, 1,
        Translation_Model_117_517_331_67_18_Sources, 1,
        Translation_Model_117_517_331_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale '<S329>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_332_67_18, 1,
        Translation_Model_117_517_332_67_18_Sources, 1,
        Translation_Model_117_517_332_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin '<S333>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_429_67_18, 1,
        Translation_Model_117_517_429_67_18_Sources, 1,
        Translation_Model_117_517_429_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseMicPooliirNumStages,PreAmpAudiopilotLfNoiseMicpooliirCoeffs '<S339>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_515_50_36, 2,
        Translation_Model_117_517_515_50_36_Sources, 2,
        Translation_Model_117_517_515_50_36_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseRefPooliirNumStages,PreAmpAudiopilotLfNoiseRefpooliirCoeffs '<S344>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_516_50_36, 2,
        Translation_Model_117_517_516_50_36_Sources, 2,
        Translation_Model_117_517_516_50_36_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseOffsetDb '<S349>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_459_67_18, 1,
        Translation_Model_117_517_459_67_18_Sources, 1,
        Translation_Model_117_517_459_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseRefLatencySamples '<S352>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_351, 1,
        Translation_Model_117_517_351_Sources, 1,
        Translation_Model_117_517_351_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSlewAttackDbPerSample '<S361>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_388, 1,
        Translation_Model_117_517_388_Sources, 1,
        Translation_Model_117_517_388_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSlewDecayDbPerSample '<S364>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_397, 1,
        Translation_Model_117_517_397_Sources, 1,
        Translation_Model_117_517_397_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSlewSlowDbPerSample '<S367>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_404, 1,
        Translation_Model_117_517_404_Sources, 1,
        Translation_Model_117_517_404_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSlewThresholdDb '<S372>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_270_67_18, 1,
        Translation_Model_117_517_270_67_18_Sources, 1,
        Translation_Model_117_517_270_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSpeedBoundsAxis '<S380>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_572_67_18, 1,
        Translation_Model_117_517_572_67_18_Sources, 1,
        Translation_Model_117_517_572_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl '<S384>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_573_67_18, 1,
        Translation_Model_117_517_573_67_18_Sources, 1,
        Translation_Model_117_517_573_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSpeedBoundsMinDbspl,PreAmpAudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl '<S386>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_577, 1,
        Translation_Model_117_517_577_Sources, 2,
        Translation_Model_117_517_577_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSpeedBoundsOn '<S391>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_582_67_18, 1,
        Translation_Model_117_517_582_67_18_Sources, 1,
        Translation_Model_117_517_582_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLfNoiseSysMaxDbspl '<S395>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_517_553_67_18, 1,
        Translation_Model_117_517_553_67_18_Sources, 1,
        Translation_Model_117_517_553_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateFlagHoldTimeSamples '<S409>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2074, 1, Translation_Model_117_2074_Sources, 1,
        Translation_Model_117_2074_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl '<S414>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2078_67_18, 1,
        Translation_Model_117_2078_67_18_Sources, 1,
        Translation_Model_117_2078_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl '<S418>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2079_67_18, 1,
        Translation_Model_117_2079_67_18_Sources, 1,
        Translation_Model_117_2079_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodSamples '<S420>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2082, 1, Translation_Model_117_2082_Sources, 1,
        Translation_Model_117_2082_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb '<S425>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2086_67_18, 1,
        Translation_Model_117_2086_67_18_Sources, 1,
        Translation_Model_117_2086_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph '<S429>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2087_67_18, 1,
        Translation_Model_117_2087_67_18_Sources, 1,
        Translation_Model_117_2087_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioEnergyLpfCoef '<S432>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2093, 1, Translation_Model_117_2093_Sources, 1,
        Translation_Model_117_2093_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioHighBoundDb '<S436>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2099_67_18, 1,
        Translation_Model_117_2099_67_18_Sources, 1,
        Translation_Model_117_2099_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioLowBoundDb '<S440>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2100_67_18, 1,
        Translation_Model_117_2100_67_18_Sources, 1,
        Translation_Model_117_2100_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioSlewAttackDbPerSample '<S445>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2115, 1, Translation_Model_117_2115_Sources, 1,
        Translation_Model_117_2115_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioSlewDecayDbPerSample '<S448>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2121, 1, Translation_Model_117_2121_Sources, 1,
        Translation_Model_117_2121_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioSlewThresholdDb '<S453>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2125_67_18, 1,
        Translation_Model_117_2125_67_18_Sources, 1,
        Translation_Model_117_2125_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioImpulseRejectionGamma0 '<S460>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2149, 1, Translation_Model_117_2149_Sources, 1,
        Translation_Model_117_2149_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef '<S463>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2155, 1, Translation_Model_117_2155_Sources, 1,
        Translation_Model_117_2155_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale '<S467>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2158_67_18, 1,
        Translation_Model_117_2158_67_18_Sources, 1,
        Translation_Model_117_2158_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale '<S471>/S-Function'
    {
        0, &
        FuncTranslation_Model_117_2159_67_18, 1,
        Translation_Model_117_2159_67_18_Sources, 1,
        Translation_Model_117_2159_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectFastDecayDbPerSample '<S483>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_196, 1, Translation_Model_120_196_Sources, 1,
        Translation_Model_120_196_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectHoldMarginDb '<S487>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_446, 1, Translation_Model_120_446_Sources, 1,
        Translation_Model_120_446_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectHoldTimeSamples '<S489>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_203, 1, Translation_Model_120_203_Sources, 1,
        Translation_Model_120_203_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectMaxVolumeDb '<S494>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_122_67_18, 1,
        Translation_Model_120_122_67_18_Sources, 1,
        Translation_Model_120_122_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectMinVolumeDb '<S498>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_123_67_18, 1,
        Translation_Model_120_123_67_18_Sources, 1,
        Translation_Model_120_123_67_18_Destinations
    },

    // Translation record for PreAmpAudiopilotLevelDetectSlowDecayDbPerSample '<S500>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_189, 1, Translation_Model_120_189_Sources, 1,
        Translation_Model_120_189_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectFastDecayDbPerSample '<S510>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_264, 1, Translation_Model_120_264_Sources, 1,
        Translation_Model_120_264_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectHoldMarginDb '<S514>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_514, 1, Translation_Model_120_514_Sources, 1,
        Translation_Model_120_514_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectHoldTimeSamples '<S516>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_257, 1, Translation_Model_120_257_Sources, 1,
        Translation_Model_120_257_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectMaxVolumeDb '<S521>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_218_67_18, 1,
        Translation_Model_120_218_67_18_Sources, 1,
        Translation_Model_120_218_67_18_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectMinVolumeDb '<S525>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_219_67_18, 1,
        Translation_Model_120_219_67_18_Sources, 1,
        Translation_Model_120_219_67_18_Destinations
    },

    // Translation record for PreAmpDyneqLevelDetectSlowDecayDbPerSample '<S527>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_250, 1, Translation_Model_120_250_Sources, 1,
        Translation_Model_120_250_Destinations
    },

    // Translation record for PreAmpLevelDetectMusicDelaySamples '<S534>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_439, 1, Translation_Model_120_439_Sources, 1,
        Translation_Model_120_439_Destinations
    },

    // Translation record for PreAmpLevelDetectPreemphasisPooliirNumStages,PreAmpLevelDetectPreemphasispooliirCoeffs '<S538>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_422_50_36, 2,
        Translation_Model_120_422_50_36_Sources, 2,
        Translation_Model_120_422_50_36_Destinations
    },

    // Translation record for PreAmpLevelDetectSysMaxDbspl '<S543>/S-Function'
    {
        0, &
        FuncTranslation_Model_120_319_67_18, 1,
        Translation_Model_120_319_67_18_Sources, 1,
        Translation_Model_120_319_67_18_Destinations
    },

    // Translation record for PreAmpVolumeCfgTable_Idx,PreAmpVolumeCfgTable_dB '<S547>/S-Function'
    {
        0, &
        FuncTranslation_Model_123_280, 1, Translation_Model_123_280_Sources, 2,
        Translation_Model_123_280_Destinations
    },

    // Translation record for PreAmpVolumeCfgmaxgain '<S553>/S-Function'
    {
        0, &
        FuncTranslation_Model_123_281_67_18, 1,
        Translation_Model_123_281_67_18_Sources, 1,
        Translation_Model_123_281_67_18_Destinations
    },

    // Translation record for PreAmpVolumeCfgRampTime '<S557>/S-Function'
    {
        0, &
        FuncTranslation_Model_123_256_67_18, 1,
        Translation_Model_123_256_67_18_Sources, 1,
        Translation_Model_123_256_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgChanRampMap '<S566>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_79, 1, Translation_Model_135_79_Sources, 1,
        Translation_Model_135_79_Destinations
    },

    // Translation record for PreAmpBalance_CfgBoostDisable '<S577>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_81_67_18, 1,
        Translation_Model_135_81_67_18_Sources, 1,
        Translation_Model_135_81_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgOffset '<S581>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_83_67_18, 1,
        Translation_Model_135_83_67_18_Sources, 1,
        Translation_Model_135_83_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgRampTime '<S585>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_84_67_18, 1,
        Translation_Model_135_84_67_18_Sources, 1,
        Translation_Model_135_84_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgSleepingBeautyMutesBass '<S589>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_143_67_18, 1,
        Translation_Model_135_143_67_18_Sources, 1,
        Translation_Model_135_143_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgEnableSilentExtreme '<S593>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_85_67_18, 1,
        Translation_Model_135_85_67_18_Sources, 1,
        Translation_Model_135_85_67_18_Destinations
    },

    // Translation record for PreAmpBalance_CfgTableDb,PreAmpBalance_CfgTableIdx '<S596>/S-Function'
    {
        0, &
        FuncTranslation_Model_135_90, 1, Translation_Model_135_90_Sources, 2,
        Translation_Model_135_90_Destinations
    },

    // Translation record for PreAmpNearWiggleCoeffs '<S1053>/S-Function'
    {
        0, &
        FuncTranslation_Model_420_67_18, 1, Translation_Model_420_67_18_Sources,
        1, Translation_Model_420_67_18_Destinations
    },

    // Translation record for PreAmpNearDelay '<S1057>/S-Function'
    {
        0, &
        FuncTranslation_Model_421_67_18, 1, Translation_Model_421_67_18_Sources,
        1, Translation_Model_421_67_18_Destinations
    },

    // Translation record for NearDr_PooliirPooliirNumStages,NearDr_PooliirpooliirCoeffs '<S1314>/S-Function'
    {
        0, &
        FuncTranslation_Model_874_36, 2, Translation_Model_874_36_Sources, 2,
        Translation_Model_874_36_Destinations
    },

    // Translation record for NearDr_EqDelays '<S1318>/S-Function'
    {
        0, &
        FuncTranslation_Model_863, 7, Translation_Model_863_Sources, 1,
        Translation_Model_863_Destinations
    },

    // Translation record for NearDr_PoolIirTunablePooliirNumStages,NearDr_PoolIirTunablepooliirCoeffs '<S1324>/S-Function'
    {
        0, &
        FuncTranslation_Model_915_36, 2, Translation_Model_915_36_Sources, 2,
        Translation_Model_915_36_Destinations
    },

    // Translation record for NearDr_eqdelays '<S1328>/S-Function'
    {
        0, &
        FuncTranslation_Model_903, 8, Translation_Model_903_Sources, 1,
        Translation_Model_903_Destinations
    },

    // Translation record for NearDr_RouterOutMap '<S1332>/S-Function'
    {
        0, &
        FuncTranslation_Model_926, 1, Translation_Model_926_Sources, 1,
        Translation_Model_926_Destinations
    },

    // Translation record for NearDr_mix '<S1340>/S-Function'
    {
        0, &
        FuncTranslation_Model_1026, 35, Translation_Model_1026_Sources, 1,
        Translation_Model_1026_Destinations
    },

    // Translation record for NearFr_PooliirPooliirNumStages,NearFr_PooliirpooliirCoeffs '<S1351>/S-Function'
    {
        0, &
        FuncTranslation_Model_1063_36, 2, Translation_Model_1063_36_Sources, 2,
        Translation_Model_1063_36_Destinations
    },

    // Translation record for NearFr_EqDelays '<S1355>/S-Function'
    {
        0, &
        FuncTranslation_Model_1052, 7, Translation_Model_1052_Sources, 1,
        Translation_Model_1052_Destinations
    },

    // Translation record for NearFr_PoolIirTunablePooliirNumStages,NearFr_PoolIirTunablepooliirCoeffs '<S1361>/S-Function'
    {
        0, &
        FuncTranslation_Model_1104_36, 2, Translation_Model_1104_36_Sources, 2,
        Translation_Model_1104_36_Destinations
    },

    // Translation record for NearFr_eqdelays '<S1365>/S-Function'
    {
        0, &
        FuncTranslation_Model_1092, 8, Translation_Model_1092_Sources, 1,
        Translation_Model_1092_Destinations
    },

    // Translation record for NearFr_RouterOutMap '<S1369>/S-Function'
    {
        0, &
        FuncTranslation_Model_1115, 1, Translation_Model_1115_Sources, 1,
        Translation_Model_1115_Destinations
    },

    // Translation record for NearFr_mix '<S1377>/S-Function'
    {
        0, &
        FuncTranslation_Model_1215, 35, Translation_Model_1215_Sources, 1,
        Translation_Model_1215_Destinations
    },

    // Translation record for NearRampDbPerSample '<S1383>/S-Function'
    {
        0, &
        FuncTranslation_Model_831_67_18, 1, Translation_Model_831_67_18_Sources,
        1, Translation_Model_831_67_18_Destinations
    },

    // Translation record for NearNumStages,NearCoefficients '<S1386>/S-Function'
    {
        0, &
        FuncTranslation_Model_1234, 2, Translation_Model_1234_Sources, 2,
        Translation_Model_1234_Destinations
    },

    // Translation record for NearLevelDetectPreEmphasisShelfFilterPooliirNumStages,NearLevelDetectPreEmphasisShelfFilterpooliirCoeffs '<S1402>/S-Function'
    {
        0, &
        FuncTranslation_Model_1475_36, 2, Translation_Model_1475_36_Sources, 2,
        Translation_Model_1475_36_Destinations
    },

    // Translation record for NearLevelDetectSysMaxDbspl '<S1407>/S-Function'
    {
        0, &
        FuncTranslation_Model_1310_67_18, 1,
        Translation_Model_1310_67_18_Sources, 1,
        Translation_Model_1310_67_18_Destinations
    },

    // Translation record for NearAnn1LevelDetectFastDecayDbPerSample '<S1415>/S-Function'
    {
        0, &
        FuncTranslation_Model_1331, 1, Translation_Model_1331_Sources, 1,
        Translation_Model_1331_Destinations
    },

    // Translation record for NearAnn1LevelDetecthold_margin_db '<S1419>/S-Function'
    {
        0, &
        FuncTranslation_Model_1338, 1, Translation_Model_1338_Sources, 1,
        Translation_Model_1338_Destinations
    },

    // Translation record for NearAnn1LevelDetectHoldTimeSamples '<S1421>/S-Function'
    {
        0, &
        FuncTranslation_Model_1343, 1, Translation_Model_1343_Sources, 1,
        Translation_Model_1343_Destinations
    },

    // Translation record for NearAnn1LevelDetectMaxVolumeDb '<S1426>/S-Function'
    {
        0, &
        FuncTranslation_Model_1347_67_18, 1,
        Translation_Model_1347_67_18_Sources, 1,
        Translation_Model_1347_67_18_Destinations
    },

    // Translation record for NearAnn1LevelDetectMinVolumeDb '<S1430>/S-Function'
    {
        0, &
        FuncTranslation_Model_1348_67_18, 1,
        Translation_Model_1348_67_18_Sources, 1,
        Translation_Model_1348_67_18_Destinations
    },

    // Translation record for NearAnn1LevelDetectSlowDecayDbPerSample '<S1432>/S-Function'
    {
        0, &
        FuncTranslation_Model_1351, 1, Translation_Model_1351_Sources, 1,
        Translation_Model_1351_Destinations
    },

    // Translation record for NearAnn2LevelDetectFastDecayDbPerSample '<S1441>/S-Function'
    {
        0, &
        FuncTranslation_Model_1368, 1, Translation_Model_1368_Sources, 1,
        Translation_Model_1368_Destinations
    },

    // Translation record for NearAnn2LevelDetectHoldMarginDb '<S1445>/S-Function'
    {
        0, &
        FuncTranslation_Model_1375, 1, Translation_Model_1375_Sources, 1,
        Translation_Model_1375_Destinations
    },

    // Translation record for NearAnn2LevelDetectHoldTimeSamples '<S1447>/S-Function'
    {
        0, &
        FuncTranslation_Model_1380, 1, Translation_Model_1380_Sources, 1,
        Translation_Model_1380_Destinations
    },

    // Translation record for NearAnn2LevelDetectMaxVolumeDb '<S1452>/S-Function'
    {
        0, &
        FuncTranslation_Model_1384_67_18, 1,
        Translation_Model_1384_67_18_Sources, 1,
        Translation_Model_1384_67_18_Destinations
    },

    // Translation record for NearAnn2LevelDetectMinVolumeDb '<S1456>/S-Function'
    {
        0, &
        FuncTranslation_Model_1385_67_18, 1,
        Translation_Model_1385_67_18_Sources, 1,
        Translation_Model_1385_67_18_Destinations
    },

    // Translation record for NearAnn2LevelDetectSlowDecayDbPerSample '<S1458>/S-Function'
    {
        0, &
        FuncTranslation_Model_1388, 1, Translation_Model_1388_Sources, 1,
        Translation_Model_1388_Destinations
    },

    // Translation record for NearAnn3LevelDetectFastDecayDbPerSample '<S1467>/S-Function'
    {
        0, &
        FuncTranslation_Model_1405, 1, Translation_Model_1405_Sources, 1,
        Translation_Model_1405_Destinations
    },

    // Translation record for NearAnn3LevelDetectHoldMarginDb '<S1471>/S-Function'
    {
        0, &
        FuncTranslation_Model_1412, 1, Translation_Model_1412_Sources, 1,
        Translation_Model_1412_Destinations
    },

    // Translation record for NearAnn3LevelDetectHoldTimeSamples '<S1473>/S-Function'
    {
        0, &
        FuncTranslation_Model_1417, 1, Translation_Model_1417_Sources, 1,
        Translation_Model_1417_Destinations
    },

    // Translation record for NearAnn3LevelDetectMaxVolumeDb '<S1478>/S-Function'
    {
        0, &
        FuncTranslation_Model_1421_67_18, 1,
        Translation_Model_1421_67_18_Sources, 1,
        Translation_Model_1421_67_18_Destinations
    },

    // Translation record for NearAnn3LevelDetectMinVolumeDb '<S1482>/S-Function'
    {
        0, &
        FuncTranslation_Model_1422_67_18, 1,
        Translation_Model_1422_67_18_Sources, 1,
        Translation_Model_1422_67_18_Destinations
    },

    // Translation record for NearAnn3LevelDetectSlowDecayDbPerSample '<S1484>/S-Function'
    {
        0, &
        FuncTranslation_Model_1425, 1, Translation_Model_1425_Sources, 1,
        Translation_Model_1425_Destinations
    },

    // Translation record for NearAnn4LevelDetectFastDecayDbPerSample '<S1493>/S-Function'
    {
        0, &
        FuncTranslation_Model_1442, 1, Translation_Model_1442_Sources, 1,
        Translation_Model_1442_Destinations
    },

    // Translation record for NearAnn4LevelDetectHoldMarginDb '<S1497>/S-Function'
    {
        0, &
        FuncTranslation_Model_1449, 1, Translation_Model_1449_Sources, 1,
        Translation_Model_1449_Destinations
    },

    // Translation record for NearAnn4LevelDetectHoldTimeSamples '<S1499>/S-Function'
    {
        0, &
        FuncTranslation_Model_1454, 1, Translation_Model_1454_Sources, 1,
        Translation_Model_1454_Destinations
    },

    // Translation record for NearAnn4LevelDetectMaxVolumeDb '<S1504>/S-Function'
    {
        0, &
        FuncTranslation_Model_1458_67_18, 1,
        Translation_Model_1458_67_18_Sources, 1,
        Translation_Model_1458_67_18_Destinations
    },

    // Translation record for NearAnn4LevelDetectMinVolumeDb '<S1508>/S-Function'
    {
        0, &
        FuncTranslation_Model_1459_67_18, 1,
        Translation_Model_1459_67_18_Sources, 1,
        Translation_Model_1459_67_18_Destinations
    },

    // Translation record for NearAnn4LevelDetectSlowDecayDbPerSample '<S1510>/S-Function'
    {
        0, &
        FuncTranslation_Model_1462, 1, Translation_Model_1462_Sources, 1,
        Translation_Model_1462_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcVncThresh '<S1529>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_7_67_18, 1,
        Translation_Model_1254_7_67_18_Sources, 1,
        Translation_Model_1254_7_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcVncSlope '<S1533>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_8_67_18, 1,
        Translation_Model_1254_8_67_18_Sources, 1,
        Translation_Model_1254_8_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcMaxBoost '<S1537>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_9_67_18, 1,
        Translation_Model_1254_9_67_18_Sources, 1,
        Translation_Model_1254_9_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcNoiseOverRide '<S1541>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_72_67_18, 1,
        Translation_Model_1254_72_67_18_Sources, 1,
        Translation_Model_1254_72_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag '<S1545>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_74_67_18, 1,
        Translation_Model_1254_74_67_18_Sources, 1,
        Translation_Model_1254_74_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcBoostOverRide '<S1549>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_75_67_18, 1,
        Translation_Model_1254_75_67_18_Sources, 1,
        Translation_Model_1254_75_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcBoostOverRideFlag '<S1553>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_76_67_18, 1,
        Translation_Model_1254_76_67_18_Sources, 1,
        Translation_Model_1254_76_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcVncEnableTuneVar '<S1557>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_99_67_18, 1,
        Translation_Model_1254_99_67_18_Sources, 1,
        Translation_Model_1254_99_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcNum,NearAnn1Ann1NonEntGainCalcDen '<S1559>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_85, 1, Translation_Model_1254_85_Sources, 2,
        Translation_Model_1254_85_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcMinVncSignal '<S1566>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_53_67_18, 1,
        Translation_Model_1254_53_67_18_Sources, 1,
        Translation_Model_1254_53_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntGainCalcMaxSpl '<S1570>/S-Function'
    {
        0, &
        FuncTranslation_Model_1254_54_67_18, 1,
        Translation_Model_1254_54_67_18_Sources, 1,
        Translation_Model_1254_54_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1NonEntVncAppliedNum,NearAnn1Ann1NonEntVncAppliedden '<S1574>/S-Function'
    {
        0, &
        FuncTranslation_Model_1255_44, 1, Translation_Model_1255_44_Sources, 2,
        Translation_Model_1255_44_Destinations
    },

    // Translation record for NearAnn1Ann1MuteRampTime '<S1581>/S-Function'
    {
        0, &
        FuncTranslation_Model_1257_276_67_18, 1,
        Translation_Model_1257_276_67_18_Sources, 1,
        Translation_Model_1257_276_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1VolumeTable_Idx,NearAnn1Ann1VolumeTable_dB '<S1583>/S-Function'
    {
        0, &
        FuncTranslation_Model_1259_139, 1, Translation_Model_1259_139_Sources, 2,
        Translation_Model_1259_139_Destinations
    },

    // Translation record for NearAnn1Ann1VolumeRampRate '<S1590>/S-Function'
    {
        0, &
        FuncTranslation_Model_1259_192_67_18, 1,
        Translation_Model_1259_192_67_18_Sources, 1,
        Translation_Model_1259_192_67_18_Destinations
    },

    // Translation record for NearAnn1Ann1VolumeRampTime '<S1594>/S-Function'
    {
        0, &
        FuncTranslation_Model_1259_190_67_18, 1,
        Translation_Model_1259_190_67_18_Sources, 1,
        Translation_Model_1259_190_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcVncThresh '<S1612>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_7_67_18, 1,
        Translation_Model_1265_7_67_18_Sources, 1,
        Translation_Model_1265_7_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcVncSlope '<S1616>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_8_67_18, 1,
        Translation_Model_1265_8_67_18_Sources, 1,
        Translation_Model_1265_8_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcMaxBoost '<S1620>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_9_67_18, 1,
        Translation_Model_1265_9_67_18_Sources, 1,
        Translation_Model_1265_9_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcNoiseOverRide '<S1624>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_72_67_18, 1,
        Translation_Model_1265_72_67_18_Sources, 1,
        Translation_Model_1265_72_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag '<S1628>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_74_67_18, 1,
        Translation_Model_1265_74_67_18_Sources, 1,
        Translation_Model_1265_74_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcBoostOverRide '<S1632>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_75_67_18, 1,
        Translation_Model_1265_75_67_18_Sources, 1,
        Translation_Model_1265_75_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcBoostOverRideFlag '<S1636>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_76_67_18, 1,
        Translation_Model_1265_76_67_18_Sources, 1,
        Translation_Model_1265_76_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcVncEnableTuneVar '<S1640>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_99_67_18, 1,
        Translation_Model_1265_99_67_18_Sources, 1,
        Translation_Model_1265_99_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcNum,NearAnn2Ann2NonEntGainCalcDen '<S1642>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_85, 1, Translation_Model_1265_85_Sources, 2,
        Translation_Model_1265_85_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcMinVncSignal '<S1649>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_53_67_18, 1,
        Translation_Model_1265_53_67_18_Sources, 1,
        Translation_Model_1265_53_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntGainCalcMaxSpl '<S1653>/S-Function'
    {
        0, &
        FuncTranslation_Model_1265_54_67_18, 1,
        Translation_Model_1265_54_67_18_Sources, 1,
        Translation_Model_1265_54_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2NonEntVncAppliedNum,NearAnn2Ann2NonEntVncAppliedden '<S1657>/S-Function'
    {
        0, &
        FuncTranslation_Model_1266_44, 1, Translation_Model_1266_44_Sources, 2,
        Translation_Model_1266_44_Destinations
    },

    // Translation record for NearAnn2Ann2MuteRampTime '<S1664>/S-Function'
    {
        0, &
        FuncTranslation_Model_1268_276_67_18, 1,
        Translation_Model_1268_276_67_18_Sources, 1,
        Translation_Model_1268_276_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2VolumeTable_Idx,NearAnn2Ann2VolumeTable_dB '<S1666>/S-Function'
    {
        0, &
        FuncTranslation_Model_1270_139, 1, Translation_Model_1270_139_Sources, 2,
        Translation_Model_1270_139_Destinations
    },

    // Translation record for NearAnn2Ann2VolumeRampRate '<S1673>/S-Function'
    {
        0, &
        FuncTranslation_Model_1270_192_67_18, 1,
        Translation_Model_1270_192_67_18_Sources, 1,
        Translation_Model_1270_192_67_18_Destinations
    },

    // Translation record for NearAnn2Ann2VolumeRampTime '<S1677>/S-Function'
    {
        0, &
        FuncTranslation_Model_1270_190_67_18, 1,
        Translation_Model_1270_190_67_18_Sources, 1,
        Translation_Model_1270_190_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcVncThresh '<S1695>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_7_67_18, 1,
        Translation_Model_1276_7_67_18_Sources, 1,
        Translation_Model_1276_7_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcVncSlope '<S1699>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_8_67_18, 1,
        Translation_Model_1276_8_67_18_Sources, 1,
        Translation_Model_1276_8_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcMaxBoost '<S1703>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_9_67_18, 1,
        Translation_Model_1276_9_67_18_Sources, 1,
        Translation_Model_1276_9_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcNoiseOverRide '<S1707>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_72_67_18, 1,
        Translation_Model_1276_72_67_18_Sources, 1,
        Translation_Model_1276_72_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag '<S1711>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_74_67_18, 1,
        Translation_Model_1276_74_67_18_Sources, 1,
        Translation_Model_1276_74_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcBoostOverRide '<S1715>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_75_67_18, 1,
        Translation_Model_1276_75_67_18_Sources, 1,
        Translation_Model_1276_75_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcBoostOverRideFlag '<S1719>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_76_67_18, 1,
        Translation_Model_1276_76_67_18_Sources, 1,
        Translation_Model_1276_76_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcVncEnableTuneVar '<S1723>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_99_67_18, 1,
        Translation_Model_1276_99_67_18_Sources, 1,
        Translation_Model_1276_99_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcNum,NearAnn3Ann3NonEntGainCalcDen '<S1725>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_85, 1, Translation_Model_1276_85_Sources, 2,
        Translation_Model_1276_85_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcMinVncSignal '<S1732>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_53_67_18, 1,
        Translation_Model_1276_53_67_18_Sources, 1,
        Translation_Model_1276_53_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntGainCalcMaxSpl '<S1736>/S-Function'
    {
        0, &
        FuncTranslation_Model_1276_54_67_18, 1,
        Translation_Model_1276_54_67_18_Sources, 1,
        Translation_Model_1276_54_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3NonEntVncAppliedNum,NearAnn3Ann3NonEntVncAppliedden '<S1740>/S-Function'
    {
        0, &
        FuncTranslation_Model_1277_44, 1, Translation_Model_1277_44_Sources, 2,
        Translation_Model_1277_44_Destinations
    },

    // Translation record for NearAnn3Ann3MuteRampTime '<S1747>/S-Function'
    {
        0, &
        FuncTranslation_Model_1279_276_67_18, 1,
        Translation_Model_1279_276_67_18_Sources, 1,
        Translation_Model_1279_276_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3VolumeTable_Idx,NearAnn3Ann3VolumeTable_dB '<S1749>/S-Function'
    {
        0, &
        FuncTranslation_Model_1281_139, 1, Translation_Model_1281_139_Sources, 2,
        Translation_Model_1281_139_Destinations
    },

    // Translation record for NearAnn3Ann3VolumeRampRate '<S1756>/S-Function'
    {
        0, &
        FuncTranslation_Model_1281_192_67_18, 1,
        Translation_Model_1281_192_67_18_Sources, 1,
        Translation_Model_1281_192_67_18_Destinations
    },

    // Translation record for NearAnn3Ann3VolumeRampTime '<S1760>/S-Function'
    {
        0, &
        FuncTranslation_Model_1281_190_67_18, 1,
        Translation_Model_1281_190_67_18_Sources, 1,
        Translation_Model_1281_190_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcVncThresh '<S1778>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_7_67_18, 1,
        Translation_Model_1287_7_67_18_Sources, 1,
        Translation_Model_1287_7_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcVncSlope '<S1782>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_8_67_18, 1,
        Translation_Model_1287_8_67_18_Sources, 1,
        Translation_Model_1287_8_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcMaxBoost '<S1786>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_9_67_18, 1,
        Translation_Model_1287_9_67_18_Sources, 1,
        Translation_Model_1287_9_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcNoiseOverRide '<S1790>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_72_67_18, 1,
        Translation_Model_1287_72_67_18_Sources, 1,
        Translation_Model_1287_72_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag '<S1794>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_74_67_18, 1,
        Translation_Model_1287_74_67_18_Sources, 1,
        Translation_Model_1287_74_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcBoostOverRide '<S1798>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_75_67_18, 1,
        Translation_Model_1287_75_67_18_Sources, 1,
        Translation_Model_1287_75_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcBoostOverRideFlag '<S1802>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_76_67_18, 1,
        Translation_Model_1287_76_67_18_Sources, 1,
        Translation_Model_1287_76_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcVncEnableTuneVar '<S1806>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_99_67_18, 1,
        Translation_Model_1287_99_67_18_Sources, 1,
        Translation_Model_1287_99_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcNum,NearAnn4Ann4NonEntGainCalcDen '<S1808>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_85, 1, Translation_Model_1287_85_Sources, 2,
        Translation_Model_1287_85_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcMinVncSignal '<S1815>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_53_67_18, 1,
        Translation_Model_1287_53_67_18_Sources, 1,
        Translation_Model_1287_53_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntGainCalcMaxSpl '<S1819>/S-Function'
    {
        0, &
        FuncTranslation_Model_1287_54_67_18, 1,
        Translation_Model_1287_54_67_18_Sources, 1,
        Translation_Model_1287_54_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4NonEntVncAppliedNum,NearAnn4Ann4NonEntVncAppliedden '<S1823>/S-Function'
    {
        0, &
        FuncTranslation_Model_1288_44, 1, Translation_Model_1288_44_Sources, 2,
        Translation_Model_1288_44_Destinations
    },

    // Translation record for NearAnn4Ann4MuteRampTime '<S1830>/S-Function'
    {
        0, &
        FuncTranslation_Model_1290_276_67_18, 1,
        Translation_Model_1290_276_67_18_Sources, 1,
        Translation_Model_1290_276_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4VolumeTable_Idx,NearAnn4Ann4VolumeTable_dB '<S1832>/S-Function'
    {
        0, &
        FuncTranslation_Model_1292_139, 1, Translation_Model_1292_139_Sources, 2,
        Translation_Model_1292_139_Destinations
    },

    // Translation record for NearAnn4Ann4VolumeRampRate '<S1839>/S-Function'
    {
        0, &
        FuncTranslation_Model_1292_192_67_18, 1,
        Translation_Model_1292_192_67_18_Sources, 1,
        Translation_Model_1292_192_67_18_Destinations
    },

    // Translation record for NearAnn4Ann4VolumeRampTime '<S1843>/S-Function'
    {
        0, &
        FuncTranslation_Model_1292_190_67_18, 1,
        Translation_Model_1292_190_67_18_Sources, 1,
        Translation_Model_1292_190_67_18_Destinations
    },

    // Translation record for TestRouterASDRouterEnableAux '<S1895>/S-Function'
    {
        0, &
        FuncTranslation_Model_291_138_8_67_18, 1,
        Translation_Model_291_138_8_67_18_Sources, 1,
        Translation_Model_291_138_8_67_18_Destinations
    },

    // Translation record for TestRouterASDRouterMainSelect '<S1900>/S-Function'
    {
        0, &
        FuncTranslation_Model_291_138_44_67_18, 1,
        Translation_Model_291_138_44_67_18_Sources, 1,
        Translation_Model_291_138_44_67_18_Destinations
    },

    // Translation record for TestRouterAuxSelect '<S1904>/S-Function'
    {
        0, &
        FuncTranslation_Model_296_67_18, 1, Translation_Model_296_67_18_Sources,
        1, Translation_Model_296_67_18_Destinations
    },
};

// Share table in a public interface for use by top-model
void* Model_TranslationEngine64_translation_table = translation_table;
int Model_TranslationEngine64_translation_table_count = sizeof(translation_table)
    / sizeof(TranslationRecord_type);

// -----------------------------------------------------
// Local storage
static uint32_t theTranslationErrorState = 0;
static char translateErrorBuffer[1024];
static int translateErrorCharsUsed = 0;

// -----------------------------------------------------
// Translation engine entry points:

// forward declare local functions
static void SetTranslationErrorState(uint32_t errorState);
static void ErrorVPrintf(const char* formatString, va_list args);
static void ErrorPrintf(const char* formatString, ...);

// -----------------------------------------------------
// Top-level model root array to access engine tables:
int numTranslationRoots = 0;
TranslationRoot* translationRoots[Model_TranslationEngine64_ModelCount] =
{
    0
};

void RegisterTranslationRoot(TranslationRoot* aRoot)
{
    int i;
    const int arraySize = Model_TranslationEngine64_ModelCount;
    for (i=0; i < arraySize; i++)
    {
        if (aRoot == translationRoots[i])
        {
            // already here!
            return;
        }

        if (0 == translationRoots[i])
        {
            // found a slot at the end
            translationRoots[i] = aRoot;
            numTranslationRoots = i+1;
            return;
        }
    }

    // ERROR! Array size was too small! This should not happen.
    while (1) ;
}

TranslateEngineIterator INVALID_TRANSLATE_ITERATOR =
{
    -1, -1
};

int IsValidTranslateIterator(TranslateEngineIterator anIterator)
{
    return (anIterator.model >= 0) && (anIterator.index >= 0);
}

static TranslationRecord_type* GetTranslationRecord(TranslateEngineIterator
    translationNumIn)
{
    // Validate input parameters
    if ((translationNumIn.model < 0) || (translationNumIn.model >=
            numTranslationRoots))
    {
        return 0;                      // model out of range
    }

    TranslationRoot* theRoot = translationRoots[translationNumIn.model];
    if ((translationNumIn.index < 0) || (translationNumIn.index >=
            *theRoot->translation_count))
    {
        return 0;                      // index out of range for specified model
    }

    TranslationRecord_type* theTable = *(TranslationRecord_type**)
        theRoot->translation_table;
    return &theTable[translationNumIn.index];
}

// Return the translation record that outputs specified TOP (or INVALID_TRANSLATE_ITERATOR if not found)
static TranslateEngineIterator FindTranslationForTop(const char* topNameIn)
{
    TranslateEngineIterator retVal = INVALID_TRANSLATE_ITERATOR;
    TranslateEngineIterator theOne;
    int m;
    int foundIt = 0;
    TranslationRecord_type* aRecord;

    // Loop through models
    for (m = 0; (0 == foundIt) && (m < numTranslationRoots); m++)
    {
        theOne.model = m;
        theOne.index = 0;

        // Loop through translations of this model
        for (aRecord = GetTranslationRecord(theOne); (0 == foundIt) && aRecord;
             aRecord = GetTranslationRecord(theOne))
        {
            // Loop through TOPs of this translation
            for (int topIndex = 0; (0 == foundIt) && (topIndex <
                    aRecord->top_count); topIndex++)
            {
                TranslateEngineIterator aTop;
                aTop.model = m;
                aTop.index = aRecord->tops[topIndex];
                const char* aTopName = GetTopName(aTop);
                if (aTopName && (0 == strcmp(aTopName, topNameIn)))
                {
                    // Found it!
                    foundIt = 1;
                    retVal = theOne;
                    break;
                }
            }

            // move on to the next translation
            theOne.index++;
        }
    }

    return retVal;
}

// Retrieve space-delimited list of TuneVars needed for specified translation
// Returns char count placed in buffer
static int ListTuneVarsForTranslation(TranslateEngineIterator translationNumIn,
    char* bufferInOut, int bufferSizeIn)
{
    char* buf = bufferInOut;
    int bufSize = bufferSizeIn;
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (aRecord)
    {
        // TOPs can only be fed by one translation - which was provided
        // Loop through and dump TuneVar names
        for (int i = 0; i < aRecord->tunevar_count; i++)
        {
            TranslateEngineIterator aTuneVar;
            aTuneVar.model = translationNumIn.model;
            aTuneVar.index = aRecord->tunevars[i];
            int used = 0;
            if (i > 0)
            {
                used = snprintf(buf, bufSize, " ");
                buf += used;
                bufSize -= used;
            }

            used = snprintf(buf, bufSize, "%s", GetTuneVarName(aTuneVar));
            buf += used;
            bufSize -= used;
        }
    }

    return (bufferSizeIn - bufSize);
}

// Returns space-delimited list of TuneVars (in bufferInOut) that feed specified top
// Returns char count placed in buffer
int ListTuneVarsForTop(const char* topNameIn, char* bufferInOut, int
                       bufferSizeIn)
{
    TranslateEngineIterator theTranslation = FindTranslationForTop(topNameIn);
    return ListTuneVarsForTranslation(theTranslation,bufferInOut,bufferSizeIn);
}

// Touch translation object to indicate new data is available and
// must be translated.
void TouchTranslation(TranslateEngineIterator translationNumIn)
{
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (aRecord)
    {
        aRecord->updated_tune_vars++;
    }
}

// Get a translation's dirty flag in the form of updated TuneVar count
int GetTranslationUpdatedTuneVarCount(TranslateEngineIterator translationNumIn)
{
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (aRecord)
    {
        return aRecord->updated_tune_vars;
    }

    return 0;                          // bad iterator
}

// Clear all flags that would indicate a translation must be run
void ClearAllTranslationRequiredFlags( void )
{
    TranslationRecord_type* aRecord;
    TranslateEngineIterator translationNum;
    int m;
    for (m = 0; m < numTranslationRoots; m++)
    {
        translationNum.model = m;
        translationNum.index = 0;
        for (aRecord = GetTranslationRecord(translationNum); aRecord;
             aRecord = GetTranslationRecord(translationNum))
        {
            aRecord->updated_tune_vars = 0;
            translationNum.index++;
        }
    }
}

// Return the first translation record that has been touched to run (or INVALID_TRANSLATE_ITERATOR if none)
TranslateEngineIterator FindFirstNeededTranslation( void )
{
    TranslateEngineIterator retVal = INVALID_TRANSLATE_ITERATOR;
    TranslateEngineIterator theFirst;
    int m;
    TranslationRecord_type* aRecord;
    for (m = 0; m < numTranslationRoots; m++)
    {
        theFirst.model = m;
        theFirst.index = 0;
        for (aRecord = GetTranslationRecord(theFirst); aRecord;
             aRecord = GetTranslationRecord(theFirst))
        {
            if (aRecord->updated_tune_vars != 0)
            {
                // Found it!
                retVal = theFirst;
                break;
            }

            theFirst.index++;
        }
    }

    return retVal;
}

// Return the next translation record that has been touched to run (or INVALID_TRANSLATE_ITERATOR if no more)
TranslateEngineIterator FindNextNeededTranslation(TranslateEngineIterator
    afterThisOne)
{
    TranslateEngineIterator retVal = INVALID_TRANSLATE_ITERATOR;
    TranslateEngineIterator nextOne;
    nextOne.index = afterThisOne.index + 1;
    int m;
    int foundIt = 0;
    TranslationRecord_type* aRecord;
    for (m = afterThisOne.model; (0 == foundIt) && (m < numTranslationRoots); m
            ++)
    {
        nextOne.model = m;
        for (aRecord = GetTranslationRecord(nextOne); aRecord;
             aRecord = GetTranslationRecord(nextOne))
        {
            if (aRecord->updated_tune_vars != 0)
            {
                // Found it!
                foundIt = 1;
                retVal = nextOne;
                break;
            }

            // move on to the next translation
            nextOne.index++;
        }

        // Reset the index in preparation for the next model search
        nextOne.index = 0;
    }

    return retVal;
}

// Verify that all TuneVars read by the specified translation have been seen
// Returns 0 if OK; nonzero if error and sets translation error state
int CheckTranslationSourceSightingsOK(TranslateEngineIterator translationNumIn)
{
    int retVal = 0;                    // assume signtings are OK
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (0 == aRecord)
        return 0;                      // if translation not found just bail ok

    // Loop through and check that all source TuneVars have been seen
    int i;
    for (i = 0; i < aRecord->tunevar_count; i++)
    {
        TranslateEngineIterator aTuneVar;
        aTuneVar.model = translationNumIn.model;
        aTuneVar.index = aRecord->tunevars[i];
        int sightings = GetTuneVarSightings(aTuneVar);
        if (sightings == 0)
        {
            // Error - have not seen this one yet!
            retVal = 1;
            ErrorPrintf("Missing TuneVar %s required for translation#%d:%d\n",
                        GetTuneVarName(aTuneVar), translationNumIn.model,
                        translationNumIn.index);

            // Missing TuneVar. Set the error state
            SetTranslationErrorState(1);
        }
    }

    return retVal;
}

// Checks source sightings & calls translation function
// Reset dirty flags only if requested and no error in translation
// returns error state (0 means OK);
int CallTranslation(TranslateEngineIterator translationNumIn, int
                    cleanFlagIfNoError)
{
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (0 == aRecord)
        return 0;                      // if translation not found just bail ok

    // remember the error state and then clear it so we can check *this*
    // translation's encounters with error
    uint32_t errorStateBefore = GetTranslationErrorState();
    SetTranslationErrorState(0);

    // Get the translation record and run the translation
    int err = CheckTranslationSourceSightingsOK(translationNumIn);
    if (0 == err)
    {
        aRecord->translation_func();
    }

    uint32_t errorStateAfter = GetTranslationErrorState();
    if (0 != errorStateAfter)
    {
        ErrorPrintf("... while processing TuneVars { ");
        int i;
        for (i = 0; i < aRecord->tunevar_count; i++)
        {
            TranslateEngineIterator tuneVar;
            tuneVar.model = translationNumIn.model;
            tuneVar.index = aRecord->tunevars[i];
            ErrorPrintf("%s ", GetTuneVarName(tuneVar));
        }

        ErrorPrintf("}\n");
    }

    // If requested to clean the flag and no errors happened
    if (cleanFlagIfNoError && 0 == errorStateAfter)
    {
        // Clear the dirty flag after a successful translation
        aRecord->updated_tune_vars = 0;
    }

    // If no new errors happened, bring back previous errors
    if (0 == errorStateAfter)
    {
        SetTranslationErrorState(errorStateBefore);
    }

    return GetTranslationErrorState();
}

// Returns characters dumped, or 0 if nothing to dump (i.e. top index too high), negative on buffer too small
int DumpTranslatedTOP(TranslateEngineIterator translationNumIn, int topIndexIn,
                      char* bufferInOut, int bufferSizeIn)
{
    int charsDumped = 0;
    TranslationRecord_type* aRecord = GetTranslationRecord(translationNumIn);
    if (aRecord)
    {
        if (topIndexIn >= 0 && topIndexIn < aRecord->top_count)
        {
            TranslateEngineIterator aTop;
            aTop.model = translationNumIn.model;
            aTop.index = aRecord->tops[topIndexIn];
            charsDumped = DumpTranslatedValue(aTop,bufferInOut,bufferSizeIn);
            if (charsDumped < 0)
            {
                ErrorPrintf("Error: Translation engine return buffer too small for TOP\n");
                SetTranslationErrorState(1);
            }
        }
    }

    return charsDumped;
}

static void SetTranslationErrorState(uint32_t errorState)
{
    theTranslationErrorState = errorState;
}

// Retrieve translation error state
uint32_t GetTranslationErrorState( void )
{
    return theTranslationErrorState;
}

// Internal use print to error buffer
static void ErrorVPrintf(const char* formatString, va_list args)
{
    char* buffer = &translateErrorBuffer[translateErrorCharsUsed];
    int bufferSize = sizeof(translateErrorBuffer) - translateErrorCharsUsed;
    if (bufferSize)
    {
        int charsPrinted = vsnprintf(
            buffer, bufferSize, formatString, args);
        translateErrorCharsUsed += charsPrinted;
    }
}

// Internal use print to error buffer
static void ErrorPrintf(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);
}

// Report a translation error (works like printf)
// Called from the model code
void TranslateError(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);

    // Add newline and set error state
    ErrorPrintf("\n");
    SetTranslationErrorState(1);
}

// Report a translation warning (works like printf)
// Called from the model code
void TranslateWarning(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);

    // Add newline and set error state
    ErrorPrintf("\n");
}

// Retrieve reported error strings
const char* GetTranslationErrorStrings( void )
{
    return &translateErrorBuffer[0];
}

// Clear error state
void ClearTranslationErrorState( void )
{
    translateErrorBuffer[0] = 0;
    translateErrorCharsUsed = 0;
    SetTranslationErrorState(0);
}

TranslationRoot Model_TranslationEngine64_TranslationRoot =
{
    &Model_TranslationEngine64_tune_var_table,
    &Model_TranslationEngine64_translation_table,
    &Model_TranslationEngine64_TOP_RcvTrans_table,
    &Model_TranslationEngine64_tune_var_table_count,
    &Model_TranslationEngine64_translation_table_count,
    &Model_TranslationEngine64_TOP_RcvTrans_table_count
};

void Model_TranslationEngine64_InitializeTranslationRoot()
{
    RegisterTranslationRoot(&Model_TranslationEngine64_TranslationRoot);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
