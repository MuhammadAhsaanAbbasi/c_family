#include <stdio.h>

void main()
{

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    int i, sum = 0;
    for (i = 2; i <= 100; i += 2)
    {
        sum += i;
    }
    printf(" Sum of even numbers from 1 to 100 is: %d", sum);
}