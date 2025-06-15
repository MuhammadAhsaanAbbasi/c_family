#include<stdio.h>

void pass_variable(int*);

void pass_variable(int* ptr1){
    printf("The address of ptr1 is %u\n", ptr1);
}

void main(){
    int i=10;
    printf("The address of i is %u\n", &i);
    pass_variable(&i);
}