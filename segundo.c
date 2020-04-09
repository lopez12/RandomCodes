/*Ahora sin estructuras porque astrid dice que asi no*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void EscribirDatos (struct schat *ArregloArchivo, FILE *fich);
void LeerDatos (struct schat *chat, FILE *fich,unsigned int NumStructs);

struct schat
{
	unsigned int id;
	unsigned int longitud;
	unsigned char datos[100];

};

int main (void)
{
	FILE *fich;
	unsigned char nombre[10]="chat.dat"; 			//variable de control solo para no escribir el nombre varias veces
	struct schat chat ;
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
	
	while(1)
	{
		chat.id = 2;
		LocalNumStructs = 0;
		printf("Mensaje...\n");
		gotoxy(15,15);
		scanf("%s",chat.datos); 
		fflush(stdin);
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
				if(chat.id == 1)
					printf("Juan dijo: ");
				else if(chat.id == 2)
					printf("Pancho dijo: ");
			printf("%s\n",chat.datos);
			LocalNumStructs++;
		}
		
			
	}

	return 0;
}

void EscribirDatos (struct schat *chat, FILE *fich)
{
	
	printf("Mensaje...\n");
	scanf("%s",chat->datos); 
	fich = fopen( "chat.dat", "a+");
	fwrite(&chat, sizeof(struct schat),1,fich);
	fclose(fich);
	
	printf("Mensaje...\n");
	scanf("%s",chat->datos); 
	fich = fopen( "chat.dat", "a+");
	fwrite(&chat, sizeof(struct schat),1,fich);
	fclose(fich);
	
	printf("Mensaje...\n");
	scanf("%s",chat->datos); 
	fich = fopen( "chat.dat", "a+");
	fwrite(&chat, sizeof(struct schat),1,fich);
	fclose(fich);
	
}

void LeerDatos (struct schat *chat, FILE *fich,unsigned int NumStructs)
{
	fich = fopen( "chat.dat", "r+");
	rewind( fich );
	fread( &chat, sizeof(struct schat), 1, fich );
	printf ("%s\n", chat->datos);
}