#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m=10,n,o;
    int* z;
    printf("here is m=%d , n and o are integer variables and *z is a pointer of m.\n",m);
    printf("z = %p\n",z);  
    printf("&m is address of m: %p\n",&m);   
    printf("&n is address of n: %p\n",&n);   
    printf("&o is address of o: %p\n",&o);   
    printf("&z is address of z: %p\n",&z);   
    return 0;
}