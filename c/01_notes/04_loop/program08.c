// Repeat 7 using while loop
#include<stdio.h>

void main(){
    int i=1,fact=1, n;
    printf("Enter the number: ");
    scanf("%d", &n);
    while(i<=n){
        fact=fact*i;
        i++;
    }
    printf("Factorial of %d is %d", n, fact);
}