#include<stdio.h>

int substr(char* str,char* key)
{
    int index=0,itr,key_itr;
    for(itr=0;str[itr]!='\0';itr++)
    {
        if(str[itr]==key[0])
        {
            int flag=0,index=itr;
            for(key_itr=0;key[key_itr]!='\0';key_itr++)
            {
                if(str[itr]==key[key_itr])
                {
                    itr++;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                return index;
            }
            flag=0;
        }
    }
    return -1;
}

int main()
{
    char string[100]="",key[100]="";
    printf("Enter a string.\n");
    scanf("%100[^\n]%*c",string);
    printf("Enter a Key.\n");
    scanf("%100[^\n]",key);
    int index=substr(string,key);
    printf("%d\n",index);
    return 0;
}