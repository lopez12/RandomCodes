#include <stdio.h>
#include <string.h>
#include <conio.h>


unsigned int UserValidation(void);


unsigned int UserValidation(void)
{
	unsigned int Valor=0;
	unsigned char User[10];
	unsigned char password[10];
	
	system("cls");
	gotoxy(18,10);
	printf("Dame el usuario: ");
	scanf("%s",&User);
	fflush(stdin);
	gotoxy(18,11);
	printf("Password: ");
	scanf("%s",&password);
	fflush(stdin);
	
	if(!strcmp(User,"astrid")&&!strcmp(password,"hola"))
	{
		system("cls");
		gotoxy(18,15);
		printf("Access Granted\n");
		gotoxy(18,16);
		printf("Welcome Astrid ;) \n");
		Valor = 1;
	}
	else if(!strcmp(User,"cesar")&&!strcmp(password,"hola"))
	{
		system("cls");
		gotoxy(18,15);
		printf("Acces Granted\n");
		gotoxy(18,16);
		printf("Welcome Cesar ;)\n");
		Valor = 2;
	}	
	else
	printf("Usuario y/o contrasena incorrecto");
	
	return Valor;
}