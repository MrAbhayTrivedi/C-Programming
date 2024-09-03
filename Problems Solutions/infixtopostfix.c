#include <stdio.h>
#include <conio.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char);
char pop();
int priority(char);
void main()
{
    char a[MAX], ch;
    int i;
    printf("Enter an infix expression:\t");
    gets(a);
    printf("\nThe postfix expression for the given expression is:\t");
    for (i = 0; a[i] != '\0'; i++)
    {
        ch = a[i];
        if ((ch >= 'a') && (ch <= 'z'))
            printf("%c", ch);
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while ((ch = pop()) != '(')
                printf("%c", ch);
        }
        else
        {
            while (priority(stack[top]) > priority(ch))
                printf("%c", pop());
            push(ch);
        }
    }
    while (top > -1)
        printf("%c", pop());
    printf("\n");
    getch();
}
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("STACK OVERFLOW");
        return;
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
char pop()
{
    int x;
    if (top == -1)
    {
        printf("STACK EMPTY");
    }
    else
    {
        x = stack[top];
        top--;
    }
    return x;
}
int priority(char ch)
{
    switch (ch)
    {
    case '^':
        return 4;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 0;
    }
}