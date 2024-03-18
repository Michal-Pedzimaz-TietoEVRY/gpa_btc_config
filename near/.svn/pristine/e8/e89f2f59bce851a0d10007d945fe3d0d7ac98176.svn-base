classdef Near1p1Config < BtcBaseClass
    % Near1p1Config Build-time configuration class for the Near1p1 block
    % Usage:
    %   aConfig = Near1p1Config
    %   Copyright 2023 Bose Corporation

    properties (GetObservable,SetObservable)
        % Child Blocks
        VolumeMute VolumeMuteConfig
        NearBandSplit NearBandSplitConfig

        HrEqDr HrEqConfig
        Upmixer1p1Dr Upmixer1p1Config
        FsEqDr FsEqConfig

        HrEqFr HrEqConfig
        Upmixer1p1Fr Upmixer1p1Config
        FsEqFr FsEqConfig

        % System Level Build Time Parameters
        FsFast = 44100
        FrameSize = 32
        AnnChannelCount = 2
        DecimationFactor = 4
        FrontPeripheralChannelCount = 7
        FullRateFrontPeripheralChannelCount = 5
        RearChannelCount = 3
        NumHeadrestSpeakers = 2
        DecimatedRateNumChannelsPerHeadrest = 14
        FullRateNumChannelsPerHeadrest = 2
        NearRouterNumIn = 10
        NearRouterNumOut = 10
        NearRouterMap = [1 0 2 3 4 5 0 0 0 0]
        NearWbAnnCount = 2

        % For unit tests
        SimulationTime = 0.5
    end

    properties(Description='TuneDefault',GetObservable,SetObservable)
        DefaultRampDbPerSample single = 0.005
    end

    methods
        %----------------------------------------------------------------------
        function this = Near1p1Config()
            % Near1p1Config constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.NearBandSplit =  NearBandSplitConfig;
            this.VolumeMute =  VolumeMuteConfig;

            this.HrEqDr =  HrEqConfig;
            this.HrEqDr.PoolIirTunable.Alias = 'NearHrEqDr';
            this.Upmixer1p1Dr =  Upmixer1p1Config;
            this.FsEqDr =  FsEqConfig;
            this.FsEqDr.Pooliir.Alias = 'NearFsDrEq'; 

            this.HrEqFr =  HrEqConfig;
            this.HrEqFr.PoolIirTunable.Alias = 'NearHrEqFr';
            this.Upmixer1p1Fr =  Upmixer1p1Config;
            this.FsEqFr =  FsEqConfig;
            this.FsEqFr.Pooliir.Alias = 'NearFsFrEq';

            this.Lock(@this.VolumeMute.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.NearBandSplit.BandSplit.BandSeparationDelay, 134);
            this.Lock(@this.NearBandSplit.BandSplit.ChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.NearBandSplit.BandSplit.Ifir.NumChannels,@()this.AnnChannelCount);
            this.Lock(@this.NearBandSplit.BandSplit.DecimationFactor,@()this.DecimationFactor);
            this.Lock(@this.NearBandSplit.BandSplit.Fireven,@()single([9.0252879e-06; 9.9146440e-05; -0.00052027265; -0.0021148610; 0.0023620191; 0.013877182; ...
                -0.00056554726; -0.052063070; -0.032084890; 0.16727670; 0.40372831; 0.40372831; 0.16727670; -0.032084890; -0.052063070; ...
                -0.00056554726; 0.013877182; 0.0023620191; -0.0021148610; -0.00052027265; 9.9146440e-05; 9.0252879e-06]));

            this.Lock(@this.NearBandSplit.BandSplit.Upfir,@()single([3.9655296e-11; 4.3562950e-10; -1.7636439e-09; -3.5542724e-09; -1.9200209e-08; -5.5579715e-08; ...
                1.0163962e-07; 4.2868666e-07; 7.1500480e-08; -1.0608002e-06; -3.5625646e-07; 6.5076006e-06; 2.1119291e-05; 3.7168553e-05; 3.9754799e-05; ...
                1.0538689e-05; -6.0066533e-05; -0.00015809962; -0.00023940312; -0.00023757125; -9.3477989e-05; 0.00020302607; 0.00057874434; 0.00087135594; ...
                0.00087635382; 0.00043770295; -0.00044340754; -0.0015339423; -0.0023896485; -0.0024877929; -0.0014609396; 0.00065943110; 0.0033073917; ...
                0.0054520010; 0.0059284554; 0.0039348640; -0.00047062020; -0.0061134384; -0.010894873; -0.012446880; -0.0091233402; -0.00093652558; ...
                0.0099832257; 0.019722581; 0.023822369; 0.019036539; 0.0050471229; -0.014656489; -0.033315908; -0.042898614; -0.037168030; -0.014654498; ...
                0.019578908; 0.054428212; 0.075802810; 0.071449369; 0.036289688; -0.023954865; -0.092145287; -0.14319539; -0.15078504; -0.095686398; ...
                0.026989911; 0.20410860; 0.40592465; 0.59264249; 0.72441155; 0.77192181; 0.72441149; 0.59264243; 0.40592492; 0.20410794; 0.026990881; ...
                -0.095687360; -0.15078461; -0.14319471; -0.092147559; -0.023950856; 0.036284208; 0.071455665; 0.075796627; 0.054433323; 0.019575622; ...
                -0.014653376; -0.037167136; -0.042900946; -0.033312973; -0.014659168; 0.0050488929; 0.019035980; 0.023821801; 0.019723887; 0.0099817170; ...
                -0.00093531597; -0.0091239316; -0.012446977; -0.010894246; -0.0061142943; -0.00046985509; 0.0039344234; 0.0059284871; 0.0054523121; 0.0033069055; ...
                0.00065989624; -0.0014612317; -0.0024877386; -0.0023894934; -0.0015342118; -0.00044313862; 0.00043752641; 0.00087639701; 0.00087143219; ...
                0.00057860138; 0.00020317119; -9.3574308e-05; -0.00023754571; -0.00023936637; -0.00015817495; -5.9992508e-05; 1.0522114e-05; 3.9766950e-05; ...
                3.7066169e-05; 2.1025204e-05; 6.9254365e-06; 3.2268397e-07; -7.4500218e-07; -1.5920190e-07; 1.9297192e-07; 1.7773219e-07; 1.7613976e-08; ...
                -4.5693007e-08; -1.2481501e-08; 2.5174247e-09; 2.2916084e-10; 0; 0]));

            this.Lock(@this.NearBandSplit.BandSplit.Ifir.Coefficients,@()repmat(single([1.0984496e-06; 1.4468500e-05; 1.4731277e-05; -5.3124266e-05; -0.00012556746; 1.8102817e-05; 0.00037151042; ...
                0.00035888629; -0.00048836780; -0.0012789407; -0.00026399034; 0.0022501568; 0.0026355444; -0.0016092581; -0.0060987310; -0.0027998667; ...
                0.0076197083; 0.011337880; -0.0021819617; -0.019842874; -0.013975122; 0.018839113; 0.038708355; 0.0043155528; -0.060726766; -0.065949984; ...
                0.055051170; 0.25189969; 0.38002419; 0.33385125; 0.15209547; -0.021290686; -0.076956734; -0.029181754; 0.028877255; 0.033811774; 0.00072287256; ...
                -0.021110561; -0.012274204; 0.0065684719; 0.011359042; 0.0021691499; -0.0057304748; -0.0043679443; 0.0010061830; 0.0029785694; 0.00097741606; ...
                -0.0010642207; -0.0010073376; 2.4669320e-05; 0.00045928860; 0.00019256775; -9.2535389e-05; -0.00010124280; -9.7402290e-06; 2.0185738e-05; 6.3477432e-06]),1,this.AnnChannelCount));

            this.Lock(@this.FsEqFr.FrontPeripheralChannelCount,@()this.FullRateFrontPeripheralChannelCount);
            this.Lock(@this.FsEqFr.sosCoefficients, @()repmat([1 0 0 1 0 0], 10*this.FullRateFrontPeripheralChannelCount, 1));
            this.Lock(@this.FsEqFr.numStagesPerChannel,@()[repmat(10, 1, this.FullRateFrontPeripheralChannelCount)]);

            this.Lock(@this.Upmixer1p1Fr.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.Upmixer1p1Fr.FrontPeripheralChannelCount,@()this.FullRateFrontPeripheralChannelCount);
            this.Lock(@this.Upmixer1p1Fr.HeadrestCount,@()this.NumHeadrestSpeakers);
            this.Lock(@this.Upmixer1p1Fr.ChannelsPerHeadrest,@()this.FullRateNumChannelsPerHeadrest);

            this.Lock(@this.HrEqFr.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.HrEqFr.FrameSize,@()this.FrameSize);
            this.Lock(@this.HrEqFr.NumHeadrestSpeakers,@()this.NumHeadrestSpeakers);
            this.Lock(@this.HrEqFr.sosCoefficients,@()[repmat([1 0 0 1 0 0], 10*this.AnnChannelCount, 1); repmat([1 0 0 1 0 0], 10*this.AnnChannelCount, 1)]);
            this.Lock(@this.HrEqFr.numStagesPerChannel,@()[repmat(10, 1, this.AnnChannelCount), repmat(10, 1, this.AnnChannelCount)]);

            this.Lock(@this.Upmixer1p1Dr.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.Upmixer1p1Dr.FrontPeripheralChannelCount,@()this.FrontPeripheralChannelCount);
            this.Lock(@this.Upmixer1p1Dr.HeadrestCount,@()this.NumHeadrestSpeakers);
            this.Lock(@this.Upmixer1p1Dr.ChannelsPerHeadrest,@()this.DecimatedRateNumChannelsPerHeadrest);

            this.Lock(@this.FsEqDr.FrameSize,@()this.FrameSize/this.DecimationFactor);
            this.Lock(@this.FsEqDr.FrontPeripheralChannelCount,@()this.FrontPeripheralChannelCount);
            this.Lock(@this.FsEqDr.sosCoefficients,@()repmat([1 0 0 1 0 0], 10*this.FrontPeripheralChannelCount, 1));
            this.Lock(@this.FsEqDr.numStagesPerChannel,@()[repmat(10, 1, this.FrontPeripheralChannelCount)]);

            this.Lock(@this.HrEqDr.FrameSize,@()this.FrameSize/this.DecimationFactor);
            this.Lock(@this.HrEqDr.AnnChannelCount,@()this.AnnChannelCount);
            this.Lock(@this.HrEqDr.NumHeadrestSpeakers,@()this.NumHeadrestSpeakers);
            this.Lock(@this.HrEqDr.sosCoefficients,@()[repmat([1 0 0 1 0 0], 10*this.AnnChannelCount, 1); repmat([1 0 0 1 0 0], 10*this.AnnChannelCount, 1)]);
            this.Lock(@this.HrEqDr.numStagesPerChannel,@()[repmat(10, 1, this.AnnChannelCount), repmat(10, 1, this.AnnChannelCount)]);
        end
        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok
            Validate@BtcBaseClass(this);
        end
    end
end
