// Minimum Meeting Rooms Required using Sorting + Min Heap
#include <stdio.h>
#include <stdlib.h>

// Meeting structure
typedef struct {
    int start, end;
} Meeting;

// Compare meetings by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Min Heap functions
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert into heap
void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size) - 1);
}

// Remove min from heap
void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int n, i;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];

    printf("Enter start and end times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // Step 1: Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    // Min heap for end times
    int heap[n];
    int heapSize = 0;

    // First meeting gets one room
    insertHeap(heap, &heapSize, meetings[0].end);

    int maxRooms = 1;

    // Process remaining meetings
    for (i = 1; i < n; i++) {

        // If earliest room is free, reuse it
        if (meetings[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        // Allocate current meeting room
        insertHeap(heap, &heapSize, meetings[i].end);

        // Update max rooms
        if (heapSize > maxRooms) {
            maxRooms = heapSize;
        }
    }

    printf("Minimum rooms required = %d\n", maxRooms);

    return 0;
}