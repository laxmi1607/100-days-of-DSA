#include <stdio.h>
#include <string.h>

#define MAX_VOTES 1000
#define MAX_NAME 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX_VOTES][MAX_NAME];
    char unique[MAX_VOTES][MAX_NAME];
    int count[MAX_VOTES] = {0};

    int uniqueCount = 0;

    // Read votes
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);

        int found = -1;

        // Check if candidate already exists
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        // If found, increase vote count
        if (found != -1) {
            count[found]++;
        }
        // New candidate
        else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    char winner[MAX_NAME];
    strcpy(winner, unique[0]);

    for (int i = 1; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        // Tie → lexicographically smaller wins
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}