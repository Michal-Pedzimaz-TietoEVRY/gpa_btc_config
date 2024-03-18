/*
 * File: Model_InterpretationEngine64_TSP_Interpret.c
 *
 * Code generated for Simulink model 'Model_InterpretationEngine64'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar  6 16:16:14 2024
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <ctype.h>
#include <string.h>                    // for strncmp
#include "rtwtypes.h"
#include "Model_InterpretationEngine64_TSP_Interpret.h"
#include "ASDID.h"                     // for SimulinkDatatypeId
#include "Model_InterpretationEngine64.h" // for TSP output signals
#include <stdio.h>                     // for sscanf, vsnprintf
#include <stdarg.h>                    // for variadic args (va_start)

// Struct for TSP interpretation (outport) dispatch table
typedef struct TSP_InterpretationTable_tag
{
    const char* name;                  // featurepath of tsp
    int sightings_count;               // counts RecognizeTSP invocations
    SimulinkDatatypeId dtype_id;      // SimulinkDatatypeId of numeric data type
    int element_bytes;                 // byte size of a single element
    int width;                         // number of elements in value
    void* value_ptr;                   // array of current numeric value
}
TSP_InterpretationTable_type;

// ----- TSP interpret dispatch table:
static TSP_InterpretationTable_type tsp_interpret_table[] =
{
    {                                  /* '<S13>/TSP' */
        "PreAmpAudiopilotHvacDbspl", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_j
    },

    {                                  /* '<S14>/TSP' */
        "PreAmpAudiopilotVehicleSpeed", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_l
    },

    {                                  /* '<S25>/TSP' */
        "PreAmpAudiopilotAudiopilotBassBoostDb", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_o
    },

    {                                  /* '<S26>/TSP' */
        "PreAmpAudiopilotAudiopilotMidrangeBoostDb", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_bq
    },

    {                                  /* '<S27>/TSP' */
        "PreAmpAudiopilotAudiopilotTrebleBoostDb", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_c
    },

    {                                  /* '<S28>/TSP' */
        "PreAmpAudiopilotDyneqBassBoostDb", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_od
    },

    {                                  /* '<S29>/TSP' */
        "PreAmpAudiopilotHfNoiseDbspl", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_f
    },

    {                                  /* '<S30>/TSP' */
        "PreAmpAudiopilotIgnoreMicFlag", 0, TSS_BOOLEAN, sizeof(boolean_T), 1U,
        &Model_InterpretationEngine64_B.TSP_lz
    },

    {                                  /* '<S31>/TSP' */
        "PreAmpAudiopilotLfNoiseDbspl", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_a
    },

    {                                  /* '<S32>/TSP' */
        "PreAmpAudiopilotNoiseRatio", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_d
    },

    {                                  /* '<S33>/TSP' */
        "PreAmpAudiopilotTotalBassBoostDb", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_dj
    },

    {                                  /* '<S34>/TSP' */
        "PreAmpAudiopilotWbNoiseDbspl", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_ai
    },

    {                                  /* '<S75>/TSP' */
        "PreAmpAudiopilotAudiopilotBoostGain", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_cp
    },

    {                                  /* '<S76>/TSP' */
        "PreAmpAudiopilotDyneqBoostGain", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_jv
    },

    {                                  /* '<S93>/TSP' */
        "PreAmpAudiopilotHfNoiseMicPsdLevel", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_h
    },

    {                                  /* '<S92>/TSP' */
        "PreAmpAudiopilotHfNoisePowerSpectralDensity", 0, TSS_SINGLE, sizeof
        (real32_T), 65U, Model_InterpretationEngine64_B.TSP_aj
    },

    {                                  /* '<S106>/TSP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatness", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_n1
    },

    {                                  /* '<S105>/TSP' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionPmin", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_nn
    },

    {                                  /* '<S102>/TSP' */
        "PreAmpAudiopilotHfNoisePostSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_n3
    },

    {                                  /* '<S103>/TSP' */
        "PreAmpAudiopilotHfNoisePreSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_cs
    },

    {                                  /* '<S132>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut", 0, TSS_SINGLE,
        sizeof(real32_T), 1U, &Model_InterpretationEngine64_B.TSP_br
    },

    {                                  /* '<S133>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_k
    },

    {                                  /* '<S134>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance", 0, TSS_SINGLE,
        sizeof(real32_T), 1U, &Model_InterpretationEngine64_B.TSP_p
    },

    {                                  /* '<S135>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance", 0, TSS_SINGLE,
        sizeof(real32_T), 1U, &Model_InterpretationEngine64_B.TSP_in
    },

    {                                  /* '<S136>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance", 0, TSS_SINGLE,
        sizeof(real32_T), 1U, &Model_InterpretationEngine64_B.TSP_jw
    },

    {                                  /* '<S137>/TSP' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance", 0, TSS_SINGLE,
        sizeof(real32_T), 1U, &Model_InterpretationEngine64_B.TSP_gj
    },

    {                                  /* '<S124>/TSP' */
        "PreAmpAudiopilotLfNoiseMicLevel", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_ih
    },

    {                                  /* '<S125>/TSP' */
        "PreAmpAudiopilotLfNoiseMicOut", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_nb
    },

    {                                  /* '<S126>/TSP' */
        "PreAmpAudiopilotLfNoiseMusicOut", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_bh
    },

    {                                  /* '<S127>/TSP' */
        "PreAmpAudiopilotLfNoiseNoiseOut", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_gl
    },

    {                                  /* '<S128>/TSP' */
        "PreAmpAudiopilotLfNoisePostSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_n0
    },

    {                                  /* '<S129>/TSP' */
        "PreAmpAudiopilotLfNoisePreSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_e
    },

    {                                  /* '<S130>/TSP' */
        "PreAmpAudiopilotLfNoisePreSpeedBound", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_o5
    },

    {                                  /* '<S186>/TSP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_oi
    },

    {                                  /* '<S187>/TSP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_kq
    },

    {                                  /* '<S188>/TSP' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsFlag", 0, TSS_DOUBLE, sizeof(real_T),
        1U, &Model_InterpretationEngine64_B.TSP
    },

    {                                  /* '<S201>/TSP' */
        "PreAmpAudiopilotRatioPostSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_hv
    },

    {                                  /* '<S202>/TSP' */
        "PreAmpAudiopilotRatioPreSlew", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_ah
    },

    {                                  /* '<S203>/TSP' */
        "PreAmpAudiopilotRatioUpdateFlag", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_fd
    },

    {                                  /* '<S219>/TSP' */
        "PreAmpLevelWatchAudiopilotEnvDb", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_ajv
    },

    {                                  /* '<S220>/TSP' */
        "PreAmpLevelWatchAudiopilotLevelDbspl", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_hc
    },

    {                                  /* '<S230>/TSP' */
        "PreAmpLevelWatchDyneqEnvDb", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_ej
    },

    {                                  /* '<S231>/TSP' */
        "PreAmpLevelWatchDyneqLevelDbspl", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_fy
    },

    {                                  /* '<S245>/TSP' */
        "PreAmpMedusaDummyState", 0, TSS_INT32, sizeof(int32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_np
    },

    {                                  /* '<S254>/TSP' */
        "PreAmpMedusaMonoDetectorLevelCenter", 0, TSS_SINGLE, sizeof(real32_T),
        1U, &Model_InterpretationEngine64_B.TSP_m
    },

    {                                  /* '<S252>/TSP' */
        "PreAmpMedusaMonoDetectorIsStereo", 0, TSS_UINT32, sizeof(uint32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_g
    },

    {                                  /* '<S253>/TSP' */
        "PreAmpMedusaMonoDetectorIsActive", 0, TSS_INT32, sizeof(int32_T), 1U,
        &Model_InterpretationEngine64_B.TSP_lr
    },

    {                                  /* '<S275>/TSP' */
        "NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_b
    },

    {                                  /* '<S282>/TSP' */
        "NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_i
    },

    {                                  /* '<S289>/TSP' */
        "NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_n
    },

    {                                  /* '<S296>/TSP' */
        "NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_B.TSP_gb
    },

    {                                  /* '<S305>/TSP' */
        "PostProcessEnergyLimiterComputedEnergy", 0, TSS_SINGLE, sizeof(real32_T),
        24U, Model_InterpretationEngine64_PostProcess_B.TSP
    },

    {                                  /* '<S306>/TSP' */
        "PostProcessEnergyLimiterCurGain", 0, TSS_SINGLE, sizeof(real32_T), 1U,
        &Model_InterpretationEngine64_PostProcess_B.TSP_b
    },

    {                                  /* '<S307>/TSP' */
        "PostProcessEnergyLimiterEnergyThreshold", 0, TSS_SINGLE, sizeof
        (real32_T), 1U, &Model_InterpretationEngine64_PostProcess_B.TSP_f
    },

    {                                  /* '<S308>/TSP' */
        "PostProcessEnergyLimiterCurState", 0, TSS_INT16, sizeof(int16_T), 1U,
        &Model_InterpretationEngine64_PostProcess_B.TSP_i
    },

    {                                  /* '<S309>/TSP' */
        "PostProcessEnergyLimiterEnableFlag", 0, TSS_INT16, sizeof(int16_T), 1U,
        &Model_InterpretationEngine64_PostProcess_B.TSP_fc
    },
};

// Share table in a public interface for use by top-model
void* Model_InterpretationEngine64_tsp_interpret_table = tsp_interpret_table;
int Model_InterpretationEngine64_tsp_interpret_table_count = sizeof
    (tsp_interpret_table) / sizeof(TSP_InterpretationTable_type);

// -----------------------------------------------------
// Local storage
static char tspErrorBuffer[400];
static int tspErrorCharsUsed = 0;

// forward declare local functions
static void ErrorVPrintf(const char* formatString, va_list args);
static void ErrorPrintf(const char* formatString, ...);

// Internal use print to error buffer
static void ErrorVPrintf(const char* formatString, va_list args)
{
    char* buffer = &tspErrorBuffer[tspErrorCharsUsed];
    int bufferSize = sizeof(tspErrorBuffer) - tspErrorCharsUsed;
    if (bufferSize)
    {
        int charsPrinted = vsnprintf(
            buffer, bufferSize, formatString, args);
        tspErrorCharsUsed += charsPrinted;
    }
}

// Internal use print to error buffer
static void ErrorPrintf(const char* formatString, ...)
{
    va_list args;
    va_start(args, formatString);
    ErrorVPrintf(formatString, args);
    va_end(args);
}

// Clear error state
void ClearTSPErrorStrings()
{
    tspErrorBuffer[0] = 0;
    tspErrorCharsUsed = 0;
}

// Retrieve reported error strings
const char* GetTSPErrorStrings()
{
    return &tspErrorBuffer[0];
}

// checks for string equality without regards to case
// returns 1 if lowercase strings are equal, 0 otherwise
static int insensitiveStrcmp(const char* A, const char* B)
{
    int i;
    for (i = 0; *A && *B; i++)
    {
        if (tolower(*A++) != tolower(*B++))
        {
            return 0;
        }
    }

    return (*A == *B);
}

static TSP_InterpretationTable_type* GetTspInterpretationRecord
    (InterpretEngineIterator iteratorIn)
{
    if ((iteratorIn.model < 0) || (iteratorIn.model >= numInterpretationRoots))
    {
        return 0;                      // model out of range
    }

    InterpretationRoot* theRoot = interpretationRoots[iteratorIn.model];
    if ((iteratorIn.index < 0) || (iteratorIn.index >=
            *theRoot->tsp_interpret_table_count))
    {
        return 0;                      // index out of range for specified model
    }

    TSP_InterpretationTable_type* theTable = *(TSP_InterpretationTable_type**)
        theRoot->tsp_interpret_table;
    return &theTable[iteratorIn.index];
}

// Return a TSP iterator if name is recognized, INVALID_INTERPRET_ITERATOR otherwise
InterpretEngineIterator RecognizeTSP(const char* tspName)
{
    InterpretEngineIterator retVal = INVALID_INTERPRET_ITERATOR;
    InterpretEngineIterator iterator;
    TSP_InterpretationTable_type* theVar = 0;
    TSP_InterpretationTable_type* aRecord;

    // Loop through table searching for a variable name match
    int m;
    for (m = 0; (m < numInterpretationRoots) && (theVar == 0); m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetTspInterpretationRecord(iterator); aRecord;
             aRecord = GetTspInterpretationRecord(iterator))
        {
            if (insensitiveStrcmp(tspName, aRecord->name))
            {
                theVar = aRecord;
                retVal = iterator;
                break;
            }

            iterator.index++;
        }
    }

    // If a variable was found, set all the flags announcing its arrival
    if (theVar)
    {
        theVar->sightings_count++;
    }
    else
    {
        // variable was *not* found. generate error string
        ErrorPrintf("Error: Unrecognized TSP [%s]\n", tspName);
    }

    return retVal;
}

