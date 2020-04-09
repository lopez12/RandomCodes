/*Ahora sin estructuras porque astrid dice que asi no*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "RandW.h"
#include "ModuloUser.h"
#include "interface.h"

struct schat chat;

int main (void)
{
	FILE *fich;
	unsigned char nombre[10]="chat.dat"; 			//variable de control solo para no escribir el nombre varias veces
	unsigned int NumStructs = 0;
	unsigned int LocalNumStructs = 0;
	
	
	
	fich = fopen( nombre, "w+" );
	printf( "Fichero: %s -> ", nombre );
	if( fich )
		printf( "creado (ABIERTO)\n" );
	else
	{
		printf( "Error (NO ABIERTO)\n" );
		return 1;
	}
	fclose(fich);
	MainInterface();
	AccessingServer();
	chat.id=UserValidation();
	delay(700);
	system("cls");
	if(chat.id==0)
		return 0;
	
	while(1)
	{
		
		EscribirDatos(&chat,&LocalNumStructs);
		if(!strcmp(chat.datos,"exit"))
			break;;
		fich = fopen( "chat.dat", "r+b");
		fseek(fich, 0, SEEK_END);
		fwrite(&chat, sizeof(struct schat),1,fich);
		NumStructs=ftell(fich)/sizeof(struct schat);
		fclose(fich);
		
		fich = fopen( "chat.dat", "r+b");
		fwrite( &NumStructs, sizeof(unsigned int), 1, fich );
		fclose(fich);
		
		fich = fopen( "chat.dat", "r+b");
		rewind(fich);
		fread( &NumStructs, sizeof(unsigned int), 1, fich );
		fclose(fich);	
		
		system("cls");
		while(LocalNumStructs<NumStructs)
		{
			fich = fopen( "chat.dat", "r+");
			fseek(fich, LocalNumStructs*sizeof(struct schat), SEEK_SET);
			fread(&chat, sizeof(struct schat), 1, fich);
			fclose(fich);
			LeerDatos(&chat);
			LocalNumStructs++;
		}
		
			
	}

	return 0;
}

