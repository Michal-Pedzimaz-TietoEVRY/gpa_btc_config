classdef FirHexagonVariantConfig < BtcVariant
% FirHexagonVariantConfig Build-time configuration class for the FirHexagon variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation

  properties
    % PropertyName size class {validation functions} = DefaultValue

  end
  properties (Dependent, SetAccess = private)
    CodeWorkMemorySize
    StateBufferSize
  end
  methods
    %----------------------------------------------------------------------
    function this = FirHexagonVariantConfig(constructingParentObj)
        this@BtcVariant(constructingParentObj);
    end
    %----------------------------------------------------------------------
    function VariantValidate(this)
        % VariantValidate validates cross-property interactions. Our parent
        % object calls us during block mask initialization.
        if mod(this.Parent.MaxAvgCoeffLength, 4) ~= 0
            error("Property [MaxAvgCoeffLength] of Fir block is not a multiple of 4. Hexagon " + ...
                "variant requires that the number of taps is a multiple of 4. Generated C code will not be correct.");
        end

        VariantValidate@BtcVariant(this);
    end
    %----------------------------------------------------------------------
    function VariantDoMaskInit(this,blockHandle)
        % VariantDoMaskInit performs automation of code generation settings
        % and other canvas interactions for a variant subsystem. Our parent
        % object calls us during block mask initialization.
        this.ConfigureDataStoreMemory("StateBuffer", blockHandle);
        this.ConfigureDataStoreMemory("CodeWorkMemory", blockHandle);

        % Coefficients needs to be aligned by 8 bytes
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'CoeffsTarget'], blockHandle, "SignalBreak/SignalBreak/SignalBreakFcn");

        % Be friendly about the CRL this variant expects
        this.EnsureCodeReplacementLibrary(blockHandle,'Hexagon');

        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, DataStoreMemoryName, blkh)
        % Get DSM block Path
        theDsm = ['Fir/TargetSpecific/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        DSMBlockHandle = getSimulinkBlockHandle(DSMBlockPath);
        Identifier = [char(this.Parent.Alias) char(num2str(randi([0 2^16]))) char(DataStoreMemoryName)];

        FullHeaderFilename = ...
               [getfullname(bdroot(DSMBlockHandle)) '_FirGenericStorage.h'];
        FullDefinitionFilename = ...
               [getfullname(bdroot(DSMBlockHandle)) '_FirGenericStorage.c'];
        % Configure DSM Storage Class
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'FirGenericStorage', ...
                                'MemorySection','AttributeAligned8',...
                                'HeaderFile', FullHeaderFilename, ...
                                'DefinitionFile', FullDefinitionFilename, ...
                                'Identifier', Identifier);
    end
    %----------------------------------------------------------------------
    function ConfigureSignalObject(this, DsmIdentifier, blockHandle, InportName)
        InputBlock = MaskUtil.SubBlockName(blockHandle, ...
            ['Fir/TargetSpecific/' char(InportName)]);
        CscUtil.SetOutportCsc(InputBlock, 1,'Blocklib','FirGenericStorage', ...
            'MemorySection', 'AttributeAligned8',...
            'Identifier', DsmIdentifier);
    end   
    %----------------------------------------------------------------------
    function val = get.CodeWorkMemorySize(this)
        val = 156 + (24 + this.Parent.NumInputs*8 + this.Parent.NumOutputs*(80 + 4*this.Parent.FrameSize));
        val = val / 4;
    end
    %----------------------------------------------------------------------
    function val = get.StateBufferSize(this)
        % qhdsp_fir_af_bose.S
        %val = (this.Parent.MaxAvgCoeffLength + this.Parent.FrameSize - 1)*this.Parent.NumOutputs;
        
        % flt_bkfir.S
        val = (this.Parent.MaxAvgCoeffLength + 2*(this.Parent.FrameSize) - 1)*this.Parent.NumOutputs;
    end
    %----------------------------------------------------------------------
  end
end
