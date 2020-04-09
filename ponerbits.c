#include<stdio.h>


ponerbits(unsigned char x, unsigned char y, int n, int p);

int main(void)
{
unsigned char x,y;
int n,p;

	
	printf("\t\tPRACTICA DE BITS\n\n");

printf("\nIngresa n:");
scanf("%i",&n);
printf("Ingresa p:");
scanf("%i",&p);
printf("Ingresa el numero y:");
fflush(stdin);
scanf("%x",&y);
ponerbits(x,y,n,p);

return 0;
}

int ponerbits(unsigned char x,unsigned char y, int n, int p)
{
unsigned char mask=0,var,maskaux;
int c;

printf("Ingresa el numero x:");
fflush(stdin);
scanf("%x",&x);

for(c=0;c<n;c++)
{
mask|=1<<c;
}


var=y&mask;


var=var<<(p-n);


mask=mask<<(p-n);


mask=~mask;

x=(mask&x);


x=var|x;
printf("\n%x",x);

return x;
}















