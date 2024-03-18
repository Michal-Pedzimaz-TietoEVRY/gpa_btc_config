classdef FirEvenHexagonVariantConfig < BtcVariant
% FirEvenHexagonVariantConfig Build-time configuration class for the FirEvenHexagon variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties
    % PropertyName size class {validation functions} = DefaultValue
    Alias = "Default"
    MaxNumOfThreads 
    StateBufferSize
  end
  methods
    %----------------------------------------------------------------------
    function this = FirEvenHexagonVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
        this.MaxNumOfThreads=constructingParentObj.MaxNumOfThreads;
    end
    %----------------------------------------------------------------------
    function VariantValidate(this)
        % VariantValidate validates cross-property interactions. Our parent
        % object calls us during block mask initialization.
        VariantValidate@BtcVariant(this);
    end
    %----------------------------------------------------------------------
    function VariantDoMaskInit(this,blockHandle)
        % VariantDoMaskInit performs automation of code generation settings
        % and other canvas interactions for a variant subsystem. Our parent
        % object calls us during block mask initialization.
        this.ConfigureDataStoreMemory("CodeWorkMemory", blockHandle);
        this.ConfigureDataStoreMemory("States", blockHandle);
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'FirEvenCoeffs'], blockHandle,'SignalBreak');
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'FirEvenInput'], blockHandle,'AudioIn');


        % Be friendly about the CRL this variant expects
        containingModel = getfullname(bdroot(blockHandle));
        selectedCRL = get_param(containingModel,'CodeReplacementLibrary');
        expectedCRL = 'Qualcomm Hexagon DSP code replacement library';
        if (false == contains(selectedCRL, expectedCRL))
            warning('Expected CRL [%s], but instead found [%s]', ...
                expectedCRL,selectedCRL);
        end
        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, DataStoreMemoryName, blkh)
        % Get DSM block Path
        theDsm = ['FirEven/' char(this.Parent.Variant) '/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        Identifier = [char(this.Parent.Alias) char(num2str(randi([0 2^16]))) char(DataStoreMemoryName)];

        % Configure DSM Storage Class
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'FirStorage',...
                                'MemorySection', 'AttributeAligned8',...
                                'Identifier', Identifier);

    end
    %----------------------------------------------------------------------
    function ConfigureSignalObject(this, Identifier, blockHandle, PortName)
        InputBlock = MaskUtil.SubBlockName(blockHandle, ...
            ['FirEven/Hexagon/' PortName]);
        CscUtil.SetOutportCsc(InputBlock, 1,'Blocklib','FirGenericStorage',...
            'MemorySection', 'AttributeAligned8',...
            'Identifier', Identifier);
    end  
    %----------------------------------------------------------------------
    function val = get.StateBufferSize(this)
        % qhdsp_fir_af_bose.S
        %val = (this.Parent.MaxAvgCoeffLength + this.Parent.FrameSize - 1)*this.Parent.NumOutputs;
        
        % flt_bkfir.S
        val = (this.Parent.MaxAvgCoeffLength + this.Parent.FrameSize*2 + 2) * this.Parent.NumChannels * 2;
    end
  end
end
