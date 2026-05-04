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

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->next == NULL)
            printf("%d", curr->data);
        else
            printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(&head, val);
    }

    printList(head);

    return 0;
}