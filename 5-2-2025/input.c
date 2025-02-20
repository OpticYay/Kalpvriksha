#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[100];
    int number;
    struct node *next;
} node;
void create(node **head, char name[], int number)
{
    node *new = malloc(sizeof(node));
    new->next = *head;
    strcpy(new->name, name);
    new->number = number;
    *head = new;
    printf("success\n");
}
void search(node *head, char name[])
{
    if (head == NULL)
    {
        printf("not found");
        return;
    }
    while (head != NULL)
    {
        if (strcmp(name, head->name) == 0)
        {
            printf("%d\n", head->number);
            return;
        }
        head = head->next;
    }
    printf("Not Found\n");
}
void delete(node **head, char name[])
{
    if (*head == NULL)
    {
        printf("Not Found\n");
        return;
    }
    else if (strcmp(name, (*head)->name) == 0)
    {
        printf("success\n");
        node *del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            if (strcmp(name, temp->next->name) == 0)
            {
                printf("success\n");
                node *del = temp->next;
                temp->next = temp->next->next;
                free(del);
                return;
            }
            temp = temp->next;
        }
        printf("not found");
    }
}
int main()
{
    node *map = NULL;
    int n = 0;
    scanf("%d", &n);
    while (n != 0)
    {
        char operation[100];
        char name[100];
        int number;
        scanf(" %[^(](\"%[^\"]\",%d)", operation, name, &number);
        switch (operation[0])
        {
        case 'a':
            create(&map, name, number);
            break;
        case 's':
            search(map, name);
            break;
        case 'd':
            delete(&map,name);
            break;
        }
        n--;
    }
    while(map!=NULL)
    {
        printf("%s -> %d\n",map->name,map->number);
        map=map->next;
    }
    return 0;
}