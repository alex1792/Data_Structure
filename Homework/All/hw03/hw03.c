#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxWord 128
#define maxLine 10240

struct Lnode
{
    char word[maxWord];
    struct Lnode *next;
};

int isAlpha(char *ptr)
{
    if (*ptr - 'a' >= 0 && *ptr - 'z' <= 0)
    {
        return 1;
    }
    else if (*ptr - 'A' >= 0 && *ptr - 'Z' <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *getWord(char *word, char *ptr)
{
    char *qtr = word;
    // is space or special character
    while (!isAlpha(ptr) && *ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    // copy the word
    while (isAlpha(ptr) && *ptr != '\0')
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

// search data in every node in linked list, if found, return the number of the node
int listFind(struct Lnode *head, char *word)
{
    int cnt = 1;
    // if the linked list is empty
    if (head == NULL)
    {
        return 0;
    }

    struct Lnode *tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->word, word) == 0)
        {
            return cnt;
        }
        else
        {
            tmp = tmp->next;
        }
        cnt++;
    }
    return 0;
}

struct Lnode *movingNode(struct Lnode *head, int number)
{
    if (number == 1)
    {
        return head;
    }
    struct Lnode *prev, *cur;
    cur = head;
    prev = cur;
    for (int i = 1; i < number; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    cur->next = head;
    return cur;
}

// insert a word into the linked list
struct Lnode *insert(struct Lnode *head, char *word)
{
    struct Lnode *tmp = malloc(sizeof(struct Lnode));
    strcpy(tmp->word, word);
    if (head == NULL)
    {
        tmp->next = NULL;
    }
    else
    {
        tmp->next = head;
    }
    return tmp;
}

// free the linked list
void freeList(struct Lnode *head)
{
    struct Lnode *prev, *cur;
    cur = head;

    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    free(cur);
}

int main()
{
    char line[maxLine], word[maxWord];
    char *ptr = NULL;
    // get a line each time
    while (fgets(line, maxLine, stdin) != NULL)
    {
        // nothing in that line
        if (strlen(line) <= 1)
        {
            continue;
        }

        // create the head of the linked list
        struct Lnode *list = NULL;
        ptr = line;

        // get word and search in the linked list
        while ((ptr = getWord(word, ptr)) != NULL)
        {
            int ret = listFind(list, word);

            // not found
            if (ret == 0)
            {
                printf("%s", word);
                list = insert(list, word);
            }
            // found -> print the number of node in the linked list and move the node to the head of list
            else
            {
                printf("%d", ret);
                list = movingNode(list, ret);
            }
        }
        // free linked list
        freeList(list);
    }
    return 0;
}