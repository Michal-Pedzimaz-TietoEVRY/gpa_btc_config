/*
 * File: VLS.c
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

#include "VLS.h"
#include "pooliir_hexagon.h"
#include "qhblas.h"
#include "qhcomplex.h"
#include "qhdsp.h"
#include "qhdsp_common.h"
#include "qhdsp_iir.h"
#include "qhmath.h"
#include "rtwtypes.h"
#include <string.h>
#include "fir_hexagon.h"
#include "Model_Target.h"
#include "circbuf.h"
#include "MedusaPostHoligram.h"
#include "Model_Target_private.h"
#include "PoolDelayStorage.h"
#include "Model_Target_FirGenericStorage.h"

/* Declare variables for internal data of system '<S33>/VLS' */
B_VLS_Model_Target_T Model_Target_VLS_B;
DW_VLS_Model_Target_T Model_Target_VLS_DW;

/* Output and update for function-call system: '<S1486>/init' */
void InitTrigger_Model_232_8_34_50_172_156(void)
{
    /* MATLAB Function: '<S1485>/PoolIirInit' */
    /* MATLAB Function: '<S1485>/PoolIirInit' incorporates:
     *  S-Function (TOP_MEX): '<S1482>/TOP'
     *  Selector: '<S1475>/Selector'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1491>:1' */
    /* '<S1491>:1:3' init(); */
    /*  Process function for Pooliir */
    /*  */
    /*  Parameters: */
    /*    x:                  input channels [frame size x number of inputs] */
    /*    NumStages:          array of filter lengths [NumChannels x 1] */
    /*    CoeffsTarget:       coefficient sets [total filter lengths x 1] */
    /*  */
    /*  Global parameters: */
    /*    states:             working memory set up during roommode reset/init CRL */
    /*                        function call [StatesSize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/PoolIirInit': '<S1488>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1488>:1:15' [FrameSize, NumChannels] = size(x); */
    /*  Initialize variables */
    /*  Get the work memory size */
    /* '<S1488>:1:21' StatesSize = numel(states); */
    /*  Output */
    /* '<S1488>:1:24' VariantStr = char(VariantUint8); */
    /* '<S1488>:1:26' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S1488>:1:28' else */
    /* '<S1488>:1:29' switch(VariantStr) */
    /* '<S1488>:1:30' case{"Hexagon"} */
    /* '<S1488>:1:31' NumCoeffPerSosStage = 4; */
    /* '<S1488>:1:32' y = pooliir_hexagon_init(single(x), uint32(FrameSize), uint32(NumChannels), uint32(NumStages), single(CoeffsTarget), ... */
    /* '<S1488>:1:33'                                      single(states), uint32(StatesSize),uint32(MaxNumOfThreads), uint32(MaxNumSosStages*NumCoeffPerSosStage)); */
    pooliir_init(&XtalkIIR22535states[0], &XtalkIIR48480PoolIirAudioIn[0], 8U,
                 16U,
                 &(Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRPooliirNumStages
                   [0]), &XtalkIIR25291PoolIirCoeffs[0], &XtalkIIR22535states[0],
                 1937U, 1U, 960U);

    /* '<S1488>:1:34' states(1) = y; */
}

/* Output and update for function-call system: '<S1494>/init' */
void InitTrigger_Model_232_8_34_50_172_192(void)
{
    /* MATLAB Function: '<S1493>/SignalBreakFcn' */
    /* MATLAB Function: '<S1493>/SignalBreakFcn' incorporates:
     *  S-Function (TOP_MEX): '<S1482>/TOP1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1496>:1' */
    /* '<S1496>:1:3' init(); */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/SignalBreak/SignalBreak/SignalBreakFcn': '<S1495>:1' */
    /* '<S1495>:1:3' y = u; */
    memcpy(&XtalkIIR25291PoolIirCoeffs[0],
           &(Model_Target_PreAmp_p10_b0.VLSXtalkCancellationIIRpooliirCoeffs[0]),
           976U * sizeof(real32_T));
}

