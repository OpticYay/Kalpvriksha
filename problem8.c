#include <stdio.h>
int main()
{
    char input[100], result[100];
    printf("Enter a string.\n");
    scanf("%s", input);
    int count = 1, res_count = 1;
    char ch = input[0];
    result[0] = input[0];
    for (int i = 1; input[i] != '\0'; i++)
    {
        if (ch == input[i])
        {
            count++;
        }
        else
        {
            int temp=count;
            count=0;
            while(temp!=0)
            {
                count=count*10+temp%10;
                temp/=10;
            }
            while(count!=0)
            {
                result[res_count++]='0'+count%10;
                count/=10;
            }
            count = 1;
            result[res_count++] = input[i];
            ch = input[i];
        }
    }
    result[res_count++]='0'+count;
    result[res_count]='\0';
    printf("%s\n",result);
    return 0;
}