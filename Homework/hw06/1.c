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

void quickSort(int *number, int left, int right, int dataCnt)
{
    if (left < right)
    {
        int i = left;
        int j = right + 1;
        int pivot = number[left];
        do
        {
            do
            {
                i++;
            } while (number[i] < pivot);

            do
            {
                j--;
            } while (number[j] > pivot);

            if (i < j)
            {
                swap(&number[i], &number[j]);
            }
        } while (i < j);

        swap(&number[left], &number[j]);

        for (int i = 0; i < dataCnt; i++)
        {
            printf("%d", number[i]);
            if (i < dataCnt - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
        quickSort(number, left, j - 1, dataCnt);  //  less than pivot
        quickSort(number, j + 1, right, dataCnt); //  greater than pivot
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

        quickSort(inputData, 0, dataCnt - 1, dataCnt);
    }
    return 0;
}