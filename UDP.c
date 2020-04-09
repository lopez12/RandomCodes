/*Servicio de Comunicacion por medio de chat a archivo*/

#include <stdio.h>
#include <stdlib.h>

void uifEscribirDatos (struct schat *chat);

struct schat
{
	unsigned int id;
	unsigned int longitud;
	unsigned char datos[100];

};

int main (void)
{
	FILE *fich;
	struct schat ArregloArchivo[20];
	unsigned char nombre[10]="datos.dat";
	int NumMensajeread = 0;
	int NumMensajewrite = 0;
	int longitud = 0;
	
	fich = fopen(nombre,"w+");
	printf("Fichero: %s -> ", nombre);
	
	if(fich)
		printf(" Fichero Abierto\n");
	else
	{
		printf("Error: Fichero NO Abierto\n");
		return 1;
	}
	

	while(1)
	{
		fich = fopen(nombre,"r+");
		while(!feof(fich))
		{
			fread(&ArregloArchivo[NumMensajeread], sizeof(struct schat),1,fich);
			if(longitud < ArregloArchivo[NumMensajeread].longitud)
					longitud = ArregloArchivo[NumMensajeread].longitud;
			printf("%i",longitud);
		}
		
		if(NumMensajewrite<longitud)
			NumMensajewrite = longitud;
		printf("Mensaje...\n");
		uifEscribirDatos(&ArregloArchivo[NumMensajewrite]);
		longitud++;
		ArregloArchivo[NumMensajewrite].id = 1;
		ArregloArchivo[NumMensajewrite].longitud = longitud;
		fwrite(&ArregloArchivo[NumMensajewrite], sizeof(struct schat),1,fich);
		NumMensajewrite++;
		
		
		NumMensajeread = 0;
		rewind(fich);
		while(NumMensajeread<NumMensajewrite)
		{
			fread(&ArregloArchivo[NumMensajeread], sizeof(struct schat),1,fich);						
			if(ArregloArchivo[NumMensajeread].id == 1)
				printf("Juan Dijo: ");
			else if(ArregloArchivo[NumMensajeread].id == 2)
				printf("Pancho Dijo: ");
			printf("%s \n", ArregloArchivo[NumMensajeread].datos);
			NumMensajeread++;
		}
		fclose(fich);
	}
	if(!fclose(fich))
		printf("Fichero Cerrado\n");
	else
	{
		printf("Error: Fichero NO Cerrado");
		return 1;
	}
	
	return 0;

}

void uifEscribirDatos (struct schat *ArregloArchivo)
{
	unsigned char *plongitud=0;                          //FUNCION UIFESCRIBIRDATOS
	unsigned int counterLong;                            //
	                                                     //
	scanf("%s",ArregloArchivo->datos);                   //Funcion para escribir el mensaje del chat.
	plongitud = ArregloArchivo->datos;                   //Esta funcion recibe una estructura (No el arreglo completo) porque solo es un mensaje
	                                                     //El scan recibe del teclado el mansaje a ser enviado. y con un apuntador me posiciono 
	while(*plongitud)                                    //en la primera posicion de todas las frase ya escritos y movemos el apuntador si hay algo
	{                                                    //y aumentamos un contador llamado counterLong. Asi podremos saber el tamaño exacto de la
		counterLong++;                                   //frase que vamos a enviar. El retorno de la funcion es el tamaño de la frase a enviar. 
		plongitud++;                                     //
	}                                                    //
	                                                     //
	return;									 //
}