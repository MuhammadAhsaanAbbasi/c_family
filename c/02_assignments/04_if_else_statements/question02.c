// Sign test
// Read a number and print whether it’s “Positive”, “Negative”, or “Zero.”

#include<stdio.h>

void main(){
    int num = 0;
    printf("Enter a number: "); scanf("%d", &num);
    if(num > 0){
        printf("Positive\n");
    }
    else if(num < 0){
        printf("Negative\n");
    }
    else {
        printf("Zero\n");
    }
}