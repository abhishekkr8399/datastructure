#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE create_node(int val)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}
NODE create_BS_Tree(NODE root, int val)
{
    if (root == NULL)
    {
        root = create_node(val);
    }
    else
    {
        NODE p, q;
        p = q = root;
        while (val != p->data && q != NULL)
        {
            p = q;
            if (val < p->data)
                q = p->llink;
            else
                q = p->rlink;
        }
        if (val == p->data)
        {
            printf("Duplication is not allowed\n");
        }
        else if (val < p->data)
            p->llink = create_node(val);
        else
            p->rlink = create_node(val);
    }
    return root;
}
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}
void search(NODE root, int key)
{
    NODE p, q;
    p = q = root;
    while (key != p->data && q != NULL)
    {
        p = q;
        if (key < p->data)
            q = p->llink;
        else
            q = p->rlink;
    }
    if (key == p->data)
        printf("Search is successful\n");
    else
        printf("Key element not found\n");
}
int maximum(NODE root)
{
    while (root->rlink != NULL)
    {
        root = root->rlink;
    }
    return root->data;
}
int main()
{
    int choice, val, key, max;
    NODE root = NULL;
    while (1)
    {
        printf("Enter your Choice\n");
        printf("1 Insert node in tree\n2 In-order\n3 Search element in tree\n4 Maximum\n5 Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &val);
            root = create_BS_Tree(root, val);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the element to be searched\n");
            scanf("%d", &key);
            search(root, key);
            break;
        case 4:
            max = maximum(root);
            printf("Maximum element is %d\n", max);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
