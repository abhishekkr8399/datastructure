#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define Max 100
struct stack
{
    int top;
    double a[Max];
};
void push(char, struct stack *);
double pop(struct stack *);
double compute(double, double, char);
int main()
{
    struct stack s;
    s.top = -1;
    int i;
    double op1, op2, res;
    char postfix[100], symb;
    printf("enter postfix expression\n");
    gets(postfix);
    for (i = 0; postfix[i] != '\0'; i++)
    {
        symb = postfix[i];
        if (isdigit(symb))
            push(symb, &s);
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            res = compute(op1, op2, symb);
            s.a[++s.top] = res;
        }
    }
    res = pop(&s);
    printf("result after evaluation is %f", res);
    return 0;
}
void push(char symb, struct stack *s)
{
    if (s->top == Max - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        s->a[++s->top] = symb - '0';
    }
}
double pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("stack is empty\n");
        exit(0);
    }
    else
        return (s->a[s->top--]);
}
double compute(double op1, double op2, char symb)
{
    switch (symb)
    {
    case '+':
        return (op1 + op2);
        break;
    case '-':
        return (op1 - op2);
        break;
    case '*':
        return (op1 * op2);
        break;
    case '/':
        return (op1 / op2);
        break;
    case '$':
    case '^':
        return (pow(op1, op2));
        break;
    default:
        printf("incorrect symbol\n");
        exit(0);
        break;
    }
    return 0;
}
