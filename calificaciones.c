#include<stdio.h>
#include<stdlib.h>

float Promedio(int Nombre,int Cali [20][3]);
void imprimetodo (char Nombre[20], int Cali[20][3]);
void aprobados (float promedios[20],char Nombre[20]);
void reprobados (float promedios[20],char Nombre[20]);

int main (void)
{
	char Nombre[20]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
	int Cali[20][3]={0};
	float promedios[20]={0};
	int i,alumn;
	
	for(alumn=0;alumn<20;alumn++)
	{
		printf("Llena las calificaciones del alumno: %i\n", alumn+1);
		for(i=0;i<3;i++)
		{
			printf("Parcial: ", i+1);
			scanf("%i",&Cali[alumn][i]);
		}
	}
	
	for(i=0;i<20;i++)
	{
		promedios[i]=Promedio(i,Cali);
	}
	
	aprobados(promedios,Nombre);
	reprobados(promedios,Nombre);
	
	return 0;
}

float Promedio(int Nombre,int Cali [20][3])
{
	float promedio=0;
	
	promedio = Cali[Nombre][2]+Cali[Nombre][1]+Cali[Nombre][0];
	
	promedio = promedio/3;
	
	return promedio;
}

void imprimetodo (char Nombre[20], int Cali[20][3])
{
	int i;
	
	for(i=0;i<20;i++)
	{
		printf("Nombre: %c Primer Parcial: %i, Segundo: %i, Tercero: %i\n",Nombre[i],Cali[i][0],Cali[i][1],Cali[i][2]);
	}
}

void aprobados (float promedios[20],char Nombre[20] )
{
	int i;
	
	for(i=0;i<20;i++)
	{
		if(promedios[i]>59)
		{
			printf("Nombre: %c esta aprobado con: %f\n",Nombre[i],promedios[i]);
		}
	}
}

void reprobados (float promedios[20],char Nombre[20] )
{
	int i;
	
	for(i=0;i<20;i++)
	{
		if(promedios[i]<=59)
		{
			printf("Nombre: %c esta reprobado con: %f\n",Nombre[i],promedios[i]);
		}
	}
}