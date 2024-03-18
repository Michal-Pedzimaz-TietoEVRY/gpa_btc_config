/*
 * File: Model_InterpretationEngine64_StateVar.c
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
#include "rtwtypes.h"
#include "Model_InterpretationEngine64_StateVar.h"
#include "Model_InterpretationEngine64_InterpretTrigger.h"
#include "ASDID.h"                     // for SimulinkDatatypeId
#include "Model_InterpretationEngine64.h" // for state variable input signals
#include <stdio.h>                     // for sscanf, fprintf

// Interpretation numbers local to this model:
enum InterpretationNumber
{
    ID_Interpretation_Model_662_27_30, /* '<S311>/S-Function' */
    ID_Interpretation_Model_663_27_30, /* '<S315>/S-Function' */
    ID_Interpretation_Model_664_27_30, /* '<S319>/S-Function' */
    ID_Interpretation_Model_665_27_30, /* '<S323>/S-Function' */
    ID_Interpretation_Model_666_27_30, /* '<S327>/S-Function' */
    ID_Interpretation_Model_141_1195_27_30,/* '<S247>/S-Function' */
    ID_Interpretation_Model_141_1404_27_30,/* '<S256>/S-Function' */
    ID_Interpretation_Model_141_1466_27_30,/* '<S260>/S-Function' */
    ID_Interpretation_Model_141_1467_27_30,/* '<S264>/S-Function' */
    ID_Interpretation_Model_117_953_27_30,/* '<S16>/S-Function' */
    ID_Interpretation_Model_117_952_27_30,/* '<S20>/S-Function' */
    ID_Interpretation_Model_117_44_372_27_30,/* '<S36>/S-Function' */
    ID_Interpretation_Model_117_44_373_27_30,/* '<S40>/S-Function' */
    ID_Interpretation_Model_117_44_374_27_30,/* '<S44>/S-Function' */
    ID_Interpretation_Model_117_44_369_27_30,/* '<S48>/S-Function' */
    ID_Interpretation_Model_117_44_381_27_30,/* '<S52>/S-Function' */
    ID_Interpretation_Model_117_44_902_27_30,/* '<S56>/S-Function' */
    ID_Interpretation_Model_117_44_378_27_30,/* '<S60>/S-Function' */
    ID_Interpretation_Model_117_44_382_27_30,/* '<S64>/S-Function' */
    ID_Interpretation_Model_117_44_371_27_30,/* '<S68>/S-Function' */
    ID_Interpretation_Model_117_44_380_27_30,/* '<S72>/S-Function' */
    ID_Interpretation_Model_117_44_394_27_30,/* '<S78>/S-Function' */
    ID_Interpretation_Model_117_44_393_27_30,/* '<S82>/S-Function' */
    ID_Interpretation_Model_117_516_1976_27_30,/* '<S95>/S-Function' */
    ID_Interpretation_Model_117_516_1966,/* '<S99>/S-Function' */
    ID_Interpretation_Model_117_516_1858_27_30,/* '<S108>/S-Function' */
    ID_Interpretation_Model_117_516_1970_27_30,/* '<S112>/S-Function' */
    ID_Interpretation_Model_117_516_1807_27_30,/* '<S116>/S-Function' */
    ID_Interpretation_Model_117_516_1948_27_30,/* '<S120>/S-Function' */
    ID_Interpretation_Model_117_517_512_27_30,/* '<S139>/S-Function' */
    ID_Interpretation_Model_117_517_508,/* '<S143>/S-Function' */
    ID_Interpretation_Model_117_517_490,/* '<S145>/S-Function' */
    ID_Interpretation_Model_117_517_484,/* '<S148>/S-Function' */
    ID_Interpretation_Model_117_517_496,/* '<S151>/S-Function' */
    ID_Interpretation_Model_117_517_502,/* '<S154>/S-Function' */
    ID_Interpretation_Model_117_517_545_27_30,/* '<S158>/S-Function' */
    ID_Interpretation_Model_117_517_560_27_30,/* '<S162>/S-Function' */
    ID_Interpretation_Model_117_517_561_27_30,/* '<S166>/S-Function' */
    ID_Interpretation_Model_117_517_562_27_30,/* '<S170>/S-Function' */
    ID_Interpretation_Model_117_517_513_27_30,/* '<S174>/S-Function' */
    ID_Interpretation_Model_117_517_514_27_30,/* '<S178>/S-Function' */
    ID_Interpretation_Model_117_517_518_27_30,/* '<S182>/S-Function' */
    ID_Interpretation_Model_117_517_566_27_30,/* '<S190>/S-Function' */
    ID_Interpretation_Model_117_517_567_27_30,/* '<S194>/S-Function' */
    ID_Interpretation_Model_117_517_569_27_30,/* '<S198>/S-Function' */
    ID_Interpretation_Model_117_2101_27_30,/* '<S205>/S-Function' */
    ID_Interpretation_Model_117_2102_27_30,/* '<S209>/S-Function' */
    ID_Interpretation_Model_117_2170_27_30,/* '<S213>/S-Function' */
    ID_Interpretation_Model_120_417_27_30,/* '<S222>/S-Function' */
    ID_Interpretation_Model_120_407_27_30,/* '<S226>/S-Function' */
    ID_Interpretation_Model_120_418_27_30,/* '<S233>/S-Function' */
    ID_Interpretation_Model_120_409_27_30,/* '<S237>/S-Function' */
    ID_Interpretation_Model_495_103_27_30,/* '<S277>/S-Function' */
    ID_Interpretation_Model_506_103_27_30,/* '<S284>/S-Function' */
    ID_Interpretation_Model_517_103_27_30,/* '<S291>/S-Function' */
    ID_Interpretation_Model_528_103_27_30,/* '<S298>/S-Function' */
    NUM_INTERPRETATION_NUMBERS
};

