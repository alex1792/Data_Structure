#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MaxLine 1024

void postFix(char *line)
{
    char *ptr = line;
    int stack[MaxLine];
    int top = -1;
    int max = -1;
    stack[0] = '\0';
    while (*ptr != '\0')
    {
        if (*ptr - '1' >= 0 && *ptr - '9' <= 0)
        {
            stack[++top] = *ptr - '0';
            if (top + 1 > max)
            {
                max = top + 1;
            }
        }
        else
        {
            if (*ptr == '+')
            {
                stack[top - 1] = stack[top - 1] + stack[top];
                top--;
            }
            else if (*ptr == '-')
            {
                stack[top - 1] = stack[top - 1] - stack[top];
                top--;
            }
            else if (*ptr == '*')
            {
                stack[top - 1] = stack[top - 1] * stack[top];
                top--;
            }
            else if (*ptr == '/')
            {
                stack[top - 1] = stack[top - 1] / stack[top];
                top--;
            }
        }
        ptr++;
    }
    printf("%d\n%d\n", stack[top], max);
}

int main()
{
    int time;
    char line[MaxLine];

    scanf("%d\n", &time);
    for (int i = 0; i < time; i++)
    {
        scanf("%s", line);
        postFix(line);
    }
    return 0;
}