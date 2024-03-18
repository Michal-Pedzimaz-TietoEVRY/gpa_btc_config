/*
 * File: Model_TranslationEngine64_TOP_RcvTrans.c
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

#include "rtwtypes.h"
#include "Model_TranslationEngine64_TOP_RcvTrans.h"
#include "Model_TranslationEngine64.h" // for TOP translated inputs
#include "ASDID.h"                     // for SimulinkDatatypeId
#include <stdio.h>                     // for snprintf

// Struct for table (moved to *.h file, see MathWorks Case#02530176)
typedef struct TOP_RcvTrans_tag
{
    const char* top_name;             // String name of Target Overlay Parameter
    int top_sightings_count;   // Count how many times translated value received
    SimulinkDatatypeId top_in_dtype_id;
                             // Id number of numeric type (e.g. float, int, etc)
    SimulinkDatatypeId top_out_dtype_id;
                             // Id number of numeric type (e.g. float, int, etc)
    const char* top_in_dtype_name;     // Name of numeric type
    const char* top_out_dtype_name;    // Name of numeric type
    int top_is_complex;            // "1" if complex number (interleaved format)
    int top_element_count;             // count of numeric data values
    void* top_value_src_ptr;           // array of translated numeric values
    void* top_value_dst_ptr;       // Source Model only : the TOP storage itself
}
TOP_RcvTrans_type;

// ----- TOP_RcvTrans object table listing all instances
static TOP_RcvTrans_type TOP_RcvTrans_table[] =
{
    {                                  /* '<S7>/TOP' */
        "InputSelectRouterCfgOutMap", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 5,
        Model_TranslationEngine64_B.OutMap,
        0
    },

    {                                  /* '<S22>/TOP' */
        "PreAmpAudiopilotTwoDowngrade", 0,
        TSS_DOUBLE, TSS_UINT32, "double", "uint32", 0, 1,
        &Model_TranslationEngine64_B.Value_ek,
        0
    },

    {                                  /* '<S28>/TOP' */
        "PreAmpAudiopilotHvacTable", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 32,
        Model_TranslationEngine64_B.tableTOP,
        0
    },

    {                                  /* '<S33>/TOP' */
        "PreAmpAudiopilotAntiZipperRampLpfNumerator", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.num_e,
        0
    },

    {                                  /* '<S33>/TOP1' */
        "PreAmpAudiopilotAntiZipperRampLpfDenominator", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.denom_b,
        0
    },

    {                                  /* '<S34>/TOP' */
        "PreAmpAudiopilotBassBpfNumerator", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 3,
        Model_TranslationEngine64_B.num_g,
        0
    },

    {                                  /* '<S34>/TOP1' */
        "PreAmpAudiopilotBassBpfDenominator", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 3,
        Model_TranslationEngine64_B.denom_e,
        0
    },

    {                                  /* '<S35>/TOP' */
        "PreAmpAudiopilotMidrangeLpfNumerator", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 5,
        Model_TranslationEngine64_B.num,
        0
    },

    {                                  /* '<S35>/TOP1' */
        "PreAmpAudiopilotMidrangeLpfDenominator", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 5,
        Model_TranslationEngine64_B.denom,
        0
    },

    {                                  /* '<S46>/TOP' */
        "PreAmpAudiopilotMidrangeLpfAlignDelaySamples", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 1,
        &Model_TranslationEngine64_B.Samples_n,
        0
    },

    {                                  /* '<S53>/TOP' */
        "PreAmpAudiopilotBassSlope0Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Bass0Enable.slopeOut,
        0
    },

    {                                  /* '<S53>/TOP1' */
        "PreAmpAudiopilotMidrangeSlope0Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Midrange0Enable_m.slopeOut,
        0
    },

    {                                  /* '<S53>/TOP2' */
        "PreAmpAudiopilotTrebleSlope0Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Treble0Enable_k.slopeOut,
        0
    },

    {                                  /* '<S53>/TOP3' */
        "PreAmpAudiopilotBassSlope1Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Bass1Enable_o.slopeOut,
        0
    },

    {                                  /* '<S53>/TOP4' */
        "PreAmpAudiopilotMidrangeSlope1Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Midrange1Enable_d.slopeOut,
        0
    },

    {                                  /* '<S53>/TOP5' */
        "PreAmpAudiopilotTrebleSlope1Dbperdb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Treble1Enable_f.slopeOut,
        0
    },

    {                                  /* '<S54>/TOP' */
        "PreAmpAudiopilotBassThresh0Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ny,
        0
    },

    {                                  /* '<S55>/TOP' */
        "PreAmpAudiopilotBassThresh1Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mx,
        0
    },

    {                                  /* '<S56>/TOP' */
        "PreAmpAudiopilotHfNoiseHighBoundDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pb,
        0
    },

    {                                  /* '<S57>/TOP' */
        "PreAmpAudiopilotHfNoiseLowBoundDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_fv,
        0
    },

    {                                  /* '<S58>/TOP' */
        "PreAmpAudiopilotLfNoiseHighBoundDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_gn,
        0
    },

    {                                  /* '<S59>/TOP' */
        "PreAmpAudiopilotLfNoiseLowBoundDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pu,
        0
    },

    {                                  /* '<S60>/TOP' */
        "PreAmpAudiopilotMidrangeThresh0Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_dl3,
        0
    },

    {                                  /* '<S61>/TOP' */
        "PreAmpAudiopilotMidrangeThresh1Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_kt,
        0
    },

    {                                  /* '<S62>/TOP' */
        "PreAmpAudiopilotTrebleThresh0Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_es,
        0
    },

    {                                  /* '<S63>/TOP' */
        "PreAmpAudiopilotTrebleThresh1Db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_nf,
        0
    },

    {                                  /* '<S122>/TOP' */
        "PreAmpAudiopilotBassDownwardThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_kk,
        0
    },

    {                                  /* '<S123>/TOP' */
        "PreAmpAudiopilotBassMaxAudiopilotBoostDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_lo,
        0
    },

    {                                  /* '<S124>/TOP' */
        "PreAmpAudiopilotBassMaxDyneqBoostDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_cuk,
        0
    },

    {                                  /* '<S125>/TOP' */
        "PreAmpAudiopilotBassMaxTotalBoostDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_jq,
        0
    },

    {                                  /* '<S126>/TOP' */
        "PreAmpAudiopilotMidrangeDownwardSlopeDbPerDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_MidrangeEnable_j.slopeOut,
        0
    },

    {                                  /* '<S126>/TOP1' */
        "PreAmpAudiopilotBassDownwardSlopeDbPerDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_BassEnable_o.slopeOut,
        0
    },

    {                                  /* '<S126>/TOP3' */
        "PreAmpAudiopilotTrebleDownwardSlopeDbPerDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrebleEnable_f.slopeOut,
        0
    },

    {                                  /* '<S127>/TOP' */
        "PreAmpAudiopilotDyneqBassThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_h3,
        0
    },

    {                                  /* '<S128>/TOP' */
        "PreAmpAudiopilotDyneqBassSlopeDbPerDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.slopeOut,
        0
    },

    {                                  /* '<S166>/TOP' */
        "PreAmpAudiopilotMinSignalLevelDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_oc,
        0
    },

    {                                  /* '<S130>/TOP' */
        "PreAmpAudiopilotMidrangeDownwardThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_eh,
        0
    },

    {                                  /* '<S131>/TOP' */
        "PreAmpAudiopilotMidrangeMaxTotalBoostDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ba,
        0
    },

    {                                  /* '<S132>/TOP' */
        "PreAmpAudiopilotTrebleDownwardThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_dl,
        0
    },

    {                                  /* '<S133>/TOP' */
        "PreAmpAudiopilotTrebleMaxTotalBoostDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_gf,
        0
    },

    {                                  /* '<S187>/TOP' */
        "PreAmpAudiopilotEnableRampCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Coef,
        0
    },

    {                                  /* '<S199>/RefPowerMin' */
        "PreAmpAudiopilotHfNoiseRefPowerMin", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.TOP_g,
        0
    },

    {                                  /* '<S210>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaFactor", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ld,
        0
    },

    {                                  /* '<S211>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatAlphaMin", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hu,
        0
    },

    {                                  /* '<S220>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatBeta", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_m0l,
        0
    },

    {                                  /* '<S221>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinstatMin", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_jpm,
        0
    },

    {                                  /* '<S230>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessHighIndex", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ko,
        0
    },

    {                                  /* '<S231>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessLowIndex", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hk,
        0
    },

    {                                  /* '<S232>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatnessThresh", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_lr,
        0
    },

    {                                  /* '<S233>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_aq,
        0
    },

    {                                  /* '<S234>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionMinSearchMinGain", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_obg,
        0
    },

    {                                  /* '<S235>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionSubWinLenSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.samples_f,
        0
    },

    {                                  /* '<S259>/TOP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionLevelUpdateCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_od,
        0
    },

    {                                  /* '<S264>/TOP' */
        "PreAmpAudiopilotHfNoiseSlewAttackDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.y_k,
        0
    },

    {                                  /* '<S265>/TOP' */
        "PreAmpAudiopilotHfNoiseSlewDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.y_c,
        0
    },

    {                                  /* '<S266>/TOP' */
        "PreAmpAudiopilotHfNoiseSlewThresholdDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_oy,
        0
    },

    {                                  /* '<S205>/TOP' */
        "PreAmpAudiopilotHfNoiseOffsetDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pf,
        0
    },

    {                                  /* '<S284>/TOP' */
        "PreAmpAudiopilotHfNoisePreprocessAntiAliasPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 5,
        Model_TranslationEngine64_B.PoolNumStages_a,
        0
    },

    {                                  /* '<S284>/TOP1' */
        "PreAmpAudiopilotHfNoisePreprocessAntiAliaspooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 45,
        Model_TranslationEngine64_B.PoolCoeffs_i,
        0
    },

    {                                  /* '<S289>/TOP' */
        "PreAmpAudiopilotHfNoisePreprocessBandpassLowpassPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 5,
        Model_TranslationEngine64_B.PoolNumStages_f,
        0
    },

    {                                  /* '<S289>/TOP1' */
        "PreAmpAudiopilotHfNoisePreprocessBandpassLowpasspooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 77,
        Model_TranslationEngine64_B.PoolCoeffs_o,
        0
    },

    {                                  /* '<S293>/TOP' */
        "PreAmpAudiopilotHfNoiseRefLatencySamples", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 1,
        &Model_TranslationEngine64_B.Samples_h,
        0
    },

    {                                  /* '<S297>/TOP' */
        "PreAmpAudiopilotLfNoiseEnergyLpfCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient.coef,
        0
    },

    {                                  /* '<S307>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionGamma0", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient_ox.coef,
        0
    },

    {                                  /* '<S308>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceFilterCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient_gn.coef,
        0
    },

    {                                  /* '<S309>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceScale", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_js,
        0
    },

    {                                  /* '<S310>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceScale", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_gl,
        0
    },

    {                                  /* '<S311>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceScale", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pj,
        0
    },

    {                                  /* '<S312>/TOP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionOutputMin", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_e5,
        0
    },

    {                                  /* '<S338>/TOP' */
        "PreAmpAudiopilotLfNoiseMicPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 1,
        &Model_TranslationEngine64_B.sf_Translation_g.PoolNumStages,
        0
    },

    {                                  /* '<S338>/TOP1' */
        "PreAmpAudiopilotLfNoiseMicpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 13,
        Model_TranslationEngine64_B.sf_Translation_g.PoolCoeffs,
        0
    },

    {                                  /* '<S343>/TOP' */
        "PreAmpAudiopilotLfNoiseRefPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 1,
        &Model_TranslationEngine64_B.sf_Translation_gf2.PoolNumStages,
        0
    },

    {                                  /* '<S343>/TOP1' */
        "PreAmpAudiopilotLfNoiseRefpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 13,
        Model_TranslationEngine64_B.sf_Translation_gf2.PoolCoeffs,
        0
    },

    {                                  /* '<S300>/TOP' */
        "PreAmpAudiopilotLfNoiseOffsetDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mk,
        0
    },

    {                                  /* '<S351>/TOP' */
        "PreAmpAudiopilotLfNoiseRefLatencySamples", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 1,
        &Model_TranslationEngine64_B.Samples_g,
        0
    },

    {                                  /* '<S357>/TOP' */
        "PreAmpAudiopilotLfNoiseSlewAttackDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2sample_p.y,
        0
    },

    {                                  /* '<S358>/TOP' */
        "PreAmpAudiopilotLfNoiseSlewDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.y_l,
        0
    },

    {                                  /* '<S359>/TOP' */
        "PreAmpAudiopilotLfNoiseSlewSlowDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2sample_l0.y,
        0
    },

    {                                  /* '<S360>/TOP' */
        "PreAmpAudiopilotLfNoiseSlewThresholdDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_cu,
        0
    },

    {                                  /* '<S374>/TOP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsAxis", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 128,
        Model_TranslationEngine64_B.Value_c1,
        0
    },

    {                                  /* '<S375>/TOP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsMaxDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 128,
        Model_TranslationEngine64_B.Value_mh,
        0
    },

    {                                  /* '<S376>/TOP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsMinDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 128,
        Model_TranslationEngine64_B.TOP,
        0
    },

    {                                  /* '<S376>/TOP1' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsMinBoundsLowestValDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.minBoundsLowestVal,
        0
    },

    {                                  /* '<S377>/TOP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsOn", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ca,
        0
    },

    {                                  /* '<S303>/TOP' */
        "PreAmpAudiopilotLfNoiseSysMaxDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_dw,
        0
    },

    {                                  /* '<S403>/TOP' */
        "PreAmpAudiopilotRatioUpdateFlagHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.samples_h,
        0
    },

    {                                  /* '<S404>/TOP' */
        "PreAmpAudiopilotRatioUpdateHfNoiseThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_h1,
        0
    },

    {                                  /* '<S405>/TOP' */
        "PreAmpAudiopilotRatioUpdateLfNoiseThreshDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mq,
        0
    },

    {                                  /* '<S406>/TOP' */
        "PreAmpAudiopilotRatioUpdateLfNoiseUpdatePeriodSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.samples,
        0
    },

    {                                  /* '<S407>/TOP' */
        "PreAmpAudiopilotRatioUpdateLfNoiseUpdateThreshDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_dg,
        0
    },

    {                                  /* '<S408>/TOP' */
        "PreAmpAudiopilotRatioUpdateSpeedUpdateThreshMph", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_os,
        0
    },

    {                                  /* '<S398>/TOP' */
        "PreAmpAudiopilotRatioEnergyLpfCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Tau2Coef.coef,
        0
    },

    {                                  /* '<S399>/TOP' */
        "PreAmpAudiopilotRatioHighBoundDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_kh,
        0
    },

    {                                  /* '<S400>/TOP' */
        "PreAmpAudiopilotRatioLowBoundDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_oj,
        0
    },

    {                                  /* '<S442>/TOP' */
        "PreAmpAudiopilotRatioSlewAttackDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.y_g,
        0
    },

    {                                  /* '<S443>/TOP' */
        "PreAmpAudiopilotRatioSlewDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.y,
        0
    },

    {                                  /* '<S444>/TOP' */
        "PreAmpAudiopilotRatioSlewThresholdDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ov,
        0
    },

    {                                  /* '<S455>/TOP' */
        "PreAmpAudiopilotRatioImpulseRejectionGamma0", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.gamma,
        0
    },

    {                                  /* '<S456>/TOP' */
        "PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceLpfCoef", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_Tau2Coef_om.coef,
        0
    },

    {                                  /* '<S457>/TOP' */
        "PreAmpAudiopilotRatioImpulseRejectionImpulseVarianceScale", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pp,
        0
    },

    {                                  /* '<S458>/TOP' */
        "PreAmpAudiopilotRatioImpulseRejectionNoiseVarianceScale", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_e1p,
        0
    },

    {                                  /* '<S477>/TOP' */
        "PreAmpAudiopilotLevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_b.y,
        0
    },

    {                                  /* '<S478>/TOP' */
        "PreAmpAudiopilotLevelDetectHoldMarginDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive.TOP,
        0
    },

    {                                  /* '<S479>/TOP' */
        "PreAmpAudiopilotLevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_j.y,
        0
    },

    {                                  /* '<S480>/TOP' */
        "PreAmpAudiopilotLevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_p4,
        0
    },

    {                                  /* '<S481>/TOP' */
        "PreAmpAudiopilotLevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_nm,
        0
    },

    {                                  /* '<S482>/TOP' */
        "PreAmpAudiopilotLevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_ow.y,
        0
    },

    {                                  /* '<S504>/TOP' */
        "PreAmpDyneqLevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_f1.y,
        0
    },

    {                                  /* '<S505>/TOP' */
        "PreAmpDyneqLevelDetectHoldMarginDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive_ko.TOP,
        0
    },

    {                                  /* '<S506>/TOP' */
        "PreAmpDyneqLevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_ki.y,
        0
    },

    {                                  /* '<S507>/TOP' */
        "PreAmpDyneqLevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_if,
        0
    },

    {                                  /* '<S508>/TOP' */
        "PreAmpDyneqLevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_dm,
        0
    },

    {                                  /* '<S509>/TOP' */
        "PreAmpDyneqLevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_ocq.y,
        0
    },

    {                                  /* '<S530>/TOP' */
        "PreAmpLevelDetectMusicDelaySamples", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 1,
        &Model_TranslationEngine64_B.Samples,
        0
    },

    {                                  /* '<S537>/TOP' */
        "PreAmpLevelDetectPreemphasisPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.PoolNumStages_g,
        0
    },

    {                                  /* '<S537>/TOP1' */
        "PreAmpLevelDetectPreemphasispooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 10,
        Model_TranslationEngine64_B.PoolCoeffs_c,
        0
    },

    {                                  /* '<S532>/TOP' */
        "PreAmpLevelDetectSysMaxDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hl,
        0
    },

    {                                  /* '<S545>/TOP_GainDB' */
        "PreAmpVolumeCfgTable_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 8,
        Model_TranslationEngine64_B.Table_dB,
        0
    },

    {                                  /* '<S545>/TOP_Index' */
        "PreAmpVolumeCfgTable_Idx", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 8,
        Model_TranslationEngine64_B.Table_Idx,
        0
    },

    {                                  /* '<S548>/TOP' */
        "PreAmpVolumeCfgmaxgain", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_oi,
        0
    },

    {                                  /* '<S546>/TOP' */
        "PreAmpVolumeCfgRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_jc,
        0
    },

    {                                  /* '<S565>/TOP' */
        "PreAmpBalance_CfgChanRampMap", 0,
        TSS_INT32, TSS_SINGLE, "int32", "single", 0, 2,
        Model_TranslationEngine64_B.ChanRampMap_o,
        0
    },

    {                                  /* '<S567>/TOP' */
        "PreAmpBalance_CfgBoostDisable", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_lh,
        0
    },

    {                                  /* '<S568>/TOP' */
        "PreAmpBalance_CfgOffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_juf,
        0
    },

    {                                  /* '<S569>/TOP' */
        "PreAmpBalance_CfgRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_fg,
        0
    },

    {                                  /* '<S570>/TOP' */
        "PreAmpBalance_CfgSleepingBeautyMutesBass", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_nb,
        0
    },

    {                                  /* '<S571>/TOP' */
        "PreAmpBalance_CfgEnableSilentExtreme", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_fq1,
        0
    },

    {                                  /* '<S572>/TOP_TableIDb' */
        "PreAmpBalance_CfgTableDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 30,
        Model_TranslationEngine64_B.tableDb_j,
        0
    },

    {                                  /* '<S572>/TOP_TableIdx' */
        "PreAmpBalance_CfgTableIdx", 0,
        TSS_UINT32, TSS_SINGLE, "uint32", "single", 0, 30,
        Model_TranslationEngine64_B.tableIdx_o,
        0
    },

    {                                  /* '<S605>/LeftMixWeight' */
        "PreAmpMedusaBassManagerLeftMixWeights", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.LeftMixWeights_i,
        0
    },

    {                                  /* '<S605>/RightMixWeight' */
        "PreAmpMedusaBassManagerRightMixWeights", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.RightMixWeights_a,
        0
    },

    {                                  /* '<S612>/TOP' */
        "PreAmpMedusaBassManagerHpfPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_l.PoolNumStages,
        0
    },

    {                                  /* '<S612>/TOP1' */
        "PreAmpMedusaBassManagerHpfpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 26,
        Model_TranslationEngine64_B.sf_Translation_l.PoolCoeffs,
        0
    },

    {                                  /* '<S616>/TOP' */
        "PreAmpMedusaBassManagerLpfPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_jt.PoolNumStages,
        0
    },

    {                                  /* '<S616>/TOP1' */
        "PreAmpMedusaBassManagerLpfpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 26,
        Model_TranslationEngine64_B.sf_Translation_jt.PoolCoeffs,
        0
    },

    {                                  /* '<S608>/TOP' */
        "PreAmpMedusaBassManagerGainLfe2C", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_br0,
        0
    },

    {                                  /* '<S625>/TOP' */
        "PreAmpMedusaDummyTune", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_po,
        0
    },

    {                                  /* '<S635>/Treble Delay' */
        "PreAmpMedusaTrebleDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 1,
        &Model_TranslationEngine64_AlignmentDelay_B.trebleDelay,
        0
    },

    {                                  /* '<S646>/TOP' */
        "PreAmpMedusaDeciRateFdpCoeffsXpMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.XpMax_g,
        0
    },

    {                                  /* '<S646>/TOP1' */
        "PreAmpMedusaDeciRateFdpCoeffsLokRokMaxScaleFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LokRokMaxScaleFactor_a,
        0
    },

    {                                  /* '<S646>/TOP5' */
        "PreAmpMedusaDeciRateFdpCoeffsXpMin", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.XpMin_d,
        0
    },

    {                                  /* '<S646>/TOP2' */
        "PreAmpMedusaDeciRateFdpCoeffsESDUpperbounddB", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3.ESDUpperbounddB,
        0
    },

    {                                  /* '<S646>/TOP3' */
        "PreAmpMedusaDeciRateFdpCoeffsESDLowerbounddB", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3.ESDLowerbounddB,
        0
    },

    {                                  /* '<S646>/TOP4' */
        "PreAmpMedusaDeciRateFdpCoeffsESDStepSize", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3.ESDStepSize,
        0
    },

    {                                  /* '<S643>/TOP' */
        "PreAmpMedusaDeciRateFdpSpumFastPsdSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation1.FastPsdSmoothFactor,
        0
    },

    {                                  /* '<S643>/TOP1' */
        "PreAmpMedusaDeciRateFdpSpumSlowPsdSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation1.SlowPsdSmoothFactor,
        0
    },

    {                                  /* '<S643>/TOP3' */
        "PreAmpMedusaDeciRateFdpSpumDirectPathSamplesDec", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3_l.DirectPathDec,
        0
    },

    {                                  /* '<S643>/TOP4' */
        "PreAmpMedusaDeciRateFdpSpumLsSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation4.LsSmoothFactor,
        0
    },

    {                                  /* '<S641>/TOP' */
        "PreAmpMedusaDeciRateFdpSpumOverwrite", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_du,
        0
    },

    {                                  /* '<S673>/TOP' */
        "PreAmpMedusaFullRateFdpCoeffsXpMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.XpMax_n,
        0
    },

    {                                  /* '<S673>/TOP1' */
        "PreAmpMedusaFullRateFdpCoeffsLokRokMaxScaleFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LokRokMaxScaleFactor,
        0
    },

    {                                  /* '<S673>/TOP5' */
        "PreAmpMedusaFullRateFdpCoeffsXpMin", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.XpMin_h,
        0
    },

    {                                  /* '<S673>/TOP2' */
        "PreAmpMedusaFullRateFdpCoeffsESDUpperbounddB", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3_hi.ESDUpperbounddB,
        0
    },

    {                                  /* '<S673>/TOP3' */
        "PreAmpMedusaFullRateFdpCoeffsESDLowerbounddB", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3_hi.ESDLowerbounddB,
        0
    },

    {                                  /* '<S673>/TOP4' */
        "PreAmpMedusaFullRateFdpCoeffsESDStepSize", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3_hi.ESDStepSize,
        0
    },

    {                                  /* '<S670>/TOP' */
        "PreAmpMedusaFullRateFdpSpumFastPsdSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation1_fu.FastPsdSmoothFactor,
        0
    },

    {                                  /* '<S670>/TOP1' */
        "PreAmpMedusaFullRateFdpSpumSlowPsdSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation1_fu.SlowPsdSmoothFactor,
        0
    },

    {                                  /* '<S670>/TOP3' */
        "PreAmpMedusaFullRateFdpSpumDirectPathSamplesDec", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation3_ll1.DirectPathDec,
        0
    },

    {                                  /* '<S670>/TOP4' */
        "PreAmpMedusaFullRateFdpSpumLsSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_TrivialTranslation4_jo.LsSmoothFactor,
        0
    },

    {                                  /* '<S668>/TOP' */
        "PreAmpMedusaFullRateFdpSpumOverwrite", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ne,
        0
    },

    {                                  /* '<S695>/TOP' */
        "PreAmpMedusaMonoDetectorLevelPole", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LevelPole,
        0
    },

    {                                  /* '<S695>/TOP1' */
        "PreAmpMedusaMonoDetectorLevelGain", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LevelGain,
        0
    },

    {                                  /* '<S695>/TOP2' */
        "PreAmpMedusaMonoDetectorLSSmoothPole", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LSSmoothPole,
        0
    },

    {                                  /* '<S695>/TOP3' */
        "PreAmpMedusaMonoDetectorLSSmoothGain", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LSSmoothGain,
        0
    },

    {                                  /* '<S695>/TOP4' */
        "PreAmpMedusaMonoDetectorLSSmoothResetPole", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LSSmoothResetPole,
        0
    },

    {                                  /* '<S695>/TOP5' */
        "PreAmpMedusaMonoDetectorLSSmoothResetGain", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LSSmoothResetGain,
        0
    },

    {                                  /* '<S695>/TOP10' */
        "PreAmpMedusaMonoDetectorHPFNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.HPFNumStages,
        0
    },

    {                                  /* '<S695>/TOP11' */
        "PreAmpMedusaMonoDetectorHPFCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_B.HPFCoeffs,
        0
    },

    {                                  /* '<S695>/TOP6' */
        "PreAmpMedusaMonoDetectorThresholdZeroLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.ThresholdZeroLevel,
        0
    },

    {                                  /* '<S695>/TOP7' */
        "PreAmpMedusaMonoDetectorLRMatchTolerance", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.LRMatchTolerance,
        0
    },

    {                                  /* '<S695>/TOP8' */
        "PreAmpMedusaMonoDetectorThresholdMono", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.ThresholdMono,
        0
    },

    {                                  /* '<S695>/TOP9' */
        "PreAmpMedusaMonoDetectorThresholdStereo", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.ThresholdStereo,
        0
    },

    {                                  /* '<S694>/TOP' */
        "PreAmpMedusaMonoDetectorEnable", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 1,
        &Model_TranslationEngine64_B.Value_fw,
        0
    },

    {                                  /* '<S715>/TOP' */
        "PreAmpMedusaSPUMDecayEstPSDSmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.PSDSmoothFactor,
        0
    },

    {                                  /* '<S715>/TOP1' */
        "PreAmpMedusaSPUMDecayEstDecaySmoothFactor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.DecaySmoothFactor,
        0
    },

    {                                  /* '<S715>/TOP2' */
        "PreAmpMedusaSPUMDecayEstFastAttack", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.FastAttack,
        0
    },

    {                                  /* '<S715>/TOP3' */
        "PreAmpMedusaSPUMDecayEstSlowAttack", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.SlowAttack,
        0
    },

    {                                  /* '<S715>/TOP4' */
        "PreAmpMedusaSPUMDecayEstStepIncrement", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.StepIncrement,
        0
    },

    {                                  /* '<S715>/TOP5' */
        "PreAmpMedusaSPUMDecayEstStepDecrement", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.StepDecrement,
        0
    },

    {                                  /* '<S715>/TOP6' */
        "PreAmpMedusaSPUMDecayEstDirectPathFramesFs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.DirectPathFramesFs,
        0
    },

    {                                  /* '<S727>/TOP' */
        "PreAmpMedusaSPUMDecayEstNoiseFloor", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_g2,
        0
    },

    {                                  /* '<S728>/TOP' */
        "PreAmpMedusaSPUMDecayEstOnsetThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_i2,
        0
    },

    {                                  /* '<S729>/TOP' */
        "PreAmpMedusaSPUMDecayEstSlewThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_e0,
        0
    },

    {                                  /* '<S748>/TOP' */
        "PreAmpMedusaSPUMDecayEstHPFPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.PoolNumStages_o,
        0
    },

    {                                  /* '<S748>/TOP1' */
        "PreAmpMedusaSPUMDecayEstHPFpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 50,
        Model_TranslationEngine64_B.PoolCoeffs_b2,
        0
    },

    {                                  /* '<S765>/TOP' */
        "PreAmpMedusatailCompEQPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 4,
        Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages,
        0
    },

    {                                  /* '<S765>/TOP1' */
        "PreAmpMedusatailCompEQpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 164,
        Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs,
        0
    },

    {                                  /* '<S763>/TOP' */
        "PreAmpMedusaWiggleFilter", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1776,
        Model_TranslationEngine64_ExpandTailComponents_B.Value,
        0
    },

    {                                  /* '<S758>/Alignment Delay' */
        "PreAmpMedusaMidrangeDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.alignmentDelay,
        0
    },

    {                                  /* '<S758>/Decimated Bass Delay' */
        "PreAmpMedusaDeciRateBassDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.bassDelayDec,
        0
    },

    {                                  /* '<S758>/Full Rate Bass Delay' */
        "PreAmpMedusaFullRateBassDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.bassDelayFull,
        0
    },

    {                                  /* '<S776>/TOP' */
        "PreAmpMedusaFullRateMixerBackwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation.TOP,
        0
    },

    {                                  /* '<S777>/TOP' */
        "PreAmpMedusaFullRateMixerBackwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_f.TOP,
        0
    },

    {                                  /* '<S778>/TOP' */
        "PreAmpMedusaFullRateMixerDownmixWeights_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_g,
        0
    },

    {                                  /* '<S778>/TOP1' */
        "PreAmpMedusaFullRateMixerDownmixWeights_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_o,
        0
    },

    {                                  /* '<S779>/TOP' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_kd,
        0
    },

    {                                  /* '<S779>/TOP1' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ja,
        0
    },

    {                                  /* '<S780>/TOP' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ff,
        0
    },

    {                                  /* '<S780>/TOP1' */
        "PreAmpMedusaFullRateMixerDownmixWeights_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gq,
        0
    },

    {                                  /* '<S781>/TOP' */
        "PreAmpMedusaFullRateMixerForwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_p.TOP,
        0
    },

    {                                  /* '<S782>/TOP' */
        "PreAmpMedusaFullRateMixerForwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_pz.TOP,
        0
    },

    {                                  /* '<S804>/TOP' */
        "PreAmpMedusaFullRateMixerDetentLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_kf,
        0
    },

    {                                  /* '<S804>/TOP1' */
        "PreAmpMedusaFullRateMixerDetentLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_er,
        0
    },

    {                                  /* '<S805>/TOP' */
        "PreAmpMedusaFullRateMixerDetentLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_f,
        0
    },

    {                                  /* '<S805>/TOP1' */
        "PreAmpMedusaFullRateMixerDetentLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ax,
        0
    },

    {                                  /* '<S806>/TOP' */
        "PreAmpMedusaFullRateMixerDetentLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_p1,
        0
    },

    {                                  /* '<S806>/TOP1' */
        "PreAmpMedusaFullRateMixerDetentLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ba,
        0
    },

    {                                  /* '<S807>/TOP' */
        "PreAmpMedusaFullRateMixerInterpolation_Method", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_a.TOP,
        0
    },

    {                                  /* '<S808>/TOP' */
        "PreAmpMedusaFullRateMixerMaxLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_c4,
        0
    },

    {                                  /* '<S808>/TOP1' */
        "PreAmpMedusaFullRateMixerMaxLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_f,
        0
    },

    {                                  /* '<S809>/TOP' */
        "PreAmpMedusaFullRateMixerMaxLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_d4,
        0
    },

    {                                  /* '<S809>/TOP1' */
        "PreAmpMedusaFullRateMixerMaxLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gk,
        0
    },

    {                                  /* '<S810>/TOP' */
        "PreAmpMedusaFullRateMixerMaxLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_cn,
        0
    },

    {                                  /* '<S810>/TOP1' */
        "PreAmpMedusaFullRateMixerMaxLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gw,
        0
    },

    {                                  /* '<S811>/TOP' */
        "PreAmpMedusaFullRateMixerMinLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_j,
        0
    },

    {                                  /* '<S811>/TOP1' */
        "PreAmpMedusaFullRateMixerMinLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_hd,
        0
    },

    {                                  /* '<S812>/TOP' */
        "PreAmpMedusaFullRateMixerMinLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_i,
        0
    },

    {                                  /* '<S812>/TOP1' */
        "PreAmpMedusaFullRateMixerMinLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_c1,
        0
    },

    {                                  /* '<S813>/TOP' */
        "PreAmpMedusaFullRateMixerMinLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_da,
        0
    },

    {                                  /* '<S813>/TOP1' */
        "PreAmpMedusaFullRateMixerMinLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 10,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_j,
        0
    },

    {                                  /* '<S848>/TOP' */
        "PreAmpMedusaPremixMonoSurroundPhi", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.phi,
        0
    },

    {                                  /* '<S848>/TOP1' */
        "PreAmpMedusaPremixMonoSurroundCosPhi", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi,
        0
    },

    {                                  /* '<S848>/TOP2' */
        "PreAmpMedusaPremixMonoSurroundSinPhi", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi,
        0
    },

    {                                  /* '<S852>/TOP' */
        "PreAmpMedusaPremixBackwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ctt.TOP,
        0
    },

    {                                  /* '<S853>/TOP' */
        "PreAmpMedusaPremixBackwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ket.TOP,
        0
    },

    {                                  /* '<S854>/TOP' */
        "PreAmpMedusaPremixDownmixWeights_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_co,
        0
    },

    {                                  /* '<S854>/TOP1' */
        "PreAmpMedusaPremixDownmixWeights_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_h,
        0
    },

    {                                  /* '<S855>/TOP' */
        "PreAmpMedusaPremixDownmixWeights_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ho4,
        0
    },

    {                                  /* '<S855>/TOP1' */
        "PreAmpMedusaPremixDownmixWeights_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_bk,
        0
    },

    {                                  /* '<S856>/TOP' */
        "PreAmpMedusaPremixDownmixWeights_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ho,
        0
    },

    {                                  /* '<S856>/TOP1' */
        "PreAmpMedusaPremixDownmixWeights_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_g,
        0
    },

    {                                  /* '<S857>/TOP' */
        "PreAmpMedusaPremixForwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_o3.TOP,
        0
    },

    {                                  /* '<S858>/TOP' */
        "PreAmpMedusaPremixForwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_cid.TOP,
        0
    },

    {                                  /* '<S880>/TOP' */
        "PreAmpMedusaPremixDetentLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_mc,
        0
    },

    {                                  /* '<S880>/TOP1' */
        "PreAmpMedusaPremixDetentLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e2,
        0
    },

    {                                  /* '<S881>/TOP' */
        "PreAmpMedusaPremixDetentLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_c,
        0
    },

    {                                  /* '<S881>/TOP1' */
        "PreAmpMedusaPremixDetentLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_n,
        0
    },

    {                                  /* '<S882>/TOP' */
        "PreAmpMedusaPremixDetentLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_h,
        0
    },

    {                                  /* '<S882>/TOP1' */
        "PreAmpMedusaPremixDetentLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e,
        0
    },

    {                                  /* '<S883>/TOP' */
        "PreAmpMedusaPremixInterpolation_Method", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_new.TOP,
        0
    },

    {                                  /* '<S884>/TOP' */
        "PreAmpMedusaPremixMaxLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_p,
        0
    },

    {                                  /* '<S884>/TOP1' */
        "PreAmpMedusaPremixMaxLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m3,
        0
    },

    {                                  /* '<S885>/TOP' */
        "PreAmpMedusaPremixMaxLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_k,
        0
    },

    {                                  /* '<S885>/TOP1' */
        "PreAmpMedusaPremixMaxLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_a,
        0
    },

    {                                  /* '<S886>/TOP' */
        "PreAmpMedusaPremixMaxLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_d,
        0
    },

    {                                  /* '<S886>/TOP1' */
        "PreAmpMedusaPremixMaxLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_c,
        0
    },

    {                                  /* '<S887>/TOP' */
        "PreAmpMedusaPremixMinLevel_CS", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 20,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_o,
        0
    },

    {                                  /* '<S887>/TOP1' */
        "PreAmpMedusaPremixMinLevel_CS_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 4,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m,
        0
    },

    {                                  /* '<S888>/TOP' */
        "PreAmpMedusaPremixMinLevel_Left", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_m,
        0
    },

    {                                  /* '<S888>/TOP1' */
        "PreAmpMedusaPremixMinLevel_Left_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_b,
        0
    },

    {                                  /* '<S889>/TOP' */
        "PreAmpMedusaPremixMinLevel_Right", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 77,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP,
        0
    },

    {                                  /* '<S889>/TOP1' */
        "PreAmpMedusaPremixMinLevel_Right_CAE", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 33,
        Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE,
        0
    },

    {                                  /* '<S924>/TOP' */
        "PreAmpMedusaVLSDrvGainsBackwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_jf.TOP,
        0
    },

    {                                  /* '<S925>/TOP' */
        "PreAmpMedusaVLSDrvGainsBackwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_de.TOP,
        0
    },

    {                                  /* '<S926>/TOP' */
        "PreAmpMedusaVLSDrvGainsDownmixWeights", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_n5.TOP,
        0
    },

    {                                  /* '<S927>/TOP' */
        "PreAmpMedusaVLSDrvGainsForwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ags.TOP,
        0
    },

    {                                  /* '<S928>/TOP' */
        "PreAmpMedusaVLSDrvGainsForwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_i5b.TOP,
        0
    },

    {                                  /* '<S944>/TOP' */
        "PreAmpMedusaVLSDrvGainsDetentLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ci2.TOP,
        0
    },

    {                                  /* '<S945>/TOP' */
        "PreAmpMedusaVLSDrvGainsInterpolation_Method", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_mpr.TOP,
        0
    },

    {                                  /* '<S946>/TOP' */
        "PreAmpMedusaVLSDrvGainsMaxLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_il.TOP,
        0
    },

    {                                  /* '<S947>/TOP' */
        "PreAmpMedusaVLSDrvGainsMinLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_c1.TOP,
        0
    },

    {                                  /* '<S962>/TOP' */
        "PreAmpMedusaVLSPaxGainsBackwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_nlp.TOP,
        0
    },

    {                                  /* '<S963>/TOP' */
        "PreAmpMedusaVLSPaxGainsBackwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_l2w.TOP,
        0
    },

    {                                  /* '<S964>/TOP' */
        "PreAmpMedusaVLSPaxGainsDownmixWeights", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_nezf.TOP,
        0
    },

    {                                  /* '<S965>/TOP' */
        "PreAmpMedusaVLSPaxGainsForwardDownmixThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_cfe.TOP,
        0
    },

    {                                  /* '<S966>/TOP' */
        "PreAmpMedusaVLSPaxGainsForwardDownmixMax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_i1c.TOP,
        0
    },

    {                                  /* '<S982>/TOP' */
        "PreAmpMedusaVLSPaxGainsDetentLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_eng.TOP,
        0
    },

    {                                  /* '<S983>/TOP' */
        "PreAmpMedusaVLSPaxGainsInterpolation_Method", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_aig.TOP,
        0
    },

    {                                  /* '<S984>/TOP' */
        "PreAmpMedusaVLSPaxGainsMaxLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_a5u.TOP,
        0
    },

    {                                  /* '<S985>/TOP' */
        "PreAmpMedusaVLSPaxGainsMinLevel", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_gv.TOP,
        0
    },

    {                                  /* '<S1004>/TOP' */
        "PreAmpMedusaDRHoligramPoolIirTunableConfigPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_f,
        0
    },

    {                                  /* '<S1004>/TOP1' */
        "PreAmpMedusaDRHoligramPoolIirTunableConfigpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 5346,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_n,
        0
    },

    {                                  /* '<S1003>/TOP' */
        "PreAmpMedusaDRHoligramFIRCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 35112,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_o,
        0
    },

    {                                  /* '<S1003>/TOP1' */
        "PreAmpMedusaDRHoligramFilterLengths", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_c,
        0
    },

    {                                  /* '<S1003>/TOP2' */
        "PreAmpMedusaDRHoligramPaddedFilterLengths", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_i,
        0
    },

    {                                  /* '<S1009>/TOP' */
        "PreAmpMedusaDRHoligramInputMapping", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 66,
        Model_TranslationEngine64_Medusa5H1Part4_B.Value_n,
        0
    },

    {                                  /* '<S1010>/TOP' */
        "PreAmpMedusaDRHoligramOutputMapping", 0,
        TSS_UINT32, TSS_SINGLE, "uint32", "single", 0, 18,
        Model_TranslationEngine64_Medusa5H1Part4_B.Value,
        0
    },

    {                                  /* '<S1022>/TOP' */
        "PreAmpMedusaFRHoligramIirConfigPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 22,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_k,
        0
    },

    {                                  /* '<S1022>/TOP1' */
        "PreAmpMedusaFRHoligramIirConfigpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 726,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_l,
        0
    },

    {                                  /* '<S1001>/TOP' */
        "PreAmpMedusaHeadrestCompEQFIRCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 6384,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_p,
        0
    },

    {                                  /* '<S1001>/TOP1' */
        "PreAmpMedusaHeadrestCompEQFilterLengths", 0,
        TSS_DOUBLE, TSS_UINT32, "double", "uint32", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_e,
        0
    },

    {                                  /* '<S1001>/TOP2' */
        "PreAmpMedusaHeadrestCompEQPaddedFilterLengths", 0,
        TSS_DOUBLE, TSS_UINT32, "double", "uint32", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_k,
        0
    },

    {                                  /* '<S1029>/TOP' */
        "PreAmpMedusaHeadrestCompEQIirConfigPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 12,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages,
        0
    },

    {                                  /* '<S1029>/TOP1' */
        "PreAmpMedusaHeadrestCompEQIirConfigpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 972,
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs,
        0
    },

    {                                  /* '<S1034>/TOP3' */
        "PreAmpMedusaFRSpeakerDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 22,
        Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay,
        0
    },

    {                                  /* '<S1034>/TOP5' */
        "PreAmpMedusaDRSpeakerDelay", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 30,
        Model_TranslationEngine64_Medusa5H1Part6_B.DRDelay,
        0
    },

    {                                  /* '<S1041>/TOP' */
        "PreAmpMedusaRoutingMap", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 24,
        Model_TranslationEngine64_MedusaPostHoligram_B.Value,
        0
    },

    {                                  /* '<S1049>/TOP' */
        "PreAmpNearWiggleCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2048,
        Model_TranslationEngine64_B.Value_dv,
        0
    },

    {                                  /* '<S1050>/TOP' */
        "PreAmpNearDelay", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_phe,
        0
    },

    {                                  /* '<S1068>/TOP' */
        "PreAmpFadeControlBoostDisable", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_m2,
        0
    },

    {                                  /* '<S1069>/TOP' */
        "PreAmpFadeControlEnableSilentExtreme", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_le,
        0
    },

    {                                  /* '<S1070>/TOPDb' */
        "PreAmpFadeControlTableDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 30,
        Model_TranslationEngine64_B.tableDb,
        0
    },

    {                                  /* '<S1070>/TOPIndex' */
        "PreAmpFadeControlTableIdx", 0,
        TSS_UINT32, TSS_SINGLE, "uint32", "single", 0, 30,
        Model_TranslationEngine64_B.tableIdx,
        0
    },

    {                                  /* '<S1071>/TOP' */
        "PreAmpFadeControloffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_of,
        0
    },

    {                                  /* '<S1072>/TOP' */
        "PreAmpFadeControlRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mg,
        0
    },

    {                                  /* '<S1092>/TOP_ChanRampMap' */
        "PreAmpFadeRamperDRChannelToRamperMap", 0,
        TSS_INT32, TSS_SINGLE, "int32", "single", 0, 30,
        Model_TranslationEngine64_B.ChanRampMap_a,
        0
    },

    {                                  /* '<S1092>/TOP' */
        "PreAmpFadeRamperDRTOPFilterCoefficients", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_B.sf_Filter_Coeffs_Translation.FilterCoeffs,
        0
    },

    {                                  /* '<S1099>/TOP_ChanRampMap' */
        "PreAmpFadeRamperFRChannelToRamperMap", 0,
        TSS_INT32, TSS_SINGLE, "int32", "single", 0, 22,
        Model_TranslationEngine64_B.ChanRampMap_j,
        0
    },

    {                                  /* '<S1099>/TOP' */
        "PreAmpFadeRamperFRTOPFilterCoefficients", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_B.sf_Filter_Coeffs_Translation_dm.FilterCoeffs,
        0
    },

    {                                  /* '<S1107>/TOP' */
        "PreAmpMuteControlRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ey,
        0
    },

    {                                  /* '<S1112>/TOP' */
        "PreAmpSleepingBeautyDRChannelToRamperMap", 0,
        TSS_INT32, TSS_SINGLE, "int32", "single", 0, 30,
        Model_TranslationEngine64_B.ChanRampMap_c,
        0
    },

    {                                  /* '<S1114>/TOP' */
        "PreAmpSleepingBeautyDROffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_cj,
        0
    },

    {                                  /* '<S1115>/TOP' */
        "PreAmpSleepingBeautyDRRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_k4,
        0
    },

    {                                  /* '<S1116>/TOP' */
        "PreAmpSleepingBeautyDRMutesBass", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_di,
        0
    },

    {                                  /* '<S1117>/TOP' */
        "PreAmpSleepingBeautyDRTableDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 30,
        Model_TranslationEngine64_B.sf_translation_h.tableDb,
        0
    },

    {                                  /* '<S1117>/TOP1' */
        "PreAmpSleepingBeautyDRTableIdx", 0,
        TSS_UINT32, TSS_SINGLE, "uint32", "single", 0, 30,
        Model_TranslationEngine64_B.sf_translation_h.tableIdx,
        0
    },

    {                                  /* '<S1135>/TOP' */
        "PreAmpSleepingBeautyFRChannelToRamperMap", 0,
        TSS_INT32, TSS_SINGLE, "int32", "single", 0, 22,
        Model_TranslationEngine64_B.ChanRampMap_i,
        0
    },

    {                                  /* '<S1137>/TOP' */
        "PreAmpSleepingBeautyFROffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_p1,
        0
    },

    {                                  /* '<S1138>/TOP' */
        "PreAmpSleepingBeautyFRRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ph,
        0
    },

    {                                  /* '<S1139>/TOP' */
        "PreAmpSleepingBeautyFRMutesBass", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_il,
        0
    },

    {                                  /* '<S1140>/TOP' */
        "PreAmpSleepingBeautyFRTableDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 30,
        Model_TranslationEngine64_B.sf_translation_am.tableDb,
        0
    },

    {                                  /* '<S1140>/TOP1' */
        "PreAmpSleepingBeautyFRTableIdx", 0,
        TSS_UINT32, TSS_SINGLE, "uint32", "single", 0, 30,
        Model_TranslationEngine64_B.sf_translation_am.tableIdx,
        0
    },

    {                                  /* '<S1164>/TOP' */
        "PreAmpVLSXtalkCancellationIIRPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 16,
        Model_TranslationEngine64_VLS_B.PoolNumStages,
        0
    },

    {                                  /* '<S1164>/TOP1' */
        "PreAmpVLSXtalkCancellationIIRpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 976,
        Model_TranslationEngine64_VLS_B.PoolCoeffs,
        0
    },

    {                                  /* '<S1162>/TOP' */
        "PreAmpVLSXtalkCancellationDelay", 0,
        TSS_DOUBLE, TSS_INT32, "double", "int32", 0, 16,
        Model_TranslationEngine64_VLS_B.Value,
        0
    },

    {                                  /* '<S1159>/TOP' */
        "PreAmpVLSGenerationDrvFIRCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 5760,
        Model_TranslationEngine64_VLS_B.sf_translation.FIRCoeffs,
        0
    },

    {                                  /* '<S1159>/TOP2' */
        "PreAmpVLSGenerationDrvPaddedFilterLengths", 0,
        TSS_DOUBLE, TSS_UINT32, "double", "uint32", 0, 20,
        Model_TranslationEngine64_VLS_B.sf_translation.PaddedFIRLengths,
        0
    },

    {                                  /* '<S1160>/TOP' */
        "PreAmpVLSGenerationPaxFIRCoeffs", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 5760,
        Model_TranslationEngine64_VLS_B.sf_translation_pa.FIRCoeffs,
        0
    },

    {                                  /* '<S1160>/TOP2' */
        "PreAmpVLSGenerationPaxPaddedFilterLengths", 0,
        TSS_DOUBLE, TSS_UINT32, "double", "uint32", 0, 20,
        Model_TranslationEngine64_VLS_B.sf_translation_pa.PaddedFIRLengths,
        0
    },

    {                                  /* '<S1178>/BoostCoeffs' */
        "PreAmpBassBoostCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1.FilterCoeffs,
        0
    },

    {                                  /* '<S1178>/CutCoeffs' */
        "PreAmpBassCutCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_o.FilterCoeffs,
        0
    },

    {                                  /* '<S1178>/Boost_dB TOP' */
        "PreAmpBassBoostMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3.maxOut,
        0
    },

    {                                  /* '<S1178>/Cut_dB TOP' */
        "PreAmpBassCutMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_k.maxOut,
        0
    },

    {                                  /* '<S1186>/TOP' */
        "PreAmpBassOffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_mo,
        0
    },

    {                                  /* '<S1187>/TOP' */
        "PreAmpBassramptime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_mu,
        0
    },

    {                                  /* '<S1188>/TOP' */
        "PreAmpBassScale", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_a,
        0
    },

    {                                  /* '<S1179>/BoostCoeffs' */
        "PreAmpMidrangeBoostCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 5,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1_n.FilterCoeffs,
        0
    },

    {                                  /* '<S1179>/CutCoeffs' */
        "PreAmpMidrangeCutCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 5,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_la.FilterCoeffs,
        0
    },

    {                                  /* '<S1179>/Boost_dB TOP' */
        "PreAmpMidrangeBoostMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3_lh.maxOut,
        0
    },

    {                                  /* '<S1179>/Cut_dB TOP' */
        "PreAmpMidrangeCutMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_bf.maxOut,
        0
    },

    {                                  /* '<S1213>/TOP' */
        "PreAmpMidrangeOffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_j,
        0
    },

    {                                  /* '<S1214>/TOP' */
        "PreAmpMidrangeRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_f,
        0
    },

    {                                  /* '<S1215>/TOP' */
        "PreAmpMidrangeScale", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_b,
        0
    },

    {                                  /* '<S1239>/TOP' */
        "PreAmpA", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.lingain,
        0
    },

    {                                  /* '<S1247>/TOP' */
        "PreAmpG", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_h,
        0
    },

    {                                  /* '<S1252>/TOP' */
        "PreAmpAnnPred", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation.TOP1,
        0
    },

    {                                  /* '<S1253>/attack' */
        "PreAmpLimiterattack", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 32,
        Model_TranslationEngine64_PreAmpPart1_B.attack,
        0
    },

    {                                  /* '<S1253>/decay' */
        "PreAmpLimiterdecay", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 32,
        Model_TranslationEngine64_PreAmpPart1_B.y_e,
        0
    },

    {                                  /* '<S1253>/maxAttack' */
        "PreAmpLimitermaxAttack", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 32,
        Model_TranslationEngine64_PreAmpPart1_B.y,
        0
    },

    {                                  /* '<S1254>/TOP' */
        "PreAmpOffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation_jf.TOP1,
        0
    },

    {                                  /* '<S1255>/TOP' */
        "PreAmpUpperThreshold", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation_e1.TOP1,
        0
    },

    {                                  /* '<S1181>/BoostCoeffs' */
        "PreAmpTrebleBoostCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1_i.FilterCoeffs,
        0
    },

    {                                  /* '<S1181>/CutCoeffs' */
        "PreAmpTrebleCutCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 3,
        Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_ej.FilterCoeffs,
        0
    },

    {                                  /* '<S1181>/Boost_dB TOP' */
        "PreAmpTrebleBoostMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3_it.maxOut,
        0
    },

    {                                  /* '<S1181>/Cut_dB TOP' */
        "PreAmpTrebleCutMaximum_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_kk4.maxOut,
        0
    },

    {                                  /* '<S1278>/TOP' */
        "PreAmpTrebleOffset", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_n,
        0
    },

    {                                  /* '<S1279>/TOP' */
        "PreAmpTrebleramptime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value_m,
        0
    },

    {                                  /* '<S1280>/TOP' */
        "PreAmpTrebleScale", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PreAmpPart1_B.Value,
        0
    },

    {                                  /* '<S1313>/TOP' */
        "NearDr_PooliirPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 7,
        Model_TranslationEngine64_B.PoolNumStages_j4,
        0
    },

    {                                  /* '<S1313>/TOP1' */
        "NearDr_PooliirpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 407,
        Model_TranslationEngine64_B.PoolCoeffs_b,
        0
    },

    {                                  /* '<S1312>/TOP' */
        "NearDr_EqDelays", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 7,
        Model_TranslationEngine64_B.sf_Translation_p.eqdelays,
        0
    },

    {                                  /* '<S1323>/TOP' */
        "NearDr_PoolIirTunablePooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 4,
        Model_TranslationEngine64_B.sf_Translation_h.PoolNumStages,
        0
    },

    {                                  /* '<S1323>/TOP1' */
        "NearDr_PoolIirTunablepooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 404,
        Model_TranslationEngine64_B.sf_Translation_h.PoolCoeffs,
        0
    },

    {                                  /* '<S1322>/TOP' */
        "NearDr_eqdelays", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 4,
        Model_TranslationEngine64_B.sf_Translation_e.eqdelays,
        0
    },

    {                                  /* '<S1331>/TOP' */
        "NearDr_RouterOutMap", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 18,
        Model_TranslationEngine64_B.sf_TrivialTranslation_p.OutMap,
        0
    },

    {                                  /* '<S1335>/TOP' */
        "NearDr_mix", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 875,
        Model_TranslationEngine64_B.mix_j,
        0
    },

    {                                  /* '<S1350>/TOP' */
        "NearFr_PooliirPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 5,
        Model_TranslationEngine64_B.PoolNumStages_j,
        0
    },

    {                                  /* '<S1350>/TOP1' */
        "NearFr_PooliirpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 405,
        Model_TranslationEngine64_B.PoolCoeffs_l,
        0
    },

    {                                  /* '<S1349>/TOP' */
        "NearFr_EqDelays", 0,
        TSS_SINGLE, TSS_INT32, "single", "int32", 0, 7,
        Model_TranslationEngine64_B.sf_Translation_pmq.eqdelays,
        0
    },

    {                                  /* '<S1360>/TOP' */
        "NearFr_PoolIirTunablePooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 4,
        Model_TranslationEngine64_B.sf_Translation_pii.PoolNumStages,
        0
    },

    {                                  /* '<S1360>/TOP1' */
        "NearFr_PoolIirTunablepooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 404,
        Model_TranslationEngine64_B.sf_Translation_pii.PoolCoeffs,
        0
    },

    {                                  /* '<S1359>/TOP' */
        "NearFr_eqdelays", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 4,
        Model_TranslationEngine64_B.sf_Translation_ir1.eqdelays,
        0
    },

    {                                  /* '<S1368>/TOP' */
        "NearFr_RouterOutMap", 0,
        TSS_INT32, TSS_INT32, "int32", "int32", 0, 18,
        Model_TranslationEngine64_B.sf_TrivialTranslation_nx.OutMap,
        0
    },

    {                                  /* '<S1372>/TOP' */
        "NearFr_mix", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 225,
        Model_TranslationEngine64_B.mix,
        0
    },

    {                                  /* '<S1380>/TOP' */
        "NearRampDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_nc,
        0
    },

    {                                  /* '<S1385>/TOP' */
        "NearCoefficients", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 164,
        Model_TranslationEngine64_B.LRHighPassCoeffs,
        0
    },

    {                                  /* '<S1385>/TOP1' */
        "NearNumStages", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 4,
        Model_TranslationEngine64_B.LRHighPassNumStages,
        0
    },

    {                                  /* '<S1401>/TOP' */
        "NearLevelDetectPreEmphasisShelfFilterPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 2,
        Model_TranslationEngine64_B.PoolNumStages,
        0
    },

    {                                  /* '<S1401>/TOP1' */
        "NearLevelDetectPreEmphasisShelfFilterpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 10,
        Model_TranslationEngine64_B.PoolCoeffs,
        0
    },

    {                                  /* '<S1400>/TOP' */
        "NearLevelDetectSysMaxDbspl", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_bu,
        0
    },

    {                                  /* '<S1409>/TOP' */
        "NearAnn1LevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_p.y,
        0
    },

    {                                  /* '<S1410>/TOP' */
        "NearAnn1LevelDetecthold_margin_db", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive_nx.TOP,
        0
    },

    {                                  /* '<S1411>/TOP' */
        "NearAnn1LevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_g.y,
        0
    },

    {                                  /* '<S1412>/TOP' */
        "NearAnn1LevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_m0,
        0
    },

    {                                  /* '<S1413>/TOP' */
        "NearAnn1LevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hz,
        0
    },

    {                                  /* '<S1414>/TOP' */
        "NearAnn1LevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_odu.y,
        0
    },

    {                                  /* '<S1435>/TOP' */
        "NearAnn2LevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_boz.y,
        0
    },

    {                                  /* '<S1436>/TOP' */
        "NearAnn2LevelDetectHoldMarginDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive_fl.TOP,
        0
    },

    {                                  /* '<S1437>/TOP' */
        "NearAnn2LevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_onh.y,
        0
    },

    {                                  /* '<S1438>/TOP' */
        "NearAnn2LevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ai,
        0
    },

    {                                  /* '<S1439>/TOP' */
        "NearAnn2LevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hi,
        0
    },

    {                                  /* '<S1440>/TOP' */
        "NearAnn2LevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_f5y.y,
        0
    },

    {                                  /* '<S1461>/TOP' */
        "NearAnn3LevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_gx3.y,
        0
    },

    {                                  /* '<S1462>/TOP' */
        "NearAnn3LevelDetectHoldMarginDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive_bm.TOP,
        0
    },

    {                                  /* '<S1463>/TOP' */
        "NearAnn3LevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_ai.y,
        0
    },

    {                                  /* '<S1464>/TOP' */
        "NearAnn3LevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hm,
        0
    },

    {                                  /* '<S1465>/TOP' */
        "NearAnn3LevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ar,
        0
    },

    {                                  /* '<S1466>/TOP' */
        "NearAnn3LevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_hk.y,
        0
    },

    {                                  /* '<S1487>/TOP' */
        "NearAnn4LevelDetectFastDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_peu.y,
        0
    },

    {                                  /* '<S1488>/TOP' */
        "NearAnn4LevelDetectHoldMarginDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_SetPositive_jq.TOP,
        0
    },

    {                                  /* '<S1489>/TOP' */
        "NearAnn4LevelDetectHoldTimeSamples", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_ow4w.y,
        0
    },

    {                                  /* '<S1490>/TOP' */
        "NearAnn4LevelDetectMaxVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ng,
        0
    },

    {                                  /* '<S1491>/TOP' */
        "NearAnn4LevelDetectMinVolumeDb", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hy,
        0
    },

    {                                  /* '<S1492>/TOP' */
        "NearAnn4LevelDetectSlowDecayDbPerSample", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 1,
        &Model_TranslationEngine64_B.sf_sec2samples_jtq.y,
        0
    },

    {                                  /* '<S1517>/TOP' */
        "NearAnn1Ann1NonEntGainCalcVncThresh", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_gs,
        0
    },

    {                                  /* '<S1518>/TOP' */
        "NearAnn1Ann1NonEntGainCalcVncSlope", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ig,
        0
    },

    {                                  /* '<S1519>/TOP' */
        "NearAnn1Ann1NonEntGainCalcMaxBoost", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ob,
        0
    },

    {                                  /* '<S1520>/TOP' */
        "NearAnn1Ann1NonEntGainCalcNoiseOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_md,
        0
    },

    {                                  /* '<S1521>/TOP' */
        "NearAnn1Ann1NonEntGainCalcNoiseOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_aye,
        0
    },

    {                                  /* '<S1522>/TOP' */
        "NearAnn1Ann1NonEntGainCalcBoostOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ay,
        0
    },

    {                                  /* '<S1523>/TOP' */
        "NearAnn1Ann1NonEntGainCalcBoostOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ky,
        0
    },

    {                                  /* '<S1524>/TOP' */
        "NearAnn1Ann1NonEntGainCalcVncEnableTuneVar", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_i0,
        0
    },

    {                                  /* '<S1525>/den' */
        "NearAnn1Ann1NonEntGainCalcDen", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_g.Den,
        0
    },

    {                                  /* '<S1525>/num' */
        "NearAnn1Ann1NonEntGainCalcNum", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_g.Num,
        0
    },

    {                                  /* '<S1562>/TOP' */
        "NearAnn1Ann1NonEntGainCalcMinVncSignal", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hb,
        0
    },

    {                                  /* '<S1563>/TOP' */
        "NearAnn1Ann1NonEntGainCalcMaxSpl", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_e1,
        0
    },

    {                                  /* '<S1573>/den' */
        "NearAnn1Ann1NonEntVncAppliedden", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_lp.Den,
        0
    },

    {                                  /* '<S1573>/num' */
        "NearAnn1Ann1NonEntVncAppliedNum", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_lp.Num,
        0
    },

    {                                  /* '<S1578>/TOP' */
        "NearAnn1Ann1MuteRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ci,
        0
    },

    {                                  /* '<S1516>/TOP_GainDB' */
        "NearAnn1Ann1VolumeTable_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation.Table_dB,
        0
    },

    {                                  /* '<S1516>/TOP_Index' */
        "NearAnn1Ann1VolumeTable_Idx", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation.Table_Idx,
        0
    },

    {                                  /* '<S1584>/TOP' */
        "NearAnn1Ann1VolumeRampRate", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_aw,
        0
    },

    {                                  /* '<S1585>/TOP' */
        "NearAnn1Ann1VolumeRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_br,
        0
    },

    {                                  /* '<S1600>/TOP' */
        "NearAnn2Ann2NonEntGainCalcVncThresh", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_nt,
        0
    },

    {                                  /* '<S1601>/TOP' */
        "NearAnn2Ann2NonEntGainCalcVncSlope", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hp,
        0
    },

    {                                  /* '<S1602>/TOP' */
        "NearAnn2Ann2NonEntGainCalcMaxBoost", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ok,
        0
    },

    {                                  /* '<S1603>/TOP' */
        "NearAnn2Ann2NonEntGainCalcNoiseOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_je,
        0
    },

    {                                  /* '<S1604>/TOP' */
        "NearAnn2Ann2NonEntGainCalcNoiseOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_m5,
        0
    },

    {                                  /* '<S1605>/TOP' */
        "NearAnn2Ann2NonEntGainCalcBoostOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_bv,
        0
    },

    {                                  /* '<S1606>/TOP' */
        "NearAnn2Ann2NonEntGainCalcBoostOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_o2,
        0
    },

    {                                  /* '<S1607>/TOP' */
        "NearAnn2Ann2NonEntGainCalcVncEnableTuneVar", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_fq,
        0
    },

    {                                  /* '<S1608>/den' */
        "NearAnn2Ann2NonEntGainCalcDen", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_bk.Den,
        0
    },

    {                                  /* '<S1608>/num' */
        "NearAnn2Ann2NonEntGainCalcNum", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_bk.Num,
        0
    },

    {                                  /* '<S1645>/TOP' */
        "NearAnn2Ann2NonEntGainCalcMinVncSignal", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hs,
        0
    },

    {                                  /* '<S1646>/TOP' */
        "NearAnn2Ann2NonEntGainCalcMaxSpl", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_g0,
        0
    },

    {                                  /* '<S1656>/den' */
        "NearAnn2Ann2NonEntVncAppliedden", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_js2.Den,
        0
    },

    {                                  /* '<S1656>/num' */
        "NearAnn2Ann2NonEntVncAppliedNum", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_js2.Num,
        0
    },

    {                                  /* '<S1661>/TOP' */
        "NearAnn2Ann2MuteRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_hg,
        0
    },

    {                                  /* '<S1599>/TOP_GainDB' */
        "NearAnn2Ann2VolumeTable_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_hx.Table_dB,
        0
    },

    {                                  /* '<S1599>/TOP_Index' */
        "NearAnn2Ann2VolumeTable_Idx", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_hx.Table_Idx,
        0
    },

    {                                  /* '<S1667>/TOP' */
        "NearAnn2Ann2VolumeRampRate", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_bw,
        0
    },

    {                                  /* '<S1668>/TOP' */
        "NearAnn2Ann2VolumeRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_au,
        0
    },

    {                                  /* '<S1683>/TOP' */
        "NearAnn3Ann3NonEntGainCalcVncThresh", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_j5,
        0
    },

    {                                  /* '<S1684>/TOP' */
        "NearAnn3Ann3NonEntGainCalcVncSlope", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_h,
        0
    },

    {                                  /* '<S1685>/TOP' */
        "NearAnn3Ann3NonEntGainCalcMaxBoost", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_d,
        0
    },

    {                                  /* '<S1686>/TOP' */
        "NearAnn3Ann3NonEntGainCalcNoiseOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_l,
        0
    },

    {                                  /* '<S1687>/TOP' */
        "NearAnn3Ann3NonEntGainCalcNoiseOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_io2,
        0
    },

    {                                  /* '<S1688>/TOP' */
        "NearAnn3Ann3NonEntGainCalcBoostOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_g,
        0
    },

    {                                  /* '<S1689>/TOP' */
        "NearAnn3Ann3NonEntGainCalcBoostOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_io,
        0
    },

    {                                  /* '<S1690>/TOP' */
        "NearAnn3Ann3NonEntGainCalcVncEnableTuneVar", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_pw,
        0
    },

    {                                  /* '<S1691>/den' */
        "NearAnn3Ann3NonEntGainCalcDen", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_aa1.Den,
        0
    },

    {                                  /* '<S1691>/num' */
        "NearAnn3Ann3NonEntGainCalcNum", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_aa1.Num,
        0
    },

    {                                  /* '<S1728>/TOP' */
        "NearAnn3Ann3NonEntGainCalcMinVncSignal", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ks,
        0
    },

    {                                  /* '<S1729>/TOP' */
        "NearAnn3Ann3NonEntGainCalcMaxSpl", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_jp,
        0
    },

    {                                  /* '<S1739>/den' */
        "NearAnn3Ann3NonEntVncAppliedden", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_kj.Den,
        0
    },

    {                                  /* '<S1739>/num' */
        "NearAnn3Ann3NonEntVncAppliedNum", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_kj.Num,
        0
    },

    {                                  /* '<S1744>/TOP' */
        "NearAnn3Ann3MuteRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_n,
        0
    },

    {                                  /* '<S1682>/TOP_GainDB' */
        "NearAnn3Ann3VolumeTable_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_bl.Table_dB,
        0
    },

    {                                  /* '<S1682>/TOP_Index' */
        "NearAnn3Ann3VolumeTable_Idx", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_bl.Table_Idx,
        0
    },

    {                                  /* '<S1750>/TOP' */
        "NearAnn3Ann3VolumeRampRate", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_c,
        0
    },

    {                                  /* '<S1751>/TOP' */
        "NearAnn3Ann3VolumeRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_f,
        0
    },

    {                                  /* '<S1766>/TOP' */
        "NearAnn4Ann4NonEntGainCalcVncThresh", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_p,
        0
    },

    {                                  /* '<S1767>/TOP' */
        "NearAnn4Ann4NonEntGainCalcVncSlope", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ju,
        0
    },

    {                                  /* '<S1768>/TOP' */
        "NearAnn4Ann4NonEntGainCalcMaxBoost", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_ox,
        0
    },

    {                                  /* '<S1769>/TOP' */
        "NearAnn4Ann4NonEntGainCalcNoiseOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_er,
        0
    },

    {                                  /* '<S1770>/TOP' */
        "NearAnn4Ann4NonEntGainCalcNoiseOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_e,
        0
    },

    {                                  /* '<S1771>/TOP' */
        "NearAnn4Ann4NonEntGainCalcBoostOverRide", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_i,
        0
    },

    {                                  /* '<S1772>/TOP' */
        "NearAnn4Ann4NonEntGainCalcBoostOverRideFlag", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_j,
        0
    },

    {                                  /* '<S1773>/TOP' */
        "NearAnn4Ann4NonEntGainCalcVncEnableTuneVar", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mc,
        0
    },

    {                                  /* '<S1774>/den' */
        "NearAnn4Ann4NonEntGainCalcDen", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_ja.Den,
        0
    },

    {                                  /* '<S1774>/num' */
        "NearAnn4Ann4NonEntGainCalcNum", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 2,
        Model_TranslationEngine64_B.sf_translation_ja.Num,
        0
    },

    {                                  /* '<S1811>/TOP' */
        "NearAnn4Ann4NonEntGainCalcMinVncSignal", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_o,
        0
    },

    {                                  /* '<S1812>/TOP' */
        "NearAnn4Ann4NonEntGainCalcMaxSpl", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_b,
        0
    },

    {                                  /* '<S1822>/den' */
        "NearAnn4Ann4NonEntVncAppliedden", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_lhh.Den,
        0
    },

    {                                  /* '<S1822>/num' */
        "NearAnn4Ann4NonEntVncAppliedNum", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 2,
        Model_TranslationEngine64_B.sf_Translation_lhh.Num,
        0
    },

    {                                  /* '<S1827>/TOP' */
        "NearAnn4Ann4MuteRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_mu,
        0
    },

    {                                  /* '<S1765>/TOP_GainDB' */
        "NearAnn4Ann4VolumeTable_dB", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_bdp.Table_dB,
        0
    },

    {                                  /* '<S1765>/TOP_Index' */
        "NearAnn4Ann4VolumeTable_Idx", 0,
        TSS_UINT32, TSS_UINT32, "uint32", "uint32", 0, 16,
        Model_TranslationEngine64_B.sf_volumetabletranslation_bdp.Table_Idx,
        0
    },

    {                                  /* '<S1833>/TOP' */
        "NearAnn4Ann4VolumeRampRate", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_m,
        0
    },

    {                                  /* '<S1834>/TOP' */
        "NearAnn4Ann4VolumeRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_B.Value_a,
        0
    },

    {                                  /* '<S1850>/attack' */
        "PostProcessLimiterattack", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction3.attack,
        0
    },

    {                                  /* '<S1850>/attack1' */
        "PostProcessLimiterattack_low", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction5_h.attack,
        0
    },

    {                                  /* '<S1850>/decay' */
        "PostProcessLimiterdecay", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.y_b,
        0
    },

    {                                  /* '<S1850>/decay1' */
        "PostProcessLimiterdecay_low", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.y_j,
        0
    },

    {                                  /* '<S1850>/k1' */
        "PostProcessLimiterk1", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction3.k1,
        0
    },

    {                                  /* '<S1850>/k2' */
        "PostProcessLimiterk1_low", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction5_h.k1,
        0
    },

    {                                  /* '<S1850>/maxAttack' */
        "PostProcessLimitermaxAttack", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.y_n,
        0
    },

    {                                  /* '<S1850>/maxAttack1' */
        "PostProcessLimitermaxAttack_low", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 24,
        Model_TranslationEngine64_PostProcess_B.y,
        0
    },

    {                                  /* '<S1871>/TOP' */
        "PostProcessMuteRampTime", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.Value,
        0
    },

    {                                  /* '<S1876>/TOP' */
        "PostProcessPostLimiterEqPooliirNumStages", 0,
        TSS_INT32, TSS_UINT32, "int32", "uint32", 0, 24,
        Model_TranslationEngine64_PostProcess_B.PoolNumStages,
        0
    },

    {                                  /* '<S1876>/TOP1' */
        "PostProcessPostLimiterEqpooliirCoeffs", 0,
        TSS_SINGLE, TSS_SINGLE, "single", "single", 0, 536,
        Model_TranslationEngine64_PostProcess_B.PoolCoeffs,
        0
    },

    {                                  /* '<S1880>/p2 TOP' */
        "PostProcessSoftClipperp2", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.p2_e,
        0
    },

    {                                  /* '<S1880>/xmax TOP' */
        "PostProcessSoftClipperxmax", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.xmax_top_m,
        0
    },

    {                                  /* '<S1880>/xmin TOP' */
        "PostProcessSoftClipperxmin", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.xmin_top_c,
        0
    },

    {                                  /* '<S1880>/p2 TOP1' */
        "PostProcessSoftClipperp2_low", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.p2,
        0
    },

    {                                  /* '<S1880>/xmax TOP1' */
        "PostProcessSoftClipperxmax_low", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.xmax_top,
        0
    },

    {                                  /* '<S1880>/xmin TOP1' */
        "PostProcessSoftClipperxmin_low", 0,
        TSS_DOUBLE, TSS_SINGLE, "double", "single", 0, 1,
        &Model_TranslationEngine64_PostProcess_B.xmin_top,
        0
    },

    {                                  /* '<S1892>/TOP' */
        "TestRouterASDRouterEnableAux", 0,
        TSS_DOUBLE, TSS_INT32, "double", "int32", 0, 1,
        &Model_TranslationEngine64_B.Value_kc,
        0
    },

    {                                  /* '<S1897>/TOP' */
        "TestRouterASDRouterMainSelect", 0,
        TSS_DOUBLE, TSS_INT32, "double", "int32", 0, 24,
        Model_TranslationEngine64_B.Value_k,
        0
    },

    {                                  /* '<S1888>/TOP' */
        "TestRouterAuxSelect", 0,
        TSS_DOUBLE, TSS_INT32, "double", "int32", 0, 24,
        Model_TranslationEngine64_B.Value,
        0
    },
};

