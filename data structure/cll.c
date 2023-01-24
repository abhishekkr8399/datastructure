#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE X;
    X = (NODE)malloc(sizeof(struct node));
    return X;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp, newnode;
    newnode = getnode();
    newnode->info = item;
    if (first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
        return newnode;
    }
    else
    {
        temp = first;
        while (temp->link != first)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        newnode->link = first;
        return first;
    }
}
NODE Delete_rear(NODE first)
{
    NODE prev, temp;
    if (first == NULL)
    {
        printf("empty\n");
        return first;
    }
    else if (first->link == first)
    {
        printf("the deleted element is%d\n", first->info);
        return NULL;
    }
    else
    {
        temp = first;
        prev = NULL;
        while (temp->link != first)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = first;
        printf("the deleted element is%d\n", temp->info);
        free(temp);
        return first;
    }
}
void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    temp = first;
    printf("elements are\n");
    while (temp->link != first)
    {
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    printf("%d\t", temp->info);
}
int main()
{
    NODE first = NULL;
    int choice, item;
    while (1)
    {
        printf("Enter your choice\n1 Insert rear\n2 Delete rear\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &item);
            first = insert_rear(first, item);
            break;
        case 2:
            first = Delete_rear(first);
            break;
        case 3:
            display(first);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
