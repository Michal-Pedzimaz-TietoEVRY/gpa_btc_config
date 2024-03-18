classdef MedusaTunableDelayConfig < MedusaDelayConfig
    % MedusaTunableDelayConfig Build-time configuration class for the MedusaTunableDelay block
    % Usage:
    %    aConfig = MedusaTunableDelayConfig
    %

    %   Copyright 2022 Bose Corporation

    properties (GetObservable,SetObservable)
        % Parameters for different delay instances. These parameters would later
        % be used to compute the size of delay buffer for different instances.
        FrameSize                                                           % Frame size of incoming audio for specified delay
        MaxDelay                        int32                               % Upper bound for delay value
        NumChannels                                                         % Num of channels to be processed by specified delay
    end

    properties (SetAccess = private)
        % Initial Value for Alignment Delay Buffer
        % (determines the size of delay buffer)
        DelayBufferInitValue            single

        % Header file name and delay buffer alias
        DelayHeaderFileName                         = 'MedusaDelays'
        BufferAlias

        % Store object meta-data for error checks and debugging
        myCaller
    end

    methods
        %----------------------------------------------------------------------
        function this = MedusaTunableDelayConfig(varargin)
            % MedusaTuneDelayConfig constructor: assign component property objects
            % and adjust component property defaults and/or lock values
            this.myCaller = MaskUtil.NotThisFileCallerInfo(mfilename);

            if(nargin > 0)
                this.ConfigureDelay(varargin{:});
            end
        end

        function ConfigureDelay(this, InstancePurpose, FrameSize, NumChannels, MaxDelay)
            % The function accepts multiple input arguments. The object is
            % the first input argument. Instance Purpose should be the
            % second input argument to the function call. This argument
            % should specify the purpose/personality of the delay object.
            % Based on the arg value, frame size, number of channels and
            % max permissible delay value will be computed. The data type of
            % this arg should be char array. The user can choose one of the
            % preexisting delay personalities to be initiated. In this case,
            % no additional arguments are required. The value of'Instance
            % Purpose' is enough. Alternatively, the user can also define a
            % new delay behavior by passing the value 'Custom'. In case the
            % arg value is 'Custom', additional arguments are required.

            if(~strcmp(InstancePurpose, 'Custom') && nargin>2)
                fprintf(['Medusa Tunable Delay - Instance Purpose is not specified as ''Custom''. ' ...
                    'Ignoring additional argument(s) - FrameSize/NumChannels/MaxDelay.\n']);
            end

            switch(InstancePurpose)
                case 'FullRateHoligramDelay'
                    this.Lock(@this.FrameSize,  @()this.FullRateFrameSize);
                    this.Lock(@this.NumChannels,@()this.NumFullRateChannels);
                    this.Lock(@this.MaxDelay,   @()this.MaxFullRateHoligramDelay);

                case 'SpeakerDelay'
                    this.Lock(@this.FrameSize,  @()this.FullRateFrameSize);
                    this.Lock(@this.NumChannels,@()this.NumFullRateChannels);
                    this.Lock(@this.MaxDelay,   @()this.MaxSpeakerDelay);

                case 'DeciRateSpeakerDelay'
                    this.Lock(@this.FrameSize,  @()this.DeciRateFrameSize);
                    this.Lock(@this.NumChannels,@()this.NumDeciRateChannels);
                    this.Lock(@this.MaxDelay,   @()this.MaxFullRateSpeakerDelay/this.DecimationFactor);

                case 'FullRateSpeakerDelay'
                    this.Lock(@this.FrameSize,  @()this.FullRateFrameSize);
                    this.Lock(@this.NumChannels,@()this.NumFullRateChannels);
                    this.Lock(@this.MaxDelay,   @()this.MaxFullRateSpeakerDelay + this.MaxFullRateHoligramDelay);

                case 'Custom'
                    this.Lock(@this.FrameSize,  @()FrameSize);
                    this.Lock(@this.NumChannels,@()NumChannels);
                    this.Lock(@this.MaxDelay,   @()MaxDelay);

                otherwise
                    error(['Invalid value for argument Instance Purpose while instantiating ''MedusaTuneDelayConfig'' class.' ...
                        ' Please choose one from the this list: FullRateHoligramDelay, SpeakerDelay, DeciRateSpeakerDelay, FullRateSpeakerDelay, Custom.']);
            end

            this.BufferAlias = InstancePurpose;
        end

        %----------------------------------------------------------------------
        function Validate(this)
            % Validate called from mask initialization to check settings ok

            % Check whether 'MaxDelay', 'FrameSize' and 'NumChannels' have
            % been computed before calculating initial value of 'DelayBuffer'
            if(isempty(this.MaxDelay) || isempty(this.FrameSize) || isempty(this.NumChannels))
                % This error only shows up during Update Diagram.
                error(['Invalid value for parameters ''MaxDelay'', ''FrameSize'', ''NumChannels'' within MedusaAlignmentDelay.' ...
                    'Please supply the ''Instance Purpose'' to object constructor at %s to initialize these values.'], this.myCaller);
            end

            % Call base class and check for any cross-property interactions
            Validate@MedusaDelayConfig(this);
        end

        %----------------------------------------------------------------------
        function DoMaskInit(this,blockHandle)
            % DoMaskInit called from mask initialization to perform automation
            % of code generation settings and other canvas interactions.

            % Compute initial value for delay buffer
            this.DelayBufferInitValue = CalcDelayBufferInitVal(this.MaxDelay, this.FrameSize, this.NumChannels);

            % Set code gen options for delay buffer
            MedusaDelayMaskInit(blockHandle, this.BufferAlias, this.DelayHeaderFileName);

            %.Call base class in case it has any work to perform:
            DoMaskInit@BtcBaseClass(this,blockHandle);
        end

    end
end