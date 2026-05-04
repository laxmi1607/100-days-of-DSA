#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) { queue[rear++] = x; }

int dequeue() { return queue[front++]; }

int isEmpty() { return front == rear; }

int main() {
  int n, i, j, edges, s;

  scanf("%d", &n);

  int adj[MAX][MAX];
  int visited[MAX];

  for (i = 0; i < n; i++) {
    visited[i] = 0;
    for (j = 0; j < n; j++) {
      adj[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &edges); // number of neighbors
    for (j = 0; j < edges; j++) {
      int v;
      scanf("%d", &v);
      adj[i][v] = 1;
    }
  }

  scanf("%d", &s);

  /* BFS */
  enqueue(s);
  visited[s] = 1;

  while (!isEmpty()) {
    int current = dequeue();
    printf("%d ", current);

    for (i = 0; i < n; i++) {
      if (adj[current][i] == 1 && !visited[i]) {
        enqueue(i);
        visited[i] = 1;
      }
    }
  }

  return 0;
}