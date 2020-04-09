
#include "RWUDP.h"
#include "ValidationIP.h"


struct sUDP protocolSend;

int main (void)
{
	FILE *fichero;
	unsigned char ClienteServidor = 0;
	unsigned int Valid = 0;
	
	fichero = fopen( "protocolo.udp", "r+" );
	if( fichero )
		printf( "Fichero Creado\n" );
	else
	{
		printf( "Error \n" );
		return 1;
	}
	fclose(fichero);
	
	printf("Cliente o Servidor? (C/S): ");
	scanf("%c",&ClienteServidor);
	if(ClienteServidor=='S'||ClienteServidor=='s')
	{
		while(1)
		{
			fclose(fichero);
			WriteMessage(&protocolSend);
			fichero = fopen( "protocolo.udp", "r+b");
			fwrite(&protocolSend, sizeof(struct sUDP),1,fichero);
			fclose(fichero);
			fichero = fopen( "protocolo.udp", "r+b");
			Valid = Validation(&protocolSend);
			ReadMessage(&protocolSend,Valid);
			fclose(fichero);
		}
	}
	else if(ClienteServidor=='C'||ClienteServidor=='c')
	{
		while(1)
		{	
			fclose(fichero);
			fichero = fopen( "protocolo.udp", "r+b");
			Valid = Validation(&protocolSend);
			ReadMessage(&protocolSend,Valid);
			fclose(fichero);
			ReadMessage(&protocolSend,Valid);
			
		}
	}
	
	
	
	
	return 0;
}


