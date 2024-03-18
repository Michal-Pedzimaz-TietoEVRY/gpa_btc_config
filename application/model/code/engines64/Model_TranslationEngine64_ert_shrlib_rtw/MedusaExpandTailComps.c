/*
 * File: MedusaExpandTailComps.c
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

#include "Model_TranslationEngine64.h"
#include "rtwtypes.h"
#include "MedusaExpandTailComps.h"
#include <math.h>
#include <string.h>
#include <emmintrin.h>

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_d(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Declare variables for internal data of system '<S752>/Expand Tail Components' */
B_ExpandTailComponents_Model_TranslationEngine64_T
    Model_TranslationEngine64_ExpandTailComponents_B;

/* Function for MATLAB Function: '<S765>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_d(int32_T b,
    int32_T y_data[], int32_T y_size[2])
{
    int32_T k;
    int32_T n;
    if (b < 1)
    {
        n = 0;
    }
    else
    {
        n = b;
    }

    y_size[0] = 1;
    y_size[1] = n;
    if (n > 0)
    {
        int32_T yk;
        y_data[0] = 1;
        yk = 1;
        for (k = 2; k <= n; k++)
        {
            yk++;
            y_data[k - 1] = yk;
        }
    }
}

/* Output and update for function-call system: '<S766>/tfunc' */
void FuncTranslation_Model_141_345_50_36(void)
{
    real_T ChannelCoeffs[160];
    real_T OverallGainPerCh[4];
    int32_T f_data[160];
    int32_T tmp_data[160];
    int32_T b_data[40];
    int32_T ts_data[40];
    int32_T NumStages[4];
    int32_T b_vlen;
    int32_T d_k;
    int32_T i;
    int32_T k;
    int32_T yk;
    real32_T ChannelSOS_data[240];
    real32_T PoolCoeffs[160];
    real32_T x;
    real32_T y;
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S765>/Translation' */
    /* MATLAB Function: '<S765>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S765>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S765>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S768>:1' */
    /* '<S768>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Expand Tail Components/Tail Component EQ/InnerLink/PoolIirTunableWithReset/Translation': '<S767>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S767>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S767>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S767>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
    /*  Perform platform-based translation for poolIir block */
    /*  */
    /*  This functions offers the following outputs: */
    /*    PoolNumStages: Number of active stages for each channel */
    /*    PoolCoeffs   : SOS coefficients in a format accepted by CRL (can be */
    /*                   different for different platform CRLs) */
    /*                   Hexagon (qhdsp_iir_af_bose.S) and ARM format - [b0, b1, a1, b2, a2]        [NumStages x 5, 1] */
    /*                   Hexagon (flt_iir_cas_bq.S) DF-II format [-a1/a0 b1/b0 -a2/a0 b2/b0] plus gain per channel. */
    /*                                              where a0 is assumed to be 1.0. [TotNumStages x 4 + NumChannel, 1] */
    /*                   SHARC plus processors - [k, b1, b2, a1, a2]          [NumStages x 4, 1]                   */
    /*  */
    /*  This function expects the following inputs: */
    /*    rawSOS      : Unprocessed SOS coefficients in the order - [b0, b1, b2, a0, a1, a2] */
    /*                  Dimensions - [NumStages x NumChannels, 6] */
    /*    numStages   : Number of active stages for each channel */
    /*                  Dimensions - [1 x NumChannels] */
    /*    maxNumStages: Maximum permissible number of stages for each channel */
    /*                  Dimensions - [1 x NumChannels] */
    /*    variantUint8: Platform Variant - accepts only uint8 data type */
    /*                  Generally, the 'variant' is a character array or a */
    /*                  string. In that case, it could be changed to uint8 data */
    /*                  type as follows: uint8(char(Config.Variant)) */
    /*   */
    /*  If rawSOS and numStages are not being supplied from a TuneVar directly, */
    /*  please change it to TuneVar output type as shown below: */
    /*  rawSOS = struct('Value', rawSosCoeffs); */
    /* 'poolIirTranslation:29' variantStr = char(variantUint8); */
    /* 'poolIirTranslation:31' switch (variantStr) */
    /* 'poolIirTranslation:38' case{"Hexagon"} */
    /*  Hexagon specific order for biquad coefficients  */
    /* 'poolIirTranslation:40' [PoolNumStages, PoolCoeffs] = PoolIirHexagonTranslationFcn(rawSOS, numStages, maxNumStages); */
    /*  Hexagon flt_iir_cas_bq.S expects biquad coefficiients in following order: */
    /*    [-a1/a0 b1/b0 -a2/a0 b2/b0] where a0 is assumed to be 1. */
    /*    Overall gain b0/a0 is appended at the end of PoolCoeffs per channel.  */
    /*  */
    /*  In Matlab, coefficients are ordered as: */
    /*    [b0, b1, b2, a0, a1, a2]. */
    /* 'PoolIirHexagonTranslationFcn:10' NumCoeffPerBiquad = 4; */
    /* 'PoolIirHexagonTranslationFcn:11' RawSOS        = rawSOS.Value; */
    /* 'PoolIirHexagonTranslationFcn:12' NumStages     = int32(numStages.Value); */
    /* 'PoolIirHexagonTranslationFcn:13' NumChannels   = numel(NumStages); */
    /* 'PoolIirHexagonTranslationFcn:14' MaxNumStages  = maxNumStages; */
    /* 'PoolIirHexagonTranslationFcn:15' PoolNumStages = int32(zeros(NumChannels,1)); */
    x = roundf(Model_TranslationEngine64_ExpandTailComponents_B.numStages.Value
               [0]);
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            NumStages[0] = (int32_T)x;
        }
        else
        {
            NumStages[0] = MIN_int32_T;
        }
    }
    else
    {
        NumStages[0] = MAX_int32_T;
    }

    Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages[0] = 0;
    x = roundf(Model_TranslationEngine64_ExpandTailComponents_B.numStages.Value
               [1]);
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            NumStages[1] = (int32_T)x;
        }
        else
        {
            NumStages[1] = MIN_int32_T;
        }
    }
    else
    {
        NumStages[1] = MAX_int32_T;
    }

    Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages[1] = 0;
    y = roundf(Model_TranslationEngine64_ExpandTailComponents_B.numStages.Value
               [2]);
    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            NumStages[2] = (int32_T)y;
        }
        else
        {
            NumStages[2] = MIN_int32_T;
        }
    }
    else
    {
        NumStages[2] = MAX_int32_T;
    }

    Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages[2] = 0;
    y = roundf(Model_TranslationEngine64_ExpandTailComponents_B.numStages.Value
               [3]);
    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            NumStages[3] = (int32_T)y;
        }
        else
        {
            NumStages[3] = MIN_int32_T;
        }
    }
    else
    {
        NumStages[3] = MAX_int32_T;
    }

    Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages[3] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 160U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 160U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    i = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            b_vlen = (int32_T)x;
        }
        else
        {
            b_vlen = MIN_int32_T;
        }
    }
    else
    {
        b_vlen = MAX_int32_T;
    }

    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            d_k = (int32_T)y;
        }
        else
        {
            d_k = MIN_int32_T;
        }
    }
    else
    {
        d_k = MAX_int32_T;
    }

    if ((((real_T)NumStages[0] + (real_T)b_vlen) + (real_T)NumStages[2]) +
            (real_T)d_k > 40.0)
    {
        /* 'PoolIirHexagonTranslationFcn:23' TranslateError('Too many second order sections'); */
        /* TRANSLATEERROR (For use in Functions triggered by TranslationTrigger blocks.) */
        /* Print error message during tune data translation. */
        /*   Do not include a final newline as this behavior is already built in. */
        /*   Note that escape sequences such as '\n' will not work here. To emit */
        /*   special characters, pass them in as arguments to %c or %s format */
        /*   specifiers. */
        /*    Copyright 2018-2019 Bose Corporation */
        /* 'TranslateError:10' coder.extrinsic('gcb') */
        /* 'TranslateError:11' coder.extrinsic('warning') */
        /* 'TranslateError:12' coder.allowpcode('plain'); */
        /*  enable code generation from p-file */
        /* 'TranslateError:14' if (coder.target('MATLAB')) */
        /* 'TranslateError:18' if (coder.target('Sfun')) */
        /* 'TranslateError:21' else */
        /* 'TranslateError:22' count = numel(varargin); */
        /* 'TranslateError:23' fixedArgs = varargin; */
        /* 'TranslateError:24' for i=1:count */
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:26' fixedArgs{i} = [varargin{i} char(0)]; */
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (b_vlen = 0; b_vlen < 31; b_vlen++)
        {
            d_data[b_vlen] = e[b_vlen];
        }

        TranslateError(&d_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (k = 0; k < 4; k++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[k];
        OverallGainPerCh[k] = 1.0;

        /* 'PoolIirHexagonTranslationFcn:29' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* 'PoolIirHexagonTranslationFcn:30' assert(ChannelNumStages <= MaxNumStages); */
        /* 'PoolIirHexagonTranslationFcn:31' if (ChannelNumStages == 0) */
        if (NumStages_0 != 0)
        {
            real_T offset;
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_d(NumStages_0,
                tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = tmp_data[d_k];
                    if ((i < 0) && (q1 < MIN_int32_T - i))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((i > 0) && (q1 > MAX_int32_T - i))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += i;
                    }

                    ChannelSOS_data[d_k + ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_ExpandTailComponents_B.sosCoefficients.Value
                        [(40 * b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((i < 0) && (NumStages_0 < MIN_int32_T - i))
            {
                i = MIN_int32_T;
            }
            else if ((i > 0) && (NumStages_0 > MAX_int32_T - i))
            {
                i = MAX_int32_T;
            }
            else
            {
                i += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                x = 1.0F;
            }
            else
            {
                x = ChannelSOS_data[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    x *= ChannelSOS_data[yk - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                y = 1.0F;
            }
            else
            {
                y = ChannelSOS_data[tmp_size[1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    y *= ChannelSOS_data[(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = x / y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                b_vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                b_vlen = MIN_int32_T;
            }
            else
            {
                b_vlen = NumStages_0 << 2;
            }

            if (b_vlen < 1)
            {
                b_vlen = 0;
            }
            else
            {
                b_vlen = (int32_T)((uint32_T)(b_vlen - 1) >> 2) + 1;
            }

            ts_size_idx_1 = b_vlen;
            if (b_vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (d_k = 2; d_k <= b_vlen; d_k++)
                {
                    yk += 4;
                    ts_data[d_k - 1] = yk;
                }
            }

            yk = b_vlen - 1;
            for (b_vlen = 0; b_vlen <= yk; b_vlen++)
            {
                d_k = ts_data[b_vlen];
                if (d_k < -2147483647)
                {
                    ts_data[b_vlen] = MIN_int32_T;
                }
                else
                {
                    ts_data[b_vlen] = d_k - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            d_k = (ts_size_idx_1 / 4) << 2;
            q1 = d_k - 4;
            for (b_vlen = 0; b_vlen <= q1; b_vlen += 4)
            {
                __m128i tmp_0;
                tmp_0 = _mm_loadu_si128((const __m128i *)&ts_data[b_vlen]);
                _mm_storeu_si128((__m128i *)&b_data[b_vlen], _mm_add_epi32(tmp_0,
                                  _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                b_data[b_vlen] = ts_data[b_vlen] + 1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[b_data[b_vlen] - 1] = -ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + b_vlen];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                d_k = ts_data[b_vlen];
                if (d_k > 2147483645)
                {
                    b_data[b_vlen] = MAX_int32_T;
                }
                else
                {
                    b_data[b_vlen] = d_k + 2;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[b_data[b_vlen] - 1] = ChannelSOS_data[b_vlen +
                    ChannelSOS_size_idx_0] / ChannelSOS_data[b_vlen];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                d_k = ts_data[b_vlen];
                if (d_k > 2147483644)
                {
                    b_data[b_vlen] = MAX_int32_T;
                }
                else
                {
                    b_data[b_vlen] = d_k + 3;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[b_data[b_vlen] - 1] =
                    -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + b_vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + b_vlen];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            for (b_vlen = 0; b_vlen <= yk; b_vlen++)
            {
                d_k = ts_data[b_vlen];
                if (d_k > 2147483643)
                {
                    ts_data[b_vlen] = MAX_int32_T;
                }
                else
                {
                    ts_data[b_vlen] = d_k + 4;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[ts_data[b_vlen] - 1] = ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    ChannelSOS_data[b_vlen];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (k < 1)
            {
                offset = 0.0;
            }
            else
            {
                offset =
                    Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages
                    [0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages
                        [d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_ExpandTailComponents_B.PoolNumStages[k] =
                NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                b_vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                b_vlen = MIN_int32_T;
            }
            else
            {
                b_vlen = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_d(b_vlen,
                tmp_data, tmp_size);
            d_k = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                real_T tmp;
                tmp = offset + (real_T)tmp_data[b_vlen];
                if (tmp < 2.147483648E+9)
                {
                    if (tmp >= -2.147483648E+9)
                    {
                        f_data[b_vlen] = (int32_T)tmp;
                    }
                    else
                    {
                        f_data[b_vlen] = MIN_int32_T;
                    }
                }
                else
                {
                    f_data[b_vlen] = MAX_int32_T;
                }
            }

            for (b_vlen = 0; b_vlen < d_k; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs[0],
           &PoolCoeffs[0], 160U * sizeof(real32_T));
    Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs[160] = (real32_T)
        OverallGainPerCh[0];
    Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs[161] = (real32_T)
        OverallGainPerCh[1];
    Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs[162] = (real32_T)
        OverallGainPerCh[2];
    Model_TranslationEngine64_ExpandTailComponents_B.PoolCoeffs[163] = (real32_T)
        OverallGainPerCh[3];

    /* End of MATLAB Function: '<S765>/Translation' */
    /*  VariantStr = char(VariantUint8); */
    /*  switch (VariantStr) */
    /*      case {"Generic","SharcPlusCore"} */
    /*          % These variants order biquad coefficients in a compacted form */
    /*          [PoolNumStages, PoolCoeffs] = pooliirTranslationFcn(RawSOS, NumStages, MaxNumStages); */
    /*      case {"SharcPlusAccelGul","SharcPlusAccelGxp"} */
    /*          % These variants order biquad coefficients for the ADI accelerator */
    /*          [PoolNumStages, PoolCoeffs] = pooliirAccelTranslationFcn(RawSOS, NumStages, MaxNumStages); */
    /*      case{"Hexagon"} */
    /*          % Hexagon specific order for biquad coefficients  */
    /*          [PoolNumStages, PoolCoeffs] = PoolIirHexagonTranslationFcn(RawSOS, NumStages, MaxNumStages); */
    /*      case{"ArmNeonV7V8"} */
    /*          [PoolNumStages, PoolCoeffs] = PoolIirArmNeonV7V8TranslationFcn(RawSOS, NumStages, MaxNumStages); */
    /*      otherwise */
    /*          % This is a build-time error, not a translation error. The */
    /*          % selected build-time variant is not supported for translation */
    /*          error('Invalid implementation type: [%s]', VariantStr); */
    /*  end */
}

/* Output and update for function-call system: '<S771>/tfunc' */
void FuncTranslation_Model_141_346_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S769>/Subsystem' */
    /* SignalConversion generated from: '<S770>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S772>:1' */
    /* '<S772>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_ExpandTailComponents_B.Value[0],
           &Model_TranslationEngine64_ExpandTailComponents_B.WiggleFilter.Value
           [0], 1776U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S769>/Subsystem' */
}

/* Initialize for atomic system: '<S752>/Expand Tail Components' */
void Model_TranslationEngine64_ExpandTailComponents_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_ExpandTailComponents_B, 0,
                  sizeof(B_ExpandTailComponents_Model_TranslationEngine64_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
