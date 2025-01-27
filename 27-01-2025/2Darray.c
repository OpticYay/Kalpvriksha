#include<stdio.h>
#include<stdlib.h>
int len(char* str)
{
    int i=0;
    while(str[i])
    {
        if(str[i]!='\0')
            i++;
        else
            break;
    }
    return i;
}
int main()
{
    int rows,cols,i,j,vowels=0,longest_x=0,longest_y=0,choice=1;
    printf("Enter rows and columns.\n");
    scanf("%d %d",&rows,&cols);
    char ***names=(char *)malloc(rows*sizeof(char *));  
    printf("%d enter names.\n",cols*rows);
    for(i=0;i<rows;i++)
    {
        names[i]=malloc(cols*sizeof(char *));
    }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            names[i][j]=malloc(50*sizeof(char *));
            printf("Name at(%d,%d)",i,j);
            scanf("\n%[^\n]",names[i][j]);
            if(names[i][j][0]=='a'||names[i][j][0]=='A'||names[i][j][0]=='e'||names[i][j][0]=='E'||names[i][j][0]=='i'||names[i][j][0]=='I'||names[i][j][0]=='o'||names[i][j][0]=='O'||names[i][j][0]=='u'||names[i][j][0]=='U')
                vowels++;
            if(len(names[i][j])>strlen(names[longest_x][longest_y]))
            {
                longest_x=i;
                longest_y=j;
            }
        }
    }
    printf("Names in matrix format.\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%s ",names[i][j]);
        }
        printf("\n");
    }
    printf("Number of names starting with a vowel: %d\n",vowels);
    printf("The longest name:%s\n",names[longest_x][longest_y]);
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            free(names[i][j]);
        }
        free(names[i]);
    }
    free(names);
    return 0;
}
