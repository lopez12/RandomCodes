function [xpobmut,xpobintmut,xpobbinmut]=mutacion(nmut,xpobbin,xmin,xmax)

% Función que realiza la mutación en toda la población que se le
% proporcione. Eligé un poblador aleatoriamente y le aplica la mutación en
% un bit aleatorio
% ///////////////FUNCIÓN DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Parámetros de Entrada:
% "nmut", número de veces que se realizará la mutación
% "xpobbin", códigos genéticos de pobladores
% "min", valor extremo minimo del rango de búsqueda
% "max", valor extremo máximo del rango de búsqueda
%
% Parámetros de Salida:
% "xpobmut", valor de pobladores mutados en el espacio de búsqueda
% "xpobintmut", valor de pobladres mutados en entero según el código genético
% "xpobbinmut", códigos genéticos de pobladores mutados

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
