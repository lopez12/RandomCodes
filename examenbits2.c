#include<stdio.h>
void BitCoding(unsigned char *Nombre);
void ASCIItoBit(unsigned char Letra);

int main (void)
{
	
	BitCoding("ELENA");
	return 0;
}

void BitCoding(unsigned char *Nombre)
{
	while(*Nombre)
	{
		ASCIItoBit(*Nombre);
		printf("= %c \n",*Nombre);
		Nombre++;
	}
}

void ASCIItoBit(unsigned char Letra)
{
	int corrimiento=1;
	Letra = Letra - 64;
	while(corrimiento<32)
	{
		
		if(Letra&corrimiento)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		corrimiento<<=1;
	}
}