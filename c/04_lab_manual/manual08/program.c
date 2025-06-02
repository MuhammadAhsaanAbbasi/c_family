#include <stdio.h>
#include <conio.h>
// Function to calculate the sum of MSD and LSD
int sum_MSD_LSD(int num) {
    int lsd = num % 10;         // Last digit
    int msd = num / 100;        // First digit (hundreds place)
    return lsd + msd;
}

void main() {
    int number, result;
    // clrscr();
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    // Ask for a 3-digit number
    printf("Enter a 3-digit integer: ");
    scanf("%d", &number);

    // Check if it's a valid 3-digit number
    if(number < 100 || number > 999) {
        printf("Invalid input! Please enter a 3-digit number.\n");
        return;
    }

    // Call the function
    result = sum_MSD_LSD(number);

    // Display the result
    printf("Sum of MSD and LSD = %d\n", result);
    // getch();
}
