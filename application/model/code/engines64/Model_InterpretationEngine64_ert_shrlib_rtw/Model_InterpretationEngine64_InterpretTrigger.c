/*
 * File: Model_InterpretationEngine64_InterpretTrigger.c
 *
 * Code generated for Simulink model 'Model_InterpretationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:16:14 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdint.h>
#include "Model_InterpretationEngine64_InterpretTrigger.h"
#include "Model_InterpretationEngine64_StateVar.h"
#include "Model_InterpretationEngine64_TSP_Interpret.h"
#include "Model_InterpretationEngine64_ModelCount.h"
#include <stdio.h>                     // for vsnprintf
#include <string.h>                    // for strncpy
#include <stdarg.h>                    // for variadic args (va_start)

// Interpretation table record
typedef void (*InterpretationFunc)(void);
typedef struct InterpretationRecord_tag
{
    int requested_state_vars;       // "dirty flag" counting requested StateVars
    InterpretationFunc interpretation_func;// interpretation function
    int tsp_count;           // indicates how many TSPs feed this interpretation
    enum TSPNumber *tsps;      // array of TSP IDs that feed this interpretation
    int stateVar_count;
          // indicates how many StateVars receive value from this interpretation
    enum StateVarNumber *stateVars;
    // array of StateVar numbers that receive values from this interpretation
}
InterpretationRecord_type;

// Interpretation numbers local to this model:
enum TSPNumber
{
    ID_TSP_PreAmpAudiopilotHvacDbspl,  /* '<S13>/TSP' */
    ID_TSP_PreAmpAudiopilotVehicleSpeed,/* '<S14>/TSP' */
    ID_TSP_PreAmpAudiopilotAudiopilotBassBoostDb,/* '<S25>/TSP' */
    ID_TSP_PreAmpAudiopilotAudiopilotMidrangeBoostDb,/* '<S26>/TSP' */
    ID_TSP_PreAmpAudiopilotAudiopilotTrebleBoostDb,/* '<S27>/TSP' */
    ID_TSP_PreAmpAudiopilotDyneqBassBoostDb,/* '<S28>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoiseDbspl,/* '<S29>/TSP' */
    ID_TSP_PreAmpAudiopilotIgnoreMicFlag,/* '<S30>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseDbspl,/* '<S31>/TSP' */
    ID_TSP_PreAmpAudiopilotNoiseRatio, /* '<S32>/TSP' */
    ID_TSP_PreAmpAudiopilotTotalBassBoostDb,/* '<S33>/TSP' */
    ID_TSP_PreAmpAudiopilotWbNoiseDbspl,/* '<S34>/TSP' */
    ID_TSP_PreAmpAudiopilotAudiopilotBoostGain,/* '<S75>/TSP' */
    ID_TSP_PreAmpAudiopilotDyneqBoostGain,/* '<S76>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoiseMicPsdLevel,/* '<S93>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoisePowerSpectralDensity,/* '<S92>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness,/* '<S106>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoiseImpulseRejectionPmin,/* '<S105>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoisePostSlew,/* '<S102>/TSP' */
    ID_TSP_PreAmpAudiopilotHfNoisePreSlew,/* '<S103>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut,/* '<S132>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef,/* '<S133>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance,/* '<S134>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance,/* '<S135>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance,/* '<S136>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance,/* '<S137>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseMicLevel,/* '<S124>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseMicOut,/* '<S125>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseMusicOut,/* '<S126>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseNoiseOut,/* '<S127>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoisePostSlew,/* '<S128>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoisePreSlew,/* '<S129>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoisePreSpeedBound,/* '<S130>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax,/* '<S186>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin,/* '<S187>/TSP' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsFlag,/* '<S188>/TSP' */
    ID_TSP_PreAmpAudiopilotRatioPostSlew,/* '<S201>/TSP' */
    ID_TSP_PreAmpAudiopilotRatioPreSlew,/* '<S202>/TSP' */
    ID_TSP_PreAmpAudiopilotRatioUpdateFlag,/* '<S203>/TSP' */
    ID_TSP_PreAmpLevelWatchAudiopilotEnvDb,/* '<S219>/TSP' */
    ID_TSP_PreAmpLevelWatchAudiopilotLevelDbspl,/* '<S220>/TSP' */
    ID_TSP_PreAmpLevelWatchDyneqEnvDb, /* '<S230>/TSP' */
    ID_TSP_PreAmpLevelWatchDyneqLevelDbspl,/* '<S231>/TSP' */
    ID_TSP_PreAmpMedusaDummyState,     /* '<S245>/TSP' */
    ID_TSP_PreAmpMedusaMonoDetectorLevelCenter,/* '<S254>/TSP' */
    ID_TSP_PreAmpMedusaMonoDetectorIsStereo,/* '<S252>/TSP' */
    ID_TSP_PreAmpMedusaMonoDetectorIsActive,/* '<S253>/TSP' */
    ID_TSP_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB,/* '<S275>/TSP' */
    ID_TSP_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB,/* '<S282>/TSP' */
    ID_TSP_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB,/* '<S289>/TSP' */
    ID_TSP_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB,/* '<S296>/TSP' */
    ID_TSP_PostProcessEnergyLimiterComputedEnergy,/* '<S305>/TSP' */
    ID_TSP_PostProcessEnergyLimiterCurGain,/* '<S306>/TSP' */
    ID_TSP_PostProcessEnergyLimiterEnergyThreshold,/* '<S307>/TSP' */
    ID_TSP_PostProcessEnergyLimiterCurState,/* '<S308>/TSP' */
    ID_TSP_PostProcessEnergyLimiterEnableFlag,/* '<S309>/TSP' */
    NUM_TSP_NUMBERS
};

enum StateVarNumber
{
    ID_StateVar_PreAmpAudiopilotHvacDbspl,/* '<S13>/StateVar' */
    ID_StateVar_PreAmpAudiopilotVehicleSpeed,/* '<S14>/StateVar' */
    ID_StateVar_PreAmpAudiopilotAudiopilotBassBoostDb,/* '<S25>/StateVar' */
    ID_StateVar_PreAmpAudiopilotAudiopilotMidrangeBoostDb,/* '<S26>/StateVar' */
    ID_StateVar_PreAmpAudiopilotAudiopilotTrebleBoostDb,/* '<S27>/StateVar' */
    ID_StateVar_PreAmpAudiopilotDyneqBassBoostDb,/* '<S28>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoiseDbspl,/* '<S29>/StateVar' */
    ID_StateVar_PreAmpAudiopilotIgnoreMicFlag,/* '<S30>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseDbspl,/* '<S31>/StateVar' */
    ID_StateVar_PreAmpAudiopilotNoiseRatio,/* '<S32>/StateVar' */
    ID_StateVar_PreAmpAudiopilotTotalBassBoostDb,/* '<S33>/StateVar' */
    ID_StateVar_PreAmpAudiopilotWbNoiseDbspl,/* '<S34>/StateVar' */
    ID_StateVar_PreAmpAudiopilotAudiopilotBoostGain,/* '<S75>/StateVar' */
    ID_StateVar_PreAmpAudiopilotDyneqBoostGain,/* '<S76>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoiseMicPsdLevel,/* '<S93>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoiseNoisePsdLevel,/* '<S92>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness,/* '<S106>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoiseImpulseRejectionPmin,/* '<S105>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoisePostSlew,/* '<S102>/StateVar' */
    ID_StateVar_PreAmpAudiopilotHfNoisePreSlew,/* '<S103>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut,/* '<S132>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionGammaTauS,/* '<S133>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceDb,/* '<S134>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceDb,/* '<S135>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceDb,/* '<S136>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVarianceDb,/* '<S137>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMicLevel,/* '<S124>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMicOut,/* '<S125>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMusicOut,/* '<S126>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseNoiseOut,/* '<S127>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoisePostSlew,/* '<S128>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoisePreSlew,/* '<S129>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoisePreSpeedBound,/* '<S130>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax,/* '<S186>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin,/* '<S187>/StateVar' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsFlag,/* '<S188>/StateVar' */
    ID_StateVar_PreAmpAudiopilotRatioPostSlew,/* '<S201>/StateVar' */
    ID_StateVar_PreAmpAudiopilotRatioPreSlew,/* '<S202>/StateVar' */
    ID_StateVar_PreAmpAudiopilotRatioUpdateFlag,/* '<S203>/StateVar' */
    ID_StateVar_PreAmpLevelWatchAudiopilotEnvDb,/* '<S219>/StateVar' */
    ID_StateVar_PreAmpLevelWatchAudiopilotLevelDbspl,/* '<S220>/StateVar' */
    ID_StateVar_PreAmpLevelWatchDyneqEnvDb,/* '<S230>/StateVar' */
    ID_StateVar_PreAmpLevelWatchDyneqLevelDbspl,/* '<S231>/StateVar' */
    ID_StateVar_PreAmpMedusaDummyState,/* '<S245>/StateVar' */
    ID_StateVar_PreAmpMedusaMonoDetectorLevelCenter,/* '<S254>/StateVar' */
    ID_StateVar_PreAmpMedusaMonoDetectorIsStereo,/* '<S252>/StateVar' */
    ID_StateVar_PreAmpMedusaMonoDetectorIsActive,/* '<S253>/StateVar' */
    ID_StateVar_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB,/* '<S275>/StateVar' */
    ID_StateVar_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB,/* '<S282>/StateVar' */
    ID_StateVar_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB,/* '<S289>/StateVar' */
    ID_StateVar_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB,/* '<S296>/StateVar' */
    ID_StateVar_PostProcessEnergyLimiterComputedEnergy,/* '<S305>/StateVar' */
    ID_StateVar_PostProcessEnergyLimiterCurGain,/* '<S306>/StateVar' */
    ID_StateVar_PostProcessEnergyLimiterEnergyThreshold,/* '<S307>/StateVar' */
    ID_StateVar_PostProcessEnergyLimiterCurState,/* '<S308>/StateVar' */
    ID_StateVar_PostProcessEnergyLimiterEnableFlag,/* '<S309>/StateVar' */
    NUM_STATEVAR_NUMBERS
};

