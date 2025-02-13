#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define MAX 10
int a[MAX];
int r=0,w=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void* update()
{
    pthread_mutex_lock(&lock);
    sleep(0.2);
    a[w]=rand()%100;
    printf("updated %d in a[%d] \n",a[w],w);
    w=(w+1)%MAX;
    pthread_mutex_unlock(&lock);
}
void* print()
{
    pthread_mutex_lock(&lock);
    sleep(0.2);
    printf("printed:%d\n",a[r]);
    r=(r+1)%MAX;
    pthread_mutex_unlock(&lock);  
}
int main()
{
    int n=10;
    pthread_t ptid1,ptid2,ptid3;
    while(n--)
    {
        pthread_create(&ptid1,NULL,&update,NULL);
        pthread_create(&ptid3,NULL,&update,NULL);
        pthread_create(&ptid2,NULL,&print,NULL);
        pthread_join(ptid1,NULL);
        pthread_join(ptid2,NULL);
        pthread_join(ptid3,NULL);
    }
    return 0;
}