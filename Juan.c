#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main (void)
{
	char Vocal[6] = {0};
	char v = 0;
	int i ;
	
	printf("Dame una cadena \n");
	gets(Vocal);
	
	printf("Dame una vocal \n");
	scanf("%c",&v);
	
	//NO termine con una vocal
	
	for(i=0 ; Vocal[i] != '\0' ; i++)
	{
		if((Vocal[i] == 'a') || (Vocal[i] == 'e') || (Vocal[i] == 'i') || (Vocal[i] == 'o') || (Vocal[i] == 'u'))
		{
			 Vocal[i] = v;
			 printf("%c",Vocal[i]);
			 printf("\n");
		}
		
		else 
		printf("%c",Vocal[i]);
	}
	return 0;
}