#include <stdio.h>
#include <stdlib.h>

void Suma (int Matrix_A[3][3], int Matrix_B[3][3]);
void Resta (int Matrix_A[3][3], int Matrix_B[3][3]);
int main (void)
{
	int Matrix_A[3][3]={{2,0,1},{3,0,0},{5,1,1}};
	int Matrix_B[3][3]={{1,0,1},{1,2,1},{1,1,0}};
	int Matrix_R[3][3]={0};
	int Menu=0;
	while(1)
	{
		printf("1.- Suma de Matrices \n 2.- Resta de Matrices \n 3.- Multiplicacion A x B \n 4.- Multiplicacion B x A \n 5.- Salir \n");
		scanf("%i",&Menu);
		
		switch(Menu)
		{
			case 1:
				Suma(Matrix_A,Matrix_B);
			break;
			
			case 2:
				Resta(Matrix_A,Matrix_B);
			
			break;
			
			case 3:
			
			break;
			
			case 4:
			
			break;
			
			case 5:
				return 0;
			break;
			
			default:
				printf("Esta opcion no es valida \n");
			break;
		}
	}
return 0;
}

void Suma (int Matrix_A[3][3], int Matrix_B[3][3])
{
	int i, j;
	int Matrix_R[3][3]={0};
	printf("Ya estoy en la Suma\n\n");
	for(i=0;i<3;i++)
	{	for(j=0; j<3; j++)
		{	
			Matrix_R[i][j] = Matrix_A[i][j]+Matrix_B[i][j];
		}
	}
	
	for(i=0;i<3;i++)
	{	for(j=0; j<3; j++)
		{	
			printf(" %i ",Matrix_R[i][j]);
		}
		printf("\n");
	}
	
	return;
}

void Resta (int Matrix_A[3][3], int Matrix_B[3][3])
{
	int i, j;
	int Matrix_R[3][3]={0};
	printf("Ya estoy en la Resta\n\n");
	for(i=0;i<3;i++)
	{	for(j=0; j<3; j++)
		{	
			Matrix_R[i][j] = Matrix_A[i][j]-Matrix_B[i][j];
		}
	}
	
	for(i=0;i<3;i++)
	{	for(j=0; j<3; j++)
		{	
			printf(" %i ",Matrix_R[i][j]);
		}
		printf("\n");
	}
	
	return;
}


