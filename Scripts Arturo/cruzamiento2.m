function pob=cruzamiento2(nhijos,pob)

% Función que crea "nhijos" número de hijos a partir de los códigos
% genéticos que se encuentren en "xpadresbin"
% ///////////////FUNCIÓN DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Parámetros de Entrada:
% "nhijos", número de hijos que se generarán
% "pob", estructura de la población
%
% Parámetros de Salida:
% "pob.xhijos", valor de hijos en el espacio de búsqueda
% "pob.xhijosint", valor de hijos en entero según el código genético
% "pob.xhijosbin", códigos genéticos de padres

xpadrestemp=pob.xpadresbin;
for k = 1:round(nhijos/size(pob.xpadresbin,1))
    xpadrestemp=[xpadrestemp;pob.xpadresbin];
end

%nbits=size(pob.xpadresbin,2);
for k = 1:nhijos
    abit=floor(rand()*pob.nbits);
    if abit==0
        abit=1;
    end
    xhijostemp(k,:)=[xpadrestemp(k,abit+1:pob.nbits) xpadrestemp(k+1,1:abit)];
end

xhijosbin=xhijostemp;
xhijosint=bin2dec(xhijosbin);
xhijos = ((pob.xmax-pob.xmin)/((2^pob.nbits)-1))*xhijosint+pob.xmin;

pob.xhijosbin=xhijosbin;
pob.xhijosint=xhijosint;
pob.xhijos =xhijos ;
