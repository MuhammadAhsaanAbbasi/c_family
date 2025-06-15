// Write a program to implement program 4 using ‘for’ and ‘do-while’ loop.

#include<stdio.h>

void main(){
    int i=1,sum=0;
    for(i=1;i<=10;i++){
        sum=sum+i;
    }
    printf("Sum of first ten natural numbers is %d",sum);
    printf("\n");
    i=1, sum=0;
    do
    {
        /* code */
        sum=sum+i;
        i++;
    } while (i<=10);
    printf("Sum of first ten natural numbers is %d", sum);
}