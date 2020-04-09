fs = 16000;
x=wavrecord(5*fs,fs,1);
wavplay(x, fs);
Tam_Total = length(x);
Energia_Total = 0;
for n=1:Tam_Total
    Energia_Total = x(n)^2+Energia_Total;
end
Energia_Total = Energia_Total / Tam_Total;
Energia_Segmentada = 0;
Silencios_rec = 0;
y=100;
Tam_Parciales = Tam_Total/80;
for Segmento=1:(Tam_Total/Tam_Parciales-1)
    for n=(Segmento*Tam_Parciales):(Tam_Parciales*Segmento+Tam_Parciales)
        Energia_Segmentada= x(n)^2+Energia_Segmentada;  
    end
    Energia_Segmentada = Energia_Segmentada/Tam_Parciales;
    if(Energia_Segmentada>Energia_Total*.9)
       for n=(Segmento*Tam_Parciales):(Tam_Parciales*Segmento+Tam_Parciales)
        Silencios_rec(y) = x(n);  
        y=y+1;
       end 
    end
    Energia_Segmentada = 0;
end
num=[1,-0.95];
den = [1,0];
funcion_preenfasis = impz(num,den);
filtro_preenf = conv  (Silencios_rec,funcion_preenfasis);
Espectro_grabada = fft(filtro_preenf);
Espectro_grabada = fftshift(Espectro_grabada);
Espectro_grabada = abs(Espectro_grabada);
Tam_espect = length(Espectro_grabada);
Punto_maximo = 0;
for n=1:Tam_espect
   if(Espectro_grabada(n)>Punto_maximo)
       Punto_maximo = Espectro_grabada(n);
   end
end
Espectro_grabada = Espectro_grabada/Punto_maximo;

CorrelacionAde=xcorr(adelante_comp,Espectro_grabada);
TamAde =  length(CorrelacionAde);
Punto_maximoA_Max = 0;
for n=1:TamAde
    if(CorrelacionAde(n)>Punto_maximoA_Max)
       Punto_maximoA_Max = CorrelacionAde(n);
    end
end

if(Punto_maximoA_Max > 110)
   disp('adelante'); 
end

figure(1);
plot(x);
figure(2);
plot(Silencios_rec);
wavplay(Silencios_rec, fs);
figure(3);
plot(filtro_preenf);
figure(4);
plot(Espectro_grabada);
figure(5);
plot(CorrelacionAde);