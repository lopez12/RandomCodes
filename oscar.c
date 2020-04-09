#include<stdio.h>
//Esta es la estructura de la fecha
struct fecha{
	char dia[2];  //Dia de dos letras '1''0' es por ejemplo el dia 10
	char mes[2];  //Mes
	char ano[4];  //Año
}fecha1; 			//Aqui se pone fecha1 porque es como declarar una varaiable de tipo struct fecha pero de manera mas rapida

char * Representacion (struct fecha *apuntador); 						//Prototipo de funcion de representacion
int Comparacion (struct fecha *apuntador1,struct fecha *apuntador2);	//Prototipo de funcion de comparacion
char * ReturnString(struct fecha *pCharMonth);

int main (void)
{
	char *Mes;
	struct fecha *apuntador,*apuntador2;  		//Declaramos los dos apuntadores a las diferntes tipos de estructuras para poder manejarlas
	struct fecha fecha2;						//Declaramos un segundo tipo de dato struct fecha para hacer las comparaciones entre ellas
	char *regresocadena;						//Esta variable se utilizara para guardar el retorno del apuntador de la funcion representacion
	int regresocomparar=0;						//Esta variable se utilizara para guardar el retorno de la funcion comparacion
	fecha1.dia[0]='1';							//Aqui llenamos la primera variable de fecha
	fecha1.dia[1]='1';
	fecha1.mes[0]='1';
	fecha1.mes[1]='1';
	fecha1.ano[0]='2';
	fecha1.ano[1]='0';
	fecha1.ano[2]='1';
	fecha1.ano[3]='5';
	
	fecha2.dia[0]='1';							//Aqui llenamos la segunda variable de fecha
	fecha2.dia[1]='1';
	fecha2.mes[0]='1';
	fecha2.mes[1]='1';
	fecha2.ano[0]='2';
	fecha2.ano[1]='0';
	fecha2.ano[2]='1';
	fecha2.ano[3]='5';							//Modificamos el ultimo valor de año para que sea distintos
	apuntador = &fecha1;						//Hago el primer apuntador que apunte a fecha1
	apuntador2 = &fecha2;						//Hago el segundo apuntador al valor que apunta a la fecha2
	
	regresocadena = Representacion(apuntador);	//Mando a llamar la funcion de representacion con el parametro apuntador que apunta al primer valor de fecha y regresa un apuntador el cual es el valor de regresocadena
	
	while(*regresocadena)						//Una vez que tenemos el apuntador que contiene la cadena nos movemos mientras tenga un contenido distinto de final de cadena
	{
		printf("%c",*regresocadena);			//Imprimimos cada caracter por separado para que finalmente se unan en una oracion
		regresocadena++;						//y cada vez que imprimos un caracter avanzamos en el apuntador
	}
	regresocomparar = Comparacion (apuntador,apuntador2); //Mandamos a llamar la funcion de comparacion la cual necesita dos apuntadores de tipo struct fecha y regresa un valor entero que guardaremos en regresocomparar
	if(!regresocomparar)						//Si regreso 0 significa que son iguales y es negacion de un false
		printf("\nSon iguales");
	else if(regresocomparar == 1)				
		printf("\nNo son iguales, la cadena 1 es mayor");
	else if(regresocomparar == -1)
		printf("\nNo son iguales, la cadena 2 es mayor");
	
	Mes = ReturnString(apuntador); 				//El apuntador a la cadena de el mes apuntado por el apuntador
	printf("\n%c%c de %s del %c%c%c%c",apuntador->dia[0],apuntador->dia[1],Mes,apuntador->ano[0],apuntador->ano[1],apuntador->ano[2],apuntador->ano[3]); //Imprimir los datos
	return 0;
}

