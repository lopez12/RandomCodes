a(11,6)={0};
non=1;
x=.227;
signo=1;
columna2=0;
non=1;
signo=1;
anterior=0;
for cont=1:11
a{cont,1}=cont-1;
a{cont,2}=(signo*(x^non)/(factorial(non)));
non=non+2;
signo=-signo;
a{cont,3}=a{cont,2}+anterior;%sumatoria
anterior=a{cont,3};
a{cont,4}=sin(x)-a{cont,3};%error verdadero
a{cont,5}=(a{cont,4}/sin(x))*100; % %error verdadero
if(cont>1)
a{cont,6}=(a{cont,3}-a{(cont-1),3})*(100/a{cont,3});%%error aproximado
end
end
a