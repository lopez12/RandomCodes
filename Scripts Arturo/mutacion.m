function [xpobmut,xpobintmut,xpobbinmut]=mutacion(nmut,xpobbin,xmin,xmax)

% Funci�n que realiza la mutaci�n en toda la poblaci�n que se le
% proporcione. Elig� un poblador aleatoriamente y le aplica la mutaci�n en
% un bit aleatorio
% ///////////////FUNCI�N DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Par�metros de Entrada:
% "nmut", n�mero de veces que se realizar� la mutaci�n
% "xpobbin", c�digos gen�ticos de pobladores
% "min", valor extremo minimo del rango de b�squeda
% "max", valor extremo m�ximo del rango de b�squeda
%
% Par�metros de Salida:
% "xpobmut", valor de pobladores mutados en el espacio de b�squeda
% "xpobintmut", valor de pobladres mutados en entero seg�n el c�digo gen�tico
% "xpobbinmut", c�digos gen�ticos de pobladores mutados

[npob,nbits]=size(xpobbin);
for i=1:nmut
    npobmut=ceil(rand*npob);
    nbitmut=ceil(rand*nbits);
    if npobmut==0
        npobmut=1;
    end
    if nbitmut==0
        nbitmut=1;
    end
    if xpobbin(npobmut,nbitmut)=='1'
        xpobbin(npobmut,nbitmut)='0';
    else
        xpobbin(npobmut,nbitmut)='1';
    end
end
xpobbinmut=xpobbin;
xpobintmut=bin2dec(xpobbinmut);
xpobmut = ((xmax-xmin)/((2^nbits)-1))*xpobintmut+xmin;
