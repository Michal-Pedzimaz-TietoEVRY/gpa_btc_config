/*
 * File: Model_InterpretationEngine64_InterpretError.h
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

#ifndef RTW_HEADER_Model_InterpretationEngine64_InterpretError_h_
#define RTW_HEADER_Model_InterpretationEngine64_InterpretError_h_

// MATLAB's loadlibrary does not support variadic functions (...)
// and gives the warning that looks something like:
//   Warning: The data type 'error' used by function InterpretError does not exist.
// So to eliminate these warnings, the following variadic functions
// have been removed from Model_InterpretationEngine64_InterpretTrigger.h which is used
// to load interpretation DLLs into MATLAB. Instead, these functions
// are declared here out of the way.

// Report a interpretation error (works like printf)
// Called from the model code
void InterpretError(const char* formatString, ...);

#endif           /* RTW_HEADER_Model_InterpretationEngine64_InterpretError_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
