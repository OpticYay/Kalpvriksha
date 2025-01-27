#include<stdio.h>
#include<stdlib.h>
void input(int **array,int n, int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&array[i][j]);
}
void display(int **array,int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }
}
int main()
{
    int row=0,col=0,key=0,x=-1,y=-1;
    scanf("%d %d",&row,&col);
    int **mat1=calloc(row,sizeof(int *));
    for(int i=0;i<row;i++)
    {
        mat1[i]=calloc(col,sizeof(int));
    }
    input(mat1,row,col);
    scanf("%d",&key);
    for(int i=0;i<row;i++)
    {
        if(key<mat1[i][col-1])
        {
            for(int j=0;j<col;j++)
            {
                if(key==mat1[i][j])
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(x!=-1)
            break;
    }
    if(x==-1)
    {
        printf("element not found\n");
    }
    else
    {
        printf("Element found at index (%d,%d)\n",x,y);
    }
    return 0;
}