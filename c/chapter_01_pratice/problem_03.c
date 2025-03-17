// Write a program to convert Celsius (Centigrade degrees temperature to Fahreheit.)

#include<stdio.h>

void main(){

    float cal, fh;

    printf("Enter temperature in Calcius to convert in Fahreheit C:");

    scanf("%f", &cal);
    
    fh = (cal*9/5)+32;

    printf("The Current temperature in %f C is %f F", cal, fh);
}