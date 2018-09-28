#include <stdio.h>
void printArray(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void inpurArray(int a[], int n)
{
    int i=0;
    while (i < n && scanf("%d", &a[i])==1)
    {
        i++;
    }
    printf("\n");
    

}
void merge(int b[],int nb, int c[],int nc, int d[], int n)
{
    int i = 0, j = 0, k;
    for (k = 0; k < n; k++)
    {
        if(i>=nb)
        {
            d[k] = c[j];
            j++;
            continue;
        }
        if(j>=nc)
        {
            d[k] = b[i];
            i++;
            continue;
        }
        if (b[i] < c[j])
        {
            d[k] = b[i];
            i++;
        }
        else
        {
            d[k] = c[j];
            j++;
        }

    }
}
void mergeSort(int a[], int d[], int n)
{
    
    if (n == 1)
    {
        d[0] = a[0];
        return;
    }
    int b[(n / 2)+(n%2)], c[(n / 2)],nb,nc;
    nb=(n/2)+(n%2);
    nc = (n/2);
    mergeSort(a, b, nb);
    mergeSort((a + nb), c, nc);
    merge(b,nb, c,nc, d, n);
}
void main()
{
    int n = 9;
    int a[n];
    printf("Please Enter the Input  array a:");
    inpurArray(a,n);
    int b[n];
    printArray(a,n);
    mergeSort(a, b, n);
    printArray(b,n);
}
