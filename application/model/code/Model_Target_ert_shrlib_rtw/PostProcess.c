/*
 * File: PostProcess.c
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

#include "PostProcess.h"
#include "rt_sys_Enabled_530.h"
#include "qhmath.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "Model_Target_private.h"
#include "rt_sys_Enabled_543.h"
#include "rt_sys_Enabled_536.h"
#include "rt_sys_Enabled_535.h"
#include "math.h"
#include "Model_Target.h"
#include "tsp_capture_settings.h"

/* Declare variables for internal data of system '<S7>/PostProcess' */
B_PostProcess_Model_Target_T Model_Target_PostProcess_B;
DW_PostProcess_Model_Target_T Model_Target_PostProcess_DW;

/* Output and update for function-call system: '<S2221>/REQ' */
void HandleReqPostProcessMuteSet(void)
{
    real32_T quantum_ms;
    real32_T x;

    /* MATLAB Function: '<S2219>/calculate_ramp_rate' */
    /* MATLAB Function: '<S2219>/calculate_ramp_rate' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S2228>:1' */
    /* '<S2228>:1:3' go(); */
    Model_Target_calculate_ramp_rate
        (Model_TargetPostProcessMuteSetRtcOut.REQ_ramp_db_per_second,
         Model_TargetPostProcessMuteSetRtcOut.REQ_ramp_milliseconds,
         Model_Target_PostProcess_p0_b0.MuteRampTime,
         &Model_Target_PostProcess_B.sf_calculate_ramp_rate_g);

    /* MATLAB Function: '<S2220>/get_ramp_coeffs' */
    /* MATLAB Function: '<S2220>/get_ramp_coeffs' incorporates:
     *  S-Function (AudioStats_MEX): '<S2220>/Audio Stats'
     */
    x = Model_Target_PostProcess_B.sf_calculate_ramp_rate_g.ramptime;

    /* MATLAB Function 'MuteRamper/get_ramp_coeffs': '<S2233>:1' */
    /* '<S2233>:1:5' targetLinearGain = single(1.0); */
    Model_TargetControlDsms.PostProcessMuteTargetLinearGain = 1.0F;

    /* '<S2233>:1:7' if muteSwitch */
    if (Model_TargetPostProcessMuteSetRtcOut.REQ_mute_switch != 0U)
    {
        /* '<S2233>:1:8' targetLinearGain = single(max(0, silentGainLinear)); */
        Model_TargetControlDsms.PostProcessMuteTargetLinearGain = 4.7315126E-7F;
    }

    /*  % Nudge the gain values a bit if they are sitting at zero. */
    /*  % If current gain is zero, replace with a value very close to zero. What we */
    /*  % really want is a value which is on the edge of perception - not too small */
    /*  % or large. If the value is too small, we'll waste some of our ramp time */
    /*  % in perceived silence. If the value is too large, the audio will lurch */
    /*  % into perceptability at the start of the ramp. */
    /*  % So, 'max(currentGainValue, silentGainLinear)' & 'max(TargetGain, silentGainLinear)' are */
    /*  % used in equations */
    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
    /*  Equivalent ramp rate is therefore calculated as follows: */
    /* '<S2233>:1:24' if (rampingRate_dBPerSec) */
    if (Model_Target_PostProcess_B.sf_calculate_ramp_rate_g.rampRate != 0.0F)
    {
        /* '<S2233>:1:25' currentGain_db = 20*log10(max(currentGainValue, silentGainLinear)); */
        /* '<S2233>:1:26' targetGain_db = 20*log10( targetLinearGain); */
        /* '<S2233>:1:27' diff = abs(currentGain_db - targetGain_db); */
        /* '<S2233>:1:28' rampingTime_ms = diff / single(rampingRate_dBPerSec) * 1000; */
        x = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f(fmaxf
                           (Model_Target_PostProcess_B.DataStoreRead,
                            4.7315126E-7F)) - 20.0F * qhmath_log10_f
                          (Model_TargetControlDsms.PostProcessMuteTargetLinearGain)),
                         Model_Target_PostProcess_B.sf_calculate_ramp_rate_g.rampRate)
            * 1000.0F;
    }

    /* '<S2233>:1:31' quantum_ms = 1000 * frameSize / Fs_Hz; */
    quantum_ms = qhmath_div_f(32000.0F, 48000.0);

    /* '<S2233>:1:32' numFrames = rampingTime_ms / quantum_ms; */
    /*  Do a ceil rather than a round to insure that we create enough */
    /*  frames. i.e. a fraction of a frame is promoted to an addition frame */
    /* '<S2233>:1:35' nFrames = max (1, ceil(numFrames)); */
    Model_TargetControlDsms.PostProcessMuteNframes = fmaxf(1.0F, qhmath_ceil_f
        (qhmath_div_f(x, quantum_ms)));

    /* '<S2233>:1:36' quantized_rampTime_ms = nFrames * quantum_ms; */
    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain differencebetween target and current value. */
    /*  Ramper's coefficient is therefore calculated as follows: */
    /*  */
    /*    TargetGain = CurrentGain *( RampCoef ^ (Fs*RampTime_ms/1000) ) */
    /*  */
    /*  therefore... */
    /*  */
    /*                      log(TargetGain/CurrentGain) */
    /*    log(RampCoef) = ------------------------------ */
    /*                         Fs*(RampTime_ms/1000) */
    /*  */
    /* '<S2233>:1:50' ramping_coeff= exp(log( targetLinearGain /max(currentGainValue, silentGainLinear) ) / (Fs_Hz * quantized_rampTime_ms / 1000)); */
    Model_Target_PostProcess_B.ramping_coeff = qhmath_div_f(qhmath_log_f
        (qhmath_div_f(Model_TargetControlDsms.PostProcessMuteTargetLinearGain,
                      fmaxf(Model_Target_PostProcess_B.DataStoreRead,
                            4.7315126E-7F))), qhmath_div_f
        (Model_TargetControlDsms.PostProcessMuteNframes * quantum_ms * 48000.0,
         1000.0F));
    Model_Target_PostProcess_B.ramping_coeff = qhmath_exp_f
        (Model_Target_PostProcess_B.ramping_coeff);

    /* End of MATLAB Function: '<S2220>/get_ramp_coeffs' */
}

/* Output and update for function-call system: '<S2244>/REQ' */
void HandleReqPostProcessPostLimiterEqShutdown(void)
{
    /* MATLAB Function: '<S2247>/Reset' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S2253>:1' */
    /* '<S2253>:1:3' go(); */
    /*  Reset the states DSM to zeros */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/Generic/Reset': '<S2249>:1' */
    /* '<S2249>:1:6' states(:) = 0; */
    memset(&Model_Target_PostProcess_DW.states[0], 0, sizeof(real32_T) << 8U);
}

/* System initialize for atomic system: '<S7>/PostProcess' */
void Model_Target_PostProcess_Init(void)
{
    int32_T i;

    /* Start for DataStoreMemory: '<S2188>/CurrentGain' */
    Model_Target_PostProcess_DW.CurrentGainValue = 1.0F;

    /* InitializeConditions for Delay: '<S2189>/Delay1' */
    Model_Target_PostProcess_DW.icLoad = true;

    /* InitializeConditions for Delay: '<S2189>/Delay2' */
    Model_Target_PostProcess_DW.Delay2_DSTATE_i = 1.0F;

    /* SystemInitialize for Atomic SubSystem: '<S2220>/Ramping_Subsystem' */
    /* SystemInitialize for IfAction SubSystem: '<S2234>/ifActionSubsystem' */
    /* InitializeConditions for DiscreteFilter: '<S2237>/ramping_filter' */
    Model_Target_PostProcess_DW.ramping_filter_icLoad = 1U;

    /* End of SystemInitialize for SubSystem: '<S2234>/ifActionSubsystem' */
    /* End of SystemInitialize for SubSystem: '<S2220>/Ramping_Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S2216>/MATLAB Function' */
    /* '<S2198>:1:10' EBL_EnableCounter=int16(0); */
    /* '<S2217>:1:22' state = single(1 * ones(1,channel_count)); */
    for (i = 0; i < 24; i++)
    {
        Model_Target_PostProcess_DW.state[i] = 1.0F;
    }

    /* End of SystemInitialize for MATLAB Function: '<S2216>/MATLAB Function' */
}

