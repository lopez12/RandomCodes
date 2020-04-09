%Sarahí Ruvalcaba
close all;
clear all;
clc;

np=8;
x1=ini_pob2(np,11,-100,100);
x2=ini_pob2(np,11,-100,100);
x3=ini_pob2(np,11,-100,100);
% Inicialización: Desde -100 hasta 100 por si el valor es negativo

k=100;
zprom=zeros(1,k);
for i=1:k
    % Función de selección: Ejercicio 1
    %Selección
    zp=((x1.xpob).^2)-(2*(x1.xpob))-10*(cos((x1.xpob)-1)+cos((x2.xpob)+.5)+cos((x3.xpob)))+((x2.xpob).^2)+(x2.xpob)+3.5+((x3.xpob).^2);
    x1=selec_mejores2(4,x1,zp,'min');
    x2=selec_mejores2(4,x2,zp,'min');
    x3=selec_mejores2(4,x3,zp,'min');
    % Cruzamiento
    x1=cruzamiento2(4,x1);
    x2=cruzamiento2(4,x2);
    x3=cruzamiento2(4,x3);
    % Mutación
    if mod(i,20)==0                     
        [x1.xhijos,x1.xhijosint,x1.xhijosbin]=mutacion(1,x1.xhijosbin,x1.xmin,x1.xmax);
        [x2.xhijos,x2.xhijosint,x2.xhijosbin]=mutacion(1,x2.xhijosbin,x2.xmin,x2.xmax);
        [x3.xhijos,x3.xhijosint,x3.xhijosbin]=mutacion(1,x3.xhijosbin,x3.xmin,x3.xmax);
    end
    x1.xpob=[x1.xpadres; x1.xhijos];  
    x2.xpob=[x2.xpadres; x2.xhijos];  
    x3.xpob=[x3.xpadres; x3.xhijos];  
    zprom(1,i)=mean(zp);
end
plot(zprom);
[zp x1.xpob x2.xpob x3.xpob]

% 
%    1.0e+04 *
% 
%     0.0178    0.0001    0.0013    0.0001