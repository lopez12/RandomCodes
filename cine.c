#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void imprimirSalaA(int SalaA[30]);
void imprimirSalaB(int SalaB[30]);
void delay (int time) ;


int main (void)
{
	int SalaA[30]={0};
	int SalaB[30]={0};
	int espaciosDisponiblesA=30;
	int espaciosDisponiblesB=30;
	char selccionSala=0;
	int numeroDeLugares = 0 ;
	float PrecioTotal;
	
	while(1)
	{
		system("cls");
		imprimirSalaA(SalaA);
		imprimirSalaB(SalaB);
		
		printf("Que lugares pelicula desea ver? (A o B)");
		scanf("%c",&selccionSala);
		switch(selccionSala)
		{
			case 'A':
			printf("Cuantos lugares quiere? (Espacios disponibles %i)",espaciosDisponiblesA);
			scanf("%i",&numeroDeLugares);;
			if(numeroDeLugares<=espaciosDisponiblesA)
			{
				PrecioTotal = numeroDeLugares * 30.5;
				printf("Precio total: %f\n",PrecioTotal);
				while(numeroDeLugares)
				{
					SalaA[espaciosDisponiblesA-1]=1;
					espaciosDisponiblesA--;
					numeroDeLugares--;
				}
				
			}
			else
			{
				printf("Solo quedan: %i \n",espaciosDisponiblesA);
			}
			
			break;
			
			case 'B':
			printf("Cuantos lugares quiere? (Espacios disponibles %i)",espaciosDisponiblesB);
			scanf("%i",&numeroDeLugares);
			if(numeroDeLugares<=espaciosDisponiblesB)
			{
				PrecioTotal = numeroDeLugares * 30.5;
				printf("Precio total: %f \n",PrecioTotal);
				while(numeroDeLugares)
				{
					SalaB[espaciosDisponiblesB-1]=1;
					espaciosDisponiblesB--;
					numeroDeLugares--;
				}
				
			}
			
			else
			{
				printf("Solo quedan: %i \n",espaciosDisponiblesB);
			}
			
			break;
		
		}
		delay(2000);
	}
	return 0;
}

void imprimirSalaA(int SalaA[30])
{
	int x;
	
	printf("Sala A\n");
	for(x=0;x<30;x++)
	{
		if(SalaA[x]==0)
		{
			printf("%c",177);
		}
		else if(SalaA[x]==1)
		{
			printf("%c",120);
		}
		
		if(x==9||x==19||x==29)
		{
			printf("\n");
		}
	}
}

void imprimirSalaB(int SalaB[30])
{
	int x;
	
	printf("Sala B\n");
	for(x=0;x<30;x++)
	{
		if(SalaB[x]==0)
		{
			printf("%c",177);
		}
		else if(SalaB[x]==1)
		{
			printf("%c",120);
		}
		
		if(x==9||x==19||x==29)
		{
			printf("\n");
		}
	}
}

void delay (int time) 
{
	time = time * 1000000;
	while(time)
	{
		time--;
	}	
	
	return;
}

