#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix,int N)
{
	int i,j;
		for(i=0;i<N;i++)
	{
		printf("\t\t\t\t");
		for(j=0;j<N;j++)
		{
			printf(" %2d ",matrix[i][j]);       // Matrix'in yaz�ld��� yer
				
		}
		printf("\n\n");
		
	}
}

void VonNeumann(int **matrix,int near,int r)
{
	matrix[r][r]=1;								// Matrix'in ortas�na 1 atad�k.
	int k=0;
	while(near!=-1) 							// Komsu sayisi degeri 0'�n alt�na d��ene kadar while d�nen yer
	{
			
		int m=-near;							// Burada �unu elde ettik. Komsu say�s� 2 ise �rne�in m de�erine -2 atad�k.
		for(m;m<=near;m++)						// [3][3]' yaz�l�yken r+m oldu�u i�in yap�yor. [3][1]=1 [3][2]=1 [3][3]=1 [3][4]=1 [3][5]=1
		{										
			matrix[r+k][r+m]=1;					//[4][2]=1 [4][3]=1 [4][4]=1  m=-near diyerek asl�nda �izgi halinde 1 atamas� yapt�k.
			matrix[r-k][r+m]=1;					//[2][2]=1 [2][3]=1 [2][4]=1  ilk ad�m i�in -2 -1 0 1 2 kom�ular� i�in	
		}										// Sonras�nda near --; deidi�imiz i�in 2.ad�mda -1 0 1 kom�ular�na
		k++;									// en sonda ise 0 kom�ular�na yani en u� noktalara atama yapt�k.
		near--;											
										
	}
	
}

int main()
{
	int **matrix,N,i,j;
	
	printf("\n\n    N degerini giriniz : ");
	scanf("%d",&N);
	int near=N;
	N=(N*2)+3;
	int r=(N-1)/2;
	matrix=(int **)malloc(N*sizeof(int *));	     // Dynamic olarak matrix tan�mlamas�
	for(i=0;i<N;i++)
	{
		matrix[i]=(int *)malloc(N*sizeof(int));	 // Dynamic olarak matrix tan�mlamas�
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix[i][j]=0;   					// Daha iyi g�z�kmesi i�in �ncelikle matrix'in bo�luklar�na 0 yazd�k.
		}
	}
	VonNeumann(matrix,near,r);
	printMatrix(matrix,N);

	for(i=0;i<N;i++)						   // Matrix'in en son freelendi�i yer.
	{
		free((void *)matrix[i]);
	}
	free((void *)matrix);
	return 0;
}
