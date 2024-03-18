/*
 * File: Ifir.c
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

#include "Ifir.h"
#include <string.h>
#include "Model_Target.h"
#include "rtwtypes.h"
#include "Model_Target_private.h"
#include "PoolDelayStorage.h"

/* Output and update for atomic system: '<S593>/Ifir' */
void Model_Target_Ifir(void)
{
    int32_T channel;
    int32_T i;
    int32_T sample;
    int32_T stateIndex;
    real32_T state[116];

    /* MATLAB Function: '<S634>/ifir' incorporates:
     *  Sum: '<S593>/Sum'
     */
    /*  An interpolated FIR filter is an FIR filter with a sparse set of */
    /*  coefficients.  That is, the coefficients contain I-1 zeros between */
    /*  each point, so the effective length of  filter is len(input_coeffs) * I   */
    /*  The function support multiple channels, with each */
    /*  channel sharing the same set of filter coefficients. */
    /*   */
    /*  p : coefficient set (non-zero coefficients) */
    /*  I : interpolation factor, I-1 zeros are inserted between each coefficient */
    /*   */
    /*  NOTES:  */
    /*  The legacy IFIR block supported coefficient sets.  Currently */
    /*  this only supports one coefficient set.  */
    /*  The coefficients are stored flipped in time. The unflipped coeffs are */
    /*  passed to block mask, and the flipping is done in mask initialization. */
    /* MATLAB Function 'Ifir/ifir': '<S636>:1' */
    /*  Initialize variables */
    /* '<S636>:1:19' [frameSize, numChannels] = size(audioIn); */
    /* '<S636>:1:20' [filterLength, ~] = size(FlippedCoefficients); */
    /* '<S636>:1:22' frameSize   = uint32(frameSize); */
    /* '<S636>:1:23' numChannels = uint32(numChannels); */
    /* '<S636>:1:24' filterLength = int32(filterLength); */
    /* '<S636>:1:25' activeCoeffSet = coder.const(uint32(zeros(1,numChannels))); */
    /*  State is a circular buffer that holds previous stateLen samples,  */
    /*  where state_index points to the last/oldest sample in the buffer, which  */
    /*  during processing will be overwritten by the current input sample. */
    /* '<S636>:1:33' if isempty(state_index) */
    /* '<S636>:1:37' audioOut = IFIR(audioIn, frameSize, numChannels, states, filterLength, ... */
    /* '<S636>:1:38'                     state_index, FlippedCoefficients, activeCoeffSet, InterpolationFactor); */
    /*  If code gen'ing, generate warning if this is not replaced with IFIR.asm */
    /* '<S636>:1:45' coder.replace('-warnifnoreplacement'); */
    /*  We have to use a different state buffer and state index than the one  */
    /*  passed in.  Matlab value objects are passed by value, not by reference,  */
    /*  so the saving of states here does not work.  The state buffer and index  */
    /*  are still necessary to pass allocate in the calling function and pass  */
    /*  here in order to trigger CRL. This double buffering is annoying, however  */
    /*  only happens during simulation, not code generation. (taken from pooliir) */
    /* '<S636>:1:55' if isempty(state_index) */
    /* '<S636>:1:59' y = coder.nullcopy(audioIn); */
    /* '<S636>:1:60' stateLen = filterLength * InterpolationFactor; */
    /* '<S636>:1:62' for channel = 1:numChannels */
    for (channel = 0; channel < 2; channel++)
    {
        /* '<S636>:1:63' state = states(:,channel); */
        memcpy(&state[0], &Model_Target_DW.states_l[channel * 116], 116U *
               sizeof(real32_T));

        /* '<S636>:1:64' stateIndex = state_index; */
        stateIndex = Model_Target_DW.state_index_a;

        /* '<S636>:1:65' coeffs = FlippedCoefficients(:,activeCoeffSet(channel)+1); */
        /* '<S636>:1:67' for sample = 1:frameSize */
        for (sample = 0; sample < 32; sample++)
        {
            int32_T qY_tmp_tmp;
            int32_T state_tmp;
            real32_T accum;

            /*  overwrite oldest sample with the current input sample */
            /* '<S636>:1:69' state(stateIndex+1) = audioIn(sample, channel); */
            if (stateIndex > 2147483646)
            {
                i = MAX_int32_T;
            }
            else
            {
                i = stateIndex + 1;
            }

            state_tmp = (channel << 5) + sample;
            state[i - 1] = MedusaBassMgrHpf9323PoolIirAudioOut[state_tmp];

            /*  go to the oldest sample (previously the 2nd oldest) */
            /* '<S636>:1:71' stateIndex = stateIndex + InterpolationFactor; */
            if (stateIndex > 2147483645)
            {
                stateIndex = MAX_int32_T;
            }
            else
            {
                stateIndex += 2;
            }

            /* '<S636>:1:72' if (stateIndex >= stateLen) */
            if (stateIndex >= 116)
            {
                /* '<S636>:1:73' stateIndex = stateIndex - stateLen; */
                stateIndex -= 116;
            }

            /* '<S636>:1:76' accum = single(0); */
            accum = 0.0F;

            /* '<S636>:1:77' for i = 1:filterLength */
            for (i = 0; i < 58; i++)
            {
                /* '<S636>:1:78' accum = accum + (state(stateIndex+1) * coeffs(i)); */
                accum += state[stateIndex] *
                    Model_Target_ConstP.ifir_FlippedCoefficients[i];

                /* '<S636>:1:79' stateIndex = stateIndex + InterpolationFactor; */
                qY_tmp_tmp = stateIndex + 2;
                stateIndex += 2;

                /*  skip zero coefficients */
                /* '<S636>:1:80' if (stateIndex >= stateLen) */
                if (qY_tmp_tmp >= 116)
                {
                    /* '<S636>:1:81' stateIndex = stateIndex - stateLen; */
                    stateIndex = qY_tmp_tmp - 116;
                }
            }

            /* '<S636>:1:84' y(sample, channel) = accum; */
            Model_Target_B.Sum_a[state_tmp] = accum;

            /*  update stateIndex for next sample */
            /*  because we subtract here state_index type is int32 not uint32 */
            /* '<S636>:1:88' stateIndex = stateIndex - (InterpolationFactor-1); */
            qY_tmp_tmp = stateIndex - 1;
            stateIndex--;

            /* '<S636>:1:89' if (stateIndex < 0) */
            if (qY_tmp_tmp < 0)
            {
                /* '<S636>:1:90' stateIndex = stateIndex + stateLen; */
                stateIndex = qY_tmp_tmp + 116;
            }
        }

        /* '<S636>:1:94' states(:, channel) = state; */
        memcpy(&Model_Target_DW.states_l[channel * 116], &state[0], 116U *
               sizeof(real32_T));
    }

    /* '<S636>:1:97' state_index = stateIndex; */
    Model_Target_DW.state_index_a = stateIndex;

    /* End of MATLAB Function: '<S634>/ifir' */
}

