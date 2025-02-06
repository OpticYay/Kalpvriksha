#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    char url[100];
    struct stack *next;
} node;
void push(node **head, char url[])
{
    node *new = malloc(sizeof(node));
    new->next = *head;
    strcpy(new->url, url);
    *head = new;
}
void pop(node **head)
{
    if (head == NULL)
        return;
    node *del = *head;
    *head = (*head)->next;
    printf("Popped website: %s\n", del->url);
    free(del);
}
void display(node *head)
{
    while (head)
    {
        printf("%s\n", (head)->url);
        head = head->next;
    }
}
void update(node *head, char oldURL[], char newURL[])
{
    while (head)
    {
        if (strcmp(head->url, oldURL) == 0)
        {
            strcpy(head->url, newURL);
            printf("success\n");
            return;
        }
        head = head->next;
    }
    printf("URL not found.\n");
}
void emptyStack(node **head)
{
    while (*head)
    {
        node *del = *head;
        *head = (*head)->next;
        free(del);
    }
}
void peek(node *head)
{
    if (head == NULL)
    {
        printf("No history\n");
        return;
    }
    printf("Last visited website: %s\n", head->url);
}
int main()
{
    node *head = NULL;
    while (1)
    {
        int ch;
        char URL[100], URLold[100];
        printf("1.Push site.\n2.pop site.\n3.update site.\n4.display\n5.clear history.\n6.peek.\n7.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter website to push: ");
            scanf("%s", URL);
            push(&head, URL);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            printf("Enter website to Update: ");
            scanf("%s", URLold);
            printf("Enter updated website: ");
            scanf("%s", URL);
            update(head, URLold, URL);
            break;
        case 4:
            display(head);
            break;
        case 5:
            emptyStack(&head);
            printf("History cleared.\n");
            break;
        case 6:
            peek(head);
            break;
        case 7:
            emptyStack(&head);
            return 0;
        default:
            printf("Invalid input.\n");
        }
    }
}