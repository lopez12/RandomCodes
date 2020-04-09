#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5558

void*  SocketHandler (void* argv);


typedef struct {
        pthread_mutex_t mutex1;
        pthread_mutex_t mutex2;

}Mutex_create;



int count=0;
int main (void)
{
		int sock_sd;
        int socket_cl;
        struct sockaddr_in servidor;
        struct sockaddr_in client;
        int sin_size;
        

		sock_sd = socket(AF_INET, SOCK_STREAM, 0);
        servidor.sin_family = AF_INET;
        servidor.sin_port = htons(PORT);
        servidor.sin_addr.s_addr = INADDR_ANY;
        bzero(&(servidor.sin_zero),8);
        bind(sock_sd,(struct sockaddr*)&servidor,sizeof(struct sockaddr));
        listen(sock_sd,0);
        sin_size=sizeof(struct sockaddr_in);
        


        pthread_t ID;
        Mutex_create My_Mutex;
        pthread_mutex_init(&My_Mutex.mutex1,NULL);
        pthread_mutex_init(&My_Mutex.mutex2,NULL);
        

        for(;;)
        {
		
		if ((socket_cl = accept(sock_sd,(struct sockaddr *)&client,&sin_size))<0) 
		{
			printf("error en accept()\n");
			exit(-1);
			}
		else 
		{
			printf("Se obtuvo una conexión desde %s\n",inet_ntoa(client.sin_addr) );
			pthread_create(&ID, NULL, &SocketHandler, (void*)socket_cl);
		}

      
		
		
        }
		
return 0;
}
void*  SocketHandler (void* socket_cl )
{
		int NumChar;
		int *socket_server = (int *)socket_cl;
		char *pCadena;
		char beto[1024]={0};
		
		fflush(stdin);
		fflush(stdout);
		 
		 pCadena = (char *) malloc(beto[1024]);
		
        for(;;)
        {

               NumChar=read(socket_server,pCadena,1024);
               printf("%i\n",NumChar);
               write(socket_server,pCadena,NumChar);
			   if(NumChar == 0)
				{
					close(socket_server); 
					free(pCadena);
					pthread_exit(SocketHandler);
				}

         }
	    
		
		 
return;
}
