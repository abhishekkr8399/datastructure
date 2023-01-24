#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int items[SIZE];
int front = -1, rear = -1;
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
void insert()
{
    int element;
    if (isFull())
        printf("Queue is full\n");
    else
    {
        printf("Enter the element\n");
        scanf("%d", &element);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }
}
void delete()
{
    int element;
    if (isEmpty())
        printf("Queue is empty\n");
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE;
        printf("Deleted element %d \n", element);
    }
}
void display()
{
    int i;
    if (isEmpty())
        printf("Queue is empty\n");
    else
    {
        printf("Elements in the queue\n");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d \n", items[i]);
    }
}
int main()
{
    int choice;
    for (;;)
    {
        printf("Enter your choice\n1 Insertion\n2 Deletion\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
