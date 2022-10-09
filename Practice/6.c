#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 20480

void process(char *line)
{
    char *ptr = line;
    char stack[Max];
    int top = -1;
    stack[0] = '\0';

    while (*ptr != '\0' && *ptr != '\n')
    {
        // is alphabet
        if (*ptr - 'a' >= 0 && *ptr - 'z' <= 0)
        {
            stack[++top] = *ptr++;
        }
        // is number
        else if (*ptr - '0' >= 0 && *ptr - '9' <= 0)
        {
            stack[++top] = *ptr++;
        }
        else if (*ptr == '[')
        {
            stack[++top] = *ptr++;
        }
        else if (*ptr == ']')
        {
            char tmp[Max];
            tmp[0] = '\0';
            int cnt = 0;
            // get word in []
            while (stack[top] != '[')
            {
                tmp[cnt] = stack[top];
                cnt++;
                top--;
            }
            tmp[cnt] = '\0';

            // reverse the word
            for (int i = 0; i < cnt / 2; i++)
            {
                char c = tmp[i];
                tmp[i] = tmp[cnt - i - 1];
                tmp[cnt - i - 1] = c;
            }
            tmp[cnt] = '\0';

            top--;

            // get number k(maybe greater than 10)
            char buffer[Max];
            int bufferCnt = 0;
            buffer[0] = '\0';
            // get num in []
            while (stack[top] - '0' >= 0 && stack[top] - '9' <= 0)
            {
                buffer[bufferCnt++] = stack[top--];
            }
            buffer[bufferCnt] = '\0';
            // reverse
            for (int i = 0; i < bufferCnt / 2; i++)
            {
                char c = buffer[i];
                buffer[i] = buffer[bufferCnt - i - 1];
                buffer[bufferCnt - i - 1] = c;
            }
            buffer[bufferCnt] = '\0';
            int num = atoi(buffer);

            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < cnt; j++)
                {
                    stack[++top] = tmp[j];
                }
            }

            ptr++;
        }
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main()
{
    int time;
    char line[Max];

    scanf("%d\n", &time);
    for (int i = 0; i < time; i++)
    {
        scanf("%s", line);
        process(line);
        line[0] = '\0';
    }

    return 0;
}