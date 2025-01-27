#include <stdio.h>
int main()
{
    char str1[100] = "", str2[100] = "";
    printf("enter 2 strings to check if the 2 are rotations of each other\n");
    scanf("%s %s", str1, str2);
    int len = 0;
    while (str1[len] != '\0')
        len++;
    if (str2[len] != '\0')
        printf("False\n");
    int index;
    for (index = 0; index < len; index++)
    {
        str1[len + index] = str1[index];
    }
    str1[len + index] = '\0';
    for (index = 0; str1[index] != '\0'; index++)
    {
        if (str1[index] == str2[0])
        {
            int flag = 0;
            for (int i = 0; i < len; i++)
            {
                if (str1[index + i] != str2[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("True\n");
                return 0;
            }
        }
    }
    printf("False\n");
    return 0;
}