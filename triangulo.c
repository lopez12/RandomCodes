#include<stdio.h>
#include<conio.h>
#include<math.h>

float wParameter (int wValue_X, int wValue_R1, int wValueR2);

int main (void)
{
	printf("%f",wParameter(3, 5, 8));
	return 0;
}

float wParameter (int wValue_X, int wValue_R1, int wValueR2)
{
	float wresult1=0;
	float wresult2=0;
	
	wresult1 = pow((double)(wValue_R1+wValueR2),2);
	wresult2 = pow((double)(wValue_R1+((wValue_X-2*wValue_R1)/2)),2);
	
	return sqrt((double)(wresult1-wresult2))+wValue_R1;
}