// Share table in a public interface for use by top-model
void* Model_TranslationEngine64_TOP_RcvTrans_table = TOP_RcvTrans_table;
int Model_TranslationEngine64_TOP_RcvTrans_table_count = sizeof
    (TOP_RcvTrans_table) / sizeof(TOP_RcvTrans_type);

// CAST_PRINT_STORE performs the cast, print, and store
// Assumed:srcArray,dstArray,numElem,buf,bufSize,srcFix.factor,failDetected
// Note that SRCPREFIX is preprended to source value evaluations
#define CAST_PRINT_STORE(STYPE,DTYPE,FMTSTR,SRCPREFIX) for (int index = 0; index < numElem; index++){ STYPE srcVal = ((STYPE *)srcArray)[index]; DTYPE dstVal = (srcFix.factor)? (DTYPE)((double)SRCPREFIX((srcVal)*srcFix.factor)):(DTYPE)(SRCPREFIX srcVal); if (bufSize > 1){ int used = snprintf(buf, bufSize, FMTSTR, dstVal); if (used <= 0) {used=0;failDetected=1;} bufSize -= used; buf += used; } if(dstArray)((DTYPE*)dstArray)[index]=dstVal; }

// SRC_DST_SWITCH is invoked by STYPE code and to then invoke CAST_PRINT_STORE by dstType id
// Assumed:dstType. Note that boolean type uses "!!" to convert to 0 or 1
#define SRC_DST_SWITCH(STYPE)          { switch (dstType) { case TSS_DOUBLE : {CAST_PRINT_STORE(STYPE,double ," %.17g",);break;} case TSS_SINGLE : {CAST_PRINT_STORE(STYPE,float ," %.9g" ,);break;} case TSS_INT8 : {CAST_PRINT_STORE(STYPE,int8_t ," %i" ,);break;} case TSS_UINT8 : {CAST_PRINT_STORE(STYPE,uint8_t ," %u" ,);break;} case TSS_INT16 : {CAST_PRINT_STORE(STYPE,int16_t ," %i" ,);break;} case TSS_UINT16 : {CAST_PRINT_STORE(STYPE,uint16_t ," %u" ,);break;} case TSS_INT32 : {CAST_PRINT_STORE(STYPE,int32_t ," %i" ,);break;} case TSS_UINT32 : {CAST_PRINT_STORE(STYPE,uint32_t ," %u" ,);break;} case TSS_BOOLEAN : {CAST_PRINT_STORE(STYPE,int8_t ," %i" ,!!);break;} default:{dstArray=0;CAST_PRINT_STORE(STYPE,double," %lf",);break;} } }

