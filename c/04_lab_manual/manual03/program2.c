#include <stdio.h>

void main()
{

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    int i, n, j = 0;
    printf("\n\t\tEnter Table No.  ");
    scanf("%d", &n);
    if (n >= 2 && n <= 20)
        for (i = 1; i <= 12; i++)
        {
            j = n * i;
            printf("\n\t\t%d * %d =  %d", n, i, j);
        }
    else
        printf("\nError!!! Enter number from 2 to 20");
}