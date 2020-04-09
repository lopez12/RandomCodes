Manchas_Solares  = [101,82,66 35 31 7 20 92 154 125 85 68 38 23 10 24 83 132 131 118 90 67 60 47 41 21 16 6 4 7 14 34 45 43 48 42 28 10 8 2 0 1 5 12 14 35 46 41 30 21 16 7 4 2 8 17 36 50 62 67 71 48 28 8 13 57 122 138 103 86 63 37 24 11 15 40 62 98 124 96 66 64 54 39 21 7 4 23 55 94 96 77 59 44 47 30 16 7 37 74];
CorrelacionA=xcorr(Manchas_Solares,Manchas_Solares);
%plot(CorrelacionA);
Tam = length(Manchas_Solares);
Picos = 0;
Promedio = 0;
j=1;
for n=2: Tam-1
   if(Manchas_Solares(n)> Manchas_Solares(n-1) && Manchas_Solares(n)> Manchas_Solares(n+1))
       Picos(j) = n;
       j=j+1;
   end      
end
Tam = length(Picos);
Memcpy_Penultimopico = Picos(Tam-1);
for n=1:Tam-1
   Picos(n) = Picos (n+1)-Picos (n);
   Promedio = Picos(n) + Promedio;
end
Periodo = Promedio/(Tam-1)
for n=1:Tam-1
    Desiviacion_Estandar = (Picos(n)-Periodo)^2;
end
Desiviacion_Estandar = (Desiviacion_Estandar/(Tam-1))^(1/2)
Picos(Tam)=Picos(Tam)-Memcpy_Penultimopico;
plot(CorrelacionA);