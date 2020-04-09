#include<stdio.h>
#include<conio.h>

int CotaDerecha (int Byte[8]);
int CotaIzquierda (int Byte[8]);
void IngresarBits (int Byte[8]);


int main(void)
{
	int Byte[8]={0};
	char Lado;
	int corrimiento;
	int cota;
	int i;
	
	IngresarBits (Byte);
	printf("Corrimeinto a la Izquierda (I) o Derecha (D)? ");
	Lado = getch();
	printf("Cuantos lugares desea recorrer? ");
	scanf("%i", &corrimiento);
	
	
	
	if(Lado == 68) //68 es D
	{
		cota = CotaDerecha(Byte);
		if(corrimiento>cota)
		{
			printf("Corrimiento Invalido");
			return 0;
		}
		for(;cota>2;cota--)
		{
			for(i=0;i<7;i++)
			{
				Byte[i]=Byte[i+1];
			}
		}
		Byte[7]=0;
	}
	else if (Lado == 73) //73 es I
	{
		cota = CotaIzquierda(Byte);
		if(corrimiento>cota)
		{
			printf("Corrimiento Invalido");
			return 0;
		}
		for(;cota>2;cota--)
		{
			for(i=7;i>0;i--)
			{
				Byte[i]=Byte[i-1];
			}
		}
		Byte[0]=0;
	}
	
	for(i=7;i>=0;i--)
	{
		printf("%i",Byte[i]);
	}
	return 0;
	
}

int CotaIzquierda (int Byte[8])
{
	int i;
	int Ultimouno = 0;
	for(i=0;i<8;i++)
	{
		if(Byte[i]==1)
		{
			Ultimouno = i;
		}
	}
	
	return Ultimouno;
}

int CotaDerecha (int Byte[8])
{
	int i;
	int Primeruno;
	for(i=0;i<8;i++)
	{
		if(Byte[i]==1)
		{
			Primeruno = i;
			return Primeruno;
		}
	}
	
	return -1;
}

void IngresarBits (int Byte[8])
{
	int i;
	
	for(i=0;i<8;i++)
	{
		printf("Ingresa el bit %i ", i);
		scanf("%i",&Byte[i]);
	}
}