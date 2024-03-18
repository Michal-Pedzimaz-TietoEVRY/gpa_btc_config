classdef MedusaDelayTuneConfig < TuneConfigClass
    % MedusaDelayTuneConfig Build-time configuration class for the default
    % values of delay tuneVars
    % Usage:
    %    aConfig = MedusaDelayTuneConfig
    %

    %   Copyright 2022 Bose Corporation

    properties(Description='TuneDefault',GetObservable,SetObservable)
        DeciRateWiggleDelay         int32   {mustBeNonnegative}   = 0
        DeciRateNearWiggleDelay     int32   {mustBeNonnegative}   = 0
        HoligramDelay               int32   {mustBeNonnegative}   = 0

        NumFullRateChannels                 {mustBePositive}      = 15
        NumNonHeadrestChannels              {mustBePositive}      = 15
        FullRateHoligramDelay       int32   {mustBeNonnegative}
        SpeakerDelay                int32   {mustBeNonnegative}
        DeciRateNonHeadrestDelay            {mustBeNonnegative}
        DriverHeadrestDelay                 {mustBeNonnegative}   = 0
        PaxHeadrestDelay                    {mustBeNonnegative}   = 0
    end
end

