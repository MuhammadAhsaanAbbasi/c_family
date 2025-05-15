#include<stdio.h>

void main(){
    int num1, num2;

    printf("Enter Num1 Value:");
    scanf("%d", &num1);

    printf("Enter Num2 Value:");
    scanf("%d", &num2);

    printf("\nAddition: %d + %d = %d", num1, num2, num1+num2);
    printf("\nSubstraction: %d - %d = %d", num1, num2, num1-num2);
    printf("\nMultiplication: %d * %d = %d", num1, num2, num1*num2);
    printf("\nDivision: %d / %d = %.2f", num1, num2, (float) num1/num2);
}