// Reset all TSP sighting counts to zero
void ClearAllTSPSightings()
{
    TSP_InterpretationTable_type* aRecord;
    InterpretEngineIterator iterator;
    int m;
    for (m = 0; m < numInterpretationRoots; m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetTspInterpretationRecord(iterator); aRecord;
             aRecord = GetTspInterpretationRecord(iterator))
        {
            aRecord->sightings_count = 0;
            iterator.index++;
        }
    }
}

// Return count of how many times the specified TSP has been seen
int GetTSPSightings(InterpretEngineIterator tspNumberIn)
{
    int sightings = 0;
    TSP_InterpretationTable_type* aRecord = GetTspInterpretationRecord
        (tspNumberIn);
    if (aRecord)
    {
        sightings = aRecord->sightings_count;
    }

    return sightings;
}

// Return TSP name (or NULL if bad number)
const char* GetTSPName(InterpretEngineIterator tspNumberIn)
{
    const char* name = 0;
    TSP_InterpretationTable_type* aRecord = GetTspInterpretationRecord
        (tspNumberIn);
    if (aRecord)
    {
        name = aRecord->name;
    }

    return name;
}

uint8_t checkIfHexData(const char* element)
{
    uint8_t isHexData = 0;
    char *hexHeader = "0x";
    if (strncmp(element, hexHeader, 2) == 0)
    {
        isHexData = 1;
    }

    return isHexData;
}

