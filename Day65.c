// C Program to Detect Cycle in an Undirected Graph using DFS + Parent Tracking

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency List Node
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *adj[MAX];
int visited[MAX];

// Create new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (Undirected Graph)
void addEdge(int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function to detect cycle
int dfs(int current, int parent)
{
    visited[current] = 1;

    Node *temp = adj[current];

    while (temp != NULL)
    {
        int neighbor = temp->vertex;

        // If not visited, continue DFS
        if (!visited[neighbor])
        {
            if (dfs(neighbor, current))
                return 1;
        }
        // If visited and not parent => cycle found
        else if (neighbor != parent)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

// Main function
int main()
{
    int n, m;
    int u, v;
    int hasCycle = 0;

    // Initialize
    for (int i = 0; i < MAX; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    // Input edges
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Check all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    // Output result
    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}