/* Output and update for function-call system: '<S1503>/init' */
void InitTrigger_Model_232_11_239_99(void)
{
    /* MATLAB Function: '<S1500>/FirGenericInitFcn' */
    /* MATLAB Function: '<S1500>/FirGenericInitFcn' incorporates:
     *  Constant: '<S1473>/filterMapping'
     *  Constant: '<S1473>/inputMapping'
     *  S-Function (TOP_MEX): '<S1473>/TOP2'
     *  Sum: '<S1473>/Add'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1505>:1' */
    /* '<S1505>:1:3' init(); */
    /*  Generic FIR function to work with M inputs, N outputs and K filters */
    /*  */
    /*  Parameters: */
    /*    u:              input channels [frame size x number of inputs] */
    /*    CoeffsTarget:    coefficient sets [total filter lengths x 1] */
    /*    CoeffsLengths:  array of filter lengths [number of filters x 1] */
    /*    InputMapping:   zero-based input mapping for each filter  [number of outputs x 1] */
    /*    CoeffsMapping:  zero-based filter mapping for each filter [number of outputs x 1] */
    /*  */
    /*  Global parameters: */
    /*    States:         array of states [totalBufferSize x 1] */
    /*    CodeWorkMemory: working memory set up during roommode reset/init CRL */
    /*                    function call [codeWorkMemorySize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericInitFcn': '<S1501>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1501>:1:18' [FrameSize, NumInputs]  = size(u); */
    /* '<S1501>:1:19' NumOutputs = numel(InputMapping); */
    /*  Get the work memory and states size */
    /* '<S1501>:1:25' WorkMemorySize = numel(CodeWorkMemory); */
    /* '<S1501>:1:26' StateBufferSize = numel(StateBuffer); */
    /*  Set correct data types */
    /* '<S1501>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
    /* '<S1501>:1:30' NumCoeffSets = uint32(numel(CoeffsLengths)); */
    /* '<S1501>:1:31' FrameSize = uint32(FrameSize); */
    /* '<S1501>:1:32' NumOutputs = uint32(NumOutputs); */
    /* '<S1501>:1:33' NumInputs = uint32(NumInputs); */
    /* '<S1501>:1:34' WorkMemorySize = uint32(WorkMemorySize); */
    /* '<S1501>:1:35' StateBufferSize = uint32(StateBufferSize); */
    /*  Reconstitute Variant */
    /* '<S1501>:1:38' VariantSelect = char(VariantUint8); */
    /* '<S1501>:1:40' switch(VariantSelect) */
    /* '<S1501>:1:52' case {'Hexagon'} */
    /* '<S1501>:1:53' y = fir_hexagon_init(u, CoeffsTarget, StateBuffer, CoeffsLengths, InputMapping, CoeffsMapping, ... */
    /* '<S1501>:1:54'             FrameSize, NumCoeffSets, NumInputs, NumOutputs, CodeWorkMemory); */
    fir_init(&FirD58960CodeWorkMemory[0], &Model_Target_VLS_B.Add[0],
             &FirD45716CoeffsTarget[0], &FirD29151StateBuffer[0],
             &(Model_Target_PreAmp_p10_b0.VLSGenerationDrvPaddedFilterLengths[0]),
             &Model_Target_ConstP.pooled104[0], &Model_Target_ConstP.pooled105[0],
             8U, 20U, 12U, 20U, &FirD58960CodeWorkMemory[0]);

    /* '<S1501>:1:55' CodeWorkMemory(1) = y; */
}

/* Output and update for function-call system: '<S1507>/init' */
void InitTrigger_Model_232_11_239_224(void)
{
    /* MATLAB Function: '<S1506>/SignalBreakFcn' */
    /* MATLAB Function: '<S1506>/SignalBreakFcn' incorporates:
     *  S-Function (TOP_MEX): '<S1473>/TOP'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1509>:1' */
    /* '<S1509>:1:3' init(); */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/SignalBreak/SignalBreak/SignalBreakFcn': '<S1508>:1' */
    /* '<S1508>:1:3' y = u; */
    memcpy(&FirD45716CoeffsTarget[0],
           &(Model_Target_PreAmp_p10_b1.VLSGenerationDrvFIRCoeffs[0]), 5760U *
           sizeof(real32_T));
}

