#include <stdio.h>

#define MAX 1000

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];

    int i = left;      // Start of left subarray
    int j = mid + 1;   // Start of right subarray
    int k = left;

    // Merge elements in sorted order
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

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy merged elements back to original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sort left half
        mergeSort(arr, left, mid);

        // Sort right half
        mergeSort(arr, mid + 1, right);

        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[MAX];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}