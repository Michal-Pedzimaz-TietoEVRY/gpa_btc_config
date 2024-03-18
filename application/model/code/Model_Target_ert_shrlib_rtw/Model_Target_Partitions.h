/*
 * File: Model_Target_Partitions.h
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

#ifndef RTW_HEADER_Model_Target_Partitions_h_
#define RTW_HEADER_Model_Target_Partitions_h_
#include <stdint.h>

// Each partition has one of these to gain access to async components
typedef struct PartitionRoot_tag
{
    void* rtcTable;
    uint32_t* rtcCount;
    void* topTable;
    uint32_t* topSize;
    uint32_t topCount;
    void* tspTable;
    uint32_t* tspCount;
}
PartitionRoot_type;

// Partition root access for RTC, TOP, TSP handlers
PartitionRoot_type* GetPartitionRoot(int groupNumber, int partitionNumber);

// Partition root access for TSP scans by partitionindex
PartitionRoot_type* GetPartitionRootByIndex(int partitionIndex);

// Partition routing table initialization called by model init
void Model_Target_InitPartitions( void );

// top-level model registration of partitions
void RegisterPartition(int groupNumber, int partitionNumber, PartitionRoot_type*
                       partitionRootIn);

#endif                               /* RTW_HEADER_Model_Target_Partitions_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
