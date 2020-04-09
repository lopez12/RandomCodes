#include<stdio.h>
#include<conio.h>

char SeleccionViaje (void);
float LlenoTanque(void);
void SeleccionTanque (char viajeselection,float PorcentajeTanque);

int main (void)
{
	char viajeselection;
	float PorcentajeTanque=0;
	
	viajeselection = SeleccionViaje();
	PorcentajeTanque = LlenoTanque();
	SeleccionTanque(viajeselection,PorcentajeTanque);
	
	return 0;
}

char SeleccionViaje (void)
{
	char viaje;
	printf("Selecciona el viaje que se hara\nA)Siderurgica\nB)Hidroelectrica\nC)Minas Zacatecas\n");
	viaje=getch();
	
	return viaje;
}

void SeleccionTanque (char viajeselection, float PorcentajeTanque)
{
	float precio;
	float tanque;
	float kilometrosRestantes=0;
	
	tanque = PorcentajeTanque * 50;
	kilometrosRestantes = tanque * 17;
	switch(viajeselection)
	{
		case 'A':
			kilometrosRestantes = 1200 - kilometrosRestantes;
			precio = (kilometrosRestantes/17)*15;	
			printf("Necesitas %f pesos",precio);
		break;
		
		case 'B':
			kilometrosRestantes = 3800 - kilometrosRestantes;
			precio = (kilometrosRestantes/17)*15;
			printf("Necesitas %f pesos",precio);
		break;
		
		case 'C':
			kilometrosRestantes = 3200 - kilometrosRestantes;
			precio = (kilometrosRestantes/17)*15;
			printf("Necesitas %f pesos",precio);
		break;
		
		default:
			printf("Opcion no valida");
		break;
	}
	return;
}

float LlenoTanque(void)
{
	char tanque;
	float valor;
	printf("Selecciona cuanta cantidad del tanque tienes\nA)Un cuarto\nB)Medio Tanque\nC)Tres cuartos\nD)Lleno\n");
	scanf("%c",&tanque);
	switch(tanque)
	{
		case 'A':
			valor = 0.25;
		break;
		
		case 'B':
			valor = 0.5;
		break;
		
		case 'C':
			valor = 0.75;
		break;
		
		case 'D':
			valor = 1;
		break;
		
		default:
			printf("Opcion no valida");
		break; 
	}
	
	return valor;
}