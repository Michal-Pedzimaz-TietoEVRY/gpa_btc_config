/*
 * File: MedusaExpandTailComps.c
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

#include "MedusaExpandTailComps.h"
#include "pooliir_hexagon.h"
#include "qhblas.h"
#include "qhcomplex.h"
#include "qhdsp.h"
#include "qhdsp_common.h"
#include "qhdsp_iir.h"
#include "qhmath.h"
#include "rtwtypes.h"
#include <string.h>
#include "fireven_hexagon.h"
#include "qhdsp_fft_internal.h"
#include "qhl_common.h"
#include "Model_Target_private.h"
#include "PoolDelayStorage.h"
#include "FirStorage.h"
#include "Model_Target.h"

/* Output and update for function-call system: '<S911>/init' */
void InitTrigger_Model_141_345_50_172_156(void)
{
    /* MATLAB Function: '<S910>/PoolIirInit' */
    /* MATLAB Function: '<S910>/PoolIirInit' incorporates:
     *  Gain: '<S906>/Gain'
     *  S-Function (TOP_MEX): '<S907>/TOP'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S916>:1' */
    /* '<S916>:1:3' init(); */
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
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/PoolIirInit': '<S913>:1' */
    /*  Extract configuration information from inputs */
    /* '<S913>:1:15' [FrameSize, NumChannels] = size(x); */
    /*  Initialize variables */
    /*  Get the work memory size */
    /* '<S913>:1:21' StatesSize = numel(states); */
    /*  Output */
    /* '<S913>:1:24' VariantStr = char(VariantUint8); */
    /* '<S913>:1:26' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S913>:1:28' else */
    /* '<S913>:1:29' switch(VariantStr) */
    /* '<S913>:1:30' case{"Hexagon"} */
    /* '<S913>:1:31' NumCoeffPerSosStage = 4; */
    /* '<S913>:1:32' y = pooliir_hexagon_init(single(x), uint32(FrameSize), uint32(NumChannels), uint32(NumStages), single(CoeffsTarget), ... */
    /* '<S913>:1:33'                                      single(states), uint32(StatesSize),uint32(MaxNumOfThreads), uint32(MaxNumSosStages*NumCoeffPerSosStage)); */
    pooliir_init(&Default25868states[0], &Default59506PoolIirAudioIn[0], 8U, 4U,
                 &(Model_Target_PreAmp_p5_b0.MedusatailCompEQPooliirNumStages[0]),
                 &Default48458PoolIirCoeffs[0], &Default25868states[0], 337U, 1U,
                 160U);

    /* '<S913>:1:34' states(1) = y; */
}

/* Output and update for function-call system: '<S919>/init' */
void InitTrigger_Model_141_345_50_172_192(void)
{
    /* MATLAB Function: '<S918>/SignalBreakFcn' */
    /* MATLAB Function: '<S918>/SignalBreakFcn' incorporates:
     *  S-Function (TOP_MEX): '<S907>/TOP1'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S921>:1' */
    /* '<S921>:1:3' init(); */
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/SignalBreak/SignalBreak/SignalBreakFcn': '<S920>:1' */
    /* '<S920>:1:3' y = u; */
    memcpy(&Default48458PoolIirCoeffs[0],
           &(Model_Target_PreAmp_p5_b0.MedusatailCompEQpooliirCoeffs[0]), 164U *
           sizeof(real32_T));
}

/* Output and update for function-call system: '<S926>/init' */
void InitTrigger_Model_141_347_65(void)
{
    /* MATLAB Function: '<S923>/FirEvenInit' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S929>:1' */
    /* '<S929>:1:3' init(); */
    /*  Extract configuration information from inputs */
    /* MATLAB Function 'FirEven/FirEven/Hexagon/FirEvenInit': '<S924>:1' */
    /* '<S924>:1:4' [FilterLength, NumFilters] = size(FlippedCoefficients); */
    /* '<S924>:1:5' [FrameSize, NumChannels] = size(u); */
    /*  Simulation  */
    /* '<S924>:1:10' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S924>:1:12' else */
    /* '<S924>:1:13' y = fireven_hexagon_init(uint32(FrameSize), uint32(NumChannels), uint32(NumFilters), uint32(FilterLength), single(FlippedCoefficients), uint32(CodeWorkMemory), uint32(MaxNumOfThreds)); */
    fireven_init(&MedusaExpandTailWiggle4764CodeWorkMemory[0], 8U, 4U, 4U, 444U,
                 &MedusaExpandTailWiggle21229FirEvenCoeffs[0],
                 &MedusaExpandTailWiggle4764CodeWorkMemory[0], 1U);

    /*  NOTE: The CRL mechanism requires an output for the function call, */
    /*  and appears to be optimized out if that return value isn't used.  */
    /*  This is a dummy operation to make sure CRL ends up in generated code */
    /* '<S924>:1:17' CodeWorkMemory(1) = y; */
}