// Set a single value of the TSP
// For an N row by M column matrix using zero-based row and col, indexIn = row + (col * N);
// Returns 0 for OK, 1=error 2=warning (does not set error state)
int SetTSPElement(InterpretEngineIterator tspNumberIn, int indexIn, const char
                  * stringElementValueIn)
{
    // bail if provided number is not within the table
    TSP_InterpretationTable_type* aRecord = GetTspInterpretationRecord
        (tspNumberIn);
    if (!aRecord)
        return 1;
    int maxElementIndex = aRecord->width;
    if (indexIn >= maxElementIndex)
    {
        ErrorPrintf("Error: TSP %s accepts only %d elements. Ignoring element #%d with value [%s]\n",
                    aRecord->name, maxElementIndex, indexIn + 1,
                    stringElementValueIn);
        fflush(stderr);
        return 2;                // bail out... requested index is out of range!
    }

    // parse the value string, placing numeric value into the TSP
    SimulinkDatatypeId dTypeId = aRecord->dtype_id;
    void* valPtr = aRecord->value_ptr;
    uint8_t isHexData = checkIfHexData(stringElementValueIn);
    if (isHexData == 1)
    {
        switch (dTypeId)
        {
          case TSS_DOUBLE:
            sscanf(stringElementValueIn, "%llx", &((double *)valPtr)[indexIn]);
            break;

          case TSS_SINGLE:
            sscanf(stringElementValueIn, "%lx", &((float *)valPtr)[indexIn]);
            break;

          case TSS_INT32:
          case TSS_UINT32:
            sscanf(stringElementValueIn, "%x", &((uint32_t *)valPtr)[indexIn]);
            break;

          case TSS_INT16:
          case TSS_UINT16:
            sscanf(stringElementValueIn, "%hx", &((uint16_t *)valPtr)[indexIn]);
            break;

          case TSS_INT8:
          case TSS_UINT8:
          case TSS_BOOLEAN:
            sscanf(stringElementValueIn, "%hhx", &((uint8_t *)valPtr)[indexIn]);
            break;
        }
    }
    else
    {
        switch (dTypeId)
        {
          case TSS_DOUBLE:
            sscanf(stringElementValueIn, "%lf", &((double*)valPtr)[indexIn]);
            break;

          case TSS_SINGLE:
            sscanf(stringElementValueIn, "%f", &((float*)valPtr)[indexIn]);
            break;

          case TSS_INT8:
            sscanf(stringElementValueIn, "%hhi", &((int8_t *)valPtr)[indexIn]);
            break;

          case TSS_UINT8:
            sscanf(stringElementValueIn, "%hhu", &((uint8_t *)valPtr)[indexIn]);
            break;

          case TSS_INT16:
            sscanf(stringElementValueIn, "%hi", &((int16_t *)valPtr)[indexIn]);
            break;

          case TSS_UINT16:
            sscanf(stringElementValueIn, "%hu", &((uint16_t *)valPtr)[indexIn]);
            break;

          case TSS_INT32:
            sscanf(stringElementValueIn, "%i", &((int32_t *)valPtr)[indexIn]);
            break;

          case TSS_UINT32:
            sscanf(stringElementValueIn, "%u", &((uint32_t *)valPtr)[indexIn]);
            break;

          case TSS_BOOLEAN:
            sscanf(stringElementValueIn, "%hhi", &((int8_t *)valPtr)[indexIn]);
            break;
        }
    }

    return 0;                          // no errors
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
