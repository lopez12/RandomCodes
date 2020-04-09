#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int OpenClose(int NumPasajeros);
/*Tren electrico que cierra las puertas de los vagones con un numero de pasajeros menor a 30
  'X' significa que esta cerrada la puerta y 'O' cuando esta abierta como los besos y los abrazos
*/
int main(void)
{
	int tren[15]={0};
	int i;
	int n;
	
	for(i=0;i<15;i++)
	{
		n = rand()%100;
		tren[i]=OpenClose(n);
		if(tren[i])
		{
			printf("O");
		}
		else
		{
			printf("X");
		}
	}
	
	return 0;
}

int OpenClose(int NumPasajeros)
{
	if(NumPasajeros>30)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}