#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main (void)
{

	int Random_NUM[15],Array1[5],Array2[5],Array3[5];
	int i;
	int coordenada[2];
	randomize();
	for(i=0;i<15;i++)
	{
		Random_NUM[i]=random(25)+1;
	}
	i=0;
	for(i=0;i<5;i++)
	{
		Array1[i] = Random_NUM[i];
	}
	for(i=5;i<10;i++)
	{
		Array2[i-5] = Random_NUM[i];
	}
	for(i=10;i<15;i++)
	{
		Array3[i-10] = Random_NUM[i];
	}
	system("cls");
	
	for(i=0;i<5;i++)
	{
		printf("Adivina la coordenada x: ");
		scanf("%i",&coordenada[0]);
		printf("Adivina la coordenada y: ");
		scanf("%i",&coordenada[1]);
		if((coordenada[0] == Array1[0]) && (coordenada[1] == Array2[0]))
		{
			printf("Muy bien eres un DIOS\n");
		}
		else
		{
			printf("Vuelve a intentarlo \n");
		}
	}
	gotoxy(Array1[0],Array2[0]);
	printf("%i \n", Array3[0]);
	return 0;
}