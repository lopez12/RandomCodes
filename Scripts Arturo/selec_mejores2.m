function pob=selec_mejores2(npadres,pob,ypob,minmax)

% Función que selecciona los mejores de una población con la opción de
% minimizar o maximizar
% ///////////////FUNCIÓN DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Parámetros de Entrada:
% "npadres", número de pobladores que sobrevivirán
% "pob", estructura de la población
% "ypob", desempeños de los pobladores
% "minmax", minimizar o máximizar según el valor 'min' ó 'max'
%
% Parámetros de Salida:
% "pob.xpadres", valor de padres en el espacio de búsqueda
% "pob.xpadresint", valor de padres en entero según el código genético
% "pob.xpadresbin", códigos genéticos de padres

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
        disp('Valores aceptados de minmax son: min ó max')
        xpadres = 0;
        xpadresint = 0;
        xpadresbin = 0;
end
pob.xpadres=xpadres;
pob.xpadresint=xpadresint;
pob.xpadresbin=xpadresbin;
pob.ypob=ypob;
