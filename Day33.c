#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '*' || op == '/')  return 2;
    if (op == '+' || op == '-')  return 1;
    return 0;  // for '(' 
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(char *expr) {
    int n = strlen(expr);

    for (int i = 0; i < n; i++) {
        char c = expr[i];

        if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                printf("%c", pop());
            }
            pop(); 
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
        else {
            printf("%c", c);
        }
    }

    while (!isEmpty()) {
        printf("%c", pop());
    }

    printf("\n");
}

int main() {
    char expr[100];
    scanf("%s", expr);
    infixToPostfix(expr);
    return 0;
}