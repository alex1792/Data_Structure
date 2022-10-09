#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 1025

struct Lnode
{
    char word[Max];
    struct Lnode *next;
};

char *getWord(char *ptr, char *word)
{
    char *qtr = word;
    while (isspace(*ptr) && *ptr != '\0')
    {
        ptr++;
    }
    while (!isspace(*ptr) && *ptr != '\0' && *ptr != '\n')
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

struct Lnode *push2List(struct Lnode *head, char *word)
{
    struct Lnode *new = malloc(sizeof(struct Lnode));
    strcpy(new->word, word);
    new->next = NULL;

    if (head == NULL)
    {
        head = new;
        return head;
    }
    else
    {
        struct Lnode *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
        return head;
    }
}

void popFromList(struct Lnode *head)
{
    struct Lnode *cur, *pre;
    cur = head;
    pre = NULL;
    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = NULL;
    free(cur);
}

void printList(struct Lnode *head)
{
    struct Lnode *pre, *cur;
    cur = head;
    pre = NULL;
    while (cur != NULL)
    {
        pre = cur;
        printf("%s", cur->word);
        if (cur->next != NULL)
        {
            printf(",");
        }
        cur = cur->next;
        free(pre);
    }
}

int main()
{
    char line[Max];
    struct Lnode *stack = NULL;
    int size = 0;
    while (fgets(line, Max, stdin) != NULL)
    {
        // printf("%s", line);
        if (strlen(line) <= 1)
        {
            break;
        }
        char *ptr = line;
        char word[Max];
        while ((ptr = getWord(ptr, word)) != NULL)
        {
            if (strcmp(word, "Push") == 0)
            {
                ptr = getWord(ptr, word);
                stack = push2List(stack, word);
                size++;
                break;
            }
            else
            {
                popFromList(stack);
                size--;
                break;
            }
        }
        // printList(stack);
    }
    printf("%d\n", size);
    printList(stack);
    // printf("\n");
    return 0;
}