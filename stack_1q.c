
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
    int size;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

bool isEmptyQueue(Queue *q)
{
    return q->size == 0;
}

int sizeQueue(Queue *q)
{
    return q->size;
}

void enqueue(Queue *q, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

int dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int peekQueue(Queue *q)
{
    return isEmptyQueue(q) ? -1 : q->front->data;
}

void printQueue(Queue *q)
{
    Node *temp = q->front;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

typedef struct
{
    Queue q1;
} Stack;

void initStack(Stack *s)
{
    initQueue(&s->q1);
}
int sizeStack(Stack *s)
{
    return s->q1.size;
}

void push(Stack *s, int x)
{
    int n = sizeStack(s);
    enqueue(&s->q1, x);
    for (int i = 0; i < n; i++)
    {
        enqueue(&s->q1, dequeue(&s->q1));
    }
}

int pop(Stack *s)
{
    if (isEmptyQueue(&s->q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    int popped = dequeue(&s->q1);
    return popped;
}

int peek(Stack *s)
{
    if (isEmptyQueue(&s->q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    int topElement = peekQueue(&s->q1);
    return topElement;
}

bool isEmptyStack(Stack *s)
{
    return isEmptyQueue(&s->q1);
}

void printStack(Stack *s)
{
    printQueue(&s->q1);
}

int main()
{
    Stack s;
    initStack(&s);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("Top Element: %d\n", value);
                break;
            case 4:
                printf(isEmptyStack(&s) ? "Stack is Empty\n" : "Stack is not Empty\n");
                break;
            case 5:
                printf("Stack: ");
                printStack(&s);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}