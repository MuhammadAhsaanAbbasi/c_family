#include <stdio.h>
#include <conio.h>

void main()
{
    int number;
    printf("\nName: Muhammad Ahsaan Abbasi\nSTUDENT ID: CSC-25S-013\nSECTION: BSCS-1A\n");
    printf("Enter an Integer: ");
    scanf("%d", &number);
    if (number % 2 == 0)
    {
        printf("%d is even.\n", number);
    }
    else
    {
        printf("%d is odd.\n", number);
    }
}