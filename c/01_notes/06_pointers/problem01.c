#include<stdio.h>

void main(){

    int a=10;

    int* ptr1 = &a;

    printf("The address of a is %u\n", &a);
    printf("The value of a is %d\n",*ptr1);

    // printf("Hello World\n");
}