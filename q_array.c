#include<stdio.h>
#define MAX 100
typedef struct Queue {
    int front, rear, size;
    int arr[MAX];
} Queue;
int isEmpty(Queue* q) 
{
    return q->size == 0;
}
int isFull(Queue* q) 
{
    return q->size == MAX;
}
void enqueue(Queue* q, int value) {
    if (isFull(q)) 
    {
        printf("Queue Overflow \n");
        return;
    }
    q->rear = (q->rear + 1);
    q->arr[q->rear] = value;
    q->size++;
}
int dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1);
    q->size--;
    return value;
}
int peek(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow.\n");
        return -1;
    }
    return q->arr[q->front];
}
void display(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) 
    {
        int index = (q->front + i) % MAX;
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}
int main()
{
    Queue q;
    q.front=-1;
    q.rear=-1;
    q.size=0;

    printf("\nQueue implementation using Stacks: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. isEmpty\n");
    printf("5. Print All\n");
    printf("6. Exit\n");

    int ch, n;
    while (1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &n);
            enqueue(&q, n);
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue(&q));
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            printf("Is empty: %s\n", isEmpty(&q) ? "True" : "False");
            break;
        case 5:
            display(&q);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
