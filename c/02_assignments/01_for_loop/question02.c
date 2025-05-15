// Sum of even numbers
// Use a for-loop to compute and print the sum of all even numbers from 2 to 20.

#include<stdio.h>

void main(){

    int sum = 0;
    for (int i = 2; i <= 20; i++){
        /* code */
        if(i % 2 == 0) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("Sum of even numbers: %d", sum);
    
}