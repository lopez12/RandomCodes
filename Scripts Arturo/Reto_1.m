%Sarahi Ruvalcaba
vt=input('Introduce tu ventana de tiempo: ');
vi=input('Introduce el monto inicial a invertir: ');
P=xlsread('google','precios','e2:e1250');
d=length(P);
MA=zeros(d,1);
GP=zeros(d,1);
A=vi/P(1);
C=vi;
cont=2;
for j=vt:d
    aux=0;
    for i=j-vt+1:j %Uso de la ventana, contador "hacia atras" 
        aux=aux+P(i);
    end
    MA(j,1)=aux/vt;
    
    if j>vt %Suponemos que no se podrá comprar cuando ya haya no haya capital.
       if MA(j-1)<P(j-1)%Comprar 
           if MA(j)>P(j)
               A=C/P(j);
               cont=cont+1;
           end
       end 
       if MA(j-1)>P(j-1)%Vender 
           if MA(j)<P(j)
               C=A*P(j);
               cont=cont+1;
           end
       end
    end
end
R=C/vi-1;
disp('Rendimiento');
disp(R);

t=1:d;
plot(t,MA,'r-',t,P,'b--');