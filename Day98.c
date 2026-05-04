// Merge Overlapping Intervals
#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
    int n, i;

    // Input number of intervals
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    // Input intervals
    printf("Enter intervals (start end):\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals by start time
    qsort(arr, n, sizeof(Interval), compare);

    // Step 2: Merge intervals
    Interval result[n];
    int index = 0;

    // First interval goes directly
    result[index] = arr[0];

    for(i = 1; i < n; i++) {

        // If overlapping, merge
        if(arr[i].start <= result[index].end) {

            // Update end if needed
            if(arr[i].end > result[index].end) {
                result[index].end = arr[i].end;
            }

        } else {
            // No overlap, move to next interval
            index++;
            result[index] = arr[i];
        }
    }

    // Output merged intervals
    printf("Merged Intervals:\n");
    for(i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }

    return 0;
}