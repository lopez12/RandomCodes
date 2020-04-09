matriz(5,7)={0};
i=1;
xi=20;
xi1=30;

for i=1:5
    matriz{i,1}=i;
    matriz{i,2}=xi;
    matriz{i,3}=xi1;
    matriz{i,4}=velocidad(xi);
    matriz{i,5}=velocidad(xi1);
    matriz{i,6}=fd(xi,xi1);
    if i>1
        matriz{i,7}=(matriz{i,6}-matriz{i-1,6})*100/matriz{i,6};
    else
        matriz{i,7}=0;
    end
    
    xi=xi1;
    xi1=matriz{i,6};
end

matriz