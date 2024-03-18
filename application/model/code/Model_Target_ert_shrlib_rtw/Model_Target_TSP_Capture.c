/*
 * File: Model_Target_TSP_Capture.c
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
#include <string.h>                    // for memcpy
#include <stdbool.h>
#include "Model_Target_TSP_Capture.h"
#include "Model_Target_private.h"      // for TSP signal buffer symbols
#include "Model_Target.h"              // for TSP signal buffer symbols
#include "Model_Target_Partitions.h"   // for partition root

// ------ Local data types:
// Struct for TSP capture (inport) control table
typedef struct Model_Target_TSP_Capture_tag
{
    const void* (*GetBlindReadPtr)(void);// Function pointer to get source signal
    uint32_t sizeInChar;               // total size of source signal buffer

#if (1 == TSP_ENABLE_ADVANCED)

    uint32_t capturesDesired;          // setup by list add: capture count
    uint32_t captureSkipInterval;
                  // setup by list add: how many frames to skip between captures
    uint32_t capturesComplete;         // counts captures as they happen
    uint32_t skipCounter;              // counts skipped frames as they happen
    int8_t* captureAddress;            // capture address setup by trigger

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

}
Model_Target_TSP_Capture_type;

// ----- Functions to access Blind Read pointers -----
/*  Blind read for '<S46>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotVehicleSpeed( void )
{
    return &(Model_TargetPreAmpAudiopilotsetSpeedInRtcOut.REQ_speedIn);
}

/*  Blind read for '<S41>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHvacDbspl( void )
{
    return &Model_Target_B.hvacDbspl;
}

/*  Blind read for '<S227>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseDbspl( void )
{
    return &Model_Target_B.LFNoise;
}

/*  Blind read for '<S230>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotWbNoiseDbspl( void )
{
    return &Model_Target_B.WBNoise;
}

/*  Blind read for '<S225>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoiseDbspl( void )
{
    return &Model_Target_B.HFNoise;
}

/*  Blind read for '<S228>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotNoiseRatio( void )
{
    return &Model_Target_B.Ratio;
}

/*  Blind read for '<S229>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotTotalBassBoostDb( void )
{
    return &Model_Target_B.Min;
}

/*  Blind read for '<S222>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotAudiopilotMidrangeBoostDb( void )
{
    return &Model_Target_B.Product1;
}

/*  Blind read for '<S223>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotAudiopilotTrebleBoostDb( void )
{
    return &Model_Target_B.Product_h5;
}

/*  Blind read for '<S224>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotDyneqBassBoostDb( void )
{
    return &Model_Target_B.Product3;
}

/*  Blind read for '<S221>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotAudiopilotBassBoostDb( void )
{
    return &Model_Target_B.Product2;
}

/*  Blind read for '<S226>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotIgnoreMicFlag( void )
{
    return &Model_Target_ConstP.pooled109;
}

/*  Blind read for '<S235>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotAudiopilotBoostGain( void )
{
    return &Model_Target_B.audiopilot_boost_gain;
}

/*  Blind read for '<S236>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotDyneqBoostGain( void )
{
    return &Model_Target_B.dyneq_boost_gain;
}

/*  Blind read for '<S496>/TSP' */
static const void* GetTspBlindPreAmpLevelWatchAudiopilotEnvDb( void )
{
    return &Model_Target_B.audiopilot;
}

/*  Blind read for '<S497>/TSP' */
static const void* GetTspBlindPreAmpLevelWatchAudiopilotLevelDbspl( void )
{
    return &Model_Target_B.sf_InnerLink.level;
}

/*  Blind read for '<S509>/TSP' */
static const void* GetTspBlindPreAmpLevelWatchDyneqEnvDb( void )
{
    return &Model_Target_B.dyneq;
}

/*  Blind read for '<S510>/TSP' */
static const void* GetTspBlindPreAmpLevelWatchDyneqLevelDbspl( void )
{
    return &Model_Target_B.sf_InnerLink_a.level;
}

/*  Blind read for '<S269>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoiseMicPsdLevel( void )
{
    return &Model_Target_B.MicLevel;
}

/*  Blind read for '<S262>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoisePowerSpectralDensity( void )
{
    return Model_Target_B.Merge_a;
}

/*  Blind read for '<S283>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoisePostSlew( void )
{
    return &Model_Target_B.PostSlew_j;
}

/*  Blind read for '<S284>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoisePreSlew( void )
{
    return &Model_Target_B.Add_o;
}

/*  Blind read for '<S292>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoiseImpulseRejectionPmin( void )
{
    return &Model_Target_B.SumofElements;
}

/*  Blind read for '<S301>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotHfNoiseImpulseRejectionFlatness
    ( void )
{
    return &Model_Target_B.flatness;
}

/*  Blind read for '<S452>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotRatioPostSlew( void )
{
    return &Model_Target_B.PostSlew;
}

/*  Blind read for '<S453>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotRatioPreSlew( void )
{
    return &Model_Target_B.Sum2;
}

/*  Blind read for '<S456>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotRatioUpdateFlag( void )
{
    return &Model_Target_B.LFUPFlag;
}

/*  Blind read for '<S362>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoisePostSlew( void )
{
    return &Model_Target_B.PostSlew_l;
}

/*  Blind read for '<S363>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoisePreSlew( void )
{
    return &Model_Target_B.NoisePreSlew;
}

/*  Blind read for '<S364>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoisePreSpeedBound( void )
{
    return &Model_Target_B.RateTransition;
}

/*  Blind read for '<S440>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsCurrMax( void )
{
    return &Model_Target_B.CurrNoiseBoundH;
}

/*  Blind read for '<S441>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsCurrMin( void )
{
    return &Model_Target_B.CurrNoiseBoundL;
}

/*  Blind read for '<S442>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsFlag( void )
{
    return &Model_Target_B.SpeedBoundFlag;
}

/*  Blind read for '<S357>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseMicLevel( void )
{
    return &Model_Target_B.MicDbspl;
}

/*  Blind read for '<S358>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseMicOut( void )
{
    return &Model_Target_B.Gain3;
}

/*  Blind read for '<S359>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseMusicOut( void )
{
    return &Model_Target_B.Gain2;
}

/*  Blind read for '<S361>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseNoiseOut( void )
{
    return &Model_Target_B.Gain;
}

/*  Blind read for '<S382>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionFilterOut
    ( void )
{
    return &Model_Target_B.FilterOut;
}

/*  Blind read for '<S384>/TSP' */
static const void* GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef
    ( void )
{
    return &Model_Target_B.ImpRejFiltCoef;
}

