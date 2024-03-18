function MedusaParams = getMedusaParams(varargin)
% Helper to create Medusa config struct. This script extracts all 
% Medusa build time configs from auto_gen_sys_defs and derives other useful 
% parameters. The MedusaBuildTimeParams struct can then be passed to init scripts of 
% the sub-blocks inside Medusa5H1 for easy configuration.
% 
% Usage:
% MedusaParams = getMedusaParams(auto_gen_sys_defs)
%    Returns a struct with configuration parameters for Medusa5H1.
% MedusaParams = getMedusaParams()
%    Returns a struct with default configuration parameters.
%
% Below is a list of fields in the output config struct:
% MedusaParams.sampleRate : Sample rate (at full rate, in Hz)
% MedusaParams.fftSize : FFT block size
% MedusaParams.frameSize : Frame size 
% MedusaParams.decimation: Decimation factor    
% MedusaParams.numSystemOut: Number of supported output channels
% MedusaParams.defaultRoutingMap: Default routing map
% MedusaParams.routingPlan: Plan to determine system outputs
% MedusaParams.include_cae : Include Compressed Audio Enhancement (CAE)
% MedusaParams.include_surround_input: Add support for 5.1 surround input.
% MedusaParams.Fb : Bass cutoff frequency for Medusa
% MedusaParams.XOFOrder : Bass manager crossover filter order
% MedusaParams.wiggleFilterLength: Length of FIR wiggle filters
% MedusaParams.maximumWiggleFilterDelayInDecSamples : Self-explanatory
% MedusaParams.maximumSPUMFrameDelay: Maximum frames allocated for SPUM
% MedusaParams.maximumHoligramFilterDelayInSamples: Maximum holigram EQ delay in samples
% MedusaParams.maximumFullrateEQDelayInSamples: Maximum fullrate EQ delay in samples
% MedusaParams.maximumOutputDelayInSamples: Maximum output delay in samples
% MedusaParams.holigramDecFIRLengthMax: Maximum length of Holigram FIR filters
% MedusaParams.holigramDecFIRLengthAvg: Maximum of average length of Holigram FIR filters
% MedusaParams.holigramDecMaxNumStages: Maximum sos stages of Holigram IIR
% MedusaParams.holigramFullMaxNumStages: Maximum sos stages of Full-rate EQ
% MedusaParams.holigramEQLinkPerSpeaker: Number of Holigram EQ links per speaker
% MedusaParams.useAcceleratorForHoligramEQ: Self-explanatory
% MedusaParams.useAcceleratorForFullrateEQ: Self-explanatory
% MedusaParams.includePremixCAE: Include support for CAE Differentiation in Premix
% MedusaParams.splitPremixBassComp: Split premix bass component into front/rear
% MedusaParams.numCenterChannels: Number of Center output channels
% MedusaParams.numSurroundChannels: Number of Surround output channels
% MedusaParams.numLeftRightPairs: Number of Left or Right output channels
% MedusaParams.numHeadrestVLS: Number of supported headrest pairs for VLS
% MedusaParams.headrestCompEQFIRLengthMax: Maximum length of Headrest component EQ filters 
% MedusaParams.headrestCompEQMaxNumStages: Maximum sos stages of Headrest component EQ
% MedusaParams.vlsImpulseFilterLength: Maximum length of VLS impulse filters 
% MedusaParams.vlsTailFilterLength: Maximum length of VLS tail filters 
% MedusaParams.xtalkMaxNumStagesPool: Maximum sos stages of crossarray
% MedusaParams.xtalkMaxDelayPool: Maximum delay pool of crossarray
% MedusaParams.useAcceleratorForVLSGen: Self-explanatory
% MedusaParams.useAcceleratorForHeadrestCompEQ: Self-explanatory
% MedusaParams.maximumNEARWiggleFilterDelayInDecSamples: Maximum NEAR Wiggle Filter latency
% MedusaParams.numOverheadSpeakerPairs: Number of supported overhead speaker pairs for 3D surround
% 
% NOTE: placeholder for configs that might be useful in the future
% MedusaParams.numMedusaSteeredOut: number of Medusa output channels
% MedusaParams.include_sound_stage_stretching : Self-explanatory
% MedusaParams.include_spatial_unmasker : Self-explanatory
% MedusaParams.use_sharc_accelerator_for_medusa_out_upfir : Self-explanatory
% MedusaParams.use_sharc_accelerator_for_medusa_wiggle_filter : Self-explanatory
% MedusaParams.Medusa_Decouple_LR_Mixing : Flag indicating whether mixing weights
%     for L/R are independent
% MedusaParams.bandSplitOption : bandsplit option, see MedusaSplit
% MedusaParams.fullRateSTFTDelay : Latency caused by full-rate frequency
%     domain processing
% MedusaParams.max3dDelayInMs : Maximum 3D delay (for 5.1 surround)
    
    %% 
    % Generate default config if no auto_gen_sys_defs is found
    if nargin > 0
        sys_defs = varargin{1};
    else
        sys_defs = [];
    end
    if(isempty(sys_defs))
        % return default config
        MedusaParams = getDefaultMedusaParams();
        return;
    end

    
    %% DSP target
    MedusaParams.DspTarget = sys_defs.DspTarget;
    
    %% System
    MedusaParams.sampleRate = sys_defs.medusa_sample_rate; % 44100
    MedusaParams.frameSize = sys_defs.frameSize; % 32
    MedusaParams.fftSize = sys_defs.fft_size; % 256
    MedusaParams.numInputChannels = sys_defs.number_of_input_entertainment_channels;

    % Decimation factor for Medusa
    MedusaParams.decimation = sys_defs.medusa_decimation_factor; % 4
    
    % Number of supported output channels for an application
    % Note: This is not necessarily Medusa speaker outputs, since some
    % outputs can be specified as 'unused' in config.tune
    MedusaParams.numSystemOut = sys_defs.number_of_output_channels;
    
    % Default routing map
    MedusaParams.defaultRoutingMap = sys_defs.medusa_routing_map;
    MedusaParams.routingPlan = sys_defs.medusa_routing_plan;

    % Feature include
    MedusaParams.include_cae = sys_defs.include_compressed_audio_enhancement;
    MedusaParams.include_surround_input = sys_defs.include_surround_input_support_in_medusa;
    % MedusaConfig.include_fullrate_filterbank = feature_includes.include_fullrate_filterbank_in_medusa;

    % Platform configuration
    MedusaParams.variant = sys_defs.DspTarget;

    %% Bass Manager
    % Bass cutoff frequency for Medusa
    MedusaParams.Fb = sys_defs.medusa_bass_cutoff_frequency_in_hz; % 90

    % These (LPF/HPF) filters are used for bass management, as well as Medusa 
    % bass filter. It must be an odd number.
    MedusaParams.XOFOrder = sys_defs.bass_manager_cross_over_filter_order; %(5 -> 3)

    %% Band Split
    % Passband cutoff frequency for Medusa 
    % Remove since we now hardcode Fp as a factor of sample rate 
    %MedusaParams.Fp = sys_defs.medusa_passband_cutoff_frequency_in_hz; % 3000 

    %% Wiggle filter
    % Wiggle filter FIR length per channel. Must be even number as we are using bdspFirEven.
    MedusaParams.wiggleFilterLength = sys_defs.wiggle_filter_length; % 442
    % Maximum wiggle filter alignment delay limit per channel. This delay is to compensate for wiggle filter latency.
    MedusaParams.maximumWiggleFilterDelayInDecSamples = sys_defs.maximum_wiggle_filter_delay_per_channel_in_dec_samples; % 166
    % 3D delay limit per channel for Ls and Rs channels. This delay is applied to surround components to achieve 3D effect.
    % MedusaParams.max3dDelayInMs = sys_defs.max_3d_delay_in_ms; % 3
    
    %% Upmixers
    MedusaParams.maximumSPUMFrameDelay = sys_defs.maximum_spum_frame_delay; % 4
    
    %% Holigram EQ
    MedusaParams.holigramDecFIRLengthMax = sys_defs.maximum_holigram_fir_length;               % 650
    MedusaParams.holigramDecFIRLengthAvg = sys_defs.maximum_average_holigram_fir_length;       % 530
    MedusaParams.holigramDecMaxNumStages = sys_defs.maximum_decimated_rate_holigram_eq_stages; % 20
    MedusaParams.holigramFullMaxNumStages = sys_defs.maximum_full_rate_holigram_eq_stages;     % 8
    MedusaParams.holigramEQLinkPerSpeaker = sys_defs.medusa_holigram_eq_per_speaker;           % 8
    MedusaParams.useAcceleratorForHoligramEQ = sys_defs.use_sharc_accelerator_for_medusa_holigram_eq;
    MedusaParams.useAcceleratorForFullrateEQ = sys_defs.use_sharc_accelerator_for_medusa_holigram_eq;
    
    %% Tunable Delay
    MedusaParams.maximumHoligramFilterDelayInSamples = sys_defs.maximum_holigram_filter_delay_in_samples;  % 1764
    MedusaParams.maximumFullrateEQDelayInSamples = sys_defs.maximum_full_rate_eq_delay_in_samples; % 45
    MedusaParams.maximumOutputDelayInSamples = sys_defs.maximum_medusa_output_delay_in_samples;    % 1323

    %% Premix and Full-rate Mixer
    MedusaParams.includePremixCAE = sys_defs.include_CAE_support_in_medusa_premix;
    MedusaParams.splitPremixBassComp = sys_defs.split_premix_bass_component;
    
    %% Number of Output Channels
    MedusaParams.numCenterChannels = sys_defs.medusa_number_of_center_channels;     % 2
    MedusaParams.numSurroundChannels = sys_defs.medusa_number_of_surround_channels; % 1
    MedusaParams.numLeftRightPairs = sys_defs.medusa_number_of_left_right_pairs;    % 6
    
     %% VLS 
    MedusaParams.numHeadrestVLS = sys_defs.number_of_headrests_with_virtual_loudspeaker;
    MedusaParams.headrestCompEQFIRLengthMax = sys_defs.maximum_headrest_component_eq_fir_length; % 530
    MedusaParams.headrestCompEQMaxNumStages = sys_defs.maximum_headrest_component_eq_stages;     % 20
    MedusaParams.vlsImpulseFilterLength = sys_defs.maximum_vls_impulse_fir_length;  % 64
    MedusaParams.vlsTailFilterLength = sys_defs.maximum_vls_tail_fir_length;        % 512
    MedusaParams.xtalkMaxNumStagesPool = sys_defs.maximum_number_of_crossarray_eq_stages; % 240 
    MedusaParams.xtalkMaxDelayPool = sys_defs.maximum_crossarray_delay_in_samples;  % 600                                  
    MedusaParams.useAcceleratorForVLSGen = sys_defs.use_sharc_accelerator_for_vls_gen;
    MedusaParams.useAcceleratorForHeadrestCompEQ = sys_defs.use_sharc_accelerator_for_headrest_component_eq;  
    MedusaParams.numHeadrestComps = 6; % hardcode based on design
    MedusaParams.maximumNEARWiggleFilterDelayInDecSamples = sys_defs.maximum_NEAR_wiggle_filter_delay_per_channel_in_dec_samples; % 166
    
    %% 3D Surround
    MedusaParams.numOverheadSpeakerPairs = sys_defs.number_of_overhead_speaker_pairs; % 2
    MedusaParams.overheadHoligramDecFIRLengthMax = sys_defs.maximum_overhead_holigram_fir_length;               % 650
    MedusaParams.overheadHoligramDecFIRLengthAvg = sys_defs.maximum_average_overhead_holigram_fir_length;       % 530
    MedusaParams.overheadHoligramDecMaxNumStages = sys_defs.maximum_decimated_rate_overhead_holigram_eq_stages; % 20
    
    %% Optimization (placeholder)
    % Optimized/Generic implementation switch by overwritting useAccelerator parameters 
    MedusaParams.useGenericCode = sys_defs.generate_generic_code;
    if (MedusaParams.useGenericCode == 1)
        MedusaParams.useAcceleratorForHoligramEQ = 2; % use Generic implementation
        MedusaParams.useAcceleratorForFullrateEQ = 2; % use Generic implementation
        MedusaParams.useAcceleratorForVLSGen = 2; % use Generic implementation
        MedusaParams.useAcceleratorForHeadrestCompEQ = 2; % use Generic implementation
    end
    
    % % For the platforms that use 214xx families of SHARC DSPs, set this option to use hardware FIR accelerator instead of
    % % upfir at the output stage of Medusa 3D.
    % MedusaConfig.use_sharc_accelerator_for_medusa_out_upfir = sys_defs.use_accelerator_for_upfir; % 0

    % % For the platforms that use 214xx families of SHARC DSPs, set this option to use hardware FIR accelerator instead of
    % % upfir for the Wiggle Filter, used by Medusa's midrange (decimated-rate) tail components.
    % MedusaConfig.use_sharc_accelerator_for_medusa_wiggle_filter = sys_defs.use_sharc_accelerator_for_medusa_wiggle_filter; % 0
    
