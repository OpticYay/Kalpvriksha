#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
typedef struct hash
{
    int num;
    int index;
    struct hash *next;
} hash;

hash *map[SIZE] = {NULL};
int target;

int hashFunc(int key)
{
    return abs(key % SIZE);
}
void insert(int key, int pos)
{
    int index = hashFunc(key);
    if (map[index] == NULL)
    {
        map[index] = malloc(sizeof(hash));
        map[index]->num = key;
        map[index]->index = pos;
        map[index]->next = NULL;
        return;
    }
    hash *new = malloc(sizeof(hash));
    new->index = pos;
    new->num = key;
    new->next = map[index];
    map[index] = new;
}
int search(int key, int i)
{
    int index = hashFunc(key);
    if (map[index] == NULL)
        return 0;
    hash *temp = map[index];
    while (temp)
    {
        if (temp->num == (key))
        {
            printf("[%d,%d]\n", temp->index, i);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main()
{
    int n = 0, num;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter target:");
    int target;
    scanf("%d", &target);
    printf("enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        int req = target - num;
        if (search(req, i))
        {
            return 0;
        }
        else
        {
            insert(num, i);
        }
    }
    return 0;
}