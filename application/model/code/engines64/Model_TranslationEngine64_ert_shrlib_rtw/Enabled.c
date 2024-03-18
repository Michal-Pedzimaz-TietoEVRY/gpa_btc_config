/*
 * File: Enabled.c
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
#include "Enabled.h"
#include <math.h>
#include <string.h>
#include "Model_TranslationEngine64_private.h"
#include "rt_nonfinite.h"

/* Forward declaration for local functions */
static void Model_TranslationEngine64_unique_vector(const real_T a_data[], const
    int32_T *a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_unique_vector_i(const real_T a_data[],
    const int32_T *a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size);

/* Output and update for function-call system: '<S1075>/tfunc' */
void FuncTranslation_Model_449_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1073>/Subsystem' */
    /* SignalConversion generated from: '<S1074>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1076>:1' */
    /* '<S1076>:1:3' f(); */
    Model_TranslationEngine64_B.Value_m2 =
        Model_TranslationEngine64_B.BoostDisable.Value;

    /* End of Outputs for SubSystem: '<S1073>/Subsystem' */
}

/* Output and update for function-call system: '<S1079>/tfunc' */
void FuncTranslation_Model_450_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1077>/Subsystem' */
    /* SignalConversion generated from: '<S1078>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1080>:1' */
    /* '<S1080>:1:3' f(); */
    Model_TranslationEngine64_B.Value_le =
        Model_TranslationEngine64_B.EnableSilentExtreme.Value;

    /* End of Outputs for SubSystem: '<S1077>/Subsystem' */
}

/* Function for MATLAB Function: '<S1070>/Fade_Table_Translation' */
static void Model_TranslationEngine64_unique_vector_i(const real_T a_data[],
    const int32_T *a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size)
{
    real_T x;
    int32_T idx_data[30];
    int32_T iwork_data[30];
    int32_T b_j;
    int32_T i;
    int32_T i2;
    int32_T kEnd;
    int32_T n;
    int32_T pEnd;
    int32_T qEnd;
    boolean_T exitg1;
    if ((int8_T)*a_size - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)(int8_T)*a_size * sizeof(int32_T));
    }

    if (*a_size != 0)
    {
        i = *a_size - 1;
        for (i2 = 1; i2 <= i; i2 += 2)
        {
            if ((a_data[i2 - 1] <= a_data[i2]) || rtIsNaN(a_data[i2]))
            {
                idx_data[i2 - 1] = i2;
                idx_data[i2] = i2 + 1;
            }
            else
            {
                idx_data[i2 - 1] = i2 + 1;
                idx_data[i2] = i2;
            }
        }

        if (((uint32_T)*a_size & 1U) != 0U)
        {
            idx_data[*a_size - 1] = *a_size;
        }

        i = 2;
        while (i < (*a_size + 1) - 1)
        {
            i2 = i << 1;
            b_j = 1;
            pEnd = i + 1;
            while (pEnd < *a_size + 1)
            {
                int32_T e_k;
                int32_T q;
                n = b_j;
                q = pEnd - 1;
                qEnd = b_j + i2;
                if (qEnd > *a_size + 1)
                {
                    qEnd = *a_size + 1;
                }

                e_k = 0;
                kEnd = qEnd - b_j;
                while (e_k + 1 <= kEnd)
                {
                    int32_T b_tmp_tmp;
                    x = a_data[idx_data[q] - 1];
                    b_tmp_tmp = idx_data[n - 1];
                    if ((a_data[b_tmp_tmp - 1] <= x) || rtIsNaN(x))
                    {
                        iwork_data[e_k] = b_tmp_tmp;
                        n++;
                        if (n == pEnd)
                        {
                            while (q + 1 < qEnd)
                            {
                                e_k++;
                                iwork_data[e_k] = idx_data[q];
                                q++;
                            }
                        }
                    }
                    else
                    {
                        iwork_data[e_k] = idx_data[q];
                        q++;
                        if (q + 1 == qEnd)
                        {
                            while (n < pEnd)
                            {
                                e_k++;
                                iwork_data[e_k] = idx_data[n - 1];
                                n++;
                            }
                        }
                    }

                    e_k++;
                }

                for (pEnd = 0; pEnd < kEnd; pEnd++)
                {
                    idx_data[(b_j + pEnd) - 1] = iwork_data[pEnd];
                }

                b_j = qEnd;
                pEnd = qEnd + i;
            }

            i = i2;
        }
    }

    n = *a_size;
    for (i = 0; i < n; i++)
    {
        b_data[i] = a_data[idx_data[i] - 1];
    }

    b_j = 0;
    while ((b_j + 1 <= *a_size) && rtIsInf(b_data[b_j]) && (b_data[b_j] < 0.0))
    {
        b_j++;
    }

    n = b_j;
    b_j = *a_size;
    while ((b_j >= 1) && rtIsNaN(b_data[b_j - 1]))
    {
        b_j--;
    }

    i = *a_size - b_j;
    exitg1 = false;
    while ((!exitg1) && (b_j >= 1))
    {
        x = b_data[b_j - 1];
        if (rtIsInf(x) && (x > 0.0))
        {
            b_j--;
        }
        else
        {
            exitg1 = true;
        }
    }

    qEnd = (*a_size - b_j) - i;
    i2 = -1;
    if (n > 0)
    {
        i2 = 0;
    }

    while (n + 1 <= b_j)
    {
        x = b_data[n];
        kEnd = n;
        do
        {
            n++;
        }
        while (!((n + 1 > b_j) || (b_data[n] != x)));

        i2++;
        b_data[i2] = x;
        idx_data[i2] = idx_data[kEnd];
    }

    if (qEnd > 0)
    {
        i2++;
        b_data[i2] = b_data[b_j];
        idx_data[i2] = idx_data[b_j];
    }

    n = b_j + qEnd;
    for (b_j = 0; b_j < i; b_j++)
    {
        qEnd = n + b_j;
        pEnd = (i2 + b_j) + 1;
        b_data[pEnd] = b_data[qEnd];
        idx_data[pEnd] = idx_data[qEnd];
    }

    i2 = (i2 + i) + 1;
    if (i2 < 1)
    {
        *b_size = 0;
    }
    else
    {
        *b_size = i2;
    }

    *ndx_size = i2;
    if ((uint8_T)i2 - 1 >= 0)
    {
        memcpy(&ndx_data[0], &idx_data[0], (uint8_T)i2 * sizeof(int32_T));
    }
}

