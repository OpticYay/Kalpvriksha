#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct hash
{
    int num;
    int seq;
    struct hash* next;
}hash;
void insert( hash** map,int ele)
{
    int index=ele%SIZE;
    hash* new = malloc(sizeof(hash));
    new->seq=0;
    new->num=ele;
    new->next=map[index];
    map[index]=new;
}
int sequence(hash** map,int key)
{
    int index=key%SIZE;
    hash* temp=map[index];
    while(temp)
    {
        if(temp->num==key)
        {
            return 1+sequence(map,key+1);
        }
        temp=temp->next;
    }
    return 0;
}
hash* locate(hash** map,int num)
{
    hash* temp=map[num%SIZE];
    while(temp)
    {
        if(temp->num==num)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
int main()
{
    hash* map[SIZE]={NULL};
    int n,ele,max_seq=0,key;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        arr[i]=ele;
        insert(map,ele);
    }
    // for(int i=0;i<SIZE;i++)
    // {
    //     hash* temp=map[i];
    //     while(temp)
    //     {
    //         printf("%d ",temp->num);
    //         temp=temp->next;
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<n;i++)
    {
        hash* temp=locate(map,arr[i]);
        temp->seq=sequence(map,arr[i]);
        if(temp->seq>max_seq)
        {
            max_seq=temp->seq;
            key=arr[i];
        }
    }
    printf("longest Sequence:");
    for(int i=key;i<key+max_seq;i++)
    {
        printf("%d ",i);
    }
    return 0;
}