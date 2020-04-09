#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
 
 
 
// M�dulos del Programa
 
 
void Delay(double );
int Titulo(void);
void InicializarSerpiente(int , int [][3], int  );
void Ponercomida(int [][3], int * , int * , int );
void DibujarSerpiente(int , int[][3] ) ;
int Finjuego(int *);
int Comprobarlimites(int [][3], int , int );
void PintarCuadrado(void);
 
void Dibujarcomida(int , int [][3] );   //funcion sin usar.
 
 
 
 
int main()
 
{
 
double delaytime=0.1;
int tamano=4,fin=0, score=0;                  //por defecto inicia la serpiente con 4 de tama�o ,en direccion 'este'.
int aumentarcol=1,aumentarfil=0;
char t,direccion='e';
int contcom=0, tiempocom=0;
int dificil=0;
 
int serpiente[50][3], comida[50][3];
 
 
randomize();
 
dificil=Titulo();  //'Explicacion' de como jugar y titulo/menu del juego.
 
InicializarSerpiente(tamano, serpiente, dificil);
 
 
 
 
 
 
 
while (fin!=1) //captura de teclado
 
{
                if (kbhit())   // si alguna tecla es pulsada entra
        {
                t = getch();
 
                if (t == 27)
      {  //escape
        t=0;
        while (t!=27) // crear seudopausa.
 
         {
         t=getch();
         }
      }
 
 
                if (t == 0 )
                {
                        t = getch();
                        switch (t)      // Mientras que nuestra serpiente vaya hacia un direccion no puede ir a la justo contraria. Ej,
                        {               // Cuando sube no puede bajar directamente, necesita un pasoprevio que es ir a derecha o izq.
 
                                case 72 : if (direccion!='s')    //caso arriba
                         direccion='a';
 
                                        break;
 
                                case  80 : if (direccion!='a')    //caso abajo
                                                                direccion='s';
 
                                break;
 
                                         case  77 :  if (direccion!='o')     //caso derecha
                         direccion='e'  ;
 
                                break;
 
 
                                case  75 : if (direccion!='e')        //caso izquierda
                           direccion='o';
 
                                break;
                }
 
         fflush(stdin);
                }
        }
 
 
 
Ponercomida(comida,&contcom,&tiempocom,dificil);
 
 
if (direccion=='a')
{
 aumentarfil=-1;
 aumentarcol=0;
}
 
if (direccion=='s')
{
        aumentarfil=1;
        aumentarcol=0;
}
if (direccion=='e')
{
   aumentarfil=0;
        aumentarcol=1;
}
if (direccion=='o')
{
 aumentarfil=0;
 aumentarcol=-1;
}
 
 
//comprueba si ha 'comido'
 
        for (int i=0; i<=contcom;i++)
{
        if (serpiente[0][0]==comida[i][0] && serpiente[0][1]==comida[i][1])
   {  tamano++;
 
        for (int aux=i;aux<=contcom;aux++)
      {                                           //esto deberia borrar el elemento que ya ha 'comido'
         comida[aux][0]=comida[aux+1][0];
         comida[aux][1]=comida[aux+1][1];
 
      }
 
       contcom--;
 
       //cuanto m�s coma mas puntos y mas rapido ira el juego , comprobamos tambien si ha comido un especial
 
 
                 if (comida[i][2]==1) score=score+(40*(tamano-4));
       else score=score+(20*(tamano-4));
 
       delaytime=delaytime-0.002;
   }
 
}
 
//borrar cola, va a la ultima posicion y borra.
 
gotoxy(serpiente[tamano][0],serpiente[tamano][1]);
printf(" ");
 
//'empuja' el array , la ultima posicion se pierde
 
for (int i=tamano;i>=1;i--)
{
 
serpiente[i][0]=serpiente[i-1][0];
serpiente[i][1]=serpiente[i-1][1];
 
}
 
//realiza aumentos segun direccion
 
serpiente[0][0]=serpiente[0][0]+aumentarcol;
serpiente[0][1]= serpiente[0][1]+aumentarfil;
 
 
//comprueba limites de la pantalla y choques con el cuerpo de la serpiente
 
if (Comprobarlimites(serpiente, dificil, tamano)==1)
{
int finjuego=Finjuego(&score);
 
                        // si el usuario desea seguir jugando , se ponen las variables a sus valores iniciales ( esto creo que deberia modularlo xD)
    if (finjuego==0)
    {
    tamano=4;
    contcom=0;
    direccion='e';
    score=0;
         delaytime=0.1;
    InicializarSerpiente(tamano, serpiente, dificil);
    }
    else (fin)=1;
}
 
 
DibujarSerpiente(tamano, serpiente);
 
 
if (dificil==0) score++;
 
gotoxy(68,3);
printf("Score : %00d",score);
 
 
Delay(delaytime);
 
 
 
 
}
 
 
 
 
getch();
return 0;
 
 
}
 
