#include <stdio.h>

int main(){
    float num1, num2;
    printf("Hello World\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1){
        printf("Result: %.2f", num1 + num2);
    }
    else if (choice == 2){
        printf("Result: %.2f", num1 - num2);
    }
    else if (choice == 3){
        printf("Result: %.2f", num1 * num2);
    }
    else if (choice == 4){
        printf("Result: %.2f", num1 / num2);
    }
    else if (choice == 5){
        // Use %d for printing an integer result.
        printf("Result: %d", (int)num1 % (int)num2);
    }
    return 0;
}
