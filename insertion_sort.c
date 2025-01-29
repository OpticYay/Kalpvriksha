#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[100];
    int performance;
    struct node* next;
}node;
node* insertionSort(node* head)
{
    if (head==NULL||head->next==NULL)
        return head;
    node* sorted=NULL;
    node* current=head;
    while(current)
    {
        node* next=current->next;
        if(sorted==NULL|| sorted->performance>=current->performance)
        {
            current->next=sorted;
            sorted=current;
        }
        else
        {
            node* temp=sorted;
            while(temp->next&& temp->next->performance<current->performance)
                temp=temp->next;
            current->next=temp->next;
            temp->next=current;
        }
        current=next;
    }
    return sorted;
}
node* createNode(char name[],int performance)
{
    node* new=(node* )malloc(sizeof(node));
    strcpy(new->name,name);
    new->performance=performance;
    return new;
}
node* insert(node* head,char name[],int performance)
{
    if(head==NULL)
    {
        head=createNode(name,performance);
        head->next=NULL;
        return head;
    }
    node* temp=createNode(name,performance);
    temp->next=head;
    head=temp;
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        printf("%s %d\n",head->name,head->performance);
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    int n=0;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter name and performance.\n");
    int performance=0;
    char name[100]="";
    while(n!=0)
    {
        scanf("%s %d",name,&performance);
        head=insert(head,name,performance);
        n--;
    }
    head=insertionSort(head);
(head);
    printf("sorted list:\n");
    display(head);
    return 0;
}