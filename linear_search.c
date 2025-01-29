#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[100];
    int order_no;
    struct node* next;
}node;
node* linearSearch(node* head,int key)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->order_no==key)
            return temp;
        temp=temp->next;
    }
    return NULL;
}
node* createNode(char name[],int order_no)
{
    node* new=(node* )malloc(sizeof(node));
    strcpy(new->name,name);
    new->order_no=order_no;
    return new;
}
node* insert(node* head,char name[],int order_no)
{
    if(head==NULL)
    {
        head=createNode(name,order_no);
        head->next=NULL;
        return head;
    }
    node* temp=createNode(name,order_no);
    temp->next=head;
    head=temp;
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        printf("%s %d\n",head->name,head->order_no);
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    int n=0;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter name and order_no.\n");
    int order_no=0;
    char name[100]="";
    while(n!=0)
    {
        scanf("%s %d",name,&order_no);
        head=insert(head,name,order_no);
        n--;
    }
    int key;
    printf("Enter key.\n");
    scanf("%d",&key);
    node* result=linearSearch(head,key);
    if(result==NULL)
    {
        printf("Key not found.\n");
    }
    else
    {
        printf("%s %d",result->name,result->order_no);
    }
    return 0;
}