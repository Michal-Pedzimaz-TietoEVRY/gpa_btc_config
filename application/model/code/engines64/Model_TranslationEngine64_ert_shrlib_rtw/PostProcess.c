/*
 * File: PostProcess.c
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
#include "Model_TranslationEngine64_types.h"
#include "rtwtypes.h"
#include "PostProcess.h"
#include <math.h>
#include <string.h>

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_j(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Declare variables for internal data of system '<S5>/PostProcess' */
B_PostProcess_Model_TranslationEngine64_T
    Model_TranslationEngine64_PostProcess_B;

/*
 * Output and update for function-call system:
 *    '<S1850>/MATLAB Function3'
 *    '<S1850>/MATLAB Function5'
 */
void Model_TranslationEngine64_MATLABFunction3(const bus_double_1_24
    *rtu_attackDB, const bus_double_1_24 *rtu_threshold, real_T rtu_Fs,
    B_MATLABFunction3_Model_TranslationEngine64_T *localB)
{
    real_T attackDB_Value[24];
    real_T threshold_Value[24];
    int32_T c_size_idx_1;
    int32_T i;
    int32_T trueCount;
    int8_T c_data[24];
    int8_T d_data[24];
    int8_T e_data[24];
    boolean_T b[24];
    boolean_T b_0;
    boolean_T exitg1;

    /*  This function translates threshold and attackDB into a k1 value */
    /*  k1 is used later in the main Limiter function to apply gain redux */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function3': '<S1853>:1' */
    /*  If we find that any channel has a threshold value of zero, */
    /*  reset it to 100, for we essentially do not want to limit  */
    /*  that specific channel. */
    /* '<S1853>:1:9' minThreshold = 0.001; */
    /*  check against small number, set to zero if so.  */
    /* '<S1853>:1:10' threshold.Value(threshold.Value < minThreshold) = 0; */
    trueCount = 0;
    for (i = 0; i < 24; i++)
    {
        attackDB_Value[i] = rtu_attackDB->Value[i];
        threshold_Value[i] = rtu_threshold->Value[i];
        b_0 = (rtu_threshold->Value[i] < 0.001);
        if (b_0)
        {
            trueCount++;
        }

        b[i] = b_0;
    }

    c_size_idx_1 = trueCount;
    trueCount = 0;
    for (i = 0; i < 24; i++)
    {
        if (b[i])
        {
            c_data[trueCount] = (int8_T)(i + 1);
            trueCount++;
        }
    }

    for (i = 0; i < c_size_idx_1; i++)
    {
        threshold_Value[c_data[i] - 1] = 0.0;
    }

    /* '<S1853>:1:11' if ~(all(threshold.Value)) */
    b_0 = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 24))
    {
        if (threshold_Value[i] == 0.0)
        {
            b_0 = false;
            exitg1 = true;
        }
        else
        {
            i++;
        }
    }

    if (!b_0)
    {
        /* '<S1853>:1:12' threshold.Value(find(threshold.Value == 0)) = 100; */
        trueCount = 0;
        for (i = 0; i < 24; i++)
        {
            b_0 = (threshold_Value[i] == 0.0);
            if (b_0)
            {
                trueCount++;
            }

            b[i] = b_0;
        }

        c_size_idx_1 = trueCount;
        trueCount = 0;
        for (i = 0; i < 24; i++)
        {
            if (b[i])
            {
                d_data[trueCount] = (int8_T)(i + 1);
                trueCount++;
            }
        }

        for (i = 0; i < c_size_idx_1; i++)
        {
            threshold_Value[d_data[i] - 1] = 100.0;
        }
    }

    /*  If we find attack value is 0, set to 10000 */
    /* '<S1853>:1:16' if ~(all(attackDB.Value)) */
    b_0 = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 24))
    {
        if (rtu_attackDB->Value[i] == 0.0)
        {
            b_0 = false;
            exitg1 = true;
        }
        else
        {
            i++;
        }
    }

    if (!b_0)
    {
        /* '<S1853>:1:17' attackDB.Value(find(attackDB.Value == 0)) = 10000; */
        trueCount = 0;
        for (i = 0; i < 24; i++)
        {
            b_0 = (rtu_attackDB->Value[i] == 0.0);
            if (b_0)
            {
                trueCount++;
            }

            b[i] = b_0;
        }

        c_size_idx_1 = trueCount;
        trueCount = 0;
        for (i = 0; i < 24; i++)
        {
            if (b[i])
            {
                e_data[trueCount] = (int8_T)(i + 1);
                trueCount++;
            }
        }

        for (i = 0; i < c_size_idx_1; i++)
        {
            attackDB_Value[e_data[i] - 1] = 10000.0;
        }
    }

    /*  Set output values */
    /* '<S1853>:1:21' attack = single(1 - undb20(-abs(attackDB.Value) / Fs)); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    /* '<S1853>:1:22' k1 = attack ./ single(threshold.Value); */
    for (i = 0; i < 24; i++)
    {
        localB->attack[i] = (real32_T)(1.0 - exp(-fabs(attackDB_Value[i]) /
            rtu_Fs * 2.3025850929940459 / 20.0));
        localB->k1[i] = localB->attack[i] / (real32_T)threshold_Value[i];
    }
}

