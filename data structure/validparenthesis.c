#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct stack
{
    int top;
    char items[MAX];
};
struct stack s;
char infix[MAX], postfix[MAX];
int pos = 0;
void convert();
int precedence(char);
void push(char);
char pop();
int f = 0;
int main()
{
    s.top = -1;
    printf("enter infix\n");
    gets(infix);
    convert();
    if (f == 0)
    {
        printf("postfix is\n");
        puts(postfix);
    }
    return 0;
}
void convert()
{
    if (infix[0] == '\0')
    {
        f = 1;
        printf("invalid input\n");
        return;
    }
    int i;
    char symbol, temp;
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((temp = pop()) != '(')
            {
                postfix[pos++] = temp;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            while ((s.top != -1) && (precedence(s.items[s.top]) >= precedence(symbol)) && precedence(symbol) != -1)
            {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;
        default:
            if (!isalpha(symbol))
            {
                printf("invalid input\n");
                f = 1;
                return;
            }
            else
            {
                postfix[pos++] = symbol;
                break;
            }
        }
    }
    while (s.top != -1)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
}
void push(char ele)
{
    if (s.top == MAX - 1)
    {
        printf("full\n");
    }
    else
    {
        s.items[++s.top] = ele;
    }
}
char pop()
{
    if (s.top == -1)
    {
        printf("empty\n");
        exit(0);
    }
    else
        return s.items[s.top--];
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '$':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '(':
    case ')':
        return 0;
        break;
    default:
        printf("invalid input\n");
        return -1;
        break;
    }
}