// ----- Interpretation functions (generated in the model):
extern void
/* [PostProcessEnergyLimiterComputedEnergy]-->[PostProcessEnergyLimiterComputedEnergy]*/
    Model_InterpretationEngine64_ifunc_em(void);
                        /* Interpretation_Model_662_27_30:'<S311>/S-Function' */
extern void
      /* [PostProcessEnergyLimiterCurGain]-->[PostProcessEnergyLimiterCurGain]*/
    Model_InterpretationEngine64_ifunc_lv(void);
                        /* Interpretation_Model_663_27_30:'<S315>/S-Function' */
extern void
/* [PostProcessEnergyLimiterEnergyThreshold]-->[PostProcessEnergyLimiterEnergyThreshold]*/
    Model_InterpretationEngine64_ifunc_jl(void);
                        /* Interpretation_Model_664_27_30:'<S319>/S-Function' */
extern void
    /* [PostProcessEnergyLimiterCurState]-->[PostProcessEnergyLimiterCurState]*/
    Model_InterpretationEngine64_ifunc_jt(void);
                        /* Interpretation_Model_665_27_30:'<S323>/S-Function' */
extern void
/* [PostProcessEnergyLimiterEnableFlag]-->[PostProcessEnergyLimiterEnableFlag]*/
    Model_InterpretationEngine64_ifunc_cj(void);
                        /* Interpretation_Model_666_27_30:'<S327>/S-Function' */
extern void             /* [PreAmpMedusaDummyState]-->[PreAmpMedusaDummyState]*/
    Model_InterpretationEngine64_ifunc_d3(void);
                   /* Interpretation_Model_141_1195_27_30:'<S247>/S-Function' */
extern void
/* [PreAmpMedusaMonoDetectorLevelCenter]-->[PreAmpMedusaMonoDetectorLevelCenter]*/
    Model_InterpretationEngine64_ifunc_gt(void);
                   /* Interpretation_Model_141_1404_27_30:'<S256>/S-Function' */
extern void
    /* [PreAmpMedusaMonoDetectorIsStereo]-->[PreAmpMedusaMonoDetectorIsStereo]*/
    Model_InterpretationEngine64_ifunc_lk(void);
                   /* Interpretation_Model_141_1466_27_30:'<S260>/S-Function' */
extern void
    /* [PreAmpMedusaMonoDetectorIsActive]-->[PreAmpMedusaMonoDetectorIsActive]*/
    Model_InterpretationEngine64_ifunc_nj(void);
                   /* Interpretation_Model_141_1467_27_30:'<S264>/S-Function' */
extern void       /* [PreAmpAudiopilotHvacDbspl]-->[PreAmpAudiopilotHvacDbspl]*/
    Model_InterpretationEngine64_ifunc(void);
                     /* Interpretation_Model_117_953_27_30:'<S16>/S-Function' */
extern void /* [PreAmpAudiopilotVehicleSpeed]-->[PreAmpAudiopilotVehicleSpeed]*/
    Model_InterpretationEngine64_ifunc_h(void);
                     /* Interpretation_Model_117_952_27_30:'<S20>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotBassBoostDb]-->[PreAmpAudiopilotAudiopilotBassBoostDb]*/
    Model_InterpretationEngine64_ifunc_p(void);
                  /* Interpretation_Model_117_44_372_27_30:'<S36>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotMidrangeBoostDb]-->[PreAmpAudiopilotAudiopilotMidrangeBoostDb]*/
    Model_InterpretationEngine64_ifunc_o(void);
                  /* Interpretation_Model_117_44_373_27_30:'<S40>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotTrebleBoostDb]-->[PreAmpAudiopilotAudiopilotTrebleBoostDb]*/
    Model_InterpretationEngine64_ifunc_f(void);
                  /* Interpretation_Model_117_44_374_27_30:'<S44>/S-Function' */
extern void
    /* [PreAmpAudiopilotDyneqBassBoostDb]-->[PreAmpAudiopilotDyneqBassBoostDb]*/
    Model_InterpretationEngine64_ifunc_j(void);
                  /* Interpretation_Model_117_44_369_27_30:'<S48>/S-Function' */
extern void /* [PreAmpAudiopilotHfNoiseDbspl]-->[PreAmpAudiopilotHfNoiseDbspl]*/
    Model_InterpretationEngine64_ifunc_b(void);
                  /* Interpretation_Model_117_44_381_27_30:'<S52>/S-Function' */
extern void
          /* [PreAmpAudiopilotIgnoreMicFlag]-->[PreAmpAudiopilotIgnoreMicFlag]*/
    Model_InterpretationEngine64_ifunc_k(void);
                  /* Interpretation_Model_117_44_902_27_30:'<S56>/S-Function' */
extern void /* [PreAmpAudiopilotLfNoiseDbspl]-->[PreAmpAudiopilotLfNoiseDbspl]*/
    Model_InterpretationEngine64_ifunc_a(void);
                  /* Interpretation_Model_117_44_378_27_30:'<S60>/S-Function' */
extern void     /* [PreAmpAudiopilotNoiseRatio]-->[PreAmpAudiopilotNoiseRatio]*/
    Model_InterpretationEngine64_ifunc_m(void);
                  /* Interpretation_Model_117_44_382_27_30:'<S64>/S-Function' */
extern void
    /* [PreAmpAudiopilotTotalBassBoostDb]-->[PreAmpAudiopilotTotalBassBoostDb]*/
    Model_InterpretationEngine64_ifunc_ak(void);
                  /* Interpretation_Model_117_44_371_27_30:'<S68>/S-Function' */
extern void /* [PreAmpAudiopilotWbNoiseDbspl]-->[PreAmpAudiopilotWbNoiseDbspl]*/
    Model_InterpretationEngine64_ifunc_o3(void);
                  /* Interpretation_Model_117_44_380_27_30:'<S72>/S-Function' */
extern void
/* [PreAmpAudiopilotAudiopilotBoostGain]-->[PreAmpAudiopilotAudiopilotBoostGain]*/
    Model_InterpretationEngine64_ifunc_m0(void);
                  /* Interpretation_Model_117_44_394_27_30:'<S78>/S-Function' */
