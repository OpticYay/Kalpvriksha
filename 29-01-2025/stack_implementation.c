#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct stack
{
    int stack[100];
    int top;
} stack;
void push(int value, stack *s)
{
    if (s->top == MAX - 1)
    {
        printf("stack overflow.\n");
        return;
    }
    s->top += 1;
    s->stack[s->top] = value;
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("stack underflow.\n");
        return;
    }
    return s->stack[s->top--];
}
void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Empty stack.\n");
        return;
    }
    int itr = s->top;
    while (itr != -1)
    {
        printf("%d ");
        itr--;
    }
    printf("\n");
}
int main()
{
    stack s;
    s.top = -1;
    int exit = 0;
    do
    {
        int option;
        printf("Enter your choice.\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        int value = 0;
        switch(option)
        {
        case 1:
            scanf("enter value to push.\n");
            push(value, &s);
            break;
        case 2:
            value = pop(&s);
            printf("Popped value:%d\n", value);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit=1;
            break;
        }
    } while (exit != 1);
    return 0;
}