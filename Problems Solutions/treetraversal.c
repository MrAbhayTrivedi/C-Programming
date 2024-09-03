#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *pnode;
pnode root = NULL;
void insert(int val)
{
    pnode p, q, t;
    t = (pnode)malloc(sizeof(struct node));
    t->left = t->right = NULL;
    t->data = val;
    if (root == NULL)
    {
        root = t;
        return;
    }
    p = root;
    q = NULL;
    while (p)
    {
        if (p->data == val)
        {
            return;
        }
        q = p;
        if (val < p->data)
            p = p->left;
        else if (val > p->data)
            p = p->right;
    }
    if (val < q->data)
        q->left = t;
    if (val > q->data)
        q->right = t;
}
int search(int key)
{
    pnode p = root;
    while (p)
    {
        if (p->data == key)
            return 1;
        else if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
    }
    return 0;
}
void inorder(pnode p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%3d", p->data);
    inorder(p->right);
}
void preorder(pnode p)
{
    if (p == NULL)
        return;
    printf("%3d", p->data);
    preorder(p->left);
    preorder(p->right);
}
void postorder(pnode p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%3d", p->data);
}
int main()
{
    int ch, x;
    while (1)
    {
        printf("\n1.insertion");
        printf("\n2.inorder");
        printf("\n3.preorder");
        printf("\n4.postorder");
        printf("\n5.search");
        printf("\n6.exit");
        printf("\nenterur choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter an elements\n");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("enter key elements\n");
            scanf("%d", &x);
            if (search(x))
                printf("found");
            else
                printf("not found");
            break;
        case 6:
            exit(0);
        }
    }
}