/*
 * File: PostProcess.c
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

#include "Model_InterpretationEngine64.h"
#include "PostProcess.h"
#include <string.h>
#include "rtwtypes.h"
#include "tsp_capture_settings.h"

/* Declare variables for internal data of system '<S4>/PostProcess' */
B_PostProcess_Model_InterpretationEngine64_T
    Model_InterpretationEngine64_PostProcess_B;

/* Output and update for function-call system: '<S311>/ifunc' */
void Model_InterpretationEngine64_ifunc_em(void)
{
    /* Outputs for Function Call SubSystem: '<S310>/Subsystem' */
    /* SignalConversion generated from: '<S312>/In1' incorporates:
     *  M-S-Function: '<S305>/TSP'
     */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S313>:1' */
    /* '<S313>:1:3' f(); */
    memcpy(&Model_InterpretationEngine64_PostProcess_B.In1_b[0],
           &Model_InterpretationEngine64_PostProcess_B.TSP[0], 24U * sizeof
           (real32_T));

    /* End of Outputs for SubSystem: '<S310>/Subsystem' */
}

/* Output and update for function-call system: '<S315>/ifunc' */
void Model_InterpretationEngine64_ifunc_lv(void)
{
    /* Outputs for Function Call SubSystem: '<S314>/Subsystem' */
    /* SignalConversion generated from: '<S316>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S317>:1' */
    /* '<S317>:1:3' f(); */
    Model_InterpretationEngine64_PostProcess_B.In1_p =
        Model_InterpretationEngine64_PostProcess_B.TSP_b;

    /* End of Outputs for SubSystem: '<S314>/Subsystem' */
}

/* Output and update for function-call system: '<S319>/ifunc' */
void Model_InterpretationEngine64_ifunc_jl(void)
{
    /* Outputs for Function Call SubSystem: '<S318>/Subsystem' */
    /* SignalConversion generated from: '<S320>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S321>:1' */
    /* '<S321>:1:3' f(); */
    Model_InterpretationEngine64_PostProcess_B.In1 =
        Model_InterpretationEngine64_PostProcess_B.TSP_f;

    /* End of Outputs for SubSystem: '<S318>/Subsystem' */
}

/* Output and update for function-call system: '<S323>/ifunc' */
void Model_InterpretationEngine64_ifunc_jt(void)
{
    /* Outputs for Function Call SubSystem: '<S322>/Subsystem' */
    /* SignalConversion generated from: '<S324>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S325>:1' */
    /* '<S325>:1:3' f(); */
    Model_InterpretationEngine64_PostProcess_B.In1_n =
        Model_InterpretationEngine64_PostProcess_B.TSP_i;

    /* End of Outputs for SubSystem: '<S322>/Subsystem' */
}

/* Output and update for function-call system: '<S327>/ifunc' */
void Model_InterpretationEngine64_ifunc_cj(void)
{
    /* Outputs for Function Call SubSystem: '<S326>/Subsystem' */
    /* SignalConversion generated from: '<S328>/In1' */
    /*  This function serves only to invoke a function trigger output */
    /* MATLAB Function 'InterpretTrigger/ifunc': '<S329>:1' */
    /* '<S329>:1:3' f(); */
    Model_InterpretationEngine64_PostProcess_B.In1_g =
        Model_InterpretationEngine64_PostProcess_B.TSP_fc;

    /* End of Outputs for SubSystem: '<S326>/Subsystem' */
}

/* Initialize for atomic system: '<S4>/PostProcess' */
void Model_InterpretationEngine64_PostProcess_initialize(void)
{
    (void) memset((void *) &Model_InterpretationEngine64_PostProcess_B, 0,
                  sizeof(B_PostProcess_Model_InterpretationEngine64_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
