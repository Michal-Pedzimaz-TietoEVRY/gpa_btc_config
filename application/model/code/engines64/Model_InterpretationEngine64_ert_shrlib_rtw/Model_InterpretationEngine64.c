/*
 * File: Model_InterpretationEngine64.c
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

#include "Model_InterpretationEngine64.h"
#include "rtwtypes.h"
#include "Model_InterpretationEngine64_private.h"
#include <math.h>
#include "PostProcess.h"
#include "tsp_capture_settings.h"

/* Block signals (default storage) */
B_Model_InterpretationEngine64_T Model_InterpretationEngine64_B;

/* Real-time model */
static RT_MODEL_Model_InterpretationEngine64_T Model_InterpretationEngine64_M_;
RT_MODEL_Model_InterpretationEngine64_T *const Model_InterpretationEngine64_M =
    &Model_InterpretationEngine64_M_;
extern void Model_InterpretationEngine64_InitializeInterpretationRoot( void );

/* Output and update for function-call system: '<S16>/ifunc' */
void Model_InterpretationEngine64_ifunc(void)
{
    /* Outputs for Function Call SubSystem: '<S15>/Subsystem' */
    /* SignalConversion generated from: '<S17>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S18>:1' */
    /* '<S18>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_dn = Model_InterpretationEngine64_B.TSP_j;

    /* End of Outputs for SubSystem: '<S15>/Subsystem' */
}

/* Output and update for function-call system: '<S20>/ifunc' */
void Model_InterpretationEngine64_ifunc_h(void)
{
    /* Outputs for Function Call SubSystem: '<S19>/Subsystem' */
    /* SignalConversion generated from: '<S21>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S22>:1' */
    /* '<S22>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_gf = Model_InterpretationEngine64_B.TSP_l;

    /* End of Outputs for SubSystem: '<S19>/Subsystem' */
}

/* Output and update for function-call system: '<S36>/ifunc' */
void Model_InterpretationEngine64_ifunc_p(void)
{
    /* Outputs for Function Call SubSystem: '<S35>/Subsystem' */
    /* SignalConversion generated from: '<S37>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S38>:1' */
    /* '<S38>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_o3 = Model_InterpretationEngine64_B.TSP_o;

    /* End of Outputs for SubSystem: '<S35>/Subsystem' */
}

/* Output and update for function-call system: '<S40>/ifunc' */
void Model_InterpretationEngine64_ifunc_o(void)
{
    /* Outputs for Function Call SubSystem: '<S39>/Subsystem' */
    /* SignalConversion generated from: '<S41>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S42>:1' */
    /* '<S42>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_dh =
        Model_InterpretationEngine64_B.TSP_bq;

    /* End of Outputs for SubSystem: '<S39>/Subsystem' */
}

/* Output and update for function-call system: '<S44>/ifunc' */
void Model_InterpretationEngine64_ifunc_f(void)
{
    /* Outputs for Function Call SubSystem: '<S43>/Subsystem' */
    /* SignalConversion generated from: '<S45>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S46>:1' */
    /* '<S46>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_i = Model_InterpretationEngine64_B.TSP_c;

    /* End of Outputs for SubSystem: '<S43>/Subsystem' */
}

/* Output and update for function-call system: '<S48>/ifunc' */
void Model_InterpretationEngine64_ifunc_j(void)
{
    /* Outputs for Function Call SubSystem: '<S47>/Subsystem' */
    /* SignalConversion generated from: '<S49>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S50>:1' */
    /* '<S50>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_gl =
        Model_InterpretationEngine64_B.TSP_od;

    /* End of Outputs for SubSystem: '<S47>/Subsystem' */
}

/* Output and update for function-call system: '<S52>/ifunc' */
void Model_InterpretationEngine64_ifunc_b(void)
{
    /* Outputs for Function Call SubSystem: '<S51>/Subsystem' */
    /* SignalConversion generated from: '<S53>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S54>:1' */
    /* '<S54>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_jm = Model_InterpretationEngine64_B.TSP_f;

    /* End of Outputs for SubSystem: '<S51>/Subsystem' */
}

