/*
 * File: Model_Target_RTC_NTF.c
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
#include "Model_Target.h"
               // for access to signal buffers for sequence, caller handle, etc.
#include "Model_Target_RTC_IDs.h"      // for RTCIDs and NTF payload formats
#include "ASDID.h"        // for AsdIdStatus_type and ASDSTATUS_RTC_NOTIFICATION

// Function pointer type for RTC request completion checking
typedef void (*RTC_NTF_Check)( void );

// Function pointer type for RTC notification message packing
typedef void (*RTC_NTF_Pack)(void* pNtfBuf);

// Struct for notification table. Note some datatypes must match
// variables defined by Simulink-generated code (uint32_T,boolean_T)
typedef struct RTC_NotificationTable_tag
{
    uint32_t message_id;
    RTC_NTF_Check check_complete_func;
    RTC_NTF_Pack pack_notification_func;
    uint32_t ntf_payload_bytes;
    uint32_T* requested_sequence_ptr;
    uint32_T* requested_caller_handle_ptr;
    boolean_T* is_completed_ptr;
    uint32_t completed_sequence;
    uint32_t completed_caller_handle;
    uint32_t last_sent_sequence;
}
Model_Target_RTC_NTF_type;

// ----- Function prototypes for request completion checking:
extern void RtcNtfCheck_PreAmpVolumeCfgSet( void );
extern void RtcNtfCheck_PreAmpBalance_CfgSet( void );
extern void RtcNtfCheck_PreAmpMedusaSurroundLevelControlIndex( void );
extern void RtcNtfCheck_PreAmpMuteControlSet( void );
extern void RtcNtfCheck_PreAmpFadeControlSet( void );
extern void RtcNtfCheck_PreAmpSleepingBeautyDRSet( void );
extern void RtcNtfCheck_PreAmpSleepingBeautyFRSet( void );
extern void RtcNtfCheck_PreAmpBassSet( void );
extern void RtcNtfCheck_PreAmpMidrangeSet( void );
extern void RtcNtfCheck_PreAmpTrebleSet( void );
extern void RtcNtfCheck_NearAnn1Ann1VolumeSet( void );
extern void RtcNtfCheck_NearAnn2Ann2VolumeSet( void );
extern void RtcNtfCheck_NearAnn3Ann3VolumeSet( void );
extern void RtcNtfCheck_NearAnn4Ann4VolumeSet( void );
extern void RtcNtfCheck_NearAnn1Ann1MuteSet( void );
extern void RtcNtfCheck_NearAnn2Ann2MuteSet( void );
extern void RtcNtfCheck_NearAnn3Ann3MuteSet( void );
extern void RtcNtfCheck_NearAnn4Ann4MuteSet( void );
extern void RtcNtfCheck_PostProcessMuteSet( void );
extern void RtcNtfCheck_PostProcessEnergyLimiterEnableLimiter( void );

// ----- Function prototypes for notification message packing:
extern void RtcNtfPack_PreAmpVolumeCfgSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpBalance_CfgSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpMedusaSurroundLevelControlIndex(void* pNtfBuf);
extern void RtcNtfPack_PreAmpMuteControlSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpFadeControlSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpSleepingBeautyDRSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpSleepingBeautyFRSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpBassSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpMidrangeSet(void* pNtfBuf);
extern void RtcNtfPack_PreAmpTrebleSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn1Ann1VolumeSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn2Ann2VolumeSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn3Ann3VolumeSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn4Ann4VolumeSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn1Ann1MuteSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn2Ann2MuteSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn3Ann3MuteSet(void* pNtfBuf);
extern void RtcNtfPack_NearAnn4Ann4MuteSet(void* pNtfBuf);
extern void RtcNtfPack_PostProcessMuteSet(void* pNtfBuf);
extern void RtcNtfPack_PostProcessEnergyLimiterEnableLimiter(void* pNtfBuf);

// ----- The NOTIFY TABLE -----:
static Model_Target_RTC_NTF_type notify_table[] =
{
    // Name: PreAmpMedusaSurroundLevelControlIndex '<S1113>/NTF Trigger'
    {
        RTCID_PreAmpMedusaSurroundLevelControlIndex,
        &RtcNtfCheck_PreAmpMedusaSurroundLevelControlIndex,
        &RtcNtfPack_PreAmpMedusaSurroundLevelControlIndex, sizeof
        (PreAmpMedusaSurroundLevelControlIndex_NTF_T),/*16 char*/
        &(Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut.REQ_sequence),
        &(Model_TargetPreAmpMedusaSurroundLevelControlIndexRtcOut.REQ_caller_handle),
        &Model_Target_Medusa5H1Part3_B.AND,
        0, 0, 0
    },

    // Name: PreAmpBassSet '<S1527>/NTF Trigger'
    {
        RTCID_PreAmpBassSet, &RtcNtfCheck_PreAmpBassSet,
        &RtcNtfPack_PreAmpBassSet, sizeof(PreAmpBassSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpBassSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpBassSetRtcOut.REQ_caller_handle),
        &Model_Target_PreAmpPart1_B.done_b,
        0, 0, 0
    },

    // Name: PreAmpMidrangeSet '<S1545>/NTF Trigger'
    {
        RTCID_PreAmpMidrangeSet, &RtcNtfCheck_PreAmpMidrangeSet,
        &RtcNtfPack_PreAmpMidrangeSet, sizeof(PreAmpMidrangeSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpMidrangeSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpMidrangeSetRtcOut.REQ_caller_handle),
        &Model_Target_PreAmpPart1_B.done_k,
        0, 0, 0
    },

    // Name: PreAmpTrebleSet '<S1581>/NTF Trigger'
    {
        RTCID_PreAmpTrebleSet, &RtcNtfCheck_PreAmpTrebleSet,
        &RtcNtfPack_PreAmpTrebleSet, sizeof(PreAmpTrebleSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpTrebleSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpTrebleSetRtcOut.REQ_caller_handle),
        &Model_Target_PreAmpPart1_B.done,
        0, 0, 0
    },

    // Name: PostProcessMuteSet '<S2221>/NTF Trigger'
    {
        RTCID_PostProcessMuteSet, &RtcNtfCheck_PostProcessMuteSet,
        &RtcNtfPack_PostProcessMuteSet, sizeof(PostProcessMuteSet_NTF_T),/*16 char*/
        &(Model_TargetPostProcessMuteSetRtcOut.REQ_sequence),
        &(Model_TargetPostProcessMuteSetRtcOut.REQ_caller_handle),
        &Model_Target_PostProcess_B.done,
        0, 0, 0
    },

    // Name: PostProcessEnergyLimiterEnableLimiter '<S2191>/NTF Trigger'
    {
        RTCID_PostProcessEnergyLimiterEnableLimiter,
        &RtcNtfCheck_PostProcessEnergyLimiterEnableLimiter,
        &RtcNtfPack_PostProcessEnergyLimiterEnableLimiter, sizeof
        (PostProcessEnergyLimiterEnableLimiter_NTF_T),/*16 char*/
        &(Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_sequence),
        &(Model_TargetPostProcessEnergyLimiterEnableLimiterRtcOut.REQ_caller_handle),
        &Model_Target_PostProcess_B.DataTypeConversion_f,
        0, 0, 0
    },

    // Name: PreAmpMuteControlSet '<S1390>/NTF Trigger'
    {
        RTCID_PreAmpMuteControlSet, &RtcNtfCheck_PreAmpMuteControlSet,
        &RtcNtfPack_PreAmpMuteControlSet, sizeof(PreAmpMuteControlSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpMuteControlSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpMuteControlSetRtcOut.REQ_caller_handle),
        &Model_Target_B.AND,
        0, 0, 0
    },

    // Name: PreAmpFadeControlSet '<S1360>/NTF Trigger'
    {
        RTCID_PreAmpFadeControlSet, &RtcNtfCheck_PreAmpFadeControlSet,
        &RtcNtfPack_PreAmpFadeControlSet, sizeof(PreAmpFadeControlSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpFadeControlSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpFadeControlSetRtcOut.REQ_caller_handle),
        &Model_Target_B.AND_h,
        0, 0, 0
    },

    // Name: PreAmpSleepingBeautyDRSet '<S1433>/NTF Trigger'
    {
        RTCID_PreAmpSleepingBeautyDRSet, &RtcNtfCheck_PreAmpSleepingBeautyDRSet,
        &RtcNtfPack_PreAmpSleepingBeautyDRSet, sizeof
        (PreAmpSleepingBeautyDRSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpSleepingBeautyDRSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpSleepingBeautyDRSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_c,
        0, 0, 0
    },

    // Name: PreAmpSleepingBeautyFRSet '<S1453>/NTF Trigger'
    {
        RTCID_PreAmpSleepingBeautyFRSet, &RtcNtfCheck_PreAmpSleepingBeautyFRSet,
        &RtcNtfPack_PreAmpSleepingBeautyFRSet, sizeof
        (PreAmpSleepingBeautyFRSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpSleepingBeautyFRSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpSleepingBeautyFRSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_o,
        0, 0, 0
    },

    // Name: NearAnn1Ann1VolumeSet '<S1908>/NTF Trigger'
    {
        RTCID_NearAnn1Ann1VolumeSet, &RtcNtfCheck_NearAnn1Ann1VolumeSet,
        &RtcNtfPack_NearAnn1Ann1VolumeSet, sizeof(NearAnn1Ann1VolumeSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn1Ann1VolumeSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn1Ann1VolumeSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_d1,
        0, 0, 0
    },

    // Name: NearAnn2Ann2VolumeSet '<S1988>/NTF Trigger'
    {
        RTCID_NearAnn2Ann2VolumeSet, &RtcNtfCheck_NearAnn2Ann2VolumeSet,
        &RtcNtfPack_NearAnn2Ann2VolumeSet, sizeof(NearAnn2Ann2VolumeSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn2Ann2VolumeSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn2Ann2VolumeSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_d,
        0, 0, 0
    },

    // Name: NearAnn3Ann3VolumeSet '<S2068>/NTF Trigger'
    {
        RTCID_NearAnn3Ann3VolumeSet, &RtcNtfCheck_NearAnn3Ann3VolumeSet,
        &RtcNtfPack_NearAnn3Ann3VolumeSet, sizeof(NearAnn3Ann3VolumeSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn3Ann3VolumeSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn3Ann3VolumeSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_ix,
        0, 0, 0
    },

    // Name: NearAnn4Ann4VolumeSet '<S2148>/NTF Trigger'
    {
        RTCID_NearAnn4Ann4VolumeSet, &RtcNtfCheck_NearAnn4Ann4VolumeSet,
        &RtcNtfPack_NearAnn4Ann4VolumeSet, sizeof(NearAnn4Ann4VolumeSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn4Ann4VolumeSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn4Ann4VolumeSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done,
        0, 0, 0
    },

    // Name: NearAnn1Ann1MuteSet '<S1886>/NTF Trigger'
    {
        RTCID_NearAnn1Ann1MuteSet, &RtcNtfCheck_NearAnn1Ann1MuteSet,
        &RtcNtfPack_NearAnn1Ann1MuteSet, sizeof(NearAnn1Ann1MuteSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn1Ann1MuteSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn1Ann1MuteSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_g,
        0, 0, 0
    },

    // Name: NearAnn2Ann2MuteSet '<S1966>/NTF Trigger'
    {
        RTCID_NearAnn2Ann2MuteSet, &RtcNtfCheck_NearAnn2Ann2MuteSet,
        &RtcNtfPack_NearAnn2Ann2MuteSet, sizeof(NearAnn2Ann2MuteSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn2Ann2MuteSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn2Ann2MuteSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_n,
        0, 0, 0
    },

    // Name: NearAnn3Ann3MuteSet '<S2046>/NTF Trigger'
    {
        RTCID_NearAnn3Ann3MuteSet, &RtcNtfCheck_NearAnn3Ann3MuteSet,
        &RtcNtfPack_NearAnn3Ann3MuteSet, sizeof(NearAnn3Ann3MuteSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn3Ann3MuteSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn3Ann3MuteSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_e,
        0, 0, 0
    },

    // Name: NearAnn4Ann4MuteSet '<S2126>/NTF Trigger'
    {
        RTCID_NearAnn4Ann4MuteSet, &RtcNtfCheck_NearAnn4Ann4MuteSet,
        &RtcNtfPack_NearAnn4Ann4MuteSet, sizeof(NearAnn4Ann4MuteSet_NTF_T),/*16 char*/
        &(Model_TargetNearAnn4Ann4MuteSetRtcOut.REQ_sequence),
        &(Model_TargetNearAnn4Ann4MuteSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_i,
        0, 0, 0
    },

    // Name: PreAmpVolumeCfgSet '<S535>/NTF Trigger'
    {
        RTCID_PreAmpVolumeCfgSet, &RtcNtfCheck_PreAmpVolumeCfgSet,
        &RtcNtfPack_PreAmpVolumeCfgSet, sizeof(PreAmpVolumeCfgSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpVolumeCfgSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpVolumeCfgSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_ef,
        0, 0, 0
    },

    // Name: PreAmpBalance_CfgSet '<S564>/NTF Trigger'
    {
        RTCID_PreAmpBalance_CfgSet, &RtcNtfCheck_PreAmpBalance_CfgSet,
        &RtcNtfPack_PreAmpBalance_CfgSet, sizeof(PreAmpBalance_CfgSet_NTF_T),/*16 char*/
        &(Model_TargetPreAmpBalance_CfgSetRtcOut.REQ_sequence),
        &(Model_TargetPreAmpBalance_CfgSetRtcOut.REQ_caller_handle),
        &Model_Target_B.done_p,
        0, 0, 0
    },

    // End Sentinel to prevent empty initializer if no NTF payloads.
    {
        0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0
    }
};

/** Services RTC Notifications - polling for request completion as well as
 * creating notification message payloads upon completion. When no notification
 * payload is returned, it means all notifications have been serviced for the
 * current audio frame. However, if a notification payload *is* returned, then
 * this routine can be called again (repeatedly) until no payload is returned.
 * All notifications have a message ID and caller handle matching their original
 * request and a statusCode of ASDSTATUS_RTC_NOTIFICATION.
 * NOTE: the same thread that services RTC requests must be responsible for
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
int Model_Target_ServiceRtcNotifications(void* pNtfBuf, uint32_t ntfBufSize)
{
    // Note assumption of single service thread that handles both
    // RTC message requests and this notification handler.

    // This static
    static uint32_t tableIdx = 0;
    int retVal = 0;

    // Calculate the table size - subtract one for the End Sentinel
    uint32_t tableSize = (sizeof(notify_table) / sizeof
                          (Model_Target_RTC_NTF_type)) - 1;
    uint32_t entryCount = tableSize;
    while (entryCount--)
    {
        Model_Target_RTC_NTF_type* pTableEntry = &notify_table[tableIdx];
        if (++tableIdx >= tableSize)
        {
            tableIdx = 0;
        }

        // Poll for completion if the current request is still pending
        if (*pTableEntry->requested_sequence_ptr !=
                pTableEntry->completed_sequence)
        {
            // Not done last we checked. Check again now:
            pTableEntry->check_complete_func();

            // If the request is done now, capture status
            if (*pTableEntry->is_completed_ptr)
            {
                pTableEntry->completed_sequence =
                    *pTableEntry->requested_sequence_ptr;
                pTableEntry->completed_caller_handle =
                    *pTableEntry->requested_caller_handle_ptr;
            }
        }

        // Attempt to send notification if a completed sequence is waiting to send
        if (pTableEntry->last_sent_sequence != pTableEntry->completed_sequence)
        {
            uint8_t ntfBufOK = (ntfBufSize >= pTableEntry->ntf_payload_bytes) &&
                pNtfBuf;
            if (ntfBufOK)
            {
                AsdIdStatus_type* statusHdr = (AsdIdStatus_type*)pNtfBuf;
                pTableEntry->pack_notification_func(pNtfBuf);

                // Overwrite status code and caller handle written by the pack function.
                // NTF payloads all have the same "I'm a notification" status which is
                // easier to place here than on the model canvas.
                // Lack of outbound buffer space might queue up NTF sends... so when
                // we *do* send a NTF we use the completed caller handle gathered
                // at the time the NTF check succeeded. Between then and now, a new
                // request might have come in. So- maybe the NTF pack above could grab
                // some overly fresh data, but at least the caller handle below will match
                // the request that finished.
                statusHdr->msgId = pTableEntry->message_id;
                statusHdr->callerHandle = pTableEntry->completed_caller_handle;
                statusHdr->statusCode = ASDSTATUS_RTC_NOTIFICATION;
                retVal = pTableEntry->ntf_payload_bytes;
                pTableEntry->last_sent_sequence =
                    pTableEntry->completed_sequence;
            }
            else
            {
                // indicate how many bytes should have been given - just make it negative
                retVal = (0 - pTableEntry->ntf_payload_bytes);
            }
            break;
        }
    }

    return retVal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