end

function DefaultMedusaParams = getDefaultMedusaParams()
    DefaultMedusaParams = struct;
    DefaultMedusaParams.numInputChannels = 2;
    DefaultMedusaParams.sampleRate = 44100;
    DefaultMedusaParams.frameSize = 32; 
    DefaultMedusaParams.fftSize = 256;
    DefaultMedusaParams.decimation = 4;
    DefaultMedusaParams.numSystemOut = 16;
    DefaultMedusaParams.defaultRoutingMap = [0:1:15];
    DefaultMedusaParams.routingPlan = 0;
    DefaultMedusaParams.include_cae = 1;
    DefaultMedusaParams.include_surround_input = 0;
    DefaultMedusaParams.Fb = 90;
    DefaultMedusaParams.XOFOrder = 3;
    DefaultMedusaParams.wiggleFilterLength = 442; 
    DefaultMedusaParams.maximumWiggleFilterDelayInDecSamples = 166;
    DefaultMedusaParams.maximumSPUMFrameDelay   = 4;
    DefaultMedusaParams.holigramDecFIRLengthMax = 650; 
    DefaultMedusaParams.holigramDecFIRLengthAvg = 530;
    DefaultMedusaParams.holigramDecMaxNumStages = 20; 
    DefaultMedusaParams.holigramFullMaxNumStages = 8; 
    DefaultMedusaParams.holigramEQLinkPerSpeaker = 8;
    DefaultMedusaParams.useAcceleratorForHoligramEQ = 0;
    DefaultMedusaParams.useAcceleratorForFullrateEQ = 0;
    DefaultMedusaParams.maximumHoligramFilterDelayInSamples = 1764;
    DefaultMedusaParams.maximumFullrateEQDelayInSamples = 45;
    DefaultMedusaParams.maximumOutputDelayInSamples = 1323;
    DefaultMedusaParams.includePremixCAE = 0;
    DefaultMedusaParams.splitPremixBassComp = 0;
    DefaultMedusaParams.numCenterChannels = 2;
    DefaultMedusaParams.numSurroundChannels = 1;
    DefaultMedusaParams.numLeftRightPairs = 6;
    DefaultMedusaParams.useGenericCode = 0;
    DefaultMedusaParams.variant = 'Generic';
    DefaultMedusaParams.numHeadrestVLS = 0;
    DefaultMedusaParams.headrestCompEQFIRLengthMax = 530;
    DefaultMedusaParams.headrestCompEQMaxNumStages = 20;
    DefaultMedusaParams.vlsImpulseFilterLength = 64;
    DefaultMedusaParams.vlsTailFilterLength = 512;
    DefaultMedusaParams.xtalkMaxNumStagesPool = 240; 
    DefaultMedusaParams.xtalkMaxDelayPool = 600;
    DefaultMedusaParams.useAcceleratorForVLSGen = 0;
    DefaultMedusaParams.useAcceleratorForHeadrestCompEQ = 0;
    DefaultMedusaParams.numHeadrestComps = 6;
    DefaultMedusaParams.maximumNEARWiggleFilterDelayInDecSamples = 166;
    DefaultMedusaParams.numOverheadSpeakerPairs = 2;
    DefaultMedusaParams.overheadHoligramDecFIRLengthMax = 650;
    DefaultMedusaParams.overheadHoligramDecFIRLengthAvg = 530;
    DefaultMedusaParams.overheadHoligramDecMaxNumStages = 20;
end