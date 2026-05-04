#include <stdio.h>

#define MAX 1000

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];

    int i = left;      // Left subarray
    int j = mid + 1;   // Right subarray
    int k = left;

    // Merge in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining right elements
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

// Recursive Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge both halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    int arr[MAX];

    // Input size
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}