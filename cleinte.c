#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>        


#define MAXDATASIZE 100   
/* El número máximo de datos en bytes */

int main(int argc, char *argv[])
{
   int fd, numbytes;       
   /* ficheros descriptores */

   char *pCadena;  
   
   char buf[MAXDATASIZE];
   /* en donde es almacenará el texto recibido */

   struct hostent *he;         
   /* estructura que recibirá información sobre el nodo remoto */

   struct sockaddr_in server;  
   /* información sobre la dirección del servidor */

	if (argc !=3) { 
      /* esto es porque nuestro programa sólo necesitará un
      argumento, (la IP) */
      printf("Uso: %s <Dirección IP>\n",argv[0]);
      exit(-1);
   }

   if ((he=gethostbyname(argv[1]))==NULL){       
      /* llamada a gethostbyname() */
      printf("gethostbyname() error\n");
      exit(-1);
   }

   if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){  
      /* llamada a socket() */
      printf("socket() error\n");
      exit(-1);
   }
	
   server.sin_family = AF_INET;
   server.sin_port = htons(atoi(argv[2])); 
   server.sin_addr = *((struct in_addr *)he->h_addr);

   if(connect(fd, (struct sockaddr *)&server,
      sizeof(struct sockaddr))==-1){ 
      /* llamada a connect() */
      printf("connect() error\n");
      exit(-1);
   }
   
   pCadena = (char *) malloc(1024);
	for(;;)
	{
		
		if ((numbytes=recv(fd,buf,MAXDATASIZE,0)) == -1)
		{  
			/* llamada a recv() */
			printf("Error en recv() \n");
			exit(-1);
		}
		
		buf[numbytes]='\0';
		
		printf("Dame una frase");
		pCadena = gets(stdin);
		
		printf("Mensaje del Servidor: %s\n",buf); 
		write(fd,pCadena,1024);
		
		
		close(fd);   /* cerramos fd =) */
	}
}