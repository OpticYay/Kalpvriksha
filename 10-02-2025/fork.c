#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void singlefork()
{
    fork();
    printf("single fork P_ID: %d ",getpid());
}
void doublefork()
{
    fork();
    fork();
    printf("double fork P_ID: %d ",getpid());
}
void triplefork()
{
    fork();
    fork();
    fork();
    printf("triple fork P_ID: %d ",getpid());
}
int main()
{
    singlefork();
    printf("\n");
    doublefork();
    printf("\n");
    // triplefork();
    return 0;
}