/*
 * File: Model_TranslationEngine64.c
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
#include "Model_TranslationEngine64_private.h"
#include <math.h>
#include <string.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "MedusaExpandTailComps.h"
#include "MedusaPostHoligram.h"
#include "Enabled.h"
#include "VLS.h"
#include "PostProcess.h"

/* Block signals (default storage) */
B_Model_TranslationEngine64_T Model_TranslationEngine64_B;

/* Real-time model */
static RT_MODEL_Model_TranslationEngine64_T Model_TranslationEngine64_M_;
RT_MODEL_Model_TranslationEngine64_T *const Model_TranslationEngine64_M =
    &Model_TranslationEngine64_M_;

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_i(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_iu(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_l(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_d3(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_i0(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static boolean_T Model_TranslationEngine64_sortLE(const real32_T v_data[],
    int32_T idx1, int32_T idx2);
static void Model_TranslationEngine64_sortrows(real32_T y_data[], const int32_T
    y_size[2]);
static void Model_TranslationEngine64_unique_vector_d(const real32_T a_data[],
    const int32_T *a_size, real32_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size);
static void Model_TranslationEngine64_do_vectors(const real_T a_data[], const
    int32_T a_size[2], const real_T b_data[], const int32_T *b_size, real_T
    c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *ia_size, int32_T
    *ib_size);
static boolean_T Model_TranslationEngine64_any(const boolean_T x_data[], const
    int32_T *x_size);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_k(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_pu(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_n(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_unique_vector_a(const real_T a_data[],
    const int32_T *a_size, real_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_ny(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_dn(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_cat(const real32_T varargin_1[25], const
    real32_T varargin_2[25], const real32_T varargin_3[25], const real32_T
    varargin_4[25], const real32_T varargin_5[25], const real32_T varargin_6[25],
    const real32_T varargin_7[25], const real32_T varargin_8[25], const real32_T
    varargin_9[25], const real32_T varargin_10[25], const real32_T varargin_11
    [25], const real32_T varargin_12[25], real32_T y[300]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_kl(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_merge(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[]);
static void Model_TranslationEngine64_sort(real_T x_data[], int32_T x_size[2]);
static void Model_TranslationEngine64_cplxpair(real_T x_data[], int32_T x_size[2]);
static boolean_T Model_TranslationEngine64_cplxpairv(creal_T x_data[], const
    int32_T x_size[2]);
static void Model_TranslationEngine64_cplxpair_b(creal_T x_data[], const int32_T
    x_size[2]);
static void Model_TranslationEngine64_abs(const real_T x_data[], const int32_T
    x_size[2], real_T y_data[], int32_T y_size[2]);
static void Model_TranslationEngine64_eml_find(const boolean_T x_data[], const
    int32_T x_size[2], int32_T i_data[], int32_T i_size[2]);
static void Model_TranslationEngine64_nullAssignment(real_T x_data[], int32_T
    x_size[2], const int32_T idx_data[], const int32_T idx_size[2]);
static void Model_TranslationEngine64_binary_expand_op_j5plg(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7);
static void Model_TranslationEngine64_binary_expand_op_j5pl(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7);
static void Model_TranslationEngine64_binary_expand_op_j5p(real_T in1_data[],
    int32_T in1_size[2], const creal_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7);
static void Model_TranslationEngine64_binary_expand_op_j5(real_T in1_data[],
    int32_T in1_size[2], const creal_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7);
static void Model_TranslationEngine64_abs_h(const creal_T x_data[], const
    int32_T x_size[2], real_T y_data[], int32_T y_size[2]);
static void Model_TranslationEngine64_zp2sos(real_T z_data[], int32_T z_size[2],
    creal_T p_data[], const int32_T p_size[2], real_T g, real_T sos_data[],
    int32_T sos_size[2]);

/* Forward declaration for local functions */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_k2(int32_T b,
    int32_T y_data[], int32_T y_size[2]);

/* Declare variables for internal data of system '<S599>/Alignment Delay' */
B_AlignmentDelay_Model_TranslationEngine64_T
    Model_TranslationEngine64_AlignmentDelay_B;

/* Declare variables for internal data of system '<S560>/Medusa5H1 Part 3' */
B_Medusa5H1Part3_Model_TranslationEngine64_T
    Model_TranslationEngine64_Medusa5H1Part3_B;

/* Declare variables for internal data of system '<S560>/Medusa5H1 Part 4' */
B_Medusa5H1Part4_Model_TranslationEngine64_T
    Model_TranslationEngine64_Medusa5H1Part4_B;

/* Declare variables for internal data of system '<S560>/Medusa5H1 Part 6' */
B_Medusa5H1Part6_Model_TranslationEngine64_T
    Model_TranslationEngine64_Medusa5H1Part6_B;

/* Declare variables for internal data of system '<S3>/PreAmpPart1' */
B_PreAmpPart1_Model_TranslationEngine64_T
    Model_TranslationEngine64_PreAmpPart1_B;
int32_T div_s32(int32_T numerator, int32_T denominator)
{
    int32_T quotient;
    if (denominator == 0)
    {
        quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

        /* Divide by zero handler */
    }
    else
    {
        uint32_T tempAbsQuotient;
        tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                           numerator) / (denominator < 0 ? ~(uint32_T)
            denominator + 1U : (uint32_T)denominator);
        quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)
            tempAbsQuotient : (int32_T)tempAbsQuotient;
    }

    return quotient;
}

/* Output and update for function-call system: '<S8>/tfunc' */
void FuncTranslation_Model_397(void)
{
    real_T endOfMap;
    real_T loopCount;
    real_T mapDifference;
    real_T mapLength;
    int32_T i;

    /* MATLAB Function: '<S7>/Trivial Translation' */
    /* MATLAB Function: '<S7>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S7>/TuneVarRouterMap'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S10>:1' */
    /* '<S10>:1:3' f(); */
    /*  ----- To access TuneVar maximum size, current size, and current value: */
    /*    Note: TuneVar signals arrive with exposed variable size information. */
    /*          The expressions below illustrate for the "Map" input argument. */
    /*  */
    /*    size(Map.Value) : the maximum possible size of the Map variable */
    /*  */
    /*    Tune.Size   : the current size of *valid* data in Map.Value */
    /*  */
    /*    Map.Size(1) : Number of rows present in Map - this does not vary. */
    /*  */
    /*    Map.Size(2) : Number of columns currently valid in Map - this is */
    /*        the variable part of size that can change (if allowed by TuneVar). */
    /*  */
    /*    Map.Value : the current value of the tune variable... but end-padded  */
    /*        to the maximum available size with undefined/invalid data. */
    /*  */
    /*    numel(Map.Value) : another way of looking at the maximum number of */
    /*        elements that could arrive in Map.Value */
    /*  */
    /*  ----- To register an error, use the following method (works like printf): */
    /*    TranslateError( <format string>, <arguments ... ) */
    /*    ... this error will cause the build process to abort. */
    /* MATLAB Function 'InputSelect/Router/Trivial Translation': '<S9>:1' */
    /*  The below logic ensures that an output map gets filled in in the  */
    /*  "round robin" manner. This is to occur when the supplied map is shorter */
    /*  than the number of channel outputs. For instance, */
    /*  nChanIn = 4 */
    /*  nChanOut = 9 */
    /*  outputMapSupplied = [4 3 2 2] */
    /*   */
    /*  This logic would run and return OutMap = [4 3 2 2 1 2 3 4 1] */
    /*  */
    /*  If no outputMap was supplied (i.e. = [];) THEN */
    /*  This logic would run and return OutMap = [1 2 3 4 1 2 3 4 1]; */
    /*  First part finds the number of output map indices that were left blank */
    /* '<S9>:1:42' nChanOut = numel(Map.Value); */
    /* '<S9>:1:43' mapLength = Map.Size(2); */
    mapLength = Model_TranslationEngine64_B.Map_b.Size[1];

    /* '<S9>:1:44' mapDifference = nChanOut - mapLength; */
    mapDifference = 5.0 - Model_TranslationEngine64_B.Map_b.Size[1];

    /* '<S9>:1:45' OutMap = int32(Map.Value); */
    for (i = 0; i < 5; i++)
    {
        Model_TranslationEngine64_B.OutMap[i] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_B.Map_b.Value[i]);
    }

    /*  This loop appropriates the correct input channel number to the */
    /*  corresponding output channel, based on the mapDifference found above */
    /* '<S9>:1:49' if (mapLength == 1) && Map.Value(1) == 0 */
    if ((Model_TranslationEngine64_B.Map_b.Size[1] == 1.0) &&
            (Model_TranslationEngine64_B.Map_b.Value[0] == 0.0))
    {
        /* '<S9>:1:50' mapLength = 0; */
        mapLength = 0.0;

        /* '<S9>:1:51' mapDifference = nChanOut; */
        mapDifference = 5.0;
    }

    /* '<S9>:1:53' endOfMap = 0; */
    endOfMap = 0.0;

    /* '<S9>:1:54' loopCount = 0; */
    loopCount = 0.0;

    /* '<S9>:1:55' while endOfMap < mapDifference */
    while (endOfMap < mapDifference)
    {
        boolean_T exitg1;

        /* '<S9>:1:56' for inputChan = 1 : nInRouterMask */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= 4))
        {
            /* '<S9>:1:57' OutMap(mapLength+inputChan+loopCount) = inputChan; */
            Model_TranslationEngine64_B.OutMap[(int32_T)((mapLength + ((real_T)i
                + 1.0)) + loopCount) - 1] = i + 1;

            /* '<S9>:1:58' endOfMap = endOfMap + 1; */
            endOfMap++;

            /* '<S9>:1:59' if endOfMap == mapDifference */
            if (endOfMap == mapDifference)
            {
                exitg1 = true;
            }
            else
            {
                i++;
            }
        }

        /* '<S9>:1:63' inputChan = 1; */
        /* '<S9>:1:64' loopCount = loopCount + nInRouterMask; */
        loopCount += 5.0;
    }

    /* End of MATLAB Function: '<S7>/Trivial Translation' */
}

/* System initialize for atomic system: '<Root>/InputSelect' */
void Model_TranslationEngine64_InputSelect_Init(void)
{
    /* user code (Initialize function Body) */

    // Register translation engine among the model roots
    Model_TranslationEngine64_InitializeTranslationRoot();
}

/* Output and update for function-call system: '<S26>/tfunc' */
void FuncTranslation_Model_117_21_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S24>/Subsystem' */
    /* SignalConversion generated from: '<S25>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S27>:1' */
    /* '<S27>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ek =
        Model_TranslationEngine64_B.TwoDowngrade.Value;

    /* End of Outputs for SubSystem: '<S24>/Subsystem' */
}

/* Function for MATLAB Function: '<S28>/TableFormatting' */
static boolean_T Model_TranslationEngine64_sortLE(const real32_T v_data[],
    int32_T idx1, int32_T idx2)
{
    real32_T v1;
    real32_T v2;
    boolean_T p;
    p = true;
    v1 = v_data[idx1 - 1];
    v2 = v_data[idx2 - 1];
    if ((!(v1 == v2)) && (!(rtIsNaNF(v1) && rtIsNaNF(v2))) && (!(v1 <= v2)) && (
            !rtIsNaNF(v2)))
    {
        p = false;
    }

    return p;
}

/* Function for MATLAB Function: '<S28>/TableFormatting' */
static void Model_TranslationEngine64_sortrows(real32_T y_data[], const int32_T
    y_size[2])
{
    int32_T idx_data[16];
    int32_T iwork_data[16];
    int32_T c_i;
    int32_T i2;
    int32_T n;
    int32_T pEnd;
    real32_T ycol_data[16];
    static const int32_T offsets[4] =
    {
        0, 1, 2, 3
    };

    n = y_size[0] + 1;
    c_i = y_size[0];
    if (c_i - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)c_i * sizeof(int32_T));
    }

    if (y_size[0] == 0)
    {
        c_i = y_size[0];
        pEnd = (y_size[0] / 4) << 2;
        i2 = pEnd - 4;
        for (n = 0; n <= i2; n += 4)
        {
            _mm_storeu_si128((__m128i *)&idx_data[n], _mm_add_epi32
                             (_mm_add_epi32(_mm_set1_epi32(n), _mm_loadu_si128((
                                 const __m128i *)&offsets[0])), _mm_set1_epi32(1)));
        }

        for (n = pEnd; n < c_i; n++)
        {
            idx_data[n] = n + 1;
        }
    }
    else
    {
        i2 = y_size[0] - 1;
        for (c_i = 1; c_i <= i2; c_i += 2)
        {
            if (Model_TranslationEngine64_sortLE(y_data, c_i, c_i + 1))
            {
                idx_data[c_i - 1] = c_i;
                idx_data[c_i] = c_i + 1;
            }
            else
            {
                idx_data[c_i - 1] = c_i + 1;
                idx_data[c_i] = c_i;
            }
        }

        if (((uint32_T)y_size[0] & 1U) != 0U)
        {
            idx_data[y_size[0] - 1] = y_size[0];
        }

        c_i = 2;
        while (c_i < n - 1)
        {
            int32_T b_j;
            i2 = c_i << 1;
            b_j = 1;
            pEnd = c_i + 1;
            while (pEnd < n)
            {
                int32_T b_k;
                int32_T kEnd;
                int32_T p;
                int32_T q;
                int32_T qEnd;
                p = b_j;
                q = pEnd;
                qEnd = b_j + i2;
                if (qEnd > n)
                {
                    qEnd = n;
                }

                b_k = 0;
                kEnd = qEnd - b_j;
                while (b_k + 1 <= kEnd)
                {
                    int32_T scalarLB_tmp;
                    int32_T tmp;
                    scalarLB_tmp = idx_data[q - 1];
                    tmp = idx_data[p - 1];
                    if (Model_TranslationEngine64_sortLE(y_data, tmp,
                            scalarLB_tmp))
                    {
                        iwork_data[b_k] = tmp;
                        p++;
                        if (p == pEnd)
                        {
                            while (q < qEnd)
                            {
                                b_k++;
                                iwork_data[b_k] = idx_data[q - 1];
                                q++;
                            }
                        }
                    }
                    else
                    {
                        iwork_data[b_k] = scalarLB_tmp;
                        q++;
                        if (q == qEnd)
                        {
                            while (p < pEnd)
                            {
                                b_k++;
                                iwork_data[b_k] = idx_data[p - 1];
                                p++;
                            }
                        }
                    }

                    b_k++;
                }

                for (pEnd = 0; pEnd < kEnd; pEnd++)
                {
                    idx_data[(b_j + pEnd) - 1] = iwork_data[pEnd];
                }

                b_j = qEnd;
                pEnd = qEnd + c_i;
            }

            c_i = i2;
        }
    }

    c_i = y_size[0] - 1;
    for (n = 0; n < 2; n++)
    {
        for (i2 = 0; i2 <= c_i; i2++)
        {
            ycol_data[i2] = y_data[(y_size[0] * n + idx_data[i2]) - 1];
        }

        for (i2 = 0; i2 <= c_i; i2++)
        {
            y_data[i2 + y_size[0] * n] = ycol_data[i2];
        }
    }
}

/* Function for MATLAB Function: '<S28>/TableFormatting' */
static void Model_TranslationEngine64_unique_vector_d(const real32_T a_data[],
    const int32_T *a_size, real32_T b_data[], int32_T *b_size, int32_T ndx_data[],
    int32_T *ndx_size)
{
    int32_T idx_data[18];
    int32_T iwork_data[18];
    int32_T b_j;
    int32_T i;
    int32_T i2;
    int32_T kEnd;
    int32_T n;
    int32_T pEnd;
    int32_T qEnd;
    real32_T x;
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
            if ((a_data[i2 - 1] <= a_data[i2]) || rtIsNaNF(a_data[i2]))
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
                    if ((a_data[b_tmp_tmp - 1] <= x) || rtIsNaNF(x))
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
    while ((b_j + 1 <= *a_size) && rtIsInfF(b_data[b_j]) && (b_data[b_j] < 0.0F))
    {
        b_j++;
    }

    n = b_j;
    b_j = *a_size;
    while ((b_j >= 1) && rtIsNaNF(b_data[b_j - 1]))
    {
        b_j--;
    }

    i = *a_size - b_j;
    exitg1 = false;
    while ((!exitg1) && (b_j >= 1))
    {
        x = b_data[b_j - 1];
        if (rtIsInfF(x) && (x > 0.0F))
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

/* Function for MATLAB Function: '<S28>/TableFormatting' */
static void Model_TranslationEngine64_do_vectors(const real_T a_data[], const
    int32_T a_size[2], const real_T b_data[], const int32_T *b_size, real_T
    c_data[], int32_T c_size[2], int32_T ia_data[], int32_T *ia_size, int32_T
    *ib_size)
{
    int32_T iafirst;
    int32_T ialast;
    int32_T iblast;
    int32_T na;
    int32_T nc;
    int32_T nia;
    na = a_size[1];
    c_size[0] = 1;
    c_size[1] = a_size[1];
    *ia_size = a_size[1];
    *ib_size = 0;
    nc = 0;
    nia = 0;
    iafirst = 0;
    ialast = 0;
    iblast = 1;
    while ((ialast + 1 <= na) && (iblast <= *b_size))
    {
        real_T ak;
        real_T bk;
        int32_T b_ialast;
        b_ialast = ialast + 1;
        ak = a_data[ialast];
        while ((b_ialast < a_size[1]) && (a_data[b_ialast] == ak))
        {
            b_ialast++;
        }

        ialast = b_ialast - 1;
        bk = b_data[iblast - 1];
        while ((iblast < *b_size) && (b_data[iblast] == bk))
        {
            iblast++;
        }

        if (ak == bk)
        {
            ialast = b_ialast;
            iafirst = b_ialast;
            iblast++;
        }
        else if (ak < bk)
        {
            nc++;
            nia++;
            c_data[nc - 1] = ak;
            ia_data[nia - 1] = iafirst + 1;
            ialast = b_ialast;
            iafirst = b_ialast;
        }
        else
        {
            iblast++;
        }
    }

    while (ialast + 1 <= na)
    {
        iblast = ialast + 1;
        while ((iblast < a_size[1]) && (a_data[iblast] == a_data[ialast]))
        {
            iblast++;
        }

        nc++;
        nia++;
        c_data[nc - 1] = a_data[ialast];
        ia_data[nia - 1] = iafirst + 1;
        ialast = iblast;
        iafirst = iblast;
    }

    if (a_size[1] > 0)
    {
        if (nia < 1)
        {
            *ia_size = 0;
        }
        else
        {
            *ia_size = nia;
        }

        if (nc < 1)
        {
            c_size[1] = 0;
        }
        else
        {
            c_size[1] = nc;
        }
    }
}

/* Function for MATLAB Function: '<S28>/TableFormatting' */
static boolean_T Model_TranslationEngine64_any(const boolean_T x_data[], const
    int32_T *x_size)
{
    int32_T ix;
    boolean_T exitg1;
    boolean_T y;
    y = false;
    ix = 1;
    exitg1 = false;
    while ((!exitg1) && (ix <= *x_size))
    {
        if (x_data[ix - 1])
        {
            y = true;
            exitg1 = true;
        }
        else
        {
            ix++;
        }
    }

    return y;
}

/* Output and update for function-call system: '<S30>/tfunc' */
void FuncTranslation_Model_117_1781(void)
{
    real_T a_data[18];
    real_T duplicateIdx_data[18];
    real_T idxUnique_data[18];
    int32_T indx_data[18];
    int32_T i;
    int32_T ixLead;
    int32_T iyLead;
    int32_T loop_ub;
    real32_T table_data[36];
    real32_T updatedTable_data[36];
    real32_T w_data[32];
    real32_T fanSettingUnique_data[18];
    real32_T table_data_0[18];
    real32_T b_y1_data[15];
    real32_T tmp1;
    char_T p_data[135];
    char_T k_data[70];
    char_T m_data[66];
    char_T o_data[54];
    char_T n_data[53];
    char_T l_data[20];
    int8_T j_data[18];
    boolean_T x_data[18];
    boolean_T isNoiseIncreasing;
    static const char_T q[70] =
        "Error in %s: Noise values must increase with increase in fan current.";
    static const char_T r[20] = "AudioPilot 3.5 HVAC";
    static const char_T s[66] =
        "Error in %s: Noise table must have atleast 2 unique fan settings.";
    static const char_T t[53] =
        "Error in %s: Noise table cannot be longer than [%d].";
    static const char_T u[54] =
        "Error in %s: Fan setting needs to be between 0 and 1.";
    static const char_T v[135] =
        "Error in %s: Fan settings [%f] corresponds to multiple noise values. Ensure that each fan setting corresponds only to one noise "
        "value.";
    int32_T a_size[2];
    int32_T w_size[2];
    int32_T fanSettingUnique_size;
    int32_T idxUnique_size;
    int32_T table_size_idx_0;
    int32_T table_size_idx_0_tmp;
    real32_T work_data_idx_0;
    boolean_T exitg1;
    boolean_T guard1 = false;

    /* MATLAB Function: '<S28>/TableFormatting' */
    /* MATLAB Function: '<S28>/TableFormatting' incorporates:
     *  S-Function (TuneVarMEX): '<S28>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S31>:1' */
    /* '<S31>:1:3' f(); */
    /*  "table": Table containing noise values corresponding to different HVAC */
    /*  settings. Column 1 contains the 'HVAC Setting' and varies from */
    /*  [0,1.0]. Column 2 contains the corresponding 'HVAC noise' values. */
    /*  Error checks for the HVAC table: */
    /*  1. Column1 must have atleast 2 unique values. */
    /*  2. Each unique value in column 1 can correspond to only one noise value. */
    /*     Example- An HVAC setting of 0.5 cannot correspond to both 60 dBSPL and 70 dBSPL. */
    /*  3. If there are duplicate pairs in the table, only one is retained. */
    /*  4. Column2 values are expected to either increase with an increase in HVAC setting or remain constant. */
    /*     Example - The noise corresponding to an HVAC setting of 1.0 must be  */
    /*     higher than or equal to that of 0.5. */
    /*  5. If the table does not contain the entries for HVAC settings 0.0 or */
    /*     1.0, they are added in the translation so that the interpolation */
    /*     can handle any incoming control messages in the range [0.0, 1.0]. */
    /*     Example - [0.5,70 ;  */
    /*  6. Size restrictions - the table must have 2 columns and <= MaskHvacTableSize rows.     */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/ConfigurationRtcInputs/Hvac/table/TableFormatting': '<S29>:1' */
    /*  "tableTOP": Output table [16x2] after performing checks */
    /* '<S29>:1:23' argName = 'AudioPilot 3.5 HVAC'; */
    /* '<S29>:1:24' tableTOP = zeros(MaskHvacTableSize,2,'single'); */
    memset(&Model_TranslationEngine64_B.tableTOP[0], 0, sizeof(real32_T) << 5U);

    /* '<S29>:1:25' numEntries = table.Size(1); */
    /* '<S29>:1:26' table = table.Value(1:numEntries,:); */
    /*  Sort the table with respect to the fan setting (ascending).  */
    /*  Ensure that the corresponding noise values are also in the ascending  */
    /*  order by checking if the difference between consecutive elements is  */
    /*  always non negative. */
    /* '<S29>:1:32' table = sortrows(table,1); */
    if (Model_TranslationEngine64_B.HvacTable.Size[0] < 1.0)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = (int32_T)Model_TranslationEngine64_B.HvacTable.Size[0] - 1;
    }

    w_size[0] = loop_ub + 1;
    w_size[1] = 2;
    for (iyLead = 0; iyLead < 2; iyLead++)
    {
        for (ixLead = 0; ixLead <= loop_ub; ixLead++)
        {
            w_data[ixLead + (loop_ub + 1) * iyLead] =
                Model_TranslationEngine64_B.HvacTable.Value[(iyLead << 4) +
                ixLead];
        }
    }

    Model_TranslationEngine64_sortrows(w_data, w_size);
    table_size_idx_0 = w_size[0];
    loop_ub = w_size[0] << 1;
    if (loop_ub - 1 >= 0)
    {
        memcpy(&table_data[0], &w_data[0], (uint32_T)loop_ub * sizeof(real32_T));
    }

    /* '<S29>:1:33' isNoiseIncreasing = all(diff(table(:,2)) >= 0); */
    i = w_size[0] - 1;
    if (w_size[0] == 0)
    {
        ixLead = 0;
    }
    else
    {
        if (w_size[0] - 1 <= 1)
        {
            iyLead = w_size[0] - 1;
        }
        else
        {
            iyLead = 1;
        }

        if (iyLead < 1)
        {
            ixLead = 0;
        }
        else
        {
            ixLead = (int8_T)(w_size[0] - 1);
            if ((int8_T)(w_size[0] - 1) != 0)
            {
                work_data_idx_0 = w_data[w_size[0]];
                for (loop_ub = 2; loop_ub <= i + 1; loop_ub++)
                {
                    tmp1 = w_data[(loop_ub + w_size[0]) - 1];
                    b_y1_data[loop_ub - 2] = tmp1 - work_data_idx_0;
                    work_data_idx_0 = tmp1;
                }
            }
        }
    }

    for (iyLead = 0; iyLead < ixLead; iyLead++)
    {
        x_data[iyLead] = (b_y1_data[iyLead] >= 0.0F);
    }

    isNoiseIncreasing = true;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= ixLead))
    {
        if (!x_data[i - 1])
        {
            isNoiseIncreasing = false;
            exitg1 = true;
        }
        else
        {
            i++;
        }
    }

    /* '<S29>:1:34' if ~isNoiseIncreasing */
    if (!isNoiseIncreasing)
    {
        /* '<S29>:1:35' TranslateError('Error in %s: Noise values must increase with increase in fan current.',argName); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&k_data[0], &q[0], 70U * sizeof(char_T));
        for (iyLead = 0; iyLead < 20; iyLead++)
        {
            l_data[iyLead] = r[iyLead];
        }

        TranslateError(&k_data[0], &l_data[0]);
    }

    /*  Ensure that the lowest fan setting is 0 and the highest is 1.0 for */
    /*  the interpolation to work. Using an intermediate variable to add the */
    /*  new row. */
    /* '<S29>:1:41' if table(1,1) ~= single(0.0) */
    if (w_data[0] != 0.0F)
    {
        /* '<S29>:1:42' numRows = size(table,1) + 1; */
        /* '<S29>:1:43' updatedTable = zeros(numRows,2,'single'); */
        table_size_idx_0_tmp = w_size[0] + 1;
        table_size_idx_0 = w_size[0] + 1;
        loop_ub = (w_size[0] + 1) << 1;
        memset(&table_data[0], 0, (uint32_T)loop_ub * sizeof(real32_T));

        /* '<S29>:1:44' updatedTable(1,1) = 0.0; */
        table_data[0] = 0.0F;

        /* '<S29>:1:45' updatedTable(1,2) = table(1,2); */
        table_data[w_size[0] + 1] = w_data[w_size[0]];

        /* '<S29>:1:46' updatedTable(2:numRows,:) = table; */
        if (w_size[0] + 1 < 2)
        {
            i = 0;
        }
        else
        {
            i = 1;
        }

        loop_ub = w_size[0];
        for (iyLead = 0; iyLead < 2; iyLead++)
        {
            for (ixLead = 0; ixLead < loop_ub; ixLead++)
            {
                table_data[(i + ixLead) + table_size_idx_0_tmp * iyLead] =
                    w_data[w_size[0] * iyLead + ixLead];
            }
        }

        /* '<S29>:1:47' table = updatedTable; */
    }

    /* '<S29>:1:49' if table(end,1) ~= single(1.0) */
    if (table_data[table_size_idx_0 - 1] != 1.0F)
    {
        /* '<S29>:1:50' numRows = size(table,1) + 1; */
        /* '<S29>:1:51' updatedTable = zeros(numRows,2,'single'); */
        i = table_size_idx_0 + 1;
        memset(&updatedTable_data[0], 0, (uint32_T)((table_size_idx_0 + 1) << 1)
               * sizeof(real32_T));

        /* '<S29>:1:52' updatedTable(numRows,1) = 1.0; */
        updatedTable_data[table_size_idx_0] = 1.0F;

        /* '<S29>:1:53' updatedTable(numRows,2) = table(numRows-1,2); */
        updatedTable_data[(table_size_idx_0 + table_size_idx_0) + 1] =
            table_data[(table_size_idx_0 + table_size_idx_0) - 1];

        /* '<S29>:1:54' updatedTable(1:numRows-1,:) = table; */
        for (iyLead = 0; iyLead < 2; iyLead++)
        {
            for (ixLead = 0; ixLead < table_size_idx_0; ixLead++)
            {
                updatedTable_data[ixLead + (table_size_idx_0 + 1) * iyLead] =
                    table_data[table_size_idx_0 * iyLead + ixLead];
            }
        }

        /* '<S29>:1:55' table = updatedTable; */
        table_size_idx_0++;
        memcpy(&table_data[0], &updatedTable_data[0], (uint32_T)(i << 1) *
               sizeof(real32_T));
    }

    /* '<S29>:1:57' fanSetting = table(:,1); */
    /* '<S29>:1:58' noise = table(:,2); */
    /* '<S29>:1:59' numEntries = numel(fanSetting); */
    /*  Check for unique indexes in fan settings. If a fan setting has a */
    /*  duplicate, check if the corresponding noise values are the same. If */
    /*  they are the same, then only one pair is retained and the others */
    /*  discarded. If they are different, an error is thrown as one fan */
    /*  setting cannot correspond to multiple noise values. */
    /* '<S29>:1:66' [fanSettingUnique,idxUnique] = unique(fanSetting); */
    iyLead = table_size_idx_0;
    if (table_size_idx_0 - 1 >= 0)
    {
        memcpy(&table_data_0[0], &table_data[0], (uint32_T)table_size_idx_0 *
               sizeof(real32_T));
    }

    Model_TranslationEngine64_unique_vector_d(table_data_0, &table_size_idx_0,
        fanSettingUnique_data, &fanSettingUnique_size, indx_data, &loop_ub);
    idxUnique_size = loop_ub;
    for (iyLead = 0; iyLead < loop_ub; iyLead++)
    {
        idxUnique_data[iyLead] = indx_data[iyLead];
    }

    /* '<S29>:1:67' duplicateIdx = setdiff(1:numEntries,idxUnique); */
    if (table_size_idx_0 < 1)
    {
        a_size[0] = 1;
        a_size[1] = 0;
    }
    else
    {
        a_size[0] = 1;
        a_size[1] = table_size_idx_0;
        loop_ub = table_size_idx_0 - 1;
        for (iyLead = 0; iyLead <= loop_ub; iyLead++)
        {
            a_data[iyLead] = (real_T)iyLead + 1.0;
        }
    }

    Model_TranslationEngine64_do_vectors(a_data, a_size, idxUnique_data,
        &idxUnique_size, duplicateIdx_data, w_size, indx_data, &loop_ub, &iyLead);

    /* '<S29>:1:69' for i = 1:numel(duplicateIdx) */
    i = w_size[1];
    for (ixLead = 0; ixLead < i; ixLead++)
    {
        int32_T j_size_idx_0;

        /* '<S29>:1:70' currFanSetting = fanSetting(duplicateIdx(i)); */
        tmp1 = table_data[(int32_T)duplicateIdx_data[ixLead] - 1];

        /* '<S29>:1:71' dupNoise = noise( fanSetting == currFanSetting ); */
        /* '<S29>:1:72' IsCorrespondingNoiseEqual = all(dupNoise == dupNoise(1)); */
        iyLead = table_size_idx_0 - 1;
        loop_ub = 0;
        for (table_size_idx_0_tmp = 0; table_size_idx_0_tmp <= iyLead;
                table_size_idx_0_tmp++)
        {
            if (table_data[table_size_idx_0_tmp] == tmp1)
            {
                loop_ub++;
            }
        }

        j_size_idx_0 = loop_ub;
        loop_ub = 0;
        for (table_size_idx_0_tmp = 0; table_size_idx_0_tmp <= iyLead;
                table_size_idx_0_tmp++)
        {
            if (table_data[table_size_idx_0_tmp] == tmp1)
            {
                j_data[loop_ub] = (int8_T)(table_size_idx_0_tmp + 1);
                loop_ub++;
            }
        }

        work_data_idx_0 = table_data[(j_data[0] + table_size_idx_0) - 1];
        for (iyLead = 0; iyLead < j_size_idx_0; iyLead++)
        {
            x_data[iyLead] = (table_data[(j_data[iyLead] + table_size_idx_0) - 1]
                              == work_data_idx_0);
        }

        isNoiseIncreasing = true;
        iyLead = 1;
        exitg1 = false;
        while ((!exitg1) && (iyLead <= j_size_idx_0))
        {
            if (!x_data[iyLead - 1])
            {
                isNoiseIncreasing = false;
                exitg1 = true;
            }
            else
            {
                iyLead++;
            }
        }

        /* '<S29>:1:73' if IsCorrespondingNoiseEqual ~= 1 */
        if (!isNoiseIncreasing)
        {
            /* '<S29>:1:74' TranslateError('Error in %s: Fan settings [%f] corresponds to multiple noise values. Ensure that each fan setting corresponds only to one noise value.',argName,currFanSetting); */
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
            memcpy(&p_data[0], &v[0], 135U * sizeof(char_T));
            for (iyLead = 0; iyLead < 20; iyLead++)
            {
                l_data[iyLead] = r[iyLead];
            }

            TranslateError(&p_data[0], &l_data[0], tmp1);
        }
    }

    /* '<S29>:1:78' numEntriesUnique = numel(fanSettingUnique); */
    /* '<S29>:1:79' noiseUnique = noise(idxUnique); */
    /*  Number of table entries needs to be atleast 2 for the interp1 function to */
    /*  work and less than equal to MaskHvacTableSize. The fan setting can */
    /*  only be in the range [0,1.0]. */
    /* '<S29>:1:84' if (numEntriesUnique < 2) */
    if (fanSettingUnique_size < 2)
    {
        /* '<S29>:1:85' TranslateError('Error in %s: Noise table must have atleast 2 unique fan settings.',argName); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&m_data[0], &s[0], 66U * sizeof(char_T));
        for (iyLead = 0; iyLead < 20; iyLead++)
        {
            l_data[iyLead] = r[iyLead];
        }

        TranslateError(&m_data[0], &l_data[0]);
    }

    /* '<S29>:1:87' if (numEntriesUnique > MaskHvacTableSize) */
    if (fanSettingUnique_size > 16)
    {
        /* '<S29>:1:88' TranslateError('Error in %s: Noise table cannot be longer than [%d].', argName,MaskHvacTableSize); */
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
        for (iyLead = 0; iyLead < 53; iyLead++)
        {
            n_data[iyLead] = t[iyLead];
        }

        for (iyLead = 0; iyLead < 20; iyLead++)
        {
            l_data[iyLead] = r[iyLead];
        }

        TranslateError(&n_data[0], &l_data[0], 16.0);
    }

    /* '<S29>:1:90' if (any(fanSetting > 1) || any(fanSetting < 0)) */
    for (iyLead = 0; iyLead < table_size_idx_0; iyLead++)
    {
        x_data[iyLead] = (table_data[iyLead] > 1.0F);
    }

    guard1 = false;
    if (Model_TranslationEngine64_any(x_data, &table_size_idx_0))
    {
        guard1 = true;
    }
    else
    {
        for (iyLead = 0; iyLead < table_size_idx_0; iyLead++)
        {
            x_data[iyLead] = (table_data[iyLead] < 0.0F);
        }

        if (Model_TranslationEngine64_any(x_data, &table_size_idx_0))
        {
            guard1 = true;
        }
    }

    if (guard1)
    {
        /* '<S29>:1:91' TranslateError('Error in %s: Fan setting needs to be between 0 and 1.', argName); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (iyLead = 0; iyLead < 54; iyLead++)
        {
            o_data[iyLead] = u[iyLead];
        }

        for (iyLead = 0; iyLead < 20; iyLead++)
        {
            l_data[iyLead] = r[iyLead];
        }

        TranslateError(&o_data[0], &l_data[0]);
    }

    /*  Create the output TOP matrix  */
    /* '<S29>:1:95' tableTOP(1:numEntriesUnique,1) = fanSettingUnique; */
    if (fanSettingUnique_size - 1 >= 0)
    {
        memcpy(&Model_TranslationEngine64_B.tableTOP[0], &fanSettingUnique_data
               [0], (uint32_T)fanSettingUnique_size * sizeof(real32_T));
    }

    /* '<S29>:1:96' tableTOP(1:numEntriesUnique,2) = noiseUnique; */
    for (iyLead = 0; iyLead < idxUnique_size; iyLead++)
    {
        Model_TranslationEngine64_B.tableTOP[iyLead + 16] = table_data[((int32_T)
            idxUnique_data[iyLead] + table_size_idx_0) - 1];
    }

    /* End of MATLAB Function: '<S28>/TableFormatting' */
}

/* Output and update for function-call system: '<S38>/tfunc' */
void FuncTranslation_Model_117_43_332(void)
{
    real32_T wc;

    /* MATLAB Function: '<S33>/Frequency2Coefficients' */
    /* MATLAB Function: '<S33>/Frequency2Coefficients' incorporates:
     *  S-Function (TuneVarMEX): '<S33>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S39>:1' */
    /* '<S39>:1:3' f(); */
    /*  Forms the numerator and denominator coefficients */
    /*  for a first order filter with the specified */
    /*  corner frequency */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainApplication/Compensation/AntizipperRampLpf/Frequency2Coefficients': '<S37>:1' */
    /* '<S37>:1:8' wc = 2 * pi * Freq.Value / SampleRate; */
    wc = 6.28318548F * Model_TranslationEngine64_B.AntiZipperRampFreqHz.Value /
        44307.6914F;

    /* '<S37>:1:9' Coef = (1 - sin(wc)) / cos(wc); */
    wc = (1.0F - sinf(wc)) / cosf(wc);

    /* '<S37>:1:11' num = 1-Coef ; */
    Model_TranslationEngine64_B.num_e = 1.0F - wc;

    /* '<S37>:1:12' denom = [1 -Coef]; */
    Model_TranslationEngine64_B.denom_b[0] = 1.0F;
    Model_TranslationEngine64_B.denom_b[1] = -wc;
}

/* Output and update for function-call system: '<S40>/tfunc' */
void FuncTranslation_Model_117_43_351(void)
{
    real_T tmp;
    real32_T num_g_tmp;
    real32_T num_g_tmp_tmp;
    real32_T sinCoef;
    real32_T wc;

    /* MATLAB Function: '<S34>/wcQ2coefs' */
    /* MATLAB Function: '<S34>/wcQ2coefs' incorporates:
     *  S-Function (TuneVarMEX): '<S34>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S34>/Tune Variable1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S42>:1' */
    /* '<S42>:1:3' f(); */
    /*  Forms the numerator and denominator coefficients */
    /*  for a second-order band-pass filter with  */
    /*  the specified cutoff frequency and Q value */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainApplication/Compensation/BassBpf/wcQ2coefs': '<S41>:1' */
    /* '<S41>:1:9' Fc = freq.Value; */
    /* '<S41>:1:10' Q = Qin.Value; */
    /*  The frequency in radians */
    /* '<S41>:1:13' wc = 2 * pi * Fc / SampleRate; */
    wc = 6.28318548F * Model_TranslationEngine64_B.BassBpfCenterFreqHz.Value /
        44307.6914F;

    /* '<S41>:1:14' sinCoef = sin(wc); */
    sinCoef = sinf(wc);

    /* '<S41>:1:15' cosCoef = cos(wc); */
    /* '<S41>:1:17' sos = [0 0 0]; */
    /* '<S41>:1:18' sos(1) = (2*Q - sinCoef)/(2*Q + sinCoef); */
    /* '<S41>:1:19' sos(2) = -4*Q*cosCoef/(2*Q + sinCoef); */
    /* '<S41>:1:20' sos(3) = sinCoef/(2*Q + sinCoef); */
    num_g_tmp_tmp = 2.0F * Model_TranslationEngine64_B.BassBpfQ.Value;
    num_g_tmp = num_g_tmp_tmp + sinCoef;
    Model_TranslationEngine64_B.num_g[2] = sinCoef / num_g_tmp;

    /* '<S41>:1:22' num = sos(3)*[1 0 -1]; */
    tmp = Model_TranslationEngine64_B.num_g[2];
    Model_TranslationEngine64_B.num_g[0] = tmp;
    Model_TranslationEngine64_B.num_g[1] = tmp * 0.0;
    Model_TranslationEngine64_B.num_g[2] = -tmp;

    /* '<S41>:1:23' denom = [1 sos(2) sos(1)]; */
    Model_TranslationEngine64_B.denom_e[0] = 1.0;
    Model_TranslationEngine64_B.denom_e[1] = -4.0F *
        Model_TranslationEngine64_B.BassBpfQ.Value * cosf(wc) / num_g_tmp;
    Model_TranslationEngine64_B.denom_e[2] = (num_g_tmp_tmp - sinCoef) /
        num_g_tmp;
}

/* Output and update for function-call system: '<S44>/tfunc' */
void FuncTranslation_Model_117_43_340(void)
{
    creal_T c[5];
    creal_T P[4];
    real_T pj[5];
    real_T re;
    real_T x_idx_0_im;
    real_T x_idx_0_re;
    real_T x_idx_1_im;
    real_T x_idx_1_re;
    real_T x_idx_2_im;
    real_T x_idx_2_re;
    real_T x_idx_3_im;
    real_T x_idx_3_re;
    int32_T b_k;
    int32_T n;
    real32_T bim;
    real32_T brm;
    real32_T frequency;
    real32_T g_im;
    real32_T g_im_0;
    real32_T g_re;
    real32_T g_re_0;
    real32_T sp_im;
    real32_T sp_im_0;
    real32_T sp_im_tmp;
    real32_T sp_re;
    real32_T sp_re_tmp;
    real32_T sp_re_tmp_tmp;

    /* MATLAB Function: '<S35>/LinkwitzRiley' */
    /* MATLAB Function: '<S35>/LinkwitzRiley' incorporates:
     *  S-Function (TuneVarMEX): '<S35>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S45>:1' */
    /* '<S45>:1:3' f(); */
    /*  Forms the numerator and denominator coefficients */
    /*  for a 4th order Linkwitz-Riley low-pass filter with  */
    /*  the specified cutoff frequency  */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainApplication/Compensation/MidrangeLpf/LinkwitzRiley': '<S43>:1' */
    /* '<S43>:1:7' Fc = freq.Value; */
    /* '<S43>:1:8' FiltOrder = 4; */
    /*  This is hard-coded */
    /* '<S43>:1:10' [Z,P,K] = LinkwitzRileyFiltDesign(FiltOrder,Fc/(SampleRate/2),'low'); */
    frequency = Model_TranslationEngine64_B.MidrangeLpfCutoffFreqHz.Value /
        22153.8457F;

    /* LinkwitzRileyFiltDesign: Our own function designing a Linkwitz Riley Filter */
    /*    [z,p,k] = LinkRitzRileyFiltDesign(order,frequency,type) */
    /*    This function returns the zeros-pole-gain (ZPK) form of the filter */
    /*    Arguments: */
    /*        order - order of filter, must be even */
    /*        frequency - cutoff frequency */
    /*        type - "high" for high-pass, "low" for low-pass */
    /* 'LinkwitzRileyFiltDesign:10' if (mod(order,2) ~= 0) */
    /*  Zeros first */
    /* 'LinkwitzRileyFiltDesign:15' z = zeros(order,1); */
    /* 'LinkwitzRileyFiltDesign:16' if strcmp(type,'high') */
    /* 'LinkwitzRileyFiltDesign:18' elseif strcmp(type,'low') */
    /* 'LinkwitzRileyFiltDesign:19' z(1:order) = -1*ones(order,1); */
    /*  Next the poles */
    /* 'LinkwitzRileyFiltDesign:25' p = complex(zeros(order,1)); */
    /* 'LinkwitzRileyFiltDesign:26' halfOrder = order/2; */
    /*  The poles are the same as those of Butterworth filters, */
    /*  but each pole is duplicated (or doubled) */
    /* 'LinkwitzRileyFiltDesign:30' for n = 1:halfOrder */
    /* 'LinkwitzRileyFiltDesign:31' if n == (halfOrder+1)/2 */
    /* 'LinkwitzRileyFiltDesign:33' else */
    /* 'LinkwitzRileyFiltDesign:34' sp_real = pi*frequency*cos(((2*n+halfOrder-1)*pi)/(2*halfOrder)); */
    /* 'LinkwitzRileyFiltDesign:35' sp_imag = pi*frequency*sin(((2*n+halfOrder-1)*pi)/(2*halfOrder)); */
    /* 'LinkwitzRileyFiltDesign:36' sp = sp_real + 1i*sp_imag; */
    sp_re_tmp = 3.14159274F * frequency * -0.707106769F;
    sp_im_0 = 3.14159274F * frequency * 0.707106769F;

    /* 'LinkwitzRileyFiltDesign:38' p(2*n-1) = (1+sp/2)/(1-sp/2); */
    if (sp_im_0 == 0.0F)
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_tmp = 0.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im = 0.0F;
    }
    else if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = 0.0F;
        sp_im_tmp = sp_im_0 / 2.0F;
        sp_re = 0.0F;
        sp_im = sp_im_tmp;
    }
    else
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_tmp = sp_im_0 / 2.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im = sp_im_tmp;
    }

    if (0.0F - sp_im == 0.0F)
    {
        if (sp_im_tmp == 0.0F)
        {
            frequency = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            sp_im = 0.0F;
        }
        else if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            frequency = 0.0F;
            sp_im = sp_im_tmp / (1.0F - sp_re);
        }
        else
        {
            frequency = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            sp_im = sp_im_tmp / (1.0F - sp_re);
        }
    }
    else if (1.0F - sp_re == 0.0F)
    {
        if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            frequency = sp_im_tmp / (0.0F - sp_im);
            sp_im = 0.0F;
        }
        else if (sp_im_tmp == 0.0F)
        {
            frequency = 0.0F;
            sp_im = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im));
        }
        else
        {
            frequency = sp_im_tmp / (0.0F - sp_im);
            sp_im = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im));
        }
    }
    else
    {
        brm = fabsf(1.0F - sp_re);
        bim = fabsf(0.0F - sp_im);
        if (brm > bim)
        {
            brm = (0.0F - sp_im) / (1.0F - sp_re);
            sp_re = (0.0F - sp_im) * brm + (1.0F - sp_re);
            frequency = ((sp_re_tmp_tmp + 1.0F) + brm * sp_im_tmp) / sp_re;
            sp_im = (sp_im_tmp - (sp_re_tmp_tmp + 1.0F) * brm) / sp_re;
        }
        else if (bim == brm)
        {
            sp_re = 1.0F - sp_re > 0.0F ? 0.5F : -0.5F;
            bim = 0.0F - sp_im > 0.0F ? 0.5F : -0.5F;
            frequency = ((sp_re_tmp_tmp + 1.0F) * sp_re + sp_im_tmp * bim) / brm;
            sp_im = (sp_im_tmp * sp_re - (sp_re_tmp_tmp + 1.0F) * bim) / brm;
        }
        else
        {
            brm = (1.0F - sp_re) / (0.0F - sp_im);
            sp_re = (1.0F - sp_re) * brm + (0.0F - sp_im);
            frequency = ((sp_re_tmp_tmp + 1.0F) * brm + sp_im_tmp) / sp_re;
            sp_im = (brm * sp_im_tmp - (sp_re_tmp_tmp + 1.0F)) / sp_re;
        }
    }

    P[0].re = frequency;
    P[0].im = sp_im;

    /* 'LinkwitzRileyFiltDesign:39' p(2*n) = (1+sp/2)/(1-sp/2); */
    if (sp_im_0 == 0.0F)
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_tmp = 0.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im_0 = 0.0F;
    }
    else if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = 0.0F;
        sp_im_tmp = sp_im_0 / 2.0F;
        sp_re = 0.0F;
        sp_im_0 /= 2.0F;
    }
    else
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_tmp = sp_im_0 / 2.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im_0 /= 2.0F;
    }

    if (0.0F - sp_im_0 == 0.0F)
    {
        if (sp_im_tmp == 0.0F)
        {
            g_re = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            g_im = 0.0F;
        }
        else if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            g_re = 0.0F;
            g_im = sp_im_tmp / (1.0F - sp_re);
        }
        else
        {
            g_re = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            g_im = sp_im_tmp / (1.0F - sp_re);
        }
    }
    else if (1.0F - sp_re == 0.0F)
    {
        if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            g_re = sp_im_tmp / (0.0F - sp_im_0);
            g_im = 0.0F;
        }
        else if (sp_im_tmp == 0.0F)
        {
            g_re = 0.0F;
            g_im = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_0));
        }
        else
        {
            g_re = sp_im_tmp / (0.0F - sp_im_0);
            g_im = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_0));
        }
    }
    else
    {
        brm = fabsf(1.0F - sp_re);
        bim = fabsf(0.0F - sp_im_0);
        if (brm > bim)
        {
            brm = (0.0F - sp_im_0) / (1.0F - sp_re);
            sp_re = (0.0F - sp_im_0) * brm + (1.0F - sp_re);
            g_re = ((sp_re_tmp_tmp + 1.0F) + brm * sp_im_tmp) / sp_re;
            g_im = (sp_im_tmp - (sp_re_tmp_tmp + 1.0F) * brm) / sp_re;
        }
        else if (bim == brm)
        {
            sp_re = 1.0F - sp_re > 0.0F ? 0.5F : -0.5F;
            bim = 0.0F - sp_im_0 > 0.0F ? 0.5F : -0.5F;
            g_re = ((sp_re_tmp_tmp + 1.0F) * sp_re + sp_im_tmp * bim) / brm;
            g_im = (sp_im_tmp * sp_re - (sp_re_tmp_tmp + 1.0F) * bim) / brm;
        }
        else
        {
            brm = (1.0F - sp_re) / (0.0F - sp_im_0);
            sp_re = (1.0F - sp_re) * brm + (0.0F - sp_im_0);
            g_re = ((sp_re_tmp_tmp + 1.0F) * brm + sp_im_tmp) / sp_re;
            g_im = (brm * sp_im_tmp - (sp_re_tmp_tmp + 1.0F)) / sp_re;
        }
    }

    P[1].re = g_re;
    P[1].im = g_im;

    /* 'LinkwitzRileyFiltDesign:31' if n == (halfOrder+1)/2 */
    /* 'LinkwitzRileyFiltDesign:33' else */
    /* 'LinkwitzRileyFiltDesign:34' sp_real = pi*frequency*cos(((2*n+halfOrder-1)*pi)/(2*halfOrder)); */
    /* 'LinkwitzRileyFiltDesign:35' sp_imag = pi*frequency*sin(((2*n+halfOrder-1)*pi)/(2*halfOrder)); */
    /* 'LinkwitzRileyFiltDesign:36' sp = sp_real + 1i*sp_imag; */
    /* 'LinkwitzRileyFiltDesign:38' p(2*n-1) = (1+sp/2)/(1-sp/2); */
    if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_0 = 0.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im_tmp = 0.0F;
    }
    else if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = 0.0F;
        sp_im_0 = sp_re_tmp / 2.0F;
        sp_re = 0.0F;
        sp_im_tmp = sp_im_0;
    }
    else
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_0 = sp_re_tmp_tmp;
        sp_re = sp_re_tmp_tmp;
        sp_im_tmp = sp_re_tmp_tmp;
    }

    if (0.0F - sp_im_tmp == 0.0F)
    {
        if (sp_im_0 == 0.0F)
        {
            g_re_0 = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            g_im_0 = 0.0F;
        }
        else if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            g_re_0 = 0.0F;
            g_im_0 = sp_im_0 / (1.0F - sp_re);
        }
        else
        {
            g_re_0 = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            g_im_0 = sp_im_0 / (1.0F - sp_re);
        }
    }
    else if (1.0F - sp_re == 0.0F)
    {
        if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            g_re_0 = sp_im_0 / (0.0F - sp_im_tmp);
            g_im_0 = 0.0F;
        }
        else if (sp_im_0 == 0.0F)
        {
            g_re_0 = 0.0F;
            g_im_0 = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_tmp));
        }
        else
        {
            g_re_0 = sp_im_0 / (0.0F - sp_im_tmp);
            g_im_0 = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_tmp));
        }
    }
    else
    {
        brm = fabsf(1.0F - sp_re);
        bim = fabsf(0.0F - sp_im_tmp);
        if (brm > bim)
        {
            brm = (0.0F - sp_im_tmp) / (1.0F - sp_re);
            sp_re = (0.0F - sp_im_tmp) * brm + (1.0F - sp_re);
            g_re_0 = ((sp_re_tmp_tmp + 1.0F) + brm * sp_im_0) / sp_re;
            g_im_0 = (sp_im_0 - (sp_re_tmp_tmp + 1.0F) * brm) / sp_re;
        }
        else if (bim == brm)
        {
            sp_re = 1.0F - sp_re > 0.0F ? 0.5F : -0.5F;
            bim = 0.0F - sp_im_tmp > 0.0F ? 0.5F : -0.5F;
            g_re_0 = ((sp_re_tmp_tmp + 1.0F) * sp_re + sp_im_0 * bim) / brm;
            g_im_0 = (sp_im_0 * sp_re - (sp_re_tmp_tmp + 1.0F) * bim) / brm;
        }
        else
        {
            brm = (1.0F - sp_re) / (0.0F - sp_im_tmp);
            sp_re = (1.0F - sp_re) * brm + (0.0F - sp_im_tmp);
            g_re_0 = ((sp_re_tmp_tmp + 1.0F) * brm + sp_im_0) / sp_re;
            g_im_0 = (brm * sp_im_0 - (sp_re_tmp_tmp + 1.0F)) / sp_re;
        }
    }

    P[2].re = g_re_0;
    P[2].im = g_im_0;

    /* 'LinkwitzRileyFiltDesign:39' p(2*n) = (1+sp/2)/(1-sp/2); */
    if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_0 = 0.0F;
        sp_re = sp_re_tmp_tmp;
        sp_im_tmp = 0.0F;
    }
    else if (sp_re_tmp == 0.0F)
    {
        sp_re_tmp_tmp = 0.0F;
        sp_im_0 = sp_re_tmp / 2.0F;
        sp_re = 0.0F;
        sp_im_tmp = sp_im_0;
    }
    else
    {
        sp_re_tmp_tmp = sp_re_tmp / 2.0F;
        sp_im_0 = sp_re_tmp_tmp;
        sp_re = sp_re_tmp_tmp;
        sp_im_tmp = sp_re_tmp_tmp;
    }

    if (0.0F - sp_im_tmp == 0.0F)
    {
        if (sp_im_0 == 0.0F)
        {
            sp_re_tmp = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            sp_im_0 = 0.0F;
        }
        else if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            sp_re_tmp = 0.0F;
            sp_im_0 /= 1.0F - sp_re;
        }
        else
        {
            sp_re_tmp = (sp_re_tmp_tmp + 1.0F) / (1.0F - sp_re);
            sp_im_0 /= 1.0F - sp_re;
        }
    }
    else if (1.0F - sp_re == 0.0F)
    {
        if (sp_re_tmp_tmp + 1.0F == 0.0F)
        {
            sp_re_tmp = sp_im_0 / (0.0F - sp_im_tmp);
            sp_im_0 = 0.0F;
        }
        else if (sp_im_0 == 0.0F)
        {
            sp_re_tmp = 0.0F;
            sp_im_0 = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_tmp));
        }
        else
        {
            sp_re_tmp = sp_im_0 / (0.0F - sp_im_tmp);
            sp_im_0 = -((sp_re_tmp_tmp + 1.0F) / (0.0F - sp_im_tmp));
        }
    }
    else
    {
        brm = fabsf(1.0F - sp_re);
        bim = fabsf(0.0F - sp_im_tmp);
        if (brm > bim)
        {
            brm = (0.0F - sp_im_tmp) / (1.0F - sp_re);
            sp_re = (0.0F - sp_im_tmp) * brm + (1.0F - sp_re);
            sp_re_tmp = ((sp_re_tmp_tmp + 1.0F) + brm * sp_im_0) / sp_re;
            sp_im_0 = (sp_im_0 - (sp_re_tmp_tmp + 1.0F) * brm) / sp_re;
        }
        else if (bim == brm)
        {
            sp_re = 1.0F - sp_re > 0.0F ? 0.5F : -0.5F;
            bim = 0.0F - sp_im_tmp > 0.0F ? 0.5F : -0.5F;
            sp_re_tmp = ((sp_re_tmp_tmp + 1.0F) * sp_re + sp_im_0 * bim) / brm;
            sp_im_0 = (sp_im_0 * sp_re - (sp_re_tmp_tmp + 1.0F) * bim) / brm;
        }
        else
        {
            brm = (1.0F - sp_re) / (0.0F - sp_im_tmp);
            sp_re = (1.0F - sp_re) * brm + (0.0F - sp_im_tmp);
            sp_re_tmp = ((sp_re_tmp_tmp + 1.0F) * brm + sp_im_0) / sp_re;
            sp_im_0 = (brm * sp_im_0 - (sp_re_tmp_tmp + 1.0F)) / sp_re;
        }
    }

    P[3].re = sp_re_tmp;
    P[3].im = sp_im_0;

    /*  Normalization Factor */
    /* 'LinkwitzRileyFiltDesign:43' if strcmp(type,'high') */
    /* 'LinkwitzRileyFiltDesign:45' else */
    /* 'LinkwitzRileyFiltDesign:46' k = real(prod((1-p(1:order))/2)); */
    if (0.0 - sp_im == 0.0)
    {
        x_idx_0_re = (1.0 - frequency) / 2.0;
        x_idx_0_im = 0.0;
    }
    else if (1.0 - frequency == 0.0)
    {
        x_idx_0_re = 0.0;
        x_idx_0_im = (0.0 - sp_im) / 2.0;
    }
    else
    {
        x_idx_0_re = (1.0 - frequency) / 2.0;
        x_idx_0_im = (0.0 - sp_im) / 2.0;
    }

    if (0.0 - g_im == 0.0)
    {
        x_idx_1_re = (1.0 - g_re) / 2.0;
        x_idx_1_im = 0.0;
    }
    else if (1.0 - g_re == 0.0)
    {
        x_idx_1_re = 0.0;
        x_idx_1_im = (0.0 - g_im) / 2.0;
    }
    else
    {
        x_idx_1_re = (1.0 - g_re) / 2.0;
        x_idx_1_im = (0.0 - g_im) / 2.0;
    }

    if (0.0 - g_im_0 == 0.0)
    {
        x_idx_2_re = (1.0 - g_re_0) / 2.0;
        x_idx_2_im = 0.0;
    }
    else if (1.0 - g_re_0 == 0.0)
    {
        x_idx_2_re = 0.0;
        x_idx_2_im = (0.0 - g_im_0) / 2.0;
    }
    else
    {
        x_idx_2_re = (1.0 - g_re_0) / 2.0;
        x_idx_2_im = (0.0 - g_im_0) / 2.0;
    }

    if (0.0 - sp_im_0 == 0.0)
    {
        x_idx_3_re = (1.0 - sp_re_tmp) / 2.0;
        x_idx_3_im = 0.0;
    }
    else if (1.0 - sp_re_tmp == 0.0)
    {
        x_idx_3_re = 0.0;
        x_idx_3_im = (0.0 - sp_im_0) / 2.0;
    }
    else
    {
        x_idx_3_re = (1.0 - sp_re_tmp) / 2.0;
        x_idx_3_im = (0.0 - sp_im_0) / 2.0;
    }

    re = x_idx_0_re * x_idx_1_re - x_idx_0_im * x_idx_1_im;
    x_idx_0_re = x_idx_0_re * x_idx_1_im + x_idx_0_im * x_idx_1_re;
    re = (re * x_idx_2_re - x_idx_0_re * x_idx_2_im) * x_idx_3_re - (re *
        x_idx_2_im + x_idx_0_re * x_idx_2_re) * x_idx_3_im;

    /* '<S43>:1:11' [num, denom] = zp2tf(Z,P,K); */
    c[0].re = 1.0;
    c[0].im = 0.0;
    for (n = 0; n < 4; n++)
    {
        x_idx_2_re = P[n].re;
        x_idx_2_im = P[n].im;
        x_idx_3_re = c[n].re;
        x_idx_3_im = c[n].im;
        c[n + 1].re = -x_idx_2_re * x_idx_3_re - -x_idx_2_im * x_idx_3_im;
        c[n + 1].im = -x_idx_2_re * x_idx_3_im + -x_idx_2_im * x_idx_3_re;
        for (b_k = n + 1; b_k >= 2; b_k--)
        {
            x_idx_3_re = c[b_k - 2].re;
            x_idx_3_im = c[b_k - 2].im;
            c[b_k - 1].re -= x_idx_3_re * x_idx_2_re - x_idx_3_im * x_idx_2_im;
            c[b_k - 1].im -= x_idx_3_im * x_idx_2_re + x_idx_3_re * x_idx_2_im;
        }
    }

    for (n = 0; n < 5; n++)
    {
        Model_TranslationEngine64_B.denom[n] = c[n].re;
    }

    pj[0] = 1.0;
    for (n = 0; n < 4; n++)
    {
        pj[n + 1] = pj[n];
        for (b_k = n + 1; b_k >= 2; b_k--)
        {
            pj[b_k - 1] -= -pj[b_k - 2];
        }
    }

    for (n = 0; n <= 2; n += 2)
    {
        __m128d tmp;

        /* MATLAB Function: '<S35>/LinkwitzRiley' */
        /* MATLAB Function: '<S35>/LinkwitzRiley' */
        tmp = _mm_loadu_pd(&pj[n]);
        tmp = _mm_mul_pd(tmp, _mm_set1_pd(re));
        _mm_storeu_pd(&Model_TranslationEngine64_B.num[n], tmp);
        _mm_storeu_pd(&pj[n], tmp);
    }

    /* MATLAB Function: '<S35>/LinkwitzRiley' */
    /* MATLAB Function: '<S35>/LinkwitzRiley' */
    for (n = 4; n < 5; n++)
    {
        x_idx_2_re = pj[n] * re;
        Model_TranslationEngine64_B.num[n] = x_idx_2_re;
        pj[n] = x_idx_2_re;
    }
}

/* Output and update for function-call system: '<S48>/tfunc' */
void FuncTranslation_Model_117_43_403(void)
{
    int32_T i;
    char_T b_data[56];
    static const char_T c[56] =
        "Delay amount cannot be greater than specified max delay";

    /* MATLAB Function: '<S46>/MaxCheck' */
    /* MATLAB Function: '<S46>/MaxCheck' incorporates:
     *  S-Function (TuneVarMEX): '<S46>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S49>:1' */
    /* '<S49>:1:3' f(); */
    /*  Check that number of delay samples will not exceed allotted delay buffer */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainApplication/Compensation/MidrangeLpfAlignDelay/AlignDelay/MaxCheck': '<S47>:1' */
    /* Check against the max */
    /* '<S47>:1:5' if DelaySamples.Value > MaxDelaySamples */
    if ((real_T)Model_TranslationEngine64_B.MidrangeLpfAlignDelaySamples.Value >
        Model_TranslationEngine64_ConstB.CapturedTuneConst_c3)
    {
        /* '<S47>:1:6' TranslateError('Delay amount cannot be greater than specified max delay'); */
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
        for (i = 0; i < 56; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S47>:1:9' Samples = DelaySamples.Value; */
    Model_TranslationEngine64_B.Samples_n =
        Model_TranslationEngine64_B.MidrangeLpfAlignDelaySamples.Value;

    /* End of MATLAB Function: '<S46>/MaxCheck' */
}

/*
 * Output and update for function-call system:
 *    '<S53>/Bass0Enable'
 *    '<S53>/Midrange0Enable'
 *    '<S53>/Treble0Enable'
 *    '<S53>/Treble1Enable'
 *    '<S53>/Midrange1Enable'
 *    '<S53>/Bass1Enable'
 *    '<S126>/BassEnable'
 *    '<S126>/MidrangeEnable'
 *    '<S126>/TrebleEnable'
 */
void Model_TranslationEngine64_Bass0Enable(const bus_single_1_1 *rtu_on, const
    bus_single_1_1 *rtu_slope, B_Bass0Enable_Model_TranslationEngine64_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainCalculation/BoostMapAdjustment/AudiopilotOn/Bass0Enable': '<S64>:1' */
    /* '<S64>:1:3' slopeOut = slope.Value * on.Value; */
    localB->slopeOut = rtu_slope->Value * rtu_on->Value;
}

/* Output and update for function-call system: '<S68>/tfunc' */
void FuncTranslation_Model_117_44_721(void)
{
    /* MATLAB Function: '<S53>/Bass0Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S76>:1' */
    /* '<S76>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.BassSlope0Dbperdb,
         &Model_TranslationEngine64_B.sf_Bass0Enable);
}

/* Output and update for function-call system: '<S69>/tfunc' */
void FuncTranslation_Model_117_44_722(void)
{
    /* MATLAB Function: '<S53>/Midrange0Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S77>:1' */
    /* '<S77>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.MidrangeSlope0DbPerDb,
         &Model_TranslationEngine64_B.sf_Midrange0Enable_m);
}

/* Output and update for function-call system: '<S70>/tfunc' */
void FuncTranslation_Model_117_44_723(void)
{
    /* MATLAB Function: '<S53>/Treble0Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S78>:1' */
    /* '<S78>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.TrebleSlope0DbPerDb,
         &Model_TranslationEngine64_B.sf_Treble0Enable_k);
}

/* Output and update for function-call system: '<S71>/tfunc' */
void FuncTranslation_Model_117_44_895(void)
{
    /* MATLAB Function: '<S53>/Treble1Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S79>:1' */
    /* '<S79>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.TrebleSlope1DbPerDb,
         &Model_TranslationEngine64_B.sf_Treble1Enable_f);
}

/* Output and update for function-call system: '<S72>/tfunc' */
void FuncTranslation_Model_117_44_736(void)
{
    /* MATLAB Function: '<S53>/Midrange1Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S80>:1' */
    /* '<S80>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.MidrangeSlope1DbPerDb,
         &Model_TranslationEngine64_B.sf_Midrange1Enable_d);
}

/* Output and update for function-call system: '<S73>/tfunc' */
void FuncTranslation_Model_117_44_894(void)
{
    /* MATLAB Function: '<S53>/Bass1Enable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S81>:1' */
    /* '<S81>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.AudiopilotOn,
         &Model_TranslationEngine64_B.BassSlope1DbPerDb,
         &Model_TranslationEngine64_B.sf_Bass1Enable_o);
}

/* Output and update for function-call system: '<S84>/tfunc' */
void FuncTranslation_Model_117_44_469_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S82>/Subsystem' */
    /* SignalConversion generated from: '<S83>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S85>:1' */
    /* '<S85>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ny =
        Model_TranslationEngine64_B.BassThresh0Db.Value;

    /* End of Outputs for SubSystem: '<S82>/Subsystem' */
}

/* Output and update for function-call system: '<S88>/tfunc' */
void FuncTranslation_Model_117_44_470_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S86>/Subsystem' */
    /* SignalConversion generated from: '<S87>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S89>:1' */
    /* '<S89>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mx =
        Model_TranslationEngine64_B.BassThresh1Db.Value;

    /* End of Outputs for SubSystem: '<S86>/Subsystem' */
}

/* Output and update for function-call system: '<S92>/tfunc' */
void FuncTranslation_Model_117_44_332_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S90>/Subsystem' */
    /* SignalConversion generated from: '<S91>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S93>:1' */
    /* '<S93>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pb =
        Model_TranslationEngine64_B.HfNoiseHighBoundDbspl.Value;

    /* End of Outputs for SubSystem: '<S90>/Subsystem' */
}

/* Output and update for function-call system: '<S96>/tfunc' */
void FuncTranslation_Model_117_44_333_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S94>/Subsystem' */
    /* SignalConversion generated from: '<S95>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S97>:1' */
    /* '<S97>:1:3' f(); */
    Model_TranslationEngine64_B.Value_fv =
        Model_TranslationEngine64_B.HfNoiseLowBoundDbspl.Value;

    /* End of Outputs for SubSystem: '<S94>/Subsystem' */
}

/* Output and update for function-call system: '<S100>/tfunc' */
void FuncTranslation_Model_117_44_334_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S98>/Subsystem' */
    /* SignalConversion generated from: '<S99>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S101>:1' */
    /* '<S101>:1:3' f(); */
    Model_TranslationEngine64_B.Value_gn =
        Model_TranslationEngine64_B.LfNoiseHighBoundDbspl.Value;

    /* End of Outputs for SubSystem: '<S98>/Subsystem' */
}

/* Output and update for function-call system: '<S104>/tfunc' */
void FuncTranslation_Model_117_44_335_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S102>/Subsystem' */
    /* SignalConversion generated from: '<S103>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S105>:1' */
    /* '<S105>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pu =
        Model_TranslationEngine64_B.LfNoiseLowBoundDbspl.Value;

    /* End of Outputs for SubSystem: '<S102>/Subsystem' */
}

/* Output and update for function-call system: '<S108>/tfunc' */
void FuncTranslation_Model_117_44_341_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S106>/Subsystem' */
    /* SignalConversion generated from: '<S107>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S109>:1' */
    /* '<S109>:1:3' f(); */
    Model_TranslationEngine64_B.Value_dl3 =
        Model_TranslationEngine64_B.MidrangeThresh0Db.Value;

    /* End of Outputs for SubSystem: '<S106>/Subsystem' */
}

/* Output and update for function-call system: '<S112>/tfunc' */
void FuncTranslation_Model_117_44_342_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S110>/Subsystem' */
    /* SignalConversion generated from: '<S111>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S113>:1' */
    /* '<S113>:1:3' f(); */
    Model_TranslationEngine64_B.Value_kt =
        Model_TranslationEngine64_B.MidrangeThresh1Db.Value;

    /* End of Outputs for SubSystem: '<S110>/Subsystem' */
}

/* Output and update for function-call system: '<S116>/tfunc' */
void FuncTranslation_Model_117_44_484_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S114>/Subsystem' */
    /* SignalConversion generated from: '<S115>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S117>:1' */
    /* '<S117>:1:3' f(); */
    Model_TranslationEngine64_B.Value_es =
        Model_TranslationEngine64_B.TrebleThresh0Db.Value;

    /* End of Outputs for SubSystem: '<S114>/Subsystem' */
}

/* Output and update for function-call system: '<S120>/tfunc' */
void FuncTranslation_Model_117_44_485_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S118>/Subsystem' */
    /* SignalConversion generated from: '<S119>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S121>:1' */
    /* '<S121>:1:3' f(); */
    Model_TranslationEngine64_B.Value_nf =
        Model_TranslationEngine64_B.TrebleThresh1Db.Value;

    /* End of Outputs for SubSystem: '<S118>/Subsystem' */
}

/* Output and update for function-call system: '<S136>/tfunc' */
void FuncTranslation_Model_117_44_315_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S134>/Subsystem' */
    /* SignalConversion generated from: '<S135>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S137>:1' */
    /* '<S137>:1:3' f(); */
    Model_TranslationEngine64_B.Value_kk =
        Model_TranslationEngine64_B.BassDownwardThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S134>/Subsystem' */
}

/* Output and update for function-call system: '<S140>/tfunc' */
void FuncTranslation_Model_117_44_316_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S138>/Subsystem' */
    /* SignalConversion generated from: '<S139>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S141>:1' */
    /* '<S141>:1:3' f(); */
    Model_TranslationEngine64_B.Value_lo =
        Model_TranslationEngine64_B.BassMaxAudiopilotBoostDb.Value;

    /* End of Outputs for SubSystem: '<S138>/Subsystem' */
}

/* Output and update for function-call system: '<S144>/tfunc' */
void FuncTranslation_Model_117_44_317_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S142>/Subsystem' */
    /* SignalConversion generated from: '<S143>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S145>:1' */
    /* '<S145>:1:3' f(); */
    Model_TranslationEngine64_B.Value_cuk =
        Model_TranslationEngine64_B.BassMaxDyneqBoostDb.Value;

    /* End of Outputs for SubSystem: '<S142>/Subsystem' */
}

/* Output and update for function-call system: '<S148>/tfunc' */
void FuncTranslation_Model_117_44_318_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S146>/Subsystem' */
    /* SignalConversion generated from: '<S147>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S149>:1' */
    /* '<S149>:1:3' f(); */
    Model_TranslationEngine64_B.Value_jq =
        Model_TranslationEngine64_B.BassMaxTotalBoostDb.Value;

    /* End of Outputs for SubSystem: '<S146>/Subsystem' */
}

/* Output and update for function-call system: '<S152>/tfunc' */
void FuncTranslation_Model_117_44_645(void)
{
    /* MATLAB Function: '<S126>/BassEnable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S156>:1' */
    /* '<S156>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.DownwardExpansionOn,
         &Model_TranslationEngine64_B.BassDownwardSlopeDbPerDb,
         &Model_TranslationEngine64_B.sf_BassEnable_o);
}

/* Output and update for function-call system: '<S153>/tfunc' */
void FuncTranslation_Model_117_44_666(void)
{
    /* MATLAB Function: '<S126>/MidrangeEnable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S157>:1' */
    /* '<S157>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.DownwardExpansionOn,
         &Model_TranslationEngine64_B.MidrangeDownwardSlopeDbPerDb,
         &Model_TranslationEngine64_B.sf_MidrangeEnable_j);
}

/* Output and update for function-call system: '<S154>/tfunc' */
void FuncTranslation_Model_117_44_672(void)
{
    /* MATLAB Function: '<S126>/TrebleEnable' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S158>:1' */
    /* '<S158>:1:3' f(); */
    Model_TranslationEngine64_Bass0Enable
        (&Model_TranslationEngine64_B.DownwardExpansionOn,
         &Model_TranslationEngine64_B.TrebleDownwardSlopeDbPerDb,
         &Model_TranslationEngine64_B.sf_TrebleEnable_f);
}

/* Output and update for function-call system: '<S161>/tfunc' */
void FuncTranslation_Model_117_44_325_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S159>/Subsystem' */
    /* SignalConversion generated from: '<S160>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S162>:1' */
    /* '<S162>:1:3' f(); */
    Model_TranslationEngine64_B.Value_h3 =
        Model_TranslationEngine64_B.DyneqBassThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S159>/Subsystem' */
}

/* Output and update for function-call system: '<S164>/tfunc' */
void FuncTranslation_Model_117_44_633(void)
{
    /* MATLAB Function: '<S128>/DynEqEnable' */
    /* MATLAB Function: '<S128>/DynEqEnable' incorporates:
     *  S-Function (TuneVarMEX): '<S128>/DyneqBassSlope'
     *  S-Function (TuneVarMEX): '<S128>/DyneqOn'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S165>:1' */
    /* '<S165>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainCalculation/Boosts/DyneqOn/DynEqEnable': '<S163>:1' */
    /* '<S163>:1:3' slopeOut = slope.Value * on.Value; */
    Model_TranslationEngine64_B.slopeOut =
        Model_TranslationEngine64_B.DyneqBassSlopeDbPerDb.Value *
        Model_TranslationEngine64_B.DyneqOn.Value;
}

/* Output and update for function-call system: '<S169>/tfunc' */
void FuncTranslation_Model_117_44_343_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S167>/Subsystem' */
    /* SignalConversion generated from: '<S168>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S170>:1' */
    /* '<S170>:1:3' f(); */
    Model_TranslationEngine64_B.Value_oc =
        Model_TranslationEngine64_B.MinSignalLevelDbspl.Value;

    /* End of Outputs for SubSystem: '<S167>/Subsystem' */
}

/* Output and update for function-call system: '<S173>/tfunc' */
void FuncTranslation_Model_117_44_337_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S171>/Subsystem' */
    /* SignalConversion generated from: '<S172>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S174>:1' */
    /* '<S174>:1:3' f(); */
    Model_TranslationEngine64_B.Value_eh =
        Model_TranslationEngine64_B.MidrangeDownwardThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S171>/Subsystem' */
}

/* Output and update for function-call system: '<S177>/tfunc' */
void FuncTranslation_Model_117_44_338_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S175>/Subsystem' */
    /* SignalConversion generated from: '<S176>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S178>:1' */
    /* '<S178>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ba =
        Model_TranslationEngine64_B.MidrangeMaxTotalBoostDb.Value;

    /* End of Outputs for SubSystem: '<S175>/Subsystem' */
}

/* Output and update for function-call system: '<S181>/tfunc' */
void FuncTranslation_Model_117_44_913_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S179>/Subsystem' */
    /* SignalConversion generated from: '<S180>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S182>:1' */
    /* '<S182>:1:3' f(); */
    Model_TranslationEngine64_B.Value_dl =
        Model_TranslationEngine64_B.TrebleDownwardThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S179>/Subsystem' */
}

/* Output and update for function-call system: '<S185>/tfunc' */
void FuncTranslation_Model_117_44_346_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S183>/Subsystem' */
    /* SignalConversion generated from: '<S184>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S186>:1' */
    /* '<S186>:1:3' f(); */
    Model_TranslationEngine64_B.Value_gf =
        Model_TranslationEngine64_B.TrebleMaxTotalBoostDb.Value;

    /* End of Outputs for SubSystem: '<S183>/Subsystem' */
}

/* Output and update for function-call system: '<S188>/tfunc' */
void FuncTranslation_Model_117_44_328(void)
{
    real32_T Coef_tmp;

    /* MATLAB Function: '<S187>/tau2coef' */
    /* MATLAB Function: '<S187>/tau2coef' incorporates:
     *  S-Function (TuneVarMEX): '<S187>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S190>:1' */
    /* '<S190>:1:3' f(); */
    /*  Convert time constant into filter coefficient */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/GainCalculation/RampedEnable/EnableRampCoef/tau2coef': '<S189>:1' */
    /* '<S189>:1:5' Coef = (1 - sin(1/(Tau.Value * FrameRate))) ... */
    /* '<S189>:1:6'     / cos(1/(Tau.Value * FrameRate)); */
    Coef_tmp = 1.0F / (Model_TranslationEngine64_B.EnableRampTauS.Value *
                       1384.61536F);
    Model_TranslationEngine64_B.Coef = (1.0F - sinf(Coef_tmp)) / cosf(Coef_tmp);
}

/* Output and update for function-call system: '<S200>/tfunc' */
void FuncTranslation_Model_117_516_1944(void)
{
    /* MATLAB Function: '<S199>/undB' */
    /* MATLAB Function: '<S199>/undB' incorporates:
     *  S-Function (TuneVarMEX): '<S199>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S202>:1' */
    /* '<S202>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/HfNoiseMusicSeparation /RefPowerMin/undB': '<S201>:1' */
    /* '<S201>:1:4' TOP = undb20(Tune.Value); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    Model_TranslationEngine64_B.TOP_g =
        Model_TranslationEngine64_B.RefPowerMinDb.Value * 2.30258512F / 20.0F;
    Model_TranslationEngine64_B.TOP_g = expf(Model_TranslationEngine64_B.TOP_g);
}

/* Output and update for function-call system: '<S214>/tfunc' */
void FuncTranslation_Model_117_516_1707_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S212>/Subsystem' */
    /* SignalConversion generated from: '<S213>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S215>:1' */
    /* '<S215>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ld =
        Model_TranslationEngine64_B.MinstatAlphaFactor.Value;

    /* End of Outputs for SubSystem: '<S212>/Subsystem' */
}

/* Output and update for function-call system: '<S218>/tfunc' */
void FuncTranslation_Model_117_516_1708_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S216>/Subsystem' */
    /* SignalConversion generated from: '<S217>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S219>:1' */
    /* '<S219>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hu =
        Model_TranslationEngine64_B.MinstatAlphaMin.Value;

    /* End of Outputs for SubSystem: '<S216>/Subsystem' */
}

/* Output and update for function-call system: '<S224>/tfunc' */
void FuncTranslation_Model_117_516_1732_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S222>/Subsystem' */
    /* SignalConversion generated from: '<S223>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S225>:1' */
    /* '<S225>:1:3' f(); */
    Model_TranslationEngine64_B.Value_m0l =
        Model_TranslationEngine64_B.MinstatBeta.Value;

    /* End of Outputs for SubSystem: '<S222>/Subsystem' */
}

/* Output and update for function-call system: '<S228>/tfunc' */
void FuncTranslation_Model_117_516_1733_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S226>/Subsystem' */
    /* SignalConversion generated from: '<S227>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S229>:1' */
    /* '<S229>:1:3' f(); */
    Model_TranslationEngine64_B.Value_jpm =
        Model_TranslationEngine64_B.MinstatMin.Value;

    /* End of Outputs for SubSystem: '<S226>/Subsystem' */
}

/* Output and update for function-call system: '<S238>/tfunc' */
void FuncTranslation_Model_117_516_1751_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S236>/Subsystem' */
    /* SignalConversion generated from: '<S237>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S239>:1' */
    /* '<S239>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ko =
        Model_TranslationEngine64_B.FlatnessHighIndex.Value;

    /* End of Outputs for SubSystem: '<S236>/Subsystem' */
}

/* Output and update for function-call system: '<S242>/tfunc' */
void FuncTranslation_Model_117_516_1752_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S240>/Subsystem' */
    /* SignalConversion generated from: '<S241>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S243>:1' */
    /* '<S243>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hk =
        Model_TranslationEngine64_B.FlatnessLowIndex.Value;

    /* End of Outputs for SubSystem: '<S240>/Subsystem' */
}

/* Output and update for function-call system: '<S246>/tfunc' */
void FuncTranslation_Model_117_516_1753_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S244>/Subsystem' */
    /* SignalConversion generated from: '<S245>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S247>:1' */
    /* '<S247>:1:3' f(); */
    Model_TranslationEngine64_B.Value_lr =
        Model_TranslationEngine64_B.FlatnessThresh.Value;

    /* End of Outputs for SubSystem: '<S244>/Subsystem' */
}

/* Output and update for function-call system: '<S250>/tfunc' */
void FuncTranslation_Model_117_516_1755_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S248>/Subsystem' */
    /* SignalConversion generated from: '<S249>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S251>:1' */
    /* '<S251>:1:3' f(); */
    Model_TranslationEngine64_B.Value_aq =
        Model_TranslationEngine64_B.MinSearchCoef.Value;

    /* End of Outputs for SubSystem: '<S248>/Subsystem' */
}

/* Output and update for function-call system: '<S254>/tfunc' */
void FuncTranslation_Model_117_516_1754_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S252>/Subsystem' */
    /* SignalConversion generated from: '<S253>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S255>:1' */
    /* '<S255>:1:3' f(); */
    Model_TranslationEngine64_B.Value_obg =
        Model_TranslationEngine64_B.MinSearchMinGain.Value;

    /* End of Outputs for SubSystem: '<S252>/Subsystem' */
}

/* Output and update for function-call system: '<S257>/tfunc' */
void FuncTranslation_Model_117_516_1758(void)
{
    /* MATLAB Function: '<S235>/Sec2Samples' */
    /* MATLAB Function: '<S235>/Sec2Samples' incorporates:
     *  S-Function (TuneVarMEX): '<S235>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S258>:1' */
    /* '<S258>:1:3' f(); */
    /*  Convert period in sec to samples */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/PostProcessing/HfImpulseRejection/MinSearch/SubWinLen/Sec2Samples': '<S256>:1' */
    /* '<S256>:1:5' samples = ceil(HFDecRate2*time.Value); */
    Model_TranslationEngine64_B.samples_f = 21.6346149F *
        Model_TranslationEngine64_B.SubWinTimeS.Value;
    Model_TranslationEngine64_B.samples_f = ceilf
        (Model_TranslationEngine64_B.samples_f);
}

/* Output and update for function-call system: '<S262>/tfunc' */
void FuncTranslation_Model_117_516_1774_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S260>/Subsystem' */
    /* SignalConversion generated from: '<S261>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S263>:1' */
    /* '<S263>:1:3' f(); */
    Model_TranslationEngine64_B.Value_od =
        Model_TranslationEngine64_B.LevelUpdateCoef.Value;

    /* End of Outputs for SubSystem: '<S260>/Subsystem' */
}

/* Output and update for function-call system: '<S267>/tfunc' */
void FuncTranslation_Model_117_516_1789(void)
{
    /* MATLAB Function: '<S264>/sec2sample' */
    /* MATLAB Function: '<S264>/sec2sample' incorporates:
     *  S-Function (TuneVarMEX): '<S264>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S269>:1' */
    /* '<S269>:1:3' f(); */
    /*  Convert rate from per sec to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/PostProcessing/HfSlew/attack/sec2sample': '<S268>:1' */
    /* '<S268>:1:4' y = (u.Value/HFDecRate2); */
    Model_TranslationEngine64_B.y_k =
        Model_TranslationEngine64_B.AttackDbPerS.Value / 21.6346149F;
}

/* Output and update for function-call system: '<S270>/tfunc' */
void FuncTranslation_Model_117_516_1795(void)
{
    /* MATLAB Function: '<S265>/sec2sample' */
    /* MATLAB Function: '<S265>/sec2sample' incorporates:
     *  S-Function (TuneVarMEX): '<S265>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S272>:1' */
    /* '<S272>:1:3' f(); */
    /*  Convert rate from per sec to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/PostProcessing/HfSlew/decay/sec2sample': '<S271>:1' */
    /* '<S271>:1:4' y = -abs(u.Value/HFDecRate2); */
    Model_TranslationEngine64_B.y_c = -fabsf
        (Model_TranslationEngine64_B.DecayDbPerS.Value / 21.6346149F);
}

/* Output and update for function-call system: '<S275>/tfunc' */
void FuncTranslation_Model_117_516_1804_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S273>/Subsystem' */
    /* SignalConversion generated from: '<S274>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S276>:1' */
    /* '<S276>:1:3' f(); */
    Model_TranslationEngine64_B.Value_oy =
        Model_TranslationEngine64_B.ThresholdDb.Value;

    /* End of Outputs for SubSystem: '<S273>/Subsystem' */
}

/* Output and update for function-call system: '<S279>/tfunc' */
void FuncTranslation_Model_117_516_1778_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S277>/Subsystem' */
    /* SignalConversion generated from: '<S278>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S280>:1' */
    /* '<S280>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pf =
        Model_TranslationEngine64_B.OffsetDb.Value;

    /* End of Outputs for SubSystem: '<S277>/Subsystem' */
}

/* Function for MATLAB Function: '<S284>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_k(int32_T b,
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

/* Output and update for function-call system: '<S285>/tfunc' */
void FuncTranslation_Model_117_516_1849_50_36(void)
{
    real_T ChannelCoeffs[40];
    real_T OverallGainPerCh[5];
    int32_T f_data[40];
    int32_T tmp_data[40];
    int32_T b_data[10];
    int32_T ts_data[10];
    int32_T NumStages[5];
    int32_T b_vlen;
    int32_T d_k;
    int32_T i;
    int32_T k;
    int32_T yk;
    real32_T ChannelSOS_data[60];
    real32_T PoolCoeffs[40];
    real32_T x;
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S284>/Translation' */
    /* MATLAB Function: '<S284>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S284>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S284>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S287>:1' */
    /* '<S287>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/PreProcessing/Anti-Aliasing Filter/InnerLink/PoolIirTunableWithReset/Translation': '<S286>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S286>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S286>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S286>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (i = 0; i < 5; i++)
    {
        x = roundf(Model_TranslationEngine64_B.numStages_g.Value[i]);
        if (x < 2.14748365E+9F)
        {
            if (x >= -2.14748365E+9F)
            {
                NumStages[i] = (int32_T)x;
            }
            else
            {
                NumStages[i] = MIN_int32_T;
            }
        }
        else
        {
            NumStages[i] = MAX_int32_T;
        }

        Model_TranslationEngine64_B.PoolNumStages_a[i] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 40U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 40U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    i = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (((((real_T)NumStages[0] + (real_T)NumStages[1]) + (real_T)NumStages[2])
            + (real_T)NumStages[3]) + (real_T)NumStages[4] > 10.0)
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
    for (k = 0; k < 5; k++)
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
            real32_T y;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_k(NumStages_0,
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
                        Model_TranslationEngine64_B.sosCoefficients_b0.Value[(10
                        * b_vlen + q1) - 1];
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
                offset = Model_TranslationEngine64_B.PoolNumStages_a[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_B.PoolNumStages_a[d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_a[k] = NumStages_0;

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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_k(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_B.PoolCoeffs_i[0], &PoolCoeffs[0], 40U *
           sizeof(real32_T));
    for (i = 0; i < 5; i++)
    {
        Model_TranslationEngine64_B.PoolCoeffs_i[i + 40] = (real32_T)
            OverallGainPerCh[i];
    }

    /* End of MATLAB Function: '<S284>/Translation' */
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

/* Function for MATLAB Function: '<S289>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_pu(int32_T b,
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

/* Output and update for function-call system: '<S290>/tfunc' */
void FuncTranslation_Model_117_516_1847_50_36(void)
{
    real_T ChannelCoeffs[72];
    real_T OverallGainPerCh[5];
    int32_T f_data[72];
    int32_T tmp_data[72];
    int32_T b_data[18];
    int32_T ts_data[18];
    int32_T NumStages[5];
    int32_T b_vlen;
    int32_T d_k;
    int32_T i;
    int32_T k;
    int32_T yk;
    real32_T ChannelSOS_data[108];
    real32_T PoolCoeffs[72];
    real32_T x;
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S289>/Translation' */
    /* MATLAB Function: '<S289>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S289>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S289>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S292>:1' */
    /* '<S292>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/PreProcessing/Bandpass or Lowpass Filter/InnerLink/PoolIirTunableWithReset/Translation': '<S291>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S291>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S291>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S291>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (i = 0; i < 5; i++)
    {
        x = roundf(Model_TranslationEngine64_B.numStages_o.Value[i]);
        if (x < 2.14748365E+9F)
        {
            if (x >= -2.14748365E+9F)
            {
                NumStages[i] = (int32_T)x;
            }
            else
            {
                NumStages[i] = MIN_int32_T;
            }
        }
        else
        {
            NumStages[i] = MAX_int32_T;
        }

        Model_TranslationEngine64_B.PoolNumStages_f[i] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 72U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 72U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    i = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (((((real_T)NumStages[0] + (real_T)NumStages[1]) + (real_T)NumStages[2])
            + (real_T)NumStages[3]) + (real_T)NumStages[4] > 18.0)
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
    for (k = 0; k < 5; k++)
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
            real32_T y;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_pu
                (NumStages_0, tmp_data, tmp_size);
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
                        Model_TranslationEngine64_B.sosCoefficients_jq.Value[(18
                        * b_vlen + q1) - 1];
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
                offset = Model_TranslationEngine64_B.PoolNumStages_f[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_B.PoolNumStages_f[d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_f[k] = NumStages_0;

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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_pu(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_B.PoolCoeffs_o[0], &PoolCoeffs[0], 72U *
           sizeof(real32_T));
    for (i = 0; i < 5; i++)
    {
        Model_TranslationEngine64_B.PoolCoeffs_o[i + 72] = (real32_T)
            OverallGainPerCh[i];
    }

    /* End of MATLAB Function: '<S289>/Translation' */
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

/* Output and update for function-call system: '<S294>/tfunc' */
void FuncTranslation_Model_117_516_957(void)
{
    int32_T i;
    real32_T Samples;
    char_T b_data[56];
    static const char_T c[56] =
        "Delay amount cannot be greater than specified max delay";

    /* MATLAB Function: '<S293>/ms2samples' */
    /* MATLAB Function: '<S293>/ms2samples' incorporates:
     *  S-Function (TuneVarMEX): '<S293>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S296>:1' */
    /* '<S296>:1:3' f(); */
    /*  Convert from time constant to samples */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/HFNoiseEstimatorCoh/ReferenceLatency/RefLatency/ms2samples': '<S295>:1' */
    /* '<S295>:1:4' Samples = floor(DelayTimeMS.Value*HFDecRate/1000); */
    Samples = floorf(Model_TranslationEngine64_B.RefLatencyMs.Value *
                     2769.23071F / 1000.0F);

    /*  Use floor to minimize the risk of going noncausal  */
    /* '<S295>:1:7' if Samples > MaxLatencySamples */
    if ((real_T)Samples > Model_TranslationEngine64_ConstB.CapturedTuneConst_fm)
    {
        /* '<S295>:1:8' TranslateError('Delay amount cannot be greater than specified max delay'); */
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
        for (i = 0; i < 56; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);
    }

    Model_TranslationEngine64_B.Samples_h = Samples;

    /* End of MATLAB Function: '<S293>/ms2samples' */
}

/*
 * Output and update for function-call system:
 *    '<S297>/TimeConstant2Coefficient'
 *    '<S307>/TimeConstant2Coefficient'
 *    '<S308>/TimeConstant2Coefficient'
 */
void Model_TranslationEngine64_TimeConstant2Coefficient(const bus_single_1_1
    *rtu_tau, B_TimeConstant2Coefficient_Model_TranslationEngine64_T *localB)
{
    real32_T wc;

    /*  Convert time constant to filter coefficient */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/EnergyLpfCoef/TimeConstant2Coefficient': '<S304>:1' */
    /* '<S304>:1:5' wc = 1/(DecRate3*tau.Value); */
    wc = 1.0F / (1.80288458F * rtu_tau->Value);

    /* '<S304>:1:6' coef = (1-sin(wc))/cos(wc); */
    localB->coef = (1.0F - sinf(wc)) / cosf(wc);
}

/* Output and update for function-call system: '<S305>/tfunc' */
void FuncTranslation_Model_117_517_435(void)
{
    /* MATLAB Function: '<S297>/TimeConstant2Coefficient' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S306>:1' */
    /* '<S306>:1:3' f(); */
    Model_TranslationEngine64_TimeConstant2Coefficient
        (&Model_TranslationEngine64_B.EnergyLpfTauS,
         &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient);
}

/* Output and update for function-call system: '<S314>/tfunc' */
void FuncTranslation_Model_117_517_422(void)
{
    /* MATLAB Function: '<S307>/TimeConstant2Coefficient' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S315>:1' */
    /* '<S315>:1:3' f(); */
    Model_TranslationEngine64_TimeConstant2Coefficient
        (&Model_TranslationEngine64_B.Gamma0TauS,
         &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient_ox);
}

/* Output and update for function-call system: '<S317>/tfunc' */
void FuncTranslation_Model_117_517_415(void)
{
    /* MATLAB Function: '<S308>/TimeConstant2Coefficient' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S318>:1' */
    /* '<S318>:1:3' f(); */
    Model_TranslationEngine64_TimeConstant2Coefficient
        (&Model_TranslationEngine64_B.ImpulseVarianceFiltTauS,
         &Model_TranslationEngine64_B.sf_TimeConstant2Coefficient_gn);
}

/* Output and update for function-call system: '<S321>/tfunc' */
void FuncTranslation_Model_117_517_330_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S319>/Subsystem' */
    /* SignalConversion generated from: '<S320>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S322>:1' */
    /* '<S322>:1:3' f(); */
    Model_TranslationEngine64_B.Value_js =
        Model_TranslationEngine64_B.ImpulseVarianceScale.Value;

    /* End of Outputs for SubSystem: '<S319>/Subsystem' */
}

/* Output and update for function-call system: '<S325>/tfunc' */
void FuncTranslation_Model_117_517_331_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S323>/Subsystem' */
    /* SignalConversion generated from: '<S324>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S326>:1' */
    /* '<S326>:1:3' f(); */
    Model_TranslationEngine64_B.Value_gl =
        Model_TranslationEngine64_B.MusicVarianceScale.Value;

    /* End of Outputs for SubSystem: '<S323>/Subsystem' */
}

/* Output and update for function-call system: '<S329>/tfunc' */
void FuncTranslation_Model_117_517_332_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S327>/Subsystem' */
    /* SignalConversion generated from: '<S328>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S330>:1' */
    /* '<S330>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pj =
        Model_TranslationEngine64_B.NoiseVarianceScale.Value;

    /* End of Outputs for SubSystem: '<S327>/Subsystem' */
}

/* Output and update for function-call system: '<S333>/tfunc' */
void FuncTranslation_Model_117_517_429_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S331>/Subsystem' */
    /* SignalConversion generated from: '<S332>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S334>:1' */
    /* '<S334>:1:3' f(); */
    Model_TranslationEngine64_B.Value_e5 =
        Model_TranslationEngine64_B.OutputMin.Value;

    /* End of Outputs for SubSystem: '<S331>/Subsystem' */
}

/* Function for MATLAB Function: '<S338>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher(int32_T b,
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

/*
 * Output and update for function-call system:
 *    '<S338>/Translation'
 *    '<S343>/Translation'
 */
void Model_TranslationEngine64_Translation(const bus_single_3_6 *rtu_RawSOS,
    const bus_single_1_1 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_T *localB)
{
    real_T ChannelCoeffs[12];
    real_T OverallGainPerCh;
    int32_T y_tmp_data[12];
    int32_T b_data[3];
    int32_T ts_data[3];
    int32_T i;
    int32_T i_0;
    int32_T yk;
    real32_T ChannelSOS_data[18];
    real32_T PoolCoeffs[12];
    real32_T x;
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];
    int32_T y_tmp_size[2];

    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/LfPreProcess/FilterMic/InnerLink/PoolIirTunableWithReset/Translation': '<S340>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S340>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S340>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S340>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    x = roundf(rtu_NumStages->Value);
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            i_0 = (int32_T)x;
        }
        else
        {
            i_0 = MIN_int32_T;
        }
    }
    else
    {
        i_0 = MAX_int32_T;
    }

    /* 'PoolIirHexagonTranslationFcn:13' NumChannels   = numel(NumStages); */
    /* 'PoolIirHexagonTranslationFcn:14' MaxNumStages  = maxNumStages; */
    /* 'PoolIirHexagonTranslationFcn:15' PoolNumStages = int32(zeros(NumChannels,1)); */
    localB->PoolNumStages = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&ChannelCoeffs[0], 0, 12U * sizeof(real_T));
    for (i = 0; i < 12; i++)
    {
        PoolCoeffs[i] = 0.0F;
    }

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (i_0 > 3)
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
        for (i = 0; i < 31; i++)
        {
            d_data[i] = e[i];
        }

        TranslateError(&d_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    OverallGainPerCh = 1.0;

    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    /* 'PoolIirHexagonTranslationFcn:29' ChannelNumStages = NumStages(i); */
    /*  Size of current SOS */
    /* 'PoolIirHexagonTranslationFcn:30' assert(ChannelNumStages <= MaxNumStages); */
    /* 'PoolIirHexagonTranslationFcn:31' if (ChannelNumStages == 0) */
    if (i_0 != 0)
    {
        __m128i tmp;
        int32_T ChannelSOS_size_idx_0;
        int32_T vectorUB;
        int32_T vlen;
        int32_T vlen_tmp;
        real32_T b_y;

        /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            y_tmp_size);
        ChannelSOS_size_idx_0 = y_tmp_size[1];
        vlen = y_tmp_size[1];
        for (i = 0; i < 6; i++)
        {
            for (yk = 0; yk < vlen; yk++)
            {
                ChannelSOS_data[yk + ChannelSOS_size_idx_0 * i] =
                    rtu_RawSOS->Value[(3 * i + y_tmp_data[yk]) - 1];
            }
        }

        /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
        /*  decompose SOS     */
        /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            tmp_size);
        vlen = tmp_size[1];
        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            tmp_size);
        if (tmp_size[1] == 0)
        {
            x = 1.0F;
        }
        else if (y_tmp_size[1] == 0)
        {
            x = 1.0F;
        }
        else
        {
            x = ChannelSOS_data[0];
            for (i = 2; i <= vlen; i++)
            {
                x *= ChannelSOS_data[i - 1];
            }
        }

        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            tmp_size);
        vlen = tmp_size[1];
        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            tmp_size);
        if (tmp_size[1] == 0)
        {
            b_y = 1.0F;
        }
        else if (y_tmp_size[1] == 0)
        {
            b_y = 1.0F;
        }
        else
        {
            b_y = ChannelSOS_data[y_tmp_size[1] * 3];
            for (i = 2; i <= vlen; i++)
            {
                b_y *= ChannelSOS_data[(ChannelSOS_size_idx_0 * 3 + i) - 1];
            }
        }

        OverallGainPerCh = x / b_y;

        /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
        /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
        if (i_0 > 536870911)
        {
            i = MAX_int32_T;
        }
        else if (i_0 <= -536870912)
        {
            i = MIN_int32_T;
        }
        else
        {
            i = i_0 << 2;
        }

        if (i < 1)
        {
            vlen = 0;
        }
        else
        {
            vlen = (int32_T)((uint32_T)(i - 1) >> 2) + 1;
        }

        if (vlen > 0)
        {
            ts_data[0] = 1;
            yk = 1;
            for (i = 2; i <= vlen; i++)
            {
                yk += 4;
                ts_data[i - 1] = yk;
            }
        }

        vlen_tmp = vlen - 1;
        yk = (vlen / 4) << 2;
        vectorUB = yk - 4;
        for (i = 0; i <= vectorUB; i += 4)
        {
            tmp = _mm_loadu_si128((const __m128i *)&ts_data[i]);
            _mm_storeu_si128((__m128i *)&ts_data[i], _mm_sub_epi32(tmp,
                              _mm_set1_epi32(1)));
        }

        for (i = yk; i <= vlen_tmp; i++)
        {
            ts_data[i]--;
        }

        /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
        vectorUB = yk - 4;
        for (i = 0; i <= vectorUB; i += 4)
        {
            tmp = _mm_loadu_si128((const __m128i *)&ts_data[i]);
            _mm_storeu_si128((__m128i *)&b_data[i], _mm_add_epi32(tmp,
                              _mm_set1_epi32(1)));
        }

        for (i = yk; i < vlen; i++)
        {
            b_data[i] = ts_data[i] + 1;
        }

        for (i = 0; i < vlen; i++)
        {
            ChannelCoeffs[b_data[i] - 1] = -ChannelSOS_data
                [(ChannelSOS_size_idx_0 << 2) + i] /
                ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + i];
        }

        /*  -a1/a0 */
        /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
        vectorUB = yk - 4;
        for (i = 0; i <= vectorUB; i += 4)
        {
            tmp = _mm_loadu_si128((const __m128i *)&ts_data[i]);
            _mm_storeu_si128((__m128i *)&b_data[i], _mm_add_epi32(tmp,
                              _mm_set1_epi32(2)));
        }

        for (i = yk; i < vlen; i++)
        {
            b_data[i] = ts_data[i] + 2;
        }

        for (i = 0; i < vlen; i++)
        {
            ChannelCoeffs[b_data[i] - 1] = ChannelSOS_data[i +
                ChannelSOS_size_idx_0] / ChannelSOS_data[i];
        }

        /*   b1/b0 */
        /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
        vectorUB = yk - 4;
        for (i = 0; i <= vectorUB; i += 4)
        {
            tmp = _mm_loadu_si128((const __m128i *)&ts_data[i]);
            _mm_storeu_si128((__m128i *)&b_data[i], _mm_add_epi32(tmp,
                              _mm_set1_epi32(3)));
        }

        for (i = yk; i < vlen; i++)
        {
            b_data[i] = ts_data[i] + 3;
        }

        for (i = 0; i < vlen; i++)
        {
            ChannelCoeffs[b_data[i] - 1] =
                -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + i] /
                ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + i];
        }

        /*  -a2/a0 */
        /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
        for (i = 0; i <= vlen_tmp; i++)
        {
            yk = ts_data[i];
            if (yk > 2147483643)
            {
                yk = MAX_int32_T;
            }
            else
            {
                yk += 4;
            }

            ts_data[i] = yk;
        }

        for (i = 0; i < vlen; i++)
        {
            ChannelCoeffs[ts_data[i] - 1] = ChannelSOS_data
                [(ChannelSOS_size_idx_0 << 1) + i] / ChannelSOS_data[i];
        }

        /*   b2/b0 */
        /*  length of Current Channel Coeffs */
        /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
        /*  Offset into coefficient array for the current channel */
        /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
        /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
        localB->PoolNumStages = i_0;

        /*  Store the coefficients */
        /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
        if (i_0 > 536870911)
        {
            i_0 = MAX_int32_T;
        }
        else if (i_0 <= -536870912)
        {
            i_0 = MIN_int32_T;
        }
        else
        {
            i_0 <<= 2;
        }

        Model_TranslationEngine64_eml_integer_colon_dispatcher(i_0, y_tmp_data,
            y_tmp_size);
        vlen = y_tmp_size[1];
        for (i_0 = 0; i_0 < vlen; i_0++)
        {
            PoolCoeffs[y_tmp_data[i_0] - 1] = (real32_T)ChannelCoeffs[i_0];
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    for (i = 0; i < 12; i++)
    {
        localB->PoolCoeffs[i] = PoolCoeffs[i];
    }

    localB->PoolCoeffs[12] = (real32_T)OverallGainPerCh;

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

/* Output and update for function-call system: '<S339>/tfunc' */
void FuncTranslation_Model_117_517_515_50_36(void)
{
    /* MATLAB Function: '<S338>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S341>:1' */
    /* '<S341>:1:3' f(); */
    Model_TranslationEngine64_Translation
        (&Model_TranslationEngine64_B.sosCoefficients_p,
         &Model_TranslationEngine64_B.numStages_ns,
         &Model_TranslationEngine64_B.sf_Translation_g);
}

/* Output and update for function-call system: '<S344>/tfunc' */
void FuncTranslation_Model_117_517_516_50_36(void)
{
    /* MATLAB Function: '<S343>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S346>:1' */
    /* '<S346>:1:3' f(); */
    Model_TranslationEngine64_Translation
        (&Model_TranslationEngine64_B.sosCoefficients_a,
         &Model_TranslationEngine64_B.numStages_ea,
         &Model_TranslationEngine64_B.sf_Translation_gf2);
}

/* Output and update for function-call system: '<S349>/tfunc' */
void FuncTranslation_Model_117_517_459_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S347>/Subsystem' */
    /* SignalConversion generated from: '<S348>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S350>:1' */
    /* '<S350>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mk =
        Model_TranslationEngine64_B.OffsetDb_o.Value;

    /* End of Outputs for SubSystem: '<S347>/Subsystem' */
}

/* Output and update for function-call system: '<S352>/tfunc' */
void FuncTranslation_Model_117_517_351(void)
{
    int32_T i;
    real32_T Samples;
    char_T b_data[56];
    static const char_T c[56] =
        "Delay amount cannot be greater than specified max delay";

    /* MATLAB Function: '<S351>/ms2samples' */
    /* MATLAB Function: '<S351>/ms2samples' incorporates:
     *  S-Function (TuneVarMEX): '<S351>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S354>:1' */
    /* '<S354>:1:3' f(); */
    /*  Convert from milliseconds to samples */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/ReferenceLatency/RefLatencySamples/ms2samples': '<S353>:1' */
    /*  Use floor to minimize the risk of going noncausal  */
    /* '<S353>:1:5' Samples = floor(DelayTimeMS.Value*DecRate/1000); */
    Samples = floorf(Model_TranslationEngine64_B.RefLatencyMs_l.Value *
                     692.307678F / 1000.0F);

    /* '<S353>:1:8' if Samples > MaxLatencySamples */
    if ((real_T)Samples > Model_TranslationEngine64_ConstB.CapturedTuneConst_d)
    {
        /* '<S353>:1:9' TranslateError('Delay amount cannot be greater than specified max delay'); */
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
        for (i = 0; i < 56; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);
    }

    Model_TranslationEngine64_B.Samples_g = Samples;

    /* End of MATLAB Function: '<S351>/ms2samples' */
}

/*
 * Output and update for function-call system:
 *    '<S357>/sec2sample'
 *    '<S359>/sec2sample'
 */
void Model_TranslationEngine64_sec2sample(const bus_single_1_1 *rtu_u,
    B_sec2sample_Model_TranslationEngine64_T *localB)
{
    /*  Convert rate from per second to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/SpeedBoundsAndNoiseSlew/LfNoiseSlew/Attack/sec2sample': '<S362>:1' */
    /* '<S362>:1:4' y = u.Value/DecRate2; */
    localB->y = rtu_u->Value / 5.40865374F;
}

/* Output and update for function-call system: '<S361>/tfunc' */
void FuncTranslation_Model_117_517_388(void)
{
    /* MATLAB Function: '<S357>/sec2sample' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S363>:1' */
    /* '<S363>:1:3' f(); */
    Model_TranslationEngine64_sec2sample
        (&Model_TranslationEngine64_B.AttackDbPerS_i,
         &Model_TranslationEngine64_B.sf_sec2sample_p);
}

/* Output and update for function-call system: '<S364>/tfunc' */
void FuncTranslation_Model_117_517_397(void)
{
    /* MATLAB Function: '<S358>/sec2sample' */
    /* MATLAB Function: '<S358>/sec2sample' incorporates:
     *  S-Function (TuneVarMEX): '<S358>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S366>:1' */
    /* '<S366>:1:3' f(); */
    /*  Convert rate from per second to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/SpeedBoundsAndNoiseSlew/LfNoiseSlew/Decay/sec2sample': '<S365>:1' */
    /* '<S365>:1:4' y = -abs(u.Value/DecRate2); */
    Model_TranslationEngine64_B.y_l = -fabsf
        (Model_TranslationEngine64_B.DecayDbPerS_p.Value / 5.40865374F);
}

/* Output and update for function-call system: '<S367>/tfunc' */
void FuncTranslation_Model_117_517_404(void)
{
    /* MATLAB Function: '<S359>/sec2sample' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S369>:1' */
    /* '<S369>:1:3' f(); */
    Model_TranslationEngine64_sec2sample(&Model_TranslationEngine64_B.SlowDbPerS,
        &Model_TranslationEngine64_B.sf_sec2sample_l0);
}

/* Output and update for function-call system: '<S372>/tfunc' */
void FuncTranslation_Model_117_517_270_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S370>/Subsystem' */
    /* SignalConversion generated from: '<S371>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S373>:1' */
    /* '<S373>:1:3' f(); */
    Model_TranslationEngine64_B.Value_cu =
        Model_TranslationEngine64_B.ThresholdDb_j.Value;

    /* End of Outputs for SubSystem: '<S370>/Subsystem' */
}

/* Output and update for function-call system: '<S380>/tfunc' */
void FuncTranslation_Model_117_517_572_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S378>/Subsystem' */
    /* SignalConversion generated from: '<S379>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S381>:1' */
    /* '<S381>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_B.Value_c1[0],
           &Model_TranslationEngine64_B.Axis.Value[0], sizeof(real32_T) << 7U);

    /* End of Outputs for SubSystem: '<S378>/Subsystem' */
}

/* Output and update for function-call system: '<S384>/tfunc' */
void FuncTranslation_Model_117_517_573_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S382>/Subsystem' */
    /* SignalConversion generated from: '<S383>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S385>:1' */
    /* '<S385>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_B.Value_mh[0],
           &Model_TranslationEngine64_B.MaxDbspl.Value[0], sizeof(real32_T) <<
           7U);

    /* End of Outputs for SubSystem: '<S382>/Subsystem' */
}

/* Output and update for function-call system: '<S386>/tfunc' */
void FuncTranslation_Model_117_517_577(void)
{
    int32_T i;
    int32_T k;

    /* MATLAB Function: '<S376>/Trivial Translation' */
    /* MATLAB Function: '<S376>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S376>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S388>:1' */
    /* '<S388>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/LFNoiseEstimatorCoh/SpeedBoundsAndNoiseSlew/SpeedBounds/min/Trivial Translation': '<S387>:1' */
    /* '<S387>:1:4' TOP = Tune1.Value; */
    memcpy(&Model_TranslationEngine64_B.TOP[0],
           &Model_TranslationEngine64_B.MindBSPL.Value[0], sizeof(real32_T) <<
           7U);

    /* '<S387>:1:5' minBoundsLowestVal = min(Tune1.Value); */
    if (!rtIsNaNF(Model_TranslationEngine64_B.MindBSPL.Value[0]))
    {
        i = 1;
    }
    else
    {
        boolean_T exitg1;
        i = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 129))
        {
            if (!rtIsNaNF(Model_TranslationEngine64_B.MindBSPL.Value[k - 1]))
            {
                i = k;
                exitg1 = true;
            }
            else
            {
                k++;
            }
        }
    }

    if (i == 0)
    {
        Model_TranslationEngine64_B.minBoundsLowestVal =
            Model_TranslationEngine64_B.MindBSPL.Value[0];
    }
    else
    {
        real32_T ex;
        ex = Model_TranslationEngine64_B.MindBSPL.Value[i - 1];
        for (k = i + 1; k < 129; k++)
        {
            real32_T tmp;
            tmp = Model_TranslationEngine64_B.MindBSPL.Value[k - 1];
            if (ex > tmp)
            {
                ex = tmp;
            }
        }

        Model_TranslationEngine64_B.minBoundsLowestVal = ex;
    }

    /* End of MATLAB Function: '<S376>/Trivial Translation' */
}

/* Output and update for function-call system: '<S391>/tfunc' */
void FuncTranslation_Model_117_517_582_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S389>/Subsystem' */
    /* SignalConversion generated from: '<S390>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S392>:1' */
    /* '<S392>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ca = Model_TranslationEngine64_B.On.Value;

    /* End of Outputs for SubSystem: '<S389>/Subsystem' */
}

/* Output and update for function-call system: '<S395>/tfunc' */
void FuncTranslation_Model_117_517_553_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S393>/Subsystem' */
    /* SignalConversion generated from: '<S394>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S396>:1' */
    /* '<S396>:1:3' f(); */
    Model_TranslationEngine64_B.Value_dw =
        Model_TranslationEngine64_B.SysMaxDbspl_j.Value;

    /* End of Outputs for SubSystem: '<S393>/Subsystem' */
}

/* Output and update for function-call system: '<S409>/tfunc' */
void FuncTranslation_Model_117_2074(void)
{
    /* MATLAB Function: '<S403>/sec2samples' */
    /* MATLAB Function: '<S403>/sec2samples' incorporates:
     *  S-Function (TuneVarMEX): '<S403>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S411>:1' */
    /* '<S411>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/APLFUP/FlagHoldTime/sec2samples': '<S410>:1' */
    /* '<S410>:1:4' samples = ceil(time.Value*HFDecRate); */
    Model_TranslationEngine64_B.samples_h =
        Model_TranslationEngine64_B.FlagHoldTimeS.Value * 21.6346149F;
    Model_TranslationEngine64_B.samples_h = ceilf
        (Model_TranslationEngine64_B.samples_h);
}

/* Output and update for function-call system: '<S414>/tfunc' */
void FuncTranslation_Model_117_2078_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S412>/Subsystem' */
    /* SignalConversion generated from: '<S413>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S415>:1' */
    /* '<S415>:1:3' f(); */
    Model_TranslationEngine64_B.Value_h1 =
        Model_TranslationEngine64_B.HfNoiseThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S412>/Subsystem' */
}

/* Output and update for function-call system: '<S418>/tfunc' */
void FuncTranslation_Model_117_2079_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S416>/Subsystem' */
    /* SignalConversion generated from: '<S417>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S419>:1' */
    /* '<S419>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mq =
        Model_TranslationEngine64_B.LfNoiseThreshDbspl.Value;

    /* End of Outputs for SubSystem: '<S416>/Subsystem' */
}

/* Output and update for function-call system: '<S420>/tfunc' */
void FuncTranslation_Model_117_2082(void)
{
    /* MATLAB Function: '<S406>/sec2samples' */
    /* MATLAB Function: '<S406>/sec2samples' incorporates:
     *  S-Function (TuneVarMEX): '<S406>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S422>:1' */
    /* '<S422>:1:3' f(); */
    /*  A trivial pass-through translation looks like this: */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/APLFUP/LfNoiseUpdatePeriod/sec2samples': '<S421>:1' */
    /* '<S421>:1:4' samples = ceil(time.Value*HFDecRate); */
    Model_TranslationEngine64_B.samples =
        Model_TranslationEngine64_B.LfNoiseUpdatePeriodS.Value * 21.6346149F;
    Model_TranslationEngine64_B.samples = ceilf
        (Model_TranslationEngine64_B.samples);
}

/* Output and update for function-call system: '<S425>/tfunc' */
void FuncTranslation_Model_117_2086_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S423>/Subsystem' */
    /* SignalConversion generated from: '<S424>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S426>:1' */
    /* '<S426>:1:3' f(); */
    Model_TranslationEngine64_B.Value_dg =
        Model_TranslationEngine64_B.LfNoiseUpdateThreshDb.Value;

    /* End of Outputs for SubSystem: '<S423>/Subsystem' */
}

/* Output and update for function-call system: '<S429>/tfunc' */
void FuncTranslation_Model_117_2087_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S427>/Subsystem' */
    /* SignalConversion generated from: '<S428>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S430>:1' */
    /* '<S430>:1:3' f(); */
    Model_TranslationEngine64_B.Value_os =
        Model_TranslationEngine64_B.SpeedUpdateThreshMph.Value;

    /* End of Outputs for SubSystem: '<S427>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S398>/Tau2Coef'
 *    '<S456>/Tau2Coef'
 */
void Model_TranslationEngine64_Tau2Coef(const bus_single_1_1 *rtu_tau,
    B_Tau2Coef_Model_TranslationEngine64_T *localB)
{
    real32_T wc;

    /*  Convert from time constant to 1st order coefficient */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/EnergyLpfCoef/Tau2Coef': '<S431>:1' */
    /* '<S431>:1:5' wc = 1/(HFDecRate*tau.Value); */
    wc = 1.0F / (21.6346149F * rtu_tau->Value);

    /* '<S431>:1:6' coef = (1-sin(wc))/cos(wc); */
    localB->coef = (1.0F - sinf(wc)) / cosf(wc);
}

/* Output and update for function-call system: '<S432>/tfunc' */
void FuncTranslation_Model_117_2093(void)
{
    /* MATLAB Function: '<S398>/Tau2Coef' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S433>:1' */
    /* '<S433>:1:3' f(); */
    Model_TranslationEngine64_Tau2Coef
        (&Model_TranslationEngine64_B.EnergyLpfTauS_g,
         &Model_TranslationEngine64_B.sf_Tau2Coef);
}

/* Output and update for function-call system: '<S436>/tfunc' */
void FuncTranslation_Model_117_2099_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S434>/Subsystem' */
    /* SignalConversion generated from: '<S435>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S437>:1' */
    /* '<S437>:1:3' f(); */
    Model_TranslationEngine64_B.Value_kh =
        Model_TranslationEngine64_B.HighBoundDb.Value;

    /* End of Outputs for SubSystem: '<S434>/Subsystem' */
}

/* Output and update for function-call system: '<S440>/tfunc' */
void FuncTranslation_Model_117_2100_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S438>/Subsystem' */
    /* SignalConversion generated from: '<S439>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S441>:1' */
    /* '<S441>:1:3' f(); */
    Model_TranslationEngine64_B.Value_oj =
        Model_TranslationEngine64_B.LowBoundDb.Value;

    /* End of Outputs for SubSystem: '<S438>/Subsystem' */
}

/* Output and update for function-call system: '<S445>/tfunc' */
void FuncTranslation_Model_117_2115(void)
{
    /* MATLAB Function: '<S442>/sec2sample' */
    /* MATLAB Function: '<S442>/sec2sample' incorporates:
     *  S-Function (TuneVarMEX): '<S442>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S447>:1' */
    /* '<S447>:1:3' f(); */
    /*  Convert rate from per sec to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/RatioSlew/attack/sec2sample': '<S446>:1' */
    /* '<S446>:1:4' y = abs(u.Value/HFDecRate); */
    Model_TranslationEngine64_B.y_g = fabsf
        (Model_TranslationEngine64_B.AttackDbPerS_o.Value / 21.6346149F);
}

/* Output and update for function-call system: '<S448>/tfunc' */
void FuncTranslation_Model_117_2121(void)
{
    /* MATLAB Function: '<S443>/sec2sample' */
    /* MATLAB Function: '<S443>/sec2sample' incorporates:
     *  S-Function (TuneVarMEX): '<S443>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S450>:1' */
    /* '<S450>:1:3' f(); */
    /*  Convert rate from per sec to per sample */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/RatioSlew/decay/sec2sample': '<S449>:1' */
    /* '<S449>:1:4' y = -abs(u.Value/HFDecRate); */
    Model_TranslationEngine64_B.y = -fabsf
        (Model_TranslationEngine64_B.DecayDbPerS_f.Value / 21.6346149F);
}

/* Output and update for function-call system: '<S453>/tfunc' */
void FuncTranslation_Model_117_2125_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S451>/Subsystem' */
    /* SignalConversion generated from: '<S452>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S454>:1' */
    /* '<S454>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ov =
        Model_TranslationEngine64_B.ThresholdDb_b.Value;

    /* End of Outputs for SubSystem: '<S451>/Subsystem' */
}

/* Output and update for function-call system: '<S460>/tfunc' */
void FuncTranslation_Model_117_2149(void)
{
    real32_T wc;

    /* MATLAB Function: '<S455>/Tau2Gamma' */
    /* MATLAB Function: '<S455>/Tau2Gamma' incorporates:
     *  S-Function (TuneVarMEX): '<S455>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S461>:1' */
    /* '<S461>:1:3' f(); */
    /*  Approximate conversion from coefficient to time constant */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Audiopilot_3_5/NoiseEstimationVariant/RegularNoiseEstimation/RatioCalculation/RatioSmoother/RatioImpulseRejectionGamma0/Tau2Gamma': '<S459>:1' */
    /* '<S459>:1:4' wc = 1/(HFDecRate*tau.Value); */
    wc = 1.0F / (21.6346149F * Model_TranslationEngine64_B.Gamma0TauS_p.Value);

    /* '<S459>:1:5' gamma = 1-(1-sin(wc))/cos(wc); */
    Model_TranslationEngine64_B.gamma = 1.0F - (1.0F - sinf(wc)) / cosf(wc);
}

/* Output and update for function-call system: '<S463>/tfunc' */
void FuncTranslation_Model_117_2155(void)
{
    /* MATLAB Function: '<S456>/Tau2Coef' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S464>:1' */
    /* '<S464>:1:3' f(); */
    Model_TranslationEngine64_Tau2Coef
        (&Model_TranslationEngine64_B.ImpulseVarianceLpfTauS,
         &Model_TranslationEngine64_B.sf_Tau2Coef_om);
}

/* Output and update for function-call system: '<S467>/tfunc' */
void FuncTranslation_Model_117_2158_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S465>/Subsystem' */
    /* SignalConversion generated from: '<S466>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S468>:1' */
    /* '<S468>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pp =
        Model_TranslationEngine64_B.ImpulseVarianceScale_h.Value;

    /* End of Outputs for SubSystem: '<S465>/Subsystem' */
}

/* Output and update for function-call system: '<S471>/tfunc' */
void FuncTranslation_Model_117_2159_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S469>/Subsystem' */
    /* SignalConversion generated from: '<S470>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S472>:1' */
    /* '<S472>:1:3' f(); */
    Model_TranslationEngine64_B.Value_e1p =
        Model_TranslationEngine64_B.NoiseVarianceScale_g.Value;

    /* End of Outputs for SubSystem: '<S469>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S477>/sec2samples'
 *    '<S482>/sec2samples'
 *    '<S504>/sec2samples'
 *    '<S509>/sec2samples'
 */
void Model_TranslationEngine64_sec2samples(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/EntertainmentLevelDetection/AudiopilotLevelDetect/AudiopilotLevelDetect/FastDecay/sec2samples': '<S484>:1' */
    /* '<S484>:1:4' y = -abs(u.Value/FrameRate); */
    localB->y = -fabsf(rtu_u->Value / 1378.125F);
}

/* Output and update for function-call system: '<S483>/tfunc' */
void FuncTranslation_Model_120_196(void)
{
    /* MATLAB Function: '<S477>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S485>:1' */
    /* '<S485>:1:3' f(); */
    Model_TranslationEngine64_sec2samples
        (&Model_TranslationEngine64_B.FastDecayDbPerS,
         &Model_TranslationEngine64_B.sf_sec2samples_b);
}

/*
 * Output and update for function-call system:
 *    '<S478>/SetPositive'
 *    '<S505>/SetPositive'
 *    '<S1410>/SetPositive'
 *    '<S1436>/SetPositive'
 *    '<S1462>/SetPositive'
 *    '<S1488>/SetPositive'
 */
void Model_TranslationEngine64_SetPositive(const bus_single_1_1 *rtu_Tune,
    B_SetPositive_Model_TranslationEngine64_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/EntertainmentLevelDetection/AudiopilotLevelDetect/AudiopilotLevelDetect/HoldMargin/SetPositive': '<S486>:1' */
    /* '<S486>:1:4' TOP = abs(Tune.Value); */
    localB->TOP = fabsf(rtu_Tune->Value);
}

/* Output and update for function-call system: '<S487>/tfunc' */
void FuncTranslation_Model_120_446(void)
{
    /* MATLAB Function: '<S478>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S488>:1' */
    /* '<S488>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb_m,
         &Model_TranslationEngine64_B.sf_SetPositive);
}

/*
 * Output and update for function-call system:
 *    '<S479>/sec2samples'
 *    '<S506>/sec2samples'
 */
void Model_TranslationEngine64_sec2samples_j(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_a_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/EntertainmentLevelDetection/AudiopilotLevelDetect/AudiopilotLevelDetect/HoldTime/sec2samples': '<S490>:1' */
    /* '<S490>:1:4' y = ceil(u.Value*FrameRate); */
    localB->y = rtu_u->Value * 1378.125F;
    localB->y = ceilf(localB->y);
}

/* Output and update for function-call system: '<S489>/tfunc' */
void FuncTranslation_Model_120_203(void)
{
    /* MATLAB Function: '<S479>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S491>:1' */
    /* '<S491>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_j
        (&Model_TranslationEngine64_B.HoldTimeS,
         &Model_TranslationEngine64_B.sf_sec2samples_j);
}

/* Output and update for function-call system: '<S494>/tfunc' */
void FuncTranslation_Model_120_122_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S492>/Subsystem' */
    /* SignalConversion generated from: '<S493>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S495>:1' */
    /* '<S495>:1:3' f(); */
    Model_TranslationEngine64_B.Value_p4 =
        Model_TranslationEngine64_B.MaxVolumeDb_l.Value;

    /* End of Outputs for SubSystem: '<S492>/Subsystem' */
}

/* Output and update for function-call system: '<S498>/tfunc' */
void FuncTranslation_Model_120_123_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S496>/Subsystem' */
    /* SignalConversion generated from: '<S497>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S499>:1' */
    /* '<S499>:1:3' f(); */
    Model_TranslationEngine64_B.Value_nm =
        Model_TranslationEngine64_B.MinVolumeDb_j.Value;

    /* End of Outputs for SubSystem: '<S496>/Subsystem' */
}

/* Output and update for function-call system: '<S500>/tfunc' */
void FuncTranslation_Model_120_189(void)
{
    /* MATLAB Function: '<S482>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S502>:1' */
    /* '<S502>:1:3' f(); */
    Model_TranslationEngine64_sec2samples
        (&Model_TranslationEngine64_B.SlowDecayDbPerS,
         &Model_TranslationEngine64_B.sf_sec2samples_ow);
}

/* Output and update for function-call system: '<S510>/tfunc' */
void FuncTranslation_Model_120_264(void)
{
    /* MATLAB Function: '<S504>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S512>:1' */
    /* '<S512>:1:3' f(); */
    Model_TranslationEngine64_sec2samples
        (&Model_TranslationEngine64_B.FastDecayDbPerS_k,
         &Model_TranslationEngine64_B.sf_sec2samples_f1);
}

/* Output and update for function-call system: '<S514>/tfunc' */
void FuncTranslation_Model_120_514(void)
{
    /* MATLAB Function: '<S505>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S515>:1' */
    /* '<S515>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb_ma,
         &Model_TranslationEngine64_B.sf_SetPositive_ko);
}

/* Output and update for function-call system: '<S516>/tfunc' */
void FuncTranslation_Model_120_257(void)
{
    /* MATLAB Function: '<S506>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S518>:1' */
    /* '<S518>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_j
        (&Model_TranslationEngine64_B.HoldTimeS_p,
         &Model_TranslationEngine64_B.sf_sec2samples_ki);
}

/* Output and update for function-call system: '<S521>/tfunc' */
void FuncTranslation_Model_120_218_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S519>/Subsystem' */
    /* SignalConversion generated from: '<S520>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S522>:1' */
    /* '<S522>:1:3' f(); */
    Model_TranslationEngine64_B.Value_if =
        Model_TranslationEngine64_B.MaxVolumeDb_e.Value;

    /* End of Outputs for SubSystem: '<S519>/Subsystem' */
}

/* Output and update for function-call system: '<S525>/tfunc' */
void FuncTranslation_Model_120_219_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S523>/Subsystem' */
    /* SignalConversion generated from: '<S524>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S526>:1' */
    /* '<S526>:1:3' f(); */
    Model_TranslationEngine64_B.Value_dm =
        Model_TranslationEngine64_B.MinVolumeDb_c.Value;

    /* End of Outputs for SubSystem: '<S523>/Subsystem' */
}

/* Output and update for function-call system: '<S527>/tfunc' */
void FuncTranslation_Model_120_250(void)
{
    /* MATLAB Function: '<S509>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S529>:1' */
    /* '<S529>:1:3' f(); */
    Model_TranslationEngine64_sec2samples
        (&Model_TranslationEngine64_B.SlowDecayDbPerS_k,
         &Model_TranslationEngine64_B.sf_sec2samples_ocq);
}

/* Output and update for function-call system: '<S534>/tfunc' */
void FuncTranslation_Model_120_439(void)
{
    int32_T i;
    real32_T Samples;
    char_T b_data[56];
    static const char_T c[56] =
        "Delay amount cannot be greater than specified max delay";

    /* MATLAB Function: '<S530>/Ms2Samples' */
    /* MATLAB Function: '<S530>/Ms2Samples' incorporates:
     *  S-Function (TuneVarMEX): '<S530>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S535>:1' */
    /* '<S535>:1:3' f(); */
    /*  Convert delay time to delay samples */
    /*  Check that delay time in msec will not exceed allotted delay buffer */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/EntertainmentLevelDetection/PreProcessing/MusicDelay/Ms2Samples': '<S533>:1' */
    /* '<S533>:1:5' Samples = floor(DelayTimeMs.Value*SampleRate/1000); */
    Samples = floorf(Model_TranslationEngine64_B.LatencyMs.Value * 44100.0F /
                     1000.0F);

    /*  Use floor to minimize the risk of going noncausal  */
    /* '<S533>:1:8' if Samples > MaxLatencySamples */
    if ((real_T)Samples > Model_TranslationEngine64_ConstB.CapturedTuneConst_dc)
    {
        /* '<S533>:1:9' TranslateError('Delay amount cannot be greater than specified max delay'); */
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
        for (i = 0; i < 56; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);
    }

    Model_TranslationEngine64_B.Samples = Samples;

    /* End of MATLAB Function: '<S530>/Ms2Samples' */
}

/* Function for MATLAB Function: '<S537>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_n(int32_T b,
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

/* Output and update for function-call system: '<S538>/tfunc' */
void FuncTranslation_Model_120_422_50_36(void)
{
    real_T ChannelCoeffs[8];
    real_T OverallGainPerCh[2];
    int32_T g_data[8];
    int32_T tmp_data[8];
    int32_T NumStages[2];
    int32_T c_data[2];
    int32_T ts_data[2];
    int32_T SOSIndex;
    int32_T c_k;
    int32_T i;
    int32_T vlen;
    int32_T yk;
    real32_T ChannelSOS_data[12];
    real32_T PoolCoeffs[8];
    real32_T x;
    real32_T y;
    char_T e_data[31];
    static const char_T f[31] = "Too many second order sections";

    /* MATLAB Function: '<S537>/Translation' */
    /* MATLAB Function: '<S537>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S537>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S537>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S540>:1' */
    /* '<S540>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/EntertainmentLevelDetection/PreProcessing/PreEmphasisShelfFilter/InnerLink/PoolIirTunableWithReset/Translation': '<S539>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S539>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S539>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S539>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    x = roundf(Model_TranslationEngine64_B.numStages_nv.Value[0]);
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

    Model_TranslationEngine64_B.PoolNumStages_g[0] = 0;
    y = roundf(Model_TranslationEngine64_B.numStages_nv.Value[1]);
    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            NumStages[1] = (int32_T)y;
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

    Model_TranslationEngine64_B.PoolNumStages_g[1] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&ChannelCoeffs[0], 0, sizeof(real_T) << 3U);
    for (i = 0; i < 8; i++)
    {
        PoolCoeffs[i] = 0.0F;
    }

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            vlen = (int32_T)x;
        }
        else
        {
            vlen = MIN_int32_T;
        }
    }
    else
    {
        vlen = MAX_int32_T;
    }

    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            c_k = (int32_T)y;
        }
        else
        {
            c_k = MIN_int32_T;
        }
    }
    else
    {
        c_k = MAX_int32_T;
    }

    if ((real_T)vlen + (real_T)c_k > 2.0)
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
        for (vlen = 0; vlen < 31; vlen++)
        {
            e_data[vlen] = f[vlen];
        }

        TranslateError(&e_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (i = 0; i < 2; i++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[i];
        OverallGainPerCh[i] = 1.0;

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
            Model_TranslationEngine64_eml_integer_colon_dispatcher_n(NumStages_0,
                tmp_data, ts_data);
            ChannelSOS_size_idx_0 = ts_data[1];
            yk = ts_data[1];
            for (vlen = 0; vlen < 6; vlen++)
            {
                for (c_k = 0; c_k < yk; c_k++)
                {
                    q1 = tmp_data[c_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    ChannelSOS_data[c_k + ChannelSOS_size_idx_0 * vlen] =
                        Model_TranslationEngine64_B.sosCoefficients_ji.Value
                        [((vlen << 1) + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (ts_data[1] == 0)
            {
                x = 1.0F;
            }
            else
            {
                x = ChannelSOS_data[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    x *= ChannelSOS_data[1];
                }
            }

            if (ts_data[1] == 0)
            {
                y = 1.0F;
            }
            else
            {
                y = ChannelSOS_data[ts_data[1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    y *= ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + 1];
                }
            }

            OverallGainPerCh[i] = x / y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            if (vlen < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = (int32_T)((uint32_T)(vlen - 1) >> 2) + 1;
            }

            ts_size_idx_1 = vlen;
            if (vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (c_k = 2; c_k <= vlen; c_k++)
                {
                    yk += 4;
                    ts_data[1] = yk;
                }
            }

            yk = vlen - 1;
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k < -2147483647)
                {
                    ts_data[vlen] = MIN_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            c_k = (ts_size_idx_1 / 4) << 2;
            q1 = c_k - 4;
            for (vlen = 0; vlen <= q1; vlen += 4)
            {
                __m128i tmp_0;
                tmp_0 = _mm_loadu_si128((const __m128i *)&ts_data[vlen]);
                _mm_storeu_si128((__m128i *)&c_data[vlen], _mm_add_epi32(tmp_0,
                                  _mm_set1_epi32(1)));
            }

            for (vlen = c_k; vlen < ts_size_idx_1; vlen++)
            {
                c_data[vlen] = ts_data[vlen] + 1;
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = -ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483645)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 2;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = ChannelSOS_data[vlen +
                    ChannelSOS_size_idx_0] / ChannelSOS_data[vlen];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483644)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 3;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] =
                    -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            yk = ts_size_idx_1 - 1;
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483643)
                {
                    ts_data[vlen] = MAX_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k + 4;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[ts_data[vlen] - 1] = ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + vlen] / ChannelSOS_data[vlen];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (i < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = Model_TranslationEngine64_B.PoolNumStages_g[0];
            }

            offset = 4.0 * (real_T)vlen;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_g[i] = NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_n(vlen,
                tmp_data, ts_data);
            c_k = ts_data[1];
            yk = ts_data[1];
            for (vlen = 0; vlen < yk; vlen++)
            {
                real_T tmp;
                tmp = offset + (real_T)tmp_data[vlen];
                if (tmp < 2.147483648E+9)
                {
                    if (tmp >= -2.147483648E+9)
                    {
                        g_data[vlen] = (int32_T)tmp;
                    }
                    else
                    {
                        g_data[vlen] = MIN_int32_T;
                    }
                }
                else
                {
                    g_data[vlen] = MAX_int32_T;
                }
            }

            for (vlen = 0; vlen < c_k; vlen++)
            {
                PoolCoeffs[g_data[vlen] - 1] = (real32_T)ChannelCoeffs[vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    for (i = 0; i < 8; i++)
    {
        Model_TranslationEngine64_B.PoolCoeffs_c[i] = PoolCoeffs[i];
    }

    Model_TranslationEngine64_B.PoolCoeffs_c[8] = (real32_T)OverallGainPerCh[0];
    Model_TranslationEngine64_B.PoolCoeffs_c[9] = (real32_T)OverallGainPerCh[1];

    /* End of MATLAB Function: '<S537>/Translation' */
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

/* Output and update for function-call system: '<S543>/tfunc' */
void FuncTranslation_Model_120_319_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S541>/Subsystem' */
    /* SignalConversion generated from: '<S542>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S544>:1' */
    /* '<S544>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hl =
        Model_TranslationEngine64_B.SysMaxDbspl_l.Value;

    /* End of Outputs for SubSystem: '<S541>/Subsystem' */
}

/* Output and update for function-call system: '<S547>/tfunc' */
void FuncTranslation_Model_123_280(void)
{
    real_T b_b_data[8];
    real_T x;
    int32_T idx_data[8];
    int32_T iwork_data[8];
    int32_T c_i;
    int32_T f_j;
    int32_T i;
    int32_T i2;
    int32_T kEnd;
    int32_T pEnd;
    int32_T qEnd;
    char_T h_data[77];
    char_T f_data[74];
    char_T g_data[6];
    static const char_T r[74] =
        "%s must have at least 2 index pairs. Encounted value with only %f pairs\\n";
    static const char_T t[77] =
        "%s out of range table index %f encountered. Index must be between 0 and 1.\\n";
    static const char_T s[6] = "Table";
    boolean_T exitg1;

    /* MATLAB Function: '<S545>/table translation' */
    /* MATLAB Function: '<S545>/table translation' incorporates:
     *  S-Function (TuneVarMEX): '<S545>/TuneVar_Table'
     *
     * Block description for '<S545>/TuneVar_Table':
     *  <HTML>Gain table maps index to gain.
     *  The index values are <FONT color="red">normalized</Font> floats between 0 and 1 while the gains are in dB (i.e. 0 implies no attenuation).
     *  </html>
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S550>:1' */
    /* '<S550>:1:3' f(); */
    /*  */
    /*  Demux table matrix into one dimesional value and index vectors */
    /*  */
    /*  Set up the size and datatype of our TOP outputs: */
    /* MATLAB Function 'ModelPreAmp/DecRate/AudioPilot35/Volume/Index2DbTable/table translation': '<S549>:1' */
    /* '<S549>:1:8' maxTableSize = numel(Table.Value) / 2; */
    /* '<S549>:1:9' idxType = 'uint8'; */
    /* '<S549>:1:10' idxStorageType = 'uint32'; */
    /* '<S549>:1:11' dbType = 'single'; */
    /* '<S549>:1:12' Table_Idx = zeros(1,maxTableSize,idxStorageType); */
    /* '<S549>:1:13' Table_dB = zeros(1,maxTableSize,dbType); */
    for (i = 0; i < 8; i++)
    {
        Model_TranslationEngine64_B.Table_Idx[i] = 0U;
        Model_TranslationEngine64_B.Table_dB[i] = 0.0F;
    }

    /*  separate the pairs into their index and value components */
    /* '<S549>:1:16' givenPairs = Table.Size(1); */
    /* '<S549>:1:17' indexes = Table.Value(1:givenPairs,1); */
    if (Model_TranslationEngine64_B.Table_f.Size[0] < 1.0)
    {
        i = 0;
    }
    else
    {
        i = (int32_T)Model_TranslationEngine64_B.Table_f.Size[0];
    }

    /* '<S549>:1:18' values = Table.Value(1:givenPairs,2); */
    /*  then sort and ignore duplicates */
    /* '<S549>:1:21' [cleanIdx,map] = unique(indexes); */
    if (i - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)i * sizeof(int32_T));
    }

    if (i != 0)
    {
        for (c_i = 1; c_i <= i - 1; c_i += 2)
        {
            if ((Model_TranslationEngine64_B.Table_f.Value[c_i - 1] <=
                    Model_TranslationEngine64_B.Table_f.Value[c_i]) || rtIsNaN
                    (Model_TranslationEngine64_B.Table_f.Value[c_i]))
            {
                idx_data[c_i - 1] = c_i;
                idx_data[c_i] = c_i + 1;
            }
            else
            {
                idx_data[c_i - 1] = c_i + 1;
                idx_data[c_i] = c_i;
            }
        }

        if (((uint32_T)i & 1U) != 0U)
        {
            idx_data[i - 1] = i;
        }

        c_i = 2;
        while (c_i < i)
        {
            i2 = c_i << 1;
            f_j = 1;
            pEnd = c_i + 1;
            while (pEnd < i + 1)
            {
                int32_T f_k;
                int32_T p;
                int32_T q;
                p = f_j;
                q = pEnd - 1;
                qEnd = f_j + i2;
                if (qEnd > i + 1)
                {
                    qEnd = i + 1;
                }

                f_k = 0;
                kEnd = qEnd - f_j;
                while (f_k + 1 <= kEnd)
                {
                    int32_T b_b_tmp_tmp;
                    x = Model_TranslationEngine64_B.Table_f.Value[idx_data[q] -
                        1];
                    b_b_tmp_tmp = idx_data[p - 1];
                    if ((Model_TranslationEngine64_B.Table_f.Value[b_b_tmp_tmp -
                         1] <= x) || rtIsNaN(x))
                    {
                        iwork_data[f_k] = b_b_tmp_tmp;
                        p++;
                        if (p == pEnd)
                        {
                            while (q + 1 < qEnd)
                            {
                                f_k++;
                                iwork_data[f_k] = idx_data[q];
                                q++;
                            }
                        }
                    }
                    else
                    {
                        iwork_data[f_k] = idx_data[q];
                        q++;
                        if (q + 1 == qEnd)
                        {
                            while (p < pEnd)
                            {
                                f_k++;
                                iwork_data[f_k] = idx_data[p - 1];
                                p++;
                            }
                        }
                    }

                    f_k++;
                }

                for (pEnd = 0; pEnd < kEnd; pEnd++)
                {
                    idx_data[(f_j + pEnd) - 1] = iwork_data[pEnd];
                }

                f_j = qEnd;
                pEnd = qEnd + c_i;
            }

            c_i = i2;
        }
    }

    c_i = (uint8_T)i;
    for (i2 = 0; i2 < c_i; i2++)
    {
        b_b_data[i2] = Model_TranslationEngine64_B.Table_f.Value[idx_data[i2] -
            1];
    }

    f_j = 0;
    while ((f_j + 1 <= i) && rtIsInf(b_b_data[f_j]) && (b_b_data[f_j] < 0.0))
    {
        f_j++;
    }

    c_i = f_j;
    f_j = i;
    while ((f_j >= 1) && rtIsNaN(b_b_data[f_j - 1]))
    {
        f_j--;
    }

    i2 = i - f_j;
    exitg1 = false;
    while ((!exitg1) && (f_j >= 1))
    {
        x = b_b_data[f_j - 1];
        if (rtIsInf(x) && (x > 0.0))
        {
            f_j--;
        }
        else
        {
            exitg1 = true;
        }
    }

    qEnd = (i - f_j) - i2;
    i = -1;
    if (c_i > 0)
    {
        i = 0;
    }

    while (c_i + 1 <= f_j)
    {
        x = b_b_data[c_i];
        kEnd = c_i;
        do
        {
            c_i++;
        }
        while (!((c_i + 1 > f_j) || (b_b_data[c_i] != x)));

        i++;
        b_b_data[i] = x;
        idx_data[i] = idx_data[kEnd];
    }

    if (qEnd > 0)
    {
        i++;
        b_b_data[i] = b_b_data[f_j];
        idx_data[i] = idx_data[f_j];
    }

    c_i = (f_j + qEnd) - 1;
    for (f_j = 0; f_j < i2; f_j++)
    {
        qEnd = (f_j + c_i) + 1;
        pEnd = (i + f_j) + 1;
        b_b_data[pEnd] = b_b_data[qEnd];
        idx_data[pEnd] = idx_data[qEnd];
    }

    i = (i + i2) + 1;
    if (i < 1)
    {
        c_i = -1;
    }
    else
    {
        c_i = i - 1;
    }

    pEnd = i;
    i = (uint8_T)i;
    if (i - 1 >= 0)
    {
        memcpy(&iwork_data[0], &idx_data[0], (uint32_T)i * sizeof(int32_T));
    }

    /*  Validate input sizes */
    /* '<S549>:1:24' numPairs = numel(map); */
    /* '<S549>:1:25' argName='Table'; */
    /*  Validate: enough data? */
    /* '<S549>:1:28' if (numPairs < 2) */
    if (pEnd < 2)
    {
        /* '<S549>:1:29' TranslateError('%s must have at least 2 index pairs. Encounted value with only %f pairs\n', argName, numPairs); */
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
        memcpy(&f_data[0], &r[0], 74U * sizeof(char_T));
        for (qEnd = 0; qEnd < 6; qEnd++)
        {
            g_data[qEnd] = s[qEnd];
        }

        TranslateError(&f_data[0], &g_data[0], (real_T)pEnd);
    }

    /*  Validate: Highest index still below 1.0? */
    /* '<S549>:1:33' if (cleanIdx(end) > 1) */
    if (b_b_data[c_i] > 1.0)
    {
        /* '<S549>:1:34' TranslateError('%s out of range table index %f encountered. Index must be between 0 and 1.\n',argName,cleanIdx(end)); */
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
        memcpy(&h_data[0], &t[0], 77U * sizeof(char_T));
        for (qEnd = 0; qEnd < 6; qEnd++)
        {
            g_data[qEnd] = s[qEnd];
        }

        TranslateError(&h_data[0], &g_data[0], b_b_data[c_i]);
    }

    /*  fill in the table buffer with provided pairs */
    /* '<S549>:1:38' for i=1:numPairs */
    for (i2 = 0; i2 < pEnd; i2++)
    {
        /* '<S549>:1:39' Table_Idx(i) = intmax(idxType) * cleanIdx(i); */
        Model_TranslationEngine64_B.Table_Idx[i2] = (uint8_T)rt_roundd_snf(255.0
            * b_b_data[i2]);

        /* '<S549>:1:40' Table_dB(i) = values(map(i)); */
        Model_TranslationEngine64_B.Table_dB[i2] = (real32_T)
            Model_TranslationEngine64_B.Table_f.Value[iwork_data[i2] + 7];
    }

    /*  fill the rest of the table buffer with the last entry */
    /* '<S549>:1:43' for j=numel(map)+1:maxTableSize */
    f_j = 7 - pEnd;
    for (c_i = 0; c_i <= f_j; c_i++)
    {
        i2 = pEnd + c_i;

        /* '<S549>:1:44' Table_Idx(j) = Table_Idx(numPairs); */
        Model_TranslationEngine64_B.Table_Idx[i2] =
            Model_TranslationEngine64_B.Table_Idx[pEnd - 1];

        /* '<S549>:1:45' Table_dB(j) =  Table_dB(numPairs); */
        Model_TranslationEngine64_B.Table_dB[i2] =
            Model_TranslationEngine64_B.Table_dB[pEnd - 1];
    }

    /* End of MATLAB Function: '<S545>/table translation' */
}

/* Output and update for function-call system: '<S553>/tfunc' */
void FuncTranslation_Model_123_281_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S551>/Subsystem' */
    /* SignalConversion generated from: '<S552>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S554>:1' */
    /* '<S554>:1:3' f(); */
    Model_TranslationEngine64_B.Value_oi =
        Model_TranslationEngine64_B.maxgain.Value;

    /* End of Outputs for SubSystem: '<S551>/Subsystem' */
}

/* Output and update for function-call system: '<S557>/tfunc' */
void FuncTranslation_Model_123_256_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S555>/Subsystem' */
    /* SignalConversion generated from: '<S556>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S558>:1' */
    /* '<S558>:1:3' f(); */
    Model_TranslationEngine64_B.Value_jc =
        Model_TranslationEngine64_B.RampTime_d.Value;

    /* End of Outputs for SubSystem: '<S555>/Subsystem' */
}

/* Output and update for function-call system: '<S566>/tfunc' */
void FuncTranslation_Model_135_79(void)
{
    /* MATLAB Function: '<S565>/channel_ramper_translation' */
    /* MATLAB Function: '<S565>/channel_ramper_translation' incorporates:
     *  S-Function (TuneVarMEX): '<S565>/TuneVarChanRampMap'
     *
     * Block description for '<S565>/TuneVarChanRampMap':
     *  Specifies the ramper to which each channel is mapped. Replace the channel number with:
     *  '1' - 'Right'; '2' - 'Left'; '3' - 'Center'. Currently, the 'Center' group is assigned a linear gain of 1.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S574>:1' */
    /* '<S574>:1:3' f(); */
    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/Balance/Balance/channel_ramper_translation': '<S573>:1' */
    /*  Verifies if each channel is assigned to one of the 4 possible rampers.  */
    /*  Acceptable rampers: */
    /*  1: left */
    /*  2: right */
    /*  3: center */
    /*  4: unused */
    /* '<S573>:1:11' argName = 'Balance'; */
    /*  Ensure each channel is present in the map */
    /* '<S573>:1:14' inputMapWidth = numel(TuneChanRampMap.Value); */
    /* '<S573>:1:15' if (inputMapWidth ~= channelCount) */
    /*  Verify that the channels are assigned to valid group numbers. */
    /* '<S573>:1:24' if (numel(unique(TuneChanRampMap.Value)) > (MaskNumRampers + 1)) */
    /* '<S573>:1:31' if (sum(TuneChanRampMap.Value == 0) > 0) */
    /* '<S573>:1:37' ChanRampMap = int32(TuneChanRampMap.Value); */
    Model_TranslationEngine64_B.ChanRampMap_o[0] = (int32_T)rt_roundd_snf
        (Model_TranslationEngine64_B.ChanRampMap.Value[0]);
    Model_TranslationEngine64_B.ChanRampMap_o[1] = (int32_T)rt_roundd_snf
        (Model_TranslationEngine64_B.ChanRampMap.Value[1]);
}

/* Output and update for function-call system: '<S577>/tfunc' */
void FuncTranslation_Model_135_81_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S575>/Subsystem' */
    /* SignalConversion generated from: '<S576>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S578>:1' */
    /* '<S578>:1:3' f(); */
    Model_TranslationEngine64_B.Value_lh =
        Model_TranslationEngine64_B.BoostDisable_c.Value;

    /* End of Outputs for SubSystem: '<S575>/Subsystem' */
}

/* Output and update for function-call system: '<S581>/tfunc' */
void FuncTranslation_Model_135_83_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S579>/Subsystem' */
    /* SignalConversion generated from: '<S580>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S582>:1' */
    /* '<S582>:1:3' f(); */
    Model_TranslationEngine64_B.Value_juf =
        Model_TranslationEngine64_B.Offset_f.Value;

    /* End of Outputs for SubSystem: '<S579>/Subsystem' */
}

/* Output and update for function-call system: '<S585>/tfunc' */
void FuncTranslation_Model_135_84_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S583>/Subsystem' */
    /* SignalConversion generated from: '<S584>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S586>:1' */
    /* '<S586>:1:3' f(); */
    Model_TranslationEngine64_B.Value_fg =
        Model_TranslationEngine64_B.RampTime_i.Value;

    /* End of Outputs for SubSystem: '<S583>/Subsystem' */
}

/* Output and update for function-call system: '<S589>/tfunc' */
void FuncTranslation_Model_135_143_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S587>/Subsystem' */
    /* SignalConversion generated from: '<S588>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S590>:1' */
    /* '<S590>:1:3' f(); */
    Model_TranslationEngine64_B.Value_nb =
        Model_TranslationEngine64_B.SleepingBeautyMutesBass.Value;

    /* End of Outputs for SubSystem: '<S587>/Subsystem' */
}

/* Output and update for function-call system: '<S593>/tfunc' */
void FuncTranslation_Model_135_85_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S591>/Subsystem' */
    /* SignalConversion generated from: '<S592>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S594>:1' */
    /* '<S594>:1:3' f(); */
    Model_TranslationEngine64_B.Value_fq1 =
        Model_TranslationEngine64_B.EnableSilentExtreme_f.Value;

    /* End of Outputs for SubSystem: '<S591>/Subsystem' */
}

/* Function for MATLAB Function: '<S572>/Balance_Table_Translation' */
static void Model_TranslationEngine64_unique_vector_a(const real_T a_data[],
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

/* Output and update for function-call system: '<S596>/tfunc' */
void FuncTranslation_Model_135_90(void)
{
    real_T cleanIdx_data[30];
    real_T tmp_data[30];
    int32_T indx_data[30];
    int32_T i;
    int32_T loop_ub;
    real32_T tmp_0;
    uint32_T tmp;
    char_T k_data[78];
    char_T i_data[74];
    char_T j_data[13];
    int8_T g_tmp_data[30];
    int8_T remainingPairs_data[30];
    static const char_T l[74] =
        "%s must have at least 2 index pairs. Encounted value with only %f pairs\\n";
    static const char_T m[13] = "BalanceTable";
    static const char_T n[78] =
        "%s out of range table index %f encountered. Index must be between 0 and %d.\\n";
    int32_T indx_size;
    int32_T remainingPairs_size_idx_1;

    /* MATLAB Function: '<S572>/Balance_Table_Translation' */
    /* MATLAB Function: '<S572>/Balance_Table_Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S572>/TuneVarBalanceTable'
     *
     * Block description for '<S572>/TuneVarBalanceTable':
     *  Define the balance curve using a table, with the first column being
     *  the list of indices and the second column being the corresponding
     *  balance gains in dB. Gain values for indices in between the elements
     *  in the table are linearly interpolated.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S597>:1' */
    /* '<S597>:1:3' f(); */
    /*  Set up the size and datatype of our TOP outputs: */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/Balance/Balance/TuneVarTable/Balance_Table_Translation': '<S595>:1' */
    /* '<S595>:1:5' maxTableSize = numel(balanceTable.Value) / 2; */
    /* '<S595>:1:6' idxType = 'uint8'; */
    /* '<S595>:1:7' idxStorageType = 'uint32'; */
    /* '<S595>:1:8' dbType = 'single'; */
    /* '<S595>:1:9' tableIdx = zeros(1,maxTableSize,idxStorageType); */
    /* '<S595>:1:10' tableDb = zeros(1,maxTableSize,dbType); */
    memset(&Model_TranslationEngine64_B.tableIdx_o[0], 0, 30U * sizeof(uint32_T));
    memset(&Model_TranslationEngine64_B.tableDb_j[0], 0, 30U * sizeof(real32_T));

    /*  separate the pairs into their index and value components */
    /* '<S595>:1:13' givenPairs = balanceTable.Size(1); */
    /* '<S595>:1:14' indexes = balanceTable.Value(1:givenPairs,1); */
    /* '<S595>:1:15' values = balanceTable.Value(1:givenPairs,2); */
    /*  then sort and ignore duplicates */
    /* '<S595>:1:18' [cleanIdx,map] = unique(indexes); */
    if (Model_TranslationEngine64_B.Table_i.Size[0] < 1.0)
    {
        loop_ub = -1;
    }
    else
    {
        loop_ub = (int32_T)Model_TranslationEngine64_B.Table_i.Size[0] - 1;
    }

    i = loop_ub + 1;
    if (loop_ub >= 0)
    {
        memcpy(&tmp_data[0], &Model_TranslationEngine64_B.Table_i.Value[0],
               (uint32_T)(loop_ub + 1) * sizeof(real_T));
    }

    Model_TranslationEngine64_unique_vector_a(tmp_data, &i, cleanIdx_data,
        &loop_ub, indx_data, &indx_size);

    /*  Validate input sizes */
    /* '<S595>:1:21' numPairs = numel(map); */
    /* '<S595>:1:22' argName='BalanceTable'; */
    /*  Validate: enough data? */
    /* '<S595>:1:25' if (numPairs < 2) */
    if (indx_size < 2)
    {
        /* '<S595>:1:26' TranslateError('%s must have at least 2 index pairs. Encounted value with only %f pairs\n', argName, numPairs); */
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
        for (i = 0; i < 13; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&i_data[0], &j_data[0], (real_T)indx_size);
    }

    /*  Validate: Highest index still below 255? */
    /* '<S595>:1:30' if (cleanIdx(1) < 0 || cleanIdx(end) > intmax(idxType)) */
    if ((cleanIdx_data[0] < 0.0) || (cleanIdx_data[loop_ub - 1] > 255.0))
    {
        /* '<S595>:1:31' TranslateError('%s out of range table index %f encountered. Index must be between 0 and %d.\n',argName,cleanIdx(end),intmax(idxType)); */
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
        for (i = 0; i < 13; i++)
        {
            j_data[i] = m[i];
        }

        TranslateError(&k_data[0], &j_data[0], cleanIdx_data[loop_ub - 1],
                       MAX_uint8_T);
    }

    /*  fill in the table buffer with provided pairs */
    /* '<S595>:1:35' tableIdx(1:numPairs) = cleanIdx(1:numPairs); */
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
        Model_TranslationEngine64_B.tableIdx_o[i] = (uint32_T)rt_roundd_snf
            (cleanIdx_data[i]);
    }

    /* '<S595>:1:36' tableDb(1:numPairs) = values(map(1:numPairs)); */
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
        Model_TranslationEngine64_B.tableDb_j[i] = (real32_T)
            Model_TranslationEngine64_B.Table_i.Value[indx_data[i] + 29];
    }

    /*  fill the rest of the table buffer with the last entry */
    /* '<S595>:1:39' remainingPairs = numel(map)+1:maxTableSize; */
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

    /* '<S595>:1:40' tableIdx(remainingPairs) = tableIdx(numPairs); */
    if (remainingPairs_size_idx_1 - 1 >= 0)
    {
        memcpy(&g_tmp_data[0], &remainingPairs_data[0], (uint32_T)
               remainingPairs_size_idx_1 * sizeof(int8_T));
    }

    tmp = Model_TranslationEngine64_B.tableIdx_o[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        Model_TranslationEngine64_B.tableIdx_o[g_tmp_data[i] - 1] = tmp;
    }

    /* '<S595>:1:41' tableDb(remainingPairs) =  tableDb(numPairs); */
    tmp_0 = Model_TranslationEngine64_B.tableDb_j[indx_size - 1];
    for (i = 0; i < remainingPairs_size_idx_1; i++)
    {
        Model_TranslationEngine64_B.tableDb_j[g_tmp_data[i] - 1] = tmp_0;
    }

    /* End of MATLAB Function: '<S572>/Balance_Table_Translation' */
}

/* Output and update for function-call system: '<S609>/tfunc' */
void FuncTranslation_Model_141_246_96(void)
{
    int32_T i;
    char_T c_data[62];
    char_T b_data[61];
    static const char_T d[61] =
        "Medusa Bass Manager: Left mix weights cannot be less than 0.";
    static const char_T e[62] =
        "Medusa Bass Manager: Right mix weights cannot be less than 0.";

    /* MATLAB Function: '<S605>/translation' */
    /* MATLAB Function: '<S605>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S598>/TuneVar'
     *  S-Function (TuneVarMEX): '<S605>/LeftMixIns'
     *  S-Function (TuneVarMEX): '<S605>/RightMixIns'
     *
     * Block description for '<S598>/TuneVar':
     *  General surround control parameter
     *  STEREO_MODE = 0
     *  SURROUND_PASSTHRU_MODE = 1
     *  MEDUSA_2_CHANNEL_MODE = 2
     *  MEDUSA_5_1_MODE = 3
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S611>:1' */
    /* '<S611>:1:3' f(); */
    /*  Expected Order of Weights: */
    /*  LeftMixWeightsIn = [L2L, Ls2L, Ltf2L, Ltb2L, C2L, Lfe2L] */
    /*  RightMixWeightsIn = [R2R, Rs2R, Rtf2R, Rtb2R, C2R, Lfe2R] */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 1/Bass Manager Stereo/Bass Manager Tuning/translation': '<S610>:1' */
    /* '<S610>:1:6' if (SurroundOn.Value == 3 || SurroundOn.Value == 4) */
    if ((Model_TranslationEngine64_B.SurroundOn.Value == 3.0) ||
            (Model_TranslationEngine64_B.SurroundOn.Value == 4.0))
    {
        /*  Mix weights are only applicable for 5.1 and 5.1.4 inputs */
        /*  Check if any of the tuned mix weights are negative */
        /* '<S610>:1:10' if(sum(LeftMixWeightsIn.Value < 0)) */
        if (Model_TranslationEngine64_B.LeftMixWeights.Value < 0.0)
        {
            /* '<S610>:1:11' TranslateError('Medusa Bass Manager: Left mix weights cannot be less than 0.'); */
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
            for (i = 0; i < 61; i++)
            {
                b_data[i] = d[i];
            }

            TranslateError(&b_data[0]);
        }

        /* '<S610>:1:14' if(sum(RightMixWeightsIn.Value < 0)) */
        if (Model_TranslationEngine64_B.RightMixWeights.Value < 0.0)
        {
            /* '<S610>:1:15' TranslateError('Medusa Bass Manager: Right mix weights cannot be less than 0.'); */
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
            for (i = 0; i < 62; i++)
            {
                c_data[i] = e[i];
            }

            TranslateError(&c_data[0]);
        }

        /*  Cast the mix weights to 'single' data type */
        /* '<S610>:1:19' LeftMixWeights = single(LeftMixWeightsIn.Value); */
        Model_TranslationEngine64_B.LeftMixWeights_i = (real32_T)
            Model_TranslationEngine64_B.LeftMixWeights.Value;

        /* '<S610>:1:20' RightMixWeights = single(RightMixWeightsIn.Value); */
        Model_TranslationEngine64_B.RightMixWeights_a = (real32_T)
            Model_TranslationEngine64_B.RightMixWeights.Value;

        /* '<S610>:1:22' if(SurroundOn.Value == 3 && NumInputs == 10) */
    }
    else
    {
        /* '<S610>:1:32' else */
        /*  For 2-channel input, use pre-defined weights to enable pass-through */
        /*  L2L = 1.0 */
        /*  R2R = 1.0 */
        /*  All other combinations are set to 0 */
        /*  Extracting the dimension of MixWeights */
        /* '<S610>:1:39' NumMixWeights = size(LeftMixWeightsIn.Value); */
        /* '<S610>:1:41' LeftMixWeights = single(eye(NumMixWeights)); */
        Model_TranslationEngine64_B.LeftMixWeights_i = 1.0F;

        /* '<S610>:1:42' RightMixWeights = single(eye(NumMixWeights)); */
        Model_TranslationEngine64_B.RightMixWeights_a = 1.0F;
    }

    /* End of MATLAB Function: '<S605>/translation' */
}

real_T rt_roundd_snf(real_T u)
{
    real_T y;
    if (fabs(u) < 4.503599627370496E+15)
    {
        if (u >= 0.5)
        {
            y = floor(u + 0.5);
        }
        else if (u > -0.5)
        {
            y = u * 0.0;
        }
        else
        {
            y = ceil(u - 0.5);
        }
    }
    else
    {
        y = u;
    }

    return y;
}

/* Function for MATLAB Function: '<S612>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_i(int32_T b,
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

/*
 * Output and update for function-call system:
 *    '<S612>/Translation'
 *    '<S616>/Translation'
 */
void Model_TranslationEngine64_Translation_l(const bus_double_6_6 *rtu_RawSOS,
    const bus_double_1_2 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_o_T *localB)
{
    real_T ChannelSOS_data[36];
    real_T ChannelCoeffs[24];
    real_T OverallGainPerCh[2];
    real_T b_y;
    real_T offset;
    int32_T g_data[24];
    int32_T tmp_data[24];
    int32_T c_data[6];
    int32_T ts_data[6];
    int32_T NumStages[2];
    int32_T ChannelCoeffsLength;
    int32_T SOSIndex;
    int32_T i;
    int32_T vlen;
    real32_T PoolCoeffs[24];
    char_T e_data[31];
    static const char_T f[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 1/Bass Manager Stereo/HPF/PoolIirTunableWithReset/Translation': '<S614>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S614>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S614>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S614>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    b_y = rt_roundd_snf(rtu_NumStages->Value[0]);
    if (b_y < 2.147483648E+9)
    {
        if (b_y >= -2.147483648E+9)
        {
            NumStages[0] = (int32_T)b_y;
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

    localB->PoolNumStages[0] = 0;
    offset = rt_roundd_snf(rtu_NumStages->Value[1]);
    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            NumStages[1] = (int32_T)offset;
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

    localB->PoolNumStages[1] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 24U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 24U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (b_y < 2.147483648E+9)
    {
        if (b_y >= -2.147483648E+9)
        {
            ChannelCoeffsLength = (int32_T)b_y;
        }
        else
        {
            ChannelCoeffsLength = MIN_int32_T;
        }
    }
    else
    {
        ChannelCoeffsLength = MAX_int32_T;
    }

    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            vlen = (int32_T)offset;
        }
        else
        {
            vlen = MIN_int32_T;
        }
    }
    else
    {
        vlen = MAX_int32_T;
    }

    if ((real_T)ChannelCoeffsLength + (real_T)vlen > 6.0)
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
        for (ChannelCoeffsLength = 0; ChannelCoeffsLength < 31;
                ChannelCoeffsLength++)
        {
            e_data[ChannelCoeffsLength] = f[ChannelCoeffsLength];
        }

        TranslateError(&e_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (i = 0; i < 2; i++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[i];
        OverallGainPerCh[i] = 1.0;

        /* 'PoolIirHexagonTranslationFcn:29' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* 'PoolIirHexagonTranslationFcn:30' assert(ChannelNumStages <= MaxNumStages); */
        /* 'PoolIirHexagonTranslationFcn:31' if (ChannelNumStages == 0) */
        if (NumStages_0 != 0)
        {
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;
            int32_T yk;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_i(NumStages_0,
                tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < 6;
                    ChannelCoeffsLength++)
            {
                for (vlen = 0; vlen < yk; vlen++)
                {
                    q1 = tmp_data[vlen];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    ChannelSOS_data[vlen + ChannelSOS_size_idx_0 *
                        ChannelCoeffsLength] = rtu_RawSOS->Value[(6 *
                        ChannelCoeffsLength + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset = ChannelSOS_data[0];
                for (ChannelCoeffsLength = 2; ChannelCoeffsLength <=
                        ChannelSOS_size_idx_0; ChannelCoeffsLength++)
                {
                    offset *= ChannelSOS_data[ChannelCoeffsLength - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                b_y = 1.0;
            }
            else
            {
                b_y = ChannelSOS_data[tmp_size[1] * 3];
                for (ChannelCoeffsLength = 2; ChannelCoeffsLength <=
                        ChannelSOS_size_idx_0; ChannelCoeffsLength++)
                {
                    b_y *= ChannelSOS_data[(ChannelSOS_size_idx_0 * 3 +
                                            ChannelCoeffsLength) - 1];
                }
            }

            OverallGainPerCh[i] = offset / b_y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                ChannelCoeffsLength = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                ChannelCoeffsLength = MIN_int32_T;
            }
            else
            {
                ChannelCoeffsLength = NumStages_0 << 2;
            }

            if (ChannelCoeffsLength < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = (int32_T)((uint32_T)(ChannelCoeffsLength - 1) >> 2) + 1;
            }

            ts_size_idx_1 = vlen;
            if (vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (ChannelCoeffsLength = 2; ChannelCoeffsLength <= vlen;
                        ChannelCoeffsLength++)
                {
                    yk += 4;
                    ts_data[ChannelCoeffsLength - 1] = yk;
                }
            }

            yk = vlen - 1;
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength <= yk;
                    ChannelCoeffsLength++)
            {
                vlen = ts_data[ChannelCoeffsLength];
                if (vlen < -2147483647)
                {
                    ts_data[ChannelCoeffsLength] = MIN_int32_T;
                }
                else
                {
                    ts_data[ChannelCoeffsLength] = vlen - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            vlen = (ts_size_idx_1 / 4) << 2;
            q1 = vlen - 4;
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength <= q1;
                    ChannelCoeffsLength += 4)
            {
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)
                                      &ts_data[ChannelCoeffsLength]);
                _mm_storeu_si128((__m128i *)&c_data[ChannelCoeffsLength],
                                 _mm_add_epi32(tmp, _mm_set1_epi32(1)));
            }

            for (ChannelCoeffsLength = vlen; ChannelCoeffsLength < ts_size_idx_1;
                 ChannelCoeffsLength++)
            {
                c_data[ChannelCoeffsLength] = ts_data[ChannelCoeffsLength] + 1;
            }

            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                ChannelCoeffs[c_data[ChannelCoeffsLength] - 1] =
                    -ChannelSOS_data[(ChannelSOS_size_idx_0 << 2) +
                    ChannelCoeffsLength] / ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + ChannelCoeffsLength];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                vlen = ts_data[ChannelCoeffsLength];
                if (vlen > 2147483645)
                {
                    c_data[ChannelCoeffsLength] = MAX_int32_T;
                }
                else
                {
                    c_data[ChannelCoeffsLength] = vlen + 2;
                }
            }

            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                ChannelCoeffs[c_data[ChannelCoeffsLength] - 1] =
                    ChannelSOS_data[ChannelCoeffsLength + ChannelSOS_size_idx_0]
                    / ChannelSOS_data[ChannelCoeffsLength];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                vlen = ts_data[ChannelCoeffsLength];
                if (vlen > 2147483644)
                {
                    c_data[ChannelCoeffsLength] = MAX_int32_T;
                }
                else
                {
                    c_data[ChannelCoeffsLength] = vlen + 3;
                }
            }

            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                ChannelCoeffs[c_data[ChannelCoeffsLength] - 1] =
                    -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 +
                    ChannelCoeffsLength] / ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + ChannelCoeffsLength];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength <= yk;
                    ChannelCoeffsLength++)
            {
                vlen = ts_data[ChannelCoeffsLength];
                if (vlen > 2147483643)
                {
                    ts_data[ChannelCoeffsLength] = MAX_int32_T;
                }
                else
                {
                    ts_data[ChannelCoeffsLength] = vlen + 4;
                }
            }

            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < ts_size_idx_1;
                    ChannelCoeffsLength++)
            {
                ChannelCoeffs[ts_data[ChannelCoeffsLength] - 1] =
                    ChannelSOS_data[(ChannelSOS_size_idx_0 << 1) +
                    ChannelCoeffsLength] / ChannelSOS_data[ChannelCoeffsLength];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (i < 1)
            {
                ChannelCoeffsLength = 0;
            }
            else
            {
                ChannelCoeffsLength = localB->PoolNumStages[0];
            }

            offset = 4.0 * (real_T)ChannelCoeffsLength;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            localB->PoolNumStages[i] = NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                ChannelCoeffsLength = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                ChannelCoeffsLength = MIN_int32_T;
            }
            else
            {
                ChannelCoeffsLength = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_i
                (ChannelCoeffsLength, tmp_data, tmp_size);
            vlen = tmp_size[1];
            yk = tmp_size[1];
            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < yk;
                    ChannelCoeffsLength++)
            {
                b_y = offset + (real_T)tmp_data[ChannelCoeffsLength];
                if (b_y < 2.147483648E+9)
                {
                    if (b_y >= -2.147483648E+9)
                    {
                        g_data[ChannelCoeffsLength] = (int32_T)b_y;
                    }
                    else
                    {
                        g_data[ChannelCoeffsLength] = MIN_int32_T;
                    }
                }
                else
                {
                    g_data[ChannelCoeffsLength] = MAX_int32_T;
                }
            }

            for (ChannelCoeffsLength = 0; ChannelCoeffsLength < vlen;
                    ChannelCoeffsLength++)
            {
                PoolCoeffs[g_data[ChannelCoeffsLength] - 1] = (real32_T)
                    ChannelCoeffs[ChannelCoeffsLength];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&localB->PoolCoeffs[0], &PoolCoeffs[0], 24U * sizeof(real32_T));
    localB->PoolCoeffs[24] = (real32_T)OverallGainPerCh[0];
    localB->PoolCoeffs[25] = (real32_T)OverallGainPerCh[1];

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

/* Output and update for function-call system: '<S613>/tfunc' */
void FuncTranslation_Model_141_246_141_36(void)
{
    /* MATLAB Function: '<S612>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S615>:1' */
    /* '<S615>:1:3' f(); */
    Model_TranslationEngine64_Translation_l
        (&Model_TranslationEngine64_B.sosCoefficients_c,
         &Model_TranslationEngine64_B.numStages_h,
         &Model_TranslationEngine64_B.sf_Translation_l);
}

/* Output and update for function-call system: '<S617>/tfunc' */
void FuncTranslation_Model_141_246_148_36(void)
{
    /* MATLAB Function: '<S616>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S619>:1' */
    /* '<S619>:1:3' f(); */
    Model_TranslationEngine64_Translation_l
        (&Model_TranslationEngine64_B.sosCoefficients_b,
         &Model_TranslationEngine64_B.numStages_nz,
         &Model_TranslationEngine64_B.sf_Translation_jt);
}

/* Output and update for function-call system: '<S622>/tfunc' */
void FuncTranslation_Model_141_246_111_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S620>/Subsystem' */
    /* SignalConversion generated from: '<S621>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S623>:1' */
    /* '<S623>:1:3' f(); */
    Model_TranslationEngine64_B.Value_br0 =
        Model_TranslationEngine64_B.GainLfe2C.Value;

    /* End of Outputs for SubSystem: '<S620>/Subsystem' */
}

/* Output and update for function-call system: '<S628>/tfunc' */
void FuncTranslation_Model_141_1196_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S626>/Subsystem' */
    /* SignalConversion generated from: '<S627>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S629>:1' */
    /* '<S629>:1:3' f(); */
    Model_TranslationEngine64_B.Value_po =
        Model_TranslationEngine64_B.DummyTune.Value;

    /* End of Outputs for SubSystem: '<S626>/Subsystem' */
}

/* Output and update for function-call system: '<S636>/tfunc' */
void FuncTranslation_Model_141_1371(void)
{
    int32_T actualTrebleDelay;
    char_T h_data[82];
    char_T d_data[72];
    char_T b_data[70];
    char_T c_data[68];
    char_T g_data[67];
    char_T e_data[65];
    char_T f_data[63];
    static const char_T i[70] =
        "Value of \'Medusa Wiggle Delay\' must be greater than or equal to zero.";
    static const char_T j[68] =
        "Value of \'NEAR Wiggle Delay\' must be greater than or equal to zero.";
    static const char_T k[72] =
        "Value of \'Medusa Holigram Delay\' must be greater than or equal to zero.";
    static const char_T l[65] =
        "Value of \'Medusa Wiggle Delay\' must be less than or equal to %d.";
    static const char_T m[63] =
        "Value of \'NEAR Wiggle Delay\' must be less than or equal to %d.";
    static const char_T n[67] =
        "Value of \'Medusa Holigram Delay\' must be less than or equal to %d.";
    static const char_T o[82] =
        "Value of \'Medusa Treble Delay\' on full-rate path exceeds the maximum value of %d.";

    /* MATLAB Function: '<S635>/translation' */
    /* MATLAB Function: '<S635>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S630>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S630>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S630>/Tune Variable5'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S638>:1' */
    /* '<S638>:1:3' f(); */
    /* [Param:DecimationFactor] */
    /* [Param:DeciRateMaxWiggleDelay] */
    /* [Param:DeciRateMaxNearWiggleDelay] */
    /* [Param:MaxHoligramDelay] */
    /* [Param:DeciRateFdpDelay] */
    /* [Param:FullRateFdpDelay] */
    /* [Param:MaxTrebleDelay] */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Alignment Delay/Full-rate Alignment Delay Translation/translation': '<S637>:1' */
    /*  Treble Delay Translation */
    /*  This translation computes the alignment delay values for full-rate */
    /*  upmixed components */
    /*  Extracting build-time parameters from config struct */
    /* '<S637>:1:19' DEC = DecimationFactor; */
    /*  Error Check for incoming tune values */
    /* '<S637>:1:22' if(wiggleDelay.Value < 0) */
    if (Model_TranslationEngine64_AlignmentDelay_B.DeciRateWiggleFilterDelaySamples.Value
        < 0)
    {
        /* '<S637>:1:23' TranslateError('Value of ''Medusa Wiggle Delay'' must be greater than or equal to zero.'); */
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
        memcpy(&b_data[0], &i[0], 70U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S637>:1:26' if(NEARWiggleDelay.Value < 0) */
    if (Model_TranslationEngine64_AlignmentDelay_B.DeciRateNearWiggleFilterDelaySamples.Value
        < 0)
    {
        /* '<S637>:1:27' TranslateError('Value of ''NEAR Wiggle Delay'' must be greater than or equal to zero.'); */
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
        memcpy(&c_data[0], &j[0], 68U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S637>:1:30' if(holigramDelay.Value < 0) */
    if (Model_TranslationEngine64_AlignmentDelay_B.HoligramFilterAlignmentDelaySamples.Value
        < 0)
    {
        /* '<S637>:1:31' TranslateError('Value of ''Medusa Holigram Delay'' must be greater than or equal to zero.'); */
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
        memcpy(&d_data[0], &k[0], 72U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /* '<S637>:1:34' if(wiggleDelay.Value > DeciRateMaxWiggleDelay) */
    if (Model_TranslationEngine64_AlignmentDelay_B.DeciRateWiggleFilterDelaySamples.Value
        > 166)
    {
        /* '<S637>:1:35' TranslateError('Value of ''Medusa Wiggle Delay'' must be less than or equal to %d.', DeciRateMaxWiggleDelay); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&e_data[0], &l[0], 65U * sizeof(char_T));
        TranslateError(&e_data[0], 166);
    }

    /* '<S637>:1:38' if(NEARWiggleDelay.Value > DeciRateMaxNearWiggleDelay) */
    if (Model_TranslationEngine64_AlignmentDelay_B.DeciRateNearWiggleFilterDelaySamples.Value
        > 166)
    {
        /* '<S637>:1:39' TranslateError('Value of ''NEAR Wiggle Delay'' must be less than or equal to %d.', DeciRateMaxNearWiggleDelay); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (actualTrebleDelay = 0; actualTrebleDelay < 63; actualTrebleDelay++)
        {
            f_data[actualTrebleDelay] = m[actualTrebleDelay];
        }

        TranslateError(&f_data[0], 166);
    }

    /* '<S637>:1:42' if(holigramDelay.Value > MaxHoligramDelay) */
    if (Model_TranslationEngine64_AlignmentDelay_B.HoligramFilterAlignmentDelaySamples.Value
        > 1764)
    {
        /* '<S637>:1:43' TranslateError('Value of ''Medusa Holigram Delay'' must be less than or equal to %d.', MaxHoligramDelay); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&g_data[0], &n[0], 67U * sizeof(char_T));
        TranslateError(&g_data[0], 1764);
    }

    /*  Computing the alignment delay values for treble path */
    /*  Medusa wiggle filter latency */
    /* '<S637>:1:48' wiggleDelayDec = int32(round(wiggleDelay.Value)); */
    /* '<S637>:1:49' wiggleDelayFull = int32(wiggleDelayDec * DEC); */
    /*  NEAR wiggle filter latency */
    /* '<S637>:1:52' NEARWiggleDelayDec = int32(round(NEARWiggleDelay.Value)); */
    /* '<S637>:1:53' NEARWiggleDelayFull = int32(NEARWiggleDelayDec * DEC); */
    /*  Holigram filter latency */
    /* '<S637>:1:56' holigramDelayFull = int32(round(holigramDelay.Value)); */
    /*  Compute the treble alignment delay (applies to full-rate upmixed components) */
    /* '<S637>:1:59' actualTrebleDelay = DeciRateFdpDelay - FullRateFdpDelay + wiggleDelayFull + NEARWiggleDelayFull + holigramDelayFull; */
    actualTrebleDelay =
        (((Model_TranslationEngine64_AlignmentDelay_B.DeciRateWiggleFilterDelaySamples.Value
           << 2) +
          (Model_TranslationEngine64_AlignmentDelay_B.DeciRateNearWiggleFilterDelaySamples.Value
           << 2)) +
         Model_TranslationEngine64_AlignmentDelay_B.HoligramFilterAlignmentDelaySamples.Value)
        + 1152;

    /*  Error check for outgoing alignment delay value */
    /* '<S637>:1:62' if(actualTrebleDelay > MaxTrebleDelay) */
    if (actualTrebleDelay > 4244)
    {
        /* '<S637>:1:63' TranslateError('Value of ''Medusa Treble Delay'' on full-rate path exceeds the maximum value of %d.', MaxTrebleDelay); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&h_data[0], &o[0], 82U * sizeof(char_T));
        TranslateError(&h_data[0], 4244);
    }

    /*  Assigning output */
    /* '<S637>:1:67' trebleDelay = actualTrebleDelay; */
    Model_TranslationEngine64_AlignmentDelay_B.trebleDelay = actualTrebleDelay;

    /* End of MATLAB Function: '<S635>/translation' */
}

/* Output and update for function-call system: '<S647>/tfunc' */
void FuncTranslation_Model_141_1560(void)
{
    int32_T i;
    char_T b_data[58];
    char_T c_data[26];
    static const char_T d[58] =
        "XpMin must be no less than 0.0, and must be less than 1.0";
    static const char_T e[58] =
        "XpMax must be no less than 0.0, and must be less than 1.0";
    static const char_T f[26] = "XpMin cannot exceed XpMax";

    /* MATLAB Function: '<S646>/Trivial Translation' */
    /* MATLAB Function: '<S646>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S639>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S646>/Tune Variable3'
     *
     * Block description for '<S639>/Tune Variable7':
     *  Minimum stretch factor - must be in range [0,1)
     *
     * Block description for '<S646>/Tune Variable3':
     *  Minimum stretch factor - must be in range [0,1).
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S651>:1' */
    /* '<S651>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Decimated-Rate FDP/Fdp/FreqDomainProcessing/CalculateAndApplyCoefficients/DeciRate/Calculate coefficients/StretchParamsTuning/Trivial Translation': '<S649>:1' */
    /* '<S649>:1:3' XpMax = XpMaxIn.Value; */
    /* '<S649>:1:4' XpMin = XpMinIn.Value; */
    /* '<S649>:1:5' if (XpMin < 0) || (XpMin >= 1) */
    if ((Model_TranslationEngine64_B.XpMin.Value < 0.0) ||
            (Model_TranslationEngine64_B.XpMin.Value >= 1.0))
    {
        /* '<S649>:1:6' TranslateError('XpMin must be no less than 0.0, and must be less than 1.0'); */
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
        for (i = 0; i < 58; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S649>:1:9' if (XpMax < 0) || (XpMax >= 1) */
    if ((Model_TranslationEngine64_B.XpMax.Value < 0.0) ||
            (Model_TranslationEngine64_B.XpMax.Value >= 1.0))
    {
        /* '<S649>:1:10' TranslateError('XpMax must be no less than 0.0, and must be less than 1.0'); */
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
        for (i = 0; i < 58; i++)
        {
            b_data[i] = e[i];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S649>:1:13' if (XpMax < XpMin) */
    if (Model_TranslationEngine64_B.XpMax.Value <
            Model_TranslationEngine64_B.XpMin.Value)
    {
        /* '<S649>:1:14' TranslateError('XpMin cannot exceed XpMax'); */
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
        for (i = 0; i < 26; i++)
        {
            c_data[i] = f[i];
        }

        TranslateError(&c_data[0]);
    }

    /* '<S649>:1:17' if (XpMax == 1) */
    if (Model_TranslationEngine64_B.XpMax.Value == 1.0)
    {
        /* '<S649>:1:18' LokRokMaxScaleFactor = 0; */
        Model_TranslationEngine64_B.LokRokMaxScaleFactor_a = 0.0;
    }
    else
    {
        /* '<S649>:1:19' else */
        /* '<S649>:1:20' LokRokMaxScaleFactor = 0.5 * XpMax / (1 - XpMax); */
        Model_TranslationEngine64_B.LokRokMaxScaleFactor_a = 0.5 *
            Model_TranslationEngine64_B.XpMax.Value / (1.0 -
            Model_TranslationEngine64_B.XpMax.Value);
    }

    Model_TranslationEngine64_B.XpMax_g =
        Model_TranslationEngine64_B.XpMax.Value;
    Model_TranslationEngine64_B.XpMin_d =
        Model_TranslationEngine64_B.XpMin.Value;

    /* End of MATLAB Function: '<S646>/Trivial Translation' */
}

/*
 * Output and update for function-call system:
 *    '<S646>/Trivial Translation3'
 *    '<S673>/Trivial Translation3'
 */
void Model_TranslationEngine64_TrivialTranslation3(const bus_double_1_1
    *rtu_ESDUpperbounddBIn, const bus_double_1_1 *rtu_ESDLowerbounddBIn,
    B_TrivialTranslation3_Model_TranslationEngine64_T *localB)
{
    int32_T i;
    char_T b_data[62];
    static const char_T c[62] =
        "Lower threshold for ESD cannot exceed upper threshold for ESD";

    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Decimated-Rate FDP/Fdp/FreqDomainProcessing/CalculateAndApplyCoefficients/DeciRate/Calculate coefficients/StretchParamsTuning/Trivial Translation3': '<S650>:1' */
    /* '<S650>:1:4' if (ESDUpperbounddBIn.Value >= ESDLowerbounddBIn.Value) */
    if (rtu_ESDUpperbounddBIn->Value >= rtu_ESDLowerbounddBIn->Value)
    {
        /* '<S650>:1:5' ESDUpperbounddB = ESDUpperbounddBIn.Value; */
        localB->ESDUpperbounddB = rtu_ESDUpperbounddBIn->Value;

        /* '<S650>:1:6' ESDLowerbounddB = ESDLowerbounddBIn.Value; */
        localB->ESDLowerbounddB = rtu_ESDLowerbounddBIn->Value;
    }
    else
    {
        /* '<S650>:1:7' else */
        /* '<S650>:1:8' TranslateError('Lower threshold for ESD cannot exceed upper threshold for ESD'); */
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
        for (i = 0; i < 62; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);

        /* '<S650>:1:9' ESDUpperbounddB = 0; */
        localB->ESDUpperbounddB = 0.0;

        /* '<S650>:1:10' ESDLowerbounddB = 0; */
        localB->ESDLowerbounddB = 0.0;
    }

    /* '<S650>:1:13' if (ESDUpperbounddBIn.Value == ESDLowerbounddBIn.Value) */
    if (rtu_ESDUpperbounddBIn->Value == rtu_ESDLowerbounddBIn->Value)
    {
        /* '<S650>:1:14' ESDStepSize = 0; */
        localB->ESDStepSize = 0.0;
    }
    else
    {
        /* '<S650>:1:15' else */
        /* '<S650>:1:16' ESDStepSize = 1/abs(ESDUpperbounddBIn.Value - ESDLowerbounddBIn.Value); */
        localB->ESDStepSize = 1.0 / fabs(rtu_ESDUpperbounddBIn->Value -
            rtu_ESDLowerbounddBIn->Value);
    }
}

/* Output and update for function-call system: '<S648>/tfunc' */
void FuncTranslation_Model_141_1561(void)
{
    /* MATLAB Function: '<S646>/Trivial Translation3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S652>:1' */
    /* '<S652>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation3
        (&Model_TranslationEngine64_B.ESDUpperbounddB,
         &Model_TranslationEngine64_B.ESDLowerbounddB,
         &Model_TranslationEngine64_B.sf_TrivialTranslation3);
}

/*
 * Output and update for function-call system:
 *    '<S643>/Trivial Translation1'
 *    '<S670>/Trivial Translation1'
 */
void Model_TranslationEngine64_TrivialTranslation1(const bus_double_1_1
    *rtu_FastPsdSmoothCutoff, const bus_double_1_1 *rtu_SlowPsdSmoothCutoff,
    real_T rtu_FrameRate, B_TrivialTranslation1_Model_TranslationEngine64_T
    *localB)
{
    int32_T i;
    char_T c_data[70];
    char_T b_data[55];
    static const char_T d[55] =
        "Cutoff frequency of single pole averager for smoothing";
    static const char_T e[70] =
        "fast PSD should be less than or equal to that for smoothing slow PSD.";

    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Decimated-Rate FDP/Fdp/FreqDomainProcessing/Reverb Extractions/Trivial Translation1': '<S656>:1' */
    /* '<S656>:1:7' if FastPsdSmoothCutoff.Value >= SlowPsdSmoothCutoff.Value */
    if (rtu_FastPsdSmoothCutoff->Value >= rtu_SlowPsdSmoothCutoff->Value)
    {
        real_T wn;

        /* '<S656>:1:8' wn = 2 * pi * FastPsdSmoothCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 * rtu_FastPsdSmoothCutoff->Value / rtu_FrameRate;

        /* '<S656>:1:9' FastPsdSmoothFactor = (1 - sin(wn)) ./ cos(wn); */
        localB->FastPsdSmoothFactor = (1.0 - sin(wn)) / cos(wn);

        /* '<S656>:1:10' wn = 2 * pi * SlowPsdSmoothCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 * rtu_SlowPsdSmoothCutoff->Value / rtu_FrameRate;

        /* '<S656>:1:11' SlowPsdSmoothFactor = (1 - sin(wn)) ./ cos(wn); */
        localB->SlowPsdSmoothFactor = (1.0 - sin(wn)) / cos(wn);
    }
    else
    {
        /* '<S656>:1:12' else */
        /* '<S656>:1:13' TranslateError('Cutoff frequency of single pole averager for smoothing'...  */
        /* '<S656>:1:14'        ,'fast PSD should be less than or equal to that for smoothing slow PSD.'); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 55; i++)
        {
            b_data[i] = d[i];
        }

        memcpy(&c_data[0], &e[0], 70U * sizeof(char_T));
        TranslateError(&b_data[0], &c_data[0]);

        /* '<S656>:1:15' FastPsdSmoothFactor = 0; */
        localB->FastPsdSmoothFactor = 0.0;

        /* '<S656>:1:16' SlowPsdSmoothFactor = 0; */
        localB->SlowPsdSmoothFactor = 0.0;
    }
}

/* Output and update for function-call system: '<S653>/tfunc' */
void FuncTranslation_Model_141_1988(void)
{
    /* MATLAB Function: '<S643>/Trivial Translation1' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S659>:1' */
    /* '<S659>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation1
        (&Model_TranslationEngine64_B.FastPsdSmoothCutoff,
         &Model_TranslationEngine64_B.SlowPsdSmoothCutoff,
         Model_TranslationEngine64_ConstB.CapturedTuneConst,
         &Model_TranslationEngine64_B.sf_TrivialTranslation1);
}

/*
 * Output and update for function-call system:
 *    '<S643>/Trivial Translation3'
 *    '<S670>/Trivial Translation3'
 */
void Model_TranslationEngine64_TrivialTranslation3_l(const bus_double_1_1
    *rtu_DirectPathSec, real_T rtu_FrameRate, real_T rtu_FrameSize,
    B_TrivialTranslation3_Model_TranslationEngine64_p_T *localB)
{
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Decimated-Rate FDP/Fdp/FreqDomainProcessing/Reverb Extractions/Trivial Translation3': '<S657>:1' */
    /* '<S657>:1:3' DirectPathDec = round(DirectPathSec.Value*FrameRate)*FrameSize; */
    localB->DirectPathDec = rt_roundd_snf(rtu_DirectPathSec->Value *
        rtu_FrameRate) * rtu_FrameSize;
}

/* Output and update for function-call system: '<S654>/tfunc' */
void FuncTranslation_Model_141_1989(void)
{
    /* MATLAB Function: '<S643>/Trivial Translation3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S660>:1' */
    /* '<S660>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation3_l
        (&Model_TranslationEngine64_B.DirectPathSec,
         Model_TranslationEngine64_ConstB.CapturedTuneConst,
         Model_TranslationEngine64_ConstB.CapturedTuneConst1,
         &Model_TranslationEngine64_B.sf_TrivialTranslation3_l);
}

/*
 * Output and update for function-call system:
 *    '<S643>/Trivial Translation4'
 *    '<S670>/Trivial Translation4'
 */
void Model_TranslationEngine64_TrivialTranslation4(const bus_double_1_1
    *rtu_LsSmoothCutoff, real_T rtu_FrameRate,
    B_TrivialTranslation4_Model_TranslationEngine64_T *localB)
{
    real_T wn;

    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Decimated-Rate FDP/Fdp/FreqDomainProcessing/Reverb Extractions/Trivial Translation4': '<S658>:1' */
    /* '<S658>:1:7' wn = 2 * pi * LsSmoothCutoff.Value / FrameRate; */
    wn = 6.2831853071795862 * rtu_LsSmoothCutoff->Value / rtu_FrameRate;

    /* '<S658>:1:8' LsSmoothFactor = (1 - sin(wn)) ./ cos(wn); */
    localB->LsSmoothFactor = (1.0 - sin(wn)) / cos(wn);
}

/* Output and update for function-call system: '<S655>/tfunc' */
void FuncTranslation_Model_141_1990(void)
{
    /* MATLAB Function: '<S643>/Trivial Translation4' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S661>:1' */
    /* '<S661>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation4
        (&Model_TranslationEngine64_B.LsSmoothCutoff,
         Model_TranslationEngine64_ConstB.CapturedTuneConst,
         &Model_TranslationEngine64_B.sf_TrivialTranslation4);
}

/* Output and update for function-call system: '<S664>/tfunc' */
void FuncTranslation_Model_141_2031_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S662>/Subsystem' */
    /* SignalConversion generated from: '<S663>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S665>:1' */
    /* '<S665>:1:3' f(); */
    Model_TranslationEngine64_B.Value_du =
        Model_TranslationEngine64_B.SpumOverwrite.Value;

    /* End of Outputs for SubSystem: '<S662>/Subsystem' */
}

/* Output and update for function-call system: '<S674>/tfunc' */
void FuncTranslation_Model_141_2423(void)
{
    int32_T i;
    char_T b_data[58];
    char_T c_data[26];
    static const char_T d[58] =
        "XpMin must be no less than 0.0, and must be less than 1.0";
    static const char_T e[58] =
        "XpMax must be no less than 0.0, and must be less than 1.0";
    static const char_T f[26] = "XpMin cannot exceed XpMax";

    /* MATLAB Function: '<S673>/Trivial Translation' */
    /* MATLAB Function: '<S673>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S666>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S673>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S673>/Tune Variable3'
     *
     * Block description for '<S666>/Tune Variable7':
     *  Minimum stretch factor - must be in range [0,1)
     *
     * Block description for '<S673>/Tune Variable':
     *  Maximum stretch factor - must be in range [0,1).
     *
     * Block description for '<S673>/Tune Variable3':
     *  Minimum stretch factor - must be in range [0,1)
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S678>:1' */
    /* '<S678>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Full-Rate FDP/Fdp/FreqDomainProcessing/CalculateAndApplyCoefficients/FullRate/Calculate coefficients/StretchParams/Trivial Translation': '<S676>:1' */
    /* '<S676>:1:3' XpMax = XpMaxIn.Value; */
    /* '<S676>:1:4' XpMin = XpMinIn.Value; */
    /* '<S676>:1:6' if (XpMin < 0) || (XpMin >= 1) */
    if ((Model_TranslationEngine64_B.XpMin_c.Value < 0.0) ||
            (Model_TranslationEngine64_B.XpMin_c.Value >= 1.0))
    {
        /* '<S676>:1:7' TranslateError('XpMin must be no less than 0.0, and must be less than 1.0'); */
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
        for (i = 0; i < 58; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S676>:1:10' if (XpMax < 0) || (XpMax >= 1) */
    if ((Model_TranslationEngine64_B.XpMax_ce.Value < 0.0) ||
            (Model_TranslationEngine64_B.XpMax_ce.Value >= 1.0))
    {
        /* '<S676>:1:11' TranslateError('XpMax must be no less than 0.0, and must be less than 1.0'); */
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
        for (i = 0; i < 58; i++)
        {
            b_data[i] = e[i];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S676>:1:14' if (XpMax < XpMin) */
    if (Model_TranslationEngine64_B.XpMax_ce.Value <
            Model_TranslationEngine64_B.XpMin_c.Value)
    {
        /* '<S676>:1:15' TranslateError('XpMin cannot exceed XpMax'); */
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
        for (i = 0; i < 26; i++)
        {
            c_data[i] = f[i];
        }

        TranslateError(&c_data[0]);
    }

    /*  Do not need to check for translation error as this is already done in */
    /*  Decimated Rate block. */
    /* '<S676>:1:20' deciXpMax = deciXpMaxIn.Value; */
    /*  NOTE: The Xp used for detect is the decimated rate Xp while the Xp */
    /*  used for the XpMax (in the dynamically created Xp) is the treble Xp. */
    /*  All parameters are also treble-specific (different from decimated rate). */
    /*  This means the LokRokMaxScaleFactor for treble stretching is calculated */
    /*  using the decimated rate XpMax. */
    /* '<S676>:1:27' if (deciXpMax == 1) */
    if (Model_TranslationEngine64_B.XpMax_c.Value == 1.0)
    {
        /* '<S676>:1:28' LokRokMaxScaleFactor = 0; */
        Model_TranslationEngine64_B.LokRokMaxScaleFactor = 0.0;
    }
    else
    {
        /* '<S676>:1:29' else */
        /* '<S676>:1:30' LokRokMaxScaleFactor = 0.5 * deciXpMax / (1 - deciXpMax); */
        Model_TranslationEngine64_B.LokRokMaxScaleFactor = 0.5 *
            Model_TranslationEngine64_B.XpMax_c.Value / (1.0 -
            Model_TranslationEngine64_B.XpMax_c.Value);
    }

    Model_TranslationEngine64_B.XpMax_n =
        Model_TranslationEngine64_B.XpMax_ce.Value;
    Model_TranslationEngine64_B.XpMin_h =
        Model_TranslationEngine64_B.XpMin_c.Value;

    /* End of MATLAB Function: '<S673>/Trivial Translation' */
}

/* Output and update for function-call system: '<S675>/tfunc' */
void FuncTranslation_Model_141_2424(void)
{
    /* MATLAB Function: '<S673>/Trivial Translation3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S679>:1' */
    /* '<S679>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation3
        (&Model_TranslationEngine64_B.ESDUpperbounddB_b,
         &Model_TranslationEngine64_B.ESDLowerbounddB_k,
         &Model_TranslationEngine64_B.sf_TrivialTranslation3_hi);
}

/* Output and update for function-call system: '<S680>/tfunc' */
void FuncTranslation_Model_141_2654(void)
{
    /* MATLAB Function: '<S670>/Trivial Translation1' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S686>:1' */
    /* '<S686>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation1
        (&Model_TranslationEngine64_B.FastPsdSmoothCutoff_j,
         &Model_TranslationEngine64_B.SlowPsdSmoothCutoff_a,
         Model_TranslationEngine64_ConstB.CapturedTuneConst_f,
         &Model_TranslationEngine64_B.sf_TrivialTranslation1_fu);
}

/* Output and update for function-call system: '<S681>/tfunc' */
void FuncTranslation_Model_141_2655(void)
{
    /* MATLAB Function: '<S670>/Trivial Translation3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S687>:1' */
    /* '<S687>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation3_l
        (&Model_TranslationEngine64_B.DirectPathSec_p,
         Model_TranslationEngine64_ConstB.CapturedTuneConst_f,
         Model_TranslationEngine64_ConstB.CapturedTuneConst1_h,
         &Model_TranslationEngine64_B.sf_TrivialTranslation3_ll1);
}

/* Output and update for function-call system: '<S682>/tfunc' */
void FuncTranslation_Model_141_2656(void)
{
    /* MATLAB Function: '<S670>/Trivial Translation4' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S688>:1' */
    /* '<S688>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation4
        (&Model_TranslationEngine64_B.LsSmoothCutoff_c,
         Model_TranslationEngine64_ConstB.CapturedTuneConst_f,
         &Model_TranslationEngine64_B.sf_TrivialTranslation4_jo);
}

/* Output and update for function-call system: '<S691>/tfunc' */
void FuncTranslation_Model_141_2697_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S689>/Subsystem' */
    /* SignalConversion generated from: '<S690>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S692>:1' */
    /* '<S692>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ne =
        Model_TranslationEngine64_B.SpumOverwrite_b.Value;

    /* End of Outputs for SubSystem: '<S689>/Subsystem' */
}

/* Output and update for function-call system: '<S696>/tfunc' */
void FuncTranslation_Model_141_2783(void)
{
    real_T LSSmoothPole;
    real_T LevelPole;
    real_T wn;
    int32_T i;
    char_T c_data[77];
    char_T b_data[61];
    boolean_T error;
    static const char_T d[61] =
        "Least square smoother should smooth more than level smoother";
    static const char_T e[77] =
        "Least square smoother for reset should smooth less than that for normal mode";

    /* MATLAB Function: '<S695>/translation' */
    /* MATLAB Function: '<S695>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S706>:1' */
    /* '<S706>:1:3' f(); */
    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Mono Detector/Mono Detector/Tune Translations/translation': '<S701>:1' */
    /* '<S701>:1:10' error = false; */
    error = false;

    /* '<S701>:1:11' if LevelCutoff.Value <= LSSmoothCutoff.Value */
    if (Model_TranslationEngine64_B.LevelCutoff.Value <=
            Model_TranslationEngine64_B.LSSmoothCutoff.Value)
    {
        /* '<S701>:1:12' TranslateError('Least square smoother should smooth more than level smoother'); */
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
        for (i = 0; i < 61; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0]);

        /* '<S701>:1:13' error = true; */
        error = true;
    }
    else if (Model_TranslationEngine64_B.LSSmoothResetCutoff.Value <=
             Model_TranslationEngine64_B.LSSmoothCutoff.Value)
    {
        /* '<S701>:1:14' elseif LSSmoothResetCutoff.Value <= LSSmoothCutoff.Value */
        /* '<S701>:1:15' TranslateError('Least square smoother for reset should smooth less than that for normal mode'); */
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
        memcpy(&c_data[0], &e[0], 77U * sizeof(char_T));
        TranslateError(&c_data[0]);

        /* '<S701>:1:16' error = true; */
        error = true;
    }

    /* '<S701>:1:19' if (~error) */
    if (!error)
    {
        /* '<S701>:1:20' wn = 2 * pi * LevelCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 * Model_TranslationEngine64_B.LevelCutoff.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst_l;

        /* '<S701>:1:21' LevelPole = (1 - sin(wn)) ./ cos(wn); */
        LevelPole = (1.0 - sin(wn)) / cos(wn);

        /* '<S701>:1:22' LevelGain = 1 - LevelPole; */
        Model_TranslationEngine64_B.LevelGain = 1.0 - LevelPole;

        /* '<S701>:1:24' wn = 2 * pi * LSSmoothCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 *
            Model_TranslationEngine64_B.LSSmoothCutoff.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst_l;

        /* '<S701>:1:25' LSSmoothPole = (1 - sin(wn)) ./ cos(wn); */
        LSSmoothPole = (1.0 - sin(wn)) / cos(wn);

        /* '<S701>:1:26' LSSmoothGain = 1 - LSSmoothPole; */
        Model_TranslationEngine64_B.LSSmoothGain = 1.0 - LSSmoothPole;

        /* '<S701>:1:28' wn = 2 * pi * LSSmoothResetCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 *
            Model_TranslationEngine64_B.LSSmoothResetCutoff.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst_l;

        /* '<S701>:1:29' LSSmoothResetPole = (1 - sin(wn)) ./ cos(wn); */
        wn = (1.0 - sin(wn)) / cos(wn);

        /* '<S701>:1:30' LSSmoothResetGain = 1 - LSSmoothResetPole; */
        Model_TranslationEngine64_B.LSSmoothResetGain = 1.0 - wn;
    }
    else
    {
        /* '<S701>:1:31' else */
        /* '<S701>:1:32' LevelPole = 0; */
        LevelPole = 0.0;

        /* '<S701>:1:33' LevelGain = 0; */
        Model_TranslationEngine64_B.LevelGain = 0.0;

        /* '<S701>:1:34' LSSmoothPole = 0; */
        LSSmoothPole = 0.0;

        /* '<S701>:1:35' LSSmoothGain = 0; */
        Model_TranslationEngine64_B.LSSmoothGain = 0.0;

        /* '<S701>:1:36' LSSmoothResetPole = 0; */
        wn = 0.0;

        /* '<S701>:1:37' LSSmoothResetGain = 0; */
        Model_TranslationEngine64_B.LSSmoothResetGain = 0.0;
    }

    Model_TranslationEngine64_B.LevelPole = LevelPole;
    Model_TranslationEngine64_B.LSSmoothPole = LSSmoothPole;
    Model_TranslationEngine64_B.LSSmoothResetPole = wn;

    /* End of MATLAB Function: '<S695>/translation' */
}

/* Output and update for function-call system: '<S697>/tfunc' */
void FuncTranslation_Model_141_2784(void)
{
    /* MATLAB Function: '<S695>/translation1' */
    /* MATLAB Function: '<S695>/translation1' incorporates:
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable3'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S707>:1' */
    /* '<S707>:1:3' f(); */
    /*  thresh = 2 * undb20(noiseFloordB) */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Mono Detector/Mono Detector/Tune Translations/translation1': '<S702>:1' */
    /* '<S702>:1:3' ThresholdZeroLevel = 2 * (10 ^ (NoiseFloordB.Value / 20)); */
    Model_TranslationEngine64_B.ThresholdZeroLevel = rt_powd_snf(10.0,
        Model_TranslationEngine64_B.NoiseFloordB.Value / 20.0) * 2.0;
}

/* Output and update for function-call system: '<S698>/tfunc' */
void FuncTranslation_Model_141_2785(void)
{
    int32_T i;
    char_T b_data[39];
    static const char_T c[39] = "Invalid tolerance for left right match";

    /* MATLAB Function: '<S695>/translation2' */
    /* MATLAB Function: '<S695>/translation2' incorporates:
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable4'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S708>:1' */
    /* '<S708>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Mono Detector/Mono Detector/Tune Translations/translation2': '<S703>:1' */
    /* '<S703>:1:3' if (LRMatchTolerancedB.Value < 0 || LRMatchTolerancedB.Value > 0.5) */
    if ((Model_TranslationEngine64_B.LRMatchTolerancedB.Value < 0.0) ||
            (Model_TranslationEngine64_B.LRMatchTolerancedB.Value > 0.5))
    {
        /* '<S703>:1:4' TranslateError('Invalid tolerance for left right match'); */
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
        for (i = 0; i < 39; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);

        /* '<S703>:1:5' LRMatchTolerance = 0; */
        Model_TranslationEngine64_B.LRMatchTolerance = 0.0;
    }
    else
    {
        /* '<S703>:1:6' else */
        /* '<S703>:1:7' LRMatchTolerance = 10 ^ (LRMatchTolerancedB.Value / 20); */
        Model_TranslationEngine64_B.LRMatchTolerance = rt_powd_snf(10.0,
            Model_TranslationEngine64_B.LRMatchTolerancedB.Value / 20.0);
    }

    /* End of MATLAB Function: '<S695>/translation2' */
}

/* Output and update for function-call system: '<S699>/tfunc' */
void FuncTranslation_Model_141_2786(void)
{
    int32_T i;
    char_T c_data[61];
    char_T b_data[57];
    static const char_T d[57] =
        "Threshold for mono should be higher than that for stereo";
    static const char_T e[61] =
        "Threshold values for mono and stereo should be less than 1.0";

    /* MATLAB Function: '<S695>/translation3' */
    /* MATLAB Function: '<S695>/translation3' incorporates:
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable5'
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable6'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S709>:1' */
    /* '<S709>:1:3' f(); */
    /*  The exponent 1/64 is carried over from AR and old bdsp implementation. */
    /*  This is designed by Chris Cheng to make the gap between two thresholds */
    /*  as small as possible, because in theory they should be almost identical. */
    /*  Removing this would still work in theory with a slight change in the  */
    /*  output. However as we verify the block against PREQ Simulink model, this */
    /*  translation is retained to get a complete match in performance. */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Mono Detector/Mono Detector/Tune Translations/translation3': '<S704>:1' */
    /* '<S704>:1:9' if ThresholdMonoInput.Value <= ThresholdStereoInput.Value */
    if (Model_TranslationEngine64_B.ThresholdMonoInput.Value <=
            Model_TranslationEngine64_B.ThresholdStereoInput.Value)
    {
        /* '<S704>:1:10' TranslateError('Threshold for mono should be higher than that for stereo'); */
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
        for (i = 0; i < 57; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0]);

        /* '<S704>:1:11' ThresholdMono = 0; */
        Model_TranslationEngine64_B.ThresholdMono = 0.0;

        /* '<S704>:1:12' ThresholdStereo = 0; */
        Model_TranslationEngine64_B.ThresholdStereo = 0.0;
    }
    else if ((Model_TranslationEngine64_B.ThresholdMonoInput.Value >= 1.0) ||
             (Model_TranslationEngine64_B.ThresholdStereoInput.Value >= 1.0))
    {
        /* '<S704>:1:13' elseif (ThresholdMonoInput.Value >= 1) || (ThresholdStereoInput.Value >= 1) */
        /* '<S704>:1:14' TranslateError('Threshold values for mono and stereo should be less than 1.0'); */
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
        for (i = 0; i < 61; i++)
        {
            c_data[i] = e[i];
        }

        TranslateError(&c_data[0]);

        /* '<S704>:1:15' ThresholdMono = 0; */
        Model_TranslationEngine64_B.ThresholdMono = 0.0;

        /* '<S704>:1:16' ThresholdStereo = 0; */
        Model_TranslationEngine64_B.ThresholdStereo = 0.0;
    }
    else
    {
        /* '<S704>:1:17' else */
        /* '<S704>:1:18' ThresholdMono = ThresholdMonoInput.Value ^ (1/64); */
        Model_TranslationEngine64_B.ThresholdMono = rt_powd_snf
            (Model_TranslationEngine64_B.ThresholdMonoInput.Value, 0.015625);

        /* '<S704>:1:19' ThresholdStereo = ThresholdStereoInput.Value ^ (1/64); */
        Model_TranslationEngine64_B.ThresholdStereo = rt_powd_snf
            (Model_TranslationEngine64_B.ThresholdStereoInput.Value, 0.015625);
    }

    /* End of MATLAB Function: '<S695>/translation3' */
}

/* Output and update for function-call system: '<S700>/tfunc' */
void FuncTranslation_Model_141_2787(void)
{
    real_T ChannelSOS[12];
    real_T ChannelCoeffs[9];
    real_T sinw;
    real_T w;
    int32_T e_data[5];
    int32_T SOSIndex;
    int32_T ibmat;
    int32_T yk;
    real32_T rawSOS[12];
    real32_T b_a[6];
    char_T c_data[61];
    int8_T y_data[5];
    boolean_T x[2];
    static const char_T f[61] =
        "Highpass filter cutoff is out of range; should be in (0, %d)";

    /* MATLAB Function: '<S695>/translation4' */
    /* MATLAB Function: '<S695>/translation4' incorporates:
     *  S-Function (TuneVarMEX): '<S695>/Tune Variable7'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S710>:1' */
    /* '<S710>:1:3' f(); */
    /* [Param:numChannels] */
    /* [Param:maxNumStages] */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/Mono Detector/Mono Detector/Tune Translations/translation4': '<S705>:1' */
    /*  Calculation is fixed for a second order high pass butterworth, i.e. this  */
    /*  translation will not work anymore if the filter order/design is changed.  */
    /*  Code for computing hpf is taken from AR model. */
    /*  More generic implementation is also included below. In this case of 2nd  */
    /*  order filter, we get better precision by getting the one-stage sos  */
    /*  directly from the transfer function. */
    /*  hpfOrder = configStruct.hpfOrder; */
    /*  normFreq = 2 * HPFCutoff.Value / sampleRate; */
    /*  [Z, P, K] = butter_for_code_gen(hpfOrder, hpfOrder, normFreq, 'high'); */
    /*  sos = zp2sos_for_code_gen(Z, P, K); */
    /* '<S705>:1:18' w = 2 * pi* HPFCutoff.Value / sampleRate; */
    w = 6.2831853071795862 * Model_TranslationEngine64_B.HPFCutoff.Value /
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_a;

    /* '<S705>:1:19' sqrt2 = sqrt(2); */
    /* '<S705>:1:20' sinw = sin(w); */
    sinw = sin(w);

    /* '<S705>:1:21' cosw = cos(w); */
    /* '<S705>:1:23' if (HPFCutoff.Value <= 0) || (HPFCutoff.Value > sampleRate/2) */
    if ((Model_TranslationEngine64_B.HPFCutoff.Value <= 0.0) ||
            (Model_TranslationEngine64_B.HPFCutoff.Value >
             Model_TranslationEngine64_ConstB.CapturedTuneConst1_a / 2.0))
    {
        /* '<S705>:1:24' TranslateError('Highpass filter cutoff is out of range; should be in (0, %d)',sampleRate/2); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (yk = 0; yk < 61; yk++)
        {
            c_data[yk] = f[yk];
        }

        TranslateError(&c_data[0],
                       Model_TranslationEngine64_ConstB.CapturedTuneConst1_a /
                       2.0);

        /* '<S705>:1:25' b = single([1 0 0]); */
        /* '<S705>:1:26' a = single([1 0 0]); */
        b_a[0] = 1.0F;
        b_a[4] = 0.0F;
        b_a[1] = 0.0F;
        b_a[5] = 0.0F;
        b_a[2] = 0.0F;
    }
    else
    {
        /* '<S705>:1:27' else */
        /* '<S705>:1:28' denom = (sqrt2 + sinw); */
        /* '<S705>:1:29' a1 = -2 * sqrt2 * cosw / denom; */
        w = -2.8284271247461903 * cos(w) / (sinw + 1.4142135623730951);

        /* '<S705>:1:30' a2 = (sqrt2 - sinw) / denom; */
        sinw = (1.4142135623730951 - sinw) / (sinw + 1.4142135623730951);

        /* '<S705>:1:31' a = single([1 a1 a2]); */
        b_a[4] = (real32_T)w;
        b_a[5] = (real32_T)sinw;

        /* '<S705>:1:32' b = single([1 -2 1] * (1-a1+a2) / 4); */
        sinw += 1.0 - w;
        b_a[0] = (real32_T)(sinw / 4.0);
        b_a[1] = (real32_T)(-2.0 * sinw / 4.0);
        b_a[2] = (real32_T)(sinw / 4.0);
    }

    /* '<S705>:1:34' sos = [b,a]; */
    b_a[3] = 1.0F;

    /* '<S705>:1:36' numStages = size(sos, 1) * ones(1, numChannels); */
    /* '<S705>:1:37' rawSOS = repmat(sos, numChannels, 1); */
    for (SOSIndex = 0; SOSIndex < 6; SOSIndex++)
    {
        real32_T b_a_0;
        b_a_0 = b_a[SOSIndex];
        ibmat = SOSIndex << 1;
        rawSOS[ibmat] = b_a_0;
        rawSOS[ibmat + 1] = b_a_0;
    }

    /* '<S705>:1:39' [HPFNumStages, HPFCoeffs] = pooliirTranslation(rawSOS, numStages, maxNumStages); */
    /*  Function to format sos into pooliir. Taken from Translation block */
    /*  inside pooliir library block. */
    /* '<S705>:1:48' RawSOS = rawSOS; */
    /* '<S705>:1:49' NumStages = int32(numStages); */
    /* '<S705>:1:50' NumChannels = length(NumStages); */
    /* '<S705>:1:52' MaxNumStages = maxNumStages; */
    /* '<S705>:1:53' PoolNumStages = int32(zeros(NumChannels,1)); */
    Model_TranslationEngine64_B.HPFNumStages[0] = 0;
    Model_TranslationEngine64_B.HPFNumStages[1] = 0;

    /* '<S705>:1:54' PoolCoeffs = double(zeros(MaxNumStages * 4 + NumChannels,1)); */
    memset(&Model_TranslationEngine64_B.HPFCoeffs[0], 0, 10U * sizeof(real_T));

    /* '<S705>:1:55' ChannelCoeffs = zeros(MaxNumStages * 4 + 1,1); */
    memset(&ChannelCoeffs[0], 0, 9U * sizeof(real_T));

    /* '<S705>:1:56' ChannelSOS = double(zeros(MaxNumStages, 6)); */
    memset(&ChannelSOS[0], 0, 12U * sizeof(real_T));

    /* '<S705>:1:57' SOSIndex = int32(0); */
    SOSIndex = -1;

    /* '<S705>:1:59' for i = 1:NumChannels */
    y_data[0] = 1;
    y_data[1] = 2;
    y_data[2] = 3;
    y_data[3] = 4;
    y_data[4] = 5;
    for (ibmat = 0; ibmat < 2; ibmat++)
    {
        boolean_T b_y;
        boolean_T exitg1;

        /* '<S705>:1:61' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* '<S705>:1:62' assert(ChannelNumStages <= MaxNumStages); */
        /* '<S705>:1:64' ChannelSOS(1:ChannelNumStages,:) = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
        for (yk = 0; yk < 6; yk++)
        {
            int32_T ChannelSOS_tmp;
            ChannelSOS_tmp = yk << 1;
            ChannelSOS[ChannelSOS_tmp] = rawSOS[(ChannelSOS_tmp + SOSIndex) + 1];
        }

        /* '<S705>:1:65' SOSIndex = SOSIndex + ChannelNumStages; */
        SOSIndex++;

        /* '<S705>:1:67' if size(ChannelSOS,2) ~= 6 */
        /*  decompose SOS */
        /* '<S705>:1:72' ts = 1:4:4*ChannelNumStages; */
        /* '<S705>:1:73' ChannelCoeffs(1,1) = prod(ChannelSOS(1:ChannelNumStages,1)); */
        ChannelCoeffs[0] = ChannelSOS[0];

        /*  b0 */
        /*  the remaining coeffs are compacted forms of the biquads */
        /* '<S705>:1:76' ChannelCoeffs(1+ts,1) = ChannelSOS(1:ChannelNumStages,6); */
        ChannelCoeffs[1] = ChannelSOS[10];

        /*  a2 */
        /* '<S705>:1:77' ChannelCoeffs(2+ts,1) = ChannelSOS(1:ChannelNumStages,5); */
        ChannelCoeffs[2] = ChannelSOS[8];

        /*  a1 */
        /* '<S705>:1:78' if( ChannelSOS(:,1) == 0 ) */
        x[0] = (ChannelSOS[0] == 0.0);
        x[1] = (ChannelSOS[1] == 0.0);
        b_y = true;
        yk = 0;
        exitg1 = false;
        while ((!exitg1) && (yk < 2))
        {
            if (!x[yk])
            {
                b_y = false;
                exitg1 = true;
            }
            else
            {
                yk++;
            }
        }

        if (b_y)
        {
            /* '<S705>:1:79' ChannelCoeffs(3+ts,1) = 0; */
            ChannelCoeffs[3] = 0.0;

            /*  b2/b0 */
            /* '<S705>:1:80' ChannelCoeffs(4+ts,1) = 0; */
            ChannelCoeffs[4] = 0.0;

            /*  b1/b0 */
        }
        else
        {
            /* '<S705>:1:81' else */
            /* '<S705>:1:82' ChannelCoeffs(3+ts,1) = ... */
            /* '<S705>:1:83'         ChannelSOS(1:ChannelNumStages,3)./ ... */
            /* '<S705>:1:84'         ChannelSOS(1:ChannelNumStages,1); */
            ChannelCoeffs[3] = ChannelSOS[4] / ChannelSOS[0];

            /*  b2/b0 */
            /* '<S705>:1:85' ChannelCoeffs(4+ts,1) = ... */
            /* '<S705>:1:86'         ChannelSOS(1:ChannelNumStages,2)./ ... */
            /* '<S705>:1:87'         ChannelSOS(1:ChannelNumStages,1); */
            ChannelCoeffs[4] = ChannelSOS[2] / ChannelSOS[0];

            /*  b1/b0 */
        }

        /*  length of Current Channel Coeffs */
        /* '<S705>:1:91' ChannelCoeffsLength = 1+4*ChannelNumStages; */
        /*  Offset into coefficient array for the current channel */
        /* '<S705>:1:94' offset = (i-1)+4*sum(PoolNumStages(1:i-1)); */
        if (ibmat < 1)
        {
            yk = 0;
        }
        else
        {
            yk = Model_TranslationEngine64_B.HPFNumStages[0];
        }

        sinw = (yk << 2) + ibmat;

        /*  Verify that the SOS does not violate the maximum number of stages */
        /*  allocated for the pool */
        /* '<S705>:1:98' PoolNumStages(i) = int32(ChannelNumStages); */
        Model_TranslationEngine64_B.HPFNumStages[ibmat] = 1;

        /* '<S705>:1:99' if sum(PoolNumStages) > MaxNumStages */
        /*  Store the coefficients */
        /* '<S705>:1:104' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = double(ChannelCoeffs(1:ChannelCoeffsLength)); */
        for (yk = 0; yk < 5; yk++)
        {
            e_data[yk] = y_data[yk] + (int32_T)sinw;
            Model_TranslationEngine64_B.HPFCoeffs[e_data[yk] - 1] =
                ChannelCoeffs[yk];
        }
    }

    /* End of MATLAB Function: '<S695>/translation4' */
}

/* Output and update for function-call system: '<S713>/tfunc' */
void FuncTranslation_Model_141_2808_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S711>/Subsystem' */
    /* SignalConversion generated from: '<S712>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S714>:1' */
    /* '<S714>:1:3' f(); */
    Model_TranslationEngine64_B.Value_fw =
        Model_TranslationEngine64_B.Enable.Value;

    /* End of Outputs for SubSystem: '<S711>/Subsystem' */
}

/* Output and update for function-call system: '<S717>/tfunc' */
void FuncTranslation_Model_141_2849(void)
{
    real_T wn;

    /* MATLAB Function: '<S715>/Trivial Translation' */
    /* MATLAB Function: '<S715>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable'
     *
     * Block description for '<S715>/Tune Variable':
     *  Cutoff frequency for single pole averager that smooths energy sequence
     *  for decay estimation.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S730>:1' */
    /* '<S730>:1:3' f(); */
    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/Decay Estimate/Trivial Translation': '<S722>:1' */
    /* '<S722>:1:6' wn = 2 * pi * PSDSmoothCutoff.Value / FrameRate; */
    wn = 6.2831853071795862 * Model_TranslationEngine64_B.PSDSmoothCutoff.Value /
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;

    /* '<S722>:1:7' PSDSmoothFactor = (1 - sin(wn)) ./ cos(wn); */
    Model_TranslationEngine64_B.PSDSmoothFactor = (1.0 - sin(wn)) / cos(wn);
}

/* Output and update for function-call system: '<S718>/tfunc' */
void FuncTranslation_Model_141_2850(void)
{
    real_T wn;

    /* MATLAB Function: '<S715>/Trivial Translation1' */
    /* MATLAB Function: '<S715>/Trivial Translation1' incorporates:
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable1'
     *
     * Block description for '<S715>/Tune Variable1':
     *  Cutoff frequency for single pole averager that further smooths decay.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S731>:1' */
    /* '<S731>:1:3' f(); */
    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/Decay Estimate/Trivial Translation1': '<S723>:1' */
    /* '<S723>:1:6' wn = 2 * pi * DecaySmoothCutoff.Value / FrameRate; */
    wn = 6.2831853071795862 *
        Model_TranslationEngine64_B.DecaySmoothCutoff.Value /
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;

    /* '<S723>:1:7' DecaySmoothFactor = (1 - sin(wn)) ./ cos(wn); */
    Model_TranslationEngine64_B.DecaySmoothFactor = (1.0 - sin(wn)) / cos(wn);
}

/* Output and update for function-call system: '<S719>/tfunc' */
void FuncTranslation_Model_141_2851(void)
{
    int32_T i;
    char_T c_data[54];
    char_T b_data[46];
    static const char_T d[46] = "Cutoff frequency of single pole averager for ";
    static const char_T e[54] =
        "decay should be less than or equal to that for attack";

    /* MATLAB Function: '<S715>/Trivial Translation2' */
    /* MATLAB Function: '<S715>/Trivial Translation2' incorporates:
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable3'
     *
     * Block description for '<S715>/Tune Variable2':
     *  Cutoff frequency for single pole averager when decay parameter is
     *  increasing.
     *
     * Block description for '<S715>/Tune Variable3':
     *  Cutoff frequency for single pole averager when decay parameter is
     *  decreasing (slow decay).
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S732>:1' */
    /* '<S732>:1:3' f(); */
    /*  Cutoff is the inverse of time constant in Hz. So this function */
    /*  basically converts reciprocal of time constant to first order iir */
    /*  filter coefficient. */
    /*  Reference: https://bosecorp.sharepoint.com/sites/ASD3/DSPTeam/Shared%20Documents/DSP_Topics/Comparison%20of%20time%20constant%20conversion%20methods.docx */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/Decay Estimate/Trivial Translation2': '<S724>:1' */
    /* '<S724>:1:6' if FastAttackCutoff.Value >= SlowAttackCutoff.Value */
    if (Model_TranslationEngine64_B.FastAttackCutoff.Value >=
            Model_TranslationEngine64_B.SlowAttackCutoff.Value)
    {
        real_T wn;

        /* '<S724>:1:7' wn = 2 * pi * FastAttackCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 *
            Model_TranslationEngine64_B.FastAttackCutoff.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;

        /* '<S724>:1:8' FastAttack = 1 - (1 - sin(wn)) ./ cos(wn); */
        Model_TranslationEngine64_B.FastAttack = 1.0 - (1.0 - sin(wn)) / cos(wn);

        /* '<S724>:1:9' wn = 2 * pi * SlowAttackCutoff.Value / FrameRate; */
        wn = 6.2831853071795862 *
            Model_TranslationEngine64_B.SlowAttackCutoff.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;

        /* '<S724>:1:10' SlowAttack = 1 - (1 - sin(wn)) ./ cos(wn); */
        Model_TranslationEngine64_B.SlowAttack = 1.0 - (1.0 - sin(wn)) / cos(wn);
    }
    else
    {
        /* '<S724>:1:11' else */
        /* '<S724>:1:12' TranslateError('Cutoff frequency of single pole averager for '... */
        /* '<S724>:1:13'         ,'decay should be less than or equal to that for attack'); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 46; i++)
        {
            b_data[i] = d[i];
        }

        for (i = 0; i < 54; i++)
        {
            c_data[i] = e[i];
        }

        TranslateError(&b_data[0], &c_data[0]);

        /* '<S724>:1:14' FastAttack = 0; */
        Model_TranslationEngine64_B.FastAttack = 0.0;

        /* '<S724>:1:15' SlowAttack = 0; */
        Model_TranslationEngine64_B.SlowAttack = 0.0;
    }

    /* End of MATLAB Function: '<S715>/Trivial Translation2' */
}

/* Output and update for function-call system: '<S720>/tfunc' */
void FuncTranslation_Model_141_2852(void)
{
    int32_T i;
    char_T b_data[63];
    static const char_T c[63] =
        "Step size for slewing should be greater than or equal to zero.";

    /* MATLAB Function: '<S715>/Trivial Translation3' */
    /* MATLAB Function: '<S715>/Trivial Translation3' incorporates:
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable4'
     *
     * Block description for '<S715>/Tune Variable4':
     *  Step size for decay slewing.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S733>:1' */
    /* '<S733>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/Decay Estimate/Trivial Translation3': '<S725>:1' */
    /* '<S725>:1:3' if StepSize.Value >= 0 */
    if (Model_TranslationEngine64_B.StepSize.Value >= 0.0)
    {
        /* '<S725>:1:4' StepIncrement = StepSize.Value/FrameRate; */
        Model_TranslationEngine64_B.StepIncrement =
            Model_TranslationEngine64_B.StepSize.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;

        /* '<S725>:1:5' StepDecrement = -StepSize.Value/FrameRate; */
        Model_TranslationEngine64_B.StepDecrement =
            -Model_TranslationEngine64_B.StepSize.Value /
            Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;
    }
    else
    {
        /* '<S725>:1:6' else */
        /* '<S725>:1:7' TranslateError('Step size for slewing should be greater than or equal to zero.'); */
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
        for (i = 0; i < 63; i++)
        {
            b_data[i] = c[i];
        }

        TranslateError(&b_data[0]);

        /* '<S725>:1:8' StepIncrement = 0; */
        Model_TranslationEngine64_B.StepIncrement = 0.0;

        /* '<S725>:1:9' StepDecrement = 0; */
        Model_TranslationEngine64_B.StepDecrement = 0.0;
    }

    /* End of MATLAB Function: '<S715>/Trivial Translation3' */
}

/* Output and update for function-call system: '<S721>/tfunc' */
void FuncTranslation_Model_141_2853(void)
{
    /* MATLAB Function: '<S715>/Trivial Translation4' */
    /* MATLAB Function: '<S715>/Trivial Translation4' incorporates:
     *  S-Function (TuneVarMEX): '<S715>/Tune Variable5'
     *
     * Block description for '<S715>/Tune Variable5':
     *  This is the time in seconds that separates dry (or direct) and reverb
     *  parts. The larger directPathSec becomes, the more energy goes into the
     *  “impulse” because a longer period of time past “onset” is
     *  considered direct energy. Ideally this value is equivalent to an
     *  integer multiple of a frame period.
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S734>:1' */
    /* '<S734>:1:3' f(); */
    /*  Convert delay in seconds to number of full-rate frames */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/Decay Estimate/Trivial Translation4': '<S726>:1' */
    /* '<S726>:1:4' DirectPathFramesFs = round(directPathSec.Value*FrameRate); */
    Model_TranslationEngine64_B.DirectPathFramesFs =
        Model_TranslationEngine64_B.DirectPathSec_k.Value *
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_hw;
    Model_TranslationEngine64_B.DirectPathFramesFs = rt_roundd_snf
        (Model_TranslationEngine64_B.DirectPathFramesFs);
}

/* Output and update for function-call system: '<S737>/tfunc' */
void FuncTranslation_Model_141_2865_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S735>/Subsystem' */
    /* SignalConversion generated from: '<S736>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S738>:1' */
    /* '<S738>:1:3' f(); */
    Model_TranslationEngine64_B.Value_g2 =
        Model_TranslationEngine64_B.NoiseFloor.Value;

    /* End of Outputs for SubSystem: '<S735>/Subsystem' */
}

/* Output and update for function-call system: '<S741>/tfunc' */
void FuncTranslation_Model_141_2866_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S739>/Subsystem' */
    /* SignalConversion generated from: '<S740>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S742>:1' */
    /* '<S742>:1:3' f(); */
    Model_TranslationEngine64_B.Value_i2 =
        Model_TranslationEngine64_B.OnsetThreshold.Value;

    /* End of Outputs for SubSystem: '<S739>/Subsystem' */
}

/* Output and update for function-call system: '<S745>/tfunc' */
void FuncTranslation_Model_141_2867_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S743>/Subsystem' */
    /* SignalConversion generated from: '<S744>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S746>:1' */
    /* '<S746>:1:3' f(); */
    Model_TranslationEngine64_B.Value_e0 =
        Model_TranslationEngine64_B.SlewThreshold.Value;

    /* End of Outputs for SubSystem: '<S743>/Subsystem' */
}

/* Function for MATLAB Function: '<S748>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_ny(int32_T b,
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

/* Output and update for function-call system: '<S749>/tfunc' */
void FuncTranslation_Model_141_2878_50_36(void)
{
    real_T ChannelCoeffs[48];
    real_T OverallGainPerCh[2];
    int32_T g_data[48];
    int32_T tmp_data[48];
    int32_T c_data[12];
    int32_T ts_data[12];
    int32_T NumStages[2];
    int32_T SOSIndex;
    int32_T c_k;
    int32_T i;
    int32_T vlen;
    int32_T yk;
    real32_T ChannelSOS_data[72];
    real32_T PoolCoeffs[48];
    real32_T x;
    real32_T y;
    char_T e_data[31];
    static const char_T f[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S748>/Translation' */
    /* MATLAB Function: '<S748>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S748>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S748>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S751>:1' */
    /* '<S751>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 2/SPUM Decay Estimate/High-pass filter  > 6kHz/InnerLink/PoolIirTunableWithReset/Translation': '<S750>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S750>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S750>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S750>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    x = roundf(Model_TranslationEngine64_B.numStages_e.Value[0]);
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

    Model_TranslationEngine64_B.PoolNumStages_o[0] = 0;
    y = roundf(Model_TranslationEngine64_B.numStages_e.Value[1]);
    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            NumStages[1] = (int32_T)y;
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

    Model_TranslationEngine64_B.PoolNumStages_o[1] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 48U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 48U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (x < 2.14748365E+9F)
    {
        if (x >= -2.14748365E+9F)
        {
            vlen = (int32_T)x;
        }
        else
        {
            vlen = MIN_int32_T;
        }
    }
    else
    {
        vlen = MAX_int32_T;
    }

    if (y < 2.14748365E+9F)
    {
        if (y >= -2.14748365E+9F)
        {
            c_k = (int32_T)y;
        }
        else
        {
            c_k = MIN_int32_T;
        }
    }
    else
    {
        c_k = MAX_int32_T;
    }

    if ((real_T)vlen + (real_T)c_k > 12.0)
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
        for (vlen = 0; vlen < 31; vlen++)
        {
            e_data[vlen] = f[vlen];
        }

        TranslateError(&e_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (i = 0; i < 2; i++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[i];
        OverallGainPerCh[i] = 1.0;

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
            Model_TranslationEngine64_eml_integer_colon_dispatcher_ny
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (vlen = 0; vlen < 6; vlen++)
            {
                for (c_k = 0; c_k < yk; c_k++)
                {
                    q1 = tmp_data[c_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    ChannelSOS_data[c_k + ChannelSOS_size_idx_0 * vlen] =
                        Model_TranslationEngine64_B.sosCoefficients_f.Value[(12 *
                        vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
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

            OverallGainPerCh[i] = x / y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            if (vlen < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = (int32_T)((uint32_T)(vlen - 1) >> 2) + 1;
            }

            ts_size_idx_1 = vlen;
            if (vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (c_k = 2; c_k <= vlen; c_k++)
                {
                    yk += 4;
                    ts_data[c_k - 1] = yk;
                }
            }

            yk = vlen - 1;
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k < -2147483647)
                {
                    ts_data[vlen] = MIN_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            c_k = (ts_size_idx_1 / 4) << 2;
            q1 = c_k - 4;
            for (vlen = 0; vlen <= q1; vlen += 4)
            {
                __m128i tmp_0;
                tmp_0 = _mm_loadu_si128((const __m128i *)&ts_data[vlen]);
                _mm_storeu_si128((__m128i *)&c_data[vlen], _mm_add_epi32(tmp_0,
                                  _mm_set1_epi32(1)));
            }

            for (vlen = c_k; vlen < ts_size_idx_1; vlen++)
            {
                c_data[vlen] = ts_data[vlen] + 1;
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = -ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483645)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 2;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = ChannelSOS_data[vlen +
                    ChannelSOS_size_idx_0] / ChannelSOS_data[vlen];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483644)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 3;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] =
                    -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483643)
                {
                    ts_data[vlen] = MAX_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k + 4;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[ts_data[vlen] - 1] = ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + vlen] / ChannelSOS_data[vlen];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (i < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = Model_TranslationEngine64_B.PoolNumStages_o[0];
            }

            offset = 4.0 * (real_T)vlen;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_o[i] = NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_ny(vlen,
                tmp_data, tmp_size);
            c_k = tmp_size[1];
            yk = tmp_size[1];
            for (vlen = 0; vlen < yk; vlen++)
            {
                real_T tmp;
                tmp = offset + (real_T)tmp_data[vlen];
                if (tmp < 2.147483648E+9)
                {
                    if (tmp >= -2.147483648E+9)
                    {
                        g_data[vlen] = (int32_T)tmp;
                    }
                    else
                    {
                        g_data[vlen] = MIN_int32_T;
                    }
                }
                else
                {
                    g_data[vlen] = MAX_int32_T;
                }
            }

            for (vlen = 0; vlen < c_k; vlen++)
            {
                PoolCoeffs[g_data[vlen] - 1] = (real32_T)ChannelCoeffs[vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_B.PoolCoeffs_b2[0], &PoolCoeffs[0], 48U *
           sizeof(real32_T));
    Model_TranslationEngine64_B.PoolCoeffs_b2[48] = (real32_T)OverallGainPerCh[0];
    Model_TranslationEngine64_B.PoolCoeffs_b2[49] = (real32_T)OverallGainPerCh[1];

    /* End of MATLAB Function: '<S748>/Translation' */
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

/* Output and update for function-call system: '<S759>/tfunc' */
void FuncTranslation_Model_141_2888(void)
{
    int32_T actualBassDelay;
    int32_T actualBassDelayDec;
    char_T h_data[90];
    char_T f_data[85];
    char_T g_data[80];
    char_T b_data[70];
    char_T c_data[68];
    char_T d_data[65];
    char_T e_data[63];
    static const char_T i[70] =
        "Value of \'Medusa Wiggle Delay\' must be greater than or equal to zero.";
    static const char_T j[68] =
        "Value of \'NEAR Wiggle Delay\' must be greater than or equal to zero.";
    static const char_T k[65] =
        "Value of \'Medusa Wiggle Delay\' must be less than or equal to %d.";
    static const char_T l[63] =
        "Value of \'NEAR Wiggle Delay\' must be less than or equal to %d.";
    static const char_T m[85] =
        "Value of \'Medusa Bass Delay\' on decimated-rate path exceeds the maximum value of %d.";
    static const char_T n[80] =
        "Value of \'Medusa Bass Delay\' on full-rate path exceeds the maximum value of %d.";
    static const char_T o[90] =
        "Value of \'Medusa Alignment Delay\' on decimated-rate path exceeds the maximum value of %d.";

    /* MATLAB Function: '<S758>/translation' */
    /* MATLAB Function: '<S758>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S753>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S753>/Tune Variable1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S761>:1' */
    /* '<S761>:1:3' f(); */
    /* [Param:DEC] */
    /* [Param:maxWiggleDelayDec] */
    /* [Param:maxNearWiggleDelayDec] */
    /* [Param:FDPDelay] */
    /* [Param:bandSplitDelay] */
    /* [Param:maxBassDelayFull] */
    /* [Param:maxBassDelayDec] */
    /* [Param:maxAlignmentDelay] */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Delay Tuning/Delay Translation/translation': '<S760>:1' */
    /*  Alignment Delay Translation */
    /*  This translation computes the alignment delay values for bass and */
    /*  decimated-rate upmixed components */
    /*  Error Check for incoming tune values */
    /* '<S760>:1:21' if(wiggleDelay.Value < 0) */
    if (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value
        < 0)
    {
        /* '<S760>:1:22' TranslateError('Value of ''Medusa Wiggle Delay'' must be greater than or equal to zero.'); */
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
        memcpy(&b_data[0], &i[0], 70U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S760>:1:25' if(nearWiggleDelay.Value < 0) */
    if (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateNearWiggleFilterDelaySamples1.Value
        < 0)
    {
        /* '<S760>:1:26' TranslateError('Value of ''NEAR Wiggle Delay'' must be greater than or equal to zero.'); */
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
        memcpy(&c_data[0], &j[0], 68U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S760>:1:29' if(wiggleDelay.Value > maxWiggleDelayDec) */
    if (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value
        > 166)
    {
        /* '<S760>:1:30' TranslateError('Value of ''Medusa Wiggle Delay'' must be less than or equal to %d.', maxWiggleDelayDec); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&d_data[0], &k[0], 65U * sizeof(char_T));
        TranslateError(&d_data[0], 166);
    }

    /* '<S760>:1:33' if(nearWiggleDelay.Value > maxNearWiggleDelayDec) */
    if (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateNearWiggleFilterDelaySamples1.Value
        > 166)
    {
        /* '<S760>:1:34' TranslateError('Value of ''NEAR Wiggle Delay'' must be less than or equal to %d.', maxNearWiggleDelayDec); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (actualBassDelay = 0; actualBassDelay < 63; actualBassDelay++)
        {
            e_data[actualBassDelay] = l[actualBassDelay];
        }

        TranslateError(&e_data[0], 166);
    }

    /*  Computing the alignment delay values for bass and mid-range paths */
    /*  Medusa wiggle filter latency */
    /* '<S760>:1:39' wiggleDelayDec = int32(round(wiggleDelay.Value)); */
    /* '<S760>:1:40' wiggleDelayFull = int32(wiggleDelayDec * DEC); */
    /*  NEAR wiggle filter latency */
    /* '<S760>:1:43' NEARWiggleDelayDec = int32(round(nearWiggleDelay.Value)); */
    /* '<S760>:1:44' NEARWiggleDelayFull = int32(NEARWiggleDelayDec * DEC); */
    /*  Compute the bass alignment delay (applies to bass components) */
    /* '<S760>:1:47' actualBassDelay = FDPDelay + bandSplitDelay/2 + wiggleDelayFull + NEARWiggleDelayFull; */
    actualBassDelay =
        ((Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value
          << 2) +
         (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateNearWiggleFilterDelaySamples1.Value
          << 2)) + 1603;

    /* '<S760>:1:48' actualBassDelayDec = int32(floor(single(actualBassDelay)/DEC)); */
    actualBassDelayDec = (int32_T)floorf((real32_T)actualBassDelay / 4.0F);

    /* '<S760>:1:49' actualBassDelayFull = actualBassDelay - actualBassDelayDec*DEC; */
    actualBassDelay -= actualBassDelayDec << 2;

    /*  Compute the mid-range alignment delay (applies to decimated-rate upmixed components) */
    /* '<S760>:1:52' actualAlignmentDelay = wiggleDelayDec; */
    /*  Error check for outgoing alignment delay values */
    /* '<S760>:1:55' if(actualBassDelayFull > maxBassDelayFull) */
    if (actualBassDelay > 3)
    {
        /* '<S760>:1:56' TranslateError('Value of ''Medusa Bass Delay'' on decimated-rate path exceeds the maximum value of %d.', maxBassDelayFull); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&f_data[0], &m[0], 85U * sizeof(char_T));
        TranslateError(&f_data[0], 3.0);
    }

    /* '<S760>:1:59' if(actualBassDelayDec > maxBassDelayDec) */
    if (actualBassDelayDec > 733)
    {
        /* '<S760>:1:60' TranslateError('Value of ''Medusa Bass Delay'' on full-rate path exceeds the maximum value of %d.', maxBassDelayDec); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&g_data[0], &n[0], 80U * sizeof(char_T));
        TranslateError(&g_data[0], 733);
    }

    /* '<S760>:1:63' if(actualAlignmentDelay > maxAlignmentDelay) */
    if (Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value
        > 166)
    {
        /* '<S760>:1:64' TranslateError('Value of ''Medusa Alignment Delay'' on decimated-rate path exceeds the maximum value of %d.', maxAlignmentDelay); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&h_data[0], &o[0], 90U * sizeof(char_T));
        TranslateError(&h_data[0], 166);
    }

    /*  Assigning outputs */
    /* '<S760>:1:68' bassDelayFull = actualBassDelayFull; */
    Model_TranslationEngine64_Medusa5H1Part3_B.bassDelayFull = actualBassDelay;

    /* '<S760>:1:69' bassDelayDec = actualBassDelayDec; */
    Model_TranslationEngine64_Medusa5H1Part3_B.bassDelayDec = actualBassDelayDec;

    /* '<S760>:1:71' alignmentDelay = actualAlignmentDelay; */
    Model_TranslationEngine64_Medusa5H1Part3_B.alignmentDelay =
        Model_TranslationEngine64_Medusa5H1Part3_B.DeciRateWiggleFilterDelaySamples1.Value;

    /* End of MATLAB Function: '<S758>/translation' */
}

/*
 * Output and update for function-call system:
 *    '<S776>/Trivial Translation'
 *    '<S852>/Trivial Translation'
 *    '<S924>/Trivial Translation'
 *    '<S962>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation(const bus_double_1_1
    *rtu_BackwardDownmixMax, B_TrivialTranslation_Model_TranslationEngine64_T
    *localB)
{
    char_T b_data[68];
    static const char_T c[68] =
        "The value of \'medusa_backward_downmix_max\' must be between 0 and 1.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Backward Downmix Max/Trivial Translation': '<S784>:1' */
    /* '<S784>:1:4' if(numel(BackwardDownmixMax.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S784>:1:9' if((BackwardDownmixMax.Value < 0) || (BackwardDownmixMax.Value > 1)) */
    if ((rtu_BackwardDownmixMax->Value < 0.0) || (rtu_BackwardDownmixMax->Value >
         1.0))
    {
        /* '<S784>:1:10' TranslateError('The value of ''medusa_backward_downmix_max'' must be between 0 and 1.'); */
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
        memcpy(&b_data[0], &c[0], 68U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S784>:1:13' TOP = BackwardDownmixMax.Value; */
    localB->TOP = rtu_BackwardDownmixMax->Value;
}

/* Output and update for function-call system: '<S783>/tfunc' */
void FuncTranslation_Model_141_2926(void)
{
    /* MATLAB Function: '<S776>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S785>:1' */
    /* '<S785>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation);
}

/*
 * Output and update for function-call system:
 *    '<S777>/Trivial Translation'
 *    '<S853>/Trivial Translation'
 *    '<S925>/Trivial Translation'
 *    '<S963>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_f(const bus_double_1_1
    *rtu_BackwardDownmixThreshold,
    B_TrivialTranslation_Model_TranslationEngine64_b_T *localB)
{
    char_T b_data[74];
    static const char_T c[74] =
        "The value of \'medusa_backward_downmix_threshold\' must be between 0 and 1.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Backward Downmix Threshold/Trivial Translation': '<S787>:1' */
    /* '<S787>:1:4' if(numel(BackwardDownmixThreshold.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S787>:1:9' if((BackwardDownmixThreshold.Value < 0) || (BackwardDownmixThreshold.Value > 1)) */
    if ((rtu_BackwardDownmixThreshold->Value < 0.0) ||
            (rtu_BackwardDownmixThreshold->Value > 1.0))
    {
        /* '<S787>:1:10' TranslateError('The value of ''medusa_backward_downmix_threshold'' must be between 0 and 1.'); */
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
        memcpy(&b_data[0], &c[0], 74U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S787>:1:13' TOP = BackwardDownmixThreshold.Value; */
    localB->TOP = rtu_BackwardDownmixThreshold->Value;
}

/* Output and update for function-call system: '<S786>/tfunc' */
void FuncTranslation_Model_141_2932(void)
{
    /* MATLAB Function: '<S777>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S788>:1' */
    /* '<S788>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_f
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_f);
}

/* Output and update for function-call system: '<S789>/tfunc' */
void FuncTranslation_Model_141_2939(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[93];
    char_T d_data[75];
    int8_T nz[6];
    boolean_T x[12];
    static const char_T e[93] =
        "The parameter \'medusa_frm_downmix_cs\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[75] =
        "The weights in \'medusa_frm_downmix_CS\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S778>/Trivial Translation' */
    /* MATLAB Function: '<S778>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S778>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S791>:1' */
    /* '<S791>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Downmix Weights CS/Trivial Translation': '<S790>:1' */
    /* '<S790>:1:3' numCSIn = MedusaFRMConfig.CS_in; */
    /* '<S790>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.CS; */
    /* '<S790>:1:6' NumRows = MedusaFRMConfig.CS_out; */
    /* '<S790>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S790>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S790>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S790>:1:13' if(downmix_wts_CS.Size(1) ~= NumRows || downmix_wts_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Size[0]
            != 2.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Size[
             1] != 6.0))
    {
        /* '<S790>:1:14' TranslateError('The parameter ''medusa_frm_downmix_cs'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 93U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 6.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S790>:1:18' checkValues = (downmix_wts_CS.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Value
             [i] < 0.0);
    }

    /* '<S790>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 6; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 5; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S790>:1:20' TranslateError('The weights in ''medusa_frm_downmix_CS'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 75U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S790>:1:24' TOP = downmix_wts_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_g[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS_c.Value[
           0], 12U * sizeof(real_T));

    /* '<S790>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S790>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_o[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_o[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_o[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_o[3] = 0.0;

    /* End of MATLAB Function: '<S778>/Trivial Translation' */
}

/* Output and update for function-call system: '<S792>/tfunc' */
void FuncTranslation_Model_141_2947(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[95];
    char_T d_data[77];
    boolean_T x[30];
    static const char_T e[95] =
        "The parameter \'medusa_frm_downmix_left\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[77] =
        "The weights in \'medusa_frm_downmix_left\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S779>/Trivial Translation' */
    /* MATLAB Function: '<S779>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S779>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S794>:1' */
    /* '<S794>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Downmix Weights Left/Trivial Translation': '<S793>:1' */
    /* '<S793>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S793>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S793>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S793>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S793>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S793>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S793>:1:13' if(downmix_wts_Left.Size(1) ~= NumRows || downmix_wts_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Size[0]
         != 10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Size
             [1] != 3.0))
    {
        /* '<S793>:1:14' TranslateError('The parameter ''medusa_frm_downmix_left'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 95U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S793>:1:18' checkValues = (downmix_wts_Left.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Value
             [i] < 0.0);
    }

    /* '<S793>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S793>:1:20' TranslateError('The weights in ''medusa_frm_downmix_left'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 77U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S793>:1:24' TOP = downmix_wts_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_kd[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left_n.Value
           [0], 30U * sizeof(real_T));

    /* '<S793>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S793>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ja[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S779>/Trivial Translation' */
}

/* Output and update for function-call system: '<S795>/tfunc' */
void FuncTranslation_Model_141_2955(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[96];
    char_T d_data[78];
    boolean_T x[30];
    static const char_T e[96] =
        "The parameter \'medusa_frm_downmix_right\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[78] =
        "The weights in \'medusa_frm_downmix_right\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S780>/Trivial Translation' */
    /* MATLAB Function: '<S780>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S780>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S797>:1' */
    /* '<S797>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Downmix Weights Right/Trivial Translation': '<S796>:1' */
    /* '<S796>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S796>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S796>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S796>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S796>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S796>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S796>:1:13' if(downmix_wts_Right.Size(1) ~= NumRows || downmix_wts_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Size
            [0] != 10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Size
             [1] != 3.0))
    {
        /* '<S796>:1:14' TranslateError('The parameter ''medusa_frm_downmix_right'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 96U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S796>:1:18' checkValues = (downmix_wts_Right.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Value
             [i] < 0.0);
    }

    /* '<S796>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S796>:1:20' TranslateError('The weights in ''medusa_frm_downmix_right'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 78U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S796>:1:24' TOP = downmix_wts_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ff[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right_d.Value
           [0], 30U * sizeof(real_T));

    /* '<S796>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S796>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gq[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S780>/Trivial Translation' */
}

/*
 * Output and update for function-call system:
 *    '<S781>/Trivial Translation'
 *    '<S857>/Trivial Translation'
 *    '<S927>/Trivial Translation'
 *    '<S965>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_p(const bus_double_1_1
    *rtu_ForwardDownmixThreshold,
    B_TrivialTranslation_Model_TranslationEngine64_d_T *localB)
{
    char_T b_data[73];
    static const char_T c[73] =
        "The value of \'medusa_forward_downmix_threshold\' must be between 0 and 1.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Forward Downmix Threshold/Trivial Translation': '<S799>:1' */
    /* '<S799>:1:4' if(numel(ForwardDownmixThreshold.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S799>:1:9' if((ForwardDownmixThreshold.Value < 0) || (ForwardDownmixThreshold.Value > 1)) */
    if ((rtu_ForwardDownmixThreshold->Value < 0.0) ||
            (rtu_ForwardDownmixThreshold->Value > 1.0))
    {
        /* '<S799>:1:10' TranslateError('The value of ''medusa_forward_downmix_threshold'' must be between 0 and 1.'); */
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
        memcpy(&b_data[0], &c[0], 73U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S799>:1:13' TOP = ForwardDownmixThreshold.Value; */
    localB->TOP = rtu_ForwardDownmixThreshold->Value;
}

/* Output and update for function-call system: '<S798>/tfunc' */
void FuncTranslation_Model_141_2962(void)
{
    /* MATLAB Function: '<S781>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S800>:1' */
    /* '<S800>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_p
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_p);
}

/*
 * Output and update for function-call system:
 *    '<S782>/Trivial Translation'
 *    '<S858>/Trivial Translation'
 *    '<S928>/Trivial Translation'
 *    '<S966>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_pz(const bus_double_1_1
    *rtu_ForwardDownmixMax, B_TrivialTranslation_Model_TranslationEngine64_a_T
    *localB)
{
    char_T b_data[67];
    static const char_T c[67] =
        "The value of \'medusa_forward_downmix_max\' must be between 0 and 1.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/Fade Tuning/Foward Downmix Max/Trivial Translation': '<S802>:1' */
    /* '<S802>:1:4' if(numel(ForwardDownmixMax.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S802>:1:9' if((ForwardDownmixMax.Value < 0) || (ForwardDownmixMax.Value > 1)) */
    if ((rtu_ForwardDownmixMax->Value < 0.0) || (rtu_ForwardDownmixMax->Value >
            1.0))
    {
        /* '<S802>:1:10' TranslateError('The value of ''medusa_forward_downmix_max'' must be between 0 and 1.'); */
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
        memcpy(&b_data[0], &c[0], 67U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S802>:1:13' TOP = ForwardDownmixMax.Value; */
    localB->TOP = rtu_ForwardDownmixMax->Value;
}

/* Output and update for function-call system: '<S801>/tfunc' */
void FuncTranslation_Model_141_2968(void)
{
    /* MATLAB Function: '<S782>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S803>:1' */
    /* '<S803>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pz
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_pz);
}

/* Output and update for function-call system: '<S814>/tfunc' */
void FuncTranslation_Model_141_3372(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[92];
    char_T d_data[74];
    int8_T nz[6];
    boolean_T x[12];
    static const char_T e[92] =
        "The parameter \'medusa_frm_cs_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[74] =
        "The weights in \'medusa_frm_cs_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S804>/Trivial Translation' */
    /* MATLAB Function: '<S804>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S804>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S816>:1' */
    /* '<S816>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Detent Level CS/Trivial Translation': '<S815>:1' */
    /* '<S815>:1:3' numCSIn = MedusaFRMConfig.CS_in; */
    /* '<S815>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.CS; */
    /* '<S815>:1:6' NumRows = MedusaFRMConfig.CS_out; */
    /* '<S815>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S815>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S815>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S815>:1:13' if(detentGain_CS.Size(1) ~= NumRows || detentGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Size[0] !=
            2.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Size[1]
             != 6.0))
    {
        /* '<S815>:1:14' TranslateError('The parameter ''medusa_frm_cs_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 92U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 6.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S815>:1:18' checkValues = (detentGain_CS.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Value[i]
             < 0.0);
    }

    /* '<S815>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 6; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 5; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S815>:1:20' TranslateError('The weights in ''medusa_frm_cs_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 74U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S815>:1:24' TOP = detentGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_kf[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS_j.Value[0],
           12U * sizeof(real_T));

    /* '<S815>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S815>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_er[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_er[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_er[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_er[3] = 0.0;

    /* End of MATLAB Function: '<S804>/Trivial Translation' */
}

/* Output and update for function-call system: '<S817>/tfunc' */
void FuncTranslation_Model_141_3380(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[94];
    char_T d_data[76];
    boolean_T x[30];
    static const char_T e[94] =
        "The parameter \'medusa_frm_left_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[76] =
        "The weights in \'medusa_frm_left_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S805>/Trivial Translation' */
    /* MATLAB Function: '<S805>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S805>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S819>:1' */
    /* '<S819>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Detent Level Left/Trivial Translation': '<S818>:1' */
    /* '<S818>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S818>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S818>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S818>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S818>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S818>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S818>:1:13' if(detentGain_Left.Size(1) ~= NumRows || detentGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Size[0]
            != 10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Size
             [1] != 3.0))
    {
        /* '<S818>:1:14' TranslateError('The parameter ''medusa_frm_left_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 94U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S818>:1:18' checkValues = (detentGain_Left.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Value[
             i] < 0.0);
    }

    /* '<S818>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S818>:1:20' TranslateError('The weights in ''medusa_frm_left_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 76U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S818>:1:24' TOP = detentGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_f[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left_n.Value
           [0], 30U * sizeof(real_T));

    /* '<S818>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S818>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ax[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S805>/Trivial Translation' */
}

/* Output and update for function-call system: '<S820>/tfunc' */
void FuncTranslation_Model_141_3388(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[95];
    char_T d_data[77];
    boolean_T x[30];
    static const char_T e[95] =
        "The parameter \'medusa_frm_right_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[77] =
        "The weights in \'medusa_frm_right_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S806>/Trivial Translation' */
    /* MATLAB Function: '<S806>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S806>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S822>:1' */
    /* '<S822>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Detent Level Right/Trivial Translation': '<S821>:1' */
    /* '<S821>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S821>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S821>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S821>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S821>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S821>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S821>:1:13' if(detentGain_Right.Size(1) ~= NumRows || detentGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Size[0]
            != 10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Size[
             1] != 3.0))
    {
        /* '<S821>:1:14' TranslateError('The parameter ''medusa_frm_right_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 95U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S821>:1:18' checkValues = (detentGain_Right.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Value
             [i] < 0.0);
    }

    /* '<S821>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S821>:1:20' TranslateError('The weights in ''medusa_frm_right_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 77U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S821>:1:24' TOP = detentGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_p1[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right_c.Value[
           0], 30U * sizeof(real_T));

    /* '<S821>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S821>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_ba[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S806>/Trivial Translation' */
}

/*
 * Output and update for function-call system:
 *    '<S807>/Trivial Translation'
 *    '<S883>/Trivial Translation'
 *    '<S945>/Trivial Translation'
 *    '<S983>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_a(const bus_double_1_1
    *rtu_interpolationMethod, B_TrivialTranslation_Model_TranslationEngine64_k_T
    *localB)
{
    char_T b_data[128];
    static const char_T c[128] =
        "The value of \'medusa_surround_db_interpolation\' must be either 0 (for linear interpolation) or 1 (for dB-linear interpolation).";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Interpolation Method/Trivial Translation': '<S824>:1' */
    /* '<S824>:1:4' if(numel(interpolationMethod.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S824>:1:9' if((interpolationMethod.Value ~= 0) && (interpolationMethod.Value ~= 1)) */
    if ((rtu_interpolationMethod->Value != 0.0) &&
            (rtu_interpolationMethod->Value != 1.0))
    {
        /* '<S824>:1:10' TranslateError('The value of ''medusa_surround_db_interpolation'' must be either 0 (for linear interpolation) or 1 (for dB-linear interpolation).'); */
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
        memcpy(&b_data[0], &c[0], sizeof(char_T) << 7U);
        TranslateError(&b_data[0]);
    }

    /* '<S824>:1:13' TOP = interpolationMethod.Value; */
    localB->TOP = rtu_interpolationMethod->Value;
}

/* Output and update for function-call system: '<S823>/tfunc' */
void FuncTranslation_Model_141_3395(void)
{
    /* MATLAB Function: '<S807>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S825>:1' */
    /* '<S825>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_a
        (&Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_a);
}

/* Output and update for function-call system: '<S826>/tfunc' */
void FuncTranslation_Model_141_3402(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[89];
    char_T d_data[71];
    int8_T nz[6];
    boolean_T x[12];
    static const char_T e[89] =
        "The parameter \'medusa_frm_cs_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[71] =
        "The weights in \'medusa_frm_cs_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S808>/Trivial Translation' */
    /* MATLAB Function: '<S808>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S808>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S828>:1' */
    /* '<S828>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Max Level CS/Trivial Translation': '<S827>:1' */
    /* '<S827>:1:3' numCSIn = MedusaFRMConfig.CS_in; */
    /* '<S827>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.CS; */
    /* '<S827>:1:6' NumRows = MedusaFRMConfig.CS_out; */
    /* '<S827>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S827>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S827>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S827>:1:13' if(maxGain_CS.Size(1) ~= NumRows || maxGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Size[0] != 2.0)
        || (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Size[1] !=
            6.0))
    {
        /* '<S827>:1:14' TranslateError('The parameter ''medusa_frm_cs_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 89U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 6.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S827>:1:18' checkValues = (maxGain_CS.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Value[i]
                < 0.0);
    }

    /* '<S827>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 6; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 5; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S827>:1:20' TranslateError('The weights in ''medusa_frm_cs_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 71U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S827>:1:24' TOP = maxGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_c4[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS_b.Value[0],
           12U * sizeof(real_T));

    /* '<S827>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S827>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_f[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_f[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_f[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_f[3] = 0.0;

    /* End of MATLAB Function: '<S808>/Trivial Translation' */
}

/* Output and update for function-call system: '<S829>/tfunc' */
void FuncTranslation_Model_141_3410(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[91];
    char_T d_data[73];
    boolean_T x[30];
    static const char_T e[91] =
        "The parameter \'medusa_frm_left_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[73] =
        "The weights in \'medusa_frm_left_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S809>/Trivial Translation' */
    /* MATLAB Function: '<S809>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S809>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S831>:1' */
    /* '<S831>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Max Level Left/Trivial Translation': '<S830>:1' */
    /* '<S830>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S830>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S830>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S830>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S830>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S830>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S830>:1:13' if(maxGain_Left.Size(1) ~= NumRows || maxGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Size[0] !=
            10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Size[1]
             != 3.0))
    {
        /* '<S830>:1:14' TranslateError('The parameter ''medusa_frm_left_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 91U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S830>:1:18' checkValues = (maxGain_Left.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Value[i]
             < 0.0);
    }

    /* '<S830>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S830>:1:20' TranslateError('The weights in ''medusa_frm_left_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 73U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S830>:1:24' TOP = maxGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_d4[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left_k.Value[0],
           30U * sizeof(real_T));

    /* '<S830>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S830>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gk[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S809>/Trivial Translation' */
}

/* Output and update for function-call system: '<S832>/tfunc' */
void FuncTranslation_Model_141_3418(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[92];
    char_T d_data[74];
    boolean_T x[30];
    static const char_T e[92] =
        "The parameter \'medusa_frm_right_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[74] =
        "The weights in \'medusa_frm_right_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S810>/Trivial Translation' */
    /* MATLAB Function: '<S810>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S810>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S834>:1' */
    /* '<S834>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Max Level Right/Trivial Translation': '<S833>:1' */
    /* '<S833>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S833>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S833>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S833>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S833>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S833>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S833>:1:13' if(maxGain_Right.Size(1) ~= NumRows || maxGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Size[0] !=
            10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Size[1]
             != 3.0))
    {
        /* '<S833>:1:14' TranslateError('The parameter ''medusa_frm_right_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 92U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S833>:1:18' checkValues = (maxGain_Right.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Value[i]
             < 0.0);
    }

    /* '<S833>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S833>:1:20' TranslateError('The weights in ''medusa_frm_right_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 74U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S833>:1:24' TOP = maxGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_cn[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right_e.Value[0],
           30U * sizeof(real_T));

    /* '<S833>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S833>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_gw[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S810>/Trivial Translation' */
}

/* Output and update for function-call system: '<S835>/tfunc' */
void FuncTranslation_Model_141_3426(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[89];
    char_T d_data[71];
    int8_T nz[6];
    boolean_T x[12];
    static const char_T e[89] =
        "The parameter \'medusa_frm_cs_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[71] =
        "The weights in \'medusa_frm_cs_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S811>/Trivial Translation' */
    /* MATLAB Function: '<S811>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S811>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S837>:1' */
    /* '<S837>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Min Level CS/Trivial Translation': '<S836>:1' */
    /* '<S836>:1:3' numCSIn = MedusaFRMConfig.CS_in; */
    /* '<S836>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.CS; */
    /* '<S836>:1:6' NumRows = MedusaFRMConfig.CS_out; */
    /* '<S836>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S836>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S836>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S836>:1:13' if(minGain_CS.Size(1) ~= NumRows || minGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Size[0] != 2.0)
        || (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Size[1] !=
            6.0))
    {
        /* '<S836>:1:14' TranslateError('The parameter ''medusa_frm_cs_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 89U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 6.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S836>:1:18' checkValues = (minGain_CS.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Value[i]
                < 0.0);
    }

    /* '<S836>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 6; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 5; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S836>:1:20' TranslateError('The weights in ''medusa_frm_cs_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 71U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S836>:1:24' TOP = minGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_j[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS_m.Value[0],
           12U * sizeof(real_T));

    /* '<S836>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S836>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_hd[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_hd[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_hd[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_hd[3] = 0.0;

    /* End of MATLAB Function: '<S811>/Trivial Translation' */
}

/* Output and update for function-call system: '<S838>/tfunc' */
void FuncTranslation_Model_141_3434(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[91];
    char_T d_data[73];
    boolean_T x[30];
    static const char_T e[91] =
        "The parameter \'medusa_frm_left_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[73] =
        "The weights in \'medusa_frm_left_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S812>/Trivial Translation' */
    /* MATLAB Function: '<S812>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S812>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S840>:1' */
    /* '<S840>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Min Level Left/Trivial Translation': '<S839>:1' */
    /* '<S839>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S839>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S839>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S839>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S839>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S839>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S839>:1:13' if(minGain_Left.Size(1) ~= NumRows || minGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Size[0] !=
            10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Size[1]
             != 3.0))
    {
        /* '<S839>:1:14' TranslateError('The parameter ''medusa_frm_left_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 91U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S839>:1:18' checkValues = (minGain_Left.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Value[i]
             < 0.0);
    }

    /* '<S839>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S839>:1:20' TranslateError('The weights in ''medusa_frm_left_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 73U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S839>:1:24' TOP = minGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_i[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left_f.Value[0],
           30U * sizeof(real_T));

    /* '<S839>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S839>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_c1[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S812>/Trivial Translation' */
}

/* Output and update for function-call system: '<S841>/tfunc' */
void FuncTranslation_Model_141_3442(void)
{
    int32_T nz[3];
    int32_T i;
    int32_T k;
    char_T c_data[92];
    char_T d_data[74];
    boolean_T x[30];
    static const char_T e[92] =
        "The parameter \'medusa_frm_right_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[74] =
        "The weights in \'medusa_frm_right_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S813>/Trivial Translation' */
    /* MATLAB Function: '<S813>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S813>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S843>:1' */
    /* '<S843>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Full-rate Mixer/Full-Rate Mixer with CAE & Fade Ramper/SLC Tuning/Min Level Right/Trivial Translation': '<S842>:1' */
    /* '<S842>:1:3' numLRIn = MedusaFRMConfig.LR_in; */
    /* '<S842>:1:4' NumCAEWeights = MedusaFRMConfig.NumTailComp.LR; */
    /* '<S842>:1:6' NumRows = MedusaFRMConfig.LR_out; */
    /* '<S842>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S842>:1:8' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S842>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S842>:1:13' if(minGain_Right.Size(1) ~= NumRows || minGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Size[0] !=
            10.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Size[1]
             != 3.0))
    {
        /* '<S842>:1:14' TranslateError('The parameter ''medusa_frm_right_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 92U * sizeof(char_T));
        TranslateError(&c_data[0], 10.0, 3.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S842>:1:18' checkValues = (minGain_Right.Value < 0); */
    for (i = 0; i < 30; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Value[i]
             < 0.0);
    }

    /* '<S842>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 3; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 10;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 9; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    if (((real_T)nz[0] + (real_T)nz[1]) + (real_T)nz[2] != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S842>:1:20' TranslateError('The weights in ''medusa_frm_right_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 74U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S842>:1:24' TOP = minGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_da[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right_e.Value[0],
           30U * sizeof(real_T));

    /* '<S842>:1:25' if(~ MedusaFRMConfig.includeCAE) */
    /* '<S842>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_j[0], 0, 10U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S813>/Trivial Translation' */
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
    real_T y;
    if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0))
    {
        y = (rtNaN);
    }
    else if (rtIsInf(u1))
    {
        y = u0;
    }
    else if ((u1 != 0.0) && (u1 != trunc(u1)))
    {
        real_T q;
        q = fabs(u0 / u1);
        if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q))
        {
            y = 0.0 * u0;
        }
        else
        {
            y = fmod(u0, u1);
        }
    }
    else
    {
        y = fmod(u0, u1);
    }

    return y;
}

/* Output and update for function-call system: '<S849>/tfunc' */
void FuncTranslation_Model_141_3495(void)
{
    char_T b_data[98];
    static const char_T c[98] =
        "The value of \'medusa_mono_c_s_blending_angle_deg\' must be in degrees and can range from 0 to 359.";

    /* MATLAB Function: '<S848>/translation' */
    /* MATLAB Function: '<S848>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S848>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S851>:1' */
    /* '<S851>:1:3' f(); */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/CS Processing/MS Tune/translation': '<S850>:1' */
    /* '<S850>:1:4' if(numel(PhaseAngle.Value) ~= 1) */
    /*  Checks if the parameter value follows bound requirements */
    /* '<S850>:1:9' if((PhaseAngle.Value < 0) || (PhaseAngle.Value >= 360)) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value < 0.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value >=
             360.0))
    {
        /* '<S850>:1:10' TranslateError('The value of ''medusa_mono_c_s_blending_angle_deg'' must be in degrees and can range from 0 to 359.'); */
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
        memcpy(&b_data[0], &c[0], 98U * sizeof(char_T));
        TranslateError(&b_data[0]);
    }

    /* '<S850>:1:13' phi = PhaseAngle.Value; */
    /* '<S850>:1:14' cos_phi = cosd(phi); */
    if (rtIsInf(Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value) ||
            rtIsNaN(Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value))
    {
        Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi = (rtNaN);
        Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi = (rtNaN);
    }
    else
    {
        real_T absx;
        real_T x;
        real_T x_tmp;
        int8_T n;
        x_tmp = rt_remd_snf
            (Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value, 360.0);
        x = x_tmp;
        absx = fabs(x_tmp);
        if (absx > 180.0)
        {
            if (x_tmp > 0.0)
            {
                x = x_tmp - 360.0;
            }
            else
            {
                x = x_tmp + 360.0;
            }

            absx = fabs(x);
        }

        if (absx <= 45.0)
        {
            x *= 0.017453292519943295;
            n = 0;
        }
        else if (absx <= 135.0)
        {
            if (x > 0.0)
            {
                x = (x - 90.0) * 0.017453292519943295;
                n = 1;
            }
            else
            {
                x = (x + 90.0) * 0.017453292519943295;
                n = -1;
            }
        }
        else if (x > 0.0)
        {
            x = (x - 180.0) * 0.017453292519943295;
            n = 2;
        }
        else
        {
            x = (x + 180.0) * 0.017453292519943295;
            n = -2;
        }

        switch (n)
        {
          case 0:
            Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi = cos(x);
            break;

          case 1:
            Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi = -sin(x);
            break;

          case -1:
            Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi = sin(x);
            break;

          default:
            Model_TranslationEngine64_Medusa5H1Part3_B.cos_phi = -cos(x);
            break;
        }

        x = x_tmp;
        absx = fabs(x_tmp);
        if (absx > 180.0)
        {
            if (x_tmp > 0.0)
            {
                x = x_tmp - 360.0;
            }
            else
            {
                x = x_tmp + 360.0;
            }

            absx = fabs(x);
        }

        if (absx <= 45.0)
        {
            x *= 0.017453292519943295;
            n = 0;
        }
        else if (absx <= 135.0)
        {
            if (x > 0.0)
            {
                x = (x - 90.0) * 0.017453292519943295;
                n = 1;
            }
            else
            {
                x = (x + 90.0) * 0.017453292519943295;
                n = -1;
            }
        }
        else if (x > 0.0)
        {
            x = (x - 180.0) * 0.017453292519943295;
            n = 2;
        }
        else
        {
            x = (x + 180.0) * 0.017453292519943295;
            n = -2;
        }

        switch (n)
        {
          case 0:
            Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi = sin(x);
            break;

          case 1:
            Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi = cos(x);
            break;

          case -1:
            Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi = -cos(x);
            break;

          default:
            Model_TranslationEngine64_Medusa5H1Part3_B.sin_phi = -sin(x);
            break;
        }
    }

    /* '<S850>:1:15' sin_phi = sind(phi); */
    Model_TranslationEngine64_Medusa5H1Part3_B.phi =
        Model_TranslationEngine64_Medusa5H1Part3_B.PhaseAngle.Value;

    /* End of MATLAB Function: '<S848>/translation' */
}

/* Output and update for function-call system: '<S859>/tfunc' */
void FuncTranslation_Model_141_3596(void)
{
    /* MATLAB Function: '<S852>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S861>:1' */
    /* '<S861>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_h,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ctt);
}

/* Output and update for function-call system: '<S862>/tfunc' */
void FuncTranslation_Model_141_3602(void)
{
    /* MATLAB Function: '<S853>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S864>:1' */
    /* '<S864>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_f
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_f,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ket);
}

/* Output and update for function-call system: '<S865>/tfunc' */
void FuncTranslation_Model_141_3609(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[96];
    char_T d_data[78];
    int8_T nz[10];
    boolean_T x[20];
    static const char_T e[96] =
        "The parameter \'medusa_premix_downmix_cs\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[78] =
        "The weights in \'medusa_premix_downmix_CS\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S854>/Trivial Translation' */
    /* MATLAB Function: '<S854>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S854>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S867>:1' */
    /* '<S867>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/Fade Tuning/Downmix Weights CS/Trivial Translation': '<S866>:1' */
    /* '<S866>:1:3' numCSIn = MedusaPremixConfig.CS_in; */
    /* '<S866>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.CS; */
    /* '<S866>:1:6' NumRows = MedusaPremixConfig.CS_out; */
    /* '<S866>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S866>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S866>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S866>:1:13' if(downmix_wts_CS.Size(1) ~= NumRows || downmix_wts_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Size[0] !=
         2.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Size[1]
             != 10.0))
    {
        /* '<S866>:1:14' TranslateError('The parameter ''medusa_premix_downmix_cs'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 96U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 10.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S866>:1:18' checkValues = (downmix_wts_CS.Value < 0); */
    for (i = 0; i < 20; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Value[i]
             < 0.0);
    }

    /* '<S866>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 10; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 9; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S866>:1:20' TranslateError('The weights in ''medusa_premix_downmix_CS'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 78U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S866>:1:24' TOP = downmix_wts_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_co[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_CS.Value[0],
           20U * sizeof(real_T));

    /* '<S866>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S866>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_h[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_h[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_h[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_h[3] = 0.0;

    /* End of MATLAB Function: '<S854>/Trivial Translation' */
}

/* Output and update for function-call system: '<S868>/tfunc' */
void FuncTranslation_Model_141_3617(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[98];
    char_T d_data[80];
    boolean_T x[77];
    static const char_T e[98] =
        "The parameter \'medusa_premix_downmix_left\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[80] =
        "The weights in \'medusa_premix_downmix_left\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S855>/Trivial Translation' */
    /* MATLAB Function: '<S855>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S855>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S870>:1' */
    /* '<S870>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/Fade Tuning/Downmix Weights Left/Trivial Translation': '<S869>:1' */
    /* '<S869>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S869>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S869>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S869>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S869>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S869>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S869>:1:13' if(downmix_wts_Left.Size(1) ~= NumRows || downmix_wts_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Size[0]
            != 11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Size[
             1] != 7.0))
    {
        /* '<S869>:1:14' TranslateError('The parameter ''medusa_premix_downmix_left'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 98U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S869>:1:18' checkValues = (downmix_wts_Left.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Value
             [i] < 0.0);
    }

    /* '<S869>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S869>:1:20' TranslateError('The weights in ''medusa_premix_downmix_left'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 80U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S869>:1:24' TOP = downmix_wts_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ho4[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Left.Value[
           0], 77U * sizeof(real_T));

    /* '<S869>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S869>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_bk[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S855>/Trivial Translation' */
}

/* Output and update for function-call system: '<S871>/tfunc' */
void FuncTranslation_Model_141_3625(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[99];
    char_T d_data[81];
    boolean_T x[77];
    static const char_T e[99] =
        "The parameter \'medusa_premix_downmix_right\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[81] =
        "The weights in \'medusa_premix_downmix_right\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S856>/Trivial Translation' */
    /* MATLAB Function: '<S856>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S856>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S873>:1' */
    /* '<S873>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/Fade Tuning/Downmix Weights Right/Trivial Translation': '<S872>:1' */
    /* '<S872>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S872>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S872>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S872>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S872>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S872>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S872>:1:13' if(downmix_wts_Right.Size(1) ~= NumRows || downmix_wts_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Size[0]
         != 11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Size
             [1] != 7.0))
    {
        /* '<S872>:1:14' TranslateError('The parameter ''medusa_premix_downmix_right'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 99U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S872>:1:18' checkValues = (downmix_wts_Right.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Value
             [i] < 0.0);
    }

    /* '<S872>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S872>:1:20' TranslateError('The weights in ''medusa_premix_downmix_right'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 81U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S872>:1:24' TOP = downmix_wts_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_ho[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_Right.Value
           [0], 77U * sizeof(real_T));

    /* '<S872>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S872>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_g[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S856>/Trivial Translation' */
}

/* Output and update for function-call system: '<S874>/tfunc' */
void FuncTranslation_Model_141_3632(void)
{
    /* MATLAB Function: '<S857>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S876>:1' */
    /* '<S876>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_p
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_o,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_o3);
}

/* Output and update for function-call system: '<S877>/tfunc' */
void FuncTranslation_Model_141_3638(void)
{
    /* MATLAB Function: '<S858>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S879>:1' */
    /* '<S879>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pz
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_d,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_cid);
}

/* Output and update for function-call system: '<S890>/tfunc' */
void FuncTranslation_Model_141_4091(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[95];
    char_T d_data[77];
    int8_T nz[10];
    boolean_T x[20];
    static const char_T e[95] =
        "The parameter \'medusa_premix_cs_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[77] =
        "The weights in \'medusa_premix_cs_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S880>/Trivial Translation' */
    /* MATLAB Function: '<S880>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S880>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S892>:1' */
    /* '<S892>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Detent Level CS/Trivial Translation': '<S891>:1' */
    /* '<S891>:1:3' numCSIn = MedusaPremixConfig.CS_in; */
    /* '<S891>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.CS; */
    /* '<S891>:1:6' NumRows = MedusaPremixConfig.CS_out; */
    /* '<S891>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S891>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S891>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S891>:1:13' if(detentGain_CS.Size(1) ~= NumRows || detentGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Size[0] !=
            2.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Size[1]
             != 10.0))
    {
        /* '<S891>:1:14' TranslateError('The parameter ''medusa_premix_cs_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 95U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 10.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S891>:1:18' checkValues = (detentGain_CS.Value < 0); */
    for (i = 0; i < 20; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Value[i] <
             0.0);
    }

    /* '<S891>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 10; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 9; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S891>:1:20' TranslateError('The weights in ''medusa_premix_cs_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 77U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S891>:1:24' TOP = detentGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_mc[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_CS.Value[0],
           20U * sizeof(real_T));

    /* '<S891>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S891>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e2[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e2[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e2[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e2[3] = 0.0;

    /* End of MATLAB Function: '<S880>/Trivial Translation' */
}

/* Output and update for function-call system: '<S893>/tfunc' */
void FuncTranslation_Model_141_4099(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[97];
    char_T d_data[79];
    boolean_T x[77];
    static const char_T e[97] =
        "The parameter \'medusa_premix_left_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[79] =
        "The weights in \'medusa_premix_left_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S881>/Trivial Translation' */
    /* MATLAB Function: '<S881>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S881>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S895>:1' */
    /* '<S895>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Detent Level Left/Trivial Translation': '<S894>:1' */
    /* '<S894>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S894>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S894>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S894>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S894>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S894>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S894>:1:13' if(detentGain_Left.Size(1) ~= NumRows || detentGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Size[0] !=
            11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Size[1]
             != 7.0))
    {
        /* '<S894>:1:14' TranslateError('The parameter ''medusa_premix_left_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 97U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S894>:1:18' checkValues = (detentGain_Left.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Value[i]
             < 0.0);
    }

    /* '<S894>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S894>:1:20' TranslateError('The weights in ''medusa_premix_left_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 79U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S894>:1:24' TOP = detentGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_c[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Left.Value[0],
           77U * sizeof(real_T));

    /* '<S894>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S894>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_n[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S881>/Trivial Translation' */
}

/* Output and update for function-call system: '<S896>/tfunc' */
void FuncTranslation_Model_141_4107(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[98];
    char_T d_data[80];
    boolean_T x[77];
    static const char_T e[98] =
        "The parameter \'medusa_premix_right_detent\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[80] =
        "The weights in \'medusa_premix_right_detent\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S882>/Trivial Translation' */
    /* MATLAB Function: '<S882>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S882>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S898>:1' */
    /* '<S898>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Detent Level Right/Trivial Translation': '<S897>:1' */
    /* '<S897>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S897>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S897>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S897>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S897>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S897>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S897>:1:13' if(detentGain_Right.Size(1) ~= NumRows || detentGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Size[0] !=
         11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Size[1]
             != 7.0))
    {
        /* '<S897>:1:14' TranslateError('The parameter ''medusa_premix_right_detent'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 98U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S897>:1:18' checkValues = (detentGain_Right.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Value[i]
             < 0.0);
    }

    /* '<S897>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S897>:1:20' TranslateError('The weights in ''medusa_premix_right_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 80U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S897>:1:24' TOP = detentGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_h[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_Right.Value[0],
           77U * sizeof(real_T));

    /* '<S897>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S897>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_e[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S882>/Trivial Translation' */
}

/* Output and update for function-call system: '<S899>/tfunc' */
void FuncTranslation_Model_141_4114(void)
{
    /* MATLAB Function: '<S883>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S901>:1' */
    /* '<S901>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_a
        (&Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_l,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_new);
}

/* Output and update for function-call system: '<S902>/tfunc' */
void FuncTranslation_Model_141_4121(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[92];
    char_T d_data[74];
    int8_T nz[10];
    boolean_T x[20];
    static const char_T e[92] =
        "The parameter \'medusa_premix_cs_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[74] =
        "The weights in \'medusa_premix_cs_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S884>/Trivial Translation' */
    /* MATLAB Function: '<S884>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S884>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S904>:1' */
    /* '<S904>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Max Level CS/Trivial Translation': '<S903>:1' */
    /* '<S903>:1:3' numCSIn = MedusaPremixConfig.CS_in; */
    /* '<S903>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.CS; */
    /* '<S903>:1:6' NumRows = MedusaPremixConfig.CS_out; */
    /* '<S903>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S903>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S903>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S903>:1:13' if(maxGain_CS.Size(1) ~= NumRows || maxGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Size[0] != 2.0) ||
        (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Size[1] != 10.0))
    {
        /* '<S903>:1:14' TranslateError('The parameter ''medusa_premix_cs_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 92U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 10.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S903>:1:18' checkValues = (maxGain_CS.Value < 0); */
    for (i = 0; i < 20; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Value[i] <
                0.0);
    }

    /* '<S903>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 10; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 9; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S903>:1:20' TranslateError('The weights in ''medusa_premix_cs_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 74U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S903>:1:24' TOP = maxGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_p[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_CS.Value[0], 20U
           * sizeof(real_T));

    /* '<S903>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S903>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m3[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m3[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m3[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m3[3] = 0.0;

    /* End of MATLAB Function: '<S884>/Trivial Translation' */
}

/* Output and update for function-call system: '<S905>/tfunc' */
void FuncTranslation_Model_141_4129(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[94];
    char_T d_data[76];
    boolean_T x[77];
    static const char_T e[94] =
        "The parameter \'medusa_premix_left_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[76] =
        "The weights in \'medusa_premix_left_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S885>/Trivial Translation' */
    /* MATLAB Function: '<S885>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S885>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S907>:1' */
    /* '<S907>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Max Level Left/Trivial Translation': '<S906>:1' */
    /* '<S906>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S906>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S906>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S906>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S906>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S906>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S906>:1:13' if(maxGain_Left.Size(1) ~= NumRows || maxGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Size[0] !=
            11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Size[1] !=
             7.0))
    {
        /* '<S906>:1:14' TranslateError('The parameter ''medusa_premix_left_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 94U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S906>:1:18' checkValues = (maxGain_Left.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Value[i]
                < 0.0);
    }

    /* '<S906>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S906>:1:20' TranslateError('The weights in ''medusa_premix_left_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 76U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S906>:1:24' TOP = maxGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_k[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Left.Value[0],
           77U * sizeof(real_T));

    /* '<S906>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S906>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_a[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S885>/Trivial Translation' */
}

/* Output and update for function-call system: '<S908>/tfunc' */
void FuncTranslation_Model_141_4137(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[95];
    char_T d_data[77];
    boolean_T x[77];
    static const char_T e[95] =
        "The parameter \'medusa_premix_right_max\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[77] =
        "The weights in \'medusa_premix_right_max\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S886>/Trivial Translation' */
    /* MATLAB Function: '<S886>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S886>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S910>:1' */
    /* '<S910>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Max Level Right/Trivial Translation': '<S909>:1' */
    /* '<S909>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S909>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S909>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S909>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S909>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S909>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S909>:1:13' if(maxGain_Right.Size(1) ~= NumRows || maxGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Size[0] !=
            11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Size[1]
             != 7.0))
    {
        /* '<S909>:1:14' TranslateError('The parameter ''medusa_premix_right_max'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 95U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S909>:1:18' checkValues = (maxGain_Right.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Value[i] <
             0.0);
    }

    /* '<S909>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S909>:1:20' TranslateError('The weights in ''medusa_premix_right_max'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 77U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S909>:1:24' TOP = maxGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_d[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_Right.Value[0],
           77U * sizeof(real_T));

    /* '<S909>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S909>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_c[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S886>/Trivial Translation' */
}

/* Output and update for function-call system: '<S911>/tfunc' */
void FuncTranslation_Model_141_4145(void)
{
    int32_T i;
    int32_T xpageoffset;
    char_T c_data[92];
    char_T d_data[74];
    int8_T nz[10];
    boolean_T x[20];
    static const char_T e[92] =
        "The parameter \'medusa_premix_cs_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[74] =
        "The weights in \'medusa_premix_cs_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S887>/Trivial Translation' */
    /* MATLAB Function: '<S887>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S887>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S913>:1' */
    /* '<S913>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Min Level CS/Trivial Translation': '<S912>:1' */
    /* '<S912>:1:3' numCSIn = MedusaPremixConfig.CS_in; */
    /* '<S912>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.CS; */
    /* '<S912>:1:6' NumRows = MedusaPremixConfig.CS_out; */
    /* '<S912>:1:7' NumColumns = numCSIn + NumCAEWeights; */
    /* '<S912>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S912>:1:9' NumColumns = numCSIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S912>:1:13' if(minGain_CS.Size(1) ~= NumRows || minGain_CS.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Size[0] != 2.0) ||
        (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Size[1] != 10.0))
    {
        /* '<S912>:1:14' TranslateError('The parameter ''medusa_premix_cs_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 92U * sizeof(char_T));
        TranslateError(&c_data[0], 2.0, 10.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S912>:1:18' checkValues = (minGain_CS.Value < 0); */
    for (i = 0; i < 20; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Value[i] <
                0.0);
    }

    /* '<S912>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 10; i++)
    {
        xpageoffset = i << 1;
        nz[i] = (int8_T)(x[xpageoffset + 1] + x[xpageoffset]);
    }

    xpageoffset = nz[0];
    for (i = 0; i < 9; i++)
    {
        xpageoffset += nz[i + 1];
    }

    if (xpageoffset != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S912>:1:20' TranslateError('The weights in ''medusa_premix_cs_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 74U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S912>:1:24' TOP = minGain_CS.Value(:, 1:numCSIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_o[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_CS.Value[0], 20U
           * sizeof(real_T));

    /* '<S912>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S912>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m[0] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m[1] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m[2] = 0.0;
    Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_m[3] = 0.0;

    /* End of MATLAB Function: '<S887>/Trivial Translation' */
}

/* Output and update for function-call system: '<S914>/tfunc' */
void FuncTranslation_Model_141_4153(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[94];
    char_T d_data[76];
    boolean_T x[77];
    static const char_T e[94] =
        "The parameter \'medusa_premix_left_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[76] =
        "The weights in \'medusa_premix_left_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S888>/Trivial Translation' */
    /* MATLAB Function: '<S888>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S888>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S916>:1' */
    /* '<S916>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Min Level Left/Trivial Translation': '<S915>:1' */
    /* '<S915>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S915>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S915>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S915>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S915>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S915>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S915>:1:13' if(minGain_Left.Size(1) ~= NumRows || minGain_Left.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Size[0] !=
            11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Size[1] !=
             7.0))
    {
        /* '<S915>:1:14' TranslateError('The parameter ''medusa_premix_left_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 94U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S915>:1:18' checkValues = (minGain_Left.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] = (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Value[i]
                < 0.0);
    }

    /* '<S915>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S915>:1:20' TranslateError('The weights in ''medusa_premix_left_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 76U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S915>:1:24' TOP = minGain_Left.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_m[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Left.Value[0],
           77U * sizeof(real_T));

    /* '<S915>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S915>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE_b[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S888>/Trivial Translation' */
}

/* Output and update for function-call system: '<S917>/tfunc' */
void FuncTranslation_Model_141_4161(void)
{
    real_T b;
    int32_T nz[7];
    int32_T i;
    int32_T k;
    char_T c_data[95];
    char_T d_data[77];
    boolean_T x[77];
    static const char_T e[95] =
        "The parameter \'medusa_premix_right_min\' must be a matrix consisting of %d rows and %d columns.";
    static const char_T f[77] =
        "The weights in \'medusa_premix_right_min\' must be greater than or equal to 0.";

    /* MATLAB Function: '<S889>/Trivial Translation' */
    /* MATLAB Function: '<S889>/Trivial Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S889>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S919>:1' */
    /* '<S919>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/Premix/Premix with Mono-Surround & CAE with Fade Ramper/SLC Tuning/Min Level Right/Trivial Translation': '<S918>:1' */
    /* '<S918>:1:3' numLRIn = MedusaPremixConfig.LR_in; */
    /* '<S918>:1:4' NumCAEWeights = MedusaPremixConfig.NumTailComp.LR; */
    /* '<S918>:1:6' NumRows = MedusaPremixConfig.LR_out; */
    /* '<S918>:1:7' NumColumns = numLRIn + NumCAEWeights; */
    /* '<S918>:1:8' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S918>:1:9' NumColumns = numLRIn; */
    /*  Checks if the parameter satisfies dimensionality requirements */
    /* '<S918>:1:13' if(minGain_Right.Size(1) ~= NumRows || minGain_Right.Size(2) ~= NumColumns) */
    if ((Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Size[0] !=
            11.0) ||
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Size[1]
             != 7.0))
    {
        /* '<S918>:1:14' TranslateError('The parameter ''medusa_premix_right_min'' must be a matrix consisting of %d rows and %d columns.', NumRows, NumColumns); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        memcpy(&c_data[0], &e[0], 95U * sizeof(char_T));
        TranslateError(&c_data[0], 11.0, 7.0);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S918>:1:18' checkValues = (minGain_Right.Value < 0); */
    for (i = 0; i < 77; i++)
    {
        x[i] =
            (Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Value[i] <
             0.0);
    }

    /* '<S918>:1:19' if(sum(sum(checkValues))) */
    for (i = 0; i < 7; i++)
    {
        int32_T xpageoffset;
        xpageoffset = i * 11;
        nz[i] = x[xpageoffset];
        for (k = 0; k < 10; k++)
        {
            nz[i] += x[(xpageoffset + k) + 1];
        }
    }

    b = nz[0];
    for (i = 0; i < 6; i++)
    {
        b += (real_T)nz[i + 1];
    }

    if (b != 0.0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S918>:1:20' TranslateError('The weights in ''medusa_premix_right_min'' must be greater than or equal to 0.'); */
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
        memcpy(&d_data[0], &f[0], 77U * sizeof(char_T));
        TranslateError(&d_data[0]);
    }

    /*  Assigning the parameter values to respective tuneTOPS */
    /* '<S918>:1:24' TOP = minGain_Right.Value(:, 1:numLRIn); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP[0],
           &Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_Right.Value[0],
           77U * sizeof(real_T));

    /* '<S918>:1:25' if(~ MedusaPremixConfig.includeCAE) */
    /* '<S918>:1:26' TOP_CAE = zeros(NumRows, NumCAEWeights); */
    memset(&Model_TranslationEngine64_Medusa5H1Part3_B.TOP_CAE[0], 0, 33U *
           sizeof(real_T));

    /* End of MATLAB Function: '<S889>/Trivial Translation' */
}

/* Output and update for function-call system: '<S929>/tfunc' */
void FuncTranslation_Model_141_983_182(void)
{
    /* MATLAB Function: '<S924>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S931>:1' */
    /* '<S931>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_a,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_jf);
}

/* Output and update for function-call system: '<S932>/tfunc' */
void FuncTranslation_Model_141_983_188(void)
{
    /* MATLAB Function: '<S925>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S934>:1' */
    /* '<S934>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_f
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_c,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_de);
}

/*
 * Output and update for function-call system:
 *    '<S926>/Trivial Translation'
 *    '<S964>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_n(const bus_double_12__1
    *rtu_downmix_wts, B_TrivialTranslation_Model_TranslationEngine64_e_T *localB)
{
    int32_T i;
    int32_T nz;
    char_T c_data[65];
    char_T b_data[57];
    boolean_T x[12];
    static const char_T d[57] =
        "The parameter \'VLS_downmix\' must be a %d element vector.";
    static const char_T e[65] =
        "The weights in \'VLS_downmix\' must be greater than or equal to 0.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/VLS Gains Computation/VLS Gains Drv/Fade Tuning/Downmix Weights/Trivial Translation': '<S936>:1' */
    /* '<S936>:1:5' if(downmix_wts.Size(1) ~= configStruct.numGains) */
    if (rtu_downmix_wts->Size[0] != 12.0)
    {
        /* '<S936>:1:6' TranslateError('The parameter ''VLS_downmix'' must be a %d element vector.', configStruct.numGains); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 57; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0], 12U);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S936>:1:10' checkValues = (downmix_wts.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (rtu_downmix_wts->Value[i] < 0.0);
    }

    /* '<S936>:1:11' if(sum(sum(checkValues))) */
    nz = x[0];
    for (i = 0; i < 11; i++)
    {
        nz += x[i + 1];
    }

    if (nz != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S936>:1:12' TranslateError('The weights in ''VLS_downmix'' must be greater than or equal to 0.'); */
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
        memcpy(&c_data[0], &e[0], 65U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S936>:1:15' TOP = downmix_wts.Value; */
    memcpy(&localB->TOP[0], &rtu_downmix_wts->Value[0], 12U * sizeof(real_T));
}

/* Output and update for function-call system: '<S935>/tfunc' */
void FuncTranslation_Model_141_983_194(void)
{
    /* MATLAB Function: '<S926>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S937>:1' */
    /* '<S937>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_n
        (&Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_n5);
}

/* Output and update for function-call system: '<S938>/tfunc' */
void FuncTranslation_Model_141_983_200(void)
{
    /* MATLAB Function: '<S927>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S940>:1' */
    /* '<S940>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_p
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_n,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ags);
}

/* Output and update for function-call system: '<S941>/tfunc' */
void FuncTranslation_Model_141_983_206(void)
{
    /* MATLAB Function: '<S928>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S943>:1' */
    /* '<S943>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pz
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_a,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_i5b);
}

/*
 * Output and update for function-call system:
 *    '<S944>/Trivial Translation'
 *    '<S982>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_c(const bus_double_12__1
    *rtu_detentGain, B_TrivialTranslation_Model_TranslationEngine64_o_T *localB)
{
    int32_T i;
    int32_T nz;
    char_T c_data[70];
    char_T b_data[62];
    boolean_T x[12];
    static const char_T d[62] =
        "The parameter \'VLS_gains_detent\' must be a %d element vector.";
    static const char_T e[70] =
        "The weights in \'VLS_gains_detent\' must be greater than or equal to 0.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/VLS Gains Computation/VLS Gains Drv/SLC Tuning/Detent Level/Trivial Translation': '<S949>:1' */
    /* '<S949>:1:5' if(detentGain.Size(1) ~= configStruct.numGains) */
    if (rtu_detentGain->Size[0] != 12.0)
    {
        /* '<S949>:1:6' TranslateError('The parameter ''VLS_gains_detent'' must be a %d element vector.', configStruct.numGains); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 62; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0], 12U);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S949>:1:10' checkValues = (detentGain.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (rtu_detentGain->Value[i] < 0.0);
    }

    /* '<S949>:1:11' if(sum(sum(checkValues))) */
    nz = x[0];
    for (i = 0; i < 11; i++)
    {
        nz += x[i + 1];
    }

    if (nz != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S949>:1:12' TranslateError('The weights in ''VLS_gains_detent'' must be greater than or equal to 0.'); */
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
        memcpy(&c_data[0], &e[0], 70U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S949>:1:15' TOP = detentGain.Value; */
    memcpy(&localB->TOP[0], &rtu_detentGain->Value[0], 12U * sizeof(real_T));
}

/* Output and update for function-call system: '<S948>/tfunc' */
void FuncTranslation_Model_141_983_287(void)
{
    /* MATLAB Function: '<S944>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S950>:1' */
    /* '<S950>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_c
        (&Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_ci2);
}

/* Output and update for function-call system: '<S951>/tfunc' */
void FuncTranslation_Model_141_983_293(void)
{
    /* MATLAB Function: '<S945>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S953>:1' */
    /* '<S953>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_a
        (&Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_j,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_mpr);
}

/*
 * Output and update for function-call system:
 *    '<S946>/Trivial Translation'
 *    '<S984>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_i(const bus_double_12__1
    *rtu_maxGain, B_TrivialTranslation_Model_TranslationEngine64_f_T *localB)
{
    int32_T i;
    int32_T nz;
    char_T c_data[67];
    char_T b_data[59];
    boolean_T x[12];
    static const char_T d[59] =
        "The parameter \'VLS_gains_max\' must be a %d element vector.";
    static const char_T e[67] =
        "The weights in \'VLS_gains_max\' must be greater than or equal to 0.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/VLS Gains Computation/VLS Gains Drv/SLC Tuning/Max Level/Trivial Translation': '<S955>:1' */
    /* '<S955>:1:5' if(maxGain.Size(1) ~= configStruct.numGains) */
    if (rtu_maxGain->Size[0] != 12.0)
    {
        /* '<S955>:1:6' TranslateError('The parameter ''VLS_gains_max'' must be a %d element vector.', configStruct.numGains); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 59; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0], 12U);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S955>:1:10' checkValues = (maxGain.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (rtu_maxGain->Value[i] < 0.0);
    }

    /* '<S955>:1:11' if(sum(sum(checkValues))) */
    nz = x[0];
    for (i = 0; i < 11; i++)
    {
        nz += x[i + 1];
    }

    if (nz != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S955>:1:12' TranslateError('The weights in ''VLS_gains_max'' must be greater than or equal to 0.'); */
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
        memcpy(&c_data[0], &e[0], 67U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S955>:1:15' TOP = maxGain.Value; */
    memcpy(&localB->TOP[0], &rtu_maxGain->Value[0], 12U * sizeof(real_T));
}

/* Output and update for function-call system: '<S954>/tfunc' */
void FuncTranslation_Model_141_983_299(void)
{
    /* MATLAB Function: '<S946>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S956>:1' */
    /* '<S956>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_i
        (&Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_il);
}

/*
 * Output and update for function-call system:
 *    '<S947>/Trivial Translation'
 *    '<S985>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_c1(const bus_double_12__1
    *rtu_minGain, B_TrivialTranslation_Model_TranslationEngine64_j_T *localB)
{
    int32_T i;
    int32_T nz;
    char_T c_data[67];
    char_T b_data[59];
    boolean_T x[12];
    static const char_T d[59] =
        "The parameter \'VLS_gains_min\' must be a %d element vector.";
    static const char_T e[67] =
        "The weights in \'VLS_gains_min\' must be greater than or equal to 0.";

    /*  Checks if the parameter satisfies dimensionality requirements */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 3/On/VLS Gains Computation/VLS Gains Drv/SLC Tuning/Min Level/Trivial Translation': '<S958>:1' */
    /* '<S958>:1:5' if(minGain.Size(1) ~= configStruct.numGains) */
    if (rtu_minGain->Size[0] != 12.0)
    {
        /* '<S958>:1:6' TranslateError('The parameter ''VLS_gains_min'' must be a %d element vector.', configStruct.numGains); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (i = 0; i < 59; i++)
        {
            b_data[i] = d[i];
        }

        TranslateError(&b_data[0], 12U);
    }

    /*  Checks if the parameter values follow bound requirements */
    /* '<S958>:1:10' checkValues = (minGain.Value < 0); */
    for (i = 0; i < 12; i++)
    {
        x[i] = (rtu_minGain->Value[i] < 0.0);
    }

    /* '<S958>:1:11' if(sum(sum(checkValues))) */
    nz = x[0];
    for (i = 0; i < 11; i++)
    {
        nz += x[i + 1];
    }

    if (nz != 0)
    {
        /*  Results in 0 if all values in the matrix respect the bound requirements */
        /* '<S958>:1:12' TranslateError('The weights in ''VLS_gains_min'' must be greater than or equal to 0.'); */
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
        memcpy(&c_data[0], &e[0], 67U * sizeof(char_T));
        TranslateError(&c_data[0]);
    }

    /* '<S958>:1:15' TOP = minGain.Value; */
    memcpy(&localB->TOP[0], &rtu_minGain->Value[0], 12U * sizeof(real_T));
}

/* Output and update for function-call system: '<S957>/tfunc' */
void FuncTranslation_Model_141_983_305(void)
{
    /* MATLAB Function: '<S947>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S959>:1' */
    /* '<S959>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_c1
        (&Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_c1);
}

/* Output and update for function-call system: '<S967>/tfunc' */
void FuncTranslation_Model_141_984_182(void)
{
    /* MATLAB Function: '<S962>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S969>:1' */
    /* '<S969>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixMax_o,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_nlp);
}

/* Output and update for function-call system: '<S970>/tfunc' */
void FuncTranslation_Model_141_984_188(void)
{
    /* MATLAB Function: '<S963>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S972>:1' */
    /* '<S972>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_f
        (&Model_TranslationEngine64_Medusa5H1Part3_B.BackwardDownmixThreshold_i,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_l2w);
}

/* Output and update for function-call system: '<S973>/tfunc' */
void FuncTranslation_Model_141_984_194(void)
{
    /* MATLAB Function: '<S964>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S975>:1' */
    /* '<S975>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_n
        (&Model_TranslationEngine64_Medusa5H1Part3_B.DownmixWeights_k,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_nezf);
}

/* Output and update for function-call system: '<S976>/tfunc' */
void FuncTranslation_Model_141_984_200(void)
{
    /* MATLAB Function: '<S965>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S978>:1' */
    /* '<S978>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_p
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixThreshold_h,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_cfe);
}

/* Output and update for function-call system: '<S979>/tfunc' */
void FuncTranslation_Model_141_984_206(void)
{
    /* MATLAB Function: '<S966>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S981>:1' */
    /* '<S981>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pz
        (&Model_TranslationEngine64_Medusa5H1Part3_B.ForwardDownmixMax_o,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_i1c);
}

/* Output and update for function-call system: '<S986>/tfunc' */
void FuncTranslation_Model_141_984_287(void)
{
    /* MATLAB Function: '<S982>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S988>:1' */
    /* '<S988>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_c
        (&Model_TranslationEngine64_Medusa5H1Part3_B.DetentLevel_e,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_eng);
}

/* Output and update for function-call system: '<S989>/tfunc' */
void FuncTranslation_Model_141_984_293(void)
{
    /* MATLAB Function: '<S983>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S991>:1' */
    /* '<S991>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_a
        (&Model_TranslationEngine64_Medusa5H1Part3_B.Interpolation_Method_o,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_aig);
}

/* Output and update for function-call system: '<S992>/tfunc' */
void FuncTranslation_Model_141_984_299(void)
{
    /* MATLAB Function: '<S984>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S994>:1' */
    /* '<S994>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_i
        (&Model_TranslationEngine64_Medusa5H1Part3_B.MaxLevel_j,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_a5u);
}

/* Output and update for function-call system: '<S995>/tfunc' */
void FuncTranslation_Model_141_984_305(void)
{
    /* MATLAB Function: '<S985>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S997>:1' */
    /* '<S997>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_c1
        (&Model_TranslationEngine64_Medusa5H1Part3_B.MinLevel_m,
         &Model_TranslationEngine64_Medusa5H1Part3_B.sf_TrivialTranslation_gv);
}

/* Function for MATLAB Function: '<S1004>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_l(int32_T b,
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

/* Output and update for function-call system: '<S1005>/tfunc' */
void FuncTranslation_Model_141_472_255_36(void)
{
    real_T OverallGainPerCh[66];
    real_T c_y;
    real_T offset;
    int32_T NumStages[66];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T d_k;
    int32_T k;
    int32_T yk;
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1004>/Translation' */
    /* MATLAB Function: '<S1004>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1004>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1004>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1007>:1' */
    /* '<S1007>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 4/On/DR Mix Matrix with Hybrid Holigram EQ/IIR/PoolIirTunableWithReset/Translation': '<S1006>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1006>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1006>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1006>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (SOSIndex = 0; SOSIndex < 66; SOSIndex++)
    {
        c_y = rt_roundd_snf
            (Model_TranslationEngine64_Medusa5H1Part4_B.numStages.Value[SOSIndex]);
        if (c_y < 2.147483648E+9)
        {
            if (c_y >= -2.147483648E+9)
            {
                NumStages[SOSIndex] = (int32_T)c_y;
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

        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_f[SOSIndex] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_m[0], 0, 5280U
           * sizeof(real32_T));
    memset(&Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[0], 0,
           5280U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    offset = NumStages[0];
    for (k = 0; k < 65; k++)
    {
        offset += (real_T)NumStages[k + 1];
    }

    if (offset > 1320.0)
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
    for (k = 0; k < 66; k++)
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
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_l(NumStages_0,
                Model_TranslationEngine64_Medusa5H1Part4_B.tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = Model_TranslationEngine64_Medusa5H1Part4_B.tmp_data[d_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[d_k
                        + ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients.Value
                        [(1320 * b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data
                        [yk - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[tmp_size
                    [1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    c_y *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data
                        [(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = offset / c_y;

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
                Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[0] = 1;
                yk = 1;
                for (d_k = 2; d_k <= b_vlen; d_k++)
                {
                    yk += 4;
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[d_k - 1] =
                        yk;
                }
            }

            yk = b_vlen - 1;
            for (b_vlen = 0; b_vlen <= yk; b_vlen++)
            {
                d_k = Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen];
                if (d_k < -2147483647)
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen] =
                        MIN_int32_T;
                }
                else
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen] =
                        d_k - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            d_k = (ts_size_idx_1 / 4) << 2;
            q1 = d_k - 4;
            for (b_vlen = 0; b_vlen <= q1; b_vlen += 4)
            {
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)
                                      &Model_TranslationEngine64_Medusa5H1Part4_B.ts_data
                                      [b_vlen]);
                _mm_storeu_si128((__m128i *)
                                 &Model_TranslationEngine64_Medusa5H1Part4_B.b_data
                                 [b_vlen], _mm_add_epi32(tmp, _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.b_data[b_vlen] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen] +
                    1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[Model_TranslationEngine64_Medusa5H1Part4_B.b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                d_k = Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen];
                if (d_k > 2147483645)
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.b_data[b_vlen] =
                        MAX_int32_T;
                }
                else
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.b_data[b_vlen] =
                        d_k + 2;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[Model_TranslationEngine64_Medusa5H1Part4_B.b_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[b_vlen
                    + ChannelSOS_size_idx_0] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[b_vlen];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                d_k = Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen];
                if (d_k > 2147483644)
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.b_data[b_vlen] =
                        MAX_int32_T;
                }
                else
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.b_data[b_vlen] =
                        d_k + 3;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[Model_TranslationEngine64_Medusa5H1Part4_B.b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 5 + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            for (b_vlen = 0; b_vlen <= yk; b_vlen++)
            {
                d_k = Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen];
                if (d_k > 2147483643)
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen] =
                        MAX_int32_T;
                }
                else
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.ts_data[b_vlen] =
                        d_k + 4;
                }
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[Model_TranslationEngine64_Medusa5H1Part4_B.ts_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data[b_vlen];
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
                    Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_f[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_f
                        [d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_f[k] =
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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_l(b_vlen,
                Model_TranslationEngine64_Medusa5H1Part4_B.tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                c_y = offset + (real_T)
                    Model_TranslationEngine64_Medusa5H1Part4_B.tmp_data[b_vlen];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        Model_TranslationEngine64_Medusa5H1Part4_B.f_data[b_vlen]
                            = (int32_T)c_y;
                    }
                    else
                    {
                        Model_TranslationEngine64_Medusa5H1Part4_B.f_data[b_vlen]
                            = MIN_int32_T;
                    }
                }
                else
                {
                    Model_TranslationEngine64_Medusa5H1Part4_B.f_data[b_vlen] =
                        MAX_int32_T;
                }
            }

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_m[Model_TranslationEngine64_Medusa5H1Part4_B.f_data
                    [b_vlen] - 1] = (real32_T)
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_n[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_m[0], 5280U *
           sizeof(real32_T));
    for (SOSIndex = 0; SOSIndex < 66; SOSIndex++)
    {
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_n[SOSIndex + 5280]
            = (real32_T)OverallGainPerCh[SOSIndex];
    }

    /* End of MATLAB Function: '<S1004>/Translation' */
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

/* Output and update for function-call system: '<S1008>/tfunc' */
void FuncTranslation_Model_141_472_235(void)
{
    /* MATLAB Function: '<S1003>/translation' */
    /* MATLAB Function: '<S1003>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1003>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1003>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1003>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1012>:1' */
    /* '<S1012>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 4/On/DR Mix Matrix with Hybrid Holigram EQ/Tune Translations/translation': '<S1011>:1' */
    /* '<S1011>:1:3' FIRCoeffs = FIRCoeffsIn.Value; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_o[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs.Value[0],
           35112U * sizeof(real_T));

    /* '<S1011>:1:4' FIRLengths = FIRLengthsIn.Value; */
    /* '<S1011>:1:5' PaddedFIRLengths = PaddedFIRLengthsIn.Value; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_c[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths.Value[0], 66U *
           sizeof(uint32_T));
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_i[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths.Value[0],
           66U * sizeof(uint32_T));
}

/* Output and update for function-call system: '<S1015>/tfunc' */
void FuncTranslation_Model_141_472_239_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1013>/Subsystem' */
    /* SignalConversion generated from: '<S1014>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1016>:1' */
    /* '<S1016>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.Value_n[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.InputMapping.Value[0],
           66U * sizeof(uint32_T));

    /* End of Outputs for SubSystem: '<S1013>/Subsystem' */
}

/* Output and update for function-call system: '<S1019>/tfunc' */
void FuncTranslation_Model_141_472_240_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1017>/Subsystem' */
    /* SignalConversion generated from: '<S1018>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1020>:1' */
    /* '<S1020>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.Value[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.OutputMapping.Value[0],
           18U * sizeof(uint32_T));

    /* End of Outputs for SubSystem: '<S1017>/Subsystem' */
}

/* Function for MATLAB Function: '<S1022>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_d3(int32_T b,
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

/* Output and update for function-call system: '<S1023>/tfunc' */
void FuncTranslation_Model_141_473_12_36(void)
{
    real_T OverallGainPerCh[22];
    real_T c_y;
    real_T offset;
    int32_T f_data[704];
    int32_T tmp_data[704];
    int32_T b_data[176];
    int32_T ts_data[176];
    int32_T NumStages[22];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T d_k;
    int32_T k;
    int32_T yk;
    real32_T PoolCoeffs[704];
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1022>/Translation' */
    /* MATLAB Function: '<S1022>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1022>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1022>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1025>:1' */
    /* '<S1025>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 4/On/FR IIR Holigram EQ/IIR/PoolIirTunableWithReset/Translation': '<S1024>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1024>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1024>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1024>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (SOSIndex = 0; SOSIndex < 22; SOSIndex++)
    {
        c_y = rt_roundd_snf
            (Model_TranslationEngine64_Medusa5H1Part4_B.numStages_j.Value[SOSIndex]);
        if (c_y < 2.147483648E+9)
        {
            if (c_y >= -2.147483648E+9)
            {
                NumStages[SOSIndex] = (int32_T)c_y;
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

        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_k[SOSIndex] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 704U * sizeof(real32_T));
    memset(&Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[0], 0,
           704U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    offset = NumStages[0];
    for (k = 0; k < 21; k++)
    {
        offset += (real_T)NumStages[k + 1];
    }

    if (offset > 176.0)
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
    for (k = 0; k < 22; k++)
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
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_d3
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = tmp_data[d_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                        d_k + ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_a.Value
                        [(176 * b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m
                        [yk - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    tmp_size[1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    c_y *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m
                        [(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = offset / c_y;

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
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[b_vlen]);
                _mm_storeu_si128((__m128i *)&b_data[b_vlen], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                b_data[b_vlen] = ts_data[b_vlen] + 1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    ChannelSOS_size_idx_0 * 3 + b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[b_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    b_vlen + ChannelSOS_size_idx_0] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m
                    [ChannelSOS_size_idx_0 * 5 + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    ChannelSOS_size_idx_0 * 3 + b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[ts_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    (ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_m[
                    b_vlen];
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
                    Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_k[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_k
                        [d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages_k[k] =
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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_d3(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                c_y = offset + (real_T)tmp_data[b_vlen];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        f_data[b_vlen] = (int32_T)c_y;
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_c[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_l[0],
           &PoolCoeffs[0], 704U * sizeof(real32_T));
    for (SOSIndex = 0; SOSIndex < 22; SOSIndex++)
    {
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs_l[SOSIndex + 704] =
            (real32_T)OverallGainPerCh[SOSIndex];
    }

    /* End of MATLAB Function: '<S1022>/Translation' */
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

/* Function for MATLAB Function: '<S1029>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_i0(int32_T b,
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

/* Output and update for function-call system: '<S1030>/tfunc' */
void FuncTranslation_Model_141_595_238_36(void)
{
    real_T OverallGainPerCh[12];
    real_T c_y;
    real_T offset;
    int32_T f_data[960];
    int32_T tmp_data[960];
    int32_T b_data[240];
    int32_T ts_data[240];
    int32_T NumStages[12];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T d_k;
    int32_T k;
    int32_T yk;
    real32_T PoolCoeffs[960];
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1029>/Translation' */
    /* MATLAB Function: '<S1029>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1029>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1029>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1032>:1' */
    /* '<S1032>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 4/On/Headrest Comp EQ/IIR/PoolIirTunableWithReset/Translation': '<S1031>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1031>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1031>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1031>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (SOSIndex = 0; SOSIndex < 12; SOSIndex++)
    {
        c_y = rt_roundd_snf
            (Model_TranslationEngine64_Medusa5H1Part4_B.numStages_m.Value[SOSIndex]);
        if (c_y < 2.147483648E+9)
        {
            if (c_y >= -2.147483648E+9)
            {
                NumStages[SOSIndex] = (int32_T)c_y;
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

        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages[SOSIndex] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 960U * sizeof(real32_T));
    memset(&Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[0], 0,
           960U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    offset = NumStages[0];
    for (k = 0; k < 11; k++)
    {
        offset += (real_T)NumStages[k + 1];
    }

    if (offset > 240.0)
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
    for (k = 0; k < 12; k++)
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
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_i0
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = tmp_data[d_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                        [d_k + ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_Medusa5H1Part4_B.sosCoefficients_d.Value
                        [(240 * b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                        [yk - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [tmp_size[1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    c_y *=
                        Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                        [(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = offset / c_y;

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
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[b_vlen]);
                _mm_storeu_si128((__m128i *)&b_data[b_vlen], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                b_data[b_vlen] = ts_data[b_vlen] + 1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [ChannelSOS_size_idx_0 * 3 + b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[b_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [b_vlen + ChannelSOS_size_idx_0] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[b_data
                    [b_vlen] - 1] =
                    -Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [ChannelSOS_size_idx_0 * 5 + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [ChannelSOS_size_idx_0 * 3 + b_vlen];
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
                Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[ts_data
                    [b_vlen] - 1] =
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [(ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelSOS_data_mb
                    [b_vlen];
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
                    Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages[
                        d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_Medusa5H1Part4_B.PoolNumStages[k] =
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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_i0(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                c_y = offset + (real_T)tmp_data[b_vlen];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        f_data[b_vlen] = (int32_T)c_y;
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)
                    Model_TranslationEngine64_Medusa5H1Part4_B.ChannelCoeffs_cl[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs[0],
           &PoolCoeffs[0], 960U * sizeof(real32_T));
    for (SOSIndex = 0; SOSIndex < 12; SOSIndex++)
    {
        Model_TranslationEngine64_Medusa5H1Part4_B.PoolCoeffs[SOSIndex + 960] =
            (real32_T)OverallGainPerCh[SOSIndex];
    }

    /* End of MATLAB Function: '<S1029>/Translation' */
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

/* Output and update for function-call system: '<S1027>/tfunc' */
void FuncTranslation_Model_141_595_191(void)
{
    /* MATLAB Function: '<S1001>/translation' */
    /* MATLAB Function: '<S1001>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1001>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1001>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1001>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1033>:1' */
    /* '<S1033>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 4/On/Headrest Comp EQ/translation': '<S1028>:1' */
    /* '<S1028>:1:3' FIRCoeffs = FIRCoeffsIn.Value; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_p[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.FIRCoeffs_e.Value[0],
           6384U * sizeof(real_T));

    /* '<S1028>:1:4' FIRLengths = FIRLengthsIn.Value; */
    /* '<S1028>:1:5' PaddedFIRLengths = PaddedFIRLengthsIn.Value; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_e[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.FIRLengths_j.Value[0],
           12U * sizeof(real_T));
    memcpy(&Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_k[0],
           &Model_TranslationEngine64_Medusa5H1Part4_B.PaddedFIRLengths_f.Value
           [0], 12U * sizeof(real_T));
}

/* Output and update for function-call system: '<S1036>/tfunc' */
void FuncTranslation_Model_141_4193(void)
{
    real_T FRNonHRDelaySamples[18];
    real_T b_rem[18];
    real_T FRHRDrvDelaySamples;
    real_T FRHRPaxDelaySamples;
    real_T c_rem;
    int32_T FREQDelaySamples[22];
    int32_T DRNonHRDelaySamples[18];
    int32_T b_FRNonHRDelaySamples[18];
    int32_T b_FRHRDrvDelaySamples;
    int32_T b_FRHRPaxDelaySamples;
    int32_T b_FRNonHRDelaySamples_0;
    int32_T b_a;
    int32_T f_k;
    int32_T nz;
    char_T d_data[58];
    char_T c_data[55];
    char_T e_data[51];
    char_T g_data[46];
    char_T b_data[40];
    char_T i_data[34];
    char_T f_data[18];
    char_T h_data[14];
    boolean_T b_x[22];
    boolean_T x[18];
    boolean_T y;
    static const char_T n[40] = "Speaker delays must be a multiple of 4.";
    static const char_T o[55] =
        "Driver headrest speaker delay must be a multiple of 4.";
    static const char_T p[58] =
        "Passenger headrest speaker delay must be a multiple of 4.";
    static const char_T q[51] =
        "Value of %s must be greater than or equal to zero.";
    static const char_T r[18] = "Medusa HFEQ delay";
    static const char_T s[46] = "Value of %s must be less than or equal to %d.";
    static const char_T t[14] = "h01/h0r delay";
    static const char_T u[14] = "h1l/h1r delay";
    static const char_T v[34] = "Medusa non-headrest speaker delay";
    boolean_T exitg1;

    /* MATLAB Function: '<S1035>/translation' */
    /* MATLAB Function: '<S1035>/translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1034>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1034>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1034>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S1034>/Tune Variable5'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1038>:1' */
    /* '<S1038>:1:3' f(); */
    /* [Param:DecimationFactor] */
    /* [Param:maxFullRateHoligramDelay] */
    /* [Param:maxFullRateSpeakerDelay] */
    /* [Param:numHeadrestComps] */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaHoligram/Medusa5H1 Part 6/Speaker Delay Tune/Output Delay Translation with Headrest/translation': '<S1037>:1' */
    /* '<S1037>:1:9' nonHRDelaySamples = tuneNonHRDelaySamples.Value; */
    memcpy(&FRNonHRDelaySamples[0],
           &Model_TranslationEngine64_Medusa5H1Part6_B.NonHeadrestSpeakerDelaySamples.Value
           [0], 18U * sizeof(real_T));

    /* '<S1037>:1:10' HRDrvDelaySamples = tuneHRDrvDelaySamples.Value; */
    /* '<S1037>:1:11' HRPaxDelaySamples = tuneHRPaxDelaySamples.Value; */
    /* '<S1037>:1:12' FREQDelaySamples = int32(tuneFREQDelaySamples.Value); */
    for (nz = 0; nz < 22; nz++)
    {
        FREQDelaySamples[nz] = (int32_T)rt_roundd_snf
            (Model_TranslationEngine64_Medusa5H1Part6_B.FRHoligramDelaySamples.Value
             [nz]);
    }

    /*  Get delay upper bounds */
    /* '<S1037>:1:15' maxFREQDelay = maxFullRateHoligramDelay; */
    /* '<S1037>:1:16' maxFRSpkrDelay = maxFullRateSpeakerDelay; */
    /*  Compute delay values in samples */
    /* '<S1037>:1:19' DEC = DecimationFactor; */
    /*  sampleRate = sampleRate; */
    /* '<S1037>:1:21' FRHRDrvDelaySamples = round(HRDrvDelaySamples); */
    FRHRDrvDelaySamples = rt_roundd_snf
        (Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestDrvSpeakerDelaySamples.Value);

    /* '<S1037>:1:22' FRHRPaxDelaySamples = round(HRPaxDelaySamples); */
    FRHRPaxDelaySamples = rt_roundd_snf
        (Model_TranslationEngine64_Medusa5H1Part6_B.HeadrestPaxSpeakerDelaySamples.Value);

    /* '<S1037>:1:23' FRNonHRDelaySamples = round(nonHRDelaySamples); */
    /*  Check whether speaker delays are multiple of 4, and if not round them up  */
    /*  to the nearest multiple */
    /* '<S1037>:1:27' rem = ceil(FRNonHRDelaySamples/4)*4 - FRNonHRDelaySamples; */
    /* '<S1037>:1:28' FRNonHRDelaySamples = int32(FRNonHRDelaySamples + rem); */
    /* '<S1037>:1:29' DRNonHRDelaySamples = int32(FRNonHRDelaySamples/DEC); */
    for (b_FRHRDrvDelaySamples = 0; b_FRHRDrvDelaySamples < 18;
            b_FRHRDrvDelaySamples++)
    {
        real_T b_rem_0;
        c_rem = rt_roundd_snf(FRNonHRDelaySamples[b_FRHRDrvDelaySamples]);
        b_rem_0 = ceil(c_rem / 4.0) * 4.0 - c_rem;
        b_FRNonHRDelaySamples_0 = (int32_T)(c_rem + b_rem_0);
        DRNonHRDelaySamples[b_FRHRDrvDelaySamples] = (int32_T)rt_roundd_snf
            ((real_T)b_FRNonHRDelaySamples_0 / 4.0);
        b_rem[b_FRHRDrvDelaySamples] = b_rem_0;
        b_FRNonHRDelaySamples[b_FRHRDrvDelaySamples] = b_FRNonHRDelaySamples_0;
        FRNonHRDelaySamples[b_FRHRDrvDelaySamples] = c_rem;
    }

    /* '<S1037>:1:30' if any(rem ~= 0) */
    y = false;
    b_FRHRDrvDelaySamples = 0;
    exitg1 = false;
    while ((!exitg1) && (b_FRHRDrvDelaySamples < 18))
    {
        if (b_rem[b_FRHRDrvDelaySamples] != 0.0)
        {
            y = true;
            exitg1 = true;
        }
        else
        {
            b_FRHRDrvDelaySamples++;
        }
    }

    if (y)
    {
        /* '<S1037>:1:31' TranslateError('Speaker delays must be a multiple of 4.'); */
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
        for (nz = 0; nz < 40; nz++)
        {
            b_data[nz] = n[nz];
        }

        TranslateError(&b_data[0]);
    }

    /* '<S1037>:1:34' rem = ceil(FRHRDrvDelaySamples/4)*4 - FRHRDrvDelaySamples; */
    c_rem = ceil(FRHRDrvDelaySamples / 4.0) * 4.0 - FRHRDrvDelaySamples;

    /* '<S1037>:1:35' FRHRDrvDelaySamples = int32(FRHRDrvDelaySamples + rem); */
    b_FRHRDrvDelaySamples = (int32_T)(FRHRDrvDelaySamples + c_rem);

    /* '<S1037>:1:36' DRHRDrvDelaySamples = int32(FRHRDrvDelaySamples/DEC); */
    b_FRNonHRDelaySamples_0 = (int32_T)rt_roundd_snf((real_T)
        b_FRHRDrvDelaySamples / 4.0);

    /* '<S1037>:1:37' if any(rem ~= 0) */
    if (c_rem != 0.0)
    {
        /* '<S1037>:1:38' TranslateError('Driver headrest speaker delay must be a multiple of 4.'); */
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
        for (nz = 0; nz < 55; nz++)
        {
            c_data[nz] = o[nz];
        }

        TranslateError(&c_data[0]);
    }

    /* '<S1037>:1:41' rem = ceil(FRHRPaxDelaySamples/4)*4 - FRHRPaxDelaySamples; */
    c_rem = ceil(FRHRPaxDelaySamples / 4.0) * 4.0 - FRHRPaxDelaySamples;

    /* '<S1037>:1:42' FRHRPaxDelaySamples = int32(FRHRPaxDelaySamples + rem); */
    b_FRHRPaxDelaySamples = (int32_T)(FRHRPaxDelaySamples + c_rem);

    /* '<S1037>:1:43' DRHRPaxDelaySamples = int32(FRHRPaxDelaySamples/DEC); */
    b_a = (int32_T)rt_roundd_snf((real_T)b_FRHRPaxDelaySamples / 4.0);

    /* '<S1037>:1:44' if any(rem ~= 0) */
    if (c_rem != 0.0)
    {
        /* '<S1037>:1:45' TranslateError('Passenger headrest speaker delay must be a multiple of 4.'); */
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
        for (nz = 0; nz < 58; nz++)
        {
            d_data[nz] = p[nz];
        }

        TranslateError(&d_data[0]);
    }

    /*  Check if delays are within bounds */
    /* '<S1037>:1:49' checkDelay(FREQDelaySamples, maxFREQDelay, 'Medusa HFEQ delay'); */
    /*  Check if delays are within bounds */
    /* '<S1037>:1:67' if(sum(delayValue < 0)) */
    for (nz = 0; nz < 22; nz++)
    {
        b_x[nz] = (FREQDelaySamples[nz] < 0);
    }

    nz = b_x[0];
    for (f_k = 0; f_k < 21; f_k++)
    {
        nz += b_x[f_k + 1];
    }

    if (nz != 0)
    {
        /* '<S1037>:1:68' TranslateError('Value of %s must be greater than or equal to zero.', name); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (nz = 0; nz < 51; nz++)
        {
            e_data[nz] = q[nz];
        }

        for (nz = 0; nz < 18; nz++)
        {
            f_data[nz] = r[nz];
        }

        TranslateError(&e_data[0], &f_data[0]);
    }

    /* '<S1037>:1:71' if(sum(delayValue > upper)) */
    for (nz = 0; nz < 22; nz++)
    {
        b_x[nz] = (FREQDelaySamples[nz] > 45);
    }

    nz = b_x[0];
    for (f_k = 0; f_k < 21; f_k++)
    {
        nz += b_x[f_k + 1];
    }

    if (nz != 0)
    {
        /* '<S1037>:1:72' TranslateError('Value of %s must be less than or equal to %d.', name, upper); */
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
        for (nz = 0; nz < 46; nz++)
        {
            g_data[nz] = s[nz];
        }

        for (nz = 0; nz < 18; nz++)
        {
            f_data[nz] = r[nz];
        }

        TranslateError(&g_data[0], &f_data[0], 45);
    }

    /* '<S1037>:1:50' checkDelay(FRHRDrvDelaySamples, maxFRSpkrDelay, 'h01/h0r delay'); */
    /*  Check if delays are within bounds */
    /* '<S1037>:1:67' if(sum(delayValue < 0)) */
    if (b_FRHRDrvDelaySamples < 0)
    {
        /* '<S1037>:1:68' TranslateError('Value of %s must be greater than or equal to zero.', name); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (nz = 0; nz < 51; nz++)
        {
            e_data[nz] = q[nz];
        }

        for (nz = 0; nz < 14; nz++)
        {
            h_data[nz] = t[nz];
        }

        TranslateError(&e_data[0], &h_data[0]);
    }

    /* '<S1037>:1:71' if(sum(delayValue > upper)) */
    if (b_FRHRDrvDelaySamples > 1324)
    {
        /* '<S1037>:1:72' TranslateError('Value of %s must be less than or equal to %d.', name, upper); */
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
        for (nz = 0; nz < 46; nz++)
        {
            g_data[nz] = s[nz];
        }

        for (nz = 0; nz < 14; nz++)
        {
            h_data[nz] = t[nz];
        }

        TranslateError(&g_data[0], &h_data[0], 1324);
    }

    /* '<S1037>:1:51' checkDelay(FRHRPaxDelaySamples, maxFRSpkrDelay, 'h1l/h1r delay'); */
    /*  Check if delays are within bounds */
    /* '<S1037>:1:67' if(sum(delayValue < 0)) */
    if (b_FRHRPaxDelaySamples < 0)
    {
        /* '<S1037>:1:68' TranslateError('Value of %s must be greater than or equal to zero.', name); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (nz = 0; nz < 51; nz++)
        {
            e_data[nz] = q[nz];
        }

        for (nz = 0; nz < 14; nz++)
        {
            h_data[nz] = u[nz];
        }

        TranslateError(&e_data[0], &h_data[0]);
    }

    /* '<S1037>:1:71' if(sum(delayValue > upper)) */
    if (b_FRHRPaxDelaySamples > 1324)
    {
        /* '<S1037>:1:72' TranslateError('Value of %s must be less than or equal to %d.', name, upper); */
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
        for (nz = 0; nz < 46; nz++)
        {
            g_data[nz] = s[nz];
        }

        for (nz = 0; nz < 14; nz++)
        {
            h_data[nz] = u[nz];
        }

        TranslateError(&g_data[0], &h_data[0], 1324);
    }

    /* '<S1037>:1:52' checkDelay(FRNonHRDelaySamples, maxFRSpkrDelay, 'Medusa non-headrest speaker delay'); */
    /*  Check if delays are within bounds */
    /* '<S1037>:1:67' if(sum(delayValue < 0)) */
    for (nz = 0; nz < 18; nz++)
    {
        x[nz] = (b_FRNonHRDelaySamples[nz] < 0);
    }

    nz = x[0];
    for (f_k = 0; f_k < 17; f_k++)
    {
        nz += x[f_k + 1];
    }

    if (nz != 0)
    {
        /* '<S1037>:1:68' TranslateError('Value of %s must be greater than or equal to zero.', name); */
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
        /* 'TranslateError:29' coder.ceval('TranslateError',fixedArgs{:}); */
        for (nz = 0; nz < 51; nz++)
        {
            e_data[nz] = q[nz];
        }

        for (nz = 0; nz < 34; nz++)
        {
            i_data[nz] = v[nz];
        }

        TranslateError(&e_data[0], &i_data[0]);
    }

    /* '<S1037>:1:71' if(sum(delayValue > upper)) */
    for (nz = 0; nz < 18; nz++)
    {
        x[nz] = (b_FRNonHRDelaySamples[nz] > 1324);
    }

    nz = x[0];
    for (f_k = 0; f_k < 17; f_k++)
    {
        nz += x[f_k + 1];
    }

    if (nz != 0)
    {
        /* '<S1037>:1:72' TranslateError('Value of %s must be less than or equal to %d.', name, upper); */
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
        for (nz = 0; nz < 46; nz++)
        {
            g_data[nz] = s[nz];
        }

        for (nz = 0; nz < 34; nz++)
        {
            i_data[nz] = v[nz];
        }

        TranslateError(&g_data[0], &i_data[0], 1324);
    }

    /*  Assign values to TOPs */
    /* '<S1037>:1:55' HRcomps = int32(ones(1,numHeadrestComps)); */
    /* '<S1037>:1:56' HRDrvDelay = DRHRDrvDelaySamples * HRcomps; */
    /* '<S1037>:1:57' HRPaxDelay = DRHRPaxDelaySamples * HRcomps; */
    /* '<S1037>:1:58' DRDelay = [DRNonHRDelaySamples, HRDrvDelay, HRPaxDelay]; */
    memcpy(&Model_TranslationEngine64_Medusa5H1Part6_B.DRDelay[0],
           &DRNonHRDelaySamples[0], 18U * sizeof(int32_T));
    for (nz = 0; nz < 6; nz++)
    {
        Model_TranslationEngine64_Medusa5H1Part6_B.DRDelay[nz + 18] =
            b_FRNonHRDelaySamples_0;
        Model_TranslationEngine64_Medusa5H1Part6_B.DRDelay[nz + 24] = b_a;
    }

    /* '<S1037>:1:59' FRSpkrDelay = FREQDelaySamples + [FRNonHRDelaySamples, FRHRDrvDelaySamples, ... */
    /* '<S1037>:1:60'     FRHRPaxDelaySamples, FRHRDrvDelaySamples, FRHRPaxDelaySamples]; */
    for (nz = 0; nz <= 12; nz += 4)
    {
        __m128i tmp;
        __m128i tmp_0;

        /* MATLAB Function: '<S1035>/translation' */
        /* MATLAB Function: '<S1035>/translation' */
        tmp = _mm_loadu_si128((const __m128i *)&FREQDelaySamples[nz]);
        tmp_0 = _mm_loadu_si128((const __m128i *)&b_FRNonHRDelaySamples[nz]);
        _mm_storeu_si128((__m128i *)
                         &Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[
                         nz], _mm_add_epi32(tmp, tmp_0));
    }

    /* MATLAB Function: '<S1035>/translation' */
    /* MATLAB Function: '<S1035>/translation' */
    for (nz = 16; nz < 18; nz++)
    {
        Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[nz] =
            FREQDelaySamples[nz] + b_FRNonHRDelaySamples[nz];
    }

    Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[18] =
        FREQDelaySamples[18] + b_FRHRDrvDelaySamples;
    Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[19] =
        FREQDelaySamples[19] + b_FRHRPaxDelaySamples;
    Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[20] =
        FREQDelaySamples[20] + b_FRHRDrvDelaySamples;
    Model_TranslationEngine64_Medusa5H1Part6_B.FRSpkrDelay[21] =
        FREQDelaySamples[21] + b_FRHRPaxDelaySamples;
}

/* Output and update for function-call system: '<S1053>/tfunc' */
void FuncTranslation_Model_420_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1051>/Subsystem' */
    /* SignalConversion generated from: '<S1052>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1054>:1' */
    /* '<S1054>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_B.Value_dv[0],
           &Model_TranslationEngine64_B.NearWiggleCoeffs.Value[0], sizeof(real_T)
           << 11U);

    /* End of Outputs for SubSystem: '<S1051>/Subsystem' */
}

/* Output and update for function-call system: '<S1057>/tfunc' */
void FuncTranslation_Model_421_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1055>/Subsystem' */
    /* SignalConversion generated from: '<S1056>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1058>:1' */
    /* '<S1058>:1:3' f(); */
    Model_TranslationEngine64_B.Value_phe =
        Model_TranslationEngine64_B.NearDelay.Value;

    /* End of Outputs for SubSystem: '<S1055>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1178>/tone filter tune translate3'
 *    '<S1178>/tone filter tune translate4'
 *    '<S1179>/tone filter tune translate3'
 *    '<S1179>/tone filter tune translate4'
 *    '<S1181>/tone filter tune translate3'
 *    '<S1181>/tone filter tune translate4'
 */
void Model_TranslationEngine64_tonefiltertunetranslate3(const bus_double_1_1
    *rtu_maxIn, B_tonefiltertunetranslate3_Model_TranslationEngine64_T *localB)
{
    /*  % inputs % parameters */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/Bass/tone filter tune translate3': '<S1191>:1' */
    /*  Just make sure the maximum is a positive dB value */
    /* '<S1191>:1:6' maxOut = single(abs(maxIn.Value)); */
    localB->maxOut = (real32_T)fabs(rtu_maxIn->Value);
}

/* Output and update for function-call system: '<S1182>/tfunc' */
void FuncTranslation_Model_247_174(void)
{
    /* MATLAB Function: '<S1178>/tone filter tune translate3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1193>:1' */
    /* '<S1193>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3);
}

/*
 * Output and update for function-call system:
 *    '<S1178>/tone filter tune translate1'
 *    '<S1178>/tone filter tune translate2'
 */
void Model_TranslationEngine64_tonefiltertunetranslate1(const bus_double_1_1
    *rtu_FilterFrequencyHz, real32_T rtu_Fs,
    B_tonefiltertunetranslate1_Model_TranslationEngine64_T *localB)
{
    real32_T B0;
    real32_T omega;

    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/Bass/tone filter tune translate1': '<S1189>:1' */
    /* '<S1189>:1:6' omega = 2 * pi * FilterFrequencyHz.Value / Fs; */
    omega = (real32_T)(6.2831853071795862 * rtu_FilterFrequencyHz->Value) /
        rtu_Fs;

    /* '<S1189>:1:8' A = (1 - sin(omega)) / cos(omega); */
    omega = (1.0F - sinf(omega)) / cosf(omega);

    /* '<S1189>:1:10' if (MaskFilterType == ToneMask.TypeLowpass) */
    /*  lowpass coeffs (e.g. bass) */
    /* '<S1189>:1:12' B0 = (1 - A) / 2; */
    B0 = (1.0F - omega) / 2.0F;

    /* '<S1189>:1:13' B1 = B0; */
    /* '<S1189>:1:20' FilterCoeffs = single([B0 B1 A]); */
    localB->FilterCoeffs[0] = B0;
    localB->FilterCoeffs[1] = B0;
    localB->FilterCoeffs[2] = omega;
}

/* Output and update for function-call system: '<S1183>/tfunc' */
void FuncTranslation_Model_247_149(void)
{
    /* MATLAB Function: '<S1178>/tone filter tune translate1' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1194>:1' */
    /* '<S1194>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz,
         Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst_j,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1);
}

/* Output and update for function-call system: '<S1184>/tfunc' */
void FuncTranslation_Model_247_153(void)
{
    /* MATLAB Function: '<S1178>/tone filter tune translate2' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1195>:1' */
    /* '<S1195>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1
        (&Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz,
         Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst_j,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_o);
}

/* Output and update for function-call system: '<S1185>/tfunc' */
void FuncTranslation_Model_247_176(void)
{
    /* MATLAB Function: '<S1178>/tone filter tune translate4' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1196>:1' */
    /* '<S1196>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_k);
}

/* Output and update for function-call system: '<S1199>/tfunc' */
void FuncTranslation_Model_247_210_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1197>/Subsystem' */
    /* SignalConversion generated from: '<S1198>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1200>:1' */
    /* '<S1200>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_mo =
        Model_TranslationEngine64_PreAmpPart1_B.Offset.Value;

    /* End of Outputs for SubSystem: '<S1197>/Subsystem' */
}

/* Output and update for function-call system: '<S1203>/tfunc' */
void FuncTranslation_Model_247_229_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1201>/Subsystem' */
    /* SignalConversion generated from: '<S1202>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1204>:1' */
    /* '<S1204>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_mu =
        Model_TranslationEngine64_PreAmpPart1_B.ramptime.Value;

    /* End of Outputs for SubSystem: '<S1201>/Subsystem' */
}

/* Output and update for function-call system: '<S1207>/tfunc' */
void FuncTranslation_Model_247_209_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1205>/Subsystem' */
    /* SignalConversion generated from: '<S1206>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1208>:1' */
    /* '<S1208>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_a =
        Model_TranslationEngine64_PreAmpPart1_B.Scale.Value;

    /* End of Outputs for SubSystem: '<S1205>/Subsystem' */
}

/* Output and update for function-call system: '<S1209>/tfunc' */
void FuncTranslation_Model_249_46(void)
{
    /* MATLAB Function: '<S1179>/tone filter tune translate3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1220>:1' */
    /* '<S1220>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_h,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3_lh);
}

/*
 * Output and update for function-call system:
 *    '<S1179>/tone filter tune translate1'
 *    '<S1179>/tone filter tune translate2'
 */
void Model_TranslationEngine64_tonefiltertunetranslate1_n(const bus_double_1_1
    *rtu_FilterFrequencyHz, real32_T rtu_Fs, const bus_double_1_1 *rtu_Qval,
    B_tonefiltertunetranslate1_Model_TranslationEngine64_m_T *localB)
{
    real32_T B0;
    real32_T B0_tmp;
    real32_T B0_tmp_0;
    real32_T FilterCoeffs_tmp;
    real32_T omega;

    /*  Compute the discrete frequency */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/Midrange/tone filter tune translate1': '<S1216>:1' */
    /* '<S1216>:1:4' omega = 2 * pi * FilterFrequencyHz.Value / Fs; */
    omega = (real32_T)(6.2831853071795862 * rtu_FilterFrequencyHz->Value) /
        rtu_Fs;

    /* '<S1216>:1:5' Q = Qval.Value; */
    /*  Equations for computing filter coefficients of a bandpass filter */
    /*  Compute the denominator coeffs */
    /* '<S1216>:1:9' A1 = (-4 * Q * cos(omega)) / (2 * Q + sin(omega)); */
    /* '<S1216>:1:10' A2 = (2 * Q - sin(omega)) / (2 * Q + sin(omega)); */
    /*  Compute the numerator coeffs */
    /* '<S1216>:1:12' B0 = sin(omega)/ (2 * Q + sin(omega)); */
    B0_tmp = sinf(omega);
    B0_tmp_0 = (real32_T)(2.0 * rtu_Qval->Value);
    B0 = B0_tmp / (B0_tmp_0 + B0_tmp);

    /* '<S1216>:1:13' B1 = 0; */
    /* '<S1216>:1:14' B2 = -B0; */
    /*  Concatenate to obtain the final coeffs */
    /* '<S1216>:1:16' FilterCoeffs = single([A1 A2 B0 B1 B2]); */
    FilterCoeffs_tmp = (real32_T)(2.0 * rtu_Qval->Value) + sinf(omega);
    localB->FilterCoeffs[0] = (real32_T)(-4.0 * rtu_Qval->Value) * cosf(omega) /
        FilterCoeffs_tmp;
    localB->FilterCoeffs[1] = (B0_tmp_0 - B0_tmp) / FilterCoeffs_tmp;
    localB->FilterCoeffs[2] = B0;
    localB->FilterCoeffs[3] = 0.0F;
    localB->FilterCoeffs[4] = -B0;
}

/* Output and update for function-call system: '<S1210>/tfunc' */
void FuncTranslation_Model_249_47(void)
{
    /* MATLAB Function: '<S1179>/tone filter tune translate1' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1221>:1' */
    /* '<S1221>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1_n
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_o,
         Model_TranslationEngine64_PreAmpPart1_ConstB.Fs,
         &Model_TranslationEngine64_PreAmpPart1_B.BoostQValue,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1_n);
}

/* Output and update for function-call system: '<S1211>/tfunc' */
void FuncTranslation_Model_249_48(void)
{
    /* MATLAB Function: '<S1179>/tone filter tune translate2' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1222>:1' */
    /* '<S1222>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1_n
        (&Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_p,
         Model_TranslationEngine64_PreAmpPart1_ConstB.Fs,
         &Model_TranslationEngine64_PreAmpPart1_B.CutQValue,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_la);
}

/* Output and update for function-call system: '<S1212>/tfunc' */
void FuncTranslation_Model_249_49(void)
{
    /* MATLAB Function: '<S1179>/tone filter tune translate4' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1223>:1' */
    /* '<S1223>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_j,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_bf);
}

/* Output and update for function-call system: '<S1226>/tfunc' */
void FuncTranslation_Model_249_50_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1224>/Subsystem' */
    /* SignalConversion generated from: '<S1225>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1227>:1' */
    /* '<S1227>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_j =
        Model_TranslationEngine64_PreAmpPart1_B.Offset_p.Value;

    /* End of Outputs for SubSystem: '<S1224>/Subsystem' */
}

/* Output and update for function-call system: '<S1230>/tfunc' */
void FuncTranslation_Model_249_51_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1228>/Subsystem' */
    /* SignalConversion generated from: '<S1229>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1231>:1' */
    /* '<S1231>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_f =
        Model_TranslationEngine64_PreAmpPart1_B.RampTime.Value;

    /* End of Outputs for SubSystem: '<S1228>/Subsystem' */
}

/* Output and update for function-call system: '<S1234>/tfunc' */
void FuncTranslation_Model_249_52_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1232>/Subsystem' */
    /* SignalConversion generated from: '<S1233>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1235>:1' */
    /* '<S1235>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_b =
        Model_TranslationEngine64_PreAmpPart1_B.Scale_k.Value;

    /* End of Outputs for SubSystem: '<S1232>/Subsystem' */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
    real32_T y;
    if (rtIsNaNF(u0) || rtIsNaNF(u1))
    {
        y = (rtNaNF);
    }
    else
    {
        real32_T tmp;
        real32_T tmp_0;
        tmp = fabsf(u0);
        tmp_0 = fabsf(u1);
        if (rtIsInfF(u1))
        {
            if (tmp == 1.0F)
            {
                y = 1.0F;
            }
            else if (tmp > 1.0F)
            {
                if (u1 > 0.0F)
                {
                    y = (rtInfF);
                }
                else
                {
                    y = 0.0F;
                }
            }
            else if (u1 > 0.0F)
            {
                y = 0.0F;
            }
            else
            {
                y = (rtInfF);
            }
        }
        else if (tmp_0 == 0.0F)
        {
            y = 1.0F;
        }
        else if (tmp_0 == 1.0F)
        {
            if (u1 > 0.0F)
            {
                y = u0;
            }
            else
            {
                y = 1.0F / u0;
            }
        }
        else if (u1 == 2.0F)
        {
            y = u0 * u0;
        }
        else if ((u1 == 0.5F) && (u0 >= 0.0F))
        {
            y = sqrtf(u0);
        }
        else if ((u0 < 0.0F) && (u1 > floorf(u1)))
        {
            y = (rtNaNF);
        }
        else
        {
            y = powf(u0, u1);
        }
    }

    return y;
}

/* Output and update for function-call system: '<S1241>/tfunc' */
void FuncTranslation_Model_642(void)
{
    /* Outputs for Function Call SubSystem: '<S1239>/Function-Call Subsystem' */
    /* MATLAB Function: '<S1240>/MATLAB Function' incorporates:
     *  S-Function (TuneVarMEX): '<S1239>/Tune Variable'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1243>:1' */
    /* '<S1243>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/NEARPreAmp/FixedAttenuator/Attenuation /Function-Call Subsystem/MATLAB Function': '<S1242>:1' */
    /* '<S1242>:1:2' lingain = 10^(dbgain.Value/20); */
    Model_TranslationEngine64_PreAmpPart1_B.lingain = rt_powf_snf(10.0F,
        Model_TranslationEngine64_PreAmpPart1_B.A.Value / 20.0F);

    /* End of Outputs for SubSystem: '<S1239>/Function-Call Subsystem' */
}

/* Output and update for function-call system: '<S1250>/tfunc' */
void FuncTranslation_Model_670_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1248>/Subsystem' */
    /* SignalConversion generated from: '<S1249>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1251>:1' */
    /* '<S1251>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_h =
        Model_TranslationEngine64_PreAmpPart1_B.G.Value;

    /* End of Outputs for SubSystem: '<S1248>/Subsystem' */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
    real_T y;
    if (rtIsNaN(u0) || rtIsNaN(u1))
    {
        y = (rtNaN);
    }
    else
    {
        real_T tmp;
        real_T tmp_0;
        tmp = fabs(u0);
        tmp_0 = fabs(u1);
        if (rtIsInf(u1))
        {
            if (tmp == 1.0)
            {
                y = 1.0;
            }
            else if (tmp > 1.0)
            {
                if (u1 > 0.0)
                {
                    y = (rtInf);
                }
                else
                {
                    y = 0.0;
                }
            }
            else if (u1 > 0.0)
            {
                y = 0.0;
            }
            else
            {
                y = (rtInf);
            }
        }
        else if (tmp_0 == 0.0)
        {
            y = 1.0;
        }
        else if (tmp_0 == 1.0)
        {
            if (u1 > 0.0)
            {
                y = u0;
            }
            else
            {
                y = 1.0 / u0;
            }
        }
        else if (u1 == 2.0)
        {
            y = u0 * u0;
        }
        else if ((u1 == 0.5) && (u0 >= 0.0))
        {
            y = sqrt(u0);
        }
        else if ((u0 < 0.0) && (u1 > floor(u1)))
        {
            y = (rtNaN);
        }
        else
        {
            y = pow(u0, u1);
        }
    }

    return y;
}

/*
 * Output and update for function-call system:
 *    '<S1252>/Trivial Translation'
 *    '<S1254>/Trivial Translation'
 *    '<S1255>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_h(const bus_double_1_1
    *rtu_Tune1, B_TrivialTranslation_Model_TranslationEngine64_ap_T *localB)
{
    /*  ----- To access TuneVar maximum size, current size, and current value: */
    /*    Note: TuneVar signals arrive with exposed variable size information. */
    /*          The expressions below illustrate for the "Tune1" input argument. */
    /*  */
    /*    size(Tune1.Value) : the maximum possible size of the Tune1 variable */
    /*  */
    /*    Tune.Size   : the current size of *valid* data in Tune1.Value */
    /*  */
    /*    Tune1.Size(1) : Number of rows present in Tune1 - this does not vary. */
    /*  */
    /*    Tune1.Size(2) : Number of columns currently valid in Tune1 - this is */
    /*        the variable part of size that can change (if allowed by TuneVar). */
    /*  */
    /*    Tune1.Value : the current value of the tune variable... but end-padded  */
    /*        to the maximum available size with undefined/invalid data. */
    /*  */
    /*    numel(Tune1.Value) : another way of looking at the maximum number of */
    /*        elements that could arrive in Tune1.Value */
    /*  */
    /*  ----- To register an error, use the following method (works like printf): */
    /*    TranslateError( <format string>, <arguments ... ) */
    /*    ... this error will cause the build process to abort. */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/NEARPreAmp/MusicLimiter/annPredTuneTOP/Trivial Translation': '<S1257>:1' */
    /*  A trivial pass-through translation looks like this: */
    /* TOP1 = Tune1.Value; */
    /* '<S1257>:1:29' TOP1 = 10 ^ ((Tune1.Value) / 20); */
    localB->TOP1 = rt_powd_snf(10.0, rtu_Tune1->Value / 20.0);
}

/* Output and update for function-call system: '<S1256>/tfunc' */
void FuncTranslation_Model_712(void)
{
    /* MATLAB Function: '<S1252>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1258>:1' */
    /* '<S1258>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_h
        (&Model_TranslationEngine64_PreAmpPart1_B.AnnPred,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation);
}

/* Output and update for function-call system: '<S1262>/tfunc' */
void FuncTranslation_Model_729(void)
{
    int32_T k;

    /* MATLAB Function: '<S1253>/MATLAB Function3' */
    /* MATLAB Function: '<S1253>/MATLAB Function3' incorporates:
     *  S-Function (TuneVarMEX): '<S1253>/attackTune'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1265>:1' */
    /* '<S1265>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/NEARPreAmp/MusicLimiter/limiter/MATLAB Function3': '<S1260>:1' */
    /* function [attack, k1]= fcn(attackDB, threshold, Fs) */
    /* '<S1260>:1:3' attack = single(1 - undb20(-abs(attackDB.Value) / Fs)); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 32; k++)
    {
        Model_TranslationEngine64_PreAmpPart1_B.attack[k] = (real32_T)(1.0 - exp
            (-fabs(Model_TranslationEngine64_PreAmpPart1_B.Attack.Value[k]) /
             Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst *
             2.3025850929940459 / 20.0));
    }

    /* End of MATLAB Function: '<S1253>/MATLAB Function3' */
    /* k1 = attack ./ single(threshold.Value); */
}

/* Output and update for function-call system: '<S1263>/tfunc' */
void FuncTranslation_Model_730(void)
{
    int32_T k;

    /* MATLAB Function: '<S1253>/MATLAB Function2' */
    /* MATLAB Function: '<S1253>/MATLAB Function2' incorporates:
     *  S-Function (TuneVarMEX): '<S1253>/decay tune'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1266>:1' */
    /* '<S1266>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/NEARPreAmp/MusicLimiter/limiter/MATLAB Function2': '<S1259>:1' */
    /* '<S1259>:1:3' y = single(undb20(abs(u.Value) / Fs)); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 32; k++)
    {
        Model_TranslationEngine64_PreAmpPart1_B.y_e[k] = (real32_T)exp(fabs
            (Model_TranslationEngine64_PreAmpPart1_B.Decay.Value[k]) /
            Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1253>/MATLAB Function2' */
}

/* Output and update for function-call system: '<S1264>/tfunc' */
void FuncTranslation_Model_731(void)
{
    int32_T k;

    /* MATLAB Function: '<S1253>/MATLAB Function4' */
    /* MATLAB Function: '<S1253>/MATLAB Function4' incorporates:
     *  S-Function (TuneVarMEX): '<S1253>/maxAttack tune'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1267>:1' */
    /* '<S1267>:1:3' f(); */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/NEARPreAmp/MusicLimiter/limiter/MATLAB Function4': '<S1261>:1' */
    /* '<S1261>:1:3' y = single(undb20(-abs(u.Value))); */
    /* UNDB20  Decibels to linear quantity */
    /*    Converts x from DB to absolute magnitude assuming that x is in volts. */
    /*    y = 10^(x/20) */
    /*  */
    /*  See also: DB20, UNDB10 */
    /*    Copyright 2018-2019 Bose Corporation */
    /*  Created : 9/7/1994 Bill Berardi */
    /* $Id: undb20.m 11244 2011-10-31 18:51:23Z rg20270 $ */
    /* 'undb20:12' y = exp(x * log(10)/20); */
    for (k = 0; k < 32; k++)
    {
        Model_TranslationEngine64_PreAmpPart1_B.y[k] = (real32_T)exp(-fabs
            (Model_TranslationEngine64_PreAmpPart1_B.MaxAttack.Value[k]) *
            2.3025850929940459 / 20.0);
    }

    /* End of MATLAB Function: '<S1253>/MATLAB Function4' */
}

/* Output and update for function-call system: '<S1268>/tfunc' */
void FuncTranslation_Model_741(void)
{
    /* MATLAB Function: '<S1254>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1270>:1' */
    /* '<S1270>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_h
        (&Model_TranslationEngine64_PreAmpPart1_B.Offset_c,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation_jf);
}

/* Output and update for function-call system: '<S1271>/tfunc' */
void FuncTranslation_Model_747(void)
{
    /* MATLAB Function: '<S1255>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1273>:1' */
    /* '<S1273>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_h
        (&Model_TranslationEngine64_PreAmpPart1_B.UpperThreshold,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_TrivialTranslation_e1);
}

/* Output and update for function-call system: '<S1274>/tfunc' */
void FuncTranslation_Model_251_174(void)
{
    /* MATLAB Function: '<S1181>/tone filter tune translate3' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1285>:1' */
    /* '<S1285>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostMaximum_dB_k,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate3_it);
}

/*
 * Output and update for function-call system:
 *    '<S1181>/tone filter tune translate1'
 *    '<S1181>/tone filter tune translate2'
 */
void Model_TranslationEngine64_tonefiltertunetranslate1_i(const bus_double_1_1
    *rtu_FilterFrequencyHz, real32_T rtu_Fs,
    B_tonefiltertunetranslate1_Model_TranslationEngine64_h_T *localB)
{
    real32_T B0;
    real32_T omega;

    /*  % inputs */
    /*  parameters */
    /* MATLAB Function 'ModelPreAmp/PreAmpPart1/Treble/tone filter tune translate1': '<S1281>:1' */
    /* '<S1281>:1:6' omega = 2 * pi * FilterFrequencyHz.Value / Fs; */
    omega = (real32_T)(6.2831853071795862 * rtu_FilterFrequencyHz->Value) /
        rtu_Fs;

    /* '<S1281>:1:8' A = (1 - sin(omega)) / cos(omega); */
    omega = (1.0F - sinf(omega)) / cosf(omega);

    /* '<S1281>:1:10' if (MaskFilterType == ToneMask.TypeLowpass) */
    /* '<S1281>:1:14' else */
    /*  highpass coeffs (e.g. treble) */
    /* '<S1281>:1:16' B0 = (1 + A) / 2; */
    B0 = (omega + 1.0F) / 2.0F;

    /* '<S1281>:1:17' B1 = 0 - B0; */
    /* '<S1281>:1:20' FilterCoeffs = single([B0 B1 A]); */
    localB->FilterCoeffs[0] = B0;
    localB->FilterCoeffs[1] = 0.0F - B0;
    localB->FilterCoeffs[2] = omega;
}

/* Output and update for function-call system: '<S1275>/tfunc' */
void FuncTranslation_Model_251_149(void)
{
    /* MATLAB Function: '<S1181>/tone filter tune translate1' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1286>:1' */
    /* '<S1286>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1_i
        (&Model_TranslationEngine64_PreAmpPart1_B.BoostFrequencyHz_p,
         Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst_b,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate1_i);
}

/* Output and update for function-call system: '<S1276>/tfunc' */
void FuncTranslation_Model_251_153(void)
{
    /* MATLAB Function: '<S1181>/tone filter tune translate2' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1287>:1' */
    /* '<S1287>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate1_i
        (&Model_TranslationEngine64_PreAmpPart1_B.CutFrequencyHz_pm,
         Model_TranslationEngine64_PreAmpPart1_ConstB.CapturedTuneConst_b,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate2_ej);
}

/* Output and update for function-call system: '<S1277>/tfunc' */
void FuncTranslation_Model_251_176(void)
{
    /* MATLAB Function: '<S1181>/tone filter tune translate4' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1288>:1' */
    /* '<S1288>:1:3' f(); */
    Model_TranslationEngine64_tonefiltertunetranslate3
        (&Model_TranslationEngine64_PreAmpPart1_B.CutMaximum_dB_e,
         &Model_TranslationEngine64_PreAmpPart1_B.sf_tonefiltertunetranslate4_kk4);
}

/* Output and update for function-call system: '<S1291>/tfunc' */
void FuncTranslation_Model_251_210_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1289>/Subsystem' */
    /* SignalConversion generated from: '<S1290>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1292>:1' */
    /* '<S1292>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_n =
        Model_TranslationEngine64_PreAmpPart1_B.Offset_cl.Value;

    /* End of Outputs for SubSystem: '<S1289>/Subsystem' */
}

/* Output and update for function-call system: '<S1295>/tfunc' */
void FuncTranslation_Model_251_229_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1293>/Subsystem' */
    /* SignalConversion generated from: '<S1294>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1296>:1' */
    /* '<S1296>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value_m =
        Model_TranslationEngine64_PreAmpPart1_B.ramptime_h.Value;

    /* End of Outputs for SubSystem: '<S1293>/Subsystem' */
}

/* Output and update for function-call system: '<S1299>/tfunc' */
void FuncTranslation_Model_251_209_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1297>/Subsystem' */
    /* SignalConversion generated from: '<S1298>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1300>:1' */
    /* '<S1300>:1:3' f(); */
    Model_TranslationEngine64_PreAmpPart1_B.Value =
        Model_TranslationEngine64_PreAmpPart1_B.Scale_a.Value;

    /* End of Outputs for SubSystem: '<S1297>/Subsystem' */
}

/* Function for MATLAB Function: '<S1313>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_dn(int32_T b,
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

/* Output and update for function-call system: '<S1314>/tfunc' */
void FuncTranslation_Model_874_36(void)
{
    real_T ChannelCoeffs[400];
    real_T OverallGainPerCh[7];
    real_T c_y;
    real_T offset;
    int32_T f_data[400];
    int32_T tmp_data[400];
    int32_T b_data[100];
    int32_T ts_data[100];
    int32_T NumStages[7];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T d_k;
    int32_T k;
    int32_T yk;
    real32_T PoolCoeffs[400];
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1313>/Translation' */
    /* MATLAB Function: '<S1313>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1313>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1313>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1316>:1' */
    /* '<S1316>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'NEAR/Near1p1/DrProc/FsEQDr/Pooliir/PoolIirTunableWithReset/Translation': '<S1315>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1315>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1315>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1315>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (SOSIndex = 0; SOSIndex < 7; SOSIndex++)
    {
        c_y = rt_roundd_snf(Model_TranslationEngine64_B.numStages.Value[SOSIndex]);
        if (c_y < 2.147483648E+9)
        {
            if (c_y >= -2.147483648E+9)
            {
                NumStages[SOSIndex] = (int32_T)c_y;
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

        Model_TranslationEngine64_B.PoolNumStages_j4[SOSIndex] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 400U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 400U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    offset = NumStages[0];
    for (k = 0; k < 6; k++)
    {
        offset += (real_T)NumStages[k + 1];
    }

    if (offset > 100.0)
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
    for (k = 0; k < 7; k++)
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
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_dn
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = tmp_data[d_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    Model_TranslationEngine64_B.ChannelSOS_data[d_k +
                        ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_B.sosCoefficients.Value[(100 *
                        b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset = Model_TranslationEngine64_B.ChannelSOS_data[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *= Model_TranslationEngine64_B.ChannelSOS_data[yk - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y = Model_TranslationEngine64_B.ChannelSOS_data[tmp_size[1] *
                    3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    c_y *= Model_TranslationEngine64_B.ChannelSOS_data
                        [(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = offset / c_y;

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
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[b_vlen]);
                _mm_storeu_si128((__m128i *)&b_data[b_vlen], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                b_data[b_vlen] = ts_data[b_vlen] + 1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[b_data[b_vlen] - 1] =
                    -Model_TranslationEngine64_B.ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
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
                ChannelCoeffs[b_data[b_vlen] - 1] =
                    Model_TranslationEngine64_B.ChannelSOS_data[b_vlen +
                    ChannelSOS_size_idx_0] /
                    Model_TranslationEngine64_B.ChannelSOS_data[b_vlen];
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
                    -Model_TranslationEngine64_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 5 + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
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
                ChannelCoeffs[ts_data[b_vlen] - 1] =
                    Model_TranslationEngine64_B.ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data[b_vlen];
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
                offset = Model_TranslationEngine64_B.PoolNumStages_j4[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_B.PoolNumStages_j4[d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_j4[k] = NumStages_0;

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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_dn(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                c_y = offset + (real_T)tmp_data[b_vlen];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        f_data[b_vlen] = (int32_T)c_y;
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_B.PoolCoeffs_b[0], &PoolCoeffs[0], 400U *
           sizeof(real32_T));
    for (SOSIndex = 0; SOSIndex < 7; SOSIndex++)
    {
        Model_TranslationEngine64_B.PoolCoeffs_b[SOSIndex + 400] = (real32_T)
            OverallGainPerCh[SOSIndex];
    }

    /* End of MATLAB Function: '<S1313>/Translation' */
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

/*
 * Output and update for function-call system:
 *    '<S1312>/Translation'
 *    '<S1349>/Translation'
 */
void Model_TranslationEngine64_Translation_p(const bus_single_1_1 *rtu_F1, const
    bus_single_1_1 *rtu_F2, const bus_single_1_1 *rtu_F3, const bus_single_1_1
    *rtu_F4, const bus_single_1_1 *rtu_F5, const bus_single_1_1 *rtu_F6, const
    bus_single_1_1 *rtu_F7, B_Translation_Model_TranslationEngine64_e_T *localB)
{
    /* MATLAB Function 'NEAR/Near1p1/DrProc/FsEQDr/Subsystem1/Translation': '<S1319>:1' */
    /* '<S1319>:1:9' eqdelays = single([ F1.Value,... */
    /* '<S1319>:1:10'                         F2.Value,... */
    /* '<S1319>:1:11'                         F3.Value,... */
    /* '<S1319>:1:12'                         F4.Value,... */
    /* '<S1319>:1:13'                         F5.Value,... */
    /* '<S1319>:1:14'                         F6.Value,... */
    /* '<S1319>:1:15'                         F7.Value]); */
    localB->eqdelays[0] = rtu_F1->Value;
    localB->eqdelays[1] = rtu_F2->Value;
    localB->eqdelays[2] = rtu_F3->Value;
    localB->eqdelays[3] = rtu_F4->Value;
    localB->eqdelays[4] = rtu_F5->Value;
    localB->eqdelays[5] = rtu_F6->Value;
    localB->eqdelays[6] = rtu_F7->Value;
}

/* Output and update for function-call system: '<S1318>/tfunc' */
void FuncTranslation_Model_863(void)
{
    /* MATLAB Function: '<S1312>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1320>:1' */
    /* '<S1320>:1:3' f(); */
    Model_TranslationEngine64_Translation_p(&Model_TranslationEngine64_B.f1_del,
        &Model_TranslationEngine64_B.f2_del, &Model_TranslationEngine64_B.f3_del,
        &Model_TranslationEngine64_B.f4_del, &Model_TranslationEngine64_B.f5_del,
        &Model_TranslationEngine64_B.f6_del, &Model_TranslationEngine64_B.f7_del,
        &Model_TranslationEngine64_B.sf_Translation_p);
}

/* Function for MATLAB Function: '<S1323>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_iu(int32_T b,
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

/*
 * Output and update for function-call system:
 *    '<S1323>/Translation'
 *    '<S1360>/Translation'
 */
void Model_TranslationEngine64_Translation_h(const bus_double_100___6
    *rtu_RawSOS, const bus_double_1_4 *rtu_NumStages,
    B_Translation_Model_TranslationEngine64_k_T *localB)
{
    real_T ChannelCoeffs[400];
    real_T OverallGainPerCh[4];
    real_T c_y;
    real_T offset;
    int32_T f_data[400];
    int32_T tmp_data[400];
    int32_T b_data[100];
    int32_T ts_data[100];
    int32_T NumStages[4];
    int32_T SOSIndex;
    int32_T b_k;
    int32_T b_vlen;
    int32_T i;
    real32_T PoolCoeffs[400];
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'NEAR/Near1p1/DrProc/HrEQDr/PoolIirTunable/PoolIirTunableWithReset/Translation': '<S1325>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1325>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1325>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1325>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    c_y = rt_roundd_snf(rtu_NumStages->Value[0]);
    if (c_y < 2.147483648E+9)
    {
        if (c_y >= -2.147483648E+9)
        {
            NumStages[0] = (int32_T)c_y;
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

    localB->PoolNumStages[0] = 0;
    c_y = rt_roundd_snf(rtu_NumStages->Value[1]);
    if (c_y < 2.147483648E+9)
    {
        if (c_y >= -2.147483648E+9)
        {
            NumStages[1] = (int32_T)c_y;
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

    localB->PoolNumStages[1] = 0;
    offset = rt_roundd_snf(rtu_NumStages->Value[2]);
    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            NumStages[2] = (int32_T)offset;
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

    localB->PoolNumStages[2] = 0;
    offset = rt_roundd_snf(rtu_NumStages->Value[3]);
    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            NumStages[3] = (int32_T)offset;
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

    localB->PoolNumStages[3] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 400U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 400U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (c_y < 2.147483648E+9)
    {
        if (c_y >= -2.147483648E+9)
        {
            b_k = (int32_T)c_y;
        }
        else
        {
            b_k = MIN_int32_T;
        }
    }
    else
    {
        b_k = MAX_int32_T;
    }

    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            b_vlen = (int32_T)offset;
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

    if ((((real_T)NumStages[0] + (real_T)b_k) + (real_T)NumStages[2]) + (real_T)
            b_vlen > 100.0)
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
        for (b_k = 0; b_k < 31; b_k++)
        {
            d_data[b_k] = e[b_k];
        }

        TranslateError(&d_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (i = 0; i < 4; i++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[i];
        OverallGainPerCh[i] = 1.0;

        /* 'PoolIirHexagonTranslationFcn:29' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* 'PoolIirHexagonTranslationFcn:30' assert(ChannelNumStages <= MaxNumStages); */
        /* 'PoolIirHexagonTranslationFcn:31' if (ChannelNumStages == 0) */
        if (NumStages_0 != 0)
        {
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;
            int32_T yk;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_iu
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_k = 0; b_k < 6; b_k++)
            {
                for (b_vlen = 0; b_vlen < yk; b_vlen++)
                {
                    q1 = tmp_data[b_vlen];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    localB->ChannelSOS_data[b_vlen + ChannelSOS_size_idx_0 * b_k]
                        = rtu_RawSOS->Value[(100 * b_k + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset = localB->ChannelSOS_data[0];
                for (b_k = 2; b_k <= ChannelSOS_size_idx_0; b_k++)
                {
                    offset *= localB->ChannelSOS_data[b_k - 1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y = localB->ChannelSOS_data[tmp_size[1] * 3];
                for (b_k = 2; b_k <= ChannelSOS_size_idx_0; b_k++)
                {
                    c_y *= localB->ChannelSOS_data[(ChannelSOS_size_idx_0 * 3 +
                        b_k) - 1];
                }
            }

            OverallGainPerCh[i] = offset / c_y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                b_k = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                b_k = MIN_int32_T;
            }
            else
            {
                b_k = NumStages_0 << 2;
            }

            if (b_k < 1)
            {
                b_vlen = 0;
            }
            else
            {
                b_vlen = (int32_T)((uint32_T)(b_k - 1) >> 2) + 1;
            }

            ts_size_idx_1 = b_vlen;
            if (b_vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (b_k = 2; b_k <= b_vlen; b_k++)
                {
                    yk += 4;
                    ts_data[b_k - 1] = yk;
                }
            }

            yk = b_vlen - 1;
            for (b_k = 0; b_k <= yk; b_k++)
            {
                b_vlen = ts_data[b_k];
                if (b_vlen < -2147483647)
                {
                    ts_data[b_k] = MIN_int32_T;
                }
                else
                {
                    ts_data[b_k] = b_vlen - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            b_vlen = (ts_size_idx_1 / 4) << 2;
            q1 = b_vlen - 4;
            for (b_k = 0; b_k <= q1; b_k += 4)
            {
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[b_k]);
                _mm_storeu_si128((__m128i *)&b_data[b_k], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (b_k = b_vlen; b_k < ts_size_idx_1; b_k++)
            {
                b_data[b_k] = ts_data[b_k] + 1;
            }

            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                ChannelCoeffs[b_data[b_k] - 1] = -localB->ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + b_k] /
                    localB->ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + b_k];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                b_vlen = ts_data[b_k];
                if (b_vlen > 2147483645)
                {
                    b_data[b_k] = MAX_int32_T;
                }
                else
                {
                    b_data[b_k] = b_vlen + 2;
                }
            }

            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                ChannelCoeffs[b_data[b_k] - 1] = localB->ChannelSOS_data[b_k +
                    ChannelSOS_size_idx_0] / localB->ChannelSOS_data[b_k];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                b_vlen = ts_data[b_k];
                if (b_vlen > 2147483644)
                {
                    b_data[b_k] = MAX_int32_T;
                }
                else
                {
                    b_data[b_k] = b_vlen + 3;
                }
            }

            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                ChannelCoeffs[b_data[b_k] - 1] = -localB->
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + b_k] /
                    localB->ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + b_k];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            for (b_k = 0; b_k <= yk; b_k++)
            {
                b_vlen = ts_data[b_k];
                if (b_vlen > 2147483643)
                {
                    ts_data[b_k] = MAX_int32_T;
                }
                else
                {
                    ts_data[b_k] = b_vlen + 4;
                }
            }

            for (b_k = 0; b_k < ts_size_idx_1; b_k++)
            {
                ChannelCoeffs[ts_data[b_k] - 1] = localB->ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + b_k] /
                    localB->ChannelSOS_data[b_k];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (i < 1)
            {
                offset = 0.0;
            }
            else
            {
                offset = localB->PoolNumStages[0];
                for (b_k = 2; b_k <= i; b_k++)
                {
                    offset += (real_T)localB->PoolNumStages[b_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            localB->PoolNumStages[i] = NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                b_k = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                b_k = MIN_int32_T;
            }
            else
            {
                b_k = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_iu(b_k,
                tmp_data, tmp_size);
            b_vlen = tmp_size[1];
            yk = tmp_size[1];
            for (b_k = 0; b_k < yk; b_k++)
            {
                c_y = offset + (real_T)tmp_data[b_k];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        f_data[b_k] = (int32_T)c_y;
                    }
                    else
                    {
                        f_data[b_k] = MIN_int32_T;
                    }
                }
                else
                {
                    f_data[b_k] = MAX_int32_T;
                }
            }

            for (b_k = 0; b_k < b_vlen; b_k++)
            {
                PoolCoeffs[f_data[b_k] - 1] = (real32_T)ChannelCoeffs[b_k];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&localB->PoolCoeffs[0], &PoolCoeffs[0], 400U * sizeof(real32_T));
    localB->PoolCoeffs[400] = (real32_T)OverallGainPerCh[0];
    localB->PoolCoeffs[401] = (real32_T)OverallGainPerCh[1];
    localB->PoolCoeffs[402] = (real32_T)OverallGainPerCh[2];
    localB->PoolCoeffs[403] = (real32_T)OverallGainPerCh[3];

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

/* Output and update for function-call system: '<S1324>/tfunc' */
void FuncTranslation_Model_915_36(void)
{
    /* MATLAB Function: '<S1323>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1326>:1' */
    /* '<S1326>:1:3' f(); */
    Model_TranslationEngine64_Translation_h
        (&Model_TranslationEngine64_B.sosCoefficients_i,
         &Model_TranslationEngine64_B.numStages_m,
         &Model_TranslationEngine64_B.sf_Translation_h);
}

/*
 * Output and update for function-call system:
 *    '<S1322>/Translation'
 *    '<S1359>/Translation'
 */
void Model_TranslationEngine64_Translation_e(const bus_single_1_1
    *rtu_driversrc1, const bus_single_1_1 *rtu_driversrc2, const bus_single_1_1 *
    rtu_passengersrc1, const bus_single_1_1 *rtu_passengersrc2,
    B_Translation_Model_TranslationEngine64_or_T *localB)
{
    /* MATLAB Function 'NEAR/Near1p1/DrProc/HrEQDr/Subsystem2/Translation': '<S1329>:1' */
    /* '<S1329>:1:2' switch NumHeadrestSpeakers */
    /* '<S1329>:1:14' case 2 */
    /* '<S1329>:1:15' switch AnnChannelCount */
    /* '<S1329>:1:18' case 2 */
    /* '<S1329>:1:19' eqdelays = single([driversrc1.Value, driversrc2.Value, passengersrc1.Value, passengersrc2.Value]); */
    localB->eqdelays[0] = rtu_driversrc1->Value;
    localB->eqdelays[1] = rtu_driversrc2->Value;
    localB->eqdelays[2] = rtu_passengersrc1->Value;
    localB->eqdelays[3] = rtu_passengersrc2->Value;
}

/* Output and update for function-call system: '<S1328>/tfunc' */
void FuncTranslation_Model_903(void)
{
    /* MATLAB Function: '<S1322>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1330>:1' */
    /* '<S1330>:1:3' f(); */
    Model_TranslationEngine64_Translation_e
        (&Model_TranslationEngine64_B.driver_src1,
         &Model_TranslationEngine64_B.driver_src2,
         &Model_TranslationEngine64_B.passenger_src1,
         &Model_TranslationEngine64_B.passenger_src2,
         &Model_TranslationEngine64_B.sf_Translation_e);
}

/*
 * Output and update for function-call system:
 *    '<S1331>/Trivial Translation'
 *    '<S1368>/Trivial Translation'
 */
void Model_TranslationEngine64_TrivialTranslation_pe(const bus_double_1_18
    *rtu_Map, real_T rtp_nInRouterMask,
    B_TrivialTranslation_Model_TranslationEngine64_jd_T *localB)
{
    real_T endOfMap;
    real_T loopCount;
    real_T mapDifference;
    real_T mapLength;
    int32_T i;

    /*  ----- To access TuneVar maximum size, current size, and current value: */
    /*    Note: TuneVar signals arrive with exposed variable size information. */
    /*          The expressions below illustrate for the "Map" input argument. */
    /*  */
    /*    size(Map.Value) : the maximum possible size of the Map variable */
    /*  */
    /*    Tune.Size   : the current size of *valid* data in Map.Value */
    /*  */
    /*    Map.Size(1) : Number of rows present in Map - this does not vary. */
    /*  */
    /*    Map.Size(2) : Number of columns currently valid in Map - this is */
    /*        the variable part of size that can change (if allowed by TuneVar). */
    /*  */
    /*    Map.Value : the current value of the tune variable... but end-padded  */
    /*        to the maximum available size with undefined/invalid data. */
    /*  */
    /*    numel(Map.Value) : another way of looking at the maximum number of */
    /*        elements that could arrive in Map.Value */
    /*  */
    /*  ----- To register an error, use the following method (works like printf): */
    /*    TranslateError( <format string>, <arguments ... ) */
    /*    ... this error will cause the build process to abort. */
    /* MATLAB Function 'NEAR/Near1p1/DrProc/RouterDr/InnerLink/Trivial Translation': '<S1333>:1' */
    /*  The below logic ensures that an output map gets filled in in the  */
    /*  "round robin" manner. This is to occur when the supplied map is shorter */
    /*  than the number of channel outputs. For instance, */
    /*  nChanIn = 4 */
    /*  nChanOut = 9 */
    /*  outputMapSupplied = [4 3 2 2] */
    /*   */
    /*  This logic would run and return OutMap = [4 3 2 2 1 2 3 4 1] */
    /*  */
    /*  If no outputMap was supplied (i.e. = [];) THEN */
    /*  This logic would run and return OutMap = [1 2 3 4 1 2 3 4 1]; */
    /*  First part finds the number of output map indices that were left blank */
    /* '<S1333>:1:42' nChanOut = numel(Map.Value); */
    /* '<S1333>:1:43' mapLength = Map.Size(2); */
    mapLength = rtu_Map->Size[1];

    /* '<S1333>:1:44' mapDifference = nChanOut - mapLength; */
    mapDifference = 18.0 - rtu_Map->Size[1];

    /* '<S1333>:1:45' OutMap = int32(Map.Value); */
    for (i = 0; i < 18; i++)
    {
        localB->OutMap[i] = (int32_T)rt_roundd_snf(rtu_Map->Value[i]);
    }

    /*  This loop appropriates the correct input channel number to the */
    /*  corresponding output channel, based on the mapDifference found above */
    /* '<S1333>:1:49' if (mapLength == 1) && Map.Value(1) == 0 */
    if ((rtu_Map->Size[1] == 1.0) && (rtu_Map->Value[0] == 0.0))
    {
        /* '<S1333>:1:50' mapLength = 0; */
        mapLength = 0.0;

        /* '<S1333>:1:51' mapDifference = nChanOut; */
        mapDifference = 18.0;
    }

    /* '<S1333>:1:53' endOfMap = 0; */
    endOfMap = 0.0;

    /* '<S1333>:1:54' loopCount = 0; */
    loopCount = 0.0;

    /* '<S1333>:1:55' while endOfMap < mapDifference */
    while (endOfMap < mapDifference)
    {
        boolean_T exitg1;

        /* '<S1333>:1:56' for inputChan = 1 : nInRouterMask */
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= (int32_T)rtp_nInRouterMask - 1))
        {
            /* '<S1333>:1:57' OutMap(mapLength+inputChan+loopCount) = inputChan; */
            localB->OutMap[(int32_T)((mapLength + ((real_T)i + 1.0)) + loopCount)
                - 1] = i + 1;

            /* '<S1333>:1:58' endOfMap = endOfMap + 1; */
            endOfMap++;

            /* '<S1333>:1:59' if endOfMap == mapDifference */
            if (endOfMap == mapDifference)
            {
                exitg1 = true;
            }
            else
            {
                i++;
            }
        }

        /* '<S1333>:1:63' inputChan = 1; */
        /* '<S1333>:1:64' loopCount = loopCount + nInRouterMask; */
        loopCount += rtp_nInRouterMask;
    }
}

/* Output and update for function-call system: '<S1332>/tfunc' */
void FuncTranslation_Model_926(void)
{
    /* MATLAB Function: '<S1331>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1334>:1' */
    /* '<S1334>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pe
        (&Model_TranslationEngine64_B.Map, 10.0,
         &Model_TranslationEngine64_B.sf_TrivialTranslation_p);
}

/* Function for MATLAB Function: '<S1335>/Translation' */
static void Model_TranslationEngine64_cat(const real32_T varargin_1[25], const
    real32_T varargin_2[25], const real32_T varargin_3[25], const real32_T
    varargin_4[25], const real32_T varargin_5[25], const real32_T varargin_6[25],
    const real32_T varargin_7[25], const real32_T varargin_8[25], const real32_T
    varargin_9[25], const real32_T varargin_10[25], const real32_T varargin_11
    [25], const real32_T varargin_12[25], real32_T y[300])
{
    int32_T j;
    for (j = 0; j < 25; j++)
    {
        y[j] = varargin_1[j];
        y[j + 25] = varargin_2[j];
        y[j + 50] = varargin_3[j];
        y[j + 75] = varargin_4[j];
        y[j + 100] = varargin_5[j];
        y[j + 125] = varargin_6[j];
        y[j + 150] = varargin_7[j];
        y[j + 175] = varargin_8[j];
        y[j + 200] = varargin_9[j];
        y[j + 225] = varargin_10[j];
        y[j + 250] = varargin_11[j];
        y[j + 275] = varargin_12[j];
    }
}

/* Output and update for function-call system: '<S1340>/tfunc' */
void FuncTranslation_Model_1026(void)
{
    int32_T i;
    int32_T i_0;
    int32_T i_1;
    int32_T mix_j_tmp;
    real32_T x[175];
    real32_T b_x[50];

    /* MATLAB Function: '<S1335>/Translation' */
    /* MATLAB Function: '<S1335>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable3'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable5'
     *  S-Function (TuneVarMEX): '<S1336>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable10'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable11'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable3'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable5'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable6'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable8'
     *  S-Function (TuneVarMEX): '<S1337>/Tune Variable9'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable10'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable11'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable3'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable5'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable6'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable8'
     *  S-Function (TuneVarMEX): '<S1338>/Tune Variable9'
     *  S-Function (TuneVarMEX): '<S1339>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1339>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1339>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1339>/Tune Variable3'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1342>:1' */
    /* '<S1342>:1:3' f(); */
    /*  mix = cat(3, F1.Value, F1.Value);                     */
    /*  mix = cat(              3,...  */
    /*                          F1.Value,... */
    /*                          F2.Value,... */
    /*                          F3.Value,... */
    /*                          F4.Value,... */
    /*                          F5.Value,... */
    /*                          F6.Value,... */
    /*                          F7.Value,... */
    /*                          LFI0.Value,... */
    /*                          LFT0.Value,... */
    /*                          RFI0.Value,... */
    /*                          RFT0.Value,... */
    /*                          LSI0.Value,... */
    /*                          LST0.Value,... */
    /*                          RSI0.Value,... */
    /*                          RST0.Value,... */
    /*                          LCI0.Value,... */
    /*                          LCT0.Value,... */
    /*                          RCI0.Value,... */
    /*                          RCT0.Value,... */
    /*                          LFI1.Value,... */
    /*                          LFT1.Value,... */
    /*                          RFI1.Value,... */
    /*                          RFT1.Value,... */
    /*                          LSI1.Value,... */
    /*                          LST1.Value,... */
    /*                          RSI1.Value,... */
    /*                          RST1.Value,... */
    /*                          LCI1.Value,... */
    /*                          LCT1.Value,... */
    /*                          RCI1.Value,... */
    /*                          RCT1.Value,... */
    /*                          nv0l.Value,... */
    /*                          nv0r.Value,... */
    /*                          nv1l.Value,... */
    /*                          nv1r.Value); */
    /* MATLAB Function 'NEAR/Near1p1/DrProc/Upmixer1p1Dr/Subsystem1/Translation': '<S1341>:1' */
    /*  f = size(fArr, 1); */
    /*  hr = size(hrArr, 1); */
    /*  cph = size(cphArr, 1); */
    /* '<S1341>:1:79' f = FrontPeripheralChannelCount; */
    /* '<S1341>:1:80' hr = HeadrestCount; */
    /* '<S1341>:1:81' cph = ChannelsPerHeadrest; */
    /* '<S1341>:1:82' mixSize = f + hr*cph; */
    /*  s = size(F1.Value, 1); */
    /* '<S1341>:1:84' s = size(LFI0.Value, 1); */
    /* '<S1341>:1:85' mix = single(zeros(s, s, mixSize)); */
    memset(&Model_TranslationEngine64_B.mix_j[0], 0, 875U * sizeof(real32_T));

    /* '<S1341>:1:87' x = cat(3, F1.Value, F2.Value, F3.Value, F4.Value, F5.Value, F6.Value, F7.Value); */
    for (i = 0; i < 25; i++)
    {
        x[i] = Model_TranslationEngine64_B.f1_mix.Value[i];
        x[i + 25] = Model_TranslationEngine64_B.f2_mix.Value[i];
        x[i + 50] = Model_TranslationEngine64_B.f3_mix.Value[i];
        x[i + 75] = Model_TranslationEngine64_B.f4_mix.Value[i];
        x[i + 100] = Model_TranslationEngine64_B.f5_mix.Value[i];
        x[i + 125] = Model_TranslationEngine64_B.f6_mix.Value[i];
        x[i + 150] = Model_TranslationEngine64_B.f7_mix.Value[i];
    }

    /* '<S1341>:1:88' mix(:,:,1:f) = x(:,:,1:f); */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 7; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                Model_TranslationEngine64_B.mix_j[(i_0 + 5 * i) + 25 * i_1] = x
                    [(5 * i + i_0) + 25 * i_1];
            }
        }
    }

    /* '<S1341>:1:89' if cph == 14 */
    /* '<S1341>:1:90' x = cat(        3,...  */
    /* '<S1341>:1:91'                     LFI0.Value,... */
    /* '<S1341>:1:92'                     LFT0.Value,... */
    /* '<S1341>:1:93'                     RFI0.Value,... */
    /* '<S1341>:1:94'                     RFT0.Value,... */
    /* '<S1341>:1:95'                     LSI0.Value,... */
    /* '<S1341>:1:96'                     LST0.Value,... */
    /* '<S1341>:1:97'                     RSI0.Value,... */
    /* '<S1341>:1:98'                     RST0.Value,... */
    /* '<S1341>:1:99'                     LCI0.Value,... */
    /* '<S1341>:1:100'                     LCT0.Value,... */
    /* '<S1341>:1:101'                     RCI0.Value,... */
    /* '<S1341>:1:102'                     RCT0.Value); */
    Model_TranslationEngine64_cat(Model_TranslationEngine64_B.LFI0_mix.Value,
        Model_TranslationEngine64_B.LFT0_mix.Value,
        Model_TranslationEngine64_B.RFI0_mix.Value,
        Model_TranslationEngine64_B.RFT0_mix.Value,
        Model_TranslationEngine64_B.LSI0_mix.Value,
        Model_TranslationEngine64_B.LST0_mix.Value,
        Model_TranslationEngine64_B.RSI0_mix.Value,
        Model_TranslationEngine64_B.RST0_mix.Value,
        Model_TranslationEngine64_B.LCI0_mix.Value,
        Model_TranslationEngine64_B.LCT0_mix.Value,
        Model_TranslationEngine64_B.RCI0_mix.Value,
        Model_TranslationEngine64_B.RCT0_mix.Value,
        &Model_TranslationEngine64_B.mix_j[175]);

    /* '<S1341>:1:103' mix(:,:,f+1:f+12) = x; */
    /* '<S1341>:1:104' if hr == 2 */
    /* '<S1341>:1:105' x = cat(    3,...  */
    /* '<S1341>:1:106'                     LFI1.Value,... */
    /* '<S1341>:1:107'                     LFT1.Value,... */
    /* '<S1341>:1:108'                     RFI1.Value,... */
    /* '<S1341>:1:109'                     RFT1.Value,... */
    /* '<S1341>:1:110'                     LSI1.Value,... */
    /* '<S1341>:1:111'                     LST1.Value,... */
    /* '<S1341>:1:112'                     RSI1.Value,... */
    /* '<S1341>:1:113'                     RST1.Value,... */
    /* '<S1341>:1:114'                     LCI1.Value,... */
    /* '<S1341>:1:115'                     LCT1.Value,... */
    /* '<S1341>:1:116'                     RCI1.Value,... */
    /* '<S1341>:1:117'                     RCT1.Value); */
    Model_TranslationEngine64_cat(Model_TranslationEngine64_B.LFI1_mix.Value,
        Model_TranslationEngine64_B.LFT1_mix.Value,
        Model_TranslationEngine64_B.RFI1_mix.Value,
        Model_TranslationEngine64_B.RFT1_mix.Value,
        Model_TranslationEngine64_B.LSI1_mix.Value,
        Model_TranslationEngine64_B.LST1_mix.Value,
        Model_TranslationEngine64_B.RSI1_mix.Value,
        Model_TranslationEngine64_B.RST1_mix.Value,
        Model_TranslationEngine64_B.LCI1_mix.Value,
        Model_TranslationEngine64_B.LCT1_mix.Value,
        Model_TranslationEngine64_B.RCI1_mix.Value,
        Model_TranslationEngine64_B.RCT1_mix.Value,
        &Model_TranslationEngine64_B.mix_j[475]);

    /* '<S1341>:1:118' mix(:,:,f+13:f+24) = x; */
    /* '<S1341>:1:121' x = cat(    3,...  */
    /* '<S1341>:1:122'             nv0l.Value,... */
    /* '<S1341>:1:123'             nv0r.Value); */
    for (i = 0; i < 25; i++)
    {
        b_x[i] = Model_TranslationEngine64_B.nv0l_mix.Value[i];
        b_x[i + 25] = Model_TranslationEngine64_B.nv0r_mix.Value[i];
    }

    /* '<S1341>:1:124' mix(:,:,f+((cph-2)*hr)+1:f+((cph-2)*hr)+2) = x; */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 2; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                mix_j_tmp = 5 * i + i_0;
                Model_TranslationEngine64_B.mix_j[mix_j_tmp + 25 * (i_1 + 31)] =
                    b_x[25 * i_1 + mix_j_tmp];
            }
        }
    }

    /* '<S1341>:1:125' if hr == 2 */
    /* '<S1341>:1:126' x = cat(    3,...  */
    /* '<S1341>:1:127'                 nv1l.Value,... */
    /* '<S1341>:1:128'                 nv1r.Value); */
    for (i = 0; i < 25; i++)
    {
        b_x[i] = Model_TranslationEngine64_B.nv1l_mix.Value[i];
        b_x[i + 25] = Model_TranslationEngine64_B.nv1r_mix.Value[i];
    }

    /* '<S1341>:1:129' mix(:,:,f+((cph-2)*hr)+3:f+((cph-2)*hr)+4) = x; */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 2; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                mix_j_tmp = 5 * i + i_0;
                Model_TranslationEngine64_B.mix_j[mix_j_tmp + 25 * (i_1 + 33)] =
                    b_x[25 * i_1 + mix_j_tmp];
            }
        }
    }

    /* End of MATLAB Function: '<S1335>/Translation' */
}

/* Function for MATLAB Function: '<S1350>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_kl(int32_T b,
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

/* Output and update for function-call system: '<S1351>/tfunc' */
void FuncTranslation_Model_1063_36(void)
{
    real_T ChannelCoeffs[400];
    real_T OverallGainPerCh[5];
    real_T c_y;
    int32_T f_data[400];
    int32_T tmp_data[400];
    int32_T b_data[100];
    int32_T ts_data[100];
    int32_T NumStages[5];
    int32_T SOSIndex;
    int32_T b_vlen;
    int32_T d_k;
    int32_T k;
    int32_T yk;
    real32_T PoolCoeffs[400];
    char_T d_data[31];
    static const char_T e[31] = "Too many second order sections";
    int32_T tmp_size[2];

    /* MATLAB Function: '<S1350>/Translation' */
    /* MATLAB Function: '<S1350>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1350>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1350>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1353>:1' */
    /* '<S1353>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'NEAR/Near1p1/FrProc/Subsystem/FsEQFr/Pooliir/PoolIirTunableWithReset/Translation': '<S1352>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1352>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1352>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1352>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    for (SOSIndex = 0; SOSIndex < 5; SOSIndex++)
    {
        c_y = rt_roundd_snf
            (Model_TranslationEngine64_B.numStages_n.Value[SOSIndex]);
        if (c_y < 2.147483648E+9)
        {
            if (c_y >= -2.147483648E+9)
            {
                NumStages[SOSIndex] = (int32_T)c_y;
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

        Model_TranslationEngine64_B.PoolNumStages_j[SOSIndex] = 0;
    }

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&PoolCoeffs[0], 0, 400U * sizeof(real32_T));
    memset(&ChannelCoeffs[0], 0, 400U * sizeof(real_T));

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (((((real_T)NumStages[0] + (real_T)NumStages[1]) + (real_T)NumStages[2])
            + (real_T)NumStages[3]) + (real_T)NumStages[4] > 100.0)
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
    for (k = 0; k < 5; k++)
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
            Model_TranslationEngine64_eml_integer_colon_dispatcher_kl
                (NumStages_0, tmp_data, tmp_size);
            ChannelSOS_size_idx_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < 6; b_vlen++)
            {
                for (d_k = 0; d_k < yk; d_k++)
                {
                    q1 = tmp_data[d_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    Model_TranslationEngine64_B.ChannelSOS_data_m[d_k +
                        ChannelSOS_size_idx_0 * b_vlen] =
                        Model_TranslationEngine64_B.sosCoefficients_o.Value[(100
                        * b_vlen + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (tmp_size[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset = Model_TranslationEngine64_B.ChannelSOS_data_m[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *= Model_TranslationEngine64_B.ChannelSOS_data_m[yk -
                        1];
                }
            }

            if (tmp_size[1] == 0)
            {
                c_y = 1.0;
            }
            else
            {
                c_y = Model_TranslationEngine64_B.ChannelSOS_data_m[tmp_size[1] *
                    3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    c_y *= Model_TranslationEngine64_B.ChannelSOS_data_m
                        [(ChannelSOS_size_idx_0 * 3 + yk) - 1];
                }
            }

            OverallGainPerCh[k] = offset / c_y;

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
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[b_vlen]);
                _mm_storeu_si128((__m128i *)&b_data[b_vlen], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (b_vlen = d_k; b_vlen < ts_size_idx_1; b_vlen++)
            {
                b_data[b_vlen] = ts_data[b_vlen] + 1;
            }

            for (b_vlen = 0; b_vlen < ts_size_idx_1; b_vlen++)
            {
                ChannelCoeffs[b_data[b_vlen] - 1] =
                    -Model_TranslationEngine64_B.ChannelSOS_data_m
                    [(ChannelSOS_size_idx_0 << 2) + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data_m[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
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
                ChannelCoeffs[b_data[b_vlen] - 1] =
                    Model_TranslationEngine64_B.ChannelSOS_data_m[b_vlen +
                    ChannelSOS_size_idx_0] /
                    Model_TranslationEngine64_B.ChannelSOS_data_m[b_vlen];
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
                    -Model_TranslationEngine64_B.ChannelSOS_data_m[ChannelSOS_size_idx_0
                    * 5 + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data_m[ChannelSOS_size_idx_0
                    * 3 + b_vlen];
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
                ChannelCoeffs[ts_data[b_vlen] - 1] =
                    Model_TranslationEngine64_B.ChannelSOS_data_m
                    [(ChannelSOS_size_idx_0 << 1) + b_vlen] /
                    Model_TranslationEngine64_B.ChannelSOS_data_m[b_vlen];
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
                offset = Model_TranslationEngine64_B.PoolNumStages_j[0];
                for (d_k = 2; d_k <= k; d_k++)
                {
                    offset += (real_T)
                        Model_TranslationEngine64_B.PoolNumStages_j[d_k - 1];
                }
            }

            offset *= 4.0;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages_j[k] = NumStages_0;

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

            Model_TranslationEngine64_eml_integer_colon_dispatcher_kl(b_vlen,
                tmp_data, tmp_size);
            NumStages_0 = tmp_size[1];
            yk = tmp_size[1];
            for (b_vlen = 0; b_vlen < yk; b_vlen++)
            {
                c_y = offset + (real_T)tmp_data[b_vlen];
                if (c_y < 2.147483648E+9)
                {
                    if (c_y >= -2.147483648E+9)
                    {
                        f_data[b_vlen] = (int32_T)c_y;
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

            for (b_vlen = 0; b_vlen < NumStages_0; b_vlen++)
            {
                PoolCoeffs[f_data[b_vlen] - 1] = (real32_T)ChannelCoeffs[b_vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    memcpy(&Model_TranslationEngine64_B.PoolCoeffs_l[0], &PoolCoeffs[0], 400U *
           sizeof(real32_T));
    for (SOSIndex = 0; SOSIndex < 5; SOSIndex++)
    {
        Model_TranslationEngine64_B.PoolCoeffs_l[SOSIndex + 400] = (real32_T)
            OverallGainPerCh[SOSIndex];
    }

    /* End of MATLAB Function: '<S1350>/Translation' */
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

/* Output and update for function-call system: '<S1355>/tfunc' */
void FuncTranslation_Model_1052(void)
{
    /* MATLAB Function: '<S1349>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1357>:1' */
    /* '<S1357>:1:3' f(); */
    Model_TranslationEngine64_Translation_p
        (&Model_TranslationEngine64_B.f1_del_p,
         &Model_TranslationEngine64_B.f2_del_c,
         &Model_TranslationEngine64_B.f3_del_b,
         &Model_TranslationEngine64_B.f4_del_p,
         &Model_TranslationEngine64_B.f5_del_b,
         &Model_TranslationEngine64_B.f6_del_n,
         &Model_TranslationEngine64_B.f7_del_c,
         &Model_TranslationEngine64_B.sf_Translation_pmq);
}

/* Output and update for function-call system: '<S1361>/tfunc' */
void FuncTranslation_Model_1104_36(void)
{
    /* MATLAB Function: '<S1360>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1363>:1' */
    /* '<S1363>:1:3' f(); */
    Model_TranslationEngine64_Translation_h
        (&Model_TranslationEngine64_B.sosCoefficients_j,
         &Model_TranslationEngine64_B.numStages_c,
         &Model_TranslationEngine64_B.sf_Translation_pii);
}

/* Output and update for function-call system: '<S1365>/tfunc' */
void FuncTranslation_Model_1092(void)
{
    /* MATLAB Function: '<S1359>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1367>:1' */
    /* '<S1367>:1:3' f(); */
    Model_TranslationEngine64_Translation_e
        (&Model_TranslationEngine64_B.driver_src1_l,
         &Model_TranslationEngine64_B.driver_src2_p,
         &Model_TranslationEngine64_B.passenger_src1_p,
         &Model_TranslationEngine64_B.passenger_src2_j,
         &Model_TranslationEngine64_B.sf_Translation_ir1);
}

/* Output and update for function-call system: '<S1369>/tfunc' */
void FuncTranslation_Model_1115(void)
{
    /* MATLAB Function: '<S1368>/Trivial Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1371>:1' */
    /* '<S1371>:1:3' f(); */
    Model_TranslationEngine64_TrivialTranslation_pe
        (&Model_TranslationEngine64_B.Map_k, 10.0,
         &Model_TranslationEngine64_B.sf_TrivialTranslation_nx);
}

/* Output and update for function-call system: '<S1377>/tfunc' */
void FuncTranslation_Model_1215(void)
{
    int32_T i;
    int32_T i_0;
    int32_T i_1;
    int32_T mix_tmp;
    real32_T x[175];
    real32_T b_x[50];

    /* MATLAB Function: '<S1372>/Translation' */
    /* MATLAB Function: '<S1372>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable3'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable4'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable5'
     *  S-Function (TuneVarMEX): '<S1373>/Tune Variable7'
     *  S-Function (TuneVarMEX): '<S1376>/Tune Variable'
     *  S-Function (TuneVarMEX): '<S1376>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1376>/Tune Variable2'
     *  S-Function (TuneVarMEX): '<S1376>/Tune Variable3'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1379>:1' */
    /* '<S1379>:1:3' f(); */
    /*  mix = cat(3, F1.Value, F1.Value);                     */
    /*  mix = cat(              3,...  */
    /*                          F1.Value,... */
    /*                          F2.Value,... */
    /*                          F3.Value,... */
    /*                          F4.Value,... */
    /*                          F5.Value,... */
    /*                          F6.Value,... */
    /*                          F7.Value,... */
    /*                          LFI0.Value,... */
    /*                          LFT0.Value,... */
    /*                          RFI0.Value,... */
    /*                          RFT0.Value,... */
    /*                          LSI0.Value,... */
    /*                          LST0.Value,... */
    /*                          RSI0.Value,... */
    /*                          RST0.Value,... */
    /*                          LCI0.Value,... */
    /*                          LCT0.Value,... */
    /*                          RCI0.Value,... */
    /*                          RCT0.Value,... */
    /*                          LFI1.Value,... */
    /*                          LFT1.Value,... */
    /*                          RFI1.Value,... */
    /*                          RFT1.Value,... */
    /*                          LSI1.Value,... */
    /*                          LST1.Value,... */
    /*                          RSI1.Value,... */
    /*                          RST1.Value,... */
    /*                          LCI1.Value,... */
    /*                          LCT1.Value,... */
    /*                          RCI1.Value,... */
    /*                          RCT1.Value,... */
    /*                          nv0l.Value,... */
    /*                          nv0r.Value,... */
    /*                          nv1l.Value,... */
    /*                          nv1r.Value); */
    /* MATLAB Function 'NEAR/Near1p1/FrProc/Subsystem/Upmixer1p1Fr/Subsystem1/Translation': '<S1378>:1' */
    /*  f = size(fArr, 1); */
    /*  hr = size(hrArr, 1); */
    /*  cph = size(cphArr, 1); */
    /* '<S1378>:1:79' f = FrontPeripheralChannelCount; */
    /* '<S1378>:1:80' hr = HeadrestCount; */
    /* '<S1378>:1:81' cph = ChannelsPerHeadrest; */
    /* '<S1378>:1:82' mixSize = f + hr*cph; */
    /*  s = size(F1.Value, 1); */
    /* '<S1378>:1:84' s = size(LFI0.Value, 1); */
    /* '<S1378>:1:85' mix = single(zeros(s, s, mixSize)); */
    memset(&Model_TranslationEngine64_B.mix[0], 0, 225U * sizeof(real32_T));

    /* '<S1378>:1:87' x = cat(3, F1.Value, F2.Value, F3.Value, F4.Value, F5.Value, F6.Value, F7.Value); */
    for (i = 0; i < 25; i++)
    {
        x[i] = Model_TranslationEngine64_B.f1_mix_f.Value[i];
        x[i + 25] = Model_TranslationEngine64_B.f2_mix_i.Value[i];
        x[i + 50] = Model_TranslationEngine64_B.f3_mix_g.Value[i];
        x[i + 75] = Model_TranslationEngine64_B.f4_mix_i.Value[i];
        x[i + 100] = Model_TranslationEngine64_B.f5_mix_g.Value[i];
        x[i + 125] = Model_TranslationEngine64_B.f6_mix_g.Value[i];
        x[i + 150] = Model_TranslationEngine64_B.f7_mix_c.Value[i];
    }

    /* '<S1378>:1:88' mix(:,:,1:f) = x(:,:,1:f); */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 5; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                Model_TranslationEngine64_B.mix[(i_0 + 5 * i) + 25 * i_1] = x[(5
                    * i + i_0) + 25 * i_1];
            }
        }
    }

    /* '<S1378>:1:89' if cph == 14 */
    /* '<S1378>:1:121' x = cat(    3,...  */
    /* '<S1378>:1:122'             nv0l.Value,... */
    /* '<S1378>:1:123'             nv0r.Value); */
    for (i = 0; i < 25; i++)
    {
        b_x[i] = Model_TranslationEngine64_B.nv0l_mix_i.Value[i];
        b_x[i + 25] = Model_TranslationEngine64_B.nv0r_mix_j.Value[i];
    }

    /* '<S1378>:1:124' mix(:,:,f+((cph-2)*hr)+1:f+((cph-2)*hr)+2) = x; */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 2; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                mix_tmp = 5 * i + i_0;
                Model_TranslationEngine64_B.mix[mix_tmp + 25 * (i_1 + 5)] = b_x
                    [25 * i_1 + mix_tmp];
            }
        }
    }

    /* '<S1378>:1:125' if hr == 2 */
    /* '<S1378>:1:126' x = cat(    3,...  */
    /* '<S1378>:1:127'                 nv1l.Value,... */
    /* '<S1378>:1:128'                 nv1r.Value); */
    for (i = 0; i < 25; i++)
    {
        b_x[i] = Model_TranslationEngine64_B.nv1l_mix_j.Value[i];
        b_x[i + 25] = Model_TranslationEngine64_B.nv1r_mix_n.Value[i];
    }

    /* '<S1378>:1:129' mix(:,:,f+((cph-2)*hr)+3:f+((cph-2)*hr)+4) = x; */
    for (i = 0; i < 5; i++)
    {
        for (i_1 = 0; i_1 < 2; i_1++)
        {
            for (i_0 = 0; i_0 < 5; i_0++)
            {
                mix_tmp = 5 * i + i_0;
                Model_TranslationEngine64_B.mix[mix_tmp + 25 * (i_1 + 7)] = b_x
                    [25 * i_1 + mix_tmp];
            }
        }
    }

    /* End of MATLAB Function: '<S1372>/Translation' */
}

/* Output and update for function-call system: '<S1383>/tfunc' */
void FuncTranslation_Model_831_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1381>/Subsystem' */
    /* SignalConversion generated from: '<S1382>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1384>:1' */
    /* '<S1384>:1:3' f(); */
    Model_TranslationEngine64_B.Value_nc =
        Model_TranslationEngine64_B.RampDbPerSample.Value;

    /* End of Outputs for SubSystem: '<S1381>/Subsystem' */
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_merge(int32_T idx_data[], real_T x_data[],
    int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T
    xwork_data[])
{
    int32_T q;
    if (nq != 0)
    {
        int32_T iout;
        int32_T n;
        int32_T qend;
        qend = np + nq;
        for (q = 0; q < qend; q++)
        {
            iwork_data[q] = idx_data[offset + q];
            xwork_data[q] = x_data[offset + q];
        }

        n = 0;
        q = np;
        iout = offset - 1;
        int32_T exitg1;
        do
        {
            exitg1 = 0;
            iout++;
            if (xwork_data[n] <= xwork_data[q])
            {
                idx_data[iout] = iwork_data[n];
                x_data[iout] = xwork_data[n];
                if (n + 1 < np)
                {
                    n++;
                }
                else
                {
                    exitg1 = 1;
                }
            }
            else
            {
                idx_data[iout] = iwork_data[q];
                x_data[iout] = xwork_data[q];
                if (q + 1 < qend)
                {
                    q++;
                }
                else
                {
                    qend = iout - n;
                    for (q = n + 1; q <= np; q++)
                    {
                        iout = qend + q;
                        idx_data[iout] = iwork_data[q - 1];
                        x_data[iout] = xwork_data[q - 1];
                    }

                    exitg1 = 1;
                }
            }
        }
        while (exitg1 == 0);
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_sort(real_T x_data[], int32_T x_size[2])
{
    real_T b_x_data[20];
    real_T xwork_data[20];
    real_T x4[4];
    int32_T idx_data[20];
    int32_T iwork_data[20];
    int32_T b_x_size[2];
    int32_T nPairs;
    int32_T tailOffset;
    int8_T idx4[4];
    int8_T perm[4];
    b_x_size[1] = x_size[1];
    nPairs = x_size[1];
    if (nPairs - 1 >= 0)
    {
        memcpy(&b_x_data[0], &x_data[0], (uint32_T)nPairs * sizeof(real_T));
    }

    if (x_size[1] != 0)
    {
        int32_T i2;
        int32_T ib;
        int32_T n;
        nPairs = x_size[1];
        if (nPairs - 1 >= 0)
        {
            memset(&idx_data[0], 0, (uint32_T)nPairs * sizeof(int32_T));
        }

        b_x_size[1] = x_size[1];
        nPairs = x_size[1];
        if (nPairs - 1 >= 0)
        {
            memcpy(&b_x_data[0], &x_data[0], (uint32_T)nPairs * sizeof(real_T));
        }

        n = x_size[1];
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        ib = 0;
        tailOffset = x_size[1];
        for (nPairs = 0; nPairs < tailOffset; nPairs++)
        {
            ib++;
            idx4[ib - 1] = (int8_T)(nPairs + 1);
            x4[ib - 1] = b_x_data[nPairs];
            if (ib == 4)
            {
                real_T tmp;
                real_T tmp_0;
                int32_T i3;
                int32_T i4;
                if (x4[0] <= x4[1])
                {
                    ib = 1;
                    i2 = 2;
                }
                else
                {
                    ib = 2;
                    i2 = 1;
                }

                if (x4[2] <= x4[3])
                {
                    i3 = 3;
                    i4 = 4;
                }
                else
                {
                    i3 = 4;
                    i4 = 3;
                }

                tmp = x4[ib - 1];
                tmp_0 = x4[i3 - 1];
                if (tmp <= tmp_0)
                {
                    tmp = x4[i2 - 1];
                    if (tmp <= tmp_0)
                    {
                        perm[0] = (int8_T)ib;
                        perm[1] = (int8_T)i2;
                        perm[2] = (int8_T)i3;
                        perm[3] = (int8_T)i4;
                    }
                    else if (tmp <= x4[i4 - 1])
                    {
                        perm[0] = (int8_T)ib;
                        perm[1] = (int8_T)i3;
                        perm[2] = (int8_T)i2;
                        perm[3] = (int8_T)i4;
                    }
                    else
                    {
                        perm[0] = (int8_T)ib;
                        perm[1] = (int8_T)i3;
                        perm[2] = (int8_T)i4;
                        perm[3] = (int8_T)i2;
                    }
                }
                else
                {
                    tmp_0 = x4[i4 - 1];
                    if (tmp <= tmp_0)
                    {
                        if (x4[i2 - 1] <= tmp_0)
                        {
                            perm[0] = (int8_T)i3;
                            perm[1] = (int8_T)ib;
                            perm[2] = (int8_T)i2;
                            perm[3] = (int8_T)i4;
                        }
                        else
                        {
                            perm[0] = (int8_T)i3;
                            perm[1] = (int8_T)ib;
                            perm[2] = (int8_T)i4;
                            perm[3] = (int8_T)i2;
                        }
                    }
                    else
                    {
                        perm[0] = (int8_T)i3;
                        perm[1] = (int8_T)i4;
                        perm[2] = (int8_T)ib;
                        perm[3] = (int8_T)i2;
                    }
                }

                idx_data[nPairs - 3] = idx4[perm[0] - 1];
                idx_data[nPairs - 2] = idx4[perm[1] - 1];
                idx_data[nPairs - 1] = idx4[perm[2] - 1];
                idx_data[nPairs] = idx4[perm[3] - 1];
                b_x_data[nPairs - 3] = x4[perm[0] - 1];
                b_x_data[nPairs - 2] = x4[perm[1] - 1];
                b_x_data[nPairs - 1] = x4[perm[2] - 1];
                b_x_data[nPairs] = x4[perm[3] - 1];
                ib = 0;
            }
        }

        if (ib > 0)
        {
            perm[1] = 0;
            perm[2] = 0;
            perm[3] = 0;
            switch (ib)
            {
              case 1:
                perm[0] = 1;
                break;

              case 2:
                if (x4[0] <= x4[1])
                {
                    perm[0] = 1;
                    perm[1] = 2;
                }
                else
                {
                    perm[0] = 2;
                    perm[1] = 1;
                }
                break;

              default:
                if (x4[0] <= x4[1])
                {
                    if (x4[1] <= x4[2])
                    {
                        perm[0] = 1;
                        perm[1] = 2;
                        perm[2] = 3;
                    }
                    else if (x4[0] <= 0.0)
                    {
                        perm[0] = 1;
                        perm[1] = 3;
                        perm[2] = 2;
                    }
                    else
                    {
                        perm[0] = 3;
                        perm[1] = 1;
                        perm[2] = 2;
                    }
                }
                else if (x4[0] <= x4[2])
                {
                    perm[0] = 2;
                    perm[1] = 1;
                    perm[2] = 3;
                }
                else
                {
                    perm[0] = 2;
                    perm[1] = 3;
                    perm[2] = 1;
                }
                break;
            }

            tailOffset = (uint8_T)ib;
            for (nPairs = 0; nPairs < tailOffset; nPairs++)
            {
                int8_T perm_0;
                perm_0 = perm[nPairs];
                i2 = (n - ib) + nPairs;
                idx_data[i2] = idx4[perm_0 - 1];
                b_x_data[i2] = x4[perm_0 - 1];
            }
        }

        if (x_size[1] > 1)
        {
            nPairs = x_size[1];
            if (nPairs - 1 >= 0)
            {
                memset(&iwork_data[0], 0, (uint32_T)nPairs * sizeof(int32_T));
            }

            nPairs = x_size[1];
            if (nPairs - 1 >= 0)
            {
                memset(&xwork_data[0], 0, (uint32_T)nPairs * sizeof(real_T));
            }

            nPairs = x_size[1] >> 2;
            n = 4;
            while (nPairs > 1)
            {
                if (((uint32_T)nPairs & 1U) != 0U)
                {
                    nPairs--;
                    tailOffset = n * nPairs;
                    ib = x_size[1] - tailOffset;
                    if (ib > n)
                    {
                        Model_TranslationEngine64_merge(idx_data, b_x_data,
                            tailOffset, n, ib - n, iwork_data, xwork_data);
                    }
                }

                ib = n << 1;
                nPairs >>= 1;
                for (tailOffset = 0; tailOffset < nPairs; tailOffset++)
                {
                    Model_TranslationEngine64_merge(idx_data, b_x_data,
                        tailOffset * ib, n, n, iwork_data, xwork_data);
                }

                n = ib;
            }

            if (x_size[1] > n)
            {
                Model_TranslationEngine64_merge(idx_data, b_x_data, 0, n,
                    x_size[1] - n, iwork_data, xwork_data);
            }
        }
    }

    x_size[0] = 1;
    x_size[1] = b_x_size[1];
    nPairs = b_x_size[1];
    if (nPairs - 1 >= 0)
    {
        memcpy(&x_data[0], &b_x_data[0], (uint32_T)nPairs * sizeof(real_T));
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_cplxpair(real_T x_data[], int32_T x_size[2])
{
    if (x_size[1] != 0)
    {
        Model_TranslationEngine64_sort(x_data, x_size);
    }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
    real_T a;
    real_T b;
    real_T y;
    a = fabs(u0);
    b = fabs(u1);
    if (a < b)
    {
        a /= b;
        y = sqrt(a * a + 1.0) * b;
    }
    else if (a > b)
    {
        b /= a;
        y = sqrt(b * b + 1.0) * a;
    }
    else if (rtIsNaN(b))
    {
        y = (rtNaN);
    }
    else
    {
        y = a * 1.4142135623730951;
    }

    return y;
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static boolean_T Model_TranslationEngine64_cplxpairv(creal_T x_data[], const
    int32_T x_size[2])
{
    real_T absx_data[20];
    real_T zi_data[20];
    real_T zr_data[20];
    real_T absxk;
    real_T absxk_tmp;
    real_T absxk_tmp_0;
    int32_T b_iwork_data[20];
    int32_T idx_data[20];
    int32_T iwork_data[20];
    int32_T absxk_tmp_tmp;
    int32_T b_i;
    int32_T b_i2;
    int32_T b_kEnd;
    int32_T b_n;
    int32_T b_p;
    int32_T b_pEnd;
    int32_T b_q;
    int32_T b_qEnd;
    int32_T d_j;
    int32_T i_k;
    int32_T idx_tmp;
    int32_T n;
    boolean_T exitg1;
    boolean_T pairable;
    n = x_size[1];
    b_n = x_size[1];
    b_i = x_size[1];
    for (i_k = 0; i_k < b_i; i_k++)
    {
        zr_data[i_k] = x_data[i_k].re;
    }

    if (b_n - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)b_n * sizeof(int32_T));
    }

    if (x_size[1] != 0)
    {
        b_i2 = x_size[1] - 1;
        for (b_i = 1; b_i <= b_i2; b_i += 2)
        {
            absxk_tmp = zr_data[b_i];
            if ((zr_data[b_i - 1] <= absxk_tmp) || rtIsNaN(absxk_tmp))
            {
                idx_data[b_i - 1] = b_i;
                idx_data[b_i] = b_i + 1;
            }
            else
            {
                idx_data[b_i - 1] = b_i + 1;
                idx_data[b_i] = b_i;
            }
        }

        if (((uint32_T)x_size[1] & 1U) != 0U)
        {
            idx_data[x_size[1] - 1] = x_size[1];
        }

        b_i = 2;
        while (b_i < b_n)
        {
            b_i2 = b_i << 1;
            d_j = 1;
            b_pEnd = b_i + 1;
            while (b_pEnd < b_n + 1)
            {
                b_p = d_j;
                b_q = b_pEnd - 1;
                b_qEnd = d_j + b_i2;
                if (b_qEnd > b_n + 1)
                {
                    b_qEnd = b_n + 1;
                }

                i_k = 0;
                b_kEnd = b_qEnd - d_j;
                while (i_k + 1 <= b_kEnd)
                {
                    absxk_tmp_tmp = idx_data[b_q];
                    absxk_tmp = zr_data[absxk_tmp_tmp - 1];
                    idx_tmp = idx_data[b_p - 1];
                    if ((zr_data[idx_tmp - 1] <= absxk_tmp) || rtIsNaN(absxk_tmp))
                    {
                        b_iwork_data[i_k] = idx_tmp;
                        b_p++;
                        if (b_p == b_pEnd)
                        {
                            while (b_q + 1 < b_qEnd)
                            {
                                i_k++;
                                b_iwork_data[i_k] = idx_data[b_q];
                                b_q++;
                            }
                        }
                    }
                    else
                    {
                        b_iwork_data[i_k] = absxk_tmp_tmp;
                        b_q++;
                        if (b_q + 1 == b_qEnd)
                        {
                            while (b_p < b_pEnd)
                            {
                                i_k++;
                                b_iwork_data[i_k] = idx_data[b_p - 1];
                                b_p++;
                            }
                        }
                    }

                    i_k++;
                }

                for (b_pEnd = 0; b_pEnd < b_kEnd; b_pEnd++)
                {
                    idx_data[(d_j + b_pEnd) - 1] = b_iwork_data[b_pEnd];
                }

                d_j = b_qEnd;
                b_pEnd = b_qEnd + b_i;
            }

            b_i = b_i2;
        }
    }

    b_i = 0;
    b_n = 0;
    b_kEnd = x_size[1];
    for (b_qEnd = 0; b_qEnd < b_kEnd; b_qEnd++)
    {
        i_k = idx_data[b_qEnd];
        absxk_tmp = x_data[i_k - 1].re;
        absxk_tmp_0 = x_data[i_k - 1].im;
        absxk = rt_hypotd_snf(absxk_tmp, absxk_tmp_0);
        if (fabs(x_data[i_k - 1].im) <= 2.2204460492503131E-14 * absxk)
        {
            b_i++;
            d_j = n - b_i;
            zr_data[d_j] = absxk_tmp;
            zi_data[d_j] = 0.0;
            absx_data[b_qEnd] = absxk;
        }
        else
        {
            b_n++;
            zr_data[b_n - 1] = absxk_tmp;
            zi_data[b_n - 1] = absxk_tmp_0;
            absx_data[b_n - 1] = absxk;
        }
    }

    for (d_j = 0; d_j < b_i; d_j++)
    {
        b_qEnd = b_n + d_j;
        x_data[b_qEnd].re = zr_data[(n - d_j) - 1];
        x_data[b_qEnd].im = 0.0;
    }

    for (n = 0; n < b_n; n++)
    {
        x_data[n].re = zr_data[n];
        x_data[n].im = zi_data[n];
    }

    pairable = ((b_n & 1) != 1);
    if (pairable)
    {
        n = 1;
        exitg1 = false;
        while ((!exitg1) && (n <= b_n))
        {
            if (zr_data[n] - zr_data[n - 1] > absx_data[n - 1] *
                    2.2204460492503131E-14)
            {
                pairable = false;
                exitg1 = true;
            }
            else
            {
                n += 2;
            }
        }
    }

    if (pairable)
    {
        n = 1;
        exitg1 = false;
        while ((!exitg1) && (n < b_n))
        {
            uint32_T pairable_tmp;
            absxk = zr_data[n - 1];
            b_i2 = n;
            b_i = n - 2;
            while ((n < b_n) && (zr_data[n] - absxk <= absx_data[n - 1] *
                                 2.2204460492503131E-14))
            {
                n++;
            }

            d_j = (n - b_i2) + 1;
            pairable_tmp = (uint32_T)d_j & 1U;
            pairable = (pairable_tmp == 0U);
            if (!pairable)
            {
                exitg1 = true;
            }
            else
            {
                boolean_T exitg2;
                for (b_qEnd = 1; b_qEnd <= d_j - 1; b_qEnd += 2)
                {
                    absxk = zi_data[(b_i + b_qEnd) + 1];
                    if ((zi_data[b_i + b_qEnd] <= absxk) || rtIsNaN(absxk))
                    {
                        b_kEnd = b_i + b_qEnd;
                        idx_data[b_kEnd] = b_qEnd;
                        idx_data[b_kEnd + 1] = b_qEnd + 1;
                    }
                    else
                    {
                        i_k = b_i + b_qEnd;
                        idx_data[i_k] = b_qEnd + 1;
                        idx_data[i_k + 1] = b_qEnd;
                    }
                }

                if (pairable_tmp != 0U)
                {
                    idx_data[b_i + d_j] = d_j;
                }

                b_qEnd = 2;
                while (b_qEnd < d_j)
                {
                    b_kEnd = b_qEnd << 1;
                    b_pEnd = 1;
                    i_k = b_qEnd + 1;
                    while (i_k < d_j + 1)
                    {
                        int32_T f_k;
                        int32_T p;
                        int32_T q;
                        p = b_pEnd;
                        q = i_k;
                        b_p = b_pEnd + b_kEnd;
                        if (b_p > d_j + 1)
                        {
                            b_p = d_j + 1;
                        }

                        f_k = 0;
                        b_q = b_p - b_pEnd;
                        while (f_k + 1 <= b_q)
                        {
                            absxk_tmp_tmp = idx_data[b_i + q];
                            absxk = zi_data[absxk_tmp_tmp + b_i];
                            idx_tmp = idx_data[b_i + p];
                            if ((zi_data[idx_tmp + b_i] <= absxk) || rtIsNaN
                                    (absxk))
                            {
                                iwork_data[f_k] = idx_tmp;
                                p++;
                                if (p == i_k)
                                {
                                    while (q < b_p)
                                    {
                                        f_k++;
                                        iwork_data[f_k] = idx_data[b_i + q];
                                        q++;
                                    }
                                }
                            }
                            else
                            {
                                iwork_data[f_k] = absxk_tmp_tmp;
                                q++;
                                if (q == b_p)
                                {
                                    while (p < i_k)
                                    {
                                        f_k++;
                                        iwork_data[f_k] = idx_data[b_i + p];
                                        p++;
                                    }
                                }
                            }

                            f_k++;
                        }

                        for (i_k = 0; i_k < b_q; i_k++)
                        {
                            idx_data[(b_i + b_pEnd) + i_k] = iwork_data[i_k];
                        }

                        b_pEnd = b_p;
                        i_k = b_p + b_qEnd;
                    }

                    b_qEnd = b_kEnd;
                }

                b_kEnd = b_i2;
                exitg2 = false;
                while ((!exitg2) && (b_kEnd <= n))
                {
                    b_qEnd = idx_data[b_kEnd - 1] + b_i;
                    if (fabs(zi_data[idx_data[((n - b_kEnd) + b_i2) - 1] + b_i]
                             + zi_data[b_qEnd]) > 2.2204460492503131E-14 *
                            absx_data[b_qEnd])
                    {
                        pairable = false;
                        exitg2 = true;
                    }
                    else
                    {
                        b_kEnd++;
                    }
                }

                if (!pairable)
                {
                    exitg1 = true;
                }
                else
                {
                    b_pEnd = d_j >> 1;
                    for (b_kEnd = 0; b_kEnd < b_pEnd; b_kEnd++)
                    {
                        i_k = ((b_kEnd + 1) << 1) + b_i;
                        b_qEnd = idx_data[(n - b_kEnd) - 1] + b_i;
                        absxk_tmp = zr_data[b_qEnd];
                        x_data[i_k - 1].re = absxk_tmp;
                        absxk_tmp_0 = zi_data[b_qEnd];
                        x_data[i_k - 1].im = -absxk_tmp_0;
                        x_data[i_k].re = absxk_tmp;
                        x_data[i_k].im = absxk_tmp_0;
                    }

                    n++;
                }
            }
        }
    }

    return pairable;
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_cplxpair_b(creal_T x_data[], const int32_T
    x_size[2])
{
    switch (x_size[1])
    {
      case 0:
        break;

      case 1:
        Model_TranslationEngine64_cplxpairv(x_data, x_size);
        break;

      default:
        {
            if (x_size[1] != 1)
            {
                Model_TranslationEngine64_cplxpairv(x_data, x_size);
            }
            else
            {
                creal_T vwork_data;
                real_T zi_data_idx_0;
                real_T zr_data_idx_0;
                int32_T nc;
                int32_T nr;
                vwork_data = x_data[0];
                nr = -1;
                nc = -1;
                if (fabs(x_data[0].im) <= 2.2204460492503131E-14 * rt_hypotd_snf
                        (x_data[0].re, x_data[0].im))
                {
                    nr = 0;
                    zr_data_idx_0 = x_data[0].re;
                    zi_data_idx_0 = 0.0;
                }
                else
                {
                    nc = 0;
                    zr_data_idx_0 = x_data[0].re;
                    zi_data_idx_0 = x_data[0].im;
                }

                if (nr >= 0)
                {
                    vwork_data.re = zr_data_idx_0;
                    vwork_data.im = 0.0;
                }

                if (nc >= 0)
                {
                    vwork_data.re = zr_data_idx_0;
                    vwork_data.im = zi_data_idx_0;
                }

                x_data[0] = vwork_data;
            }
        }
        break;
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_abs(const real_T x_data[], const int32_T
    x_size[2], real_T y_data[], int32_T y_size[2])
{
    int32_T b;
    int32_T k;
    y_size[0] = 1;
    y_size[1] = x_size[1];
    b = x_size[1];
    for (k = 0; k < b; k++)
    {
        y_data[k] = fabs(x_data[k]);
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_eml_find(const boolean_T x_data[], const
    int32_T x_size[2], int32_T i_data[], int32_T i_size[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    idx = 0;
    i_size[0] = 1;
    i_size[1] = x_size[1];
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= x_size[1] - 1))
    {
        if (x_data[ii])
        {
            idx++;
            i_data[idx - 1] = ii + 1;
            if (idx >= x_size[1])
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

    if (x_size[1] == 1)
    {
        if (idx == 0)
        {
            i_size[0] = 1;
            i_size[1] = 0;
        }
    }
    else if (idx < 1)
    {
        i_size[1] = 0;
    }
    else
    {
        i_size[1] = idx;
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_nullAssignment(real_T x_data[], int32_T
    x_size[2], const int32_T idx_data[], const int32_T idx_size[2])
{
    int32_T b_size_idx_1;
    int32_T c;
    int32_T e;
    int32_T k0;
    int32_T nxout;
    boolean_T b_data[20];
    b_size_idx_1 = x_size[1];
    nxout = x_size[1];
    if (nxout - 1 >= 0)
    {
        memset(&b_data[0], 0, (uint32_T)nxout * sizeof(boolean_T));
    }

    e = idx_size[1];
    for (nxout = 0; nxout < e; nxout++)
    {
        b_data[idx_data[nxout] - 1] = true;
    }

    nxout = 0;
    for (e = 0; e < b_size_idx_1; e++)
    {
        nxout += b_data[e];
    }

    nxout = x_size[1] - nxout;
    k0 = -1;
    c = x_size[1];
    for (e = 0; e < c; e++)
    {
        if ((e + 1 > b_size_idx_1) || (!b_data[e]))
        {
            k0++;
            x_data[k0] = x_data[e];
        }
    }

    if (nxout < 1)
    {
        x_size[1] = 0;
    }
    else
    {
        x_size[1] = nxout;
    }
}

static void Model_TranslationEngine64_binary_expand_op_j5plg(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 :
        div_s32(in7 - in5, in6) + 1;
    stride_0_1 = (div_s32(in4, in3) + 1 != 1);
    stride_1_1 = (div_s32(in7 - in5, in6) + 1 != 1);
    loop_ub = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 : div_s32
        (in7 - in5, in6) + 1;
    for (i = 0; i < loop_ub; i++)
    {
        in1_data[i] = -in2_data[i * stride_0_1 * in3] - in2_data[i * stride_1_1 *
            in6 + in5];
    }
}

static void Model_TranslationEngine64_binary_expand_op_j5pl(real_T in1_data[],
    int32_T in1_size[2], const real_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 :
        div_s32(in7 - in5, in6) + 1;
    stride_0_1 = (div_s32(in4, in3) + 1 != 1);
    stride_1_1 = (div_s32(in7 - in5, in6) + 1 != 1);
    loop_ub = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 : div_s32
        (in7 - in5, in6) + 1;
    for (i = 0; i < loop_ub; i++)
    {
        in1_data[i] = in2_data[i * stride_1_1 * in6 + in5] * in2_data[i *
            stride_0_1 * in3];
    }
}

static void Model_TranslationEngine64_binary_expand_op_j5p(real_T in1_data[],
    int32_T in1_size[2], const creal_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 :
        div_s32(in7 - in5, in6) + 1;
    stride_0_1 = (div_s32(in4, in3) + 1 != 1);
    stride_1_1 = (div_s32(in7 - in5, in6) + 1 != 1);
    loop_ub = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 : div_s32
        (in7 - in5, in6) + 1;
    for (i = 0; i < loop_ub; i++)
    {
        in1_data[i] = -in2_data[i * stride_0_1 * in3].re - in2_data[i *
            stride_1_1 * in6 + in5].re;
    }
}

static void Model_TranslationEngine64_binary_expand_op_j5(real_T in1_data[],
    int32_T in1_size[2], const creal_T in2_data[], int32_T in3, int32_T in4,
    int32_T in5, int32_T in6, int32_T in7)
{
    int32_T i;
    int32_T loop_ub;
    int32_T stride_0_1;
    int32_T stride_1_1;
    in1_size[0] = 1;
    in1_size[1] = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 :
        div_s32(in7 - in5, in6) + 1;
    stride_0_1 = (div_s32(in4, in3) + 1 != 1);
    stride_1_1 = (div_s32(in7 - in5, in6) + 1 != 1);
    loop_ub = div_s32(in7 - in5, in6) + 1 == 1 ? div_s32(in4, in3) + 1 : div_s32
        (in7 - in5, in6) + 1;
    for (i = 0; i < loop_ub; i++)
    {
        int32_T tmp;
        tmp = i * stride_1_1 * in6 + in5;
        in1_data[i] = in2_data[i * stride_0_1 * in3].re * in2_data[tmp].re -
            in2_data[i * stride_0_1 * in3].im * in2_data[tmp].im;
    }
}

/* Function for MATLAB Function: '<S1385>/Translation' */
static void Model_TranslationEngine64_abs_h(const creal_T x_data[], const
    int32_T x_size[2], real_T y_data[], int32_T y_size[2])
{
    int32_T b;
    int32_T k;
    y_size[0] = 1;
    y_size[1] = x_size[1];
    b = x_size[1];
    for (k = 0; k < b; k++)
    {
        y_data[k] = rt_hypotd_snf(x_data[k].re, x_data[k].im);
    }
}

/*
 * Function for MATLAB Function: '<S1385>/Translation'
 * function [sos,g] = zp2sos(z,p,g)
 */
static void Model_TranslationEngine64_zp2sos(real_T z_data[], int32_T z_size[2],
    creal_T p_data[], const int32_T p_size[2], real_T g, real_T sos_data[],
    int32_T sos_size[2])
{
    __m128d tmp;
    creal_T pr_temp_data[40];
    creal_T p_conj_data[20];
    creal_T p_real_data[20];
    creal_T pc_data[20];
    real_T zr_temp_data[40];
    real_T prms_data[21];
    real_T prp_data[21];
    real_T zrms_data[21];
    real_T zrp_data[21];
    real_T ind_complement_data[20];
    real_T ind_data[20];
    real_T tmp_data[20];
    real_T z_real_data[20];
    real_T zcm2r_data[20];
    real_T nprsec;
    real_T nzrsec;
    real_T varargin_1;
    int32_T ind_data_0[20];
    int32_T ind_complement_size[2];
    int32_T ind_size[2];
    int32_T pc_size[2];
    int32_T tmp_size[2];
    int32_T tmp_size_0[2];
    int32_T zc_size[2];
    int32_T c;
    int32_T d;
    int32_T e;
    int32_T f;
    int32_T loop_ub;
    int32_T npc;
    int32_T npr;
    int32_T nzc;
    int32_T nzr;
    int32_T p_real_size_idx_1;
    int32_T y_size_idx_1;
    int32_T z_real_size_idx_1;
    int8_T y_data[20];
    boolean_T tmp_data_0[20];

    /*  The zp2sos Function stated below supports code generation!  */
    /*  Most of the code is scripted refering to the Matlab's zp2sos.m and */
    /*  https://searchcode.com/codesearch/view/9505959/  */
    /*  Integration of two codes was majorily required due to cplxreal function  */
    /*  which is no more supported in Matlab Scripts.  */
    /* '<S1387>:1:154' if nargin < 3 */
    /* '<S1387>:1:157' if nargin < 2 */
    /*  Sort the numbers z into complex-conjugate-valued and real-valued elements. */
    /*  The positive imaginary complex numbers of each complex conjugate pair  */
    /*  are returned in zc and the real numbers are returned in zr. */
    /*  pair up the conjugate poles and zeros using cplxpair */
    /* '<S1387>:1:166' z = cplxpair(z); */
    Model_TranslationEngine64_cplxpair(z_data, z_size);

    /* '<S1387>:1:167' p = cplxpair(p); */
    Model_TranslationEngine64_cplxpair_b(p_data, p_size);

    /*  Get the number of poles and zeros */
    /* '<S1387>:1:170' lz = length(z); */
    /* '<S1387>:1:171' lp = length(p); */
    /* '<S1387>:1:173' ind = find(abs(imag(p)) > 0); */
    ind_size[0] = 1;
    ind_size[1] = p_size[1];
    loop_ub = p_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        ind_data[d] = p_data[d].im;
    }

    Model_TranslationEngine64_abs(ind_data, ind_size, tmp_data, tmp_size);
    tmp_size_0[0] = 1;
    tmp_size_0[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        tmp_data_0[d] = (tmp_data[d] > 0.0);
    }

    Model_TranslationEngine64_eml_find(tmp_data_0, tmp_size_0, ind_data_0,
        tmp_size);
    ind_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        ind_data[d] = ind_data_0[d];
    }

    /* '<S1387>:1:174' p_conj = p(ind); */
    npr = tmp_size[1];
    loop_ub = tmp_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        p_conj_data[d] = p_data[(int32_T)ind_data[d] - 1];
    }

    /*  poles that have conjugate pairs */
    /* '<S1387>:1:176' coder.varsize('ind_complement'); */
    /* '<S1387>:1:177' B = p_conj(imag(p_conj) >= 0); */
    /* '<S1387>:1:178' ind_complement = 1:lp; */
    if (p_size[1] < 1)
    {
        ind_complement_size[0] = 1;
        ind_complement_size[1] = 0;
    }
    else
    {
        ind_complement_size[0] = 1;
        ind_complement_size[1] = p_size[1];
        loop_ub = p_size[1] - 1;
        for (d = 0; d <= loop_ub; d++)
        {
            ind_complement_data[d] = (real_T)d + 1.0;
        }
    }

    /* '<S1387>:1:179' if ~isempty(ind) */
    if (tmp_size[1] != 0)
    {
        /* '<S1387>:1:180' ind_complement(ind) = []; */
        tmp_size[0] = 1;
        loop_ub = ind_size[1];
        for (d = 0; d < loop_ub; d++)
        {
            ind_data_0[d] = (int32_T)ind_data[d];
        }

        Model_TranslationEngine64_nullAssignment(ind_complement_data,
            ind_complement_size, ind_data_0, tmp_size);
    }

    /* '<S1387>:1:182' p_real = p(ind_complement); */
    p_real_size_idx_1 = ind_complement_size[1];
    loop_ub = ind_complement_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        p_real_data[d] = p_data[(int32_T)ind_complement_data[d] - 1];
    }

    /*  poles that are real */
    /*  break up conjugate pairs and real zeros */
    /* '<S1387>:1:185' ind = find(abs(imag(z)) > 0); */
    ind_size[0] = 1;
    ind_size[1] = z_size[1];
    loop_ub = z_size[1];
    if (loop_ub - 1 >= 0)
    {
        memset(&ind_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
    }

    Model_TranslationEngine64_abs(ind_data, ind_size, tmp_data, tmp_size);
    tmp_size_0[0] = 1;
    tmp_size_0[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        tmp_data_0[d] = (tmp_data[d] > 0.0);
    }

    Model_TranslationEngine64_eml_find(tmp_data_0, tmp_size_0, ind_data_0,
        tmp_size);
    ind_size[1] = tmp_size[1];
    loop_ub = tmp_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        ind_data[d] = ind_data_0[d];
    }

    /* '<S1387>:1:186' z_conj = z(ind); */
    /*  zeros that have conjugate pairs */
    /* '<S1387>:1:187' C = z_conj(imag(z_conj) >= 0); */
    /* '<S1387>:1:188' ind_complement = 1:lz; */
    if (z_size[1] < 1)
    {
        ind_complement_size[0] = 1;
        ind_complement_size[1] = 0;
    }
    else
    {
        ind_complement_size[0] = 1;
        ind_complement_size[1] = z_size[1];
        loop_ub = z_size[1] - 1;
        for (d = 0; d <= loop_ub; d++)
        {
            ind_complement_data[d] = (real_T)d + 1.0;
        }
    }

    /* '<S1387>:1:189' if ~isempty(ind) */
    if (tmp_size[1] != 0)
    {
        /* '<S1387>:1:190' ind_complement(ind) = []; */
        tmp_size[0] = 1;
        loop_ub = ind_size[1];
        for (d = 0; d < loop_ub; d++)
        {
            ind_data_0[d] = (int32_T)ind_data[d];
        }

        Model_TranslationEngine64_nullAssignment(ind_complement_data,
            ind_complement_size, ind_data_0, tmp_size);
    }

    /* '<S1387>:1:192' z_real = z(ind_complement); */
    z_real_size_idx_1 = ind_complement_size[1];
    loop_ub = ind_complement_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        z_real_data[d] = z_data[(int32_T)ind_complement_data[d] - 1];
    }

    /* '<S1387>:1:194' zr = z_real; */
    /*  zeroes that are real */
    /* '<S1387>:1:195' pr = p_real ; */
    /*  poles that are real */
    /* '<S1387>:1:196' pc = B; */
    nzc = npr - 1;
    npc = 0;
    for (npr = 0; npr <= nzc; npr++)
    {
        if (p_conj_data[npr].im >= 0.0)
        {
            npc++;
        }
    }

    pc_size[0] = 1;
    pc_size[1] = npc;
    npc = 0;
    for (npr = 0; npr <= nzc; npr++)
    {
        nzrsec = p_conj_data[npr].im;
        if (nzrsec >= 0.0)
        {
            pc_data[npc].re = p_conj_data[npr].re;
            pc_data[npc].im = nzrsec;
            npc++;
        }
    }

    /*  positive conjugate poles */
    /* '<S1387>:1:197' zc = C ; */
    nzc = ind_size[1];
    npc = 0;
    for (npr = 0; npr < nzc; npr++)
    {
        npc++;
    }

    y_size_idx_1 = npc;
    for (npr = 0; npr < nzc; npr++)
    {
        y_data[npr] = (int8_T)(npr + 1);
    }

    zc_size[0] = 1;
    zc_size[1] = npc;
    for (d = 0; d < npc; d++)
    {
        ind_complement_data[d] = z_data[(int32_T)ind_data[y_data[d] - 1] - 1];
    }

    /*  positive conjugate zeros */
    /*  zc,zr,pc,pr found */
    /* '<S1387>:1:201' nzc = length(zc); */
    nzc = npc;

    /* '<S1387>:1:202' npc = length(pc); */
    npc = pc_size[1];

    /* '<S1387>:1:204' nzr = length(zr); */
    nzr = ind_complement_size[1] - 1;

    /* '<S1387>:1:205' npr = length(pr); */
    npr = p_real_size_idx_1 - 1;

    /*  Pair up real zeros: */
    /* '<S1387>:1:208' if nzr */
    if (ind_complement_size[1] != 0)
    {
        /* '<S1387>:1:209' if mod(nzr,2)==1 */
        if (fmod(ind_complement_size[1], 2.0) == 1.0)
        {
            /* '<S1387>:1:210' zr_temp = [zr;0]; */
            ind_size[0] = 2;
            ind_size[1] = 1;
            zr_temp_data[0] = z_real_data[0];
            zr_temp_data[1] = 0.0;

            /* '<S1387>:1:211' nzr = nzr+1; */
            nzr = ind_complement_size[1];
        }
        else
        {
            /* '<S1387>:1:212' else */
            /* '<S1387>:1:213' zr_temp = zr; */
            ind_size[0] = 1;
            ind_size[1] = ind_complement_size[1];
            if (z_real_size_idx_1 - 1 >= 0)
            {
                memcpy(&zr_temp_data[0], &z_real_data[0], (uint32_T)
                       z_real_size_idx_1 * sizeof(real_T));
            }
        }

        /* '<S1387>:1:215' nzrsec = nzr/2; */
        nzrsec = ((real_T)nzr + 1.0) / 2.0;

        /* '<S1387>:1:216' zrms = real(-zr_temp(1:2:nzr-1) - zr_temp(2:2:nzr)); */
        if (nzr < 1)
        {
            c = 1;
            z_real_size_idx_1 = -1;
            f = 0;
            e = 1;
            d = -1;
        }
        else
        {
            c = 2;
            z_real_size_idx_1 = nzr - 1;
            f = 1;
            e = 2;
            d = nzr;
        }

        loop_ub = div_s32(z_real_size_idx_1, c);
        if (div_s32(d - f, e) + 1 == loop_ub + 1)
        {
            for (d = 0; d <= loop_ub; d++)
            {
                zrms_data[d] = -zr_temp_data[c * d] - zr_temp_data[e * d + f];
            }
        }
        else
        {
            Model_TranslationEngine64_binary_expand_op_j5plg(zrms_data, ind_size,
                zr_temp_data, c, z_real_size_idx_1, f, e, d);
        }

        /* '<S1387>:1:217' zrp = real(zr_temp(1:2:nzr-1) .* zr_temp(2:2:nzr)); */
        if (nzr < 1)
        {
            c = 1;
            z_real_size_idx_1 = -1;
            f = 0;
            e = 1;
            nzr = -1;
        }
        else
        {
            c = 2;
            z_real_size_idx_1 = nzr - 1;
            f = 1;
            e = 2;
        }

        loop_ub = div_s32(z_real_size_idx_1, c);
        if (div_s32(nzr - f, e) + 1 == loop_ub + 1)
        {
            for (d = 0; d <= loop_ub; d++)
            {
                zrp_data[d] = zr_temp_data[e * d + f] * zr_temp_data[c * d];
            }
        }
        else
        {
            Model_TranslationEngine64_binary_expand_op_j5pl(zrp_data, ind_size,
                zr_temp_data, c, z_real_size_idx_1, f, e, nzr);
        }
    }
    else
    {
        /* '<S1387>:1:218' else */
        /* '<S1387>:1:219' nzrsec = 0; */
        nzrsec = 0.0;

        /* '<S1387>:1:220' zrms = 0; */
        zrms_data[0] = 0.0;

        /* '<S1387>:1:221' zrp = 0; */
        zrp_data[0] = 0.0;
    }

    /*  Pair up real poles: */
    /* '<S1387>:1:225' if npr */
    if (p_real_size_idx_1 != 0)
    {
        /* '<S1387>:1:226' if mod(npr,2) == 1 */
        if (fmod(p_real_size_idx_1, 2.0) == 1.0)
        {
            /* '<S1387>:1:227' pr_temp = [pr;0]; */
            pr_temp_data[0] = p_real_data[0];
            pr_temp_data[1].re = 0.0;
            pr_temp_data[1].im = 0.0;

            /* '<S1387>:1:228' npr = npr+1; */
            npr = p_real_size_idx_1;
        }
        else
        {
            /* '<S1387>:1:229' else */
            /* '<S1387>:1:230' pr_temp = pr; */
            memcpy(&pr_temp_data[0], &p_real_data[0], (uint32_T)
                   p_real_size_idx_1 * sizeof(creal_T));
        }

        /* '<S1387>:1:232' nprsec = npr/2; */
        nprsec = ((real_T)npr + 1.0) / 2.0;

        /* '<S1387>:1:233' prms = real(-pr_temp(1:2:npr-1) - pr_temp(2:2:npr)); */
        if (npr < 1)
        {
            nzr = 1;
            c = -1;
            z_real_size_idx_1 = 0;
            f = 1;
            e = -1;
        }
        else
        {
            nzr = 2;
            c = npr - 1;
            z_real_size_idx_1 = 1;
            f = 2;
            e = npr;
        }

        loop_ub = div_s32(c, nzr);
        if (div_s32(e - z_real_size_idx_1, f) + 1 == loop_ub + 1)
        {
            for (d = 0; d <= loop_ub; d++)
            {
                prms_data[d] = -pr_temp_data[nzr * d].re - pr_temp_data[f * d +
                    z_real_size_idx_1].re;
            }
        }
        else
        {
            Model_TranslationEngine64_binary_expand_op_j5p(prms_data, ind_size,
                pr_temp_data, nzr, c, z_real_size_idx_1, f, e);
        }

        /* '<S1387>:1:234' prp = real(pr_temp(1:2:npr-1) .* pr_temp(2:2:npr)); */
        if (npr < 1)
        {
            nzr = 1;
            c = -1;
            z_real_size_idx_1 = 0;
            f = 1;
            npr = -1;
        }
        else
        {
            nzr = 2;
            c = npr - 1;
            z_real_size_idx_1 = 1;
            f = 2;
        }

        loop_ub = div_s32(c, nzr);
        if (div_s32(npr - z_real_size_idx_1, f) + 1 == loop_ub + 1)
        {
            for (d = 0; d <= loop_ub; d++)
            {
                npr = f * d + z_real_size_idx_1;
                c = nzr * d;
                prp_data[d] = pr_temp_data[npr].re * pr_temp_data[c].re -
                    pr_temp_data[npr].im * pr_temp_data[c].im;
            }
        }
        else
        {
            Model_TranslationEngine64_binary_expand_op_j5(prp_data, ind_size,
                pr_temp_data, nzr, c, z_real_size_idx_1, f, npr);
        }
    }
    else
    {
        /* '<S1387>:1:235' else */
        /* '<S1387>:1:236' nprsec = 0; */
        nprsec = 0.0;

        /* '<S1387>:1:237' prp = 0; */
        prp_data[0] = 0.0;

        /* '<S1387>:1:238' prms = 0; */
        prms_data[0] = 0.0;
    }

    /* '<S1387>:1:241' nsecs = max(ceil(lz/2), ceil(lp/2)); */
    npr = (int32_T)fmax(ceil((real_T)z_size[1] / 2.0), ceil((real_T)p_size[1] /
                         2.0));

    /*  Convert complex zeros and poles to real 2nd-order section form: */
    /* '<S1387>:1:244' zcm2r = -2*real(zc); */
    loop_ub = zc_size[1];
    nzr = (zc_size[1] / 2) << 1;
    z_real_size_idx_1 = nzr - 2;
    for (d = 0; d <= z_real_size_idx_1; d += 2)
    {
        tmp = _mm_loadu_pd(&ind_complement_data[d]);
        _mm_storeu_pd(&zcm2r_data[d], _mm_mul_pd(_mm_set1_pd(-2.0), tmp));
    }

    for (d = nzr; d < loop_ub; d++)
    {
        zcm2r_data[d] = -2.0 * ind_complement_data[d];
    }

    /* '<S1387>:1:245' zca2 = abs(zc) .^ 2; */
    Model_TranslationEngine64_abs(ind_complement_data, zc_size, tmp_data,
        tmp_size);
    loop_ub = tmp_size[1];
    nzr = (tmp_size[1] / 2) << 1;
    z_real_size_idx_1 = nzr - 2;
    for (d = 0; d <= z_real_size_idx_1; d += 2)
    {
        tmp = _mm_loadu_pd(&tmp_data[d]);
        _mm_storeu_pd(&ind_complement_data[d], _mm_mul_pd(tmp, tmp));
    }

    for (d = nzr; d < loop_ub; d++)
    {
        varargin_1 = tmp_data[d];
        ind_complement_data[d] = varargin_1 * varargin_1;
    }

    /* '<S1387>:1:246' pcm2r = -2 * real(pc); */
    loop_ub = pc_size[1];
    for (d = 0; d < loop_ub; d++)
    {
        z_real_data[d] = -2.0 * pc_data[d].re;
    }

    /* '<S1387>:1:247' pca2 = abs(pc) .^ 2; */
    Model_TranslationEngine64_abs_h(pc_data, pc_size, tmp_data, tmp_size);
    loop_ub = tmp_size[1];
    nzr = (tmp_size[1] / 2) << 1;
    z_real_size_idx_1 = nzr - 2;
    for (d = 0; d <= z_real_size_idx_1; d += 2)
    {
        tmp = _mm_loadu_pd(&tmp_data[d]);
        _mm_storeu_pd(&ind_data[d], _mm_mul_pd(tmp, tmp));
    }

    for (d = nzr; d < loop_ub; d++)
    {
        varargin_1 = tmp_data[d];
        ind_data[d] = varargin_1 * varargin_1;
    }

    /* '<S1387>:1:249' sos = zeros(nsecs, 6); */
    sos_size[0] = npr;
    sos_size[1] = 6;
    loop_ub = npr * 6;
    if (loop_ub - 1 >= 0)
    {
        memset(&sos_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
    }

    /* '<S1387>:1:250' sos(:,1) = ones(nsecs, 1); */
    for (d = 0; d < npr; d++)
    {
        sos_data[d] = 1.0;
    }

    /*  all 2nd-order polynomials are monic */
    /* '<S1387>:1:251' sos(end,1) = g*sos(end, 1); */
    sos_data[npr - 1] *= g;

    /* '<S1387>:1:252' sos(:,4) = ones(nsecs, 1); */
    for (d = 0; d < npr; d++)
    {
        sos_data[d + npr * 3] = 1.0;
    }

    /* '<S1387>:1:254' nzrl = nzc + nzrsec; */
    nzrsec += (real_T)y_size_idx_1;

    /*  index of last real zero section */
    /* '<S1387>:1:255' nprl = npc + nprsec; */
    nprsec += (real_T)pc_size[1];

    /*  index of last real pole section */
    /* '<S1387>:1:257' for i = 1:nsecs */
    for (nzr = 0; nzr < npr; nzr++)
    {
        /* '<S1387>:1:259' if i <= nzc */
        if (nzr + 1 <= nzc)
        {
            /*  lay down a complex zero pair: */
            /* '<S1387>:1:260' sos(i,2:3) = [zcm2r(i) zca2(i)]; */
            sos_data[nzr + npr] = zcm2r_data[nzr];
            sos_data[nzr + (npr << 1)] = ind_complement_data[nzr];

            /* '<S1387>:1:261' sos(end,2:3) = g*sos(end,2:3); */
            d = (npr + npr) - 1;
            sos_data[d] *= g;
            d = ((npr << 1) + npr) - 1;
            sos_data[d] *= g;
        }
        else if ((real_T)nzr + 1.0 <= nzrsec)
        {
            /* '<S1387>:1:262' elseif i <= nzrl */
            /*  lay down a pair of real zeros: */
            /* '<S1387>:1:263' sos(i,2:3) = [zrms(i-nzc) zrp(i-nzc)]; */
            d = nzr - nzc;
            sos_data[nzr + npr] = zrms_data[d];
            sos_data[nzr + (npr << 1)] = zrp_data[d];

            /* '<S1387>:1:264' sos(end,2:3) = g*sos(end,2:3); */
            d = (npr + npr) - 1;
            sos_data[d] *= g;
            d = ((npr << 1) + npr) - 1;
            sos_data[d] *= g;
        }

        /* '<S1387>:1:267' if i <= npc */
        if (nzr + 1 <= npc)
        {
            /*  lay down a complex pole pair: */
            /* '<S1387>:1:268' sos(i,5:6) = [pcm2r(i) pca2(i)]; */
            sos_data[nzr + (npr << 2)] = z_real_data[nzr];
            sos_data[nzr + npr * 5] = ind_data[nzr];
        }
        else if ((real_T)nzr + 1.0 <= nprsec)
        {
            /* '<S1387>:1:269' elseif i <= nprl */
            /*  lay down a pair of real poles: */
            /* '<S1387>:1:270' sos(i,5:6) = [prms(i-npc) prp(i-npc)]; */
            d = nzr - npc;
            sos_data[nzr + (npr << 2)] = prms_data[d];
            sos_data[nzr + npr * 5] = prp_data[d];
        }
    }
}

/* Output and update for function-call system: '<S1386>/tfunc' */
void FuncTranslation_Model_1234(void)
{
    creal_T p_data[20];
    creal_T p[10];
    creal_T x_data[10];
    real_T rawSOSHighPass_data[240];
    real_T ChannelCoeffs[161];
    real_T sosHighPass_data[60];
    real_T halfZ_data_0[20];
    real_T frequency;
    real_T order;
    real_T sp_im;
    real_T sp_re;
    int32_T j_data[41];
    int32_T b_vlen;
    int32_T c_k;
    int32_T iacol;
    int32_T ibcol;
    int32_T ibmat;
    int32_T nrows;
    real32_T ChannelSOS[240];
    uint32_T SOSIndex;
    int16_T ts_data[10];
    char_T k_data[65];
    int8_T h_data[10];
    int8_T halfZ_data[10];
    uint8_T y_data[41];
    boolean_T b_x_data[10];
    static const char_T v[65] =
        "Poorly-formed SOS: zero b0 for multi-stage results in a zero EQ.";
    real_T sp_re_tmp_tmp;
    int32_T halfZ_size[2];
    int32_T p_size[2];
    int32_T sosHighPass_size[2];
    int32_T halfZ_size_idx_1;
    int32_T x_size_idx_1;

    /* MATLAB Function: '<S1385>/Translation' */
    /* MATLAB Function: '<S1385>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1385>/HpfCutOffTuneVar'
     *  S-Function (TuneVarMEX): '<S1385>/HpfOrderTuneVar'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1388>:1' */
    /* '<S1388>:1:3' f(); */
    /* MATLAB Function 'NEAR/Near1p1/NearBandSplit/HighpassFilter/Translation': '<S1387>:1' */
    /* '<S1387>:1:3' MAX_HPF_ORDER = 10; */
    /* '<S1387>:1:4' MAX_NUM_CHANNELS = 4; */
    /* '<S1387>:1:5' IIR_HIGHPASS = 1; */
    /*  Linkwitz-Riley Filters can be construed as the cascade of */
    /*  two Butterworth Filters of half the order at the same frequency. */
    /* '<S1387>:1:9' filterOrder = order.Value; */
    /* '<S1387>:1:10' butterOrder = floor((filterOrder+1)/2); */
    order = floor((Model_TranslationEngine64_B.HpfFilterOrder.Value + 1.0) / 2.0);

    /* '<S1387>:1:11' normFrequency = crossOverFrequency.Value/(sampleRate/2); */
    frequency = Model_TranslationEngine64_B.HpfCutoffFrequency.Value /
        (Model_TranslationEngine64_ConstB.SampleRateCapConst / 2.0);

    /*  High-pass Filters */
    /* '<S1387>:1:14' [halfZ, halfP, halfK] = CalcButterworth(butterOrder,normFrequency,IIR_HIGHPASS); */
    /* '<S1387>:1:108' MAX_HPF_ORDER = 10; */
    /* '<S1387>:1:109' IIR_HIGHPASS = 1; */
    /* '<S1387>:1:111' if order > MAX_HPF_ORDER */
    if (order > 10.0)
    {
        /* '<S1387>:1:112' order = MAX_HPF_ORDER; */
        order = 10.0;
    }

    /*  zeros first */
    /* '<S1387>:1:116' z = zeros(1,order); */
    ibmat = (int32_T)order;

    /* '<S1387>:1:117' if filterType == IIR_HIGHPASS */
    /* '<S1387>:1:118' z(1:order) = ones(1,min(order,MAX_HPF_ORDER)); */
    if ((int32_T)order - 1 >= 0)
    {
        memset(&halfZ_data[0], 1, (uint32_T)(int32_T)order * sizeof(int8_T));
    }

    /* '<S1387>:1:125' p = complex(zeros(1,MAX_HPF_ORDER)); */
    memset(&p[0], 0, 10U * sizeof(creal_T));

    /* '<S1387>:1:126' for n = 1:order */
    for (nrows = 0; nrows < ibmat; nrows++)
    {
        real_T sp_im_tmp;

        /* '<S1387>:1:127' if n == (order+1)/2 */
        if ((order + 1.0) / 2.0 == (real_T)nrows + 1.0)
        {
            /* '<S1387>:1:128' sp = -pi*frequency; */
            sp_re = -3.1415926535897931 * frequency;
            sp_im = 0.0;
        }
        else
        {
            /* '<S1387>:1:129' else */
            /* '<S1387>:1:130' sp_real = pi*frequency*cos(((2*n+order-1)*pi)/(2*order)); */
            /* '<S1387>:1:131' sp_imag = pi*frequency*sin(((2*n+order-1)*pi)/(2*order)); */
            /* '<S1387>:1:132' sp = sp_real + 1i*sp_imag; */
            sp_re_tmp_tmp = ((((real_T)nrows + 1.0) * 2.0 + order) - 1.0) *
                3.1415926535897931 / (2.0 * order);
            sp_re = 3.1415926535897931 * frequency * cos(sp_re_tmp_tmp);
            sp_im = 3.1415926535897931 * frequency * sin(sp_re_tmp_tmp);
        }

        /* '<S1387>:1:135' p(n) = (1+sp/2)/(1-sp/2); */
        if (sp_im == 0.0)
        {
            sp_re_tmp_tmp = sp_re / 2.0;
            sp_im_tmp = 0.0;
            sp_re = sp_re_tmp_tmp;
            sp_im = 0.0;
        }
        else if (sp_re == 0.0)
        {
            sp_re_tmp_tmp = 0.0;
            sp_im_tmp = sp_im / 2.0;
            sp_re = 0.0;
            sp_im = sp_im_tmp;
        }
        else
        {
            sp_re_tmp_tmp = sp_re / 2.0;
            sp_im_tmp = sp_im / 2.0;
            sp_re = sp_re_tmp_tmp;
            sp_im = sp_im_tmp;
        }

        if (0.0 - sp_im == 0.0)
        {
            if (sp_im_tmp == 0.0)
            {
                p[nrows].re = (sp_re_tmp_tmp + 1.0) / (1.0 - sp_re);
                p[nrows].im = 0.0;
            }
            else if (sp_re_tmp_tmp + 1.0 == 0.0)
            {
                p[nrows].re = 0.0;
                p[nrows].im = sp_im_tmp / (1.0 - sp_re);
            }
            else
            {
                p[nrows].re = (sp_re_tmp_tmp + 1.0) / (1.0 - sp_re);
                p[nrows].im = sp_im_tmp / (1.0 - sp_re);
            }
        }
        else if (1.0 - sp_re == 0.0)
        {
            if (sp_re_tmp_tmp + 1.0 == 0.0)
            {
                p[nrows].re = sp_im_tmp / (0.0 - sp_im);
                p[nrows].im = 0.0;
            }
            else if (sp_im_tmp == 0.0)
            {
                p[nrows].re = 0.0;
                p[nrows].im = -((sp_re_tmp_tmp + 1.0) / (0.0 - sp_im));
            }
            else
            {
                p[nrows].re = sp_im_tmp / (0.0 - sp_im);
                p[nrows].im = -((sp_re_tmp_tmp + 1.0) / (0.0 - sp_im));
            }
        }
        else
        {
            real_T bim;
            real_T brm;
            brm = fabs(1.0 - sp_re);
            bim = fabs(0.0 - sp_im);
            if (brm > bim)
            {
                brm = (0.0 - sp_im) / (1.0 - sp_re);
                sp_im = (0.0 - sp_im) * brm + (1.0 - sp_re);
                p[nrows].re = ((sp_re_tmp_tmp + 1.0) + brm * sp_im_tmp) / sp_im;
                p[nrows].im = (sp_im_tmp - (sp_re_tmp_tmp + 1.0) * brm) / sp_im;
            }
            else if (bim == brm)
            {
                sp_re = 1.0 - sp_re > 0.0 ? 0.5 : -0.5;
                sp_im = 0.0 - sp_im > 0.0 ? 0.5 : -0.5;
                p[nrows].re = ((sp_re_tmp_tmp + 1.0) * sp_re + sp_im_tmp * sp_im)
                    / brm;
                p[nrows].im = (sp_im_tmp * sp_re - (sp_re_tmp_tmp + 1.0) * sp_im)
                    / brm;
            }
            else
            {
                brm = (1.0 - sp_re) / (0.0 - sp_im);
                sp_im = (1.0 - sp_re) * brm + (0.0 - sp_im);
                p[nrows].re = ((sp_re_tmp_tmp + 1.0) * brm + sp_im_tmp) / sp_im;
                p[nrows].im = (brm * sp_im_tmp - (sp_re_tmp_tmp + 1.0)) / sp_im;
            }
        }
    }

    /* '<S1387>:1:138' z = z(1:order); */
    if (order < 1.0)
    {
        halfZ_size_idx_1 = 0;
        ibmat = -1;
        iacol = -1;
    }
    else
    {
        halfZ_size_idx_1 = (int32_T)order;
        ibmat = (int32_T)order - 1;
        iacol = (int32_T)order - 1;
    }

    /* '<S1387>:1:139' p = p(1:order); */
    nrows = iacol + 1;

    /* '<S1387>:1:141' if filterType == IIR_HIGHPASS */
    /* '<S1387>:1:142' k = real(prod((1+p(1:order))/2)); */
    if (order < 1.0)
    {
        b_vlen = -1;
    }
    else
    {
        b_vlen = (int32_T)order - 1;
    }

    x_size_idx_1 = b_vlen + 1;
    for (iacol = 0; iacol <= b_vlen; iacol++)
    {
        sp_im = p[iacol].re + 1.0;
        order = p[iacol].im;
        if (order == 0.0)
        {
            x_data[iacol].re = sp_im / 2.0;
            x_data[iacol].im = 0.0;
        }
        else if (sp_im == 0.0)
        {
            x_data[iacol].re = 0.0;
            x_data[iacol].im = order / 2.0;
        }
        else
        {
            x_data[iacol].re = sp_im / 2.0;
            x_data[iacol].im = order / 2.0;
        }
    }

    if (b_vlen + 1 == 0)
    {
        sp_re = 1.0;
    }
    else
    {
        sp_re = x_data[0].re;
        sp_im = x_data[0].im;
        for (iacol = 2; iacol <= x_size_idx_1; iacol++)
        {
            order = x_data[iacol - 1].re;
            frequency = x_data[iacol - 1].im;
            sp_re_tmp_tmp = frequency * sp_re + order * sp_im;
            sp_re = order * sp_re - frequency * sp_im;
            sp_im = sp_re_tmp_tmp;
        }
    }

    /* '<S1387>:1:15' fullZ = [halfZ halfZ]; */
    /*  zeros */
    /* '<S1387>:1:16' fullP = [halfP halfP]; */
    /*  poles */
    /* '<S1387>:1:17' fullK = halfK*halfK; */
    /*  gain */
    /* '<S1387>:1:18' sosHighPass = zp2sos(fullZ,fullP,fullK); */
    halfZ_size[0] = 1;
    halfZ_size[1] = halfZ_size_idx_1 + halfZ_size_idx_1;
    for (iacol = 0; iacol < halfZ_size_idx_1; iacol++)
    {
        halfZ_data_0[iacol] = halfZ_data[iacol];
    }

    for (iacol = 0; iacol < halfZ_size_idx_1; iacol++)
    {
        halfZ_data_0[iacol + halfZ_size_idx_1] = halfZ_data[iacol];
    }

    p_size[0] = 1;
    p_size[1] = (ibmat + ibmat) + 2;
    if (nrows - 1 >= 0)
    {
        memcpy(&p_data[0], &p[0], (uint32_T)nrows * sizeof(creal_T));
    }

    for (iacol = 0; iacol < nrows; iacol++)
    {
        p_data[(iacol + ibmat) + 1] = p[iacol];
    }

    Model_TranslationEngine64_zp2sos(halfZ_data_0, halfZ_size, p_data, p_size,
        sp_re * sp_re, sosHighPass_data, sosHighPass_size);

    /*  Generate Linkwitz-Riley Pair Coefficients */
    /* '<S1387>:1:21' maxFilterOrder = MAX_HPF_ORDER; */
    /* '<S1387>:1:22' maxNumChannels = MAX_NUM_CHANNELS; */
    /* '<S1387>:1:23' numStages = uint32(size(sosHighPass, 1) * ones(1, maxNumChannels)); */
    /* '<S1387>:1:24' maxNumStages = maxFilterOrder * maxNumChannels; */
    /* '<S1387>:1:26' LRHighPassNumStages = uint32(zeros(maxNumChannels,1)); */
    /* '<S1387>:1:27' LRHighPassCoeffs = single(zeros((maxNumStages * 4 + maxNumChannels),1)); */
    /* '<S1387>:1:29' rawSOSHighPass = repmat(sosHighPass, 4, 1); */
    halfZ_size_idx_1 = (int8_T)(sosHighPass_size[0] << 2);
    nrows = sosHighPass_size[0];
    for (b_vlen = 0; b_vlen < 6; b_vlen++)
    {
        iacol = b_vlen * nrows;
        ibmat = (nrows << 2) * b_vlen - 1;
        for (x_size_idx_1 = 0; x_size_idx_1 < 4; x_size_idx_1++)
        {
            ibcol = (x_size_idx_1 * nrows + ibmat) + 1;
            for (c_k = 0; c_k < nrows; c_k++)
            {
                rawSOSHighPass_data[ibcol + c_k] = sosHighPass_data[iacol + c_k];
            }
        }
    }

    /* '<S1387>:1:30' [LRHighPassNumStages, LRHighPassCoeffs] = pooliirTranslation(rawSOSHighPass, numStages, maxNumStages, numChannels, maxNumChannels); */
    /* '<S1387>:1:36' RawSOS = rawSOS; */
    /* '<S1387>:1:37' NumStages = uint32(numStages); */
    /* '<S1387>:1:38' NumChannels = numChannels; */
    /* '<S1387>:1:40' MaxNumStages = maxNumStages; */
    /* '<S1387>:1:41' PoolNumStages = uint32(zeros(maxNumChannels,1)); */
    Model_TranslationEngine64_B.LRHighPassNumStages[0] = 0U;
    Model_TranslationEngine64_B.LRHighPassNumStages[1] = 0U;
    Model_TranslationEngine64_B.LRHighPassNumStages[2] = 0U;
    Model_TranslationEngine64_B.LRHighPassNumStages[3] = 0U;

    /* '<S1387>:1:42' PoolCoeffs = single(zeros(MaxNumStages * 4 + maxNumChannels,1)); */
    memset(&Model_TranslationEngine64_B.LRHighPassCoeffs[0], 0, 164U * sizeof
           (real32_T));

    /* '<S1387>:1:43' ChannelCoeffs = zeros(MaxNumStages * 4 + 1,1); */
    memset(&ChannelCoeffs[0], 0, 161U * sizeof(real_T));

    /* '<S1387>:1:44' ChannelSOS = single(zeros(MaxNumStages, 6)); */
    memset(&ChannelSOS[0], 0, 240U * sizeof(real32_T));

    /* '<S1387>:1:45' SOSIndex = uint32(0); */
    SOSIndex = 0U;

    /* '<S1387>:1:48' for i = 1:NumChannels */
    x_size_idx_1 = (int32_T)Model_TranslationEngine64_ConstB.NumChannelsCapConst;
    for (nrows = 0; nrows < x_size_idx_1; nrows++)
    {
        /* '<S1387>:1:50' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* '<S1387>:1:51' assert(ChannelNumStages <= MaxNumStages); */
        /* '<S1387>:1:53' if (ChannelNumStages == 0) */
        if (sosHighPass_size[0] != 0)
        {
            real32_T b_y;
            uint32_T offset;
            boolean_T c_y;
            boolean_T exitg1;

            /* '<S1387>:1:57' ChannelSOS(1:ChannelNumStages,:) = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            ibcol = sosHighPass_size[0];
            b_vlen = sosHighPass_size[0];
            for (iacol = 0; iacol < b_vlen; iacol++)
            {
                y_data[iacol] = (uint8_T)(iacol + 1);
            }

            for (ibmat = 0; ibmat < 6; ibmat++)
            {
                for (iacol = 0; iacol < ibcol; iacol++)
                {
                    ChannelSOS[iacol + 40 * ibmat] = (real32_T)
                        rawSOSHighPass_data[((int32_T)(y_data[iacol] + SOSIndex)
                        + halfZ_size_idx_1 * ibmat) - 1];
                }
            }

            /* '<S1387>:1:58' SOSIndex = SOSIndex + ChannelNumStages; */
            SOSIndex += (uint32_T)sosHighPass_size[0];

            /* '<S1387>:1:60' if size(ChannelSOS,2) ~= 6 */
            /*  decompose SOS */
            /* '<S1387>:1:65' ts = 1:4:4*ChannelNumStages; */
            b_vlen = (int32_T)((((uint32_T)sosHighPass_size[0] << 2) - 1U) >> 2)
                + 1;
            c_k = b_vlen;
            for (iacol = 0; iacol < b_vlen; iacol++)
            {
                ts_data[iacol] = (int16_T)(((uint32_T)iacol << 2) + 1U);
            }

            /* '<S1387>:1:66' ChannelCoeffs(1,1) = prod(ChannelSOS(1:ChannelNumStages,1)); */
            b_vlen = sosHighPass_size[0];
            b_y = ChannelSOS[0];
            for (iacol = 2; iacol <= b_vlen; iacol++)
            {
                b_y *= ChannelSOS[iacol - 1];
            }

            ChannelCoeffs[0] = b_y;

            /*  b0 */
            /*  Error out for poorly-formed sos coeffs */
            /* '<S1387>:1:69' if ((ChannelCoeffs(1,1) == 0) && (ChannelNumStages > 1)) */
            if ((b_y == 0.0F) && (sosHighPass_size[0] > 1))
            {
                /* '<S1387>:1:70' TranslateError('Poorly-formed SOS: zero b0 for multi-stage results in a zero EQ.'); */
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
                memcpy(&k_data[0], &v[0], 65U * sizeof(char_T));
                TranslateError(&k_data[0]);
            }

            /*  the remaining coeffs are compacted forms of the biquads */
            /* '<S1387>:1:74' ChannelCoeffs(1+ts,1) = ChannelSOS(1:ChannelNumStages,6); */
            b_vlen = sosHighPass_size[0];
            for (ibmat = 0; ibmat < b_vlen; ibmat++)
            {
                ChannelCoeffs[ts_data[ibmat]] = ChannelSOS[ibmat + 200];
            }

            /*  a2 */
            /* '<S1387>:1:75' ChannelCoeffs(2+ts,1) = ChannelSOS(1:ChannelNumStages,5); */
            b_vlen = sosHighPass_size[0];

            /*  a1 */
            /* '<S1387>:1:76' if( any(ChannelSOS(1:ChannelNumStages,1) == 0 )) */
            iacol = sosHighPass_size[0];
            for (ibmat = 0; ibmat < b_vlen; ibmat++)
            {
                ChannelCoeffs[ts_data[ibmat] + 1] = ChannelSOS[ibmat + 160];
                b_x_data[ibmat] = (ChannelSOS[ibmat] == 0.0F);
            }

            c_y = false;
            b_vlen = 1;
            exitg1 = false;
            while ((!exitg1) && (b_vlen <= iacol))
            {
                if (b_x_data[b_vlen - 1])
                {
                    c_y = true;
                    exitg1 = true;
                }
                else
                {
                    b_vlen++;
                }
            }

            if (c_y)
            {
                __m128i tmp;

                /* '<S1387>:1:77' ChannelCoeffs(3+ts,1) = 0; */
                for (ibmat = 0; ibmat < c_k; ibmat++)
                {
                    halfZ_data[ibmat] = (int8_T)ts_data[ibmat];
                }

                iacol = (c_k / 16) << 4;
                ibcol = iacol - 16;
                for (ibmat = 0; ibmat <= ibcol; ibmat += 16)
                {
                    tmp = _mm_loadu_si128((const __m128i *)&halfZ_data[ibmat]);
                    _mm_storeu_si128((__m128i *)&h_data[ibmat], _mm_add_epi8(tmp,
                                      _mm_set1_epi8(3)));
                }

                for (ibmat = iacol; ibmat < c_k; ibmat++)
                {
                    h_data[ibmat] = (int8_T)(halfZ_data[ibmat] + 3);
                }

                for (ibmat = 0; ibmat < c_k; ibmat++)
                {
                    ChannelCoeffs[h_data[ibmat] - 1] = 0.0;
                }

                /*  b2/b0 */
                /* '<S1387>:1:78' ChannelCoeffs(4+ts,1) = 0; */
                ibcol = iacol - 16;
                for (ibmat = 0; ibmat <= ibcol; ibmat += 16)
                {
                    tmp = _mm_loadu_si128((const __m128i *)&halfZ_data[ibmat]);
                    _mm_storeu_si128((__m128i *)&h_data[ibmat], _mm_add_epi8(tmp,
                                      _mm_set1_epi8(4)));
                }

                for (ibmat = iacol; ibmat < c_k; ibmat++)
                {
                    h_data[ibmat] = (int8_T)(halfZ_data[ibmat] + 4);
                }

                for (ibmat = 0; ibmat < c_k; ibmat++)
                {
                    ChannelCoeffs[h_data[ibmat] - 1] = 0.0;
                }

                /*  b1/b0 */
            }
            else
            {
                /* '<S1387>:1:79' else */
                /* '<S1387>:1:80' ChannelCoeffs(3+ts,1) = ... */
                /* '<S1387>:1:81'         ChannelSOS(1:ChannelNumStages,3)./ ... */
                /* '<S1387>:1:82'         ChannelSOS(1:ChannelNumStages,1); */
                b_vlen = sosHighPass_size[0];
                for (ibmat = 0; ibmat < b_vlen; ibmat++)
                {
                    ChannelCoeffs[ts_data[ibmat] + 2] = ChannelSOS[ibmat + 80] /
                        ChannelSOS[ibmat];
                }

                /*  b2/b0 */
                /* '<S1387>:1:83' ChannelCoeffs(4+ts,1) = ... */
                /* '<S1387>:1:84'         ChannelSOS(1:ChannelNumStages,2)./ ... */
                /* '<S1387>:1:85'         ChannelSOS(1:ChannelNumStages,1); */
                b_vlen = sosHighPass_size[0];
                for (ibmat = 0; ibmat < b_vlen; ibmat++)
                {
                    ChannelCoeffs[ts_data[ibmat] + 3] = ChannelSOS[ibmat + 40] /
                        ChannelSOS[ibmat];
                }

                /*  b1/b0 */
            }

            /*  length of Cuurent Channel Coeffs */
            /* '<S1387>:1:90' ChannelCoeffsLength = 1+4*ChannelNumStages; */
            b_vlen = (int32_T)(((uint32_T)sosHighPass_size[0] << 2) + 1U);

            /*  Offset into coefficient array for the current channel */
            /* '<S1387>:1:93' offset = uint32((i-1)+4*sum(PoolNumStages(1:i-1))); */
            if (nrows < 1)
            {
                order = 0.0;
            }
            else
            {
                order = Model_TranslationEngine64_B.LRHighPassNumStages[0];
                for (ibmat = 2; ibmat <= nrows; ibmat++)
                {
                    order += (real_T)
                        Model_TranslationEngine64_B.LRHighPassNumStages[ibmat -
                        1];
                }
            }

            offset = (uint32_T)((((real_T)nrows + 1.0) - 1.0) + 4.0 * order);

            /*  Verify that the SOS does not violate the maximum number of stages */
            /*  allocated for the pool */
            /* '<S1387>:1:97' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.LRHighPassNumStages[nrows] = (uint32_T)
                sosHighPass_size[0];

            /* '<S1387>:1:98' if sum(PoolNumStages) > MaxNumStages */
            /*  Store the coefficients */
            /* '<S1387>:1:103' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            for (ibmat = 0; ibmat < b_vlen; ibmat++)
            {
                y_data[ibmat] = (uint8_T)(ibmat + 1);
            }

            for (ibmat = 0; ibmat < b_vlen; ibmat++)
            {
                j_data[ibmat] = (int32_T)(y_data[ibmat] + offset);
            }

            for (ibmat = 0; ibmat < b_vlen; ibmat++)
            {
                Model_TranslationEngine64_B.LRHighPassCoeffs[j_data[ibmat] - 1] =
                    (real32_T)ChannelCoeffs[ibmat];
            }
        }
    }

    /* End of MATLAB Function: '<S1385>/Translation' */
}

/* Function for MATLAB Function: '<S1401>/Translation' */
static void Model_TranslationEngine64_eml_integer_colon_dispatcher_k2(int32_T b,
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

/* Output and update for function-call system: '<S1402>/tfunc' */
void FuncTranslation_Model_1475_36(void)
{
    real_T ChannelSOS_data[12];
    real_T ChannelCoeffs[8];
    real_T OverallGainPerCh[2];
    real_T b_y;
    real_T offset;
    int32_T g_data[8];
    int32_T tmp_data[8];
    int32_T NumStages[2];
    int32_T c_data[2];
    int32_T ts_data[2];
    int32_T SOSIndex;
    int32_T c_k;
    int32_T i;
    int32_T vlen;
    int32_T yk;
    real32_T PoolCoeffs[8];
    char_T e_data[31];
    static const char_T f[31] = "Too many second order sections";

    /* MATLAB Function: '<S1401>/Translation' */
    /* MATLAB Function: '<S1401>/Translation' incorporates:
     *  S-Function (TuneVarMEX): '<S1401>/Tune Variable1'
     *  S-Function (TuneVarMEX): '<S1401>/Tune Variable2'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1404>:1' */
    /* '<S1404>:1:3' f(); */
    /*  Translation from raw SOS for pool SOS */
    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/AnnouncementLevelDetector/PreProcessing/PreEmphasisShelfFilter/PoolIirTunableWithReset/Translation': '<S1403>:1' */
    /*  Some build time sanity size checking before calling the translation */
    /* '<S1403>:1:7' if numel(NumStages.Value) ~= NumChannels */
    /* '<S1403>:1:11' if RawSOS.Size(2) ~= 6 */
    /* '<S1403>:1:15' [PoolNumStages, PoolCoeffs] = poolIirTranslation(RawSOS, NumStages, MaxNumStages, VariantUint8); */
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
    b_y = rt_roundd_snf(Model_TranslationEngine64_B.numStages_cf.Value[0]);
    if (b_y < 2.147483648E+9)
    {
        if (b_y >= -2.147483648E+9)
        {
            NumStages[0] = (int32_T)b_y;
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

    Model_TranslationEngine64_B.PoolNumStages[0] = 0;
    offset = rt_roundd_snf(Model_TranslationEngine64_B.numStages_cf.Value[1]);
    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            NumStages[1] = (int32_T)offset;
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

    Model_TranslationEngine64_B.PoolNumStages[1] = 0;

    /* 'PoolIirHexagonTranslationFcn:16' PoolCoeffs    = single(zeros(MaxNumStages * NumCoeffPerBiquad, 1)); */
    /* 'PoolIirHexagonTranslationFcn:17' ChannelCoeffs = zeros(MaxNumStages * NumCoeffPerBiquad, 1); */
    memset(&ChannelCoeffs[0], 0, sizeof(real_T) << 3U);
    for (i = 0; i < 8; i++)
    {
        PoolCoeffs[i] = 0.0F;
    }

    /* 'PoolIirHexagonTranslationFcn:18' SOSIndex      = int32(0); */
    SOSIndex = 0;

    /*  Verify that the SOS does not violate the maximum number of stages */
    /*  allocated for the pool */
    /* 'PoolIirHexagonTranslationFcn:22' if sum(NumStages) > MaxNumStages */
    if (b_y < 2.147483648E+9)
    {
        if (b_y >= -2.147483648E+9)
        {
            vlen = (int32_T)b_y;
        }
        else
        {
            vlen = MIN_int32_T;
        }
    }
    else
    {
        vlen = MAX_int32_T;
    }

    if (offset < 2.147483648E+9)
    {
        if (offset >= -2.147483648E+9)
        {
            c_k = (int32_T)offset;
        }
        else
        {
            c_k = MIN_int32_T;
        }
    }
    else
    {
        c_k = MAX_int32_T;
    }

    if ((real_T)vlen + (real_T)c_k > 2.0)
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
        for (vlen = 0; vlen < 31; vlen++)
        {
            e_data[vlen] = f[vlen];
        }

        TranslateError(&e_data[0]);
    }

    /* 'PoolIirHexagonTranslationFcn:26' OverallGainPerCh = ones(NumChannels, 1); */
    /* 'PoolIirHexagonTranslationFcn:27' for i = 1:NumChannels */
    for (i = 0; i < 2; i++)
    {
        int32_T NumStages_0;
        NumStages_0 = NumStages[i];
        OverallGainPerCh[i] = 1.0;

        /* 'PoolIirHexagonTranslationFcn:29' ChannelNumStages = NumStages(i); */
        /*  Size of current SOS */
        /* 'PoolIirHexagonTranslationFcn:30' assert(ChannelNumStages <= MaxNumStages); */
        /* 'PoolIirHexagonTranslationFcn:31' if (ChannelNumStages == 0) */
        if (NumStages_0 != 0)
        {
            int32_T ChannelSOS_size_idx_0;
            int32_T q1;
            int32_T ts_size_idx_1;

            /* 'PoolIirHexagonTranslationFcn:35' ChannelSOS = RawSOS(SOSIndex+(1:ChannelNumStages),:); */
            Model_TranslationEngine64_eml_integer_colon_dispatcher_k2
                (NumStages_0, tmp_data, ts_data);
            ChannelSOS_size_idx_0 = ts_data[1];
            yk = ts_data[1];
            for (vlen = 0; vlen < 6; vlen++)
            {
                for (c_k = 0; c_k < yk; c_k++)
                {
                    q1 = tmp_data[c_k];
                    if ((SOSIndex < 0) && (q1 < MIN_int32_T - SOSIndex))
                    {
                        q1 = MIN_int32_T;
                    }
                    else if ((SOSIndex > 0) && (q1 > MAX_int32_T - SOSIndex))
                    {
                        q1 = MAX_int32_T;
                    }
                    else
                    {
                        q1 += SOSIndex;
                    }

                    ChannelSOS_data[c_k + ChannelSOS_size_idx_0 * vlen] =
                        Model_TranslationEngine64_B.sosCoefficients_ih.Value
                        [((vlen << 1) + q1) - 1];
                }
            }

            /* 'PoolIirHexagonTranslationFcn:36' SOSIndex = SOSIndex + ChannelNumStages; */
            if ((SOSIndex < 0) && (NumStages_0 < MIN_int32_T - SOSIndex))
            {
                SOSIndex = MIN_int32_T;
            }
            else if ((SOSIndex > 0) && (NumStages_0 > MAX_int32_T - SOSIndex))
            {
                SOSIndex = MAX_int32_T;
            }
            else
            {
                SOSIndex += NumStages_0;
            }

            /*  decompose SOS     */
            /* 'PoolIirHexagonTranslationFcn:39' OverallGainPerCh(i) = prod(ChannelSOS(:, 1)) / prod(ChannelSOS(:, 4)); */
            if (ts_data[1] == 0)
            {
                offset = 1.0;
            }
            else
            {
                offset = ChannelSOS_data[0];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    offset *= ChannelSOS_data[1];
                }
            }

            if (ts_data[1] == 0)
            {
                b_y = 1.0;
            }
            else
            {
                b_y = ChannelSOS_data[ts_data[1] * 3];
                for (yk = 2; yk <= ChannelSOS_size_idx_0; yk++)
                {
                    b_y *= ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + 1];
                }
            }

            OverallGainPerCh[i] = offset / b_y;

            /*  [a1 b1/b0 a2 b2/b0] Hexagon assembly code  */
            /* 'PoolIirHexagonTranslationFcn:42' ts = (1:NumCoeffPerBiquad:(NumCoeffPerBiquad*ChannelNumStages)) - 1; */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            if (vlen < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = (int32_T)((uint32_T)(vlen - 1) >> 2) + 1;
            }

            ts_size_idx_1 = vlen;
            if (vlen > 0)
            {
                ts_data[0] = 1;
                yk = 1;
                for (c_k = 2; c_k <= vlen; c_k++)
                {
                    yk += 4;
                    ts_data[1] = yk;
                }
            }

            yk = vlen - 1;
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k < -2147483647)
                {
                    ts_data[vlen] = MIN_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k - 1;
                }
            }

            /* 'PoolIirHexagonTranslationFcn:43' ChannelCoeffs(ts + 1) = -ChannelSOS(:, 5) ./ ChannelSOS(:, 4); */
            c_k = (ts_size_idx_1 / 4) << 2;
            q1 = c_k - 4;
            for (vlen = 0; vlen <= q1; vlen += 4)
            {
                __m128i tmp;
                tmp = _mm_loadu_si128((const __m128i *)&ts_data[vlen]);
                _mm_storeu_si128((__m128i *)&c_data[vlen], _mm_add_epi32(tmp,
                                  _mm_set1_epi32(1)));
            }

            for (vlen = c_k; vlen < ts_size_idx_1; vlen++)
            {
                c_data[vlen] = ts_data[vlen] + 1;
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = -ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 2) + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a1/a0 */
            /* 'PoolIirHexagonTranslationFcn:44' ChannelCoeffs(ts + 2) =  ChannelSOS(:, 2) ./ ChannelSOS(:, 1); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483645)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 2;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] = ChannelSOS_data[vlen +
                    ChannelSOS_size_idx_0] / ChannelSOS_data[vlen];
            }

            /*   b1/b0 */
            /* 'PoolIirHexagonTranslationFcn:45' ChannelCoeffs(ts + 3) = -ChannelSOS(:, 6) ./ ChannelSOS(:, 4); */
            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483644)
                {
                    c_data[vlen] = MAX_int32_T;
                }
                else
                {
                    c_data[vlen] = c_k + 3;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[c_data[vlen] - 1] =
                    -ChannelSOS_data[ChannelSOS_size_idx_0 * 5 + vlen] /
                    ChannelSOS_data[ChannelSOS_size_idx_0 * 3 + vlen];
            }

            /*  -a2/a0 */
            /* 'PoolIirHexagonTranslationFcn:46' ChannelCoeffs(ts + 4) =  ChannelSOS(:, 3) ./ ChannelSOS(:, 1); */
            yk = ts_size_idx_1 - 1;
            for (vlen = 0; vlen <= yk; vlen++)
            {
                c_k = ts_data[vlen];
                if (c_k > 2147483643)
                {
                    ts_data[vlen] = MAX_int32_T;
                }
                else
                {
                    ts_data[vlen] = c_k + 4;
                }
            }

            for (vlen = 0; vlen < ts_size_idx_1; vlen++)
            {
                ChannelCoeffs[ts_data[vlen] - 1] = ChannelSOS_data
                    [(ChannelSOS_size_idx_0 << 1) + vlen] / ChannelSOS_data[vlen];
            }

            /*   b2/b0 */
            /*  length of Current Channel Coeffs */
            /* 'PoolIirHexagonTranslationFcn:49' ChannelCoeffsLength = NumCoeffPerBiquad*ChannelNumStages; */
            /*  Offset into coefficient array for the current channel */
            /* 'PoolIirHexagonTranslationFcn:52' offset = NumCoeffPerBiquad*sum(PoolNumStages(1:i-1)); */
            if (i < 1)
            {
                vlen = 0;
            }
            else
            {
                vlen = Model_TranslationEngine64_B.PoolNumStages[0];
            }

            offset = 4.0 * (real_T)vlen;

            /* 'PoolIirHexagonTranslationFcn:53' PoolNumStages(i) = int32(ChannelNumStages); */
            Model_TranslationEngine64_B.PoolNumStages[i] = NumStages_0;

            /*  Store the coefficients */
            /* 'PoolIirHexagonTranslationFcn:56' PoolCoeffs(offset+(1:ChannelCoeffsLength)) = single(ChannelCoeffs(1:ChannelCoeffsLength)); */
            if (NumStages_0 > 536870911)
            {
                vlen = MAX_int32_T;
            }
            else if (NumStages_0 <= -536870912)
            {
                vlen = MIN_int32_T;
            }
            else
            {
                vlen = NumStages_0 << 2;
            }

            Model_TranslationEngine64_eml_integer_colon_dispatcher_k2(vlen,
                tmp_data, ts_data);
            c_k = ts_data[1];
            yk = ts_data[1];
            for (vlen = 0; vlen < yk; vlen++)
            {
                b_y = offset + (real_T)tmp_data[vlen];
                if (b_y < 2.147483648E+9)
                {
                    if (b_y >= -2.147483648E+9)
                    {
                        g_data[vlen] = (int32_T)b_y;
                    }
                    else
                    {
                        g_data[vlen] = MIN_int32_T;
                    }
                }
                else
                {
                    g_data[vlen] = MAX_int32_T;
                }
            }

            for (vlen = 0; vlen < c_k; vlen++)
            {
                PoolCoeffs[g_data[vlen] - 1] = (real32_T)ChannelCoeffs[vlen];
            }
        }
    }

    /* 'PoolIirHexagonTranslationFcn:59' PoolCoeffs = [PoolCoeffs; OverallGainPerCh]; */
    for (i = 0; i < 8; i++)
    {
        Model_TranslationEngine64_B.PoolCoeffs[i] = PoolCoeffs[i];
    }

    Model_TranslationEngine64_B.PoolCoeffs[8] = (real32_T)OverallGainPerCh[0];
    Model_TranslationEngine64_B.PoolCoeffs[9] = (real32_T)OverallGainPerCh[1];

    /* End of MATLAB Function: '<S1401>/Translation' */
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

/* Output and update for function-call system: '<S1407>/tfunc' */
void FuncTranslation_Model_1310_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1405>/Subsystem' */
    /* SignalConversion generated from: '<S1406>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1408>:1' */
    /* '<S1408>:1:3' f(); */
    Model_TranslationEngine64_B.Value_bu =
        Model_TranslationEngine64_B.SysMaxDbspl.Value;

    /* End of Outputs for SubSystem: '<S1405>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1409>/sec2samples'
 *    '<S1414>/sec2samples'
 *    '<S1435>/sec2samples'
 *    '<S1440>/sec2samples'
 *    '<S1461>/sec2samples'
 *    '<S1466>/sec2samples'
 *    '<S1487>/sec2samples'
 *    '<S1492>/sec2samples'
 */
void Model_TranslationEngine64_sec2samples_p(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_h_T *localB)
{
    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/AnnouncementLevelDetector/ch1_level/fast_decay/sec2samples': '<S1416>:1' */
    /* '<S1416>:1:4' y = -abs(u.Value/FrameRate); */
    localB->y = -fabsf(rtu_u->Value / 1378.125F);
}

/* Output and update for function-call system: '<S1415>/tfunc' */
void FuncTranslation_Model_1331(void)
{
    /* MATLAB Function: '<S1409>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1417>:1' */
    /* '<S1417>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.FastDecayDbPers,
         &Model_TranslationEngine64_B.sf_sec2samples_p);
}

/* Output and update for function-call system: '<S1419>/tfunc' */
void FuncTranslation_Model_1338(void)
{
    /* MATLAB Function: '<S1410>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1420>:1' */
    /* '<S1420>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb,
         &Model_TranslationEngine64_B.sf_SetPositive_nx);
}

/*
 * Output and update for function-call system:
 *    '<S1411>/sec2samples'
 *    '<S1437>/sec2samples'
 *    '<S1463>/sec2samples'
 *    '<S1489>/sec2samples'
 */
void Model_TranslationEngine64_sec2samples_g(const bus_single_1_1 *rtu_u,
    B_sec2samples_Model_TranslationEngine64_ae_T *localB)
{
    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/AnnouncementLevelDetector/ch1_level/hold_time/sec2samples': '<S1422>:1' */
    /* '<S1422>:1:4' y = ceil(u.Value*FrameRate); */
    localB->y = rtu_u->Value * 1378.125F;
    localB->y = ceilf(localB->y);
}

/* Output and update for function-call system: '<S1421>/tfunc' */
void FuncTranslation_Model_1343(void)
{
    /* MATLAB Function: '<S1411>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1423>:1' */
    /* '<S1423>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_g
        (&Model_TranslationEngine64_B.HoldTimes,
         &Model_TranslationEngine64_B.sf_sec2samples_g);
}

/* Output and update for function-call system: '<S1426>/tfunc' */
void FuncTranslation_Model_1347_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1424>/Subsystem' */
    /* SignalConversion generated from: '<S1425>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1427>:1' */
    /* '<S1427>:1:3' f(); */
    Model_TranslationEngine64_B.Value_m0 =
        Model_TranslationEngine64_B.MaxVolumeDb.Value;

    /* End of Outputs for SubSystem: '<S1424>/Subsystem' */
}

/* Output and update for function-call system: '<S1430>/tfunc' */
void FuncTranslation_Model_1348_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1428>/Subsystem' */
    /* SignalConversion generated from: '<S1429>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1431>:1' */
    /* '<S1431>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hz =
        Model_TranslationEngine64_B.MinVolumeDb.Value;

    /* End of Outputs for SubSystem: '<S1428>/Subsystem' */
}

/* Output and update for function-call system: '<S1432>/tfunc' */
void FuncTranslation_Model_1351(void)
{
    /* MATLAB Function: '<S1414>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1434>:1' */
    /* '<S1434>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.SlowDecayDbPers,
         &Model_TranslationEngine64_B.sf_sec2samples_odu);
}

/* Output and update for function-call system: '<S1441>/tfunc' */
void FuncTranslation_Model_1368(void)
{
    /* MATLAB Function: '<S1435>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1443>:1' */
    /* '<S1443>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.FastDecayDbPers_i,
         &Model_TranslationEngine64_B.sf_sec2samples_boz);
}

/* Output and update for function-call system: '<S1445>/tfunc' */
void FuncTranslation_Model_1375(void)
{
    /* MATLAB Function: '<S1436>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1446>:1' */
    /* '<S1446>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb_i,
         &Model_TranslationEngine64_B.sf_SetPositive_fl);
}

/* Output and update for function-call system: '<S1447>/tfunc' */
void FuncTranslation_Model_1380(void)
{
    /* MATLAB Function: '<S1437>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1449>:1' */
    /* '<S1449>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_g
        (&Model_TranslationEngine64_B.HoldTimes_c,
         &Model_TranslationEngine64_B.sf_sec2samples_onh);
}

/* Output and update for function-call system: '<S1452>/tfunc' */
void FuncTranslation_Model_1384_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1450>/Subsystem' */
    /* SignalConversion generated from: '<S1451>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1453>:1' */
    /* '<S1453>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ai =
        Model_TranslationEngine64_B.MaxVolumeDb_f.Value;

    /* End of Outputs for SubSystem: '<S1450>/Subsystem' */
}

/* Output and update for function-call system: '<S1456>/tfunc' */
void FuncTranslation_Model_1385_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1454>/Subsystem' */
    /* SignalConversion generated from: '<S1455>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1457>:1' */
    /* '<S1457>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hi =
        Model_TranslationEngine64_B.MinVolumeDb_m.Value;

    /* End of Outputs for SubSystem: '<S1454>/Subsystem' */
}

/* Output and update for function-call system: '<S1458>/tfunc' */
void FuncTranslation_Model_1388(void)
{
    /* MATLAB Function: '<S1440>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1460>:1' */
    /* '<S1460>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.SlowDecayDbPers_f,
         &Model_TranslationEngine64_B.sf_sec2samples_f5y);
}

/* Output and update for function-call system: '<S1467>/tfunc' */
void FuncTranslation_Model_1405(void)
{
    /* MATLAB Function: '<S1461>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1469>:1' */
    /* '<S1469>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.FastDecayDbPers_h,
         &Model_TranslationEngine64_B.sf_sec2samples_gx3);
}

/* Output and update for function-call system: '<S1471>/tfunc' */
void FuncTranslation_Model_1412(void)
{
    /* MATLAB Function: '<S1462>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1472>:1' */
    /* '<S1472>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb_p,
         &Model_TranslationEngine64_B.sf_SetPositive_bm);
}

/* Output and update for function-call system: '<S1473>/tfunc' */
void FuncTranslation_Model_1417(void)
{
    /* MATLAB Function: '<S1463>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1475>:1' */
    /* '<S1475>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_g
        (&Model_TranslationEngine64_B.HoldTimes_j,
         &Model_TranslationEngine64_B.sf_sec2samples_ai);
}

/* Output and update for function-call system: '<S1478>/tfunc' */
void FuncTranslation_Model_1421_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1476>/Subsystem' */
    /* SignalConversion generated from: '<S1477>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1479>:1' */
    /* '<S1479>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hm =
        Model_TranslationEngine64_B.MaxVolumeDb_i.Value;

    /* End of Outputs for SubSystem: '<S1476>/Subsystem' */
}

/* Output and update for function-call system: '<S1482>/tfunc' */
void FuncTranslation_Model_1422_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1480>/Subsystem' */
    /* SignalConversion generated from: '<S1481>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1483>:1' */
    /* '<S1483>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ar =
        Model_TranslationEngine64_B.MinVolumeDb_g.Value;

    /* End of Outputs for SubSystem: '<S1480>/Subsystem' */
}

/* Output and update for function-call system: '<S1484>/tfunc' */
void FuncTranslation_Model_1425(void)
{
    /* MATLAB Function: '<S1466>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1486>:1' */
    /* '<S1486>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.SlowDecayDbPers_l,
         &Model_TranslationEngine64_B.sf_sec2samples_hk);
}

/* Output and update for function-call system: '<S1493>/tfunc' */
void FuncTranslation_Model_1442(void)
{
    /* MATLAB Function: '<S1487>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1495>:1' */
    /* '<S1495>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.FastDecayDbPers_p,
         &Model_TranslationEngine64_B.sf_sec2samples_peu);
}

/* Output and update for function-call system: '<S1497>/tfunc' */
void FuncTranslation_Model_1449(void)
{
    /* MATLAB Function: '<S1488>/SetPositive' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1498>:1' */
    /* '<S1498>:1:3' f(); */
    Model_TranslationEngine64_SetPositive
        (&Model_TranslationEngine64_B.HoldMarginDb_e,
         &Model_TranslationEngine64_B.sf_SetPositive_jq);
}

/* Output and update for function-call system: '<S1499>/tfunc' */
void FuncTranslation_Model_1454(void)
{
    /* MATLAB Function: '<S1489>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1501>:1' */
    /* '<S1501>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_g
        (&Model_TranslationEngine64_B.HoldTimes_k,
         &Model_TranslationEngine64_B.sf_sec2samples_ow4w);
}

/* Output and update for function-call system: '<S1504>/tfunc' */
void FuncTranslation_Model_1458_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1502>/Subsystem' */
    /* SignalConversion generated from: '<S1503>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1505>:1' */
    /* '<S1505>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ng =
        Model_TranslationEngine64_B.MaxVolumeDb_k.Value;

    /* End of Outputs for SubSystem: '<S1502>/Subsystem' */
}

/* Output and update for function-call system: '<S1508>/tfunc' */
void FuncTranslation_Model_1459_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1506>/Subsystem' */
    /* SignalConversion generated from: '<S1507>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1509>:1' */
    /* '<S1509>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hy =
        Model_TranslationEngine64_B.MinVolumeDb_a.Value;

    /* End of Outputs for SubSystem: '<S1506>/Subsystem' */
}

/* Output and update for function-call system: '<S1510>/tfunc' */
void FuncTranslation_Model_1462(void)
{
    /* MATLAB Function: '<S1492>/sec2samples' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1512>:1' */
    /* '<S1512>:1:3' f(); */
    Model_TranslationEngine64_sec2samples_p
        (&Model_TranslationEngine64_B.SlowDecayDbPers_k,
         &Model_TranslationEngine64_B.sf_sec2samples_jtq);
}

/* Output and update for function-call system: '<S1529>/tfunc' */
void FuncTranslation_Model_1254_7_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1527>/Subsystem' */
    /* SignalConversion generated from: '<S1528>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1530>:1' */
    /* '<S1530>:1:3' f(); */
    Model_TranslationEngine64_B.Value_gs =
        Model_TranslationEngine64_B.VncThresh.Value;

    /* End of Outputs for SubSystem: '<S1527>/Subsystem' */
}

/* Output and update for function-call system: '<S1533>/tfunc' */
void FuncTranslation_Model_1254_8_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1531>/Subsystem' */
    /* SignalConversion generated from: '<S1532>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1534>:1' */
    /* '<S1534>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ig =
        Model_TranslationEngine64_B.VncSlope.Value;

    /* End of Outputs for SubSystem: '<S1531>/Subsystem' */
}

/* Output and update for function-call system: '<S1537>/tfunc' */
void FuncTranslation_Model_1254_9_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1535>/Subsystem' */
    /* SignalConversion generated from: '<S1536>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1538>:1' */
    /* '<S1538>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ob =
        Model_TranslationEngine64_B.MaxBoost.Value;

    /* End of Outputs for SubSystem: '<S1535>/Subsystem' */
}

/* Output and update for function-call system: '<S1541>/tfunc' */
void FuncTranslation_Model_1254_72_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1539>/Subsystem' */
    /* SignalConversion generated from: '<S1540>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1542>:1' */
    /* '<S1542>:1:3' f(); */
    Model_TranslationEngine64_B.Value_md =
        Model_TranslationEngine64_B.NoiseOverRide.Value;

    /* End of Outputs for SubSystem: '<S1539>/Subsystem' */
}

/* Output and update for function-call system: '<S1545>/tfunc' */
void FuncTranslation_Model_1254_74_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1543>/Subsystem' */
    /* SignalConversion generated from: '<S1544>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1546>:1' */
    /* '<S1546>:1:3' f(); */
    Model_TranslationEngine64_B.Value_aye =
        Model_TranslationEngine64_B.NoiseOverRideFlag.Value;

    /* End of Outputs for SubSystem: '<S1543>/Subsystem' */
}

/* Output and update for function-call system: '<S1549>/tfunc' */
void FuncTranslation_Model_1254_75_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1547>/Subsystem' */
    /* SignalConversion generated from: '<S1548>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1550>:1' */
    /* '<S1550>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ay =
        Model_TranslationEngine64_B.BoostOverRide.Value;

    /* End of Outputs for SubSystem: '<S1547>/Subsystem' */
}

/* Output and update for function-call system: '<S1553>/tfunc' */
void FuncTranslation_Model_1254_76_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1551>/Subsystem' */
    /* SignalConversion generated from: '<S1552>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1554>:1' */
    /* '<S1554>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ky =
        Model_TranslationEngine64_B.BoostOverRideFlag.Value;

    /* End of Outputs for SubSystem: '<S1551>/Subsystem' */
}

/* Output and update for function-call system: '<S1557>/tfunc' */
void FuncTranslation_Model_1254_99_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1555>/Subsystem' */
    /* SignalConversion generated from: '<S1556>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1558>:1' */
    /* '<S1558>:1:3' f(); */
    Model_TranslationEngine64_B.Value_i0 =
        Model_TranslationEngine64_B.VncEnableTuneVar.Value;

    /* End of Outputs for SubSystem: '<S1555>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1525>/translation'
 *    '<S1608>/translation'
 *    '<S1691>/translation'
 *    '<S1774>/translation'
 */
void Model_TranslationEngine64_translation_g(const bus_single_1_1 *rtu_tau,
    B_translation_Model_TranslationEngine64_g_T *localB)
{
    real32_T Wc;

    /*  */
    /*  Calculate coefficients for single pole LPF */
    /*  */
    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/VolMuteCh1/Ann1NonEntGainCalc/TuneTOP8/translation': '<S1560>:1' */
    /* '<S1560>:1:6' Wc      = 1/(tau.Value*Fd); */
    Wc = 1.0F / (rtu_tau->Value * 11025.0F);

    /* '<S1560>:1:7' sinCoef = sin(Wc); */
    /* '<S1560>:1:8' cosCoef = cos(Wc); */
    /* '<S1560>:1:9' coef    = (1-sinCoef)/cosCoef; */
    Wc = (1.0F - sinf(Wc)) / cosf(Wc);

    /* '<S1560>:1:11' Num = double([1-coef 0]); */
    localB->Num[0] = 1.0F - Wc;
    localB->Num[1] = 0.0;

    /* '<S1560>:1:12' Den =  double([1 -(coef)]); */
    localB->Den[0] = 1.0;
    localB->Den[1] = -Wc;
}

/* Output and update for function-call system: '<S1559>/tfunc' */
void FuncTranslation_Model_1254_85(void)
{
    /* MATLAB Function: '<S1525>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1561>:1' */
    /* '<S1561>:1:3' f(); */
    Model_TranslationEngine64_translation_g(&Model_TranslationEngine64_B.Tau,
        &Model_TranslationEngine64_B.sf_translation_g);
}

/* Output and update for function-call system: '<S1566>/tfunc' */
void FuncTranslation_Model_1254_53_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1564>/Subsystem' */
    /* SignalConversion generated from: '<S1565>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1567>:1' */
    /* '<S1567>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hb =
        Model_TranslationEngine64_B.MinVncSignal.Value;

    /* End of Outputs for SubSystem: '<S1564>/Subsystem' */
}

/* Output and update for function-call system: '<S1570>/tfunc' */
void FuncTranslation_Model_1254_54_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1568>/Subsystem' */
    /* SignalConversion generated from: '<S1569>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1571>:1' */
    /* '<S1571>:1:3' f(); */
    Model_TranslationEngine64_B.Value_e1 =
        Model_TranslationEngine64_B.MaxSpl.Value;

    /* End of Outputs for SubSystem: '<S1568>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1573>/Translation'
 *    '<S1656>/Translation'
 *    '<S1739>/Translation'
 *    '<S1822>/Translation'
 */
void Model_TranslationEngine64_Translation_lp(const bus_double_1_1 *rtu_tau,
    real32_T rtu_Fs, real32_T rtu_L, B_Translation_Model_TranslationEngine64_l_T
    *localB)
{
    real_T Wc;
    real32_T T;
    real32_T a1;

    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/VolMuteCh1/Ann1NonEntVncApplied/nonentVNCApplied_subsystem/TuneTOP/Translation': '<S1575>:1' */
    /* '<S1575>:1:3' f0 = 1/tau.Value; */
    /*  Approximation of cutoff freq from lpf filter time constant */
    /* '<S1575>:1:5' fs_lpf = Fs/L; */
    /*  lpf filtter sample rate */
    /*  [Num, Den]= butter(1,2*f0/fs_lpf);  % butter() doesn't work with dynamic parameters */
    /* '<S1575>:1:8' [Num, Den] = firstOrderButter(fs_lpf,f0); */
    /*  */
    /*   Equations derived from RESEARCH PAPERS FACULTY OF MATERIALS SCIENCE */
    /*   AND TECHNOLOGY IN TRNAVA SLOVAK UNIVERSITY OF TECHNOLOGY IN BRATISLAVA */
    /*   2019, Volume 27, Number 45 DOI 10.2478/rput-2019-0030 */
    /*   DIGITAL IMPLEMENTATION OF BUTTERWORTH FIRST–ORDER FILTER TYPE IIR */
    /*  */
    /*    FsLpf is samplerate of filter */
    /*    Fc is cutoff freq of filter */
    /*  */
    /* 'firstOrderButter:11' Wc = 2*pi*Fc; */
    Wc = 1.0 / rtu_tau->Value * 6.2831853071795862;

    /*  Cutoff freq in radians */
    /* 'firstOrderButter:12' T = 1/FsLpf; */
    T = 1.0F / (rtu_Fs / rtu_L);

    /*  Sample time of filter */
    /*  */
    /*  Calculate denominator coeffs */
    /*  */
    /* 'firstOrderButter:16' b1 = 1; */
    /* 'firstOrderButter:17' b2 = (2 * tan (Wc*T/2) - 2) / (2 + 2*tan (Wc*T/2)); */
    /*  */
    /*  Calculate numerator coeffs  */
    /*  */
    /* 'firstOrderButter:21' a1  = 2*tan(Wc*T/2) / (2 + 2*tan(Wc*T/2)); */
    a1 = tanf((real32_T)Wc * T / 2.0F);
    a1 = 2.0F * a1 / (2.0F * a1 + 2.0F);

    /* 'firstOrderButter:22' a2 = a1; */
    /*  */
    /*  Return coeffs */
    /*  */
    /* 'firstOrderButter:26' num = [a1 a2]; */
    localB->Num[0] = a1;
    localB->Num[1] = a1;

    /* 'firstOrderButter:27' den = [b1 b2]; */
    localB->Den[0] = 1.0F;
    localB->Den[1] = (tanf((real32_T)Wc * T / 2.0F) * 2.0F - 2.0F) / (tanf
        ((real32_T)Wc * T / 2.0F) * 2.0F + 2.0F);

    /*  Calculation of lpf filter coefficients */
}

/* Output and update for function-call system: '<S1574>/tfunc' */
void FuncTranslation_Model_1255_44(void)
{
    /* MATLAB Function: '<S1573>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1576>:1' */
    /* '<S1576>:1:3' f(); */
    Model_TranslationEngine64_Translation_lp(&Model_TranslationEngine64_B.Tau_k,
        Model_TranslationEngine64_ConstB.CapturedTuneConst_k,
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_l,
        &Model_TranslationEngine64_B.sf_Translation_lp);
}

/* Output and update for function-call system: '<S1581>/tfunc' */
void FuncTranslation_Model_1257_276_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1579>/Subsystem' */
    /* SignalConversion generated from: '<S1580>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1582>:1' */
    /* '<S1582>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ci =
        Model_TranslationEngine64_B.RampTime.Value;

    /* End of Outputs for SubSystem: '<S1579>/Subsystem' */
}

/*
 * Output and update for function-call system:
 *    '<S1516>/volume table translation'
 *    '<S1599>/volume table translation'
 *    '<S1682>/volume table translation'
 *    '<S1765>/volume table translation'
 */
void Model_TranslationEngine64_volumetabletranslation(const bus_double_16__2
    *rtu_VolumeTable, B_volumetabletranslation_Model_TranslationEngine64_T
    *localB)
{
    real_T b_b_data[16];
    real_T x;
    int32_T idx_data[16];
    int32_T iwork_data[16];
    int32_T c_i;
    int32_T f_j;
    int32_T i;
    int32_T i2;
    int32_T kEnd;
    int32_T pEnd;
    int32_T qEnd;
    char_T h_data[77];
    char_T f_data[74];
    char_T g_data[12];
    static const char_T r[74] =
        "%s must have at least 2 index pairs. Encounted value with only %f pairs\\n";
    static const char_T t[77] =
        "%s out of range table index %f encountered. Index must be between 0 and 1.\\n";
    static const char_T s[12] = "VolumeTable";
    boolean_T exitg1;

    /*  */
    /*  Demux Volume Table matrix into an index vector amd gain vector */
    /*  */
    /* MATLAB Function 'NEAR/Near1p1/VolumeMute/VolMuteCh1/Volume/volume table translation': '<S1586>:1' */
    /*  Set up the size and datatype of our TOP outputs: */
    /* '<S1586>:1:8' maxTableSize = numel(VolumeTable.Value) / 2; */
    /* '<S1586>:1:9' idxType = 'uint8'; */
    /* '<S1586>:1:10' idxStorageType = 'uint32'; */
    /* '<S1586>:1:11' dbType = 'single'; */
    /* '<S1586>:1:12' Table_Idx = zeros(1,maxTableSize,idxStorageType); */
    /* '<S1586>:1:13' Table_dB = zeros(1,maxTableSize,dbType); */
    memset(&localB->Table_Idx[0], 0, sizeof(uint32_T) << 4U);
    memset(&localB->Table_dB[0], 0, sizeof(real32_T) << 4U);

    /*  separate the pairs into their index and value components */
    /* '<S1586>:1:16' givenPairs = VolumeTable.Size(1); */
    /* '<S1586>:1:17' indexes = VolumeTable.Value(1:givenPairs,1); */
    if (rtu_VolumeTable->Size[0] < 1.0)
    {
        i = 0;
    }
    else
    {
        i = (int32_T)rtu_VolumeTable->Size[0];
    }

    /* '<S1586>:1:18' values = VolumeTable.Value(1:givenPairs,2); */
    /*  then sort and ignore duplicates */
    /* '<S1586>:1:21' [cleanIdx,map] = unique(indexes); */
    if (i - 1 >= 0)
    {
        memset(&idx_data[0], 0, (uint32_T)i * sizeof(int32_T));
    }

    if (i != 0)
    {
        for (c_i = 1; c_i <= i - 1; c_i += 2)
        {
            if ((rtu_VolumeTable->Value[c_i - 1] <= rtu_VolumeTable->Value[c_i])
                || rtIsNaN(rtu_VolumeTable->Value[c_i]))
            {
                idx_data[c_i - 1] = c_i;
                idx_data[c_i] = c_i + 1;
            }
            else
            {
                idx_data[c_i - 1] = c_i + 1;
                idx_data[c_i] = c_i;
            }
        }

        if (((uint32_T)i & 1U) != 0U)
        {
            idx_data[i - 1] = i;
        }

        c_i = 2;
        while (c_i < i)
        {
            i2 = c_i << 1;
            f_j = 1;
            pEnd = c_i + 1;
            while (pEnd < i + 1)
            {
                int32_T f_k;
                int32_T p;
                int32_T q;
                p = f_j;
                q = pEnd - 1;
                qEnd = f_j + i2;
                if (qEnd > i + 1)
                {
                    qEnd = i + 1;
                }

                f_k = 0;
                kEnd = qEnd - f_j;
                while (f_k + 1 <= kEnd)
                {
                    int32_T b_b_tmp_tmp;
                    x = rtu_VolumeTable->Value[idx_data[q] - 1];
                    b_b_tmp_tmp = idx_data[p - 1];
                    if ((rtu_VolumeTable->Value[b_b_tmp_tmp - 1] <= x) ||
                            rtIsNaN(x))
                    {
                        iwork_data[f_k] = b_b_tmp_tmp;
                        p++;
                        if (p == pEnd)
                        {
                            while (q + 1 < qEnd)
                            {
                                f_k++;
                                iwork_data[f_k] = idx_data[q];
                                q++;
                            }
                        }
                    }
                    else
                    {
                        iwork_data[f_k] = idx_data[q];
                        q++;
                        if (q + 1 == qEnd)
                        {
                            while (p < pEnd)
                            {
                                f_k++;
                                iwork_data[f_k] = idx_data[p - 1];
                                p++;
                            }
                        }
                    }

                    f_k++;
                }

                for (pEnd = 0; pEnd < kEnd; pEnd++)
                {
                    idx_data[(f_j + pEnd) - 1] = iwork_data[pEnd];
                }

                f_j = qEnd;
                pEnd = qEnd + c_i;
            }

            c_i = i2;
        }
    }

    i2 = (uint8_T)i;
    for (c_i = 0; c_i < i2; c_i++)
    {
        b_b_data[c_i] = rtu_VolumeTable->Value[idx_data[c_i] - 1];
    }

    f_j = 0;
    while ((f_j + 1 <= i) && rtIsInf(b_b_data[f_j]) && (b_b_data[f_j] < 0.0))
    {
        f_j++;
    }

    c_i = f_j;
    f_j = i;
    while ((f_j >= 1) && rtIsNaN(b_b_data[f_j - 1]))
    {
        f_j--;
    }

    i2 = i - f_j;
    exitg1 = false;
    while ((!exitg1) && (f_j >= 1))
    {
        x = b_b_data[f_j - 1];
        if (rtIsInf(x) && (x > 0.0))
        {
            f_j--;
        }
        else
        {
            exitg1 = true;
        }
    }

    qEnd = (i - f_j) - i2;
    i = -1;
    if (c_i > 0)
    {
        i = 0;
    }

    while (c_i + 1 <= f_j)
    {
        x = b_b_data[c_i];
        kEnd = c_i;
        do
        {
            c_i++;
        }
        while (!((c_i + 1 > f_j) || (b_b_data[c_i] != x)));

        i++;
        b_b_data[i] = x;
        idx_data[i] = idx_data[kEnd];
    }

    if (qEnd > 0)
    {
        i++;
        b_b_data[i] = b_b_data[f_j];
        idx_data[i] = idx_data[f_j];
    }

    c_i = (f_j + qEnd) - 1;
    for (f_j = 0; f_j < i2; f_j++)
    {
        qEnd = (f_j + c_i) + 1;
        pEnd = (i + f_j) + 1;
        b_b_data[pEnd] = b_b_data[qEnd];
        idx_data[pEnd] = idx_data[qEnd];
    }

    i = (i + i2) + 1;
    if (i < 1)
    {
        c_i = -1;
    }
    else
    {
        c_i = i - 1;
    }

    if ((uint8_T)i - 1 >= 0)
    {
        memcpy(&iwork_data[0], &idx_data[0], (uint8_T)i * sizeof(int32_T));
    }

    /*  Validate input sizes */
    /* '<S1586>:1:24' numPairs = numel(map); */
    /* '<S1586>:1:25' argName='VolumeTable'; */
    /*  Validate: enough data? */
    /* '<S1586>:1:28' if (numPairs < 2) */
    if (i < 2)
    {
        /* '<S1586>:1:29' TranslateError('%s must have at least 2 index pairs. Encounted value with only %f pairs\n', argName, numPairs); */
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
        memcpy(&f_data[0], &r[0], 74U * sizeof(char_T));
        for (qEnd = 0; qEnd < 12; qEnd++)
        {
            g_data[qEnd] = s[qEnd];
        }

        TranslateError(&f_data[0], &g_data[0], (real_T)i);
    }

    /*  Validate: Highest index still below 1.0? */
    /* '<S1586>:1:33' if (cleanIdx(end) > 1) */
    if (b_b_data[c_i] > 1.0)
    {
        /* '<S1586>:1:34' TranslateError('%s out of range table index %f encountered. Index must be between 0 and 1.\n',argName,cleanIdx(end)); */
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
        memcpy(&h_data[0], &t[0], 77U * sizeof(char_T));
        for (qEnd = 0; qEnd < 12; qEnd++)
        {
            g_data[qEnd] = s[qEnd];
        }

        TranslateError(&h_data[0], &g_data[0], b_b_data[c_i]);
    }

    /*  fill in the table buffer with provided pairs */
    /* '<S1586>:1:38' for i=1:numPairs */
    for (c_i = 0; c_i < i; c_i++)
    {
        /* '<S1586>:1:39' Table_Idx(i) = intmax(idxType) * cleanIdx(i); */
        localB->Table_Idx[c_i] = (uint8_T)rt_roundd_snf(255.0 * b_b_data[c_i]);

        /* '<S1586>:1:40' Table_dB(i) = values(map(i)); */
        localB->Table_dB[c_i] = (real32_T)rtu_VolumeTable->Value[iwork_data[c_i]
            + 15];
    }

    /*  fill the rest of the table buffer with the last entry */
    /* '<S1586>:1:43' for j=numel(map)+1:maxTableSize */
    c_i = 15 - i;
    for (f_j = 0; f_j <= c_i; f_j++)
    {
        i2 = i + f_j;

        /* '<S1586>:1:44' Table_Idx(j) = Table_Idx(numPairs); */
        localB->Table_Idx[i2] = localB->Table_Idx[i - 1];

        /* '<S1586>:1:45' Table_dB(j) =  Table_dB(numPairs); */
        localB->Table_dB[i2] = localB->Table_dB[i - 1];
    }
}

/* Output and update for function-call system: '<S1583>/tfunc' */
void FuncTranslation_Model_1259_139(void)
{
    /* MATLAB Function: '<S1516>/volume table translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1587>:1' */
    /* '<S1587>:1:3' f(); */
    Model_TranslationEngine64_volumetabletranslation
        (&Model_TranslationEngine64_B.Table_l,
         &Model_TranslationEngine64_B.sf_volumetabletranslation);
}

/* Output and update for function-call system: '<S1590>/tfunc' */
void FuncTranslation_Model_1259_192_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1588>/Subsystem' */
    /* SignalConversion generated from: '<S1589>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1591>:1' */
    /* '<S1591>:1:3' f(); */
    Model_TranslationEngine64_B.Value_aw =
        Model_TranslationEngine64_B.RampRate.Value;

    /* End of Outputs for SubSystem: '<S1588>/Subsystem' */
}

/* Output and update for function-call system: '<S1594>/tfunc' */
void FuncTranslation_Model_1259_190_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1592>/Subsystem' */
    /* SignalConversion generated from: '<S1593>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1595>:1' */
    /* '<S1595>:1:3' f(); */
    Model_TranslationEngine64_B.Value_br =
        Model_TranslationEngine64_B.RampTime_g.Value;

    /* End of Outputs for SubSystem: '<S1592>/Subsystem' */
}

/* Output and update for function-call system: '<S1612>/tfunc' */
void FuncTranslation_Model_1265_7_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1610>/Subsystem' */
    /* SignalConversion generated from: '<S1611>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1613>:1' */
    /* '<S1613>:1:3' f(); */
    Model_TranslationEngine64_B.Value_nt =
        Model_TranslationEngine64_B.VncThresh_g.Value;

    /* End of Outputs for SubSystem: '<S1610>/Subsystem' */
}

/* Output and update for function-call system: '<S1616>/tfunc' */
void FuncTranslation_Model_1265_8_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1614>/Subsystem' */
    /* SignalConversion generated from: '<S1615>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1617>:1' */
    /* '<S1617>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hp =
        Model_TranslationEngine64_B.VncSlope_l.Value;

    /* End of Outputs for SubSystem: '<S1614>/Subsystem' */
}

/* Output and update for function-call system: '<S1620>/tfunc' */
void FuncTranslation_Model_1265_9_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1618>/Subsystem' */
    /* SignalConversion generated from: '<S1619>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1621>:1' */
    /* '<S1621>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ok =
        Model_TranslationEngine64_B.MaxBoost_j.Value;

    /* End of Outputs for SubSystem: '<S1618>/Subsystem' */
}

/* Output and update for function-call system: '<S1624>/tfunc' */
void FuncTranslation_Model_1265_72_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1622>/Subsystem' */
    /* SignalConversion generated from: '<S1623>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1625>:1' */
    /* '<S1625>:1:3' f(); */
    Model_TranslationEngine64_B.Value_je =
        Model_TranslationEngine64_B.NoiseOverRide_k.Value;

    /* End of Outputs for SubSystem: '<S1622>/Subsystem' */
}

/* Output and update for function-call system: '<S1628>/tfunc' */
void FuncTranslation_Model_1265_74_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1626>/Subsystem' */
    /* SignalConversion generated from: '<S1627>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1629>:1' */
    /* '<S1629>:1:3' f(); */
    Model_TranslationEngine64_B.Value_m5 =
        Model_TranslationEngine64_B.NoiseOverRideFlag_h.Value;

    /* End of Outputs for SubSystem: '<S1626>/Subsystem' */
}

/* Output and update for function-call system: '<S1632>/tfunc' */
void FuncTranslation_Model_1265_75_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1630>/Subsystem' */
    /* SignalConversion generated from: '<S1631>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1633>:1' */
    /* '<S1633>:1:3' f(); */
    Model_TranslationEngine64_B.Value_bv =
        Model_TranslationEngine64_B.BoostOverRide_n.Value;

    /* End of Outputs for SubSystem: '<S1630>/Subsystem' */
}

/* Output and update for function-call system: '<S1636>/tfunc' */
void FuncTranslation_Model_1265_76_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1634>/Subsystem' */
    /* SignalConversion generated from: '<S1635>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1637>:1' */
    /* '<S1637>:1:3' f(); */
    Model_TranslationEngine64_B.Value_o2 =
        Model_TranslationEngine64_B.BoostOverRideFlag_d.Value;

    /* End of Outputs for SubSystem: '<S1634>/Subsystem' */
}

/* Output and update for function-call system: '<S1640>/tfunc' */
void FuncTranslation_Model_1265_99_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1638>/Subsystem' */
    /* SignalConversion generated from: '<S1639>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1641>:1' */
    /* '<S1641>:1:3' f(); */
    Model_TranslationEngine64_B.Value_fq =
        Model_TranslationEngine64_B.VncEnableTuneVar_j.Value;

    /* End of Outputs for SubSystem: '<S1638>/Subsystem' */
}

/* Output and update for function-call system: '<S1642>/tfunc' */
void FuncTranslation_Model_1265_85(void)
{
    /* MATLAB Function: '<S1608>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1644>:1' */
    /* '<S1644>:1:3' f(); */
    Model_TranslationEngine64_translation_g(&Model_TranslationEngine64_B.Tau_p,
        &Model_TranslationEngine64_B.sf_translation_bk);
}

/* Output and update for function-call system: '<S1649>/tfunc' */
void FuncTranslation_Model_1265_53_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1647>/Subsystem' */
    /* SignalConversion generated from: '<S1648>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1650>:1' */
    /* '<S1650>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hs =
        Model_TranslationEngine64_B.MinVncSignal_d.Value;

    /* End of Outputs for SubSystem: '<S1647>/Subsystem' */
}

/* Output and update for function-call system: '<S1653>/tfunc' */
void FuncTranslation_Model_1265_54_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1651>/Subsystem' */
    /* SignalConversion generated from: '<S1652>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1654>:1' */
    /* '<S1654>:1:3' f(); */
    Model_TranslationEngine64_B.Value_g0 =
        Model_TranslationEngine64_B.MaxSpl_d.Value;

    /* End of Outputs for SubSystem: '<S1651>/Subsystem' */
}

/* Output and update for function-call system: '<S1657>/tfunc' */
void FuncTranslation_Model_1266_44(void)
{
    /* MATLAB Function: '<S1656>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1659>:1' */
    /* '<S1659>:1:3' f(); */
    Model_TranslationEngine64_Translation_lp(&Model_TranslationEngine64_B.Tau_gb,
        Model_TranslationEngine64_ConstB.CapturedTuneConst_fr,
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_ad,
        &Model_TranslationEngine64_B.sf_Translation_js2);
}

/* Output and update for function-call system: '<S1664>/tfunc' */
void FuncTranslation_Model_1268_276_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1662>/Subsystem' */
    /* SignalConversion generated from: '<S1663>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1665>:1' */
    /* '<S1665>:1:3' f(); */
    Model_TranslationEngine64_B.Value_hg =
        Model_TranslationEngine64_B.RampTime_n.Value;

    /* End of Outputs for SubSystem: '<S1662>/Subsystem' */
}

/* Output and update for function-call system: '<S1666>/tfunc' */
void FuncTranslation_Model_1270_139(void)
{
    /* MATLAB Function: '<S1599>/volume table translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1670>:1' */
    /* '<S1670>:1:3' f(); */
    Model_TranslationEngine64_volumetabletranslation
        (&Model_TranslationEngine64_B.Table_o,
         &Model_TranslationEngine64_B.sf_volumetabletranslation_hx);
}

/* Output and update for function-call system: '<S1673>/tfunc' */
void FuncTranslation_Model_1270_192_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1671>/Subsystem' */
    /* SignalConversion generated from: '<S1672>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1674>:1' */
    /* '<S1674>:1:3' f(); */
    Model_TranslationEngine64_B.Value_bw =
        Model_TranslationEngine64_B.RampRate_o.Value;

    /* End of Outputs for SubSystem: '<S1671>/Subsystem' */
}

/* Output and update for function-call system: '<S1677>/tfunc' */
void FuncTranslation_Model_1270_190_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1675>/Subsystem' */
    /* SignalConversion generated from: '<S1676>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1678>:1' */
    /* '<S1678>:1:3' f(); */
    Model_TranslationEngine64_B.Value_au =
        Model_TranslationEngine64_B.RampTime_b.Value;

    /* End of Outputs for SubSystem: '<S1675>/Subsystem' */
}

/* Output and update for function-call system: '<S1695>/tfunc' */
void FuncTranslation_Model_1276_7_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1693>/Subsystem' */
    /* SignalConversion generated from: '<S1694>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1696>:1' */
    /* '<S1696>:1:3' f(); */
    Model_TranslationEngine64_B.Value_j5 =
        Model_TranslationEngine64_B.VncThresh_h.Value;

    /* End of Outputs for SubSystem: '<S1693>/Subsystem' */
}

/* Output and update for function-call system: '<S1699>/tfunc' */
void FuncTranslation_Model_1276_8_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1697>/Subsystem' */
    /* SignalConversion generated from: '<S1698>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1700>:1' */
    /* '<S1700>:1:3' f(); */
    Model_TranslationEngine64_B.Value_h =
        Model_TranslationEngine64_B.VncSlope_c.Value;

    /* End of Outputs for SubSystem: '<S1697>/Subsystem' */
}

/* Output and update for function-call system: '<S1703>/tfunc' */
void FuncTranslation_Model_1276_9_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1701>/Subsystem' */
    /* SignalConversion generated from: '<S1702>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1704>:1' */
    /* '<S1704>:1:3' f(); */
    Model_TranslationEngine64_B.Value_d =
        Model_TranslationEngine64_B.MaxBoost_k.Value;

    /* End of Outputs for SubSystem: '<S1701>/Subsystem' */
}

/* Output and update for function-call system: '<S1707>/tfunc' */
void FuncTranslation_Model_1276_72_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1705>/Subsystem' */
    /* SignalConversion generated from: '<S1706>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1708>:1' */
    /* '<S1708>:1:3' f(); */
    Model_TranslationEngine64_B.Value_l =
        Model_TranslationEngine64_B.NoiseOverRide_e.Value;

    /* End of Outputs for SubSystem: '<S1705>/Subsystem' */
}

/* Output and update for function-call system: '<S1711>/tfunc' */
void FuncTranslation_Model_1276_74_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1709>/Subsystem' */
    /* SignalConversion generated from: '<S1710>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1712>:1' */
    /* '<S1712>:1:3' f(); */
    Model_TranslationEngine64_B.Value_io2 =
        Model_TranslationEngine64_B.NoiseOverRideFlag_e.Value;

    /* End of Outputs for SubSystem: '<S1709>/Subsystem' */
}

/* Output and update for function-call system: '<S1715>/tfunc' */
void FuncTranslation_Model_1276_75_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1713>/Subsystem' */
    /* SignalConversion generated from: '<S1714>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1716>:1' */
    /* '<S1716>:1:3' f(); */
    Model_TranslationEngine64_B.Value_g =
        Model_TranslationEngine64_B.BoostOverRide_e.Value;

    /* End of Outputs for SubSystem: '<S1713>/Subsystem' */
}

/* Output and update for function-call system: '<S1719>/tfunc' */
void FuncTranslation_Model_1276_76_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1717>/Subsystem' */
    /* SignalConversion generated from: '<S1718>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1720>:1' */
    /* '<S1720>:1:3' f(); */
    Model_TranslationEngine64_B.Value_io =
        Model_TranslationEngine64_B.BoostOverRideFlag_c.Value;

    /* End of Outputs for SubSystem: '<S1717>/Subsystem' */
}

/* Output and update for function-call system: '<S1723>/tfunc' */
void FuncTranslation_Model_1276_99_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1721>/Subsystem' */
    /* SignalConversion generated from: '<S1722>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1724>:1' */
    /* '<S1724>:1:3' f(); */
    Model_TranslationEngine64_B.Value_pw =
        Model_TranslationEngine64_B.VncEnableTuneVar_i.Value;

    /* End of Outputs for SubSystem: '<S1721>/Subsystem' */
}

/* Output and update for function-call system: '<S1725>/tfunc' */
void FuncTranslation_Model_1276_85(void)
{
    /* MATLAB Function: '<S1691>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1727>:1' */
    /* '<S1727>:1:3' f(); */
    Model_TranslationEngine64_translation_g(&Model_TranslationEngine64_B.Tau_c,
        &Model_TranslationEngine64_B.sf_translation_aa1);
}

/* Output and update for function-call system: '<S1732>/tfunc' */
void FuncTranslation_Model_1276_53_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1730>/Subsystem' */
    /* SignalConversion generated from: '<S1731>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1733>:1' */
    /* '<S1733>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ks =
        Model_TranslationEngine64_B.MinVncSignal_e.Value;

    /* End of Outputs for SubSystem: '<S1730>/Subsystem' */
}

/* Output and update for function-call system: '<S1736>/tfunc' */
void FuncTranslation_Model_1276_54_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1734>/Subsystem' */
    /* SignalConversion generated from: '<S1735>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1737>:1' */
    /* '<S1737>:1:3' f(); */
    Model_TranslationEngine64_B.Value_jp =
        Model_TranslationEngine64_B.MaxSpl_l.Value;

    /* End of Outputs for SubSystem: '<S1734>/Subsystem' */
}

/* Output and update for function-call system: '<S1740>/tfunc' */
void FuncTranslation_Model_1277_44(void)
{
    /* MATLAB Function: '<S1739>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1742>:1' */
    /* '<S1742>:1:3' f(); */
    Model_TranslationEngine64_Translation_lp(&Model_TranslationEngine64_B.Tau_j,
        Model_TranslationEngine64_ConstB.CapturedTuneConst_i,
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_d,
        &Model_TranslationEngine64_B.sf_Translation_kj);
}

/* Output and update for function-call system: '<S1747>/tfunc' */
void FuncTranslation_Model_1279_276_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1745>/Subsystem' */
    /* SignalConversion generated from: '<S1746>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1748>:1' */
    /* '<S1748>:1:3' f(); */
    Model_TranslationEngine64_B.Value_n =
        Model_TranslationEngine64_B.RampTime_j.Value;

    /* End of Outputs for SubSystem: '<S1745>/Subsystem' */
}

/* Output and update for function-call system: '<S1749>/tfunc' */
void FuncTranslation_Model_1281_139(void)
{
    /* MATLAB Function: '<S1682>/volume table translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1753>:1' */
    /* '<S1753>:1:3' f(); */
    Model_TranslationEngine64_volumetabletranslation
        (&Model_TranslationEngine64_B.Table_a,
         &Model_TranslationEngine64_B.sf_volumetabletranslation_bl);
}

/* Output and update for function-call system: '<S1756>/tfunc' */
void FuncTranslation_Model_1281_192_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1754>/Subsystem' */
    /* SignalConversion generated from: '<S1755>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1757>:1' */
    /* '<S1757>:1:3' f(); */
    Model_TranslationEngine64_B.Value_c =
        Model_TranslationEngine64_B.RampRate_b.Value;

    /* End of Outputs for SubSystem: '<S1754>/Subsystem' */
}

/* Output and update for function-call system: '<S1760>/tfunc' */
void FuncTranslation_Model_1281_190_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1758>/Subsystem' */
    /* SignalConversion generated from: '<S1759>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1761>:1' */
    /* '<S1761>:1:3' f(); */
    Model_TranslationEngine64_B.Value_f =
        Model_TranslationEngine64_B.RampTime_h.Value;

    /* End of Outputs for SubSystem: '<S1758>/Subsystem' */
}

/* Output and update for function-call system: '<S1778>/tfunc' */
void FuncTranslation_Model_1287_7_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1776>/Subsystem' */
    /* SignalConversion generated from: '<S1777>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1779>:1' */
    /* '<S1779>:1:3' f(); */
    Model_TranslationEngine64_B.Value_p =
        Model_TranslationEngine64_B.VncThresh_a.Value;

    /* End of Outputs for SubSystem: '<S1776>/Subsystem' */
}

/* Output and update for function-call system: '<S1782>/tfunc' */
void FuncTranslation_Model_1287_8_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1780>/Subsystem' */
    /* SignalConversion generated from: '<S1781>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1783>:1' */
    /* '<S1783>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ju =
        Model_TranslationEngine64_B.VncSlope_j.Value;

    /* End of Outputs for SubSystem: '<S1780>/Subsystem' */
}

/* Output and update for function-call system: '<S1786>/tfunc' */
void FuncTranslation_Model_1287_9_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1784>/Subsystem' */
    /* SignalConversion generated from: '<S1785>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1787>:1' */
    /* '<S1787>:1:3' f(); */
    Model_TranslationEngine64_B.Value_ox =
        Model_TranslationEngine64_B.MaxBoost_a.Value;

    /* End of Outputs for SubSystem: '<S1784>/Subsystem' */
}

/* Output and update for function-call system: '<S1790>/tfunc' */
void FuncTranslation_Model_1287_72_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1788>/Subsystem' */
    /* SignalConversion generated from: '<S1789>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1791>:1' */
    /* '<S1791>:1:3' f(); */
    Model_TranslationEngine64_B.Value_er =
        Model_TranslationEngine64_B.NoiseOverRide_b.Value;

    /* End of Outputs for SubSystem: '<S1788>/Subsystem' */
}

/* Output and update for function-call system: '<S1794>/tfunc' */
void FuncTranslation_Model_1287_74_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1792>/Subsystem' */
    /* SignalConversion generated from: '<S1793>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1795>:1' */
    /* '<S1795>:1:3' f(); */
    Model_TranslationEngine64_B.Value_e =
        Model_TranslationEngine64_B.NoiseOverRideFlag_l.Value;

    /* End of Outputs for SubSystem: '<S1792>/Subsystem' */
}

/* Output and update for function-call system: '<S1798>/tfunc' */
void FuncTranslation_Model_1287_75_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1796>/Subsystem' */
    /* SignalConversion generated from: '<S1797>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1799>:1' */
    /* '<S1799>:1:3' f(); */
    Model_TranslationEngine64_B.Value_i =
        Model_TranslationEngine64_B.BoostOverRide_o.Value;

    /* End of Outputs for SubSystem: '<S1796>/Subsystem' */
}

/* Output and update for function-call system: '<S1802>/tfunc' */
void FuncTranslation_Model_1287_76_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1800>/Subsystem' */
    /* SignalConversion generated from: '<S1801>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1803>:1' */
    /* '<S1803>:1:3' f(); */
    Model_TranslationEngine64_B.Value_j =
        Model_TranslationEngine64_B.BoostOverRideFlag_f.Value;

    /* End of Outputs for SubSystem: '<S1800>/Subsystem' */
}

/* Output and update for function-call system: '<S1806>/tfunc' */
void FuncTranslation_Model_1287_99_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1804>/Subsystem' */
    /* SignalConversion generated from: '<S1805>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1807>:1' */
    /* '<S1807>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mc =
        Model_TranslationEngine64_B.VncEnableTuneVar_f.Value;

    /* End of Outputs for SubSystem: '<S1804>/Subsystem' */
}

/* Output and update for function-call system: '<S1808>/tfunc' */
void FuncTranslation_Model_1287_85(void)
{
    /* MATLAB Function: '<S1774>/translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1810>:1' */
    /* '<S1810>:1:3' f(); */
    Model_TranslationEngine64_translation_g(&Model_TranslationEngine64_B.Tau_g,
        &Model_TranslationEngine64_B.sf_translation_ja);
}

/* Output and update for function-call system: '<S1815>/tfunc' */
void FuncTranslation_Model_1287_53_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1813>/Subsystem' */
    /* SignalConversion generated from: '<S1814>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1816>:1' */
    /* '<S1816>:1:3' f(); */
    Model_TranslationEngine64_B.Value_o =
        Model_TranslationEngine64_B.MinVncSignal_j.Value;

    /* End of Outputs for SubSystem: '<S1813>/Subsystem' */
}

/* Output and update for function-call system: '<S1819>/tfunc' */
void FuncTranslation_Model_1287_54_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1817>/Subsystem' */
    /* SignalConversion generated from: '<S1818>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1820>:1' */
    /* '<S1820>:1:3' f(); */
    Model_TranslationEngine64_B.Value_b =
        Model_TranslationEngine64_B.MaxSpl_b.Value;

    /* End of Outputs for SubSystem: '<S1817>/Subsystem' */
}

/* Output and update for function-call system: '<S1823>/tfunc' */
void FuncTranslation_Model_1288_44(void)
{
    /* MATLAB Function: '<S1822>/Translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1825>:1' */
    /* '<S1825>:1:3' f(); */
    Model_TranslationEngine64_Translation_lp(&Model_TranslationEngine64_B.Tau_i,
        Model_TranslationEngine64_ConstB.CapturedTuneConst_c,
        Model_TranslationEngine64_ConstB.CapturedTuneConst1_p,
        &Model_TranslationEngine64_B.sf_Translation_lhh);
}

/* Output and update for function-call system: '<S1830>/tfunc' */
void FuncTranslation_Model_1290_276_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1828>/Subsystem' */
    /* SignalConversion generated from: '<S1829>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1831>:1' */
    /* '<S1831>:1:3' f(); */
    Model_TranslationEngine64_B.Value_mu =
        Model_TranslationEngine64_B.RampTime_bw.Value;

    /* End of Outputs for SubSystem: '<S1828>/Subsystem' */
}

/* Output and update for function-call system: '<S1832>/tfunc' */
void FuncTranslation_Model_1292_139(void)
{
    /* MATLAB Function: '<S1765>/volume table translation' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1836>:1' */
    /* '<S1836>:1:3' f(); */
    Model_TranslationEngine64_volumetabletranslation
        (&Model_TranslationEngine64_B.Table_n,
         &Model_TranslationEngine64_B.sf_volumetabletranslation_bdp);
}

/* Output and update for function-call system: '<S1839>/tfunc' */
void FuncTranslation_Model_1292_192_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1837>/Subsystem' */
    /* SignalConversion generated from: '<S1838>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1840>:1' */
    /* '<S1840>:1:3' f(); */
    Model_TranslationEngine64_B.Value_m =
        Model_TranslationEngine64_B.RampRate_l.Value;

    /* End of Outputs for SubSystem: '<S1837>/Subsystem' */
}

/* Output and update for function-call system: '<S1843>/tfunc' */
void FuncTranslation_Model_1292_190_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1841>/Subsystem' */
    /* SignalConversion generated from: '<S1842>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1844>:1' */
    /* '<S1844>:1:3' f(); */
    Model_TranslationEngine64_B.Value_a =
        Model_TranslationEngine64_B.RampTime_h0.Value;

    /* End of Outputs for SubSystem: '<S1841>/Subsystem' */
}

/* Output and update for function-call system: '<S1895>/tfunc' */
void FuncTranslation_Model_291_138_8_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1893>/Subsystem' */
    /* SignalConversion generated from: '<S1894>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1896>:1' */
    /* '<S1896>:1:3' f(); */
    Model_TranslationEngine64_B.Value_kc =
        Model_TranslationEngine64_B.EnableAux.Value;

    /* End of Outputs for SubSystem: '<S1893>/Subsystem' */
}

/* Output and update for function-call system: '<S1900>/tfunc' */
void FuncTranslation_Model_291_138_44_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1898>/Subsystem' */
    /* SignalConversion generated from: '<S1899>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1901>:1' */
    /* '<S1901>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_B.Value_k[0],
           &Model_TranslationEngine64_B.MainSelect.Value[0], 24U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S1898>/Subsystem' */
}

/* Output and update for function-call system: '<S1904>/tfunc' */
void FuncTranslation_Model_296_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1902>/Subsystem' */
    /* SignalConversion generated from: '<S1903>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1905>:1' */
    /* '<S1905>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_B.Value[0],
           &Model_TranslationEngine64_B.AuxSelect.Value[0], 24U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S1902>/Subsystem' */
}

/* Model step function */
void Model_TranslationEngine64_step(void)
{
    /* End of Outputs for S-Function (TranslateTrigger): '<S26>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S30>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S38>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S40>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S44>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S48>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S68>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S69>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S70>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S73>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S72>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S71>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S84>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S88>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S92>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S96>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S100>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S104>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S108>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S112>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S116>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S120>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S136>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S140>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S144>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S148>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S153>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S152>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S154>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S161>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S164>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S169>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S173>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S177>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S181>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S185>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S188>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S200>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S214>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S218>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S224>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S228>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S238>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S242>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S246>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S250>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S254>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S257>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S262>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S267>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S270>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S275>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S279>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S285>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S290>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S294>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S305>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S314>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S317>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S321>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S325>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S329>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S333>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S339>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S344>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S349>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S352>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S361>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S364>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S367>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S372>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S380>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S384>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S386>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S391>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S395>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S409>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S414>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S418>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S420>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S425>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S429>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S432>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S436>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S440>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S445>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S448>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S453>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S460>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S463>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S467>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S471>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S483>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S487>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S489>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S494>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S498>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S500>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S510>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S514>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S516>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S521>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S525>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S527>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S534>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S538>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S543>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S547>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S553>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S557>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S566>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S577>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S581>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S585>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S589>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S593>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S596>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1053>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1057>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1314>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1318>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1324>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1328>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1332>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1340>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1351>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1355>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1361>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1365>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1369>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1377>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1383>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1386>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1402>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1407>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1415>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1419>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1421>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1426>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1430>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1432>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1441>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1445>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1447>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1452>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1456>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1458>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1467>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1471>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1473>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1478>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1482>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1484>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1493>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1497>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1499>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1504>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1508>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1510>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1529>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1533>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1537>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1541>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1545>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1549>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1553>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1557>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1559>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1566>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1570>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1574>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1581>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1583>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1590>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1594>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1612>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1616>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1620>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1624>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1628>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1632>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1636>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1640>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1642>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1649>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1653>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1657>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1664>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1666>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1673>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1677>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1695>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1699>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1703>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1707>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1711>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1715>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1719>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1723>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1725>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1732>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1736>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1740>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1747>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1749>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1756>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1760>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1778>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1782>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1786>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1790>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1794>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1798>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1802>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1806>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1808>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1815>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1819>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1823>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1830>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1832>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1839>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1843>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1895>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1900>/S-Function' */
    /* End of Outputs for S-Function (TranslateTrigger): '<S1904>/S-Function' */
}

/* Initialize for atomic system: '<S599>/Alignment Delay' */
void Model_TranslationEngine64_AlignmentDelay_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_AlignmentDelay_B, 0,
                  sizeof(B_AlignmentDelay_Model_TranslationEngine64_T));
}

/* Initialize for atomic system: '<S560>/Medusa5H1 Part 3' */
void Model_TranslationEngine64_Medusa5H1Part3_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_Medusa5H1Part3_B, 0,
                  sizeof(B_Medusa5H1Part3_Model_TranslationEngine64_T));
}

/* Initialize for atomic system: '<S560>/Medusa5H1 Part 4' */
void Model_TranslationEngine64_Medusa5H1Part4_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_Medusa5H1Part4_B, 0,
                  sizeof(B_Medusa5H1Part4_Model_TranslationEngine64_T));
}

/* Initialize for atomic system: '<S560>/Medusa5H1 Part 6' */
void Model_TranslationEngine64_Medusa5H1Part6_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_Medusa5H1Part6_B, 0,
                  sizeof(B_Medusa5H1Part6_Model_TranslationEngine64_T));
}

/* Initialize for atomic system: '<S3>/PreAmpPart1' */
void Model_TranslationEngine64_PreAmpPart1_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_PreAmpPart1_B, 0,
                  sizeof(B_PreAmpPart1_Model_TranslationEngine64_T));
}

/* Model initialize function */
void Model_TranslationEngine64_initialize(void)
{
    /* Registration code */

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* initialize error status */
    rtmSetErrorStatus(Model_TranslationEngine64_M, (NULL));

    /* block I/O */
    (void) memset(((void *) &Model_TranslationEngine64_B), 0,
                  sizeof(B_Model_TranslationEngine64_T));

    /* Initialize subsystem data */
    Model_TranslationEngine64_AlignmentDelay_initialize();
    Model_TranslationEngine64_ExpandTailComponents_initialize();
    Model_TranslationEngine64_Medusa5H1Part3_initialize();
    Model_TranslationEngine64_Medusa5H1Part4_initialize();
    Model_TranslationEngine64_Medusa5H1Part6_initialize();
    Model_TranslationEngine64_MedusaPostHoligram_initialize();
    Model_TranslationEngine64_VLS_initialize();
    Model_TranslationEngine64_PreAmpPart1_initialize();
    Model_TranslationEngine64_PostProcess_initialize();

    /* user code (Start function Body) */

    // Load default values for all TuneVars
    LoadAllTuneVarDefaults();

    /* SystemInitialize for Atomic SubSystem: '<Root>/InputSelect' */
    Model_TranslationEngine64_InputSelect_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/InputSelect' */
}

/* Model terminate function */
void Model_TranslationEngine64_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