/* Output and update for function-call system: '<S56>/ifunc' */
void Model_InterpretationEngine64_ifunc_k(void)
{
    /* Outputs for Function Call SubSystem: '<S55>/Subsystem' */
    /* SignalConversion generated from: '<S57>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S58>:1' */
    /* '<S58>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_jq =
        Model_InterpretationEngine64_B.TSP_lz;

    /* End of Outputs for SubSystem: '<S55>/Subsystem' */
}

/* Output and update for function-call system: '<S60>/ifunc' */
void Model_InterpretationEngine64_ifunc_a(void)
{
    /* Outputs for Function Call SubSystem: '<S59>/Subsystem' */
    /* SignalConversion generated from: '<S61>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S62>:1' */
    /* '<S62>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_g3 = Model_InterpretationEngine64_B.TSP_a;

    /* End of Outputs for SubSystem: '<S59>/Subsystem' */
}

/* Output and update for function-call system: '<S64>/ifunc' */
void Model_InterpretationEngine64_ifunc_m(void)
{
    /* Outputs for Function Call SubSystem: '<S63>/Subsystem' */
    /* SignalConversion generated from: '<S65>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S66>:1' */
    /* '<S66>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_g = Model_InterpretationEngine64_B.TSP_d;

    /* End of Outputs for SubSystem: '<S63>/Subsystem' */
}

/* Output and update for function-call system: '<S68>/ifunc' */
void Model_InterpretationEngine64_ifunc_ak(void)
{
    /* Outputs for Function Call SubSystem: '<S67>/Subsystem' */
    /* SignalConversion generated from: '<S69>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S70>:1' */
    /* '<S70>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_kr =
        Model_InterpretationEngine64_B.TSP_dj;

    /* End of Outputs for SubSystem: '<S67>/Subsystem' */
}

/* Output and update for function-call system: '<S72>/ifunc' */
void Model_InterpretationEngine64_ifunc_o3(void)
{
    /* Outputs for Function Call SubSystem: '<S71>/Subsystem' */
    /* SignalConversion generated from: '<S73>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S74>:1' */
    /* '<S74>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_nz =
        Model_InterpretationEngine64_B.TSP_ai;

    /* End of Outputs for SubSystem: '<S71>/Subsystem' */
}

/* Output and update for function-call system: '<S78>/ifunc' */
void Model_InterpretationEngine64_ifunc_m0(void)
{
    /* Outputs for Function Call SubSystem: '<S77>/Subsystem' */
    /* SignalConversion generated from: '<S79>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S80>:1' */
    /* '<S80>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_e = Model_InterpretationEngine64_B.TSP_cp;

    /* End of Outputs for SubSystem: '<S77>/Subsystem' */
}

/* Output and update for function-call system: '<S82>/ifunc' */
void Model_InterpretationEngine64_ifunc_kq(void)
{
    /* Outputs for Function Call SubSystem: '<S81>/Subsystem' */
    /* SignalConversion generated from: '<S83>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S84>:1' */
    /* '<S84>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_cc =
        Model_InterpretationEngine64_B.TSP_jv;

    /* End of Outputs for SubSystem: '<S81>/Subsystem' */
}

/* Output and update for function-call system: '<S95>/ifunc' */
void Model_InterpretationEngine64_ifunc_ku(void)
{
    /* Outputs for Function Call SubSystem: '<S94>/Subsystem' */
    /* SignalConversion generated from: '<S96>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S97>:1' */
    /* '<S97>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_py = Model_InterpretationEngine64_B.TSP_h;

    /* End of Outputs for SubSystem: '<S94>/Subsystem' */
}