// This snippet of code shared by both TOP_MEX.c and TOP_MEX.tlc -- BUT
// due to TALARIA-104, the SS_INT8 etc types had to be changed to TSS_INT8
// to avoid conflicts. To keep generated code clean (even for translation engine)
// the TOP_MEX.c file includes mappings to the TSS_... names

// Decode fixed point data types
typedef struct FixedInfo_tag
{
    int unsupportedType;
    int isSigned;
    int intDTypeId;
    int totalBits;
    int fractionalBits;
    double factor;
}
FixedInfo;

static FixedInfo DecodeFixedTypeName(const char* typeName)
{
    FixedInfo info;
    char signedChar;
    info.unsupportedType = 0;
    info.factor = 0;
    int numFound = sscanf(typeName, "%cfix%d_En%d", &signedChar, &info.totalBits,
                          &info.fractionalBits);
    if (numFound == 3)
    {
        info.factor = 1.0/(1 << info.fractionalBits);
        info.isSigned = (signedChar == 's') ? 1 : 0;
        int bytesInInt = (info.totalBits + 7) / 8;
        switch (bytesInInt)
        {
          case 1:
            info.intDTypeId = (info.isSigned) ? TSS_INT8 : TSS_UINT8;
            break;

          case 2:
            info.intDTypeId = (info.isSigned) ? TSS_INT16 : TSS_UINT16;
            break;

          case 3:
            info.intDTypeId = (info.isSigned) ? TSS_INT32 : TSS_UINT32;
            break;

          case 4:
            info.intDTypeId = (info.isSigned) ? TSS_INT32 : TSS_UINT32;
            break;

          default:
            info.unsupportedType = 1;
            break;
        }
    }
    else
    {
        info.unsupportedType = 1;
    }

    return info;
}

