function pob=cruzamiento2(nhijos,pob)

% Funci�n que crea "nhijos" n�mero de hijos a partir de los c�digos
% gen�ticos que se encuentren en "xpadresbin"
% ///////////////FUNCI�N DESARROLLADA POR DR. RIEMANN RUIZ//////////
%
% Par�metros de Entrada:
% "nhijos", n�mero de hijos que se generar�n
% "pob", estructura de la poblaci�n
%
% Par�metros de Salida:
% "pob.xhijos", valor de hijos en el espacio de b�squeda
% "pob.xhijosint", valor de hijos en entero seg�n el c�digo gen�tico
% "pob.xhijosbin", c�digos gen�ticos de padres

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
