function [M,F]=Voz
[M,F]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\vocal_i_Arturo.wav');
Tam=length(M);
Ts=1/8000;
T=1/F;
enc=Ts:Ts:Tam*Ts;
Y=M(18420:18490);
plot(Y)
Tam=length(Y);
Algo=ones(Tam,1)*T;
A=ones(1,Tam);
X=A*Ts;
w=2*pi*F;
Tan=-T/2:T:T/2;
A0=(X*Y)*(2/T);


N=input('Dame el numero de Ns a sacar \n');

for n=1:N
    aux1 = cos (n*w*Tan);
    aux2 = Y*aux1;
    aux3(n,1)= aux2(n,1)*Algo(n,1);
end

An = aux3 *(2/T);

for n=1:N
    aux1 = sin (n*w*Tan);
    aux2 = Y*aux1;
    aux3(n,1)= aux2(n,1)*Algo(n,1);
end

bn = aux3 *(2/T);

for n=1:N
    serie(n,1)=An(n,1)*cos(w*T/2*n)+bn(n,1)*sin(w*T/2*n);
end


Potencia_Inicial = (A0^2)/4;
Potencia_Cmp1 = 0;

for n=1:N
    
Potencia_Cmp1 = An(n,1)^2+bn(n,1)^2 + Potencia_Inicial + Potencia_Cmp1;

end

k=1;
A_cmp=1;
diferencia = 1;


plot(serie);

k=110
 xlabel('t');
 ylabel('Magnitud');
 title('Vocal "i"');
sound(M,F);
