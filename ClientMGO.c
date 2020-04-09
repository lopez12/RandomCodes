#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <mqueue.h>
#include <fcntl.h>
#include <time.h>


#define SHELL_PROMPT    ("\n\rWhat do you want your message to say? ")
#define FAIL    -1
#define OK    1


uint8_t bfnDataLengthMSB(uint16_t wFrame);
uint8_t bfnDataLengthLSB(uint8_t  bFrame);
uint8_t bfnChecksum(uint8_t * Frame, uint16_t FrameSize);

int main(int argc, char * argv[])
{
    uint8_t * Command;
    uint8_t bSof = 0xAA;
    uint8_t bDataLenghtMSB;
    uint8_t bDataLenghtLSB;
    uint8_t bChecksum;
    uint8_t * bSendData;
    uint8_t * bRecievedData;
    uint16_t wCounter = 0;
    int32_t dwStatus;
    uint32_t dwPortSrv;
    int32_t dwClntSocket;
    struct sockaddr_in SocketAddr;
    
    
    dwPortSrv = atoi(argv[2]);
    
    
    dwClntSocket = socket(AF_INET, SOCK_STREAM, 0);
    SocketAddr.sin_family = AF_INET;
    SocketAddr.sin_port = htons(dwPortSrv);
    SocketAddr.sin_addr.s_addr = inet_addr(argv[1]);
    
    
    dwStatus = connect(dwClntSocket, (struct sockaddr *)&SocketAddr,sizeof(struct sockaddr));
    printf("\n %i\n", dwStatus);
    
    
    while(1)
    {
       
        Command = (uint8_t*)readline(PROMPT);
        printf("\n the message send was %s \n",(char *)Command);
        printf("With %i characters \n",strlen((char *)Command));
        bDataLenghtMSB = bfnDataLengthMSB(strlen((char*)Command));
        bDataLenghtLSB = bfnDataLengthLSB(strlen((char*)Command));
        printf("%i  Most significant bit  ",bDataLenghtMSB);
        printf("%i Less significant bit ",bDataLenghtLSB);
        
        
        bSendData = (uint8_t*)malloc(strlen((char *)Command)+4);
        bSendData[0] = bSof;
        bSendData[1] = bDataLenghtMSB;
        bSendData[2] = bDataLenghtLSB;
        memcpy((char *)&bSendData[3],(char *)Command,strlen((char *)Command));
        
        bChecksum = bfnChecksum(bSendData,(uint16_t)(strlen((char *)Command)+3));
        
        bSendData[3+strlen((char *)Command)] = bChecksum;/*chesum*/
        
        printf("\n Send this data ");
        if ( wCounter != 3)
        {
            printf("%x ",bSendData[wCounter]);
            
            wCounter++;
        }
        wCounter = 3;
        if ( wCounter != strlen((char *)Command)+3)
        {
            printf("%c ",bSendData[wCounter]);
            
            wCounter++;
        }
        printf( "%x ",bSendData[3+strlen((char *)Command)]);
        printf("\n");
        
        wCounter = 0;
        
        write(dwClntSocket,bSendData,strlen((char *)Command)+4);
        free(bSendData);
        bRecievedData = (uint8_t*)malloc(3);
        read(dwClntSocket, bRecievedData,3);
        
    printf("%x- %x -%x \n\r",bRecievedData[0],bRecievedData[1],bRecievedData[2]);
        if(bRecievedData[2] != bfnChecksum((uint8_t*)bRecievedData,2))
        {
            printf("%x\n\r",bfnChecksum((uint8_t*)bRecievedData,2));
            printf("vALIO madre");
        }
        else
        {
            if(bRecievedData[OK]== 0x0F)
            {
                printf("Ok");
            }
            else if(bRecievedData[FAIL]== 0x0F)
            {
                printf("Fail");
            }
        }
        free(bRecievedData); 
    }

    return 0;
}

uint8_t bfnDataLengthMSB(uint16_t wFrame)
{
    wFrame = wFrame & 0xff00;
    wFrame = wFrame >> 8;
    return wFrame;    
}

uint8_t bfnDataLengthLSB(uint8_t bFrame)
{
    return bFrame;
}

uint8_t bfnChecksum(uint8_t * Frame, uint16_t FrameSize)
{
    uint8_t bChecksumResult = 0;
    uint16_t FrameOffset = 0;

    while(FrameSize--)
    {
        bChecksumResult += Frame[FrameOffset];
        FrameOffset++;
    }

    return(~bChecksumResult);

}