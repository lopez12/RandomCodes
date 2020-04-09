#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void pintarinvasores (int invasores[25][80]);
void delay (int time);
void pintarnave (int nave[80]);
void pintardisparo (int disparo[25][80]);

int main (void)
{
	int invasores[25][80]={{0}};
	int nave[80]={{0}};
	int x,y;
	int comando = 77;
	int direccioninvaders=1;
	int varnave=0;
	int disparo[25][80]={{0}};
	int vardisparox=80;
	int vardisparoy=25;
	int iniciardisparo = 0;
	int moverabajox;
	int moverabajoy;
	int aux[80]={0};
	int puntuacion = 0;
	
	
	
	for(x=0;x<=10;x++)
	{
		invasores[3][x]=10;
	}
	for(x=0;x<=10;x++)
	{
		invasores[2][x]=20;
	}
	for(x=0;x<=10;x++)
	{
		invasores[1][x]=30;
	}
	invasores[0][5]=30;
	
	arthur1
	
	x=0;
	y=0;
	nave[0]=1;

	while(1)
	{	
		if(direccioninvaders==1)
		{
			clrscr ();
			pintarinvasores(invasores);
			invasores[y+3][x+10]=invasores[y+3][x];
			invasores[y+3][x]=0;
			invasores[y+2][x+10]=invasores[y+2][x];
			invasores[y+2][x] = 0;
			invasores[y+1][x+10]=invasores[y+1][x];
			invasores[y+1][x]=0;
			invasores[y][x+6]=invasores[y][x+5];
			invasores[y][x+5]=0;
			if(x==70)
			{
				for(moverabajoy = y+5;moverabajoy>=0;moverabajoy--)
				{
					for(moverabajox = 0;moverabajox<=80;moverabajox++)
					{
						if(moverabajoy==0)
						{
							invasores[moverabajoy][moverabajox] = 0;
						}
						invasores[moverabajoy][moverabajox]=invasores[moverabajoy-1][moverabajox];
					}
				}
				y++;
				direccioninvaders=2;
				
			}
			if(y>18)
			{
				printf("Tu puntuacion fue: %i",puntuacion);
				return 0;
			}
			x++;
		}
		if(direccioninvaders==2)
		{
			clrscr ();
			pintarinvasores(invasores);
			invasores[y+3][x]=	invasores[y+3][x+10];
			invasores[y+3][x+10]=0;
			invasores[y+2][x]=invasores[y+2][x+10];
			invasores[y+2][x+10] = 0;
			invasores[y+1][x]=invasores[y+1][x+10];
			invasores[y+1][x+10]=0;
			invasores[y][x+5]=invasores[y][x+6];
			invasores[y][x+6] = 0;
			if(x==0)
			{
				for(moverabajoy = y+5;moverabajoy>=0;moverabajoy--)
				{
					for(moverabajox = 0;moverabajox<=80;moverabajox++)
					{
						if(moverabajoy==0)
						{
							invasores[moverabajoy][moverabajox] = 0;
						}
						invasores[moverabajoy][moverabajox]=invasores[moverabajoy-1][moverabajox];;
					}
				}
				y++;
				direccioninvaders=1;
			}
			if(y>18)
			{
				printf("Tu puntuacion fue: %i",puntuacion);
				return 0;
			}
			x--;
		}
		
		if(kbhit()) 
			{										
				comando	= getch();	
			}
			if((comando == 75) && (varnave > 0)) /*El 75 es flechita a la izquierda*/ 
			{	
				nave[varnave]=0;
				varnave--;
				nave[varnave]=1;	
			}
			else if((comando == 77) && (varnave < 80)) /*El 77 es flechita a la derecha*/ 
			{
				nave[varnave]=0;
				varnave++;
				nave[varnave]=1;
			}
			else if(comando == 32 && iniciardisparo!=1) /*El 77 es espacio*/
			{
				vardisparox = varnave;
				disparo[vardisparoy][vardisparox] = 1;
				iniciardisparo = 1;
			}
			if(iniciardisparo==1)
			{
				disparo[vardisparoy][vardisparox] = 0;
				vardisparoy--;
				disparo[vardisparoy][vardisparox] = 1;
				pintardisparo(disparo);
				if(vardisparoy==0)
				{
					disparo[vardisparoy][vardisparox] = 0;
					iniciardisparo = 0;
					vardisparox=80;
					vardisparoy=25;
				}
				if(invasores[vardisparoy][vardisparox]==10||invasores[vardisparoy][vardisparox]==20||invasores[vardisparoy][vardisparox]==30)
				{
					puntuacion = invasores[vardisparoy][vardisparox] + puntuacion;
					invasores[vardisparoy][vardisparox] = 0;
					disparo[vardisparoy][vardisparox] = 0;
					iniciardisparo = 0;
					vardisparox=80;
					vardisparoy=25;
					
				}
			}
			pintarnave(nave);
			delay(250);
	}
		
	
	return 0;
	
}

void pintarinvasores (int invasores[25][80])
{
	int x,y;
	for(x=0;x<=80;x++)
		{								
			for(y=0;y<=20;y++)
			{
				if(invasores[y][x]==10)
					{
					gotoxy(x+1,y+1);
					textcolor(LIGHTGREEN);
					cprintf("%c",2);
					}
				else if(invasores[y][x]==20)
					{
					gotoxy(x+1,y+1);
					textcolor(BLUE);
					cprintf("%c",2);
					}
				else if(invasores[y][x]==30)
					{
					gotoxy(x+1,y+1);
					textcolor(RED);
					cprintf("%c",2);
					}
				else if(invasores[y][x]==200)
					{
					gotoxy(x+1,y+1);
					textcolor(WHITE);
					cprintf("%c",2);
					}
			}
		}

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

void pintarnave (int nave[80])
{
	int i;
	
	for(i=0;i<80;i++)
	{
		if (nave[i]==1)
		{
			gotoxy(i+1,25);
			textcolor(MAGENTA);
			cprintf("%c",2);
		}
	}

}

void pintardisparo (int disparo[25][80])
{
	int i;
	int x;
	for(x=0;x<25;x++)
	{
		for(i=0;i<80;i++)
		{
			if (disparo[x][i]==1)
			{
				gotoxy(i+1,x+1);
				textcolor(WHITE);
				cprintf("%c",2);
			}
		}
	}

}
