/*
 * File: rt_sys_Enabled_543.c
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
#include "rt_sys_Enabled_543.h"
#include "Model_Target_private.h"

/*
 * Output and update for action system:
 *    '<S1417>/elseActionSubsystem'
 *    '<S1899>/elseActionSubsystem'
 *    '<S1979>/elseActionSubsystem'
 *    '<S2059>/elseActionSubsystem'
 *    '<S2139>/elseActionSubsystem'
 *    '<S2234>/elseActionSubsystem'
 */
void Model_Target_elseActionSubsystem(real32_T rtu_In1, real32_T rty_Out1[32])
{
    int32_T i;

    /* Product: '<S1419>/Multiply' */
    for (i = 0; i < 32; i++)
    {
        rty_Out1[i] = rtu_In1;
    }

    /* End of Product: '<S1419>/Multiply' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
