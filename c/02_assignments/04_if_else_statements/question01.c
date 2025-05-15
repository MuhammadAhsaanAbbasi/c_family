// Even or Odd
// Read an integer and print “Even” if it’s divisible by 2, otherwise print “Odd.”

#include<stdio.h>

void main(){
    int num = 0;
    printf("Enter a number: "); scanf("%d", &num);
    if(num % 2 == 0){
        printf("Even\n");
    }
    else {
        printf("Odd\n");
    }
}