/*
 * File: Enabled.c
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

#include "rtwtypes.h"
#include "Enabled.h"
#include <math.h>
#include "qhmath.h"
#include "Model_Target_types.h"
#include <string.h>
#include "Model_Target.h"
#include "rt_sys_Enabled_530.h"
#include "Model_Target_private.h"
#include "rt_sys_Enabled_536.h"
#include "rt_sys_Enabled_535.h"
#include "rt_sys_Enabled_543.h"

/* Forward declaration for local functions */
static void Model_Target_eml_find(const boolean_T x[30], int32_T i_data[],
    int32_T i_size[2]);

/* Forward declaration for local functions */
static void Model_Target_eml_find_j(const boolean_T x[22], int32_T i_data[],
    int32_T i_size[2]);

/* Forward declaration for local functions */
static void Model_Target_eml_find_i(const boolean_T x[30], int32_T i_data[],
    int32_T i_size[2]);
static void Model_Target_eml_find_e(const boolean_T x[22], int32_T i_data[],
    int32_T i_size[2]);

/*
 * Output and update for function-call system:
 *    '<S1375>/SetDsm'
 *    '<S1375>/SetDsm1'
 */
void Model_Target_SetDsm_l(uint32_T rtp_Value)
{
    /* DataStoreWrite: '<S1376>/Data Store Write' incorporates:
     *  Constant: '<S1376>/Constant'
     */
    Model_TargetControlDsms.PreAmpFadeRamperDRFreeze = rtp_Value;
}

/* Output and update for function-call system: '<S1375>/fade control' */
void Model_Target_fadecontrol(const real32_T rtu_targetGainLinear[4], real32_T
    rtu_dbPerSec, real32_T rtu_rampTimeMs, real32_T rtu_sampleRateHz, real32_T
    rtu_frameSize)
{
    real_T currentGainLinear_idx_0;
    real_T currentGainLinear_idx_1;
    real_T currentGainLinear_idx_2;
    real_T currentGainLinear_idx_3;
    real32_T db_diff_idx_0;
    real32_T db_diff_idx_1;
    real32_T numFrames;
    real32_T quantumMs;
    real32_T targetGainLinear;
    real32_T targetGainLinear_0;
    real32_T targetGainLinear_1;
    real32_T targetGainLinear_2;

    /* inputs  */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperDR/InnerLink/fade control': '<S1380>:1' */
    /*  High level control summary: */
    /*  The fade effect is achieved by boosting the gain of one group of */
    /*  speakers and cutting the gain of the opposite side. The corresponding */
    /*  gain (Rampers 1,2) is applied to the non-bass content of the audio, and  */
    /*  the bass content is simply added to it. For example, this means that even */
    /*  if the audio is faded forward, the bass content of the rear group is  */
    /*  retained. However, when the 'silent extreme' option is enabled, the bass  */
    /*  content of the rear group (or vice versa) needs to be muted. Hence, two  */
    /*  more rampers are setup for this purpose (Rampers 3,4). These two rampers  */
    /*  are used only when the fade effect is at either extreme *and* 'silent  */
    /*  extreme' is enabled. */
    /*  Inputs: */
    /*    targetGainLinear: Indicates the gain (in linear scale) which needs to */
    /*        be applied to the audio. Gain values can be mapped to the ramper */
    /*        configuration. */
    /*    rampTimeMs: Indicates the time in milliseconds in which the gain of the */
    /*        rampers must change from their current to target values. */
    /*    dbPerSecond: Indicates the rate in dB/second at which the gain of the */
    /*        rampers must change from their current to target values. If this */
    /*        value is non-zero, it is used to compute the ramp time and */
    /*        'rampTimeMs' is discarded (if specified). */
    /*    rgain_SILENT_GAIN: Parameter defined in the initFcn callback. */
    /*  Control Data: */
    /*    Freeze(1) freezes the processing during this control operation */
    /*    Rampers(1) is the non-bass ramper for the 'Front' group. Boost vs. cut  */
    /*         is determined by the value of the fade index */
    /*    Rampers(2) is the second phase ramper. Boost vs. cut is determined by */
    /*         the sign of the linear current gain. */
    /*    Rampers(3) is the bass ramper for the 'Front' group. Used for ramping */
    /*        from 1 to 0 (or vice versa), determined by whether the fade index */
    /*        is at the extreme and the status of 'silent extreme'. */
    /*    Rampers(4) is the bass ramper for the 'Rear' group. Used for ramping */
    /*        from 1 to 0 (or vice versa), determined by whether the fade index */
    /*        is at the extreme and the status of 'silent extreme'. */
    /* '<S1380>:1:43' numRampers = numel(Rampers); */
    /* '<S1380>:1:45' rgain_SILENT_GAIN = RgainBusUtil.GetSilentGainLinear(); */
    /*  Step 1: FREEZE the gain ramper so that we can perform calculations based */
    /*  on the current gain value. (This step is done outside on canvas now) */
    /*  Step 2: Get the current and target gains for all rampers */
    /*  If the linear gain is 0, nudge it to a value very close to zero to avoid  */
    /*  an infinite dB value. */
    /* '<S1380>:1:53' currentGainLinear = zeros(1,numRampers); */
    /* '<S1380>:1:54' for i = 1:numRampers */
    /* '<S1380>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_0 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[0].currentGain,
         5.0118723E-7F);

    /* '<S1380>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear = fmaxf(rtu_targetGainLinear[0], 5.0118723E-7F);

    /* '<S1380>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_1 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[1].currentGain,
         5.0118723E-7F);

    /* '<S1380>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_0 = fmaxf(rtu_targetGainLinear[1], 5.0118723E-7F);

    /* '<S1380>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_2 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[2].currentGain,
         5.0118723E-7F);

    /* '<S1380>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_1 = fmaxf(rtu_targetGainLinear[2], 5.0118723E-7F);

    /* '<S1380>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_3 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[3].currentGain,
         5.0118723E-7F);

    /* '<S1380>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_2 = fmaxf(rtu_targetGainLinear[3], 5.0118723E-7F);

    /*  Step 3a: TIME- If a slope in dB/second is provided, ignore the ramp time */
    /*  (if also provided) and instead calculate a new ramp time that matches */
    /*  the slope. */
    /* '<S1380>:1:63' rampMs = zeros(1,numRampers,'single'); */
    /* '<S1380>:1:64' if (dbPerSec) */
    if (rtu_dbPerSec != 0.0F)
    {
        /*  Now that we have both current and target impacts, find the difference */
        /* '<S1380>:1:66' currentGaindB = db20(currentGainLinear); */
        /* DB20  Linear quantity to decibels */
        /*    Converts x to dB assuming that x represents volts. */
        /*    y=20*log10(abs(x)); */
        /*  */
        /*  See Also: DB10, UNDB20 */
        /*    Copyright 2018-2019 Bose Corporation */
        /*  Bill Berardi */
        /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
        /* 'db20:12' y = 20/log(10)*log(abs(x)); */
        /* '<S1380>:1:67' targetGaindB = db20(targetGainLinear); */
        /* DB20  Linear quantity to decibels */
        /*    Converts x to dB assuming that x represents volts. */
        /*    y=20*log10(abs(x)); */
        /*  */
        /*  See Also: DB10, UNDB20 */
        /*    Copyright 2018-2019 Bose Corporation */
        /*  Bill Berardi */
        /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
        /* 'db20:12' y = 20/log(10)*log(abs(x)); */
        /* '<S1380>:1:68' db_diff = abs(currentGaindB - targetGaindB); */
        /* '<S1380>:1:69' rampMs = db_diff / single(dbPerSec) * 1000; */
        db_diff_idx_0 = qhmath_div_f(qhmath_abs_f((real32_T)(8.685889638065035 *
            log(currentGainLinear_idx_0)) - 8.68588924F * qhmath_log_f
            (targetGainLinear)), rtu_dbPerSec) * 1000.0F;
        db_diff_idx_1 = qhmath_div_f(qhmath_abs_f((real32_T)(8.685889638065035 *
            log(currentGainLinear_idx_1)) - 8.68588924F * qhmath_log_f
            (targetGainLinear_0)), rtu_dbPerSec) * 1000.0F;

        /* '<S1380>:1:70' rampMs(3) = rampMs(1); */
        /*  Front group */
        /* '<S1380>:1:71' rampMs(4) = rampMs(2); */
        /*  Rear group */
    }
    else
    {
        /* '<S1380>:1:72' else */
        /* '<S1380>:1:73' rampMs(:) = single(rampTimeMs); */
        db_diff_idx_0 = rtu_rampTimeMs;
        db_diff_idx_1 = rtu_rampTimeMs;
    }

    /*  Step 3b: TIME- QUANTIZE the desired ramp time to our FrameSize. Retrieve  */
    /*  the whole number of frames required to best match requested ramp time. */
    /*  Ensure that at least one frame is used. The frame size will therefore */
    /*  determine the steepest ramp (i.e. one frame could go *almost* anywhere). */
    /* '<S1380>:1:80' quantumMs = 1000 * frameSize / sampleRateHz; */
    quantumMs = qhmath_div_f(1000.0F * rtu_frameSize, rtu_sampleRateHz);

    /* '<S1380>:1:81' numFrames = rampMs / quantumMs; */
    /*  Do a ceil rather than a round to insure that we create enough */
    /*  frames. i.e. a fraction of a frame is promoted to an addition frame */
    /*  numFrames = max (1, round(numFrames)); */
    /* '<S1380>:1:85' numFrames = max (1, ceil(numFrames)); */
    /*  Step 4: For each ramper, store the corresponding gains, ramp coefficient */
    /*  and the number of frames over which the ramping occurs. */
    /* '<S1380>:1:89' for currentRamper = 1:numRampers */
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_0, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1380>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1380>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1380>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[0].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear,
                        (real32_T)currentGainLinear_idx_0)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1380>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1380>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[0].targetGain =
        targetGainLinear;

    /* '<S1380>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[0].currentGain = (real32_T)
        currentGainLinear_idx_0;

    /* '<S1380>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[0].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_1, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1380>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1380>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1380>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[1].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_0,
                        (real32_T)currentGainLinear_idx_1)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1380>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1380>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[1].targetGain =
        targetGainLinear_0;

    /* '<S1380>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[1].currentGain = (real32_T)
        currentGainLinear_idx_1;

    /* '<S1380>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[1].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_0, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1380>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1380>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1380>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[2].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_1,
                        (real32_T)currentGainLinear_idx_2)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1380>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1380>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[2].targetGain =
        targetGainLinear_1;

    /* '<S1380>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[2].currentGain = (real32_T)
        currentGainLinear_idx_2;

    /* '<S1380>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[2].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_1, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1380>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1380>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1380>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[3].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_2,
                        (real32_T)currentGainLinear_idx_3)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1380>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1380>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[3].targetGain =
        targetGainLinear_2;

    /* '<S1380>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[3].currentGain = (real32_T)
        currentGainLinear_idx_3;

    /* '<S1380>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[3].frameCount = (int32_T)
        numFrames;

    /*  Step 4: UNFREEZE the gain ramper (performed outside on canvas now) */
}

/*
 * Output and update for function-call system:
 *    '<S1382>/SetDsm'
 *    '<S1382>/SetDsm1'
 */
void Model_Target_SetDsm_d(uint32_T rtp_Value)
{
    /* DataStoreWrite: '<S1383>/Data Store Write' incorporates:
     *  Constant: '<S1383>/Constant'
     */
    Model_TargetControlDsms.PreAmpFadeRamperFRFreeze = rtp_Value;
}