/* Output and update for function-call system: '<S99>/ifunc' */
void Model_InterpretationEngine64_ifunc_k0(void)
{
    int32_T k;

    /* MATLAB Function: '<S92>/ExtractNoiseLevel' */
    /* MATLAB Function: '<S92>/ExtractNoiseLevel' incorporates:
     *  M-S-Function: '<S92>/TSP'
     */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S100>:1' */
    /* '<S100>:1:3' f(); */
    /*  This sums the Power Spectral Density values across all */
    /*  frequency bands. */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/HfNoiseMusicSeparation /NoisePsdLevel/ExtractNoiseLevel': '<S98>:1' */
    /* '<S98>:1:6' NoiseLevel = sum(PSD); */
    Model_InterpretationEngine64_B.NoiseLevel =
        Model_InterpretationEngine64_B.TSP_aj[0];
    for (k = 0; k < 64; k++)
    {
        Model_InterpretationEngine64_B.NoiseLevel +=
            Model_InterpretationEngine64_B.TSP_aj[k + 1];
    }

    /* End of MATLAB Function: '<S92>/ExtractNoiseLevel' */
}

/* Output and update for function-call system: '<S108>/ifunc' */
void Model_InterpretationEngine64_ifunc_d(void)
{
    /* Outputs for Function Call SubSystem: '<S107>/Subsystem' */
    /* SignalConversion generated from: '<S109>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S110>:1' */
    /* '<S110>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_fv =
        Model_InterpretationEngine64_B.TSP_n1;

    /* End of Outputs for SubSystem: '<S107>/Subsystem' */
}

/* Output and update for function-call system: '<S112>/ifunc' */
void Model_InterpretationEngine64_ifunc_bh(void)
{
    /* Outputs for Function Call SubSystem: '<S111>/Subsystem' */
    /* SignalConversion generated from: '<S113>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S114>:1' */
    /* '<S114>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_as =
        Model_InterpretationEngine64_B.TSP_nn;

    /* End of Outputs for SubSystem: '<S111>/Subsystem' */
}

/* Output and update for function-call system: '<S116>/ifunc' */
void Model_InterpretationEngine64_ifunc_bd(void)
{
    /* Outputs for Function Call SubSystem: '<S115>/Subsystem' */
    /* SignalConversion generated from: '<S117>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S118>:1' */
    /* '<S118>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_b0 =
        Model_InterpretationEngine64_B.TSP_n3;

    /* End of Outputs for SubSystem: '<S115>/Subsystem' */
}

/* Output and update for function-call system: '<S120>/ifunc' */
void Model_InterpretationEngine64_ifunc_ad(void)
{
    /* Outputs for Function Call SubSystem: '<S119>/Subsystem' */
    /* SignalConversion generated from: '<S121>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S122>:1' */
    /* '<S122>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_ny =
        Model_InterpretationEngine64_B.TSP_cs;

    /* End of Outputs for SubSystem: '<S119>/Subsystem' */
}

/* Output and update for function-call system: '<S139>/ifunc' */
void Model_InterpretationEngine64_ifunc_af(void)
{
    /* Outputs for Function Call SubSystem: '<S138>/Subsystem' */
    /* SignalConversion generated from: '<S140>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S141>:1' */
    /* '<S141>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_du =
        Model_InterpretationEngine64_B.TSP_br;

    /* End of Outputs for SubSystem: '<S138>/Subsystem' */
}

/* Output and update for function-call system: '<S143>/ifunc' */
void Model_InterpretationEngine64_ifunc_n(void)
{
    /* MATLAB Function: '<S133>/GammaConversion' */
    /* MATLAB Function: '<S133>/GammaConversion' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S144>:1' */
    /* '<S144>:1:3' f(); */
    /*  Converts the filter coefficient back to time constant */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/LfNoiseImpulseRejection/GammaTauS/GammaConversion': '<S142>:1' */
    /*  Keep all values single */
    /* '<S142>:1:6' one1 = single(1.0); */
    /* '<S142>:1:7' zero1 = single(0.0); */
    /*  Handle the divide-by-zero case */
    /* '<S142>:1:10' if (Coef == one1) */
    if (Model_InterpretationEngine64_B.TSP_k == 1.0F)
    {
        /* '<S142>:1:11' State = zero1; */
        Model_InterpretationEngine64_B.State_a = 0.0F;
    }
    else
    {
        /* '<S142>:1:12' else */
        /* '<S142>:1:13' State = one1 / ((one1 - Coef)*DecRate3); */
        Model_InterpretationEngine64_B.State_a = 1.0F / ((1.0F -
            Model_InterpretationEngine64_B.TSP_k) * 1.80288458F);
    }

    /* End of MATLAB Function: '<S133>/GammaConversion' */
}

