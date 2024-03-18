function UpdateMedusaFromSysDefs(MedusaConfig, SysDefs)
%UPDATEMEDUSAFROMSYSDEFS Update Medusa BTC configs from sysdefs
%   This helper function acts as a glue layer between the sysdefs
%   and the BTC patter for configuring Medusa. This function should
%   be called during a model initialization in order to 
    MedusaConfig.Variant = SysDefs.DspTarget;
    
    MedusaConfig.SampleRate = SysDefs.medusa_sample_rate;
    MedusaConfig.FullRateFrameSize = SysDefs.frame_size_in_samples;
    MedusaConfig.BassManager.XofOrder = SysDefs.bass_manager_cross_over_filter_order;
    MedusaConfig.BassManager.LpfFc = SysDefs.medusa_bass_cutoff_frequency_in_hz;
    
    MedusaConfig.NumCenterChannels = SysDefs.medusa_number_of_center_channels;
    MedusaConfig.NumSurroundChannels = SysDefs.medusa_number_of_surround_channels;
    MedusaConfig.NumLeftRightSpeakerPairs = SysDefs.medusa_number_of_left_right_pairs;
    MedusaConfig.NumOverheadSpeakerPairs = SysDefs.number_of_overhead_speaker_pairs;
    MedusaConfig.NumVlsHeadrestSpeakerPairs = SysDefs.number_of_headrests_with_virtual_loudspeaker;   
    
    MedusaConfig.AvgPeripheralFirLength = SysDefs.maximum_average_holigram_fir_length;
    MedusaConfig.MaxPeripheralFirLength = SysDefs.maximum_holigram_fir_length;
    MedusaConfig.MaxPeripheralNumStages = SysDefs.maximum_decimated_rate_holigram_eq_stages;
    MedusaConfig.AvgOverheadFirLength = SysDefs.maximum_average_overhead_holigram_fir_length;
    MedusaConfig.MaxOverheadFirLength = SysDefs.maximum_overhead_holigram_fir_length;
    MedusaConfig.MaxOverheadNumStages = SysDefs.maximum_decimated_rate_overhead_holigram_eq_stages;

    %MedusaConfig.DeciRateFdp.Rfft.SelectVariant(SysDefs.DspTarget);
    %MedusaConfig.DeciRateFdp.Rifft.SelectVariant(SysDefs.DspTarget);
    %MedusaConfig.FullRateFdp.Rfft.SelectVariant(SysDefs.DspTarget);
    %MedusaConfig.FullRateFdp.Rifft.SelectVariant(SysDefs.DspTarget);
	
	%@SSC-TODO
    MedusaConfig.DeciRateFdp.Rfft.SelectVariant(SysDefs.DspTarget);
    MedusaConfig.DeciRateFdp.Rifft.SelectVariant(SysDefs.DspTarget);
    MedusaConfig.FullRateFdp.Rfft.SelectVariant(SysDefs.DspTarget);
    MedusaConfig.FullRateFdp.Rifft.SelectVariant(SysDefs.DspTarget);
    MedusaConfig.PeripheralHoligramEq.HoligramEq.Iir.SelectVariant(SysDefs.DspTarget);
    MedusaConfig.OverheadHoligramEq.HoligramEq.Iir.SelectVariant(SysDefs.DspTarget);
end
