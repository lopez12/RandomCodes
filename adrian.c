int Suma (int Numero1,int Numero2);
int ContadorArreglo (char *apuntador);
void vfnMemCpy (int *apuntador1, int *apuntador2, int tamano);

void main (void)
{
	char variable1 = 'H';
	char variable2 = 'o';
	char variable3 = 'l';
	char variable4 = 'a';
	
	int *apuntador;
	
	char Arreglo[4];
	int Arreglo1[5] = {1,2,3,4,0};
	int Arreglo2[5] ={0};
	
	int resultado;
	
	Arreglo[0] = variable1;
	Arreglo[1] = variable2;
	Arreglo[2] = variable3;
	Arreglo[3] = variable4;
	
	vfnMemCpy(Arreglo1,Arreglo2,5);
	
	apuntador = Arreglo2;
	
	while(*apuntador)
	{
		printf("%i",*apuntador);
		apuntador++;
	}
	
	apuntador = Arreglo;

	
	resultado = ContadorArreglo (Arreglo);
	
	//printf("%i",resultado);
	//printf("%i",resultado);
	//printf("<cadenas> %(tipo_dato_a_imprimir)",(variable));
	return;
}

int Suma (int Numero1,int Numero2)
{
	int resultado;
	
	resultado = Numero1 + Numero2;
	
	return resultado;
}

int ContadorArreglo (char *apuntador)
{
	int contador = 0;
	while(*apuntador)
	{
		apuntador++;
		contador++;
	}
	return contador;
}

void vfnMemCpy(int *apuntador1,int *apuntador2,int tamano)
{
	while (tamano)
	{
		*apuntador2 = *apuntador1;
		apuntador1++;
		apuntador2++;
		tamano--;
	}
}

/*int = enteros		(32-16 bits)
char =  caracteres	(8 bits)
float = punto flotante (numeros muy grandes y decimales)	(32 bits)
void = nada			(0 bits)

funciones = modulos

tipo_de_dato <Nombre_Funcion> (tipos_datos_recibidos)

apuntadores
*/