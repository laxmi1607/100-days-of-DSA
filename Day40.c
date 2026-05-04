#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    /* Phase 1: Build Max Heap */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Phase 2: Extract elements one by one */
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]); /* Move current max to end */
        heapify(arr, i, 0);     /* Restore heap on reduced range */
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("After:  ");
    printArray(arr, n);

    return 0;
}