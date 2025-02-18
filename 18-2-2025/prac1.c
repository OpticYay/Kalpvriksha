#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct item
{
    char item_name[20];
    int stock;
    struct item *next;
} item;
void insert(item **head, char *name, int qty)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(item));
        (*head)->stock = qty;
        strcpy((*head)->item_name, name);
        return;
    }
    item *temp = *head;
    while (temp)
    {
        if (strcmp(temp->item_name, name) == 0)
        {
            temp->stock += qty;
            return;
        }
        temp = temp->next;
    }
    item *new = malloc(sizeof(item));
    new->stock = qty;
    strcpy(new->item_name, name);
    new->next = *head;
    *head = new;
}
void update(item *head, char *name, int qty)
{
    while (head)
    {
        if (strcmp(head->item_name, name) == 0)
        {
            head->stock = qty;
            return;
        }
        head = head->next;
    }
}
void search(item *head, char *name)
{
    while (head)
    {
        if (strcmp(head->item_name, name) == 0)
        {
            printf("%s:%d", head->item_name, head->stock);
            return;
        }
        head = head->next;
    }
    printf("Item not found\n");
}
void display(item *head)
{
    while (head)
    {
        printf("%s->%d\n", head->item_name, head->stock);
        head = head->next;
    }
}
int main()
{
    item *head = NULL;
    int n;
    printf("Enter number of operations:");
    scanf("%d", &n);
    while (n--)
    {
        char operation[20] = "";
        char item_name[20];
        int qty;
        scanf("%s", operation);
        switch (operation[0])
        {
        case 'A':
            scanf("%s %d", item_name, &qty);
            insert(&head, item_name, qty);
            break;
        case 'U':
            scanf("%s %d", item_name, &qty);
            update(head, item_name, qty);
            break;
        case 'Q':
            search(head, item_name);
            break;
        default:
            printf("incorrect input\n");
        }
    }
    return 0;
}