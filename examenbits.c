#include<stdio.h>
int EdadElena(int Edad);


int main (void)
{
	int Edad=0;
	Edad = EdadElena(Edad);
	return 0;
}

int EdadElena(int Edad)
{
	
if (Edad > 19) 
	return 1;
else 
{
	printf("%i\n",Edad);
	return (EdadElena(Edad+1));
}
	
}