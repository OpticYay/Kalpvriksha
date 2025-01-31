#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* newNode(int value, node* next) {
    node* new = malloc(sizeof(node));
    new->next = next;
    new->value = value;
    return new;
}

void push(node** head, int value) {
    *head = newNode(value, *head);
}

int pop(node** head) {
    if (*head == NULL) {
        printf("Stack underflow.\n");
        return -1;
    }
    int value = (*head)->value;
    node* toDel = *head;
    *head = (*head)->next;
    free(toDel);
    return value;
}

int peek(node* head) {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return head->value;
}

int size(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int isEmpty(node* head) {
    return head == NULL;
}

void display(node* head) {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. SIZE\n5. DISPLAY\n6. isEmpty\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                value = pop(&head);
                if (value != -1)
                    printf("Deleted element: %d\n", value);
                break;
            case 3:
                value = peek(head);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                printf("Size of stack: %d\n", size(head));
                break;
            case 5:
                printf("Stack: ");
                display(head);
                break;
            case 6:
                printf(isEmpty(head) ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }
    }
}