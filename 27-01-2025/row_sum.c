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
    for(int i=0;i<row;i++)
    {
        mat1[i]=calloc(col,sizeof(int));
    }
    input(mat1,row,col);
    int* row_sum=malloc(row*sizeof(int));
    int* col_sum=malloc(col*sizeof(int));
    for(int i=0;i<row;i++)
    {
        
        for(int j=0;j<col;j++)
            row_sum[i]+=mat1[i][j];
    }
    for(int i=0;i<col;i++)
    {
        col_sum[i]=0;
        for(int j=0;j<row;j++)
            col_sum[i]+=mat1[j][i];
    }
    printf("Row sums:");
    for(int i=0;i<row;i++)
    {
        printf("%d ",row_sum[i]);
    }
    printf("\n");
    printf("col sums:");
    for(int i=0;i<row;i++)
    {
        printf("%d ",col_sum[i]);
    }
    printf("\n");
    
    return 0;
}