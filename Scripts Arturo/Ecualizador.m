[x,fs]=wavread('C:\Users\Arturo\Desktop\I need your love.wav');
F_Muestreo = 8000;
Wn1 = 125*2/F_Muestreo;
Wn2 = 250*2/F_Muestreo;
Wn3 = 500*2/F_Muestreo;
Wn4 = 3000/F_Muestreo;

Generos = input('Introduce el siguiente valor \n 1.-Pop \n 2.-Acustica \n 3.-Rock \n','s');

switch(Generos)
    case 1
        Ganancia_Baja = 10^(0/20);
        Ganancia_Banda1 = 10^(0/20);
        Ganancia_Banda2 = 10^(4/20);
        Ganancia_Banda3 = 10^(-1/20);
        Ganancia_Alta = 10^(-2/20);
    
        case 2
        Ganancia_Baja = 10^(-3/20);
        Ganancia_Banda1 = 10^(-1/20);
        Ganancia_Banda2 = 10^(3/20);
        Ganancia_Banda3 = 10^(-5/20);
        Ganancia_Alta = 10^(-5/20);
    
        case 3
        Ganancia_Baja = 10^(4/20);
        Ganancia_Banda1 = 10^(2/20);
        Ganancia_Banda2 = 10^(0/20);
        Ganancia_Banda3 = 10^(1/20);
        Ganancia_Alta = 10^(3/20);
    otherwise
        Ganancia_Baja = 10^(10/20);
        Ganancia_Banda1 = 10^(10/20);
        Ganancia_Banda2 = 10^(10/20);
        Ganancia_Banda3 = 10^(10/20);
        Ganancia_Alta = 10^(10/20);
end

Baja_Filtro = fir1 (4,Wn1,'low');
Banda1_Filtro = fir1 (4,[Wn1 Wn2]);
Banda2_Filtro = fir1 (4,[Wn2 Wn3]);
Banda3_Filtro = fir1 (4,[Wn3 Wn4]);
Alta_Filtro = fir1 (4,Wn4,'high');

Baja_Filtrada = conv(Baja_Filtro,x);
Banda1_Filtrada = conv(Banda1_Filtro,x);
Banda2_Filtrada = conv(Banda2_Filtro,x);
Banda3_Filtrada = conv(Banda3_Filtro,x);
Alta_Filtrada = conv(Alta_Filtro,x);

Baja_Amplificada = Baja_Filtrada * Ganancia_Baja;
Banda1_Amplificada = Banda1_Filtrada * Ganancia_Banda1;
Banda2_Amplificada = Banda2_Filtrada * Ganancia_Banda2;
Banda3_Amplificada = Banda3_Filtrada * Ganancia_Banda3;
Alta_Amplificada = Alta_Filtrada * Ganancia_Alta;


wavwrite(Baja_Amplificada,fs,'Bajas');
wavwrite(Banda1_Amplificada,fs,'Banda1');
wavwrite(Banda2_Amplificada,fs,'Banda2');
wavwrite(Banda3_Amplificada,fs,'Banda3');
wavwrite(Alta_Amplificada,fs,'Altas');


Audio_Final = Baja_Amplificada + Banda1_Amplificada + Banda2_Amplificada + Banda3_Amplificada + Alta_Amplificada;
%Caja_Final = conv(Audio_Final);
wavwrite(Audio_Final,fs,'Final');
%sound(Audio_Final,fs);

figure(1)
freqz(Baja_Filtro);

