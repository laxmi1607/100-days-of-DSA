#include <stdio.h>

#define MAX 100

int main() {
    int n, edges;
    int graph[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX], index = 0;

    // Input vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input directed edges
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;   // Increase in-degree of destination
    }

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // Kahn's Algorithm
    while (front <= rear) {
        int current = queue[front++];
        topo[index++] = current;

        // Reduce indegree of adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    // Check for cycle
    if (index != n) {
        printf("Cycle exists! Topological sort not possible.\n");
    } else {
        printf("Topological Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}