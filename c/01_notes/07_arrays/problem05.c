// 5. Write a program containing a function which reverses the array passed to it.

#include<stdio.h>

void printResponse(int arr[], int size){
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int size){
    for(int i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

void main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    
    printResponse(arr, 10);
    reverseArray(arr, 10);
    printResponse(arr, 10);
}