/* Output and update for function-call system: '<S1516>/init' */
void InitTrigger_Model_232_12_239_99(void)
{
    /* MATLAB Function: '<S1513>/FirGenericInitFcn' */
    /* MATLAB Function: '<S1513>/FirGenericInitFcn' incorporates:
     *  Constant: '<S1474>/filterMapping'
     *  Constant: '<S1474>/inputMapping'
     *  S-Function (TOP_MEX): '<S1474>/TOP2'
     *  Sum: '<S1474>/Add'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1518>:1' */
    /* '<S1518>:1:3' init(); */
    /*  Generic FIR function to work with M inputs, N outputs and K filters */
    /*  */
    /*  Parameters: */
    /*    u:              input channels [frame size x number of inputs] */
    /*    CoeffsTarget:    coefficient sets [total filter lengths x 1] */
    /*    CoeffsLengths:  array of filter lengths [number of filters x 1] */
    /*    InputMapping:   zero-based input mapping for each filter  [number of outputs x 1] */
    /*    CoeffsMapping:  zero-based filter mapping for each filter [number of outputs x 1] */
    /*  */
    /*  Global parameters: */
    /*    States:         array of states [totalBufferSize x 1] */
    /*    CodeWorkMemory: working memory set up during roommode reset/init CRL */
    /*                    function call [codeWorkMemorySize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericInitFcn': '<S1514>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1514>:1:18' [FrameSize, NumInputs]  = size(u); */
    /* '<S1514>:1:19' NumOutputs = numel(InputMapping); */
    /*  Get the work memory and states size */
    /* '<S1514>:1:25' WorkMemorySize = numel(CodeWorkMemory); */
    /* '<S1514>:1:26' StateBufferSize = numel(StateBuffer); */
    /*  Set correct data types */
    /* '<S1514>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
    /* '<S1514>:1:30' NumCoeffSets = uint32(numel(CoeffsLengths)); */
    /* '<S1514>:1:31' FrameSize = uint32(FrameSize); */
    /* '<S1514>:1:32' NumOutputs = uint32(NumOutputs); */
    /* '<S1514>:1:33' NumInputs = uint32(NumInputs); */
    /* '<S1514>:1:34' WorkMemorySize = uint32(WorkMemorySize); */
    /* '<S1514>:1:35' StateBufferSize = uint32(StateBufferSize); */
    /*  Reconstitute Variant */
    /* '<S1514>:1:38' VariantSelect = char(VariantUint8); */
    /* '<S1514>:1:40' switch(VariantSelect) */
    /* '<S1514>:1:52' case {'Hexagon'} */
    /* '<S1514>:1:53' y = fir_hexagon_init(u, CoeffsTarget, StateBuffer, CoeffsLengths, InputMapping, CoeffsMapping, ... */
    /* '<S1514>:1:54'             FrameSize, NumCoeffSets, NumInputs, NumOutputs, CodeWorkMemory); */
    fir_init(&FirP56149CodeWorkMemory[0], &Model_Target_VLS_B.Add_b[0],
             &FirP16311CoeffsTarget[0], &FirP33462StateBuffer[0],
             &(Model_Target_PreAmp_p10_b0.VLSGenerationPaxPaddedFilterLengths[0]),
             &Model_Target_ConstP.pooled104[0], &Model_Target_ConstP.pooled105[0],
             8U, 20U, 12U, 20U, &FirP56149CodeWorkMemory[0]);

    /* '<S1514>:1:55' CodeWorkMemory(1) = y; */
}

/* Output and update for function-call system: '<S1520>/init' */
void InitTrigger_Model_232_12_239_224(void)
{
    /* MATLAB Function: '<S1519>/SignalBreakFcn' */
    /* MATLAB Function: '<S1519>/SignalBreakFcn' incorporates:
     *  S-Function (TOP_MEX): '<S1474>/TOP'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1522>:1' */
    /* '<S1522>:1:3' init(); */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/SignalBreak/SignalBreak/SignalBreakFcn': '<S1521>:1' */
    /* '<S1521>:1:3' y = u; */
    memcpy(&FirP16311CoeffsTarget[0],
           &(Model_Target_PreAmp_p10_b1.VLSGenerationPaxFIRCoeffs[0]), 5760U *
           sizeof(real32_T));
}

