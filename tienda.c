#include <stdio.h>
#include <stdlib.h>
char menu();
char OpcionDeMenu;

int opcionA(int Ventas [12][3]);
int opcionB(int Ventas[12][3],int decision);
int opcionC(int Ventas[12][3]);
int main() 
{
int decision=0;
int Ventas[12][3] = {{265180,128342,272474},
					{179445,186497,270691},
					{195620,167921,292188},
					{203780,239944,192384},
					{168815,262622,105459},
					{145820,127323,216685},
					{226534,298360,269474},
					{195987,115133,293394},
					{171945,136510,125418},
					{286685,263468,258045},
					{243514,265935,264416},
					{168343,236771,292351}};
		while (1){
		
			switch (menu())
		{
				case 'a': 
					printf ("Ventas totales del año de todas las sucursales: %i\n",opcionA(Ventas));
					
				break;
				
				case 'b': 
					printf ("Ventas totales del año de una sucursal, selecciona la sucursal:\n");
					scanf("%i",&decision);
					fflush( stdin );
					printf ("Ventas totales del año de la sucursal: %i \n ",opcionB(Ventas,decision));
				break;
				case 'c': 
					printf("Ventas Totales de todas las sucursales en cierto mes\n Selecciona el mes: %i\n",opcionC(Ventas));
				break;
				case 'd': 
					printf("Sucursal que más vendió en todo el año:\n");
				break;
				case 'e': 
					printf("Sucursal que menos vendió en todo el año: \n");
				break;
				case 'f': 
					printf("Sucursal que más vendió en cierto mes\n Selecciona el mes: \n"); 
				break;
				case 'g': 
					printf("Sucursal que menos vendió en cierto mes\n Selecciona el mes: \n");
				break;
				case 'h': 
					printf ("Adiós\n");
					return 0; 
				break; 
				default: 
					printf("Opción no válida\n");
				break;
		}
		
		
				}//Fin del while
			return 0;
			
} //fin del main
char menu() {	
	
		printf ("\n\nMENU PRINCIPAL\n\n");
		printf("a. Calcular las ventas totales del año de todas las sucursales\n\n");
		printf("b. Calcular las ventas totales de una sucursal en particular en todo el año\n\n");
		printf("c. Calcular las ventas totales de un mes en particular de todas las sucursales\n\n");
		printf("d. Determinar la sucursal que más vendió en todo el año\n\n");
		printf("e. Determinar la sucursal que menos vendió en todo el año\n\n");
		printf("f. Determinar la sucursal que más vendió en un mes en particular\n\n");
		printf("g. Determinar la sucursal que menos vendió en un mes en particular\n\n");
		printf("h. Salir\n");
		scanf("%c", &OpcionDeMenu);
		fflush( stdin );
		
return OpcionDeMenu;
	}
	
	
int opcionA(int Ventas [12][3])
{ 
	int total = 0; 
	int i,j;
	
	for (i=0 ; i<12 ; i++ )
	{
		for (j=0 ; j<3 ; j++)	
			total = Ventas[i][j] + total ;
	}
	
	
return total; }


int opcionB(int Ventas[12][3],int decision)
{
	int total=0;
	int i;
	for (i=0 ; i<12 ; i++)
		{
			total = Ventas[i][decision-1] + total;
		}	
			
	return total;
}

int opcionC(int Ventas[12][3])
{

	int total= 0; 
	int decision = 0; 
	int j;
	
	printf ("Selecciona el mes: \n 1.- Enero\n 2.- Febrero\n 3.- Marzo\n 4.- Abril\n 5.-Mayo\n 6.-Junio\n 7.-Julio\n 8.-Agosto\n 9.-Septiembre\n 10.Octubre\n 11.Noviembre\n 12.Diciembre\n");
	scanf("%i",&decision);
	fflush( stdin );
	for (j=0; j<3; j++)
	
		{
			total = Ventas[decision-1][j] + total;
		}
	return total;
}