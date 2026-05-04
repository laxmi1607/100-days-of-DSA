#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int queue[MAX];
int front = 0, rear = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    for (i = 0; i < n; i++)
    {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    for (i = 0; i < n; i++)
    {
        enqueue(pop());
    }

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}