/* Output and update for function-call system: '<S145>/ifunc' */
void Model_InterpretationEngine64_ifunc_jx(void)
{
    /* MATLAB Function: '<S134>/db20' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S147>:1' */
    /* '<S147>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/LfNoiseImpulseRejection/ImpulseVariance/db20': '<S146>:1' */
    /* '<S146>:1:4' State = db20(abs(TSP1)+eps); */
    /* DB20  Linear quantity to decibels */
    /*    Converts x to dB assuming that x represents volts. */
    /*    y=20*log10(abs(x)); */
    /*  */
    /*  See Also: DB10, UNDB20 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Bill Berardi */
    /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
    /* 'db20:12' y = 20/log(10)*log(abs(x)); */
    Model_InterpretationEngine64_B.State = logf(fabsf
        (Model_InterpretationEngine64_B.TSP_p) + 2.22044605E-16F) * 8.68588924F;
}

/*
 * Output and update for function-call system:
 *    '<S135>/db20 '
 *    '<S136>/db20 '
 *    '<S137>/db20 '
 */
void Model_InterpretationEngine64_db20(real32_T rtu_TSP1,
    B_db20_Model_InterpretationEngine64_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/LfNoiseImpulseRejection/MusicVariance/db20 ': '<S149>:1' */
    /* '<S149>:1:4' State = db20(abs(TSP1) + eps); */
    /* DB20  Linear quantity to decibels */
    /*    Converts x to dB assuming that x represents volts. */
    /*    y=20*log10(abs(x)); */
    /*  */
    /*  See Also: DB10, UNDB20 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Bill Berardi */
    /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
    /* 'db20:12' y = 20/log(10)*log(abs(x)); */
    localB->State = logf(fabsf(rtu_TSP1) + 2.22044605E-16F) * 8.68588924F;
}

/* Output and update for function-call system: '<S148>/ifunc' */
void Model_InterpretationEngine64_ifunc_px(void)
{
    /* MATLAB Function: '<S135>/db20 ' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S150>:1' */
    /* '<S150>:1:3' f(); */
    Model_InterpretationEngine64_db20(Model_InterpretationEngine64_B.TSP_in,
        &Model_InterpretationEngine64_B.sf_db20_g);
}

/* Output and update for function-call system: '<S151>/ifunc' */
void Model_InterpretationEngine64_ifunc_f4(void)
{
    /* MATLAB Function: '<S136>/db20 ' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S153>:1' */
    /* '<S153>:1:3' f(); */
    Model_InterpretationEngine64_db20(Model_InterpretationEngine64_B.TSP_jw,
        &Model_InterpretationEngine64_B.sf_db20_co);
}

/* Output and update for function-call system: '<S154>/ifunc' */
void Model_InterpretationEngine64_ifunc_pe(void)
{
    /* MATLAB Function: '<S137>/db20 ' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S156>:1' */
    /* '<S156>:1:3' f(); */
    Model_InterpretationEngine64_db20(Model_InterpretationEngine64_B.TSP_gj,
        &Model_InterpretationEngine64_B.sf_db20_pi);
}

/* Output and update for function-call system: '<S158>/ifunc' */
void Model_InterpretationEngine64_ifunc_hv(void)
{
    /* Outputs for Function Call SubSystem: '<S157>/Subsystem' */
    /* SignalConversion generated from: '<S159>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S160>:1' */
    /* '<S160>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_dw =
        Model_InterpretationEngine64_B.TSP_ih;

    /* End of Outputs for SubSystem: '<S157>/Subsystem' */
}

/* Output and update for function-call system: '<S162>/ifunc' */
void Model_InterpretationEngine64_ifunc_ng(void)
{
    /* Outputs for Function Call SubSystem: '<S161>/Subsystem' */
    /* SignalConversion generated from: '<S163>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S164>:1' */
    /* '<S164>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_ct =
        Model_InterpretationEngine64_B.TSP_nb;

    /* End of Outputs for SubSystem: '<S161>/Subsystem' */
}

