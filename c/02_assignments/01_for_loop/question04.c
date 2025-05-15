// Cubes of 1–5
// Use a for-loop to print the cubes (¹³, 2³, …, 5³) of the integers 1 through 5.

#include<stdio.h>

void main(){

    for(int i = 1; i <= 5; i++){
        printf("The cube of %d is %d\n", i, i * i * i);
    }
}