extern void
        /* [PreAmpAudiopilotDyneqBoostGain]-->[PreAmpAudiopilotDyneqBoostGain]*/
    Model_InterpretationEngine64_ifunc_kq(void);
                  /* Interpretation_Model_117_44_393_27_30:'<S82>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseMicPsdLevel]-->[PreAmpAudiopilotHfNoiseMicPsdLevel]*/
    Model_InterpretationEngine64_ifunc_ku(void);
                /* Interpretation_Model_117_516_1976_27_30:'<S95>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoisePowerSpectralDensity]-->[PreAmpAudiopilotHfNoiseNoisePsdLevel]*/
    Model_InterpretationEngine64_ifunc_k0(void);
                      /* Interpretation_Model_117_516_1966:'<S99>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionFlatness]-->[PreAmpAudiopilotHfNoiseImpulseRejectionFlatness]*/
    Model_InterpretationEngine64_ifunc_d(void);
               /* Interpretation_Model_117_516_1858_27_30:'<S108>/S-Function' */
extern void
/* [PreAmpAudiopilotHfNoiseImpulseRejectionPmin]-->[PreAmpAudiopilotHfNoiseImpulseRejectionPmin]*/
    Model_InterpretationEngine64_ifunc_bh(void);
               /* Interpretation_Model_117_516_1970_27_30:'<S112>/S-Function' */
extern void
      /* [PreAmpAudiopilotHfNoisePostSlew]-->[PreAmpAudiopilotHfNoisePostSlew]*/
    Model_InterpretationEngine64_ifunc_bd(void);
               /* Interpretation_Model_117_516_1807_27_30:'<S116>/S-Function' */
extern void
        /* [PreAmpAudiopilotHfNoisePreSlew]-->[PreAmpAudiopilotHfNoisePreSlew]*/
    Model_InterpretationEngine64_ifunc_ad(void);
               /* Interpretation_Model_117_516_1948_27_30:'<S120>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut]-->[PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut]*/
    Model_InterpretationEngine64_ifunc_af(void);
                /* Interpretation_Model_117_517_512_27_30:'<S139>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef]-->[PreAmpAudiopilotLfNoiseImpulseRejectionGammaTauS]*/
    Model_InterpretationEngine64_ifunc_n(void);
                      /* Interpretation_Model_117_517_508:'<S143>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance]-->[PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceDb]*/
    Model_InterpretationEngine64_ifunc_jx(void);
                      /* Interpretation_Model_117_517_490:'<S145>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance]-->[PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceDb]*/
    Model_InterpretationEngine64_ifunc_px(void);
                      /* Interpretation_Model_117_517_484:'<S148>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance]-->[PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceDb]*/
    Model_InterpretationEngine64_ifunc_f4(void);
                      /* Interpretation_Model_117_517_496:'<S151>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance]-->[PreAmpAudiopilotLfNoiseImpulseRejectionTotalVarianceDb]*/
    Model_InterpretationEngine64_ifunc_pe(void);
                      /* Interpretation_Model_117_517_502:'<S154>/S-Function' */
extern void
      /* [PreAmpAudiopilotLfNoiseMicLevel]-->[PreAmpAudiopilotLfNoiseMicLevel]*/
    Model_InterpretationEngine64_ifunc_hv(void);
                /* Interpretation_Model_117_517_545_27_30:'<S158>/S-Function' */
extern void
          /* [PreAmpAudiopilotLfNoiseMicOut]-->[PreAmpAudiopilotLfNoiseMicOut]*/
    Model_InterpretationEngine64_ifunc_ng(void);
                /* Interpretation_Model_117_517_560_27_30:'<S162>/S-Function' */
extern void
      /* [PreAmpAudiopilotLfNoiseMusicOut]-->[PreAmpAudiopilotLfNoiseMusicOut]*/
    Model_InterpretationEngine64_ifunc_l(void);
                /* Interpretation_Model_117_517_561_27_30:'<S166>/S-Function' */
extern void
      /* [PreAmpAudiopilotLfNoiseNoiseOut]-->[PreAmpAudiopilotLfNoiseNoiseOut]*/
    Model_InterpretationEngine64_ifunc_nv(void);
                /* Interpretation_Model_117_517_562_27_30:'<S170>/S-Function' */
extern void
      /* [PreAmpAudiopilotLfNoisePostSlew]-->[PreAmpAudiopilotLfNoisePostSlew]*/
    Model_InterpretationEngine64_ifunc_b0(void);
                /* Interpretation_Model_117_517_513_27_30:'<S174>/S-Function' */
extern void
        /* [PreAmpAudiopilotLfNoisePreSlew]-->[PreAmpAudiopilotLfNoisePreSlew]*/
    Model_InterpretationEngine64_ifunc_hz(void);
                /* Interpretation_Model_117_517_514_27_30:'<S178>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoisePreSpeedBound]-->[PreAmpAudiopilotLfNoisePreSpeedBound]*/
    Model_InterpretationEngine64_ifunc_nu(void);
                /* Interpretation_Model_117_517_518_27_30:'<S182>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax]-->[PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax]*/
    Model_InterpretationEngine64_ifunc_jq(void);
                /* Interpretation_Model_117_517_566_27_30:'<S190>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin]-->[PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin]*/
    Model_InterpretationEngine64_ifunc_ne(void);
                /* Interpretation_Model_117_517_567_27_30:'<S194>/S-Function' */
extern void
/* [PreAmpAudiopilotLfNoiseSpeedBoundsFlag]-->[PreAmpAudiopilotLfNoiseSpeedBoundsFlag]*/
    Model_InterpretationEngine64_ifunc_g(void);
                /* Interpretation_Model_117_517_569_27_30:'<S198>/S-Function' */
extern void
          /* [PreAmpAudiopilotRatioPostSlew]-->[PreAmpAudiopilotRatioPostSlew]*/
    Model_InterpretationEngine64_ifunc_nq(void);
                   /* Interpretation_Model_117_2101_27_30:'<S205>/S-Function' */
extern void /* [PreAmpAudiopilotRatioPreSlew]-->[PreAmpAudiopilotRatioPreSlew]*/
    Model_InterpretationEngine64_ifunc_c(void);
                   /* Interpretation_Model_117_2102_27_30:'<S209>/S-Function' */
extern void
      /* [PreAmpAudiopilotRatioUpdateFlag]-->[PreAmpAudiopilotRatioUpdateFlag]*/
    Model_InterpretationEngine64_ifunc_bo(void);
                   /* Interpretation_Model_117_2170_27_30:'<S213>/S-Function' */
extern void
      /* [PreAmpLevelWatchAudiopilotEnvDb]-->[PreAmpLevelWatchAudiopilotEnvDb]*/
    Model_InterpretationEngine64_ifunc_fl(void);
                    /* Interpretation_Model_120_417_27_30:'<S222>/S-Function' */
extern void
/* [PreAmpLevelWatchAudiopilotLevelDbspl]-->[PreAmpLevelWatchAudiopilotLevelDbspl]*/
    Model_InterpretationEngine64_ifunc_bg(void);
                    /* Interpretation_Model_120_407_27_30:'<S226>/S-Function' */
extern void     /* [PreAmpLevelWatchDyneqEnvDb]-->[PreAmpLevelWatchDyneqEnvDb]*/
    Model_InterpretationEngine64_ifunc_jw(void);
                    /* Interpretation_Model_120_418_27_30:'<S233>/S-Function' */
extern void
      /* [PreAmpLevelWatchDyneqLevelDbspl]-->[PreAmpLevelWatchDyneqLevelDbspl]*/
    Model_InterpretationEngine64_ifunc_a4(void);
                    /* Interpretation_Model_120_409_27_30:'<S237>/S-Function' */
extern void
/* [NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB]-->[NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB]*/
    Model_InterpretationEngine64_ifunc_e(void);
                    /* Interpretation_Model_495_103_27_30:'<S277>/S-Function' */
extern void
/* [NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB]-->[NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB]*/
    Model_InterpretationEngine64_ifunc_bhr(void);
                    /* Interpretation_Model_506_103_27_30:'<S284>/S-Function' */
extern void
/* [NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB]-->[NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB]*/
    Model_InterpretationEngine64_ifunc_k3(void);
                    /* Interpretation_Model_517_103_27_30:'<S291>/S-Function' */
extern void
/* [NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB]-->[NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB]*/
    Model_InterpretationEngine64_ifunc_ld(void);
                    /* Interpretation_Model_528_103_27_30:'<S298>/S-Function' */

