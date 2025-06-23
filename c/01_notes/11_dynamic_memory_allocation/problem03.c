#include<stdio.h>
#include<stdlib.h>

void main(){
    int n=6;
    int *ptr;

    ptr = (int *)calloc(n, sizeof(int));
    printf("The address of ptr is %u\n", ptr);
    ptr[0] = 10;
    ptr[1] = 20;

    printf("The value of ptr[0] is %d\n", ptr[0]);
    printf("The value of ptr[1] is %d\n", ptr[1]);
}