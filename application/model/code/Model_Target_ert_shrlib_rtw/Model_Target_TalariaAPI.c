/*
 * File: Model_Target_TalariaAPI.c
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

#include "rtwtypes.h"
#include "ASDID.h"
#include "Model_Target_TalariaAPI.h"
#include "Model_Target_TOP_Access.h"   // for TOP access request handler
#include "Model_Target_RTC_REQ_RSP.h"  // for RTC msg handler

// Declare prototype of RTC's notification service handler
int Model_Target_ServiceRtcNotifications(void* pNtfBuf, uint32_t ntfBufSize);

#include "Model_Target_SCH_API.h"      // for SCH msg handler

// Declare prototype of TSP's notification service handler
int Model_Target_ServiceTspNotification(void* pNtfBuf, uint32_t ntfBufSize);

#include "Model_Target_TSP_Capture.h"  // for TSP msg handler

/** @ingroup ASDID
 * Top level asynchronous message handler accepting inbound
 * request and potentially generating a response. The inbound request
 * may relate to any ASDID based service such as RTCs or TOPs.
 * If the request has an associated response, this function's return
 * code will indicate how many bytes were consumed in pRspBuf.
 * Even if the request fails, the return code here should be positive
 * here indicating the size of the response. The status code INSIDE
 * the response can indicate the failure. @see AsdIdStatus_type
 * Negative values returned from this function use ASDSTATUS codes-
 * e.g. ASDSTATUS_RSP_BUFFER_SMALL indicates a response (even an
 * error response) could not be created in the provided rspBufSize.
 *  @param pReqBuf Request buffer containing request
 *  @param reqBufSize number of bytes used in the request buffer
 *  @param pRspBuf Response buffer to receive response of @ref AsdIdStatus_type
 *  @param rspBufSize Size of available bytes provided for the response to fill
 *  @return Returns the total number of bytes utilized in the response buffer, or
 *          ASDSTATUS_RSP_BUFFER_SMALL if the response would not fit. Note that the
 *          response itself may contain an error statusCode based on processing
 *          the request. Some request messages never return responses.
 * @see AsdIdStatus_type for the header format of the response
 * @see ASDID_IS_ERROR to detect error payloads in the response payload status
 */
int Model_Target_HandleAsdIdRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize)
{
    int retVal = 0;
    uint32_t asdId = ((uint32_t*)pReqBuf)[0];
    if (ASDID_IS_TOP(asdId))
    {
        retVal = Model_Target_HandleTopRequest(pReqBuf,reqBufSize,pRspBuf,
            rspBufSize);
    }

    if (ASDID_IS_RTC(asdId))
    {
        retVal = Model_Target_HandleRtcRequest(pReqBuf,reqBufSize,pRspBuf,
            rspBufSize);
    }

    if (ASDID_IS_SCH(asdId))
    {
        retVal = Model_Target_HandleSchRequest(pReqBuf,reqBufSize,pRspBuf,
            rspBufSize);
    }

    if (ASDID_IS_TSP(asdId))
    {
        retVal = Model_Target_HandleTspRequest(pReqBuf,reqBufSize,pRspBuf,
            rspBufSize);
    }

    return retVal;
}

/** @ingroup ASDID
 * Top level notification servicing - polling for request completion as well as
 * creating notification message payloads upon completion. When no notification
 * payload is returned, it means all notifications have been serviced for the
 * current audio frame. However, if a notification payload *is* returned, then
 * this routine can be called again (repeatedly) until no payload is returned.
 * All notifications have a message ID and caller handle matching their original
 * request and a statusCode of ASDSTATUS_RTC_NOTIFICATION.
 * NOTE: the same thread that handlers ASDID requests must be responsible for
 * servicing notifications as well. The two routines must not operate at the
 * same time or race conditions can lead to faulty operation.
 *  @param pNtfBuf Empty buffer read to receive a notification message.
 *  @param ntfBufSize Size of buffer in bytes.
 *  @returns Number of bytes used in the provided notification buffer (pNtfBuf).
 *          Return Value | Meaning
 *           ----------- | :--------
 *               0       | All done. No use in calling this again until audio processing happens.
 *             > 0       | A notification was returned with this many bytes used in buffer. Line up more buffer space and call again if you can.
 *             < 0       | Error: buffer is too small. This is how many bytes are needed for the buffer (in negative form)
 * @ingroup rtc
 * @see AsdIdStatus_type for format of each notification message's header
 */
int Model_Target_ServiceNotifications(void* pNtfBuf, uint32_t ntfBufSize)
{
    int retVal = 0;

    // Handle RTC notifications
    if (retVal == 0)
    {
        retVal = Model_Target_ServiceRtcNotifications(pNtfBuf, ntfBufSize);
    }

    // Handle TSP notifications
    if (retVal == 0)
    {
        retVal = Model_Target_ServiceTspNotification(pNtfBuf, ntfBufSize);
    }

    return retVal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
