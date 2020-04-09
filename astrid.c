#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main(void)
{ 
	int Menu = 0 ;
	int numero[10] = {0};
	int i;
	int Multiplicacion = 1;
	int Suma = 0;
	
	system("cls");
	printf("Menu Opciones \n 1.Ingresar datos \n 2.Multiplicacion\n 3.Suma\n 4.Salir\n\n");
	for(;;)
	{
	Menu = 0;
	system("cls");
	printf("Menu Opciones \n 1.Ingresar datos \n 2.Multiplicacion\n 3.Suma\n 4.Salir\n\n");
	scanf("%i",&Menu);
	switch(Menu)
		{
			case 1:
				printf("Ingresa Datos \n");
				for(i=0; i<10;i++)
				{	printf("Dame el dato %i ",i+1);
					scanf("%i",&numero[i]);
				}
			break;
			
			case 2:
			
				for(i=0; i<10;i++)
				{
					Multiplicacion = numero[i] * Multiplicacion;
					printf("%i * " ,numero[i]);
					
				}
				printf("= %i ", Multiplicacion);
				getch();
			break;
			
			case 3:
				for(i=0; i<10;i++)
				{
					Suma = numero[i] + Suma;
					printf("%i + ", numero[i]);
				}
				printf("= %i ", Suma);
				getch();
			break;
			
			case 4:
				return 0;
			break;
		
			default:
				printf("No valid");
			break;
		}
	}
	return 0;
	
}
