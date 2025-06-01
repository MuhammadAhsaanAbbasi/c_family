#include <stdio.h>

void main()
{

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    double f;
    int num;
    // computes the product n*(n-1)*(n-2)*(n-3)*...*2*1
    while (num != 0)
    {
        printf("\n\n\n\t\tEnter the number to find its factorial: ");
        scanf("%d", &num);
        f = 1;
        while (num > 1)
        {
            f = f * num;
            num--;
        }
        printf("\t\tThe factorial is %lf", f);
    }
}