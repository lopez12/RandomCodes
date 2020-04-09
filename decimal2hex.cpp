// operating with variables

#include <iostream>
void convert(int dec);
using namespace std;


int main ()
{

  char val[8];
  int resultado = 0;
  int residuo;
  
  cin >> val; //Recibir una cadena

  if(val[7] == '1')
  {
	  resultado = resultado + 1;
  }
  
  if(val[6] == '1')
  {
	  resultado = resultado + 2;
  }
  
  if(val[5] == '1')
  {
	  resultado = resultado + 4;
  }
  
  if(val[4] == '1')
  {
	  resultado = resultado + 8;
  }
  
  if(val[3] == '1')
  {
	  resultado = resultado + 16;
  }
  
  if(val[2] == '1')
  {
	  resultado = resultado + 32;
  }
  
  if(val[1] == '1')
  {
	  resultado = resultado + 64;
  }
  
  if(val[0] == '1')
  {
	  resultado = resultado + 128;
  }
  

  cout << "Valor Decimal:";
  cout << resultado;
  cout << "\n";
    
  residuo = resultado % 16; //88(decimal) = 58 (hexadecimal)
 
  //16(Decimal) = 10 (Hexadecimal)
  //17(Decimal) = 11 (Hexadecimal)
  //20(Decimal) = 14 (Hexadecimal)
  //27(Decimal) = 1B (Hexadecimal)
  //88(Decimal) = 58 (Hexadecimal)
  
  if (residuo > 9)
	residuo = (char)(residuo - 10 + 'A');
  else
	residuo = residuo ;

  resultado = resultado/16;
  cout << "Valor Hexadecimal:";
  if (resultado > 9)
  {
	resultado = (char)(resultado - 10 + 'A');
	cout << (char)resultado;
  }
  else
  {
	resultado = resultado ;
	cout << resultado;
  }
  
  if(residuo > 9)
  {
	cout << (char)residuo;
  }
  else
  {
	cout << residuo;  
  }
  
  

  return 0;
}
