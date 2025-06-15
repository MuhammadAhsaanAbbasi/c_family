// Write a program to print multiplication table of 10 in reversed order.

#include<stdio.h>

void main(){

    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    for(int i=10; i>=1; i--){
        printf("%d * %d = %d\n",n,i,n*i);
    }
}