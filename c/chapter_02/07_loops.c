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
    }
}