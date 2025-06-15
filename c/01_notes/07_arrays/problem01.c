// Create an array of 10 numbers. Verify using pointer arithmetic that (ptr+2) points
// to the third element where ptr is a pointer pointing to the first element of the
// array.

#include<stdio.h>

void printResponse(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    
}

void main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = arr;
    printResponse(arr, 10);
    printf("\n");
    printf("The value of ptr is %d\n", *ptr);
    printf("The value of *(ptr+2) is %d\n", *(ptr+2));
}