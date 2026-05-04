#include <stdio.h>

#define MAX 1000

// Merge two sorted halves and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // Left subarray
    int j = mid + 1;   // Right subarray
    int k = left;
    
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;

            // All remaining elements in left subarray form inversions
            inversions += (mid - i + 1);
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

    // Copy merged array back
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inversions;
}

// Modified Merge Sort
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        // Left half
        inversions += mergeSort(arr, temp, left, mid);

        // Right half
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Merge both halves
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[MAX], temp[MAX];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count inversions
    long long inversionCount = mergeSort(arr, temp, 0, n - 1);

    // Output result
    printf("%lld\n", inversionCount);

    return 0;
}