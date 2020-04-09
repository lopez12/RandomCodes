#ifndef NUMEROCOMPLEJO 
#define NUMEROCOMPLEJO

class Complex {
   public:
		Complex(int RealC,int ImaginaryC); //Contructor
		int Real;
		int Imaginary;
		
		
		Complex add(Complex NumeroComplejo); //Funcion publica
		
		void printComplex(void);
      
};

complex::complex(int realconsr, int imaginconsr)
{
	real = realconsr;
	imaginary = imaginconsr;
}

complex complex:: add(complex receive)
{
	receive.real = receive.real + real;
	receive.imaginary = receive.imaginary + imaginary;
	
	return receive;
}
void complex:: printComplex(void)
{
  cout << real;
  cout << "+";
  cout << imaginary;
  cout << "i";

}

#endif