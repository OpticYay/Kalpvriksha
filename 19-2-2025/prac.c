#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void create(node** head, int num)
{
    node* new = malloc(sizeof(node));
    new->next = (*head);
    new->data = num;
    (*head) = new;
}
node* merge(node* left,node* right)
{
    node* result=NULL;
    if(left==NULL)
    {
        return right;
    }
    else if(right==NULL)
    {
        return left;
    }
    if(left!=NULL&&right!=NULL)
    {
        if(left->data<right->data)
        {
            result=left;
            result->next=merge(left->next,right);
        }
        else
        {
            result=right;
            result->next=merge(left,right->next);
        }
    }
    return result;
}
void split(node* head,node** left,node** right)
{
    if(head==NULL||head->next==NULL)
    {
        *left=head;
        *right=NULL;
        return;
    }
    node* slow=head,*fast=head->next;
    fast=head->next;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    *left=head;
    *right=slow->next;
    slow->next=NULL;
}

node* mergeSort(node* head)
{   
    if(head==NULL||head->next==NULL)
        return head;
    node* left=NULL,*right=NULL;
    split(head,&left,&right);
    left=mergeSort(left);
    right=mergeSort(right);
    return merge(left,right);
}
void display(node* head)
{
    while (head)
    {
        printf("%d ", head->data);
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
    // removeDuplicates(head);
    display(head);
    freeList(head);
    return 0;
}