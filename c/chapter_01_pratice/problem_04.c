// Write a program to calculate simple interest for a set of values representing principal,
// Number of Years & Rate of Interest.

#include<stdio.h>

void main(){
    int prin, tm;
    float roi;

    printf("**Welcome the Calculator that Calculate simple interest**");

    printf("\nGive us the Princple Value between 1000 & 1000:");
    scanf("%d", &prin);

    printf("\nGive us Time of Years You want to take Interest:");
    scanf("%d", &tm);

    printf("\n Give us Rate of Interest in % between 2 & 15:");
    scanf("%f", &roi);

    float sim_int;
    sim_int = (prin*roi*tm)/100;

    printf("The simple Interest of given Principle %d, ROI %f, TOY %d is: %.2f", prin, roi, tm, sim_int);
}