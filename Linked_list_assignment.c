#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int item;
    struct node *next;
} Node;
Node *start = NULL;

void insertAtBeginning(int value)
{
    if (start == NULL)
    {
        start = malloc(sizeof(Node));
        start->next = NULL;
        start->item = value;
    }
    else
    {
        Node *temp = malloc(sizeof(Node));
        temp->next = start;
        start = temp;
        temp->item = value;
    }
}
void insertAtEnd(int value)
{

    if (start == NULL)
    {
        start = malloc(sizeof(Node));
        start->next = NULL;
        start->item = value;
    }
    else
    {
        Node *itr = start;
        while (itr->next != NULL)
            itr = itr->next;
        itr->next = malloc(sizeof(Node));
        itr = itr->next;
        itr->next = NULL;
        itr->item = value;
    }
}
void insertAtPosition(int position, int value)
{
    Node *itr = start;
    int pointer = 1;
    Node *temp = malloc(sizeof(Node));
    if (start == NULL && position == 1)
    {
        start = temp;
        temp->next = NULL;
        temp->item = value;
    }
    else if (position == 1)
    {
        temp->next = start;
        start = temp;
        temp->item = value;
    }
    else
    {
        while (itr != NULL && pointer != position - 1)
        {
            itr = itr->next;
            pointer++;
        }
        if (pointer != position - 1 || itr == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        else
        {
            temp->next = itr->next;
            itr->next = temp;
            temp->item = value;
        }
    }
}
void display()
{
    Node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void updateAtPosition(int position, int newValue)
{
    Node *itr = start;
    int pointer = 1;
    while (itr != NULL && pointer != position)
    {
        itr = itr->next;
        pointer++;
    }
    if (pointer != position || itr == NULL)
    {
        printf("Invalid position");
        return;
    }
    itr->item = newValue;
}
void deleteAtBegining()
{
    if (start == NULL)
    {
        printf("Empty List");
        return;
    }
    Node *temp = start;
    start = start->next;
    free(temp);
}
void deleteAtEnd()
{
    Node *itr = start;
    if (start == NULL)
    {
        printf("Empty List.\n");
    }
    else if (start->next == NULL)
    {
        free(start);
    }
    else
    {
        while (itr->next->next != NULL)
            itr = itr->next;
        free(itr->next);
        itr->next = NULL;
    }
}
void deleteAtPosition(int position)
{
    if (start == NULL)
    {
        printf("Empty List.\n");
        return;
    }
    else if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    else if (position == 1)
    {
        Node *temp = start;
        start = start->next;
        free(temp);
        return;
    }
    else
    {
        Node *itr = start;
        int pos = 1;

        while (itr->next != NULL && pos != position - 1)
        {
            itr = itr->next;
            pos++;
        }
        if (itr->next == NULL || pos != position - 1)
        {
            printf("Invalid position.\n");
            return;
        }
        Node *temp = itr->next;
        itr->next = itr->next->next;
        free(temp);
    }
}

int main()
{
    int operations;
    printf("Enter number of operations:");
    scanf("%d", &operations);
    do
    {
        int op, pos, value;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 3:
            scanf("%d", &pos);
            scanf("%d", &value);
            if (pos < 1)
            {
                printf("Invalid position");
                break;
            }
            insertAtPosition(pos, value);
            break;
        case 4:
            if (start == NULL)
                printf("Empty List.\n");
            else
                display();
            break;
        case 5:
            scanf("%d", &pos);
            scanf("%d", &value);
            if (start == NULL && pos != 1)
            {
                printf("Invalid position");
                break;
            }
            updateAtPosition(pos, value);
            break;
        case 6:
            deleteAtBegining();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        default:
            printf("Invalid operation.\n");
        }
        operations--;
    } while (operations > 0);
    return 0;
}