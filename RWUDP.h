#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void WriteMessage (struct sUDP *protocol);

struct sUDP
{
	unsigned int length;
	unsigned char ipOrigin[19]; 
	unsigned char ipDestiny[19];
	unsigned char datos[100];

} ;


void WriteMessage (struct sUDP *protocol)
{
	unsigned int length=0;
	unsigned char *pIPDatos;
	
	printf("Ingresa IP destino: ");
	scanf("%s",&protocol->ipDestiny);

	
	printf("Ingresa el Mensaje: ");
	scanf("%s",&protocol->datos);

	pIPDatos = protocol->datos;
	
	while(*pIPDatos)
	{	
		length++;
		pIPDatos++;
	}
	
	protocol->length = length;
}

void ReadMessage (struct sUDP *protocol,unsigned int Validation)
{
	unsigned int length;
	unsigned char *pData;
	
	if(Validation)
	{	
		
		length = protocol->length;
		pData = protocol->datos;
		while(length)
		{
			printf("%c",*pData);
			pData++;
			length--;
		}
		printf("\n");
	}
	else{
		printf("IP Incorrecta");
	}
}
