#include<stdio.h>
#include<conio.h>
#include<windows.h>

void pintar(int lugares[25]);

int main (void)
{
	int lugares[25]={0};
	int seleccionlugar;
	int tipodecajon;
	int i;
	int contadorlugarminus=0;
	int contadorlugarnormal=0;
	int seleccionentradasalida;
	float tiempo;
	float dinero;
	int cajon=0;
	
	for(;;)
	{
		printf("1.-Entrada   2.- Salida\n");
		seleccionentradasalida=getch();
		
		if(seleccionentradasalida==49)
		{
			printf("\nSelecciona el tipo de cajon \n1.-Normal   2.- Minusvalidos\n");
			tipodecajon=getch();
			if(tipodecajon==50)		//porque es el valor caracter de 2 ASCII
			{
				for(i=4;i<25;i++)
				{
					if(lugares[i]==0)
					{
						printf("El proximo lugar disponible es el cajon: %i", i);
						lugares[i]=1;
						break;
					}
					else
					{
						contadorlugarminus++;
					}
					i=i+4;
				}
				if(contadorlugarminus==5)
				{
					printf("No hay lugares de minusvalidos disponibles");
				}
			}
			else if(tipodecajon==49)
			{
				for(i=0;i<25;i++)
				{
					if(lugares[i]==0)
					{
						printf("El proximo lugar disponible es el cajon: %i", i);
						lugares[i]=1;
						break;
					}
					else
					{
						contadorlugarnormal++;
					}
				}
				if(contadorlugarnormal)
				{
					printf("No hay lugares de normales disponibles");
				}
			}
		}
		
		else if(seleccionentradasalida==50)
		{
			printf("Que cajon usaste?");
			scanf("%i",&cajon);
			printf("Cuanto tiempo estuviste?");
			scanf("%f",&tiempo);
			if(cajon==4||cajon==9||cajon==14||cajon==19||cajon==24)
			{
				dinero=tiempo*7;
			}
			else
			{
				dinero=tiempo*12;
			}
			lugares[cajon]=0;
			
			printf("Debes: %f",dinero);
			Sleep(1000);
		}
		
		pintar(lugares);
		
	}
	return 0;
}

void pintar(int lugares[25])
{
	int i;
	system("cls");
	gotoxy(1,1);
	for(i=0;i<25;i++)
	{
		if(lugares[i]==1)
		{	
			textcolor( LIGHTRED );
			cprintf("%c",2);
		}
		else
		{
			textcolor( WHITE  );
			cprintf("%c",2);
		}
	}
}