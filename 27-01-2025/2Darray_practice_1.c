// Problem Statement:
// You are given a 6x6 2D array, A, where each element is an integer. An hourglass in A is defined as a subset of values with the following pattern:

// a b c  
//   d  
// e f g  
// The task is to calculate the sum of all values in every hourglass in A and determine the maximum hourglass sum.

// Constraints:

// The array A will always be 6x6.
// Each element of A is a space-separated integer provided as input.
// Input Format:
// A 6x6 2D array of integers provided as 6 lines of input, where each line contains 6 integers separated by spaces.

// Output Format:
// Print the maximum hourglass sum.
#include <stdio.h>

int main()
{
    int arr[6][6];
    int row=0,col=0,sum_max=0;
    for(row=0;row<6;row++)
    {
        for(col=0;col<6;col++)
            scanf("%d",(&arr[row][col]));
    }
    for(row=1;row<5;row++)
    {
        for(col=1;col<5;col++)
        {
            int sum=arr[row-1][col-1]+arr[row-1][col]+arr[row-1][col+1]+arr[row+1][col-1]+arr[row+1][col]+arr[row+1][col+1]+arr[row][col];
            if(sum>sum_max || (row==1&&col==1))
            {
                sum_max=sum;
            }
        }  
    }
    printf("%d",sum_max);
    return 0;
}