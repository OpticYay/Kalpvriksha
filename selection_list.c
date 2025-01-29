#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[100];
    int borrow;
    struct node *next;
} node;
node *selectionSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node* itr1=head;
    while(itr1->next!=NULL)
    {
        node* maxNode=itr1;
        node* itr2=itr1->next;
        while(itr2)
        {
            if(itr2->borrow>maxNode->borrow)
                maxNode=itr2;
            itr2=itr2->next;
        }
        if(maxNode!=itr1)
        {
            int temp = itr1->borrow;
            itr1->borrow = maxNode->borrow;
            maxNode->borrow = temp;
        }
        itr1=itr1->next;
    }
    return head;
}
node *createNode(char name[], int borrow)
{
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name, name);
    new->borrow = borrow;
    return new;
}
node *insert(node *head, char name[], int borrow)
{
    if (head == NULL)
    {
        head = createNode(name, borrow);
        head->next = NULL;
        return head;
    }
    node *temp = createNode(name, borrow);
    temp->next = head;
    head = temp;
    return head;
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%s %d\n", head->name, head->borrow);
        head = head->next;
    }
}
int main()
{
    node *head = NULL;
    int n = 0;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter name and borrowed.\n");
    int borrow = 0;
    char name[100] = "";
    while (n != 0)
    {
        scanf("%s %d", name, &borrow);
        head = insert(head, name, borrow);
        n--;
    }
    head = selectionSort(head);
    printf("sorted list:\n");
    display(head);
    return 0;
}