/*  Blind read for '<S385>/TSP' */
static const void
    * GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance( void )
{
    return &Model_Target_B.ImpulseVar;
}

/*  Blind read for '<S388>/TSP' */
static const void
    * GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance( void )
{
    return &Model_Target_B.MusicVar;
}

/*  Blind read for '<S391>/TSP' */
static const void
    * GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance( void )
{
    return &Model_Target_B.NoiseVar;
}

/*  Blind read for '<S394>/TSP' */
static const void
    * GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance( void )
{
    return &Model_Target_B.TotalVar;
}

/*  Blind read for '<S632>/TSP' */
static const void* GetTspBlindPreAmpMedusaDummyState( void )
{
    return &Model_Target_ConstP.pooled34;
}

/*  Blind read for '<S841>/TSP' */
static const void* GetTspBlindPreAmpMedusaMonoDetectorLevelCenter( void )
{
    return &Model_Target_B.center;
}

/*  Blind read for '<S836>/TSP' */
static const void* GetTspBlindPreAmpMedusaMonoDetectorIsStereo( void )
{
    return &Model_Target_B.Merge;
}

/*  Blind read for '<S837>/TSP' */
static const void* GetTspBlindPreAmpMedusaMonoDetectorIsActive( void )
{
    return &(Model_Target_PreAmp_p3_b0.MedusaMonoDetectorEnable);
}

/*  Blind read for '<S1876>/TSP' */
static const void* GetTspBlindNearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB
    ( void )
{
    return &Model_Target_B.Switch;
}

/*  Blind read for '<S1956>/TSP' */
static const void* GetTspBlindNearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB
    ( void )
{
    return &Model_Target_B.Switch_l;
}

/*  Blind read for '<S2036>/TSP' */
static const void* GetTspBlindNearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB
    ( void )
{
    return &Model_Target_B.Switch_g;
}

/*  Blind read for '<S2116>/TSP' */
static const void* GetTspBlindNearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB
    ( void )
{
    return &Model_Target_B.Switch_b;
}

/*  Blind read for '<S2203>/TSP' */
static const void* GetTspBlindPostProcessEnergyLimiterComputedEnergy( void )
{
    return Model_Target_PostProcess_B.DataTypeConversion1;
}

/*  Blind read for '<S2204>/TSP' */
static const void* GetTspBlindPostProcessEnergyLimiterCurGain( void )
{
    return &Model_Target_PostProcess_B.CurrentGain;
}

/*  Blind read for '<S2205>/TSP' */
static const void* GetTspBlindPostProcessEnergyLimiterEnergyThreshold( void )
{
    return (real32_T*)&Model_Target_PostProcess_ConstB.DataTypeConversion3;
}

/*  Blind read for '<S2206>/TSP' */
static const void* GetTspBlindPostProcessEnergyLimiterCurState( void )
{
    return &Model_Target_PostProcess_B.DataTypeConversion5;
}

/*  Blind read for '<S2207>/TSP' */
static const void* GetTspBlindPostProcessEnergyLimiterEnableFlag( void )
{
    return &Model_Target_PostProcess_B.DataTypeConversion6;
}

#if (1 == TSP_ENABLE_ADVANCED)

// ----- Trigger signal to activate trigger captures and notification state
static uint8_t triggerActive = false;
static uint32_t triggerRequestTotalCaptureCount = 0;
static uint32_t triggerRequestSequence = 0;
static uint32_t triggerRequestCallerHandle = 0;
static uint32_t triggerCompletedTotalCaptureCount = 0;
static uint32_t triggerCompletedSequence = 0;
static uint32_t triggerCompletedCallerHandle = 0;
static uint32_t triggerLastSentSequence = 0;

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

