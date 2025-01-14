#include<stdio.h>
int strlength(char *str)
{
    int itr;
    for(itr=0;str[itr]!='\0';itr++);
    return itr;
}
int main()
{
    char input1[100],input2[100];
    scanf("%s %s",input1,input2);
    if(strlength(input1)!=strlength(input2))
        printf("False");
    for(int ptr1=0;input1[ptr1]!='\0';ptr1++)
    {
        int flag=1;
        for(int ptr2=0;input2[ptr2]!='\0';ptr2++)
        {
            if(input1[ptr1]==input2[ptr2])
            {
                flag=0;
                input2[ptr2]='-';
                break;
            }
        }
        if(flag==1)
        {
            printf("False");
            return 0;
        }
    }
    printf("True");
    return 0;
}