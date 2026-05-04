#include <stdio.h>

#define MAX 1000

// Structure to store prefix sum and first index
struct Hash {
    int sum;
    int index;
};

int main() {
    int n;

    // Input size of array
    scanf("%d", &n);

    int arr[MAX];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Hash hash[MAX];
    int hashCount = 0;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum becomes 0, subarray from 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        int found = 0;

        // Check if same prefix sum seen before
        for (int j = 0; j < hashCount; j++) {
            if (hash[j].sum == sum) {
                int len = i - hash[j].index;

                if (len > maxLen) {
                    maxLen = len;
                }

                found = 1;
                break;
            }
        }

        // Store first occurrence of prefix sum
        if (!found) {
            hash[hashCount].sum = sum;
            hash[hashCount].index = i;
            hashCount++;
        }
    }

    // Output result
    printf("%d\n", maxLen);

    return 0;
}