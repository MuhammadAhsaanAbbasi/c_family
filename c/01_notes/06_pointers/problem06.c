// 6. Write a program to print the value of a variable i by using “pointer to pointer” type
// of variable.

#include<stdio.h>

void main(){
    int a = 10;
    int *ptr = &a;
    int **ptr2 = &ptr;

    printf("The address of a is %u\n", &a);
    printf("The Value of a is %d\n", *ptr);
    printf("The Value of a is %d\n", **ptr2);
}