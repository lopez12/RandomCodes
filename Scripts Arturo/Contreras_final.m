clc;
clear all;
[A,fs]=wavread('C:\Users\Arturo\Desktop\Franz Ferdinand - Love illumination.wav');

disp('Elige una opción')
disp('1.- Rock')
disp('2.- Acustico') %Menu de las opciones
disp('3.- Popular')
opcion=input('');



 switch opcion
     case 1
         ganancia=[10^(7/20) 10^(5/20) 10^(-1/20) 10^(4/20) 10^(6/20)]; %Ganancias para las diferentes bandas
     case 2
         ganancia=[10^(-3/20) 10^(-1/20) 10^(5/20) 10^(4/20) 10^(-1/20)];
     case 3
         ganancia=[10^(-1/20) 10^(1/20) 10^(5/20) 10^(0/20) 10^(-3/20)];
     otherwise
         ganancia=[1 1 1 1 1];
 end

Zeros_BandaBaja=[-1, -1, -1]; %Zeros del pasa bajas
Polos_BandaBaja=[0.9819 + 0.0303i, 0.9819 - 0.0303i, 0.9650]; %Polos para las bajas

Zeros_Banda1=[1,1,1,-1,-1,-1];%Zeros de la Banda 1
Polos_Banda1=[0.9683 + 0.1314i, 0.9683 - 0.1314i, 0.9607 + 0.0908i, 0.9607 - 0.0908i, 0.9849 + 0.0722i, 0.9849 - 0.0722i]; %Polo de la banda 1

Zeros_Banda2=[1,1,1,-1,-1,-1];%Zeros de la Banda 2
Polos_Banda2=[0.9584 + 0.2015i,0.9584 - 0.2015i, 0.9509 + 0.1641i,0.9509 - 0.1641i,0.9750 + 0.1429i, 0.9750 - 0.1429i]; %Polos de la Banda 2

Zeros_Banda3=[1,1,1,-1,-1,-1]; %Zeros de la Banda 3
Polos_Banda3=[0.9423 + 0.2699i,0.9423 - 0.2699i,0.9363 + 0.2334i,0.9363 - 0.2334i,0.9614 + 0.2122i,0.9614 - 0.2122i]; %Polos de la Banda 3

Zeros_BandaAlta=[1,1,1]; %Zeros de las Altas
Polos_BandaAlta=[0.6631 + 0.3680i, 0.6631 - 0.3680i, 0.5469 ]; %Polos de las Altas

Saturacion_Normalization = 6*1e5;


for n=1:360
    Circulo_Unitario(n)=exp(n*1i); %generacion del circulo unitario
end

for n=1:3
    for m=1:360        
      Baja_RestaZeros(m,n)=Circulo_Unitario(m)-Zeros_BandaBaja(n);
      Baja_RestaPolos(m,n)=Circulo_Unitario(m)-Polos_BandaBaja(n);
      Alta_RestaZeros(m,n)=Circulo_Unitario(m)-Zeros_BandaAlta(n);%Encuentra la diferencia de los zeros y polos y de el exponancial imaginaria
      Alta_RestaPolos(m,n)=Circulo_Unitario(m)-Polos_BandaAlta(n);
    end
end

Baja_MultipicacionZeros=ones(360,1);
Baja_MultipicacionPolos=ones(360,1);
Alta_MultiplicacionZero=ones(360,1);
Alta_MultiplicacionPolos=ones(360,1);

for i=1:360
    for j=1:3
        Baja_MultipicacionZeros(i)=Baja_MultipicacionZeros(i)*Baja_RestaZeros(i,j);
        Baja_MultipicacionPolos(i)=Baja_MultipicacionPolos(i)*Baja_RestaPolos(i,j);
        Alta_MultiplicacionZero(i)=Alta_MultiplicacionZero(i)*Alta_RestaZeros(i,j);
        Alta_MultiplicacionPolos(i)=Alta_MultiplicacionPolos(i)*Alta_RestaPolos(i,j);
    end
end

Funcion_TransferenciaBaja=Baja_MultipicacionZeros./Baja_MultipicacionPolos; %Da la funcion de Transferencia del filtro Pasa Baja
Funcion_TransferenciaAltas=Alta_MultiplicacionZero./Alta_MultiplicacionPolos;%Da la funcion de Transferencia del filtro Pasa Alta