/* Output and update for function-call system: '<S1382>/fade control' */
void Model_Target_fadecontrol_b(const real32_T rtu_targetGainLinear[4], real32_T
    rtu_dbPerSec, real32_T rtu_rampTimeMs, real32_T rtu_sampleRateHz, real32_T
    rtu_frameSize)
{
    real_T currentGainLinear_idx_0;
    real_T currentGainLinear_idx_1;
    real_T currentGainLinear_idx_2;
    real_T currentGainLinear_idx_3;
    real32_T db_diff_idx_0;
    real32_T db_diff_idx_1;
    real32_T numFrames;
    real32_T quantumMs;
    real32_T targetGainLinear;
    real32_T targetGainLinear_0;
    real32_T targetGainLinear_1;
    real32_T targetGainLinear_2;

    /* inputs  */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperFR/InnerLink/fade control': '<S1387>:1' */
    /*  High level control summary: */
    /*  The fade effect is achieved by boosting the gain of one group of */
    /*  speakers and cutting the gain of the opposite side. The corresponding */
    /*  gain (Rampers 1,2) is applied to the non-bass content of the audio, and  */
    /*  the bass content is simply added to it. For example, this means that even */
    /*  if the audio is faded forward, the bass content of the rear group is  */
    /*  retained. However, when the 'silent extreme' option is enabled, the bass  */
    /*  content of the rear group (or vice versa) needs to be muted. Hence, two  */
    /*  more rampers are setup for this purpose (Rampers 3,4). These two rampers  */
    /*  are used only when the fade effect is at either extreme *and* 'silent  */
    /*  extreme' is enabled. */
    /*  Inputs: */
    /*    targetGainLinear: Indicates the gain (in linear scale) which needs to */
    /*        be applied to the audio. Gain values can be mapped to the ramper */
    /*        configuration. */
    /*    rampTimeMs: Indicates the time in milliseconds in which the gain of the */
    /*        rampers must change from their current to target values. */
    /*    dbPerSecond: Indicates the rate in dB/second at which the gain of the */
    /*        rampers must change from their current to target values. If this */
    /*        value is non-zero, it is used to compute the ramp time and */
    /*        'rampTimeMs' is discarded (if specified). */
    /*    rgain_SILENT_GAIN: Parameter defined in the initFcn callback. */
    /*  Control Data: */
    /*    Freeze(1) freezes the processing during this control operation */
    /*    Rampers(1) is the non-bass ramper for the 'Front' group. Boost vs. cut  */
    /*         is determined by the value of the fade index */
    /*    Rampers(2) is the second phase ramper. Boost vs. cut is determined by */
    /*         the sign of the linear current gain. */
    /*    Rampers(3) is the bass ramper for the 'Front' group. Used for ramping */
    /*        from 1 to 0 (or vice versa), determined by whether the fade index */
    /*        is at the extreme and the status of 'silent extreme'. */
    /*    Rampers(4) is the bass ramper for the 'Rear' group. Used for ramping */
    /*        from 1 to 0 (or vice versa), determined by whether the fade index */
    /*        is at the extreme and the status of 'silent extreme'. */
    /* '<S1387>:1:43' numRampers = numel(Rampers); */
    /* '<S1387>:1:45' rgain_SILENT_GAIN = RgainBusUtil.GetSilentGainLinear(); */
    /*  Step 1: FREEZE the gain ramper so that we can perform calculations based */
    /*  on the current gain value. (This step is done outside on canvas now) */
    /*  Step 2: Get the current and target gains for all rampers */
    /*  If the linear gain is 0, nudge it to a value very close to zero to avoid  */
    /*  an infinite dB value. */
    /* '<S1387>:1:53' currentGainLinear = zeros(1,numRampers); */
    /* '<S1387>:1:54' for i = 1:numRampers */
    /* '<S1387>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_0 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[0].currentGain,
         5.0118723E-7F);

    /* '<S1387>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear = fmaxf(rtu_targetGainLinear[0], 5.0118723E-7F);

    /* '<S1387>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_1 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[1].currentGain,
         5.0118723E-7F);

    /* '<S1387>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_0 = fmaxf(rtu_targetGainLinear[1], 5.0118723E-7F);

    /* '<S1387>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_2 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[2].currentGain,
         5.0118723E-7F);

    /* '<S1387>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_1 = fmaxf(rtu_targetGainLinear[2], 5.0118723E-7F);

    /* '<S1387>:1:55' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_3 = fmaxf
        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[3].currentGain,
         5.0118723E-7F);

    /* '<S1387>:1:56' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_2 = fmaxf(rtu_targetGainLinear[3], 5.0118723E-7F);

    /*  Step 3a: TIME- If a slope in dB/second is provided, ignore the ramp time */
    /*  (if also provided) and instead calculate a new ramp time that matches */
    /*  the slope. */
    /* '<S1387>:1:63' rampMs = zeros(1,numRampers,'single'); */
    /* '<S1387>:1:64' if (dbPerSec) */
    if (rtu_dbPerSec != 0.0F)
    {
        /*  Now that we have both current and target impacts, find the difference */
        /* '<S1387>:1:66' currentGaindB = db20(currentGainLinear); */
        /* DB20  Linear quantity to decibels */
        /*    Converts x to dB assuming that x represents volts. */
        /*    y=20*log10(abs(x)); */
        /*  */
        /*  See Also: DB10, UNDB20 */
        /*    Copyright 2018-2019 Bose Corporation */
        /*  Bill Berardi */
        /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
        /* 'db20:12' y = 20/log(10)*log(abs(x)); */
        /* '<S1387>:1:67' targetGaindB = db20(targetGainLinear); */
        /* DB20  Linear quantity to decibels */
        /*    Converts x to dB assuming that x represents volts. */
        /*    y=20*log10(abs(x)); */
        /*  */
        /*  See Also: DB10, UNDB20 */
        /*    Copyright 2018-2019 Bose Corporation */
        /*  Bill Berardi */
        /*  $Id: db20.m 11813 2012-07-11 17:31:25Z rs7109 $ */
        /* 'db20:12' y = 20/log(10)*log(abs(x)); */
        /* '<S1387>:1:68' db_diff = abs(currentGaindB - targetGaindB); */
        /* '<S1387>:1:69' rampMs = db_diff / single(dbPerSec) * 1000; */
        db_diff_idx_0 = qhmath_div_f(qhmath_abs_f((real32_T)(8.685889638065035 *
            log(currentGainLinear_idx_0)) - 8.68588924F * qhmath_log_f
            (targetGainLinear)), rtu_dbPerSec) * 1000.0F;
        db_diff_idx_1 = qhmath_div_f(qhmath_abs_f((real32_T)(8.685889638065035 *
            log(currentGainLinear_idx_1)) - 8.68588924F * qhmath_log_f
            (targetGainLinear_0)), rtu_dbPerSec) * 1000.0F;

        /* '<S1387>:1:70' rampMs(3) = rampMs(1); */
        /*  Front group */
        /* '<S1387>:1:71' rampMs(4) = rampMs(2); */
        /*  Rear group */
    }
    else
    {
        /* '<S1387>:1:72' else */
        /* '<S1387>:1:73' rampMs(:) = single(rampTimeMs); */
        db_diff_idx_0 = rtu_rampTimeMs;
        db_diff_idx_1 = rtu_rampTimeMs;
    }

    /*  Step 3b: TIME- QUANTIZE the desired ramp time to our FrameSize. Retrieve  */
    /*  the whole number of frames required to best match requested ramp time. */
    /*  Ensure that at least one frame is used. The frame size will therefore */
    /*  determine the steepest ramp (i.e. one frame could go *almost* anywhere). */
    /* '<S1387>:1:80' quantumMs = 1000 * frameSize / sampleRateHz; */
    quantumMs = qhmath_div_f(1000.0F * rtu_frameSize, rtu_sampleRateHz);

    /* '<S1387>:1:81' numFrames = rampMs / quantumMs; */
    /*  Do a ceil rather than a round to insure that we create enough */
    /*  frames. i.e. a fraction of a frame is promoted to an addition frame */
    /*  numFrames = max (1, round(numFrames)); */
    /* '<S1387>:1:85' numFrames = max (1, ceil(numFrames)); */
    /*  Step 4: For each ramper, store the corresponding gains, ramp coefficient */
    /*  and the number of frames over which the ramping occurs. */
    /* '<S1387>:1:89' for currentRamper = 1:numRampers */
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_0, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1387>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1387>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1387>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[0].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear,
                        (real32_T)currentGainLinear_idx_0)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1387>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1387>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[0].targetGain =
        targetGainLinear;

    /* '<S1387>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[0].currentGain = (real32_T)
        currentGainLinear_idx_0;

    /* '<S1387>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[0].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_1, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1387>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1387>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1387>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[1].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_0,
                        (real32_T)currentGainLinear_idx_1)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1387>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1387>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[1].targetGain =
        targetGainLinear_0;

    /* '<S1387>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[1].currentGain = (real32_T)
        currentGainLinear_idx_1;

    /* '<S1387>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[1].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_0, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1387>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1387>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1387>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[2].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_1,
                        (real32_T)currentGainLinear_idx_2)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1387>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1387>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[2].targetGain =
        targetGainLinear_1;

    /* '<S1387>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[2].currentGain = (real32_T)
        currentGainLinear_idx_2;

    /* '<S1387>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[2].frameCount = (int32_T)
        numFrames;
    numFrames = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(db_diff_idx_1, quantumMs)));

    /*  In order to have the desired ramp time, the slope must vary dependent */
    /*  on the gain difference between target and current value. */
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
    /* '<S1387>:1:103' currentRampTimeMs = quantumMs * numFrames(currentRamper); */
    /* '<S1387>:1:104' factor = log(targetGainLinear(currentRamper) / currentGainLinear(currentRamper)); */
    /* '<S1387>:1:105' rampCoef = exp(factor / (sampleRateHz * currentRampTimeMs / 1000)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[3].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_2,
                        (real32_T)currentGainLinear_idx_3)), qhmath_div_f
                      (quantumMs * numFrames * rtu_sampleRateHz, 1000.0F)));

    /*  Output control signals */
    /* '<S1387>:1:108' Rampers(currentRamper).rampCoeff   = single(rampCoef); */
    /* '<S1387>:1:109' Rampers(currentRamper).targetGain  = single(targetGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[3].targetGain =
        targetGainLinear_2;

    /* '<S1387>:1:110' Rampers(currentRamper).currentGain = single(currentGainLinear(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[3].currentGain = (real32_T)
        currentGainLinear_idx_3;

    /* '<S1387>:1:111' Rampers(currentRamper).frameCount = int32(numFrames(currentRamper)); */
    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[3].frameCount = (int32_T)
        numFrames;

    /*  Step 4: UNFREEZE the gain ramper (performed outside on canvas now) */
}

/* Output and update for function-call system: '<S1360>/REQ' */
void HandleReqPreAmpFadeControlSet(void)
{
    int32_T cutLinearLowFreq;
    real32_T boostLinearHighFreq;
    real32_T cutLinearHighFreq;
    uint8_T j;
    boolean_T exitg1;

    /* MATLAB Function: '<S1359>/calculate_fade_gain' */
    /* MATLAB Function: '<S1359>/calculate_fade_gain' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S1372>:1' */
    /* '<S1372>:1:3' go(); */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeControl/InnerLink/calculate_fade_gain': '<S1367>:1' */
    /*  Computes the fade gains for the 'Front' and 'Rear' groups based on the */
    /*  index. Based on the position of the index in the table, either group  */
    /*  receives a gain 'cut' or 'boost' in order to achieve the fade effect. The */
    /*  gain 'cut' is computed from the table and the 'boost' is in turn computed */
    /*  from the 'cut' value depending on whether 'boostDisable' is set (0dB) or */
    /*  reset. When reset, the boost value is computed from the cut value based  */
    /*  on the energy preseving relationship: Boost^2 + Cut^2 = 2. These gain  */
    /*  values are applied only to the non-bass frequencies; the bass remains  */
    /*  unaltered (unless 'silent extreme' is enabled).  */
    /*  Ramper configuration: */
    /*  1 & 2: Non-bass (Front; Rear) */
    /*  3 & 4: Bass (Front; Rear) */
    /*  global Rampers; */
    /* '<S1367>:1:20' j = uint8(1); */
    j = 1U;

    /* '<S1367>:1:21' cutLinearHighFreq = single(1.0); */
    cutLinearHighFreq = 1.0F;

    /* '<S1367>:1:22' cutLinearLowFreq = single(1.0); */
    cutLinearLowFreq = 1;

    /* '<S1367>:1:23' targetGains = ones(1,MaskNumRampers,'single'); */
    /* '<S1367>:1:24' fadeIndex = single(fadeIndex); */
    /*  Find the front and the rear gains */
    /*  Based on the Fade table, the dB value of the index is calculated */
    /* '<S1367>:1:28' while (j <= numel(fadeTableIdx)) */
    exitg1 = false;
    while ((!exitg1) && (j <= 30))
    {
        /* '<S1367>:1:29' if (fadeIndex <= fadeTableIdx(j)) */
        boostLinearHighFreq = Model_Target_PreAmp_p9_b0.FadeControlTableIdx[j -
            1];
        if (Model_TargetPreAmpFadeControlSetRtcOut.REQ_gain_index <=
                boostLinearHighFreq)
        {
            /* '<S1367>:1:30' if (j <= 1) */
            if (j <= 1)
            {
                /*  First indexed value is linearly interpolated to zero */
                /* '<S1367>:1:31' if (fadeTableIdx(j)) */
                if (Model_Target_PreAmp_p9_b0.FadeControlTableIdx[0] != 0.0F)
                {
                    /* '<S1367>:1:32' percent = single(fadeIndex) / single(fadeTableIdx(j)); */
                    cutLinearHighFreq = qhmath_div_f((real32_T)
                        Model_TargetPreAmpFadeControlSetRtcOut.REQ_gain_index,
                        Model_Target_PreAmp_p9_b0.FadeControlTableIdx[0]);
                }
                else
                {
                    /* '<S1367>:1:33' else */
                    /* '<S1367>:1:34' percent = single(1); */
                }

                /* '<S1367>:1:36' cutLinearHighFreq = percent * 10 ^ (fadeTabledB(j) / 20); */
                cutLinearHighFreq *= qhmath_pow_f(10.0F, qhmath_div_f
                    (Model_Target_PreAmp_p9_b0.FadeControlTableDb[0], 20.0F));
            }
            else
            {
                real32_T cutLinearHighFreq_tmp;

                /* '<S1367>:1:37' else */
                /*  Other values are interpolated in dB space */
                /* '<S1367>:1:38' lastIdx = fadeTableIdx(j-1); */
                /* '<S1367>:1:39' percent = single(fadeIndex - lastIdx) / single(fadeTableIdx(j) - lastIdx); */
                /* '<S1367>:1:40' cutLinearHighFreq = 10 ^ (((percent * (fadeTabledB(j) - fadeTabledB(j-1))) + fadeTabledB(j-1)) / 20); */
                cutLinearHighFreq =
                    Model_Target_PreAmp_p9_b0.FadeControlTableIdx[j - 2];
                cutLinearHighFreq_tmp =
                    Model_Target_PreAmp_p9_b0.FadeControlTableDb[j - 2];
                cutLinearHighFreq = qhmath_pow_f(10.0F, qhmath_div_f
                    ((Model_Target_PreAmp_p9_b0.FadeControlTableDb[j - 1] -
                      cutLinearHighFreq_tmp) * qhmath_div_f((real32_T)
                    Model_TargetPreAmpFadeControlSetRtcOut.REQ_gain_index -
                    cutLinearHighFreq, boostLinearHighFreq - cutLinearHighFreq)
                     + cutLinearHighFreq_tmp, 20.0F));
            }

            exitg1 = true;
        }
        else
        {
            /* '<S1367>:1:43' else */
            /* '<S1367>:1:44' j = j + 1; */
            j++;
        }
    }

    /*  Compute boost gain */
    /* '<S1367>:1:49' if boostDisable ~= 0 */
    if (Model_Target_PreAmp_p9_b0.FadeControlBoostDisable != 0.0F)
    {
        /* '<S1367>:1:50' boostLinearHighFreq = single(1); */
        boostLinearHighFreq = 1.0F;
    }
    else
    {
        /* '<S1367>:1:51' else */
        /* '<S1367>:1:52' boostLinearHighFreq = sqrt(2.0 - cutLinearHighFreq^2); */
        boostLinearHighFreq = qhmath_sqrt_f(2.0F - cutLinearHighFreq *
            cutLinearHighFreq);
    }

    /*  If silent extreme is enabled and we're extreme, make the cut complete */
    /* '<S1367>:1:56' if (EnableSilentExtreme && abs(fadeIndex - indexOffset) >= (indexOffset-1)) */
    if ((Model_Target_PreAmp_p9_b0.FadeControlEnableSilentExtreme != 0.0F) &&
            (qhmath_abs_f((real32_T)
                          Model_TargetPreAmpFadeControlSetRtcOut.REQ_gain_index
                          - Model_Target_PreAmp_p9_b0.FadeControloffset) >=
             Model_Target_PreAmp_p9_b0.FadeControloffset - 1.0F))
    {
        /* '<S1367>:1:57' cutLinearHighFreq = single(0); */
        cutLinearHighFreq = 0.0F;

        /* '<S1367>:1:58' cutLinearLowFreq = single(0); */
        cutLinearLowFreq = 0;
    }

    /*  Assign to Gain Values */
    /* '<S1367>:1:62' if (fadeIndex - indexOffset) < 0 */
    if ((real32_T)Model_TargetPreAmpFadeControlSetRtcOut.REQ_gain_index -
            Model_Target_PreAmp_p9_b0.FadeControloffset < 0.0F)
    {
        /*  Front speakers attenuated */
        /* '<S1367>:1:63' targetGains(1) = single(cutLinearHighFreq); */
        Model_Target_B.targetGains[0] = cutLinearHighFreq;

        /* '<S1367>:1:64' targetGains(2) = single(boostLinearHighFreq); */
        Model_Target_B.targetGains[1] = boostLinearHighFreq;

        /* '<S1367>:1:65' targetGains(3) = single(cutLinearLowFreq); */
        Model_Target_B.targetGains[2] = (real32_T)cutLinearLowFreq;

        /* '<S1367>:1:66' targetGains(4) = single(1.0); */
        Model_Target_B.targetGains[3] = 1.0F;
    }
    else
    {
        /* '<S1367>:1:67' else */
        /* '<S1367>:1:68' targetGains(1) = single(boostLinearHighFreq); */
        Model_Target_B.targetGains[0] = boostLinearHighFreq;

        /* '<S1367>:1:69' targetGains(2) = single(cutLinearHighFreq); */
        Model_Target_B.targetGains[1] = cutLinearHighFreq;

        /* '<S1367>:1:70' targetGains(3) = single(1.0); */
        Model_Target_B.targetGains[2] = 1.0F;

        /* '<S1367>:1:71' targetGains(4) = single(cutLinearLowFreq); */
        Model_Target_B.targetGains[3] = (real32_T)cutLinearLowFreq;
    }

    /* End of MATLAB Function: '<S1359>/calculate_fade_gain' */

    /* MATLAB Function: '<S1359>/calculate_ramp_parameters' */
    /* MATLAB Function: '<S1359>/calculate_ramp_parameters' */
    boostLinearHighFreq = Model_Target_PreAmp_p9_b0.FadeControlRampTime;

    /*  parameters */
    /*  Function to calculate ramp parameters */
    /*   */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeControl/InnerLink/calculate_ramp_parameters': '<S1368>:1' */
    /*  Ramp time and rate are provided to the block through RTC messages. However  */
    /*  in case neither of them are provided, the block will use the default ramp  */
    /*  time given in the tune variables. */
    /* '<S1368>:1:11' ramptime = single(rampTimeTune); */
    /* '<S1368>:1:12' rampRate = single(0); */
    cutLinearHighFreq = 0.0F;

    /* '<S1368>:1:14' if (rampRateRTC) */
    if (Model_TargetPreAmpFadeControlSetRtcOut.REQ_ramp_db_per_second != 0U)
    {
        /* '<S1368>:1:15' rampRate = single(rampRateRTC); */
        /* '<S1368>:1:16' rampRate = max(rampRateBounds(1), rampRate); */
        /* '<S1368>:1:17' rampRate = min(rampRateBounds(2), rampRate); */
        cutLinearHighFreq = fminf(50000.0F, fmaxf(5.0F, (real32_T)
            Model_TargetPreAmpFadeControlSetRtcOut.REQ_ramp_db_per_second));
    }

    /* '<S1368>:1:19' if (rampTimeRTC) */
    if (Model_TargetPreAmpFadeControlSetRtcOut.REQ_ramp_milliseconds != 0U)
    {
        /* '<S1368>:1:20' ramptime = single(rampTimeRTC); */
        boostLinearHighFreq = (real32_T)
            Model_TargetPreAmpFadeControlSetRtcOut.REQ_ramp_milliseconds;
    }

    /* '<S1368>:1:22' ramptime = max(rampTimeBounds(1), ramptime); */
    /* '<S1368>:1:23' ramptime = min(rampTimeBounds(2), ramptime); */
    boostLinearHighFreq = fminf(3000.0F, fmaxf(1.0F, boostLinearHighFreq));

    /* End of MATLAB Function: '<S1359>/calculate_ramp_parameters' */

    /* Outputs for Function Call SubSystem: '<S1375>/SetDsm' */
    Model_Target_SetDsm_l(1U);

    /* End of Outputs for SubSystem: '<S1375>/SetDsm' */

    /* MATLAB Function: '<S1375>/fade control' */
    /* MATLAB Function: '<S1375>/fade control' incorporates:
     *  S-Function (AudioStats_MEX): '<S1375>/Audio Stats'
     */
    Model_Target_fadecontrol(Model_Target_B.targetGains, cutLinearHighFreq,
        boostLinearHighFreq, 11076.923076923078, 8.0);

    /* Outputs for Function Call SubSystem: '<S1375>/SetDsm1' */
    Model_Target_SetDsm_l(0U);

    /* End of Outputs for SubSystem: '<S1375>/SetDsm1' */

    /* Outputs for Function Call SubSystem: '<S1382>/SetDsm' */
    Model_Target_SetDsm_d(1U);

    /* End of Outputs for SubSystem: '<S1382>/SetDsm' */

    /* MATLAB Function: '<S1382>/fade control' */
    /* MATLAB Function: '<S1382>/fade control' incorporates:
     *  S-Function (AudioStats_MEX): '<S1382>/Audio Stats'
     */
    Model_Target_fadecontrol_b(Model_Target_B.targetGains, cutLinearHighFreq,
        boostLinearHighFreq, 44307.692307692312, 32.0);

    /* Outputs for Function Call SubSystem: '<S1382>/SetDsm1' */
    Model_Target_SetDsm_d(0U);

    /* End of Outputs for SubSystem: '<S1382>/SetDsm1' */
}