/* Output and update for function-call system: '<S1082>/tfunc' */
void FuncTranslation_Model_455(void)
{
    real_T cleanIdx_data[30];
    real_T tmp_data[30];
    int32_T indx_data[30];
    int32_T i;
    int32_T loop_ub;
    real32_T tmp_0;
    uint32_T tmp;
    char_T k_data[79];
    char_T i_data[74];
    char_T j_data[10];
    int8_T g_tmp_data[30];
    int8_T remainingPairs_data[30];
    static const char_T l[74] =
        "%s must have at least 2 index pairs. Encounted value with only %f pairs\\n";
    static const char_T n[79] =
        "%s out of range table index %f encountered. Index must be between 0 and 255.\\n";
    static const char_T m[10] = "FadeTable";
    int32_T indx_size;
    int32_T remainingPairs_size_idx_1;

    /* MATLAB Function: '<S1070>/Fade_Table_Translation' */
    /* MATLAB Function: '<S1070>/Fade_Table_Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1070>/TuneVarFadeTable'
     *
     * Block description for '<S1070>/TuneVarFadeTable':
     *  Define the fade curve using a table, with the first column being the
     *  list of indices and the second column being the corresponding fade
     *  gains in dB. Gain values for indices in between the elements in the
     *  table are linearly interpolated.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1083>:1' */
    /* '<S1083>:1:3' f(); */
    /*  Set up the size and datatype of our TOP outputs: */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeControl/InnerLink/TuneVarFadeTable/Fade_Table_Translation': '<S1081>:1' */
    /* '<S1081>:1:5' maxTableSize = numel(fadeTable.Value) / 2; */
    /* '<S1081>:1:6' idxType = 'uint8'; */
    /* '<S1081>:1:7' idxStorageType = 'uint32'; */
    /* '<S1081>:1:8' dbType = 'single'; */
    /* '<S1081>:1:9' tableIdx = zeros(1,maxTableSize,idxStorageType); */
    /* '<S1081>:1:10' tableDb = zeros(1,maxTableSize,dbType); */
    memset(&Model_TranslationEngine64_B.tableIdx[0], 0, 30U * sizeof(uint32_T));
    memset(&Model_TranslationEngine64_B.tableDb[0], 0, 30U * sizeof(real32_T));

    /*  separate the pairs into their index and value components */
    /* '<S1081>:1:13' givenPairs = fadeTable.Size(1); */
    /* '<S1081>:1:14' indexes = fadeTable.Value(1:givenPairs,1); */
    /* '<S1081>:1:15' values = fadeTable.Value(1:givenPairs,2); */
    /*  then sort and ignore duplicates */
    /* '<S1081>:1:18' [cleanIdx,map] = unique(indexes); */
    if (Model_TranslationEngine64_B.Table.Size[0] < 1.0)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = (int32_T)Model_TranslationEngine64_B.Table.Size[0] - 1;
    }

    i = loop_ub + 1;
    if (loop_ub >= 0)
    {
        memcpy(&tmp_data[0], &Model_TranslationEngine64_B.Table.Value[0],
               (uint32_T)(loop_ub + 1) * sizeof(real_T));
    }

    Model_TranslationEngine64_unique_vector_i(tmp_data, &i, cleanIdx_data,
        &loop_ub, indx_data, &indx_size);

    /*  Validate input sizes */
    /* '<S1081>:1:21' numPairs = numel(map); */
    /* '<S1081>:1:22' argName='FadeTable'; */
    /*  Validate: enough data? */
    /* '<S1081>:1:25' if (numPairs < 2) */
    if (indx_size < 2)
    {
        /* '<S1081>:1:26' TranslateError('%s must have at least 2 index pairs. Encounted value with only %f pairs\n', argName, numPairs); */
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
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:26' fixedArgs{i} = [varargin{i} char(0)]; */
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&i_data[0], &l[0], 74U * sizeof(char_T));
        for (i = 0; i < 10; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&i_data[0], &j_data[0], (real_T)indx_size);
    }

    /*  Validate: Highest index still below 1.0? */
    /* '<S1081>:1:30' if (cleanIdx(1) < 0 || cleanIdx(end) > intmax(idxType)) */
    if ((cleanIdx_data[0] < 0.0) || (cleanIdx_data[loop_ub - 1] > 255.0))
    {
        /* '<S1081>:1:31' TranslateError('%s out of range table index %f encountered. Index must be between 0 and 255.\n',argName,cleanIdx(end)); */
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
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:26' fixedArgs{i} = [varargin{i} char(0)]; */
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&k_data[0], &n[0], 79U * sizeof(char_T));
        for (i = 0; i < 10; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&k_data[0], &j_data[0], cleanIdx_data[loop_ub - 1]);
    }

    /*  fill in the table buffer with provided pairs */
    /* '<S1081>:1:35' tableIdx(1:numPairs) = cleanIdx(1:numPairs); */
    if (indx_size < 1)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = indx_size - 1;
    }

    for (i = 0; i <= loop_ub; i++)
    {
        Model_TranslationEngine64_B.tableIdx[i] = (uint32_T)rt_roundd_snf
            (cleanIdx_data[i]);
    }

    /* '<S1081>:1:36' tableDb(1:numPairs) = values(map(1:numPairs)); */
    if (indx_size < 1)
    {
        loop_ub = 0;
    }
    else
    {
        loop_ub = indx_size;
    }

    for (i = 0; i < loop_ub; i++)
    {
        Model_TranslationEngine64_B.tableDb[i] = (real32_T)
            Model_TranslationEngine64_B.Table.Value[indx_data[i] + 29];
    }

    /*  fill the rest of the table buffer with the last entry */
    /* '<S1081>:1:39' remainingPairs = numel(map)+1:maxTableSize; */
    if (indx_size + 1 > 30)
    {
        remainingPairs_size_idx_1 = 0;
    }
    else
    {
        remainingPairs_size_idx_1 = 30 - indx_size;
        loop_ub = 29 - indx_size;
        for (i = 0; i <= loop_ub; i++)
        {
            remainingPairs_data[i] = (int8_T)((indx_size + 1) + i);
        }
    }

    /* '<S1081>:1:40' tableIdx(remainingPairs) = tableIdx(numPairs); */
    if (remainingPairs_size_idx_1 - 1 >= 0)
    {
        memcpy(&g_tmp_data[0], &remainingPairs_data[0], (uint32_T)
               remainingPairs_size_idx_1 * sizeof(int8_T));
    }

    tmp = Model_TranslationEngine64_B.tableIdx[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        Model_TranslationEngine64_B.tableIdx[g_tmp_data[i] - 1] = tmp;
    }

    /* '<S1081>:1:41' tableDb(remainingPairs) =  tableDb(numPairs); */
    tmp_0 = Model_TranslationEngine64_B.tableDb[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        Model_TranslationEngine64_B.tableDb[g_tmp_data[i] - 1] = tmp_0;
    }

    /* End of MATLAB Function: '<S1070>/Fade_Table_Translation' */
}

