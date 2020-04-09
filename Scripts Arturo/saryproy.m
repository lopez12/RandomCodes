clc 
clear all 
format long;
precios=xlsread('Banorte.xlsx','table','b2:b2587');
d=length(precios);
m=d;
R=zeros(d,1);

K=15;

for i=2:d
    R(i,1)=(precios(i,1)/precios(i-1,1))-1;
end 

P=1;
Q=1;
[w,a,b]=ugarch(R,P,Q);
disp('Los coeficientes estimados');
disp([w;a;b]);

%Estimaciones de volatilidad pasadas y futuras
NumPeriods=10; %Estimaciones Futuras
[VarianceForcast,H1]=ugarchpred(R,w,a,b,NumPeriods);
for i=1:d
B(i)=(R(i)-mean(R))^2; 
end 
for i=1:d
A(i)=(R(i)^2)/H1(i);
end

%Construir la función de auto correlación de la variable B consideremos K rezagos
Brez=zeros(m,K); %Para construir el numerador de (1.1)
B_Bmed=zeros(m,1);%Para construir del denominador de (1.1)
for i=2:m
B_Bmed(i)=(B(i)-mean(B))^2;
end
for j=1:K
for i=2:m-j
Brez(i+j,j)=(B(i+j)-mean(B))*(B(i)-mean(B));
end
end
%Calcular el coeficiente de auto correlación de K rezagos para la variable B
CautB=zeros(K,1);
for i=1:K
 CautB(i,1)=sum(Brez(1:m,i))/sum(B_Bmed);
end

%segunda prueba 
%Construir la función de auto correlación de la variable A consideremos K rezagos
K=15;
Arez=zeros(m,K); %Para construir el numerador de (1.1)
A_Amed=zeros(m,1); %Para construir del denominador de (1.1)
for i=2:m
A_Amed(i)=(A(i)-mean(A))^2;
end
for j=1:K
for i=2:m-j
Arez(i+j,j)=(A(i+j)-mean(A))*(A(i)-mean(A));
end
end
%Calcular el coeficiente de auto correlación de K rezagos para la variable A
CautA=zeros(K,1);
for i=1:K
CautA(i,1)=sum(Arez(1:m,i))/sum(A_Amed); %Efectuar la división según la ecuación en (1.1)
end

%Prueba Formal 

%Estadísticos para prueba formal del auto correlación en A
Lja=zeros(K,1);
for a=1:K
Lja(a,1)=((m+2)/(m-a))*CautA(a,1)^2; %Para construir según la ecuación(1.2)
end
LjBTestA=m*sum(Lja);
%Estadísticos para prueba formal del auto correlación en B
Ljb=zeros(K,1);
for a=1:K
Ljb(a,1)=((m+2)/(m-a))*CautB(a,1)^2; %Para construir según la ecuación (1.2)
end
LjBTestB=m*sum(Ljb);
%El estadístico de prueba, será una ji cuadrada con 15, grados de libertad y un nivel de significancia del 10%.
%Estadístico de prueba es una ji-cuadrada con K grados de libertad y .90
%probabilidades
EP=chi2inv(.90,K); %Aquí calculamos el valor del estadístico de prueba.
%Y efectuamos la prueba para la variable B
if LjBTestB>EP
 disp('La serie B presenta auto correlación');
end
if LjBTestB<EP
 disp('La serie B no presenta auto correlación');
end
%Ahora lo hacemos para la variable A
if LjBTestA>EP
 disp('La serie A presenta auto correlación');
 disp('Se rechaza Ho y el modelo no ajusta a un GARCH(1,1)');
end
if LjBTestA<EP
 disp('La serie A no presenta auto correlación');
 disp('No se rechaza Ho y el modelo ajusta a un GARCH(1,1)');
end