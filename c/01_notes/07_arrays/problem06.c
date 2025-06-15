// Write a program containing functions which counts the number of positive
// integers in an array.

#include<stdio.h>

void positiveCount(int num[], int size){
    int postiveInt = 0;
    for(int i = 0; i < size; i++){
        if(num[i] > 0){
            postiveInt += 1;
        }
    }
    printf("Number of positive integers: %d", postiveInt);

}

void main(){
    int num[10] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};

    positiveCount(num, 10);
}