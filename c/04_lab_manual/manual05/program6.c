#include <stdio.h>

void main()
{

    char text[1000];
    int i, vowels = 0, consonants = 0, special = 0;

    // Ask user for input
    printf("\n Name: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    printf("Enter a line of text: ");
    gets(text); // Note: gets is unsafe, but used here for simplicity as per beginner context

    // Traverse each character
    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        // Check for vowels
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
        // Check for consonants (alphabets that are not vowels)
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            consonants++;
        }
        // Anything else is a special character (including space, numbers, punctuation)
        else
        {
            special++;
        }
    }

    // Print the results
    printf("Total Vowels: %d\n", vowels);
    printf("Total Consonants: %d\n", consonants);
    printf("Total Special Characters: %d\n", special);
}