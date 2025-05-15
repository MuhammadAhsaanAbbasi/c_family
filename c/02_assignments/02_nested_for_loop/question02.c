// Number grid
// Print a 4×4 grid where each row is 1 2 3 4

#include<stdio.h>

void main(){

    for (int i = 1; i <= 4; i++){
        for (int j = 0; j <= 4; j++){
            printf("a%d ", j);
        }
        printf("\n");
    }
}