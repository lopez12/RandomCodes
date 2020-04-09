function pob = ini_pob2(npob,nbits,xmin,xmax)
% Función que inicializá "npob" número de pobladores, dentro de un rango que
% va desde "xmin" hasta "xmax" con una resolución de "nbits" bits.
% ///////////////FUNCIÓN DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Parámetros de Entrada:
% "npob", número de pobladores
% "nbits", número de bits del código genético
% "xmin", valor extremo mínimo del rango de búsqueda
% "xmax", valor extremo máximo del rango de búsqueda
%
% Parámetros de Salida:
% "pob", estructura con los parámetros de la población
% "pob.npob", número de pobladores
% "pob.nbits", número de bits del código genético
% "pob.xmin", valor extremo mínimo del rango de búsqueda
% "pob.xmax", valor extremo máximo del rango de búsqueda
% "pob.xpob", valor de la población en el espacio de búsqueda
% "pob.xint", valor de la población en entero según el código genético
% "pob.xbin", códigos genéticos de la población
% "pob.ypob"=[];
% "pob.xpadres"=[];
% "pob.xpadresint"=[];
% "pob.xpadresbin"=[];
% "pob.xhijos"=[];
% "pob.xhijosint"=[];
% "pob.xhijosbin"=[];

% Generación de los "npob" pobladores
pob.npob=npob;
pob.nbits=nbits;
pob.xmin=xmin;
pob.xmax=xmax;
pob.xint=round(((2^nbits)-1)*rand(npob,1));
pob.xpob = ((xmax-xmin)/((2^nbits)-1))*pob.xint+xmin;
pob.xbin=dec2bin(pob.xint,nbits);
pob.ypob=[];
pob.xpadres=[];
pob.xpadresint=[];
pob.xpadresbin=[];
pob.xhijos=[];
pob.xhijosint=[];
pob.xhijosbin=[];

