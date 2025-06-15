// Write a function and pass the value by reference.
#include<stdio.h>

void passByReference(int *a);

void passByReference(int *a){
    printf("Value of a is %d\n",*a);
}

void main(){
    int a=10;
    printf("The Value of a is %d\n", a);
    passByReference(&a);
}