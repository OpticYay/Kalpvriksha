#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct hash
{
    int num;
    int start;
    int end;
    int freq;
    struct hash* next;
}hash;
void insert(hash** map,int ele,int i)
{
    int index=ele%SIZE;
    hash* new = map[index];
    while(new)
    {
        if(new->num==ele)
        {
            new->freq++;
            new->end=i;
            return;
        }
        new=new->next;
    }
    new=malloc(sizeof(hash));
    new->freq=1;
    new->num=ele;
    new->start=i;
    new->end=i;
    new->next=map[index];
    map[index]=new;
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
    int n;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        insert(map,arr[i],i);
    }
    // for(int i=0;i<SIZE;i++)
    // {
    //     hash* temp=map[i];
    //     while(temp)
    //     {
    //         printf("%d->%d %d-%d ",temp->num,temp->freq,temp->start,temp->end);
    //         temp=temp->next;
    //     }
    //     printf("\n");
    // }
    int key,len=0,freq=0,start,end;
    for(int i=0;i<n;i++)
    {
        hash* temp=locate(map,arr[i]);
        if(temp->freq>freq)
        {
            freq=temp->freq;
            key=arr[i];
            len=temp->end-temp->start;
            start=temp->start;
            end=temp->end;
        }
        else if(temp->freq==freq && len>(temp->end-temp->start))
        {   
            key=arr[i];
            len=temp->end-temp->start;
            start=temp->start;
            end=temp->end;
        }
    }
    printf("key:%d range:%d-%d\n",key,start,end);
    for(int i=start;i<=end;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}