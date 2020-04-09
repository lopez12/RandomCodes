#include<stdio.h>
#include<stdlib.h>							
#include<conio.h>
#include<windows.h>

void PintaVibora (int Vibora[40][80]);
void PintarMarco (void);

/*Hola chicos, este programa se los hize en terminos generales lo que hize fue el pensar en la cabeza y en la cola de la viborita y como se mueven*/
int main (void)
{	
	
	int Vibora[40][80]={0}; 				//Esta variable es la vibora en si y es de 40 por 80 porque la culebrita podria ser de ese tamaño maximo si juegas como coreano
	int x=0,y=0; 							//Estas variables lo use para saber la posicion en el mapa
	int ViboraSize = 3;						//Con este sabre el tamaño de la vibora
	int Cabeza[2] = {3,0};					//Este arreglo es la cabeza de la vibora e inicia en la posicion 3,0 porque la culebrita sera de 4 bolitas al inicio
	int Cola[2]= {0,0} ;					//la cola esta en la 0,0 
	int comando = 77;						//El comando sera usado para saber que felchita presionas y empieza en 77 porque es flechita a la derecha
	int instrucciones[80] = {1,1,1,0}; /*1 = x+ , 2 = x- , 3 = y+ , 4 = y-*/ //Este comentario no lo borren es vital
	int fruta[40][80] = {0};				//Esto de fruta es la comida de la culebrita
	int timer = 200;						//timer lo uso para que si tarda mucho en comer la bolita la mueva y tambien nos ayudara a mantener la bolita en su lugar
	int positionx,positiony;				//Estas son la variables de la comida
	int Score = 0;							//el marcador
	int i;		
	int Speed = 200;						//La velocidad del juego
	
	
	
	
	Vibora[0][1] = 1;  						//primero lleno los espacios que seran la viborita inicial, el primer parametro son las "y" y el segundo la "x"
	Vibora[0][2] = 1;						//entonces inicia acostada la vibora en las primeras posiciones.
	Vibora[0][3] = 1;
	
		while(1)   							//while 1 se usa para que se corra infinitamente
		{
			clrscr ();						//Un borrado de pantalla siempre para que se quiten las cosas anteriores
			PintarMarco ();					//pintar marco es una funcion que sirve para pintar las paredes donde puede chocar la viborita
			PintaVibora (Vibora);			//Esta funcion pinta la viborita y recibe el parametro vibora abajo se explica mejor
			
			if(timer > 100)					//El timer inicio en 200 por lo tanto entra la primera vez que corre el programa
			{	
				positionx =  random(80);	//cada vez que entre le daremos a la posicion "x" y "y" un valor aleatorio
				positiony =  random(40);
				fruta[positiony][positionx] = 1; //Le ponemos un valor de 1 porque luego compararemos este 1 con el 1 de la vibora para ver si comio
				gotoxy(positionx,positiony);		//vamos a la posicion generada aletaoriamente 
				textcolor(RED);						//le ponemos rojo
				cprintf("%c",129);					//y la pintamos, le pusimos el 129 para que sea una figura y por eso es %c ya que es el caracter 129
				timer = 0;							//y mandamos el timer a 0 para que no vuelva a entrar a esta funcion ya que si vuelve a entrar estaria generando posiciones
			}										//random y pintandolas siempre y queremos que se mantenga en la misma posicion por un buen rato
			else 
			{
				gotoxy(positionx,positiony); 		//en vista de que timer ya es otro valor menor a 100 siempre debemos ir a la posicion xy que no se guardo en las
				textcolor(RED);						//variables y pintarla de nuevo ya que siempre se borra la pantalla cada ciclo
				cprintf("%c",129);
			}
			if((Cabeza[0]==positionx-1) && (Cabeza[1]==positiony-1)) //esta es la comparacion de la cabeza con la fruta, si la posicion 0 de la cabeza (que es la "x") esta la misma "x"
			{															// que la "x" de la fruta y tambien la "y" de ambas cosas significa que se comio una fruta
				Score++;											//agregamos 1 al score
				timer = 200;										//como comio algo debemos de generar una posicion random nueva para la comida y para eso debemos de entrar a la funcion de arriba la cual depende del valor timer asi que le damos un valor mayor a 100
				Vibora[Cabeza[1]][Cabeza[0]] = 1;					//y debemos de darle un valor de 1 siempre a la cabeza ya que se pintan los 1 en la pantalla
				ViboraSize++;										//la aumentamos uno al tamaño de la vibora porque se comio algo
			}
			else 
				Vibora[Cola[1]][Cola[0]] = 0;						//si no comio algo hay que borra la cola asi que vamos a la cola y la borramos, arriba no la borramos porque esa comida nos dara un obstaculo que nacera de la cola de la serpiente
			gotoxy(2,1);   											//con esto pintamos el marcador para que lo vea el usuario
			printf("Score: %i", Score);
			
			if(Score > 5)   						//esto es sencillo, si la puntuacion es mayor a 5 le subimos la velocidad
			{
				Speed = 150;	
			}
			if(Score > 10)							//luego mayor a 10
			{
				Speed = 100;	
			}
			if(Score > 15)							//y asi sucesivamente
			{
				Speed = 50;	
			}
			
			
			if(kbhit()) 							//Si presionamos algo debemos de leer que fue lo que presionamos sino se presiona nada la vibora debe seguir asi que solo
			{										//si se presiona algo el valor de comando debe de cambiar sino mantiene su valor
				comando	= getch();					//asi que guardamos ese getch en el comando
			}
			if((comando == 75) && (x > 0)) /*El 75 es flechita a la izquierda*/ //asi que si la presionamos y x es mayor a 0 la vibora debe seguir
			{
				x--;															//vamos a mover la x un valor a la izquierda
				if(Vibora[Cabeza[1]][Cabeza[0]-1] == 1)							//considerando que vamos a la izquierda si la vibora en el mismo valor "y" (Cabeza[1]) pero una posicion a la izquierda de la cabeza YA es uno significa que
				{																//que alli existe un pedazo de serpiente y chocar una parte de la serpiente significa perder
					printf("Perdiste");
					return 0;
				}
				Cabeza[0]--;													//si no perdiste movemos la cabeza un espacio a la izquierda en los valores de equis (Cabeza[0])
				timer ++;														//le aumentamos uno al timer para que cuente algo
				instrucciones[ViboraSize] = 2;									//y le decimos que la instruccion que dimos fue 2 (Aqui es la parte de los comentarios de arriba que dije que no borraran)
			}																	//cada instruccion tiene un valor que vamos guardando en un arreglo de instrucciones para saber a donde mover la cola ya que no se mueve en paralelo con la cabeza
			
			if((comando == 77) && (x < 80)) /*El 77 es flechita a la derecha*/  //Repetimos el mismo procedimiento pero cada uno dependera de que instruccion se le de
			{
				x++;
				if(Vibora[Cabeza[1]][Cabeza[0]+1] == 1)
				{
					printf("Perdiste");
					return 0;
				}
				Cabeza[0]++;
				timer ++;
				instrucciones[ViboraSize] = 1;
			}
			
			if((comando == 72) && (y > 0)) /*El 72 es flechita arriba*/
			{
				y--;
				if(Vibora[Cabeza[1]-1][Cabeza[0]] == 1)
				{
					printf("Perdiste");
					return 0;
				}	
				Cabeza[1]--;
				timer ++;
				instrucciones[ViboraSize] = 4;
			}
			
			if((comando == 80) && (y < 40)) /*El 80 es flechita abajo*/
			{
				y++;
				if(Vibora[Cabeza[1]+1][Cabeza[0]] == 1)
				{
					printf("Perdiste");
					return 0;
				}
				Cabeza[1]++;
				timer ++;
				instrucciones[ViboraSize] = 3;
			}
																		//Aqui se acaban los comandos que se le pueden dar
			if(Cabeza[0]==80 || Cabeza[1] ==40 || Cabeza[0]==0)			//Esta es la comparacion para la cabeza con las paredes si alcanzas a tocar algunos de los limites con la cabeza
			{
				printf("Perdiste");										//Pues perdiste
				return 0;
			}
			
			
			switch(instrucciones[0])									//Ahora el corazon del codigo, este switch va a ir a la primera instruccion guardada y va a mover la cola
			{															//a esa posicion en base a donde se a movido la serpiente
				case 1:
					Cola[0] = Cola[0] + 1; 								//Si la instruccion fue 1 significa que la cola se debe de mover a la derecha
					
				break;
				
				case 2:													//Si fue 2 a la izquierda
					Cola[0] = Cola[0] - 1;
				break;
				
				case 3:													//3 para abajo
					Cola[1] = Cola[1] + 1;
				break;
				
				case 4:													//y 4 para arriba
					Cola[1] = Cola[1] - 1;
				break;
			}
			
			for(i=0;i<80;i++)										//Una vez que se movio la cola donde debia se debe de perder ese valor de instruccion ya que no nos sirve
			{														//asi que el valor de cada posicion se mueve a la derecha
				instrucciones[i] = instrucciones[i+1];				//osea que el valor 0 toma lo que tenia el valor 1 el 1 llo que tenia el 2 y asi sucesivamente para saber que instruccion
			}														//sigue
			
			Vibora[Cabeza[1]][Cabeza[0]] = 1;						//Simpre ponemos un 1 en la posicion de la cabeza para poder pintarla en la funcion pintavibora
			
			Sleep(Speed);											//Esto es lo que dura pintado todo y de igual manera la velocidad del juego
			
		}
		
}

void PintaVibora (int Vibora[40][80])		/*Funcion para pintar la barra (Solo la pinta, no la mueve)*/
{

int equis;										//En esta funcion recibimos la vibora y si alguno de sus valores es 1 lo pintamos en esa posicion de "x" y "y"
int ye;

	for(equis=0; equis<80; equis++)
	{	
		for (ye = 0; ye < 40;ye++)
		{
			if(Vibora[ye][equis] == 1)
			{
				gotoxy(equis+1,ye+1);
				printf("%c",2);
			
			}
		}
		
	}

	return;
}

void PintarMarco (void)
{
	int x, y;
	
	for(x=0;x<=80;x++)
	{
		for(y=0;y<=40;y++)
		{
			if(x==80 || y ==40 || x==1)
				{
					gotoxy(x,y);
					printf("%c",2);
				}
		}
	
	}

}