/* Output and update for function-call system: '<S1857>/tfunc' */
void FuncTranslation_Model_1495(void)
{
    /* MATLAB Function: '<S1850>/MATLAB Function3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1863>:1' */
    /* '<S1863>:1:3' f(); */
    Model_TranslationEngine64_MATLABFunction3
        (&Model_TranslationEngine64_PostProcess_B.Attack,
         &Model_TranslationEngine64_PostProcess_B.Threshold,
         Model_TranslationEngine64_PostProcess_ConstB.CapturedTuneConst,
         &Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction3);
}

/* Output and update for function-call system: '<S1858>/tfunc' */
void FuncTranslation_Model_1496(void)
{
    int32_T k;

    /* MATLAB Function: '<S1850>/MATLAB Function2' */
    /* MATLAB Function: '<S1850>/MATLAB Function2' incorporates:
     *  S-Function (TuneVarMEX): '<S1850>/decay tune'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1864>:1' */
    /* '<S1864>:1:3' f(); */
    /*  Convert decay value from dB to linear */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function2': '<S1852>:1' */
    /* '<S1852>:1:4' y = single(undb20(abs(u.Value) / Fs)); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 24; k++)
    {
        Model_TranslationEngine64_PostProcess_B.y_b[k] = (real32_T)exp(fabs
            (Model_TranslationEngine64_PostProcess_B.Decay.Value[k]) /
            Model_TranslationEngine64_PostProcess_ConstB.CapturedTuneConst *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1850>/MATLAB Function2' */
}

/* Output and update for function-call system: '<S1859>/tfunc' */
void FuncTranslation_Model_1497(void)
{
    int32_T k;

    /* MATLAB Function: '<S1850>/MATLAB Function4' */
    /* MATLAB Function: '<S1850>/MATLAB Function4' incorporates:
     *  S-Function (TuneVarMEX): '<S1850>/maxAttack tune'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1865>:1' */
    /* '<S1865>:1:3' f(); */
    /*  Translate from dB to linear */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function4': '<S1854>:1' */
    /* '<S1854>:1:4' y = single(undb20(-abs(u.Value))); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 24; k++)
    {
        Model_TranslationEngine64_PostProcess_B.y_n[k] = (real32_T)exp(-fabs
            (Model_TranslationEngine64_PostProcess_B.MaxAttack.Value[k]) *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1850>/MATLAB Function4' */
}

/* Output and update for function-call system: '<S1860>/tfunc' */
void FuncTranslation_Model_1498(void)
{
    /* MATLAB Function: '<S1850>/MATLAB Function5' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1866>:1' */
    /* '<S1866>:1:3' f(); */
    Model_TranslationEngine64_MATLABFunction3
        (&Model_TranslationEngine64_PostProcess_B.Attack_low,
         &Model_TranslationEngine64_PostProcess_B.Threshold_low,
         Model_TranslationEngine64_PostProcess_ConstB.CapturedTuneConst,
         &Model_TranslationEngine64_PostProcess_B.sf_MATLABFunction5_h);
}

