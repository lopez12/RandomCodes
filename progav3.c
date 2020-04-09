#include<stdio.h>
void InvertirCaden (char *CadenaAInvertir); //El probelma 2;
void CortarCadena (char *CadenaACortar, char caracterCortado); //El problema 4
void ConcatenarCadena (char *Cadena1, char *Cadena2); //El problema 6

int main (void)
{
	char Cadena1[20]={0};
	char Cadena2[20]={0};
	InvertirCaden ("Hola");
	CortarCadena ("Programacion",'c');
	printf("Primera Cadena: ");
	scanf("%s",&Cadena1);
	printf("Segunda Cadena: ");
	scanf("%s",&Cadena2);
	ConcatenarCadena(&Cadena1,&Cadena2);
	
	return 0;
}

void InvertirCaden (char *CadenaAInvertir)
{
	char Invertida[20]={0};
	int sizecadena = 0;
	int array=0;
	
	while(*CadenaAInvertir)
	{	
		sizecadena++;
		CadenaAInvertir++;
	}
	
	while(sizecadena+1)
	{
		Invertida[array] = *CadenaAInvertir;
		printf("%c",Invertida[array]);
		CadenaAInvertir--;
		array++;
		sizecadena--;
	}
	
	
	return;
}

void CortarCadena (char *CadenaACortar, char caracterCortado)
{
	char *CadenaCortada;
	while(*CadenaACortar)
	{
		if(*CadenaACortar == caracterCortado)
		{	
			CadenaCortada = CadenaACortar;
		}
		CadenaACortar++;
	}
	while(*CadenaCortada)
	{
		printf("%c",*CadenaCortada);
		CadenaCortada++;
	}
	return;
}

void ConcatenarCadena (char *Cadena1, char *Cadena2)
{
	char *Final ;
	Final = Cadena1;
	while(*Cadena1)
	{
		Cadena1++;
	}
	while(*Cadena2)
	{
		*Cadena1 = *Cadena2;
		Cadena1++;
		Cadena2++;
	}

	Cadena1 = Final;
	
	while(*Cadena1)
	{
		printf("%c",*Cadena1);
		Cadena1++;
	}
	return;
}

/*
¿Qué es un apuntador a un apuntador?
Es un referencia que hace referencia a diferentes referecias
¿Qué diferencia existe entre pasar el valor a una función y pasar el apuntador?
Que el valor es solo el valor numérico y el apuntador pasa la referencia (La dirección en memoria) del dato
En apuntadores a estructuras que se utiliza en lugar del punto “.”
La flecha ->
¿Qué funciones se utilizan para escribir  y leer en archivos de texto o binarios? Da un ejemplo
Fwrite y fread
¿Qué función se utiliza para abrir y cerrar un archivo de texto o binario?
Fopen y fclose
¿Con qué permisos se puede abrir o crear un archivo?
w
Escribe una instrucción que te permita moverte dentro del archivo binario o de texto.

Que diferencia existe entre los archivos binarios y de texto(UNIX)
El cuando se debe de mover para poder hacer la lectura de los datos (la encriptacion)
¿Qué es un apuntador a una función? ¿Para qué nos servía en la práctica apuntadores a funciones?
Para poder ejecutar funciones con diferentes estados
¿Qué permite el uso de archivos?

Adicional.  ¿Para qué sirven las listas enlazadas?
Para hacer referencias dinámicas.
*/