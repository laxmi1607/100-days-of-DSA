#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(struct Node **rear, int data) {
    struct Node *node = createNode(data);
    if (*rear == NULL) {
        node->next = node;   // points to itself
        *rear = node;
    } else {
        node->next = (*rear)->next;  // new node -> front
        (*rear)->next = node;        // old rear  -> new node
        *rear = node;                // rear moves to new node
    }
}

void rotate(struct Node **rear) {
    *rear = (*rear)->next;
}

void display(struct Node *rear, int n) {
    struct Node *curr = rear->next;  // start at front
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *rear = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&rear, x);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        rotate(&rear);
    }

    display(rear, n);
    return 0;
}