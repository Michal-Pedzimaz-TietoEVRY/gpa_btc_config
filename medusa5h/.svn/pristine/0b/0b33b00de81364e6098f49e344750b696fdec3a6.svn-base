function varargout = warp_lti(varargin)
%WARP_LTI Frequency warping of discrete-time LTI systems.
%
%   Warping is controlled by the warping factor ALPHA, which is between -1
%   and 1.  Positive values of ALPHA cause the low frequencies to be
%   compressed and the high frequencies to be stretched; negative values
%   of ALPHA cause the low frequencies to be stretched and the high
%   frequencies to be compressed.  The warping process can be reversed by
%   warping with -ALPHA.
%
%   The function can be called with various input arguments:
%      WARP_LTI(LTI,ALPHA)     LTI structure representation (.Z,.P,.K)
%      WARP_LTI(B,A,ALPHA)     Transfer function representation
%      WARP_LTI(Z,P,K,ALPHA)   Singularity representation
%   The function can also return results in several forms:
%      LTI     = WARP_LTI()    LTI structure representation (.Z,.P,.K)
%      [B,A]   = WARP_LTI()    Transfer function representation
%      [Z,P,K] = WARP_LTI()    Singularity representation
%
%   Required programs: (none)
%   
%   Required files: (none)
%   
%   Required functions:
%     ZP2SOS (Signal Processing Toolbox)
%     SOS2ZP (Signal Processing Toolbox)
%
%   See also WARP, WARP_FILTER, WARP_FREQZ

% BOSE CONFIDENTIAL INFORMATION
%
% Paul Hultz
% $Id: warp_lti.m 11244 2011-10-31 18:51:23Z rg20270 $

% Get alpha from input arguments
alpha = varargin{nargin};
% LTI structure input
if (nargin==2)
   z = varargin{1}.Z;
	p = varargin{1}.P;
	k = varargin{1}.K;
% Transfer function input
elseif (nargin==3)
	b = varargin{1}(:).';
   a = varargin{2}(:).';
	[z,p,k] = tf2zp(b,a);
% Singularity input
elseif (nargin==4)
	z = varargin{1};
	p = varargin{2};
	k = varargin{3};
end

% Convert to SOS
sos = zp2sos(z,p,k);

% Warp each SOS
for k = 1:size(sos,1)
   % Section is second-order
   if ( (sos(k,3) ~= 0) || (sos(k,6) ~= 0) )
      sos(k,:) = [ sos(k,1)            - sos(k,2)*alpha           + sos(k,3)*alpha^2, ...
                   -2*sos(k,1)*alpha   + sos(k,2)*(alpha^2 + 1)   - 2*sos(k,3)*alpha, ...
                   sos(k,1)*alpha^2    - sos(k,2)*alpha           + sos(k,3), ...
                   sos(k,4)            - sos(k,5)*alpha           + sos(k,6)*alpha^2, ...
                   -2*sos(k,4)*alpha   + sos(k,5)*(alpha^2 + 1)   - 2*sos(k,6)*alpha, ...
                   sos(k,4)*alpha^2    - sos(k,5)*alpha           + sos(k,6) ...
                 ];
   % Section is first-order
   else
      sos(k,:) = [ sos(k,1)            - sos(k,2)*alpha, ...
                   -sos(k,1)*alpha     + sos(k,2), ...
                   0, ...
                   sos(k,4)            - sos(k,5)*alpha, ...
                   -sos(k,4)*alpha     + sos(k,5), ...
                   0 ...
                 ];
   end
end

% Convert back to singularities
[z,p,k] = sos2zp(sos);

% LTI structure output
if (nargout==1)
	varargout{1}.Z = z;
	varargout{1}.P = p;
	varargout{1}.K = k;
% Transfer function output
elseif (nargout==2)
	[varargout{1},varargout{2}] = zp2tf(z,p,k);
% Singularity output
else
	varargout{1} = z;
	varargout{2} = p;
	varargout{3} = k;
end
