// Write a program to calculate the factorial of a given number using a for loop.

#include<stdio.h>

void main(){
    int i,fact=1,n;
    printf("Enter the number : "); scanf("%d",&n);
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    printf("Factorial of %d is %d",n,fact);
}