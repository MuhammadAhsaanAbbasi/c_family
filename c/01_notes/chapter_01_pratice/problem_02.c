// Calculate the area of Circle & modify the same to calculate the volume of 
// Cylinder given it's radius & height.

#include<stdio.h>

void main(){
    int rad, height;

    scanf("%d", &rad);
    scanf("%d", &height);

    printf("The area of the Circle from given Radius %d is %f", rad, 3.14*rad*rad);
}