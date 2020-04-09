#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mqueue.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>


#define PROMPT			("\n\rWhat do you want your message to say? ")
uint8_t bfnDataLengthMSB(uint16_t wframe);
uint8_t bfnDataLengthLSB(uint8_t  bframe);
uint8_t CalculateChecksum(uint8_t * Frame, uint16_t FrameSize);

int main(int argc, char * argv[])
{
	uint8_t * Command;
	uint8_t MSB;
	uint8_t LSB;
	uint8_t SOF = 0xAA;
	uint8_t CS;
	uint8_t * bDataToSend; 
	uint8_t * bReadData;
	uint32_t ServerPort;
	struct sockaddr_in SocketSettings;
	int32_t ClientSocket;
	uint16_t counter = 0;
	//int8_t * DataRecieved;
	int32_t Status;
	
	ServerPort = atoi(argv[2]);
	
    SocketSettings.sin_family = AF_INET;
	SocketSettings.sin_port = htons(ServerPort);
	SocketSettings.sin_addr.s_addr = inet_addr(argv[1]);
	
	ClientSocket = socket(AF_INET, SOCK_STREAM, 0);

	Status = connect(ClientSocket, (struct sockaddr *)&SocketSettings,sizeof(struct sockaddr));
    printf("\n %i\n", Status);
	
	
    while(1)
    {
        
        Command = (uint8_t*)readline(PROMPT);
        printf("\n the message send was %s \n",(char *)Command);
        printf("with %i charecteres \n",strlen((char *)Command));
        MSB = bfnDataLengthMSB(strlen((char*)Command));
		LSB = bfnDataLengthLSB(strlen((char*)Command));
		printf("%i  msb  ",MSB);
		printf("%i lsb ",LSB);
		
		
		
		bDataToSend =(uint8_t*)malloc(strlen((char *)Command)+4);
		bDataToSend[0] = SOF;
		bDataToSend[1] = MSB;
		bDataToSend[2] = LSB;
		memcpy((char *)&bDataToSend[3],(char *)Command,strlen((char *)Command));
		
		CS = CalculateChecksum(bDataToSend,(uint16_t)(strlen((char *)Command)+3));
		
		bDataToSend[3+strlen((char *)Command)] = CS;/*chesum*/
		
		printf("\n frame to send ");
		for(; counter != 3;counter++;)
		{
			printf("%x ",bDataToSend[counter]);
		}
		counter = 3;
		for(; counter != 3;counter++;)
		{
			printf("%c ",bDataToSend[counter]);
		}
		printf( "%x ",bDataToSend[3+strlen((char *)Command)]);
		printf("\n");
		
		counter= 0;
		
		write(ClientSocket,bDataToSend,strlen((char *)Command)+4);
		free(bDataToSend);
		bReadData = (uint8_t*)malloc(3);
		read(ClientSocket, bReadData,3);
		
	printf("%x- %x -%x \n\r",bReadData[0],bReadData[1],bReadData[2]);
		if(bReadData[2] != CalculateChecksum((uint8_t*)bReadData,2))
		{
			printf("%x\n\r",CalculateChecksum((uint8_t*)bReadData,2));
			printf("CheckSum does not match");
		}
		else
		{
			if(bReadData[1] != 0x0F)
			{
				printf("Wrong Data");
			}
		}
		free(bReadData);
        
    }

    return 0;
}

uint8_t bfnDataLengthLSB(uint8_t bframe)
{

	return bframe;
}

uint8_t bfnDataLengthMSB(uint16_t wframe)
{
	wframe= wframe & 0xff00;
	wframe=wframe>>8;
	return wframe;	
}


uint8_t CalculateChecksum(uint8_t * Frame, uint16_t FrameSize)
{
	uint8_t Checksum = 0;
	uint16_t FrameOffset = 0;

	while(FrameSize--)
	{
		Checksum += Frame[FrameOffset];
		FrameOffset++;
	}

	return(~Checksum);

}
