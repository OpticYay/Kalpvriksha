#include<stdio.h>
//this code shows how data segements are allocated
int main()
{
    //allocated in stack
    int a=100;
    //allocated memory after a and any extra characters over the limit is ignored
    char name1[12]={'K','a','l','a','p','v','r','i','k','s','h','a'};
    //allocated memory after name1
    char name[13]={'K','a','l','a','p','v','r','i','k','s','h','a','\0'};

    printf("%s\n",name);
    printf("%s\n",name1);
    return 0;
}
//this program will print kalpavriksha in one line and kalpavrikshad in next as 100 is ascii value of small d
//and when the name1 and name are interchanged then the output is kalpavriksa and kalpavrikshakalpavriksha
//print statement will print till the last character in the array + next 4 bytes or till it reaches a null pointer