char * Representacion (struct fecha *apuntador)
{
	char *cadena;									//Creamos un apuntador de tipo char porque es lo que vamos a regresar la funcion
	
	*cadena = apuntador->dia[0];					//LLenamos el apuntador con valor numerico separado que tiene cada dato de la estructura
	*(cadena+1) = apuntador->dia[1];				//No hacemos cadena++ porque eso mueve la posicion del apuntador
	*(cadena+2) = apuntador->mes[0];				//Pero no quiero mover el apuntador lo unico que se quiere hacer el modificar el contenido
	*(cadena+3) = apuntador->mes[1];				//Del apuntador y regresar cadena porque esa se quedo en la posicion original
	*(cadena+4) = apuntador->ano[0];
	*(cadena+5) = apuntador->ano[1];
	*(cadena+6) = apuntador->ano[2];
	*(cadena+7) = apuntador->ano[3];
	
	return cadena;									//Ya lleno el apuntador se regresa a la funcion main

} 

int Comparacion (struct fecha *apuntador1,struct fecha *apuntador2) //Aqui tenemos el incio de funcion
{

	if(apuntador1->dia[0]==apuntador2->dia[0] && apuntador1->dia[1]==apuntador2->dia[1] && apuntador1->mes[0]==apuntador2->mes[0] && apuntador1->mes[1]==apuntador2->mes[1] && apuntador1->ano[0]==apuntador2->ano[0] && apuntador1->ano[1]==apuntador2->ano[1] && apuntador1->ano[2]==apuntador2->ano[2] && apuntador1->ano[3]==apuntador2->ano[3])
		return 0;										//Si cada uno de los apartados en los apuntadores son iguales regresamos cero
	else if(apuntador1->ano[0] > apuntador2->ano[0] || apuntador1->ano[0] == apuntador2->ano[0] && apuntador1->ano[1] > apuntador2->ano[1] || apuntador1->ano[0] == apuntador2->ano[0] && apuntador1->ano[1] == apuntador2->ano[1] && apuntador1->ano[2] > apuntador2->ano[2] || apuntador1->ano[0] == apuntador2->ano[0] && apuntador1->ano[1] == apuntador2->ano[1] && apuntador1->ano[2] == apuntador2->ano[2] && apuntador1->ano[3] == apuntador2->ano[3])	
	{	
		return 1;										//Aqui se comparan los años
	}		
	else if(apuntador1->mes[0] > apuntador2->mes[0] || apuntador1->mes[0] == apuntador2->mes[0] && apuntador1->mes[1] > apuntador2->mes[1]  ) 	
	{
		return 1;										//Aqui se comparan los meses
	}
	else if(apuntador1->dia[0] > apuntador2->dia[0] || apuntador1->dia[0] == apuntador2->dia[0] && apuntador1->dia[1] > apuntador2->dia[1])
		return 1;										//Aqui se comparan los dias
	else												//Si no logro 
		return -1;
}

char * ReturnString(struct fecha *pCharMonth)
{
	char * mes[] = {                 
					"mes ilegal", 
                     "enero", 
                     "febrero", 
                     "marzo", 
                     "abril", 							//Se crea el arreglo de apuntadores a cadenas enumeradas para los meses
                     "mayo", 
                     "junio", 
                     "julio", 
                     "agosto", 
                     "septiembre", 
                     "octubre", 
                     "noviembre", 
                     "diciembre", 
                         };
						 
	if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '1')
		return mes[1];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '2')
		return mes[2];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '3')
		return mes[3];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '4')
		return mes[4];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '5')
		return mes[5];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '6')
		return mes[6];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '7')			//Se hace la comparacion con cada uno de los datos
		return mes[7];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '8')
		return mes[8];
	else if(pCharMonth->mes[0]=='0' && pCharMonth->mes[1] == '9')
		return mes[9];
	else if(pCharMonth->mes[0]=='1' && pCharMonth->mes[1] == '0')
		return mes[10];
	else if(pCharMonth->mes[0]=='1' && pCharMonth->mes[1] == '1')
		return mes[11];
	else if(pCharMonth->mes[0]=='1' && pCharMonth->mes[1] == '2')
		return mes[12];
	else
		return mes[0];														//y regresa cadena invalida en caso de no cunmplir con los 12 meses
}

