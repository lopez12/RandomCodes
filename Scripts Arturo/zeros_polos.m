function[Num,Den]=zeros_polos(Numero_zp)
for n=1:Numero_zp
     zeros(n)=input('Introduce un zeros \n');
     polos(n)=input('Introduce un polo \n');
end
     Num = poly(zeros);
     Den = poly(polos);
     Grado_poli=length(Num);
     y=[0 0 0 0 0 0 0 0 0 0 0 0 0];
     x=[0 0 0 1 0 0 0 0];
     for n=4:8
     y(n)=Den(4)*y(n-3)+Num(4)*x(n-3)+Den(3)*y(n-2)+Num(3)*x(n-2)+Den(2)*y(n-1)+Num(2)*x(n-1)+Den(1)*y(n)+Num(1)*x(n)
     respuesta(n) = y(n)
     end
 
    for contadordeoperaciones=1:Numprocesos
    Resultado(1,contadoringreso)=Resultado(1,contadoringreso)+b(1,contadordeoperaciones)*a(1,contadordeoperaciones);
    end
  
     Convolucion_Matlab_own = Resultado(1,contadoringreso)

     % y(n)=Den(1)*y(n-3)+Num(1)*x(n-3)+Den(2)*y(n-2)+Num(2)*x(n-2)+Den(3)*y(n-1)+Num(3)*x(n-1)+Den(4)*y(n)+Num(4)*x(n);