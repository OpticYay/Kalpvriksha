#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    long long number;  
    struct node *next;
} node;

void add(node **head, char name[], long long number) {
    node *new = malloc(sizeof(node));
    new->next = *head;
    strcpy(new->name, name);
    new->number = number;
    *head = new;
    printf("Success\n");
}

void search(node *head, char name[]) {
    while (head != NULL) {
        if (strcmp(name, head->name) == 0) {
            printf("%lld\n", head->number);  
            return;
        }
        head = head->next;
    }
    printf("Not Found\n");
}
void delete(node **head, char name[]) {
    if (*head == NULL) {
        printf("Not Found\n");
        return;
    }

    if (strcmp(name, (*head)->name) == 0) {
        node *del = *head;
        *head = (*head)->next;
        free(del);
        printf("Success\n");
        return;
    }

    node *temp = *head;
    while (temp->next != NULL) {
        if (strcmp(name, temp->next->name) == 0) {
            node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            printf("Success\n");
            return;
        }
        temp = temp->next;
    }

    printf("Not Found\n");
}

int main() {
    node *phonebook = NULL;
    int n;
    scanf("%d", &n);
    getchar(); 

    while (n--) {
        char operation[10];
        char name[100];
        long long number;

        if (scanf("%s", operation) == 1) {
            if (strcmp(operation, "add") == 0) {
                scanf(" (\"%[^\"]\",%lld)", name, &number);
                add(&phonebook, name, number);
            } else if (strcmp(operation, "search") == 0) {
                scanf(" (\"%[^\"]\")", name);
                search(phonebook, name);
            } else if (strcmp(operation, "delete") == 0) {
                scanf(" (\"%[^\"]\")", name);
                delete(&phonebook, name);
            }
        }
    }

    return 0;
}
