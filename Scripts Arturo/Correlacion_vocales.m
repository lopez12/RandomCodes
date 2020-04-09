[A,Fa]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_A.wav');
[E,Fe]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_E.wav');
[I,Fi]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_I.wav');
[O,Fo]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_O.wav');
[U,Fu]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_U.wav');
TamA=length(A);
TamE=length(E);
TamI=length(I);
TamO=length(O);
TamU=length(U);
Punto_maximoA = 0;
Punto_maximoE = 0;
Punto_maximoI = 0;
Punto_maximoO = 0;
Punto_maximoU = 0;
Punto_maximo_Audio = 0;

Punto_maximoA1 = 0;
Punto_maximoA2 = 0;
Punto_maximoA_Max = 0;
Punto_maximoE1 = 0;
Punto_maximoE2 = 0;
Punto_maximoE_Max = 0;
Punto_maximoI1 = 0;
Punto_maximoI2 = 0;
Punto_maximoI_Max = 0;
Punto_maximoO1 = 0;
Punto_maximoO2 = 0;
Punto_maximoO_Max = 0;
Punto_maximoU1 = 0;
Punto_maximoU2 = 0;
Punto_maximoU_Max = 0;


for n=1:TamI
    if(I(n)>Punto_maximoI)
       Punto_maximoI = I(n);
    end
end
for n=1:TamA
    if(A(n)>Punto_maximoA)
       Punto_maximoA = A(n);
    end
end
for n=1:TamE
    if(E(n)>Punto_maximoE)
       Punto_maximoE = E(n);
    end
end
for n=1:TamO
    if(O(n)>Punto_maximoO)
       Punto_maximoO = O(n);
    end
end
for n=1:TamU
    if(U(n)>Punto_maximoU)
       Punto_maximoU = U(n);
    end
end
A=A/Punto_maximoA;
E=E/Punto_maximoE;
I=I/Punto_maximoI;
O=O/Punto_maximoO;
U=U/Punto_maximoU;


%recObj = audiorecorder;
%disp('Start speaking.')
%recordblocking(recObj, 2);
%disp('End of Recording.');
%Audio_Got = getaudiodata(recObj);
%TamAudio = length(Audio_Got);
%for n=1:TamAudio
   % if(Audio_Got(n)>Punto_maximoI)
  %     Punto_maximo_Audio = Audio_Got(n);
 %   end
%end
%Audio_Got = Audio_Got/Punto_maximo_Audio;
[Audio_Got,Fu]=wavread('C:\Users\Arturo\Desktop\Scripts Arturo\Vocal_E.wav');


CorrelacionA=xcorr(Audio_Got,A);
CorrelacionE=xcorr(Audio_Got,E);
CorrelacionI=xcorr(Audio_Got,I);
CorrelacionO=xcorr(Audio_Got,O);
CorrelacionU=xcorr(Audio_Got,U);
TamA=length(CorrelacionA);
TamE=length(CorrelacionE);
TamI=length(CorrelacionI);
TamO=length(CorrelacionO);
TamU=length(CorrelacionU);

for n=1:13000
    if(CorrelacionA(n)>Punto_maximoA1)
       Punto_maximoA1 = CorrelacionA(n);
    end
end
for n=20000:TamA
    if(CorrelacionA(n)>Punto_maximoA2)
       Punto_maximoA2 = CorrelacionA(n);
    end
end
for n=1:TamA
    if(CorrelacionA(n)>Punto_maximoA_Max)
       Punto_maximoA_Max = CorrelacionA(n);
    end
end
if(Punto_maximoA_Max > Punto_maximoA1+Punto_maximoA2)
    disp('La letra es A')
end

for n=1:13000
    if(CorrelacionE(n)>Punto_maximoE1)
       Punto_maximoE1 = CorrelacionE(n);
    end
end
for n=20000:TamE
    if(CorrelacionE(n)>Punto_maximoE2)
       Punto_maximoE2 = CorrelacionE(n);
    end
end
for n=1:TamE
    if(CorrelacionE(n)>Punto_maximoE_Max)
       Punto_maximoE_Max = CorrelacionE(n);
    end
end
if(Punto_maximoE_Max > Punto_maximoE1+Punto_maximoE2)
    disp('La letra es E')
end

for n=1:13000
    if(CorrelacionI(n)>Punto_maximoI1)
       Punto_maximoI1 = CorrelacionI(n);
    end
end
for n=20000:TamI
    if(CorrelacionI(n)>Punto_maximoI2)
       Punto_maximoI2 = CorrelacionI(n);
    end
end
for n=1:TamI
    if(CorrelacionI(n)>Punto_maximoI_Max)
       Punto_maximoI_Max = CorrelacionI(n);
    end
end
if(Punto_maximoI_Max > Punto_maximoI1+Punto_maximoI2)
    disp('La letra es I')
end

for n=1:13000
    if(CorrelacionO(n)>Punto_maximoO1)
       Punto_maximoO1 = CorrelacionO(n);
    end
end
for n=20000:TamO
    if(CorrelacionO(n)>Punto_maximoO2)
       Punto_maximoO2 = CorrelacionO(n);
    end
end
for n=1:TamO
    if(CorrelacionO(n)>Punto_maximoO_Max)
       Punto_maximoO_Max = CorrelacionO(n);
    end
end
if(Punto_maximoO_Max > Punto_maximoO1+Punto_maximoO2)
    disp('La letra es O')
end

for n=1:13000
    if(CorrelacionU(n)>Punto_maximoU1)
       Punto_maximoU1 = CorrelacionU(n);
    end
end
for n=20000:TamU
    if(CorrelacionU(n)>Punto_maximoU2)
       Punto_maximoU2 = CorrelacionU(n);
    end
end
for n=1:TamU
    if(CorrelacionU(n)>Punto_maximoU_Max)
       Punto_maximoU_Max = CorrelacionU(n);
    end
end
if(Punto_maximoU_Max > Punto_maximoU1+Punto_maximoU2)
    disp('La letra es U')
end

    

    