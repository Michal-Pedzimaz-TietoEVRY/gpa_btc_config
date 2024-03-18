%% Please do not edit!
%% File automatically generated!

function x=auto_gen_sys_defs_gpa()

x=struct();

% System Parameters %

x.Fs=48000;
x.sampling_rate_in_hz=x.Fs;  %TODO: Remove duplicates
x.frameSize=32;
x.frame_size_in_samples=x.frameSize; %TODO: Remove duplicates
x.nAudioOut = 24;
x.nAuxOut = 14;
x.nChimesOut = 11;
x.number_of_input_entertainment_channels = 2;
x.number_of_output_audio_channels = x.nAudioOut; %TODO: Remove duplicates
x.number_of_output_channels = x.nAudioOut; %JK: Check if Medusa could be updated to remove this parameter
% One over the sampling rate (useful for some calculations).
x.sampling_period_in_seconds=2.26757369615e-05;

% Use ADI ROM table for sine (see math_lut.c).
x.sin_lookup_table_length=1024;

% Use ADI ROM table for sine (see math_lut.c).
x.sine_table_size=1024;
% Build parameters for Chimes %
x.nChimesIn = 16;

% Build parameters for ENT %
x.maxMusicDelay = 512;
x.decimated_sample_rate = x.Fs * (12/13);

% Build parameters for PASD %
x.pasdnumStagesInEqPerPathPerCh = 4;
x.pasdnumStagesOutEqPerPathPerCh = 4;

%% Build Parameters of Announcements

% Number of announcement paths
x.nAnnPaths = 4;
% Number of announcement inputs
x.nAnnIn = 4;
% Number of announcement outputs
x.nAnnOut = x.nAuxOut;
% Number of announcement inputs per path
x.nAnnInPerPath = 1;
% Number of Steered outputs per announcement Path
x.nAnnSteerOut = 6;

% Announcement output delay is used to buffer up garbage data during unlock events.
% It is applied to announcement output channels before a mute module.
x.announcement_output_delay_in_ms = 0;

% Maximum numbers of delay samples per announcement path
x.maxAnnDelay = 4096;

% Upper bound on the total number of EQ stages consumed by both input and output EQs per announcement path at
% one time (to conserve MIPS).  Enforced by Symfun build. Tuning can tradeoff where EQ
% stages are consumed.
% NOTE: This may be less than the total number of stages allcated (maxAnnInEqStages + maxAnnOutEqStages).
x.maxAnnEqStages = 126;

x.maxAnnInputEqStages = 8;

x.maxAnnOutputEqStages = 118;

x.Enable_IIRAccel_functionality = 0;

x.volumeInitialGain = 0;

% anngaincalc block specific build parameters
x.vncEnable = 1;
x.vncBoostGain = x.vncEnable;
x.NoiseOverRideFlag = 0;
x.NoiseOverRide = 0;
x.boostOverRide = 0;
x.boostOverRideFlag = 0;
x.rampTau = 0.1;

% annVNC block specific buil parameters
x.fsig = 20;        %Cut-off frequency of VNC low pass filter
x.Fs2 = x.Fs;      %Sampling frequency of VNC low pass filter

% annsteering block specific build parameters
x.PrevGainValues = 1;
x.snapthresh = 0.0001;
x.mindB = -100.0;
%%
%% Build Parameters of Medusa
% As of now there is no support for CAE without 5.1 surround input.
x.include_compressed_audio_enhancement=0;
% If true, Medusa creates dedicated signal processing chain
% for surround (5.1) inputs.
x.include_surround_input_support_in_medusa=0;
% These (LPF/HPF) filters are used for bass management,
% as well as Medusa bass filter. Used to be 5th order
% Butterworth, now changed to 6th order Linkwitz-Riley,
% i.e. two cascaded 3rd order Butterworth filters.
x.bass_manager_cross_over_filter_order=3;

% Cutoff frequency for Medusa bass cross-over filter.
x.medusa_bass_cutoff_frequency_in_hz=90;

% Upper bound cutoff frequency for Medusa passband.
x.medusa_passband_cutoff_frequency_in_hz=3000;

% Wiggle filter FIR length per channel. Must be even number as we are
% using bdspFirEven.
x.wiggle_filter_length=444;

% Medusa fft size
x.fft_size = 256;

% Medusa decimation factor
x.medusa_decimation_factor = 4;

% Medusa Holigram configs
x.maximum_holigram_fir_length = 652;
x.maximum_average_holigram_fir_length = 532;
x.maximum_decimated_rate_holigram_eq_stages = 20;
x.maximum_full_rate_holigram_eq_stages = 8;

% Current Medusa Holigram EQ supports either 6 or 8 eq links per speaker
x.medusa_holigram_eq_per_speaker = 8;       % JK: Switch to N8 when Medusa works

% For the platforms that use 215xx families of SHARC+ DSPs,
% set this option to use hardware FIR/IIR accelerators instead of
% core implementation for Medusa Holigram and Full-rate EQ.
% Implementation types: 0 - Core, 1 - Accel, 2 - Generic
x.use_sharc_accelerator_for_medusa_holigram_eq=2;

