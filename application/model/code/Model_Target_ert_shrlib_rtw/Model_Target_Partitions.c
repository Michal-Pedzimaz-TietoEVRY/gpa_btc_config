/*
 * File: Model_Target_Partitions.c
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

#include "Model_Target_Partitions.h"
#include "Model_Target_TalariaAPI.h"   // for global async routing table

// Datatype for RTC tables
struct Model_Target_RTC_REQ_RSP_tag;
extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0000;
extern uint32_t RtcDispatchTable0000Count;

#ifdef RTCROOT_G0P0
#undef RTCROOT_G0P0
#endif

#define RTCROOT_G0P0                   &RtcDispatchTable0000, &RtcDispatchTable0000Count

extern void* TopGroup0Partition0[];
extern uint32_t TopGroup0Partition0Size[];

#ifdef TOPROOT_G0P0
#undef TOPROOT_G0P0
#endif

#define TOPROOT_G0P0                   &TopGroup0Partition0, TopGroup0Partition0Size, 1

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0204;
extern uint32_t RtcDispatchTable0204Count;

#ifdef RTCROOT_G2P4
#undef RTCROOT_G2P4
#endif

#define RTCROOT_G2P4                   &RtcDispatchTable0204, &RtcDispatchTable0204Count

extern void* TopGroup2Partition4[];
extern uint32_t TopGroup2Partition4Size[];

#ifdef TOPROOT_G2P4
#undef TOPROOT_G2P4
#endif

#define TOPROOT_G2P4                   &TopGroup2Partition4, TopGroup2Partition4Size, 120

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0211;
extern uint32_t RtcDispatchTable0211Count;

#ifdef RTCROOT_G2P11
#undef RTCROOT_G2P11
#endif

#define RTCROOT_G2P11                  &RtcDispatchTable0211, &RtcDispatchTable0211Count

extern void* TopGroup2Partition11[];
extern uint32_t TopGroup2Partition11Size[];

#ifdef TOPROOT_G2P11
#undef TOPROOT_G2P11
#endif

#define TOPROOT_G2P11                  &TopGroup2Partition11, TopGroup2Partition11Size, 8

extern void* TopGroup2Partition2[];
extern uint32_t TopGroup2Partition2Size[];

#ifdef TOPROOT_G2P2
#undef TOPROOT_G2P2
#endif

#define TOPROOT_G2P2                   &TopGroup2Partition2, TopGroup2Partition2Size, 8

extern void* TopGroup2Partition3[];
extern uint32_t TopGroup2Partition3Size[];

#ifdef TOPROOT_G2P3
#undef TOPROOT_G2P3
#endif

#define TOPROOT_G2P3                   &TopGroup2Partition3, TopGroup2Partition3Size, 48

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0205;
extern uint32_t RtcDispatchTable0205Count;

#ifdef RTCROOT_G2P5
#undef RTCROOT_G2P5
#endif

#define RTCROOT_G2P5                   &RtcDispatchTable0205, &RtcDispatchTable0205Count

extern void* TopGroup2Partition5[];
extern uint32_t TopGroup2Partition5Size[];

#ifdef TOPROOT_G2P5
#undef TOPROOT_G2P5
#endif

#define TOPROOT_G2P5                   &TopGroup2Partition5, TopGroup2Partition5Size, 85

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0206;
extern uint32_t RtcDispatchTable0206Count;

#ifdef RTCROOT_G2P6
#undef RTCROOT_G2P6
#endif

#define RTCROOT_G2P6                   &RtcDispatchTable0206, &RtcDispatchTable0206Count

extern void* TopGroup2Partition6[];
extern uint32_t TopGroup2Partition6Size[];

#ifdef TOPROOT_G2P6
#undef TOPROOT_G2P6
#endif

#define TOPROOT_G2P6                   &TopGroup2Partition6, TopGroup2Partition6Size, 14

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0207;
extern uint32_t RtcDispatchTable0207Count;

#ifdef RTCROOT_G2P7
#undef RTCROOT_G2P7
#endif

#define RTCROOT_G2P7                   &RtcDispatchTable0207, &RtcDispatchTable0207Count

extern void* TopGroup2Partition8[];
extern uint32_t TopGroup2Partition8Size[];

#ifdef TOPROOT_G2P8
#undef TOPROOT_G2P8
#endif

#define TOPROOT_G2P8                   &TopGroup2Partition8, TopGroup2Partition8Size, 2

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0201;
extern uint32_t RtcDispatchTable0201Count;

#ifdef RTCROOT_G2P1
#undef RTCROOT_G2P1
#endif

#define RTCROOT_G2P1                   &RtcDispatchTable0201, &RtcDispatchTable0201Count

extern void* TopGroup2Partition1[];
extern uint32_t TopGroup2Partition1Size[];

#ifdef TOPROOT_G2P1
#undef TOPROOT_G2P1
#endif

#define TOPROOT_G2P1                   &TopGroup2Partition1, TopGroup2Partition1Size, 1

extern void* TopGroup2Partition13[];
extern uint32_t TopGroup2Partition13Size[];

#ifdef TOPROOT_G2P13
#undef TOPROOT_G2P13
#endif

#define TOPROOT_G2P13                  &TopGroup2Partition13, TopGroup2Partition13Size, 2

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0209;
extern uint32_t RtcDispatchTable0209Count;

#ifdef RTCROOT_G2P9
#undef RTCROOT_G2P9
#endif

#define RTCROOT_G2P9                   &RtcDispatchTable0209, &RtcDispatchTable0209Count

extern void* TopGroup2Partition9[];
extern uint32_t TopGroup2Partition9Size[];

#ifdef TOPROOT_G2P9
#undef TOPROOT_G2P9
#endif

#define TOPROOT_G2P9                   &TopGroup2Partition9, TopGroup2Partition9Size, 23

extern void* TopGroup2Partition10[];
extern uint32_t TopGroup2Partition10Size[];

#ifdef TOPROOT_G2P10
#undef TOPROOT_G2P10
#endif

#define TOPROOT_G2P10                  &TopGroup2Partition10, TopGroup2Partition10Size, 7

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0200;
extern uint32_t RtcDispatchTable0200Count;

#ifdef RTCROOT_G2P0
#undef RTCROOT_G2P0
#endif

#define RTCROOT_G2P0                   &RtcDispatchTable0200, &RtcDispatchTable0200Count

extern void* TopGroup2Partition0[];
extern uint32_t TopGroup2Partition0Size[];

#ifdef TOPROOT_G2P0
#undef TOPROOT_G2P0
#endif

#define TOPROOT_G2P0                   &TopGroup2Partition0, TopGroup2Partition0Size, 29

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0100;
extern uint32_t RtcDispatchTable0100Count;

#ifdef RTCROOT_G1P0
#undef RTCROOT_G1P0
#endif

#define RTCROOT_G1P0                   &RtcDispatchTable0100, &RtcDispatchTable0100Count

extern void* TopGroup1Partition0[];
extern uint32_t TopGroup1Partition0Size[];

#ifdef TOPROOT_G1P0
#undef TOPROOT_G1P0
#endif

#define TOPROOT_G1P0                   &TopGroup1Partition0, TopGroup1Partition0Size, 122

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0300;
extern uint32_t RtcDispatchTable0300Count;

#ifdef RTCROOT_G3P0
#undef RTCROOT_G3P0
#endif

#define RTCROOT_G3P0                   &RtcDispatchTable0300, &RtcDispatchTable0300Count

extern void* TopGroup3Partition0[];
extern uint32_t TopGroup3Partition0Size[];

#ifdef TOPROOT_G3P0
#undef TOPROOT_G3P0
#endif

#define TOPROOT_G3P0                   &TopGroup3Partition0, TopGroup3Partition0Size, 17

extern struct Model_Target_RTC_REQ_RSP_tag* RtcDispatchTable0500;
extern uint32_t RtcDispatchTable0500Count;

#ifdef RTCROOT_G5P0
#undef RTCROOT_G5P0
#endif

#define RTCROOT_G5P0                   &RtcDispatchTable0500, &RtcDispatchTable0500Count

extern void* TopGroup5Partition0[];
extern uint32_t TopGroup5Partition0Size[];

#ifdef TOPROOT_G5P0
#undef TOPROOT_G5P0
#endif

#define TOPROOT_G5P0                   &TopGroup5Partition0, TopGroup5Partition0Size, 3

// ------------------------------------------------------------
// TOP-LEVEL MODEL: GLOBAL ASYNCHRONOUS ROUTING TABLE
// ------------------------------------------------------------
void* TalariaAsyncRoutingTable[256] =
{
    0
};

void RegisterPartition(int groupNumber, int partitionNumber, PartitionRoot_type*
                       partitionRootIn)
{
    // add to global async routing table
    int index = (groupNumber * 16U) + partitionNumber;
    TalariaAsyncRoutingTable[index] = partitionRootIn;
}

PartitionRoot_type* GetPartitionRoot(int groupNumber, int partitionNumber)
{
    int index = (groupNumber * 16U) + partitionNumber;
    PartitionRoot_type* theRoot = (PartitionRoot_type*)
        (TalariaAsyncRoutingTable[index]);
    return theRoot;
}

PartitionRoot_type* GetPartitionRootByIndex(int partitionIndex)
{
    PartitionRoot_type* theRoot = (PartitionRoot_type*)
        (TalariaAsyncRoutingTable[partitionIndex&0xff]);
    return theRoot;
}

#ifndef RTCROOT_G0P0
#define RTCROOT_G0P0                   0,0
#endif

#ifndef TOPROOT_G0P0
#define TOPROOT_G0P0                   0,0,0
#endif

#ifndef TSPROOT_G0P0
#define TSPROOT_G0P0                   0,0
#endif

PartitionRoot_type RootG0P0 =
{
    RTCROOT_G0P0,
    TOPROOT_G0P0,
    TSPROOT_G0P0
};

extern void* TspDispatchTable0204[];
extern uint32_t TspDispatchTable0204Count;

#ifdef TSPROOT_G2P4
#undef TSPROOT_G2P4
#endif

#define TSPROOT_G2P4                   &TspDispatchTable0204, &TspDispatchTable0204Count
#ifndef RTCROOT_G2P4
#define RTCROOT_G2P4                   0,0
#endif

#ifndef TOPROOT_G2P4
#define TOPROOT_G2P4                   0,0,0
#endif

#ifndef TSPROOT_G2P4
#define TSPROOT_G2P4                   0,0
#endif

PartitionRoot_type RootG2P4 =
{
    RTCROOT_G2P4,
    TOPROOT_G2P4,
    TSPROOT_G2P4
};

#ifndef RTCROOT_G2P11
#define RTCROOT_G2P11                  0,0
#endif

#ifndef TOPROOT_G2P11
#define TOPROOT_G2P11                  0,0,0
#endif

#ifndef TSPROOT_G2P11
#define TSPROOT_G2P11                  0,0
#endif

PartitionRoot_type RootG2P11 =
{
    RTCROOT_G2P11,
    TOPROOT_G2P11,
    TSPROOT_G2P11
};

extern void* TspDispatchTable0202[];
extern uint32_t TspDispatchTable0202Count;

#ifdef TSPROOT_G2P2
#undef TSPROOT_G2P2
#endif

#define TSPROOT_G2P2                   &TspDispatchTable0202, &TspDispatchTable0202Count
#ifndef RTCROOT_G2P2
#define RTCROOT_G2P2                   0,0
#endif

#ifndef TOPROOT_G2P2
#define TOPROOT_G2P2                   0,0,0
#endif

#ifndef TSPROOT_G2P2
#define TSPROOT_G2P2                   0,0
#endif

PartitionRoot_type RootG2P2 =
{
    RTCROOT_G2P2,
    TOPROOT_G2P2,
    TSPROOT_G2P2
};

extern void* TspDispatchTable0203[];
extern uint32_t TspDispatchTable0203Count;

#ifdef TSPROOT_G2P3
#undef TSPROOT_G2P3
#endif

#define TSPROOT_G2P3                   &TspDispatchTable0203, &TspDispatchTable0203Count
#ifndef RTCROOT_G2P3
#define RTCROOT_G2P3                   0,0
#endif

#ifndef TOPROOT_G2P3
#define TOPROOT_G2P3                   0,0,0
#endif

#ifndef TSPROOT_G2P3
#define TSPROOT_G2P3                   0,0
#endif

PartitionRoot_type RootG2P3 =
{
    RTCROOT_G2P3,
    TOPROOT_G2P3,
    TSPROOT_G2P3
};

#ifndef RTCROOT_G2P5
#define RTCROOT_G2P5                   0,0
#endif

#ifndef TOPROOT_G2P5
#define TOPROOT_G2P5                   0,0,0
#endif

#ifndef TSPROOT_G2P5
#define TSPROOT_G2P5                   0,0
#endif

PartitionRoot_type RootG2P5 =
{
    RTCROOT_G2P5,
    TOPROOT_G2P5,
    TSPROOT_G2P5
};

#ifndef RTCROOT_G2P6
#define RTCROOT_G2P6                   0,0
#endif

#ifndef TOPROOT_G2P6
#define TOPROOT_G2P6                   0,0,0
#endif

#ifndef TSPROOT_G2P6
#define TSPROOT_G2P6                   0,0
#endif

PartitionRoot_type RootG2P6 =
{
    RTCROOT_G2P6,
    TOPROOT_G2P6,
    TSPROOT_G2P6
};

#ifndef RTCROOT_G2P7
#define RTCROOT_G2P7                   0,0
#endif

#ifndef TOPROOT_G2P7
#define TOPROOT_G2P7                   0,0,0
#endif

#ifndef TSPROOT_G2P7
#define TSPROOT_G2P7                   0,0
#endif

PartitionRoot_type RootG2P7 =
{
    RTCROOT_G2P7,
    TOPROOT_G2P7,
    TSPROOT_G2P7
};

#ifndef RTCROOT_G2P8
#define RTCROOT_G2P8                   0,0
#endif

#ifndef TOPROOT_G2P8
#define TOPROOT_G2P8                   0,0,0
#endif

#ifndef TSPROOT_G2P8
#define TSPROOT_G2P8                   0,0
#endif

PartitionRoot_type RootG2P8 =
{
    RTCROOT_G2P8,
    TOPROOT_G2P8,
    TSPROOT_G2P8
};

#ifndef RTCROOT_G2P1
#define RTCROOT_G2P1                   0,0
#endif

#ifndef TOPROOT_G2P1
#define TOPROOT_G2P1                   0,0,0
#endif

#ifndef TSPROOT_G2P1
#define TSPROOT_G2P1                   0,0
#endif

PartitionRoot_type RootG2P1 =
{
    RTCROOT_G2P1,
    TOPROOT_G2P1,
    TSPROOT_G2P1
};

#ifndef RTCROOT_G2P13
#define RTCROOT_G2P13                  0,0
#endif

#ifndef TOPROOT_G2P13
#define TOPROOT_G2P13                  0,0,0
#endif

#ifndef TSPROOT_G2P13
#define TSPROOT_G2P13                  0,0
#endif

PartitionRoot_type RootG2P13 =
{
    RTCROOT_G2P13,
    TOPROOT_G2P13,
    TSPROOT_G2P13
};

#ifndef RTCROOT_G2P9
#define RTCROOT_G2P9                   0,0
#endif

#ifndef TOPROOT_G2P9
#define TOPROOT_G2P9                   0,0,0
#endif

#ifndef TSPROOT_G2P9
#define TSPROOT_G2P9                   0,0
#endif

PartitionRoot_type RootG2P9 =
{
    RTCROOT_G2P9,
    TOPROOT_G2P9,
    TSPROOT_G2P9
};

#ifndef RTCROOT_G2P10
#define RTCROOT_G2P10                  0,0
#endif

#ifndef TOPROOT_G2P10
#define TOPROOT_G2P10                  0,0,0
#endif

#ifndef TSPROOT_G2P10
#define TSPROOT_G2P10                  0,0
#endif

PartitionRoot_type RootG2P10 =
{
    RTCROOT_G2P10,
    TOPROOT_G2P10,
    TSPROOT_G2P10
};

#ifndef RTCROOT_G2P0
#define RTCROOT_G2P0                   0,0
#endif

#ifndef TOPROOT_G2P0
#define TOPROOT_G2P0                   0,0,0
#endif

#ifndef TSPROOT_G2P0
#define TSPROOT_G2P0                   0,0
#endif

PartitionRoot_type RootG2P0 =
{
    RTCROOT_G2P0,
    TOPROOT_G2P0,
    TSPROOT_G2P0
};

#ifndef RTCROOT_G1P0
#define RTCROOT_G1P0                   0,0
#endif

#ifndef TOPROOT_G1P0
#define TOPROOT_G1P0                   0,0,0
#endif

#ifndef TSPROOT_G1P0
#define TSPROOT_G1P0                   0,0
#endif

PartitionRoot_type RootG1P0 =
{
    RTCROOT_G1P0,
    TOPROOT_G1P0,
    TSPROOT_G1P0
};

extern void* TspDispatchTable0100[];
extern uint32_t TspDispatchTable0100Count;

#ifdef TSPROOT_G1P0
#undef TSPROOT_G1P0
#endif

#define TSPROOT_G1P0                   &TspDispatchTable0100, &TspDispatchTable0100Count

extern void* TspDispatchTable0300[];
extern uint32_t TspDispatchTable0300Count;

#ifdef TSPROOT_G3P0
#undef TSPROOT_G3P0
#endif

#define TSPROOT_G3P0                   &TspDispatchTable0300, &TspDispatchTable0300Count
#ifndef RTCROOT_G3P0
#define RTCROOT_G3P0                   0,0
#endif

#ifndef TOPROOT_G3P0
#define TOPROOT_G3P0                   0,0,0
#endif

#ifndef TSPROOT_G3P0
#define TSPROOT_G3P0                   0,0
#endif

PartitionRoot_type RootG3P0 =
{
    RTCROOT_G3P0,
    TOPROOT_G3P0,
    TSPROOT_G3P0
};

#ifndef RTCROOT_G5P0
#define RTCROOT_G5P0                   0,0
#endif

#ifndef TOPROOT_G5P0
#define TOPROOT_G5P0                   0,0,0
#endif

#ifndef TSPROOT_G5P0
#define TSPROOT_G5P0                   0,0
#endif

PartitionRoot_type RootG5P0 =
{
    RTCROOT_G5P0,
    TOPROOT_G5P0,
    TSPROOT_G5P0
};

// ----- Register partitions with routing table-----:
void Model_Target_InitPartitions()
{
    RegisterPartition(0U,0U,&RootG0P0);
    RegisterPartition(2U,4U,&RootG2P4);
    RegisterPartition(2U,11U,&RootG2P11);
    RegisterPartition(2U,2U,&RootG2P2);
    RegisterPartition(2U,3U,&RootG2P3);
    RegisterPartition(2U,5U,&RootG2P5);
    RegisterPartition(2U,6U,&RootG2P6);
    RegisterPartition(2U,7U,&RootG2P7);
    RegisterPartition(2U,8U,&RootG2P8);
    RegisterPartition(2U,1U,&RootG2P1);
    RegisterPartition(2U,13U,&RootG2P13);
    RegisterPartition(2U,9U,&RootG2P9);
    RegisterPartition(2U,10U,&RootG2P10);
    RegisterPartition(2U,0U,&RootG2P0);
    RegisterPartition(1U,0U,&RootG1P0);
    RegisterPartition(3U,0U,&RootG3P0);
    RegisterPartition(5U,0U,&RootG5P0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
