/*
 * File: Model_TranslationEngine64_private.h
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

#ifndef RTW_HEADER_Model_TranslationEngine64_private_h_
#define RTW_HEADER_Model_TranslationEngine64_private_h_
#include "rtwtypes.h"
#include "Model_TranslationEngine64_types.h"
#include "Model_TranslationEngine64.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void Model_TranslationEngine64_Bass0Enable(const bus_single_1_1 *rtu_on,
    const bus_single_1_1 *rtu_slope, B_Bass0Enable_Model_TranslationEngine64_T
    *localB);
extern void Model_TranslationEngine64_TimeConstant2Coefficient(const
    bus_single_1_1 *rtu_tau,
    B_TimeConstant2Coefficient_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_Translation(const bus_single_3_6
    *rtu_RawSOS, const bus_single_1_1 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_sec2sample(const bus_single_1_1 *rtu_u,
    B_sec2sample_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_Tau2Coef(const bus_single_1_1 *rtu_tau,
    B_Tau2Coef_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_sec2samples(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_SetPositive(const bus_single_1_1 *rtu_Tune,
    B_SetPositive_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_sec2samples_j(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_a_T *localB);
extern void Model_TranslationEngine64_Translation_l(const bus_double_6_6
    *rtu_RawSOS, const bus_double_1_2 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_o_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation3(const bus_double_1_1
    *rtu_ESDUpperbounddBIn, const bus_double_1_1 *rtu_ESDLowerbounddBIn,
    B_TrivialTranslation3_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation1(const bus_double_1_1
    *rtu_FastPsdSmoothCutoff, const bus_double_1_1 *rtu_SlowPsdSmoothCutoff,
    real_T rtu_FrameRate, B_TrivialTranslation1_Model_TranslationEngine64_T
    *localB);
extern void Model_TranslationEngine64_TrivialTranslation3_l(const bus_double_1_1
    *rtu_DirectPathSec, real_T rtu_FrameRate, real_T rtu_FrameSize,
    B_TrivialTranslation3_Model_TranslationEngine64_p_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation4(const bus_double_1_1
    *rtu_LsSmoothCutoff, real_T rtu_FrameRate,
    B_TrivialTranslation4_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation(const bus_double_1_1
    *rtu_BackwardDownmixMax, B_TrivialTranslation_Model_TranslationEngine64_T
    *localB);
extern void Model_TranslationEngine64_TrivialTranslation_f(const bus_double_1_1 *
    rtu_BackwardDownmixThreshold,
    B_TrivialTranslation_Model_TranslationEngine64_b_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_p(const bus_double_1_1 *
    rtu_ForwardDownmixThreshold,
    B_TrivialTranslation_Model_TranslationEngine64_d_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_pz(const bus_double_1_1
    *rtu_ForwardDownmixMax, B_TrivialTranslation_Model_TranslationEngine64_a_T
    *localB);
extern void Model_TranslationEngine64_TrivialTranslation_a(const bus_double_1_1 *
    rtu_interpolationMethod, B_TrivialTranslation_Model_TranslationEngine64_k_T *
    localB);
extern void Model_TranslationEngine64_TrivialTranslation_n(const
    bus_double_12__1 *rtu_downmix_wts,
    B_TrivialTranslation_Model_TranslationEngine64_e_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_c(const
    bus_double_12__1 *rtu_detentGain,
    B_TrivialTranslation_Model_TranslationEngine64_o_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_i(const
    bus_double_12__1 *rtu_maxGain,
    B_TrivialTranslation_Model_TranslationEngine64_f_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_c1(const
    bus_double_12__1 *rtu_minGain,
    B_TrivialTranslation_Model_TranslationEngine64_j_T *localB);
extern void Model_TranslationEngine64_tonefiltertunetranslate3(const
    bus_double_1_1 *rtu_maxIn,
    B_tonefiltertunetranslate3_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_tonefiltertunetranslate1(const
    bus_double_1_1 *rtu_FilterFrequencyHz, real32_T rtu_Fs,
    B_tonefiltertunetranslate1_Model_TranslationEngine64_T *localB);
extern void Model_TranslationEngine64_tonefiltertunetranslate1_n(const
    bus_double_1_1 *rtu_FilterFrequencyHz, real32_T rtu_Fs, const bus_double_1_1
    *rtu_Qval, B_tonefiltertunetranslate1_Model_TranslationEngine64_m_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_h(const bus_double_1_1 *
    rtu_Tune1, B_TrivialTranslation_Model_TranslationEngine64_ap_T *localB);
extern void Model_TranslationEngine64_tonefiltertunetranslate1_i(const
    bus_double_1_1 *rtu_FilterFrequencyHz, real32_T rtu_Fs,
    B_tonefiltertunetranslate1_Model_TranslationEngine64_h_T *localB);
extern void Model_TranslationEngine64_Translation_p(const bus_single_1_1 *rtu_F1,
    const bus_single_1_1 *rtu_F2, const bus_single_1_1 *rtu_F3, const
    bus_single_1_1 *rtu_F4, const bus_single_1_1 *rtu_F5, const bus_single_1_1
    *rtu_F6, const bus_single_1_1 *rtu_F7,
    B_Translation_Model_TranslationEngine64_e_T *localB);
extern void Model_TranslationEngine64_Translation_h(const bus_double_100___6
    *rtu_RawSOS, const bus_double_1_4 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_k_T *localB);
extern void Model_TranslationEngine64_Translation_e(const bus_single_1_1
    *rtu_driversrc1, const bus_single_1_1 *rtu_driversrc2, const bus_single_1_1 *
    rtu_passengersrc1, const bus_single_1_1 *rtu_passengersrc2,
    B_Translation_Model_TranslationEngine64_or_T *localB);
extern void Model_TranslationEngine64_TrivialTranslation_pe(const
    bus_double_1_18 *rtu_Map, real_T rtp_nInRouterMask,
    B_TrivialTranslation_Model_TranslationEngine64_jd_T *localB);
extern void Model_TranslationEngine64_sec2samples_p(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_h_T *localB);
extern void Model_TranslationEngine64_sec2samples_g(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_ae_T *localB);
extern void Model_TranslationEngine64_translation_g(const bus_single_1_1
    *rtu_tau, B_translation_Model_TranslationEngine64_g_T *localB);
extern void Model_TranslationEngine64_Translation_lp(const bus_double_1_1
    *rtu_tau, real32_T rtu_Fs, real32_T rtu_L,
    B_Translation_Model_TranslationEngine64_l_T *localB);
extern void Model_TranslationEngine64_volumetabletranslation(const
    bus_double_16__2 *rtu_VolumeTable,
    B_volumetabletranslation_Model_TranslationEngine64_T *localB);
extern void FuncTranslation_Model_141_1371(void);
extern void FuncTranslation_Model_141_2888(void);
extern void FuncTranslation_Model_141_2926(void);
extern void FuncTranslation_Model_141_2932(void);
extern void FuncTranslation_Model_141_2939(void);
extern void FuncTranslation_Model_141_2947(void);
extern void FuncTranslation_Model_141_2955(void);
extern void FuncTranslation_Model_141_2962(void);
extern void FuncTranslation_Model_141_2968(void);
extern void FuncTranslation_Model_141_3372(void);
extern void FuncTranslation_Model_141_3380(void);
extern void FuncTranslation_Model_141_3388(void);
extern void FuncTranslation_Model_141_3395(void);
extern void FuncTranslation_Model_141_3402(void);
extern void FuncTranslation_Model_141_3410(void);
extern void FuncTranslation_Model_141_3418(void);
extern void FuncTranslation_Model_141_3426(void);
extern void FuncTranslation_Model_141_3434(void);
extern void FuncTranslation_Model_141_3442(void);
extern void FuncTranslation_Model_141_3495(void);
extern void FuncTranslation_Model_141_3596(void);
extern void FuncTranslation_Model_141_3602(void);
extern void FuncTranslation_Model_141_3609(void);
extern void FuncTranslation_Model_141_3617(void);
extern void FuncTranslation_Model_141_3625(void);
extern void FuncTranslation_Model_141_3632(void);
extern void FuncTranslation_Model_141_3638(void);
extern void FuncTranslation_Model_141_4091(void);
extern void FuncTranslation_Model_141_4099(void);
extern void FuncTranslation_Model_141_4107(void);
extern void FuncTranslation_Model_141_4114(void);
extern void FuncTranslation_Model_141_4121(void);
extern void FuncTranslation_Model_141_4129(void);
extern void FuncTranslation_Model_141_4137(void);
extern void FuncTranslation_Model_141_4145(void);
extern void FuncTranslation_Model_141_4153(void);
extern void FuncTranslation_Model_141_4161(void);
extern void FuncTranslation_Model_141_983_182(void);
extern void FuncTranslation_Model_141_983_188(void);
extern void FuncTranslation_Model_141_983_194(void);
extern void FuncTranslation_Model_141_983_200(void);
extern void FuncTranslation_Model_141_983_206(void);
extern void FuncTranslation_Model_141_983_287(void);
extern void FuncTranslation_Model_141_983_293(void);
extern void FuncTranslation_Model_141_983_299(void);
extern void FuncTranslation_Model_141_983_305(void);
extern void FuncTranslation_Model_141_984_182(void);
extern void FuncTranslation_Model_141_984_188(void);
extern void FuncTranslation_Model_141_984_194(void);
extern void FuncTranslation_Model_141_984_200(void);
extern void FuncTranslation_Model_141_984_206(void);
extern void FuncTranslation_Model_141_984_287(void);
extern void FuncTranslation_Model_141_984_293(void);
extern void FuncTranslation_Model_141_984_299(void);
extern void FuncTranslation_Model_141_984_305(void);
extern void FuncTranslation_Model_141_472_255_36(void);
extern void FuncTranslation_Model_141_472_235(void);
extern void FuncTranslation_Model_141_472_239_67_18(void);
extern void FuncTranslation_Model_141_472_240_67_18(void);
extern void FuncTranslation_Model_141_473_12_36(void);
extern void FuncTranslation_Model_141_595_238_36(void);
extern void FuncTranslation_Model_141_595_191(void);
extern void FuncTranslation_Model_141_4193(void);
extern void FuncTranslation_Model_247_174(void);
extern void FuncTranslation_Model_247_149(void);
extern void FuncTranslation_Model_247_153(void);
extern void FuncTranslation_Model_247_176(void);
extern void FuncTranslation_Model_247_210_67_18(void);
extern void FuncTranslation_Model_247_229_67_18(void);
extern void FuncTranslation_Model_247_209_67_18(void);
extern void FuncTranslation_Model_249_46(void);
extern void FuncTranslation_Model_249_47(void);
extern void FuncTranslation_Model_249_48(void);
extern void FuncTranslation_Model_249_49(void);
extern void FuncTranslation_Model_249_50_67_18(void);
extern void FuncTranslation_Model_249_51_67_18(void);
extern void FuncTranslation_Model_249_52_67_18(void);
extern void FuncTranslation_Model_642(void);
extern void FuncTranslation_Model_670_67_18(void);
extern void FuncTranslation_Model_712(void);
extern void FuncTranslation_Model_729(void);
extern void FuncTranslation_Model_730(void);
extern void FuncTranslation_Model_731(void);
extern void FuncTranslation_Model_741(void);
extern void FuncTranslation_Model_747(void);
extern void FuncTranslation_Model_251_174(void);
extern void FuncTranslation_Model_251_149(void);
extern void FuncTranslation_Model_251_153(void);
extern void FuncTranslation_Model_251_176(void);
extern void FuncTranslation_Model_251_210_67_18(void);
extern void FuncTranslation_Model_251_229_67_18(void);
extern void FuncTranslation_Model_251_209_67_18(void);
extern void FuncTranslation_Model_397(void);
extern void Model_TranslationEngine64_InputSelect_Init(void);
extern void FuncTranslation_Model_117_21_67_18(void);
extern void FuncTranslation_Model_117_1781(void);
extern void FuncTranslation_Model_117_43_332(void);
extern void FuncTranslation_Model_117_43_351(void);
extern void FuncTranslation_Model_117_43_340(void);
extern void FuncTranslation_Model_117_43_403(void);
extern void FuncTranslation_Model_117_44_721(void);
extern void FuncTranslation_Model_117_44_722(void);
extern void FuncTranslation_Model_117_44_723(void);
extern void FuncTranslation_Model_117_44_895(void);
extern void FuncTranslation_Model_117_44_736(void);
extern void FuncTranslation_Model_117_44_894(void);
extern void FuncTranslation_Model_117_44_469_67_18(void);
extern void FuncTranslation_Model_117_44_470_67_18(void);
extern void FuncTranslation_Model_117_44_332_67_18(void);
extern void FuncTranslation_Model_117_44_333_67_18(void);
extern void FuncTranslation_Model_117_44_334_67_18(void);
extern void FuncTranslation_Model_117_44_335_67_18(void);
extern void FuncTranslation_Model_117_44_341_67_18(void);
extern void FuncTranslation_Model_117_44_342_67_18(void);
extern void FuncTranslation_Model_117_44_484_67_18(void);
extern void FuncTranslation_Model_117_44_485_67_18(void);
extern void FuncTranslation_Model_117_44_315_67_18(void);
extern void FuncTranslation_Model_117_44_316_67_18(void);
extern void FuncTranslation_Model_117_44_317_67_18(void);
extern void FuncTranslation_Model_117_44_318_67_18(void);
extern void FuncTranslation_Model_117_44_645(void);
extern void FuncTranslation_Model_117_44_666(void);
extern void FuncTranslation_Model_117_44_672(void);
extern void FuncTranslation_Model_117_44_325_67_18(void);
extern void FuncTranslation_Model_117_44_633(void);
extern void FuncTranslation_Model_117_44_343_67_18(void);
extern void FuncTranslation_Model_117_44_337_67_18(void);
extern void FuncTranslation_Model_117_44_338_67_18(void);
extern void FuncTranslation_Model_117_44_913_67_18(void);
extern void FuncTranslation_Model_117_44_346_67_18(void);
extern void FuncTranslation_Model_117_44_328(void);
extern void FuncTranslation_Model_117_516_1944(void);
extern void FuncTranslation_Model_117_516_1707_67_18(void);
extern void FuncTranslation_Model_117_516_1708_67_18(void);
extern void FuncTranslation_Model_117_516_1732_67_18(void);
extern void FuncTranslation_Model_117_516_1733_67_18(void);
extern void FuncTranslation_Model_117_516_1751_67_18(void);
extern void FuncTranslation_Model_117_516_1752_67_18(void);
extern void FuncTranslation_Model_117_516_1753_67_18(void);
extern void FuncTranslation_Model_117_516_1755_67_18(void);
extern void FuncTranslation_Model_117_516_1754_67_18(void);
extern void FuncTranslation_Model_117_516_1758(void);
extern void FuncTranslation_Model_117_516_1774_67_18(void);
extern void FuncTranslation_Model_117_516_1789(void);
extern void FuncTranslation_Model_117_516_1795(void);
extern void FuncTranslation_Model_117_516_1804_67_18(void);
extern void FuncTranslation_Model_117_516_1778_67_18(void);
extern void FuncTranslation_Model_117_516_1849_50_36(void);
extern void FuncTranslation_Model_117_516_1847_50_36(void);
extern void FuncTranslation_Model_117_516_957(void);
extern void FuncTranslation_Model_117_517_435(void);
extern void FuncTranslation_Model_117_517_422(void);
extern void FuncTranslation_Model_117_517_415(void);
extern void FuncTranslation_Model_117_517_330_67_18(void);
extern void FuncTranslation_Model_117_517_331_67_18(void);
extern void FuncTranslation_Model_117_517_332_67_18(void);
extern void FuncTranslation_Model_117_517_429_67_18(void);
extern void FuncTranslation_Model_117_517_515_50_36(void);
extern void FuncTranslation_Model_117_517_516_50_36(void);
extern void FuncTranslation_Model_117_517_459_67_18(void);
extern void FuncTranslation_Model_117_517_351(void);
extern void FuncTranslation_Model_117_517_388(void);
extern void FuncTranslation_Model_117_517_397(void);
extern void FuncTranslation_Model_117_517_404(void);
extern void FuncTranslation_Model_117_517_270_67_18(void);
extern void FuncTranslation_Model_117_517_572_67_18(void);
extern void FuncTranslation_Model_117_517_573_67_18(void);
extern void FuncTranslation_Model_117_517_577(void);
extern void FuncTranslation_Model_117_517_582_67_18(void);
extern void FuncTranslation_Model_117_517_553_67_18(void);
extern void FuncTranslation_Model_117_2074(void);
extern void FuncTranslation_Model_117_2078_67_18(void);
extern void FuncTranslation_Model_117_2079_67_18(void);
extern void FuncTranslation_Model_117_2082(void);
extern void FuncTranslation_Model_117_2086_67_18(void);
extern void FuncTranslation_Model_117_2087_67_18(void);
extern void FuncTranslation_Model_117_2093(void);
extern void FuncTranslation_Model_117_2099_67_18(void);
extern void FuncTranslation_Model_117_2100_67_18(void);
extern void FuncTranslation_Model_117_2115(void);
extern void FuncTranslation_Model_117_2121(void);
extern void FuncTranslation_Model_117_2125_67_18(void);
extern void FuncTranslation_Model_117_2149(void);
extern void FuncTranslation_Model_117_2155(void);
extern void FuncTranslation_Model_117_2158_67_18(void);
extern void FuncTranslation_Model_117_2159_67_18(void);
extern void FuncTranslation_Model_120_196(void);
extern void FuncTranslation_Model_120_446(void);
extern void FuncTranslation_Model_120_203(void);
extern void FuncTranslation_Model_120_122_67_18(void);
extern void FuncTranslation_Model_120_123_67_18(void);
extern void FuncTranslation_Model_120_189(void);
extern void FuncTranslation_Model_120_264(void);
extern void FuncTranslation_Model_120_514(void);
extern void FuncTranslation_Model_120_257(void);
extern void FuncTranslation_Model_120_218_67_18(void);
extern void FuncTranslation_Model_120_219_67_18(void);
extern void FuncTranslation_Model_120_250(void);
extern void FuncTranslation_Model_120_439(void);
extern void FuncTranslation_Model_120_422_50_36(void);
extern void FuncTranslation_Model_120_319_67_18(void);
extern void FuncTranslation_Model_123_280(void);
extern void FuncTranslation_Model_123_281_67_18(void);
extern void FuncTranslation_Model_123_256_67_18(void);
extern void FuncTranslation_Model_135_79(void);
extern void FuncTranslation_Model_135_81_67_18(void);
extern void FuncTranslation_Model_135_83_67_18(void);
extern void FuncTranslation_Model_135_84_67_18(void);
extern void FuncTranslation_Model_135_143_67_18(void);
extern void FuncTranslation_Model_135_85_67_18(void);
extern void FuncTranslation_Model_135_90(void);
extern void FuncTranslation_Model_141_246_96(void);
extern void FuncTranslation_Model_141_246_141_36(void);
extern void FuncTranslation_Model_141_246_148_36(void);
extern void FuncTranslation_Model_141_246_111_67_18(void);
extern void FuncTranslation_Model_141_1196_67_18(void);
extern void FuncTranslation_Model_141_1560(void);
extern void FuncTranslation_Model_141_1561(void);
extern void FuncTranslation_Model_141_1988(void);
extern void FuncTranslation_Model_141_1989(void);
extern void FuncTranslation_Model_141_1990(void);
extern void FuncTranslation_Model_141_2031_67_18(void);
extern void FuncTranslation_Model_141_2423(void);
extern void FuncTranslation_Model_141_2424(void);
extern void FuncTranslation_Model_141_2654(void);
extern void FuncTranslation_Model_141_2655(void);
extern void FuncTranslation_Model_141_2656(void);
extern void FuncTranslation_Model_141_2697_67_18(void);
extern void FuncTranslation_Model_141_2783(void);
extern void FuncTranslation_Model_141_2784(void);
extern void FuncTranslation_Model_141_2785(void);
extern void FuncTranslation_Model_141_2786(void);
extern void FuncTranslation_Model_141_2787(void);
extern void FuncTranslation_Model_141_2808_67_18(void);
extern void FuncTranslation_Model_141_2849(void);
extern void FuncTranslation_Model_141_2850(void);
extern void FuncTranslation_Model_141_2851(void);
extern void FuncTranslation_Model_141_2852(void);
extern void FuncTranslation_Model_141_2853(void);
extern void FuncTranslation_Model_141_2865_67_18(void);
extern void FuncTranslation_Model_141_2866_67_18(void);
extern void FuncTranslation_Model_141_2867_67_18(void);
extern void FuncTranslation_Model_141_2878_50_36(void);
extern void FuncTranslation_Model_420_67_18(void);
extern void FuncTranslation_Model_421_67_18(void);
extern void FuncTranslation_Model_874_36(void);
extern void FuncTranslation_Model_863(void);
extern void FuncTranslation_Model_915_36(void);
extern void FuncTranslation_Model_903(void);
extern void FuncTranslation_Model_926(void);
extern void FuncTranslation_Model_1026(void);
extern void FuncTranslation_Model_1063_36(void);
extern void FuncTranslation_Model_1052(void);
extern void FuncTranslation_Model_1104_36(void);
extern void FuncTranslation_Model_1092(void);
extern void FuncTranslation_Model_1115(void);
extern void FuncTranslation_Model_1215(void);
extern void FuncTranslation_Model_831_67_18(void);
extern void FuncTranslation_Model_1234(void);
extern void FuncTranslation_Model_1475_36(void);
extern void FuncTranslation_Model_1310_67_18(void);
extern void FuncTranslation_Model_1331(void);
extern void FuncTranslation_Model_1338(void);
extern void FuncTranslation_Model_1343(void);
extern void FuncTranslation_Model_1347_67_18(void);
extern void FuncTranslation_Model_1348_67_18(void);
extern void FuncTranslation_Model_1351(void);
extern void FuncTranslation_Model_1368(void);
extern void FuncTranslation_Model_1375(void);
extern void FuncTranslation_Model_1380(void);
extern void FuncTranslation_Model_1384_67_18(void);
extern void FuncTranslation_Model_1385_67_18(void);
extern void FuncTranslation_Model_1388(void);
extern void FuncTranslation_Model_1405(void);
extern void FuncTranslation_Model_1412(void);
extern void FuncTranslation_Model_1417(void);
extern void FuncTranslation_Model_1421_67_18(void);
extern void FuncTranslation_Model_1422_67_18(void);
extern void FuncTranslation_Model_1425(void);
extern void FuncTranslation_Model_1442(void);
extern void FuncTranslation_Model_1449(void);
extern void FuncTranslation_Model_1454(void);
extern void FuncTranslation_Model_1458_67_18(void);
extern void FuncTranslation_Model_1459_67_18(void);
extern void FuncTranslation_Model_1462(void);
extern void FuncTranslation_Model_1254_7_67_18(void);
extern void FuncTranslation_Model_1254_8_67_18(void);
extern void FuncTranslation_Model_1254_9_67_18(void);
extern void FuncTranslation_Model_1254_72_67_18(void);
extern void FuncTranslation_Model_1254_74_67_18(void);
extern void FuncTranslation_Model_1254_75_67_18(void);
extern void FuncTranslation_Model_1254_76_67_18(void);
extern void FuncTranslation_Model_1254_99_67_18(void);
extern void FuncTranslation_Model_1254_85(void);
extern void FuncTranslation_Model_1254_53_67_18(void);
extern void FuncTranslation_Model_1254_54_67_18(void);
extern void FuncTranslation_Model_1255_44(void);
extern void FuncTranslation_Model_1257_276_67_18(void);
extern void FuncTranslation_Model_1259_139(void);
extern void FuncTranslation_Model_1259_192_67_18(void);
extern void FuncTranslation_Model_1259_190_67_18(void);
extern void FuncTranslation_Model_1265_7_67_18(void);
extern void FuncTranslation_Model_1265_8_67_18(void);
extern void FuncTranslation_Model_1265_9_67_18(void);
extern void FuncTranslation_Model_1265_72_67_18(void);
extern void FuncTranslation_Model_1265_74_67_18(void);
extern void FuncTranslation_Model_1265_75_67_18(void);
extern void FuncTranslation_Model_1265_76_67_18(void);
extern void FuncTranslation_Model_1265_99_67_18(void);
extern void FuncTranslation_Model_1265_85(void);
extern void FuncTranslation_Model_1265_53_67_18(void);
extern void FuncTranslation_Model_1265_54_67_18(void);
extern void FuncTranslation_Model_1266_44(void);
extern void FuncTranslation_Model_1268_276_67_18(void);
extern void FuncTranslation_Model_1270_139(void);
extern void FuncTranslation_Model_1270_192_67_18(void);
extern void FuncTranslation_Model_1270_190_67_18(void);
extern void FuncTranslation_Model_1276_7_67_18(void);
extern void FuncTranslation_Model_1276_8_67_18(void);
extern void FuncTranslation_Model_1276_9_67_18(void);
extern void FuncTranslation_Model_1276_72_67_18(void);
extern void FuncTranslation_Model_1276_74_67_18(void);
extern void FuncTranslation_Model_1276_75_67_18(void);
extern void FuncTranslation_Model_1276_76_67_18(void);
extern void FuncTranslation_Model_1276_99_67_18(void);
extern void FuncTranslation_Model_1276_85(void);
extern void FuncTranslation_Model_1276_53_67_18(void);
extern void FuncTranslation_Model_1276_54_67_18(void);
extern void FuncTranslation_Model_1277_44(void);
extern void FuncTranslation_Model_1279_276_67_18(void);
extern void FuncTranslation_Model_1281_139(void);
extern void FuncTranslation_Model_1281_192_67_18(void);
extern void FuncTranslation_Model_1281_190_67_18(void);
extern void FuncTranslation_Model_1287_7_67_18(void);
extern void FuncTranslation_Model_1287_8_67_18(void);
extern void FuncTranslation_Model_1287_9_67_18(void);
extern void FuncTranslation_Model_1287_72_67_18(void);
extern void FuncTranslation_Model_1287_74_67_18(void);
extern void FuncTranslation_Model_1287_75_67_18(void);
extern void FuncTranslation_Model_1287_76_67_18(void);
extern void FuncTranslation_Model_1287_99_67_18(void);
extern void FuncTranslation_Model_1287_85(void);
extern void FuncTranslation_Model_1287_53_67_18(void);
extern void FuncTranslation_Model_1287_54_67_18(void);
extern void FuncTranslation_Model_1288_44(void);
extern void FuncTranslation_Model_1290_276_67_18(void);
extern void FuncTranslation_Model_1292_139(void);
extern void FuncTranslation_Model_1292_192_67_18(void);
extern void FuncTranslation_Model_1292_190_67_18(void);
extern void FuncTranslation_Model_291_138_8_67_18(void);
extern void FuncTranslation_Model_291_138_44_67_18(void);
extern void FuncTranslation_Model_296_67_18(void);
extern void Model_TranslationEngine64_AlignmentDelay_initialize(void);
extern void Model_TranslationEngine64_Medusa5H1Part3_initialize(void);
extern void Model_TranslationEngine64_Medusa5H1Part4_initialize(void);
extern void Model_TranslationEngine64_Medusa5H1Part6_initialize(void);
extern void Model_TranslationEngine64_PreAmpPart1_initialize(void);

#endif                     /* RTW_HEADER_Model_TranslationEngine64_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
