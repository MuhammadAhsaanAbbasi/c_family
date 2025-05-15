// Find the maximum
// Given an array of integers, write code to find and print its largest element.

#include<stdio.h>

void main(){
    int integers[5] = {9, 3, 1, 5, 8};
    int max = 0;
    for(int i = 0; i < 5; i++){
        if(integers[i] > max){
            max = integers[i];
        }
    }
    printf("Maximum element: %d", max);
}