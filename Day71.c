#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;

    // Input table size
    scanf("%d", &m);

    int hashTable[m];

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    // Number of operations
    scanf("%d", &q);

    while (q--) {
        char operation[10];
        int key;

        scanf("%s %d", operation, &key);

        // INSERT operation
        if (strcmp(operation, "INSERT") == 0) {
            int inserted = 0;

            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;

                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    inserted = 1;
                    break;
                }
            }

            // Optional: if table full, insertion ignored
        }

        // SEARCH operation
        else if (strcmp(operation, "SEARCH") == 0) {
            int found = 0;

            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;

                if (hashTable[index] == EMPTY) {
                    break; // Key not present
                }

                if (hashTable[index] == key) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}