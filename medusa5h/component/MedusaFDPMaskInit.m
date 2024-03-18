function MedusaFDPMaskInit(configStruct)
    % Set implementation type for RFFT/RIFFT
    useGenericCode = configStruct.useGenericCode;
    
    fftBlockPath = MaskUtil.SubBlockName(gcbh, 'DRFDP/Real STFFT/2-channel RFFT');
    fftBlockHandle = getSimulinkBlockHandle(fftBlockPath);
    if -1 ~= fftBlockHandle
        set_param(fftBlockHandle, 'variantSelect', useGenericCode);
    end

    fftWindowPath = MaskUtil.SubBlockName(gcbh, 'DRFDP/Real STFFT/Windowing1');
    fftWindowHandle = getSimulinkBlockHandle(fftWindowPath);
    if useGenericCode == 0
        if -1 ~= fftWindowHandle
            CscUtil.SetOutportCsc(fftWindowHandle, 1, 'Blocklib', 'FFTBuffer', 'MemorySection', 'FFTMemL1DmWordAlign256');
            CscUtil.SetOutportCsc(fftWindowHandle, 2, 'Blocklib', 'FFTBuffer', 'MemorySection', 'FFTMemL1DmWordAlign256');
        end
    end
    
    ifftBlockPath = MaskUtil.SubBlockName(gcbh, 'DRFDP/Real ISTFFT/RIFFT, Windowing and Overlap-Add');
    ifftBlockHandle = getSimulinkBlockHandle(ifftBlockPath);
    if -1 ~= ifftBlockHandle
        set_param(ifftBlockHandle, 'variantSelect', useGenericCode);
    end
end