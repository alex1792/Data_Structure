#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define Max 21
#define wordMax 32
#define Infinite 9999999

void insertName(char name[][wordMax], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        scanf("%s", name[i]);
    }
}

void insertEdges(int dist[][Max], int vertices, int edge)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            dist[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        dist[a - 1][b - 1] = dist[b - 1][a - 1] = cost;
    }
}

// check if all vertices are chosen or not
int allFind(int state[], int verticeCnt)
{
    int ret = 0;
    for (int i = 0; i < verticeCnt; i++)
    {
        if (state[i] == 1)
        {
            ret++;
        }
    }
    if (ret != verticeCnt)
    {
        return 0;
    }
    return 1;
}

int dijkstra(int adjMatrix[][Max], int verticesCnt, int target)
{
    //  to save the shortest path from every vertex to target vertex
    int shortest_path[verticesCnt];
    //  use to note that whether the vertex was chosen or not
    int state[verticesCnt];

    // initialize the state and set them to "not chosen"
    for (int i = 0; i < verticesCnt; i++)
    {
        state[i] = 0;
    }

    //  start from target vertices
    for (int i = 0; i < verticesCnt; i++)
    {
        if (i == target)
        {
            state[target] = 1;
        }
        if (adjMatrix[target][i] == 0 && i != target)
        {
            shortest_path[i] = Infinite;
        }
        else
        {
            shortest_path[i] = adjMatrix[target][i];
        }
    }

    for (int i = 0; i < verticesCnt - 1; i++)
    {
        //  find shortest cost in shortest_path array and choose it as next vertex
        int minPath = shortest_path[0];
        int minPathIdx = 0;
        for (int j = 0; j < verticesCnt; j++)
        {
            if (shortest_path[j] < minPath && state[j] == 0)
            {
                minPath = shortest_path[j];
                minPathIdx = j;
            }
        }

        // set the minPathIdx vertex's state to 1(found the shortest path)
        state[minPathIdx] = 1;
        if (allFind(state, verticesCnt) == 1)
        {
            break;
        }

        // choose the least cost vertex and determine the shortest_path
        int currentCost = shortest_path[minPathIdx];
        for (int j = 0; j < verticesCnt; j++)
        {
            if (state[j] == 1)
            {
                continue;
            }
            else
            {
                if (currentCost + adjMatrix[minPathIdx][j] < shortest_path[j])
                {
                    if (adjMatrix[minPathIdx][j] == 0)
                    {
                        continue;
                    }
                    shortest_path[j] = currentCost + adjMatrix[minPathIdx][j];
                }
                else if (adjMatrix[minPathIdx][j] == 0 && state[j] == 0)
                {
                    continue;
                }
            }
        }
    }

    // the cost of every vertex to target vertex
    int sum = 0;
    for (int i = 0; i < verticesCnt; i++)
    {
        sum += shortest_path[i];
    }
    return sum;
}

int main()
{
    // variables
    int verticeCnt, edges;
    int totalCaseCnt = 1;

    while (scanf("%d %d", &verticeCnt, &edges) != EOF)
    {
        // vertex name and adjacency matrix
        char vertices[Max][wordMax];
        int dist[Max][Max];

        if (verticeCnt == 0 && edges == 0)
        {
            break;
        }
        if (totalCaseCnt != 1)
        {
            printf("\n");
        }

        // insert names of vertices and cost of edges
        insertName(vertices, verticeCnt);
        insertEdges(dist, verticeCnt, edges);

        // finalCase is use to save the cost of every vertex as the target vertex
        int finalCase[verticeCnt];
        for (int i = 0; i < verticeCnt; i++)
        {
            finalCase[i] = dijkstra(dist, verticeCnt, i);
        }

        // find the least cost
        int min = finalCase[0];
        int minIdx = 0;
        for (int i = 0; i < verticeCnt; i++)
        {
            if (min > finalCase[i])
            {
                min = finalCase[i];
                minIdx = i;
            }
        }
        printf("Case #%d %s", totalCaseCnt, vertices[minIdx]);
        totalCaseCnt++;
    }

    return 0;
}