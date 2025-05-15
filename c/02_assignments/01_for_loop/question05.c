// Characters in a string
// Store a short word in a variable (e.g. "hello"). Use a for-loop to print each character on its own line.

#include<stdio.h>

void main(){

    char word[5] = "Hijab";
    for(int i = 0; i < 5; i++){
        printf("%c\n", word[i]);
    }
}