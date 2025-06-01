#include <stdio.h>

void main()
{

    char ch;
    printf("\nName: Muhammad Ahsaan Abbasi\nSTUDENT ID: CSC-25S-013\nSECTION: BSCS-1A\n");
    printf("Enter a Character: \n");
    scanf("%c", &ch);
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        char lowerCh = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u')
        {
            printf("%c' is a Vowel.\n", ch);
        }
        else
        {
            printf("%c' is a Consonant.\n", ch);
        }
    }
    else
    {
        printf("%c' is not an Alphabet.\n", ch);
    }
}