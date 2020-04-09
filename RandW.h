#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EscribirDatos (struct schat *chat,unsigned int *LocalNumStructs);
void LeerDatos (struct schat *chat);

 struct schat
{
	unsigned int id;
	unsigned int longitud;
	unsigned char ipdestino[19];
	unsigned char datos[100];
	unsigned int idDestion;

} ;


void EscribirDatos (struct schat *chat,unsigned int *LocalNumStructs)
{

	unsigned char *pCounter;
	unsigned int Counter=0;
	*LocalNumStructs = 0;
	printf("Mensaje...\n");
	scanf("%s",chat->datos); 
	fflush(stdin);
	pCounter = chat->datos;
	printf("Ip de Destino: ");
	scanf("%s",chat->ipdestino); 
	fflush(stdin);
	if(!strcmp(chat->ipdestino,"1.1.1.1"))
		chat->idDestion = 1;						//aqui
	else if(!strcmp(chat->ipdestino,"2.2.2.2"))
		chat->idDestion = 2;
	
	while(*pCounter)
	{
		pCounter++;
		Counter++;
	}
	
	chat->longitud = Counter;
	
}

void LeerDatos (struct schat *chat)
{
		if(chat->id == 1 && chat->idDestion == 2)
			printf("Astrid dijo a Cesar: %s longitud: %i\n",chat->datos,chat->longitud);
		else if(chat->id == 2 && chat->idDestion == 1)
			printf("Cesar dijo a Astrid: %s longitud: %i\n",chat->datos,chat->longitud);
		
}