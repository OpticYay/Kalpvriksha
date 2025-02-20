#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node;
void create(node** head,int a)
{
    node* new=malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Allocation failed\n");
        return;
    }
    new->next=(*head);
    *head=new;
    new->value=a;
}
int main()
{
    node* head=NULL;
    int n=10;
    while(n--)
    {
        create(&head,n);
    }
    while(head)
    {
        printf("%d ",head->value);
        head=head->next;
    }
    return 0;
}