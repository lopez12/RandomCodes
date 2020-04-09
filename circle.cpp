#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main (void)
{
	//Variable en Conjunto
	string center;
	string test;
	int puntoA,puntoB;
	int testA,testB;
	int radio;
	int circulo;
	int radiocuadrado;
	//Escribir al String
	cout << "Enter a center: ";
	getline(cin, center); //getline si el string tiene espacios
	puntoA = center[0] - 48;
	puntoB = center[2] - 48;
	
	cout << "Enter a radius: ";
	cin >> radio;
	
	fflush(stdin);
	
	cout << "Enter a point to test: ";
	getline(cin, test); //getline si el string tiene espacios
	testA = test[0] - 48;
	testB = test[2] - 48;
	
	if((testA > 9 || testA < 0) || (testB > 9 || testB < 0) || (puntoA > 9 || puntoA < 0) || (puntoB > 9 || puntoB < 0))
	{
		cout << "Result: input point error ";
	}
	
	radiocuadrado = radio * radio;
	
	circulo = ((testA-puntoA)*(testA-puntoA))+((testB-puntoB)*(testB-puntoB));
	
	if(circulo == radiocuadrado)
	{
		cout << "Result: On the circle";
	}
	if(circulo > radiocuadrado)
	{
		cout << "Result: Outside";
	}
	if(circulo < radiocuadrado)
	{
		cout << "Result: Inside";
	}
	
	
	
	return 0;
	//(x-a)2	+	(y-b)2	=	c2
	
}