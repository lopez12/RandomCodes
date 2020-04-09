#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menuprincipal (void);
int desplegar_pregunta(int pregunta);
int Validarrespuesta (int pregunta, int respuesta);

int main(void)
{
    
   int pregunta = 0;
   int respuesta = 0;
   int correcto = 0;

   clrscr(); 
   menuprincipal();
   while(1)
   {
       clrscr(); 
       printf("Eligue la pregunta que crees saber\n ");
       
       printf("1.- Pregunta 1?\n ");
       printf("2.- Pregunta 1?\n ");
       printf("3.- Pregunta 1?\n ");
       printf("4.- Pregunta 1?\n ");
       printf("5.- Pregunta 1?\n ");
       printf("6.- Pregunta 1?\n ");
       printf("0.- Salir\n ");
       scanf("%i", &pregunta);
       
       
       if(pregunta !=0)
       {
           respuesta = desplegar_pregunta(pregunta);
           correcto = Validarrespuesta(pregunta,respuesta);
           if(correcto == 1)
           {
              printf("Correcto!!\n");
              getch();                      
           }
           else 
           {
              printf("Incorrecto!!\n");
              getch();    
           }          
    
       }
       else
       {
          printf("Fin del Juego\n");
          getch();	
          return 0;   
       }
    }
  
}

void menuprincipal (void)
{
     clrscr(); 
     printf("Bienvenido a la SUPER TRIVIA\n");
     printf("Press Enter\n");
     getch();
     
     return;
}

int desplegar_pregunta(int pregunta)
{
    int respuesta=0;
     switch(pregunta)
     {
        case 1:
             printf("Pregunta 1?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;
        case 2:
             printf("Pregunta 2?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;     
        case 3:
             printf("Pregunta 3?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;                     
        case 4:
             printf("Pregunta 4?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;
        case 5:
             printf("Pregunta 5?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;
        case 6:
             printf("Pregunta 6?\n ");
             printf("1.- Respuesta 1\n ");
             printf("2.- Respuesta 2\n ");
             printf("3.- Respuesta 3\n ");
             printf("4.- Respuesta 4\n ");
             scanf("%i", &respuesta);
             break;
        default:
                printf("Codigo Invalido");
             break;                       
     }
     
     return respuesta;
          
}

int Validarrespuesta (int pregunta, int respuesta)
{
   if(pregunta == 1 && respuesta == 4 )
           return 1;
   else if (pregunta == 2 && respuesta == 3 )
           return 1;
   else if (pregunta == 3 && respuesta == 2 )
           return 1;
   else if (pregunta == 4 && respuesta == 1 )
           return 1;
   else if (pregunta == 5 && respuesta == 4 )
           return 1;
   else if (pregunta == 6 && respuesta == 3 )
           return 1;
   else 
           return 0;        
    
}
