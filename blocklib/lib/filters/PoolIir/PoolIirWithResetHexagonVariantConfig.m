classdef PoolIirWithResetHexagonVariantConfig < BtcVariant
% PoolIirWithResetHexagonVariantConfig Build-time configuration class for the PooliirHexagon variant
% Usage:
%    <automatically allocated by setting the "Variant" property of the
%    containing object derived from BtcBaseClassWithVariants
%

%   Copyright 2023 Bose Corporation
  properties(GetObservable, SetObservable, SetAccess = private)
      PostOverlayRequired     = 1
  end
  properties(GetObservable, SetObservable)
      DsmStatesInitVal  (:,1)
      MaxNumOfThreads = 0;
  end
  methods
    %----------------------------------------------------------------------
    function this = PoolIirWithResetHexagonVariantConfig(parentObj)
        this@BtcVariant(parentObj);
        this.Lock(@this.DsmStatesInitVal, ...
            @() zeros(2 * parentObj.MaxNumStages*parentObj.NumChannels + 16 + 3 * this.MaxNumOfThreads + this.MaxNumOfThreads * 7 + 1, 1));
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

        % Be friendly about the CRL this variant expects
        %this.EnsureCodeReplacementLibrary(blockHandle,'Hexagon');
        
        this.ConfigureDataStoreMemory('states', blockHandle);
        
        % Input needs to be aligned by 8 bytes
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'PoolIirAudioIn'], blockHandle, "AudioIn");
        % Output needs to be aligned by 8 bytes
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'PoolIirAudioOut'], blockHandle, "PoolIirProcess");
        % Coeffs need to be aligned by 8 bytes
        this.ConfigureSignalObject([char(this.Parent.Alias) char(num2str(randi([0 2^16]))) 'PoolIirCoeffs'], blockHandle, "SignalBreak/SignalBreak/SignalBreakFcn");

        VariantDoMaskInit@BtcVariant(this,blockHandle);
    end
    %----------------------------------------------------------------------
    function ConfigureDataStoreMemory(this, DataStoreMemoryName, blkh)
        % Get DSM block Path
        theDsm = ['PoolIir/TargetSpecific/' char(DataStoreMemoryName)];
        DSMBlockPath = MaskUtil.SubBlockName(blkh,theDsm);
        Identifier = [char(this.Parent.Alias) char(num2str(randi([0 2^16]))) char(DataStoreMemoryName)];

        % Configure DSM Storage Class
        CscUtil.SetDatastoreCsc(DSMBlockPath, 'Blocklib', 'PooliirAccelStorage', ...
                                'MemorySection','AttributeAligned8',...
                                'Identifier', Identifier);
    end
    %----------------------------------------------------------------------
    function ConfigureSignalObject(this, DsmIdentifier, blockHandle, InportName)
        InputBlock = MaskUtil.SubBlockName(blockHandle, ...
            ['PoolIir/TargetSpecific' InportName]);
        CscUtil.SetOutportCsc(InputBlock, 1,'Blocklib','PooliirAccelStorage', ...
            'MemorySection', 'AttributeAligned8',...
            'Identifier', DsmIdentifier);
    end 
    %----------------------------------------------------------------------
  end
end
