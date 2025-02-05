#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node* next;
} node;

void split(node* head, node** left, node** right)
{
    if (head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return;
    }
    node* slow = head, * fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

node* mergeSortedLists(node* left, node* right)
{
    if (!left)
        return right;
    if (!right)
        return left;
    node* result = NULL;
    if (left->num <= right->num)
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

node* mergeSort(node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node* left, * right;
    split(head, &left, &right);
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeSortedLists(left, right);
}

void create(node** head, int num)
{
    node* new = malloc(sizeof(node));
    new->next = (*head);
    new->num = num;
    (*head) = new;
}

void display(node* head)
{
    while (head)
    {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

void freeList(node* head)
{
    node* temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void removeDuplicates(node* head)
{
    if (head == NULL || head->next == NULL)
        return;

    node* temp1 = head;
    node* temp2;
    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL && temp1->num == temp2->num)
        {
            node* del = temp2;
            temp2 = temp2->next;
            free(del); 
        }
        temp1->next = temp2;
        temp1 = temp1->next; 
    }
}

int main()
{
    int n;
    node* head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        int ele;
        scanf("%d", &ele);
        create(&head, ele);
    }
    head = mergeSort(head);
    printf("Sorted list: ");
    removeDuplicates(head);
    display(head);
    freeList(head);
    return 0;
}