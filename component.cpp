#include <iostream>
#include <string>
#include "externalclasses.h"
#include <stdlib.h>
#define SCREEN_ROWS 20
using namespace std;
void delay(long time);
void ClearScreen();

int main (void)
{
	/*Banderas*/
	int AddingWater_FLAG = 0;
	int AddingQR_FLAG = 0;
	int AddingKM_FLAG = 0;
	int Pumping2Lines = 0;
	int Blending = 0;
	int SystemREADY = 1;
	int SystemFAULT = 0; //1 = SI falla, 0 = NO falla
	string inputUSER = "";
	
	/*Valvulas*/
	valve AV_CW(CLOSE);
	valve AV_QR(CLOSE);
	valve AV_KM(CLOSE);
	valve AV_MT(CLOSE);
	
	/*Tanques*/
	tank MTTank(2000);
	tank QRTank(400);
	tank KMTank(200);
	
	/*Bombas*/
	pump PUMP_QR(OFF);
	pump PUMP_KM(OFF);
	pump PUMP_MT(OFF);
	
	cout << "SYSTEM READY \n";
	
	cout << "Mix Tank is Currently at: ";
	cout << MTTank.getCurrentCapacity()*100/2000;
	cout << "% \n";
	
	char line[1839];
	
	/*Agregado de Agua*/
	while(AV_CW.getOpenStatus() == CLOSE)
	{
		cout << "Do you wish to Start de WATER process? (yes,no)";
		getline(cin, inputUSER);
		if (inputUSER.compare("yes") == 0)
		{
			AV_CW.setOpenStatus(OPEN); //Open AV_CW 
			AddingQR_FLAG = 1;
		}
	}
		
	if(AV_CW.getOpenStatus() == OPEN)
	{
		cout << "AV_CW Valve = ON\n";
		cout << "PUMP_CW Pump = ON\n";
		cout << "Initiating WATER...\n";
		delay(0xAFFFFFFF);
		while(MTTank.getCurrentCapacity() < 1275 || AV_CW.getOpenStatus() == OPEN)
		{
			/*line[MTTank.getCurrentCapacity()] = '*';
			cout << "Filling Mix Tank (WATER):  ";
			cout << line;
			delay(0xFF);
			ClearScreen();*/
			MTTank.addCapacity(1);
			if(MTTank.getCurrentCapacity() == 1275)
			{
				cout << "Mix Tank is Currently at: ";
				cout << MTTank.getCurrentCapacity()*100/2000;
				cout << "% \n";
				AV_CW.setOpenStatus(CLOSE);
				cout << "Terminating WATER Process...";
				delay(0xAFFFFFFF);
			}
		}
	}
	else
	{
		SystemFAULT = 1;
		cout << "SYSTEM FAULT";
		return 0;
	}	
	AddingWater_FLAG = 0;
	SystemFAULT = 0;
	cout << "AV_CW Valve = OFF\n";
	cout << "PUMP_CW Pump = OFF\n";
	
	/*Agregado de Quimico QR*/
	while(AV_QR.getOpenStatus() == CLOSE)
	{
		cout << "Do you wish to Start de QR process? (yes,no)";
		getline(cin, inputUSER);
		if (inputUSER.compare("yes") == 0)
		{
			AV_QR.setOpenStatus(OPEN); //Open AV_QR 
			AddingQR_FLAG = 1;
		}
	}
	
	if(AV_QR.getOpenStatus() == OPEN)
	{	
		cout << "AV_QR Valve = ON\n";
		cout << "PUMP_QR Pump = ON\n";
		cout << "Initiating QR...\n";
		delay(0xAFFFFFFF);
		while(MTTank.getCurrentCapacity() < 1275+390)
		{
			line[MTTank.getCurrentCapacity()] = '*';
			cout << "Filling Mix Tank (QR):  ";
			cout << line;
			delay(0xFF);
			ClearScreen();
			MTTank.addCapacity(1);
			if(MTTank.getCurrentCapacity() == 1275+390)
			{
				cout << "Mix Tank is Currently at: ";
				cout << MTTank.getCurrentCapacity()*100/2000;
				cout << "% \n";
				AV_QR.setOpenStatus(CLOSE);
				cout << "Terminating QR Process...";
				delay(0xAFFFFFFF);
			}
		}
	}
	else
	{
		SystemFAULT = 1;
		cout << "SYSTEM FAULT";
		return 0;
	}	
	AddingQR_FLAG = 0;
	SystemFAULT = 0;
	cout << "AV_QR Valve = OFF\n";
	cout << "PUMP_QR Pump = OFF\n";
	
	/*Agregado de QuimicoKM*/
	while(AV_KM.getOpenStatus() == CLOSE)
	{
		cout << "Do you wish to Start de KM process? (yes,no)";
		getline(cin, inputUSER);
		if (inputUSER.compare("yes") == 0)
		{
			AV_KM.setOpenStatus(OPEN); //Open AV_QR 
			AddingKM_FLAG = 1;
		}
	}
	
	if(AV_KM.getOpenStatus() == OPEN)
	{
		cout << "AV_KM Valve = ON\n";
		cout << "PUMP_KM Pump = ON\n";
		cout << "Initiating KM...\n";
		delay(0xAFFFFFFF);
		while(MTTank.getCurrentCapacity() < 1275+390+173 && AV_KM.getOpenStatus() == OPEN)
		{	
			line[MTTank.getCurrentCapacity()] = '*';
			cout << "Filling Mix Tank (KM):  ";
			cout << line;
			delay(0xFF);
			ClearScreen();
			MTTank.addCapacity(1);
			if(MTTank.getCurrentCapacity() == 1275+390+173)
			{
				cout << "Mix Tank is Currently at: ";
				cout << MTTank.getCurrentCapacity()*100/2000;
				cout << "% \n";
				AV_KM.setOpenStatus(CLOSE);
				cout << "Terminating KM Process...";
				delay(0xAFFFFFFF);
			}
		}
	}
	else
	{
		cout << "SYSTEM FAULT";
		SystemFAULT = 1;
		return 0;
	}	
	AddingKM_FLAG = 0;
	SystemFAULT=0;
	cout << "AV_KM Valve = OFF\n";
	cout << "PUMP_KM Pump = OFF\n";
	
	/*Blending*/
	Blending = 1;
	while(Blending)
	{
		cout << "Agitator = ON...";
		cout << "Blending...";
		delay(0xfFFFFFFF);
		Blending = 0;
	}
	
	/*Pipe Release*/
	while(AV_MT.getOpenStatus() == CLOSE)
	{
		cout << "Open AV_MT? (yes,no)";
		getline(cin, inputUSER);
		if (inputUSER.compare("yes") == 0)
		{
			AV_MT.setOpenStatus(OPEN); //Open AV_MT 
			Pumping2Lines = 1;
		}
	}
	
	if(AV_MT.getOpenStatus() == OPEN)
	{
		while(MTTank.getCurrentCapacity() > 0)
		{
			cout << "Emptying Mix Tank:  ";
			cout << MTTank.getCurrentCapacity();
			delay(0xFFFF);
			ClearScreen();
			MTTank.substractCapacity(1);
		}
		cout << "Close AV_MT? (yes,no)";
		getline(cin, inputUSER);
		if (inputUSER.compare("yes") == 0)
		{
			AV_MT.setOpenStatus(CLOSE);
		}
		if(AV_MT.getOpenStatus() == OPEN)
		{
			SystemFAULT = 1;
			cout << "SYSTEM FAULT";
			return 0;
		}
	}
	else
	{
		SystemFAULT = 1;
		cout << "SYSTEM FAULT";
		return 0;
	}
	Pumping2Lines = 0;
	SystemREADY = 1;
	cout << "SYSTEM READY \n";
	
	cout << "Mix Tank is Currently at: ";
	cout << MTTank.getCurrentCapacity()*100/2000;
	cout << "% \n";
	
	return 0;
}

void delay(long time)
{
	while(time--);
}

void ClearScreen() {

    int rows = SCREEN_ROWS;

    while(--rows >= 0) { printf("\n"); }
}