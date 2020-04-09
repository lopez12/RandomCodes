#include <conio.h>
#include <stdio.h>

void MainInterface (void);
void delay(int counter);
void AccessingServer(void);

void MainInterface (void)
{
	do
	{
		system("cls");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vvvvvvvvvv  vvvvvvv        vvvvvvvv  vvvvvvv  vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv    vvvvvv    vvvvvv  vvvvvvvvvvvvvvv    vvvvv  vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vv  vv  vv  vvvvvvvv  vvvvvvvvvvvvv  vv  vvv  vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vvvv  vvvv  vvvvvvvvvv  vvvvvvvvvvv  vvv  vv  vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vvvvvvvvvv  vvvvvvvvvvvv  vvvvvvvvv  vvvv  v  vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vvvvvvvvvv  vvvvvvvvvvvvv  vvvvvvvv  vvvvv    vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvv  vvvvvvvvvv  vvvvv        vvvvvvvvvv  vvvvvv   vvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv       vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv  vvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv  vvvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvv  vvvvvvvv  vvvvvvvvvvvvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvv  vvvvvv  vvvvvvvvvvvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvv  vvvv  vvvvvvvvvvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvv  vv  vvvvvvvvvvvv  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvv    vvvvvvvvvvvvv          vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvv  CUENTAS CON USUARIO DE MSN V2? (S/N)  vvvvvvvvvvvvvvvvvvvvvvvv");
		printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
	}while(getch()!='s');
	
	
	fflush(stdin);
}

void AccessingServer(void)
{
	system("cls");
	gotoxy(18,10);
	printf("Accesing Server");
	delay(45);
	gotoxy(18,10);
	printf("Accesing Server.");
	delay(45);
	system("cls");
	gotoxy(18,10);
	printf("Accesing Server..");
	delay(45);
	system("cls");
	gotoxy(18,10);
	printf("Accesing Server...");
	delay(45);
	system("cls");
	gotoxy(18,10);
	printf("Accesing Server");
	delay(45);
	gotoxy(18,10);
	printf("Accesing Server.");
	delay(45);
	system("cls");
	gotoxy(18,10);
	printf("Accesing Server..");
	
}

void delay(int counter)
{
	counter = counter*10000000000;
	while(counter)
	{
		counter--;
	}
	return;
}