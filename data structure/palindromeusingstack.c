#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
int main()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("1-enter string\n2-exit\n");
        printf("enter your choice\n");
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String\n");
            gets(s);
            for (i = 0; s[i] != '\0'; i++)
            {
                b = s[i];
                push(b);
            }
            printf("reverse of the String is\n");
            for (i = top; i >= 0; i--)
            {
                printf("%c", s[i]);
            }
            for (i = 0; i < (strlen(s) / 2); i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("\n%s is not a palindrome\n", s);
                    break;
                }
            }
            if ((strlen(s) / 2) == front)
                printf("\n%s is palindrome\n", s);
            front = 0;
            top = -1;
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
/* to push a character into stack */
void push(char a)
{
    top++;
    stack[top] = a;
}
/* to delete an element in stack */
void pop()
{
    top--;
}