/* Function for MATLAB Function: '<S1375>/fade' */
static void Model_Target_eml_find(const boolean_T x[30], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 30))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 30)
            {
                exitg1 = true;
            }
            else
            {
                ii++;
            }
        }
        else
        {
            ii++;
        }
    }

    if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

/* Output and update for atomic system: '<S1375>/fade' */
void Model_Target_fade(const real32_T rtu_audioIn[240], const real32_T
                       rtu_channelToRamperMap[30], const real32_T rtu_yLpf[240],
                       B_fade_Model_Target_T *localB)
{
    int32_T d_data[30];
    int32_T d_size[2];
    int32_T b;
    int32_T ch;
    int32_T q0;
    int32_T ramper;
    real32_T yHpf[240];
    real32_T rampCoeffMultipliersBass[8];
    real32_T rampCoeffMultipliersNonBass[8];
    boolean_T rtu_channelToRamperMap_0[30];

    /*  inputs */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperDR/InnerLink/fade': '<S1379>:1' */
    /*  Applies the 'Front' and 'Rear' gains to the respective channels */
    /*  Inputs: */
    /*   audioIn: Input audio */
    /*   channelToRamperMap: Input channels mapped to their corresponding group. */
    /*     'Front' channels are mapped to rampers 1 and 3, and 'Rear' to rampers 2 */
    /*     and 4. */
    /*   yLpf: Low frequency content of the input audio */
    /*  Data Store objects (registered in "Edit Data" dialog) */
    /* '<S1379>:1:14' tgtGains = ones(1,2,'single'); */
    /*  Figure out the frame size, channel count and number of rampers */
    /* '<S1379>:1:17' [frameSize, ~] = size(audioIn); */
    /*  set the size and datatype of the output buffer */
    /* '<S1379>:1:20' audioOut = coder.nullcopy(audioIn); */
    /* '<S1379>:1:22' for ramper = 1:2 */
    for (q0 = 0; q0 < 240; q0++)
    {
        yHpf[q0] = rtu_audioIn[q0] - rtu_yLpf[q0];
    }

    for (ramper = 0; ramper < 2; ramper++)
    {
        real32_T gainHighFreq;
        real32_T gainLowFreq;

        /* '<S1379>:1:23' rampCoeffMultipliersBass = ones(1, frameSize, 'single'); */
        /* '<S1379>:1:24' rampCoeffMultipliersNonBass = ones(1, frameSize, 'single'); */
        for (q0 = 0; q0 < 8; q0++)
        {
            rampCoeffMultipliersBass[q0] = 1.0F;
            rampCoeffMultipliersNonBass[q0] = 1.0F;
        }

        /*  Get the gains for the corresponding channel group (non-bass/bass) */
        /* '<S1379>:1:27' gainHighFreq = Rampers(ramper).currentGain; */
        gainHighFreq = Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper]
            .currentGain;

        /* '<S1379>:1:28' gainLowFreq = Rampers(ramper + 2).currentGain; */
        gainLowFreq = Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper +
            2].currentGain;

        /* '<S1379>:1:30' if (Freeze(1) == false) */
        if (Model_TargetControlDsms.PreAmpFadeRamperDRFreeze == 0U)
        {
            /* '<S1379>:1:31' if (Rampers(ramper).frameCount == 0) */
            if (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].
                    frameCount == 0)
            {
                /*  The ramp is finished. Stop ramping and SNAP to the target */
                /* '<S1379>:1:33' gainHighFreq = Rampers(ramper).targetGain; */
                gainHighFreq =
                    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].
                    targetGain;

                /* '<S1379>:1:34' gainLowFreq = Rampers(ramper + 2).targetGain; */
                gainLowFreq =
                    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper + 2]
                    .targetGain;
            }
            else
            {
                /* '<S1379>:1:35' else */
                /*  The ramp is *NOT* frozen or done: gain is moving */
                /* '<S1379>:1:37' kHighFreq = Rampers(ramper).rampCoeff; */
                /* '<S1379>:1:38' kLowFreq = Rampers(ramper + 2).rampCoeff; */
                /*  Create ramp coefficient arrays to vectorize their  */
                /*  multiplication with the input audio */
                /* '<S1379>:1:42' rampCoeffMultipliersBass = (kLowFreq * rampCoeffMultipliersBass) .^ (1:frameSize); */
                /* '<S1379>:1:43' rampCoeffMultipliersNonBass = (kHighFreq * rampCoeffMultipliersNonBass) .^ (1:frameSize); */
                for (q0 = 0; q0 < 8; q0++)
                {
                    rampCoeffMultipliersBass[q0] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper
                         + 2].rampCoeff, (real32_T)((real_T)q0 + 1.0));
                    rampCoeffMultipliersNonBass[q0] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper]
                         .rampCoeff, (real32_T)((real_T)q0 + 1.0));
                }

                /* '<S1379>:1:44' Rampers(ramper).frameCount = Rampers(ramper).frameCount - 1; */
                q0 = Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].
                    frameCount;
                if (q0 < -2147483647)
                {
                    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].
                        frameCount = MIN_int32_T;
                }
                else
                {
                    Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].
                        frameCount = q0 - 1;
                }
            }
        }

        /*  Loop through samples, adjusting gain and applying to channels */
        /* '<S1379>:1:49' currentChannelGroup = find(channelToRamperMap == ramper); */
        for (q0 = 0; q0 < 30; q0++)
        {
            rtu_channelToRamperMap_0[q0] = ((real_T)(ramper + 1) ==
                rtu_channelToRamperMap[q0]);
        }

        Model_Target_eml_find(rtu_channelToRamperMap_0, d_data, d_size);

        /* '<S1379>:1:50' yHpf = audioIn - yLpf; */
        /* '<S1379>:1:51' for ch = 1:numel(currentChannelGroup) */
        b = d_size[1];
        for (ch = 0; ch < b; ch++)
        {
            int32_T d_tmp;

            /* '<S1379>:1:52' audioOut(:,currentChannelGroup(ch)) = (gainLowFreq * rampCoeffMultipliersBass)' .* yLpf(:,currentChannelGroup(ch)) + ... */
            /* '<S1379>:1:53'             (gainHighFreq * rampCoeffMultipliersNonBass)' .* yHpf(:,currentChannelGroup(ch)); */
            d_tmp = d_data[ch];
            for (q0 = 0; q0 < 8; q0++)
            {
                localB->audioOut[q0 + ((d_tmp - 1) << 3)] = rtu_yLpf[((d_tmp - 1)
                    << 3) + q0] * (gainLowFreq * rampCoeffMultipliersBass[q0]) +
                    yHpf[((d_tmp - 1) << 3) + q0] * (gainHighFreq *
                    rampCoeffMultipliersNonBass[q0]);
            }
        }

        /*  Send out target gains */
        /* '<S1379>:1:57' tgtGains(ramper) = Rampers(ramper).targetGain; */
        /*  Update the gain of the rampers for the next frame */
        /* '<S1379>:1:60' Rampers(ramper).currentGain = gainHighFreq * rampCoeffMultipliersNonBass(end); */
        Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper].currentGain =
            gainHighFreq * rampCoeffMultipliersNonBass[7];

        /* '<S1379>:1:61' Rampers(ramper + 2).currentGain = gainLowFreq * rampCoeffMultipliersBass(end); */
        Model_TargetControlDsms.PreAmpFadeRamperDRRampers[ramper + 2].
            currentGain = gainLowFreq * rampCoeffMultipliersBass[7];
    }

    /*  If ramper value of -1 is encountered, this indicates an unused channel. */
    /*  Assign values of zero to all samples of these channels. */
    /* '<S1379>:1:66' unusedChannelGroup = find(channelToRamperMap == -1); */
    for (q0 = 0; q0 < 30; q0++)
    {
        rtu_channelToRamperMap_0[q0] = (rtu_channelToRamperMap[q0] == -1.0F);
    }

    Model_Target_eml_find(rtu_channelToRamperMap_0, d_data, d_size);

    /* '<S1379>:1:67' for unusedCh = 1:numel(unusedChannelGroup) */
    ch = d_size[1];
    for (ramper = 0; ramper < ch; ramper++)
    {
        /* '<S1379>:1:68' audioOut(:,unusedChannelGroup(unusedCh)) = 0; */
        b = d_data[ramper];
        for (q0 = 0; q0 < 8; q0++)
        {
            localB->audioOut[q0 + ((b - 1) << 3)] = 0.0F;
        }
    }
}

/* Function for MATLAB Function: '<S1382>/fade' */
static void Model_Target_eml_find_j(const boolean_T x[22], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 22))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 22)
            {
                exitg1 = true;
            }
            else
            {
                ii++;
            }
        }
        else
        {
            ii++;
        }
    }

    if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

