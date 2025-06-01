#include <stdio.h>

void main()
{
    char name[50];
    int age;
    float height;
    char gender;

    printf("Name: Muhammad Ahsaan Abbasi\n");

    printf("Student ID: CSC-25S-013\n");

    printf("Section: BSCS-1A\n");

    printf("\n\nEnter your Name: ");
    gets(name);
    printf("Enter your Age: ");
    scanf("%d", &age);
    printf("Enter your Height in ft: ");
    scanf("%f", &height);
    printf("Enter your Gender (M / F): ");
    scanf("%c", &gender);
    gender = getchar();
    printf("\n\n----- User Informatio -----");
    printf("\nName: %s", name);
    printf("\nAge: %d Years old", age);
    printf("\nHeight: %.2f ft", height);
    printf("\nGender: %c", gender);
}