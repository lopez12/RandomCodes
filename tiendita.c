#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void desplegar_menu (int Arreglo_precios[], int Arreglo_codigos[]);
int Buscar_codigo(int valor_tecleado, int Arreglo_codigos[]);

int main (void)
{	
	int Arreglo_precios[10]={0};  //Arreglo de los precios de los productos
	int Arreglo_codigos[10]={0};  //Arreglo de los codigos de los productos
	int Arreglo_compra[10]={0};   //Arreglo de lo que ha comprado el cliente
	int Codigo_buscado;
	int Precio_total = 0;
	int Resultado_busqueda=0;
	int i;
	int k=0;
	
	clrscr();
	for(i=0;i<=10;i++)
	{
		Arreglo_precios[i]=rand()%20;
		Arreglo_codigos[i]=rand();
	}
	
	desplegar_menu (Arreglo_precios,Arreglo_codigos);
	
	while(Codigo_buscado!=255)
	{
		
		printf("\n(Press 0 to show menu)\nEligue el codigo de producto: ");
		scanf("%i",&Codigo_buscado);
		clrscr();
		if(Codigo_buscado == 0)
		{
			desplegar_menu (Arreglo_precios,Arreglo_codigos);
			printf("\nPara finalizar la compra teclee 255\n");
		}
		
		Resultado_busqueda = Buscar_codigo(Codigo_buscado,Arreglo_codigos);
		
		if(Resultado_busqueda != -1 )
		{
			Arreglo_compra[k]= Arreglo_precios[Resultado_busqueda];
			k++;
		}
		else
		{
			printf("\nCodigo Invalido!\n");
		}
	}
	
	for (i=0; Arreglo_compra[i]!=0;i++)
	{
		Precio_total = Precio_total + Arreglo_compra[i];
	}
	
	printf("Precio Final: %i\n",Precio_total);
	
	
	
	
	return 0;
}

void desplegar_menu (int Arreglo_precios[], int Arreglo_codigos[])
{
	int i;
		printf("Codigo  -  Producto       Precio\n");
	for (i=1;i<10;i++)
	{
		printf("%i      - Coca 100ml       %i\n", Arreglo_codigos[i],Arreglo_precios[i]);
	}
	
}

int Buscar_codigo(int valor_tecleado, int Arreglo_codigos[])
{
	int i;
	
	for (i=0;i<10;i++)
	{
		if (valor_tecleado == Arreglo_codigos[i])
			return i;
	}
	
	return -1;
} 

/*Realice un programa que utilice un arreglo de enteros para almacenar códigos de mercancía 
en una tienda de abarrotes. Utilice otro arreglo de números reales para almacenar el costo 
de cada producto y un arreglo más para ir almacenando la compra que realizará el usuario. 
Despliegue un menú con los nombres de cada producto y el código que le correspondería según
 el orden del arreglo. OJO NO se necesita utilizar arreglos de caracteres, SOLO numéricos.

El usuario deberá teclear un código y si es válido, se anexará al arreglo de "compra” el valor 
de ese producto, si el código es CERO, el programa deberá desplegar nuevamente el menú de opciones 
de compra.

Utilice una función para desplegar los nombres de los productos, códigos y precio de la mercancía. 
Utilice otra función para buscar si el código tecleado es válido (regrese -1 si no existe o la 
posición donde se encuentra almacenado el código en caso contrario).

Sugerencia: Relacione el arreglo de códigos con el de costos por medio del índice. (el 0 de un 
arreglo corresponde al 0 del otro). */