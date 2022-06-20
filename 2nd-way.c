#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void printarr(int arr[], int n)
{ 
printf("\n ");
int i;

for (i=0; i < n; i++)
{
printf(" %d ", arr[i]);
}

}
void merge(int arr[], int left, int mid, int right)
{
int i, j, k;
int a1 = mid - left + 1;
int a2 = right - mid;
int arr1[a1], arr2[a2];
for (i = 0; i < a1; i++) // Değerleri sağ ve sol olarak 2 farklı diziye aktardık.
arr1[i] = arr[left + i];
for (j = 0; j < a2; j++)
arr2[j] = arr[mid + 1+ j]; // Sağ sol dizilerin sınırlarının belirlendiği yerler
i = 0;
j = 0;
k = left;

while (i < a1 && j < a2)
{
if (arr1[i] <= arr2[j])
{
arr[k] = arr1[i];
i++;
}
else
{
arr[k] = arr2[j];
j++;
}
k++;
}
while (i < a1) // Dizilerin sıralanmış halini arr[] dizisine sırayla kopyaladık.
{
arr[k] = arr1[i];
i++;
k++;
}
while (j < a2)
{
arr[k] = arr2[j];
j++;
k++;
}
}
void mergeSort(int arr[], int left, int right)
{
if (left < right)
{
int mid = left+(right-left)/2; // Her girişinde mid değerinin belirlenmesi.
mergeSort(arr, left, mid); // Sağ ve sol dizileri sıraladık.
mergeSort(arr, mid+1, right); // Recursive olarak mergeSort kısmı.
merge(arr, left, mid, right);
}
}
void closest(int arr[],int n)
{
int i,min,range;
min=arr[1]-arr[0]; // Rastgele bir min değeri veremeyiz.Bu yüzden başlangıç olarak ilk 2 elemanın arasındaki değeri min'e atadık.
for(i=1;i<n-1;i++)
{
range=arr[i+1]-arr[i];
if(range<min)
{
min=range; // Range minden düşük ise min=range diyerek yeni min degerini min'e atadık.
}
}

int j=0;
range=arr[n]-arr[0]; // Range değerini sıfırlamamız gerekiyor.Fakat sıfırlamak 
derken 0 yazamayız çünkü min değeri 0 ise while döngüsüne girmeden yanlış cevabı verir.
while(j<n-1 && min!=range) // Bu yüzden range değerini son eleman - ilk eleman yaparak 0'ladık.Her durumu sağlatması için.
{
range=arr[j+1]-arr[j];
j++;
}
printf("\n\n Closest range : %d (%d | %d)",min,arr[j-1],arr[j]); // En yakın sayıların uzaklığını ve sayıları yazdırdık.
}


int main()
{
int n,i;
int arr[200001];
int kullanicitercihi;
srand(time(NULL));
printf("\n Dizinin elemanlarini kendiniz girmek istiyorsaniz 1, random olarak uretilmesini istiyorsaniz 2 tuslayiniz.\n");
scanf("%d",&kullanicitercihi);
printf("\n Dizinin eleman sayisini giriniz : ");
scanf("%d",&n);

if(kullanicitercihi==1)
{
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
}
else
{
for(i=0;i<n;i++)
{
arr[i]=rand()%100000+1;
}
}
clock_t start = clock();
mergeSort(arr,0,n-1);
clock_t end = clock();
printarr(arr,n);
closest(arr,n);
double runningtime = (double)(end-start)/CLOCKS_PER_SEC;
if(kullanicitercihi==2)
{
printf("\n\n Running Time : %0.3f Saniye (Eleman sayisi : %d )",runningtime,n);
}
return 0;
}
