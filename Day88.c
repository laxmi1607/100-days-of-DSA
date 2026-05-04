#include <stdio.h>

// Bubble Sort to sort stall positions
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Check if cows can be placed with minimum distance = dist
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // First cow in first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int n, k;

    // Input number of stalls and cows
    scanf("%d %d", &n, &k);

    int stalls[n];

    // Input stall positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    sort(stalls, n);

    // Binary Search on answer
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            answer = mid;     // Possible, try bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;   // Not possible, reduce distance
        }
    }

    // Output result
    printf("%d\n", answer);

    return 0;
}