/* Output and update for atomic system: '<S1763>/Ifir' */
void Model_Target_Ifir_k(void)
{
    int32_T channel;
    int32_T i;
    int32_T sample;
    int32_T stateIndex;
    real32_T state[114];

    /* MATLAB Function: '<S1766>/ifir' */
    /*  An interpolated FIR filter is an FIR filter with a sparse set of */
    /*  coefficients.  That is, the coefficients contain I-1 zeros between */
    /*  each point, so the effective length of  filter is len(input_coeffs) * I   */
    /*  The function support multiple channels, with each */
    /*  channel sharing the same set of filter coefficients. */
    /*   */
    /*  p : coefficient set (non-zero coefficients) */
    /*  I : interpolation factor, I-1 zeros are inserted between each coefficient */
    /*   */
    /*  NOTES:  */
    /*  The legacy IFIR block supported coefficient sets.  Currently */
    /*  this only supports one coefficient set.  */
    /*  The coefficients are stored flipped in time. The unflipped coeffs are */
    /*  passed to block mask, and the flipping is done in mask initialization. */
    /* MATLAB Function 'Ifir/ifir': '<S1776>:1' */
    /*  Initialize variables */
    /* '<S1776>:1:19' [frameSize, numChannels] = size(audioIn); */
    /* '<S1776>:1:20' [filterLength, ~] = size(FlippedCoefficients); */
    /* '<S1776>:1:22' frameSize   = uint32(frameSize); */
    /* '<S1776>:1:23' numChannels = uint32(numChannels); */
    /* '<S1776>:1:24' filterLength = int32(filterLength); */
    /* '<S1776>:1:25' activeCoeffSet = coder.const(uint32(zeros(1,numChannels))); */
    /*  State is a circular buffer that holds previous stateLen samples,  */
    /*  where state_index points to the last/oldest sample in the buffer, which  */
    /*  during processing will be overwritten by the current input sample. */
    /* '<S1776>:1:33' if isempty(state_index) */
    /* '<S1776>:1:37' audioOut = IFIR(audioIn, frameSize, numChannels, states, filterLength, ... */
    /* '<S1776>:1:38'                     state_index, FlippedCoefficients, activeCoeffSet, InterpolationFactor); */
    /*  If code gen'ing, generate warning if this is not replaced with IFIR.asm */
    /* '<S1776>:1:45' coder.replace('-warnifnoreplacement'); */
    /*  We have to use a different state buffer and state index than the one  */
    /*  passed in.  Matlab value objects are passed by value, not by reference,  */
    /*  so the saving of states here does not work.  The state buffer and index  */
    /*  are still necessary to pass allocate in the calling function and pass  */
    /*  here in order to trigger CRL. This double buffering is annoying, however  */
    /*  only happens during simulation, not code generation. (taken from pooliir) */
    /* '<S1776>:1:55' if isempty(state_index) */
    /* '<S1776>:1:59' y = coder.nullcopy(audioIn); */
    /* '<S1776>:1:60' stateLen = filterLength * InterpolationFactor; */
    /* '<S1776>:1:62' for channel = 1:numChannels */
    for (channel = 0; channel < 2; channel++)
    {
        /* '<S1776>:1:63' state = states(:,channel); */
        memcpy(&state[0], &Model_Target_DW.states_g[channel * 114], 114U *
               sizeof(real32_T));

        /* '<S1776>:1:64' stateIndex = state_index; */
        stateIndex = Model_Target_DW.state_index;

        /* '<S1776>:1:65' coeffs = FlippedCoefficients(:,activeCoeffSet(channel)+1); */
        /* '<S1776>:1:67' for sample = 1:frameSize */
        for (sample = 0; sample < 32; sample++)
        {
            int32_T qY_tmp_tmp;
            int32_T state_tmp;
            real32_T accum;

            /*  overwrite oldest sample with the current input sample */
            /* '<S1776>:1:69' state(stateIndex+1) = audioIn(sample, channel); */
            if (stateIndex > 2147483646)
            {
                i = MAX_int32_T;
            }
            else
            {
                i = stateIndex + 1;
            }

            state_tmp = (channel << 5) + sample;
            state[i - 1] = Model_Target_B.LoRoLimpRimp[state_tmp];

            /*  go to the oldest sample (previously the 2nd oldest) */
            /* '<S1776>:1:71' stateIndex = stateIndex + InterpolationFactor; */
            if (stateIndex > 2147483645)
            {
                stateIndex = MAX_int32_T;
            }
            else
            {
                stateIndex += 2;
            }

            /* '<S1776>:1:72' if (stateIndex >= stateLen) */
            if (stateIndex >= 114)
            {
                /* '<S1776>:1:73' stateIndex = stateIndex - stateLen; */
                stateIndex -= 114;
            }

            /* '<S1776>:1:76' accum = single(0); */
            accum = 0.0F;

            /* '<S1776>:1:77' for i = 1:filterLength */
            for (i = 0; i < 57; i++)
            {
                /* '<S1776>:1:78' accum = accum + (state(stateIndex+1) * coeffs(i)); */
                accum += state[stateIndex] *
                    Model_Target_ConstP.ifir_FlippedCoefficients_j[i];

                /* '<S1776>:1:79' stateIndex = stateIndex + InterpolationFactor; */
                qY_tmp_tmp = stateIndex + 2;
                stateIndex += 2;

                /*  skip zero coefficients */
                /* '<S1776>:1:80' if (stateIndex >= stateLen) */
                if (qY_tmp_tmp >= 114)
                {
                    /* '<S1776>:1:81' stateIndex = stateIndex - stateLen; */
                    stateIndex = qY_tmp_tmp - 114;
                }
            }

            /* '<S1776>:1:84' y(sample, channel) = accum; */
            Model_Target_B.FRIn[state_tmp] = accum;

            /*  update stateIndex for next sample */
            /*  because we subtract here state_index type is int32 not uint32 */
            /* '<S1776>:1:88' stateIndex = stateIndex - (InterpolationFactor-1); */
            qY_tmp_tmp = stateIndex - 1;
            stateIndex--;

            /* '<S1776>:1:89' if (stateIndex < 0) */
            if (qY_tmp_tmp < 0)
            {
                /* '<S1776>:1:90' stateIndex = stateIndex + stateLen; */
                stateIndex = qY_tmp_tmp + 114;
            }
        }

        /* '<S1776>:1:94' states(:, channel) = state; */
        memcpy(&Model_Target_DW.states_g[channel * 114], &state[0], 114U *
               sizeof(real32_T));
    }

    /* '<S1776>:1:97' state_index = stateIndex; */
    Model_Target_DW.state_index = stateIndex;

    /* End of MATLAB Function: '<S1766>/ifir' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
