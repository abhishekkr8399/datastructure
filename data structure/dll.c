#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE insert_front(NODE first, int val)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->info = val;
    newnode->llink = NULL;
    if (first == NULL)
    {
        first = newnode;
        newnode->rlink = NULL;
        return first;
    }
    else
    {
        newnode->rlink = first;
        first->llink = newnode;
        return newnode;
    }
}
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return first;
    }
    cur = first;
    if (first->rlink == NULL)
    {
        printf("Deleted data is %d\n", first->info);
        free(first);
        return NULL;
    }
    else
    {
        prev = NULL;
        while (cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        prev = cur->llink;
        prev->rlink = NULL;
        printf("Deleted data is %d\n", cur->info);
        free(cur);
        return first;
    }
}
void display(NODE first)
{
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        NODE temp = first;
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->rlink;
        }
        printf("\n");
    }
}
int main()
{
    NODE first = NULL;
    int choice, val;
    while (1)
    {
        printf("Enter your choice\n1 Insert front\n2 Delete rear\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &val);
            first = insert_front(first, val);
            break;
        case 2:
            first = delete_rear(first);
            break;
        case 3:
            display(first);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
