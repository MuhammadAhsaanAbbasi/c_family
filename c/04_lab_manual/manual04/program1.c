#include <stdio.h>

void main()
{

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    float guess, incr;
    char ch;
    printf("Think of a number between 1 and 99,and\n");
    printf("I'will guess what it is. Type 'e' for equals,\n");
    printf("'g' for greater than, and 'l' for less than.\n");
    incr = guess = 50; /* two assignments at once */
    while (incr > 1.0) /* while not close enough */
    {
        printf("\nIs your number greater or less than %.0f?\n", guess);
        incr = incr / 2;
        if ((ch = getche()) == 'e') /* if guess it already */
            break;                  /* escape from loop */
        else if (ch == 'g')         /* if guess too low */
            guess = guess + incr;   /* try higher */
        else                        /* if guess too high */
            guess = guess - incr;   /* try lower */
    }
    printf("\nThe number is %.0f. Am I not clever?", guess);
}