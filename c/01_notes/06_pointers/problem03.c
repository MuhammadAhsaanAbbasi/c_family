#include<stdio.h>

void change_address_ten_times(int* a);

void change_address_ten_times(int* a){
    *a = *a * 10;
}

void main(){
    int a = 50;
    printf("The value of a is %u\n", a);
    change_address_ten_times(&a);
    printf("The value of 10x a is %d\n", a);
}