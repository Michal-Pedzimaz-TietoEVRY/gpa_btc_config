/*
 * File: Model_Target_RTC_REQ_RSP.h
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

#ifndef RTW_HEADER_Model_Target_RTC_REQ_RSP_h_
#define RTW_HEADER_Model_Target_RTC_REQ_RSP_h_

// ------------------------------------------------------------
// ACCESS ROUTINE TO HANDLE RTC REQUEST/RESPONSE
// ------------------------------------------------------------
// Handle inbound request. Returns number of bytes in response
// or negative value upon error (See ASDID.h for returned ASDSTATUS codes.)
int Model_Target_HandleRtcRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize);

#endif                              /* RTW_HEADER_Model_Target_RTC_REQ_RSP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
