// 10. Write a program to check whether a given number is prime or not using loops.

#include<stdio.h>

void main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int flag = 0;
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Prime");
    }
    else{
        printf("Not Prime");
    }
}