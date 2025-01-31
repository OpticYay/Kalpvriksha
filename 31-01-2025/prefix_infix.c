#include<stdio.h>
#include<string.h>
void push(char* stack, char ch,int* top)
{
    if(top<99)
    {
        *top+=1;
        stack[*top]=ch;
    }
}
char pop(char* stack, int* top)
{
    if(top>-1)
    {
        char ch=stack[*top];
        *top-=1;
        return ch;
    }
}
int peek(char* stack,int top)
{
    if(top>-1)
    {
        return 1;
    }
    return 0;
}
char* infix(char* input)
{
    int i=0,result_index=0,top=-1;
    char result[100]="",stack[100];
    while(input[i]!='\0')
    {
        if(input[i]!='+'||input[i]!='-'||input[i]!='*'||input[i]!='%'||input[i]!='^'||input[i]!='/')
        {
            char ch=peek(stack,top);
            if((ch>='a'&&ch<='z') || (ch>='A'&&ch>='Z'))
            {
                char temp[100];
                *temp=strcat(ch,result);
            }
        }
    }
}
int main()