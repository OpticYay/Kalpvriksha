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