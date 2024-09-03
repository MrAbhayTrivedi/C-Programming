#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
void bubblesort(int x[], int n);
void main()
{
    int num[10], i, n;
    printf("Enter the no of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    bubblesort(num, n);
    printf("sorted elements are\n");
    for (i = 0; i < n; i++)
        printf("%d\t", num[i]);
}
void bubblesort(int x[], int n)
{
    int hold, j, pass, K = TRUE;
    for (pass = 0; pass < n - 1 && K == TRUE; pass++)
    {
        K = FALSE;
        for (j = 0; j < n - pass - 1; j++)
            if (x[j] > x[j + 1])
            {
                K = TRUE;
                hold = x[j];
                x[j] = x[j + 1];
                x[j + 1] = hold;
            }
    }
}