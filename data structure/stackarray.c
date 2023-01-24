#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int top = -1;
void push(int a[], int item)
{
    top++;
    a[top] = item;
}
void pop(int a[])
{
    int item;
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        item = a[top--];
        printf("the deleted element is %d\n", item);
    }
}
void display(int a[])
{
    int i;
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("the elements in stack are:");
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", a[top--]);
        }
        printf("\n");
    }
}
int main()
{
    int item, choice, s[10];
    while (1)
    {
        printf("enter choice\n");
        printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == MAX - 1)
            {
                printf("stack is full\n");
                break;
            }
            else
            {
                printf("enter item\n");
                scanf("%d", &item);
                push(s, item);
                break;
            }
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}