#include <stdio.h>

#define MAX 100

// Insertion Sort for each bucket
void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main() {
    int n;

    // Input number of elements
    scanf("%d", &n);

    float arr[MAX];

    // Input array elements (values in [0,1))
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create buckets
    float buckets[MAX][MAX];
    int bucketCount[MAX] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;   // Bucket index
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    // Concatenate all buckets
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}