// StateVar table record
typedef struct StateVar_tag
{
    const char* name;                  // name of StateVar
    int requested;                    // counts RequestStateVariable invocations
    SimulinkDatatypeId dtype_id;      // SimulinkDatatypeId of numeric data type
    const char* dtype_name;            // Name of numeric data type
    int element_bytes;                 // byte size of a single element
    int width;                         // number of elements in StateVar value
    void* value_ptr;                   // array of current numeric value
    enum InterpretationNumber interpretation;
                                  // interpretation number feeding this StateVar
}
StateVar_type;

static const char* dtypeStr[] =
{
    "DOUBLE", "SINGLE", "INT8", "UINT8", "INT16", "UINT16", "INT32", "UINT32",
    "BOOLEAN"
};

// ----- State variable table:
static StateVar_type state_var_table[] =
{
    {                                  /* '<S13>/StateVar' */
        "PreAmpAudiopilotHvacDbspl", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_dn,
        ID_Interpretation_Model_117_953_27_30
    },

    {                                  /* '<S14>/StateVar' */
        "PreAmpAudiopilotVehicleSpeed", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_gf,
        ID_Interpretation_Model_117_952_27_30
    },

    {                                  /* '<S25>/StateVar' */
        "PreAmpAudiopilotAudiopilotBassBoostDb", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_o3,
        ID_Interpretation_Model_117_44_372_27_30
    },

    {                                  /* '<S26>/StateVar' */
        "PreAmpAudiopilotAudiopilotMidrangeBoostDb", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_dh,
        ID_Interpretation_Model_117_44_373_27_30
    },

    {                                  /* '<S27>/StateVar' */
        "PreAmpAudiopilotAudiopilotTrebleBoostDb", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_i,
        ID_Interpretation_Model_117_44_374_27_30
    },

    {                                  /* '<S28>/StateVar' */
        "PreAmpAudiopilotDyneqBassBoostDb", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_gl,
        ID_Interpretation_Model_117_44_369_27_30
    },

    {                                  /* '<S29>/StateVar' */
        "PreAmpAudiopilotHfNoiseDbspl", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_jm,
        ID_Interpretation_Model_117_44_381_27_30
    },

    {                                  /* '<S30>/StateVar' */
        "PreAmpAudiopilotIgnoreMicFlag", 0, TSS_BOOLEAN, "boolean", sizeof
        (boolean_T), 1, &Model_InterpretationEngine64_B.In1_jq,
        ID_Interpretation_Model_117_44_902_27_30
    },

    {                                  /* '<S31>/StateVar' */
        "PreAmpAudiopilotLfNoiseDbspl", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_g3,
        ID_Interpretation_Model_117_44_378_27_30
    },

    {                                  /* '<S32>/StateVar' */
        "PreAmpAudiopilotNoiseRatio", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_g,
        ID_Interpretation_Model_117_44_382_27_30
    },

    {                                  /* '<S33>/StateVar' */
        "PreAmpAudiopilotTotalBassBoostDb", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_kr,
        ID_Interpretation_Model_117_44_371_27_30
    },

    {                                  /* '<S34>/StateVar' */
        "PreAmpAudiopilotWbNoiseDbspl", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_nz,
        ID_Interpretation_Model_117_44_380_27_30
    },

    {                                  /* '<S75>/StateVar' */
        "PreAmpAudiopilotAudiopilotBoostGain", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_e,
        ID_Interpretation_Model_117_44_394_27_30
    },

    {                                  /* '<S76>/StateVar' */
        "PreAmpAudiopilotDyneqBoostGain", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_cc,
        ID_Interpretation_Model_117_44_393_27_30
    },

    {                                  /* '<S93>/StateVar' */
        "PreAmpAudiopilotHfNoiseMicPsdLevel", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_py,
        ID_Interpretation_Model_117_516_1976_27_30
    },

    {                                  /* '<S92>/StateVar' */
        "PreAmpAudiopilotHfNoiseNoisePsdLevel", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.NoiseLevel,
        ID_Interpretation_Model_117_516_1966
    },

    {                                  /* '<S106>/StateVar' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionFlatness", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_fv,
        ID_Interpretation_Model_117_516_1858_27_30
    },

    {                                  /* '<S105>/StateVar' */
        "PreAmpAudiopilotHfNoiseImpulseRejectionPmin", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_as,
        ID_Interpretation_Model_117_516_1970_27_30
    },

    {                                  /* '<S102>/StateVar' */
        "PreAmpAudiopilotHfNoisePostSlew", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_b0,
        ID_Interpretation_Model_117_516_1807_27_30
    },

    {                                  /* '<S103>/StateVar' */
        "PreAmpAudiopilotHfNoisePreSlew", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_ny,
        ID_Interpretation_Model_117_516_1948_27_30
    },

    {                                  /* '<S132>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_du,
        ID_Interpretation_Model_117_517_512_27_30
    },

    {                                  /* '<S133>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionGammaTauS", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.State_a,
        ID_Interpretation_Model_117_517_508
    },

    {                                  /* '<S134>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVarianceDb", 0,
        TSS_SINGLE, "single", sizeof(real32_T), 1,
        &Model_InterpretationEngine64_B.State,
        ID_Interpretation_Model_117_517_490
    },

    {                                  /* '<S135>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionMusicVarianceDb", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1,
        &Model_InterpretationEngine64_B.sf_db20_g.State,
        ID_Interpretation_Model_117_517_484
    },

    {                                  /* '<S136>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVarianceDb", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1,
        &Model_InterpretationEngine64_B.sf_db20_co.State,
        ID_Interpretation_Model_117_517_496
    },

    {                                  /* '<S137>/StateVar' */
        "PreAmpAudiopilotLfNoiseImpulseRejectionTotalVarianceDb", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1,
        &Model_InterpretationEngine64_B.sf_db20_pi.State,
        ID_Interpretation_Model_117_517_502
    },

    {                                  /* '<S124>/StateVar' */
        "PreAmpAudiopilotLfNoiseMicLevel", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_dw,
        ID_Interpretation_Model_117_517_545_27_30
    },

    {                                  /* '<S125>/StateVar' */
        "PreAmpAudiopilotLfNoiseMicOut", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_ct,
        ID_Interpretation_Model_117_517_560_27_30
    },

    {                                  /* '<S126>/StateVar' */
        "PreAmpAudiopilotLfNoiseMusicOut", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_ft,
        ID_Interpretation_Model_117_517_561_27_30
    },

    {                                  /* '<S127>/StateVar' */
        "PreAmpAudiopilotLfNoiseNoiseOut", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_o,
        ID_Interpretation_Model_117_517_562_27_30
    },

    {                                  /* '<S128>/StateVar' */
        "PreAmpAudiopilotLfNoisePostSlew", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_a,
        ID_Interpretation_Model_117_517_513_27_30
    },

    {                                  /* '<S129>/StateVar' */
        "PreAmpAudiopilotLfNoisePreSlew", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_pp,
        ID_Interpretation_Model_117_517_514_27_30
    },

    {                                  /* '<S130>/StateVar' */
        "PreAmpAudiopilotLfNoisePreSpeedBound", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_fk,
        ID_Interpretation_Model_117_517_518_27_30
    },

    {                                  /* '<S186>/StateVar' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_j,
        ID_Interpretation_Model_117_517_566_27_30
    },

    {                                  /* '<S187>/StateVar' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_da,
        ID_Interpretation_Model_117_517_567_27_30
    },

    {                                  /* '<S188>/StateVar' */
        "PreAmpAudiopilotLfNoiseSpeedBoundsFlag", 0, TSS_DOUBLE, "double",
        sizeof(real_T), 1, &Model_InterpretationEngine64_B.In1,
        ID_Interpretation_Model_117_517_569_27_30
    },

    {                                  /* '<S201>/StateVar' */
        "PreAmpAudiopilotRatioPostSlew", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_f5,
        ID_Interpretation_Model_117_2101_27_30
    },

    {                                  /* '<S202>/StateVar' */
        "PreAmpAudiopilotRatioPreSlew", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_d0,
        ID_Interpretation_Model_117_2102_27_30
    },

    {                                  /* '<S203>/StateVar' */
        "PreAmpAudiopilotRatioUpdateFlag", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_lh,
        ID_Interpretation_Model_117_2170_27_30
    },

    {                                  /* '<S219>/StateVar' */
        "PreAmpLevelWatchAudiopilotEnvDb", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_n,
        ID_Interpretation_Model_120_417_27_30
    },

    {                                  /* '<S220>/StateVar' */
        "PreAmpLevelWatchAudiopilotLevelDbspl", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_cr,
        ID_Interpretation_Model_120_407_27_30
    },

    {                                  /* '<S230>/StateVar' */
        "PreAmpLevelWatchDyneqEnvDb", 0, TSS_SINGLE, "single", sizeof(real32_T),
        1, &Model_InterpretationEngine64_B.In1_h,
        ID_Interpretation_Model_120_418_27_30
    },

    {                                  /* '<S231>/StateVar' */
        "PreAmpLevelWatchDyneqLevelDbspl", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_p,
        ID_Interpretation_Model_120_409_27_30
    },

    {                                  /* '<S245>/StateVar' */
        "PreAmpMedusaDummyState", 0, TSS_INT32, "int32", sizeof(int32_T), 1,
        &Model_InterpretationEngine64_B.In1_fo,
        ID_Interpretation_Model_141_1195_27_30
    },

    {                                  /* '<S254>/StateVar' */
        "PreAmpMedusaMonoDetectorLevelCenter", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_B.In1_k,
        ID_Interpretation_Model_141_1404_27_30
    },

    {                                  /* '<S252>/StateVar' */
        "PreAmpMedusaMonoDetectorIsStereo", 0, TSS_UINT32, "uint32", sizeof
        (uint32_T), 1, &Model_InterpretationEngine64_B.In1_f,
        ID_Interpretation_Model_141_1466_27_30
    },

    {                                  /* '<S253>/StateVar' */
        "PreAmpMedusaMonoDetectorIsActive", 0, TSS_INT32, "int32", sizeof
        (int32_T), 1, &Model_InterpretationEngine64_B.In1_ez,
        ID_Interpretation_Model_141_1467_27_30
    },

    {                                  /* '<S275>/StateVar' */
        "NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_b,
        ID_Interpretation_Model_495_103_27_30
    },

    {                                  /* '<S282>/StateVar' */
        "NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_d,
        ID_Interpretation_Model_506_103_27_30
    },

    {                                  /* '<S289>/StateVar' */
        "NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_l,
        ID_Interpretation_Model_517_103_27_30
    },

    {                                  /* '<S296>/StateVar' */
        "NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB", 0, TSS_SINGLE,
        "single", sizeof(real32_T), 1, &Model_InterpretationEngine64_B.In1_c,
        ID_Interpretation_Model_528_103_27_30
    },

    {                                  /* '<S305>/StateVar' */
        "PostProcessEnergyLimiterComputedEnergy", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 24, Model_InterpretationEngine64_PostProcess_B.In1_b,
        ID_Interpretation_Model_662_27_30
    },

    {                                  /* '<S306>/StateVar' */
        "PostProcessEnergyLimiterCurGain", 0, TSS_SINGLE, "single", sizeof
        (real32_T), 1, &Model_InterpretationEngine64_PostProcess_B.In1_p,
        ID_Interpretation_Model_663_27_30
    },

    {                                  /* '<S307>/StateVar' */
        "PostProcessEnergyLimiterEnergyThreshold", 0, TSS_SINGLE, "single",
        sizeof(real32_T), 1, &Model_InterpretationEngine64_PostProcess_B.In1,
        ID_Interpretation_Model_664_27_30
    },

    {                                  /* '<S308>/StateVar' */
        "PostProcessEnergyLimiterCurState", 0, TSS_INT16, "int16", sizeof
        (int16_T), 1, &Model_InterpretationEngine64_PostProcess_B.In1_n,
        ID_Interpretation_Model_665_27_30
    },

    {                                  /* '<S309>/StateVar' */
        "PostProcessEnergyLimiterEnableFlag", 0, TSS_INT16, "int16", sizeof
        (int16_T), 1, &Model_InterpretationEngine64_PostProcess_B.In1_g,
        ID_Interpretation_Model_666_27_30
    },
};

