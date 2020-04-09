function [Resultado]=convolution(b)
clear;
clc; 

SerialHandler = serial('COM4');
fopen(SerialHandler);

a=[1,2,3,4,5]
Numprocesos=length (a)
b=zeros(1,Numprocesos);
Resultado=zeros(1,((Numprocesos*2)-1));


for contadoringreso=1:((Numprocesos*2)-1)
    if(contadoringreso<=Numprocesos)
    b(1,1) = input('Introduce el siguiente valor ','s')-48; 
    
    fprintf(SerialHandler,b(1,1));
   
    l=fscanf(SerialHandler,'%s');
    l=l+1-1
   
    end
    
    for contadordeoperaciones=1:Numprocesos
    Resultado(1,contadoringreso)=Resultado(1,contadoringreso)+b(1,contadordeoperaciones)*a(1,contadordeoperaciones);
    end
  
     Convolucion_Matlab_own = Resultado(1,contadoringreso)

    
    for contadorcorrimiento= 0:(Numprocesos-2)
    b(1,(Numprocesos-contadorcorrimiento))=b(1,(Numprocesos-contadorcorrimiento-1));
    end   
b(1,1)=0;

end

fclose(SerialHandler);