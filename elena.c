#include<stdio.h>
#include <stdlib.h> 
//Inicio del Tercer Codigo MACROS
#define FALSE 0
#define TRUE 1
#define HEXANUMBER(x) ((x) > 16 ? (FALSE) : (TRUE))
//Fin del tercer codigo MACROS
struct time 
{
	int horas;
	int minutos;
	int segundos;
};

struct datetime 
{
	int dia;
	int mes;
	int ano;
	struct time tiempo;
};

int NumeroVocales (char *pCadena, char letra); //Funcion del Segundo codigo

int main (void)
{
	int vocales=0;
	
	struct datetime *pDia;
	
	
	
	//Inicio del primer Codigo
	unsigned char ValorConEdad=4;
	ValorConEdad = ValorConEdad<<4;
	ValorConEdad = ValorConEdad + 19;
	printf("%i\n",ValorConEdad);
	//Fin del primer codigo
	
	//Inicio Del segundo Codigo
	vocales = NumeroVocales ("HolaSOYElena", 'a');
	printf("%i\n",vocales);
	//Fin del segundo codigo
	
	//Inicio impresion del tercer codigo
	printf("1 es un numero hexa? %i",HEXANUMBER(0XA));
	//Fin impresion del tercer codigo
	
	//Inicio del cuarto codigo
	pDia = (struct datetime *) malloc (1);
	printf("Dia: ");
	scanf("%i",&pDia->dia);
	printf("Mes: ");
	scanf("%i",&pDia->mes);
	printf("Año: ");
	scanf("%i",&pDia->ano);
	printf("Hora: ");
	scanf("%i",&pDia->tiempo.horas);
	printf("Minutos: ");
	scanf("%i",&pDia->tiempo.minutos);
	printf("Segundos: ");
	scanf("%i",&pDia->tiempo.segundos);
	
	
	printf("%i/%i/%i    %i:%i:%i\n",pDia->dia,pDia->mes,pDia->ano,pDia->tiempo.horas,pDia->tiempo.minutos,pDia->tiempo.segundos);

	free (pDia);
	//Fin del cuarto codigo
	
	return 0;
}

//Segundo Codigo
int NumeroVocales (char *pCadena, char letra)
{
	int VocalesCounter = 0;
	while(*pCadena)
	{
		if((*pCadena)=='a'||(*pCadena)=='e'||(*pCadena)=='i'||(*pCadena)=='o'||(*pCadena)=='u'||(*pCadena)=='A'||(*pCadena)=='E'||(*pCadena)=='O'||(*pCadena)=='I'||(*pCadena)=='U')
		{
			VocalesCounter++;
		}
		pCadena++;
	}

	return VocalesCounter;
}