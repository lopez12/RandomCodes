
function Ans=Matrix_Multiplication_Arturo(a,b)
[row1,col1]=size(a);
[row2,col2]=size(b);
if row1==col1
    disp('A es Cuadrada');
        if row2==col2
            disp('B es Cuadrada');
                if row1 == row2
                    [Ans]=zeros(row1);
                    for rowa = 1:row1
                         for colb = 1:col2
                             for cola = 1:col1
                             Ans(rowa,colb)=Ans(rowa,colb)+a(rowa,cola)*b(cola,colb) ; 
                              end
                         end
                    end
                else
                    disp('A y B no son del mismo valor');
                end
        else
            disp('B no es Cuadrada');
        end
    
else
    disp('A no es Cuadrada');
end
