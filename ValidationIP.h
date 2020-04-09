#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IPMask 		65535 //255.255.255.255
#define PrimerIP 	255 //255.0.0.0
#define SegundaIP	255  //0.255.0.0
#define TercerIP 	255   //0.0.255.0
#define CuartaIP 	255    //0.0.0.255

int Validation(struct sUDP *protocol);

int Validation(struct sUDP *protocol)
{
	unsigned char *pIPDir;
	unsigned int length=0;
	unsigned int IPVerify[4]={0};
	unsigned int i=0;
	
	
	pIPDir = protocol->ipDestiny;
	
	while(*pIPDir!='.')
	{
		length++;
		pIPDir++;
	}
	while(i<length)
	{
		IPVerify[0] = (protocol->ipDestiny[length-1-i]-48) * (pow(10,i)) +IPVerify[0];
		i++;
		
	}
	
	pIPDir++;
	length=0;
	i=0;
	while(*pIPDir!='.')
	{
		length++;
		pIPDir++;
	}
	while(i<length)
	{
		IPVerify[1] = (protocol->ipDestiny[length+3-i]-48) * (pow(10,i)) +IPVerify[1];
		i++;
		
	}
	
	pIPDir++;
	length=0;
	i=0;
	while(*pIPDir!='.')
	{
		length++;
		pIPDir++;
	}
	while(i<length)
	{
		IPVerify[2] = (protocol->ipDestiny[length+7-i]-48) * (pow(10,i)) +IPVerify[2];
		i++;
		
	}
	
	pIPDir++;
	length=0;
	i=0;
	while(*pIPDir)
	{
		length++;
		pIPDir++;
	}
	while(i<length)
	{
		IPVerify[3] = (protocol->ipDestiny[length+11-i]-48) * (pow(10,i)) +IPVerify[3];
		i++;
		
	}

	if(IPVerify[0]==PrimerIP&&IPVerify[1]==SegundaIP&&IPVerify[2]==TercerIP&&IPVerify[3]==CuartaIP)
		return 1;
	else
		return 0;
}

