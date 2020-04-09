#include<stdio.h>
#include<string.h>

void LlenarVueloData (struct vuelo *vuelo);

struct fecha{
			char dia[4];
			char mes[4];
			char ano[4];
			int ID;
			char disponibilidad[13];
};

struct vuelo{
			char origen[20];
			char destino[20];
			struct fecha FechaVuelo;
			struct vuelo *siguienteVuelo;
};

struct persona{
			char nombre[20];
			char apellido[20];
			int asiento;
			struct vuelo *primervuelo;
			struct persona *siguientePersona;
};

struct reservacion{

			struct persona ResPersona;
			int CodigoRes;
			struct reservacion *siguientereservacion;

};

	struct reservacion Reservation[5];
	struct vuelo VuelosArray[5];
	
int main (void)
{
	
	struct vuelo *vuelo;		
	vuelo = &VuelosArray[0];	

	LlenarVueloData(vuelo); //Mandas a llamar la funcion
	
	//Todo el vuelo llenado queda guardado en el contenido del apuntador vuelo
	printf("\n\nResumen de Vuelo\nOrigen: %s Destino: %s\n",(*vuelo).origen,(*vuelo).destino);
	printf("Fecha: %s/%s/%s \n",(*vuelo).FechaVuelo.dia,(*vuelo).FechaVuelo.mes,(*vuelo).FechaVuelo.ano);
	printf("ID: %i\n",(*vuelo).FechaVuelo.ID);
	printf("Disponibilidad: %s",(*vuelo).FechaVuelo.disponibilidad);
	
	
	return;
}

void LlenarVueloData (struct vuelo *vuelo)
{
	printf("Origen: ");
	scanf("%s",&((*vuelo).origen));
	printf("Destino: ");
	scanf("%s",&((*vuelo).destino));
	printf("Fecha:\n");
	printf("Ano: ");
	scanf("%s",&((*vuelo).FechaVuelo.ano));
	printf("Mes: ");
	scanf("%s",&((*vuelo).FechaVuelo.mes));
	printf("Dia: ");
	scanf("%s",&((*vuelo).FechaVuelo.dia));
	printf("ID: ");
	scanf("%i",&((*vuelo).FechaVuelo.ID));
	printf("Disponibilidad: ");
	scanf("%s",&((*vuelo).FechaVuelo.disponibilidad));

	return;
}

