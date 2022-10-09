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

// Utility function to find minimum of two numbers
int min(int x, int y)
{
    return (x < y) ? x : y;
}

// Merge two sorted subarrays A[from .. mid] and A[mid + 1 .. to]
void merge(int A[], int temp[], int from, int mid, int to, int dataCnt)
{
    int k = from, i = from, j = mid + 1;
    // printf("mid:%d\n", mid);

    // loop till there are elements in the left and right runs
    while (i <= mid && j <= to)
    {
        // printf("A[i]:%d\nA[j]:%d\n", A[i], A[j]);
        if (A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    // printf("before copy remaining\n");
    // for (int k = 0; k < dataCnt; k++)
    //     {
    //         printf("%d", temp[k]);
    //         if (k < dataCnt - 1)
    //         {
    //             printf(", ");
    //         }
    //     }
    //     printf("\n");

    // Copy remaining elements
    while (i < dataCnt && i <= mid)
    {
        // printf("A:%d\n", A[i]);
        temp[k++] = A[i++];
    }

    // Don't need to copy second half

    // copy back to the original array to reflect sorted order
    for (int i = from; i <= to; i++)
        A[i] = temp[i];
}

// Iteratively sort array A[low..high] using temporary array
void merge_sort(int A[], int temp[], int low, int high, int dataCnt)
{
    // divide the array into blocks of size m
    // m = [1, 2, 4, 8, 16...]
    for (int m = 1; m <= high - low; m = 2 * m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8
        // for m = 2, i = 0, 4, 8
        // for m = 4, i = 0, 8
        // ...
        for (int i = low; i < high; i += 2 * m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2 * m - 1, high);

            merge(A, temp, from, mid, to, dataCnt);
        }

        for (int k = 0; k < dataCnt; k++)
        {
            printf("%d", A[k]);
            if (k < dataCnt - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void minimumGap(int A[], int length)
{
    int gap;
    int minGap = 10000000;
    for (int i = 0; i < length - 1; i++)
    {
        gap = A[i + 1] - A[i];
        if (gap < minGap)
        {
            minGap = gap;
        }
    }
    printf("Minimum gap: %d", minGap);
}

int main()
{
    char line[Max];
    int inputData[Max];
    int sorted[Max];
    int dataCnt = 0;
    while (fgets(line, Max, stdin) != NULL)
    {
        char *ptr = line;
        char word[16];
        while ((ptr = getWord(ptr, word)) != NULL)
        {
            // printf("%s\n", word);
            inputData[dataCnt] = atoi(word);
            sorted[dataCnt] = inputData[dataCnt];
            dataCnt++;
        }
        // printf("original data:\n");
        // for (int i = 0; i < dataCnt; i++)
        // {
        //     printf("%d", inputData[i]);
        //     if (i < dataCnt - 1)
        //     {
        //         printf(", ");
        //     }
        // }
        // printf("\n");

        merge_sort(inputData, sorted, 0, dataCnt - 1, dataCnt);
        minimumGap(inputData, dataCnt);
    }
    return 0;
}