// Share table in a public interface for use by top-model
void* Model_InterpretationEngine64_state_var_table = state_var_table;
int Model_InterpretationEngine64_state_var_table_count = sizeof(state_var_table)
    / sizeof(StateVar_type);

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

static StateVar_type* GetStateVarRecord(InterpretEngineIterator iteratorIn)
{
    if ((iteratorIn.model < 0) || (iteratorIn.model >= numInterpretationRoots))
    {
        return 0;                      // model out of range
    }

    InterpretationRoot* theRoot = interpretationRoots[iteratorIn.model];
    if ((iteratorIn.index < 0) || (iteratorIn.index >= *theRoot->statevar_count))
    {
        return 0;                      // index out of range for specified model
    }

    StateVar_type* theTable = *(StateVar_type**)theRoot->statevar_table;
    return &theTable[iteratorIn.index];
}

// Return a state variable iterator if name is recognized, INVALID_INTERPRET_ITERATOR otherwise
InterpretEngineIterator RequestStateVariable(const char* variableName)
{
    InterpretEngineIterator retVal = INVALID_INTERPRET_ITERATOR;
    InterpretEngineIterator iterator;
    StateVar_type* theVar = 0;
    StateVar_type* aRecord;

    // Loop through table searching for a variable name match
    int m;
    for (m = 0; (m < numInterpretationRoots) && (theVar == 0); m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetStateVarRecord(iterator); aRecord;
             aRecord = GetStateVarRecord(iterator))
        {
            if (insensitiveStrcmp(variableName, aRecord->name))
            {
                // Found it!
                theVar = aRecord;
                retVal = iterator;
                break;
            }

            iterator.index++;
        }
    }

    // If a variable was found, mark it as requested and flag the interpretation
    if (theVar)
    {
        theVar->requested++;
        InterpretEngineIterator anInterpretation;
        anInterpretation.model = iterator.model;
        anInterpretation.index = theVar->interpretation;
        TouchInterpretation(anInterpretation);
    }

    return retVal;
}

