#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n, m;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Input vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize graph and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;

        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges (undirected graph)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Start DFS from vertex 1
    dfs(1);

    // Check if all vertices are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}