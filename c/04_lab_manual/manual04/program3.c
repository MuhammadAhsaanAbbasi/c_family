#include <stdio.h>

void main()                /* use int main, not void main */
{
    printf("Name: Muhammad Ahsaan Abbasi\n");
    printf("Student ID: CSC-25S-013\n");
    printf("Section: BSCS-1A\n");

    char x, y;

    // printf("Enter the first character: ");
    scanf(" %c", &x);         /* note the leading space */

    // printf("Enter the second character: ");
    scanf(" %c", &y);         /* leading space again */

    if (x == 'n' && y == 'o')
        printf("You typed no\n");
}