/* Output and update for atomic system: '<S1382>/fade' */
void Model_Target_fade_l(const real32_T rtu_audioIn[704], const real32_T
    rtu_channelToRamperMap[22], const real32_T rtu_yLpf[704],
    B_fade_Model_Target_m_T *localB)
{
    int32_T d_data[22];
    int32_T d_size[2];
    int32_T ch;
    int32_T q0;
    int32_T ramper;
    real32_T rampCoeffMultipliersBass[32];
    real32_T rampCoeffMultipliersNonBass[32];
    boolean_T rtu_channelToRamperMap_0[22];

    /*  inputs */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperFR/InnerLink/fade': '<S1386>:1' */
    /*  Applies the 'Front' and 'Rear' gains to the respective channels */
    /*  Inputs: */
    /*   audioIn: Input audio */
    /*   channelToRamperMap: Input channels mapped to their corresponding group. */
    /*     'Front' channels are mapped to rampers 1 and 3, and 'Rear' to rampers 2 */
    /*     and 4. */
    /*   yLpf: Low frequency content of the input audio */
    /*  Data Store objects (registered in "Edit Data" dialog) */
    /* '<S1386>:1:14' tgtGains = ones(1,2,'single'); */
    /*  Figure out the frame size, channel count and number of rampers */
    /* '<S1386>:1:17' [frameSize, ~] = size(audioIn); */
    /*  set the size and datatype of the output buffer */
    /* '<S1386>:1:20' audioOut = coder.nullcopy(audioIn); */
    /* '<S1386>:1:22' for ramper = 1:2 */
    for (q0 = 0; q0 < 704; q0++)
    {
        localB->yHpf[q0] = rtu_audioIn[q0] - rtu_yLpf[q0];
    }

    for (ramper = 0; ramper < 2; ramper++)
    {
        int32_T b;
        real32_T gainHighFreq;
        real32_T gainLowFreq;

        /* '<S1386>:1:23' rampCoeffMultipliersBass = ones(1, frameSize, 'single'); */
        /* '<S1386>:1:24' rampCoeffMultipliersNonBass = ones(1, frameSize, 'single'); */
        for (q0 = 0; q0 < 32; q0++)
        {
            rampCoeffMultipliersBass[q0] = 1.0F;
            rampCoeffMultipliersNonBass[q0] = 1.0F;
        }

        /*  Get the gains for the corresponding channel group (non-bass/bass) */
        /* '<S1386>:1:27' gainHighFreq = Rampers(ramper).currentGain; */
        gainHighFreq = Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper]
            .currentGain;

        /* '<S1386>:1:28' gainLowFreq = Rampers(ramper + 2).currentGain; */
        gainLowFreq = Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper +
            2].currentGain;

        /* '<S1386>:1:30' if (Freeze(1) == false) */
        if (Model_TargetControlDsms.PreAmpFadeRamperFRFreeze == 0U)
        {
            /* '<S1386>:1:31' if (Rampers(ramper).frameCount == 0) */
            if (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].
                    frameCount == 0)
            {
                /*  The ramp is finished. Stop ramping and SNAP to the target */
                /* '<S1386>:1:33' gainHighFreq = Rampers(ramper).targetGain; */
                gainHighFreq =
                    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].
                    targetGain;

                /* '<S1386>:1:34' gainLowFreq = Rampers(ramper + 2).targetGain; */
                gainLowFreq =
                    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper + 2]
                    .targetGain;
            }
            else
            {
                /* '<S1386>:1:35' else */
                /*  The ramp is *NOT* frozen or done: gain is moving */
                /* '<S1386>:1:37' kHighFreq = Rampers(ramper).rampCoeff; */
                /* '<S1386>:1:38' kLowFreq = Rampers(ramper + 2).rampCoeff; */
                /*  Create ramp coefficient arrays to vectorize their  */
                /*  multiplication with the input audio */
                /* '<S1386>:1:42' rampCoeffMultipliersBass = (kLowFreq * rampCoeffMultipliersBass) .^ (1:frameSize); */
                /* '<S1386>:1:43' rampCoeffMultipliersNonBass = (kHighFreq * rampCoeffMultipliersNonBass) .^ (1:frameSize); */
                for (q0 = 0; q0 < 32; q0++)
                {
                    rampCoeffMultipliersBass[q0] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper
                         + 2].rampCoeff, (real32_T)((real_T)q0 + 1.0));
                    rampCoeffMultipliersNonBass[q0] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper]
                         .rampCoeff, (real32_T)((real_T)q0 + 1.0));
                }

                /* '<S1386>:1:44' Rampers(ramper).frameCount = Rampers(ramper).frameCount - 1; */
                q0 = Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].
                    frameCount;
                if (q0 < -2147483647)
                {
                    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].
                        frameCount = MIN_int32_T;
                }
                else
                {
                    Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].
                        frameCount = q0 - 1;
                }
            }
        }

        /*  Loop through samples, adjusting gain and applying to channels */
        /* '<S1386>:1:49' currentChannelGroup = find(channelToRamperMap == ramper); */
        for (q0 = 0; q0 < 22; q0++)
        {
            rtu_channelToRamperMap_0[q0] = ((real_T)(ramper + 1) ==
                rtu_channelToRamperMap[q0]);
        }

        Model_Target_eml_find_j(rtu_channelToRamperMap_0, d_data, d_size);

        /* '<S1386>:1:50' yHpf = audioIn - yLpf; */
        /* '<S1386>:1:51' for ch = 1:numel(currentChannelGroup) */
        b = d_size[1];
        for (ch = 0; ch < b; ch++)
        {
            int32_T d_tmp;

            /* '<S1386>:1:52' audioOut(:,currentChannelGroup(ch)) = (gainLowFreq * rampCoeffMultipliersBass)' .* yLpf(:,currentChannelGroup(ch)) + ... */
            /* '<S1386>:1:53'             (gainHighFreq * rampCoeffMultipliersNonBass)' .* yHpf(:,currentChannelGroup(ch)); */
            d_tmp = d_data[ch];
            for (q0 = 0; q0 < 32; q0++)
            {
                localB->audioOut[q0 + ((d_tmp - 1) << 5)] = rtu_yLpf[((d_tmp - 1)
                    << 5) + q0] * (gainLowFreq * rampCoeffMultipliersBass[q0]) +
                    localB->yHpf[((d_tmp - 1) << 5) + q0] * (gainHighFreq *
                    rampCoeffMultipliersNonBass[q0]);
            }
        }

        /*  Send out target gains */
        /* '<S1386>:1:57' tgtGains(ramper) = Rampers(ramper).targetGain; */
        localB->tgtGains[ramper] =
            Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].targetGain;

        /*  Update the gain of the rampers for the next frame */
        /* '<S1386>:1:60' Rampers(ramper).currentGain = gainHighFreq * rampCoeffMultipliersNonBass(end); */
        Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper].currentGain =
            gainHighFreq * rampCoeffMultipliersNonBass[31];

        /* '<S1386>:1:61' Rampers(ramper + 2).currentGain = gainLowFreq * rampCoeffMultipliersBass(end); */
        Model_TargetControlDsms.PreAmpFadeRamperFRRampers[ramper + 2].
            currentGain = gainLowFreq * rampCoeffMultipliersBass[31];
    }

    /*  If ramper value of -1 is encountered, this indicates an unused channel. */
    /*  Assign values of zero to all samples of these channels. */
    /* '<S1386>:1:66' unusedChannelGroup = find(channelToRamperMap == -1); */
    for (q0 = 0; q0 < 22; q0++)
    {
        rtu_channelToRamperMap_0[q0] = (rtu_channelToRamperMap[q0] == -1.0F);
    }

    Model_Target_eml_find_j(rtu_channelToRamperMap_0, d_data, d_size);

    /* '<S1386>:1:67' for unusedCh = 1:numel(unusedChannelGroup) */
    ch = d_size[1];
    for (ramper = 0; ramper < ch; ramper++)
    {
        /* '<S1386>:1:68' audioOut(:,unusedChannelGroup(unusedCh)) = 0; */
        q0 = d_data[ramper];
        memset(&localB->audioOut[(q0 << 5) + -32], 0, sizeof(real32_T) << 5U);
    }
}

/* Output and update for function-call system: '<S1390>/REQ' */
void HandleReqPreAmpMuteControlSet(void)
{
    real32_T quantum_ms;
    real32_T x;

    /* MATLAB Function: '<S1389>/calculate_ramp_rate' */
    /* MATLAB Function: '<S1389>/calculate_ramp_rate' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S1397>:1' */
    /* '<S1397>:1:3' go(); */
    Model_Target_calculate_ramp_rate
        (Model_TargetPreAmpMuteControlSetRtcOut.REQ_ramp_db_per_second,
         Model_TargetPreAmpMuteControlSetRtcOut.REQ_ramp_milliseconds,
         Model_Target_PreAmp_p9_b0.MuteControlRampTime,
         &Model_Target_B.sf_calculate_ramp_rate);

    /* MATLAB Function: '<S1400>/get_ramp_coeffs' */
    /* MATLAB Function: '<S1400>/get_ramp_coeffs' incorporates:
     *  S-Function (AudioStats_MEX): '<S1400>/Audio Stats'
     */
    x = Model_Target_B.sf_calculate_ramp_rate.ramptime;

    /* MATLAB Function 'MuteRamper/get_ramp_coeffs': '<S1403>:1' */
    /* '<S1403>:1:5' targetLinearGain = single(1.0); */
    Model_TargetControlDsms.PreAmpMuteDRTargetLinearGain = 1.0F;

    /* '<S1403>:1:7' if muteSwitch */
    if (Model_TargetPreAmpMuteControlSetRtcOut.REQ_mute_switch != 0U)
    {
        /* '<S1403>:1:8' targetLinearGain = single(max(0, silentGainLinear)); */
        Model_TargetControlDsms.PreAmpMuteDRTargetLinearGain = 4.7315126E-7F;
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
    /* '<S1403>:1:24' if (rampingRate_dBPerSec) */
    if (Model_Target_B.sf_calculate_ramp_rate.rampRate != 0.0F)
    {
        /* '<S1403>:1:25' currentGain_db = 20*log10(max(currentGainValue, silentGainLinear)); */
        /* '<S1403>:1:26' targetGain_db = 20*log10( targetLinearGain); */
        /* '<S1403>:1:27' diff = abs(currentGain_db - targetGain_db); */
        /* '<S1403>:1:28' rampingTime_ms = diff / single(rampingRate_dBPerSec) * 1000; */
        x = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f(fmaxf
                           (Model_Target_B.DataStoreRead_f3, 4.7315126E-7F)) -
                          20.0F * qhmath_log10_f
                          (Model_TargetControlDsms.PreAmpMuteDRTargetLinearGain)),
                         Model_Target_B.sf_calculate_ramp_rate.rampRate) *
            1000.0F;
    }

    /* '<S1403>:1:31' quantum_ms = 1000 * frameSize / Fs_Hz; */
    quantum_ms = qhmath_div_f(8000.0F, 11076.923076923078);

    /* '<S1403>:1:32' numFrames = rampingTime_ms / quantum_ms; */
    /*  Do a ceil rather than a round to insure that we create enough */
    /*  frames. i.e. a fraction of a frame is promoted to an addition frame */
    /* '<S1403>:1:35' nFrames = max (1, ceil(numFrames)); */
    Model_TargetControlDsms.PreAmpMuteDRNframes = fmaxf(1.0F, qhmath_ceil_f
        (qhmath_div_f(x, quantum_ms)));

    /* '<S1403>:1:36' quantized_rampTime_ms = nFrames * quantum_ms; */
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
    /* '<S1403>:1:50' ramping_coeff= exp(log( targetLinearGain /max(currentGainValue, silentGainLinear) ) / (Fs_Hz * quantized_rampTime_ms / 1000)); */
    Model_Target_B.ramping_coeff_m = qhmath_div_f(qhmath_log_f(qhmath_div_f
        (Model_TargetControlDsms.PreAmpMuteDRTargetLinearGain, fmaxf
         (Model_Target_B.DataStoreRead_f3, 4.7315126E-7F))), qhmath_div_f
        (Model_TargetControlDsms.PreAmpMuteDRNframes * quantum_ms *
         11076.923076923078, 1000.0F));
    Model_Target_B.ramping_coeff_m = qhmath_exp_f(Model_Target_B.ramping_coeff_m);

    /* End of MATLAB Function: '<S1400>/get_ramp_coeffs' */

    /* MATLAB Function: '<S1413>/get_ramp_coeffs' */
    /* MATLAB Function: '<S1413>/get_ramp_coeffs' incorporates:
     *  S-Function (AudioStats_MEX): '<S1413>/Audio Stats'
     */
    x = Model_Target_B.sf_calculate_ramp_rate.ramptime;

    /* MATLAB Function 'MuteRamper/get_ramp_coeffs': '<S1416>:1' */
    /* '<S1416>:1:5' targetLinearGain = single(1.0); */
    Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain = 1.0F;

    /* '<S1416>:1:7' if muteSwitch */
    if (Model_TargetPreAmpMuteControlSetRtcOut.REQ_mute_switch != 0U)
    {
        /* '<S1416>:1:8' targetLinearGain = single(max(0, silentGainLinear)); */
        Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain = 4.7315126E-7F;
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
    /* '<S1416>:1:24' if (rampingRate_dBPerSec) */
    if (Model_Target_B.sf_calculate_ramp_rate.rampRate != 0.0F)
    {
        /* '<S1416>:1:25' currentGain_db = 20*log10(max(currentGainValue, silentGainLinear)); */
        /* '<S1416>:1:26' targetGain_db = 20*log10( targetLinearGain); */
        /* '<S1416>:1:27' diff = abs(currentGain_db - targetGain_db); */
        /* '<S1416>:1:28' rampingTime_ms = diff / single(rampingRate_dBPerSec) * 1000; */
        x = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f(fmaxf
                           (Model_Target_B.DataStoreRead_b, 4.7315126E-7F)) -
                          20.0F * qhmath_log10_f
                          (Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain)),
                         Model_Target_B.sf_calculate_ramp_rate.rampRate) *
            1000.0F;
    }

    /* '<S1416>:1:31' quantum_ms = 1000 * frameSize / Fs_Hz; */
    quantum_ms = qhmath_div_f(32000.0F, 44307.692307692312);

    /* '<S1416>:1:32' numFrames = rampingTime_ms / quantum_ms; */
    /*  Do a ceil rather than a round to insure that we create enough */
    /*  frames. i.e. a fraction of a frame is promoted to an addition frame */
    /* '<S1416>:1:35' nFrames = max (1, ceil(numFrames)); */
    Model_TargetControlDsms.PreAmpMuteFRNframes = fmaxf(1.0F, qhmath_ceil_f
        (qhmath_div_f(x, quantum_ms)));

    /* '<S1416>:1:36' quantized_rampTime_ms = nFrames * quantum_ms; */
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
    /* '<S1416>:1:50' ramping_coeff= exp(log( targetLinearGain /max(currentGainValue, silentGainLinear) ) / (Fs_Hz * quantized_rampTime_ms / 1000)); */
    Model_Target_B.ramping_coeff_l = qhmath_div_f(qhmath_log_f(qhmath_div_f
        (Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain, fmaxf
         (Model_Target_B.DataStoreRead_b, 4.7315126E-7F))), qhmath_div_f
        (Model_TargetControlDsms.PreAmpMuteFRNframes * quantum_ms *
         44307.692307692312, 1000.0F));
    Model_Target_B.ramping_coeff_l = qhmath_exp_f(Model_Target_B.ramping_coeff_l);

    /* End of MATLAB Function: '<S1413>/get_ramp_coeffs' */
}

/*
 * Output and update for function-call system:
 *    '<S1432>/calculate_SB_gains'
 *    '<S1452>/calculate_SB_gains'
 */
