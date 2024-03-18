%disp('Running NEARInit')


% Model Parameters
if exist('sampleRate', 'var')
    NEAR_sample_rate_in_hertz = sampleRate;
else
    NEAR_sample_rate_in_hertz = 44100;
end
NEAR_frame_size = 32;
NEAR_ann_sysin_channel_count = 4;
NEAR_decimation_factor = 4;
NEAR_rear_channel_count = 3;

% Moved the following two lines up here because thay are needed for the channel EQs
NEAR_front_peripheral_channel_count = 7;
NEAR_headrest_count = 2;


% Parameters

% Noise RTC
NEAR_initial_noise_level = 0;

% anngaincalc
NEAR_agc.enable = 1;
NEAR_agc.boost_gain = 1;
NEAR_agc.threshold = zeros(1, 1);
NEAR_agc.slope = 0.4.*ones(1,1);
NEAR_agc.max_boost = 18.*ones(1,1);
NEAR_agc.max_spl = 120.*ones(1,1);
NEAR_agc.min_signal = 40;
NEAR_agc.ramp_tau = 0.1;
NEAR_agc.decimated_rate = NEAR_sample_rate_in_hertz/NEAR_decimation_factor;
NEAR_agc.noise_override_flag = 0;
NEAR_agc.noise_override_value = 0;
NEAR_agc.boost_override_flag = zeros(1,1);
NEAR_agc.boost_override_value = zeros(1,1);

% VNC
NEAR_vnc.frame_size = NEAR_frame_size/NEAR_decimation_factor;
NEAR_vnc.lowpass_frequency = 20;
NEAR_vnc.lpf_fs = NEAR_sample_rate_in_hertz/NEAR_decimation_factor;

% location delays
base_delay = 3;
eqdelays.driver    =    ceil((base_delay)*689.1/1000);
eqdelays.passenger =    ceil((base_delay)*689.1/1000);
eqdelays.dc  =          ceil((base_delay)*689.1/1000);
eqdelays.fl  =          ceil((base_delay)*689.1/1000);
eqdelays.fr  =          ceil((base_delay)*689.1/1000);
eqdelays.gl  =          ceil((base_delay)*689.1/1000);
eqdelays.gr  =          ceil((base_delay)*689.1/1000);
eqdelays.flw =          ceil((base_delay)*689.1/1000);
eqdelays.frw =          ceil((base_delay)*689.1/1000);