// -----------------------------------------------------
// ----- Source TSPs for each interpretation function:
static enum TSPNumber Interpretation_Model_662_27_30_Sources[] =
{                                      /* '<S311>/S-Function' */
    ID_TSP_PostProcessEnergyLimiterComputedEnergy,
};

static enum TSPNumber Interpretation_Model_663_27_30_Sources[] =
{                                      /* '<S315>/S-Function' */
    ID_TSP_PostProcessEnergyLimiterCurGain,
};

static enum TSPNumber Interpretation_Model_664_27_30_Sources[] =
{                                      /* '<S319>/S-Function' */
    ID_TSP_PostProcessEnergyLimiterEnergyThreshold,
};

static enum TSPNumber Interpretation_Model_665_27_30_Sources[] =
{                                      /* '<S323>/S-Function' */
    ID_TSP_PostProcessEnergyLimiterCurState,
};

static enum TSPNumber Interpretation_Model_666_27_30_Sources[] =
{                                      /* '<S327>/S-Function' */
    ID_TSP_PostProcessEnergyLimiterEnableFlag,
};

static enum TSPNumber Interpretation_Model_141_1195_27_30_Sources[] =
{                                      /* '<S247>/S-Function' */
    ID_TSP_PreAmpMedusaDummyState,
};

static enum TSPNumber Interpretation_Model_141_1404_27_30_Sources[] =
{                                      /* '<S256>/S-Function' */
    ID_TSP_PreAmpMedusaMonoDetectorLevelCenter,
};

static enum TSPNumber Interpretation_Model_141_1466_27_30_Sources[] =
{                                      /* '<S260>/S-Function' */
    ID_TSP_PreAmpMedusaMonoDetectorIsStereo,
};

static enum TSPNumber Interpretation_Model_141_1467_27_30_Sources[] =
{                                      /* '<S264>/S-Function' */
    ID_TSP_PreAmpMedusaMonoDetectorIsActive,
};

static enum TSPNumber Interpretation_Model_117_953_27_30_Sources[] =
{                                      /* '<S16>/S-Function' */
    ID_TSP_PreAmpAudiopilotHvacDbspl,
};

static enum TSPNumber Interpretation_Model_117_952_27_30_Sources[] =
{                                      /* '<S20>/S-Function' */
    ID_TSP_PreAmpAudiopilotVehicleSpeed,
};

static enum TSPNumber Interpretation_Model_117_44_372_27_30_Sources[] =
{                                      /* '<S36>/S-Function' */
    ID_TSP_PreAmpAudiopilotAudiopilotBassBoostDb,
};

static enum TSPNumber Interpretation_Model_117_44_373_27_30_Sources[] =
{                                      /* '<S40>/S-Function' */
    ID_TSP_PreAmpAudiopilotAudiopilotMidrangeBoostDb,
};

static enum TSPNumber Interpretation_Model_117_44_374_27_30_Sources[] =
{                                      /* '<S44>/S-Function' */
    ID_TSP_PreAmpAudiopilotAudiopilotTrebleBoostDb,
};

static enum TSPNumber Interpretation_Model_117_44_369_27_30_Sources[] =
{                                      /* '<S48>/S-Function' */
    ID_TSP_PreAmpAudiopilotDyneqBassBoostDb,
};

static enum TSPNumber Interpretation_Model_117_44_381_27_30_Sources[] =
{                                      /* '<S52>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoiseDbspl,
};

static enum TSPNumber Interpretation_Model_117_44_902_27_30_Sources[] =
{                                      /* '<S56>/S-Function' */
    ID_TSP_PreAmpAudiopilotIgnoreMicFlag,
};

static enum TSPNumber Interpretation_Model_117_44_378_27_30_Sources[] =
{                                      /* '<S60>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseDbspl,
};

static enum TSPNumber Interpretation_Model_117_44_382_27_30_Sources[] =
{                                      /* '<S64>/S-Function' */
    ID_TSP_PreAmpAudiopilotNoiseRatio,
};

static enum TSPNumber Interpretation_Model_117_44_371_27_30_Sources[] =
{                                      /* '<S68>/S-Function' */
    ID_TSP_PreAmpAudiopilotTotalBassBoostDb,
};

static enum TSPNumber Interpretation_Model_117_44_380_27_30_Sources[] =
{                                      /* '<S72>/S-Function' */
    ID_TSP_PreAmpAudiopilotWbNoiseDbspl,
};

static enum TSPNumber Interpretation_Model_117_44_394_27_30_Sources[] =
{                                      /* '<S78>/S-Function' */
    ID_TSP_PreAmpAudiopilotAudiopilotBoostGain,
};

static enum TSPNumber Interpretation_Model_117_44_393_27_30_Sources[] =
{                                      /* '<S82>/S-Function' */
    ID_TSP_PreAmpAudiopilotDyneqBoostGain,
};

static enum TSPNumber Interpretation_Model_117_516_1976_27_30_Sources[] =
{                                      /* '<S95>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoiseMicPsdLevel,
};

static enum TSPNumber Interpretation_Model_117_516_1966_Sources[] =
{                                      /* '<S99>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoisePowerSpectralDensity,
};

static enum TSPNumber Interpretation_Model_117_516_1858_27_30_Sources[] =
{                                      /* '<S108>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness,
};

static enum TSPNumber Interpretation_Model_117_516_1970_27_30_Sources[] =
{                                      /* '<S112>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoiseImpulseRejectionPmin,
};

static enum TSPNumber Interpretation_Model_117_516_1807_27_30_Sources[] =
{                                      /* '<S116>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoisePostSlew,
};

static enum TSPNumber Interpretation_Model_117_516_1948_27_30_Sources[] =
{                                      /* '<S120>/S-Function' */
    ID_TSP_PreAmpAudiopilotHfNoisePreSlew,
};

static enum TSPNumber Interpretation_Model_117_517_512_27_30_Sources[] =
{                                      /* '<S139>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut,
};

static enum TSPNumber Interpretation_Model_117_517_508_Sources[] =
{                                      /* '<S143>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef,
};

static enum TSPNumber Interpretation_Model_117_517_490_Sources[] =
{                                      /* '<S145>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance,
};

static enum TSPNumber Interpretation_Model_117_517_484_Sources[] =
{                                      /* '<S148>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance,
};

static enum TSPNumber Interpretation_Model_117_517_496_Sources[] =
{                                      /* '<S151>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance,
};

static enum TSPNumber Interpretation_Model_117_517_502_Sources[] =
{                                      /* '<S154>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance,
};

static enum TSPNumber Interpretation_Model_117_517_545_27_30_Sources[] =
{                                      /* '<S158>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseMicLevel,
};

static enum TSPNumber Interpretation_Model_117_517_560_27_30_Sources[] =
{                                      /* '<S162>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseMicOut,
};

static enum TSPNumber Interpretation_Model_117_517_561_27_30_Sources[] =
{                                      /* '<S166>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseMusicOut,
};

static enum TSPNumber Interpretation_Model_117_517_562_27_30_Sources[] =
{                                      /* '<S170>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseNoiseOut,
};

static enum TSPNumber Interpretation_Model_117_517_513_27_30_Sources[] =
{                                      /* '<S174>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoisePostSlew,
};

static enum TSPNumber Interpretation_Model_117_517_514_27_30_Sources[] =
{                                      /* '<S178>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoisePreSlew,
};

static enum TSPNumber Interpretation_Model_117_517_518_27_30_Sources[] =
{                                      /* '<S182>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoisePreSpeedBound,
};

static enum TSPNumber Interpretation_Model_117_517_566_27_30_Sources[] =
{                                      /* '<S190>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax,
};

static enum TSPNumber Interpretation_Model_117_517_567_27_30_Sources[] =
{                                      /* '<S194>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin,
};

static enum TSPNumber Interpretation_Model_117_517_569_27_30_Sources[] =
{                                      /* '<S198>/S-Function' */
    ID_TSP_PreAmpAudiopilotLfNoiseSpeedBoundsFlag,
};

static enum TSPNumber Interpretation_Model_117_2101_27_30_Sources[] =
{                                      /* '<S205>/S-Function' */
    ID_TSP_PreAmpAudiopilotRatioPostSlew,
};

