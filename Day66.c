#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int V; // number of vertices
int adj[MAX][MAX]; // adjacency matrix

// DFS function to detect cycle
bool dfs(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            // If not visited, recurse
            if (!visited[i] && dfs(i, visited, recStack))
                return true;
            // If already in recursion stack → cycle
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false; // remove from recursion stack
    return false;
}

// Function to check cycle in graph
bool hasCycle() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}