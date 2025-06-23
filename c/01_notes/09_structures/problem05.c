// 5. Write a program with a structure representing a complex number.

#include<stdio.h>

struct complex
{
    /* data */
    int real;
    int img;
};


void main(){
    struct complex c1;
    printf("Enter the real and imaginary part of complex number: ");
    scanf("%d %d",&c1.real,&c1.img);
    printf("Complex number is: %d + %di",c1.real,c1.img);
}