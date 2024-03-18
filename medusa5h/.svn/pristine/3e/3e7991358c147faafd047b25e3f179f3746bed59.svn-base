function MedusaBandSplitConfig = MedusaBandSplitInit(MedusaParams)
% Init script for MedusaBandSplit block
%
% Input arguments: 
% Config struct with the following fields:
%   MedusaConfig.samppleRate: Sample rate (at full rate, in Hz)
%   MedusaConfig.decimation : Decimation factor
%   MedusaConfig.Fp         : Passband cutoff frequency
%
% Returns:
% Struct in base workspace that can be passed to Simulink block 
%   MedusaBandSplitConfig: config struct to interface with library block

    sampleRate = MedusaParams.sampleRate;
    decimationFactor = MedusaParams.decimation;
    variant = MedusaParams.variant;
    dspTarget = MedusaParams.DspTarget;

    %% Interpolated FIR Filter (IFIR)
    
    F = 44100;   % All cutoffs in Hz are carried over from 44.1k design
    Fs = (F/2) / decimationFactor; % stopband cutoff frequency
    Fp = 3000;   % passband cutoff frequency
                 % Fp = Fs * 0.54422 = 3000 for decimationFactor = 4, 
                 % which was the static constant at 44.1kHz
    ripple_dB = 100; % ripple for stop and pass band in dB
    ripple = 10^(-ripple_dB/20);

    [n,Wn,bta,filtype] = kaiserord([Fp Fs],  ... % band edge frequencies
                                   [1 0],    ... % amplitude in bands - LPF
                                   [ripple ripple], ...
                                   sampleRate); % sampling rate

    b = fir1(n,                 ... % filter order
             Wn,                ... % cut-off frequency
             filtype,           ... % filter type
             kaiser(n+1, bta),  ... % kaiser window with length (n+1) and
                                ... % shape parameter bta   
             'noscale');

    interp_order = n; % save to check for even/odd order 

    % create sparse coefficient set for filter containing (down-1) zeros 
    % between each point 
    down = decimationFactor/2;
    basemask = down*[1 zeros(1,(down-1))];
    mask = [];
    for i = 1:ceil(length(b)/down)
       mask = [mask basemask];
    end
    interpolated_filter_sparse = b .* mask(1:length(b));
    
    % the sparse filter is used to calculate delay only
    % downsample to save only the non-zero filter coefficients 
    interpolated_filter = downsample(interpolated_filter_sparse, decimationFactor/2);

    %% Image Rejection Filter (FIREven)

    % The image stopband frequency changes with sampling rate, so Fss is
    % calculated based on current sampleRate
    Fss = min(sampleRate/2 - 1, (sampleRate/down) - Fs); % stopband cutoff (relaxed)
    [n,Wn,bta,filtype] = kaiserord([Fp Fss], ...
                                   [1 0], ...
                                   [ripple ripple], ...
                                   sampleRate); 

    % force interp_imrej_filter to have even total length to avoid half 
    % sample delay for band_separation_delay                         
    n = n + mod(interp_order + n, 2);       
    image_rejection_filter = fir1(n, Wn, filtype, kaiser(n+1,bta), 'noscale');

    % force image rejection filter to have even length to take advantage of 
    % SIMD capabilities of the SHARC processor using FIREven
    % FIREven takes in flipped coeffs, so the zeros are appended in front
    LL = ceil(length(image_rejection_filter)/2) * 2; 
    image_rejection_filter_even_flipped = [zeros(1, LL - length(image_rejection_filter))...
                                           image_rejection_filter];

    %% Filter Alignment Delay

    % apply delay to make sure the signals going to subtract block are 
    % aligned at half the filter length
    interp_imrej_filter = conv(interpolated_filter_sparse, image_rejection_filter);
    reconstruction_filter = interp_imrej_filter;
    cascaded_bspath_filter = conv(interp_imrej_filter, reconstruction_filter);
    band_separation_delay =  floor(length(cascaded_bspath_filter)/2);

    %% Upsample and FIR Filter (UpFIR)
    
    % Simulink FIR Interpolated block automatically scales filter coefficients 
    % by gain = decimationFactor and implements polyphase structure
    reconstruction_filter = decimationFactor * reconstruction_filter;

    % force reconstruction filter length to be multiple of decimationFactor
    % Simulink upfir implementation takes in unflipped coeffs, so the zeros 
    % are appended at the end.
    LL = ceil(length(reconstruction_filter)/decimationFactor) * decimationFactor;
    reconstruction_filter = [reconstruction_filter ...
                             zeros(1, LL - length(reconstruction_filter))];
    
    %% TODO: This is a shim for backward compatability since MedsuaBandSplit is
    %% not BTC compliant yet, but the FIR even block was upgraded and we need to maingain
    ImageRejectionFilterSettings = FirEvenConfig();
    %if(startsWith(variant, {'SharcPlusCore', 'SharcPlusAccelGul'}))
    %    variant = 'SharcPlus';
    %end

    %@SSC-TODO
    ImageRejectionFilterSettings.SelectVariant(dspTarget);
    ImageRejectionFilterSettings.Alias = 'MedusaBandSplitImgRej';
    ImageRejectionFilterSettings.MaxAvgCoeffLength = length(reconstruction_filter(:)); 
    ImageRejectionFilterSettings.NumChannels = MedusaParams.numSystemOut;
    ImageRejectionFilterSettings.FrameSize = MedusaParams.frameSize / MedusaParams.decimation;

    FirUpVariant = FirUpBtcConfig;
    FirUpVariant.CoeffsRaw = reconstruction_filter(:);
    FirUpVariant.UpFactor = decimationFactor;
    FirUpVariant.Alias = 'MedusaBandsplitFirUp';
    FirUpVariant.SelectVariant(dspTarget);
    FirUpVariant.SelectVariant("WithFir");
    FirUpVariant.VariantObj.Fir.SelectVariant(dspTarget);
    FirUpVariant.VariantObj.NumChannels = MedusaParams.numSystemOut;
    FirUpVariant.VariantObj.FrameSizeIn = MedusaParams.frameSize / MedusaParams.decimation;


    PostHoligramFirUp = FirUpBtcConfig(reconstruction_filter);
    PostHoligramFirUp.UpFactor = decimationFactor;
    PostHoligramFirUp.Alias = 'MedusaPostHoligramFirUp';
    PostHoligramFirUp.SelectVariant("WithFir");
    PostHoligramFirUp.VariantObj.Fir.SelectVariant(dspTarget);


    PostHoligramFirUp.VariantObj.NumChannels = MedusaParams.numSystemOut;
    PostHoligramFirUp.VariantObj.FrameSizeIn = MedusaParams.frameSize / MedusaParams.decimation;
    MedusaBandSplitIfirConfig = IfirConfig;
    ifirCoeffs = single(interpolated_filter(:));
    MedusaBandSplitIfirConfig.Coefficients = repmat(ifirCoeffs, 1, MedusaParams.numInputChannels);
    MedusaBandSplitIfirConfig.InterpolationFactor = decimationFactor/2;
    MedusaBandSplitIfirConfig.NumChannels = MedusaParams.numInputChannels;
    MedusaFirUp = FirUpBtcConfig();
    MedusaFirUp.Alias = "MedusaFirUp";
    MedusaFirUp.SelectVariant("WithFir");
    MedusaFirUp.UpFactor = decimationFactor;
    MedusaFirUp.CoeffsRaw = single(reconstruction_filter(:));
    MedusaBandSplitConfig = struct('D', decimationFactor, ...
                                   'Ifir', MedusaBandSplitIfirConfig, ...
                                   'fireven', single(image_rejection_filter_even_flipped(:)), ...
                                   'upfir', single(reconstruction_filter(:)), ...
                                   'upfirBTC', MedusaFirUp, ...
                                   'band_separation_delay', single(band_separation_delay), ...
                                   'ImageRejectionFilterSettings', ImageRejectionFilterSettings, ...
                                   'FirUpVariant',FirUpVariant, ...
                                   'PostHoligramFirUp',PostHoligramFirUp);
                               
    %% UNCOMMENT TO GRAPH
%     fvtool(image_rejection_filter,1,interpolated_filter_sparse,1,'Fs',sampleRate);
%     legend('Image rejection filter', 'Interpolated filter');
%     
%     reconstruction_filter = interp_imrej_filter;
%     band_separation_delay = floor(length(reconstruction_filter)/2);
%     
%     f = reconstruction_filter;
%     f = [f zeros(1,4096-length(f))];
%     fg_order = 1; % set 1 to look before decimation, set to 2 to look after reconstruction
%     g = zeros(1,length(f));    
%     g(band_separation_delay*fg_order + 1) = 1;
%     lp = fft(f).^fg_order;
%     hp = fft(g)-fft(f).^fg_order;
%     figure(1);
%     l =[0:(length(f)-1)]*sampleRate/length(f); 
%     plot(l,db20(lp),l,db20(hp));
%     grid;
%     plot(l,unwrap(angle(lp));
end