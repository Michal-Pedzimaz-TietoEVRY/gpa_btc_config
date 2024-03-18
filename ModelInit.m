% Pull in build time configuration parameters
%clear;
sys_defs = auto_gen_sys_defs_gpa();


%% DSP target
%% Snapdragon supported targets are 'Generic', 'Hexagon', or 'ArmNeonV7V8'.
sys_defs.DspTarget = ModelSettings.DspTarget;


%% Disable/Enable CAE
sys_defs.include_compressed_audio_enhancement = 0;
sys_defs.include_CAE_support_in_medusa_premix = 0;


%% setup simulation RTC data
run([ModelRootName() 'SimEvents.m']);


%% Legacy Medusa non-BTC configuration
medusa5h1_init;
MedusaConfig.HoligramEQConfig.variantFIR = sys_defs.DspTarget;
MedusaConfig.HoligramEQConfig.variantIIR = sys_defs.DspTarget;
MedusaConfig.TailCompFirEvenSettings.Variant = sys_defs.DspTarget;
MedusaConfig.BandSplitConfig.ImageRejectionFilterSettings.Variant = sys_defs.DspTarget;
[b, a] = butter(2, 0.99);
sos = [b a];
sos = repmat(sos, 8, 1);
MedusaConfig.HoligramEQConfig.FRIIR.sos = sos;
MedusaConfig.HoligramEQConfig.FRIIR.numStages = ...
    size(sos, 1) * ones(1, MedusaConfig.HoligramEQConfig.numSpkrOutput); 
MedusaConfig.HoligramEQConfig.FRIIR.coeffs = ...
    repmat(sos, MedusaConfig.HoligramEQConfig.numSpkrOutput, 1);

ModelSettings.ModelPreAmp.MedusaConfig = MedusaConfig;

%% VLS
VLS_init;
VLSConfig.HeadrestCompEQConfig.variantFIR = sys_defs.DspTarget;
VLSConfig.HeadrestCompEQConfig.variantIIR = sys_defs.DspTarget;
VLSConfig.HeadrestCompEQConfig.DRIIR.alias = 'VlsHeadrestEq';
VLSConfig.HeadrestCompEQConfig.DRIIR.sos = sos;
VLSConfig.HeadrestCompEQConfig.DRIIR.numStages = ...
    size(sos, 1) * ones(1, VLSConfig.HeadrestCompEQConfig.numEQlink);
VLSConfig.HeadrestCompEQConfig.DRIIR.coeffs = ...
     repmat(sos, VLSConfig.HeadrestCompEQConfig.numEQlink, 1);

VLSConfig.XtalkCancellationConfig.IIR.variantSelect = sys_defs.DspTarget;
VLSConfig.XtalkCancellationConfig.IIR.alias = 'XtalkIIR';
VLSConfig.XtalkCancellationConfig.IIR.sos = sos;
VLSConfig.XtalkCancellationConfig.IIR.numStages = ...
    size(sos, 1) * ones(1, VLSConfig.XtalkCancellationConfig.numFilters);
VLSConfig.XtalkCancellationConfig.IIR.coeffs = ...
     repmat(sos, VLSConfig.XtalkCancellationConfig.numFilters, 1);

ModelSettings.ModelPreAmp.VLSConfig = VLSConfig;
