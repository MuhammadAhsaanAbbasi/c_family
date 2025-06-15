// Write a program to calculate the sum of the numbers occurring in the
// multiplication table of 8. (consider 8 x 1 to 8 x 10).

#include<stdio.h>

void main(){

    int i=1,sum=0;
    while(i<=10){
        sum=sum+8*i;
        i++;
    }
    printf("Sum of first ten natural numbers is %d",sum);
}