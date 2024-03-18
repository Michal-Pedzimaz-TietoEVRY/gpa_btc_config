/*
 * File: PoolDelayStorage.h
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

#ifndef RTW_HEADER_PoolDelayStorage_h_
#define RTW_HEADER_PoolDelayStorage_h_
#include "rtwtypes.h"
#include "Model_Target_types.h"

/* Exported data declaration */

/* Declaration for custom storage class: FirGenericStorage */
extern __attribute((aligned(8))) real32_T DrHeadrestFirEq63094CoeffsTarget[6384];/* '<S1253>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T FirD45716CoeffsTarget[5760];/* '<S1506>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T FirP16311CoeffsTarget[5760];/* '<S1519>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T
    MedusaBandSplitImgRej18508FirEvenInput[64];/* '<S635>/Gain' */
extern __attribute((aligned(8))) real32_T
    MedusaBandSplitImgRej44511FirEvenCoeffs[24];/* '<S638>/SignalBreak' */
extern __attribute((aligned(8))) real32_T
    MedusaDrHoligramFirEq62995CoeffsTarget[35112];/* '<S1206>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T
    MedusaExpandTailWiggle21229FirEvenCoeffs[1776];/* '<S923>/SignalBreak' */
extern __attribute((aligned(8))) real32_T
    MedusaExpandTailWiggle22052FirEvenInput[32];/* '<S905>/Gain' */
extern __attribute((aligned(8))) real32_T
    MedusaPostHoligramFirUpFir11299CoeffsTarget[144];/* '<S1317>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearBandSplit44375FirEvenCoeffs[22];/* '<S1768>/SignalBreak' */
extern __attribute((aligned(8))) real32_T NearBandSplit61633FirEvenInput[64];/* '<S1765>/Gain' */
extern __attribute((aligned(8))) real32_T NearWiggle24579FirEvenInput[16];/* '<S1332>/Gain' */
extern __attribute((aligned(8))) real32_T NearWiggle35727FirEvenCoeffs[2048];/* '<S1337>/SignalBreak' */

/* Declaration for custom storage class: PooliirAccelStorage */
extern __attribute((aligned(8))) real32_T Default13908states[33];/* '<S522>/states' */
extern __attribute((aligned(8))) real32_T Default16984PoolIirCoeffs[10];/* '<S530>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T Default25868states[337];/* '<S910>/states' */
extern __attribute((aligned(8))) real32_T Default3743PoolIirAudioOut[64];/* '<S522>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T Default48458PoolIirCoeffs[164];/* '<S918>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T Default57912PoolIirAudioOut[32];/* '<S910>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T Default59506PoolIirAudioIn[32];/* '<S906>/Gain' */
extern __attribute((aligned(8))) real32_T Default59515PoolIirAudioIn[64];/* '<S518>/Gain' */
extern __attribute((aligned(8))) real32_T HFAA13856states[97];/* '<S319>/states' */
extern __attribute((aligned(8))) real32_T HFAA24216PoolIirAudioOut[160];/* '<S319>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T HFAA24880PoolIirCoeffs[45];/* '<S327>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T HFAA49482PoolIirAudioIn[160];/* '<S256>/Product1' */
extern __attribute((aligned(8))) real32_T HFBPFilt11080PoolIirAudioOut[160];/* '<S335>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T HFBPFilt30618states[161];/* '<S335>/states' */
extern __attribute((aligned(8))) real32_T HFBPFilt37133PoolIirAudioIn[160];/* '<S256>/Matrix Concatenate' */
extern __attribute((aligned(8))) real32_T HFBPFilt63687PoolIirCoeffs[77];/* '<S343>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T HoligramFrIir16314states[7761];/* '<S1231>/states' */
extern __attribute((aligned(8))) real32_T HoligramFrIir16350PoolIirAudioOut[704];/* '<S1231>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T HoligramFrIir17389PoolIirAudioIn[704];/* '<S1227>/Gain' */
extern __attribute((aligned(8))) real32_T HoligramFrIir29898PoolIirCoeffs[726];/* '<S1239>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T LFRefFilt15698states[41];/* '<S417>/states' */
extern __attribute((aligned(8))) real32_T LFRefFilt33927PoolIirAudioIn[32];/* '<S249>/MuteLF' */
extern __attribute((aligned(8))) real32_T LFRefFilt39774PoolIirCoeffs[13];/* '<S425>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T LFRefFilt59260PoolIirAudioOut[32];/* '<S417>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T LPMicFilt1725PoolIirAudioIn[32];/* '<S397>/Gain' */
extern __attribute((aligned(8))) real32_T LPMicFilt28254PoolIirAudioOut[32];/* '<S401>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T LPMicFilt39390PoolIirCoeffs[13];/* '<S409>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T LPMicFilt61359states[41];/* '<S401>/states' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrHpf37858states[41];/* '<S603>/states' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrHpf48329PoolIirAudioIn[64];/* '<S595>/Gain' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrHpf48748PoolIirCoeffs[26];/* '<S611>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrHpf9323PoolIirAudioOut[64];/* '<S603>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrLpf16381states[41];/* '<S618>/states' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrLpf20780PoolIirAudioIn[64];/* '<S596>/Gain' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrLpf31798PoolIirAudioOut
    [64];                              /* '<S618>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T MedusaBassMgrLpf35518PoolIirCoeffs[26];/* '<S626>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T MedusaDrHoligramIirEq2PoolIirAudioIn
    [528];                             /* '<S1196>/Gain' */
