#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int count;
    char key;
    struct Node* next;
} node;

node* create(char ch) {
    node* new = malloc(sizeof(node));
    new->key = ch;
    new->count = 1;
    new->next = NULL;
    return new;
}

void insert(node** head, char ch) {
    node* temp;
    if ((*head) == NULL) {
        (*head) = create(ch);
        return;
    }
    if ((*head)->key > ch) {
        temp = create(ch);
        temp->next = *head;
        (*head) = temp;
        return;
    }
    if ((*head)->key == ch) {
        (*head)->count++;
        return;
    }
    
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->key == ch) {
            temp->next->count++;
            return;
        }
        if (temp->next->key > ch) {
            node* new_node = create(ch);
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    temp->next = create(ch);
}

void freeList(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[100000];
    node* map = NULL;
    
    scanf("%[^\n]", input);
    
    for (int i = 0; input[i] != '\0'; i++) {
        insert(&map, input[i]);
    }

    printf("{");
    node* current = map;
    while (current != NULL) {
        printf("%c:%d", current->key, current->count);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("}\n");

    freeList(map);
    
    return 0;
}