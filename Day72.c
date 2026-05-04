#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];

    // Input string
    scanf("%s", s);

    // Frequency array for 26 lowercase letters
    int visited[26] = {0};

    // Traverse string
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If already seen, first repeated character found
        if (visited[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    // No repeated character
    printf("-1\n");

    return 0;
}