function varargout = hilbpair(w1,w2,dtheta)
%HILBPAIR  Design discrete-time allpass Hilbert transform pair
%
%   [B1,A1,B2,A2] = HILBPAIR(W1,W2,DTHETA) designs two discrete-time
%   allpass filters, given by numerator coefficients B and denominator
%   coefficients A, such that the first filter lags the second by PI
%   (90 degrees) over a specified frequency range.  The lowest
%   frequency of interest is W1 (0,PI), and the highest frequency of
%   interest is W2 (0,PI).  The maximum allowed phase difference
%   deviation is DTHETA (in radians).
%
%   [SOS1,SOS2] = HILBPAIR(W1,W2,DTHETA) returns the designed filters
%   as second-order sections.  
%
%   [Z1,P1,K1,Z2,P2,K2] = HILBPAIR(W1,W2,DTHETA) returns the designed
%   filters in zero-pole representation.
%
%   The resulting filters are strictly allpass and have an equal-ripple
%   phase difference across the frequency band of interest.  The orders
%   of the two filters never differ by more than 1.
%   
%   See also ELLIP

% Paul Hultz
% $Id: hilbpair.m 11244 2011-10-31 18:51:23Z rg20270 $

% BOSE CONFIDENTIAL INFORMATION

%   Required functions:
%     ELLIPORD (Signal Processing Toolbox),
%     ELLIPAP (Signal Processing Toolbox),
%     WARP_LTI (Bose Common Toolbox)
%
%   References:
%     [1] R. Ansari, "IIR Discrete-Time Hilbert Transformers," IEEE
%         Trans. Acoust., Speech, Signal Processing, vol. ASSP-35,
%         no. 8, pp. 1116-1119, Aug. 1987.
%     [2] R. Ansari, "Elliptic Filter Design for a Class of
%         Generalized Halfband Filters," IEEE Trans. Acoust.,
%         Speech, Signal Processing, vol. ASSP-33, no. 4, pp.
%         1146-1150, Oct. 1985.

%   NOTE:
%   It is possible to use the filters designed by this program to 
%   create filters spaced by approximately PI/4 (45 degrees).  To do
%   this, convert the designed poles to continuous-time poles using the
%   bilinear transform, and then interpolate between (and outside) them
%   on a log scale using cubic interpolation.  This produces two extra
%   sets of poles, which will give the (roughly) PI/4 filters when
%   converted back to discrete-time allpass filters.

% Equivalent halfband elliptic filter stopband ripple
d = sin(0.5*dtheta);
% Equivalent halfband elliptic filter passband edge
wp = pi/2 - 2 * atan( sqrt( tan(w1/2)*cot(w2/2) ) );

% Passband ripple in dB
rp = -10 * log10( 1 - d^2 );
% Stopband ripple in dB
rs = -10 * log10( d^2 );

% Total filter order
order = ellipord(wp/pi,(pi-wp)/pi,rp,rs);

% Design equivalent halfband elliptic filter
[z,p] = ellipap(order,rp,rs);

% Convert conjugate singularities to right half-plane singularities;
% these map to imaginary-axis poles for the elliptic halfband filter,
% but we use them as real-axis poles to create the Hilbert filter
p(imag(p) < 0) = -p(imag(p) < 0);

% Cosine of singularity angles
cos_theta = cos(angle(p));

% Discrete-time coefficients (poles^2)
a = zeros(size(p));
idx = find(cos_theta ~= -1);
a(idx) = (1 - cos_theta(idx)) ./ (1 + cos_theta(idx));
a(cos_theta == -1) = 0;
a = sort(a);

% Discrete-time singularities
dtpz = sqrt(a);

% Odd-order calculations
if (rem(order,2) == 1)
   % Poles for odd order -- don't include delay (pole @ origin)
   p = [ -dtpz(fliplr(3:2:end)); dtpz(3:2:end) ];
   % Zeros for odd order
   z = [ -dtpz(fliplr(2:2:end)); dtpz(2:2:end) ];
   % Divide into two sets of causal singularities
   p1 = p(abs(p) < 1);
   z1 = z(abs(z) > 1);
   p2 = z(abs(z) < 1);
   z2 = p(abs(p) > 1);
   % Calculate transfer functions -- include delay
   num1 = [ 0 poly(z1) ];
   den1 = [ poly(p1) 0 ];
   num2 = poly(z2);
   den2 = poly(p2);
   % Normalize transfer functions
   num1 = num1 * sum(den1)/sum(num1);
   num2 = num2 * sum(den2)/sum(num2);
   
% Even-order calculations
else
   % Poles for even order
   p = [ -dtpz(fliplr(1:2:end)); dtpz(2:2:end) ];
   % Zeros for even order
   z = [ -dtpz(fliplr(2:2:end)); dtpz(1:2:end) ];
   % Divide into two sets of causal singularities
   p1 = p(abs(p) < 1);
   z1 = z(abs(z) > 1);
   p2 = z(abs(z) < 1);
   z2 = p(abs(p) > 1);
   % Calculate transfer functions
   num1 = poly(z1);
   den1 = poly(p1);
   num2 = poly(z2);
   den2 = poly(p2);
   % Normalize transfer functions
   num1 = num1 * sum(den1)/sum(num1);
   num2 = num2 * sum(den2)/sum(num2);
end

% Make sure first transfer function lags second -- reverse if necessary
if (rem(order,4) > 1)
   num = num2; den = den2;
   num2 = num1; den2 = den1;
   num1 = num; den1 = den;
end
   
% Warping coefficient
alpha = (sqrt(tan(w1/2)*tan(w2/2)) - 1) / (sqrt(tan(w1/2)*tan(w2/2)) + 1);
% Warp transfer functions -- warp_lti uses -alpha
[num1,den1] = warp_lti(num1,den1,-alpha);
[num2,den2] = warp_lti(num2,den2,-alpha);

% Transfer function output
if (nargout == 4)
   varargout{1} = num1;
   varargout{2} = den1;
   varargout{3} = num2;
   varargout{4} = den2;
% SOS output
elseif (nargout == 2)
   sos1 = tf2sos(num1,den1);
   sos2 = tf2sos(num2,den2);
   varargout{1} = sos1;
   varargout{2} = sos2;
% ZPK output
elseif (nargout == 6)
   [z1,p1,k1] = tf2zp(num1,den1);
   [z2,p2,k2] = tf2zp(num2,den2);
   varargout{1} = z1;
   varargout{2} = p1;
   varargout{3} = k1;
   varargout{4} = z2;
   varargout{5} = p2;
   varargout{6} = k2;
end