// Reset all StateVar requested flags to zero
void ClearAllStateRequests()
{
    InterpretEngineIterator iterator;
    StateVar_type* aRecord = 0;
    int m;
    for (m = 0; m < numInterpretationRoots; m++)
    {
        iterator.model = m;
        iterator.index = 0;
        for (aRecord = GetStateVarRecord(iterator); aRecord;
             aRecord = GetStateVarRecord(iterator))
        {
            aRecord->requested = 0;
            iterator.index++;
        }
    }
}

// Return whether the specified StateVar has been requested
int GetStateVarRequested(InterpretEngineIterator stateVarNumberIn)
{
    int requested = 0;
    StateVar_type* aRecord = GetStateVarRecord(stateVarNumberIn);
    if (aRecord)
    {
        requested = aRecord->requested;
    }

    return requested;
}

// Return StateVar name (or NULL if bad number)
const char* GetStateVarName(InterpretEngineIterator stateVarNumberIn)
{
    const char* name = 0;
    StateVar_type* aRecord = GetStateVarRecord(stateVarNumberIn);
    if (aRecord)
    {
        name = aRecord->name;
    }

    return name;
}

const char* GetFirstStateVarName(InterpretEngineIterator* stateVarNumberIn)
{
    if (!stateVarNumberIn)
        return 0;
    stateVarNumberIn->model = 0;
    stateVarNumberIn->index = 0;
    const char* aName = GetStateVarName(*stateVarNumberIn);
    if (aName == 0)
    {
        // First model had none. Try next:
        return GetNextStateVarName(stateVarNumberIn);
    }

    return aName;
}

