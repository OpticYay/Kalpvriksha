#include<stdio.h>

int main()
{
    char stack[100];
    int top=-1;
    char input[100];
    printf("Enter a sequence of brackets.\n");
    scanf("%s%*c",input);
    int flag=0;
    for(int itr=0;input[itr]!='\0';itr++)
    {
        if(input[itr]=='['||input[itr]=='('||input[itr]=='{')
        {
            stack[++top]=input[itr];
        }
        else if(input[itr]==']'&& stack[top]!='[')
        {
            printf("Invalid sequence.\n");
            flag=1;
            break;
        }
        else if(input[itr]==')'&& stack[top]!='(')
        {
            printf("Invalid sequence.\n");
            flag=1;
            break;
        }
        else if(input[itr]=='}'&& stack[top]!='{')
        {
            printf("Invalid sequence.\n");
            flag=1;
            break;
        }
        else
            top--;
    }
    if(flag==0)
        printf("Valid sequence.\n");
    return 0;
}