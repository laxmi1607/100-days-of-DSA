#include <stdio.h>

int main() {
    int n, x;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target
    scanf("%d", &x);

    // Lower Bound
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
            high = mid;
        else
            low = mid + 1;
    }
    int lowerBound = low;

    // Upper Bound
    low = 0;
    high = n;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }
    int upperBound = low;

    // Output
    printf("%d %d\n", lowerBound, upperBound);

    return 0;
}