#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 1024

char *getWord(char *line, char *word)
{
    char *ptr = line;
    char *qtr = word;
    while (isspace(*ptr) || *ptr == ',')
    {
        ptr++;
    }
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

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selectionSort(int *number, int dataCnt)
{
    for (int i = 0; i < dataCnt - 1; i++)
    {
        int min = number[i];
        int minIdx = i;
        for (int j = i + 1; j < dataCnt; j++)
        {
            if (number[j] < min)
            {
                min = number[j];
                minIdx = j;
            }
        }
        // printf("minIdx:%d\n", minIdx);
        swap(&number[i], &number[minIdx]);

        for (int k = 0; k < dataCnt; k++)
        {
            printf("%d", number[k]);
            if (k < dataCnt - 1)
            {
                printf(", ");
            }
        }
        if (i < dataCnt - 1)
        {
            printf("\n");
        }
    }
}

int main()
{
    char line[Max];
    int inputData[Max];
    int dataCnt = 0;
    while (fgets(line, Max, stdin) != NULL)
    {
        char *ptr = line;
        char word[16];
        while ((ptr = getWord(ptr, word)) != NULL)
        {
            // printf("%s\n", word);
            inputData[dataCnt] = atoi(word);
            dataCnt++;
        }
        // for (int i = 0; i < dataCnt; i++)
        // {
        //     printf("%d\n", inputData[i]);
        // }

        selectionSort(inputData, dataCnt);
    }
    return 0;
}