void Model_Target_calculate_SB_gains(uint32_T rtu_gainIdx, const real32_T
    rtu_TableDb[30], const real32_T rtu_TableIdx[30], real32_T rtu_indexOffset,
    real32_T rtu_MaskSilentExtremeMutesBass, B_calculate_SB_gains_Model_Target_T
    *localB)
{
    real32_T cut_linear;
    real32_T tmp;
    uint8_T j;
    boolean_T exitg1;

    /*  Computes the gains for the L, R, C Mono channel groups.   */
    /*  Based on the gainIdx, we will: */
    /*      1. Set specific speakers to mute, if the gain index is  */
    /*      extreme (i.e. either 0 or 255) */
    /*      2. Begin a gain-tapering function on the speakers, if the */
    /*      gain index is approaching 0 or 255 (i.e. taper the speaker gains */
    /*      beginning with the last few clicks of the gain index) */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/calculate_SB_gains': '<S1441>:1' */
    /*   Set target gains to ones */
    /* '<S1441>:1:13' j = uint8(1); */
    j = 1U;

    /* '<S1441>:1:14' cut_linear = single(0.0); */
    cut_linear = 0.0F;

    /* '<S1441>:1:16' targetGainsSB = coder.nullcopy(ones(1, MaskNumRampers,'single')); */
    /* '<S1441>:1:17' gainIdx = single(gainIdx); */
    /*  Find the left and the right gains */
    /*  Based on the SB table, the dB value of the index is calculated */
    /* '<S1441>:1:21' while (j <= numel(TableIdx)) */
    exitg1 = false;
    while ((!exitg1) && (j <= 30))
    {
        /* '<S1441>:1:22' if (gainIdx <= TableIdx(j)) */
        tmp = rtu_TableIdx[j - 1];
        if (rtu_gainIdx <= tmp)
        {
            /* '<S1441>:1:23' if (j <= 1) */
            if (j <= 1)
            {
                /*  first indexed value is linearly interpolated to zero */
                /* '<S1441>:1:24' if (TableIdx(j)) */
                if (rtu_TableIdx[0] != 0.0F)
                {
                    /* '<S1441>:1:25' percent = gainIdx / TableIdx(j); */
                    cut_linear = qhmath_div_f((real32_T)rtu_gainIdx,
                        rtu_TableIdx[0]);
                }
                else
                {
                    /* '<S1441>:1:26' else */
                    /* '<S1441>:1:27' percent = single(1); */
                    cut_linear = 1.0F;
                }

                /* '<S1441>:1:29' cut_linear = percent * 10 ^ (TableDb(j) / 20); */
                cut_linear *= qhmath_pow_f(10.0F, qhmath_div_f(rtu_TableDb[0],
                    20.0F));
            }
            else
            {
                real32_T cut_linear_tmp;

                /* '<S1441>:1:30' else */
                /*  other values are interpolated in db space */
                /* '<S1441>:1:31' lastIdx = single(TableIdx(j-1)); */
                /* '<S1441>:1:32' percent = (gainIdx - lastIdx) / (TableIdx(j) - lastIdx); */
                /* '<S1441>:1:33' cut_linear = 10 ^ (((percent * (TableDb(j) - TableDb(j-1))) + TableDb(j-1)) / 20); */
                cut_linear = rtu_TableIdx[j - 2];
                cut_linear_tmp = rtu_TableDb[j - 2];
                cut_linear = qhmath_pow_f(10.0F, qhmath_div_f((rtu_TableDb[j - 1]
                    - cut_linear_tmp) * qhmath_div_f((real32_T)rtu_gainIdx -
                    cut_linear, tmp - cut_linear) + cut_linear_tmp, 20.0F));
            }

            exitg1 = true;
        }
        else
        {
            /* '<S1441>:1:36' else */
            /* '<S1441>:1:37' j = j + 1; */
            j++;
        }
    }

    /*  Assign left and right Gain Values to headrest speakers (TAPERING) */
    /* '<S1441>:1:42' if (gainIdx - indexOffset) > 0 */
    tmp = (real32_T)rtu_gainIdx - rtu_indexOffset;
    if (tmp > 0.0F)
    {
        /*  Left speakers attenuated */
        /* '<S1441>:1:43' left = single(cut_linear); */
        localB->targetGainsSB[0] = cut_linear;

        /* '<S1441>:1:44' right = single(1); */
        localB->targetGainsSB[1] = 1.0F;

        /* '<S1441>:1:45' center = left; */
        localB->targetGainsSB[2] = cut_linear;

        /* '<S1441>:1:46' mono = center; */
        localB->targetGainsSB[3] = cut_linear;

        /*  % If we're extreme, make the cut complete */
        /* '<S1441>:1:49' if (abs(gainIdx - indexOffset) >= (indexOffset-1)) */
        if (qhmath_abs_f(tmp) >= rtu_indexOffset - 1.0F)
        {
            /* '<S1441>:1:50' left = single(0); */
            localB->targetGainsSB[0] = 0.0F;

            /* '<S1441>:1:51' center = single(0); */
            localB->targetGainsSB[2] = 0.0F;
        }
    }
    else
    {
        /* '<S1441>:1:53' else */
        /*  Right speakers attenuated  */
        /* '<S1441>:1:54' right = single(cut_linear); */
        localB->targetGainsSB[1] = cut_linear;

        /* '<S1441>:1:55' left = single(1); */
        localB->targetGainsSB[0] = 1.0F;

        /* '<S1441>:1:56' center = right; */
        localB->targetGainsSB[2] = cut_linear;

        /* '<S1441>:1:57' mono = center; */
        localB->targetGainsSB[3] = cut_linear;

        /*  % If we're extreme, make the cut complete */
        /* '<S1441>:1:60' if (abs(gainIdx - indexOffset) >= (indexOffset-1)) */
        if (qhmath_abs_f((real32_T)rtu_gainIdx - rtu_indexOffset) >=
                rtu_indexOffset - 1.0F)
        {
            /* '<S1441>:1:61' right = single(0); */
            localB->targetGainsSB[1] = 0.0F;

            /* '<S1441>:1:62' center = single(0); */
            localB->targetGainsSB[2] = 0.0F;
        }
    }

    /*  Mute the mono channels if we're extreme and if it's checked in the mask */
    /* '<S1441>:1:67' if (abs(gainIdx - indexOffset) >= (indexOffset-1)) && (MaskSilentExtremeMutesBass) */
    if ((qhmath_abs_f((real32_T)rtu_gainIdx - rtu_indexOffset) >=
            rtu_indexOffset - 1.0F) && (rtu_MaskSilentExtremeMutesBass != 0.0F))
    {
        /* '<S1441>:1:68' mono = single(0); */
        localB->targetGainsSB[3] = 0.0F;
    }

    /*  Write gains to targetGains  */
    /* '<S1441>:1:72' targetGainsSB(1) = left; */
    /* '<S1441>:1:73' targetGainsSB(2) = right; */
    /* '<S1441>:1:74' targetGainsSB(3) = center; */
    /* '<S1441>:1:75' targetGainsSB(4) = mono; */
}

/*
 * Output and update for function-call system:
 *    '<S1432>/calculate_ramp_parameters'
 *    '<S1452>/calculate_ramp_parameters'
 */
void Model_Target_calculate_ramp_parameters(real32_T rtu_rampTimeTune, uint32_T
    rtu_rampRateRTC, uint32_T rtu_rampTimeRTC,
    B_calculate_ramp_parameters_Model_Target_T *localB)
{
    real32_T y;
    y = rtu_rampTimeTune;

    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/calculate_ramp_parameters': '<S1442>:1' */
    /*  Ramp time and rate are provided to the block through SB RTC messages */
    /*  However in case neither of them are provided, the block will use the  */
    /*  default ramp time given in the tune variables. */
    /* '<S1442>:1:9' ramptime = single(rampTimeTune); */
    /* '<S1442>:1:10' rampRate = single(0); */
    localB->rampRate = 0.0F;

    /* '<S1442>:1:12' if (rampRateRTC) */
    if (rtu_rampRateRTC != 0U)
    {
        /* '<S1442>:1:13' rampRate = single(rampRateRTC); */
        /* '<S1442>:1:14' rampRate = max(rampRateBounds(1), rampRate); */
        /* '<S1442>:1:15' rampRate = min(rampRateBounds(2), rampRate); */
        localB->rampRate = fminf(50000.0F, fmaxf(5.0F, (real32_T)rtu_rampRateRTC));
    }

    /* '<S1442>:1:17' if (rampTimeRTC) */
    if (rtu_rampTimeRTC != 0U)
    {
        /* '<S1442>:1:18' ramptime = single(rampTimeRTC); */
        y = (real32_T)rtu_rampTimeRTC;
    }

    /* '<S1442>:1:20' ramptime = max(rampTimeBounds(1), ramptime); */
    /* '<S1442>:1:21' ramptime = min(rampTimeBounds(2), ramptime); */
    localB->ramptime = fminf(3000.0F, fmaxf(1.0F, y));
}

/*
 * Output and update for function-call system:
 *    '<S1432>/SetDsm'
 *    '<S1432>/SetDsm1'
 */
void Model_Target_SetDsm_h(uint32_T rtp_Value)
{
    /* DataStoreWrite: '<S1434>/Data Store Write' incorporates:
     *  Constant: '<S1434>/Constant'
     */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRFreeze = rtp_Value;
}

/* Output and update for function-call system: '<S1433>/REQ' */
void HandleReqPreAmpSleepingBeautyDRSet(void)
{
    real32_T currentGainLinear_idx_0;
    real32_T currentGainLinear_idx_1;
    real32_T currentGainLinear_idx_2;
    real32_T currentGainLinear_idx_3;
    real32_T diff_idx_0;
    real32_T diff_idx_1;
    real32_T diff_idx_2;
    real32_T diff_idx_3;
    real32_T quantumMs;
    real32_T targetGainLinear;
    real32_T targetGainLinear_0;
    real32_T targetGainLinear_1;
    real32_T targetGainLinear_2;

    /* MATLAB Function: '<S1432>/calculate_SB_gains' */
    /* MATLAB Function: '<S1432>/calculate_SB_gains' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S1449>:1' */
    /* '<S1449>:1:3' go(); */
    Model_Target_calculate_SB_gains
        (Model_TargetPreAmpSleepingBeautyDRSetRtcOut.REQ_gain_index,
         &(Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableDb[0]),
         &(Model_Target_PreAmp_p9_b0.SleepingBeautyDRTableIdx[0]),
         Model_Target_PreAmp_p9_b0.SleepingBeautyDROffset,
         Model_Target_PreAmp_p9_b0.SleepingBeautyDRMutesBass,
         &Model_Target_B.sf_calculate_SB_gains);

    /* MATLAB Function: '<S1432>/calculate_ramp_parameters' */
    /* MATLAB Function: '<S1432>/calculate_ramp_parameters' */
    Model_Target_calculate_ramp_parameters
        (Model_Target_PreAmp_p9_b0.SleepingBeautyDRRampTime,
         Model_TargetPreAmpSleepingBeautyDRSetRtcOut.REQ_ramp_db_per_second,
         Model_TargetPreAmpSleepingBeautyDRSetRtcOut.REQ_ramp_milliseconds,
         &Model_Target_B.sf_calculate_ramp_parameters_b);

    /* Outputs for Function Call SubSystem: '<S1432>/SetDsm' */
    Model_Target_SetDsm_h(1U);

    /* End of Outputs for SubSystem: '<S1432>/SetDsm' */

    /* MATLAB Function: '<S1432>/control' */
    /* MATLAB Function: '<S1432>/control' incorporates:
     *  S-Function (AudioStats_MEX): '<S1432>/Audio Stats'
     */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/control': '<S1444>:1' */
    /*  CONTROL LOGIC: */
    /*  Shift of 'balance' between the 'Right' and 'Left' channel groups is */
    /*  achieved by multiplying the corresponding 'cut' or 'boost' gain. As the */
    /*  index increases from 0, the balance shifts from left to right. */
    /*  rampdbPerSec takes precidence: */
    /*    If dbPerSec has a non-zero value then any ramp_times_ms values are */
    /*    ignored and the dbPerSec is used to determine ramper timing. */
    /*  Inputs: */
    /*    targetGainLinear: Indicates the gain (in linear scale) which needs to */
    /*        be applied to the audio. Gain values can be mapped to the ramper */
    /*        configuration. */
    /*    rampTimeMs: Indicates the time in milliseconds in which the gain of the */
    /*        rampers must change from their current to target values. */
    /*    rampdbPerSecond: Indicates the rate in dB/second at which the gain of the */
    /*        rampers must change from their current to target values. If this */
    /*        value is non-zero, it is used to compute the ramp time and */
    /*        'rampTimeMs' is discarded (if specified). */
    /*    rgain_SILENT_GAIN: Parameter defined in the initFcn callback. */
    /*  Control Data: */
    /*    Freeze(1) freezes the processing during this control operation */
    /*    Rampers(1) is the ramper for the left speaker */
    /*    Rampers(2) is the ramper for the right speaker */
    /*    Rampers(3) is the ramper for the center speaker */
    /*    Rampers(4) is the ramper for the mono speaker */
    /* '<S1444>:1:34' rgain_SILENT_GAIN = RgainBusUtil.GetSilentGainLinear(); */
    /*  Step 1: FREEZE the gain ramper so that we can perform calculations based */
    /*  on the current gain value. This step now done externally on canvas */
    /*  Step 2: Nudge the gain values a bit if they are sitting at zero. */
    /*  When this control set goes live, ensure that the current gain will move. */
    /*  If current gain is zero, replace with a value very close to zero. What we */
    /*  really want is a value which is on the edge of perception - not too small */
    /*  or large. If the value is too small, we'll waste some of our ramp time */
    /*  in perceived silence. If the value is too large, the audio will lurch */
    /*  into perceptability at the start of the ramp. */
    /*  UPDATE: This will now loop over 4 rampers */
    /* '<S1444>:1:48' currentGainLinear = zeros(1,MaskNumRampers,'single'); */
    /* '<S1444>:1:49' for i = 1:MaskNumRampers */
    /* '<S1444>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_0 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].currentGain,
         5.0118723E-7F);

    /* '<S1444>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear = fmaxf(Model_Target_B.sf_calculate_SB_gains.targetGainsSB
        [0], 5.0118723E-7F);

    /* '<S1444>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_1 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].currentGain,
         5.0118723E-7F);

    /* '<S1444>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_0 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains.targetGainsSB[1], 5.0118723E-7F);

    /* '<S1444>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_2 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].currentGain,
         5.0118723E-7F);

    /* '<S1444>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_1 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains.targetGainsSB[2], 5.0118723E-7F);

    /* '<S1444>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_3 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].currentGain,
         5.0118723E-7F);

    /* '<S1444>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_2 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains.targetGainsSB[3], 5.0118723E-7F);

    /*  Step 3a: If a slope in dB/second is provided, ignore the ramp time */
    /*  and instead calculate a new ramp time that matches the slope. */
    /* '<S1444>:1:56' rampMs = zeros(1,MaskNumRampers,'single'); */
    /* '<S1444>:1:57' if (rampdbPerSec) */
    if (Model_Target_B.sf_calculate_ramp_parameters_b.rampRate != 0.0F)
    {
        /* '<S1444>:1:58' currentGainDb = 20*log10(currentGainLinear); */
        /* '<S1444>:1:59' targetGainDb = 20*log10(targetGainLinear); */
        /* '<S1444>:1:60' diff = abs(currentGainDb - targetGainDb); */
        /* '<S1444>:1:61' rampMs = diff / single(rampdbPerSec) * 1000; */
        diff_idx_0 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_0) - 20.0F * qhmath_log10_f(targetGainLinear)),
            Model_Target_B.sf_calculate_ramp_parameters_b.rampRate) * 1000.0F;
        diff_idx_1 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_1) - 20.0F * qhmath_log10_f
            (targetGainLinear_0)),
            Model_Target_B.sf_calculate_ramp_parameters_b.rampRate) * 1000.0F;
        diff_idx_2 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_2) - 20.0F * qhmath_log10_f
            (targetGainLinear_1)),
            Model_Target_B.sf_calculate_ramp_parameters_b.rampRate) * 1000.0F;
        diff_idx_3 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_3) - 20.0F * qhmath_log10_f
            (targetGainLinear_2)),
            Model_Target_B.sf_calculate_ramp_parameters_b.rampRate) * 1000.0F;
    }
    else
    {
        /* '<S1444>:1:62' else */
        /* '<S1444>:1:63' rampMs(:) = single(rampTimesMs); */
        diff_idx_0 = Model_Target_B.sf_calculate_ramp_parameters_b.ramptime;
        diff_idx_1 = Model_Target_B.sf_calculate_ramp_parameters_b.ramptime;
        diff_idx_2 = Model_Target_B.sf_calculate_ramp_parameters_b.ramptime;
        diff_idx_3 = Model_Target_B.sf_calculate_ramp_parameters_b.ramptime;
    }

    /*  Step 3b: QUANTIZE the desired ramp time to our FrameSize. Also retrieve  */
    /*  the whole number of frames required to best match requested ramp time. */
    /*  Ensure that at least one frame is used. The frame size will therefore */
    /*  determine the steepest ramp (i.e. within one frame you can go anywhere). */
    /* '<S1444>:1:70' quantumMs = 1000 * frameSize / sampleRateInHertz; */
    quantumMs = qhmath_div_f(1000.0F * 8.0, 11076.923076923078);

    /* '<S1444>:1:71' numFrames = rampMs / quantumMs; */
    /* '<S1444>:1:72' numFrames = max (1, ceil(numFrames)); */
    /* '<S1444>:1:73' quantizedRampTimeMs = numFrames * quantumMs; */
    /*  UPDATE: Loop over 4 rampers now (L, R, C, and Mono) */
    /* '<S1444>:1:76' for ramper=1:MaskNumRampers */
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_0, quantumMs)));

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
    /* '<S1444>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1444>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1444>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].frameCount =
            MAX_int32_T;
    }

    /* '<S1444>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].targetGain =
        targetGainLinear;

    /* '<S1444>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear,
                        currentGainLinear_idx_0)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 11076.923076923078, 1000.0F)));

    /* '<S1444>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[0].currentGain =
        currentGainLinear_idx_0;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_1, quantumMs)));

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
    /* '<S1444>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1444>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1444>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].frameCount =
            MAX_int32_T;
    }

    /* '<S1444>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].targetGain =
        targetGainLinear_0;

    /* '<S1444>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_0,
                        currentGainLinear_idx_1)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 11076.923076923078, 1000.0F)));

    /* '<S1444>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[1].currentGain =
        currentGainLinear_idx_1;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_2, quantumMs)));

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
    /* '<S1444>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1444>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1444>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].frameCount =
            MAX_int32_T;
    }

    /* '<S1444>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].targetGain =
        targetGainLinear_1;

    /* '<S1444>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_1,
                        currentGainLinear_idx_2)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 11076.923076923078, 1000.0F)));

    /* '<S1444>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[2].currentGain =
        currentGainLinear_idx_2;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_3, quantumMs)));

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
    /* '<S1444>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1444>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1444>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].frameCount =
            MAX_int32_T;
    }

    /* '<S1444>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].targetGain =
        targetGainLinear_2;

    /* '<S1444>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_2,
                        currentGainLinear_idx_3)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 11076.923076923078, 1000.0F)));

    /* '<S1444>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[3].currentGain =
        currentGainLinear_idx_3;

    /* End of MATLAB Function: '<S1432>/control' */

    /* Outputs for Function Call SubSystem: '<S1432>/SetDsm1' */
    /*  unfreeze the gain. This step now done externally on canvas */
    Model_Target_SetDsm_h(0U);

    /* End of Outputs for SubSystem: '<S1432>/SetDsm1' */
}