/* Output and update for function-call system: '<S1086>/tfunc' */
void FuncTranslation_Model_459_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1084>/Subsystem' */
    /* SignalConversion generated from: '<S1085>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1087>:1' */
    /* '<S1087>:1:3' f(); */
    Model_TranslationEngine64_B.Value_of =
        Model_TranslationEngine64_B.offset.Value;

    /* End of Outputs for SubSystem: '<S1084>/Subsystem' */
}

/* Output and update for function-call system: '<S1090>/tfunc' */
void FuncTranslation_Model_460_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1088>/Subsystem' */
    /* SignalConversion generated from: '<S1089>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1091>:1' */
    /* '<S1091>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mg =
        Model_TranslationEngine64_B.RampTime_bg.Value;

    /* End of Outputs for SubSystem: '<S1088>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1092>/Filter_Coeffs_Translation'
 *    '<S1099>/Filter_Coeffs_Translation'
 */
void Model_TranslationEngine64_Filter_Coeffs_Translation(const bus_double_1_1
    *rtu_cutoffFreqHz, real32_T rtu_FsHz,
    B_Filter_Coeffs_Translation_Model_TranslationEngine64_T *localB)
{
    real32_T B0;
    real32_T omega;

    /*  Generate the low pass filter coefficients which will then be applied to */
    /*  the audio input */
    /*  Inputs: */
    /*   cutoffFreqHz: Cut off frequency in Hz for LPF */
    /*   FsHz: Sampling frequency in Hz */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperDR/InnerLink/Filter_Coeffs_Translation': '<S1094>:1' */
    /* '<S1094>:1:9' omega = 2 * pi * cutoffFreqHz.Value / FsHz; */
    omega = (real32_T)(6.2831853071795862 * rtu_cutoffFreqHz->Value) / rtu_FsHz;

    /* '<S1094>:1:11' A = 1 - sin(omega) / cos(omega); */
    omega = 1.0F - sinf(omega) / cosf(omega);

    /* '<S1094>:1:12' B0 = (1 - A) / 2; */
    B0 = (1.0F - omega) / 2.0F;

    /* '<S1094>:1:13' B1 = B0; */
    /* '<S1094>:1:15' FilterCoeffs = single([B0 B1 A]); */
    localB->FilterCoeffs[0] = B0;
    localB->FilterCoeffs[1] = B0;
    localB->FilterCoeffs[2] = omega;
}

