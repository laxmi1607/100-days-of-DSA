#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create new node
struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure for level order building
struct Queue
{
    struct Node **arr;
    int front, rear, size;
};

// Create queue
struct Queue *createQueue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->arr = (struct Node **)malloc(size * sizeof(struct Node *));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue *q, struct Node *node)
{
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node *dequeue(struct Queue *q)
{
    return q->arr[q->front++];
}

// Check if empty
int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

// Build tree from level order
struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node *root = newNode(arr[0]);
    struct Queue *q = createQueue(n);
    enqueue(q, root);

    int i = 1;

    while (!isEmpty(q) && i < n)
    {
        struct Node *curr = dequeue(q);

        // Left child
        if (arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Function to find height
int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

// Main function
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}