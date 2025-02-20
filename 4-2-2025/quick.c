#include<stdio.h>

int partition(int* arr,int low,int high)
{
    int pivot=arr[low];
    int i=low+1,j=high;
    while(i<j)
    {
        while(i<high && arr[i]<=pivot)
            i++;
        while(j>low && arr[j]>pivot)
            j--;
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quicksort(int* arr,int low,int high)
{
    if(low<high)
    {
        int pivot=partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
int main()
{
    int array[10]={1,4,3,8,2,5,1,3,9,0};
    quicksort(array,0,9);
    for(int i=0;i<10;i++)
        printf("%d ",array[i]);
    printf("\n");
    return 0;
}