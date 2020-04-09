function [M,F]=Modulacion
[M,F]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_Arturo.wav');
Tam=length(M);
Espectro_Voz = abs(fft(M));
w=pi
for t=1:Tam
    C(t)=cos(t*w);
    Modulacion_1(t) = C(t) * M(t);
end

Espectro_Modulacion1 = abs(fft(Modulacion_1));


for t=1:Tam
    C(t)=cos(t*w);
    Modulacion_2(t) = C(t)*Modulacion_1(t);
end
Espectro_Modulacion2 = abs(fft(Modulacion_2));
Espectro_Coseno = abs(fft(C));

plot(Espectro_Voz);
sound(M,F);