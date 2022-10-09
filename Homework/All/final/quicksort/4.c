#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 1024

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// int done(int *arr, int dataCnt)
// {
//     for(int i = 0; i < dataCnt - 1; i++)
//     {
//         if(arr[i] > arr[i + 1])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

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
                for (int i = 0; i < dataCnt; i++)
                {
                    printf("%d", number[i]);
                    if (i < dataCnt - 1)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        } while (i < j);
        // printf("number[left]:%d\tnumber[j]:%d\n", number[left], number[j]);
        if (number[left] > number[j])
        {
            swap(&number[left], &number[j]);

            for (int i = 0; i < dataCnt; i++)
            {
                printf("%d", number[i]);
                if (i < dataCnt - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
            quickSort(number, left, j - 1, dataCnt);  //  less than pivot
            quickSort(number, j + 1, right, dataCnt); //  greater than pivot
        }
    }
}

int main()
{
    // char line[Max];
    int inputData[Max];
    int dataCnt = 0;
    while (scanf("%d", &inputData[dataCnt]) != EOF)
    {
        dataCnt++;
    }
    quickSort(inputData, 0, dataCnt - 1, dataCnt);
    return 0;
}