/* Output and update for function-call system: '<S1095>/tfunc' */
void FuncTranslation_Model_175_136_98(void)
{
    /* MATLAB Function: '<S1092>/Filter_Coeffs_Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1097>:1' */
    /* '<S1097>:1:3' f(); */
    Model_TranslationEngine64_Filter_Coeffs_Translation
        (&Model_TranslationEngine64_B.CutoffHz,
         Model_TranslationEngine64_ConstB.CapturedTuneConst1_m,
         &Model_TranslationEngine64_B.sf_Filter_Coeffs_Translation);
}

/* Output and update for function-call system: '<S1096>/tfunc' */
void FuncTranslation_Model_175_136_99(void)
{
    int32_T i;

    /* MATLAB Function: '<S1092>/Channel_Ramper_Translation' */
    /* MATLAB Function: '<S1092>/Channel_Ramper_Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1092>/TuneVarChannelRamperMap'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1098>:1' */
    /* '<S1098>:1:3' f(); */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperDR/InnerLink/Channel_Ramper_Translation': '<S1093>:1' */
    /*  Verifies if each channel is assigned to either the 'Front'(1) or 'Rear'(2) */
    /*  groups.  */
    /* '<S1093>:1:7' argName = 'Fade'; */
    /*  Ensure each channel is present in the map */
    /* '<S1093>:1:10' inputMapWidth = numel(TuneChanRampMap.Value); */
    /* '<S1093>:1:11' if (inputMapWidth ~= channelCount) */
    /*  Verify that the channels are assigned to valid group numbers */
    /* '<S1093>:1:19' if (numel(unique(TuneChanRampMap.Value)) > MaskNumChannelGroups + 1) */
    /*  Ensure that a value of 0 was not entered as a ramper */
    /* '<S1093>:1:26' if (sum(TuneChanRampMap.Value == 0) > 0) */
    /*  Output */
    /* '<S1093>:1:33' ChanRampMap = int32(TuneChanRampMap.Value); */
    for (i = 0; i < 30; i++)
    {
        Model_TranslationEngine64_B.ChanRampMap_a[i] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_B.ChannelToRamperMap.Value[i]);
    }

    /* End of MATLAB Function: '<S1092>/Channel_Ramper_Translation' */
}

/* Output and update for function-call system: '<S1102>/tfunc' */
void FuncTranslation_Model_176_136_98(void)
{
    /* MATLAB Function: '<S1099>/Filter_Coeffs_Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1104>:1' */
    /* '<S1104>:1:3' f(); */
    Model_TranslationEngine64_Filter_Coeffs_Translation
        (&Model_TranslationEngine64_B.CutoffHz_m,
         Model_TranslationEngine64_ConstB.CapturedTuneConst1_lp,
         &Model_TranslationEngine64_B.sf_Filter_Coeffs_Translation_dm);
}

/* Output and update for function-call system: '<S1103>/tfunc' */
void FuncTranslation_Model_176_136_99(void)
{
    int32_T i;

    /* MATLAB Function: '<S1099>/Channel_Ramper_Translation' */
    /* MATLAB Function: '<S1099>/Channel_Ramper_Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1099>/TuneVarChannelRamperMap'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1105>:1' */
    /* '<S1105>:1:3' f(); */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/FadeRamperFR/InnerLink/Channel_Ramper_Translation': '<S1100>:1' */
    /*  Verifies if each channel is assigned to either the 'Front'(1) or 'Rear'(2) */
    /*  groups.  */
    /* '<S1100>:1:7' argName = 'Fade'; */
    /*  Ensure each channel is present in the map */
    /* '<S1100>:1:10' inputMapWidth = numel(TuneChanRampMap.Value); */
    /* '<S1100>:1:11' if (inputMapWidth ~= channelCount) */
    /*  Verify that the channels are assigned to valid group numbers */
    /* '<S1100>:1:19' if (numel(unique(TuneChanRampMap.Value)) > MaskNumChannelGroups + 1) */
    /*  Ensure that a value of 0 was not entered as a ramper */
    /* '<S1100>:1:26' if (sum(TuneChanRampMap.Value == 0) > 0) */
    /*  Output */
    /* '<S1100>:1:33' ChanRampMap = int32(TuneChanRampMap.Value); */
    for (i = 0; i < 22; i++)
    {
        Model_TranslationEngine64_B.ChanRampMap_j[i] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_B.ChannelToRamperMap_g.Value[i]);
    }

    /* End of MATLAB Function: '<S1099>/Channel_Ramper_Translation' */
}

