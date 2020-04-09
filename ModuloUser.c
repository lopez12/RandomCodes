#include <stdio.h>
#include <string.h>

unsigned int UserValidation(void);


unsigned int UserValidation(void)
{
	unsigned int Valor=0;
	unsigned char User[10];
	unsigned char password[10];
	
	printf("Dame el usuario: ");
	scanf("%s",&User);
	fflush(stdin);
	printf("Password: ");
	scanf("%s",&password);
	fflush(stdin);
	
	if(!strcmp(User,"astrid")&&!strcmp(password,"hola"))
	{
		printf("Acces Granted\nWelcome Astrid");
		Valor = 1;
	}
	else if(!strcmp(User,"cesar")&&!strcmp(password,"hola"))
	{
		printf("Acces Granted\nWelcome Cesar");
		Valor = 1;
	}	
	else
	printf("Usuario y/o contrasena incorrecto");
	
	return Valor;
}