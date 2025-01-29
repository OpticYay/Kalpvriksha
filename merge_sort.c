#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[100];
    int marks;
    struct node *next;
} node;
void splitList(node *head, node **left, node **right)
{
    if (head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return;
    }
    node *slow = head, *fast = head->next;
    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}
node *mergeSortedLists(node *left, node *right)
{
    if (!left)
        return right;
    if (!right)
        return left;
    node *result = NULL;
    if (left->marks <= right->marks)
    {
        result = left;
        result->next = mergeSortedLists(left->next, right);
    }
    else
    {
        result = right;
        result->next = mergeSortedLists(left, right->next);
    }
    return result;
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *left, *right;
    splitList(head, &left, &right);
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeSortedLists(left, right);
}
node *createNode(char name[], int marks)
{
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name, name);
    new->marks = marks;
    return new;
}
node *insert(node *head, char name[], int marks)
{
    if (head == NULL)
    {
        head = createNode(name, marks);
        head->next = NULL;
        return head;
    }
    node *temp = createNode(name, marks);
    temp->next = head;
    head = temp;
    return head;
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%s %d\n", head->name, head->marks);
        head = head->next;
    }
}
int main()
{
    node *head = NULL;
    int n = 0;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter name and marks of products.\n");
    int marks = 0;
    char name[100] = "";
    while (n != 0)
    {
        scanf("%s %d", name, &marks);
        head = insert(head, name, marks);
        n--;
    }
    head = mergeSort(head);
    printf("sorted list:\n");
    display(head);
    return 0;
}