#include<stdio.h>

int main(void)
{
	float generador=0;

	printf("Gramos: ");
	scanf("%f",&generador);
	
	printf("vinagre, sal, y huevos: %f, aceite %f", (generador*1)/350,(generador*320)/350);
	return 0;
	
}