const char* GetNextStateVarName(InterpretEngineIterator* stateVarNumberIn)
{
    if (!stateVarNumberIn)
        return 0;

    // Check for next name in current model
    stateVarNumberIn->index++;
    const char* aName = GetStateVarName(*stateVarNumberIn);

    // If no more - try the next model
    if (0 == aName)
    {
        // Name not found - so try the next model(s)
        stateVarNumberIn->index = 0;
        while ((0 == aName) && (++(stateVarNumberIn->model) <
                                numInterpretationRoots))
        {
            // name not found - so try the next model
            aName = GetStateVarName(*stateVarNumberIn);
        }
    }

    return aName;
}

// TYPED_PRINT performs the print
// Assumed:srcArray,numElem,buf,bufSize
#define TYPED_PRINT(STYPE,FMTSTR)      for (int index = 0; index < numElem; index++){ STYPE srcVal = ((STYPE *)srcArray)[index]; if (bufSize > 1){ int used=0; if(srcFix.factor){ used = snprintf(buf, bufSize, " %lf", (double)(srcVal)*srcFix.factor); } else { used = snprintf(buf, bufSize, FMTSTR, srcVal); } bufSize -= used; buf += used; }}

// This snippet of code used by StateVarSFunc.tlc (same file found in top folder)

