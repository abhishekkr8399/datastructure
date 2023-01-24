#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE insert_rear(NODE head, int val)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->info = val;
    if (head->rlink == head)
    {
        head->rlink = newnode;
        head->llink = newnode;
        newnode->llink = head;
        newnode->rlink = head;
        return head;
    }
    else
    {
        NODE temp = head->llink;
        temp->rlink = newnode;
        newnode->llink = temp;
        newnode->rlink = head;
        head->llink = newnode;
        return head;
    }
}
NODE delete_front(NODE head)
{
    int del;
    NODE temp = head->rlink;
    if (head->rlink == head)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        NODE next = temp->rlink;
        head->rlink = next;
        next->llink = head;
        del = temp->info;
        free(temp);
        printf("%d deleted\n", del);
        return head;
    }
}
void display(NODE head)
{
    if (head->rlink == head)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        printf("Contents of the Circular Doubly Linked list are\n");
        NODE temp = head->rlink;
        while (temp != head)
        {
            printf("%d ", temp->info);
            temp = temp->rlink;
        }
        printf("\n");
    }
}
NODE insert_right(NODE head, int key, int val)
{
    NODE temp = head->rlink;
    while (temp != head)
    {
        if (temp->info == key)
            break;
        temp = temp->rlink;
    }
    if (temp == head)
    {
        printf("Key not found\n");
        return head;
    }
    else
    {
        NODE newnode;
        newnode = (NODE)malloc(sizeof(struct node));
        newnode->info = val;
        NODE next = temp->rlink;
        temp->rlink = newnode;
        newnode->llink = temp;
        newnode->rlink = next;
        next->llink = newnode;
        return head;
    }
}
int main()
{
    NODE head = (NODE)malloc(sizeof(struct node));
    head->info = 0;
    head->rlink = head;
    head->llink = head;
    int choice, val, key;
    for (;;)
    {
        printf("Enter your choice\n1 Insert rear\n2 Delete front\n3 Insert right\n4 Display\n5 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d", &val);
            head = insert_rear(head, val);
            break;
        case 2:
            head = delete_front(head);
            break;
        case 3:
            printf("Enter the element present in list after which the element has to be entered\n");
            scanf("%d", &key);
            printf("Enter a element to be added\n");
            scanf("%d", &val);
            head = insert_right(head, key, val);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}
