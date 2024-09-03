#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
void push(char);
char pop(void);
char ex[50], s[50], op1, op2;
int i, top = -1;
void main()
{
    printf("Enter the expression:");
    gets(ex);
    for (i = 0; ex[i] != '\0'; i++)
    {
        if (isdigit(ex[i]))
            push(ex[i] - 48);
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ex[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '%':
                push(op1 % op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            }
        }
    }
    printf("result is :%d", s[top]);
    getch();
}
void push(char a)
{
    s[++top] = a;
}
char pop()
{
    return (s[top--]);
}