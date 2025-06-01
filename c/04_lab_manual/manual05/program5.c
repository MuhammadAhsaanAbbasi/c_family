#include <stdio.h>
#include <conio.h>

void main()
{

    char operator;
    int num1, num2, result;

    // Ask the user for input
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A");
    printf("\nEnter an arithmetic operator (+, -, *, /, %%): ");
    scanf(" %c", &operator); // space before %c to catch any leftover newline

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform the calculation
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("Result: %d + %d = %d\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result: %d - %d = %d\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result: %d * %d = %d\n", num1, num2, result);
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("Result: %d / %d = %d\n", num1, num2, result);
        }
        else
        {
            printf("Error: Division by zero is not allowed.\n");
        }
        break;
    case '%':
        if (num2 != 0)
        {
            result = num1 % num2;
            printf("Result: %d %% %d = %d\n", num1, num2, result);
        }
        else
        {
            printf("Error: Modulo by zero is not allowed.\n");
        }
        break;
    default:
        printf("Invalid operator.\n");
    }
}