#include <stdio.h>
#include <stdlib.h>
struct node
{
    char name[20];
    char usn[20];
    int sem;
    struct node *link;
} *first = NULL;
int c = 0;
void insert_pos(int i)
{
    if (i <= c + 1 && i > 0)
    {
        struct node *p, *t, *q;
        p = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter USN:");
        scanf("%s", p->usn);
        printf("\nEnter Sem:");
        scanf("%d", &p->sem);
        printf("\nEnter Name:");
        scanf("%s", p->name);
        p->link = NULL;
        if (first == NULL)
            first = p;
        else if (i == 1)
        {
            p->link = first;
            first = p;
        }
        else
        {
            int count = 1;
            t = first;
            q = first;
            while (count != i)
            {
                q = t;
                t = t->link;
                count++;
            }
            q->link = p;
            p->link = t;
        }
        c++;
    }
    else
        printf("Error Cannot Insert\n");
}
void del()
{
    struct node *p;
    p = first;
    if (first == NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    else if (first->link == NULL)
    {
        printf("Deleted details are:\n");
        printf("\nUSN: %s", first->usn);
        printf("\nSem: %d", first->sem);
        printf("\nName: %s", first->name);
        free(first);
        first = NULL;
    }
    else
    {
        first = p->link;
        printf("Deleted details are:\n");
        printf("\nUSN: %s", p->usn);
        printf("\nSem: %d", p->sem);
        printf("\nName: %s", p->name);
        free(p);
    }
    c--;
}
void display()
{
    struct node *p;
    p = first;
    if (first == NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    printf("Student details are:\n");
    while (p->link != NULL)
    {
        printf("\nUSN: %s", p->usn);
        printf("\nSem: %d", p->sem);
        printf("\nName: %s", p->name);
        p = p->link;
        printf("\n");
    }
    printf("\nUSN: %s", p->usn);
    printf("\nSem: %d", p->sem);
    printf("\nName: %s", p->name);
    p = p->link;
}
int main()
{
    printf("Student Information Linked List\n");
    while (1)
    {
        int f, ch;
        printf("\nMenu\t1.Insert\t2.Delete\t3.Display\n");
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Position to Insert:");
            scanf("%d", &f);
            insert_pos(f);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid");
            exit(0);
        }
    }
}