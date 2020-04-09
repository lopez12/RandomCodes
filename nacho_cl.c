#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *pcmessage;
	char cmessage[1024]={0};
	char server_reply[2000];
	int  iStringSize = 0 ;
	int  iCheckSumSend = 0;
	int  iCheckSumRecv = 0;
	char *pRecv = 0;
	char *pHandle = 0;
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr(argv[2]);
    server.sin_family = AF_INET;
    servidor.sin_port = htons(atoi(argv[1]));
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
	pcmessage = (char *) malloc(1024);
	pRecv = (char *) malloc(1024);
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , cmessage);
		fflush();
		pcmessage = cmessage;
		
		
		while(*pcmessage)
		{
			iStringSize++;
			iCheckSumSend = *pcmessage + iCheckSumSend;
			pcmessage++;
		}
		
		pcmessage = cmessage;
		pcmessage = pcmessage - 2;
		*pcmessage = 0xAA;
		iCheckSumSend = iCheckSumSend + 0xAA;
		pcmessage++;
		*pcmessage = iStringSize;
		printf("\n Data length: %i ",iStringSize);
		iCheckSumSend = iCheckSumSend + iStringSize;
		while(iStringSize)
		{	
			pcmessage++;
			iStringSize--;
		}
		iCheckSumSend = !iCheckSumSend
		printf("\n CheckSum: %i",iCheckSumSend);
		*pcmessage = iCheckSumSend;
		pcmessage = cmessage;
		pcmessage = pcmessage - 2;
		
         
        //Send some data
        if( write(sock,pcmessage,iStringSize) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( read(sock,pRecv,1024) < 0)
        {
            puts("recv failed");
            break;
        }
		
		pHandle = &pRecv;
			while(*pHandle)
			{
				iCheckSumRecv = *pHandle + iCheckSumRecv;
				pHandle++;
			}
		pHandle = &pRecv;
		pHandle++;
		if(*pHandle == 0x0F)
		{
			printf("OK");
		}
		else if(*pHandle == 0x10) //mota de odiseo 3315725973
		{
			printf("FAIL");
		}
		if(iCheckSumRecv == iCheckSumSend)
		{
			printf("CheckSum correcto");
		}
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    close(sock);
	free(pcmessage);
	free(pRecv);
    return 0;
}