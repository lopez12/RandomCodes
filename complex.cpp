#include <iostream>
#include "numerocomplejo.h"
using namespace std;

int main()
{
	complex compx1(1, 5);
	complex compx2(2, 8);
	complex compxrt(0,0);
	compxrt=compx1.add(compx2);
	compx1.printComplex();
}