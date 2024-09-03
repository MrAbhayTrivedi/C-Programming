#include <stdio.h>
#include <conio.h>
void quick(int a[10], int lb, int n);
void main()
{
    int n, i, a[10];
    printf("enter how many elements \n");
    scanf("%d", &n);
    printf("enter the elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick(a, 0, n - 1);
    printf("the sorted elements are \n");
    for (i = 0; i < n; i++)
        printf("%d \n", a[i]);
}
void quick(int a[], int lb, int ub)
{
    int i, j, t, key;
    if (lb > ub)
        return;
    i = lb;
    j = ub;
    key = lb;
    while (i < j)
    {
        while (a[key] > a[i])
            i++;
        while (a[key] < a[j])
            j--;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[j];
    a[j] = a[key];
    a[key] = t;
    quick(a, 0, j - 1);
    quick(a, j + 1, ub);
}
