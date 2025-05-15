// Write a C program to calculate area of Rectangle.

#include<stdio.h>

void main(){
    int length, width;

    printf("Enter The Value of Rectangle Length:");
    scanf("%d", &length);

    printf("\nEnter the Value of Rectangle Width:");
    scanf("%d", &width);

    int area;

    area=length*width;

    printf("\nThe Total Area of Rectangle that have %d length, %d width: %d", length, width, area);
}

