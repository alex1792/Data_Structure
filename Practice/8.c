#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 1024

struct term
{
    int coefficient;
    int exponent;
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

void addPoly(struct term *A, int *aTop, struct term *B, int *bTop)
{
    struct term C[Max];
    int aIdx = 0;
    int bIdx = 0;
    int cIdx = 0;

    // printf("atop:%d\nbtop:%d\n", *aTop, *bTop);
    while (1)
    {
        if (aIdx == *aTop || bIdx == *bTop)
        {
            // printf("break!\n");
            break;
        }

        if (A[aIdx].exponent > B[bIdx].exponent)
        {
            // printf("a > b\n");
            C[cIdx].coefficient = A[aIdx].coefficient;
            C[cIdx].exponent = A[aIdx].exponent;
            cIdx++;
            aIdx++;
        }
        else if (A[aIdx].exponent < B[bIdx].exponent)
        {
            // printf("a < b\n");
            C[cIdx].coefficient = B[bIdx].coefficient;
            C[cIdx].exponent = B[bIdx].exponent;
            cIdx++;
            bIdx++;
        }
        else if (A[aIdx].exponent == B[bIdx].exponent)
        {
            // printf("same\n");
            C[cIdx].coefficient = A[aIdx].coefficient + B[bIdx].coefficient;
            C[cIdx].exponent = A[aIdx].exponent;
            cIdx++;
            aIdx++;
            bIdx++;
        }
    }
    while (aIdx != *aTop)
    {
        C[cIdx].coefficient = A[aIdx].coefficient;
        C[cIdx].exponent = A[aIdx].exponent;
        cIdx++;
        aIdx++;
    }
    while (bIdx != *bTop)
    {
        C[cIdx].coefficient = B[bIdx].coefficient;
        C[cIdx].exponent = B[bIdx].exponent;
        cIdx++;
        bIdx++;
    }
    for (int i = 0; i < cIdx; i++)
    {
        printf("%d %d\n", C[i].coefficient, C[i].exponent);
    }
}

int main()
{
    char line[Max];
    struct term A[Max];
    struct term B[Max];
    int aTop, bTop;
    aTop = bTop = 0;
    int state = 0;

    while (fgets(line, Max, stdin) != NULL)
    {
        if (strcmp(line, "next\n") == 0)
        {
            state = 1;
            continue;
        }
        else if (strcmp(line, "end\n") == 0)
        {
            // printf("end\n");
            break;
        }

        char *ptr = line;
        char word[Max];

        if (state == 0)
        {
            ptr = getWord(ptr, word);
            // printf("%s ", word);
            A[aTop].coefficient = atoi(word);
            ptr = getWord(ptr, word);
            // printf("%s\n", word);
            A[aTop].exponent = atoi(word);
            aTop++;
        }
        else if (state == 1)
        {
            ptr = getWord(ptr, word);
            B[bTop].coefficient = atoi(word);
            ptr = getWord(ptr, word);
            B[bTop].exponent = atoi(word);
            bTop++;
        }
    }

    addPoly(A, &aTop, B, &bTop);

    return 0;
}