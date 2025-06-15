// Write a program to sum first ten natural numbers using while loop.

#include<stdio.h>

void main(){
    int i=1,sum=0;
    while(i<=10){
        sum=sum+i;
        i++;
    }
    printf("Sum of first ten natural numbers is %d",sum);
}