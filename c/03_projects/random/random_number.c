#include<stdio.h>
#include <stdlib.h>
#include <time.h>


void main(){
    // printf("Hello World");
     
    // This ensures you get a different sequence of random numbers on each run.
    srand(time(NULL));

    int randomNumber, player_life=0, player_guess;
    randomNumber = (rand() % 20) + 1;
    // printf("Random Number: %d\n", randomNumber);    
    do
    {
        /* code */
        player_life++;
        printf("Enter your guess: ");
        scanf("%d", &player_guess);
        if (player_guess > randomNumber)
        {
            printf("Your guess is too high\n");
        }
        else if (player_guess < randomNumber)
        {
            printf("Your guess is too low\n");
        }
        else
        {
            printf("You guessed it right\n");
        }
    } while (player_life <= 5 && randomNumber != player_guess);
    if (player_life >= 5){
        printf("You did not guess the number in 5 attempts or less.\n");
    };
}