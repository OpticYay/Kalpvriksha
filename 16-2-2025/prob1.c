#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int page;
    struct node* next;
}node;

typedef enum operation
{
    BOOKMARK=1,
    DELETE,
    LIST
}op;

void create(node** head,int page)
{
    node* new=malloc(sizeof(node));
    new->page=page;
    new->next=*head;
    *head=new;
}

void delete(node** head)
{
    node* del=*head;
    if(del==NULL)
    {
        printf("NO BOOKMARKS\n");
        return;
    }
    *head=del->next;
    free(del);
}

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
    if (left->page <= right->page)
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
int main()
{
    node* head=NULL;
    printf("Enter Number of operations:");
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        op option;
        char input[10];
        int page;
        scanf("%s",input);
        if(strcmp(input,"BOOKMARK")==0)
            option=BOOKMARK;
        else if(strcmp(input,"DELETE"))
            option=DELETE;
        else
            option=LIST;
        switch (option)
        {
            case BOOKMARK:
            scanf("%d",&page);
            create(&head,page);
            break;
            case DELETE:
            delete(&head);
            break;
            case LIST:
               
        }  
    }
    return 0;
}