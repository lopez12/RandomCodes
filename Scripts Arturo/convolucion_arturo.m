a=[1 2 3 4 5 6 7];
b=[0 0 0 0 0 0 0];
A_size= size(a,2);
B_size= size(b,2);
Shifter=zeros(1,B_size+14);
answer=zeros(1,B_size+5);
count=0;
while(count<A_size)
   Shifter(count+A_size+1)=a(count+1);
   count=count+1;
end
position =0;
while(1)
    b=circshift(b,[0,1]);
    NewData=input('Dame el numero de Ns a sacar \n');
    b(1,1)=NewData;
    c=b(end:-1:1);
    count=1;
    while(count<B_size+7)
         answer(count)=c(B_size)*Shifter(count+A_size)+c(B_size-1)*Shifter(count+A_size-1)+c(B_size-2)*Shifter(count+A_size-2)+c(B_size-3)*Shifter(count+A_size-3)+c(B_size-4)*Shifter(count+A_size-4)+c(B_size-5)*Shifter(count+A_size-5)+c(B_size-6)*Shifter(count+A_size-6);
         count=count+1;     
    end 
    answer_matlab=conv(a,b)
    answer
    if(answer_matlab == answer)
       disp('bien');
    end
end
 