/* Output and update for function-call system: '<S1861>/tfunc' */
void FuncTranslation_Model_1499(void)
{
    int32_T k;

    /* MATLAB Function: '<S1850>/MATLAB Function1' */
    /* MATLAB Function: '<S1850>/MATLAB Function1' incorporates:
     *  S-Function (TuneVarMEX): '<S1850>/decay tune1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1867>:1' */
    /* '<S1867>:1:3' f(); */
    /*  Convert from dB to linear */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function1': '<S1851>:1' */
    /* '<S1851>:1:4' y = single(undb20(abs(u.Value) / Fs)); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 24; k++)
    {
        Model_TranslationEngine64_PostProcess_B.y_j[k] = (real32_T)exp(fabs
            (Model_TranslationEngine64_PostProcess_B.Decay_low.Value[k]) /
            Model_TranslationEngine64_PostProcess_ConstB.CapturedTuneConst *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1850>/MATLAB Function1' */
}

/* Output and update for function-call system: '<S1862>/tfunc' */
void FuncTranslation_Model_1500(void)
{
    int32_T k;

    /* MATLAB Function: '<S1850>/MATLAB Function6' */
    /* MATLAB Function: '<S1850>/MATLAB Function6' incorporates:
     *  S-Function (TuneVarMEX): '<S1850>/maxAttack tune1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1868>:1' */
    /* '<S1868>:1:3' f(); */
    /*  Convert from dB to linear */
    /* MATLAB Function 'PostProcess/PostProcess/Limiter/Limiter/MATLAB Function6': '<S1856>:1' */
    /* '<S1856>:1:4' y = single(undb20(-abs(u.Value))); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 24; k++)
    {
        Model_TranslationEngine64_PostProcess_B.y[k] = (real32_T)exp(-fabs
            (Model_TranslationEngine64_PostProcess_B.MaxAttack_low.Value[k]) *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1850>/MATLAB Function6' */
}

/* Output and update for function-call system: '<S1874>/tfunc' */
void FuncTranslation_Model_72_276_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1872>/Subsystem' */
    /* SignalConversion generated from: '<S1873>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1875>:1' */
    /* '<S1875>:1:3' f(); */
    Model_TranslationEngine64_PostProcess_B.Value =
        Model_TranslationEngine64_PostProcess_B.RampTime.Value;

    /* End of Outputs for SubSystem: '<S1872>/Subsystem' */
}

