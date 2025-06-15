#include<stdio.h>

void main(){
    int arr[3][10];
    int multiplier[3] = {2, 7, 9};

    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 10; j++)
       {
           arr[i][j] = multiplier[i] * (j+1);
       }
       
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d x %d = %d\n", multiplier[i], (j+1), arr[i][j]);
        }
        printf("\n");
    }
}