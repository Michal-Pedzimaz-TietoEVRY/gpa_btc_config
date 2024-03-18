/*
 * File: rtmodel.c
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

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Model_Target_step(int_T tid)
{
    switch (tid)
    {
      case 0 :
        Model_Target_step0();
        break;

      case 1 :
        Model_Target_step1();
        break;

      case 2 :
        Model_Target_step2();
        break;

      case 3 :
        Model_Target_step3();
        break;

      case 4 :
        Model_Target_step4();
        break;

      case 5 :
        Model_Target_step5();
        break;

      case 6 :
        Model_Target_step6();
        break;

      case 7 :
        Model_Target_step7();
        break;

      case 8 :
        Model_Target_step8();
        break;

      default :
        /* do nothing */
        break;
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
