clear;
clc; 
for n=1:20
f(n)=1000*n;
end
for j=1:20
    for n=2000:11000
        seno(j,n)=sin(n*f(j));
    end
end
SumatoriaSin=zeros(1,11000);
for n=2000:11000
    for j=1: 20
         SumatoriaSin(n) = seno(j,n)+SumatoriaSin(n);
    end
end
length(SumatoriaSin)
plot(SumatoriaSin)

for n=3000:4500
if(SumatoriaSin(n)>SumatoriaSin(n+1));
maximo=SumatoriaSin(n+1);
end
end

SerialHandler = serial('COM6');
fopen(SerialHandler);
for n=3000:4500
    %b(1,1) = input('Introduce el siguiente valor ','s')-48; 
    
    %fprintf(SerialHandler,b(1,1));
    
fprintf(SerialHandler,SumatoriaSin(n)/maximo);
l=fgetl(SerialHandler)
end
fclose(SerialHandler);
                                                                                                        