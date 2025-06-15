// 5. Write a program using a function which calculates the sum and average of two
// numbers. Use pointers and print the values of sum and average in main().

#include<stdio.h>

// int* sum(int a, int b);

int* sum(int a, int b) {
    int s = a + b;
    printf("The Sum of %d and %d is %d\n", a, b, s);
    int* ptr1 = &s;
    return ptr1;
}

float* avg(int a, int b) {
    float avg = (a + b) / 2;
    printf("The Average of %d and %d is %f\n", a, b, avg);
    float* ptr2 = &avg;
    return ptr2;
}

void main(){
    int x = 5;
    int y = 12;

    int* ptr1;
    float* ptr2;

    ptr1 = sum(x, y);
    ptr2 = avg(x, y);

     printf("The address of sum is %u and of average is %u", ptr1, ptr2 );
}