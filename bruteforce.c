#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void printarray(int arr[],int n)
{
int i;
printf(" \n Dizinin elemanlari \n\n ");
for(i=0;i<n;i++)
{
printf(" %d ",arr[i]);
}

}
int closestrange(int arr[],int n) // Brute-Force yöntemi olduğu için tüm elemanları birbiriyle karşılaştırarak en düşük uzaklığı bulduk.
{
int range;
int minrange;
int i,j;
range=arr[0]-arr[1];
if(range<0)
{
range=range*-1;
}
minrange=range; // Dizi içerisindeki sayilarin herhangi birinin uzakligini bilmedigimiz için rastgele bir minrage degeri atamasi yapamazdik.
// Bu yüzden ilk 2 elemanı karşılaştırarak kısaca her durum için uyum sağlayacak bir minrange değeri başlangıcı yaptık.

for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++) // Kendisinden önceki elemanlarla karşılaştırılmamasını sağlar. j=i+1; Çünkü zaten çoktan karşılaştırılmış olarak buraya geldi.
{
range=arr[i]-arr[j];
if(range<0) 
{
range=range*-1; // Range hesaplarken çıkartma yaptığımız için negatif değerleri pozitife çevirdik.
}
if(range<minrange)
{
minrange=range;
}
}
}
return minrange;
}
int closest(int arr[],int n,int min) 
{
int range,i,j;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++) // Kendisinden önceki elemanlarla karşılaştırılmamasını sağlar. j=i+1; Çünkü zaten çoktan karşılaştırılmış olarak buraya geldi.
{
range=arr[i]-arr[j];
if(range<0)
{
range=range*-1; 
}
if(range==min) // En düşük uzaklığı bulduğumuz için o uzaklığı elde ettiğimiz an bu if döngüsüne girerek
{
printf(" (%d | %d)",arr[i],arr[j]); // Bilgiyi yazdırdık ve returnle fonksiyon dışına çıkarak gereksiz aramaları önledik.
return 0;
}
}
}
}
int main() 
{
int arr[200001];
int n,i;
int min;
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
arr[i]=rand()%100000;
}
}
printarray(arr,n);
clock_t start = clock();
min=closestrange(arr,n);
printf("\n\n Closest Range : %d",min);
closest(arr,n,min);
clock_t end = clock();
double runningtime = (double)(end-start)/CLOCKS_PER_SEC;
if(kullanicitercihi==2)
{
printf("\n\n Running Time : %0.3f Saniye (Eleman sayisi : %d )",runningtime,n);
}
return 0;
}
