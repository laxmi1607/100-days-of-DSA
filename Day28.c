#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Points back to head (circular)
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Always points back to head (circular)
        }
    }

    // Traverse and print
    if (head != NULL) {
        struct Node* curr = head;
        do {
            if (curr != head) printf(" ");
            printf("%d", curr->data);
            curr = curr->next;
        } while (curr != head);
        printf("\n");
    }

    // Free memory
    if (head != NULL) {
        struct Node* curr = head;
        do {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        } while (curr != head);
    }

    return 0;
}