/* Output and update for function-call system: '<S1110>/tfunc' */
void FuncTranslation_Model_489_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1108>/Subsystem' */
    /* SignalConversion generated from: '<S1109>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1111>:1' */
    /* '<S1111>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ey =
        Model_TranslationEngine64_B.RampTime_bq.Value;

    /* End of Outputs for SubSystem: '<S1108>/Subsystem' */
}

/* Output and update for function-call system: '<S1113>/tfunc' */
void FuncTranslation_Model_533(void)
{
    int32_T i;

    /* MATLAB Function: '<S1112>/channel_ramper_translation' */
    /* MATLAB Function: '<S1112>/channel_ramper_translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1112>/TuneVarChannelRamperMap'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1119>:1' */
    /* '<S1119>:1:3' f(); */
    /*  %Inputs */
    /*  Parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/channel_ramper_translation': '<S1118>:1' */
    /*  Function that verifies channel-to-ramper map is valid */
    /*  Takes channelRamperMap and channelCount as inputs, and  */
    /*  number of rampers as a parameter */
    /* '<S1118>:1:7' argName = 'SleepingBeauty'; */
    /*  Ensure each channel is present in the map */
    /* '<S1118>:1:10' inputMapWidth = numel(TuneChanRampMap.Value); */
    /* '<S1118>:1:11' if (inputMapWidth ~= channelCount) */
    /*  Verifies if each channel is assigned to one of the 5 possible rampers. */
    /* '<S1118>:1:20' if (numel(unique(TuneChanRampMap.Value)) > (MaskNumRampers + 1)) */
    /*  Verify that a value of 0 was not incorrectly entered as a ramper */
    /* '<S1118>:1:28' if (sum(TuneChanRampMap.Value == 0) > 0) */
    /* '<S1118>:1:34' ChanRampMap = int32(TuneChanRampMap.Value); */
    for (i = 0; i < 30; i++)
    {
        Model_TranslationEngine64_B.ChanRampMap_c[i] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_B.ChannelToRamperMap_f.Value[i]);
    }

    /* End of MATLAB Function: '<S1112>/channel_ramper_translation' */
}

/* Output and update for function-call system: '<S1122>/tfunc' */
void FuncTranslation_Model_538_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1120>/Subsystem' */
    /* SignalConversion generated from: '<S1121>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1123>:1' */
    /* '<S1123>:1:3' f(); */
    Model_TranslationEngine64_B.Value_cj =
        Model_TranslationEngine64_B.Offset.Value;

    /* End of Outputs for SubSystem: '<S1120>/Subsystem' */
}

/* Output and update for function-call system: '<S1126>/tfunc' */
void FuncTranslation_Model_539_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1124>/Subsystem' */
    /* SignalConversion generated from: '<S1125>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1127>:1' */
    /* '<S1127>:1:3' f(); */
    Model_TranslationEngine64_B.Value_k4 =
        Model_TranslationEngine64_B.RampTime_k.Value;

    /* End of Outputs for SubSystem: '<S1124>/Subsystem' */
}

/* Output and update for function-call system: '<S1130>/tfunc' */
void FuncTranslation_Model_540_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1128>/Subsystem' */
    /* SignalConversion generated from: '<S1129>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1131>:1' */
    /* '<S1131>:1:3' f(); */
    Model_TranslationEngine64_B.Value_di =
        Model_TranslationEngine64_B.MutesBass.Value;

    /* End of Outputs for SubSystem: '<S1128>/Subsystem' */
}

