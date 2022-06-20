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
			printf(" %2d ",matrix[i][j]);       // Matrix'in yazýldýðý yer
				
		}
		printf("\n\n");
		
	}
}

void VonNeumann(int **matrix,int near,int r)
{
	matrix[r][r]=1;								// Matrix'in ortasýna 1 atadýk.
	int k=0;
	while(near!=-1) 							// Komsu sayisi degeri 0'ýn altýna düþene kadar while dönen yer
	{
			
		int m=-near;							// Burada þunu elde ettik. Komsu sayýsý 2 ise örneðin m deðerine -2 atadýk.
		for(m;m<=near;m++)						// [3][3]' yazýlýyken r+m olduðu için yapýyor. [3][1]=1 [3][2]=1 [3][3]=1 [3][4]=1 [3][5]=1
		{										
			matrix[r+k][r+m]=1;					//[4][2]=1 [4][3]=1 [4][4]=1  m=-near diyerek aslýnda çizgi halinde 1 atamasý yaptýk.
			matrix[r-k][r+m]=1;					//[2][2]=1 [2][3]=1 [2][4]=1  ilk adým için -2 -1 0 1 2 komþularý için	
		}										// Sonrasýnda near --; deidiðimiz için 2.adýmda -1 0 1 komþularýna
		k++;									// en sonda ise 0 komþularýna yani en uç noktalara atama yaptýk.
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
	matrix=(int **)malloc(N*sizeof(int *));	     // Dynamic olarak matrix tanýmlamasý
	for(i=0;i<N;i++)
	{
		matrix[i]=(int *)malloc(N*sizeof(int));	 // Dynamic olarak matrix tanýmlamasý
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix[i][j]=0;   					// Daha iyi gözükmesi için öncelikle matrix'in boþluklarýna 0 yazdýk.
		}
	}
	VonNeumann(matrix,near,r);
	printMatrix(matrix,N);

	for(i=0;i<N;i++)						   // Matrix'in en son freelendiði yer.
	{
		free((void *)matrix[i]);
	}
	free((void *)matrix);
	return 0;
}
