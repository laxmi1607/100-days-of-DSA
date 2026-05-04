#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyUp(int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent])
        {
            swap(&heap[i], &heap[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int i)
{
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
        {
            break;
        }
    }
}

void insert(int val)
{
    heap[size] = val;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    if (size == 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return min;
}

int peek()
{
    if (size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n;
    scanf("%d", &n);

    char op[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (op[0] == 'i')
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e')
        {
            printf("%d\n", extractMin());
        }
        else if (op[0] == 'p')
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}