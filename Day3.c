/*Implement linear search to find key k in an array. Count and display the number of comparisons performed.
*/
#include <stdio.h>
int main()
{
    int n, k, comparisons = 0, found = 0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n]; // Create an array of size n
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key to search: ");
    scanf("%d", &k);

    for(int i = 0; i < n; i++)
    {
        comparisons++;
        if(arr[i] == k)
        {
            found = 1;
            printf("Key %d found at position %d.\n", k, i + 1);
            break;
        }
    }

    if(!found)
    {
        printf("Key %d not found in the array.\n", k);
    }

    printf("Number of comparisons made: %d\n", comparisons);
    return 0;
}