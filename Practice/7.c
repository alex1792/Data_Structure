#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 128
#define Right 4
#define Down 3
#define Left 2
#define Up 1

struct POS
{
    int x;
    int y;
};

void scanMaze(char maze[][11], char visited[][11])
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", maze[i]);
        strcpy(visited[i], maze[i]);
    }
}

int runMaze(struct POS *person, char visited[][11])
{
    int x = person->x;
    int y = person->y;

    // go right
    if (visited[y][x + 1] == '0')
    {
        person->x += 1;
        return Right;
    }
    // go down
    else if (visited[y + 1][x] == '0')
    {
        // printf("go down\n");
        person->y += 1;
        return Down;
    }
    // go left
    else if (visited[y][x - 1] == '0')
    {
        person->x -= 1;
        return Left;
    }
    // go up
    else if (visited[y - 1][x] == '0')
    {
        person->y -= 1;
        return Up;
    }
    // dead end
    else
    {
        return 0;
    }
}

int main()
{
    char maze[10][11], visited[10][11];
    int top = 0;
    struct POS stack[Max];
    struct POS person;
    person.x = 1;
    person.y = 1;

    scanMaze(maze, visited);

    stack[top] = person;

    printf("(%d,%d),", person.y, person.x);

    while (top >= 0)
    {
        int ret = runMaze(&person, visited);

        // dead end -> go back to last position
        if (ret == 0)
        {
            // printf("\nstack top:(%d,%d)\n", stack[top].x, stack[top].y);
            top--;
            person.x = stack[top].x;
            person.y = stack[top].y;
        }
        else
        {
            stack[++top] = person;
            // printf("stack top:(%d,%d)\n", stack[top].x, stack[top].y);
            visited[person.y][person.x] = '2';
        }

        if (person.x == 8 && person.y == 8)
        {
            printf("(8,8)\n");
            break;
        }
        printf("(%d,%d),", person.y, person.x);
    }

    return 0;
}