#include <stdio.h>

#define MAX 1000

// Partition function using Lomuto Partition Scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Last element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++) {

        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot at correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Pivot index
}

// Recursive Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // Partition array
        int pi = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pi - 1);

        // Sort right part
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    int arr[MAX];

    // Input size
    scanf("%d", &n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}