static enum TSPNumber Interpretation_Model_117_2102_27_30_Sources[] =
{                                      /* '<S209>/S-Function' */
    ID_TSP_PreAmpAudiopilotRatioPreSlew,
};

static enum TSPNumber Interpretation_Model_117_2170_27_30_Sources[] =
{                                      /* '<S213>/S-Function' */
    ID_TSP_PreAmpAudiopilotRatioUpdateFlag,
};

static enum TSPNumber Interpretation_Model_120_417_27_30_Sources[] =
{                                      /* '<S222>/S-Function' */
    ID_TSP_PreAmpLevelWatchAudiopilotEnvDb,
};

static enum TSPNumber Interpretation_Model_120_407_27_30_Sources[] =
{                                      /* '<S226>/S-Function' */
    ID_TSP_PreAmpLevelWatchAudiopilotLevelDbspl,
};

static enum TSPNumber Interpretation_Model_120_418_27_30_Sources[] =
{                                      /* '<S233>/S-Function' */
    ID_TSP_PreAmpLevelWatchDyneqEnvDb,
};

static enum TSPNumber Interpretation_Model_120_409_27_30_Sources[] =
{                                      /* '<S237>/S-Function' */
    ID_TSP_PreAmpLevelWatchDyneqLevelDbspl,
};

static enum TSPNumber Interpretation_Model_495_103_27_30_Sources[] =
{                                      /* '<S277>/S-Function' */
    ID_TSP_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum TSPNumber Interpretation_Model_506_103_27_30_Sources[] =
{                                      /* '<S284>/S-Function' */
    ID_TSP_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum TSPNumber Interpretation_Model_517_103_27_30_Sources[] =
{                                      /* '<S291>/S-Function' */
    ID_TSP_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum TSPNumber Interpretation_Model_528_103_27_30_Sources[] =
{                                      /* '<S298>/S-Function' */
    ID_TSP_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB,
};

// -----------------------------------------------------
// ----- Dependent StateVars for each interpretation function:
static enum StateVarNumber Interpretation_Model_662_27_30_Destinations[] =
{                                      /* '<S311>/S-Function' */
    ID_StateVar_PostProcessEnergyLimiterComputedEnergy,
};

static enum StateVarNumber Interpretation_Model_663_27_30_Destinations[] =
{                                      /* '<S315>/S-Function' */
    ID_StateVar_PostProcessEnergyLimiterCurGain,
};

static enum StateVarNumber Interpretation_Model_664_27_30_Destinations[] =
{                                      /* '<S319>/S-Function' */
    ID_StateVar_PostProcessEnergyLimiterEnergyThreshold,
};

static enum StateVarNumber Interpretation_Model_665_27_30_Destinations[] =
{                                      /* '<S323>/S-Function' */
    ID_StateVar_PostProcessEnergyLimiterCurState,
};

static enum StateVarNumber Interpretation_Model_666_27_30_Destinations[] =
{                                      /* '<S327>/S-Function' */
    ID_StateVar_PostProcessEnergyLimiterEnableFlag,
};

static enum StateVarNumber Interpretation_Model_141_1195_27_30_Destinations[] =
{                                      /* '<S247>/S-Function' */
    ID_StateVar_PreAmpMedusaDummyState,
};

static enum StateVarNumber Interpretation_Model_141_1404_27_30_Destinations[] =
{                                      /* '<S256>/S-Function' */
    ID_StateVar_PreAmpMedusaMonoDetectorLevelCenter,
};

static enum StateVarNumber Interpretation_Model_141_1466_27_30_Destinations[] =
{                                      /* '<S260>/S-Function' */
    ID_StateVar_PreAmpMedusaMonoDetectorIsStereo,
};

static enum StateVarNumber Interpretation_Model_141_1467_27_30_Destinations[] =
{                                      /* '<S264>/S-Function' */
    ID_StateVar_PreAmpMedusaMonoDetectorIsActive,
};

static enum StateVarNumber Interpretation_Model_117_953_27_30_Destinations[] =
{                                      /* '<S16>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHvacDbspl,
};

static enum StateVarNumber Interpretation_Model_117_952_27_30_Destinations[] =
{                                      /* '<S20>/S-Function' */
    ID_StateVar_PreAmpAudiopilotVehicleSpeed,
};

static enum StateVarNumber Interpretation_Model_117_44_372_27_30_Destinations[] =
{                                      /* '<S36>/S-Function' */
    ID_StateVar_PreAmpAudiopilotAudiopilotBassBoostDb,
};

static enum StateVarNumber Interpretation_Model_117_44_373_27_30_Destinations[] =
{                                      /* '<S40>/S-Function' */
    ID_StateVar_PreAmpAudiopilotAudiopilotMidrangeBoostDb,
};

static enum StateVarNumber Interpretation_Model_117_44_374_27_30_Destinations[] =
{                                      /* '<S44>/S-Function' */
    ID_StateVar_PreAmpAudiopilotAudiopilotTrebleBoostDb,
};

static enum StateVarNumber Interpretation_Model_117_44_369_27_30_Destinations[] =
{                                      /* '<S48>/S-Function' */
    ID_StateVar_PreAmpAudiopilotDyneqBassBoostDb,
};

static enum StateVarNumber Interpretation_Model_117_44_381_27_30_Destinations[] =
{                                      /* '<S52>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoiseDbspl,
};

static enum StateVarNumber Interpretation_Model_117_44_902_27_30_Destinations[] =
{                                      /* '<S56>/S-Function' */
    ID_StateVar_PreAmpAudiopilotIgnoreMicFlag,
};

static enum StateVarNumber Interpretation_Model_117_44_378_27_30_Destinations[] =
{                                      /* '<S60>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseDbspl,
};

static enum StateVarNumber Interpretation_Model_117_44_382_27_30_Destinations[] =
{                                      /* '<S64>/S-Function' */
    ID_StateVar_PreAmpAudiopilotNoiseRatio,
};

static enum StateVarNumber Interpretation_Model_117_44_371_27_30_Destinations[] =
{                                      /* '<S68>/S-Function' */
    ID_StateVar_PreAmpAudiopilotTotalBassBoostDb,
};

static enum StateVarNumber Interpretation_Model_117_44_380_27_30_Destinations[] =
{                                      /* '<S72>/S-Function' */
    ID_StateVar_PreAmpAudiopilotWbNoiseDbspl,
};

static enum StateVarNumber Interpretation_Model_117_44_394_27_30_Destinations[] =
{                                      /* '<S78>/S-Function' */
    ID_StateVar_PreAmpAudiopilotAudiopilotBoostGain,
};

static enum StateVarNumber Interpretation_Model_117_44_393_27_30_Destinations[] =
{                                      /* '<S82>/S-Function' */
    ID_StateVar_PreAmpAudiopilotDyneqBoostGain,
};

static enum StateVarNumber Interpretation_Model_117_516_1976_27_30_Destinations[]
    =
{                                      /* '<S95>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoiseMicPsdLevel,
};

static enum StateVarNumber Interpretation_Model_117_516_1966_Destinations[] =
{                                      /* '<S99>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoiseNoisePsdLevel,
};

static enum StateVarNumber Interpretation_Model_117_516_1858_27_30_Destinations[]
    =
{                                      /* '<S108>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoiseImpulseRejectionFlatness,
};

static enum StateVarNumber Interpretation_Model_117_516_1970_27_30_Destinations[]
    =
{                                      /* '<S112>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoiseImpulseRejectionPmin,
};

static enum StateVarNumber Interpretation_Model_117_516_1807_27_30_Destinations[]
    =
{                                      /* '<S116>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoisePostSlew,
};

static enum StateVarNumber Interpretation_Model_117_516_1948_27_30_Destinations[]
    =
{                                      /* '<S120>/S-Function' */
    ID_StateVar_PreAmpAudiopilotHfNoisePreSlew,
};

static enum StateVarNumber Interpretation_Model_117_517_512_27_30_Destinations[]
    =
{                                      /* '<S139>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut,
};

static enum StateVarNumber Interpretation_Model_117_517_508_Destinations[] =
{                                      /* '<S143>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionGammaTauS,
};

static enum StateVarNumber Interpretation_Model_117_517_490_Destinations[] =
{                                      /* '<S145>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceDb,
};

static enum StateVarNumber Interpretation_Model_117_517_484_Destinations[] =
{                                      /* '<S148>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceDb,
};

static enum StateVarNumber Interpretation_Model_117_517_496_Destinations[] =
{                                      /* '<S151>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceDb,
};

static enum StateVarNumber Interpretation_Model_117_517_502_Destinations[] =
{                                      /* '<S154>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseImpulseRejectionTotalVarianceDb,
};

static enum StateVarNumber Interpretation_Model_117_517_545_27_30_Destinations[]
    =
{                                      /* '<S158>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMicLevel,
};

static enum StateVarNumber Interpretation_Model_117_517_560_27_30_Destinations[]
    =
{                                      /* '<S162>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMicOut,
};

static enum StateVarNumber Interpretation_Model_117_517_561_27_30_Destinations[]
    =
{                                      /* '<S166>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseMusicOut,
};

static enum StateVarNumber Interpretation_Model_117_517_562_27_30_Destinations[]
    =
{                                      /* '<S170>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseNoiseOut,
};

static enum StateVarNumber Interpretation_Model_117_517_513_27_30_Destinations[]
    =
{                                      /* '<S174>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoisePostSlew,
};

static enum StateVarNumber Interpretation_Model_117_517_514_27_30_Destinations[]
    =
{                                      /* '<S178>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoisePreSlew,
};

static enum StateVarNumber Interpretation_Model_117_517_518_27_30_Destinations[]
    =
{                                      /* '<S182>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoisePreSpeedBound,
};

static enum StateVarNumber Interpretation_Model_117_517_566_27_30_Destinations[]
    =
{                                      /* '<S190>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax,
};

static enum StateVarNumber Interpretation_Model_117_517_567_27_30_Destinations[]
    =
{                                      /* '<S194>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin,
};

static enum StateVarNumber Interpretation_Model_117_517_569_27_30_Destinations[]
    =
{                                      /* '<S198>/S-Function' */
    ID_StateVar_PreAmpAudiopilotLfNoiseSpeedBoundsFlag,
};

static enum StateVarNumber Interpretation_Model_117_2101_27_30_Destinations[] =
{                                      /* '<S205>/S-Function' */
    ID_StateVar_PreAmpAudiopilotRatioPostSlew,
};

static enum StateVarNumber Interpretation_Model_117_2102_27_30_Destinations[] =
{                                      /* '<S209>/S-Function' */
    ID_StateVar_PreAmpAudiopilotRatioPreSlew,
};

static enum StateVarNumber Interpretation_Model_117_2170_27_30_Destinations[] =
{                                      /* '<S213>/S-Function' */
    ID_StateVar_PreAmpAudiopilotRatioUpdateFlag,
};

static enum StateVarNumber Interpretation_Model_120_417_27_30_Destinations[] =
{                                      /* '<S222>/S-Function' */
    ID_StateVar_PreAmpLevelWatchAudiopilotEnvDb,
};

static enum StateVarNumber Interpretation_Model_120_407_27_30_Destinations[] =
{                                      /* '<S226>/S-Function' */
    ID_StateVar_PreAmpLevelWatchAudiopilotLevelDbspl,
};

static enum StateVarNumber Interpretation_Model_120_418_27_30_Destinations[] =
{                                      /* '<S233>/S-Function' */
    ID_StateVar_PreAmpLevelWatchDyneqEnvDb,
};

static enum StateVarNumber Interpretation_Model_120_409_27_30_Destinations[] =
{                                      /* '<S237>/S-Function' */
    ID_StateVar_PreAmpLevelWatchDyneqLevelDbspl,
};

static enum StateVarNumber Interpretation_Model_495_103_27_30_Destinations[] =
{                                      /* '<S277>/S-Function' */
    ID_StateVar_NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum StateVarNumber Interpretation_Model_506_103_27_30_Destinations[] =
{                                      /* '<S284>/S-Function' */
    ID_StateVar_NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum StateVarNumber Interpretation_Model_517_103_27_30_Destinations[] =
{                                      /* '<S291>/S-Function' */
    ID_StateVar_NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB,
};

static enum StateVarNumber Interpretation_Model_528_103_27_30_Destinations[] =
{                                      /* '<S298>/S-Function' */
    ID_StateVar_NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB,
};

// -----------------------------------------------------
// ----- Interpretation object table listing all interpretations
static InterpretationRecord_type interpretation_table[] =
{
    // Interpretation record for PostProcessEnergyLimiterComputedEnergy '<S311>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_em, 1,
        Interpretation_Model_662_27_30_Sources, 1,
        Interpretation_Model_662_27_30_Destinations
    },

    // Interpretation record for PostProcessEnergyLimiterCurGain '<S315>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_lv, 1,
        Interpretation_Model_663_27_30_Sources, 1,
        Interpretation_Model_663_27_30_Destinations
    },

    // Interpretation record for PostProcessEnergyLimiterEnergyThreshold '<S319>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_jl, 1,
        Interpretation_Model_664_27_30_Sources, 1,
        Interpretation_Model_664_27_30_Destinations
    },

    // Interpretation record for PostProcessEnergyLimiterCurState '<S323>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_jt, 1,
        Interpretation_Model_665_27_30_Sources, 1,
        Interpretation_Model_665_27_30_Destinations
    },

    // Interpretation record for PostProcessEnergyLimiterEnableFlag '<S327>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_cj, 1,
        Interpretation_Model_666_27_30_Sources, 1,
        Interpretation_Model_666_27_30_Destinations
    },

