#include <stdio.h>
#include <conio.h>

void main() {
    int arr[100], n, i;
    float sum = 0, avg;

    // clrscr();  // Clear the screen
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    // Calculate average
    avg = sum / n;

    printf("\nAverage of the entered numbers = %.2f", avg);

    // getch();
}
