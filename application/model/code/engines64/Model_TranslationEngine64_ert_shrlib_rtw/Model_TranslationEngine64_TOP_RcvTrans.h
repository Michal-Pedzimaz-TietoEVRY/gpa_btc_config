/*
 * File: Model_TranslationEngine64_TOP_RcvTrans.h
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

#ifndef RTW_HEADER_Model_TranslationEngine64_TOP_RcvTrans_h_
#define RTW_HEADER_Model_TranslationEngine64_TOP_RcvTrans_h_
#include "Model_TranslationEngine64_TranslateTrigger.h" // for TranslateEngineIterator

// Dump the translated value to provided buffer & updating sightings
// Returns number of chars filled in buffer
int DumpTranslatedValue(TranslateEngineIterator rcvTransNumberIn, char
                        * bufferInOut, int bufferSizeIn);

// Get the name of a TOP, or NULL if not found
const char* GetTopName(TranslateEngineIterator topNumberIn);

// Local model translation table
extern void* Model_TranslationEngine64_TOP_RcvTrans_table;
extern int Model_TranslationEngine64_TOP_RcvTrans_table_count;

#endif                /* RTW_HEADER_Model_TranslationEngine64_TOP_RcvTrans_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
