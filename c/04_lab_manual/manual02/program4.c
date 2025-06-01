#include <stdio.h>
#include<conio.h>
#include <math.h>

void main()
{
    int num1, num2;
    int sum, difference, product;
    float quotient;

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    printf("Enter first Integer: ");
    scanf("%d", &num1);
    printf("Enter second Integer: ");
    scanf("%d", &num2);
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    if (num2 != 0)
    {
        quotient = (float)num1 / num2;
    }
    else
    {
        printf("Division by Zero is not Allowed.\n");
    }
    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", difference);
    printf("Product = %d\n", product);
    if (num2 != 0)
    {
        printf("Quotient = %.2f\n", quotient);
    }
}