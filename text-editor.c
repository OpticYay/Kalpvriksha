#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char *str;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, const char *str) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->str = strdup(str);
    newNode->next = *top;
    *top = newNode;
}

void pop(StackNode **top, char *str) {
    if (*top == NULL) return;
    StackNode *temp = *top;
    strcpy(str, temp->str);
    *top = temp->next;
    free(temp->str);
    free(temp);
}

void append(char *s, const char *input, StackNode **history) {
    push(history, s);
    strcat(s, input);
}

void delete(char *s, int k, StackNode **history) {
    push(history, s);
    s[strlen(s) - k] = '\0';
}

void undo(StackNode **history, char *s) {
    pop(history, s);
}

int main() {
    StackNode *history = NULL;
    char string[1000001] = "";  
    int q;
    scanf("%d", &q);

    while (q--) {
        int operation, k;
        char input[1000001];

        scanf("%d", &operation);

        switch (operation) {
            case 1:  
                scanf("%s", input);
                append(string, input, &history);
                break;

            case 2:  
                scanf("%d", &k);
                delete(string, k, &history);
                break;

            case 3:  
                scanf("%d", &k);
                printf("%c\n", string[k - 1]);
                break;

            case 4:  
                undo(&history, string);
                break;
        }
    }

    while (history) {  
        StackNode *temp = history;
        history = history->next;
        free(temp->str);
        free(temp);
    }

    return 0;
}