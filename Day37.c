#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size - 1;

    // Shift elements right to make room for x
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq[0]);

    // Shift all elements left
    for (int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];
    size--;
}

void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {
            delete();
        } else {
            peek();
        }
    }
    return 0;
}