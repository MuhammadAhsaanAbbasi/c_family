#include <stdio.h>
#include <conio.h>

#define PI 3.1416

void main() {
    float radius, area, volume;

    // clrscr();  // Clear screen

    // Input radius
    printf("\nName: Muhammad Ahsaan Abbasi \nSTUDENT ID: CSC-25S-013 \nSECTION: BSCS-1A\n");
    printf("Enter radius of the sphere: ");
    scanf("%f", &radius);

    // Calculate area and volume
    area = 4 * PI * radius * radius;
    volume = (4.0 / 3.0) * PI * radius * radius * radius;

    // Display results
    printf("\nSurface Area of Sphere = %.2f", area);
    printf("\nVolume of Sphere = %.2f", volume);

    // getch();  // Pause screen
}