void Delay(double delaytime)   //funcion para 'ralentizar el tiempo'
{
 
 clock_t start_time;//, cur_time;
                        start_time = clock();
                        while((clock() - start_time) < delaytime * CLOCKS_PER_SEC)
                        {
                        }
 }
 
int Titulo(void)
 
 {
const int POSICION1=20 , POSICION2=21 , POSICION3=22, cursorx=19 ;
int cursory=POSICION1 , fin=0,dificultad=0;
int cursor=219; // caracter de cuadrado
char t;
 
printf("\n          ..######..##....##....###....##....##.########");
printf("\n          .##....##.###...##...##.##...##...##..##......");
printf("\n          .##.......####..##..##...##..##..##...##......");
printf("\n          ..######..##.##.##.##.....##.#####....######..");
printf("\n          .......##.##..####.#########.##..##...##......");
printf("\n          .##....##.##...###.##.....##.##...##..##......");
printf("\n          ..######..##....##.##.....##.##....##.########");
 
printf("\n \n             DA GEIM aka El Juego by paytoNftw");
 
printf("\n \n \n Mueve la serpiente con las teclas de direccion y hazla comer para crecer :D. \n Las comidas azules suman el doble que las normales . \n");
 
printf("\n Elige la opcion que desees con el cursor y pulsa ENTER para continuar");
 
gotoxy(cursorx,cursory);
printf("%c", cursor );
 
gotoxy(cursorx+2,POSICION1);
printf("1. Jugar ahora!");
 
gotoxy(cursorx+2,POSICION2);
printf("2. Cambiar nivel de dificultad: Facil");
 
gotoxy(cursorx+2,POSICION3);
printf("3. Ver maximas puntuaciones");
 
 
while (fin!=1)
 
        {
                if (kbhit())   // si alguna tecla es pulsada entra
        {
                t = getch();
 
                if (t==13)
                {
 
 
 
                switch(cursory)
                {
                case POSICION1:
                clrscr();
      fin=1;
                break;
 
                case POSICION2:
      if (dificultad==0)
        {
         gotoxy(cursorx+2,POSICION2);
                        printf("                                                     ");
         gotoxy(cursorx+2,POSICION2);
                        printf("2. Cambiar nivel de dificultad: Dificil");
 
         dificultad=1;
 
        }
      else
      {
 
        gotoxy(cursorx+2,POSICION2);
                        printf("                                                     ");
         gotoxy(cursorx+2,POSICION2);
                        printf("2. Cambiar nivel de dificultad: Facil");
 
          dificultad=0;
      }
 
                break;
 
                case POSICION3:
 
                break;
 
                        }
                }
                else
                if (t == 0 )
                {
                        t = getch();
 
                        switch (t)
                        {
                                case 72 :
                                 //caso arriba
 
                                 gotoxy(cursorx,cursory);
                                 printf(" "); // borrar cursor
                                 if (cursory==POSICION1) cursory=POSICION3;
 
                                 else cursory--;
 
                                 gotoxy(cursorx,cursory);
                                 printf("%c", cursor );
 
 
 
 
                                        break;
 
                                case  80 : //caso abajo
                                          gotoxy(cursorx,cursory);
                                 printf(" ");      // borrar cursor
                                 if (cursory==POSICION3) cursory=POSICION1;
                                 else cursory++;
 
                                 gotoxy(cursorx,cursory);
                                 printf("%c", cursor );
 
                                 break;
 
                        }
                }
        }
}
 
 
clrscr();
 
return dificultad;
 
 
}
 
void Ponercomida(int comida[][3],int * contcom, int * tiempocom, int dificil)
{
 
 
int altcomida=random(20);   //tiempo aleatorio de aparicion de comida
 
 
 
if (altcomida==10 && (*contcom)<5)  //  solo puede haber 5 comidas en juego
        {
        int c=2;
        if (dificil==1)
        {
          comida[*contcom][0]=random(40)+16;    //posicion aleatoria x,y  para nivel dificil
    comida[*contcom][1]=random(8)+7;
          comida[*contcom][2]=random(3);
  }
  else
  {
        comida[*contcom][0]=random(76)+2;    //posicion aleatoria x,y y si se trata de comida especial (doble de puntos) o normal
        comida[*contcom][1]=random(22)+2;
        comida[*contcom][2]=random(3);
  }
        gotoxy(comida[*contcom][0],comida[*contcom][1]);
 
        textcolor(WHITE);
        if (comida[*contcom][2]==1) textcolor(LIGHTCYAN);
        cprintf("%c",c);
 
                (*contcom)++;
 
                if (*tiempocom==0) (*tiempocom)=1;   //inicializa la variable que borrar� la comida
        }
 
 
                if (tiempocom!=0) //si esta inicializada...
        {
                (*tiempocom)++;
                        if (*tiempocom>40)
                        {
                         (*tiempocom)=1;                 // borra la primera comida que se ha puesto y se empuja el array
 
                         gotoxy(comida[0][0],comida[0][1]);
 
                         printf(" ");
 
                         (*contcom)--;
 
 
                         //empujamos array de comida
                                for (int i=0;i<=*contcom;i++)
                                {
                                comida[i][0]=comida[i+1][0];
                                comida[i][1]=comida[i+1][1];
 
                                }
 
                         }
        }
}
 
 
void DibujarSerpiente(int tamano, int serpiente[][3])
{
 
        for (int i=0;i<=tamano;i++)
        {
                                                                                                  //recorre todo el array , pinta de rojo todo excepto la cabeza (indice 0) que la pinta de verde.
        int c=254;
        textcolor(RED);
        if (i==0) textcolor(GREEN);
        gotoxy(serpiente[i][0],serpiente[i][1]);
        cprintf("%c",c);
 
        }
}
 
