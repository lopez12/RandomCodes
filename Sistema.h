#include<stdio.h>
#include "vuelo.h"

void SistemaOperativo(void);

void SistemaOperativo(void)
{
	int SoldTickets[10]={0};
	int VenderTicket;
	int OpcionMenu=0;
	int Changeticket=0;
	int CancelTicket=0;
	int i;
	struct Vuelo *p, *cambiar, *lista, *cancelar;
	
	p=&Vuelo1[0];
	while(1)
	{
		printf("1.-Vender\n2.-Lista\n3.-Cambiar\n4.-Cancelar\n5.-Salir\n");
		scanf("%i",&OpcionMenu);
		switch(OpcionMenu)
		{
		
			case 1:
				VenderTicket=Vender(p);
				if(SoldTickets[VenderTicket]!=1)
				{
					SoldTickets[VenderTicket]=1;
					p++;
				}
				else
				{
					printf("Ese boleto ya esta vendido\n");
					for(i=0;i<150;i++)
					{
						p->Nombre[i]=0;
						p->Apellidos[i]=0;
					}
					p->Asiento=0;
				}
			break;
			
			case 2:
			lista=&Vuelo1[0];
				while(lista->Asiento)
				{
					printf("ASIENTO %i	OCUPADO POR %s, %s\n",lista->Asiento,lista->Apellidos,lista->Nombre);
					lista++;
				}
			break;
			
			case 3:
				printf("Que boleto desea cambiar?");
				scanf("%i",&Changeticket);
				cambiar=&Vuelo1[0];
				Cambiarboleto(cambiar,Changeticket);
			break;
			
			case 4:
				printf("Que boleto desea cancelar?");
				scanf("%i",&CancelTicket);
				SoldTickets[CancelTicket-1]=0;
				
			break;
			
			case 5:
				return;
			break;
			
		}
	}
}