/* Output and update for function-call system: '<S166>/ifunc' */
void Model_InterpretationEngine64_ifunc_l(void)
{
    /* Outputs for Function Call SubSystem: '<S165>/Subsystem' */
    /* SignalConversion generated from: '<S167>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S168>:1' */
    /* '<S168>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_ft =
        Model_InterpretationEngine64_B.TSP_bh;

    /* End of Outputs for SubSystem: '<S165>/Subsystem' */
}

/* Output and update for function-call system: '<S170>/ifunc' */
void Model_InterpretationEngine64_ifunc_nv(void)
{
    /* Outputs for Function Call SubSystem: '<S169>/Subsystem' */
    /* SignalConversion generated from: '<S171>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S172>:1' */
    /* '<S172>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_o = Model_InterpretationEngine64_B.TSP_gl;

    /* End of Outputs for SubSystem: '<S169>/Subsystem' */
}

/* Output and update for function-call system: '<S174>/ifunc' */
void Model_InterpretationEngine64_ifunc_b0(void)
{
    /* Outputs for Function Call SubSystem: '<S173>/Subsystem' */
    /* SignalConversion generated from: '<S175>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S176>:1' */
    /* '<S176>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_a = Model_InterpretationEngine64_B.TSP_n0;

    /* End of Outputs for SubSystem: '<S173>/Subsystem' */
}

/* Output and update for function-call system: '<S178>/ifunc' */
void Model_InterpretationEngine64_ifunc_hz(void)
{
    /* Outputs for Function Call SubSystem: '<S177>/Subsystem' */
    /* SignalConversion generated from: '<S179>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S180>:1' */
    /* '<S180>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_pp = Model_InterpretationEngine64_B.TSP_e;

    /* End of Outputs for SubSystem: '<S177>/Subsystem' */
}

/* Output and update for function-call system: '<S182>/ifunc' */
void Model_InterpretationEngine64_ifunc_nu(void)
{
    /* Outputs for Function Call SubSystem: '<S181>/Subsystem' */
    /* SignalConversion generated from: '<S183>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S184>:1' */
    /* '<S184>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_fk =
        Model_InterpretationEngine64_B.TSP_o5;

    /* End of Outputs for SubSystem: '<S181>/Subsystem' */
}

/* Output and update for function-call system: '<S190>/ifunc' */
void Model_InterpretationEngine64_ifunc_jq(void)
{
    /* Outputs for Function Call SubSystem: '<S189>/Subsystem' */
    /* SignalConversion generated from: '<S191>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S192>:1' */
    /* '<S192>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_j = Model_InterpretationEngine64_B.TSP_oi;

    /* End of Outputs for SubSystem: '<S189>/Subsystem' */
}

/* Output and update for function-call system: '<S194>/ifunc' */
void Model_InterpretationEngine64_ifunc_ne(void)
{
    /* Outputs for Function Call SubSystem: '<S193>/Subsystem' */
    /* SignalConversion generated from: '<S195>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S196>:1' */
    /* '<S196>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_da =
        Model_InterpretationEngine64_B.TSP_kq;

    /* End of Outputs for SubSystem: '<S193>/Subsystem' */
}

/* Output and update for function-call system: '<S198>/ifunc' */
void Model_InterpretationEngine64_ifunc_g(void)
{
    /* Outputs for Function Call SubSystem: '<S197>/Subsystem' */
    /* SignalConversion generated from: '<S199>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S200>:1' */
    /* '<S200>:1:3' f(); */
    Model_InterpretationEngine64_B.In1 = Model_InterpretationEngine64_B.TSP;

    /* End of Outputs for SubSystem: '<S197>/Subsystem' */
}

/* Output and update for function-call system: '<S205>/ifunc' */
void Model_InterpretationEngine64_ifunc_nq(void)
{
    /* Outputs for Function Call SubSystem: '<S204>/Subsystem' */
    /* SignalConversion generated from: '<S206>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S207>:1' */
    /* '<S207>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_f5 =
        Model_InterpretationEngine64_B.TSP_hv;

    /* End of Outputs for SubSystem: '<S204>/Subsystem' */
}

