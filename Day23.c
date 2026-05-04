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

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);  // temporary dummy node
    struct Node* curr = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    // Attach remaining nodes
    if (l1 != NULL) curr->next = l1;
    if (l2 != NULL) curr->next = l2;

    return dummy->next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        if (head->next == NULL)
            printf("%d", head->data);
        else
            printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m, val;

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&list1, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insert(&list2, val);
    }

    struct Node* merged = mergeSorted(list1, list2);

    printList(merged);

    return 0;
}