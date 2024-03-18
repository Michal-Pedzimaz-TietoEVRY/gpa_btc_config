function [z,p,k] = butter_for_code_gen(order,maxOrder,frequency,type)
%MYBUTTER Summary of this function goes here
%   Detailed explanation goes here

% zeros first
z = zeros(1,maxOrder);
if strcmp(type,'high')
    z(1:order) = ones(1,min(order,maxOrder));
elseif strcmp(type,'low')
    z(1:order) = -1*ones(1,min(order,maxOrder));
else
    TranslateError('Filter Type must be high or low');
end

p = complex(zeros(1,maxOrder));
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


if strcmp(type,'high')
    k = real(prod((1+p(1:order))/2));
else 
    k = real(prod((1-p(1:order))/2));
end
 
       
 


