#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

// Find vertex with minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 1; v <= n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    // Initialize all keys as infinite
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from vertex 1
    key[1] = 0;
    parent[1] = -1;

    // MST will have n vertices
    for (int count = 1; count < n; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total MST weight
    int totalWeight = 0;

    for (int i = 2; i <= n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    printf("%d\n", totalWeight);

    return 0;
}