% Maximum Holigram filter response alignment delay
% This delay is to align the holigram filter response with the desired
% impulse response
x.maximum_holigram_filter_delay_in_samples = 1764;              % 40ms <==> 1764 samples

% Medusa delays
x.maximum_wiggle_filter_delay_per_channel_in_dec_samples = 166; % FR - 15ms <==> 662 samples

x.maximum_full_rate_eq_delay_in_samples = 45;                   % 1ms <==> 45 samples

x.maximum_medusa_output_delay_in_samples = 1323;                % 30 ms <==> 1323 samples

% JK: Clean this up when Medusa is stable
%x.maximum_holigram_filter_delay_in_ms = 40;
%
%% Medusa delays
%x.maximum_wiggle_filter_delay_per_channel_in_ms = 15;
%
%x.maximum_full_rate_eq_delay_in_ms = 1;
%
%x.maximum_medusa_output_delay_in_ms = 30;

% Number of outputs
x.medusa_number_of_center_channels = 2;

x.medusa_number_of_surround_channels = 0;

x.medusa_number_of_left_right_pairs = 8;

% Medusa sample rate
% This is added only to test run Medusa at 48KHz with or without SRC.
% The current Medusa is designed to only operate at 44.1 KHz.
x.medusa_sample_rate = (12/13)*48000;

% If premix is required to support CAE, the following parameter needs to be
% set to 1
x.include_CAE_support_in_medusa_premix = 1;     %TODO: Check for CAE coverage and remove, if unnecessary

% If this is set to 0, premix outputs only Lbass and Rbass (given, N8 config)
% If this is set to 1, split the premix bass component to front/rear
x.split_premix_bass_component = 1;
% Number of maximum frame delay for Spatial Unmasker
x.maximum_spum_frame_delay = 4;

% Default Routing Map for Medusa
% The routing map is  single-dimensional array. It is 0-based and 
% uses '-1' to interpret unused channels
x.medusa_routing_map = [0:1:x.nAudioOut-1];
% If this is set to 0, expose upmixer outputs at system level
% If this is set to 1, implement 'flat' routing scheme
x.medusa_routing_plan = 1;
% If this is set to 1, use Generic implementations only for Holigram EQ and
% VLS Gen
x.generate_generic_code = 1;
% This variable shall control the implementation type of poolIir instances
% not associated with Holigram EQ and VLS Gen
% Acceptable values for this parameter are as follows:
% Generic - 'Generic'
% SharcPlusCore - 'SharcPlusCore'
% SharcPlusAccelGul - 'SharcPlusAccelGul'
% Hexagon - 'Hexagon'
% ArmNeonV7V8 - 'ArmNeonV7V8'
% The value is case-sensitive
% Set rfft_variant (1: generic, 2: sharc, 3: hexagon)
x.rfft_variant = 3;
%%

%% VLS configs (These are needed by MedusaParams; not used by algorithm)
%x.maximum_headrest_component_eq_fir_length = 5; % 530
%
%x.maximum_headrest_component_eq_stages = 1; % 20
%
%x.maximum_vls_impulse_fir_length = 2; %64
%
%x.maximum_vls_tail_fir_length = 2;  %512


%% VLS configs (These are needed by MedusaParams; not used by algorithm)
x.maximum_headrest_component_eq_fir_length = 532; % 530
x.maximum_headrest_component_eq_stages = 20;      % 20
x.maximum_vls_impulse_fir_length = 64; %64
x.maximum_vls_tail_fir_length = 512;  %512

% 4 speakers x (18 straight path + 16 cross seat + 13 cross-car x 2)
x.maximum_number_of_crossarray_eq_stages = 240; % 240

% 4 speakers x (0 straight path + 20 cross seat + 50 cross-car near side +
% 80 cross-car far side)
x.maximum_crossarray_delay_in_samples = 600; % 600

% For the platforms that use 215xx families of SHARC+ DSPs,
% set this option to use hardware FIR/IIR accelerators instead of
% core implementation.
% Implementation types: 0 - Core, 1 - Accel, 2 - Generic
x.use_sharc_accelerator_for_vls_gen = 0;

x.use_sharc_accelerator_for_headrest_component_eq = 0;

% Number of headrest pairs for virtual loudspeaker processing
x.number_of_headrests_with_virtual_loudspeaker = 2;

% Maximum NEAR wiggle filter alignment delay
% This delay is to align the bass and treble audio with the NEAR wiggle
% filter latency introduced in midrange path. This value should be set to 0 if
% the application doesn't support NEAR processing
x.maximum_NEAR_wiggle_filter_delay_per_channel_in_dec_samples = 166;  %166;	% FR: 15ms <==> 662 samples

x.include_NEAR_wideband = 1;
%%
%% 3D Surround Config
% Number of overhead L/R speaker pairs
x.number_of_overhead_speaker_pairs = 0;

% Overhead Holigram configs
x.maximum_overhead_holigram_fir_length = 652;
x.maximum_average_overhead_holigram_fir_length = 532;
x.maximum_decimated_rate_overhead_holigram_eq_stages = 20;
%%
return;

end

