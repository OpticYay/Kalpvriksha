#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* input=malloc(100*sizeof(char));
    printf("enter a string without spaces.\n");
    scanf("%s",input);
    int size=0;
    while(size!='\0')
        size++;
    char* result=calloc(size,sizeof(char));
    int itr,set_size=0;
    for(itr=0;input[itr]!='\0';itr++)
    {
        int set_itr,flag=0;
        for(set_itr=0;set_itr<=set_size;set_itr++)
        {
            if(input[itr]==result[set_itr])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            result[set_size++]=input[itr];
        }
        flag=0;
    }
    result[set_size]='\0';
    printf("%s\n",result);
    free(input);
    free(result);
    return 0;
}