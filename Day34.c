#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

void push(Node **top, int val) {
    Node *n = newNode(val);
    n->next = *top;
    *top = n;
}

int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack underflow — invalid expression\n");
        exit(1);
    }
    Node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluatePostfix(char *expr) {
    Node *top = NULL;
    char *token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&top, atoi(token));
        } else {
            int b = pop(&top);
            int a = pop(&top);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) { printf("Division by zero\n"); exit(1); }
                    result = a / b;
                    break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }
            push(&top, result);
        }
        token = strtok(NULL, " ");
    }

    int finalResult = pop(&top);

    while (top != NULL) {
        Node *temp = top;
        top = top->next;
        free(temp);
    }

    return finalResult;
}

int main() {
    char expr[200];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    printf("%d\n", evaluatePostfix(expr));
    return 0;
}