void InicializarSerpiente(int tamano,int serpiente[][3] ,int dificil)
{
 
clrscr();
 
 
   if  (dificil==1)
   {
    serpiente[0][0]=random(30)+20;
    serpiente[0][1]=random(10)+7;
    PintarCuadrado();
   }
   else
   {
serpiente[0][0]=random(60)+3;  //valores iniciales
serpiente[0][1]=random(15)+2;
  }
 
        for (int i=1;i<=tamano;i++)
        {
        serpiente[i][0]=serpiente[0][0]-i;     //serpiente 'recta' de tama�o 4(por defecto)
        serpiente[i][1]=serpiente[0][1];
 
        }
 
        for (int i=tamano;i<=30;i++)
        {
        serpiente[i][0]=0;
        serpiente[i][1]=0;
        }
}
 
void Dibujarcomida(int contcom, int comida[][3])   //funcion no usada.
{
 
        for (int i=0;i<=contcom;i++)
        {
 
        int c=3;
 
 
        gotoxy(comida[i][0],comida[i][1]);
        printf("*");
 
        }
}
int Finjuego(int * score)
{
clrscr();
  char volver;
  int resultado;
 
   gotoxy(25,20);
   printf("Has perdido :( Tu puntuacion ha sido de %d puntos",*score);
   gotoxy(25,21);
 
   printf("�Quieres volver a jugar? (S/N): ");
   scanf("%c",&volver);
 
   if (volver=='S' || volver=='s')
   return 0;
   else if (volver=='N' || volver=='n') return 1;
 
 
}
int Comprobarlimites(int serpiente[50][3], int dificil, int tamano)
{
int x, y;
 if (dificil==1)
 {
        for (x=16;x<=65;x++)
        {
        if ((serpiente[0][0]==x && (serpiente[0][1]==6 || serpiente[0][1]==20)) || (serpiente[0][0]<=15 || serpiente[0][0]>64))
      return 1;
        }
 }
 
 for (int i=1;i<=tamano;i++)
        {
                if (serpiente[0][0]==serpiente[i][0] && serpiente[0][1]==serpiente[i][1]) return 1;
        }
 
 
if (serpiente[0][0]==79)  serpiente[0][0]=2;
if (serpiente[0][0]==1)  serpiente[0][0]=78;
 
if (serpiente[0][1]==1)  serpiente[0][1]=23;
if (serpiente[0][1]==24)  serpiente[0][1]=2;
 
return 0;
 
 
}
 
void PintarCuadrado(void)
{
//limites de este cuadrado son definibles , simplemente cambiar las variablas xprincipio , xfinal etc.
int x,y;
int lateral=186,esquinasupder=187,esquinasupizq=201,esquinainfizq=200,esquinainfder=188,base=205;
 
int xprincipio=15,xfinal=65,yprincipio=6,yfinal=20;
 
for (int x=xprincipio;x<=xfinal;x++)
{
 
if (x==xprincipio)
        {
        for (int y=yprincipio;y<=yfinal;y++)
        {
        gotoxy(xprincipio,y);
                printf("%c",lateral);
                gotoxy(xfinal,y);
                printf("%c",lateral);
 
                }
 
   }
        gotoxy(x,yprincipio);
        printf("%c",base);
        gotoxy(x,yfinal);
        printf("%c",base);
}
//ajustes de esquinas
 
gotoxy(xprincipio,yprincipio);
printf("%c",esquinasupizq);
 
gotoxy(xfinal,yprincipio);
printf("%c",esquinasupder);
 
gotoxy(xprincipio,yfinal);
printf("%c",esquinainfizq);
 
gotoxy(xfinal,yfinal);
printf("%c",esquinainfder);
}