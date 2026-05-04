#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

// Find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int source) {
    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Process all vertices
    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] &&
                !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input weighted edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}