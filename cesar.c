#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int StringReceive (char Anagramcmp[]);

int main (void)
{
	char Anagramcmp[25] = {0};
	int i ;
	int YESana = 0;
	
	printf("Dame una Oracion \n");
	gets(Anagramcmp);
	
	YESana = StringReceive(Anagramcmp);
	if(YESana == 1)
		printf("Si es un anagrama");
	else
		printf("No es");
}

int StringReceive (char Anagramcmp[25])
{
	int i = 0;
	int StringSize = 0;
	int YESana;
	int counter= 0;
	
	for(i=0 ; Anagramcmp[i] != '\0' ; i++)
	{
	  //Hacer nada
	}
	
	StringSize = i;
	
	for(i=0;i<StringSize;i++)
	{
	//printf("%c \n",Anagramcmp[i]);
	//printf("%c \n",Anagramcmp[StringSize-i-1]);
		if(Anagramcmp[i] == Anagramcmp[StringSize-i-1])
		{	counter++;
			//printf("%i \n",counter);
		}
	}
	
	if(counter == StringSize)
		YESana = 1;
		
	return YESana;
}