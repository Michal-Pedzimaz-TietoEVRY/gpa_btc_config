% Most of the code is scripted refering to the Matlab's zp2sos.m and
% https://searchcode.com/codesearch/view/9505959/ 
% Integration of two codes was majorily required due to cplxreal function 
% which is no more supported in Matlab Scripts. 

% The zp2sos Function stated below supports code generation! 

function [sos,g] = zp2sos_for_code_gen(z,p,g)
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