// Leap Year Checker
// Given a year (e.g. 2024), determine if it’s a leap year:

// divisible by 4 and (not by 100 unless also by 400).
// Print “Leap year” or “Not a leap year.”

#include<stdio.h>

void main(){
    int year = 0;
    printf("Enter a year: "); scanf("%d", &year);
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        printf("Leap year\n");
    }
    else {
        printf("Not a leap year\n");
    }
}