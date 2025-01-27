// Problem Statement:
// Rotate a given square 2D array (matrix) by 90 degrees clockwise.

// Input Format:

// The first line contains an integer n, the size of the matrix.
// The next n lines each contain n integers, representing the rows of the matrix.
// Output Format:
// Print the rotated matrix.

// Example:
// Input:

// 3  
// 1 2 3  
// 4 5 6  
// 7 8 9  
// Output:

// 7 4 1  
// 8 5 2  
// 9 6 3  

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size=0,rows,cols;
    scanf("%d",&size);
    int **mat=calloc(size,sizeof(int *));
    int **result=calloc(size,sizeof(int *));
    printf("Enter matrix\n");
    for(rows=0;rows<size;rows++)
    {
        mat[rows]=malloc(size*sizeof(int));
        result[rows]=malloc(size*sizeof(int));
        for(cols=0;cols<size;cols++)
        {
            scanf("%d",&mat[rows][cols]);
        }
    }
    for(rows=0;rows<size;rows++)
    {
        for(cols=0;cols<size;cols++)
        {
            result[cols][size-1-rows]=mat[rows][cols];
        }
    }
    for(rows=0;rows<size;rows++)
    {
        for(cols=0;cols<size;cols++)
        {
            printf("%d ",result[rows][cols]);
        }
        printf("\n");
    }
    for(rows=0;rows<size;rows++)
    {
        free(mat[rows]);
        free(result[rows]);
    }
    free(mat);
    free(result);
    return 0;
}