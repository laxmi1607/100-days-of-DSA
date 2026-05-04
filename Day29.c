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
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    k = k % n;
    if (k == 0) {
        struct Node* curr = head;
        while (curr != NULL) {
            if (curr != head) printf(" ");
            printf("%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
        return 0;
    }

    int stepsToNewTail = n - k - 1;
    struct Node* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;   
    tail->next = head;      
     head = newHead;         

    struct Node* curr = head;
    while (curr != NULL) {
        if (curr != head) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}