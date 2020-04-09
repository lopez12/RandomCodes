#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void pantalla (void);
void printnada(void);
void CartaNoJugada(int x,int y);
void imprimirfiguras(int seleccion, int memorama[12]);
void imprimecirculo(int x, int y);
void imprimetriangulo(int x, int y);
void imprimeEquis(int x, int y);
void imprimecuadrado(int x, int y);
void delay (int time);
int timer (void);

int main(void)
{
    
    int eleccion[2]={0};
    int memorama[12]={1,2,1,2,3,4,3,4,0,0,0,0};
    int seleccion[3]={0};
    int x;
    int y;
	int counter = 60;
	
	printf("Seleciona un nivel (1,2,3): ");
	switch(getch()-48)
	{
		case 1:
			counter = 60;
		break;
		
		case 2:
			memorama[0]=4;
			memorama[1]=1;
			memorama[2]=3;
			memorama[3]=1;
			memorama[4]=2;
			memorama[5]=4;
			memorama[6]=3;
			memorama[7]=2;
			memorama[8]=1;
			memorama[9]=1;
			memorama[10]=0;
			memorama[11]=0;
			counter = 30;
		break;
		
		case 3:
			memorama[0]=2;
			memorama[1]=1;
			memorama[2]=4;
			memorama[3]=1;
			memorama[4]=2;
			memorama[5]=4;
			memorama[6]=2;
			memorama[7]=2;
			memorama[8]=1;
			memorama[9]=1;
			memorama[10]=3;
			memorama[11]=3;
			counter = 20;
		break;
	}
    
	while(1)
	{
	system("cls");
    pantalla();	
    for(x=0;x<12;x++)
    {
        if(memorama[x]==0 && x <= 3)
        {
			y=1;
			CartaNoJugada(x,y);
        }
		else if(memorama[x]==0 && x <= 7 && x > 3)
		{
			y=9;
			CartaNoJugada(x-4,y);
		}
		else if(memorama[x]==0 && x <= 12 && x > 7)
		{
			y=17;
			CartaNoJugada(x-8,y);
		}
    }
	
    
    if(kbhit())
    { 
		
       seleccion[2] = getch()-48;
	   if(seleccion[2]=='a'-48)
	   {
		seleccion[2] = 10;
	   }
	   else if(seleccion[2]=='b'-48)
	   {
		seleccion[2] = 11;
	   }
	   else if(seleccion[2]=='c'-48)
	   {
		seleccion[2] = 12;
	   }
	   
	   if(eleccion[0]==1)
		{
			eleccion[1] = 1;  
			seleccion[1] = seleccion[2];
			imprimirfiguras(seleccion[1],memorama);
			delay(200);
				if(memorama[seleccion[1]-1]==memorama[seleccion[0]-1])
				{	
					memorama[seleccion[1]-1] = 0;
					memorama[seleccion[0]-1] = 0;
				}
			eleccion[0] = 0;
			eleccion[1] = 0;
			
		}
		else
		{
		eleccion[0] = 1;
		seleccion[0] = seleccion[2];		 
		}
	}
	
	if(seleccion[0]!=0)
	{
		imprimirfiguras(seleccion[0],memorama);
	
	}
	gotoxy(1,24);
	printf("%i",counter);
    if(timer())
      counter--;
	if(counter == 0)
	break;
	
  	delay(2000);
   
}
  printf("\nPerdiste\n");
  return 0;
}

void pantalla (void)
{
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("|                 | |                 | |                 | |                 |\n");
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|       1         | |       2         | |         3       | |         4       |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("                                                                               \n");
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("|                 | |                 | |                 | |                 |\n");
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|        5        | |        6        | |         7       | |         8       |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("                                                                               \n");
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("|                 | |                 | |                 | |                 |\n");
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|        9        | |         a       | |         b       | |          c      |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("|                 | |                 | |                 | |                 |\n"); 
     printf("------------------- ------------------- ------------------- -------------------\n");
     printf("                                                                               \n");    
     
}

void printnada(void)
{
     printf("                   ");      
}

void CartaNoJugada(int x,int y)
{
	gotoxy((x*20)+1,y);
    printnada();
    gotoxy((x*20)+1,y+1);
    printnada();
    gotoxy((x*20)+1,y+2);
    printnada();
    gotoxy((x*20)+1,y+3);
    printnada();
    gotoxy((x*20)+1,y+4);
    printnada();
    gotoxy((x*20)+1,y+5);
    printnada();
    gotoxy((x*20)+1,y+6);
    printnada();

}