    // Interpretation record for PreAmpMedusaDummyState '<S247>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_d3, 1,
        Interpretation_Model_141_1195_27_30_Sources, 1,
        Interpretation_Model_141_1195_27_30_Destinations
    },

    // Interpretation record for PreAmpMedusaMonoDetectorLevelCenter '<S256>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_gt, 1,
        Interpretation_Model_141_1404_27_30_Sources, 1,
        Interpretation_Model_141_1404_27_30_Destinations
    },

    // Interpretation record for PreAmpMedusaMonoDetectorIsStereo '<S260>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_lk, 1,
        Interpretation_Model_141_1466_27_30_Sources, 1,
        Interpretation_Model_141_1466_27_30_Destinations
    },

    // Interpretation record for PreAmpMedusaMonoDetectorIsActive '<S264>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_nj, 1,
        Interpretation_Model_141_1467_27_30_Sources, 1,
        Interpretation_Model_141_1467_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHvacDbspl '<S16>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc, 1,
        Interpretation_Model_117_953_27_30_Sources, 1,
        Interpretation_Model_117_953_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotVehicleSpeed '<S20>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_h, 1,
        Interpretation_Model_117_952_27_30_Sources, 1,
        Interpretation_Model_117_952_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotAudiopilotBassBoostDb '<S36>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_p, 1,
        Interpretation_Model_117_44_372_27_30_Sources, 1,
        Interpretation_Model_117_44_372_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotAudiopilotMidrangeBoostDb '<S40>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_o, 1,
        Interpretation_Model_117_44_373_27_30_Sources, 1,
        Interpretation_Model_117_44_373_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotAudiopilotTrebleBoostDb '<S44>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_f, 1,
        Interpretation_Model_117_44_374_27_30_Sources, 1,
        Interpretation_Model_117_44_374_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotDyneqBassBoostDb '<S48>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_j, 1,
        Interpretation_Model_117_44_369_27_30_Sources, 1,
        Interpretation_Model_117_44_369_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoiseDbspl '<S52>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_b, 1,
        Interpretation_Model_117_44_381_27_30_Sources, 1,
        Interpretation_Model_117_44_381_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotIgnoreMicFlag '<S56>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_k, 1,
        Interpretation_Model_117_44_902_27_30_Sources, 1,
        Interpretation_Model_117_44_902_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseDbspl '<S60>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_a, 1,
        Interpretation_Model_117_44_378_27_30_Sources, 1,
        Interpretation_Model_117_44_378_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotNoiseRatio '<S64>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_m, 1,
        Interpretation_Model_117_44_382_27_30_Sources, 1,
        Interpretation_Model_117_44_382_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotTotalBassBoostDb '<S68>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ak, 1,
        Interpretation_Model_117_44_371_27_30_Sources, 1,
        Interpretation_Model_117_44_371_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotWbNoiseDbspl '<S72>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_o3, 1,
        Interpretation_Model_117_44_380_27_30_Sources, 1,
        Interpretation_Model_117_44_380_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotAudiopilotBoostGain '<S78>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_m0, 1,
        Interpretation_Model_117_44_394_27_30_Sources, 1,
        Interpretation_Model_117_44_394_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotDyneqBoostGain '<S82>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_kq, 1,
        Interpretation_Model_117_44_393_27_30_Sources, 1,
        Interpretation_Model_117_44_393_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoiseMicPsdLevel '<S95>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ku, 1,
        Interpretation_Model_117_516_1976_27_30_Sources, 1,
        Interpretation_Model_117_516_1976_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoiseNoisePsdLevel '<S99>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_k0, 1,
        Interpretation_Model_117_516_1966_Sources, 1,
        Interpretation_Model_117_516_1966_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoiseImpulseRejectionFlatness '<S108>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_d, 1,
        Interpretation_Model_117_516_1858_27_30_Sources, 1,
        Interpretation_Model_117_516_1858_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoiseImpulseRejectionPmin '<S112>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_bh, 1,
        Interpretation_Model_117_516_1970_27_30_Sources, 1,
        Interpretation_Model_117_516_1970_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoisePostSlew '<S116>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_bd, 1,
        Interpretation_Model_117_516_1807_27_30_Sources, 1,
        Interpretation_Model_117_516_1807_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotHfNoisePreSlew '<S120>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ad, 1,
        Interpretation_Model_117_516_1948_27_30_Sources, 1,
        Interpretation_Model_117_516_1948_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut '<S139>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_af, 1,
        Interpretation_Model_117_517_512_27_30_Sources, 1,
        Interpretation_Model_117_517_512_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionGammaTauS '<S143>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_n, 1,
        Interpretation_Model_117_517_508_Sources, 1,
        Interpretation_Model_117_517_508_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceDb '<S145>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_jx, 1,
        Interpretation_Model_117_517_490_Sources, 1,
        Interpretation_Model_117_517_490_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceDb '<S148>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_px, 1,
        Interpretation_Model_117_517_484_Sources, 1,
        Interpretation_Model_117_517_484_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceDb '<S151>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_f4, 1,
        Interpretation_Model_117_517_496_Sources, 1,
        Interpretation_Model_117_517_496_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseImpulseRejectionTotalVarianceDb '<S154>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_pe, 1,
        Interpretation_Model_117_517_502_Sources, 1,
        Interpretation_Model_117_517_502_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseMicLevel '<S158>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_hv, 1,
        Interpretation_Model_117_517_545_27_30_Sources, 1,
        Interpretation_Model_117_517_545_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseMicOut '<S162>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ng, 1,
        Interpretation_Model_117_517_560_27_30_Sources, 1,
        Interpretation_Model_117_517_560_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseMusicOut '<S166>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_l, 1,
        Interpretation_Model_117_517_561_27_30_Sources, 1,
        Interpretation_Model_117_517_561_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseNoiseOut '<S170>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_nv, 1,
        Interpretation_Model_117_517_562_27_30_Sources, 1,
        Interpretation_Model_117_517_562_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoisePostSlew '<S174>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_b0, 1,
        Interpretation_Model_117_517_513_27_30_Sources, 1,
        Interpretation_Model_117_517_513_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoisePreSlew '<S178>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_hz, 1,
        Interpretation_Model_117_517_514_27_30_Sources, 1,
        Interpretation_Model_117_517_514_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoisePreSpeedBound '<S182>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_nu, 1,
        Interpretation_Model_117_517_518_27_30_Sources, 1,
        Interpretation_Model_117_517_518_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax '<S190>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_jq, 1,
        Interpretation_Model_117_517_566_27_30_Sources, 1,
        Interpretation_Model_117_517_566_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin '<S194>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ne, 1,
        Interpretation_Model_117_517_567_27_30_Sources, 1,
        Interpretation_Model_117_517_567_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotLfNoiseSpeedBoundsFlag '<S198>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_g, 1,
        Interpretation_Model_117_517_569_27_30_Sources, 1,
        Interpretation_Model_117_517_569_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotRatioPostSlew '<S205>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_nq, 1,
        Interpretation_Model_117_2101_27_30_Sources, 1,
        Interpretation_Model_117_2101_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotRatioPreSlew '<S209>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_c, 1,
        Interpretation_Model_117_2102_27_30_Sources, 1,
        Interpretation_Model_117_2102_27_30_Destinations
    },

    // Interpretation record for PreAmpAudiopilotRatioUpdateFlag '<S213>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_bo, 1,
        Interpretation_Model_117_2170_27_30_Sources, 1,
        Interpretation_Model_117_2170_27_30_Destinations
    },

    // Interpretation record for PreAmpLevelWatchAudiopilotEnvDb '<S222>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_fl, 1,
        Interpretation_Model_120_417_27_30_Sources, 1,
        Interpretation_Model_120_417_27_30_Destinations
    },

    // Interpretation record for PreAmpLevelWatchAudiopilotLevelDbspl '<S226>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_bg, 1,
        Interpretation_Model_120_407_27_30_Sources, 1,
        Interpretation_Model_120_407_27_30_Destinations
    },

    // Interpretation record for PreAmpLevelWatchDyneqEnvDb '<S233>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_jw, 1,
        Interpretation_Model_120_418_27_30_Sources, 1,
        Interpretation_Model_120_418_27_30_Destinations
    },

    // Interpretation record for PreAmpLevelWatchDyneqLevelDbspl '<S237>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_a4, 1,
        Interpretation_Model_120_409_27_30_Sources, 1,
        Interpretation_Model_120_409_27_30_Destinations
    },

    // Interpretation record for NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB '<S277>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_e, 1,
        Interpretation_Model_495_103_27_30_Sources, 1,
        Interpretation_Model_495_103_27_30_Destinations
    },

    // Interpretation record for NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB '<S284>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_bhr, 1,
        Interpretation_Model_506_103_27_30_Sources, 1,
        Interpretation_Model_506_103_27_30_Destinations
    },

    // Interpretation record for NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB '<S291>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_k3, 1,
        Interpretation_Model_517_103_27_30_Sources, 1,
        Interpretation_Model_517_103_27_30_Destinations
    },

    // Interpretation record for NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB '<S298>/S-Function'
    {
        0, &
        Model_InterpretationEngine64_ifunc_ld, 1,
        Interpretation_Model_528_103_27_30_Sources, 1,
        Interpretation_Model_528_103_27_30_Destinations
    },
};

