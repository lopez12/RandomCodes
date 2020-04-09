clear all;
a1=0;
b1=0;
c1=0;
d1=0;

a2=0;
b2=0;
c2=0;
d2=0;

a3=0;
b3=0;
c3=0;
d3=0;

a4=0;
b4=0;
c4=0;
d4=0;

resultado=0;
decision=0;
variables=0;
n =0;
while n==0
    disp ('¿Qué desea hacer?');
    disp ('Para SUMAR presione la tecla 1');
    disp ('Para RESTAR presione la tecla 2');
    disp ('Para MULTIPLICAR presione la tecla 3');
    disp ('Para DIVIDIR presione la tecla 4');
    disp ('Para RESOLVER UNA ECUACIÓN DE LA FORMA ax^2+bx+c=d presione la tecla 4');
    disp ('Para RESOLVER MATRICES DE "N*N" presione la tecla 5');
    disp ('Para SALIR presione la tecla 0');
    decision = input('decida');
    if decision >= 0
        disp ('¿Cuantas variables tiene tu operación? (Hasta 16 vars.');
        variable = input ('Vars:');
        while variable >= 2
            variable = variable -1
            disp ('inserte sus variables');
            a1=input('a1:');
            b1=input('b1:');
            c1=input('c1:');
            d1=input('d1:');
            
            a2=input('a2:');
            b2=input('b2:');
            c2=input('c2:');
            d2=input('d2:');
            
            a3=input('a3:');
            b3=input('b3:');
            c3=input('c3:');
            d3=input('d3:');
            
            a4=input('a4:');
            b4=input('b4:');
            c4=input('c4:');
            d4=input('d4:');
            
            resultado= a1 + b1 + c1 + d1 + a2 + b2 + c2 + d2 + a3 + b3 + c3 + d3;
            disp(resultado);
            
        end
    end
end