/* Function for MATLAB Function: '<S1117>/translation' */
static void Model_TranslationEngine64_unique_vector(const real_T a_data[], const
    int32_T *a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size)
{
    real_T x;
    int32_T idx_data[30];
    int32_T iwork_data[30];
    int32_T b_j;
    int32_T i;
    int32_T i2;
    int32_T kEnd;
    int32_T n;
    int32_T pEnd;
    int32_T qEnd;
    boolean_T exitg1;
    if ((int8_T)*a_size - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)(int8_T)*a_size * sizeof(int32_T));
    }

    if (*a_size != 0)
    {
        i = *a_size - 1;
        for (i2 = 1; i2 <= i; i2 += 2)
        {
            if ((a_data[i2 - 1] <= a_data[i2]) || rtIsNaN(a_data[i2]))
            {
                idx_data[i2 - 1] = i2;
                idx_data[i2] = i2 + 1;
            }
            else
            {
                idx_data[i2 - 1] = i2 + 1;
                idx_data[i2] = i2;
            }
        }

        if (((uint32_T)*a_size & 1U) != 0U)
        {
            idx_data[*a_size - 1] = *a_size;
        }

        i = 2;
        while (i < (*a_size + 1) - 1)
        {
            i2 = i << 1;
            b_j = 1;
            pEnd = i + 1;
            while (pEnd < *a_size + 1)
            {
                int32_T e_k;
                int32_T q;
                n = b_j;
                q = pEnd - 1;
                qEnd = b_j + i2;
                if (qEnd > *a_size + 1)
                {
                    qEnd = *a_size + 1;
                }

                e_k = 0;
                kEnd = qEnd - b_j;
                while (e_k + 1 <= kEnd)
                {
                    int32_T b_tmp_tmp;
                    x = a_data[idx_data[q] - 1];
                    b_tmp_tmp = idx_data[n - 1];
                    if ((a_data[b_tmp_tmp - 1] <= x) || rtIsNaN(x))
                    {
                        iwork_data[e_k] = b_tmp_tmp;
                        n++;
                        if (n == pEnd)
                        {
                            while (q + 1 < qEnd)
                            {
                                e_k++;
                                iwork_data[e_k] = idx_data[q];
                                q++;
                            }
                        }
                    }
                    else
                    {
                        iwork_data[e_k] = idx_data[q];
                        q++;
                        if (q + 1 == qEnd)
                        {
                            while (n < pEnd)
                            {
                                e_k++;
                                iwork_data[e_k] = idx_data[n - 1];
                                n++;
                            }
                        }
                    }

                    e_k++;
                }

                for (pEnd = 0; pEnd < kEnd; pEnd++)
                {
                    idx_data[(b_j + pEnd) - 1] = iwork_data[pEnd];
                }

                b_j = qEnd;
                pEnd = qEnd + i;
            }

            i = i2;
        }
    }

    n = *a_size;
    for (i = 0; i < n; i++)
    {
        b_data[i] = a_data[idx_data[i] - 1];
    }

    b_j = 0;
    while ((b_j + 1 <= *a_size) && rtIsInf(b_data[b_j]) && (b_data[b_j] < 0.0))
    {
        b_j++;
    }

    n = b_j;
    b_j = *a_size;
    while ((b_j >= 1) && rtIsNaN(b_data[b_j - 1]))
    {
        b_j--;
    }

    i = *a_size - b_j;
    exitg1 = false;
    while ((!exitg1) && (b_j >= 1))
    {
        x = b_data[b_j - 1];
        if (rtIsInf(x) && (x > 0.0))
        {
            b_j--;
        }
        else
        {
            exitg1 = true;
        }
    }

    qEnd = (*a_size - b_j) - i;
    i2 = -1;
    if (n > 0)
    {
        i2 = 0;
    }

    while (n + 1 <= b_j)
    {
        x = b_data[n];
        kEnd = n;
        do
        {
            n++;
        }
        while (!((n + 1 > b_j) || (b_data[n] != x)));

        i2++;
        b_data[i2] = x;
        idx_data[i2] = idx_data[kEnd];
    }

    if (qEnd > 0)
    {
        i2++;
        b_data[i2] = b_data[b_j];
        idx_data[i2] = idx_data[b_j];
    }

    n = b_j + qEnd;
    for (b_j = 0; b_j < i; b_j++)
    {
        qEnd = n + b_j;
        pEnd = (i2 + b_j) + 1;
        b_data[pEnd] = b_data[qEnd];
        idx_data[pEnd] = idx_data[qEnd];
    }

    i2 = (i2 + i) + 1;
    if (i2 < 1)
    {
        *b_size = 0;
    }
    else
    {
        *b_size = i2;
    }

    *ndx_size = i2;
    if ((uint8_T)i2 - 1 >= 0)
    {
        memcpy(&ndx_data[0], &idx_data[0], (uint8_T)i2 * sizeof(int32_T));
    }
}

/*
 * Output and update for function-call system:
 *    '<S1117>/translation'
 *    '<S1140>/translation'
 */
