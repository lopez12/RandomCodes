#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>


void PintarBarra (int Barra[80]);
int MoverBarra (int IniBarra , char comando);
int PintarBolita (int IniBarra);
void delay (int time);

static int j=0;
static int x=80,y=39;
int Level = 1;
static int botes = 0;
int valorObstaculos = 0;
FILE *f;

int main (void)
{
	int Barra[80]={{0}};
	int x1,y1;
	char comando=0;
	int IniBarra = 0;
	int GameStatus = 1;
	int Obstaculos1[5][80] ={ {0},{0},{3,1,2,1,3,2,1,2,3,1,3,1,2,3,1,2,3,1,3,1,2,3,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,1,1,1,1,1,2,2,2,3,3,3,3,3,2,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1},{0,1,1,1,1,2,2,2,2,2,3,3,3,2,2,3,3,3,1,1,1,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,3,3,3,3,2,2,2,3,3,3,3,3,2,2,2,2,2,1,1,2,2,1,1,1,3,3,3,2,2,2,2,2,1,1,1,1,3,3,3,1},{1,2,2,2,2,2,1,1,1,1,2,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,1}};
	
	IniBarra = 0;		/*Esta variable la usaremos para saber el inicio de la barra*/
	f = fopen("puntos.txt","w");
	if(f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	while(Level == 1)
	{
		clrscr ();  /* Borrado de la pantalla siempre para refrescar*/
		for(x1=0;x1<=80;x1++)
		{								/*Aqui pintamos los obstaculos */
			for(y1=0;y1<=5;y1++)
			{
				if(Obstaculos1[y1][x1]==1)
					{
					gotoxy(x1,y1);
					textcolor(LIGHTGREEN);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			    else if(Obstaculos1[y1][x1]==3)
					{
					gotoxy(x1,y1);
					textcolor(BLUE);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 2;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
				else if(Obstaculos1[y1][x1]==2)
					{
					gotoxy(x1,y1);
					textcolor(YELLOW);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			}
			
		}
		
		Barra[IniBarra]=1;		/*	Se cllena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=1;		
		Barra[IniBarra+2]=1;		
		Barra[IniBarra+3]=1;
		Barra[IniBarra+4]=1;
		Barra[IniBarra+5]=1;
		PintarBarra(Barra); /*Pinta la barra*/
		gotoxy(1,1);
		printf("Score: %i",valorObstaculos);
		GameStatus = PintarBolita (IniBarra);
		if(GameStatus == 0)
			return 0;
		delay (300);
		Barra[IniBarra]=0;		/*	Se rellena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=0;		
		Barra[IniBarra+2]=0;		
		Barra[IniBarra+3]=0;
		Barra[IniBarra+4]=0;
		Barra[IniBarra+5]=0;
		if(kbhit()){
			comando	= getch(); /*Recibe el comando para ver que va a hacer (mover la barrita, salir,...etc.)*/
		}
		/*else{ 
			comando = 0;
		}*/
		IniBarra = MoverBarra(IniBarra,comando);
		if(comando == 13) /*Si presiona Enter se sale del juego*/
		{
			return 0;
		}
		
		if(botes == 5)
			Level = 2;
		
	}
	while(Level == 2)
	{
		clrscr ();  /* Borrad de la pantalla siempre para refrescar*/
		for(x1=0;x1<=80;x1++)
		{								/*Aqui pintamos los obstaculos */
			for(y1=0;y1<=5;y1++)
			{
				if(Obstaculos1[y1][x1]==1)
					{
					gotoxy(x1,y1);
					textcolor(LIGHTGREEN);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("Score: %i",valorObstaculos);
						}
					}
			    else if(Obstaculos1[y1][x1]==3)
					{
					gotoxy(x1,y1);
					textcolor(RED);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 2;
							gotoxy(1,1);
							printf("Score: %i",valorObstaculos);
						}
					}
				else if(Obstaculos1[y1][x1]==2)
					{
					gotoxy(x1,y1);
					textcolor(YELLOW);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("Score: %i",valorObstaculos);
						}
					}
			}
			
		}
		
		Barra[IniBarra]=1;		/*	Se cllena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=1;		
		Barra[IniBarra+2]=1;		
		Barra[IniBarra+3]=1;
		Barra[IniBarra+4]=1;
		Barra[IniBarra+5]=1;
		PintarBarra(Barra); /*Pinta la barra*/
		gotoxy(1,1);
		printf("Score: %i",valorObstaculos);
		GameStatus = PintarBolita (IniBarra);
		if(GameStatus == 0)
			return 0;
		delay (280);
		Barra[IniBarra]=0;		/*	Se rellena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=0;		
		Barra[IniBarra+2]=0;		
		Barra[IniBarra+3]=0;
		Barra[IniBarra+4]=0;
		Barra[IniBarra+5]=0;
		if(kbhit()){
			comando	= getch(); /*Recibe el comando para ver que va a hacer (mover la barrita, salir,...etc.)*/
		}
		/*else{ 
			comando = 0;
		}*/
		IniBarra = MoverBarra(IniBarra,comando);
		if(comando == 13) /*Si presiona Enter se sale del juego*/
		{
			return 0;
		}
		
		if(botes == 5)
			Level = 3;
		
	}
	while(Level == 3)
	{
		clrscr ();  /* Borrado de la pantalla siempre para refrescar*/
		for(x1=0;x1<=80;x1++)
		{								/*Aqui pintamos los obstaculos */
			for(y1=0;y1<=5;y1++)
			{
				if(Obstaculos1[y1][x1]==1)
					{
					gotoxy(x1,y1);
					textcolor(LIGHTGREEN);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			    else if(Obstaculos1[y1][x1]==3)
					{
					gotoxy(x1,y1);
					textcolor(RED);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 2;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
				else if(Obstaculos1[y1][x1]==2)
					{
					gotoxy(x1,y1);
					textcolor(YELLOW);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			}
			
		}
		
		Barra[IniBarra]=1;		/*	Se cllena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=1;		
		Barra[IniBarra+2]=1;		
		Barra[IniBarra+3]=1;
		Barra[IniBarra+4]=1;
		Barra[IniBarra+5]=1;
		PintarBarra(Barra); /*Pinta la barra*/
		gotoxy(1,1);
		printf("%i",valorObstaculos);
		GameStatus = PintarBolita (IniBarra);
		if(GameStatus == 0)
			return 0;
		delay (260);
		Barra[IniBarra]=0;		/*	Se rellena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=0;		
		Barra[IniBarra+2]=0;		
		Barra[IniBarra+3]=0;
		Barra[IniBarra+4]=0;
		Barra[IniBarra+5]=0;
		if(kbhit()){
			comando	= getch(); /*Recibe el comando para ver que va a hacer (mover la barrita, salir,...etc.)*/
		}
		/*else{ 
			comando = 0;
		}*/
		IniBarra = MoverBarra(IniBarra,comando);
		if(comando == 13) /*Si presiona Enter se sale del juego*/
		{
			return 0;
		}
		
		if(botes == 5)
			printf("Ganaste");
		
	}
	while(Level == 4)
	{
		clrscr ();  /* Borrado de la pantalla siempre para refrescar*/
		for(x1=0;x1<=80;x1++)
		{								/*Aqui pintamos los obstaculos */
			for(y1=0;y1<=5;y1++)
			{
				if(Obstaculos1[y1][x1]==1)
					{
					gotoxy(x1,y1);
					textcolor(LIGHTGREEN);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			    else if(Obstaculos1[y1][x1]==3)
					{
					gotoxy(x1,y1);
					textcolor(BLUE);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 2;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
				else if(Obstaculos1[y1][x1]==2)
					{
					gotoxy(x1,y1);
					textcolor(YELLOW);
					cprintf("%c",2);
						if(x==x1&&y==y1)
						{
							valorObstaculos = valorObstaculos + 1;
							gotoxy(1,1);
							printf("%i",valorObstaculos);
						}
					}
			}
			
		}
		
		Barra[IniBarra]=1;		/*	Se cllena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=1;		
		Barra[IniBarra+2]=1;		
		Barra[IniBarra+3]=1;
		Barra[IniBarra+4]=1;
		Barra[IniBarra+5]=1;
		PintarBarra(Barra); /*Pinta la barra*/
		gotoxy(1,1);
		printf("%i",valorObstaculos);
		GameStatus = PintarBolita (IniBarra);
		if(GameStatus == 0)
			return 0;
		delay (240);
		Barra[IniBarra]=0;		/*	Se rellena los primero valores de la barra con 1 para que se pinte	*/
		Barra[IniBarra+1]=0;		
		Barra[IniBarra+2]=0;		
		Barra[IniBarra+3]=0;
		Barra[IniBarra+4]=0;
		Barra[IniBarra+5]=0;
		if(kbhit()){
			comando	= getch(); /*Recibe el comando para ver que va a hacer (mover la barrita, salir,...etc.)*/
		}
		/*else{ 
			comando = 0;
		}*/
		IniBarra = MoverBarra(IniBarra,comando);
		if(comando == 13) /*Si presiona Enter se sale del juego*/
		{
			return 0;
		}
		
		if(botes == 5)
			printf("Ganaste");
		
	}
	fclose(f);
	return 0;

}

void PintarBarra (int Barra[80])		/*Funcion para pintar la barra (Solo la pinta, no la mueve)*/
{

int i;

	for(i=0; i<=80; i++)
	{
		if(Barra[i])
		{
			gotoxy(i+1,40-j);
			textcolor(RED);
			cprintf("%c",2);
			
		}
	}

	return;
}

int MoverBarra (int IniBarra, char comando)
{
  

	if((comando == 75) && (IniBarra > 0)) /*El 75 es flechita a la izquierda*/
	{
		IniBarra--;
		IniBarra--;
	}
	
	if((comando == 77) && (IniBarra < 74)) /*El 77 es flechita a la derecha*/
	{
		IniBarra++;
		IniBarra++;
	}
	
	if((comando == 72) && (j < 10)) /*El 72 es flechita arriba*/
	{
		j++;
	}
	
	if((comando == 80) && (j > 1)) /*El 80 es flechita abajo*/
	{
		j--;
		
	}
	
	if(comando == 0)
	{
		IniBarra = IniBarra;
	}
	
	
	return IniBarra;
}

int PintarBolita (int IniBarra) /*Pinta la bolita, y tiene las condiciones de rebote*/
{
	static int direccion = 3;
	
	
	
	
	switch(direccion)
	{
		case 1:  /*Caso uno es para abajo y para la derecha*/
			if(x >= 80)
				direccion = 4;
			else if(y > 40-2-j)
				if((IniBarra == x || IniBarra+1 == x || IniBarra+2 == x || IniBarra+3 == x || IniBarra+4 == x|| IniBarra+5 == x|| IniBarra+6 == x)) /**/
					{
						botes++;
						direccion = 2;  /*Aqui se comparo la bolita con la barra*/
					}
				else{
					system("cls");
					gotoxy(40,20);
					printf("Perdiste");  /*En caso de no chocar se sale del juego*/
					fprintf(f, "PUNTUACION: %i\n", valorObstaculos);
					fclose(f);
					return 0;
				}
			else{
				x++;
				y++;
			}
			gotoxy(x,y);
			printf("%c",2);
		break;
		
		case 2: /*El caso dos es arriba y para la derecha*/
			if(x >= 80)
				direccion = 3;
			else if(y <= 1)
				direccion = 1;
			else{
				x++;
				y--;
			}
			gotoxy(x,y);
			printf("%c",2);
		break;
		
		case 3: /*Caso 3 es para arriba y para la izquierda*/
			if(x <= 1)
				direccion = 2;
			else if(y <= 1)
				direccion = 4;
			else{
				x--;
				y--;
			}
			gotoxy(x,y);
			printf("%c",2);
		break;
		
		case 4: /*CAso 4 es para abajo y para la izquierda */
			if(x <= 1)
				direccion = 1;
			else if(y > 40-2-j)
				if((IniBarra == x || IniBarra+1 == x || IniBarra+2 == x || IniBarra+3 == x || IniBarra+4 == x|| IniBarra+5 == x|| IniBarra+6 == x))
					{
						botes++;
						direccion = 3;  /*Aqui se comparo la bolita con la barra*/
					}
				else{
					system("cls");
					gotoxy(40,20);
					printf("Perdiste"); /*En caso de no chocar se sale del juego*/
					fprintf(f, "PUNTUACION: %i\n", valorObstaculos);
					fclose(f);
					return 0;
				}
			else{
				x--;
				y++;
			}
			gotoxy(x,y);
			printf("%c",2);
		break ;
	
	}
	
	return 1;
}

void delay (int time) /*Funcion de delay porque no se como ase pone el sleep :P*/
{
	time = time * 1000000;
	while(time)
	{
		time--;
	}	
	
	return;
}
