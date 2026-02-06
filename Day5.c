/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/
#include <stdio.h>
#define MAX_SIZE 100
void mergeLogs(int log1[], int size1, int log2[], int size2, int mergedLog[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            mergedLog[k++] = log1[i++];
        } else {
            mergedLog[k++] = log2[j++];
        }
    }

    while (i < size1) {
        mergedLog[k++] = log1[i++];
    }

    while (j < size2) {
        mergedLog[k++] = log2[j++];
    }
}
int main() {
    int size1, size2;
    int log1[MAX_SIZE], log2[MAX_SIZE], mergedLog[2 * MAX_SIZE];    
    printf("Enter number of entries in log 1: ");
    scanf("%d", &size1);
    printf("Enter %d sorted arrival times for log 1:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &log1[i]);
    }
    printf("Enter number of entries in log 2: ");
    scanf("%d", &size2);   
     printf("Enter %d sorted arrival times for log 2:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &log2[i]);
    }
    mergeLogs(log1, size1, log2, size2, mergedLog);    
    printf("Merged chronological log:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedLog[i]);
    }
    printf("\n");
    return 0;
}