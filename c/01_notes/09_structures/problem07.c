// 6. Create an array of 5 complex numbers created in Problem 5 and display them
// with the help of a display function. The values must be taken as an input from
// the user.

#include <stdio.h>

typedef struct c
{
    /* data */
    int real;
    int img;
} complex;

void display(complex c1)
{
    printf("The real part is %d\n", c1.real);
    printf("The imaginary part is %d\n", c1.img);
}

void main()
{
    complex c1[5];
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("Enter the real and imaginary part of complex number: ");
        scanf("%d %d", &c1[i].real, &c1[i].img);
        display(c1[i]);
    }
}