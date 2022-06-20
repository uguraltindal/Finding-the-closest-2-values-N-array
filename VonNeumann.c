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
			printf(" %2d ",matrix[i][j]);       // Matrix'in yazıldığı yer
				
		}
		printf("\n\n");
		
	}
}

void VonNeumann(int **matrix,int near,int r)
{
	matrix[r][r]=1;								// Matrix'in ortasına 1 atadık.
	int k=0;
	while(near!=-1) 							// Komsu sayisi degeri 0'ın altına düşene kadar while dönen yer
	{
			
		int m=-near;							// Burada şunu elde ettik. Komsu sayısı 2 ise örneğin m değerine -2 atadık.
		for(m;m<=near;m++)						// [3][3]' yazılıyken r+m olduğu için yapıyor. [3][1]=1 [3][2]=1 [3][3]=1 [3][4]=1 [3][5]=1
		{										
			matrix[r+k][r+m]=1;					//[4][2]=1 [4][3]=1 [4][4]=1  m=-near diyerek aslında çizgi halinde 1 ataması yaptık.
			matrix[r-k][r+m]=1;					//[2][2]=1 [2][3]=1 [2][4]=1  ilk adım için -2 -1 0 1 2 komşuları için	
		}										// Sonrasında near --; deidiğimiz için 2.adımda -1 0 1 komşularına
		k++;									// en sonda ise 0 komşularına yani en uç noktalara atama yaptık.
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
	matrix=(int **)malloc(N*sizeof(int *));	     // Dynamic olarak matrix tanımlaması
	for(i=0;i<N;i++)
	{
		matrix[i]=(int *)malloc(N*sizeof(int));	 // Dynamic olarak matrix tanımlaması
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix[i][j]=0;   					// Daha iyi gözükmesi için öncelikle matrix'in boşluklarına 0 yazdık.
		}
	}
	VonNeumann(matrix,near,r);
	printMatrix(matrix,N);

	for(i=0;i<N;i++)						   // Matrix'in en son freelendiği yer.
	{
		free((void *)matrix[i]);
	}
	free((void *)matrix);
	return 0;
}