// Share table in a public interface for use by top-model
void* Model_InterpretationEngine64_interpretation_table = interpretation_table;
int Model_InterpretationEngine64_interpretation_table_count = sizeof
    (interpretation_table) / sizeof(InterpretationRecord_type);

// -----------------------------------------------------
// Local storage
static uint32_t theInterpretationErrorState = 0;
static char interpretErrorBuffer[1024];
static int interpretErrorCharsUsed = 0;

// -----------------------------------------------------
// Interpretation engine entry points:

// forward declare local functions
static void SetInterpretationErrorState(uint32_t errorState);
static void ErrorVPrintf(const char* formatString, va_list args);
static void ErrorPrintf(const char* formatString, ...);

// -----------------------------------------------------
// Top-level model root array to access engine tables:
int numInterpretationRoots = 0;
InterpretationRoot* interpretationRoots[Model_InterpretationEngine64_ModelCount]
    =
{
    0
};

void RegisterInterpretationRoot(InterpretationRoot* aRoot)
{
    int i;
    const int arraySize = Model_InterpretationEngine64_ModelCount;
    for (i = 0; i < arraySize; i++)
    {
        if (aRoot == interpretationRoots[i])
        {
            // already here!
            return;
        }

        if (0 == interpretationRoots[i])
        {
            // found a slot at the end
            interpretationRoots[i] = aRoot;
            numInterpretationRoots = i + 1;
            return;
        }
    }

    // ERROR! Array size was too small! This should not happen.
    while (1) ;
}

InterpretEngineIterator INVALID_INTERPRET_ITERATOR =
{
    -1, -1
};

int IsValidInterpretIterator(InterpretEngineIterator anIterator)
{
    return (anIterator.model >= 0) && (anIterator.index >= 0);
}

