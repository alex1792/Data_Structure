#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 1024

struct Tnode
{
    int data;
    int coin;
    struct Tnode *l_child;
    struct Tnode *r_child;
};

char *getWord(char *line, char *word)
{
    char *ptr = line;
    char *qtr = word;
    // skip space and ','
    while (isspace(*ptr) || *ptr == ',')
    {
        ptr++;
    }
    // copy the charactor into word array
    while (!isspace(*ptr) && *ptr != '\0' && *ptr != ',')
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

struct Tnode *BSTinsert(struct Tnode *root, int data, int money)
{
    struct Tnode *newNode = malloc(sizeof(struct Tnode));
    newNode->data = data;
    newNode->coin = money;
    newNode->l_child = NULL;
    newNode->r_child = NULL;

    // create BST
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

void go2Leaf(struct Tnode *node, int path[], int pathLen, int coinCnt, int *maxCoin, char allPath[][Max], int *pathCnt)
{
    if (node == NULL)
    {
        return;
    }

    // record the path and number of collected coin
    path[pathLen] = node->data;
    pathLen++;
    coinCnt += node->coin;

    // is leaf node, then determin the coin and the path
    if (node->l_child == NULL && node->r_child == NULL)
    {
        if (coinCnt >= *maxCoin)
        {
            // number of collected coin is greater than max coin
            if (coinCnt > *maxCoin)
            {
                // repalece the value of max coin
                *maxCoin = coinCnt;
                // copy the path into allPath 2-D array, start from the begining
                for (int i = 0; i < pathLen; i++)
                {
                    char buffer[10];
                    // turn the path from integer type into string type save in buffer
                    sprintf(buffer, "%d", path[i]);
                    // the use string concatnation to connect the path
                    strcat(allPath[0], " ");
                    strcat(allPath[0], buffer);
                }
                *pathCnt = 1;
            }
            else
            {
                // copy path into allPath 2-D array
                for (int i = 0; i < pathLen; i++)
                {
                    char buffer[10];
                    sprintf(buffer, "%d", path[i]);
                    strcat(allPath[*pathCnt], " ");
                    strcat(allPath[*pathCnt], buffer);
                }
                *pathCnt += 1;
            }
        }
    }
    // is not a leaf node, the keep visiting next node(left goes first)
    else
    {
        go2Leaf(node->l_child, path, pathLen, coinCnt, maxCoin, allPath, pathCnt);
        go2Leaf(node->r_child, path, pathLen, coinCnt, maxCoin, allPath, pathCnt);
    }
}

void printPath(struct Tnode *root)
{
    // variables and initialization
    int path[100];
    int coinCnt = 0;
    int maxCoin = 0;
    int pathCnt = 0;
    char allPath[Max][Max];

    // find the path recursively
    go2Leaf(root, path, 0, coinCnt, &maxCoin, allPath, &pathCnt);

    // print out the consequences
    for (int i = 0; i < pathCnt; i++)
    {
        printf("Trajectory %d:%s\n", i + 1, allPath[i]);
    }

    printf("Coins: %d\n", maxCoin);
}

// free the tree in post order traversal
void freeTree(struct Tnode *root)
{
    if (root->l_child == NULL && root->r_child == NULL)
    {
        free(root);
    }
    else
    {
        freeTree(root->l_child);
        freeTree(root->r_child);
        free(root);
    }
}

int main()
{
    // variables
    char line[100];
    struct Tnode *root = NULL;

    while (fgets(line, 100, stdin) != NULL)
    {
        // varaibles
        char word[100];
        char *ptr = line;

        // get first number using getWord function
        ptr = getWord(ptr, word);
        // check if reach the end of input
        if (strcmp(word, "00") == 0)
        {
            break;
        }
        // the number to compare in BST
        int input = (int)atoi(word);

        // get another number using getWord function
        ptr = getWord(ptr, word);
        // use atoi to transform the string into integer
        int coin = (int)atoi(word);

        // insert into BST
        root = BSTinsert(root, input, coin);
    }

    // find every root to leaf path and save them into array(using recursive function)
    printPath(root);

    // free the BST
    freeTree(root);

    return 0;
}