static TOP_RcvTrans_type* GetTopRecord(TranslateEngineIterator topNumIn)
{
    // Validate input parameters
    if ((topNumIn.model < 0) || (topNumIn.model >= numTranslationRoots))
    {
        return 0;                      // model out of range
    }

    TranslationRoot* theRoot = translationRoots[topNumIn.model];
    if ((topNumIn.index < 0) || (topNumIn.index >= *theRoot->top_count))
    {
        return 0;                      // index out of range for specified model
    }

    TOP_RcvTrans_type* theTable = *(TOP_RcvTrans_type**)theRoot->top_table;
    return &theTable[topNumIn.index];
}

// Get the name of a TOP, or NULL if not found
const char* GetTopName(TranslateEngineIterator topNumberIn)
{
    const char* theName = 0;
    TOP_RcvTrans_type* recordIn = GetTopRecord(topNumberIn);
    if (recordIn)
    {
        theName = recordIn->top_name;
    }

    return theName;
}

// Dump the translated value to provided buffer & updating sightings
// Returns number of chars filled in buffer or negative if buffer too small
int DumpTranslatedValue(TranslateEngineIterator rcvTransNumberIn, char
                        * bufferInOut,
                        int bufferSizeIn)
{
    int failDetected = 0;
    TOP_RcvTrans_type* recordIn = GetTopRecord(rcvTransNumberIn);
    if (!recordIn)
    {
        return 0;                      // Top not found
    }

    // Remember how many time this TOP has been encountered
    recordIn->top_sightings_count++;

    // Setup variables for the nested switch macros:
    int srcType = recordIn->top_in_dtype_id;
    int dstType = recordIn->top_out_dtype_id;
    void * srcArray = recordIn->top_value_src_ptr;
    void * dstArray = recordIn->top_value_dst_ptr;
    int numElem = recordIn->top_element_count * (1 + recordIn->top_is_complex);
    char* buf = bufferInOut;
    int bufSize = bufferSizeIn;
    FixedInfo srcFix = DecodeFixedTypeName(recordIn->top_in_dtype_name);
    if (srcFix.factor)
    {
        // When decoding a fixed point type, set the srcType to the
        // integer format of the data. Then... the srcfix.factor will
        // be used to convert to floating point
        srcType = srcFix.intDTypeId;
    }

    // Start with the TOP name and datatype
    int nameChars = snprintf(buf, bufSize, "%s %s",
        recordIn->top_name, recordIn->top_out_dtype_name);
    if (nameChars <= 0)
    {
        // Older implementations of snprintf only give failure
        // (instead of indicating how many bytes would be needed)
        nameChars = 0;
        failDetected = 1;
    }

    bufSize -= nameChars;
    buf += nameChars;
    switch (srcType)
    {
      case TSS_DOUBLE:
        SRC_DST_SWITCH(double);
        break;

      case TSS_SINGLE:
        SRC_DST_SWITCH(float);
        break;

      case TSS_INT8:
        SRC_DST_SWITCH(int8_T);
        break;

      case TSS_UINT8:
        SRC_DST_SWITCH(uint8_T);
        break;

      case TSS_INT16:
        SRC_DST_SWITCH(int16_T);
        break;

      case TSS_UINT16:
        SRC_DST_SWITCH(uint16_T);
        break;

      case TSS_INT32:
        SRC_DST_SWITCH(int32_T);
        break;

      case TSS_UINT32:
        SRC_DST_SWITCH(uint32_T);
        break;

      case TSS_BOOLEAN:
        SRC_DST_SWITCH(int8_T);
        break;
    }

    return failDetected ? (-1) : (bufferSizeIn - bufSize);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
