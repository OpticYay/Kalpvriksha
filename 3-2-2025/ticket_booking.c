#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char movie[100];
    int screen;
    char seat[10];
    int amt;
    int status;
    struct node* next;
}node;
int isEmpty(node* tail)
{
    return tail==NULL?1:0;
}
node* newNode(node* head,char name[],int scr,char seat[],int amount)
{
    node* new=malloc(sizeof(node));
    new->amt=amount;
    strcpy(new->movie,name);
    strcpy(new->seat,seat);
    new->screen=scr;
    new->status=0;
    new->next=head;
}

void enqueue(node** head,node** tail,char name[],int scr,char seat[],int amount)
{
    node* new=newNode(*head,name,scr,seat,amount);
    if(*head==NULL)
    {
        *head=new;
        *tail=*head;
        return;
    }
    *head=new;
}
node* dequeue(node** head,node** tail)
{
    if(*head==NULL)
    {
        return NULL;
    }
    if(*head==*tail)
    {
        node* temp=*head;
        *head=NULL;
        *tail=NULL;
        return temp;
    }
    node* temp=*head;
    while(temp->next!=*tail)
    {
        temp=temp->next;
    }
    node* del=*tail;
    temp->next=NULL;
    *tail=temp;
    return del;
}

int main()
{
    node* bhead=NULL,* btail=NULL;
    node* ahead=NULL;
    while(1)
    {
        printf("1.BOOK\n2.Approve\n3.BOOK display\n4.Approve display\n5.EXIT\n");
        int choice=0;
        scanf("%d",&choice);
        char name[100],seat[10];
        int scr,amt;
        node* temp;
        switch (choice)
        {
        case 1:
            printf("Enter Movie Name:");
            scanf("%s%*c",name);
            printf("Enter screen number:");
            scanf("%d%*c",&scr);
            printf("Enter seat number:");
            scanf("%s%*c",seat);
            printf("Enter amount:");
            scanf("%d%*c",&amt);
            enqueue(&bhead,&btail,name,scr,seat,amt);
            break;
        case 2:
            temp=dequeue(&bhead,&btail);
            if(temp==NULL)
                break;
            temp->next=ahead;
            ahead=temp;
            temp->status=1;
            break;
        default:
        case 3:
            temp=bhead;
            while(temp!=NULL)
            {
                printf("Movie Name: %s ",temp->movie);
                printf("screen number: %d ",temp->screen);
                printf("seat number: %s ",temp->seat);
                printf("amount:%d ",temp->amt);
                printf("Status:Pending\n");
                temp=temp->next;
            }
            break;
        case 4:
            temp=ahead;
            while(temp!=NULL)
            {
                printf("Movie Name: %s ",temp->movie);
                printf("screen number: %d ",temp->screen);
                printf("seat number: %s ",temp->seat);
                printf("amount:%d ",temp->amt);
                printf("Status:Approved\n");
                temp=temp->next;
            }
            break;
            case 5:
                printf("Exiting....");
                return 0;
                break;
        }
    }
}