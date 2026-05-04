#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isComplete(struct Node* root, int index, int total) {
    if (root == NULL)
        return 1;

    if (index >= total)
        return 0;

    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
        return (root->data <= root->left->data);

    // Both children
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) && isMinHeap(root->right);

    return 0;
}

// Main check
int checkMinHeap(struct Node* root) {
    int total = countNodes(root);

    if (isComplete(root, 0, total) && isMinHeap(root))
        return 1;
    return 0;
}

int main() {
    // Example: 1 3 5 7 9 8 10
    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(7);
    root->left->right = newNode(9);
    root->right->left = newNode(8);
    root->right->right = newNode(10);

    if (checkMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}