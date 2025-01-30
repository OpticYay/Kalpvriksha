#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* a=NULL;
    int size=0,input=0;
    while(1)
    {
        printf("Enter elements and enter -1 to exit.\n");
        scanf("%d%*c",&input);
        if(input==-1)
            break;
        size=size+1;
        int* new=realloc(a,size);
        new[size-1]=input;
        a=new;
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}