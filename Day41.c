#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front; /* dequeue end */
    Node *rear;  /* enqueue end */
    int size;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    { /* queue was empty */
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;

    Node *temp = q->front;
    int removed = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) /* queue became empty */
        q->rear = NULL;

    free(temp);
    q->size--;
    return removed;
}

void freeQueue(Queue *q)
{
    while (!isEmpty(q))
        dequeue(q);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    char op[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "ENQUEUE") == 0)
        {
            int val;
            scanf("%d", &val);
            enqueue(&q, val);
        }
        else if (strcmp(op, "DEQUEUE") == 0)
        {
            printf("%d\n", dequeue(&q));
        }
        else
        {
            printf("Unknown operation: %s\n", op);
        }
    }

    freeQueue(&q);
    return 0;
}