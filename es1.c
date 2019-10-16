#include "time.h"
#include "stdio.h"
#include "stdlib.h"

//int mergeSort(int a[], int left, int right) 
//{
//	if (left<right)
//    {
//		int center = (left+right)/2;
//		mergeSort(a, left, center);
//		mergeSort(a, center+1, right);
//		mergeSort(a, left, center, right);
//	}
//}

void insSort(int *a, int n)
{
    int i, j;
    int c1;
    for(i = 1; i < n; i++)
    { 
        c1 = a[i]; 
        j = i-1; 
        while(j >= 0 && a[j] > c1)
        {
		    a[j+1]=a[j];		
		    j--;
        }	
        a[j+1] = c1;	
	}
}

int NewArray(int n)
{
    int array[n];
    int dif;
    int i;
    for(i = 0; i < n; i++)
    {
        array[i]=rand();
    }
    clock_t t1, t2;
    t1=clock();
    insSort(array, n);
    t2=clock();
    dif = t2 - t1;
    return dif;
}

int main()
{
    int i = 100;
    int media = 0;
    int j = 0;
    while(i <= 10000)
    {
        while (j < 10) 
        {
            media = media + NewArray(i);
            j++;
        }
        media = media/10;
        printf("%d\n",media);
        media = 0;
        i = i + 100;
        j = 0;
    }
}