void imprimirfiguras(int seleccion, int memorama[12])
{
	switch(seleccion)
	{
		case 1:
			if(memorama[seleccion-1]==1)
				imprimecirculo(1,1);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(1,1);
			if(memorama[seleccion-1]==3)
				imprimeEquis(1,1);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(1,1);
		break;
		
		case 2:
			if(memorama[seleccion-1]==1)
				imprimecirculo(20,1);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(20,1);
			if(memorama[seleccion-1]==3)
				imprimeEquis(20,1);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(20,1);
		break;
		
		case 3:
			if(memorama[seleccion-1]==1)
				imprimecirculo(40,1);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(40,1);
			if(memorama[seleccion-1]==3)
				imprimeEquis(40,1);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(40,1);
		break;
		
		case 4:
			if(memorama[seleccion-1]==1)
				imprimecirculo(60,1);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(60,1);
			if(memorama[seleccion-1]==3)
				imprimeEquis(60,1);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(60,1);
		break;
		
		case 5:
			if(memorama[seleccion-1]==1)
				imprimecirculo(1,9);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(1,9);
			if(memorama[seleccion-1]==3)
				imprimeEquis(1,9);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(1,9);
		break;
		
		case 6:
			if(memorama[seleccion-1]==1)
				imprimecirculo(20,9);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(20,9);
			if(memorama[seleccion-1]==3)
				imprimeEquis(20,9);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(20,9);
		break;
		
		case 7:
			if(memorama[seleccion-1]==1)
				imprimecirculo(40,9);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(40,9);
			if(memorama[seleccion-1]==3)
				imprimeEquis(40,9);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(40,9);
		break;
		
		case 8:
			if(memorama[seleccion-1]==1)
				imprimecirculo(60,9);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(60,9);
			if(memorama[seleccion-1]==3)
				imprimeEquis(60,9);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(60,9);
		break;
		
		case 9:
			if(memorama[seleccion-1]==1)
				imprimecirculo(1,17);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(1,17);
			if(memorama[seleccion-1]==3)
				imprimeEquis(1,17);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(1,17);
		break;
		
		case 10:
			if(memorama[seleccion-1]==1)
				imprimecirculo(20,17);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(20,17);
			if(memorama[seleccion-1]==3)
				imprimeEquis(20,17);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(20,17);
		break;
		
		case 11:
			if(memorama[seleccion-1]==1)
				imprimecirculo(40,17);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(40,17);
			if(memorama[seleccion-1]==3)
				imprimeEquis(40,17);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(40,17);
		break;
		
		case 12:
			if(memorama[seleccion-1]==1)
				imprimecirculo(60,17);
			if(memorama[seleccion-1]==2)
				imprimetriangulo(60,17);
			if(memorama[seleccion-1]==3)
				imprimeEquis(60,17);
			if(memorama[seleccion-1]==4)
				imprimecuadrado(60,17);
		break;
	}
}

void imprimecirculo(int x, int y)
{	
	gotoxy(x,y);
	printf("-------------------  ");
	gotoxy(x,y+1);
    printf("|       *****      | ");
	gotoxy(x,y+2);
    printf("|      *     *     | "); 
	gotoxy(x,y+3);
    printf("|     *       *    | "); 
	gotoxy(x,y+4);
    printf("|      *      *    | ");
	gotoxy(x,y+5);	
    printf("|       ******     | ");
	gotoxy(x,y+6);
    printf("-------------------  ");
}

void imprimetriangulo(int x, int y)
{
	gotoxy(x,y);
	printf("-------------------  ");
	gotoxy(x,y+1);
    printf("|         *        | ");
	gotoxy(x,y+2);
    printf("|        * *       | ");
	gotoxy(x,y+3);	
    printf("|       *   *      | ");
	gotoxy(x,y+4);	
    printf("|      *     *     | ");
	gotoxy(x,y+5);	
    printf("|     *********    | ");
	gotoxy(x,y+6);
    printf("-------------------  ");
}

void imprimeEquis(int x, int y)
{
	gotoxy(x,y);
	printf("-------------------  ");
	gotoxy(x,y+1);
    printf("|       *    *     | ");
	gotoxy(x,y+2);
    printf("|        *  *      | ");
	gotoxy(x,y+3);
    printf("|          *       | ");
	gotoxy(x,y+4);	
    printf("|         * *      | ");
	gotoxy(x,y+5);
    printf("|        *   *     | ");
	gotoxy(x,y+6);
    printf("-------------------  ");
}

void imprimecuadrado(int x, int y)
{
	gotoxy(x,y);
	printf("-------------------  ");
	gotoxy(x,y+1);
    printf("|     *******      | ");
	gotoxy(x,y+2);
    printf("|     *     *      | ");
	gotoxy(x,y+3);	
    printf("|     *     *      | ");
	gotoxy(x,y+4);
    printf("|     *     *      | ");
	gotoxy(x,y+5);
    printf("|     *******      | ");
	gotoxy(x,y+6);
    printf("-------------------  ");
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

int timer (void)
{
    static int timer=1;
    
    while(timer)
    {
     timer--;
     return 0;           
    }
    timer = 1;
    return 1;
    
}