/*
 * File: MedusaPostHoligram.c
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
#include "MedusaPostHoligram.h"
#include <string.h>

/* Declare variables for internal data of system '<S561>/MedusaPostHoligram' */
B_MedusaPostHoligram_Model_TranslationEngine64_T
    Model_TranslationEngine64_MedusaPostHoligram_B;

/* Output and update for function-call system: '<S1044>/tfunc' */
void FuncTranslation_Model_150_574_67_18(void)
{
    /* Outputs for Function Call SubSystem: '<S1042>/Subsystem' */
    /* SignalConversion generated from: '<S1043>/Bus Selector' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'TranslateTrigger/tfunc': '<S1045>:1' */
    /* '<S1045>:1:3' f(); */
    memcpy(&Model_TranslationEngine64_MedusaPostHoligram_B.Value[0],
           &Model_TranslationEngine64_MedusaPostHoligram_B.RoutingMap.Value[0],
           24U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S1042>/Subsystem' */
}

/* Initialize for atomic system: '<S561>/MedusaPostHoligram' */
void Model_TranslationEngine64_MedusaPostHoligram_initialize(void)
{
    (void) memset((void *) &Model_TranslationEngine64_MedusaPostHoligram_B, 0,
                  sizeof(B_MedusaPostHoligram_Model_TranslationEngine64_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
