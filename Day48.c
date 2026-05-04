#include <stdio.h>

#define MAX 1000

int main()
{
    int n;
    scanf("%d", &n);

    // Special case: single node
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    int degree[MAX] = {0}; // to store degree of each node

    int u, v;

    // Read edges
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }

    int leaf_count = 0;

    // Count nodes with degree = 1
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 1)
        {
            leaf_count++;
        }
    }

    printf("%d\n", leaf_count);

    return 0;
}