void Model_TranslationEngine64_translation(const bus_double_30__2
    *rtu_sleepingBeautyTable, B_translation_Model_TranslationEngine64_T *localB)
{
    real_T cleanIdx_data[30];
    real_T rtu_sleepingBeautyTable_data[30];
    int32_T indx_data[30];
    int32_T i;
    int32_T loop_ub;
    real32_T tmp_0;
    uint32_T tmp;
    char_T k_data[78];
    char_T i_data[74];
    char_T j_data[20];
    int8_T g_tmp_data[30];
    int8_T remainingPairs_data[30];
    static const char_T l[74] =
        "%s must have at least 2 index pairs. Encounted value with only %f pairs\\n";
    static const char_T m[20] = "sleepingBeautyTable";
    static const char_T n[78] =
        "%s out of range table index %f encountered. Index must be between 0 and %d.\\n";
    int32_T cleanIdx_size;
    int32_T indx_size;
    int32_T remainingPairs_size_idx_1;

    /*  Set up the size and datatype of our TOP outputs: */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyDR/InnerLink/TuneVarTable/translation': '<S1133>:1' */
    /* '<S1133>:1:5' maxTableSize = numel(sleepingBeautyTable.Value) / 2; */
    /* '<S1133>:1:6' idxType = 'uint8'; */
    /* '<S1133>:1:7' idxStorageType = 'uint32'; */
    /* '<S1133>:1:8' dbType = 'single'; */
    /* '<S1133>:1:9' tableIdx = zeros(1,maxTableSize,idxStorageType); */
    /* '<S1133>:1:10' tableDb = zeros(1,maxTableSize,dbType); */
    memset(&localB->tableIdx[0], 0, 30U * sizeof(uint32_T));
    memset(&localB->tableDb[0], 0, 30U * sizeof(real32_T));

    /*  separate the pairs into their index and value components */
    /* '<S1133>:1:13' givenPairs = sleepingBeautyTable.Size(1); */
    /* '<S1133>:1:14' indices = sleepingBeautyTable.Value(1:givenPairs,1); */
    /* '<S1133>:1:15' values = sleepingBeautyTable.Value(1:givenPairs,2); */
    /*  then sort and ignore duplicates */
    /* '<S1133>:1:18' [cleanIdx,map] = unique(indices); */
    if (rtu_sleepingBeautyTable->Size[0] < 1.0)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = (int32_T)rtu_sleepingBeautyTable->Size[0] - 1;
    }

    i = loop_ub + 1;
    if (loop_ub >= 0)
    {
        memcpy(&rtu_sleepingBeautyTable_data[0], &rtu_sleepingBeautyTable->
               Value[0], (uint32_T)(loop_ub + 1) * sizeof(real_T));
    }

    Model_TranslationEngine64_unique_vector(rtu_sleepingBeautyTable_data, &i,
        cleanIdx_data, &cleanIdx_size, indx_data, &indx_size);

    /*  Validate input sizes */
    /* '<S1133>:1:21' numPairs = numel(map); */
    /* '<S1133>:1:22' argName='sleepingBeautyTable'; */
    /*  Validate: enough data? */
    /* '<S1133>:1:25' if (numPairs < 2) */
    if (indx_size < 2)
    {
        /* '<S1133>:1:26' TranslateError('%s must have at least 2 index pairs. Encounted value with only %f pairs\n', argName, numPairs); */
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
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:26' fixedArgs{i} = [varargin{i} char(0)]; */
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&i_data[0], &l[0], 74U * sizeof(char_T));
        for (i = 0; i < 20; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&i_data[0], &j_data[0], (real_T)indx_size);
    }

    /*  Validate: Highest index still below 255? */
    /* '<S1133>:1:30' if (cleanIdx(1) < 0 || cleanIdx(end) > intmax(idxType)) */
    if ((cleanIdx_data[0] < 0.0) || (cleanIdx_data[cleanIdx_size - 1] > 255.0))
    {
        /* '<S1133>:1:31' TranslateError('%s out of range table index %f encountered. Index must be between 0 and %d.\n',argName,cleanIdx(end),intmax(idxType)); */
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
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:26' fixedArgs{i} = [varargin{i} char(0)]; */
        /* 'TranslateError:25' if (ischar(varargin{i})) */
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&k_data[0], &n[0], 78U * sizeof(char_T));
        for (i = 0; i < 20; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&k_data[0], &j_data[0], cleanIdx_data[cleanIdx_size - 1],
                       MAX_uint8_T);
    }

    /*  fill in the table buffer with provided pairs */
    /* '<S1133>:1:35' tableIdx(1:numPairs) = cleanIdx(1:numPairs); */
    if (indx_size < 1)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = indx_size - 1;
    }

    for (i = 0; i <= loop_ub; i++)
    {
        localB->tableIdx[i] = (uint32_T)rt_roundd_snf(cleanIdx_data[i]);
    }

    /* '<S1133>:1:36' tableDb(1:numPairs) = values(map(1:numPairs)); */
    if (indx_size < 1)
    {
        cleanIdx_size = 0;
    }
    else
    {
        cleanIdx_size = indx_size;
    }

    for (i = 0; i < cleanIdx_size; i++)
    {
        localB->tableDb[i] = (real32_T)rtu_sleepingBeautyTable->
            Value[indx_data[i] + 29];
    }

    /*  fill the rest of the table buffer with the last entry */
    /* '<S1133>:1:39' remainingPairs = numel(map)+1:maxTableSize; */
    if (indx_size + 1 > 30)
    {
        remainingPairs_size_idx_1 = 0;
    }
    else
    {
        remainingPairs_size_idx_1 = 30 - indx_size;
        loop_ub = 29 - indx_size;
        for (cleanIdx_size = 0; cleanIdx_size <= loop_ub; cleanIdx_size++)
        {
            remainingPairs_data[cleanIdx_size] = (int8_T)((indx_size + 1) +
                cleanIdx_size);
        }
    }

    /* '<S1133>:1:40' tableIdx(remainingPairs) = tableIdx(numPairs); */
    if (remainingPairs_size_idx_1 - 1 >= 0)
    {
        memcpy(&g_tmp_data[0], &remainingPairs_data[0], (uint32_T)
               remainingPairs_size_idx_1 * sizeof(int8_T));
    }

    tmp = localB->tableIdx[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        localB->tableIdx[g_tmp_data[i] - 1] = tmp;
    }

    /* '<S1133>:1:41' tableDb(remainingPairs) =  tableDb(numPairs); */
    tmp_0 = localB->tableDb[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        localB->tableDb[g_tmp_data[i] - 1] = tmp_0;
    }
}

