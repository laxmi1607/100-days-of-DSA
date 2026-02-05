//Insert an Element in an Array

/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space.*/
#include <stdio.h>
int main()
{
    int n, pos, value;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n + 1]; 
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);
    printf("Enter the position (1-based index) to insert the value: ");
    scanf("%d", &pos);

    for(int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1]; 
        
    }
    arr[pos - 1] = value;
    n++;
    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

