#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

struct Perro {
  int Edad;
  string Nombre;
  string Color;
  float Estatura;
};

class perrro {
   private:
       int Edad; 		//Variables privadas
	   string Nombre;
	   string Color;
	   float Estatura;
	   int Multplica(int dato) //Funcion privada
		{	
			return dato*7;
		}
   public:
		perrro(int Edad,string Nombre); //Contructor
		int Resultado; //Variable publica
		void Bark(int dato, string cadena) //Funcion publica
		{	
			Resultado = Multplica(5);
			cout << Resultado;
			cout << cadena;
		}
      
};

int main (void)
{
	int Dato[3]; //Arreglo
	//Tipo de Dato y Nombre de la Variable
	perrro firulais2(20,"Juanito"); //Creo variable con constructor
	Perro firulais[3]; //Arreglo de estructuras
	firulais2.Bark(5,"Hola");
	firulais2.Multplica(5); //No se puede

}