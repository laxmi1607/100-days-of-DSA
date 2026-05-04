#include <stdio.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix
int visited[MAX];
int n;

/* Recursive DFS function */
void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int edges, u, v, start;

    /* Input number of vertices */
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Initialize graph with 0 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    /* Input number of edges */
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Input adjacency list (edges) */
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        /* Undirected graph */
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    /* Starting vertex */
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* DFS Traversal */
    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}