extern __attribute((aligned(8))) real32_T
    MedusaDrHoligramIirEq3543PoolIirAudioOut[528];/* '<S1213>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T
    MedusaDrHoligramIirEq36493PoolIirCoeffs[5346];/* '<S1221>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T MedusaDrHoligramIirEq53194states
    [174257];                          /* '<S1213>/states' */
extern __attribute((aligned(8))) real32_T
    MedusaMonoDetectorHpf26135PoolIirCoeffs[10];/* '<S852>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T
    MedusaMonoDetectorHpf28317PoolIirAudioIn[64];/* '<S586>/Selector' */
extern __attribute((aligned(8))) real32_T
    MedusaMonoDetectorHpf58663PoolIirAudioOut[64];/* '<S844>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T MedusaMonoDetectorHpf61492states[33];/* '<S844>/states' */
extern __attribute((aligned(8))) real32_T
    MedusaPremixCSsosA45850PoolIirAudioOut[8];/* '<S1022>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosA55058states[57];/* '<S1022>/states' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosA59792PoolIirAudioIn
    [8];                               /* '<S1011>/Add' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosA9635PoolIirCoeffs[21];/* '<S1030>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T
    MedusaPremixCSsosB17910PoolIirAudioOut[8];/* '<S1039>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosB23177PoolIirAudioIn
    [8];                               /* '<S1014>/Matrix Multiply1' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosB36825states[57];/* '<S1039>/states' */
extern __attribute((aligned(8))) real32_T MedusaPremixCSsosB46041PoolIirCoeffs
    [21];                              /* '<S1047>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearFsDrEq17368PoolIirAudioIn[56];/* '<S1617>/Gain' */
extern __attribute((aligned(8))) real32_T NearFsDrEq33283states[1417];/* '<S1623>/states' */
extern __attribute((aligned(8))) real32_T NearFsDrEq5274PoolIirCoeffs[407];/* '<S1631>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearFsDrEq7346PoolIirAudioOut[56];/* '<S1623>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T NearFsFrEq11505states[1017];/* '<S1681>/states' */
extern __attribute((aligned(8))) real32_T NearFsFrEq27702PoolIirAudioOut[160];/* '<S1681>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T NearFsFrEq50753PoolIirAudioIn[160];/* '<S1675>/Gain' */
extern __attribute((aligned(8))) real32_T NearFsFrEq5572PoolIirCoeffs[405];/* '<S1689>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearHrEqDr16726states[817];/* '<S1642>/states' */
extern __attribute((aligned(8))) real32_T NearHrEqDr38590PoolIirAudioOut[32];/* '<S1642>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T NearHrEqDr45488PoolIirCoeffs[404];/* '<S1650>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearHrEqDr5320PoolIirAudioIn[32];/* '<S1636>/Gain' */
extern __attribute((aligned(8))) real32_T NearHrEqFr19PoolIirAudioOut[128];/* '<S1700>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T NearHrEqFr30301states[817];/* '<S1700>/states' */
extern __attribute((aligned(8))) real32_T NearHrEqFr38294PoolIirAudioIn[128];/* '<S1694>/Gain' */
extern __attribute((aligned(8))) real32_T NearHrEqFr62159PoolIirCoeffs[404];/* '<S1708>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T
    NearPreEmphasisShelfFilter15569PoolIirAudioIn[64];/* '<S1796>/Gain' */
extern __attribute((aligned(8))) real32_T
    NearPreEmphasisShelfFilter26026PoolIirCoeffs[10];/* '<S1810>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T NearPreEmphasisShelfFilter28252states
    [25];                              /* '<S1802>/states' */
extern __attribute((aligned(8))) real32_T
    NearPreEmphasisShelfFilter5094PoolIirAudioOut[64];/* '<S1802>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T SPUMDecayIir22216PoolIirAudioOut[64];/* '<S873>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T SPUMDecayIir2637PoolIirAudioIn[64];/* '<S869>/Gain' */
extern __attribute((aligned(8))) real32_T SPUMDecayIir32251PoolIirCoeffs[50];/* '<S881>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T SPUMDecayIir53406states[113];/* '<S873>/states' */
extern __attribute((aligned(8))) real32_T VlsHeadrestEq15002PoolIirCoeffs[972];/* '<S1268>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T VlsHeadrestEq2098PoolIirAudioIn[96];/* '<S1245>/Gain' */
extern __attribute((aligned(8))) real32_T VlsHeadrestEq57429states[5777];/* '<S1260>/states' */
extern __attribute((aligned(8))) real32_T VlsHeadrestEq817PoolIirAudioOut[96];/* '<S1260>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T XtalkIIR22535states[1937];/* '<S1485>/states' */
extern __attribute((aligned(8))) real32_T XtalkIIR25291PoolIirCoeffs[976];/* '<S1493>/SignalBreakFcn' */
extern __attribute((aligned(8))) real32_T XtalkIIR46060PoolIirAudioOut[128];/* '<S1485>/PoolIirProcess' */
extern __attribute((aligned(8))) real32_T XtalkIIR48480PoolIirAudioIn[128];/* '<S1475>/Selector' */

#endif                                 /* RTW_HEADER_PoolDelayStorage_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
