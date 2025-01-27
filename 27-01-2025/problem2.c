#include<stdio.h>
#include<stdlib.h>
int strlength(char *str)
{
    int itr;
    for(itr=0;str[itr]!='\0';itr++);
    return itr;
}
int main()
{
    char* input=malloc(100*sizeof(char));
    printf("enter a string to count words in.\n");
    scanf("%[^\n]",input);
    int space=0,index=0;
    for(index=strlength(input);input[index]==' ';index--)
        input[index]='\0';
    for(index=0;input[index]==' ';index++);
    for(;input[index]!='\0';index++)
        if(input[index]==' ')
            {
                space++;
                while(input[index]==' ')
                    index++;
            }
    if(space>=1)
        printf("string contains %d words.\n",space+1);
    else
        printf("Entpy string.\n");
    free(input);
    return 0;
}