% Mix Gains
j=0;
% mix_base_FL  = single([20 15 10 5 0; 15 11.25 7.5 3.75 0; 10 7.5 5 2.5 0; 5 3.75 2.5 1.25 0; 0 0 0 0 0])+j;
mix.f1    = single([	0 0 1 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f2    = single([	1 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f3    = single([	0 0 0 0 1; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f4    = single([	0 1 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f5    = single([	0 0 0 1 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f6   = single([     0 0 0 0 0; 
                        0 0 0 0 0; 
                        1 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.f7   = single([     0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 1; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LFI0  = single([	1 1 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LFT0  = single([	1 0 0 0 0; 
                        1 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RFI0  = single([	0 0 0 1 1; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RFT0  = single([	0 0 0 0 1; 
                        0 0 0 0 1; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LSI0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        1 1 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LST0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        1 0 0 0 0; 
                        1 0 0 0 0; 
                        0 0 0 0 0]);

mix.RSI0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 1 1; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RST0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 1; 
                        0 0 0 0 1; 
                        0 0 0 0 0]);

mix.LCI0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 1 1 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LCT0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 1 0 0 0; 
                        0 1 0 0 0; 
                        0 0 0 0 0]);

mix.RCI0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 1 1 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RCT0  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 1 0; 
                        0 0 0 1 0; 
                        0 0 0 0 0]);

mix.LFI1  = single([	.5 .5 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LFT1  = single([	.5 0 0 0 0; 
                        .5 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RFI1  = single([	0 0 0 .5 .5; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RFT1  = single([	0 0 0 0 .5; 
                        0 0 0 0 .5; 
                        0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LSI1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        .5 .5 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LST1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        .5 0 0 0 0; 
                        .5 0 0 0 0; 
                        0 0 0 0 0]);

mix.RSI1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 .5 .5; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RST1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 .5; 
                        0 0 0 0 .5; 
                        0 0 0 0 0]);

mix.LCI1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 .5 .5 0 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.LCT1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 .5 0 0 0; 
                        0 .5 0 0 0; 
                        0 0 0 0 0]);

mix.RCI1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 .5 .5 0; 
                        0 0 0 0 0; 
                        0 0 0 0 0]);

mix.RCT1  = single([	0 0 0 0 0; 
                        0 0 0 0 0; 
                        0 0 0 .5 0; 
                        0 0 0 .5 0; 
                        0 0 0 0 0]);

loc_init = [0 0];   % Initial value of location RTC

channel_count = 2;  % stereo
coeffs = [2.*ones(1, channel_count); zeros(1024 , channel_count)];	% passthrough filter

nearwiggle                  = WiggleFilterClass();
nearwiggle.coeffs           = coeffs;
nearwiggle.channel_count	= channel_count;
nearwiggle.numCoeffs        = 1;%size(coeffs, 1);
nearwiggle.crossfader       = CrossfaderClass(NEAR_sample_rate_in_hertz/NEAR_decimation_factor);

% setup simulation RTC data
if ~exist('isTestRun', 'var')
    maxGain = 100;      % Maximum allowable value for gain
    sim_time = .5;
    
    vm                          = VmClass();
    vm.sampling_rate_in_hertz   = NEAR_sample_rate_in_hertz/NEAR_decimation_factor;
    vm.frame_size               = NEAR_frame_size/NEAR_decimation_factor;
    vm.agc                      = NEAR_agc;
    vm.vnc                      = NEAR_vnc;
    
    upmixer                                 = UpmixerClass();
    upmixer.ann_sysin_channel_count         = NEAR_ann_sysin_channel_count;
    upmixer.mix                             = mix;
    upmixer.loc_init                        = loc_init;
    upmixer.eqdelays                        = eqdelays;
    upmixer.front_peripheral_channel_count  = NEAR_front_peripheral_channel_count;
    upmixer.headrest_count                  = NEAR_headrest_count;
    upmixer.channels_per_headrest           = 12;
    upmixer.interp                          = 1;
    
	near = NEARClass( ...
                NEAR_sample_rate_in_hertz,...
                NEAR_frame_size,...
                NEAR_ann_sysin_channel_count,...
                NEAR_front_peripheral_channel_count,...
                NEAR_headrest_count,...
                NEAR_decimation_factor,...
                NEAR_rear_channel_count,...
                vm);
else
    upmixer                         = UpmixerClass();
    upmixer.ann_sysin_channel_count = NEAR_ann_sysin_channel_count;
    upmixer.mix                     = mix;
    upmixer.loc_init                = loc_init;
    upmixer.eqdelays                = eqdelays;
    
	near.sample_rate_in_hertz = NEAR_sample_rate_in_hertz;
	near.frame_size = NEAR_frame_size;
	near.ann_sysin_channel_count = NEAR_ann_sysin_channel_count;
	near.decimation_factor = NEAR_decimation_factor;
	near.rear_channel_count = NEAR_rear_channel_count;

	% Moved the following two lines up here because thay are needed for the channel EQs
	near.front_peripheral_channel_count = NEAR_front_peripheral_channel_count;
	near.headrest_count = NEAR_headrest_count;
end

% Bandsplitter initialization
% bandsplitter = BandsplitterClass(near.ann_sysin_channel_count,...
%     near.sample_rate_in_hertz, near.frame_size, near.decimation_factor);
%Instantiate Common Bandsplitter class
BandSplitterWideBand = 0;
bandsplitter = BandsplitterCommonClass(near.ann_sysin_channel_count,...
    near.sample_rate_in_hertz, near.frame_size, near.decimation_factor, BandSplitterWideBand);
% Set initial HPF to cutoff frequency of 90hz, filter order of 5
bandsplitter = bandsplitter.CalcHpfCoefficients(90, 5);

% Channel EQ initialization
hrEQ = HrEQClass(near.headrest_count, near.ann_sysin_channel_count,...
    near.frame_size/near.decimation_factor);
fsEQ = FsEQClass(near.front_peripheral_channel_count, near.frame_size/near.decimation_factor);

% Preamp initialization
preAmp = PreAmpClass(NEAR_sample_rate_in_hertz, NEAR_frame_size);
