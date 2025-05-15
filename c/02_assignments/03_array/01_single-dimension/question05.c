// Count positives & negatives
// Given an array that may include positive and negative numbers, count how many of each and print the two totals.

#include<stdio.h>

void main(){
    int integers[5] = {1, -2, 3, -4, 5};
    int positiveCount = 0, negativeCount = 0;
    int positive = 0, negative = 0;

    for(int i = 0; i < 5; i++){
        if(integers[i] > 0){
            positiveCount += 1;
            positive += integers[i];
        }
        else if(integers[i] < 0){
            negativeCount += 1;
            negative += integers[i];
        }
    }    

    printf("Positive count: %d\n", positiveCount);
    printf("Negative count: %d\n", negativeCount);
    printf("Positive sum: %d\n", positive);
    printf("Negative sum: %d\n", negative);

    printf("Total Sum: %d\n", positive + negative);
    
}