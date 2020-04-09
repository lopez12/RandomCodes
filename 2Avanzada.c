/*Escriba un programa que permita registrar preguntas (10 máximo) para un examen:
Todas las preguntas tienen el formato verdadero/falso, también se debe de alimentar la respuesta correcta para cada pregunta cargada
Utilize estructuras para almacenar los datos del examen
Al terminar de cargar las preguntas, el programa debe solicitar un nombre para guardar los datos y almacenarlo*/

#include <stdio.h>
#include <stdlib.h>

void CaputarPregunta (struct Pregunta *apuntador_quiz);
unsigned char Cambio_SiPorUno(unsigned char *Cadena);

struct Pregunta
{
	unsigned char Pregunta[20]; 
	unsigned char Respuesta;
} Pregunta[5];


int main (void)
{
	FILE *fichero;
	struct Pregunta *apuntador_quiz;
	unsigned char RespuestaUsuario[2]={0};
	unsigned char RespuestaUsuarioComparar;
	int i=5;
	int PromedioQuiz = 0;
	apuntador_quiz = &Pregunta[0];
	
	while(i--)
	{
		CaputarPregunta(apuntador_quiz);
		apuntador_quiz++;
	}

	fichero = fopen("examen.dat","w+");
	if(fichero)
		printf(" Fichero Abierto\n");
	else
	{
		printf("Error: Fichero NO Abierto\n");
		return 1;
	}
	fwrite(&Pregunta[0], sizeof(struct Pregunta),5,fichero);
	fclose(fichero);
	i=5;
	apuntador_quiz = &Pregunta[0];
	
	fichero = fopen("examen.dat","w+");
	rewind(fichero);
	while(i--)
	{
		fread(apuntador_quiz, sizeof(struct Pregunta),1,fichero);
		printf("%s\n",apuntador_quiz->Pregunta);
		
		printf("Respuesta: ");
		scanf("%s",&RespuestaUsuario);
		RespuestaUsuarioComparar = Cambio_SiPorUno(&RespuestaUsuario);
		printf("%i\n",RespuestaUsuarioComparar);
		if(apuntador_quiz->Respuesta==RespuestaUsuarioComparar)
		{
			PromedioQuiz+=1;
		}
		apuntador_quiz++;
	}
	
	printf("%i",PromedioQuiz*100/5);
	
	return 0;
}

void CaputarPregunta (struct Pregunta *apuntador_quiz)
{
	unsigned char RespuestaEnCadena[2]={0};
	printf("Pregunta: ");
	scanf("%s",&apuntador_quiz->Pregunta);
	printf("Respuesta: ");
	scanf("%s",&RespuestaEnCadena);
	apuntador_quiz->Respuesta = Cambio_SiPorUno(&RespuestaEnCadena);
}

unsigned char Cambio_SiPorUno(unsigned char *Cadena)
{
	if((*Cadena == 'S' || *Cadena == 's') && (*(Cadena+1) == 'I' || *(Cadena+1) == 'i'))
		return 1;
	else return 0;
	
}