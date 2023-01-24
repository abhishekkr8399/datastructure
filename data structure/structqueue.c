#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct queue
{
    int a[MAX];
    int front, rear;
};
void push(struct queue *s, int item)
{
    (s->rear)++;
    s->a[(s->rear)] = item;
}
void pop(struct queue *s)
{
    int item;
    if (s->front > s->rear)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        item = s->a[(s->front)];
        printf("the deleted element is %d\n", item);
        (s->front)++;
    }
}
void display(struct queue *s)
{
    int i;
    if (s->front > s->rear)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("the elements in queue are");
        for (i = s->front; i <= s->rear; i++)
        {
            printf("%d\t", s->a[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct queue s;
    s.front = 0;
    s.rear = -1;
    int item, choice;
    while (1)
    {
        printf("enter choice\n");
        printf("1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (s.rear == MAX - 1)
            {
                printf("queue is full\n");
                break;
            }
            else
            {
                printf("enter item\n");
                scanf("%d", &item);
                push(&s, item);
                break;
            }
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}