// Sum & average
// For an array of scores (e.g. [70, 85, 90, 100]), compute and print both the total sum and the average.

#include<stdio.h>

void main(){
    char name[10] = "John Doe";
    int scores[4] = {70, 85, 90, 100};
    int sum = 0, average = 0;
    for(int i = 0; i < 4; i++){
        sum += scores[i];
    }
    average = sum / 4;
    printf("Name: %s\n", name);
    printf("Sum: %d\n", sum);
    printf("Average: %d", average);
}