/*
 * Output and update for function-call system:
 *    '<S1452>/SetDsm'
 *    '<S1452>/SetDsm1'
 */
void Model_Target_SetDsm_lc(uint32_T rtp_Value)
{
    /* DataStoreWrite: '<S1454>/Data Store Write' incorporates:
     *  Constant: '<S1454>/Constant'
     */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRFreeze = rtp_Value;
}

/* Output and update for function-call system: '<S1453>/REQ' */
void HandleReqPreAmpSleepingBeautyFRSet(void)
{
    real32_T currentGainLinear_idx_0;
    real32_T currentGainLinear_idx_1;
    real32_T currentGainLinear_idx_2;
    real32_T currentGainLinear_idx_3;
    real32_T diff_idx_0;
    real32_T diff_idx_1;
    real32_T diff_idx_2;
    real32_T diff_idx_3;
    real32_T quantumMs;
    real32_T targetGainLinear;
    real32_T targetGainLinear_0;
    real32_T targetGainLinear_1;
    real32_T targetGainLinear_2;

    /* MATLAB Function: '<S1452>/calculate_SB_gains' */
    /* MATLAB Function: '<S1452>/calculate_SB_gains' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S1469>:1' */
    /* '<S1469>:1:3' go(); */
    Model_Target_calculate_SB_gains
        (Model_TargetPreAmpSleepingBeautyFRSetRtcOut.REQ_gain_index,
         &(Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableDb[0]),
         &(Model_Target_PreAmp_p9_b0.SleepingBeautyFRTableIdx[0]),
         Model_Target_PreAmp_p9_b0.SleepingBeautyFROffset,
         Model_Target_PreAmp_p9_b0.SleepingBeautyFRMutesBass,
         &Model_Target_B.sf_calculate_SB_gains_hk);

    /* MATLAB Function: '<S1452>/calculate_ramp_parameters' */
    /* MATLAB Function: '<S1452>/calculate_ramp_parameters' */
    Model_Target_calculate_ramp_parameters
        (Model_Target_PreAmp_p9_b0.SleepingBeautyFRRampTime,
         Model_TargetPreAmpSleepingBeautyFRSetRtcOut.REQ_ramp_db_per_second,
         Model_TargetPreAmpSleepingBeautyFRSetRtcOut.REQ_ramp_milliseconds,
         &Model_Target_B.sf_calculate_ramp_parameters_c2);

    /* Outputs for Function Call SubSystem: '<S1452>/SetDsm' */
    Model_Target_SetDsm_lc(1U);

    /* End of Outputs for SubSystem: '<S1452>/SetDsm' */

    /* MATLAB Function: '<S1452>/control' */
    /* MATLAB Function: '<S1452>/control' incorporates:
     *  S-Function (AudioStats_MEX): '<S1452>/Audio Stats'
     */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyFR/InnerLink/control': '<S1464>:1' */
    /*  CONTROL LOGIC: */
    /*  Shift of 'balance' between the 'Right' and 'Left' channel groups is */
    /*  achieved by multiplying the corresponding 'cut' or 'boost' gain. As the */
    /*  index increases from 0, the balance shifts from left to right. */
    /*  rampdbPerSec takes precidence: */
    /*    If dbPerSec has a non-zero value then any ramp_times_ms values are */
    /*    ignored and the dbPerSec is used to determine ramper timing. */
    /*  Inputs: */
    /*    targetGainLinear: Indicates the gain (in linear scale) which needs to */
    /*        be applied to the audio. Gain values can be mapped to the ramper */
    /*        configuration. */
    /*    rampTimeMs: Indicates the time in milliseconds in which the gain of the */
    /*        rampers must change from their current to target values. */
    /*    rampdbPerSecond: Indicates the rate in dB/second at which the gain of the */
    /*        rampers must change from their current to target values. If this */
    /*        value is non-zero, it is used to compute the ramp time and */
    /*        'rampTimeMs' is discarded (if specified). */
    /*    rgain_SILENT_GAIN: Parameter defined in the initFcn callback. */
    /*  Control Data: */
    /*    Freeze(1) freezes the processing during this control operation */
    /*    Rampers(1) is the ramper for the left speaker */
    /*    Rampers(2) is the ramper for the right speaker */
    /*    Rampers(3) is the ramper for the center speaker */
    /*    Rampers(4) is the ramper for the mono speaker */
    /* '<S1464>:1:34' rgain_SILENT_GAIN = RgainBusUtil.GetSilentGainLinear(); */
    /*  Step 1: FREEZE the gain ramper so that we can perform calculations based */
    /*  on the current gain value. This step now done externally on canvas */
    /*  Step 2: Nudge the gain values a bit if they are sitting at zero. */
    /*  When this control set goes live, ensure that the current gain will move. */
    /*  If current gain is zero, replace with a value very close to zero. What we */
    /*  really want is a value which is on the edge of perception - not too small */
    /*  or large. If the value is too small, we'll waste some of our ramp time */
    /*  in perceived silence. If the value is too large, the audio will lurch */
    /*  into perceptability at the start of the ramp. */
    /*  UPDATE: This will now loop over 4 rampers */
    /* '<S1464>:1:48' currentGainLinear = zeros(1,MaskNumRampers,'single'); */
    /* '<S1464>:1:49' for i = 1:MaskNumRampers */
    /* '<S1464>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_0 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].currentGain,
         5.0118723E-7F);

    /* '<S1464>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear = fmaxf
        (Model_Target_B.sf_calculate_SB_gains_hk.targetGainsSB[0], 5.0118723E-7F);

    /* '<S1464>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_1 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].currentGain,
         5.0118723E-7F);

    /* '<S1464>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_0 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains_hk.targetGainsSB[1], 5.0118723E-7F);

    /* '<S1464>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_2 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].currentGain,
         5.0118723E-7F);

    /* '<S1464>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_1 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains_hk.targetGainsSB[2], 5.0118723E-7F);

    /* '<S1464>:1:50' currentGainLinear(i) = max(Rampers(i).currentGain, rgain_SILENT_GAIN); */
    currentGainLinear_idx_3 = fmaxf
        (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].currentGain,
         5.0118723E-7F);

    /* '<S1464>:1:51' targetGainLinear(i) = max(targetGainLinear(i), rgain_SILENT_GAIN); */
    targetGainLinear_2 = fmaxf
        (Model_Target_B.sf_calculate_SB_gains_hk.targetGainsSB[3], 5.0118723E-7F);

    /*  Step 3a: If a slope in dB/second is provided, ignore the ramp time */
    /*  and instead calculate a new ramp time that matches the slope. */
    /* '<S1464>:1:56' rampMs = zeros(1,MaskNumRampers,'single'); */
    /* '<S1464>:1:57' if (rampdbPerSec) */
    if (Model_Target_B.sf_calculate_ramp_parameters_c2.rampRate != 0.0F)
    {
        /* '<S1464>:1:58' currentGainDb = 20*log10(currentGainLinear); */
        /* '<S1464>:1:59' targetGainDb = 20*log10(targetGainLinear); */
        /* '<S1464>:1:60' diff = abs(currentGainDb - targetGainDb); */
        /* '<S1464>:1:61' rampMs = diff / single(rampdbPerSec) * 1000; */
        diff_idx_0 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_0) - 20.0F * qhmath_log10_f(targetGainLinear)),
            Model_Target_B.sf_calculate_ramp_parameters_c2.rampRate) * 1000.0F;
        diff_idx_1 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_1) - 20.0F * qhmath_log10_f
            (targetGainLinear_0)),
            Model_Target_B.sf_calculate_ramp_parameters_c2.rampRate) * 1000.0F;
        diff_idx_2 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_2) - 20.0F * qhmath_log10_f
            (targetGainLinear_1)),
            Model_Target_B.sf_calculate_ramp_parameters_c2.rampRate) * 1000.0F;
        diff_idx_3 = qhmath_div_f(qhmath_abs_f(20.0F * qhmath_log10_f
            (currentGainLinear_idx_3) - 20.0F * qhmath_log10_f
            (targetGainLinear_2)),
            Model_Target_B.sf_calculate_ramp_parameters_c2.rampRate) * 1000.0F;
    }
    else
    {
        /* '<S1464>:1:62' else */
        /* '<S1464>:1:63' rampMs(:) = single(rampTimesMs); */
        diff_idx_0 = Model_Target_B.sf_calculate_ramp_parameters_c2.ramptime;
        diff_idx_1 = Model_Target_B.sf_calculate_ramp_parameters_c2.ramptime;
        diff_idx_2 = Model_Target_B.sf_calculate_ramp_parameters_c2.ramptime;
        diff_idx_3 = Model_Target_B.sf_calculate_ramp_parameters_c2.ramptime;
    }

    /*  Step 3b: QUANTIZE the desired ramp time to our FrameSize. Also retrieve  */
    /*  the whole number of frames required to best match requested ramp time. */
    /*  Ensure that at least one frame is used. The frame size will therefore */
    /*  determine the steepest ramp (i.e. within one frame you can go anywhere). */
    /* '<S1464>:1:70' quantumMs = 1000 * frameSize / sampleRateInHertz; */
    quantumMs = qhmath_div_f(1000.0F * 32.0, 44307.692307692312);

    /* '<S1464>:1:71' numFrames = rampMs / quantumMs; */
    /* '<S1464>:1:72' numFrames = max (1, ceil(numFrames)); */
    /* '<S1464>:1:73' quantizedRampTimeMs = numFrames * quantumMs; */
    /*  UPDATE: Loop over 4 rampers now (L, R, C, and Mono) */
    /* '<S1464>:1:76' for ramper=1:MaskNumRampers */
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_0, quantumMs)));

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
    /* '<S1464>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1464>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1464>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].frameCount =
            MAX_int32_T;
    }

    /* '<S1464>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].targetGain =
        targetGainLinear;

    /* '<S1464>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear,
                        currentGainLinear_idx_0)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 44307.692307692312, 1000.0F)));

    /* '<S1464>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[0].currentGain =
        currentGainLinear_idx_0;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_1, quantumMs)));

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
    /* '<S1464>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1464>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1464>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].frameCount =
            MAX_int32_T;
    }

    /* '<S1464>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].targetGain =
        targetGainLinear_0;

    /* '<S1464>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_0,
                        currentGainLinear_idx_1)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 44307.692307692312, 1000.0F)));

    /* '<S1464>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[1].currentGain =
        currentGainLinear_idx_1;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_2, quantumMs)));

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
    /* '<S1464>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1464>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1464>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].frameCount =
            MAX_int32_T;
    }

    /* '<S1464>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].targetGain =
        targetGainLinear_1;

    /* '<S1464>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_1,
                        currentGainLinear_idx_2)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 44307.692307692312, 1000.0F)));

    /* '<S1464>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[2].currentGain =
        currentGainLinear_idx_2;
    diff_idx_0 = fmaxf(1.0F, qhmath_ceil_f(qhmath_div_f(diff_idx_3, quantumMs)));

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
    /* '<S1464>:1:89' factor = log( targetGainLinear(ramper) / currentGainLinear(ramper) ); */
    /* '<S1464>:1:90' RampCoef = double(exp(factor / (sampleRateInHertz * quantizedRampTimeMs(ramper) / 1000))); */
    /*  Output control signals */
    /* '<S1464>:1:93' Rampers(ramper).frameCount  = int32(numFrames(ramper)); */
    if (diff_idx_0 < 2.14748365E+9F)
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].frameCount =
            (int32_T)diff_idx_0;
    }
    else
    {
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].frameCount =
            MAX_int32_T;
    }

    /* '<S1464>:1:94' Rampers(ramper).targetGain  = targetGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].targetGain =
        targetGainLinear_2;

    /* '<S1464>:1:95' Rampers(ramper).rampCoeff = single(RampCoef); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].rampCoeff =
        qhmath_exp_f(qhmath_div_f(qhmath_log_f(qhmath_div_f(targetGainLinear_2,
                        currentGainLinear_idx_3)), qhmath_div_f(diff_idx_0 *
                       quantumMs * 44307.692307692312, 1000.0F)));

    /* '<S1464>:1:96' Rampers(ramper).currentGain = currentGainLinear(ramper); */
    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[3].currentGain =
        currentGainLinear_idx_3;

    /* End of MATLAB Function: '<S1452>/control' */

    /* Outputs for Function Call SubSystem: '<S1452>/SetDsm1' */
    /*  unfreeze the gain. This step now done externally on canvas */
    Model_Target_SetDsm_lc(0U);

    /* End of Outputs for SubSystem: '<S1452>/SetDsm1' */
}

/* Function for MATLAB Function: '<S1432>/sleepingBeautyProcess' */
static void Model_Target_eml_find_i(const boolean_T x[30], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 30))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 30)
            {
                exitg1 = true;
            }
            else
            {
                ii++;
            }
        }
        else
        {
            ii++;
        }
    }

    if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

