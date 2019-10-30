#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertionSort(int *a, int n)
{
    int i, j, c;

    for(i = 1; i < n; i++)
    {
        c = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > c)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = c;
    }
}

void Merge(int *array, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = array[l+i];
    for(j = 0; j < n2; j++)
        R[j] = array[m+1+j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int *a, int f, int l)
{
    if(f < l)
    {
        int m = f + (l - f)/2;

        MergeSort(a, f, m);
        MergeSort(a, m+1, l);

        Merge(a, f, m, l);
    }
}

int OrdinaArray(int dim)
{
    int array[dim];
    int i;
    int differenza;
    clock_t t1, t2;

    for(i = 0; i < dim; i++)
    {
        array[i] = rand();
    }

    t1 = clock();
    //InsertionSort(array, dim);            //se vuoi usare merge commenti ins e viceversa
    MergeSort(array, 0, dim);
    t2 = clock();
    
    differenza = t2 - t1;
    return differenza;
}

int main()
{
    int i = 100;
    int media = 0;
    int j = 0;

    while(i <= 10000)
    {
        while(j < 10)
        {
            media = media + OrdinaArray(i);
            j++;
        }
        media = media/10;
        printf("dimensione %d   tempo %d\n", i, media);
        media = 0;
        i = i + 100;
        j = 0;
    }
}
