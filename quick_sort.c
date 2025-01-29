#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[100];
    int age;
    struct node *next;
} node;
node* partition(node* head,node* end,node** newHead,node** newEnd)
{
    node* pivot=end;
    node* prev=NULL,*cur=head,*tail=pivot;
    while(cur!=pivot)
    {
        if(cur->age< pivot->age)
        {
            if(*newHead==NULL)
                *newHead=cur;
            prev=cur;
            cur=cur->next;
        }
        else
        {
            if(prev!=NULL)
                prev->next=cur->next;
            node* temp=cur->next;
            cur->next=NULL;
            tail->next=NULL;
            tail=cur;
            cur=temp;
        }
    }
    if(*newHead==NULL)
        *newHead=pivot;
    *newEnd=tail;
    return pivot;
}
node *createNode(char name[], int age)
{
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name, name);
    new->age =age;
    return new;
}
node* quickSort(node* head,node* end)
{
    if(head==NULL||head->next!=NULL)
        return head;
    node* newHead=NULL,*newEnd=NULL;
    node* pivot=partition(head,end,&newHead,&newEnd);
    if(newHead!=pivot)
    {
        node* temp=newHead;
        while(temp->next!=pivot)
            temp=temp->next;
        temp->next=NULL;
        newHead=quickSort(newHead,temp);
        temp=newHead;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=pivot;
    }
    pivot->next=quickSort(pivot->next,newEnd);
    return newHead;
}
node* insert(node *head, char name[], int age)
{
    if (head == NULL)
    {
        head = createNode(name, age);
        head->next = NULL;
        return head;
    }
    node *temp = createNode(name, age);
    temp->next = head;
    head = temp;
    return head;
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%s %d\n", head->name, head->age);
        head = head->next;
    }
}
int main()
{
    node *head = NULL,*end=NULL;
    int n = 0;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter name and age of products.\n");
    int age = 0;
    char name[100] = "";
    while (n != 0)
    {
        scanf("%s %d", name, &age);
        head = insert(head, name, age);
        n--;
    }
    end=head;
    while(end->next!=NULL)
        end=end->next;
    head = quickSort(head,end);
    printf("sorted list:\n");
    display(head);
    return 0;
}