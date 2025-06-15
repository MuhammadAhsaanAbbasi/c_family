#include<stdio.h>

void main(){
    int arr[10][10];
    int multiplier[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter a number: "); scanf("%d", &multiplier[i]);
        printf("\n");
    }

    for (int i = 0; i < 10; i++)
    {
       for (int j = 0; j < 10; j++)
       {
           arr[i][j] = multiplier[i] * (j+1);
       }
       
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d x %d = %d\n", multiplier[i], (j+1), arr[i][j]);
        }
        printf("\n");
    }
}