/* Output and update for atomic system: '<S7>/PostProcess' */
void Model_Target_PostProcess(void)
{
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    real_T rtb_Add1_db[24];
    real_T rtb_DataTypeConversion[24];
    real_T coeffIdx;
    real_T rtb_SumofElements;
    int32_T i;
    int32_T rtb_DataStoreRead1_fv_tmp;
    int32_T s;
    real32_T rtb_Merge_in[32];
    real32_T downCoeff;
    real32_T gdiff;
    real32_T gp;
    real32_T lpfCoeff;
    real32_T rtb_DataStoreRead1_fv_tmp_tmp;
    real32_T rtb_DataStoreRead1_h;
    real32_T rtb_Delay_ed;
    real32_T rtb_Magsq_f;
    real32_T rtb_Max_bj;
    real32_T upCoeff;
    real32_T *attack_param;
    real32_T *decay_param;
    real32_T *k1_param;
    real32_T *maxAttack_param;
    uint32_T st;
    boolean_T rtb_LogicalOperator1_f;
    boolean_T rtb_Merge_ps;

    /* DataStoreRead: '<S2220>/Data Store Read' */
    Model_Target_PostProcess_B.DataStoreRead =
        Model_TargetControlDsms.PostProcessMuteCurrentGain;

    /* DataStoreRead: '<S2220>/Data Store Read1' */
    rtb_DataStoreRead1_h =
        Model_TargetControlDsms.PostProcessMuteTargetLinearGain;

    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S2221>/RTC Request Response Trigger' */

    /* Outputs for Atomic SubSystem: '<S2220>/Ramping_Subsystem' */
    /* MinMax: '<S2234>/Max' incorporates:
     *  Constant: '<S2234>/minGain'
     */
    rtb_Max_bj = fmaxf(Model_Target_PostProcess_B.DataStoreRead, 4.7315126E-7F);

    /* If: '<S2234>/If' incorporates:
     *  Abs: '<S2234>/Abs3'
     *  Constant: '<S2220>/snapThresh'
     *  DataStoreRead: '<S2234>/frames'
     *  Sum: '<S2234>/Add'
     */
    if ((qhmath_abs_f(rtb_DataStoreRead1_h - rtb_Max_bj) > 1.0E-9F) &&
            (Model_TargetControlDsms.PostProcessMuteNframes > 0.0F))
    {
        /* Outputs for IfAction SubSystem: '<S2234>/ifActionSubsystem' incorporates:
         *  ActionPort: '<S2237>/Action Port'
         */
        /* DataStoreWrite: '<S2237>/Data Store Write' incorporates:
         *  Constant: '<S2237>/Constant1'
         *  Sum: '<S2237>/Add'
         */
        Model_TargetControlDsms.PostProcessMuteNframes =
            Model_TargetControlDsms.PostProcessMuteNframes - 1.0F;

        /* If: '<S2239>/If' incorporates:
         *  Delay: '<S2239>/Delay'
         *  Sum: '<S2239>/Add2'
         */
        if (rtb_DataStoreRead1_h - Model_Target_PostProcess_DW.Delay_DSTATE_l ==
            0.0F)
        {
            /* Outputs for IfAction SubSystem: '<S2239>/If Action Subsystem' incorporates:
             *  ActionPort: '<S2240>/Action Port'
             */
            Model_Target_IfActionSubsystem(&rtb_Merge_ps);

            /* End of Outputs for SubSystem: '<S2239>/If Action Subsystem' */
        }
        else
        {
            /* Outputs for IfAction SubSystem: '<S2239>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S2241>/Action Port'
             */
            Model_Target_IfActionSubsystem1(&rtb_Merge_ps);

            /* End of Outputs for SubSystem: '<S2239>/If Action Subsystem1' */
        }

        /* End of If: '<S2239>/If' */

        /* DiscreteFilter: '<S2237>/ramping_filter' incorporates:
         *  Merge: '<S2234>/Merge'
         *  Product: '<S2237>/Matrix Multiply'
         *  Product: '<S2238>/Multiply'
         */
        if (rtb_Merge_ps)
        {
            Model_Target_PostProcess_DW.ramping_filter_icLoad = 1U;
        }

        if (Model_Target_PostProcess_DW.ramping_filter_icLoad != 0)
        {
            Model_Target_PostProcess_DW.ramping_filter_states =
                Model_Target_PostProcess_B.ramping_coeff * rtb_Max_bj;
        }

        s = 0;
        for (i = 0; i < 32; i++)
        {
            rtb_Merge_in[s] = Model_Target_PostProcess_DW.ramping_filter_states;
            Model_Target_PostProcess_DW.ramping_filter_states = 0.0F -
                -Model_Target_PostProcess_B.ramping_coeff * rtb_Merge_in[s];
            s++;
        }

        /* End of DiscreteFilter: '<S2237>/ramping_filter' */

        /* Update for Delay: '<S2239>/Delay' */
        Model_Target_PostProcess_DW.Delay_DSTATE_l = rtb_DataStoreRead1_h;

        /* Update for DiscreteFilter: '<S2237>/ramping_filter' */
        Model_Target_PostProcess_DW.ramping_filter_icLoad = 0U;

        /* End of Outputs for SubSystem: '<S2234>/ifActionSubsystem' */
    }
    else
    {
        /* Outputs for IfAction SubSystem: '<S2234>/elseActionSubsystem' incorporates:
         *  ActionPort: '<S2236>/Action Port'
         */
        Model_Target_elseActionSubsystem(rtb_DataStoreRead1_h, rtb_Merge_in);

        /* End of Outputs for SubSystem: '<S2234>/elseActionSubsystem' */
    }

    /* End of If: '<S2234>/If' */

    /* S-Function (sdspperm2): '<S2231>/Variable Selector' incorporates:
     *  DataStoreWrite: '<S2220>/Data Store Write'
     *  Merge: '<S2234>/Merge'
     */
    Model_TargetControlDsms.PostProcessMuteCurrentGain = rtb_Merge_in[31];

    /* Outputs for Iterator SubSystem: '<S2235>/For Each Subsystem' incorporates:
     *  ForEach: '<S2242>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 32; ForEach_itr++)
    {
        /* ForEachSliceSelector generated from: '<S2242>/In1' incorporates:
         *  Merge: '<S2234>/Merge'
         */
        rtb_DataStoreRead1_h = rtb_Merge_in[ForEach_itr];

        /* ForEachSliceAssignment generated from: '<S2242>/Out1' incorporates:
         *  ForEachSliceSelector generated from: '<S2242>/In2'
         *  Product: '<S2242>/Multiply'
         */
        for (s = 0; s < 24; s++)
        {
            /* ForEachSliceSelector generated from: '<S2242>/In2' */
            i = (s << 5) + ForEach_itr;
            Model_Target_PostProcess_B.ImpAsg_InsertedFor_Out1_at_inport_0[i] =
                Model_Target_B.out[i] * rtb_DataStoreRead1_h;
        }

        /* End of ForEachSliceAssignment generated from: '<S2242>/Out1' */
    }

    /* End of Outputs for SubSystem: '<S2235>/For Each Subsystem' */
    /* End of Outputs for SubSystem: '<S2220>/Ramping_Subsystem' */
    /* End of Outputs for S-Function (RTC_NTF): '<S2221>/NTF Trigger' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S2185>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S2186>/RTC Request Response Trigger' */
    /* MATLAB Function: '<S2216>/MATLAB Function' incorporates:
     *  ForEachSliceAssignment generated from: '<S2242>/Out1'
     *  S-Function (TOP_MEX): '<S2216>/attack'
     *  S-Function (TOP_MEX): '<S2216>/attack1'
     *  S-Function (TOP_MEX): '<S2216>/decay'
     *  S-Function (TOP_MEX): '<S2216>/decay1'
     *  S-Function (TOP_MEX): '<S2216>/k1'
     *  S-Function (TOP_MEX): '<S2216>/k2'
     *  S-Function (TOP_MEX): '<S2216>/maxAttack'
     *  S-Function (TOP_MEX): '<S2216>/maxAttack1'
     */
    /*  This is the main function for the Limiter. */
    /*  It takes an audio input, as well as 8 tunable variables (2 sets of 4), */
    /*  which are attack, maxAttack, k1, and decay. It will limit, or apply */
    /*  a gain reduction, to any samples that are essentially above a  */
    /*  pre-set threshold.  */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function': '<S2217>:1' */
    /*  Grab data from input */
    /* '<S2217>:1:10' y = coder.nullcopy(u); */
    /* '<S2217>:1:11' [frame_size, channel_count] = size(u); */
    /*  Initialize memory */
    /*  attack = single(2.5768580901e-002 * ones(1,channel_count)); */
    /*  decay = single(1.0002610981e+000 * ones(1,channel_count)); */
    /* '<S2217>:1:16' maxGain = single(1); */
    /*  maxAttack = single(3.1622776602e-001 * ones(1,channel_count)); */
    /*  k1 = single(2.8631756556e-002 * ones(1,channel_count)); */
    /* '<S2217>:1:21' if isempty(state) */
    /* '<S2217>:1:25' if (param_set == 1) */
    if (Model_TargetPostProcessLimiterSoftclipParamSetRtcOut.REQ_paramSet == 1U)
    {
        /* '<S2217>:1:26' attack_param = attack; */
        /* '<S2217>:1:27' k1_param = k1; */
        /* '<S2217>:1:28' decay_param = decay; */
        /* '<S2217>:1:29' maxAttack_param = maxAttack; */
        attack_param = (&(Model_Target_PostProcess_p0_b0.Limiterattack[0]));
        k1_param = (&(Model_Target_PostProcess_p0_b0.Limiterk1[0]));
        decay_param = (&(Model_Target_PostProcess_p0_b0.Limiterdecay[0]));
        maxAttack_param = (&(Model_Target_PostProcess_p0_b0.LimitermaxAttack[0]));
    }
    else
    {
        /* '<S2217>:1:30' else */
        /* '<S2217>:1:31' attack_param = attack_low; */
        /* '<S2217>:1:32' k1_param = k1_low; */
        /* '<S2217>:1:33' decay_param = decay_low; */
        /* '<S2217>:1:34' maxAttack_param = maxAttack_low; */
        attack_param = (&(Model_Target_PostProcess_p0_b0.Limiterattack_low[0]));
        k1_param = (&(Model_Target_PostProcess_p0_b0.Limiterk1_low[0]));
        decay_param = (&(Model_Target_PostProcess_p0_b0.Limiterdecay_low[0]));
        maxAttack_param =
            (&(Model_Target_PostProcess_p0_b0.LimitermaxAttack_low[0]));
    }

    /* '<S2217>:1:38' Limiter_Active = uint32(0); */
    /*  Check for a disable RTC message, pass audio through unaffected if so */
    /* '<S2217>:1:40' if (disableMsg) */
    if (Model_TargetPostProcessLimiterSoftclipDisableRtcOut.REQ_disableMsg != 0U)
    {
        /* '<S2217>:1:41' y(:) = u(:); */
        memcpy(&Model_Target_PostProcess_B.y_b[0],
               &Model_Target_PostProcess_B.ImpAsg_InsertedFor_Out1_at_inport_0[0],
               768U * sizeof(real32_T));
    }
    else
    {
        /* '<S2217>:1:42' else */
        /*  Process the audio */
        /* '<S2217>:1:44' for i = 1:channel_count */
        for (i = 0; i < 24; i++)
        {
            /* '<S2217>:1:45' k0 = 1 + attack_param(i); */
            /* '<S2217>:1:46' g1 = state(i); */
            rtb_DataStoreRead1_h = Model_Target_PostProcess_DW.state[i];

            /* '<S2217>:1:47' temp = single(0); */
            /* '<S2217>:1:48' temp1 = temp; */
            /* '<S2217>:1:49' for s = 1:frame_size */
            for (s = 0; s < 32; s++)
            {
                rtb_Max_bj = attack_param[i];

                /*  Compute the gain for this sample. Implementation copied from BDSP */
                /* '<S2217>:1:51' p1 = k1_param(i) * g1; */
                /* '<S2217>:1:52' p2 = u(s, i); */
                /* '<S2217>:1:53' p2 = abs(p2); */
                /* '<S2217>:1:54' temp = temp + p2; */
                /* '<S2217>:1:55' g1 = g1 * decay_param(i); */
                /* '<S2217>:1:56' p2 = p2 * p1; */
                /* '<S2217>:1:57' p2 = max(p2, attack_param(i)); */
                /* '<S2217>:1:58' p2 = k0 - p2; */
                /* '<S2217>:1:59' p2 = max(p2, maxAttack_param(i)); */
                /* '<S2217>:1:60' g1 = g1 * p2; */
                /* '<S2217>:1:61' g1 = min(g1, maxGain); */
                rtb_DataStoreRead1_fv_tmp = (i << 5) + s;
                rtb_Delay_ed =
                    Model_Target_PostProcess_B.ImpAsg_InsertedFor_Out1_at_inport_0
                    [rtb_DataStoreRead1_fv_tmp];
                rtb_DataStoreRead1_h = fminf(fmaxf((rtb_Max_bj + 1.0F) - fmaxf
                    (k1_param[i] * rtb_DataStoreRead1_h * qhmath_abs_f
                     (rtb_Delay_ed), rtb_Max_bj), maxAttack_param[i]) *
                    (rtb_DataStoreRead1_h * decay_param[i]), 1.0F);

                /*  Apply the gain */
                /* '<S2217>:1:63' y(s, i) = u(s, i) * g1; */
                Model_Target_PostProcess_B.y_b[rtb_DataStoreRead1_fv_tmp] =
                    rtb_Delay_ed * rtb_DataStoreRead1_h;

                /* '<S2217>:1:64' p3 = abs(y(s,i)); */
                /* '<S2217>:1:65' temp1 = temp1 + p3; */
            }

            /* '<S2217>:1:68' state(i) = g1; */
            Model_Target_PostProcess_DW.state[i] = rtb_DataStoreRead1_h;

            /* '<S2217>:1:69' if temp1 < temp */
        }
    }

    /* End of MATLAB Function: '<S2216>/MATLAB Function' */

    /* Math: '<S2190>/Magsq'
     *
     * About '<S2190>/Magsq':
     *  Operator: magnitude^2
     */
    for (i = 0; i < 768; i++)
    {
        rtb_DataStoreRead1_h = Model_Target_PostProcess_B.y_b[i];
        Model_Target_PostProcess_B.Magsq[i] = rtb_DataStoreRead1_h *
            rtb_DataStoreRead1_h;
    }

    /* End of Math: '<S2190>/Magsq' */
    for (i = 0; i < 24; i++)
    {
        /* Sum: '<S2190>/Add' incorporates:
         *  Math: '<S2190>/Magsq'
         *
         * About '<S2190>/Magsq':
         *  Operator: magnitude^2
         */
        s = i << 5;
        rtb_DataStoreRead1_h = -0.0F;
        for (rtb_DataStoreRead1_fv_tmp = 0; rtb_DataStoreRead1_fv_tmp < 32;
                rtb_DataStoreRead1_fv_tmp++)
        {
            rtb_DataStoreRead1_h += Model_Target_PostProcess_B.Magsq[s +
                rtb_DataStoreRead1_fv_tmp];
        }

        /* Sum: '<S2196>/Add1' incorporates:
         *  Delay: '<S2196>/Delay2'
         *  Product: '<S2196>/Product3'
         *  Product: '<S2196>/Product4'
         *  Sum: '<S2190>/Add'
         */
        rtb_SumofElements = rtb_DataStoreRead1_h *
            Model_Target_PostProcess_ConstB.Subtract1 +
            Model_Target_PostProcess_ConstB.MathFunction *
            Model_Target_PostProcess_DW.Delay2_DSTATE[i];

        /* Gain: '<S2189>/Multiply' incorporates:
         *  Gain: '<S2189>/Multiply1'
         *  Math: '<S2189>/Log10'
         *
         * About '<S2189>/Log10':
         *  Operator: log10
         */
        coeffIdx = log10(0.0625 * rtb_SumofElements) * 10.0;

        /* DataTypeConversion: '<S2189>/Data Type Conversion1' */
        Model_Target_PostProcess_B.DataTypeConversion1[i] = (real32_T)coeffIdx;

        /* Sum: '<S2196>/Add1' */
        rtb_Add1_db[i] = rtb_SumofElements;

        /* Gain: '<S2189>/Multiply' incorporates:
         *  DataTypeConversion: '<S2209>/Data Type Conversion'
         */
        rtb_DataTypeConversion[i] = coeffIdx;
    }

    /* Delay: '<S2189>/Delay1' incorporates:
     *  DataStoreRead: '<S2188>/Data Store Read'
     */
    if (Model_Target_PostProcess_DW.icLoad)
    {
        Model_Target_PostProcess_DW.Delay1_DSTATE =
            Model_Target_PostProcess_DW.CurrentGainValue;
    }

    /* Delay: '<S2189>/Delay1' */
    Model_Target_PostProcess_B.CurrentGain =
        Model_Target_PostProcess_DW.Delay1_DSTATE;

    /* Sum: '<S2209>/Sum of Elements' */
    rtb_SumofElements = -0.0;
    for (rtb_DataStoreRead1_fv_tmp = 0; rtb_DataStoreRead1_fv_tmp < 24;
            rtb_DataStoreRead1_fv_tmp++)
    {
        /* DataTypeConversion: '<S2209>/Data Type Conversion' incorporates:
         *  RelationalOperator: '<S2209>/Relational Operator'
         */
        coeffIdx = (rtb_DataTypeConversion[rtb_DataStoreRead1_fv_tmp] >
                    Model_Target_PostProcess_ConstB.DEBUG_EBL_THRESHOLD_DBSPL);

        /* Sum: '<S2209>/Sum of Elements' */
        rtb_SumofElements += coeffIdx;

        /* DataTypeConversion: '<S2209>/Data Type Conversion' incorporates:
         *  RelationalOperator: '<S2209>/Relational Operator'
         */
        rtb_DataTypeConversion[rtb_DataStoreRead1_fv_tmp] = coeffIdx;
    }

    /* Delay: '<S2189>/Delay2' */
    rtb_Max_bj = Model_Target_PostProcess_DW.Delay2_DSTATE_i;

    /* Logic: '<S2189>/Logical Operator' incorporates:
     *  Delay: '<S2189>/Delay2'
     *  RelationalOperator: '<S2189>/Relational Operator2'
     *  RelationalOperator: '<S2189>/Relational Operator4'
     */
    rtb_Merge_ps = ((rtb_SumofElements >
                     Model_Target_PostProcess_ConstB.RoundingFunction_b) &&
                    (Model_Target_PostProcess_DW.Delay2_DSTATE_i >=
                     Model_Target_PostProcess_ConstB.RoundingFunction1));

    /* Logic: '<S2189>/Logical Operator1' incorporates:
     *  Delay: '<S2189>/Delay2'
     *  RelationalOperator: '<S2189>/Relational Operator1'
     *  RelationalOperator: '<S2189>/Relational Operator3'
     */
    rtb_LogicalOperator1_f = ((rtb_SumofElements <=
        Model_Target_PostProcess_ConstB.RoundingFunction_b) &&
        (Model_Target_PostProcess_DW.Delay2_DSTATE_i >=
         Model_Target_PostProcess_ConstB.RoundingFunction));

    /* MATLAB Function: '<S2189>/EBL State' incorporates:
     *  Constant: '<S2208>/Constant1'
     */
    /*  */
    /*  Return gain notifications based on current gain and thresholds */
    /*  */
    /* MATLAB Function 'PostProcess/PostProcess/EnergyLimiter/EnergyLimiter1/EnergyRunningAvg /EBL State': '<S2197>:1' */
    /* '<S2197>:1:6' ELNotification = single(0); */
    rtb_DataStoreRead1_h = 0.0F;

    /* '<S2197>:1:7' if((currgain<maxgain)) */
    if (Model_Target_PostProcess_B.CurrentGain < 1.0F)
    {
        /* '<S2197>:1:8' if(aboveth) */
        if (rtb_Merge_ps)
        {
            /*     %% Gain reduction when energy limiter active */
            /* '<S2197>:1:10' ELNotification = single(1.0); */
            rtb_DataStoreRead1_h = 1.0F;
        }

        /* if((currgain==mingain)) */
        /* '<S2197>:1:13' if(belowth) */
        if (rtb_LogicalOperator1_f)
        {
            /*         %% Increased gain notification when energy limiter active */
            /* '<S2197>:1:15' ELNotification= single(2.0); */
            rtb_DataStoreRead1_h = 2.0F;
        }
    }
    else if (Model_Target_PostProcess_B.CurrentGain == 1.0F)
    {
        /* '<S2197>:1:17' elseif(currgain== maxgain) */
        /*     %% No Gain reduction when energy limiter active */
        /* '<S2197>:1:19' ELNotification= single(3.0); */
        rtb_DataStoreRead1_h = 3.0F;
    }
    else
    {
        /* '<S2197>:1:20' else */
        /* '<S2197>:1:21' ELNotification= single(4.0); */
        rtb_DataStoreRead1_h = 4.0F;
    }

    /* End of MATLAB Function: '<S2189>/EBL State' */

    /* Delay: '<S2189>/Delay' */
    /* '<S2197>:1:24' y = single(ELNotification); */
    rtb_Delay_ed = Model_Target_PostProcess_DW.Delay_DSTATE;

    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S2191>/RTC Request Response Trigger' */

    /* DataTypeConversion: '<S2189>/Data Type Conversion4' */
    rtb_DataStoreRead1_fv_tmp_tmp = (real32_T)
        Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_EnableGainLimiter;

    /* MATLAB Function: '<S2189>/EBL Transition' incorporates:
     *  DataTypeConversion: '<S2189>/Data Type Conversion4'
     *  Delay: '<S2189>/Delay3'
     */
    /*  */
    /*  Calculate EBL states */
    /*  */
    /*  Calculate next state and transition from previous state, current state, previous enable */
    /*  flag, and current enable flag */
    /*  */
    /* MATLAB Function 'PostProcess/PostProcess/EnergyLimiter/EnergyLimiter1/EnergyRunningAvg /EBL Transition': '<S2198>:1' */
    /* '<S2198>:1:10' if isempty(EBL_EnableCounter) */
    /*  List of all EBL states and transitions */
    /* '<S2198>:1:13' EBL_EnableFlag_False         = single(0.0); */
    /* '<S2198>:1:14' EBL_EnableFlag_True          = single(1.0); */
    /* '<S2198>:1:15' EBL_StateNoUpdate            = single(0.0); */
    /* '<S2198>:1:16' EBL_StateAttackInProgress    = single(1.0); */
    /* '<S2198>:1:17' EBL_StateRecoveryInProgress  = single(2.0); */
    /* '<S2198>:1:18' EBL_StateDisengaged          = single(3.0); */
    /* '<S2198>:1:19' EBL_TransitionNoChange       = single(0.0); */
    /* '<S2198>:1:20' EBL_TransitionAttackStart    = single(1.0); */
    /* '<S2198>:1:21' EBL_TransitionRecoverDone    = single(2.0); */
    /*  First, check if the enable flag is updated */
    /* '<S2198>:1:24' if(preState==EBL_StateAttackInProgress     && ... */
    /* '<S2198>:1:25'         curEnableFlag==EBL_EnableFlag_True && ... */
    /* '<S2198>:1:26'         preEnableFlag==EBL_EnableFlag_False) */
    if ((rtb_Delay_ed == 1.0F) &&
            (Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_EnableGainLimiter
             == 1.0F) && (Model_Target_PostProcess_DW.Delay3_DSTATE == 0.0F))
    {
        /* '<S2198>:1:27' EBL_EnableCounter = EBL_EnableCounter+1; */
        s = Model_Target_PostProcess_DW.EBL_EnableCounter_d + 1;
        if (Model_Target_PostProcess_DW.EBL_EnableCounter_d + 1 > 32767)
        {
            s = 32767;
        }

        Model_Target_PostProcess_DW.EBL_EnableCounter_d = (int16_T)s;

        /*  EBL enabled while attack in progress */
        /* '<S2198>:1:29' transition=EBL_TransitionAttackStart; */
        Model_Target_PostProcess_B.transition = 1.0F;

        /* '<S2198>:1:30' if(curState == EBL_StateNoUpdate) */
        if (rtb_DataStoreRead1_h == 0.0F)
        {
            /* '<S2198>:1:31' nextState=preState; */
            rtb_DataStoreRead1_h = 1.0F;
        }
        else
        {
            /* '<S2198>:1:32' else */
            /* '<S2198>:1:33' nextState=curState; */
        }

        /*  Check if the EBL state is updated */
        /* '<S2198>:1:39' if(curState == EBL_StateNoUpdate) */
    }
    else if (rtb_DataStoreRead1_h == 0.0F)
    {
        /* '<S2198>:1:40' transition=EBL_TransitionNoChange; */
        Model_Target_PostProcess_B.transition = 0.0F;

        /* '<S2198>:1:41' nextState=preState; */
        rtb_DataStoreRead1_h = rtb_Delay_ed;

        /* '<S2198>:1:43' else */
        /* '<S2198>:1:44' nextState=curState; */
        /*  Determine the transition based on EBL state */
        /* '<S2198>:1:48' if(preState==EBL_StateDisengaged && ... */
        /* '<S2198>:1:49'    curState==EBL_StateAttackInProgress) */
    }
    else if ((rtb_Delay_ed == 3.0F) && (rtb_DataStoreRead1_h == 1.0F))
    {
        /*  attack begins */
        /* '<S2198>:1:51' transition=EBL_TransitionAttackStart; */
        Model_Target_PostProcess_B.transition = 1.0F;
    }
    else if ((rtb_Delay_ed == 2.0F) && (rtb_DataStoreRead1_h == 3.0F))
    {
        /* '<S2198>:1:52' elseif(preState==EBL_StateRecoveryInProgress && ... */
        /* '<S2198>:1:53'        curState==EBL_StateDisengaged) */
        /*  recovery done */
        /* '<S2198>:1:55' transition=EBL_TransitionRecoverDone; */
        Model_Target_PostProcess_B.transition = 2.0F;
    }
    else
    {
        /* '<S2198>:1:56' else */
        /* '<S2198>:1:57' transition=EBL_TransitionNoChange; */
        Model_Target_PostProcess_B.transition = 0.0F;
    }

    /* End of MATLAB Function: '<S2189>/EBL Transition' */

    /* DataTypeConversion: '<S2189>/Data Type Conversion5' */
    rtb_Delay_ed = fmodf(qhmath_floor_f(rtb_DataStoreRead1_h), 65536.0F);

    /* DataTypeConversion: '<S2189>/Data Type Conversion5' */
    Model_Target_PostProcess_B.DataTypeConversion5 = (int16_T)(rtb_Delay_ed <
        0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Delay_ed : (int32_T)
        (int16_T)(uint16_T)rtb_Delay_ed);

    /* DataTypeConversion: '<S2189>/Data Type Conversion6' */
    Model_Target_PostProcess_B.DataTypeConversion6 = (int16_T)
        Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_EnableGainLimiter;

    /* Switch: '<S2189>/Switch' incorporates:
     *  Constant: '<S2189>/Constant'
     *  MinMax: '<S2189>/MinMax'
     *  Product: '<S2189>/Product2'
     *  Switch: '<S2189>/Switch1'
     *  Switch: '<S2189>/Switch2'
     *  Switch: '<S2189>/Switch3'
     */
    if (rtb_Merge_ps)
    {
        rtb_Delay_ed = (real32_T)fmax(Model_Target_PostProcess_B.CurrentGain *
            Model_Target_PostProcess_ConstB.MathFunction2,
            Model_Target_PostProcess_ConstB.MathFunction4);
        rtb_Max_bj = 0.0F;
    }
    else if (rtb_LogicalOperator1_f)
    {
        /* Switch: '<S2189>/Switch1' incorporates:
         *  Constant: '<S2208>/Constant1'
         *  MinMax: '<S2189>/MinMax1'
         *  Product: '<S2189>/Product1'
         */
        rtb_Delay_ed = fminf((real32_T)
                             (Model_Target_PostProcess_ConstB.MathFunction1 *
                              Model_Target_PostProcess_B.CurrentGain), 1.0F);

        /* Switch: '<S2189>/Switch3' incorporates:
         *  Constant: '<S2189>/Constant1'
         */
        rtb_Max_bj = 0.0F;
    }
    else
    {
        /* Switch: '<S2189>/Switch1' */
        rtb_Delay_ed = Model_Target_PostProcess_B.CurrentGain;

        /* Switch: '<S2189>/Switch3' incorporates:
         *  Constant: '<S2189>/Constant2'
         *  Sum: '<S2189>/Add'
         */
        rtb_Max_bj++;
    }

    /* End of Switch: '<S2189>/Switch' */
    /* End of Outputs for S-Function (RTC_NTF): '<S2191>/NTF Trigger' */

    /* MATLAB Function: '<S2188>/RamperProcess' incorporates:
     *  Constant: '<S2188>/Constant2'
     *  Constant: '<S2188>/Constant6'
     *  Constant: '<S2188>/Constant7'
     *  DataStoreRead: '<S2188>/Data Store Read'
     *  S-Function (AudioStats_MEX): '<S2188>/Audio Stats'
     */
    /* MATLAB Function 'PostProcess/PostProcess/EnergyLimiter/EnergyLimiter1/RamperProcess': '<S2192>:1' */
    /* '<S2192>:1:2' M = 1; */
    /*  for matlab 1 based indexing */
    /* '<S2192>:1:3' nf = single(size(x,1)); */
    /*  get the frame size. DO NOT USE length() since it may */
    /* '<S2192>:1:4' y = single(zeros(size(x))); */
    /*  more channels than samples per frame. */
    /* Defines for status */
    /* '<S2192>:1:7' RAMP_IDLE        = 0; */
    /* '<S2192>:1:7' RAMPING_UP       = 1; */
    /* '<S2192>:1:7' RAMPING_DOWN     = -1; */
    /* '<S2192>:1:9' numChs = single(size(x,2)); */
    /* '<S2192>:1:9' numRampers = 1; */
    /*  Configure the rgain block to have an attack (or decay) rate that */
    /*  is twice as fast as the ratio of GainChangeStepIndB to */
    /*  GainIncreaseDurationInSeconds (or */
    /*  GainDecreaseDurationInSeconds). That way, the rgain block will */
    /*  have settled to the target value before a new gain change occurs. */
    /* '<S2192>:1:15' rampUpRates_dBPerSec= (2*GainChangedB/GainInc); */
    /* '<S2192>:1:15' rampDownRates_dBPerSec=(-2*GainChangedB/GainDec); */
    /* '<S2192>:1:16' frameSize=nf; */
    /* '<S2192>:1:16' Fs=SampleRate; */
    /* '<S2192>:1:16' lpfTau=frameSize/Fs; */
    /* '<S2192>:1:16' snapThresh=single(1e-5); */
    /* '<S2192>:1:16' mindB=single(-100.0); */
    /* '<S2192>:1:19' upCoeff       = undb20(rampUpRates_dBPerSec/Fs); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    upCoeff = qhmath_exp_f(qhmath_div_f(qhmath_div_f(2.0F, 48000.0) *
                            2.30258512F, 20.0F));

    /* '<S2192>:1:19' upCoeffN  = upCoeff .^ frameSize; */
    /* '<S2192>:1:20' downCoeff     = undb20(-abs(rampDownRates_dBPerSec)/Fs); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    downCoeff = qhmath_exp_f(qhmath_div_f(qhmath_div_f(-2.0F, 48000.0) *
        2.30258512F, 20.0F));

    /* '<S2192>:1:20' downCoeffN  = downCoeff .^ frameSize; */
    /* '<S2192>:1:21' lpfCoeff      = single(exp(-1./(lpfTau.*Fs))); */
    lpfCoeff = qhmath_exp_f(qhmath_div_f(-1.0F, qhmath_div_f(32.0F, 48000.0) *
        48000.0));

    /* '<S2192>:1:21' minGain = undb20(mindB); */
    /* '<S2192>:1:22' targetCoeffSet =single(zeros(numRampers,1)); */
    /* '<S2192>:1:22' activeCoeffSet =single(zeros(numRampers,1)); */
    /* '<S2192>:1:23' status = RAMP_IDLE; */
    /* '<S2192>:1:23' freeze=single(0.0); */
    /* '<S2192>:1:24' targetRamper =single(zeros(numChs,1)); */
    /* '<S2192>:1:24' activeRamper=single(zeros(numChs,1)); */
    /* '<S2192>:1:26' if(isempty(prevGain)) */
    if (!Model_Target_PostProcess_DW.prevGain_not_empty)
    {
        /* '<S2192>:1:27' prevGain=single((PreviousGain*ones(numRampers,1))); */
        Model_Target_PostProcess_DW.prevGain =
            Model_Target_PostProcess_DW.CurrentGainValue;
        Model_Target_PostProcess_DW.prevGain_not_empty = true;
    }

    /* '<S2192>:1:29' targetGain=targetgainlinear; */
    /* '<S2192>:1:30' if(targetgainlinear<1) */
    /* '<S2192>:1:33' rGain=single(zeros(numRampers,1)); */
    /*  simulate use of scratch buffers for ramped envelopes */
    /* '<S2192>:1:37' scratchBufs = single(zeros(nf,numRampers)); */
    /*  loop over rampers first */
    /* '<S2192>:1:39' for r = 1:numRampers */
    /*  update active set with target */
    /* '<S2192>:1:41' activeCoeffSet(r) = targetCoeffSet(r); */
    /* '<S2192>:1:42' setIdx = activeCoeffSet(r) + M; */
    /*  get all coeffs from active set */
    /* '<S2192>:1:44' lpfCoeff = lpfCoeff(setIdx); */
    /* '<S2192>:1:46' gp = prevGain(r); */
    gp = Model_Target_PostProcess_DW.prevGain;

    /* '<S2192>:1:47' if freeze */
    /* '<S2192>:1:49' else */
    /* '<S2192>:1:50' gt = targetGain(r); */
    /* '<S2192>:1:52' gdiff = gt-gp; */
    gdiff = Model_Target_PostProcess_B.CurrentGain -
        Model_Target_PostProcess_DW.prevGain;

    /*  Snap to target gain if it's close enough */
    /* '<S2192>:1:55' if( abs(gdiff) <= snapThresh ) */
    if (qhmath_abs_f(gdiff) <= 1.0E-5F)
    {
        /* '<S2192>:1:56' prevGain(r) = gt; */
        Model_Target_PostProcess_DW.prevGain =
            Model_Target_PostProcess_B.CurrentGain;

        /* '<S2192>:1:57' status(r) = RAMP_IDLE; */
        /* '<S2192>:1:58' scratchBufs(:,r) = gt; */
        for (i = 0; i < 32; i++)
        {
            rtb_Merge_in[i] = Model_Target_PostProcess_B.CurrentGain;
        }
    }
    else
    {
        /*  Ramp up or down? */
        /* '<S2192>:1:63' if( gdiff>0 ) */
        if (gdiff > 0.0F)
        {
            /* '<S2192>:1:64' status(r) = RAMPING_UP; */
            /*  Check for ramp done */
            /* '<S2192>:1:67' temp = max(gp,minGain); */
            downCoeff = fmaxf(Model_Target_PostProcess_DW.prevGain,
                              9.99999338E-6F);

            /*  previous gain cannot be zero for exponential ramp */
            /* '<S2192>:1:68' if( temp*upCoeffN(setIdx) < gt ) */
            if (downCoeff * qhmath_pow_f(upCoeff, 32.0F) <
                    Model_Target_PostProcess_B.CurrentGain)
            {
                /*  Ramp not done, so do zero-input exponential ramp */
                /* '<S2192>:1:70' a = upCoeff(setIdx); */
                lpfCoeff = upCoeff;

                /* '<S2192>:1:70' b0 = single(0.0); */
                upCoeff = 0.0F;

                /* '<S2192>:1:70' gp = temp; */
                gp = downCoeff;
            }
            else
            {
                /* '<S2192>:1:71' else */
                /*  LPF with target gain as input */
                /* '<S2192>:1:73' a = lpfCoeff; */
                /* '<S2192>:1:73' b0 = 1-a; */
                upCoeff = 1.0F - lpfCoeff;
            }

            /* '<S2192>:1:75' else */
            /* '<S2192>:1:76' status(r) = RAMPING_DOWN; */
            /*  Check for ramp done */
            /* '<S2192>:1:78' if( gp*downCoeffN(setIdx) > gt ) */
        }
        else if (Model_Target_PostProcess_DW.prevGain * qhmath_pow_f(downCoeff,
                  32.0F) > Model_Target_PostProcess_B.CurrentGain)
        {
            /*  Ramp not done, so do zero-input exponential ramp */
            /* '<S2192>:1:80' a = downCoeff(setIdx); */
            lpfCoeff = downCoeff;

            /* '<S2192>:1:80' b0 = single(0.0); */
            upCoeff = 0.0F;
        }
        else
        {
            /* '<S2192>:1:81' else */
            /*  LPF with target gain as input */
            /* '<S2192>:1:83' a = lpfCoeff; */
            /* '<S2192>:1:83' b0 = 1-a; */
            upCoeff = 1.0F - lpfCoeff;
        }

        /*  Calculate gain envelope for current ramper */
        /*      zi = a*gp;    % initial condition for filter */
        /*      scratchBufs(:,r) = filter(b0,[1 -a],gt*ones(nf,1),zi); */
        /*  use single() to force MATLAB to compute gain envelope in 32-bit */
        /*  precision to match the performance of current 32-bit DSP processors */
        /* '<S2192>:1:91' for k = 1:nf */
        for (i = 0; i < 32; i++)
        {
            /* scratchBufs(k,r) = double(single(b0)*single(gt) + (single(a)*single(gp)));  */
            /* '<S2192>:1:93' scratchBufs(k,r) = b0*gt + a*gp; */
            gp = upCoeff * Model_Target_PostProcess_B.CurrentGain + lpfCoeff *
                gp;

            /* '<S2192>:1:93' gp = scratchBufs(k,r); */
            rtb_Merge_in[i] = gp;
        }

        /*  save state */
        /* '<S2192>:1:96' prevGain(r) = scratchBufs(end,r); */
        Model_Target_PostProcess_DW.prevGain = rtb_Merge_in[31];
    }

    /*  then apply ramped gains to channels */
    /* '<S2192>:1:100' for ch = 1:numChs */
    for (i = 0; i < 24; i++)
    {
        /* '<S2192>:1:101' activeRamper(ch) = targetRamper(ch); */
        /*  update active ramper with target */
        /* '<S2192>:1:102' if  activeRamper(ch) ~= -1 */
        /* '<S2192>:1:103' rGain = scratchBufs(:,activeRamper(ch) + M); */
        /*  get ramped envelope assigned to ch */
        /* '<S2192>:1:104' y(:,ch) = rGain.*x(:,ch); */
        for (s = 0; s < 32; s++)
        {
            rtb_DataStoreRead1_fv_tmp = (i << 5) + s;
            Model_Target_PostProcess_B.Magsq[rtb_DataStoreRead1_fv_tmp] =
                Model_Target_PostProcess_B.y_b[rtb_DataStoreRead1_fv_tmp] *
                rtb_Merge_in[s];
        }
    }

    /* End of MATLAB Function: '<S2188>/RamperProcess' */

    /* Switch: '<S2188>/Switch' */
    rtb_Merge_ps =
        (Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_EnableGainLimiter
         > 0U);
    for (s = 0; s < 768; s++)
    {
        rtb_Magsq_f = Model_Target_PostProcess_B.Magsq[s];
        if (!rtb_Merge_ps)
        {
            rtb_Magsq_f = Model_Target_PostProcess_B.y_b[s];
        }

        Model_Target_PostProcess_B.Magsq[s] = rtb_Magsq_f;
    }

    /* End of Switch: '<S2188>/Switch' */
    /* MATLAB Function: '<S2268>/MATLAB Function' incorporates:
     *  Switch: '<S2188>/Switch'
     */
    /*  This is the main function for the Soft-Clipper */
    /*  It takes in audio, typically from the Limiter, and applies a gain */
    /*  reduction when appropriate.  */
    /*  It takes in two sets of tunable parameters. */
    /*  Each set represents values corresponding to a car that either stays on, */
    /*  or shuts off, when idling.  */
    /* MATLAB Function 'PostProcess/PostProcess/Soft Clipper/SoftClipper/MATLAB Function': '<S2269>:1' */
    /* '<S2269>:1:9' y = coder.nullcopy(u); */
    /* '<S2269>:1:10' [frame_size, channel_count] = size(u); */
    /*  Choose whether we are using the set of coefficients for a car that shuts */
    /*  off while idling, or not. */
    /* '<S2269>:1:14' if (param_set == 1) */
    if (Model_TargetPostProcessLimiterSoftclipParamSetRtcOut.REQ_paramSet == 1U)
    {
        /* '<S2269>:1:15' xmin_param = xmin; */
        lpfCoeff = Model_Target_PostProcess_p0_b0.SoftClipperxmin;

        /* '<S2269>:1:16' xmax_param = xmax; */
        gp = Model_Target_PostProcess_p0_b0.SoftClipperxmax;

        /* '<S2269>:1:17' p2_param = p2; */
        upCoeff = Model_Target_PostProcess_p0_b0.SoftClipperp2;
    }
    else
    {
        /* '<S2269>:1:18' else */
        /* '<S2269>:1:19' xmin_param = xmin_low; */
        lpfCoeff = Model_Target_PostProcess_p0_b0.SoftClipperxmin_low;

        /* '<S2269>:1:20' xmax_param = xmax_low; */
        gp = Model_Target_PostProcess_p0_b0.SoftClipperxmax_low;

        /* '<S2269>:1:21' p2_param = p2_low; */
        upCoeff = Model_Target_PostProcess_p0_b0.SoftClipperp2_low;
    }

    /* '<S2269>:1:25' Sclip_Active = uint32(0); */
    /*  If RTC Disable message is 1, do not perform soft-clipping */
    /* '<S2269>:1:27' if (disableMsg) */
    if (Model_TargetPostProcessLimiterSoftclipDisableRtcOut.REQ_disableMsg != 0U)
    {
        /* '<S2269>:1:28' y(:) = u(:); */
        memcpy(&Model_Target_PostProcess_B.y[0],
               &Model_Target_PostProcess_B.Magsq[0], 768U * sizeof(real32_T));
    }
    else
    {
        /* '<S2269>:1:29' else */
        /*      Loop over all channels */
        /* '<S2269>:1:31' for i = 1:channel_count */
        for (i = 0; i < 24; i++)
        {
            /*          Loop over each sample of each channel */
            /* '<S2269>:1:33' for j = 1:frame_size */
            for (s = 0; s < 32; s++)
            {
                rtb_DataStoreRead1_fv_tmp = (i << 5) + s;
                rtb_Magsq_f =
                    Model_Target_PostProcess_B.Magsq[rtb_DataStoreRead1_fv_tmp];

                /* '<S2269>:1:34' x1 = abs( u(j,i) ); */
                /* '<S2269>:1:35' x1 = min(x1, xmax_param); */
                downCoeff = fminf(qhmath_abs_f(rtb_Magsq_f), gp);

                /* '<S2269>:1:36' x2 = x1 - xmin_param; */
                /* '<S2269>:1:37' x2 = max(x2, single(0)); */
                gdiff = fmaxf(downCoeff - lpfCoeff, 0.0F);

                /* '<S2269>:1:38' x2 = x2 * x2; */
                /* '<S2269>:1:39' x2 = x2 * p2_param; */
                /* '<S2269>:1:40' x1 = x1 - x2; */
                /* '<S2269>:1:41' y(j,i) = copysignf(x1, u(j,i)); */
                Model_Target_PostProcess_B.y[rtb_DataStoreRead1_fv_tmp] =
                    copysignf(downCoeff - gdiff * gdiff * upCoeff, rtb_Magsq_f);
            }

            /* '<S2269>:1:43' if (max(abs(u(:,i)))> xmin_param) */
        }
    }

    /* End of MATLAB Function: '<S2268>/MATLAB Function' */
    /* MATLAB Function: '<S2247>/PoolIirProcess' incorporates:
     *  S-Function (TOP_MEX): '<S2243>/TOP'
     *  S-Function (TOP_MEX): '<S2243>/TOP1'
     */
    /*  Extract configuration information from inputs */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/Generic/PoolIirProcess': '<S2248>:1' */
    /* '<S2248>:1:5' [frame_size, num_channels] = size(x); */
    /*  Initialize variables */
    /*  Typecast the variables */
    /* '<S2248>:1:11' frame_size = uint32(frame_size); */
    /* '<S2248>:1:12' num_channels = uint32(num_channels); */
    /* Compute the filter coefficients */
    /* '<S2248>:1:15' y = pooliir(x, frame_size, num_channels, numStages, coeffs, states); */
    /*  We have to use a different state buffer than the one passed in.  Matlab */
    /*  value objects are passed by value, not by reference, so the saving of */
    /*  states here does not work.  The state buffer is still necessary to pass */
    /*  allocate in the calling function and pass here in order to trigger CRL. */
    /*  This double buffering is annoying, however only happens during */
    /*  simulation, not code generation. */
    /*  num_states = (length(coeffs) - numChannels) / 2; */
    /*  persistent states; */
    /*  if isempty(states) */
    /*      states = single(zeros(1, num_states)); */
    /*  end */
    /* 'pooliir:15' stateIdx = 1; */
    rtb_SumofElements = 1.0;

    /* 'pooliir:16' coeffIdx = 1; */
    coeffIdx = 1.0;

    /* 'pooliir:18' frameMinus1  = frameSize-1; */
    /*  number of samples minus one */
    /* 'pooliir:19' y     = coder.nullcopy(x); */
    /*  output matrix */
    /*  OUTER LOOP over all channels                  */
    /* 'pooliir:22' for cha = 1:numChannels */
    for (s = 0; s < 24; s++)
    {
        real_T stateIdx;
        int32_T downCoeff_tmp;
        real32_T lpfCoeff_tmp;
        real32_T q;
        uint32_T b;

        /*  FIRST STAGE */
        /*  prologue: get coefficients, states and input vector  */
        /*  and perform some computations */
        /* 'pooliir:28' w1 = states(stateIdx); */
        lpfCoeff = Model_Target_PostProcess_DW.states[(int32_T)rtb_SumofElements
            - 1];

        /* 'pooliir:28' stateIdx = stateIdx+1; */
        stateIdx = rtb_SumofElements + 1.0;

        /* S-Function (TOP_MEX): '<S2243>/TOP1' */
        /* 'pooliir:29' gain = coeffs(coeffIdx); */
        rtb_Magsq_f = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
            [(int32_T)coeffIdx - 1];

        /* 'pooliir:29' coeffIdx = coeffIdx+1; */
        /* 'pooliir:30' w2 = states(stateIdx); */
        gp = Model_Target_PostProcess_DW.states[(int32_T)(rtb_SumofElements +
            1.0) - 1];

        /* 'pooliir:30' stateIdx = stateIdx-1; */
        rtb_SumofElements = (rtb_SumofElements + 1.0) - 1.0;

        /* S-Function (TOP_MEX): '<S2243>/TOP1' */
        /* 'pooliir:31' a2   = coeffs(coeffIdx); */
        upCoeff = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
            [(int32_T)(coeffIdx + 1.0) - 1];

        /* 'pooliir:31' coeffIdx = coeffIdx+1; */
        /* 'pooliir:32' xx  = x(1,cha); */
        /* 'pooliir:32' a1   = coeffs(coeffIdx); */
        /* 'pooliir:32' coeffIdx = coeffIdx+1; */
        /* 'pooliir:33' xx  = xx*gain; */
        downCoeff_tmp = s << 5;
        downCoeff = Model_Target_PostProcess_B.y[downCoeff_tmp] * rtb_Magsq_f;

        /* 'pooliir:33' b2   = coeffs(coeffIdx); */
        /* 'pooliir:33' coeffIdx = coeffIdx+1; */
        /* 'pooliir:34' yy  = w1+xx; */
        gdiff = lpfCoeff + downCoeff;

        /* S-Function (TOP_MEX): '<S2243>/TOP1' */
        /* 'pooliir:34' b1   = coeffs(coeffIdx); */
        /* 'pooliir:34' coeffIdx = coeffIdx+1; */
        /* 'pooliir:35' w1  = b1*xx; */
        lpfCoeff_tmp =
            Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs[(int32_T)
            ((((coeffIdx + 1.0) + 1.0) + 1.0) + 1.0) - 1];
        lpfCoeff = lpfCoeff_tmp * downCoeff;

        /*  main loop: 5 ops/sample */
        /* 'pooliir:38' i = 1; */
        /* 'pooliir:39' while i <= frameMinus1 */
        for (i = 0; i < 31; i++)
        {
            /* 'pooliir:40' r  = a1*yy; */
            /* 'pooliir:40' w1 = w1+w2; */
            lpfCoeff += gp;

            /* 'pooliir:40' y(i,cha) = yy; */
            rtb_DataStoreRead1_fv_tmp = i + downCoeff_tmp;
            Model_Target_PostProcess_B.Magsq[rtb_DataStoreRead1_fv_tmp] = gdiff;

            /* 'pooliir:41' q  = b2*xx; */
            q = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                [(int32_T)(((coeffIdx + 1.0) + 1.0) + 1.0) - 1] * downCoeff;

            /* 'pooliir:41' w1 = w1-r; */
            /* 'pooliir:41' xx = x(i+1,cha); */
            /* 'pooliir:42' xx = xx*gain; */
            downCoeff = Model_Target_PostProcess_B.y[rtb_DataStoreRead1_fv_tmp +
                1] * rtb_Magsq_f;

            /* 'pooliir:43' w2 = a2*yy; */
            gp = upCoeff * gdiff;

            /* 'pooliir:43' yy = w1+xx; */
            gdiff = (lpfCoeff -
                     Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                     [(int32_T)((coeffIdx + 1.0) + 1.0) - 1] * gdiff) +
                downCoeff;

            /* 'pooliir:44' w1 = b1*xx; */
            lpfCoeff = lpfCoeff_tmp * downCoeff;

            /* 'pooliir:44' w2 = q-w2; */
            gp = q - gp;

            /* 'pooliir:44' i = i + 1; */
        }

        /*  epilogue: drain pipe and write states */
        /* 'pooliir:48' r  = a1*yy; */
        /* 'pooliir:48' w1 = w1+w2; */
        /* 'pooliir:48' y(frameMinus1+1,cha) = yy; */
        Model_Target_PostProcess_B.Magsq[downCoeff_tmp + 31] = gdiff;

        /* 'pooliir:49' q  = b2*xx; */
        /* 'pooliir:49' w1 = w1-r; */
        Model_Target_PostProcess_DW.states[(int32_T)(stateIdx - 1.0) - 1] =
            (lpfCoeff + gp) -
            Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs[(int32_T)
            ((coeffIdx + 1.0) + 1.0) - 1] * gdiff;

        /* 'pooliir:50' w2 = a2*yy; */
        /* 'pooliir:50' states(stateIdx) = w1; */
        /* 'pooliir:50' stateIdx = stateIdx+1; */
        /* 'pooliir:51' w2 = q-w2; */
        Model_Target_PostProcess_DW.states[(int32_T)(rtb_SumofElements + 1.0) -
            1] = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
            [(int32_T)(((coeffIdx + 1.0) + 1.0) + 1.0) - 1] * downCoeff -
            upCoeff * gdiff;

        /* 'pooliir:51' states(stateIdx) = w2; */
        /* 'pooliir:51' stateIdx = stateIdx+1; */
        rtb_SumofElements = (rtb_SumofElements + 1.0) + 1.0;

        /*  NOTE: asm implementation needs to exit here if it's only */
        /*  one stage, NOTE: all subsequent stages work in-place */
        /* 'pooliir:55' for st = 2:numStages(cha) */
        b = Model_Target_PostProcess_p0_b0.PostLimiterEqPooliirNumStages[s];
        for (st = 2U; st <= b; st++)
        {
            real_T upCoeff_tmp;

            /*  prologue: get coefficients, states and input vector,  */
            /*  and perform some computations */
            /* 'pooliir:58' w1 = states(stateIdx); */
            lpfCoeff = Model_Target_PostProcess_DW.states[(int32_T)
                rtb_SumofElements - 1];

            /* 'pooliir:58' stateIdx = stateIdx+1; */
            stateIdx = rtb_SumofElements + 1.0;

            /* 'pooliir:59' a2 = coeffs(coeffIdx); */
            upCoeff_tmp = (((((coeffIdx + 1.0) + 1.0) + 1.0) + 1.0) + 1.0) +
                ((real_T)st - 2.0) * 4.0;
            upCoeff = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                [(int32_T)upCoeff_tmp - 1];

            /* 'pooliir:59' coeffIdx = coeffIdx+1; */
            /* 'pooliir:60' w2 = states(stateIdx); */
            gp = Model_Target_PostProcess_DW.states[(int32_T)(rtb_SumofElements
                + 1.0) - 1];

            /* 'pooliir:60' stateIdx = stateIdx-1; */
            rtb_SumofElements = (rtb_SumofElements + 1.0) - 1.0;

            /* 'pooliir:61' a1 = coeffs(coeffIdx); */
            rtb_Magsq_f =
                Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                [(int32_T)(upCoeff_tmp + 1.0) - 1];

            /* 'pooliir:61' coeffIdx = coeffIdx+1; */
            /* 'pooliir:62' xx = y(1,cha); */
            downCoeff = Model_Target_PostProcess_B.Magsq[downCoeff_tmp];

            /* 'pooliir:62' b2 = coeffs(coeffIdx); */
            /* 'pooliir:62' coeffIdx = coeffIdx+1; */
            /* 'pooliir:63' yy = w1+xx; */
            gdiff = downCoeff + lpfCoeff;

            /* 'pooliir:63' b1 = coeffs(coeffIdx); */
            /* 'pooliir:63' coeffIdx = coeffIdx+1; */
            /* 'pooliir:64' w1 = b1*xx; */
            lpfCoeff_tmp =
                Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                [(int32_T)(((upCoeff_tmp + 1.0) + 1.0) + 1.0) - 1];
            lpfCoeff = lpfCoeff_tmp * downCoeff;

            /*  main loop: 4 ops/sample */
            /* 'pooliir:67' i = 1; */
            /* 'pooliir:68' while i <= frameMinus1 */
            for (i = 0; i < 31; i++)
            {
                /* 'pooliir:69' r  = a1*yy; */
                /* 'pooliir:69' w1 = w1+w2; */
                lpfCoeff += gp;

                /* 'pooliir:69' y(i,cha) = yy; */
                Model_Target_PostProcess_B.Magsq[i + (s << 5)] = gdiff;

                /* 'pooliir:70' q  = b2*xx; */
                q = Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                    [(int32_T)((upCoeff_tmp + 1.0) + 1.0) - 1] * downCoeff;

                /* 'pooliir:70' w1 = w1-r ; */
                /* 'pooliir:70' xx = y(i+1,cha); */
                downCoeff = Model_Target_PostProcess_B.Magsq[((s << 5) + i) + 1];

                /* 'pooliir:71' w2 = a2*yy; */
                gp = upCoeff * gdiff;

                /* 'pooliir:71' yy = w1+xx; */
                gdiff = (lpfCoeff - rtb_Magsq_f * gdiff) + downCoeff;

                /* 'pooliir:72' w1 = b1*xx; */
                lpfCoeff = downCoeff * lpfCoeff_tmp;

                /* 'pooliir:72' w2 = q-w2; */
                gp = q - gp;

                /* 'pooliir:72' i = i + 1; */
            }

            /*  epilogue: drain pipe and write states */
            /* 'pooliir:76' r  = a1*yy; */
            /* 'pooliir:76' w1 = w1+w2; */
            /* 'pooliir:76' y(frameMinus1+1,cha) = yy; */
            Model_Target_PostProcess_B.Magsq[downCoeff_tmp + 31] = gdiff;

            /* 'pooliir:77' q  = b2*xx; */
            /* 'pooliir:77' w1 = w1-r; */
            Model_Target_PostProcess_DW.states[(int32_T)(stateIdx - 1.0) - 1] =
                (lpfCoeff + gp) - rtb_Magsq_f * gdiff;

            /* 'pooliir:78' w2 = a2*yy; */
            /* 'pooliir:78' states(stateIdx) = w1; */
            /* 'pooliir:78' stateIdx = stateIdx+1; */
            /* 'pooliir:79' w2 = q-w2; */
            Model_Target_PostProcess_DW.states[(int32_T)(rtb_SumofElements + 1.0)
                - 1] =
                Model_Target_PostProcess_p0_b0.PostLimiterEqpooliirCoeffs
                [(int32_T)((upCoeff_tmp + 1.0) + 1.0) - 1] * downCoeff - upCoeff
                * gdiff;

            /* 'pooliir:79' states(stateIdx) = w2; */
            /* 'pooliir:79' stateIdx = stateIdx+1; */
            rtb_SumofElements = (rtb_SumofElements + 1.0) + 1.0;
        }

        coeffIdx = (((((coeffIdx + 1.0) + 1.0) + 1.0) + 1.0) + 1.0) + (((real_T)
            b - 2.0) + 1.0) * 4.0;
    }

    /* End of MATLAB Function: '<S2247>/PoolIirProcess' */

    /* Reshape: '<S2247>/Reshape' */
    memcpy((&(UnitTest_Target_AudioOut[0])), &Model_Target_PostProcess_B.Magsq[0],
           768U * sizeof(real32_T));

    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S2244>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S2244>/NTF Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S2185>/NTF Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S2186>/NTF Trigger' */

    /* Update for Delay: '<S2196>/Delay2' incorporates:
     *  Sum: '<S2196>/Add1'
     */
    memcpy(&Model_Target_PostProcess_DW.Delay2_DSTATE[0], &rtb_Add1_db[0], 24U *
           sizeof(real_T));

    /* Update for M-S-Function: '<S2203>/TSP' */
    // TSP advanced triggered capture for PostProcessEnergyLimiterComputedEnergy '<S2203>/TSP':
