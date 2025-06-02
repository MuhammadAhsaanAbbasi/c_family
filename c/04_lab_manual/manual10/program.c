#include <stdio.h>
#include <conio.h>

void main() {
    int matrix1[2][2], matrix2[2][2], sum[2][2];
    int i, j;

    // clrscr();  // Clear screen

    // Input elements for Matrix 1
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    printf("Enter elements of Matrix 1 (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for Matrix 2
    printf("\nEnter elements of Matrix 2 (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Compute the sum of matrices
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display the result
    printf("\nSum of the two matrices:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // getch();  // Pause output screen
}

