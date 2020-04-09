function [Resultado]=corelacion(b,a)





Numprocesos=length (a);

Resultado=zeros(1,((Numprocesos*2)-1));


for contadoringreso=1:((Numprocesos*2)-1)
    
    
    for contadordeoperaciones=1:Numprocesos
    Resultado(1,contadoringreso)=Resultado(1,contadoringreso)+b(1,Numprocesos+1-contadordeoperaciones)*a(1,contadordeoperaciones);
        Resultado(1,contadordeoperaciones)
    end
  
     Corelacion_Matlab_own = Resultado(1,contadoringreso)

    
    for contadorcorrimiento= 1:(Numprocesos-1)
    b(1,contadorcorrimiento)=b(1,contadorcorrimiento+1);
    end   
b(1,Numprocesos)=0;

end