#if TSP_ENABLE_ADVANCED

    TSP_StepCapture(TspDispatchTable0300, 0,
                    &Model_Target_PostProcess_B.DataTypeConversion1[0]);

#endif                                 //TSP_ENABLE_ADVANCED

    /* Update for Delay: '<S2189>/Delay1' */
    Model_Target_PostProcess_DW.icLoad = false;
    Model_Target_PostProcess_DW.Delay1_DSTATE = rtb_Delay_ed;

    /* Update for M-S-Function: '<S2204>/TSP' */
    // TSP advanced triggered capture for PostProcessEnergyLimiterCurGain '<S2204>/TSP':
#if TSP_ENABLE_ADVANCED

    TSP_StepCapture(TspDispatchTable0300, 1,
                    &Model_Target_PostProcess_B.CurrentGain);

#endif                                 //TSP_ENABLE_ADVANCED

    /* Update for M-S-Function: '<S2205>/TSP' */
    // TSP advanced triggered capture for PostProcessEnergyLimiterEnergyThreshold '<S2205>/TSP':
#if TSP_ENABLE_ADVANCED

    TSP_StepCapture(TspDispatchTable0300, 4,
                    &Model_Target_PostProcess_ConstB.DataTypeConversion3);

#endif                                 //TSP_ENABLE_ADVANCED

    /* Update for Delay: '<S2189>/Delay2' */
    Model_Target_PostProcess_DW.Delay2_DSTATE_i = rtb_Max_bj;

    /* Update for Delay: '<S2189>/Delay' */
    Model_Target_PostProcess_DW.Delay_DSTATE = rtb_DataStoreRead1_h;

    /* Update for Delay: '<S2189>/Delay3' incorporates:
     *  DataTypeConversion: '<S2189>/Data Type Conversion4'
     */
    Model_Target_PostProcess_DW.Delay3_DSTATE = rtb_DataStoreRead1_fv_tmp_tmp;

    /* Update for M-S-Function: '<S2206>/TSP' */
    // TSP advanced triggered capture for PostProcessEnergyLimiterCurState '<S2206>/TSP':
#if TSP_ENABLE_ADVANCED

    TSP_StepCapture(TspDispatchTable0300, 2,
                    &Model_Target_PostProcess_B.DataTypeConversion5);

#endif                                 //TSP_ENABLE_ADVANCED

    /* Update for M-S-Function: '<S2207>/TSP' */
    // TSP advanced triggered capture for PostProcessEnergyLimiterEnableFlag '<S2207>/TSP':
#if TSP_ENABLE_ADVANCED

    TSP_StepCapture(TspDispatchTable0300, 3,
                    &Model_Target_PostProcess_B.DataTypeConversion6);

#endif                                 //TSP_ENABLE_ADVANCED

}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
