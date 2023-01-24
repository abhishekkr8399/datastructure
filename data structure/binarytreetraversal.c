#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *NODE;
NODE create_B_Tree()
{
    NODE newnode;
    int data = 0;
    newnode = NULL;
    printf("Enter data ('0' if no data)");
    scanf("%d", &data);
    if (data)
    {
        newnode = (NODE)malloc(sizeof(struct node));
        newnode->info = data;
        printf("\nLeft child of %d\n", newnode->info);
        newnode->lchild = create_B_Tree();
        printf("\nRight child of %d\n", newnode->info);
        newnode->rchild = create_B_Tree();
    }
    return newnode;
}
void pre_order(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->info);
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}
void post_order(NODE root)
{
    if (root != NULL)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        printf("%d\t", root->info);
    }
}
void in_order(NODE root)
{
    if (root != NULL)
    {
        in_order(root->lchild);
        printf("%d\t", root->info);
        in_order(root->rchild);
    }
}
int main()
{
    printf("Create binary tree, start from root\n");
    NODE root;
    root = create_B_Tree();
    while (1)
    {
        printf("Select mode of traversal for displaying the binary tree\n");
        printf("1 Pre-order\n2 Post-order\n3 In-order\n4 Exit\nChoice \n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The pre-order traversal is \n");
            pre_order(root);
            printf("\n");
            break;
        case 2:
            printf("The Post-order traversal is \n");
            post_order(root);
            printf("\n");
            break;
        case 3:
            printf("The In-order traversal is \n");
            in_order(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
