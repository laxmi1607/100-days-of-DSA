//Delete an Element from an Array

//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
#include <stdio.h>
int main()
{
    int n, pos;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position (1-based index) to delete the value: ");
    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; 
    }
    n--;
    printf("Array after deletion:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}