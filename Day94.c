#include <stdio.h>

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Step 2: Create frequency array
    int count[max + 1];

    // Initialize frequency array with 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 3: Compute prefix sums
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 4: Build output array (stable sorting)
    int output[n];

    // Traverse from end to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy output to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}