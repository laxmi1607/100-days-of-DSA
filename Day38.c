#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *b = *a;
    *a = temp;
}

void heapifyUp(MinHeap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->arr[i] < h->arr[parent]) {
            int temp = h->arr[i];
            h->arr[i] = h->arr[parent];
            h->arr[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(MinHeap *h, int i) {
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;

        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest != i) {
            int temp = h->arr[i];
            h->arr[i] = h->arr[smallest];
            h->arr[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}

void insert(MinHeap *h, int x) {
    if (h->size == MAX)
        return;

    h->arr[h->size] = x;
    heapifyUp(h, h->size);
    h->size++;
}

int extractMin(MinHeap *h) {
    if (h->size == 0)
        return -1;

    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapifyDown(h, 0);

    return root;
}

int peek(MinHeap *h) {
    if (h->size == 0)
        return -1;
    return h->arr[0];
}

int main() {
    int n;
    scanf("%d", &n);

    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            int x;
            scanf("%d", &x);
            insert(&heap, x);
        }
        else if (op[0] == 'e') {  // extractMin
            printf("%d\n", extractMin(&heap));
        }
        else if (op[0] == 'p') {  // peek
            printf("%d\n", peek(&heap));
        }
    }

    return 0;
}