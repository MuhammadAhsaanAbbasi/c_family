#include <stdio.h>

void main()
{

    int numbers[10];
    int i, largest;
    // Input 10 integers
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Assume the first number is the largest
    largest = numbers[0];

    // Compare with the rest of the numbers
    for (i = 1; i < 10; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }

    // Output the largest number
    printf("The largest number is: %d\n", largest);
}