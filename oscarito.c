#include<stdio.h>
#include<conio.h>

void DrawSlots(int ParkingSlots[25]);
void unassignParkingSlot (int ParkingSlots [25]);
void delay(int time);
void assignlugarnormal (int ParkingSlots [25]);
void assignlugarminusvalidos (int ParkingSlots [25]);

int main (void)
{
	int ParkingSlots[25]={0};
	int NormalMinusvalidoSelection;
	int InputOutput;
	
	
	while(1)
	{
		
		printf("\nUsted viene de entrada (1) o salida (2)");
		InputOutput=getch();
		
		if(InputOutput==1+48)
		{
			printf("\nBuen Dia Selecciona el lugar: Normal (1) o Minusvalidos (2)\n");
			NormalMinusvalidoSelection=getch();
			if(NormalMinusvalidoSelection==2+48)
			{
				assignlugarnormal(ParkingSlots);
			}
			else if(NormalMinusvalidoSelection==1+48)
			{
				assignlugarminusvalidos (ParkingSlots);
			}
		}
		
		else if(InputOutput==2+48)
		{
			unassignParkingSlot(ParkingSlots);
		}
		
		DrawSlots(ParkingSlots);
		
	}
	return 0;
}

void DrawSlots(int ParkingSlots[25])
{
	int i;
	clrscr();
	gotoxy(1,1);
	for(i=0;i<25;i++)
	{
		if(ParkingSlots[i]==1)
		{	
			printf("X\n");
		}
		else
		{
			printf("%c\n",4);
		}
	}
}

void unassignParkingSlot (int ParkingSlots [25])
{

	float InputTime;
	float Money;
	int Space=0;

	printf("\nDe que cajon saliste?\n");
	scanf("%i",&Space);
	printf("\nDa la duración de la estancia\n");
	scanf("%f",&InputTime);
	if(Space==4||Space==9||Space==14||Space==19||Space==24)
	{
		Money=InputTime*7;
	}
	else
	{
		Money=InputTime*12;
	}
	ParkingSlots[Space]=0;
	
	printf("Debes: %f",Money);
	delay(800);

}

void delay(int time)
{
	time = time * 1000000;
	while(time)
	{
		time--;
	}	
	
	return;
}

void assignlugarnormal (int ParkingSlots [25])
{
	int i;
	static int contadorlugarminus=0;
	for(i=4;i<25;i++)
	{
		if(ParkingSlots[i]==0)
		{
			printf("El proximo lugar disponible es el espacio: %i", i);
			ParkingSlots[i]=1;
			break;
		}
		else
		{
			contadorlugarminus++;
		}
		i=i+4;
	}
	if(contadorlugarminus==5)
	{
		printf("No hay lugares de minusvalidos disponibles");
	}

}

void assignlugarminusvalidos (int ParkingSlots [25])
{
	int i;
	static int contadorlugarnormal=0;
	for(i=0;i<25;i++)
	{
		if(ParkingSlots[i]==0)
		{
			printf("El proximo lugar disponible es el Space: %i", i);
			ParkingSlots[i]=1;
			break;
		}
		else
		{
			contadorlugarnormal++;
		}
	}
	if(contadorlugarnormal==25)
	{
		printf("No hay lugares de normales disponibles");
	}
}