#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main(void)
{
	int RandomNum[20]={0};
	int Menu = 0;
	int i = 0;
	int NumeroMayor,NumeroMenor;
	
	printf("1.- Mostrar TODO \n 2.- Mostrar posiciones pares \n 3.- Mostrar posiciones impares \n 4.- Calcular el MAYOR y el MENOR \n 5.- Salir \n");
	scanf("%i",&Menu);
	randomize();
	for(i=0;i<20;i++)
	{
		RandomNum[i]=random(20);
	}
	
	switch(Menu)
	{
		case 1:
			for(i=0;i<20;i++)
			{
				printf("%i ",RandomNum[i]);
			}
		break;
		
		case 2:
			for(i=0;i<20;i++)
			{
				printf("%i ",RandomNum[i]);
				i++;
			}
		break;
		
		case 3:
			for(i=1;i<20;i++)
			{
				printf("%i ",RandomNum[i]);
				i++;
			}
		break;
		
		case 4:
			for(i=0;i<18;i++)
			{
				if((RandomNum[i] > RandomNum[i+1])&&(NumeroMenor > RandomNum[i]))
				{
					NumeroMenor = RandomNum[i];
				}
				
				if((RandomNum[i] < RandomNum[i+1])&&(NumeroMayor < RandomNum[i]))
				{
					NumeroMayor = RandomNum[i];
				}
				
			}
			
			printf("El Numero Mayor es :%i ",NumeroMayor);
			printf("El Numero Menor es :%i ",NumeroMenor);
		break;
		
		case 5:
			printf("Adios Guapo ;)");
			return 0;
		break;
		
		
		
	}
	
return 0;
}