#include <stdio.h>
#include <string.h>
 
#define MAX_ACTIONS 1000
#define MAX_LOG_LENGTH 100
 
int readLogs(char logs[MAX_ACTIONS][MAX_LOG_LENGTH]) {
    int n = 0;
    while (scanf("%s", logs[n]) == 1) {
        n++; 
        if (getchar() == '\n') break;  
    }
    return n;
}
 
void countFrequencies(char logs[MAX_ACTIONS][MAX_LOG_LENGTH], int count[MAX_ACTIONS], int n) {
    for (int i = 0; i < n; i++) {
        if (count[i] == -1) continue; 
        count[i] = 1; 
        for (int j = i + 1; j < n; j++) {
            if (strcmp(logs[i], logs[j]) == 0) {
                count[i]++;
                count[j] = -1; 
            }
        }
    }
}
 
 
void printActions(char logs[MAX_ACTIONS][MAX_LOG_LENGTH], int count[MAX_ACTIONS], int n, int threshold) {
    int printed = 0;
    printf("[");
    int first = 1;  
 
    for (int i = 0; i < n; i++) {
        if (count[i] > 0 && count[i] < threshold) {
            if (!first) {
                printf(", ");
            }
            printf("\"%s\"", logs[i]);
            first = 0;  
            printed = 1; 
        }
    }
 
  
    if (!printed) {
        printf("]");
    } else {
        printf("]\n");
    }
}
 
int main() {
    char logs[MAX_ACTIONS][MAX_LOG_LENGTH];
    int count[MAX_ACTIONS] = {0};  
    int threshold;
 
    // Read log entries and get the number of entries
    int n = readLogs(logs);
 
   
    scanf("%d", &threshold);
 
   
    countFrequencies(logs, count, n);
 
 
    printActions(logs, count, n, threshold);
 
    return 0;
}