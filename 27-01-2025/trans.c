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
    int row=0,col=0;
    scanf("%d %d",&row,&col);
    int **mat1=calloc(row,sizeof(int *));
    int **mat2=calloc(col,sizeof(int *));
    for(int i=0;i<row;i++)
    {
        mat1[i]=calloc(col,sizeof(int));
    }
    for(int i=0;i<col;i++)
    {
        mat2[i]=calloc(row,sizeof(int));
    }
    input(mat1,row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            mat2[j][i]=mat1[i][j];
        }
    }
    display(mat2,col,row);
    return 0;
}