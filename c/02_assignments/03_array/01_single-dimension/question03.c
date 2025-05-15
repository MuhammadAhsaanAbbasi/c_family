// Reverse without modifying
// Store [1,2,3,4,5] in an array, then print its elements in reverse order without altering the original array.

#include<stdio.h>

void main(){
    int integers[5] = {1, 2, 3, 4, 5};
    for(int i = 4; i >= 0; i--){
        printf("%d\n", integers[i]);
    }
}