// Decode fixed point data types
typedef struct FixedInfo_tag
{
    int unsupportedType;
    int isSigned;
    int intDTypeId;
    int totalBits;
    int fractionalBits;
    double factor;
}
FixedInfo;

static FixedInfo DecodeFixedTypeName(const char* typeName)
{
    FixedInfo info;
    char signedChar;
    info.unsupportedType = 0;
    info.factor = 0;
    int numFound = sscanf(typeName, "%cfix%d_En%d", &signedChar, &info.totalBits,
                          &info.fractionalBits);
    if (numFound == 3)
    {
        info.factor = 1.0/(1 << info.fractionalBits);
        info.isSigned = (signedChar == 's') ? 1 : 0;
        int bytesInInt = (info.totalBits + 7) / 8;
        switch (bytesInInt)
        {
          case 1:
            info.intDTypeId = (info.isSigned) ? TSS_INT8 : TSS_UINT8;
            break;

          case 2:
            info.intDTypeId = (info.isSigned) ? TSS_INT16 : TSS_UINT16;
            break;

          case 3:
            info.intDTypeId = (info.isSigned) ? TSS_INT32 : TSS_UINT32;
            break;

          case 4:
            info.intDTypeId = (info.isSigned) ? TSS_INT32 : TSS_UINT32;
            break;

          default:
            info.unsupportedType = 1;
            break;
        }
    }
    else
    {
        info.unsupportedType = 1;
    }

    return info;
}

