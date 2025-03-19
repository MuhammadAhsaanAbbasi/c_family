// Write a program that takes 5 inputs in a loop & calculate the number of inputs are odd and even.
// If Number of even is greater than odd then restart the game, If game is tied so show the message
// are you continued or not, If continue so restart the game otherwise exit the game.

#include<stdio.h>

void main(){
    int even_number, odd_number;
    char continue_game;
    do
    {
        even_number=0;
        odd_number=0;
        for (int i = 1; i <= 5; i++)
        {
            int num;
            printf("Enter the number: ");
            scanf("%d", &num);
            if(num % 2 == 0) {
                even_number++;
            } else if (num % 2 != 0)
            {
                odd_number++;
            }
        };
        if(even_number > odd_number) {
            printf("Even Numbers: %d\n", even_number);
            printf("Odd Numbers: %d\n", odd_number);
            printf("Even numbers are greater than odd numbers. Restart the game.\n");
        } else if (even_number == odd_number)
        {
            printf("Even Numbers: %d\n", even_number);
            printf("Odd Numbers: %d\n", odd_number);
            printf("Even numbers are equal to odd numbers. Do you want to continue? (Y/N): ");
            scanf(" %c", &continue_game);
            if(continue_game == 'Y' || continue_game == 'y') {
                continue;
            } else if (continue_game == 'N' || continue_game == 'n')
            {
                break;
            }
        } else
        {
            printf("Even Numbers: %d\n", even_number);
            printf("Odd Numbers: %d\n", odd_number);
            printf("Odd numbers are greater than even numbers. Do you want to continue? (Y/N): ");
            scanf(" %c", &continue_game);
            if(continue_game == 'Y' || continue_game == 'y') {
                continue;
            } else if (continue_game == 'N' || continue_game == 'n')
            {
                break;
            }
        }
    } while (1);
}