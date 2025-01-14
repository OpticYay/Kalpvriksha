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
    char input[100],words[50][50];
    int word=0,word_index=0;
    scanf("%[^\n]",input);    
    for(int index=0;input[index]!='\0';index++)
    {
        if(input[index]==' ')
        {
            words[word][word_index]='\0';
            word++;
            word_index=0;
            continue;
        }
        words[word][word_index++]=input[index];
    }
    int max_len=strlength(words[0]),ptr=0;
    for(int index=1;index<=word;index++)
        if(strlength(words[index])>=max_len)
            ptr=index;
    printf("%s",words[ptr]);
    return 0;
}