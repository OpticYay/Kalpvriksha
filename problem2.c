#include<stdio.h>
#include<stdlib.h>
int main()
{
    char* input=malloc(100*sizeof(char));
    printf("enter a string to count words in.\n");
    scanf("%[^\n]",input);
    int space=0,index;
    for(index=0;input[index]!='\0';index++)
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