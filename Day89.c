#include <stdio.h>

// Find maximum value in array
int maxElement(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Find sum of array
int sumArray(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

// Check if allocation is possible with maxPages limit
int isPossible(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If one book has more pages than maxPages
        if (books[i] > maxPages) {
            return 0;
        }

        // Assign to next student
        if (pagesSum + books[i] > maxPages) {
            studentCount++;
            pagesSum = books[i];

            if (studentCount > students) {
                return 0;
            }
        } else {
            pagesSum += books[i];
        }
    }

    return 1;
}

int main() {
    int n, m;

    // Input number of books and students
    scanf("%d %d", &n, &m);

    int books[n];

    // Input pages in books
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    // Binary Search on answer
    int low = maxElement(books, n);
    int high = sumArray(books, n);
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, n, m, mid)) {
            answer = mid;      // Possible, try smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;     // Not possible, increase limit
        }
    }

    // Output result
    printf("%d\n", answer);

    return 0;
}
