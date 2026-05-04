#include <stdio.h>

// Find maximum board length
int maxElement(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Find total sum of board lengths
int sumArray(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

// Check if painting is possible within maxTime
int isPossible(int boards[], int n, int painters, int maxTime) {
    int painterCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {

        // If one board exceeds maxTime
        if (boards[i] > maxTime) {
            return 0;
        }

        // Assign to next painter
        if (currentSum + boards[i] > maxTime) {
            painterCount++;
            currentSum = boards[i];

            if (painterCount > painters) {
                return 0;
            }
        } else {
            currentSum += boards[i];
        }
    }

    return 1;
}

int main() {
    int n, k;

    // Input number of boards and painters
    scanf("%d %d", &n, &k);

    int boards[n];

    // Input board lengths
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    // Binary Search on answer
    int low = maxElement(boards, n);
    int high = sumArray(boards, n);
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            answer = mid;      // Possible, try smaller time
            high = mid - 1;
        } else {
            low = mid + 1;     // Not possible, increase time
        }
    }

    // Output result
    printf("%d\n", answer);

    return 0;
}