static InterpretationRecord_type* GetInterpretationRecord
    (InterpretEngineIterator interpretationNumIn)
{
    // Validate input parameters
    if ((interpretationNumIn.model < 0) || (interpretationNumIn.model >=
            numInterpretationRoots))
    {
        return 0;                      // model out of range
    }

    InterpretationRoot* theRoot = interpretationRoots[interpretationNumIn.model];
    if ((interpretationNumIn.index < 0) || (interpretationNumIn.index >=
            *theRoot->interpretation_count))
    {
        return 0;                      // index out of range for specified model
    }

    InterpretationRecord_type* theTable = *(InterpretationRecord_type**)
        theRoot->interpretation_table;
    return &theTable[interpretationNumIn.index];
}

// Touch interpretation object to indicate new data is available and
// must be interpreted.
void TouchInterpretation(InterpretEngineIterator interpretationNumIn)
{
    InterpretationRecord_type* aRecord = GetInterpretationRecord
        (interpretationNumIn);
    if (aRecord)
    {
        aRecord->requested_state_vars++;
    }
}

// Clear all flags that would indicate a interpretation must be run
void ClearAllInterpretationRequiredFlags( void )
{
    InterpretationRecord_type* aRecord;
    InterpretEngineIterator interpretationNum;
    int m;
    for (m = 0; m < numInterpretationRoots; m++)
    {
        interpretationNum.model = m;
        interpretationNum.index = 0;
        for (aRecord = GetInterpretationRecord(interpretationNum); aRecord;
             aRecord = GetInterpretationRecord(interpretationNum))
        {
            aRecord->requested_state_vars = 0;
            interpretationNum.index++;
        }
    }
}

// Retrieve space-delimited list of TSPs needed for specified interpretation
// Returns char count placed in buffer
int ListTSPsForInterpretation(InterpretEngineIterator interpretationNumIn, char*
    bufferIn, int bufferSizeIn)
{
    char* buf = bufferIn;
    int bufSize = bufferSizeIn;
    InterpretationRecord_type* aRecord = GetInterpretationRecord
        (interpretationNumIn);
    if (aRecord)
    {
        // Loop through and dump TSP names
        for (int i = 0; i < aRecord->tsp_count; i++)
        {
            InterpretEngineIterator aTSP;
            aTSP.model = interpretationNumIn.model;
            aTSP.index = aRecord->tsps[i];
            int used = 0;
            if (i > 0)
            {
                used = snprintf(buf, bufSize, " ");
                buf += used;
                bufSize -= used;
            }

            used = snprintf(buf, bufSize, "%s", GetTSPName(aTSP));
            buf += used;
            bufSize -= used;
        }
    }

    return (bufferSizeIn - bufSize);
}

// Return the first interpretation record that has been touched to run (or INVALID_INTERPRETATION if none)
InterpretEngineIterator FindFirstNeededInterpretation( void )
{
    InterpretEngineIterator retVal = INVALID_INTERPRET_ITERATOR;
    InterpretEngineIterator theFirst;
    int m;
    InterpretationRecord_type* aRecord;
    for (m = 0; m < numInterpretationRoots; m++)
    {
        theFirst.model = m;
        theFirst.index = 0;
        for (aRecord = GetInterpretationRecord(theFirst); aRecord;
             aRecord = GetInterpretationRecord(theFirst))
        {
            if (aRecord->requested_state_vars != 0)
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

// Return the next interpretation record that has been touched to run (or -1 if no more)
InterpretEngineIterator FindNextNeededInterpretation(InterpretEngineIterator
    afterThisOne)
{
    InterpretEngineIterator retVal = INVALID_INTERPRET_ITERATOR;
    InterpretEngineIterator nextOne;
    nextOne.index = afterThisOne.index + 1;
    int m;
    int foundIt = 0;
    InterpretationRecord_type* aRecord;
    for (m = afterThisOne.model; (0 == foundIt) && (m < numInterpretationRoots);
         m++)
    {
        nextOne.model = m;
        for (aRecord = GetInterpretationRecord(nextOne); aRecord;
             aRecord = GetInterpretationRecord(nextOne))
        {
            if (aRecord->requested_state_vars != 0)
            {
                // Found it!
                foundIt = 1;
                retVal = nextOne;
                break;
            }

            // move on to the next interpretation
            nextOne.index++;
        }

        // Reset the index in preparation for the next model search
        nextOne.index = 0;
    }

    return retVal;
}

// Verify that all TSPs read by the specified interpretation have been seen
// returns 0 for OK, nonzero is error
int CheckInterpretationSourceSightingsOK(InterpretEngineIterator
    interpretationNumIn)
{
    int retVal = 0;                    // assume signtings are OK
    InterpretationRecord_type* aRecord = GetInterpretationRecord
        (interpretationNumIn);
    if (0 == aRecord)
        return 0;                    // if interpretation not found just bail ok

    // Loop through and check that all source TSPs have been seen
    int i;
    for (i = 0; i < aRecord->tsp_count; i++)
    {
        InterpretEngineIterator aTSP;
        aTSP.model = interpretationNumIn.model;
        aTSP.index = aRecord->tsps[i];
        int sightings = GetTSPSightings(aTSP);
        if (sightings == 0)
        {
            // Error - have not seen this one yet!
            retVal = 1;
            ErrorPrintf("Error: Missing TSP %s (needed for interpretation#%d:%d)\n",
                        GetTSPName(aTSP), interpretationNumIn.model,
                        interpretationNumIn.index);

            // Missing StateVar. Set the error state
            SetInterpretationErrorState(1);
        }
    }

    return retVal;
}

// Checks source sightings & calls interpretation function, but does *not* reset dirty flags
// returns error state (0 means OK);
int CallInterpretation(InterpretEngineIterator interpretationNumIn)
{
    InterpretationRecord_type* aRecord = GetInterpretationRecord
        (interpretationNumIn);
    if (0 == aRecord)
        return 0;                    // if interpretation not found just bail ok
    int err = CheckInterpretationSourceSightingsOK(interpretationNumIn);
    if (0 == err)
    {
        aRecord->interpretation_func();
    }

    if (0 != GetInterpretationErrorState())
    {
        ErrorPrintf("... while processing TSPs { ");
        int i;
        for (i = 0; i < aRecord->tsp_count; i++)
        {
            InterpretEngineIterator aTSP;
            aTSP.model = interpretationNumIn.model;
            aTSP.index = aRecord->tsps[i];
            ErrorPrintf("%s ", GetTSPName(aTSP));
        }

        ErrorPrintf("}\n");
    }

    return GetInterpretationErrorState();
}

// Retrieve interpretation error state
uint32_t GetInterpretationErrorState( void )
{
    return theInterpretationErrorState;
}

static void SetInterpretationErrorState(uint32_t errorState)
{
    theInterpretationErrorState = errorState;
}

// Internal use print to error buffer
static void ErrorVPrintf(const char* formatString, va_list args)
{
    char* buffer = &interpretErrorBuffer[interpretErrorCharsUsed];
    int bufferSize = sizeof(interpretErrorBuffer) - interpretErrorCharsUsed;
    if (bufferSize)
    {
        int charsPrinted = vsnprintf(
            buffer, bufferSize, formatString, args);
        interpretErrorCharsUsed += charsPrinted;
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

// Report a interpretation error (works like printf)
// Called from the model code
void InterpretError(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);

    // Add newline and set error state
    ErrorPrintf("\n");
    SetInterpretationErrorState(1);
}

// Retrieve reported error strings
const char* GetInterpretationErrorStrings( void )
{
    return &interpretErrorBuffer[0];
}

// Clear error state
void ClearInterpretationErrorState( void )
{
    interpretErrorBuffer[0] = 0;
    interpretErrorCharsUsed = 0;
    SetInterpretationErrorState(0);
}

InterpretationRoot Model_InterpretationEngine64_InterpretationRoot =
{
    &Model_InterpretationEngine64_state_var_table,
    &Model_InterpretationEngine64_interpretation_table,
    &Model_InterpretationEngine64_tsp_interpret_table,
    &Model_InterpretationEngine64_state_var_table_count,
    &Model_InterpretationEngine64_interpretation_table_count,
    &Model_InterpretationEngine64_tsp_interpret_table_count
};

void Model_InterpretationEngine64_InitializeInterpretationRoot()
{
    RegisterInterpretationRoot(&Model_InterpretationEngine64_InterpretationRoot);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
