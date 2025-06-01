#include <stdio.h>

void main()
{

    int temp;

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    printf("Enter the temperature: ");
    scanf("%d", &temp);

    if (temp < 80)
    {
        if (temp > 60)
        {
            printf("nice day");
        };
    }
    else
    {

        printf("sure it is hot");
    }
}