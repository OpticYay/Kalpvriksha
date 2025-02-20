#include<stdio.h>
#include<stdlib.h>

int* fun()
{
    int a=10;
    free(&a);
    return &a;
}
int main()
{
    int* a=fun();
    printf("%d",*a);
    return 0;
}
// free(): invalid pointer
// Aborted (core dumped)