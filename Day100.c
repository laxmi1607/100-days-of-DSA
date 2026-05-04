// Count Smaller Elements on Right Side using Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int value;
    int index;
} Element;

// Merge function
void merge(Element arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Element L[n1], R[n2];

    int i, j, k;

    // Copy data
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    int rightCount = 0;

    // Merge while counting smaller elements
    while(i < n1 && j < n2) {

        // Right element is smaller
        if(R[j].value < L[i].value) {
            arr[k++] = R[j++];
            rightCount++;
        }
        else {
            // Add count of smaller right elements
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
    }

    // Remaining left elements
    while(i < n1) {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    // Remaining right elements
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort
void mergeSort(Element arr[], int left, int right, int count[]) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Element arr[n];
    int count[n];

    // Initialize count array
    for(i = 0; i < n; i++)
        count[i] = 0;

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    // Perform merge sort count
    mergeSort(arr, 0, n - 1, count);

    // Output result
    printf("Count of smaller elements on right:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}