#include<stdio.h>

void main(){
    printf("Hello World");
    int i = 0;
    while(i < 5){
        printf(" %d", i);
        i++;
    }
    printf("\n");

    for(int j = 0; j < 5; j++){
        printf(" %d", j);
        add();
    }
}

void add() {
    int a, b;
    printf("\nEnter First Number: ");
    scanf("%d", &a);
    printf("\nEnter Second Number: ");
    scanf("%d", &b);
    printf("\nThe Sum of %d and %d is %d \n", a, b, a+b);
}