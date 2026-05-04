#include <stdio.h>

int main() {
    long long n;

    // Input number
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    // Binary Search for integer square root
    while (low <= high) {
        long long mid = (low + high) / 2;

        // Avoid overflow using division
        if (mid <= n / mid) {
            ans = mid;       // mid is possible answer
            low = mid + 1;   // Search larger value
        } else {
            high = mid - 1;  // Search smaller value
        }
    }

    // Output result
    printf("%lld\n", ans);

    return 0;
}