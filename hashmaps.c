#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct hash
{
    int value;
    int key;
    struct hash *next;
} hash;
int hashfunction(int key)
{
    return key % MAX;
}
void insert(hash **map, int key, int value)
{
    int index = hashfunction(key);
    if (map[index] == NULL)
    {
        map[index] = malloc(sizeof(hash));
        map[index]->next = NULL;
        map[index]->value = value;
        map[index]->key = key;
        return;
    }
    hash *new = malloc(sizeof(hash));
    new->next = map[index];
    map[index] = new;
    new->value = value;
}
void search(hash **map, int key)
{
    int index = hashfunction(key);
    hash *temp = map[index];
    while (temp)
    {
        if (temp->key == key)
        {
            printf("Value: %d \n", temp->value);
            return;
        }
    }
    printf("NOT FOUND!\n");
}
void delete(hash **map, int key)
{
    int index = hashfunction(key);
    hash *temp = map[index], *prev = NULL, *del;
    while (temp)
    {
        if (key == temp->key)
        {
            if (prev == NULL)
            {
                del = temp;
                map[index] = temp->next;
                printf("key %d deleted\n", del->key);
                free(del);
                return;
            }
            prev = temp->next;
            printf("key %d deleted\n", temp->key);
            free(temp);
            return;
        }
    }
}
void freemap(hash** map)
{
    for(int i=0;i<MAX;i++)
    {
        hash* temp=map[i];
        while(temp)
        {
            hash* del=temp;
            temp=temp->next;
            free(del);
        }
    }
}
void display(hash **map)
{

    for (int i = 0; i < MAX; i++)
    {

        hash *temp = map[i];
        if (temp == NULL)
        {
            continue;
        }
        printf("map %d: ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    hash *map[MAX];
    for (int i = 0; i < MAX; i++)
    {
        map[i] = NULL;
    }
    int choice, key, value;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert (Put)\n");
        printf("2. Search (Get)\n");
        printf("3. Delete (Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(map, key, value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(map, key);
            break;
        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete (map, key);
            break;
        case 4:
            display(map);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    freemap(map);
    return 0;
}
