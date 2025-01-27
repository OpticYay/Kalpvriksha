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
    int **mat2=calloc(row,sizeof(int *));
    int **result=calloc(row,sizeof(int *));
    for(int i=0;i<row;i++)
    {
        mat1[i]=calloc(col,sizeof(int));
        mat2[i]=calloc(col,sizeof(int));
        result[i]=calloc(col,sizeof(int));
    }
    input(mat1,row,col);
    input(mat2,row,col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int product=0;
            for(int k=0;k<row;k++)
            {
                product=product+mat1[i][k]*mat2[k][j];
            }
            result[i][j]=product;
        }
    }
    display(result,row,col);
    return 0;
}