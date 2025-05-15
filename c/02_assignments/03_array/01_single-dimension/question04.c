// Search for a value
// Ask the user for a number, then check if it exists in a predefined array; print “Found” or “Not found.

#include<stdio.h>

void main(){

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int userInput = 0;
    printf("Enter a number: "); scanf("%d", &userInput);
    for(int i = 0; i < 10; i++){
        if(arr[i] == userInput){
            printf("Found\n");
            break;
        }
        else {
            continue;
        }
    }
    if(userInput >= 10){
        printf("Not Found\n");
    }
}