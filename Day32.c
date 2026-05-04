#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n, m, val;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    for (int i = top; i >= 0; i--) {
        if (i != top) printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");

    return 0;
}