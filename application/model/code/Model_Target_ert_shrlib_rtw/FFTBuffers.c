/*
 * File: FFTBuffers.c
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

#include "FFTBuffers.h"
#include "rtwtypes.h"
#include "Model_Target_types.h"

/* Exported data definition */

/* Definition for custom storage class: FFTBuffer */
__attribute((aligned(1024))) real32_T LfRfftWindowRfftInput[512];/* '<S373>/Windowing' */
__attribute((aligned(1024))) real32_T MedusaFdpDeciRateRfftRfftInput[512];/* '<S657>/Windowing' */
__attribute((aligned(1024))) real32_T MedusaFdpFullRateRfftRfftInput[512];/* '<S753>/Windowing' */
__attribute((aligned(1024))) real32_T RfftRefRfftInput[1536];/* '<S272>/Windowing' */

/* Definition for custom storage class: FFTBuffer */
__attribute((aligned(8))) creal32_T LfRfftWindowRfftBufferRfftOutputTmp[256];/* '<S377>/RfftOutputTmp' */
__attribute((aligned(8))) creal32_T LfRfftWindowRfftBufferTwiddle1[96];/* '<S377>/Twiddle1' */
__attribute((aligned(8))) creal32_T LfRfftWindowRfftBufferTwiddle2[128];/* '<S377>/Twiddle2' */
__attribute((aligned(8))) creal32_T
    MedusaFdpDeciRateRfftRfftBufferRfftOutputTmp[256];/* '<S745>/RfftOutputTmp' */
__attribute((aligned(8))) creal32_T MedusaFdpDeciRateRfftRfftBufferTwiddle1[96];/* '<S745>/Twiddle1' */
__attribute((aligned(8))) creal32_T MedusaFdpDeciRateRfftRfftBufferTwiddle2[128];/* '<S745>/Twiddle2' */
__attribute((aligned(8))) creal32_T
    MedusaFdpDeciRateRifftRifftBufferRifftOutputTmp[256];/* '<S737>/RifftOutputTmp' */
__attribute((aligned(8))) creal32_T MedusaFdpDeciRateRifftRifftBufferTwiddle1[96];/* '<S737>/Twiddle1' */
__attribute((aligned(8))) creal32_T MedusaFdpDeciRateRifftRifftBufferTwiddle2
    [128];                             /* '<S737>/Twiddle2' */
__attribute((aligned(8))) creal32_T
    MedusaFdpFullRateRfftRfftBufferRfftOutputTmp[256];/* '<S829>/RfftOutputTmp' */
__attribute((aligned(8))) creal32_T MedusaFdpFullRateRfftRfftBufferTwiddle1[96];/* '<S829>/Twiddle1' */
__attribute((aligned(8))) creal32_T MedusaFdpFullRateRfftRfftBufferTwiddle2[128];/* '<S829>/Twiddle2' */
__attribute((aligned(8))) creal32_T
    MedusaFdpFullRateRifftRifftBufferRifftOutputTmp[256];/* '<S821>/RifftOutputTmp' */
__attribute((aligned(8))) creal32_T MedusaFdpFullRateRifftRifftBufferTwiddle1[96];/* '<S821>/Twiddle1' */
__attribute((aligned(8))) creal32_T MedusaFdpFullRateRifftRifftBufferTwiddle2
    [128];                             /* '<S821>/Twiddle2' */
__attribute((aligned(8))) creal32_T RfftRefRfftBufferRfftOutputTmp[256];/* '<S276>/RfftOutputTmp' */
__attribute((aligned(8))) creal32_T RfftRefRfftBufferTwiddle1[96];/* '<S276>/Twiddle1' */
__attribute((aligned(8))) creal32_T RfftRefRfftBufferTwiddle2[128];/* '<S276>/Twiddle2' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
