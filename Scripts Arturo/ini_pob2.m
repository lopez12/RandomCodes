function pob = ini_pob2(npob,nbits,xmin,xmax)
% Funci�n que inicializ� "npob" n�mero de pobladores, dentro de un rango que
% va desde "xmin" hasta "xmax" con una resoluci�n de "nbits" bits.
% ///////////////FUNCI�N DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Par�metros de Entrada:
% "npob", n�mero de pobladores
% "nbits", n�mero de bits del c�digo gen�tico
% "xmin", valor extremo m�nimo del rango de b�squeda
% "xmax", valor extremo m�ximo del rango de b�squeda
%
% Par�metros de Salida:
% "pob", estructura con los par�metros de la poblaci�n
% "pob.npob", n�mero de pobladores
% "pob.nbits", n�mero de bits del c�digo gen�tico
% "pob.xmin", valor extremo m�nimo del rango de b�squeda
% "pob.xmax", valor extremo m�ximo del rango de b�squeda
% "pob.xpob", valor de la poblaci�n en el espacio de b�squeda
% "pob.xint", valor de la poblaci�n en entero seg�n el c�digo gen�tico
% "pob.xbin", c�digos gen�ticos de la poblaci�n
% "pob.ypob"=[];
% "pob.xpadres"=[];
% "pob.xpadresint"=[];
% "pob.xpadresbin"=[];
% "pob.xhijos"=[];
% "pob.xhijosint"=[];
% "pob.xhijosbin"=[];

% Generaci�n de los "npob" pobladores
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

