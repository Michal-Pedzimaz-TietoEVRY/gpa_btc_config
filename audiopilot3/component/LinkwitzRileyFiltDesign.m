function [z,p,k] = LinkwitzRileyFiltDesign(order,frequency,type)
%LinkwitzRileyFiltDesign: Our own function designing a Linkwitz Riley Filter
%   [z,p,k] = LinkRitzRileyFiltDesign(order,frequency,type)
%   This function returns the zeros-pole-gain (ZPK) form of the filter
%   Arguments:
%       order - order of filter, must be even
%       frequency - cutoff frequency
%       type - "high" for high-pass, "low" for low-pass

if (mod(order,2) ~= 0)
   TranslateError('Filter order must be even'); 
end

% Zeros first
z = zeros(order,1);
if strcmp(type,'high')
    z(1:order) = ones(order,1);
elseif strcmp(type,'low')
    z(1:order) = -1*ones(order,1);
else
    TranslateError('Filter Type must be high or low');
end

% Next the poles
p = complex(zeros(order,1));
halfOrder = order/2;

% The poles are the same as those of Butterworth filters,
% but each pole is duplicated (or doubled)
for n = 1:halfOrder
    if n == (halfOrder+1)/2 
        sp = -pi*frequency;
    else
        sp_real = pi*frequency*cos(((2*n+halfOrder-1)*pi)/(2*halfOrder));
        sp_imag = pi*frequency*sin(((2*n+halfOrder-1)*pi)/(2*halfOrder));
        sp = sp_real + 1i*sp_imag;
    end
    p(2*n-1) = (1+sp/2)/(1-sp/2);
    p(2*n) = (1+sp/2)/(1-sp/2);
end

% Normalization Factor
if strcmp(type,'high')
    k = real(prod((1+p(1:order))/2));
else 
    k = real(prod((1-p(1:order))/2));
end
 
       
 


