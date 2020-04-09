/*
    C socket server example
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
    int counter_data = 0;
    int used_data[9] = {0};
    int data_space = 0;
    char income_stringe[50];
    int r;
    const int variables[9] = {11,12,13,21,22,23,31,32,33};

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 6000 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
         while(1)
{

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
 
	int randomm;
	randomm=rand()%8;
	printf("%i",variables[randomm]);
	read_size = 1;
    //Receive a message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
		
	counter_data++;
	
		//Send the message back to client
		//printf("%s",client_message);
		
		used_data[data_space] = strtol(client_message,NULL, 10);
		data_space++;
		sprintf(income_stringe,"%d",variables[randomm]);
		write(client_sock , income_stringe , strlen(client_message));
	
    }
}
     
    if(read_size == 0 && counter_data%2)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
    return 0;
}
