#include<stdio.h>
#include <conio.h>
void maxheap(int[], int, int);
void buildmaxheap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        maxheap(a, i, n);
    }
}
void maxheap(int a[], int i, int n)
{
    int R, L, largest, t;
    L = 2 * i;
    R = 2 * i + 1;
    if ((L <= n) && (a[L] > a[i]))
        largest = L;
    else
        largest = i;
    if ((R <= n) && (a[i] > a[largest]))
        largest = R;
    if (largest != i)
    {
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        maxheap(a, largest, n);
    }
}
void heapsort(int a[], int n)
{
    int i, temp;
    buildmaxheap(a, n);
    for (i = n; i >= 2; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        maxheap(a, 1, i - 1);
    }
}
void main()
{
    int a[50], i, n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements of array \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    printf("sorted array is \n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
}