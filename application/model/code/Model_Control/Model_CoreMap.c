/*
 * Model_CoreMap.c : Determine core assignment from token.
 * The Talaria partitioning tool generates this file.
 */


#include "rtwtypes.h"
#include "ASDID.h"
#include "Model_CoreMap.h"

static const char coreMap[256];

char GetCoreFromToken(unsigned int tokenIn)
{
    char coreNum = 0;
    if (ASDID_IS_SCH(tokenIn))
    {
        coreNum = SCHID_CORE_NUM(tokenIn);
    }
    else
    {
        int groupNumber = ASDID_GROUP(tokenIn);
        int partitionNumber = ASDID_PARTITION(tokenIn);
        int lookupIndex = (groupNumber * 16U) + partitionNumber;
        coreNum = coreMap[lookupIndex];
    }
    return coreNum;
}

char GetCoreFromAtomicId(unsigned int atomicIdIn)
{
    return (atomicIdIn < sizeof(coreMap)) ? coreMap[atomicIdIn] : 255U;
}

static const char coreMap[256] = 
{
    1U, // Group 0, Partition 0 is on Target
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    1U, // Group 1, Partition 0 is on Target
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    1U, // Group 2, Partition 0 is on Target
    1U, // Group 2, Partition 1 is on Target
    1U, // Group 2, Partition 2 is on Target
    1U, // Group 2, Partition 3 is on Target
    1U, // Group 2, Partition 4 is on Target
    1U, // Group 2, Partition 5 is on Target
    1U, // Group 2, Partition 6 is on Target
    1U, // Group 2, Partition 7 is on Target
    1U, // Group 2, Partition 8 is on Target
    1U, // Group 2, Partition 9 is on Target
    1U, // Group 2, Partition 10 is on Target
    1U, // Group 2, Partition 11 is on Target
    1U, // Group 2, Partition 12 is on Target
    1U, // Group 2, Partition 13 is on Target
    255U, // not used
    255U, // not used
    1U, // Group 3, Partition 0 is on Target
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    1U, // Group 5, Partition 0 is on Target
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
    255U, // not used
};

