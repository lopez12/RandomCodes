int Vender(struct Vuelo *p);
void Cambiarboleto(struct Vuelo *cambiar, int Changeticket);

struct Vuelo {
   char  Nombre [150];
   char  Apellidos [150];
   int   Asiento ;
} Vuelo1[10];


int Vender( struct Vuelo *p)
{
	printf("Dame tu nombre: ");
	scanf( "%s" , &p->Nombre);
	printf("Dame tu apellido: ");
	scanf( "%s" , &p->Apellidos);
	printf("Selecciona el asiento: ");
	scanf( "%i" , &p->Asiento);
	
	return (p->Asiento)-1;
	
}

void Cambiarboleto(struct Vuelo *cambiar, int Changeticket)
{
	int ArrayStruct;
	for(ArrayStruct=0;ArrayStruct<10;ArrayStruct++)
		{
			
			if(Changeticket==cambiar->Asiento)
			{
				printf("Se cambiara el boleto de: %s %s \n",cambiar->Nombre,cambiar->Apellidos);
				printf("A que lugar lo cambiara?\n ");
				scanf("%i",&cambiar->Asiento);
				cambiar++;
			}
			else
			{
				cambiar++;
			}
			
		}
}