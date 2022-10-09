#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 1024

struct Tnode
{
    int data;
    struct Tnode *l_child;
    struct Tnode *r_child;
};

char *getWord(char *line, char *word)
{
    char *ptr = line;
    char *qtr = word;
    while (isspace(*ptr))
    {
        ptr++;
    }
    while (!isspace(*ptr) && *ptr != '\0')
    {
        *qtr++ = *ptr++;
    }
    *qtr = '\0';
    if (strlen(word) == 0)
    {
        return NULL;
    }
    else
    {
        return ptr;
    }
}

struct Tnode *BSTinsert(struct Tnode *root, int data)
{
    struct Tnode *newNode = malloc(sizeof(struct Tnode));
    newNode->data = data;
    newNode->l_child = NULL;
    newNode->r_child = NULL;

    if (root == NULL)
    {
        return newNode;
    }

    struct Tnode *tmp = root;
    while (tmp)
    {
        if (data > tmp->data)
        {
            if (tmp->r_child == NULL)
            {
                tmp->r_child = newNode;
                break;
            }
            tmp = tmp->r_child;
        }
        else if (data < tmp->data)
        {
            if (tmp->l_child == NULL)
            {
                tmp->l_child = newNode;
                break;
            }
            tmp = tmp->l_child;
        }
    }
    return root;
}

void inOrderTraversal(struct Tnode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->l_child);
        printf("%d ", root->data);
        inOrderTraversal(root->r_child);
    }
}

struct Tnode *dequeue(struct Tnode queue[Max], int *front)
{
    return &queue[*front--];
}

void enqueue(struct Tnode *node, struct Tnode **queue, int *rear)
{
    *rear += 1;
    queue[*rear] = node;
}

int isEmpty(int front, int rear)
{
    if (front > rear)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void levelOrderTraversal(struct Tnode *root)
{
    struct Tnode *queue[Max];
    int front = 0;
    int rear = 0;
    queue[rear] = root;

    while (isEmpty(front, rear))
    {
        // printf("in\n");
        struct Tnode *tmp = queue[front];
        printf("%d ", tmp->data);
        if (tmp->l_child != NULL)
        {
            enqueue(tmp->l_child, queue, &rear);
        }
        if (tmp->r_child != NULL)
        {
            enqueue(tmp->r_child, queue, &rear);
        }
        front++;
    }
}

int main()
{
    char line[100];
    struct Tnode *root = NULL;
    while (fgets(line, 100, stdin) != NULL)
    {
        char word[100];
        char *ptr = line;
        ptr = getWord(ptr, word);
        if (strcmp(word, "00") == 0)
        {
            break;
        }
        int input = (int)atoi(word);
        // printf("input:%d\n", input);
        root = BSTinsert(root, input);
    }

    printf("Infixorder: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Levelorder: ");
    levelOrderTraversal(root);
    // printf("\n");

    return 0;
}