/* Output and update for function-call system: '<S209>/ifunc' */
void Model_InterpretationEngine64_ifunc_c(void)
{
    /* Outputs for Function Call SubSystem: '<S208>/Subsystem' */
    /* SignalConversion generated from: '<S210>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S211>:1' */
    /* '<S211>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_d0 =
        Model_InterpretationEngine64_B.TSP_ah;

    /* End of Outputs for SubSystem: '<S208>/Subsystem' */
}

/* Output and update for function-call system: '<S213>/ifunc' */
void Model_InterpretationEngine64_ifunc_bo(void)
{
    /* Outputs for Function Call SubSystem: '<S212>/Subsystem' */
    /* SignalConversion generated from: '<S214>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S215>:1' */
    /* '<S215>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_lh =
        Model_InterpretationEngine64_B.TSP_fd;

    /* End of Outputs for SubSystem: '<S212>/Subsystem' */
}

/* Output and update for function-call system: '<S222>/ifunc' */
void Model_InterpretationEngine64_ifunc_fl(void)
{
    /* Outputs for Function Call SubSystem: '<S221>/Subsystem' */
    /* SignalConversion generated from: '<S223>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S224>:1' */
    /* '<S224>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_n =
        Model_InterpretationEngine64_B.TSP_ajv;

    /* End of Outputs for SubSystem: '<S221>/Subsystem' */
}

/* Output and update for function-call system: '<S226>/ifunc' */
void Model_InterpretationEngine64_ifunc_bg(void)
{
    /* Outputs for Function Call SubSystem: '<S225>/Subsystem' */
    /* SignalConversion generated from: '<S227>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S228>:1' */
    /* '<S228>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_cr =
        Model_InterpretationEngine64_B.TSP_hc;

    /* End of Outputs for SubSystem: '<S225>/Subsystem' */
}

/* Output and update for function-call system: '<S233>/ifunc' */
void Model_InterpretationEngine64_ifunc_jw(void)
{
    /* Outputs for Function Call SubSystem: '<S232>/Subsystem' */
    /* SignalConversion generated from: '<S234>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S235>:1' */
    /* '<S235>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_h = Model_InterpretationEngine64_B.TSP_ej;

    /* End of Outputs for SubSystem: '<S232>/Subsystem' */
}

/* Output and update for function-call system: '<S237>/ifunc' */
void Model_InterpretationEngine64_ifunc_a4(void)
{
    /* Outputs for Function Call SubSystem: '<S236>/Subsystem' */
    /* SignalConversion generated from: '<S238>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S239>:1' */
    /* '<S239>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_p = Model_InterpretationEngine64_B.TSP_fy;

    /* End of Outputs for SubSystem: '<S236>/Subsystem' */
}

/* Output and update for function-call system: '<S247>/ifunc' */
void Model_InterpretationEngine64_ifunc_d3(void)
{
    /* Outputs for Function Call SubSystem: '<S246>/Subsystem' */
    /* SignalConversion generated from: '<S248>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S249>:1' */
    /* '<S249>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_fo =
        Model_InterpretationEngine64_B.TSP_np;

    /* End of Outputs for SubSystem: '<S246>/Subsystem' */
}

/* Output and update for function-call system: '<S256>/ifunc' */
void Model_InterpretationEngine64_ifunc_gt(void)
{
    /* Outputs for Function Call SubSystem: '<S255>/Subsystem' */
    /* SignalConversion generated from: '<S257>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S258>:1' */
    /* '<S258>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_k = Model_InterpretationEngine64_B.TSP_m;

    /* End of Outputs for SubSystem: '<S255>/Subsystem' */
}

/* Output and update for function-call system: '<S260>/ifunc' */
void Model_InterpretationEngine64_ifunc_lk(void)
{
    /* Outputs for Function Call SubSystem: '<S259>/Subsystem' */
    /* SignalConversion generated from: '<S261>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S262>:1' */
    /* '<S262>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_f = Model_InterpretationEngine64_B.TSP_g;

    /* End of Outputs for SubSystem: '<S259>/Subsystem' */
}

