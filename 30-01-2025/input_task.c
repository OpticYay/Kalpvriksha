#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int* array=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d%*c",&array[i]);
    }
    char text[100];
    scanf("%[^\n]%*c",text);
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("%s",text);
}