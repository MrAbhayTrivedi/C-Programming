#include <stdio.h>
#include <conio.h> 
void main()
{
    int n, i, j, a[10], min, t;
    printf("enter how many elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
    printf("the sorted elements are \n");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);
}