/* Output and update for function-call system: '<S264>/ifunc' */
void Model_InterpretationEngine64_ifunc_nj(void)
{
    /* Outputs for Function Call SubSystem: '<S263>/Subsystem' */
    /* SignalConversion generated from: '<S265>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S266>:1' */
    /* '<S266>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_ez =
        Model_InterpretationEngine64_B.TSP_lr;

    /* End of Outputs for SubSystem: '<S263>/Subsystem' */
}

/* Output and update for function-call system: '<S277>/ifunc' */
void Model_InterpretationEngine64_ifunc_e(void)
{
    /* Outputs for Function Call SubSystem: '<S276>/Subsystem' */
    /* SignalConversion generated from: '<S278>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S279>:1' */
    /* '<S279>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_b = Model_InterpretationEngine64_B.TSP_b;

    /* End of Outputs for SubSystem: '<S276>/Subsystem' */
}

/* Output and update for function-call system: '<S284>/ifunc' */
void Model_InterpretationEngine64_ifunc_bhr(void)
{
    /* Outputs for Function Call SubSystem: '<S283>/Subsystem' */
    /* SignalConversion generated from: '<S285>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S286>:1' */
    /* '<S286>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_d = Model_InterpretationEngine64_B.TSP_i;

    /* End of Outputs for SubSystem: '<S283>/Subsystem' */
}

/* Output and update for function-call system: '<S291>/ifunc' */
void Model_InterpretationEngine64_ifunc_k3(void)
{
    /* Outputs for Function Call SubSystem: '<S290>/Subsystem' */
    /* SignalConversion generated from: '<S292>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S293>:1' */
    /* '<S293>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_l = Model_InterpretationEngine64_B.TSP_n;

    /* End of Outputs for SubSystem: '<S290>/Subsystem' */
}

/* Output and update for function-call system: '<S298>/ifunc' */
void Model_InterpretationEngine64_ifunc_ld(void)
{
    /* Outputs for Function Call SubSystem: '<S297>/Subsystem' */
    /* SignalConversion generated from: '<S299>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S300>:1' */
    /* '<S300>:1:3' f(); */
    Model_InterpretationEngine64_B.In1_c = Model_InterpretationEngine64_B.TSP_gb;

    /* End of Outputs for SubSystem: '<S297>/Subsystem' */
}

/* Model step function */
void Model_InterpretationEngine64_step(void)
{
    /* End of Outputs for S-Function (InterpretTrigger): '<S16>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S20>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S36>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S40>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S44>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S48>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S52>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S56>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S60>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S64>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S68>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S72>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S78>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S82>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S95>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S99>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S108>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S112>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S116>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S120>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S139>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S143>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S145>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S148>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S151>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S154>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S158>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S162>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S166>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S170>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S174>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S178>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S182>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S190>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S194>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S198>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S205>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S209>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S213>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S222>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S226>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S233>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S237>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S277>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S284>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S291>/S-Function' */
    /* End of Outputs for S-Function (InterpretTrigger): '<S298>/S-Function' */
}

/* Model initialize function */
void Model_InterpretationEngine64_initialize(void)
{
    /* Registration code */

    /* initialize error status */
    rtmSetErrorStatus(Model_InterpretationEngine64_M, (NULL));

    /* block I/O */
    (void) memset(((void *) &Model_InterpretationEngine64_B), 0,
                  sizeof(B_Model_InterpretationEngine64_T));

    /* Initialize subsystem data */
    Model_InterpretationEngine64_PostProcess_initialize();

    /* SystemInitialize for Atomic SubSystem: '<S5>/AudioPilot35' */

    /* user code (Initialize function Body) */

    // Register interpretation engine among the model roots
    Model_InterpretationEngine64_InitializeInterpretationRoot();

    /* End of SystemInitialize for SubSystem: '<S5>/AudioPilot35' */
}

/* Model terminate function */
void Model_InterpretationEngine64_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
