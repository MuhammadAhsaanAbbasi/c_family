// Multiplication table
// Ask the user for an integer N, then use a for-loop to print N × 1 through N × 10.

#include<stdio.h>

void main(){

    int N;
    printf("Enter a number: "); scanf("%d", &N);
    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", N, i, N * i);
    }
}