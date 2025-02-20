#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct thread_node {
  char name[10];
  int priority;
  struct thread_node *next;
};
typedef struct thread_node thread_node;

struct priority_queue {
  thread_node *front, *rear;
};
typedef struct priority_queue priority_queue;

void enqueue(priority_queue *queue, thread_node *thread) 
{
    if(queue->front==NULL)
    {
        queue->front=thread;
        queue->rear=queue->front;
    }
    else
    {
        queue->rear->next=thread;
        queue->rear=thread;
    }
}

thread_node* dequeue(priority_queue *queue) 
{
    thread_node* prev=NULL;
    thread_node* curr=queue->front,* min=queue->front;
    while(curr->next!=NULL)
    {
        if(min->priority>curr->next->priority)
        {
            prev=curr;
            min=curr->next;
        }
    }
    if(prev==NULL)
    {
        queue->front=queue->front->next;
        min->next=NULL;
        return min;
    }
    prev->next=min->next;
    return min;
}


/*=======DO NOT MODIFY THE CODE BELOW =======*/

thread_node* create_node(char *thread_name, int thread_priority) {
  thread_node *thread;
  thread = malloc(sizeof(thread_node));
  thread->priority = thread_priority;
  strcpy (thread->name, thread_name);
  thread->next = NULL;

  return thread;
}

//Get new queue
priority_queue* create_queue() {
  priority_queue *queue = malloc(sizeof(priority_queue));
  queue->front = NULL;
  queue->rear = NULL;

  return queue;
}

void display(thread_node *thread) {
        printf("%s %d", thread->name, thread->priority);
        printf("\n");
}

int main(int argc, char * argv[])
{
        int thread_count, thread_priority;
        char thread_name[10];

        priority_queue *queue = create_queue();

        scanf("%d", &thread_count);

        thread_node *thread[thread_count];

        //Input the Thread priority table and put it in queue.
        for (int index = 0; index < thread_count; index++) {
        scanf("%s %d",thread_name,&thread_priority);

        thread[index] = create_node(thread_name, thread_priority);

        enqueue(queue, thread[index]);
        }

        for (int index = 0; index < thread_count; index++) {
                //dequeue will return threads
                display(dequeue(queue));
       }
}