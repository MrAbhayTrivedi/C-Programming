#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int a[10], n, flag = 0, i, lb, ub, key, mid, ch;
    printf("enter the size of the elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("enter any key element to search\n");
    scanf("%d", &key);
    printf("menu\n");
    printf("\n1.linear search\n2.binary search \n");
    printf("enter your choice:\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        for (i = 0; i < n; i++)
            if (a[i] == key)
            {
                flag = 1;
                break;
            }
    case 2:
        for (lb = 0, ub = n - 1; lb <= ub;)
        {
            mid = (lb + ub) / 2;
            if (key == a[mid])
            {
                flag = 1;
                break;
            }
            else if (key < a[mid])
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        break;
    default:
        exit(0);
    }
    if (flag == 1)
        printf("seach is successful");
    else
        printf("search is not successful \n");
    getch();
}