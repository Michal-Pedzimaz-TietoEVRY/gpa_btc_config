classdef MedusaDrHoligramEqTuneConfig < TuneConfigClass
% MedusaDrHoligramEqTuneConfig Default TuneVar values for MedusaDrHoligramEq block

%   Copyright 2023 Bose Corporation
  properties (Description='TuneDefault',GetObservable,SetObservable)
    FirCoeffs
    FirLengths
    PaddedFirLengths
    InputMapping
    OutputMapping
  end

  methods
    function EasyConstructor(this)
        % Called from MedusaDrHoligramEqTuneConfig Constructor.
        this.Default(@this.FirCoeffs, @() this.GetDefaultFirCoeffs());
        this.Default(@this.FirLengths, @() this.GetDefaultFirLengths());
        this.Default(@this.PaddedFirLengths, @() this.GetDefaultFirLengths());
        this.Default(@this.InputMapping, @() this.GetDefaultInputMapping());
        this.Default(@this.OutputMapping, @() this.GetDefaultOutputMapping());
    end

    function coeffs = GetDefaultFirCoeffs(this)
        avgFirLength = this.Parent.AvgFirLength;
        numEqLinks = this.Parent.TotalNumEqLinks;
        numOutputs = this.Parent.NumOutputs;

        flippedPassThruCoeffs = repmat([zeros(avgFirLength-1,1); 1], numOutputs, 1);
        zeroCoeffs = repmat(zeros(avgFirLength,1), numEqLinks - numOutputs, 1);
        coeffs = vertcat(flippedPassThruCoeffs, zeroCoeffs);
    end

    function firLengths = GetDefaultFirLengths(this)
        firLengths = this.Parent.AvgFirLength * ones(this.Parent.TotalNumEqLinks, 1, 'uint32');
    end

    function inputMapping = GetDefaultInputMapping(this)
        numInputs = this.Parent.NumInputs;
        numEqLinks = this.Parent.TotalNumEqLinks;

        inputMapping = [(0:1:numInputs-1)'; zeros(numEqLinks-numInputs, 1)];
    end

    function outputMapping = GetDefaultOutputMapping(this)
        outputMapping = (0:1:this.Parent.NumOutputs-1)';
    end

  end
end