/* Output and update for function-call system: '<S927>/init' */
void InitTrigger_Model_141_347_84(void)
{
    /* MATLAB Function: '<S923>/SignalBreak' */
    /* MATLAB Function: '<S923>/SignalBreak' incorporates:
     *  S-Function (TOP_MEX): '<S904>/TOP'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S930>:1' */
    /* '<S930>:1:3' init(); */
    memcpy(&MedusaExpandTailWiggle21229FirEvenCoeffs[0],
           &(Model_Target_PreAmp_p5_b0.MedusaWiggleFilter[0]), 1776U * sizeof
           (real32_T));

    /* MATLAB Function 'FirEven/FirEven/Hexagon/SignalBreak': '<S928>:1' */
    /* '<S928>:1:3' y = u; */
}

/* System initialize for atomic system: '<S887>/Expand Tail Components' */
void Model_Target_ExpandTailComponents_Init(void)
{
    /* user code (Initialize function Body) */

    /* InitTriggerControl '<S919>/ITC1' */
    InitTrigger_Model_141_345_50_172_192();

    /* InitTriggerControl '<S911>/ITC1' */
    InitTrigger_Model_141_345_50_172_156();

    /* InitTriggerControl '<S927>/ITC1' */
    InitTrigger_Model_141_347_84();

    /* InitTriggerControl '<S926>/ITC1' */
    InitTrigger_Model_141_347_65();
}

/* Output and update for atomic system: '<S887>/Expand Tail Components' */
void Model_Target_ExpandTailComponents(void)
{
    real32_T tmp[32];
    uint32_T tmp_0[4];

    /* Gain: '<S905>/Gain' incorporates:
     *  Sum: '<S936>/Add'
     */
    memcpy(&MedusaExpandTailWiggle22052FirEvenInput[0],
           &Model_Target_Medusa5H1Part3_B.PremixMatrix_i[0], sizeof(real32_T) <<
           5U);

    /* MATLAB Function: '<S923>/FirEvenProcess' incorporates:
     *  Constant: '<S894>/Constant'
     *  Gain: '<S905>/Gain'
     */
    /*  Extract configuration information from inputs */
    /* MATLAB Function 'FirEven/FirEven/Hexagon/FirEvenProcess': '<S925>:1' */
    /* '<S925>:1:4' [FilterLength, ~] = size(FlippedCoeffs); */
    /* '<S925>:1:5' [FrameSize, NumChannels] = size(u); */
    /*  Initialize variables */
    /*  persistent States; */
    /*  if isempty(States) */
    /*      States = single(zeros(FilterLength + FrameSize*2 + 2, NumChannels)); */
    /*  end */
    /*  Set correct data types */
    /* '<S925>:1:17' FilterLength = uint32(FilterLength); */
    /* '<S925>:1:18' FrameSize = uint32(FrameSize); */
    /* '<S925>:1:19' ActiveCoeffSet = uint32(ActiveCoeffSet); */
    /* '<S925>:1:22' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S925>:1:25' else */
    /*  FIR EVEN HEXAGON */
    /* '<S925>:1:27' if (FilterLength > FrameSize) */
    /* '<S925>:1:28' y = fireven_hexagon_process_mt(single(u), uint32(ActiveCoeffSet), single(States), uint32(CodeWorkMemory)); */
    tmp_0[0] = 0U;
    tmp_0[1] = 1U;
    tmp_0[2] = 2U;
    tmp_0[3] = 3U;
    fireven_process_mt(&tmp[0], &MedusaExpandTailWiggle22052FirEvenInput[0],
                       &tmp_0[0], &MedusaExpandTailWiggle53733States[0],
                       &MedusaExpandTailWiggle4764CodeWorkMemory[0]);

    /* Gain: '<S906>/Gain' incorporates:
     *  MATLAB Function: '<S923>/FirEvenProcess'
     */
    memcpy(&Default59506PoolIirAudioIn[0], &tmp[0], sizeof(real32_T) << 5U);

    /* MATLAB Function: '<S910>/PoolIirProcess' incorporates:
     *  Gain: '<S906>/Gain'
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
    /* MATLAB Function 'PoolIirWithReset/PoolIir/TargetSpecific/PoolIirProcess': '<S914>:1' */
    /*  Extract configuration information from inputs */
    /* '<S914>:1:15' [~, NumChannels] = size(x); */
    /*  Initialize variables */
    /* '<S914>:1:20' VariantStr = char(VariantUint8); */
    /* '<S914>:1:22' if(coder.target('MATLAB') || coder.target('Sfun')) */
    /* '<S914>:1:29' else */
    /* '<S914>:1:30' switch(VariantStr) */
    /* '<S914>:1:31' case{"Hexagon"} */
    /* '<S914>:1:32' y = pooliir_hexagon_process(single(x), single(states)); */
    pooliir_process(&Default57912PoolIirAudioOut[0],
                    &Default59506PoolIirAudioIn[0], &Default25868states[0]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
