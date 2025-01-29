#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[100];
    int price;
    struct node* next;
}node;
node* bubblesort(node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    int swapped;
    node* itr=head,* end=NULL;
    do
    {
        swapped=0;
        itr=head;
        while(itr->next!=NULL)
        {
            if(itr->price<itr->next->price)
            {
                int temp=itr->price;
                itr->price=itr->next->price;
                itr->next->price=temp;
                swapped=1;
            }
            itr=itr->next;
        }
        end=itr;
    }while(swapped);
    return head;
}
node* createNode(char name[],int price)
{
    node* new=(node* )malloc(sizeof(node));
    strcpy(new->name,name);
    new->price=price;
    return new;
}
node* insert(node* head,char name[],int price)
{
    if(head==NULL)
    {
        head=createNode(name,price);
        head->next=NULL;
        return head;
    }
    node* temp=createNode(name,price);
    temp->next=head;
    head=temp;
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        printf("%s %d\n",head->name,head->price);
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    int n=0;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter name and price of products.\n");
    int price=0;
    char name[100]="";
    while(n!=0)
    {
        scanf("%s %d",name,&price);
        head=insert(head,name,price);
        n--;
    }
    head=bubblesort(head);
    printf("sorted list:\n");
    display(head);
    return 0;
}