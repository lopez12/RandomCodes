MResultado(11,6)={0};
counter = 1;
x=0.227;
non=1;
signo = 1;
SumRes=0;
for counter=1:11
    MResultado{counter,1}= counter;
    MResultado{counter,2}= signo*((x^non)/(factorial(non)));
    SumRes =  MResultado{counter,2} + SumRes;
    non = non + 2;
    signo = -signo;
    MResultado{counter,3}= SumRes;
    MResultado{counter,4}= sin(x) - SumRes;
    MResultado{counter,5}= (MResultado{counter,4}*100)/(sin(x));
    if(counter > 1)
        MResultado{counter,6}= SumRes - MResultado{(counter-1),3};
    end
end