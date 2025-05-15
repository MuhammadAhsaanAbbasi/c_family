// Multiplication chart
// Print a 5×5 table of products so that row i, column j shows i * j.

#include<stdio.h>

void main(){

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            printf("%d ", i * j);
        }
        printf("\n");
    }
}