/* Function for MATLAB Function: '<S1452>/sleepingBeautyProcess' */
static void Model_Target_eml_find_e(const boolean_T x[22], int32_T i_data[],
    int32_T i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 22))
    {
        if (x[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= 22)
            {
                exitg1 = true;
            }
            else
            {
                ii++;
            }
        }
        else
        {
            ii++;
        }
    }

    if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

/* System initialize for atomic system: '<S1345>/Enabled' */
void Model_Target_Enabled_Init(void)
{
    /* SystemInitialize for Atomic SubSystem: '<S1400>/Ramping_Subsystem' */
    /* SystemInitialize for IfAction SubSystem: '<S1404>/ifActionSubsystem' */
    /* InitializeConditions for DiscreteFilter: '<S1407>/ramping_filter' */
    Model_Target_DW.ramping_filter_icLoad_i = 1U;

    /* End of SystemInitialize for SubSystem: '<S1404>/ifActionSubsystem' */
    /* End of SystemInitialize for SubSystem: '<S1400>/Ramping_Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<S1413>/Ramping_Subsystem' */
    /* SystemInitialize for IfAction SubSystem: '<S1417>/ifActionSubsystem' */
    /* InitializeConditions for DiscreteFilter: '<S1420>/ramping_filter' */
    Model_Target_DW.ramping_filter_icLoad_f = 1U;

    /* End of SystemInitialize for SubSystem: '<S1417>/ifActionSubsystem' */
    /* End of SystemInitialize for SubSystem: '<S1413>/Ramping_Subsystem' */
    /* '<S1381>:1:12' filterStates = zeros(1,channel_count,'single'); */
    /* '<S1388>:1:12' filterStates = zeros(1,channel_count,'single'); */
}

