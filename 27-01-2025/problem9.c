#include<stdio.h>
int main()
{
    char ch,input[100],result[100];
    printf("Enter a string\n");
    scanf("%[^\n]%*c",input);
    printf("Enter a character\n");
    scanf("%c",&ch);
    int index,itr=0;
    for(index=0;input[index]!='\0';index++)
    {
        if(input[index]!=ch)
            result[itr++]=input[index];
    }
    result[itr]='\0';
    printf("result:%s\n",result);
    return 0;
}