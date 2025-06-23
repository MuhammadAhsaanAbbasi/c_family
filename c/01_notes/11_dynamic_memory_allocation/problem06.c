// 4. Create an array dynamically capable of storing 5 integers. Now use realloc so
// that it can now store 10 integers.

#include <stdlib.h>
#include<stdio.h>

void main(){
    int n;
    int *ptr;

    ptr = (int *)calloc(n, sizeof(int));
    printf("The address of ptr is %u\n", ptr);
    ptr[0] = 10;
    ptr[1] = 20;

    printf("The value of ptr[0] is %d\n", ptr[0]);
    printf("The value of ptr[1] is %d\n", ptr[1]);

    n = 10;
    ptr = realloc(ptr, n*sizeof(int));

    printf("The value of ptr[0] is %d\n", ptr[0]);
    printf("The value of ptr[1] is %d\n", ptr[1]);
}