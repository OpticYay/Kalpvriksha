#include<stdio.h>

int main()
{
    char input[100],name[100];
    scanf("%[^(]",input);
    scanf("(\"%99[^\"]\")", name);
    printf("%s\n%s",input,name);
    return 0;
}