for n=1:6
    for m=1:360        
      Banda2_RestaZeros(m,n)=Circulo_Unitario(m)-Zeros_Banda1(n);
      Banda2_RestaPolos(m,n)=Circulo_Unitario(m)-Polos_Banda1(n);
      Banda3_RestaZeros(m,n)=Circulo_Unitario(m)-Zeros_Banda2(n);%Encuentra la diferencia de los zeros y polos y de el exponancial imaginaria
      Banda3_RestaPolos(m,n)=Circulo_Unitario(m)-Polos_Banda2(n);
      Banda4_RestaZeros(m,n)=Circulo_Unitario(m)-Zeros_Banda3(n);
      Banda4_RestaPolos(m,n)=Circulo_Unitario(m)-Polos_Banda3(n);
    end
end

Banda2_MultipicacionZeros=ones(360,1);
Banda2_MultipicacionPolos=ones(360,1);
Banda3_MultiplicacionZeros=ones(360,1);
Banda3_MultiplicacionPolos=ones(360,1);
Banda4_MultiplicacionZeros=ones(360,1);
Banda4_MultiplicacionPolos=ones(360,1);

for i=1:360
    for j=1:6
        Banda2_MultipicacionZeros(i)=Banda2_MultipicacionZeros(i)*Banda2_RestaZeros(i,j);
        Banda2_MultipicacionPolos(i)=Banda2_MultipicacionPolos(i)*Banda2_RestaPolos(i,j);
        Banda3_MultiplicacionZeros(i)=Banda3_MultiplicacionZeros(i)*Banda3_RestaZeros(i,j);
        Banda3_MultiplicacionPolos(i)=Banda3_MultiplicacionPolos(i)*Banda3_RestaPolos(i,j);
        Banda4_MultiplicacionZeros(i)=Banda4_MultiplicacionZeros(i)*Banda4_RestaZeros(i,j);
        Banda4_MultiplicacionPolos(i)=Banda4_MultiplicacionPolos(i)*Banda4_RestaPolos(i,j);
    end
end

Funcion_TransferenciaBanda2=Banda2_MultipicacionZeros./Banda2_MultipicacionPolos;
Funcion_TranferenciaBanda3=Banda3_MultiplicacionZeros./Banda3_MultiplicacionPolos; %Funciones de Transferencias 
Funcion_TransferenciaBanda4=Banda4_MultiplicacionZeros./Banda4_MultiplicacionPolos;

for n=1:360
    Funcion_TransferenciaBajaR=real(Funcion_TransferenciaBaja);
    Funcion_TransferenciaBajaI=imag(Funcion_TransferenciaBaja);
    
    Funcion_TransferenciaBanda2R=real(Funcion_TransferenciaBanda2);
    Funcion_TransferenciaBanda2I=imag(Funcion_TransferenciaBanda2);
    
    Funcion_TranferenciaBanda3R=real(Funcion_TranferenciaBanda3); %Separamos todos los valores imaginarios de los valores reales
    Funcion_TranferenciaBanda3I=imag(Funcion_TranferenciaBanda3);
    
    Funcion_TransferenciaBanda4R=real(Funcion_TransferenciaBanda4);
    Funcion_TransferenciaBanda4I=imag(Funcion_TransferenciaBanda4);
    
    Funcion_TransferenciaAltasR=real(Funcion_TransferenciaAltas);
    Funcion_TransferenciaAltasI=imag(Funcion_TransferenciaAltas);
end

[Fase,Filtro_Baja]=cart2pol(Funcion_TransferenciaBajaR, Funcion_TransferenciaBajaI);
[Fase,Filtro_Banda2]=cart2pol(Funcion_TransferenciaBanda2R, Funcion_TransferenciaBanda2I);
[Fase,Filtro_Banda3]=cart2pol(Funcion_TranferenciaBanda3R, Funcion_TranferenciaBanda3I); %Ahora sacamos los valores rectangulares para encontrar los valores del polnomio original
[Fase,Filtro_Banda4]=cart2pol(Funcion_TransferenciaBanda4R, Funcion_TransferenciaBanda4I);
[Fase,Filtro_Alta]=cart2pol(Funcion_TransferenciaAltasR, Funcion_TransferenciaAltasI);

for n=1:360
    Filtro_Total=(ganancia(1)*Filtro_Baja)+(ganancia(2)*Filtro_Banda2)+(ganancia(3)*Filtro_Banda3)+(ganancia(4)*Filtro_Banda4)+(ganancia(5)*Filtro_Alta); %juntamos todos los filtros para que sea un solo sistema a convolucionar
end



nconv = length(A)+length(Filtro_Total)-1;
    
    for i = 1:nconv
        contador1 = i;
        contador2 = 0;
        for j=1:length(Filtro_Total)
            if((contador1>=1) && (contador1<length(A)))  %convolucion paso por paso
                contador2 = contador2 + (A(contador1)*Filtro_Total(j));
            end
            contador1 = contador1-1;
            Final(i) = contador2;
        end
    end



Final=Final/Saturacion_Normalization;
plot(Final);

sound(Final,fs);