// Receive a new interpreted value, resetting request flag & printing value to buffer
// returns char count placed in buffer
int ReceiveInterpretation(InterpretEngineIterator stateVarNumberIn, char
    * bufferIn, int bufferSizeIn)
{
    // bail out if the specified StateVar receiver is not found
    StateVar_type* aRecord = GetStateVarRecord(stateVarNumberIn);
    if (!aRecord)
        return 0;

    // Clear out the request. We have received it!
    aRecord->requested = 0;

    // Receive the input datatype array & print
    SimulinkDatatypeId dTypeId = aRecord->dtype_id;
    void* srcArray = aRecord->value_ptr;
    int numElem = aRecord->width;
    char* buf = bufferIn;
    int bufSize = bufferSizeIn;
    int nameChars = 0;
    FixedInfo srcFix = DecodeFixedTypeName(aRecord->dtype_name);
    if (srcFix.factor)
    {
        // When decoding a fixed point type, set the dTypeId to the
        // integer format of the data. Then... the srcfix.factor will
        // be used to convert to floating point
        dTypeId = srcFix.intDTypeId;

        // output the fixed point type name
        nameChars = snprintf(buf, bufSize, "%s %s", aRecord->name,
                             aRecord->dtype_name);
    }
    else
    {
        // for regular types, use our all-caps type names
        nameChars = snprintf(buf, bufSize, "%s %s", aRecord->name,
                             dtypeStr[aRecord->dtype_id]);
    }

    bufSize -= nameChars;
    buf += nameChars;
    switch (dTypeId)
    {
      case TSS_DOUBLE:
        {
            TYPED_PRINT(double, " %lf")
        }
            break;

          case TSS_SINGLE:
            {
                TYPED_PRINT(float, " %f")
            }
                break;

              case TSS_INT8:
                {
                    TYPED_PRINT(int8_T, " %i")
                }
                    break;

                  case TSS_UINT8:
                    {
                        TYPED_PRINT(uint8_T, " %u")
                    }
                        break;

                      case TSS_INT16:
                        {
                            TYPED_PRINT(int16_T, " %i")
                        }
                            break;

                          case TSS_UINT16:
                            {
                                TYPED_PRINT(uint16_T, " %u")
                            }
                                break;

                              case TSS_INT32:
                                {
                                    TYPED_PRINT(int32_T, " %i")
                                }
                                    break;

                                  case TSS_UINT32:
                                    {
                                        TYPED_PRINT(uint32_T, " %u")
                                    }
                                        break;

                                      case TSS_BOOLEAN:
                                        {
                                            TYPED_PRINT(int8_T, " %i")
                                        }
                                            break;
                                        }

                                        return (bufferSizeIn - bufSize);
                                    }

                                    // Return the first StateVar  that has been requested (or INVALID_INTERPRETATION if none)
                                    InterpretEngineIterator
                                        FindFirstRequestedStateVar()
                                    {
                                        InterpretEngineIterator retVal =
                                            INVALID_INTERPRET_ITERATOR;
                                        InterpretEngineIterator theFirst;
                                        int m;
                                        StateVar_type* aRecord;
                                        for (m = 0; m < numInterpretationRoots;
                                                m++)
                                        {
                                            theFirst.model = m;
                                            theFirst.index = 0;
                                            for (aRecord = GetStateVarRecord
                                                    (theFirst); aRecord;
                                                 aRecord = GetStateVarRecord
                                                    (theFirst))
                                            {
                                                if (aRecord->requested != 0)
                                                {
                                                    // Found it!
                                                    retVal = theFirst;
                                                    break;
                                                }

                                                theFirst.index++;
                                            }
                                        }

                                        return retVal;
                                    }

                                    // Return the next StateVar that has been requested (or -1 if no more)
                                    InterpretEngineIterator
                                        FindNextRequestedStateVar
                                        (InterpretEngineIterator afterThisOne)
                                    {
                                        InterpretEngineIterator retVal =
                                            INVALID_INTERPRET_ITERATOR;
                                        InterpretEngineIterator nextOne;
                                        nextOne.index = afterThisOne.index + 1;
                                        int m;
                                        int foundIt = 0;
                                        StateVar_type* aRecord;
                                        for (m = afterThisOne.model; (0 ==
                                                foundIt) && (m <
                                                numInterpretationRoots); m++)
                                        {
                                            nextOne.model = m;
                                            for (aRecord = GetStateVarRecord
                                                    (nextOne); aRecord;
                                                 aRecord = GetStateVarRecord
                                                    (nextOne))
                                            {
                                                if (aRecord->requested != 0)
                                                {
                                                    // Found it!
                                                    foundIt = 1;
                                                    retVal = nextOne;
                                                    break;
                                                }

                                                // move on to the next interpretation
                                                nextOne.index++;
                                            }

                                            // Reset the index in preparation for the next model search
                                            nextOne.index = 0;
                                        }

                                        return retVal;
                                    }

                                    /*
                                     * File trailer for generated code.
                                     *
                                     * [EOF]
                                     */
