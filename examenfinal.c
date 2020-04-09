#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	int fichas[50]={0};
	int i, j=0, k=0,l=0;
	int sopranos[50]={0};
	int tenor[50]={0};
	int baritonos[50]={0};

	for(i=0;i<50;i++)
	{
		printf("Frecuencia de el concursante numero: %i",i);
		scanf("%i",&fichas[i]);
		if(fichas[i]>0&&fichas[i]<100)
		{
			sopranos[j] = i;
			j++;
		}
		else if(fichas[i]>101&&fichas[i]<200)
		{
			tenor[k] = i;
			k++;
		}
		else if(fichas[i]>201&&fichas[i]<300)
		{
			baritonos[l] = i;
			l++;
		}
	}
	for(i=0;i<50;i++)
	{
		printf("Los sopranos fueron la ficha: %i \n", sopranos[i]);
	}
	for(i=0;i<50;i++)
	{
		printf("Los tenores fueron la ficha: %i \n", tenor[i]);
	}
	for(i=0;i<50;i++)
	{
		printf("Los baritonos fueron la ficha: %i \n", baritonos[i]);
	}
	
	
	return 0;
}