#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void sort_arr(int *arr,int size)
{
    int ptr1,ptr2;
    for(ptr1=0;ptr1<size;ptr1++)
    {
        for(ptr2=ptr1+1;ptr2<size;ptr2++)
        {
            if(arr[ptr1]>arr[ptr2])
            {
                arr[ptr1]+=arr[ptr2];
                arr[ptr2]=arr[ptr1]-arr[ptr2];
                arr[ptr1]=arr[ptr1]-arr[ptr2];
            }
        }
    }
    return;
}
int main() {

    char string[105];
    scanf("%[^\n]", string);
    int index = 0, array_size = 1, array_itr = 0;
    while (string[index] != '\0')
    {
        if (string[index] == ' ')
        {
            array_size++;
        }
        index++;
    }
    int *array = calloc(array_size, sizeof(int));
    for (index = 1; string[index] != '\0'; index++)
    {
        if (string[index] == '-')
        {
            index++;
            while (string[index] != ' ')
            {
                if (string[index] == ']')
                    break;
                array[array_itr] = (array[array_itr] * 10) - (int)(string[index] - '0');
                index++;
            }
            array_itr++;
        }
        else
        {
            while (string[index] != ' ')
            {
                if (string[index] == ']')
                    break;
                array[array_itr] = (array[array_itr] * 10) + (int)(string[index] - '0');
                index++;
            }
            array_itr++;
        }
    }
    int ptr1,ptr2,ptr3;
    sort_arr(array,array_size);
    int **result=NULL,size=0;
    for (ptr1=0;ptr1<array_size;ptr1++)
    {
        for(ptr2=ptr1;ptr2<array_size;ptr2++)
        {
            for(ptr3=ptr2;ptr3<array_size;ptr3++)
            {
                if(ptr1!=ptr2 && ptr1!=ptr3 && ptr2!=ptr3)
                {
                    int sum=array[ptr1]+array[ptr2]+array[ptr3];
                    if(sum==0)
                    {
                        result=realloc(result,++size*sizeof(int *));
                        result[size-1]=malloc(3*sizeof(int));
                        result[size-1][0]=ptr1;
                        result[size-1][1]=ptr2;
                        result[size-1][2]=ptr3;
                    }
                }
            }
        }
    }
    for(ptr1=0;ptr1<size;ptr1++)
    {
        int flag=0;
        for(ptr2=ptr1+1;ptr2<size;ptr2++)
        {
            if(result[ptr1][0]==result[ptr2][0])
            {
                if(result[ptr1][1]==result[ptr2][1])
                {
                    if(result[ptr1][2]==result[ptr2][2])
                    {
                       flag=1;
                       break; 
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("[%d %d %d]\n",array[result[ptr1][0]],array[result[ptr1][1]],array[result[ptr1][2]]);
        }
    }
    return 0;
}