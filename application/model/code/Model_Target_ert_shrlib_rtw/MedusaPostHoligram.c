/*
 * File: MedusaPostHoligram.c
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
#include "MedusaPostHoligram.h"
#include "fir_hexagon.h"
#include <string.h>
#include "Model_Target.h"
#include <math.h>
#include "Model_Target_private.h"
#include "Model_Target_FirGenericStorage.h"
#include "PoolDelayStorage.h"

/* Named constants for MATLAB Function: '<S1305>/GetFirMappings' */
#define Model_Target_UpFactor          (4.0)

/* Declare variables for internal data of system '<S559>/MedusaPostHoligram' */
B_MedusaPostHoligram_Model_Target_T Model_Target_MedusaPostHoligram_B;
DW_MedusaPostHoligram_Model_Target_T Model_Target_MedusaPostHoligram_DW;

/* Output and update for function-call system: '<S1314>/init' */
void InitTrigger_Model_150_610_443_99(void)
{
    /* MATLAB Function: '<S1311>/FirGenericInitFcn' */
    /* MATLAB Function: '<S1311>/FirGenericInitFcn' incorporates:
     *  Concatenate: '<S1296>/Matrix Concatenate'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1316>:1' */
    /* '<S1316>:1:3' init(); */
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
    /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericInitFcn': '<S1312>:1' */
    /*  Extract configuration information from inputs */
    /* '<S1312>:1:18' [FrameSize, NumInputs]  = size(u); */
    /* '<S1312>:1:19' NumOutputs = numel(InputMapping); */
    /*  Get the work memory and states size */
    /* '<S1312>:1:25' WorkMemorySize = numel(CodeWorkMemory); */
    /* '<S1312>:1:26' StateBufferSize = numel(StateBuffer); */
    /*  Set correct data types */
    /* '<S1312>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
    /* '<S1312>:1:30' NumCoeffSets = uint32(numel(CoeffsLengths)); */
    /* '<S1312>:1:31' FrameSize = uint32(FrameSize); */
    /* '<S1312>:1:32' NumOutputs = uint32(NumOutputs); */
    /* '<S1312>:1:33' NumInputs = uint32(NumInputs); */
    /* '<S1312>:1:34' WorkMemorySize = uint32(WorkMemorySize); */
    /* '<S1312>:1:35' StateBufferSize = uint32(StateBufferSize); */
    /*  Reconstitute Variant */
    /* '<S1312>:1:38' VariantSelect = char(VariantUint8); */
    /* '<S1312>:1:40' switch(VariantSelect) */
    /* '<S1312>:1:52' case {'Hexagon'} */
    /* '<S1312>:1:53' y = fir_hexagon_init(u, CoeffsTarget, StateBuffer, CoeffsLengths, InputMapping, CoeffsMapping, ... */
    /* '<S1312>:1:54'             FrameSize, NumCoeffSets, NumInputs, NumOutputs, CodeWorkMemory); */
    fir_init(&MedusaPostHoligramFirUpFir17940CodeWorkMemory[0],
             &Model_Target_MedusaPostHoligram_B.MatrixConcatenate[0],
             &MedusaPostHoligramFirUpFir11299CoeffsTarget[0],
             &MedusaPostHoligramFirUpFir54162StateBuffer[0],
             &Model_Target_MedusaPostHoligram_B.CoeffsLengths[0],
             &Model_Target_MedusaPostHoligram_B.InputMapping[0],
             &Model_Target_MedusaPostHoligram_B.CoeffsMapping[0], 8U, 88U, 22U,
             88U, &MedusaPostHoligramFirUpFir17940CodeWorkMemory[0]);

    /* '<S1312>:1:55' CodeWorkMemory(1) = y; */
}

/* Output and update for function-call system: '<S1318>/init' */
void InitTrigger_Model_150_610_443_224(void)
{
    /* MATLAB Function: '<S1317>/SignalBreakFcn' */
    /* MATLAB Function: '<S1317>/SignalBreakFcn' incorporates:
     *  Constant: '<S1299>/Constant'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1320>:1' */
    /* '<S1320>:1:3' init(); */
    /* MATLAB Function 'Fir/Fir/TargetSpecific/SignalBreak/SignalBreak/SignalBreakFcn': '<S1319>:1' */
    /* '<S1319>:1:3' y = u; */
    memcpy(&MedusaPostHoligramFirUpFir11299CoeffsTarget[0],
           &Model_Target_ConstP.Constant_Value_l[0], 144U * sizeof(real32_T));
}