/* Function for MATLAB Function: '<S1876>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_j(int32_T b,
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

/* Output and update for function-call system: '<S1877>/tfunc' */
void FuncTranslation_Model_76_36(void)
{
    real_T tmp_data[128];
    real_T ts_data[128];
    real_T offset;
    int32_T l_data[513];
    int32_T tmp_data_0[513];
    int32_T f_data[128];
    int32_T NumStages[24];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T i;
    int32_T k;
    int32_T loop_ub;
    real32_T ChannelSOS[768];
    real32_T b_y;
    char_T g_data[65];
    char_T e_data[31];
    boolean_T x_data[128];
    static const char_T h[31] = "Too many second order sections";
    static const char_T j[65] =
        "Poorly-formed SOS: zero b0 for multi-stage results in a zero EQ.";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1876>/Translation' */
    /* MATLAB Function: '<S1876>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1876>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1876>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1879>:1' */
    /* '<S1879>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'PostProcess/PostProcess/PostLimiterEQ/PoolIirTunableWithReset/Translation': '<S1878>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1878>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1878>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1878>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    /* 'poolIirTranslation:32' case {"Generic","SharcPlusCore"} */
    /*  These variants order biquad coefficients in a compacted form */
    /* 'poolIirTranslation:34' [PoolNumStages, PoolCoeffs] = pooliirTranslationFcn(rawSOS, numStages, maxNumStages); */
    /* 'pooliirTranslationFcn:3' RawSOS = rawSOS.Value; */
    /* 'pooliirTranslationFcn:4' NumStages = int32(numStages.Value); */
    /* 'pooliirTranslationFcn:5' NumChannels = length(NumStages); */
    /* 'pooliirTranslationFcn:7' MaxNumStages = maxNumStages; */
    /* 'pooliirTranslationFcn:8' PoolNumStages = int32(zeros(NumChannels,1)); */
    for (SOSIndex = 0; SOSIndex < 24; SOSIndex++)
    {
        b_y = roundf
            (Model_TranslationEngine64_PostProcess_B.numStages.Value[SOSIndex]);
        if (b_y < 2.14748365E+9F)
        {
            if (b_y >= -2.14748365E+9F)
            {
                NumStages[SOSIndex] = (int32_T)b_y;
            }
            else
            {
                NumStages[SOSIndex] = MIN_int32_T;
            }
        }
        else
        {
            NumStages[SOSIndex] = MAX_int32_T;
        }

        Model_TranslationEngine64_PostProcess_B.PoolNumStages[SOSIndex] = 0;
    }

    /* 'pooliirTranslationFcn:9' PoolCoeffs = single(zeros(MaxNumStages * 4 + NumChannels,1)); */
    memset(&Model_TranslationEngine64_PostProcess_B.PoolCoeffs[0], 0, 536U *
           sizeof(real32_T));

    /* 'pooliirTranslationFcn:10' ChannelSOS = single(zeros(MaxNumStages, 6)); */
    memset(&ChannelSOS[0], 0, 768U * sizeof(real32_T));

    /* 'pooliirTranslationFcn:11' SOSIndex = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'pooliirTranslationFcn:15' if sum(NumStages) > MaxNumStages */
    offset = NumStages[0];
    for (k = 0; k < 23; k++)
    {
        offset += (real_T)NumStages[k + 1];
    }

    if (offset > 128.0)
    {
        /* 'pooliirTranslationFcn:16' TranslateError('Too many second order sections'); */
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
            e_data[b_vlen] = h[b_vlen];
        }

        TranslateError(&e_data[0]);
    }

    /* 'pooliirTranslationFcn:19' for i = 1:NumChannels */
    for (k = 0; k < 24; k++)
    {
        /* 'pooliirTranslationFcn:21' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* 'pooliirTranslationFcn:22' assert(ChannelNumStages <= MaxNumStages); */
        /* 'pooliirTranslationFcn:24' if (ChannelNumStages == 0) */
        if (NumStages[k] != 0)
        {
            int32_T ChannelCoeffsLength;
            int32_T ChannelSOS_tmp;
            boolean_T c_y;

            /* 'pooliirTranslationFcn:28' ChannelSOS(1:ChannelNumStages,:) = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_j(NumStages[k],
                tmp_data_0, tmp_size);
            loop_ub = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (i = 0; i < loop_ub; i++)
                {
                    ChannelCoeffsLength = tmp_data_0[i];
                    if ((SOSIndex < 0) && (ChannelCoeffsLength < MIN_int32_T
                                           - SOSIndex))
                    {
                        ChannelCoeffsLength = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (ChannelCoeffsLength >
                                                MAX_int32_T - SOSIndex))
                    {
                        ChannelCoeffsLength = MAX_int32_T;
                    }
                    else
                    {
                        ChannelCoeffsLength += SOSIndex;
                    }

                    ChannelSOS_tmp = b_vlen << 7;
                    ChannelSOS[i + ChannelSOS_tmp] =
                        Model_TranslationEngine64_PostProcess_B.sosCoefficients.Value
                        [(ChannelSOS_tmp + ChannelCoeffsLength) - 1];
                }
            }

            /* 'pooliirTranslationFcn:29' SOSIndex = SOSIndex + ChannelNumStages; */
            ChannelCoeffsLength = NumStages[k];
            if ((SOSIndex < 0) && (ChannelCoeffsLength < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (ChannelCoeffsLength > MAX_int32_T
                                        - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += ChannelCoeffsLength;
            }

            /* 'pooliirTranslationFcn:31' if size(ChannelSOS,2) ~= 6 */
            /*  decompose SOS */
            /* 'pooliirTranslationFcn:36' ChannelCoeffs = sos2pooliir(ChannelSOS(1:ChannelNumStages, :)); */
            if (NumStages[k] < 1)
            {
                b_vlen = -1;
                i = -1;
            }
            else
            {
                b_vlen = NumStages[k] - 1;
                i = b_vlen;
            }

            ChannelCoeffsLength = i + 1;

            /* SOS2POOLIIR Converts SOS stages for a given channel to pooliir coeffs */
            /*    Copyright 2018-2019 Bose Corporation */
            /*  Preparation */
            /* 'sos2pooliir:6' num_stages = size(sos, 1); */
            /* 'sos2pooliir:7' ts = 1:4:4*num_stages; */
            offset = (real_T)(b_vlen + 1) * 4.0;
            if (offset < 1.0)
            {
                ChannelSOS_tmp = 0;
            }
            else
            {
                loop_ub = (int32_T)((offset - 1.0) / 4.0);
                ChannelSOS_tmp = loop_ub + 1;
                for (i = 0; i <= loop_ub; i++)
                {
                    ts_data[i] = 4.0 * (real_T)i + 1.0;
                }
            }

            /* 'sos2pooliir:8' coeffs = zeros(num_stages * 4 + 1,1); */
            loop_ub = (b_vlen + 1) << 2;
            if (loop_ub >= 0)
            {
                memset
                    (&Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data[
                     0], 0, (uint32_T)(loop_ub + 1) * sizeof(real_T));
            }

            /*  First element is the overall gain of the SOS */
            /* 'sos2pooliir:11' coeffs(1,1) = prod(sos(:,1)); */
            if (b_vlen + 1 == 0)
            {
                b_y = 1.0F;
            }
            else
            {
                b_y = ChannelSOS[0];
                for (loop_ub = 2; loop_ub <= ChannelCoeffsLength; loop_ub++)
                {
                    b_y *= ChannelSOS[loop_ub - 1];
                }
            }

            Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data[0] = b_y;

            /*  Error out for poorly-formed sos coeffs */
            /* 'sos2pooliir:14' if ((coeffs(1,1) == 0) && (num_stages > 1)) */
            if ((b_y == 0.0F) && (b_vlen + 1 > 1))
            {
                /* 'sos2pooliir:15' TranslateError('Poorly-formed SOS: zero b0 for multi-stage results in a zero EQ.'); */
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
                memcpy(&g_data[0], &j[0], 65U * sizeof(char_T));
                TranslateError(&g_data[0]);
            }

            /*  the remaining coeffs are compacted forms of the biquads */
            /*  a2 is next, stagger for each stage */
            /* 'sos2pooliir:20' coeffs(1+ts, 1) = sos(:,6); */
            if (ChannelSOS_tmp - 1 >= 0)
            {
                memcpy(&tmp_data[0], &ts_data[0], (uint32_T)ChannelSOS_tmp *
                       sizeof(real_T));
            }

            for (i = 0; i < ChannelCoeffsLength; i++)
            {
                Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data
                    [(int32_T)(tmp_data[i] + 1.0) - 1] = ChannelSOS[i + 640];
            }

            /*  a1 is next, stagger for each stage */
            /* 'sos2pooliir:23' coeffs(2+ts,1) = sos(:,5); */
            for (i = 0; i < ChannelCoeffsLength; i++)
            {
                Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data
                    [(int32_T)(tmp_data[i] + 2.0) - 1] = ChannelSOS[i + 512];
            }

            /*  b2 then b1 are next, normalized by the stage gain */
            /* 'sos2pooliir:26' if( sos(:,1) == 0 ) */
            loop_ub = b_vlen + 1;
            for (b_vlen = 0; b_vlen < ChannelCoeffsLength; b_vlen++)
            {
                x_data[b_vlen] = (ChannelSOS[b_vlen] == 0.0F);
            }

            c_y = (loop_ub != 0);
            if (c_y)
            {
                boolean_T exitg1;
                b_vlen = 0;
                exitg1 = false;
                while ((!exitg1) && (b_vlen <= loop_ub - 1))
                {
                    if (!x_data[b_vlen])
                    {
                        c_y = false;
                        exitg1 = true;
                    }
                    else
                    {
                        b_vlen++;
                    }
                }
            }

            if (c_y)
            {
                /* 'sos2pooliir:27' coeffs(3+ts,1) = 0; */
                for (b_vlen = 0; b_vlen < ChannelSOS_tmp; b_vlen++)
                {
                    f_data[b_vlen] = (int32_T)(tmp_data[b_vlen] + 3.0);
                }

                for (b_vlen = 0; b_vlen < ChannelSOS_tmp; b_vlen++)
                {
                    Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data[f_data
                        [b_vlen] - 1] = 0.0;
                }

                /* 'sos2pooliir:28' coeffs(4+ts,1) = 0; */
                for (b_vlen = 0; b_vlen < ChannelSOS_tmp; b_vlen++)
                {
                    f_data[b_vlen] = (int32_T)(tmp_data[b_vlen] + 4.0);
                }

                for (b_vlen = 0; b_vlen < ChannelSOS_tmp; b_vlen++)
                {
                    Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data[f_data
                        [b_vlen] - 1] = 0.0;
                }
            }
            else
            {
                /* 'sos2pooliir:29' else */
                /* 'sos2pooliir:30' coeffs(3+ts,1) = sos(:,3)./sos(:,1); */
                for (b_vlen = 0; b_vlen < ChannelCoeffsLength; b_vlen++)
                {
                    Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data
                        [(int32_T)(ts_data[b_vlen] + 3.0) - 1] =
                        ChannelSOS[b_vlen + 256] / ChannelSOS[b_vlen];
                }

                /*  b2/b0 */
                /* 'sos2pooliir:31' coeffs(4+ts,1) = sos(:,2)./sos(:,1); */
                for (b_vlen = 0; b_vlen < ChannelCoeffsLength; b_vlen++)
                {
                    Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data
                        [(int32_T)(ts_data[b_vlen] + 4.0) - 1] =
                        ChannelSOS[b_vlen + 128] / ChannelSOS[b_vlen];
                }

                /*  b1/b0 */
            }

            /*  length of Cuurent Channel Coeffs */
            /* 'pooliirTranslationFcn:40' ChannelCoeffsLength = 1+4*ChannelNumStages; */
            b_vlen = NumStages[k];
            if (b_vlen > 536870911)
            {
                b_vlen = MAX_int32_T;
            }
            else if (b_vlen <= -536870912)
            {
                b_vlen = MIN_int32_T;
            }
            else
            {
                b_vlen <<= 2;
            }

            /*  Offset into coefficient array for the current channel */
            /* 'pooliirTranslationFcn:43' offset = (i-1)+4*sum(PoolNumStages(1:i-1)); */
            if (k < 1)
            {
                offset = 0.0;
            }
            else
            {
                offset = Model_TranslationEngine64_PostProcess_B.PoolNumStages[0];
                for (loop_ub = 2; loop_ub <= k; loop_ub++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_PostProcess_B.PoolNumStages[loop_ub
                        - 1];
                }
            }

            offset = (((real_T)k + 1.0) - 1.0) + 4.0 * offset;

            /* 'pooliirTranslationFcn:45' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_PostProcess_B.PoolNumStages[k] =
                NumStages[k];

            /*  Store the coefficients */
            /* 'pooliirTranslationFcn:48' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (b_vlen > 2147483646)
            {
                b_vlen = MAX_int32_T;
            }
            else
            {
                b_vlen++;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_j(b_vlen,
                tmp_data_0, tmp_size);
            ChannelCoeffsLength = tmp_size[1];
            loop_ub = tmp_size[1];
            for (b_vlen = 0; b_vlen < loop_ub; b_vlen++)
            {
                real_T tmp;
                tmp = offset + (real_T)tmp_data_0[b_vlen];
                if (tmp < 2.147483648E+9)
                {
                    if (tmp >= -2.147483648E+9)
                    {
                        l_data[b_vlen] = (int32_T)tmp;
                    }
                    else
                    {
                        l_data[b_vlen] = MIN_int32_T;
                    }
                }
                else
                {
                    l_data[b_vlen] = MAX_int32_T;
                }
            }

            for (b_vlen = 0; b_vlen < ChannelCoeffsLength; b_vlen++)
            {
                Model_TranslationEngine64_PostProcess_B.PoolCoeffs[l_data[b_vlen]
                    - 1] = (real32_T)
                    Model_TranslationEngine64_PostProcess_B.ChannelCoeffs_data[b_vlen];
            }
        }
    }

    /* End of MATLAB Function: '<S1876>/Translation' */
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

/* Output and update for function-call system: '<S1881>/tfunc' */
void FuncTranslation_Model_1527(void)
{
    real_T xmax_top;

    /* MATLAB Function: '<S1880>/translation' */
    /* MATLAB Function: '<S1880>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1880>/xmin TuneVar'
     *  S-Function (TuneVarMEX): '<S1880>/ymax TuneVar'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1885>:1' */
    /* '<S1885>:1:3' f(); */
    /*  Translates Ymax and Xmin to Xmax and Xmin */
    /* MATLAB Function 'PostProcess/PostProcess/Soft Clipper/SoftClipper/translation': '<S1883>:1' */
    /* '<S1883>:1:5' xmin_top = xmin_tune.Value; */
    /* '<S1883>:1:6' xmax_top = 2 * ymax_tune.Value - xmin_top; */
    xmax_top = 2.0 * Model_TranslationEngine64_PostProcess_B.YMax.Value -
        Model_TranslationEngine64_PostProcess_B.XMin.Value;

    /*  p2 remains 0 unless below condition is met */
    /*  p2 is later used in the gain redux function  */
    /* '<S1883>:1:10' p2 = 0; */
    Model_TranslationEngine64_PostProcess_B.p2_e = 0.0;

    /* '<S1883>:1:11' if (xmax_top ~= xmin_top) */
    if (xmax_top != Model_TranslationEngine64_PostProcess_B.XMin.Value)
    {
        /* '<S1883>:1:12' p2 = 1 / (2 * (xmax_top - xmin_top)); */
        Model_TranslationEngine64_PostProcess_B.p2_e = 1.0 / ((xmax_top -
            Model_TranslationEngine64_PostProcess_B.XMin.Value) * 2.0);
    }

    Model_TranslationEngine64_PostProcess_B.xmin_top_c =
        Model_TranslationEngine64_PostProcess_B.XMin.Value;
    Model_TranslationEngine64_PostProcess_B.xmax_top_m = xmax_top;

    /* End of MATLAB Function: '<S1880>/translation' */
}

/* Output and update for function-call system: '<S1882>/tfunc' */
void FuncTranslation_Model_1528(void)
{
    real_T xmax_top;

    /* MATLAB Function: '<S1880>/translation1' */
    /* MATLAB Function: '<S1880>/translation1' incorporates:
     *  S-Function (TuneVarMEX): '<S1880>/xmin TuneVar1'
     *  S-Function (TuneVarMEX): '<S1880>/ymax TuneVar1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1886>:1' */
    /* '<S1886>:1:3' f(); */
    /*  Translates Ymax and Xmin to Xmax and Xmin */
    /* MATLAB Function 'PostProcess/PostProcess/Soft Clipper/SoftClipper/translation1': '<S1884>:1' */
    /* '<S1884>:1:5' xmin_top = xmin_tune.Value; */
    /* '<S1884>:1:6' xmax_top = 2 * ymax_tune.Value - xmin_top; */
    xmax_top = 2.0 * Model_TranslationEngine64_PostProcess_B.YMaxLow.Value -
        Model_TranslationEngine64_PostProcess_B.XMinLow.Value;

    /*  p2 remains 0 unless below condition is met */
    /*  p2 is later used in the gain redux function  */
    /* '<S1884>:1:10' p2 = 0; */
    Model_TranslationEngine64_PostProcess_B.p2 = 0.0;

    /* '<S1884>:1:11' if (xmax_top ~= xmin_top) */
    if (xmax_top != Model_TranslationEngine64_PostProcess_B.XMinLow.Value)
    {
        /* '<S1884>:1:12' p2 = 1 / (2 * (xmax_top - xmin_top)); */
        Model_TranslationEngine64_PostProcess_B.p2 = 1.0 / ((xmax_top -
            Model_TranslationEngine64_PostProcess_B.XMinLow.Value) * 2.0);
    }

    Model_TranslationEngine64_PostProcess_B.xmin_top =
        Model_TranslationEngine64_PostProcess_B.XMinLow.Value;
    Model_TranslationEngine64_PostProcess_B.xmax_top = xmax_top;

    /* End of MATLAB Function: '<S1880>/translation1' */
}

/* Initialize for atomic system: '<S5>/PostProcess' */
void Model_TranslationEngine64_PostProcess_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_PostProcess_B, 0,
                  sizeof(B_PostProcess_Model_TranslationEngine64_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
