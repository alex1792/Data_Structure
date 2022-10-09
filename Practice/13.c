#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
    int value;
    struct Tnode *rChild;
    struct Tnode *lChild;
};

struct Tnode *BSTinsert(struct Tnode *root, int input)
{
    struct Tnode *tmp, *parent;
    struct Tnode *new = malloc(sizeof(struct Tnode));
    new->value = input;
    new->lChild = NULL;
    new->rChild = NULL;

    if (root == NULL)
    {
        return new;
    }

    tmp = root;
    parent = NULL;

    while (1)
    {
        parent = tmp;

        if (input > tmp->value)
        {
            tmp = parent->rChild;
            if (tmp == NULL)
            {
                parent->rChild = new;
                return root;
            }
        }
        else if (input < tmp->value)
        {
            tmp = parent->lChild;
            if (tmp == NULL)
            {
                parent->lChild = new;
                return root;
            }
        }
    }
}

void inOrder(struct Tnode *root)
{
    if (root != NULL)
    {
        inOrder(root->lChild);
        printf("%d ", root->value);
        inOrder(root->rChild);
    }
}

void postOrder(struct Tnode *root)
{
    if (root != NULL)
    {
        postOrder(root->lChild);
        postOrder(root->rChild);
        printf("%d ", root->value);
    }
}

void preOrder(struct Tnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->lChild);
        preOrder(root->rChild);
    }
}

void freeTree(struct Tnode *root)
{
    if (root->lChild != NULL)
    {
        freeTree(root->lChild);
    }
    if (root->rChild != NULL)
    {
        freeTree(root->rChild);
    }
    free(root);
}

int main()
{
    struct Tnode *root = NULL;
    int input;
    while (scanf("%d", &input) != EOF)
    {
        root = BSTinsert(root, input);
    }

    inOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    freeTree(root);

    return 0;
}