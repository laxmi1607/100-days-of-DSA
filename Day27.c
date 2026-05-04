#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) { fprintf(stderr, "Memory allocation failed\n"); exit(1); }
    node->data = val;
    node->next = NULL;
    return node;
}

void append(Node** head, int val) {
    Node* newNode = createNode(val);
    if (!*head) { *head = newNode; return; }
    Node* cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
}

void freeList(Node* head) {
    while (head) { Node* tmp = head; head = head->next; free(tmp); }
}

int listLength(Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}
Node* advance(Node* node, int steps) {
    while (steps--) node = node->next;
    return node;
}

Node* findIntersection(Node* l1, Node* l2) {
    int len1 = listLength(l1);
    int len2 = listLength(l2);

    if (len1 > len2) l1 = advance(l1, len1 - len2);
    else             l2 = advance(l2, len2 - len1);

    while (l1 && l2) {
        if (l1->data == l2->data) return l1;  
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}

int main(void) {
    int n, m, val;
    Node *list1 = NULL, *list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &val); append(&list1, val); }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) { scanf("%d", &val); append(&list2, val); }

    Node* result = findIntersection(list1, list2);
    if (result) printf("%d\n", result->data);
    else        printf("No Intersection\n");

    freeList(list1);
    freeList(list2);
    return 0;
}