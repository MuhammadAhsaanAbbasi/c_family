// Vowel or Consonant
// Read a single letter and print whether it’s a vowel (a, e, i, o, u) or a consonant.

#include<stdio.h>

void main(){
    char letter = 'b';
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
        printf("Vowel\n");
    else
        printf("Consonant\n");
}