// ----- TspDispatchTable0204 -----:
Model_Target_TSP_Capture_type actual_TspDispatchTable0204[] =
{
    /*  "PreAmpAudiopilotAudiopilotBassBoostDb" '<S221>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.0*/
        &GetTspBlindPreAmpAudiopilotAudiopilotBassBoostDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotAudiopilotBoostGain" '<S235>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.1*/
        &GetTspBlindPreAmpAudiopilotAudiopilotBoostGain,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotAudiopilotMidrangeBoostDb" '<S222>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.2*/
        &GetTspBlindPreAmpAudiopilotAudiopilotMidrangeBoostDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotAudiopilotTrebleBoostDb" '<S223>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.3*/
        &GetTspBlindPreAmpAudiopilotAudiopilotTrebleBoostDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotDyneqBassBoostDb" '<S224>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.4*/
        &GetTspBlindPreAmpAudiopilotDyneqBassBoostDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotDyneqBoostGain" '<S236>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.5*/
        &GetTspBlindPreAmpAudiopilotDyneqBoostGain,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoiseDbspl" '<S225>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.6*/
        &GetTspBlindPreAmpAudiopilotHfNoiseDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoiseImpulseRejectionFlatness" '<S301>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.7*/
        &GetTspBlindPreAmpAudiopilotHfNoiseImpulseRejectionFlatness,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoiseImpulseRejectionPmin" '<S292>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.8*/
        &GetTspBlindPreAmpAudiopilotHfNoiseImpulseRejectionPmin,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoiseMicPsdLevel" '<S269>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.9*/
        &GetTspBlindPreAmpAudiopilotHfNoiseMicPsdLevel,
        sizeof(creal32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoisePostSlew" '<S283>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.10*/
        &GetTspBlindPreAmpAudiopilotHfNoisePostSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoisePowerSpectralDensity" '<S262>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.11*/
        &GetTspBlindPreAmpAudiopilotHfNoisePowerSpectralDensity,
        sizeof(real32_T) * 65,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHfNoisePreSlew" '<S284>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.12*/
        &GetTspBlindPreAmpAudiopilotHfNoisePreSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotHvacDbspl" '<S41>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.13*/
        &GetTspBlindPreAmpAudiopilotHvacDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotIgnoreMicFlag" '<S226>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.14*/
        &GetTspBlindPreAmpAudiopilotIgnoreMicFlag,
        sizeof(boolean_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseDbspl" '<S227>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.15*/
        &GetTspBlindPreAmpAudiopilotLfNoiseDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef" '<S384>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.16*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionFiltCoef,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionFilterOut" '<S382>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.17*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionFilterOut,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance" '<S385>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.18*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionImpulseVariance,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance" '<S388>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.19*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionMusicVariance,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance" '<S391>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.20*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionNoiseVariance,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance" '<S394>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.21*/
        &GetTspBlindPreAmpAudiopilotLfNoiseImpulseRejectionTotalVariance,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseMicLevel" '<S357>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.22*/
        &GetTspBlindPreAmpAudiopilotLfNoiseMicLevel,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseMicOut" '<S358>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.23*/
        &GetTspBlindPreAmpAudiopilotLfNoiseMicOut,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseMusicOut" '<S359>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.24*/
        &GetTspBlindPreAmpAudiopilotLfNoiseMusicOut,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseNoiseOut" '<S361>/TSP' Rate-Factor:9984U*/
    {                                  /*Index TspDispatchTable0204.25*/
        &GetTspBlindPreAmpAudiopilotLfNoiseNoiseOut,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoisePostSlew" '<S362>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.26*/
        &GetTspBlindPreAmpAudiopilotLfNoisePostSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoisePreSlew" '<S363>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.27*/
        &GetTspBlindPreAmpAudiopilotLfNoisePreSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoisePreSpeedBound" '<S364>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.28*/
        &GetTspBlindPreAmpAudiopilotLfNoisePreSpeedBound,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMax" '<S440>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.29*/
        &GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsCurrMax,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseSpeedBoundsCurrMin" '<S441>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.30*/
        &GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsCurrMin,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotLfNoiseSpeedBoundsFlag" '<S442>/TSP' Rate-Factor:3328U*/
    {                                  /*Index TspDispatchTable0204.31*/
        &GetTspBlindPreAmpAudiopilotLfNoiseSpeedBoundsFlag,
        sizeof(real_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotNoiseRatio" '<S228>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.32*/
        &GetTspBlindPreAmpAudiopilotNoiseRatio,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotRatioPostSlew" '<S452>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.33*/
        &GetTspBlindPreAmpAudiopilotRatioPostSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotRatioPreSlew" '<S453>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.34*/
        &GetTspBlindPreAmpAudiopilotRatioPreSlew,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotRatioUpdateFlag" '<S456>/TSP' Rate-Factor:832U*/
    {                                  /*Index TspDispatchTable0204.35*/
        &GetTspBlindPreAmpAudiopilotRatioUpdateFlag,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotTotalBassBoostDb" '<S229>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.36*/
        &GetTspBlindPreAmpAudiopilotTotalBassBoostDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotVehicleSpeed" '<S46>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.37*/
        &GetTspBlindPreAmpAudiopilotVehicleSpeed,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpAudiopilotWbNoiseDbspl" '<S230>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.38*/
        &GetTspBlindPreAmpAudiopilotWbNoiseDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpLevelWatchAudiopilotEnvDb" '<S496>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.39*/
        &GetTspBlindPreAmpLevelWatchAudiopilotEnvDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpLevelWatchAudiopilotLevelDbspl" '<S497>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.40*/
        &GetTspBlindPreAmpLevelWatchAudiopilotLevelDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpLevelWatchDyneqEnvDb" '<S509>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.41*/
        &GetTspBlindPreAmpLevelWatchDyneqEnvDb,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpLevelWatchDyneqLevelDbspl" '<S510>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0204.42*/
        &GetTspBlindPreAmpLevelWatchDyneqLevelDbspl,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },
};

uint32_t TspDispatchTable0204Count = sizeof(actual_TspDispatchTable0204)/sizeof
    (actual_TspDispatchTable0204[0]);
void* TspDispatchTable0204 = actual_TspDispatchTable0204;

// ----- TspDispatchTable0202 -----:
Model_Target_TSP_Capture_type actual_TspDispatchTable0202[] =
{
    /*  "PreAmpMedusaDummyState" '<S632>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0202.0*/
        &GetTspBlindPreAmpMedusaDummyState,
        sizeof(int32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },
};

uint32_t TspDispatchTable0202Count = sizeof(actual_TspDispatchTable0202)/sizeof
    (actual_TspDispatchTable0202[0]);
void* TspDispatchTable0202 = actual_TspDispatchTable0202;

// ----- TspDispatchTable0203 -----:
Model_Target_TSP_Capture_type actual_TspDispatchTable0203[] =
{
    /*  "PreAmpMedusaMonoDetectorIsActive" '<S837>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0203.0*/
        &GetTspBlindPreAmpMedusaMonoDetectorIsActive,
        sizeof(int32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpMedusaMonoDetectorIsStereo" '<S836>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0203.1*/
        &GetTspBlindPreAmpMedusaMonoDetectorIsStereo,
        sizeof(uint32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PreAmpMedusaMonoDetectorLevelCenter" '<S841>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0203.2*/
        &GetTspBlindPreAmpMedusaMonoDetectorLevelCenter,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },
};

uint32_t TspDispatchTable0203Count = sizeof(actual_TspDispatchTable0203)/sizeof
    (actual_TspDispatchTable0203[0]);
void* TspDispatchTable0203 = actual_TspDispatchTable0203;

// ----- TspDispatchTable0100 -----:
Model_Target_TSP_Capture_type actual_TspDispatchTable0100[] =
{
    /*  "NearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB" '<S1876>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0100.0*/
        &GetTspBlindNearAnn1Ann1NonEntGainCalcGetNonEntBoostLeveldB,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "NearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB" '<S1956>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0100.1*/
        &GetTspBlindNearAnn2Ann2NonEntGainCalcGetNonEntBoostLeveldB,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "NearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB" '<S2036>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0100.2*/
        &GetTspBlindNearAnn3Ann3NonEntGainCalcGetNonEntBoostLeveldB,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "NearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB" '<S2116>/TSP' Rate-Factor:13U*/
    {                                  /*Index TspDispatchTable0100.3*/
        &GetTspBlindNearAnn4Ann4NonEntGainCalcGetNonEntBoostLeveldB,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },
};

uint32_t TspDispatchTable0100Count = sizeof(actual_TspDispatchTable0100)/sizeof
    (actual_TspDispatchTable0100[0]);
void* TspDispatchTable0100 = actual_TspDispatchTable0100;

// ----- TspDispatchTable0300 -----:
Model_Target_TSP_Capture_type actual_TspDispatchTable0300[] =
{
    /*  "PostProcessEnergyLimiterComputedEnergy" '<S2203>/TSP' Rate-Factor:12U*/
    {                                  /*Index TspDispatchTable0300.0*/
        &GetTspBlindPostProcessEnergyLimiterComputedEnergy,
        sizeof(real32_T) * 24,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PostProcessEnergyLimiterCurGain" '<S2204>/TSP' Rate-Factor:12U*/
    {                                  /*Index TspDispatchTable0300.1*/
        &GetTspBlindPostProcessEnergyLimiterCurGain,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PostProcessEnergyLimiterCurState" '<S2206>/TSP' Rate-Factor:12U*/
    {                                  /*Index TspDispatchTable0300.2*/
        &GetTspBlindPostProcessEnergyLimiterCurState,
        sizeof(int16_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PostProcessEnergyLimiterEnableFlag" '<S2207>/TSP' Rate-Factor:12U*/
    {                                  /*Index TspDispatchTable0300.3*/
        &GetTspBlindPostProcessEnergyLimiterEnableFlag,
        sizeof(int16_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },

    /*  "PostProcessEnergyLimiterEnergyThreshold" '<S2205>/TSP' Rate-Factor:12U*/
    {                                  /*Index TspDispatchTable0300.4*/
        &GetTspBlindPostProcessEnergyLimiterEnergyThreshold,
        sizeof(real32_T) * 1,

#if (1 == TSP_ENABLE_ADVANCED)

        0, 0, 0, 0, (int8_t*)NULL
#endif                                 // (1 == TSP_ENABLE_ADVANCED)
    },
};

uint32_t TspDispatchTable0300Count = sizeof(actual_TspDispatchTable0300)/sizeof
    (actual_TspDispatchTable0300[0]);
void* TspDispatchTable0300 = actual_TspDispatchTable0300;

#if (1 == TSP_ENABLE_ADVANCED)

// Capture buffer
static int8_t tspCaptureBuffer[TSP_CAPTURE_BUFFER_SIZE];

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

// "Quick lookup" flags to determine if a partition is capturing
static char partitionActiveFlag[256] =
{
    0
};

// File scope function prototypes
static void GetTableByMsgId(uint32_t msgId, Model_Target_TSP_Capture_type*
    * theTable, uint32_t* tableSize);
static void GetTableByPartitionIndex(int partitionIndex,
    Model_Target_TSP_Capture_type** theTable, uint32_t* tableSize);
static int GetPartitionIndex(uint32_t msgId);

#if (1 == TSP_ENABLE_ADVANCED)

static bool IsPartitionActive(int partitionIndex);
static uint32_t GetRequiredCaptureBufferBytes(void);
static int32_t TSP_CaptureListAdd(TspListAddReqType* theReq, uint32_t
    bufferBytes);
static ASDSTATUS TSP_CaptureListSub(TspListSubReqType* subReq);
static void TSP_CaptureListClear(void);
static uint32_t TSP_CaptureTrigger(int8_t* captureBuffer, uint32_t bufferBytes);
static bool TSP_CaptureCheckComplete(void);
static uint32_t TSP_CaptureRetrievalSize(void);
static ASDSTATUS TSP_CaptureRetrieve(TspRetrieveReqType* theReq,
    uint32_t* charsReturnedOut, int8_t* bufferOut, uint32_t bufferOutSize);

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

static ASDSTATUS TSP_BlindRead(TspBlindReadReqType* theReq,
    uint32_t* charsReturnedOut, int8_t* bufferOut, uint32_t bufferOutSize);

/** Handle Target State Prob request (TSP) and generate response payload (if any).
 * NOTE: This function integrates with HandleAsdIdRequest. It is not intended
 * to be called directly if @ref Model_Target_HandleAsdIdRequest is more convenient.
 *  @param pReqBuf Request buffer containing RTC request*  @param reqBufSize number of bytes used in the request buffer
 *  @param pRspBuf Response buffer to receive response of AsdIdStatus_type*  @param rspBufSize Size of available bytes provided for the response to fill
 *  @return Returns the toal number of bytes utilized in the response buffer, or
 *          ASDSTATUS_RSP_BUFFER_SMALL if the response buffer is too small to
 *          contain a AsdIdStatus_type payload. If the returned value is positive,
 *          the caller must check the AsdIdStatus_type's statusCode. If the
 *          status code is less than zero, then any further reponse "data" as
 *          defined by the RTC service will not be present (i.e. there probably
 *          was not space for it anyway).
 *
 * @ingroup rtc
 */
int Model_Target_HandleTspRequest(void* pReqBuf, uint32_t reqBufSize,
    void* pRspBuf, uint32_t rspBufSize)
{
    // returns number of bytes
    int retVal = 0;
    int status = ASDSTATUS_OK;

    // parse out the message id
    if (reqBufSize < sizeof(uint32_T) || pReqBuf == 0)
    {
        return ASDSTATUS_REQ_BUFFER_SMALL;
    }

    if (rspBufSize < sizeof(AsdIdStatus_type) || pRspBuf == 0)
    {
        return ASDSTATUS_RSP_BUFFER_SMALL;
    }

    // setup cast of the response buffer (if any)
    uint32_t msgId = ((uint32_t*)pReqBuf)[0];
    uint32_t callerHandle = ((uint32_t*)pReqBuf)[1];
    AsdIdStatus_type* rspStatusBuf = (AsdIdStatus_type*)pRspBuf;
    rspStatusBuf->msgId = msgId;
    rspStatusBuf->callerHandle = callerHandle;

    // Setup default returned size & override as necessary
    retVal = sizeof(AsdIdStatus_type);

    // Extract TSP information from the msgId
    uint32_t tspCmd = RTCID_INFO(msgId);
    switch (tspCmd)
    {

#if (1 == TSP_ENABLE_ADVANCED)

      case TSP_COMMAND_LIST_ADD:
        {
            TspListAddReqType* theReq = (TspListAddReqType*)pReqBuf;
            if (reqBufSize < sizeof(TspListAddReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                status = TSP_CaptureListAdd(theReq, TSP_CAPTURE_BUFFER_SIZE);
            }
        }
        break;

      case TSP_COMMAND_LIST_SUB:
        {
            TspListSubReqType* theReq = (TspListSubReqType*)pReqBuf;
            if (reqBufSize < sizeof(TspListSubReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                status = TSP_CaptureListSub(theReq);
            }
        }
        break;

      case TSP_COMMAND_LIST_CLEAR:
        {
            if (reqBufSize < sizeof(TspListClearReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                TSP_CaptureListClear();
            }
        }
        break;

      case TSP_COMMAND_CAPTURE:
        {
            TspCaptureReqType* theReq = (TspCaptureReqType*)pReqBuf;
            if (reqBufSize < sizeof(TspCaptureReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                uint32_t totalCaptures = TSP_CaptureTrigger(&tspCaptureBuffer[0],
                    TSP_CAPTURE_BUFFER_SIZE);

                // setup state to support capture complete notification
                triggerRequestSequence++;
                triggerRequestTotalCaptureCount = totalCaptures;
                triggerRequestCallerHandle = theReq->callerHandle;
            }
        }
        break;

      case TSP_COMMAND_RETRIEVE:
        {
            TspRetrieveReqType* theReq = (TspRetrieveReqType*)pReqBuf;
            if (reqBufSize < sizeof(TspRetrieveReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                uint32_t requiredRspSize = sizeof(TspRetrieveRspType) +
                    theReq->charCount;
                if (rspBufSize < requiredRspSize)
                {
                    status = ASDSTATUS_RSP_BUFFER_SMALL;
                }
                else
                {
                    retVal = requiredRspSize;
                    TspRetrieveRspType* theRsp = (TspRetrieveRspType*)pRspBuf;
                    status = TSP_CaptureRetrieve(theReq,
                        &(theRsp->charCount), theRsp->data, theReq->charCount);
                }
            }
        }
        break;

#else

      case TSP_COMMAND_LIST_ADD:
      case TSP_COMMAND_LIST_SUB:
      case TSP_COMMAND_LIST_CLEAR:
      case TSP_COMMAND_CAPTURE:
      case TSP_COMMAND_RETRIEVE:
        // All advanced triggered capture code is removed from the image.
        // Return a special error code informing caller that this binary is
        // not able to service triggered capture requests.
        status = ASDSTATUS_TSP_CAPTURE_ALL_OFF;
        break;

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

      case TSP_COMMAND_BLIND_READ:
        {
            TspBlindReadReqType* theReq = (TspBlindReadReqType*)pReqBuf;
            if (reqBufSize < sizeof(TspBlindReadReqType))
            {
                status = ASDSTATUS_REQ_BUFFER_SMALL;
            }
            else
            {
                uint32_t requiredRspSize = sizeof(TspBlindReadRspType) +
                    theReq->charCount;
                if (rspBufSize < requiredRspSize)
                {
                    status = ASDSTATUS_RSP_BUFFER_SMALL;
                }
                else
                {
                    retVal = requiredRspSize;
                    TspBlindReadRspType* theRsp = (TspBlindReadRspType*)pRspBuf;
                    status = TSP_BlindRead(theReq, &(theRsp->charCount),
                                           theRsp->data, theReq->charCount);
                }
            }
        }
        break;

      default:
        status = ASDSTATUS_RTC_UNKNOWN_SERVICE;
    }

    // If the request-response was successful, everything is already all set.
    // Otherwise - handle errors by attempting to return an error response:
    rspStatusBuf->statusCode = status;
    if (status < 0)
    {
        // Response buffer looks ready to receive error, so return it
        // Copy caller handle and message id still available from the REQ:
        retVal = sizeof(AsdIdStatus_type);
    }

    return retVal;
}

static void GetTableByMsgId(uint32_t msgId, Model_Target_TSP_Capture_type*
    * theTable, uint32_t* tableSize)
{
    int partitionIndex = GetPartitionIndex(msgId);
    GetTableByPartitionIndex(partitionIndex, theTable, tableSize);
}

static void GetTableByPartitionIndex(int partitionIndex,
    Model_Target_TSP_Capture_type** theTable, uint32_t* tableSize)
{
    PartitionRoot_type* partitionRoot = GetPartitionRootByIndex(partitionIndex);
    if (partitionRoot && partitionRoot->tspTable && partitionRoot->tspCount)
    {
        *theTable = *(Model_Target_TSP_Capture_type**)partitionRoot->tspTable;
        *tableSize = *partitionRoot->tspCount;
    }
    else
    {
        *theTable = 0;
        *tableSize = 0;
    }
}

static int GetPartitionIndex(uint32_t msgId)
{
    uint32_t groupNumber = ASDID_GROUP(msgId);
    uint32_t partitionNumber = ASDID_PARTITION(msgId);
    return ((groupNumber & 0xf) * 16U) + (partitionNumber & 0xf);
}

//-------------------------------------------------------------------------
// Advanced TSP capture capabilities
#if (1 == TSP_ENABLE_ADVANCED)

// Returns true if anything in partition desires captures
static bool IsPartitionActive(int partitionIndex)
{
    bool isActive = false;
    PartitionRoot_type* partitionRoot = GetPartitionRootByIndex(partitionIndex);
    Model_Target_TSP_Capture_type* theTable = (Model_Target_TSP_Capture_type*)
        partitionRoot->tspTable;
    int tableSize = *partitionRoot->tspCount;
    int i;
    for (i = 0; i < tableSize; i++)
    {
        Model_Target_TSP_Capture_type* theEntry = &theTable[i];
        if (theEntry->capturesDesired > 0)
        {
            isActive = true;
            break;
        }
    }

    return isActive;
}

// Capture TSP during step operations (i.e. AUDIO THREAD!)
void TSP_StepCapture(void* tablePtr, uint32_t tableIndex, const void
                     * sourceBuffer)
{
    // Assume the tableIndex is good because it was placed by generated code
    // if a capture is happening (and a safety check for table bounds)
    if (triggerActive)
    {
        // access the table entry and perform the capture
        Model_Target_TSP_Capture_type* theEntry =
            &(((Model_Target_TSP_Capture_type*)tablePtr)[tableIndex]);

        // if the desired number of captures have not yet been completed
        // (... and there's an address of where to capture)
        if (theEntry->capturesComplete < theEntry->capturesDesired
            /*[safe]*/
            && theEntry->captureAddress)
        {
            // First check that the skip interval has passed
            if (theEntry->skipCounter >= theEntry->captureSkipInterval)
            {
                // Setup a destination header struct inside the capture buffer
                uint32_t requiredBytes = theEntry->sizeInChar;
                int8_t* destination = (int8_t*)
                    (theEntry->captureAddress + (requiredBytes *
                      theEntry->capturesComplete));

                // Copy in data from the TSP source buffer and reset the skip counter
                memcpy(destination, sourceBuffer, theEntry->sizeInChar);
                ++(theEntry->capturesComplete);
                theEntry->skipCounter = 0;
            }
            else
            {
                // Skip this frame
                ++(theEntry->skipCounter);
            }
        }
    }
}

static uint32_t GetRequiredCaptureBufferBytes()
{
    uint32_t i;
    uint32_t totalBytes = 0;
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    int p;
    for (p=0; p<256; p++)
    {
        if (partitionActiveFlag[p])
        {
            GetTableByPartitionIndex(p,&theTable,&tableSize);
            for (i = 0; i < tableSize; i++)
            {
                Model_Target_TSP_Capture_type* theEntry = &theTable[i];
                uint32_t unitBytes = theEntry->sizeInChar;
                uint32_t requiredBytes = unitBytes * theEntry->capturesDesired;
                totalBytes += requiredBytes;
            }
        }
    }

    return totalBytes;
}

// Add TSP to capture list, returns ASDID status code (ASDSTATUS_TSP_CAPTURE_OVERFLOW if no room in buffer for this request)
static ASDSTATUS TSP_CaptureListAdd(TspListAddReqType* theReq, uint32_t
    bufferBytes)
{
    // TODO - FAIL any add requests if a trigger is currently active
    // ... because the desired capture count changes here!
    ASDSTATUS retVal = ASDSTATUS_OK;
    uint32_t tableIndex = RTCID_INDEX(theReq->msgId);
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    GetTableByMsgId(theReq->msgId, &theTable, &tableSize);
    if (tableIndex < tableSize)
    {
        Model_Target_TSP_Capture_type* theEntry = &theTable[tableIndex];
        if (theEntry->captureSkipInterval == (uint32_t)-1)
        {
            // Ability to perform triggered capture is not available for this TSP
            retVal = ASDSTATUS_TSP_CAPTURE_THIS_OFF;
        }
        else
        {
            // See if the buffer is big enough
            uint32_t previousWishes = theEntry->capturesDesired;
            theEntry->capturesDesired = theReq->captureCount;

            // Mark this partition active to participate in required size
            int partitionIndex = GetPartitionIndex(theReq->msgId);
            partitionActiveFlag[partitionIndex] = 1;
            uint32_t requiredBytes = GetRequiredCaptureBufferBytes();
            if (requiredBytes > bufferBytes)
            {
                // oops - buffer not big enough. Roll back to previous state
                // ... and return an error status
                retVal = ASDSTATUS_TSP_CAPTURE_OVERFLOW;
                theEntry->capturesDesired = previousWishes;

                // Reset partition active state to the way it should be
                bool isActive = IsPartitionActive(partitionIndex);
                partitionActiveFlag[partitionIndex] = isActive;
            }
            else
            {
                // Looks good. Record the desired skip interval as well
                theEntry->captureSkipInterval = theReq->skipInterval;
            }
        }
    }
    else
    {
        retVal = ASDSTATUS_TSP_BAD_STATE_ID;
    }

    return retVal;
}

static ASDSTATUS TSP_CaptureListSub(TspListSubReqType* theReq )
{
    ASDSTATUS retVal = ASDSTATUS_OK;
    uint32_t tableIndex = RTCID_INDEX(theReq->msgId);
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    GetTableByMsgId(theReq->msgId, &theTable, &tableSize);
    if (tableIndex < tableSize)
    {
        Model_Target_TSP_Capture_type* theEntry = &theTable[tableIndex];
        theEntry->capturesDesired = 0;

        // Clear the partition's active flag if this was the only capture
        int partitionIndex = GetPartitionIndex(theReq->msgId);
        bool isActive = IsPartitionActive(partitionIndex);
        partitionActiveFlag[partitionIndex] = isActive;
    }
    else
    {
        retVal = ASDSTATUS_TSP_BAD_STATE_ID;
    }

    return retVal;
}

static void TSP_CaptureListClear()
{
    uint32_t i;
    uint32_t tableSize;
    Model_Target_TSP_Capture_type* theTable = 0;

    // Blindly clear every partition and its active flags
    int p;
    for (p=0; p<256; p++)
    {
        GetTableByPartitionIndex(p,&theTable,&tableSize);
        for (i=0; i < tableSize; i++)
        {
            Model_Target_TSP_Capture_type* theEntry = &theTable[i];
            theEntry->capturesDesired = 0;
        }

        partitionActiveFlag[p] = 0;
    }
}

// Setup and trigger a capture to happen
static uint32_t TSP_CaptureTrigger(int8_t* captureBuffer, uint32_t bufferBytes)
{
    uint32_t i;
    uint32_t totalBytes = 0;
    uint32_t totalCaptures = 0;

    // ensure that no captures are happening
    triggerActive = false;
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    int p;
    for (p=0; p<256; p++)
    {
        if (partitionActiveFlag[p])
        {
            GetTableByPartitionIndex(p,&theTable,&tableSize);

            // setup the capture address for each desired TSP
            for (i = 0; i < tableSize; i++)
            {
                Model_Target_TSP_Capture_type* theEntry = &theTable[i];

                // Reset the counter - all captures will begin anew just before
                // exiting this function (when triggerActive becomes true)
                theEntry->capturesComplete = 0;
                theEntry->skipCounter = 0;

                // If captures are desired, set up where to put them.
                if (theEntry->capturesDesired > 0)
                {
                    uint32_t unitBytes = theEntry->sizeInChar;
                    uint32_t requiredBytes = unitBytes *
                        theEntry->capturesDesired;
                    if ((totalBytes + requiredBytes) <= bufferBytes)
                    {
                        totalCaptures += theEntry->capturesDesired;
                        theEntry->captureAddress = captureBuffer + totalBytes;
                        totalBytes += requiredBytes;
                    }
                    else
                    {
                        // We should never run out of space because the ListAdd was
                        // supposed to check that size was available. Nevertheless,
                        // to handle this unexpected turn of events, kill the capture
                        // by clobbering the capture address. No capture will happen.
                        theEntry->captureAddress = 0;/*[safe]*/
                    }
                }
                else
                {
                    theEntry->captureAddress = 0;
                }
            }
        }                              // if partition active
    }                                  // loop partitions

    // release the triggers to happen ASAP
    triggerActive = true;
    return totalCaptures;
}

// Notification worker that checks if triggered capture is done
static bool TSP_CaptureCheckComplete()
{
    uint32_t i;
    bool complete = true;
    if (triggerActive)
    {
        Model_Target_TSP_Capture_type* theTable = 0;
        uint32_t tableSize;
        int p;
        for (p=0; (complete==true) && (p<256); p++)
        {
            if (partitionActiveFlag[p])
            {
                GetTableByPartitionIndex(p,&theTable,&tableSize);
                for (i=0; i < tableSize; i++)
                {
                    Model_Target_TSP_Capture_type* theEntry = &theTable[i];
                    if (theEntry->capturesComplete < theEntry->capturesDesired
                        /*[safe]*/
                        && theEntry->captureAddress)
                    {
                        // found one that still has work to do
                        complete = false;
                        break;
                    }
                }
            }                          // if partition active
        }                              // loop partitions
    }                                  // if trigger active

    // if the capture is complete, go ahead and shut the trigger off
    if (complete)
    {
        triggerActive = false;
    }

    return complete;
}

// Size of current capture data. Returns how many chars are required
// to contain the currently specified capture data.
static uint32_t TSP_CaptureRetrievalSize()
{
    uint32_t requiredBytes = GetRequiredCaptureBufferBytes();
    return requiredBytes;
}

/** Retrieve a single state value from the capture buffer filled by the last trigger.
 * @param tableIndex TSP index of the state which was previously
 *        added to the capture list.
 * @param captureIndex Sequential capture instance for this state (i.e. if the TSP
 *        was added to the list with a capture count of 3, then index values
 *        of 0, 1, and 2 are valid here.
 * @param offset Char offset into the captured state data resolved by the
 *        above tsp tableIndex and capture_instance index.
 * @param charsReturnedOut ptr to int to return the chars returned in buffer
 * @param bufferOut ptr to buffer to receive the data
 * @param bufferOutSize size of provided buffer
 * @return ASDSTATUS code: ASDSTATUS_OK,ASDSTATUS_TSP_BAD_STATE_ID,ASDSTATUS_TSP_CAPTURE_OVERFLOW  */
static ASDSTATUS TSP_CaptureRetrieve(TspRetrieveReqType* theReq,
    uint32_t* charsReturnedOut, int8_t* bufferOut, uint32_t bufferOutSize)
{
    ASDSTATUS retVal = ASDSTATUS_OK;
    uint32_t tableIndex = RTCID_INDEX(theReq->msgId);
    uint32_t offset = theReq->charOffset;
    uint32_t captureIndex = theReq->captureIndex;
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    GetTableByMsgId(theReq->msgId, &theTable, &tableSize);
    if (tableIndex < tableSize)
    {
        Model_Target_TSP_Capture_type* theEntry = &theTable[tableIndex];

        // Ensure the offset does not start off beyond the edge of data
        uint32_t tspSize = theEntry->sizeInChar;
        if ((theEntry->capturesComplete <= captureIndex) || (offset >= tspSize))
        {
            // There is no data that can even partially satisfy the request
            *charsReturnedOut = 0;
            retVal = ASDSTATUS_TSP_CAPTURE_OVERFLOW;
        }
        else
        {
            // seems ok - grab the data
            uint32_t unitBytes = theEntry->sizeInChar;
            uint32_t instanceOffset = unitBytes * captureIndex;
            int8_t* source = (theEntry->captureAddress + instanceOffset + offset);

            // Retrieve the minimum between these two choices:
            //   max-possible-size vs. output-buffer-size
            uint32_t maxRetrievalSize = theEntry->sizeInChar - offset;
            if (maxRetrievalSize < bufferOutSize)
            {
                // Not enough data to fill buffer, so copy what *is* available
                memcpy(bufferOut, source, maxRetrievalSize);

                // ... and pad the rest with 0
                memset(bufferOut+maxRetrievalSize, 0, bufferOutSize-
                       maxRetrievalSize);
                *charsReturnedOut = maxRetrievalSize;
            }
            else
            {
                // Fill the output buffer with data
                memcpy(bufferOut, source, bufferOutSize);
                *charsReturnedOut = bufferOutSize;
            }
        }
    }
    else
    {
        memset(bufferOut, 0, bufferOutSize);
        *charsReturnedOut = 0;
        retVal = ASDSTATUS_TSP_BAD_STATE_ID;
    }

    return retVal;
}

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

//-------------------------------------------------------------------------

/** Blindly read a state value directly from its source signal. The
 * integrity of the value is not reliable as audio processing can
 * happen during the middle of this read. (not recommended for multi-
 * word signals).
 * @param tableIndex Numeric index of the state to blindly read
 * @param offset Char offset into the signal source memory
 * @param charsReturnedOut ptr to int to return the chars returned in buffer
 * @param bufferOut ptr to buffer to receive the data
 * @param bufferOutSize size of provided buffer
 * @return ASDSTATUS code: ASDSTATUS_OK,ASDSTATUS_TSP_BAD_STATE_ID,ASDSTATUS_TSP_CAPTURE_OVERFLOW
 */
static ASDSTATUS TSP_BlindRead(TspBlindReadReqType* theReq,
    uint32_t* charsReturnedOut, int8_t* bufferOut, uint32_t bufferOutSize)
{
    ASDSTATUS retVal = ASDSTATUS_OK;
    uint32_t tableIndex = RTCID_INDEX(theReq->msgId);
    uint32_t offset = theReq->charOffset;
    Model_Target_TSP_Capture_type* theTable = 0;
    uint32_t tableSize;
    GetTableByMsgId(theReq->msgId, &theTable, &tableSize);
    if (tableIndex < tableSize)
    {
        Model_Target_TSP_Capture_type* theEntry = &theTable[tableIndex];

        // Ensure the offset does not start off beyond the edge of data
        uint32_t tspSize = theEntry->sizeInChar;
        if (offset >= tspSize)
        {
            // There is no data that can even partially satisfy the request
            *charsReturnedOut = 0;
            retVal = ASDSTATUS_TSP_CAPTURE_OVERFLOW;
        }
        else
        {
            // Read the signal *DIRECTLY* while it continues to change// Retrieve the minimum between these two choices:
            //   max-possible-size vs. output-buffer-size
            const int8_t* blindReadPtr = (int8_t*)(theEntry->GetBlindReadPtr)();
            uint32_t maxRetrievalSize = theEntry->sizeInChar - offset;
            if (maxRetrievalSize < bufferOutSize)
            {
                // Not enough data to fill buffer, so copy what *is* available
                memcpy(bufferOut, &blindReadPtr[offset], maxRetrievalSize);

                // ... and pad the rest with 0
                memset(bufferOut+maxRetrievalSize, 0, bufferOutSize-
                       maxRetrievalSize);
                *charsReturnedOut = maxRetrievalSize;
            }
            else
            {
                // Fill the output buffer with data
                memcpy(bufferOut, &blindReadPtr[offset], bufferOutSize);
                *charsReturnedOut = bufferOutSize;
            }
        }
    }
    else
    {
        memset(bufferOut, 0, bufferOutSize);
        *charsReturnedOut = 0;
        retVal = ASDSTATUS_TSP_BAD_STATE_ID;
    }

    return retVal;
}

/** Services TSP Notification - polling for request completion as well as
 * creating notification message payloads upon completion.
 * NOTE: the same thread that services RTC requests must be responsible for
 * servicing notifications as well. The two routines must not operate at the
 * same time or race conditions can lead to faulty operation.
 *  @param pNtfBuf Empty buffer read to receive a notification message.
 *  @param ntfBufSize Size of buffer in bytes.
 *  @returns Number of bytes used in the provided notification buffer (pNtfBuf).
 *          Return Value | Meaning
 *           ----------- | :--------
 *               0       | All done. No use in calling this again until audio processing happens.
 *             > 0       | A notification was returned with this many bytes used in buffer.
 *             < 0       | Error: buffer is too small. This is how many bytes are needed for the buffer (in negative form)
 * @ingroup rtc
 * @see AsdIdStatus_type for format of each notification message's header
 */
int Model_Target_ServiceTspNotification(void* pNtfBuf, uint32_t ntfBufSize)
{
    // Note assumption of single service thread that handles both
    // RTC message requests and this notification handler.
    int retVal = 0;

#if (1 == TSP_ENABLE_ADVANCED)

    // Calculate the table size - subtract one for the End Sentinel
    // Poll for completion if the current request is still pending
    if (triggerRequestSequence != triggerCompletedSequence)
    {
        // Not done last we checked. Check again now and
        // if the capture is done, capture status
        if (TSP_CaptureCheckComplete())
        {
            triggerCompletedSequence = triggerRequestSequence;
            triggerCompletedCallerHandle = triggerRequestCallerHandle;
            triggerCompletedTotalCaptureCount = triggerRequestTotalCaptureCount;
        }
    }

    // Attempt to send notification if a completed sequence is waiting to send
    if (triggerLastSentSequence != triggerCompletedSequence)
    {
        uint32_t requiredNtfBytes = sizeof(TspCaptureNtfType);
        bool ntfBufOK = (ntfBufSize >= requiredNtfBytes && pNtfBuf);
        if (ntfBufOK)
        {
            TspCaptureNtfType* statusHdr = (TspCaptureNtfType*)pNtfBuf;
            statusHdr->msgId = Model_Target_TSPID_CAPTURE;
            statusHdr->callerHandle = triggerCompletedCallerHandle;
            statusHdr->statusCode = ASDSTATUS_RTC_NOTIFICATION;
            statusHdr->totalCaptureCount = triggerCompletedTotalCaptureCount;
            retVal = requiredNtfBytes;
            triggerLastSentSequence = triggerCompletedSequence;
        }
        else
        {
            // indicate how many bytes should have been given - just make it negative
            retVal = (0 - requiredNtfBytes);
        }
    }

#endif                                 // (1 == TSP_ENABLE_ADVANCED)

    return retVal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