/* Output and update for function-call system: '<S1308>/init' */
void InitTrigger_Model_150_610_446(void)
{
    int32_T k;
    static const int8_T tmp[88] =
    {
        0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5,
        6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
        11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15,
        16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20,
        20, 20, 21, 21, 21, 21
    };

    /* MATLAB Function: '<S1305>/GetFirMappings' */
    /* MATLAB Function: '<S1305>/GetFirMappings' */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'ITC/init': '<S1321>:1' */
    /* '<S1321>:1:3' init(); */
    /* MATLAB Function 'FirUp/FirUp/WithFir/GetFirMappings': '<S1307>:1' */
    /* '<S1307>:1:3' [~, NumChannels] = size(AudioIn); */
    /* '<S1307>:1:4' NumOutputs = UpFactor*NumChannels; */
    /*  Coefficients are equally divided up into [UpFactor] number of coefficient */
    /*  sets.  */
    /*  CoeffsLengths = uint32(ceil(ones(1,UpFactor).*(numel(CoeffsTarget)/UpFactor))); */
    /* '<S1307>:1:9' CoeffsLengths = uint32(ceil(ones(1,NumOutputs).*(numel(CoeffsTarget)/UpFactor))); */
    /*  Output is mapped as follows, where UpFactor = L and NumChannels = Nc */
    /*  ix = 0: Nc - 1 */
    /*    iy = 0: L - 1 */
    /*  fcn(Input[ix], Filter[iy]) = Output[ix*L + iy] */
    /*  */
    /*  CoeffsMapping = [0, 1, 2 ... L-1, 0, 1, 2 ... L-1 ...] */
    /* '<S1307>:1:18' CoeffsMapping = uint32(mod(0:NumOutputs-1,UpFactor)); */
    for (k = 0; k < 88; k++)
    {
        Model_Target_MedusaPostHoligram_B.InputMapping[k] = (uint32_T)tmp[k];
        Model_Target_MedusaPostHoligram_B.CoeffsLengths[k] = 36U;
        if (k == 0)
        {
            Model_Target_MedusaPostHoligram_B.CoeffsMapping[k] = 0U;
        }
        else
        {
            Model_Target_MedusaPostHoligram_B.CoeffsMapping[k] = (uint32_T)
                (int8_T)fmod(((real_T)k + 1.0) - 1.0, Model_Target_UpFactor);
        }
    }

    /* End of MATLAB Function: '<S1305>/GetFirMappings' */
    /*  InputMapping = [0 0 0 0 ... 1 1 1 1 ... 2 2 2 2 ... Nc-1 Nc-1 Nc-1 Nc-1 ...] */
    /* '<S1307>:1:20' InputMapping = uint32(reshape(repmat(0:NumChannels-1,UpFactor,1),1,[])'); */
}

/* Output and update for function-call system: '<S1300>/REQ' */
void HandleReqPreAmpMedusaPostHoligramDisable(void)
{
    /* Outputs for Function Call SubSystem: '<S1296>/Enable State Write' */
    /* DataStoreWrite: '<S1298>/Data Store Write' incorporates:
     *  Constant: '<S1298>/Constant'
     */
    /*  Invoke the function trigger output */
    /* MATLAB Function 'RTC/REQ': '<S1325>:1' */
    /* '<S1325>:1:3' go(); */
    Model_Target_MedusaPostHoligram_DW.MedusaPostHoligramEnable = 0U;

    /* End of Outputs for SubSystem: '<S1296>/Enable State Write' */
}

/* System initialize for atomic system: '<S559>/MedusaPostHoligram' */
void Model_Target_MedusaPostHoligram_Init(void)
{
    /* Start for If: '<S1296>/If' */
    Model_Target_MedusaPostHoligram_DW.If_ActiveSubsystem = -1;

    /* Start for DataStoreMemory: '<S1296>/Data Store Memory' */
    Model_Target_MedusaPostHoligram_DW.MedusaPostHoligramEnable = 1U;

    /* SystemInitialize for IfAction SubSystem: '<S1296>/On' */

    /* user code (Initialize function Body) */

    /* InitTriggerControl '<S1308>/ITC1' */
    InitTrigger_Model_150_610_446();

    /* InitTriggerControl '<S1318>/ITC1' */
    InitTrigger_Model_150_610_443_224();

    /* InitTriggerControl '<S1314>/ITC1' */
    InitTrigger_Model_150_610_443_99();

    /* End of SystemInitialize for SubSystem: '<S1296>/On' */

    /* SystemInitialize for Merge: '<S1296>/Merge' */
    memset(&Model_Target_MedusaPostHoligram_B.Merge[0], 0, 768U * sizeof
           (real32_T));
}

