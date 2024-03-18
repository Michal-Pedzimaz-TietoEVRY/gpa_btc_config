/*
 * File: Model_Target_TOP_Access.h
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

#ifndef RTW_HEADER_Model_Target_TOP_Access_h_
#define RTW_HEADER_Model_Target_TOP_Access_h_

// ------------------------------------------------------------
// ACCESS ROUTINE TO GET AND SET TOP VALUES
// ------------------------------------------------------------
// See ASDID.h for returned ASDSTATUS codes.
int Model_Target_HandleTopRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize);

#endif                               /* RTW_HEADER_Model_Target_TOP_Access_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
