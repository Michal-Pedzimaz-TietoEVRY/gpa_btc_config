classdef BandsplitterClass
    %BandsplitterClass contains properties and functions for the Simulink BandsplitterLib
    % model
    
    properties (Constant = true)
        DEFAULT_NUM_STAGES_PER_CHANNEL = 10;
        DEFAULT_CROSSOVER_FREQUENCY = 90;
        DEFAULT_FILTER_ORDER = 5;
        MAX_HPF_ORDER = 10;
        MAX_NUM_CHANNELS = 4;
        IIR_HIGHPASS = 1;
        IIR_LOWPASS = 0;
    end
    
    properties
        sampleRate
        frameSize
        channelCount

        % HPF pooliir parameters
         maxNumStages
         numStagesPerChannel
         sosCoefficients
        
        % HPF design
        crossOverFrequency
        filterOrder
        
        %LPF parameters
        interpolatedFilter
        decimationFactor
    end
    
    methods
        % Constructor
        function obj = BandsplitterClass(numChannels, sampleRate, frameSize, decimationFactor)

            obj.channelCount = numChannels;
            obj.sampleRate = sampleRate;
            obj.frameSize = frameSize;
            obj.decimationFactor = decimationFactor;
            
            obj.crossOverFrequency = obj.DEFAULT_CROSSOVER_FREQUENCY;
            obj.filterOrder = obj.DEFAULT_FILTER_ORDER;

            obj = obj.InitializeHpfCoefficients(BandsplitterClass.DEFAULT_NUM_STAGES_PER_CHANNEL);
            obj = obj.CalcLpfCoefficients();
        end
        
        function obj = InitializeHpfCoefficients(obj, numStages)
            obj.maxNumStages = numStages * obj.channelCount;

            obj.numStagesPerChannel = repmat(numStages,...
                1, obj.channelCount);
            obj.sosCoefficients = repmat([1 0 0 1 0 0], obj.maxNumStages, 1);
        end
        
        function obj = CalcLpfCoefficients(obj)
            % Calculate anti-aliasing filter coefficients (same as Medusa band splitter)
            %% Interpolated Filter
            F = obj.sampleRate;
            Fs = (F/2)/obj.decimationFactor;    % Stop Band Cutoff
            Fp = Fs * .54422;                   % Pass Band Cutoff (.54422 will cause Fp=1500 for DECIMATE = 8, which was the static constant originally)
            down = obj.decimationFactor/2;      % Interpolation Factor (originally 4)... change to reflect DECIMATE value

            ripple_dB = 100;        % Ripple for stop and pass band in dB   
            ripple = 10^(-ripple_dB/20);

            [n,Wn,bta,filtype] = kaiserord([Fp Fs],[1 0],[ripple ripple],F);
            b = fir1(n,Wn,filtype,kaiser(n+1,bta),'noscale');
            firWn = Wn;
            interp_order = n; % save to check for even/odd order 

            basemask = down*[1 zeros(1,(down-1))];
            mask = [];

            for i = 1:ceil(length(b)/down)
              mask = [mask basemask];
            end

            obj.interpolatedFilter = b .* mask(1:length(b));

        end
        
        function obj = CalcHpfCoefficients(obj, fc, order)
            obj.crossOverFrequency = fc;
            obj.filterOrder = order;
        end
        
    end
    methods (Static)
        function [z,p,k] = CalcButterworth(order,frequency,filterType)

            if order > BandsplitterClass.MAX_HPF_ORDER
                order = BandsplitterClass.MAX_HPF_ORDER;
            end
            
            % zeros first
            z = zeros(1,BandsplitterClass.MAX_HPF_ORDER);
            if filterType == BandsplitterClass.IIR_HIGHPASS
                z(1:order) = ones(1,min(order,BandsplitterClass.MAX_HPF_ORDER));
            elseif filterType == BandsplitterClass.IIR_LOWPASS
                z(1:order) = -1*ones(1,min(order,BandsplitterClass.MAX_HPF_ORDER));
            else
                TranslateError('Filter Type must be high or low');
            end

            p = complex(zeros(1,BandsplitterClass.MAX_HPF_ORDER));
            for n = 1:order
                if n == (order+1)/2 
                    sp = -pi*frequency;
                else
                    sp_real = pi*frequency*cos(((2*n+order-1)*pi)/(2*order));
                    sp_imag = pi*frequency*sin(((2*n+order-1)*pi)/(2*order));
                    sp = sp_real + 1i*sp_imag;
                end

                p(n) = (1+sp/2)/(1-sp/2);
            end

            z = z(1:order);
            p = p(1:order);

            if filterType == BandsplitterClass.IIR_HIGHPASS
                k = real(prod((1+p(1:order))/2));
            else 
                k = real(prod((1-p(1:order))/2));
            end
        end

        % The zp2sos Function stated below supports code generation! 
        % Most of the code is scripted refering to the Matlab's zp2sos.m and
        % https://searchcode.com/codesearch/view/9505959/ 
        % Integration of two codes was majorily required due to cplxreal function 
        % which is no more supported in Matlab Scripts. 
        function [sos,g] = zp2sos(z,p,g)
            if nargin < 3
                g = 1; 
            end
            if nargin < 2
                p = []; 
            end

            % Sort the numbers z into complex-conjugate-valued and real-valued elements.
            % The positive imaginary complex numbers of each complex conjugate pair 
            % are returned in zc and the real numbers are returned in zr.

            % pair up the conjugate poles and zeros using cplxpair
            z = cplxpair(z);
            p = cplxpair(p);

            % Get the number of poles and zeros
            lz = length(z);
            lp = length(p);

            ind = find(abs(imag(p)) > 0);
            p_conj = p(ind);   % poles that have conjugate pairs

            coder.varsize('ind_complement');
            B = p_conj(imag(p_conj) >= 0);
            ind_complement = 1:lp;
            if ~isempty(ind)
                ind_complement(ind) = [];
            end
            p_real = p(ind_complement);    % poles that are real

            % break up conjugate pairs and real zeros
            ind = find(abs(imag(z)) > 0);
            z_conj = z(ind);   % zeros that have conjugate pairs
            C = z_conj(imag(z_conj) >= 0);
            ind_complement = 1:lz;
            if ~isempty(ind)
                ind_complement(ind) = [];
            end
            z_real = z(ind_complement);

            zr = z_real; % zeroes that are real
            pr = p_real ;% poles that are real
            pc = B; % positive conjugate poles
            zc = C ; % positive conjugate zeros

            % zc,zr,pc,pr found

            nzc = length(zc);
            npc = length(pc);

            nzr = length(zr);
            npr = length(pr);

            % Pair up real zeros:
            if nzr
                if mod(nzr,2)==1
                    zr_temp = [zr;0]; 
                    nzr = nzr+1; 
                else
                    zr_temp = zr;
                end
                nzrsec = nzr/2;
                zrms = real(-zr_temp(1:2:nzr-1) - zr_temp(2:2:nzr));
                zrp = real(zr_temp(1:2:nzr-1) .* zr_temp(2:2:nzr));
            else
                nzrsec = 0;
                zrms = 0; 
                zrp = 0;
            end

            % Pair up real poles:
            if npr
                if mod(npr,2) == 1
                    pr_temp = [pr;0]; 
                    npr = npr+1; 
                else
                    pr_temp = pr;
                end
                nprsec = npr/2;
                prms = real(-pr_temp(1:2:npr-1) - pr_temp(2:2:npr));
                prp = real(pr_temp(1:2:npr-1) .* pr_temp(2:2:npr));
            else
                nprsec = 0;
                prp = 0;
                prms = 0;
            end

            nsecs = max(ceil(lz/2), ceil(lp/2));

            % Convert complex zeros and poles to real 2nd-order section form:
            zcm2r = -2*real(zc);
            zca2 = abs(zc) .^ 2;
            pcm2r = -2 * real(pc);
            pca2 = abs(pc) .^ 2;

            sos = zeros(nsecs, 6);
            sos(:,1) = ones(nsecs, 1); % all 2nd-order polynomials are monic
            sos(end,1) = g*sos(end, 1);
            sos(:,4) = ones(nsecs, 1); 

            nzrl = nzc + nzrsec; % index of last real zero section
            nprl = npc + nprsec; % index of last real pole section

            for i = 1:nsecs

                if i <= nzc % lay down a complex zero pair:
                    sos(i,2:3) = [zcm2r(i) zca2(i)];
                    sos(end,2:3) = g*sos(end,2:3);
                elseif i <= nzrl % lay down a pair of real zeros:
                    sos(i,2:3) = [zrms(i-nzc) zrp(i-nzc)];
                    sos(end,2:3) = g*sos(end,2:3);
                end  

                if i <= npc % lay down a complex pole pair:
                    sos(i,5:6) = [pcm2r(i) pca2(i)];
                elseif i <= nprl % lay down a pair of real poles:
                    sos(i,5:6) = [prms(i-npc) prp(i-npc)];
                end  
            end        
        end
    end
end
