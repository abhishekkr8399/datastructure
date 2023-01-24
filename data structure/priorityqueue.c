#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int q[MAX];
int front = 0, rear = -1, i, j;
void insert()
{
    int ele;
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else
    {
        printf("Enter value\n");
        scanf("%d", &ele);
        j = rear;
        while ((j >= front) && (ele > q[j]))
        {
            q[j + 1] = q[j];
            j--;
        }
        q[j + 1] = ele;
        rear++;
    }
}
void Delete()
{
    int flag = 0;
    if (front > rear)
        printf("There are no elements to delete\n");
    else
    {
        int ele;
        printf("Enter value to delete\n");
        scanf("%d", &ele);
        for (i = front; i <= rear; i++)
        {
            if (q[i] == ele)
            {
                flag = 1;
                for (j = i; j > front; j--)
                    q[j] = q[j - 1];
                front++;
                break;
            }
        }
        if (flag == 0)
            printf("%d not found\n", ele);
    }
}
void display()
{
    if (front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("the elements are\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    for (;;)
    {
        printf("1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
