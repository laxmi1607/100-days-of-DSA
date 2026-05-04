#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
        return;
    }
    printf("Popped Element: %d\n", stack[top]);
    top--;
}
void display()
{
    if (top == -1)
    {
        printf("Stack underflow");
        return;
    }
    printf("Stack elements:");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int n, choice, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &choice);

        if (choice == 1)
        {
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
    }

    return 0;
}