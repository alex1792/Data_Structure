#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MaxLine 1024

int isOperator(char *ptr)
{
    if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/')
    {
        return 1;
    }
    return 0;
}

int isOperand(char *ptr)
{
    if (*ptr - 'a' >= 0 && *ptr - 'z' <= 0)
    {
        return 1;
    }
    return 0;
}

int precedence(char *ptr)
{
    if (*ptr == '+' || *ptr == '-')
    {
        return 1;
    }
    else if (*ptr == '*' || *ptr == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void infix2Postfix(char *line)
{
    char *ptr = line;
    char string[MaxLine];
    char stack[MaxLine];
    string[0] = '\0';
    stack[0] = '?';
    int stringTop = -1;
    int stackTop = 0;

    while (*ptr != '\n')
    {
        // printf("%c", *ptr);
        // numbers -> push into string
        if (isOperand(ptr))
        {
            string[++stringTop] = *ptr;
        }
        else if (*ptr == '(')
        {
            stackTop++;
            stack[stackTop] = *ptr;
        }
        else if (*ptr == ')')
        {
            while (stack[stackTop] != '(')
            {
                stringTop++;
                string[stringTop] = stack[stackTop];
                stackTop--;
            }
            stack[stackTop] = 0;
            // 跳過'('
            stackTop--;
        }
        // is operator
        else
        {
            if (precedence(ptr) > precedence(&stack[stackTop]))
            {
                stack[++stackTop] = *ptr;
            }
            else
            {
                while (stackTop > 0 && precedence(ptr) <= precedence(&stack[stackTop]))
                {
                    stringTop++;
                    string[stringTop] = stack[stackTop];
                    stackTop--;
                }
                stack[++stackTop] = *ptr;
            }
        }
        ptr++;
    }

    // printf("stackTop:%d\n", stackTop);
    while (stackTop > 0)
    {
        stringTop++;
        string[stringTop] = stack[stackTop];
        stackTop--;
        // string[++stringTop] = stack[stackTop--];
    }
    string[++stringTop] = '\0';
    printf("%s\n", string);
}

int main()
{
    char line[MaxLine];
    int time;
    scanf("%d\n", &time);
    for (int i = 0; i < time; i++)
    {
        fgets(line, MaxLine, stdin);
        infix2Postfix(line);
    }
    return 0;
}