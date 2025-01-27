#include<stdio.h>

int atoi(char* str)
{
    int number=0,index=0,flag;
    if(str[0]!='-'&& str[0]<'0'&&str[0]>'9')
        return 0;
    if(str[index]=='-')
    {
        for(index=1;str[index]!='\0';index++)
        {
            if(str[index]<'0'||str[index]>'9')
                return 0;
            number=number*10-(str[index]-'0');
        }
    }
    else
    {
        for(index=0;str[index]!='\0';index++)
        {
            if(str[index]<'0'||str[index]>'9')
                return 0;
            number=number*10+(str[index]-'0');
        }
    }
    return number;
}
int main()
{
    char input[100]="";
    scanf("%s",input);
    printf("%d\n",atoi(input));
    return 0;
}