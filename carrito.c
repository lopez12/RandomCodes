#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void delay (int time);
void PintarCarroEnemigo(int CarroEnemigopositionHorizontal,int CarroEnemigopositionVertical);
void PintarCarroMIO(int CarroMIOpositionHorizontal);

int main (void)
{
	int CarroEnemigopositionHorizontal=1;
	int CarroEnemigopositionVertical = 1;
	int CarroMIOpositionHorizontal = 1;
	int i;
	int comando=77;
	int Score =0;
	
	for(;;)
	{	
		clrscr ();
		PintarCarroEnemigo(CarroEnemigopositionHorizontal,CarroEnemigopositionVertical);
		PintarCarroMIO(CarroMIOpositionHorizontal);
		if(CarroEnemigopositionVertical==17 && CarroMIOpositionHorizontal==CarroEnemigopositionHorizontal)
		{
			clrscr ();
			printf("Final Score: %i",Score);
			return 0;
		}
		if(kbhit()) 
		{										
			comando	= getch();	
		}
		if(comando == 75) /*El 75 es flechita a la izquierda*/
		{
			CarroMIOpositionHorizontal = 2;
		}
		else if(comando == 77) /*El 77 es flechita a la derecha*/ 
		{
			CarroMIOpositionHorizontal = 1;
		}
		gotoxy(60,4);
		printf("Score: %i",Score);
		delay(200);
		CarroEnemigopositionVertical++;
		if(CarroEnemigopositionVertical>=25)
		{
			CarroEnemigopositionVertical = 1;
			Score++;
			CarroEnemigopositionHorizontal = CarroEnemigopositionHorizontal^3;
		}
	}
	return 0;
}

void delay (int time) 
{
	time = time * 1000000;
	while(time)
	{
		time--;
	}	
	
	return;
}

void PintarCarroEnemigo(int CarroEnemigopositionHorizontal, int CarroEnemigopositionVertical)
{
	if(CarroEnemigopositionHorizontal==1)
	{
		gotoxy(40,CarroEnemigopositionVertical+3);
		textcolor(WHITE);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(41,CarroEnemigopositionVertical+2);
		cprintf("%c",2);
		gotoxy(40,CarroEnemigopositionVertical+1);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(41,CarroEnemigopositionVertical);
		cprintf("%c",2);
	}
	else if(CarroEnemigopositionHorizontal==2)
	{
		gotoxy(37,CarroEnemigopositionVertical+3);
		textcolor(WHITE);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(38,CarroEnemigopositionVertical+2);
		cprintf("%c",2);
		gotoxy(37,CarroEnemigopositionVertical+1);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(38,CarroEnemigopositionVertical);
		cprintf("%c",2);
	}
	
}

void PintarCarroMIO(int CarroMIOpositionHorizontal)
{
	if(CarroMIOpositionHorizontal==1)
	{
		gotoxy(40,20+3);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(41,20+2);
		cprintf("%c",2);
		gotoxy(40,20+1);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(41,20);
		cprintf("%c",2);
	}
	if(CarroMIOpositionHorizontal==2)
	{
		gotoxy(37,20+3);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(38,20+2);
		cprintf("%c",2);
		gotoxy(37,20+1);
		cprintf("%c",2);
		cprintf("%c",2);
		cprintf("%c",2);
		gotoxy(38,20);
		cprintf("%c",2);
	}
}

