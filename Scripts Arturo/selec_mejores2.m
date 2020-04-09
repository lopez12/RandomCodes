function pob=selec_mejores2(npadres,pob,ypob,minmax)

% Funci�n que selecciona los mejores de una poblaci�n con la opci�n de
% minimizar o maximizar
% ///////////////FUNCI�N DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Par�metros de Entrada:
% "npadres", n�mero de pobladores que sobrevivir�n
% "pob", estructura de la poblaci�n
% "ypob", desempe�os de los pobladores
% "minmax", minimizar o m�ximizar seg�n el valor 'min' � 'max'
%
% Par�metros de Salida:
% "pob.xpadres", valor de padres en el espacio de b�squeda
% "pob.xpadresint", valor de padres en entero seg�n el c�digo gen�tico
% "pob.xpadresbin", c�digos gen�ticos de padres

xpobtodo=[ypob pob.xpob pob.xint];
xpobtodo=sortrows(xpobtodo,1);

switch minmax
    case 'min'
        xpadres = xpobtodo(1:npadres,2);
        xpadresint = xpobtodo(1:npadres,3);
        xpadresbin = dec2bin(xpadresint,size(pob.xbin,2));
    case 'max'
        xpadres = xpobtodo(size(xpobtodo,1)-(npadres-1):size(xpobtodo,1),2);
        xpadresint = xpobtodo(size(xpobtodo,1)-(npadres-1):size(xpobtodo,1),3);
        xpadresbin = dec2bin(xpadresint,size(pob.xbin,2));
    otherwise
        disp('Valores aceptados de minmax son: min � max')
        xpadres = 0;
        xpadresint = 0;
        xpadresbin = 0;
end
pob.xpadres=xpadres;
pob.xpadresint=xpadresint;
pob.xpadresbin=xpadresbin;
pob.ypob=ypob;
