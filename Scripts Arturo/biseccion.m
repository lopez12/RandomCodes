a=20;
b=30;
matriza(11,8)={0};
i=1;
    for i=1:11
        matriza{i,1}=i-1;
        matriza{i,2}=a; %-
        matriza{i,3}=b; %+
        matriza{i,4}=(9.81*a/10)*(1-exp(-10*17/a))-25;
        matriza{i,5}=(9.81*b/10)*(1-exp(-10*17/b))-25;
        c=(a+b)/2;
        matriza{i,6}=c;
        matriza{i,7}=velocidad(c);
        if (matriza{i,7}<0)
            a=c;
        else 
            b=c;           
        end
        if(i>1)
            matriza{i,8}=((matriza{i,6})-(matriza{i-1,6}))*(100/matriza{i,6})
        end
    end
matriza