/* Output and update for function-call system: '<S1132>/tfunc' */
void FuncTranslation_Model_545(void)
{
    /* MATLAB Function: '<S1117>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1134>:1' */
    /* '<S1134>:1:3' f(); */
    Model_TranslationEngine64_translation
        (&Model_TranslationEngine64_B.TaperGainTable,
         &Model_TranslationEngine64_B.sf_translation_h);
}

/* Output and update for function-call system: '<S1136>/tfunc' */
void FuncTranslation_Model_596(void)
{
    int32_T i;

    /* MATLAB Function: '<S1135>/channel_ramper_translation' */
    /* MATLAB Function: '<S1135>/channel_ramper_translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1135>/TuneVarChannelRamperMap'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1142>:1' */
    /* '<S1142>:1:3' f(); */
    /*  %Inputs */
    /*  Parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/SleepingBeauty/SleepingBeauty/Enabled/SleepingBeautyFR/InnerLink/channel_ramper_translation': '<S1141>:1' */
    /*  Function that verifies channel-to-ramper map is valid */
    /*  Takes channelRamperMap and channelCount as inputs, and  */
    /*  number of rampers as a parameter */
    /* '<S1141>:1:7' argName = 'SleepingBeauty'; */
    /*  Ensure each channel is present in the map */
    /* '<S1141>:1:10' inputMapWidth = numel(TuneChanRampMap.Value); */
    /* '<S1141>:1:11' if (inputMapWidth ~= channelCount) */
    /*  Verifies if each channel is assigned to one of the 5 possible rampers. */
    /* '<S1141>:1:20' if (numel(unique(TuneChanRampMap.Value)) > (MaskNumRampers + 1)) */
    /*  Verify that a value of 0 was not incorrectly entered as a ramper */
    /* '<S1141>:1:28' if (sum(TuneChanRampMap.Value == 0) > 0) */
    /* '<S1141>:1:34' ChanRampMap = int32(TuneChanRampMap.Value); */
    for (i = 0; i < 22; i++)
    {
        Model_TranslationEngine64_B.ChanRampMap_i[i] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_B.ChannelToRamperMap_m.Value[i]);
    }

    /* End of MATLAB Function: '<S1135>/channel_ramper_translation' */
}

/* Output and update for function-call system: '<S1145>/tfunc' */
void FuncTranslation_Model_601_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1143>/Subsystem' */
    /* SignalConversion generated from: '<S1144>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1146>:1' */
    /* '<S1146>:1:3' f(); */
    Model_TranslationEngine64_B.Value_p1 =
        Model_TranslationEngine64_B.Offset_l.Value;

    /* End of Outputs for SubSystem: '<S1143>/Subsystem' */
}

/* Output and update for function-call system: '<S1149>/tfunc' */
void FuncTranslation_Model_602_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1147>/Subsystem' */
    /* SignalConversion generated from: '<S1148>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1150>:1' */
    /* '<S1150>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ph =
        Model_TranslationEngine64_B.RampTime_e.Value;

    /* End of Outputs for SubSystem: '<S1147>/Subsystem' */
}

/* Output and update for function-call system: '<S1153>/tfunc' */
void FuncTranslation_Model_603_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1151>/Subsystem' */
    /* SignalConversion generated from: '<S1152>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1154>:1' */
    /* '<S1154>:1:3' f(); */
    Model_TranslationEngine64_B.Value_il =
        Model_TranslationEngine64_B.MutesBass_h.Value;

    /* End of Outputs for SubSystem: '<S1151>/Subsystem' */
}

/* Output and update for function-call system: '<S1155>/tfunc' */
void FuncTranslation_Model_608(void)
{
    /* MATLAB Function: '<S1140>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1157>:1' */
    /* '<S1157>:1:3' f(); */
    Model_TranslationEngine64_translation
        (&Model_TranslationEngine64_B.TaperGainTable_h,
         &Model_TranslationEngine64_B.sf_translation_am);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
