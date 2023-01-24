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
NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("list is empty\n");
        return first;
    }
    else
    {
        temp = first;
        printf("deleted element is %d\n", temp->info);
        temp = temp->link;
        free(first);
        return temp;
    }
}
void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = first;
        printf("elements are\n");
        while (temp != NULL)
        {
            printf(" %d", temp->info);
            temp = temp->link;
        }
        printf("\n");
    }
}
int main()
{
    NODE first = NULL;
    int choice, item;
    while (1)
    {
        printf("enter choice\n");
        printf("1.Insert\t2.Delete\t3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter item\n");
            scanf("%d", &item);
            first = insert_front(first, item);
            break;
        case 2:
            first = delete_front(first);
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
