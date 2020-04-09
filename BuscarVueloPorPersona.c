#include<stdio.h>
#include<string.h>
struct reservacion * BuscarPersona(struct reservacion *spRes, char bpNombre[20],char bpApellido[20]);

struct fecha{
			char dia;
			char mes;
			char ano;
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
	struct reservacion *spRes;
	struct reservacion *RetornoFuncion;  //Este es el pauntador de regreso
	spRes = &Reservation[0];									//
	strcpy(Reservation[0].ResPersona.nombre, "Arturo");			//	
	strcpy(Reservation[0].ResPersona.apellido, "Lopez");		//  Aqui lleno los arreglos para hacer la prueba
	Reservation[0].ResPersona.asiento = 1;						//
	Reservation[0].CodigoRes = 101;								//
	strcpy(VuelosArray[0].origen, "Monterrey");					//
	strcpy(VuelosArray[0].destino, "CiudadMexico");
	VuelosArray[0].FechaVuelo.dia = 10;
	VuelosArray[0].FechaVuelo.mes = 02;
	VuelosArray[0].FechaVuelo.ano = 2013;
	VuelosArray[0].FechaVuelo.ID = 1022;
	strcpy(VuelosArray[0].FechaVuelo.disponibilidad, "SiHay");
	Reservation[0].ResPersona.primervuelo = &VuelosArray[0];
	RetornoFuncion = BuscarPersona(spRes, "Arturo","Lopez"); 	//Aqui mando a llamar la funcion, necesita el apuntador a la lista y los nombres
	if(RetornoFuncion)
	{
		printf("Vuelo De %s ",(*RetornoFuncion).ResPersona.primervuelo->origen);	//Imprimo el contenido del apuntador regresado para ver el valor
		printf("A %s ",(*RetornoFuncion).ResPersona.primervuelo->destino);			//
	}
	else{
		printf("Usuario No encontrado");					//Si no lo encuentra
	}
	
	
	
	return;
}

struct reservacion * BuscarPersona(struct reservacion *spRes, char bpNombre[20],char bpApellido[20])
{
	//while(ExistanResrvaciones)
	if(!strcmp(bpNombre,(*spRes).ResPersona.nombre) && !strcmp(bpApellido,(*spRes).ResPersona.apellido))
	{
		return spRes;
	}
	else{
		return 0;
		//Aqui debes de moverte en la lista enlazada
	}
	
	
}

struct reservacion* CambiarVuelo (struct reservacion *spRes, )
{

	
}