/* System initialize for atomic system: '<S33>/VLS' */
void Model_Target_VLS_Init(void)
{
    /* user code (Initialize function Body) */

    /* InitTriggerControl '<S1494>/ITC1' */
    InitTrigger_Model_232_8_34_50_172_192();

    /* InitTriggerControl '<S1486>/ITC1' */
    InitTrigger_Model_232_8_34_50_172_156();

    /* InitTriggerControl '<S1507>/ITC1' */
    InitTrigger_Model_232_11_239_224();

    /* InitTriggerControl '<S1503>/ITC1' */
    InitTrigger_Model_232_11_239_99();

    /* InitTriggerControl '<S1520>/ITC1' */
    InitTrigger_Model_232_12_239_224();

    /* InitTriggerControl '<S1516>/ITC1' */
    InitTrigger_Model_232_12_239_99();

    /* '<S1480>:1:15' delayIndex = int32(0); */
}

/* Output and update for atomic system: '<S33>/VLS' */
void Model_Target_VLS(void)
{
    int32_T i;
    int32_T i_0;
    int32_T idxS;
    int32_T j;
    int32_T srcIndex;
    int32_T u1;
    real32_T rtb_y_fd[160];
    real32_T rtb_audioOut_e[128];
    real32_T rtb_ArrayVectorMultiply1[96];
    real32_T rtb_Selector_i[80];
    real32_T rtb_Add_nn[32];
    real32_T tmp;
    static const int8_T tmp_0[12] =
    {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
    };

    static const int8_T tmp_1[10] =
    {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 17
    };

    static const int8_T tmp_2[10] =
    {
        1, 3, 5, 7, 9, 11, 13, 15, 18, 19
    };

    static const int8_T tmp_3[12] =
    {
        6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11
    };

    /* Selector: '<S562>/Selector2' incorporates:
     *  S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1'
     *  Selector: '<S1346>/Selector1'
     */
    for (i_0 = 0; i_0 < 12; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_ArrayVectorMultiply1[idxS + (i_0 << 3)] =
                Model_Target_B.PreAmp2HeadrestDr[(tmp_0[i_0] << 3) + idxS];
        }
    }

    /* End of Selector: '<S562>/Selector2' */

    /* S-Function (sdspdmult2): '<S562>/Array-Vector Multiply' incorporates:
     *  S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1'
     */
    idxS = 0;
    srcIndex = 0;
    for (i_0 = 0; i_0 < 12; i_0++)
    {
        for (j = 0; j < 8; j++)
        {
            rtb_ArrayVectorMultiply1[idxS] *=
                Model_Target_Medusa5H1Part3_B.Merge2[srcIndex];
            idxS++;
        }

        srcIndex++;
    }

    /* End of S-Function (sdspdmult2): '<S562>/Array-Vector Multiply' */
    for (i_0 = 0; i_0 < 96; i_0++)
    {
        /* Sum: '<S1473>/Add' incorporates:
         *  S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1'
         *  Selector: '<S562>/Selector'
         */
        Model_Target_VLS_B.Add[i_0] = rtb_ArrayVectorMultiply1[i_0] +
            Model_Target_B.FRIn[i_0];
    }

    /* MATLAB Function: '<S1500>/FirGenericProcessFcn' incorporates:
     *  Sum: '<S1473>/Add'
     */
    /*  Generic FIR function to work with M inputs, N outputs and K filters */
    /*  */
    /*  Parameters: */
    /*    u:              input channels [frame size x number of inputs] */
    /*    CoeffsTarget:   coefficient sets, translated to target specfic format [total filter lengths x 1] */
    /*    CoeffsLengths:  array of filter lengths [number of filters x 1] */
    /*    InputMapping:   zero-based input mapping for each filter  [number of outputs x 1] */
    /*    CoeffsMapping:  zero-based filter mapping for each filter [number of outputs x 1] */
    /*    VariantStr:     string corresponding to the variant type */
    /*  */
    /*  Global parameters: */
    /*    States:         array of states [totalBufferSize x 1] */
    /*    CodeWorkMemory: working memory set up during roommode reset/init CRL */
    /*                    function call [codeWorkMemorySize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericProcessFcn': '<S1502>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1502>:1:20' [FrameSize, ~]  = size(u); */
    /* '<S1502>:1:21' NumOutputs = numel(InputMapping); */
    /*  Define persistent variables for SharcPlusAccel Variant */
    /*  Set correct data types */
    /* '<S1502>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
    /* '<S1502>:1:30' FrameSize = uint32(FrameSize); */
    /* '<S1502>:1:31' NumOutputs = uint32(NumOutputs); */
    /* '<S1502>:1:32' InputMapping = uint32(InputMapping); */
    /*  Reconstitute Variant */
    /* '<S1502>:1:35' VariantSelect = char(VariantUint8); */
    /*  Simulation */
    /* '<S1502>:1:38' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S1502>:1:58' else */
    /* '<S1502>:1:59' switch(VariantSelect) */
    /* '<S1502>:1:65' case {'Hexagon'} */
    /* '<S1502>:1:66' y = fir_hexagon_process(u, CodeWorkMemory, NumOutputs); */
    fir_process(&rtb_y_fd[0], &Model_Target_VLS_B.Add[0],
                &FirD58960CodeWorkMemory[0], 20U);

    /* Selector: '<S1497>/Selector' */
    for (i_0 = 0; i_0 < 10; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_Selector_i[idxS + (i_0 << 3)] = rtb_y_fd[(tmp_1[i_0] << 3) +
                idxS];
        }
    }

    /* End of Selector: '<S1497>/Selector' */

    /* Sum: '<S1497>/Matrix Sum' incorporates:
     *  Selector: '<S1497>/Selector'
     */
    for (srcIndex = 0; srcIndex < 8; srcIndex++)
    {
        tmp = -0.0F;
        for (i_0 = 0; i_0 < 10; i_0++)
        {
            tmp += rtb_Selector_i[(i_0 << 3) + srcIndex];
        }

        rtb_Add_nn[srcIndex] = tmp;
    }

    /* End of Sum: '<S1497>/Matrix Sum' */

    /* Selector: '<S1497>/Selector1' */
    for (i_0 = 0; i_0 < 10; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_Selector_i[idxS + (i_0 << 3)] = rtb_y_fd[(tmp_2[i_0] << 3) +
                idxS];
        }
    }

    /* End of Selector: '<S1497>/Selector1' */

    /* Sum: '<S1497>/Matrix Sum1' incorporates:
     *  Selector: '<S1497>/Selector1'
     */
    for (srcIndex = 0; srcIndex < 8; srcIndex++)
    {
        tmp = -0.0F;
        for (i_0 = 0; i_0 < 10; i_0++)
        {
            tmp += rtb_Selector_i[(i_0 << 3) + srcIndex];
        }

        rtb_Add_nn[srcIndex + 8] = tmp;
    }

    /* End of Sum: '<S1497>/Matrix Sum1' */

    /* Selector: '<S562>/Selector3' incorporates:
     *  S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1'
     *  Selector: '<S1346>/Selector1'
     */
    for (i_0 = 0; i_0 < 12; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_ArrayVectorMultiply1[idxS + (i_0 << 3)] =
                Model_Target_B.PreAmp2HeadrestDr[(tmp_3[i_0] << 3) + idxS];
        }
    }

    /* End of Selector: '<S562>/Selector3' */

    /* S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1' */
    idxS = 0;
    srcIndex = 0;
    for (i_0 = 0; i_0 < 12; i_0++)
    {
        for (j = 0; j < 8; j++)
        {
            rtb_ArrayVectorMultiply1[idxS] *=
                Model_Target_Medusa5H1Part3_B.Merge3[srcIndex];
            idxS++;
        }

        srcIndex++;
    }

    /* End of S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1' */
    for (i_0 = 0; i_0 < 96; i_0++)
    {
        /* Sum: '<S1474>/Add' incorporates:
         *  S-Function (sdspdmult2): '<S562>/Array-Vector Multiply1'
         *  Selector: '<S562>/Selector1'
         */
        Model_Target_VLS_B.Add_b[i_0] = Model_Target_B.FRIn[i_0 + 96] +
            rtb_ArrayVectorMultiply1[i_0];
    }

    /* MATLAB Function: '<S1513>/FirGenericProcessFcn' incorporates:
     *  Sum: '<S1474>/Add'
     */
    /*  Generic FIR function to work with M inputs, N outputs and K filters */
    /*  */
    /*  Parameters: */
    /*    u:              input channels [frame size x number of inputs] */
    /*    CoeffsTarget:   coefficient sets, translated to target specfic format [total filter lengths x 1] */
    /*    CoeffsLengths:  array of filter lengths [number of filters x 1] */
    /*    InputMapping:   zero-based input mapping for each filter  [number of outputs x 1] */
    /*    CoeffsMapping:  zero-based filter mapping for each filter [number of outputs x 1] */
    /*    VariantStr:     string corresponding to the variant type */
    /*  */
    /*  Global parameters: */
    /*    States:         array of states [totalBufferSize x 1] */
    /*    CodeWorkMemory: working memory set up during roommode reset/init CRL */
    /*                    function call [codeWorkMemorySize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericProcessFcn': '<S1515>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1515>:1:20' [FrameSize, ~]  = size(u); */
    /* '<S1515>:1:21' NumOutputs = numel(InputMapping); */
    /*  Define persistent variables for SharcPlusAccel Variant */
    /*  Set correct data types */
    /* '<S1515>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
    /* '<S1515>:1:30' FrameSize = uint32(FrameSize); */
    /* '<S1515>:1:31' NumOutputs = uint32(NumOutputs); */
    /* '<S1515>:1:32' InputMapping = uint32(InputMapping); */
    /*  Reconstitute Variant */
    /* '<S1515>:1:35' VariantSelect = char(VariantUint8); */
    /*  Simulation */
    /* '<S1515>:1:38' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S1515>:1:58' else */
    /* '<S1515>:1:59' switch(VariantSelect) */
    /* '<S1515>:1:65' case {'Hexagon'} */
    /* '<S1515>:1:66' y = fir_hexagon_process(u, CodeWorkMemory, NumOutputs); */
    fir_process(&rtb_y_fd[0], &Model_Target_VLS_B.Add_b[0],
                &FirP56149CodeWorkMemory[0], 20U);

    /* Selector: '<S1510>/Selector' */
    for (i_0 = 0; i_0 < 10; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_Selector_i[idxS + (i_0 << 3)] = rtb_y_fd[(tmp_1[i_0] << 3) +
                idxS];
        }
    }

    /* End of Selector: '<S1510>/Selector' */

    /* Sum: '<S1510>/Matrix Sum' incorporates:
     *  Selector: '<S1510>/Selector'
     */
    for (srcIndex = 0; srcIndex < 8; srcIndex++)
    {
        tmp = -0.0F;
        for (i_0 = 0; i_0 < 10; i_0++)
        {
            tmp += rtb_Selector_i[(i_0 << 3) + srcIndex];
        }

        rtb_Add_nn[srcIndex + 16] = tmp;
    }

    /* End of Sum: '<S1510>/Matrix Sum' */

    /* Selector: '<S1510>/Selector1' */
    for (i_0 = 0; i_0 < 10; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            rtb_Selector_i[idxS + (i_0 << 3)] = rtb_y_fd[(tmp_2[i_0] << 3) +
                idxS];
        }
    }

    /* End of Selector: '<S1510>/Selector1' */

    /* Sum: '<S1510>/Matrix Sum1' incorporates:
     *  Selector: '<S1510>/Selector1'
     */
    for (srcIndex = 0; srcIndex < 8; srcIndex++)
    {
        tmp = -0.0F;
        for (i_0 = 0; i_0 < 10; i_0++)
        {
            tmp += rtb_Selector_i[(i_0 << 3) + srcIndex];
        }

        rtb_Add_nn[srcIndex + 24] = tmp;
    }

    /* End of Sum: '<S1510>/Matrix Sum1' */

    /* Selector: '<S1475>/Selector' incorporates:
     *  Constant: '<S1475>/Constant'
     *  Selector: '<S562>/Selector4'
     *  Sum: '<S562>/Add'
     */
    for (i_0 = 0; i_0 < 16; i_0++)
    {
        for (idxS = 0; idxS < 8; idxS++)
        {
            i = (int32_T)Model_Target_ConstP.Constant_Value[i_0];
            XtalkIIR48480PoolIirAudioIn[idxS + (i_0 << 3)] = rtb_Add_nn[((i - 1)
                << 3) + idxS] + Model_Target_B.FRIn[((i + 23) << 3) + idxS];
        }
    }

    /* End of Selector: '<S1475>/Selector' */
    /* MATLAB Function: '<S1485>/PoolIirProcess' incorporates:
     *  Selector: '<S1475>/Selector'
     */
    /*  Process function for Pooliir */
    /*  */
    /*  Parameters: */
    /*    x:              input channels [frame size x number of inputs] */
    /*    NumStages:      array of filter lengths per channel [NumChannels x 1] */
    /*    CoeffsTarget:   coefficient set used for the specific target [total sim filter lengths x 1] */
    /*   */
    /*  Global parameters: */
    /*    states: working memory set up during roommode reset/init CRL */
    /*                    function call [StatesSize x 1] */
    /* -------------------------------------------------------------------------- */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/PoolIirProcess': '<S1489>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1489>:1:15' [~, NumChannels] = size(x); */
    /*  Initialize variables */
    /* '<S1489>:1:20' VariantStr = char(VariantUint8); */
    /* '<S1489>:1:22' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S1489>:1:29' else */
    /* '<S1489>:1:30' switch(VariantStr) */
    /* '<S1489>:1:31' case{"Hexagon"} */
    /* '<S1489>:1:32' y = pooliir_hexagon_process(single(x), single(states)); */
    pooliir_process(&XtalkIIR46060PoolIirAudioOut[0],
                    &XtalkIIR48480PoolIirAudioIn[0], &XtalkIIR22535states[0]);

    /* MATLAB Function: '<S1476>/MATLAB Function' incorporates:
     *  S-Function (TOP_MEX): '<S1479>/TOP'
     */
    /*  Our delayline lives in global variable. We treat as a circular buffer.  */
    /* MATLAB Function 'Pool Delay/MATLAB Function': '<S1480>:1' */
    /*  figure out the frame size and channel count */
    /* '<S1480>:1:7' [frameSize, numChannels] = size(audioIn); */
    /* '<S1480>:1:8' frameSize = int32(frameSize); */
    /* '<S1480>:1:9' maxTotalDelay = int32(maxTotalDelay); */
    /* '<S1480>:1:10' audioOut = coder.nullcopy(audioIn); */
    /*  writeIndex points to our current write location in buffer */
    /* '<S1480>:1:14' if isempty(delayIndex) */
    /* '<S1480>:1:18' bufferIndex = delayIndex; */
    i = Model_Target_VLS_DW.delayIndex;

    /*  OUTPUT */
    /* '<S1480>:1:21' for channel = 1:numChannels */
    for (i_0 = 0; i_0 < 16; i_0++)
    {
        /* S-Function (TOP_MEX): '<S1479>/TOP' */
        /*  Delay for current channel */
        /* '<S1480>:1:23' delay = delayTime(channel); */
        /*  Number of samples into the delay buffer */
        /* '<S1480>:1:26' partialDelay = min(frameSize, delay); */
        u1 = Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay[i_0];
        if (u1 >= 8)
        {
            u1 = 8;
            idxS = 8;
        }
        else
        {
            idxS = u1;
        }

        idxS++;

        /*  Initial offset into delay buffer */
        /* '<S1480>:1:29' srcIndex = circindex(bufferIndex, int32(1), maxTotalDelay); */
        srcIndex = circindex(i, 1, 600);

        /*  Fill first part of output buffer from delay buffer */
        /* '<S1480>:1:32' for sample = 1:partialDelay */
        for (j = 0; j <= idxS - 2; j++)
        {
            /* '<S1480>:1:33' audioOut(sample, channel) = delayBuffer(srcIndex + 1); */
            rtb_audioOut_e[j + (i_0 << 3)] =
                Model_Target_VLS_DW.delayBuffer[srcIndex];

            /* '<S1480>:1:34' srcIndex = circindex(srcIndex, int32(1), maxTotalDelay); */
            srcIndex = circindex(srcIndex, 1, 600);
        }

        /*  Fill the rest from the input buffer */
        /* '<S1480>:1:38' for sample = partialDelay+1:frameSize */
        for (srcIndex = idxS; srcIndex < 9; srcIndex++)
        {
            /* '<S1480>:1:39' audioOut(sample, channel) = audioIn(sample - partialDelay, channel); */
            j = i_0 << 3;
            rtb_audioOut_e[(srcIndex + j) - 1] = XtalkIIR46060PoolIirAudioOut
                [((srcIndex - u1) + j) - 1];
        }

        /*  Advance buffer index for next channel */
        /* '<S1480>:1:43' bufferIndex = circindex(bufferIndex, delay, maxTotalDelay); */
        i = circindex(i,
                      Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay[i_0],
                      600);
    }

    /*  Reset and advance by one frame */
    /* '<S1480>:1:47' bufferIndex = circindex(delayIndex, min(frameSize, maxTotalDelay), maxTotalDelay); */
    i = circindex(Model_Target_VLS_DW.delayIndex, 8, 600);

    /* '<S1480>:1:48' delayIndex = bufferIndex; */
    Model_Target_VLS_DW.delayIndex = i;

    /*  DELAY LINE */
    /* '<S1480>:1:51' for channel = 1:numChannels */
    for (i_0 = 0; i_0 < 16; i_0++)
    {
        /* S-Function (TOP_MEX): '<S1479>/TOP' */
        /*  Delay for current channel */
        /* '<S1480>:1:54' delay = delayTime(channel); */
        /*  Number of samples into the delay buffer */
        /* '<S1480>:1:57' partialDelay = min(frameSize, delay); */
        idxS = Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay[i_0];
        if (idxS >= 8)
        {
            idxS = 8;
        }

        /*  Calculate index with offset */
        /* '<S1480>:1:60' destIndex = circindex(bufferIndex, delay - partialDelay + 1, maxTotalDelay); */
        srcIndex = circindex(i,
                             (Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay
                              [i_0] - idxS) + 1, 600);

        /*  Fill output buffer from delay buffer */
        /* '<S1480>:1:63' for sample = frameSize - partialDelay+1:frameSize */
        idxS = 9 - idxS;
        for (j = idxS; j < 9; j++)
        {
            /* '<S1480>:1:64' delayBuffer(destIndex + 1) = audioIn(sample, channel); */
            Model_Target_VLS_DW.delayBuffer[srcIndex] =
                XtalkIIR46060PoolIirAudioOut[((i_0 << 3) + j) - 1];

            /* '<S1480>:1:65' destIndex = circindex(destIndex, int32(1), maxTotalDelay); */
            srcIndex = circindex(srcIndex, 1, 600);
        }

        /*  Advance buffer index for next channel */
        /* '<S1480>:1:69' bufferIndex = circindex(bufferIndex, delay, maxTotalDelay); */
        i = circindex(i,
                      Model_Target_PreAmp_p10_b0.VLSXtalkCancellationDelay[i_0],
                      600);
    }

    /* End of MATLAB Function: '<S1476>/MATLAB Function' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1494>/ITC1' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1486>/ITC1' */
    /* MATLAB Function: '<S1472>/Sum Channels' */
    /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/VLS/Crosstalk Cancellation/Sum Channels': '<S1478>:1' */
    /* '<S1478>:1:3' numFilters = configStruct.numFilters; */
    /* '<S1478>:1:4' numHeadrests = configStruct.numHeadrests; */
    /* '<S1478>:1:5' numFilterPerSpkr = configStruct.numFilterPerSpkr; */
    /* '<S1478>:1:7' [frameSize, ~] = size(in); */
    /* '<S1478>:1:8' y = coder.nullcopy(single(zeros(frameSize, numHeadrests))); */
    /* '<S1478>:1:10' for i = 1:numHeadrests */
    for (i = 0; i < 4; i++)
    {
        /* '<S1478>:1:11' y(:,i) = sum(in(:,i:numFilterPerSpkr:numFilters),2); */
        for (idxS = 0; idxS < 8; idxS++)
        {
            Model_Target_MedusaPostHoligram_B.MatrixConcatenate[idxS + ((i + 18)
                << 3)] = rtb_audioOut_e[idxS % 8 + (i << 3)];
        }

        for (i_0 = 0; i_0 < 3; i_0++)
        {
            srcIndex = (i_0 + 1) << 3;
            for (j = 0; j < 8; j++)
            {
                idxS = srcIndex + j;
                u1 = ((i + 18) << 3) + j;
                Model_Target_MedusaPostHoligram_B.MatrixConcatenate[u1] =
                    rtb_audioOut_e[((((idxS / 8) << 2) + i) << 3) + idxS % 8] +
                    Model_Target_MedusaPostHoligram_B.MatrixConcatenate[u1];
            }
        }
    }

    /* End of MATLAB Function: '<S1472>/Sum Channels' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1507>/ITC1' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1503>/ITC1' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1520>/ITC1' */
    /* End of Outputs for S-Function (InitTriggerControl): '<S1516>/ITC1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
