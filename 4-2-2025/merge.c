#include<stdio.h>

void merge(int* array,int left,int mid,int right)
{
    int result[right-left+1];
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right)
    {
        if(array[i]<array[j])
        {
            result[k++]=array[i++];
        }
        else
        {
            result[k++]=array[j++];
        }
    }
    while(i<=mid)
    {
        result[k++]=array[i++];
    }
    while(j<=right)
    {
        result[k++]=array[j++];
    }
    for(int a=0;a<k;a++)
    {
        array[left+a]=result[a];
    }
}
void mergesort(int* array,int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}
int main()
{
    int n;
    printf("Enter number of elements.\n");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
    mergesort(array,0,n-1);
    printf("SORTED ARRAY: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
    return 0;
}