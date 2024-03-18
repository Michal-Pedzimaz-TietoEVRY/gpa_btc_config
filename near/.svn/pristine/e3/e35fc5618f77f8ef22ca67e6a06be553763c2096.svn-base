classdef AnnouncementLevelDetectorConfig < BtcBaseClass
    % AnnouncementLevelDetectorConfig Build-time configuration class for the AnnouncementLevelDetector block
    % Usage:
    %   aConfig = AnnouncementLevelDetectorConfig
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        % System Level Build-Time Parameters 
        FsFast = 44100
        FrameSize = 32
        FrameRate = 44100/32
        AnnChannelCount = 2

        ShelfNumStages
        ShelfSos

        annTrigThreshold = 0.5
        superFastDecaydBperSec = 30.0
        latencyMsec = 1.4966                                                % msec
        preemphasisWeight  = 4.0

        PreEmphasisShelfFilter PoolIirTunableConfig
    end

    properties(Description='TuneDefault',GetObservable,SetObservable)
        DefaultLevelDetectSysMaxDbspl single = 123                          % dBSPL

        DefaultAnn1LevelDetectFastDecayDbPers single = 5.0                  % dB/sec
        DefaultAnn1LevelDetectHoldMarginDb single = 6.0                     % dB
        DefaultAnn1LevelDetectHoldTimes single = 3.0                        % sec
        DefaultAnn1LevelDetectSlowDecayDbPers single =0.1                   % dB/sec
        DefaultAnn1LevelDetectMaxVolumeDb single = 0.0                      % dBSPL
        DefaultAnn1LevelDetectMinVolumeDb single = -80.0                    % dBSPL

        DefaultAnn2LevelDetectFastDecayDbPers single = 5.0
        DefaultAnn2LevelDetectHoldTimes single = 3.0
        DefaultAnn2LevelDetectSlowDecayDbPers single = 0.1
        DefaultAnn2LevelDetectMaxVolumeDb single = 0.0
        DefaultAnn2LevelDetectMinVolumeDb single = -80.0
        DefaultAnn2LevelDetectHoldMarginDb single = 6.0

        DefaultAnn3LevelDetectMaxVolumeDb single = 0.0
        DefaultAnn3LevelDetectMinVolumeDb single = -80.0
        DefaultAnn3LevelDetectSlowDecayDbPers single = 0.1
        DefaultAnn3LevelDetectFastDecayDbPers single = 5
        DefaultAnn3LevelDetectHoldTimes single = 3
        DefaultAnn3LevelDetectHoldMarginDb single = 6

        DefaultAnn4LevelDetectMaxVolumeDb single = 0.0
        DefaultAnn4LevelDetectMinVolumeDb single = -80.0
        DefaultAnn4LevelDetectHoldMarginDb single = 6
        DefaultAnn4LevelDetectSlowDecayDbPers single = 0.1
        DefaultAnn4LevelDetectFastDecayDbPers single = 5
        DefaultAnn4LevelDetectHoldTimes single = 3
    end
    methods
        %----------------------------------------------------------------------
        function this = AnnouncementLevelDetectorConfig()
            % AnnouncementLevelDetectorConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.PreEmphasisShelfFilter = PoolIirTunableConfig;
            this.PreEmphasisShelfFilter.Alias = 'NearPreEmphasisShelfFilter';

            Gain = 4;
            Slope = 1.0;
            wc = 100/(this.FsFast/2);
            [numShelf, denomShelf] = designShelvingEQ(Gain, Slope, wc, 'hi');
            this.ShelfSos = tf2sos(numShelf,[1;denomShelf]);
            this.ShelfNumStages = length(denomShelf)/2;

            this.Default(@this.FrameRate,@()this.FsFast/this.FrameSize);
            this.Default(@this.PreEmphasisShelfFilter.TuneDefaults.SosCoefficients,@()repmat(this.ShelfSos,this.AnnChannelCount,1));
            this.Default(@this.PreEmphasisShelfFilter.TuneDefaults.NumStages,@()repmat(this.ShelfNumStages,this.AnnChannelCount,1));
            this.Default(@this.PreEmphasisShelfFilter.MaxNumStages,@()this.AnnChannelCount*this.ShelfNumStages);
            this.Default(@this.PreEmphasisShelfFilter.NumChannels,@()this.AnnChannelCount);

        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