/* Output and update for atomic system: '<S559>/MedusaPostHoligram' */
void Model_Target_MedusaPostHoligram(void)
{
    int32_T i;
    int32_T i_0;
    real32_T rtb_y_m_0[32];
    int8_T rtAction;
    int8_T rtPrevAction;

    /* If: '<S1296>/If' incorporates:
     *  DataStoreRead: '<S1296>/Enable State Read'
     */
    rtPrevAction = Model_Target_MedusaPostHoligram_DW.If_ActiveSubsystem;
    rtAction = (int8_T)
        (Model_Target_MedusaPostHoligram_DW.MedusaPostHoligramEnable <= 0U);
    Model_Target_MedusaPostHoligram_DW.If_ActiveSubsystem = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0))
    {
    }

    if (rtAction == 0)
    {
        if (rtPrevAction != 0)
        {
        }

        /* End of Outputs for S-Function (InitTriggerControl): '<S1308>/ITC1' */

        /* MATLAB Function: '<S1311>/FirGenericProcessFcn' incorporates:
         *  Concatenate: '<S1296>/Matrix Concatenate'
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
        /* MATLAB Function 'Fir/Fir/TargetSpecific/FirGenericProcessFcn': '<S1313>:1' */
        /*  Extract configuration information from inputs */
        /* '<S1313>:1:20' [FrameSize, ~]  = size(u); */
        /* '<S1313>:1:21' NumOutputs = numel(InputMapping); */
        /*  Define persistent variables for SharcPlusAccel Variant */
        /*  Set correct data types */
        /* '<S1313>:1:29' CoeffsLengths = uint32(CoeffsLengths); */
        /* '<S1313>:1:30' FrameSize = uint32(FrameSize); */
        /* '<S1313>:1:31' NumOutputs = uint32(NumOutputs); */
        /* '<S1313>:1:32' InputMapping = uint32(InputMapping); */
        /*  Reconstitute Variant */
        /* '<S1313>:1:35' VariantSelect = char(VariantUint8); */
        /*  Simulation */
        /* '<S1313>:1:38' if(coder.target('MATLAB') || coder.target('Sfun')) */
        /* '<S1313>:1:58' else */
        /* '<S1313>:1:59' switch(VariantSelect) */
        /* '<S1313>:1:65' case {'Hexagon'} */
        /* '<S1313>:1:66' y = fir_hexagon_process(u, CodeWorkMemory, NumOutputs); */
        fir_process(&Model_Target_MedusaPostHoligram_B.y_m[0],
                    &Model_Target_MedusaPostHoligram_B.MatrixConcatenate[0],
                    &MedusaPostHoligramFirUpFir17940CodeWorkMemory[0], 88U);

        /* MATLAB Function: '<S1305>/TransformPolphaseOutputs' */
        /*  Converts polyphase filter outputs into standard filter outputs */
        /* MATLAB Function 'FirUp/FirUp/WithFir/TransformPolphaseOutputs': '<S1309>:1' */
        /*  Instantiate output array */
        /* '<S1309>:1:5' [FrameSizeIn, PolyphaseChannels] = size(PolyphaseFilterOutputs); */
        /* '<S1309>:1:6' NumChannels = PolyphaseChannels/UpFactor; */
        /* '<S1309>:1:7' Output = zeros(FrameSizeIn*UpFactor, PolyphaseChannels/UpFactor,'single'); */
        /* '<S1309>:1:8' for ch = 1: NumChannels */
        for (i = 0; i < 22; i++)
        {
            int32_T ch;

            /*  Commutation of polyphase subfilter outputs into a single upsampled */
            /*  output */
            /* '<S1309>:1:11' Output(:,ch) = reshape(PolyphaseFilterOutputs(:,(ch-1)*UpFactor + (1:UpFactor))',1,[]); */
            ch = i << 2;
            for (i_0 = 0; i_0 < 8; i_0++)
            {
                int32_T rtb_y_m_tmp;
                rtb_y_m_tmp = i_0 << 2;
                rtb_y_m_0[rtb_y_m_tmp] = Model_Target_MedusaPostHoligram_B.y_m
                    [(ch << 3) + i_0];
                rtb_y_m_0[rtb_y_m_tmp + 1] =
                    Model_Target_MedusaPostHoligram_B.y_m[((ch + 1) << 3) + i_0];
                rtb_y_m_0[rtb_y_m_tmp + 2] =
                    Model_Target_MedusaPostHoligram_B.y_m[((ch + 2) << 3) + i_0];
                rtb_y_m_0[rtb_y_m_tmp + 3] =
                    Model_Target_MedusaPostHoligram_B.y_m[((ch + 3) << 3) + i_0];
            }

            memcpy(&Model_Target_MedusaPostHoligram_B.Output_h[i << 5],
                   &rtb_y_m_0[0], sizeof(real32_T) << 5U);
        }

        /* End of MATLAB Function: '<S1305>/TransformPolphaseOutputs' */

        /* Sum: '<S1299>/Add' incorporates:
         *  Sum: '<S559>/Add1'
         */
        for (i_0 = 0; i_0 < 704; i_0++)
        {
            Model_Target_MedusaPostHoligram_B.Output_h[i_0] +=
                Model_Target_B.FRIn[i_0];
        }

        /* End of Sum: '<S1299>/Add' */
        /* End of Outputs for S-Function (InitTriggerControl): '<S1318>/ITC1' */
        /* End of Outputs for S-Function (InitTriggerControl): '<S1314>/ITC1' */
        /* MATLAB Function: '<S1299>/Router' incorporates:
         *  S-Function (TOP_MEX): '<S1303>/TOP'
         *  Sum: '<S1299>/Add'
         */
        /* MATLAB Function 'ModelPreAmp/DecRate/Medusa5H1/MedusaPostHoligram/MedusaPostHoligram/On/Router': '<S1302>:1' */
        /* '<S1302>:1:3' [frameSize, numIn] = size(u); */
        /* '<S1302>:1:4' numOut = numel(routingMap); */
        /* '<S1302>:1:5' y = coder.nullcopy(single(zeros(frameSize, numOut))); */
        /* '<S1302>:1:7' for i = 1:numOut */
        for (i = 0; i < 24; i++)
        {
            /* '<S1302>:1:8' index = routingMap(i); */
            /* '<S1302>:1:9' if (index < 0) || (index >= numIn) */
            if (Model_Target_PreAmp_p1_b0.MedusaRoutingMap[i] < 0.0F)
            {
                /* '<S1302>:1:10' y(:,i) = zeros(frameSize,1); */
                memset(&Model_Target_MedusaPostHoligram_B.y_c[i << 5], 0, sizeof
                       (real32_T) << 5U);
            }
            else if (Model_Target_PreAmp_p1_b0.MedusaRoutingMap[i] >= 22.0F)
            {
                /* '<S1302>:1:10' y(:,i) = zeros(frameSize,1); */
                memset(&Model_Target_MedusaPostHoligram_B.y_c[i << 5], 0, sizeof
                       (real32_T) << 5U);
            }
            else
            {
                /* '<S1302>:1:11' else */
                /* '<S1302>:1:12' y(:,i) = u(:, index + 1); */
                i_0 = (int32_T)(Model_Target_PreAmp_p1_b0.MedusaRoutingMap[i] +
                                1.0F);
                memcpy(&Model_Target_MedusaPostHoligram_B.y_c[i << 5],
                       &Model_Target_MedusaPostHoligram_B.Output_h[(i_0 << 5) +
                       -32], sizeof(real32_T) << 5U);

                /*  add 1 for Matlab indexing */
            }
        }

        /* End of MATLAB Function: '<S1299>/Router' */

        /* Merge: '<S1296>/Merge' incorporates:
         *  SignalConversion generated from: '<S1299>/AudioOut'
         */
        memcpy(&Model_Target_MedusaPostHoligram_B.Merge[0],
               &Model_Target_MedusaPostHoligram_B.y_c[0], 768U * sizeof(real32_T));

        /* End of Outputs for SubSystem: '<S1296>/On' */
    }
    else
    {
        /* Outputs for IfAction SubSystem: '<S1296>/Bypass' incorporates:
         *  ActionPort: '<S1297>/Action Port'
         */
        /* Merge: '<S1296>/Merge' incorporates:
         *  SignalConversion generated from: '<S1297>/IsStereo'
         */
        memset(&Model_Target_MedusaPostHoligram_B.Merge[0], 0, 768U * sizeof
               (real32_T));

        /* End of Outputs for SubSystem: '<S1296>/Bypass' */
    }

    /* End of If: '<S1296>/If' */
    /* End of Outputs for S-Function (RTC_REQ_RSP): '<S1300>/RTC Request Response Trigger' */
    /* End of Outputs for S-Function (RTC_NTF): '<S1300>/NTF Trigger' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
