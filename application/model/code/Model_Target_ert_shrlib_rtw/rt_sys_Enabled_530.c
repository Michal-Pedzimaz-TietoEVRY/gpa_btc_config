/*
 * File: rt_sys_Enabled_530.c
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
#include "rt_sys_Enabled_530.h"
#include <math.h>
#include "Model_Target_private.h"

/*
 * Output and update for function-call system:
 *    '<S1389>/calculate_ramp_rate'
 *    '<S1884>/calculate_ramp_rate'
 *    '<S1964>/calculate_ramp_rate'
 *    '<S2044>/calculate_ramp_rate'
 *    '<S2124>/calculate_ramp_rate'
 *    '<S2219>/calculate_ramp_rate'
 */
void Model_Target_calculate_ramp_rate(uint32_T rtu_rampRateRTC, uint32_T
    rtu_rampTimeRTC, real32_T rtu_rampTimeTune,
    B_calculate_ramp_rate_Model_Target_T *localB)
{
    real32_T y;
    y = rtu_rampTimeTune;

    /*  % Inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/MuteControl/MuteControl/calculate_ramp_rate': '<S1393>:1' */
    /*  Ramp time and rate are provided to the block through RTC messages. However  */
    /*  in case neither of them are provided, the block will use the default ramp  */
    /*  time given in the tune variable. */
    /* '<S1393>:1:8' ramptime = single(rampTimeTune); */
    /* '<S1393>:1:9' rampRate = single(0); */
    localB->rampRate = 0.0F;

    /* '<S1393>:1:11' if (rampRateRTC) */
    if (rtu_rampRateRTC != 0U)
    {
        /* '<S1393>:1:12' rampRate = single(rampRateRTC); */
        /* '<S1393>:1:13' rampRate = max(rampRateBounds(1), rampRate); */
        /* '<S1393>:1:14' rampRate = min(rampRateBounds(2), rampRate); */
        localB->rampRate = fminf(50000.0F, fmaxf(5.0F, (real32_T)rtu_rampRateRTC));
    }

    /* '<S1393>:1:16' if (rampTimeRTC) */
    if (rtu_rampTimeRTC != 0U)
    {
        /* '<S1393>:1:17' ramptime = single(rampTimeRTC); */
        y = (real32_T)rtu_rampTimeRTC;
    }

    /* '<S1393>:1:19' ramptime = max(rampTimeBounds(1), ramptime); */
    /* '<S1393>:1:20' ramptime = min(rampTimeBounds(2), ramptime); */
    localB->ramptime = fminf(3000.0F, fmaxf(1.0F, y));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