/* Output and update for atomic system: '<S1345>/Enabled' */
void Model_Target_Enabled(void)
{
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T ForEach_itr_j;
    int32_T d_data[30];
    int32_T d_data_0[22];
    int32_T d_size[2];
    int32_T b;
    int32_T ch;
    int32_T d_tmp;
    int32_T i;
    int32_T ramper;
    real32_T rampCoeffMultipliers_0[32];
    real32_T rtb_Merge[32];
    real32_T rampCoeffMultipliers[8];
    real32_T rtb_Merge_o2[8];
    real32_T gain;
    real32_T rtb_Max_b;
    real32_T rtb_yLpf_a_tmp;
    real32_T rtb_yLpf_e;
    real32_T tmp_1;
    boolean_T tmp[30];
    boolean_T tmp_0[22];
    boolean_T rtb_Merge_b;

    /* MATLAB Function: '<S1432>/sleepingBeautyProcess' incorporates:
     *  S-Function (TOP_MEX): '<S1432>/TOP'
     */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/sleepingBeautyProcess': '<S1445>:1' */
    /*  Applies the Left and Right gains to the respective channels via multiple */
    /*    rampers */
    /*  Inputs: */
    /*   audioIn: Input audio */
    /*   channelToRamperMap: Input channels mapped to their corresponding ramper. */
    /*   MaskNumRampers: Number of rampers (set in the Mask file) = 4 */
    /*  Data Store objects (registered in "Edit Data" dialog) */
    /*  Figure out the frame size, channel count and number of rampers */
    /* '<S1445>:1:16' [frameSize, ~] = size(audioIn); */
    /*  set the size and datatype of the output buffer */
    /* '<S1445>:1:19' audioOut = coder.nullcopy(audioIn); */
    /*    Every channel needs a ramper, but every ramper does not need to be on a */
    /*    channel necessarily. */
    /* '<S1445>:1:23' for ramper = 1:MaskNumRampers */
    for (ramper = 0; ramper < 4; ramper++)
    {
        /*  Get the gains */
        /* '<S1445>:1:25' gain = Rampers(ramper).currentGain; */
        gain = Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper].
            currentGain;

        /* '<S1445>:1:26' rampCoeffMultipliers = ones(1, frameSize, 'single'); */
        for (i = 0; i < 8; i++)
        {
            rampCoeffMultipliers[i] = 1.0F;
        }

        /* '<S1445>:1:27' if (Freeze(1) == false) */
        if (Model_TargetControlDsms.PreAmpSleepingBeautyDRFreeze == 0U)
        {
            /* '<S1445>:1:28' if (Rampers(ramper).frameCount == 0) */
            if (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper].
                    frameCount == 0)
            {
                /*  The ramp is finished. Stop ramping and SNAP to the target */
                /* '<S1445>:1:30' gain = Rampers(ramper).targetGain; */
                gain =
                    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper]
                    .targetGain;
            }
            else
            {
                /* '<S1445>:1:31' else */
                /*  The ramp is *NOT* frozen or done: gain is moving */
                /* '<S1445>:1:33' k = Rampers(ramper).rampCoeff; */
                /* '<S1445>:1:34' rampCoeffMultipliers = (k * rampCoeffMultipliers) .^ (1:frameSize); */
                for (i = 0; i < 8; i++)
                {
                    rampCoeffMultipliers[i] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper]
                         .rampCoeff, (real32_T)((real_T)i + 1.0));
                }

                /* '<S1445>:1:35' Rampers(ramper).frameCount = Rampers(ramper).frameCount - 1; */
                i = Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper]
                    .frameCount;
                if (i < -2147483647)
                {
                    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper]
                        .frameCount = MIN_int32_T;
                }
                else
                {
                    Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper]
                        .frameCount = i - 1;
                }
            }
        }

        /*  Apply the gains to the corresponding channels via the Mask parameter */
        /*  and tuneTop paramter "channelToRamperMap".   */
        /* '<S1445>:1:41' currentChannelGroup = find(channelToRamperMap == ramper); */
        for (i = 0; i < 30; i++)
        {
            tmp[i] = ((real_T)(ramper + 1) ==
                      Model_Target_PreAmp_p9_b0.SleepingBeautyDRChannelToRamperMap
                      [i]);
        }

        Model_Target_eml_find_i(tmp, d_data, d_size);

        /* '<S1445>:1:42' for ch = 1:numel(currentChannelGroup) */
        b = d_size[1];
        for (ch = 0; ch < b; ch++)
        {
            /* '<S1445>:1:43' audioOut(:,currentChannelGroup(ch)) = (gain * rampCoeffMultipliers)' .* audioIn(:,currentChannelGroup(ch)); */
            d_tmp = d_data[ch];
            for (i = 0; i < 8; i++)
            {
                Model_Target_B.audioOut_n[i + ((d_tmp - 1) << 3)] =
                    Model_Target_Medusa5H1Part6_B.audioOut_d[((d_tmp - 1) << 3)
                    + i] * (gain * rampCoeffMultipliers[i]);
            }
        }

        /* '<S1445>:1:45' Rampers(ramper).currentGain = gain * rampCoeffMultipliers(end); */
        Model_TargetControlDsms.PreAmpSleepingBeautyDRRampers[ramper].
            currentGain = gain * rampCoeffMultipliers[7];
    }

    /*  If ramper value of -1 is encountered, this indicates an unused channel. */
    /*  Assign values of zero to all samples of these channels. */
    /* '<S1445>:1:50' unusedChannelGroup = find(channelToRamperMap == -1); */
    for (i = 0; i < 30; i++)
    {
        tmp[i] = (Model_Target_PreAmp_p9_b0.SleepingBeautyDRChannelToRamperMap[i]
                  == -1.0F);
    }

    Model_Target_eml_find_i(tmp, d_data, d_size);

    /* '<S1445>:1:51' for unusedCh = 1:numel(unusedChannelGroup) */
    ramper = d_size[1];
    for (b = 0; b < ramper; b++)
    {
        /* '<S1445>:1:52' audioOut(:,unusedChannelGroup(unusedCh)) = 0; */
        ch = d_data[b];
        for (i = 0; i < 8; i++)
        {
            Model_Target_B.audioOut_n[i + ((ch - 1) << 3)] = 0.0F;
        }
    }

    /* End of MATLAB Function: '<S1432>/sleepingBeautyProcess' */

    /* DataStoreRead: '<S1400>/Data Store Read' */
    Model_Target_B.DataStoreRead_f3 =
        Model_TargetControlDsms.PreAmpMuteDRCurrentGain;

    /* DataStoreRead: '<S1400>/Data Store Read1' */
    gain = Model_TargetControlDsms.PreAmpMuteDRTargetLinearGain;

    /* DataStoreRead: '<S1413>/Data Store Read' */
    Model_Target_B.DataStoreRead_b =
        Model_TargetControlDsms.PreAmpMuteFRCurrentGain;

    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1390>/RTC Request Response Trigger' */

    /* Outputs for Atomic SubSystem: '<S1400>/Ramping_Subsystem' */
    /* MinMax: '<S1404>/Max' incorporates:
     *  Constant: '<S1404>/minGain'
     */
    rtb_Max_b = fmaxf(Model_Target_B.DataStoreRead_f3, 4.7315126E-7F);

    /* If: '<S1404>/If' incorporates:
     *  Abs: '<S1404>/Abs3'
     *  Constant: '<S1400>/snapThresh'
     *  DataStoreRead: '<S1404>/frames'
     *  Sum: '<S1404>/Add'
     */
    if ((qhmath_abs_f(gain - rtb_Max_b) > 1.0E-9F) &&
            (Model_TargetControlDsms.PreAmpMuteDRNframes > 0.0F))
    {
        /* Outputs for IfAction SubSystem: '<S1404>/ifActionSubsystem' incorporates:
         *  ActionPort: '<S1407>/Action Port'
         */
        /* DataStoreWrite: '<S1407>/Data Store Write' incorporates:
         *  Constant: '<S1407>/Constant1'
         *  Sum: '<S1407>/Add'
         */
        Model_TargetControlDsms.PreAmpMuteDRNframes =
            Model_TargetControlDsms.PreAmpMuteDRNframes - 1.0F;

        /* If: '<S1409>/If' incorporates:
         *  Delay: '<S1409>/Delay'
         *  Sum: '<S1409>/Add2'
         */
        if (gain - Model_Target_DW.Delay_DSTATE_c == 0.0F)
        {
            /* Outputs for IfAction SubSystem: '<S1409>/If Action Subsystem' incorporates:
             *  ActionPort: '<S1410>/Action Port'
             */
            Model_Target_IfActionSubsystem(&rtb_Merge_b);

            /* End of Outputs for SubSystem: '<S1409>/If Action Subsystem' */
        }
        else
        {
            /* Outputs for IfAction SubSystem: '<S1409>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S1411>/Action Port'
             */
            Model_Target_IfActionSubsystem1(&rtb_Merge_b);

            /* End of Outputs for SubSystem: '<S1409>/If Action Subsystem1' */
        }

        /* End of If: '<S1409>/If' */

        /* DiscreteFilter: '<S1407>/ramping_filter' incorporates:
         *  Merge: '<S1404>/Merge'
         *  Product: '<S1407>/Matrix Multiply'
         *  Product: '<S1408>/Multiply'
         */
        if (rtb_Merge_b)
        {
            Model_Target_DW.ramping_filter_icLoad_i = 1U;
        }

        if (Model_Target_DW.ramping_filter_icLoad_i != 0)
        {
            Model_Target_DW.ramping_filter_states_e =
                Model_Target_B.ramping_coeff_m * rtb_Max_b;
        }

        ramper = 0;
        for (ch = 0; ch < 8; ch++)
        {
            rtb_Merge_o2[ramper] = Model_Target_DW.ramping_filter_states_e;
            Model_Target_DW.ramping_filter_states_e = 0.0F -
                -Model_Target_B.ramping_coeff_m * rtb_Merge_o2[ramper];
            ramper++;
        }

        /* End of DiscreteFilter: '<S1407>/ramping_filter' */

        /* Update for Delay: '<S1409>/Delay' */
        Model_Target_DW.Delay_DSTATE_c = gain;

        /* Update for DiscreteFilter: '<S1407>/ramping_filter' */
        Model_Target_DW.ramping_filter_icLoad_i = 0U;

        /* End of Outputs for SubSystem: '<S1404>/ifActionSubsystem' */
    }
    else
    {
        /* Outputs for IfAction SubSystem: '<S1404>/elseActionSubsystem' incorporates:
         *  ActionPort: '<S1406>/Action Port'
         */
        /* Product: '<S1406>/Multiply' incorporates:
         *  Merge: '<S1404>/Merge'
         */
        for (i = 0; i < 8; i++)
        {
            rtb_Merge_o2[i] = gain;
        }

        /* End of Product: '<S1406>/Multiply' */
        /* End of Outputs for SubSystem: '<S1404>/elseActionSubsystem' */
    }

    /* End of If: '<S1404>/If' */

    /* S-Function (sdspperm2): '<S1401>/Variable Selector' incorporates:
     *  DataStoreWrite: '<S1400>/Data Store Write'
     *  Merge: '<S1404>/Merge'
     */
    Model_TargetControlDsms.PreAmpMuteDRCurrentGain = rtb_Merge_o2[7];

    /* Outputs for Iterator SubSystem: '<S1405>/For Each Subsystem' incorporates:
     *  ForEach: '<S1412>/For Each'
     */
    for (ForEach_itr_j = 0; ForEach_itr_j < 8; ForEach_itr_j++)
    {
        /* ForEachSliceSelector generated from: '<S1412>/In1' incorporates:
         *  Merge: '<S1404>/Merge'
         */
        gain = rtb_Merge_o2[ForEach_itr_j];

        /* ForEachSliceAssignment generated from: '<S1412>/Out1' incorporates:
         *  Product: '<S1412>/Multiply'
         */
        for (i = 0; i < 30; i++)
        {
            ramper = (i << 3) + ForEach_itr_j;
            Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0_n[ramper] =
                Model_Target_B.audioOut_n[ramper] * gain;
        }
    }

    /* End of Outputs for SubSystem: '<S1405>/For Each Subsystem' */
    /* End of Outputs for SubSystem: '<S1400>/Ramping_Subsystem' */
    /* End of Outputs for S-Function (RTC_NTF): '<S1390>/NTF Trigger' */
    /* MATLAB Function: '<S1452>/sleepingBeautyProcess' incorporates:
     *  S-Function (TOP_MEX): '<S1452>/TOP'
     */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyFR/InnerLink/sleepingBeautyProcess': '<S1465>:1' */
    /*  Applies the Left and Right gains to the respective channels via multiple */
    /*    rampers */
    /*  Inputs: */
    /*   audioIn: Input audio */
    /*   channelToRamperMap: Input channels mapped to their corresponding ramper. */
    /*   MaskNumRampers: Number of rampers (set in the Mask file) = 4 */
    /*  Data Store objects (registered in "Edit Data" dialog) */
    /*  Figure out the frame size, channel count and number of rampers */
    /* '<S1465>:1:16' [frameSize, ~] = size(audioIn); */
    /*  set the size and datatype of the output buffer */
    /* '<S1465>:1:19' audioOut = coder.nullcopy(audioIn); */
    /*    Every channel needs a ramper, but every ramper does not need to be on a */
    /*    channel necessarily. */
    /* '<S1465>:1:23' for ramper = 1:MaskNumRampers */
    for (ramper = 0; ramper < 4; ramper++)
    {
        /*  Get the gains */
        /* '<S1465>:1:25' gain = Rampers(ramper).currentGain; */
        gain = Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper].
            currentGain;

        /* '<S1465>:1:26' rampCoeffMultipliers = ones(1, frameSize, 'single'); */
        for (i = 0; i < 32; i++)
        {
            rampCoeffMultipliers_0[i] = 1.0F;
        }

        /* '<S1465>:1:27' if (Freeze(1) == false) */
        if (Model_TargetControlDsms.PreAmpSleepingBeautyFRFreeze == 0U)
        {
            /* '<S1465>:1:28' if (Rampers(ramper).frameCount == 0) */
            if (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper].
                    frameCount == 0)
            {
                /*  The ramp is finished. Stop ramping and SNAP to the target */
                /* '<S1465>:1:30' gain = Rampers(ramper).targetGain; */
                gain =
                    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper]
                    .targetGain;
            }
            else
            {
                /* '<S1465>:1:31' else */
                /*  The ramp is *NOT* frozen or done: gain is moving */
                /* '<S1465>:1:33' k = Rampers(ramper).rampCoeff; */
                /* '<S1465>:1:34' rampCoeffMultipliers = (k * rampCoeffMultipliers) .^ (1:frameSize); */
                for (i = 0; i < 32; i++)
                {
                    rampCoeffMultipliers_0[i] = qhmath_pow_f
                        (Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper]
                         .rampCoeff, (real32_T)((real_T)i + 1.0));
                }

                /* '<S1465>:1:35' Rampers(ramper).frameCount = Rampers(ramper).frameCount - 1; */
                i = Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper]
                    .frameCount;
                if (i < -2147483647)
                {
                    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper]
                        .frameCount = MIN_int32_T;
                }
                else
                {
                    Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper]
                        .frameCount = i - 1;
                }
            }
        }

        /*  Apply the gains to the corresponding channels via the Mask parameter */
        /*  and tuneTop paramter "channelToRamperMap".   */
        /* '<S1465>:1:41' currentChannelGroup = find(channelToRamperMap == ramper); */
        for (i = 0; i < 22; i++)
        {
            tmp_0[i] = ((real_T)(ramper + 1) ==
                        Model_Target_PreAmp_p9_b0.SleepingBeautyFRChannelToRamperMap
                        [i]);
        }

        Model_Target_eml_find_e(tmp_0, d_data_0, d_size);

        /* '<S1465>:1:42' for ch = 1:numel(currentChannelGroup) */
        b = d_size[1];
        for (ch = 0; ch < b; ch++)
        {
            /* '<S1465>:1:43' audioOut(:,currentChannelGroup(ch)) = (gain * rampCoeffMultipliers)' .* audioIn(:,currentChannelGroup(ch)); */
            d_tmp = d_data_0[ch];
            for (i = 0; i < 32; i++)
            {
                Model_Target_B.audioOut[i + ((d_tmp - 1) << 5)] =
                    Model_Target_Medusa5H1Part6_B.audioOut[((d_tmp - 1) << 5) +
                    i] * (gain * rampCoeffMultipliers_0[i]);
            }
        }

        /* '<S1465>:1:45' Rampers(ramper).currentGain = gain * rampCoeffMultipliers(end); */
        Model_TargetControlDsms.PreAmpSleepingBeautyFRRampers[ramper].
            currentGain = gain * rampCoeffMultipliers_0[31];
    }

    /*  If ramper value of -1 is encountered, this indicates an unused channel. */
    /*  Assign values of zero to all samples of these channels. */
    /* '<S1465>:1:50' unusedChannelGroup = find(channelToRamperMap == -1); */
    for (i = 0; i < 22; i++)
    {
        tmp_0[i] =
            (Model_Target_PreAmp_p9_b0.SleepingBeautyFRChannelToRamperMap[i] ==
             -1.0F);
    }

    Model_Target_eml_find_e(tmp_0, d_data_0, d_size);

    /* '<S1465>:1:51' for unusedCh = 1:numel(unusedChannelGroup) */
    ramper = d_size[1];
    for (b = 0; b < ramper; b++)
    {
        /* '<S1465>:1:52' audioOut(:,unusedChannelGroup(unusedCh)) = 0; */
        ch = d_data_0[b];
        memset(&Model_Target_B.audioOut[(ch << 5) + -32], 0, sizeof(real32_T) <<
               5U);
    }

    /* End of MATLAB Function: '<S1452>/sleepingBeautyProcess' */

    /* Outputs for Atomic SubSystem: '<S1413>/Ramping_Subsystem' */
    /* MinMax: '<S1417>/Max' incorporates:
     *  Constant: '<S1417>/minGain'
     */
    gain = fmaxf(Model_Target_B.DataStoreRead_b, 4.7315126E-7F);

    /* If: '<S1417>/If' incorporates:
     *  Abs: '<S1417>/Abs3'
     *  Constant: '<S1413>/snapThresh'
     *  DataStoreRead: '<S1413>/Data Store Read1'
     *  DataStoreRead: '<S1417>/frames'
     *  Sum: '<S1417>/Add'
     */
    if ((qhmath_abs_f(Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain -
                      gain) > 1.0E-9F) &&
            (Model_TargetControlDsms.PreAmpMuteFRNframes > 0.0F))
    {
        /* Outputs for IfAction SubSystem: '<S1417>/ifActionSubsystem' incorporates:
         *  ActionPort: '<S1420>/Action Port'
         */
        /* DataStoreWrite: '<S1420>/Data Store Write' incorporates:
         *  Constant: '<S1420>/Constant1'
         *  Sum: '<S1420>/Add'
         */
        Model_TargetControlDsms.PreAmpMuteFRNframes =
            Model_TargetControlDsms.PreAmpMuteFRNframes - 1.0F;

        /* If: '<S1422>/If' incorporates:
         *  Delay: '<S1422>/Delay'
         *  Sum: '<S1422>/Add2'
         */
        if (Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain -
                Model_Target_DW.Delay_DSTATE_n == 0.0F)
        {
            /* Outputs for IfAction SubSystem: '<S1422>/If Action Subsystem' incorporates:
             *  ActionPort: '<S1423>/Action Port'
             */
            Model_Target_IfActionSubsystem(&rtb_Merge_b);

            /* End of Outputs for SubSystem: '<S1422>/If Action Subsystem' */
        }
        else
        {
            /* Outputs for IfAction SubSystem: '<S1422>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S1424>/Action Port'
             */
            Model_Target_IfActionSubsystem1(&rtb_Merge_b);

            /* End of Outputs for SubSystem: '<S1422>/If Action Subsystem1' */
        }

        /* End of If: '<S1422>/If' */

        /* DiscreteFilter: '<S1420>/ramping_filter' incorporates:
         *  Merge: '<S1417>/Merge'
         *  Product: '<S1420>/Matrix Multiply'
         *  Product: '<S1421>/Multiply'
         */
        if (rtb_Merge_b)
        {
            Model_Target_DW.ramping_filter_icLoad_f = 1U;
        }

        if (Model_Target_DW.ramping_filter_icLoad_f != 0)
        {
            Model_Target_DW.ramping_filter_states_i =
                Model_Target_B.ramping_coeff_l * gain;
        }

        ramper = 0;
        for (ch = 0; ch < 32; ch++)
        {
            rtb_Merge[ramper] = Model_Target_DW.ramping_filter_states_i;
            Model_Target_DW.ramping_filter_states_i = 0.0F -
                -Model_Target_B.ramping_coeff_l * rtb_Merge[ramper];
            ramper++;
        }

        /* End of DiscreteFilter: '<S1420>/ramping_filter' */

        /* Update for Delay: '<S1422>/Delay' */
        Model_Target_DW.Delay_DSTATE_n =
            Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain;

        /* Update for DiscreteFilter: '<S1420>/ramping_filter' */
        Model_Target_DW.ramping_filter_icLoad_f = 0U;

        /* End of Outputs for SubSystem: '<S1417>/ifActionSubsystem' */
    }
    else
    {
        /* Outputs for IfAction SubSystem: '<S1417>/elseActionSubsystem' incorporates:
         *  ActionPort: '<S1419>/Action Port'
         */
        Model_Target_elseActionSubsystem
            (Model_TargetControlDsms.PreAmpMuteFRTargetLinearGain, rtb_Merge);

        /* End of Outputs for SubSystem: '<S1417>/elseActionSubsystem' */
    }

    /* End of If: '<S1417>/If' */

    /* S-Function (sdspperm2): '<S1414>/Variable Selector' incorporates:
     *  DataStoreWrite: '<S1413>/Data Store Write'
     *  Merge: '<S1417>/Merge'
     */
    Model_TargetControlDsms.PreAmpMuteFRCurrentGain = rtb_Merge[31];

    /* Outputs for Iterator SubSystem: '<S1418>/For Each Subsystem' incorporates:
     *  ForEach: '<S1425>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 32; ForEach_itr++)
    {
        /* ForEachSliceSelector generated from: '<S1425>/In1' incorporates:
         *  Merge: '<S1417>/Merge'
         */
        gain = rtb_Merge[ForEach_itr];

        /* ForEachSliceAssignment generated from: '<S1425>/Out1' incorporates:
         *  Product: '<S1425>/Multiply'
         */
        for (i = 0; i < 22; i++)
        {
            ramper = (i << 5) + ForEach_itr;
            Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0[ramper] =
                Model_Target_B.audioOut[ramper] * gain;
        }
    }

    /* End of Outputs for SubSystem: '<S1418>/For Each Subsystem' */
    /* End of Outputs for SubSystem: '<S1413>/Ramping_Subsystem' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1360>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S1360>/NTF Trigger' */
    /* MATLAB Function: '<S1375>/lpf' incorporates:
     *  ForEachSliceAssignment generated from: '<S1412>/Out1'
     *  S-Function (TOP_MEX): '<S1375>/TOP'
     */
    /*  Applies the filter coefficients to the input audio */
    /*  Inputs:  */
    /*   audioIn: Input audio */
    /*   lpfCoeffs: Filter coefficients */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperDR/InnerLink/lpf': '<S1381>:1' */
    /* '<S1381>:1:8' [frameSize, channel_count] = size(audioIn); */
    /* '<S1381>:1:11' if (isempty(filterStates)) */
    /* '<S1381>:1:15' yLpf = coder.nullcopy(audioIn); */
    /*  Get filter coefficients */
    /* '<S1381>:1:18' bCoeffs = lpfCoeffs(1:2); */
    /* '<S1381>:1:19' aCoeffs = lpfCoeffs(3); */
    /*  Apply the filter to the audio */
    /* '<S1381>:1:22' for n = 1:frameSize */
    gain = Model_Target_PreAmp_p9_b0.FadeRamperDRTOPFilterCoefficients[0];
    rtb_Max_b = Model_Target_PreAmp_p9_b0.FadeRamperDRTOPFilterCoefficients[1];
    tmp_1 = Model_Target_PreAmp_p9_b0.FadeRamperDRTOPFilterCoefficients[2];
    for (ramper = 0; ramper < 8; ramper++)
    {
        /* '<S1381>:1:23' yLpf(n,:) = bCoeffs(1) * audioIn(n,:) + filterStates; */
        /* '<S1381>:1:24' filterStates = bCoeffs(2) * audioIn(n,:) + aCoeffs * yLpf(n,:); */
        for (i = 0; i < 30; i++)
        {
            b = (i << 3) + ramper;
            rtb_yLpf_a_tmp =
                Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0_n[b];
            rtb_yLpf_e = rtb_yLpf_a_tmp * gain +
                Model_Target_DW.filterStates_p[i];
            Model_Target_DW.filterStates_p[i] = rtb_yLpf_a_tmp * rtb_Max_b +
                tmp_1 * rtb_yLpf_e;
            Model_Target_B.yLpf_a[b] = rtb_yLpf_e;
        }
    }

    /* End of MATLAB Function: '<S1375>/lpf' */

    /* MATLAB Function: '<S1375>/fade' */
    Model_Target_fade(Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0_n,
                      &(Model_Target_PreAmp_p9_b0.FadeRamperDRChannelToRamperMap[
                        0]), Model_Target_B.yLpf_a, &Model_Target_B.sf_fade);

    /* MATLAB Function: '<S1382>/lpf' incorporates:
     *  ForEachSliceAssignment generated from: '<S1425>/Out1'
     *  S-Function (TOP_MEX): '<S1382>/TOP'
     */
    /*  Applies the filter coefficients to the input audio */
    /*  Inputs:  */
    /*   audioIn: Input audio */
    /*   lpfCoeffs: Filter coefficients */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperFR/InnerLink/lpf': '<S1388>:1' */
    /* '<S1388>:1:8' [frameSize, channel_count] = size(audioIn); */
    /* '<S1388>:1:11' if (isempty(filterStates)) */
    /* '<S1388>:1:15' yLpf = coder.nullcopy(audioIn); */
    /*  Get filter coefficients */
    /* '<S1388>:1:18' bCoeffs = lpfCoeffs(1:2); */
    /* '<S1388>:1:19' aCoeffs = lpfCoeffs(3); */
    /*  Apply the filter to the audio */
    /* '<S1388>:1:22' for n = 1:frameSize */
    gain = Model_Target_PreAmp_p9_b0.FadeRamperFRTOPFilterCoefficients[0];
    rtb_Max_b = Model_Target_PreAmp_p9_b0.FadeRamperFRTOPFilterCoefficients[1];
    tmp_1 = Model_Target_PreAmp_p9_b0.FadeRamperFRTOPFilterCoefficients[2];
    for (ramper = 0; ramper < 32; ramper++)
    {
        /* '<S1388>:1:23' yLpf(n,:) = bCoeffs(1) * audioIn(n,:) + filterStates; */
        /* '<S1388>:1:24' filterStates = bCoeffs(2) * audioIn(n,:) + aCoeffs * yLpf(n,:); */
        for (i = 0; i < 22; i++)
        {
            b = (i << 5) + ramper;
            rtb_yLpf_a_tmp =
                Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0[b];
            rtb_yLpf_e = rtb_yLpf_a_tmp * gain + Model_Target_DW.filterStates[i];
            Model_Target_DW.filterStates[i] = rtb_yLpf_a_tmp * rtb_Max_b + tmp_1
                * rtb_yLpf_e;
            Model_Target_B.yLpf[b] = rtb_yLpf_e;
        }
    }

    /* End of MATLAB Function: '<S1382>/lpf' */

    /* MATLAB Function: '<S1382>/fade' */
    Model_Target_fade_l(Model_Target_B.ImpAsg_InsertedFor_Out1_at_inport_0,
                        &(Model_Target_PreAmp_p9_b0.FadeRamperFRChannelToRamperMap
                          [0]), Model_Target_B.yLpf, &Model_Target_B.sf_fade_l);

    /* Selector: '<S1346>/Selector' */
    memcpy(&Model_Target_B.PreAmp2NonHrDr[0], &Model_Target_B.sf_fade.audioOut[0],
           144U * sizeof(real32_T));

    /* Selector: '<S1346>/Selector1' */
    memcpy(&Model_Target_B.PreAmp2HeadrestDr[0],
           &Model_Target_B.sf_fade.audioOut[144], 96U * sizeof(real32_T));

    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1433>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S1433>/NTF Trigger' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1453>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S1453>/NTF Trigger' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1354>/RTC Request Response Trigger' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
